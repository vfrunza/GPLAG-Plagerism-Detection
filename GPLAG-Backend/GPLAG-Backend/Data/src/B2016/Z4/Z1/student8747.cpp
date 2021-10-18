/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm> 
#define eps 1e-10


typedef std::pair<double,double> Tacka;

bool jednaki(const double &a, const double &b=0){
      return std::fabs(a-b)<=eps*(std::fabs(a)+std::fabs(b));
}

bool jednake_tacke(const Tacka &a, const Tacka &b){
    if(jednaki(a.first,b.first) && jednaki(a.second,b.second)) return true;
    return false;
}

class Trougao{
    Tacka tacka1,tacka2,tacka3;
    public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
        tacka1=t1; tacka2=t2; tacka3=t3;
    }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){ *this=Trougao(t1,t2,t3); }
    void Postavi(int indeks, const Tacka &t);
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        double b=t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
        if(b>0 && (jednaki(b)==0)) return 1;
        else if(b<0 && (jednaki(b)==0)) return -1;
        return 0;
    }
    Tacka DajTjeme(int indeks) const;
    double DajStranicu(int indeks) const;
    double DajUgao(int indeks) const;
    Tacka DajCentar() const{ Tacka a= std::make_pair((tacka1.first+tacka2.first+tacka3.first)/3.,(tacka1.second+tacka2.second+tacka3.second)/3.); return a; }
    double DajObim() const;
    double DajPovrsinu() const;
    bool DaLiJePozitivnoOrijentiran() const { 
        if(Orijentacija(tacka1,tacka2,tacka3)==1) return true;
        return false;
    }
    bool DaLiJeUnutra(const Tacka &t) const;
    void Ispisi() const { std::cout << "((" << tacka1.first << "," << tacka1.second << "),(" << tacka2.first << "," << tacka2.second << "),(" << tacka3.first << "," << tacka3.second << "))"; }
    void Transliraj(double delta_x, double delta_y);    
    void Centriraj(const Tacka &t);
    void Rotiraj(const Tacka &t, double ugao);
    void Skaliraj(const Tacka &t, double faktor);
    void Rotiraj(double ugao) { Rotiraj(DajCentar(),ugao); }
    void Skaliraj(double faktor) { Skaliraj(DajCentar(),faktor); }
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
}; 

void Trougao::Postavi(int indeks, const Tacka &t){
    if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks"); // vazi za sve funkcije koje traze indeks
    if(indeks==1) *this=Trougao(t,tacka2,tacka3);
    else if(indeks==2) *this=Trougao(tacka1,t,tacka3);
    else if(indeks==3) *this=Trougao(tacka1,tacka2,t);
}

Tacka Trougao::DajTjeme(int indeks) const{
    if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
    if(indeks==1) return tacka1;
    else if(indeks==2) return tacka2;
    return tacka3;
}

double Trougao::DajStranicu(int indeks) const{
    if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
    double b=0;
    if(indeks==1) b=std::sqrt((tacka2.first-tacka3.first)*(tacka2.first-tacka3.first)+(tacka2.second-tacka3.second)*(tacka2.second-tacka3.second));
    else if(indeks==2) b=std::sqrt((tacka1.first-tacka3.first)*(tacka1.first-tacka3.first)+(tacka1.second-tacka3.second)*(tacka1.second-tacka3.second));
    else if(indeks==3) b=std::sqrt((tacka1.first-tacka2.first)*(tacka1.first-tacka2.first)+(tacka1.second-tacka2.second)*(tacka1.second-tacka2.second));
    return b;
}

double Trougao::DajUgao(int indeks) const{
    if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
    double a=DajStranicu(1); double b=DajStranicu(2); double c=DajStranicu(3);
    double alfa=0;
    if(indeks==1) alfa=std::acos((b*b+c*c-a*a)/(2*b*c));
    else if(indeks==2) alfa=std::acos((a*a+c*c-b*b)/(2*a*c));
    else if(indeks==3) alfa=std::acos((a*a+b*b-c*c)/(2*a*b));
    return alfa;
}

double Trougao::DajObim() const{
    double a=DajStranicu(1); double b=DajStranicu(2); double c=DajStranicu(3);
    double O=a+b+c;
    return O;
}

double Trougao::DajPovrsinu() const{
    double P=0.5*(std::fabs(tacka1.first*(tacka2.second-tacka3.second)-tacka2.first*(tacka1.second-tacka3.second)+tacka3.first*(tacka1.second-tacka2.second)));
    return P;
}

bool Trougao::DaLiJeUnutra(const Tacka &t) const{
    if(Orijentacija(t,tacka2,tacka3)==0 || Orijentacija(tacka1,t,tacka3)==0 || Orijentacija(tacka1,tacka2,t)==0 ) return false;
    double P=DajPovrsinu(); 
    Trougao T1(t,tacka2,tacka3); double P1=T1.DajPovrsinu(); 
    Trougao T2(tacka1,t,tacka3); double P2=T2.DajPovrsinu(); 
    Trougao T3(tacka1,tacka2,t); double P3=T3.DajPovrsinu(); 
    return jednaki(P,P1+P2+P3);
}

void Trougao::Transliraj(double delta_x, double delta_y){
    tacka1.first+=delta_x; tacka1.second+=delta_y;
    tacka2.first+=delta_x; tacka2.second+=delta_y;
    tacka3.first+=delta_x; tacka3.second+=delta_y;
}

void Trougao::Centriraj(const Tacka &t){
    Tacka trenutni_centar=DajCentar();
    double delta_x=t.first-trenutni_centar.first;
    double delta_y=t.second-trenutni_centar.second;
    Transliraj(delta_x,delta_y);
}

void Trougao::Rotiraj(const Tacka &t, double ugao){
    double x1=t.first+(tacka1.first-t.first)*std::cos(ugao)-(tacka1.second-t.second)*std::sin(ugao);
    double y1=t.second+(tacka1.first-t.first)*std::sin(ugao)+(tacka1.second-t.second)*std::cos(ugao);
    double x2=t.first+(tacka2.first-t.first)*std::cos(ugao)-(tacka2.second-t.second)*std::sin(ugao);
    double y2=t.second+(tacka2.first-t.first)*std::sin(ugao)+(tacka2.second-t.second)*std::cos(ugao);
    double x3=t.first+(tacka3.first-t.first)*std::cos(ugao)-(tacka3.second-t.second)*std::sin(ugao);
    double y3=t.second+(tacka3.first-t.first)*std::sin(ugao)+(tacka3.second-t.second)*std::cos(ugao);
    Postavi(std::make_pair(x1,y1),std::make_pair(x2,y2),std::make_pair(x3,y3));
    
}

void Trougao::Skaliraj(const Tacka &t, double faktor){
    if(jednaki(faktor)) throw std::domain_error("Nekorektan faktor skaliranja");
    tacka1.first=t.first+faktor*(tacka1.first-t.first);
    tacka1.second=t.second+faktor*(tacka1.second-t.second);
    tacka2.first=t.first+faktor*(tacka2.first-t.first);
    tacka2.second=t.second+faktor*(tacka2.second-t.second);
    tacka3.first=t.first+faktor*(tacka3.first-t.first);
    tacka3.second=t.second+faktor*(tacka3.second-t.second);
}

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
   if(jednake_tacke(t1.tacka1,t2.tacka1) && jednake_tacke(t1.tacka2,t2.tacka2) && jednake_tacke(t1.tacka3,t2.tacka3)) return true;
   else if(jednake_tacke(t1.tacka1,t2.tacka1) && jednake_tacke(t1.tacka2,t2.tacka3) && jednake_tacke(t1.tacka3,t2.tacka2)) return true;
   else if(jednake_tacke(t1.tacka1,t2.tacka2) && jednake_tacke(t1.tacka2,t2.tacka1) && jednake_tacke(t1.tacka3,t2.tacka3)) return true;
   else if(jednake_tacke(t1.tacka1,t2.tacka2) && jednake_tacke(t1.tacka2,t2.tacka3) && jednake_tacke(t1.tacka3,t2.tacka1)) return true;
   else if(jednake_tacke(t1.tacka1,t2.tacka3) && jednake_tacke(t1.tacka2,t2.tacka2) && jednake_tacke(t1.tacka3,t2.tacka1)) return true;
   else if(jednake_tacke(t1.tacka1,t2.tacka3) && jednake_tacke(t1.tacka2,t2.tacka1) && jednake_tacke(t1.tacka3,t2.tacka2)) return true;
   return false;
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
    Tacka a,b,c;
    if(jednaki(t1.DajStranicu(1),t2.DajStranicu(1)) && jednaki(t1.DajUgao(1),t2.DajUgao(1))) a=t2.DajTjeme(1);
    else if(jednaki(t1.DajStranicu(1),t2.DajStranicu(2)) && jednaki(t1.DajUgao(1),t2.DajUgao(2))) a=t2.DajTjeme(2);
    else if(jednaki(t1.DajStranicu(1),t2.DajStranicu(3)) && jednaki(t1.DajUgao(1),t2.DajUgao(3))) a=t2.DajTjeme(3);
    else return false;
    
    if(jednaki(t1.DajStranicu(2),t2.DajStranicu(1)) && jednaki(t1.DajUgao(2),t2.DajUgao(1)) && !jednake_tacke(t2.DajTjeme(1),a)) b=t2.DajTjeme(1);
    else if(jednaki(t1.DajStranicu(2),t2.DajStranicu(2)) && jednaki(t1.DajUgao(2),t2.DajUgao(2)) && !jednake_tacke(t2.DajTjeme(2),a)) b=t2.DajTjeme(2);
    else if(jednaki(t1.DajStranicu(2),t2.DajStranicu(3)) && jednaki(t1.DajUgao(2),t2.DajUgao(3)) && !jednake_tacke(t2.DajTjeme(3),a)) b=t2.DajTjeme(3);
    else return false;
    
    if(jednaki(t1.DajStranicu(3),t2.DajStranicu(1)) && jednaki(t1.DajUgao(3),t2.DajUgao(1)) && !jednake_tacke(t2.DajTjeme(1),a) && !jednake_tacke(t2.DajTjeme(1),b)) c=t2.DajTjeme(1);
    else if(jednaki(t1.DajStranicu(3),t2.DajStranicu(2)) && jednaki(t1.DajUgao(3),t2.DajUgao(2)) && !jednake_tacke(t2.DajTjeme(2),a) && !jednake_tacke(t2.DajTjeme(2),b)) c=t2.DajTjeme(2);
    else if(jednaki(t1.DajStranicu(3),t2.DajStranicu(3)) && jednaki(t1.DajUgao(3),t2.DajUgao(3)) && !jednake_tacke(t2.DajTjeme(3),a) && !jednake_tacke(t2.DajTjeme(3),b)) c=t2.DajTjeme(3);
    else return false;
    
    Trougao pomocni(a,b,c);
    if(!(jednaki(pomocni.DajStranicu(1),t1.DajStranicu(1)) && jednaki(pomocni.DajStranicu(2),t1.DajStranicu(2)) && jednaki(pomocni.DajStranicu(3),t1.DajStranicu(3)))) return false;
    if(pomocni.DaLiJePozitivnoOrijentiran()==t1.DaLiJePozitivnoOrijentiran()) return true;
    return false;
}

bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
    double a1=t1.DajStranicu(1), b1=t1.DajStranicu(2), c1=t1.DajStranicu(3);
    double a2=t2.DajStranicu(1), b2=t2.DajStranicu(2), c2=t2.DajStranicu(3);
    double k=0;
    if(jednaki(a1/a2,b1/b2) && jednaki(a1/a2,c1/c2)) k=a1/a2; 
    else if(jednaki(a1/a2,b1/c2) && jednaki(a1/a2,c1/b2)) k=a1/a2;
    else if(jednaki(a1/b2,b1/a2) && jednaki(a1/b2,c1/c2)) k=a1/b2;
    else if(jednaki(a1/b2,b1/c2) && jednaki(a1/b2,c1/a2)) k=a1/b2;
    else if(jednaki(a1/c2,b1/a2) && jednaki(a1/c2,c1/b2)) k=a1/c2;
    else if(jednaki(a1/c2,b1/b2) && jednaki(a1/c2,c1/a2)) k=a1/c2;
    else return false;
    Trougao pomocni(t2.tacka1,t2.tacka2,t2.tacka3);
    pomocni.Skaliraj(k);
    return DaLiSuPodudarni(pomocni,t1);
}

int main ()
{   
    std::cout << "Koliko zelite kreirati trouglova: ";
    int n; std::cin >> n;
    std::vector<std::shared_ptr<Trougao>> v(n) ;
    for(int i=0;i<n;i++){
        std::cout << "Unesite podatke za " << i+1 << ". trougao (x1 y1 x2 y2 x3 y3): ";
        double a,b,c,d,e,f;
        std::cin >> a >> b >> c >> d >> e >> f;
        try{
            v[i]=std::make_shared<Trougao>(std::make_pair(a,b),std::make_pair(c,d),std::make_pair(e,f));
        }catch(std::domain_error e){
            std::cout << e.what() <<", ponovite unos!" <<std::endl;
            i--;
        }
    }
    std::cout << "Unesite vektor translacije (dx dy): ";
    double dx,dy;
    std::cin >> dx >> dy;
    std::cout << "Unesite ugao rotacije: ";  
    double alfa; std::cin >> alfa;
    double k;
    std::cout << "Unesite faktor skaliranja: ";
    std::cin >> k;
    std::transform(v.begin(),v.end(),v.begin(),[dx,dy,alfa,k]( std::shared_ptr<Trougao> pok){
       pok->Transliraj(dx,dy);
       pok->Rotiraj(alfa);
       pok->Skaliraj(pok->DajTjeme(1),k);
       return pok;
    });
    std::sort(v.begin(),v.end(),[](std::shared_ptr<Trougao> pok1, std::shared_ptr<Trougao> pok2){
       return  pok1->DajPovrsinu()<pok2->DajPovrsinu();
    });
    std::cout << "Trouglovi nakon obavljenih transformacija:" << std::endl;
    std::for_each(v.begin(),v.end(),[](std::shared_ptr<Trougao> pok){pok->Ispisi(); std::cout << std::endl;});
    std::cout << "Trougao sa najmanjim obimom: ";

   (*std::min_element(v.begin(),v.end(),[](std::shared_ptr<Trougao> pok1,std::shared_ptr<Trougao> pok2){
       return pok1->DajObim()<pok2->DajObim(); 
    }))->Ispisi();
    std::cout << std::endl;
    std::vector<std::pair<Trougao,Trougao>> identicni;
    std::vector<std::pair<Trougao,Trougao>> slicni;
    std::vector<std::pair<Trougao,Trougao>> podudarni;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(DaLiSuIdenticni(*v[i],*v[j])) identicni.push_back(std::make_pair(*v[i],*v[j]));
            if(DaLiSuPodudarni(*v[i],*v[j])) podudarni.push_back(std::make_pair(*v[i],*v[j]));
            if(DaLiSuSlicni(*v[i],*v[j])) slicni.push_back(std::make_pair(*v[i],*v[j]));
        }
    }
    if(identicni.size()==0) std::cout << "Nema identicnih trouglova!" << std::endl;
    else{
        std::cout << "Parovi identicnih trouglova:" << std::endl;
        for(int i=0;i<identicni.size();i++){
            identicni[i].first.Ispisi(); std::cout << " i "; identicni[i].second.Ispisi();
            std::cout << std::endl;
        }
    }
    if(podudarni.size()==0) std::cout << "Nema podudarnih trouglova!" << std::endl;
    else{
        std::cout << "Parovi podudarnih trouglova:" << std::endl;
        for(int i=0;i<podudarni.size();i++){
            podudarni[i].first.Ispisi(); std::cout << " i "; podudarni[i].second.Ispisi();
            std::cout << std::endl;
        }
    }
    if(podudarni.size()==0) std::cout << "Nema slicnih trouglova!";
    else{
        std::cout << "Parovi slicnih trouglova:" << std::endl;
        for(int i=0;i<slicni.size();i++){
            slicni[i].first.Ispisi(); std::cout << " i "; slicni[i].second.Ispisi();
            std::cout << std::endl;
        }
    } 
	return 0;
}