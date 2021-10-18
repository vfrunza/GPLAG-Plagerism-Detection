/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <vector>
#include <memory>
#include <algorithm>
#include <stdexcept>
#include <cmath>

typedef std::pair<double, double> Tacka;
const double E(1e-10);

class Trougao {
    Tacka t1, t2, t3;
    static bool ProvjeraIndeksa(int indeks) { return (indeks<4 && indeks>0); }
    static double RacunajDuzinuStranice(const Tacka &t1, const Tacka &t2) {
        return std::sqrt(std::pow(t2.first-t1.first, 2)+ std::pow(t2.second-t1.second, 2));
    }
    static double Rezultat(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        return (t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second));
    }
    static bool Poredi(double x, double y) {
        return std::fabs(x-y)<=E*(std::fabs(x)+std::fabs(y));
    }
    void Rotacija( Tacka &t, const Tacka &tc, double ugao ) {
        auto temp (t.first);
        t.first=tc.first+std::cos(ugao)*(t.first-tc.first)-std::sin(ugao)*(t.second-tc.second);
        t.second=tc.second+std::sin(ugao)*(temp-tc.first)+std::cos(ugao)*(t.second-tc.second);
    }
    void Skaliranje(Tacka &t, const Tacka &tc, double k) {
        t.first=tc.first+k*(t.first-tc.first); t.second=tc.second+k*(t.second-tc.second);
    }
  
    public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) { Postavi(t1, t2, t3);}
    
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){ if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
        Trougao::t1=t1; Trougao::t2=t2; Trougao::t3=t3; }
   
    void Postavi(int indeks, const Tacka &t) { if(indeks==1) Trougao::t1=t; else if(indeks==2) Trougao::t2=t;  else if(indeks==3) Trougao::t3=t; 
        else throw std::range_error("Nekorektan indeks"); if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena"); }
    
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) { double rez(Rezultat(t1, t2, t3)); if(rez>0) return 1; 
         if(rez<0) return -1;  return 0; }
    
    Tacka DajTjeme(int indeks) const { if(!ProvjeraIndeksa(indeks)) throw std::range_error("Nekorektan indeks"); if(indeks==1) return t1; 
        if(indeks==2) return t2; return t3;  }
    
    double DajStranicu(int indeks) const { if(!ProvjeraIndeksa(indeks)) throw std::range_error("Nekorektan indeks"); 
        if(indeks==1) return RacunajDuzinuStranice(t2, t3); if(indeks==2) return RacunajDuzinuStranice(t1, t3); return RacunajDuzinuStranice(t1, t2); }
    
    double DajUgao(int indeks) const{ if(!ProvjeraIndeksa(indeks)) throw std::range_error("Nekorektan indeks"); 
        double a(RacunajDuzinuStranice(t2, t3)), b(RacunajDuzinuStranice(t1, t3)), c(RacunajDuzinuStranice(t1, t2));
        if(indeks==1) return std::acos((b*b+c*c-a*a)/(2*b*c)); if(indeks==2) return std::acos((a*a+c*c-b*b)/(2*a*c)); 
        return std::acos((a*a+b*b-c*c)/(2*a*b)); }
        
    Tacka DajCentar() const {double x=(t1.first+t2.first+t3.first)/3; double y=(t1.second+t2.second+t3.second)/3; 
        Tacka t(std::make_pair(x, y));   return t; }
    
    double DajObim() const { double a(RacunajDuzinuStranice(t2, t3)), b(RacunajDuzinuStranice(t1, t3)), c(RacunajDuzinuStranice(t1, t2)); return a+b+c; }
    
    double DajPovrsinu() const { return (1./2)*std::fabs(Rezultat(t1, t2, t3)); }
    
    bool DaLiJePozitivnoOrjentiran() const { return (Orijentacija(t1, t2, t3)==1); }
    
    bool DaLiJeUnutra(const Tacka &t) const { return (Orijentacija(t1, t2, t3)==Orijentacija(t1, t2, t)==Orijentacija(t2, t3, t)==Orijentacija(t3, t1, t)); }
    
    void Ispisi() const {std::cout<<"(("<<t1.first<<","<<t1.second<<"),("<<t2.first<<","<<t2.second<<"),("<<t3.first<<","<<t3.second<<"))";;  } 
    
    void Transliraj(double delta_x, double delta_y) { t1.first+=delta_x; t1.second+=delta_y; t2.first+=delta_x; t2.second+=delta_y; 
        t3.first+=delta_x; t3.second+=delta_y; }
    
    void Centriraj(const Tacka &t) { double x(t.first-(t1.first+t2.first+t3.first)/3), y(t.second-(t1.second+t2.second+t3.second)/3); Transliraj(x, y);}
    
    void Rotiraj(const Tacka &t, double ugao) { Rotacija(t1,t, ugao); Rotacija(t2, t, ugao); Rotacija(t3, t, ugao);  }
    
    void Skaliraj(const Tacka &t, double faktor) { if(faktor-0<E) throw std::domain_error("Nekorektan faktor skaliranja;");
        Skaliranje(t1, t, faktor); Skaliranje(t2, t, faktor); Skaliranje(t3, t, faktor); }
    void Rotiraj(double ugao) {Tacka t(DajCentar()); Rotiraj(t, ugao); }
    
    void Skaliraj(double faktor) { Tacka t(DajCentar()); Skaliraj(t, faktor); }
    
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2) {
    std::vector<Tacka> v1{t1.t1, t1.t2, t1.t3};
    std::vector<Tacka> v2{t2.t1, t2.t2, t2.t3};
    std::sort(v1.begin(), v1.end()); std::sort(v2.begin(), v2.end());
    bool isti(true);
    for(int i=0; i<v1.size(); i++) {
        if(v1[i]!=v2[i]) {
            isti=false;
            break;
        }
    }
    if(!isti) return false;
    return true;
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2) {
    
    std::vector<Tacka> v1{t1.t1, t1.t2, t1.t3};
    std::vector<Tacka> v2{t2.t1, t2.t2, t2.t3};
    double a1(t1.DajStranicu(1)), b1(t1.DajStranicu(2)), c1(t1.DajStranicu(3));
    std::vector<double> stranice1{a1, b1, c1};
    double a2(t2.DajStranicu(1)), b2(t2.DajStranicu(2)), c2(t2.DajStranicu(3));
    std::vector<double> stranice2{a2, b2, c2};
    
    
    for(int i=0; i<3; i++) {
        for(int j=i+1; j<3; j++) {
            if(stranice1[i]>stranice1[j]) {
               std::swap(stranice1[i], stranice1[j]);
             std::swap(v1[i], v1[j]);
                j--;
            }
        }
    }
    
    for(int i=0; i<3; i++) {
        for(int j=i+1; j<3; j++) {
            if(stranice2[i]>stranice2[j]) {
                std::swap(stranice2[i], stranice2[j]);
                std::swap(v2[i], v2[j]); j--;
            }
        }
    }
    
    for(int i=0; i<3; i++) {
        if(!Trougao::Poredi(stranice1[i], stranice2[i])) return false;
    }
    if(Trougao::Orijentacija(v1[0], v1[1], v1[2])!=Trougao::Orijentacija(v2[0], v2[1], v2[2])) return false;
    return true;
}


bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2) {
    std::vector<Tacka> v1{t1.t1, t1.t2, t1.t3};
    std::vector<Tacka> v2{t2.t1, t2.t2, t2.t3};
    double a1(t1.DajStranicu(1)), b1(t1.DajStranicu(2)), c1(t1.DajStranicu(3));
    std::vector<double> stranice1{a1, b1, c1};
    double a2(t2.DajStranicu(1)), b2(t2.DajStranicu(2)), c2(t2.DajStranicu(3));
    std::vector<double> stranice2{a2, b2, c2};
    
    
    for(int i=0; i<3; i++) {
        for(int j=i+1; j<3; j++) {
            if(stranice1[i]>stranice1[j]) {
                std::swap(stranice1[i], stranice1[j]);
                std::swap(v1[i], v1[j]); j--;
            }
        }
    }
    
    for(int i=0; i<3; i++) {
        for(int j=i+1; j<3; j++) {
            if(stranice2[i]>stranice2[j]) {
                std::swap(stranice2[i], stranice2[j]);
                std::swap(v2[i], v2[j]); j--;
            }
        }
    }
    
    if(Trougao::Orijentacija(v1[0], v1[1], v1[2])!=Trougao::Orijentacija(v2[0], v2[1], v2[2])) return false;
    
    int k(0), i(0);
    if(stranice1[0]>=stranice2[0])  {
        k=std::abs (stranice1[0]/stranice2[0]);
        for(i=0; i<3; i++) {
            if(!Trougao::Poredi(stranice1[i]/stranice2[i], k)) break;
        }
    if(i!=3) return false; }
    
    if(stranice2[0]>stranice1[0]) {
        k=std::abs(stranice2[0]/stranice1[0]);
        for(i=0; i<3; i++) {
            if(!Trougao::Poredi(stranice2[i]/stranice1[i], k)) break;
        }
    }
    if(i!=3) return false;
    return true;
}


int main ()
{
    int broj;
    std::cout << "Koliko zelite kreirati trouglova: ";
    std::cin >> broj;
    std::vector <std::shared_ptr<Trougao>> v(broj);
    for(int i=0; i<broj; i++) {
        std::cout << "Unesite podatke za " << i+1<< ". trougao (x1 y1 x2 y2 x3 y3): ";
        double x1,y1,x2,y2,x3,y3;
        std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        Tacka t1(std::make_pair(x1,y1)); Tacka t2(std::make_pair(x2,y2)); Tacka t3(std::make_pair(x3,y3));
        try {
           v[i]=std::make_shared<Trougao> (t1,t2,t3);   }
        catch(std::domain_error tekst)
        {
            std::cout << tekst.what() << ", ponovite unos!\n";
            i--;
        }
    }
    
    double delta_x, delta_y;
    std::cout << "Unesite vektor translacije (dx dy): ";
    std::cin >> delta_x >> delta_y;
    
    std::transform(v.begin(), v.end(), v.begin(), [delta_x, delta_y](std::shared_ptr<Trougao> p) { p->Transliraj(delta_x, delta_y); return p; });
    double ugao;
    std::cout << "Unesite ugao rotacije: ";
    std::cin >> ugao;
    std::transform(v.begin(), v.end(), v.begin(), [ugao] (std::shared_ptr<Trougao>p) { p->Rotiraj(p->DajCentar(),ugao); return p; });
   
    double faktor;
    std::cout << "Unesite faktor skaliranja: ";
    std::cin >> faktor;
    
    std::transform(v.begin(), v.end(), v.begin(), [faktor] (std::shared_ptr<Trougao> p) { p->Skaliraj(p->DajTjeme(1), faktor); return p;});

    std::sort(v.begin(), v.end(), [](std::shared_ptr<Trougao> p1, std::shared_ptr<Trougao>p2) { return p1->DajPovrsinu()<p2->DajPovrsinu(); } );
    std::cout << "Trouglovi nakon obavljenih transformacija:" << std::endl;
    std::for_each(v.begin(), v.end(), [](std::shared_ptr<Trougao> p) { p->Ispisi();std::cout << std::endl;});
    
    std::cout << "Trougao sa najmanjim obimom: "; 
      auto element= *std::min_element(v.begin(), v.end(), [](std::shared_ptr<Trougao> p1, std::shared_ptr<Trougao> p2) { return p1->DajObim()<p2->DajObim(); });
       element->Ispisi();
    int brojac(0);
    
    for(int i=0; i<broj; i++) {
        for(int j=i+1; j<broj; j++) {
            if(DaLiSuIdenticni(*v[i], *v[j])) brojac++;
        }
    }
    if(brojac!=0) {
    std::cout << "\nParovi identicnih trouglova:" << std::endl;
    for(int i=0; i<broj; i++) {
        for(int j=i+1; j<broj; j++) {
            if(DaLiSuIdenticni(*v[i], *v[j])) {
                v[i]->Ispisi(); std::cout << " i "; v[j]->Ispisi(); std::cout << std::endl;
            }
        }
    }
    }
    else std::cout << "\nNema identicnih trouglova!" << std::endl;
    
    brojac=0;
    for(int i=0; i<broj; i++) {
        for(int j=i+1; j<broj; j++) {
            if(DaLiSuPodudarni(*v[i], *v[j])) brojac++;
        }
    }
    if(brojac!=0) {
    std::cout << "Parovi podudarnih trouglova:\n";
    for(int i=0; i<broj; i++) {
        for(int j=i+1; j<broj; j++) {
            if(DaLiSuPodudarni(*v[i], *v[j])) {
                v[i]->Ispisi(); std::cout << " i ";  v[j]->Ispisi(); std::cout << std::endl;
            }
        }
    }
    }
    else std::cout << "Nema podudarnih trouglova!" << std::endl;
    
    brojac=0;
    for(int i=0; i<broj; i++) {
        for(int j=i+1; j<broj; j++) {
            if(DaLiSuSlicni(*v[i], *v[j])) brojac++;
        }
    }
    
    if(brojac!=0) {
    std::cout << "Parovi slicnih trouglova:\n";
    for(int i=0; i<broj; i++) {
        for(int j=i+1; j<broj; j++) {
            if(DaLiSuSlicni(*v[i], *v[j])) {
                v[i]->Ispisi(); std::cout << " i " ; v[j]->Ispisi(); std::cout << std::endl;
            }
        }
    }
    }
    else std::cout << "Nema slicnih trouglova! " << std::endl;
    
	return 0;
}