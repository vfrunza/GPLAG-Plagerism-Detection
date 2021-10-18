/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>
#define pi 3.14159265359

typedef std::pair<double, double> Tacka;

class Trougao {
  Tacka t1, t2, t3;
  void ProvjeriIndeks(int indeks) const { if(indeks<1 || indeks>3) throw std::domain_error("Nekorektan indeks"); }
  static bool ProvjeriNaJednakost(double a, double b) { long double Eps = 1e-10; if(fabs(a-b) <= Eps * (fabs(a)+fabs(b))) return true; return false; }
  static double ZaPovrsinu(const Tacka t1, const Tacka t2, const Tacka t3) { double a = (t1.first*(t2.second-t3.second))-(t2.first*(t1.second-t3.second))+(t3.first*(t1.second-t2.second)); return a; }
  public: 
  Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3);
  void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) { if(ProvjeriNaJednakost(ZaPovrsinu(t1,t2,t3),0)) throw std::domain_error("Nekorektne pozicije tjemena"); Trougao::t1=t1; Trougao::t2=t2; Trougao::t3=t3; }
  void Postavi(int indeks, const Tacka &t);
  static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) { if(ZaPovrsinu(t1, t2, t3)>0) return 1; else return -1; }
  Tacka DajTjeme(int indeks) const { ProvjeriIndeks(indeks); if(indeks==1) return t1; else if(indeks==2) return t2; else return t3; }
  double DajStranicu(int indeks) const;
  double DajUgao(int indeks) const;
  Tacka DajCentar() const { Tacka c = std::make_pair((t1.first+t2.first+t3.first)/3, (t1.second+t2.second+t3.second)/3); return c; }
  double DajObim() const { double a=DajStranicu(1), b=DajStranicu(2), c=DajStranicu(3); return a+b+c; }
  double DajPovrsinu() const { return std::fabs(ZaPovrsinu(t1, t2, t3))/2; }
  bool DaLiJePozitivnoOrijentiran() const { return Orijentacija(t1, t2, t3); }
  bool DaLiJeUnutra(const Tacka &t) const;
  void Ispisi() const { std::cout << "((" << t1.first << "," << t1.second << "),(" << t2.first << "," << t2.second << "),(" << t3.first << "," << t3.second << "))"; }
  void Transliraj(double delta_x, double delta_y) { Trougao::t1.first+=delta_x; Trougao::t1.second+=delta_y; Trougao::t2.first+=delta_x; Trougao::t2.second+=delta_y; Trougao::t3.first+=delta_x; Trougao::t3.second+=delta_y; }
  void Centriraj(const Tacka &t) { Tacka tjeme=DajCentar(); Transliraj(t.first-tjeme.first, t.second-tjeme.second); }
  void Rotiraj(const Tacka &t, double ugao);
  void Skaliraj(const Tacka &t, double faktor);
  void Rotiraj(double ugao) { Rotiraj(DajCentar(), ugao); }
  void Skaliraj(double faktor) { Skaliraj(DajCentar(), faktor); }
  friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
  friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
  friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};

Trougao::Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
   // if((Trougao::ProvjeriNaJednakost(t1.first, t2. first) && Trougao::ProvjeriNaJednakost(t1. first, t3.first)) || (Trougao::ProvjeriNaJednakost(t1.second, t2.second) && Trougao::ProvjeriNaJednakost(t2.second, t3.second))) throw std::domain_error("Nekorektne pozicije tjemena");
    if(ProvjeriNaJednakost(ZaPovrsinu(t1,t2,t3), 0)) throw std::domain_error("Nekorektne pozicije tjemena");
    Trougao::t1=t1; Trougao::t2=t2; Trougao::t3=t3;
}

void Trougao::Postavi(int indeks, const Tacka &t) {
    ProvjeriIndeks(indeks);
    if(indeks==1) Trougao::t1=t;
    else if(indeks==2) Trougao::t2=t;
    else Trougao::t3=t;
}

double Trougao::DajStranicu(int indeks) const {
    ProvjeriIndeks(indeks);
    if(indeks==1) return std::sqrt(std::pow(t3.first-t2.first, 2) + std::pow(t2.second-t3.second,2));
    else if(indeks==2) return std::sqrt(std::pow(t1.first-t3.first, 2) + std::pow(t1.second-t3.second, 2));
    else return std::sqrt(std::pow(t2.first-t1.first, 2) + std::pow(t2.second-t1.second, 2));
}

double Trougao::DajUgao(int indeks) const {
    ProvjeriIndeks(indeks);
    double a = DajStranicu(1), b = DajStranicu(2), c = DajStranicu(3);
    
    if(indeks==1) return std::acos((b*b+c*c-a*a)/(2*b*c))*pi/180;
    else if(indeks==2) return std::acos((a*a+c*c-b*b)/(2*a*c))*pi/180;
    else return std::acos((b*b-c*c+a*a)/(2*b*a))*pi/180;
}

void Trougao::Rotiraj(const Tacka &t, double ugao) {
    Tacka p;
    p.first = t.first+(t1.first-t.first)*cos(ugao)-(t1.second-t.second)*sin(ugao); p.second = t.second+(t1.first-t.first)*sin(ugao)+(t1.second-t.second)*cos(ugao);
    t1.first = p.first; t1.second = p.second;
    p.first = t.first+(t2.first-t.first)*cos(ugao)-(t2.second-t.second)*sin(ugao); p.second = t.second+(t2.first-t.first)*sin(ugao)+(t2.second-t.second)*cos(ugao);
    t2.first=p.first; t2.second = p.second;
    p.first = t.first+(t3.first-t.first)*cos(ugao)-(t3.second-t.second)*sin(ugao); p.second = t.second+(t3.first-t.first)*sin(ugao)+(t3.second-t.second)*cos(ugao);
    t3.first = p.first; t3.second = p.second;
    
}

void Trougao::Skaliraj(const Tacka &t, double faktor) {
    if(Trougao::ProvjeriNaJednakost(faktor,0)) throw std::domain_error("Nekorektan faktor skaliranja");
    t1 = std::make_pair(t.first+faktor*(t1.first-t.first), t.second+faktor*(t1.second-t.second));
    t2 = std::make_pair(t.first+faktor*(t2.first-t.first), t.second+faktor*(t2.second-t.second));
    t3 = std::make_pair(t.first+faktor*(t3.first-t.first), t.second+faktor*(t3.second-t.second));
}

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2) {
     if((t1.t1==t2.t1 && ((t1.t2==t2.t2 && t1.t3==t2.t3) || (t1.t2==t2.t3 && t1.t3==t2.t2))) || (t1.t1==t2.t2 && ((t1.t2 == t2.t3 && t1.t3 == t2.t1) || (t1.t2 == t2.t1 && t1.t3 == t2.t3))) || (t1.t1 == t2.t3 && ((t1.t2==t2.t1 && t1.t3 == t2.t2) || (t1.t2 == t2.t2 && t1.t3 == t2.t1)))) return true;
     return false;
}

bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2) {
   double st1[3] = {t1.DajStranicu(3), t1.DajStranicu(2), t1.DajStranicu(1)};
   double st2[3] = {t2.DajStranicu(1), t2.DajStranicu(2), t2.DajStranicu(3)};
   
   std::sort(st1, st1+3);
   std::sort(st2, st2+3);
 
  if(Trougao::ProvjeriNaJednakost(st1[1]/st2[1], st1[2]/st2[2]) && !Trougao::ProvjeriNaJednakost(Trougao::Orijentacija(t1.t1,t1.t2, t1.t3), Trougao::Orijentacija(t2.t1,t2.t2,t2.t3) )) return true;
  
   return false;
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2) {
    
    double st1[3] = {t1.DajStranicu(1), t1.DajStranicu(2), t1.DajStranicu(3) };
    double st2[3] = {t2.DajStranicu(1), t2.DajStranicu(2), t2.DajStranicu(3) };
   
    if(!Trougao::ProvjeriNaJednakost(Trougao::Orijentacija(t1.t1,t1.t2,t1.t3), Trougao::Orijentacija(t2.t1,t2.t2,t2.t3))) {
   
    std::sort(st1, st1+3);
    std::sort(st2, st2+3);
       if(Trougao::ProvjeriNaJednakost(st1[0], st2[0]) && Trougao::ProvjeriNaJednakost(st1[1], st2[1]) && Trougao::ProvjeriNaJednakost(st1[2], st2[2])) return true;
     
   }
   else {
        if(Trougao::ProvjeriNaJednakost(st1[0], st2[0]) && Trougao::ProvjeriNaJednakost(st1[1], st2[2]) && Trougao::ProvjeriNaJednakost(st1[2], st2[1])) return true;

   }
    
    return false;
}

int main (){
    std::cout << "Koliko zelite kreirati trouglova: ";
    int n;
    std::cin >> n;
    
    std::vector<std::shared_ptr<Trougao>> v(n, nullptr);
    //try{
    for(int i=0; i<n; i++) {
        Tacka t1, t2, t3;
        try {
            std::cout << "Unesite podatke za " << i+1 << ". trougao (x1 y1 x2 y2 x3 y3): ";
            Tacka tocka;
           // std::cout << "Unesite prvo tjeme: ";
            int x1, y1, x2, y2, x3, y3;
            std::cin >> x1 >> y1;
            t1 = std::make_pair(x1, y1);
        
            //std::cout << "Unesite drugo tjeme: ";
            std::cin >> x2 >> y2;
            t2 = std::make_pair(x2, y2);
        
            //std::cout << "Unesite trece tjeme: ";
            std::cin >> x3 >> y3;
            t3 = std::make_pair(x3, y3);
            
            Trougao t(t1, t2, t3);  
            v[i] = std::make_shared<Trougao> (t);

        } catch(std::domain_error w) { std::cout << w.what() << ", ponovite unos!" << std::endl; i--; continue; }
    }
    try{
    std::cout << "Unesite vektor translacije (dx dy): ";
    double dx, dy, ugao, faktor;
    std::cin >> dx >> dy;
    std::transform(v.begin(), v.end(), v.begin(), [dx, dy] (std::shared_ptr<Trougao> v) { v->Transliraj(dx, dy); return v; });
//    v[0]->Ispisi();
    std::cout << "Unesite ugao rotacije: ";
    std::cin >> ugao;
    std::transform(v.begin(), v.end(), v.begin(), [ugao] (std::shared_ptr<Trougao> v) { v->Rotiraj(v->DajCentar(),ugao); return v; });
    //v[0]->Ispisi();
    std::cout << "Unesite faktor skaliranja: ";
    std::cin >> faktor;
    std::transform(v.begin(), v.end(), v.begin(), [faktor] (std::shared_ptr<Trougao> v) { v->Skaliraj(v->DajTjeme(1), faktor); return v;});
   // v[0]->Ispisi();
  std::sort(v.begin(), v.end(), [] (std::shared_ptr<Trougao> x, std::shared_ptr<Trougao> y) { return x->DajPovrsinu() < y->DajPovrsinu(); });
    
        std::cout << "Trouglovi nakon obavljenih transformacija:" << std::endl;

    std::for_each(v.begin(), v.end(), [] (std::shared_ptr<Trougao> v) { v->Ispisi(); std::cout << std::endl; });

   auto mini = *std::min_element(v.begin(), v.end(), [] (std::shared_ptr<Trougao> a, std::shared_ptr<Trougao> b) { double o1(a->DajObim()), o2(b->DajObim()); return o1<o2; });

    std::cout << "Trougao sa najmanjim obimom: "; mini->Ispisi(); std::cout << std::endl;
    
        
        
    std::vector<std::pair<Trougao, Trougao>> identicni, podudarni, slicni;
    
    //std::vector<int> pamti_j;
    
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++)  {
            if(DaLiSuIdenticni(*v[i], *v[j])) { identicni.push_back(std::make_pair(*v[i], *v[j])); }
        }
    }
    if(identicni.size()==0) std::cout << "Nema identicnih trouglova!" << std::endl;
    else {      std::cout << "Parovi identicnih trouglova:" << std::endl;
                std::for_each(identicni.begin(), identicni.end(), [] (std::pair<Trougao, Trougao> p) { (p.first).Ispisi(); std::cout << " i "; (p.second).Ispisi(); std::cout << std::endl; } ); }
    

     for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++)  {
            if(DaLiSuPodudarni(*v[i], *v[j])) { podudarni.push_back(std::make_pair(*v[i], *v[j])); }
        }
    }
    if(podudarni.size()==0) std::cout << "Nema podudarnih trouglova!" << std::endl;
    else {     std::cout << "Parovi podudarnih trouglova:" << std::endl;
        std::for_each(podudarni.begin(), podudarni.end(), [] (std::pair<Trougao, Trougao> p) { (p.first).Ispisi(); std::cout << " i "; (p.second).Ispisi(); std::cout << std::endl;} ); }
    
     for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++)  {
            if(DaLiSuSlicni(*v[i], *v[j])) { slicni.push_back(std::make_pair(*v[i], *v[j])); }
        }
    }
    if(slicni.size()==0) std::cout << "Nema slicnih trouglova!" << std::endl;
    else {     std::cout << "Parovi slicnih trouglova:" << std::endl;
        std::for_each(slicni.begin(), slicni.end(), [] (std::pair<Trougao, Trougao> p) { (p.first).Ispisi(); std::cout << " i "; (p.second).Ispisi(); std::cout << std::endl;} ); }
    
    
    } catch(std::domain_error s) { std::cout << s.what(); }
    catch(...) {};
return 0;
} 
/*{ 
    Tacka t1(3,6);
    Tacka t2(11,4);
    Tacka t3(9,8);
    
    Tacka ta1(7,5);
    Tacka ta2(-1,7);
    Tacka ta3(5,9);
    Trougao tr1(t1,t2,t3), tr2(ta1, ta2, ta3);
   // t.Ispisi();
   // Tacka transliraj(1,1);
    //t.Transliraj(2,3);
    std::cout << std::endl; 
    //t.Ispisi();
    //t.Rotiraj(0);
    //Tacka cent = t.DajCentar();
    //std::cout << "teziste: " << cent.first << "," << cent.second;
    //std::cout << std::endl; t.Ispisi(); 
    
    //t.Skaliraj(t.DajTjeme(1), 2);
    //std::cout << std::endl; t.Ispisi();
    std::cout << (int)DaLiSuPodudarni(tr1, tr2);
    
return 0;
} */