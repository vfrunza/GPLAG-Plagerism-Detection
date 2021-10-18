/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <utility>
#include <memory>
#include <algorithm>


typedef std::pair<double,double> Tacka;
const double EPS(1e-10);

class Trougao {
    Tacka tac1, tac2, tac3;
    static bool Uporedi(const Tacka &t1, const Tacka &t2) {
        if(std::abs(t1.first-t2.first)<EPS && std::abs(t1.second-t2.second)<EPS) return true;
        return false;
    }
    static double PomocnaDuzinaStranice(const Tacka &t1, const Tacka &t2) {
        return std::sqrt((t1.first-t2.first)*(t1.first-t2.first)+(t1.second-t2.second)*(t1.second-t2.second));
    }
    
    public:
    Trougao (const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
        tac1=t1; tac2=t2; tac3=t3;
    }
    
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
        tac1=t1; tac2=t2; tac3=t3;
    }
    
    void Postavi(int indeks, const Tacka &t) {
        if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
        if(indeks==1) tac1=t;
        if(indeks==2) tac2=t;
        if(indeks==3) tac3=t;
    }
    
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        double rezultat(t1.first*(t2.second-t3.second)+t2.first*(t3.second-t1.second)+t3.first*(t1.second-t2.second));
        if(std::abs(rezultat)<EPS) return 0;
        else if(rezultat<0) return -1;
        else return 1;
    }
    
    Tacka DajTjeme(int indeks) const {
        if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
        if(indeks==1) return tac1;
        if(indeks==2) return tac2;
        if(indeks==3) return tac3;
    }
    
    double DajStranicu(int indeks) const {
        if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
        if(indeks==1) return Trougao::PomocnaDuzinaStranice(tac2,tac3); 
        if(indeks==2) return Trougao::PomocnaDuzinaStranice(tac1,tac3); 
        if(indeks==3) return Trougao::PomocnaDuzinaStranice(tac1,tac2); 
    }
    
    double DajUgao(int indeks) const {
        if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
        if(indeks==1) return (acos((DajStranicu(2)*DajStranicu(2)+DajStranicu(3)*DajStranicu(3)-DajStranicu(1)*DajStranicu(1))/(2*DajStranicu(2)*DajStranicu(3))));
        if(indeks==2) return (acos((DajStranicu(1)*DajStranicu(1)+DajStranicu(3)*DajStranicu(3)-DajStranicu(2)*DajStranicu(2))/(2*DajStranicu(1)*DajStranicu(3))));
        if(indeks==3) return (acos((DajStranicu(1)*DajStranicu(1)+DajStranicu(2)*DajStranicu(2)-DajStranicu(3)*DajStranicu(3))/(2*DajStranicu(1)*DajStranicu(2))));
    }
    
    Tacka DajCentar() const {
        Tacka rezultat;
        rezultat.first=(tac1.first+tac2.first+tac3.first)/3;
        rezultat.second=(tac1.second+tac2.second+tac3.second)/3;
        return rezultat;
    }
    
    double DajObim() const {
        return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
    }
    
    double DajPovrsinu() const {
        return std::abs(tac1.first*(tac2.second-tac3.second)-tac2.first*(tac1.second-tac3.second)+tac3.first*(tac1.second-tac2.second))/2;
    }
    
    bool DaLiJePozitivnoOrijentiran() const {
        if(Orijentacija(tac1,tac2,tac3)==1) return true;
        return false;
    }
    
    bool DaLiJeUnutra(const Tacka &t) const {
        auto orj=Orijentacija(tac1,tac2,tac3);
        if(orj==Orijentacija(tac1,tac2,t) && orj==Orijentacija(tac2,tac3,t) && orj==Orijentacija(tac3,tac1,t)) return true;
        return false;
    } 
    void Ispisi() const {
        std::cout<<"(("<<tac1.first<<","<<tac1.second<<"),("<<tac2.first<<","<<tac2.second<<"),("<<tac3.first<<","<<tac3.second<<"))";
    }
    
    void Transliraj(double delta_x, double delta_y) {
        tac1.first+=delta_x; tac1.second+=delta_y;
        tac2.first+=delta_x; tac2.second+=delta_y;
        tac3.first+=delta_x; tac3.second+=delta_y;
    }
    
    void Centriraj(const Tacka &t) {
        Tacka centar(DajCentar());
        double delta_x(t.first-centar.first);
        double delta_y(t.second-centar.second);
        Transliraj(delta_x, delta_y);
    }
    
    void Rotiraj(const Tacka &t, double ugao) {
        auto a(tac1.first);
        auto b(tac1.second);
        tac1.first = t.first + (a - t.first)*std::cos(ugao) - (b - t.second)*std::sin(ugao);
        tac1.second = t.second + (a - t.first)*std::sin(ugao) + (b - t.second)*std::cos(ugao);
        
        a=tac2.first;
        b=tac2.second;
        tac2.first=t.first+(a -t.first)*std::cos(ugao)-(b-t.second)*std::sin(ugao);
        tac2.second=t.second+(a-t.first)*std::sin(ugao)+(b-t.second)*std::cos(ugao);
        
        a=tac3.first;
        b=tac3.second;
        tac3.first=t.first+(a-t.first)*std::cos(ugao)-(b-t.second)*std::sin(ugao);
        tac3.second=t.second+(a-t.first)*std::sin(ugao)+(b-t.second)*std::cos(ugao);
    } 
    
    void Skaliraj(const Tacka &t, double faktor) {
        if(std::abs(faktor)<0) throw std::domain_error("Nekorektan faktor skaliranja");
        tac1.first=t.first+faktor*(tac1.first-t.first);
        tac1.second=t.second+faktor*(tac1.second-t.second);
        tac2.first=t.first+faktor*(tac2.first-t.first);
        tac2.second=t.second+faktor*(tac2.second-t.second);
        tac3.first=t.first+faktor*(tac3.first-t.first);
        tac3.second=t.second+faktor*(tac3.second-t.second);
       if(faktor<0) Rotiraj(t,180);
    } 
    void Rotiraj(double ugao) {
        auto t(DajCentar());
        auto a(tac1.first);
        auto b(tac1.second);
        tac1.first = t.first + (a - t.first)*std::cos(ugao) - (b - t.second)*std::sin(ugao);
        tac1.second = t.second + (a - t.first)*std::sin(ugao) + (b - t.second)*std::cos(ugao);
        
        a=tac2.first;
        b=tac2.second;
        tac2.first=t.first+(a -t.first)*std::cos(ugao)-(b-t.second)*std::sin(ugao);
        tac2.second=t.second+(a-t.first)*std::sin(ugao)+(b-t.second)*std::cos(ugao);
        
        a=tac3.first;
        b=tac3.second;
        tac3.first=t.first+(a-t.first)*std::cos(ugao)-(b-t.second)*std::sin(ugao);
        tac3.second=t.second+(a-t.first)*std::sin(ugao)+(b-t.second)*std::cos(ugao);
    } 
    
    void Skaliraj(double faktor) {
        auto t(DajCentar());
        if(std::abs(faktor)<0) throw std::domain_error("Nekorektan faktor skaliranja");
        tac1.first=t.first+faktor*(tac1.first-t.first);
        tac1.second=t.second+faktor*(tac1.second-t.second);
        tac2.first=t.first+faktor*(tac2.first-t.first);
        tac2.second=t.second+faktor*(tac2.second-t.second);
        tac3.first=t.first+faktor*(tac3.first-t.first);
        tac3.second=t.second+faktor*(tac3.second-t.second);
        if(faktor<0) Rotiraj(t,180);
    } 
    
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);  
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);  
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2); 
    
};

    bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2) {
        if((Trougao::Uporedi(t1.tac1,t2.tac1) && Trougao::Uporedi(t1.tac2,t2.tac2) && Trougao::Uporedi(t1.tac3,t2.tac3)) ||
        (Trougao::Uporedi(t1.tac1,t2.tac2) && Trougao::Uporedi(t1.tac2,t2.tac1) && Trougao::Uporedi(t1.tac3,t2.tac3)) ||
        (Trougao::Uporedi(t1.tac1,t2.tac3) && Trougao::Uporedi(t1.tac2,t2.tac2) && Trougao::Uporedi(t1.tac3,t2.tac1)) ||
        (Trougao::Uporedi(t1.tac1,t2.tac1) && Trougao::Uporedi(t1.tac2,t2.tac3) && Trougao::Uporedi(t1.tac3,t2.tac2)) ||
        (Trougao::Uporedi(t1.tac1,t2.tac2) && Trougao::Uporedi(t1.tac2,t2.tac3) && Trougao::Uporedi(t1.tac3,t2.tac1)) ||
        (Trougao::Uporedi(t1.tac1,t2.tac3) && Trougao::Uporedi(t1.tac2,t2.tac1) && Trougao::Uporedi(t1.tac3,t2.tac2)) ) return true;
        return false;
    }
    
    bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2) {
            if(std::abs(t1.DajStranicu(1)-t2.DajStranicu(1))<EPS && std::abs(t1.DajStranicu(2)-t2.DajStranicu(2))<EPS && std::abs(t1.DajStranicu(3)-t2.DajStranicu(3))<EPS &&
            t1.Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3))==t2.Orijentacija(t2.DajTjeme(1),t2.DajTjeme(2),t2.DajTjeme(3)) ) return true;
            
            if(std::abs(t1.DajStranicu(1) -t2.DajStranicu(1))<EPS && std::abs(t1.DajStranicu(2)-t2.DajStranicu(3))<EPS && std::abs(t1.DajStranicu(3)-t2.DajStranicu(2))<EPS &&
            t1.Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3))==t2.Orijentacija(t2.DajTjeme(1),t2.DajTjeme(3),t2.DajTjeme(2)) ) return true;
            
            if(std::abs(t1.DajStranicu(1) -t2.DajStranicu(2))<EPS && std::abs(t1.DajStranicu(2)-t2.DajStranicu(3))<EPS && std::abs(t1.DajStranicu(3)-t2.DajStranicu(1))<EPS &&
            t1.Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3))==t2.Orijentacija(t2.DajTjeme(2),t2.DajTjeme(3),t2.DajTjeme(1)) ) return true;
            
            if(std::abs(t1.DajStranicu(1) -t2.DajStranicu(3))<EPS && std::abs(t1.DajStranicu(2)-t2.DajStranicu(1))<EPS && std::abs(t1.DajStranicu(3)-t2.DajStranicu(2))<EPS &&
            t1.Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3))==t2.Orijentacija(t2.DajTjeme(3),t2.DajTjeme(1),t2.DajTjeme(2)) ) return true;
            
            if(std::abs(t1.DajStranicu(1) -t2.DajStranicu(2))<EPS && std::abs(t1.DajStranicu(2)-t2.DajStranicu(1))<EPS && std::abs(t1.DajStranicu(3)-t2.DajStranicu(3))<EPS &&
            t1.Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3))==t2.Orijentacija(t2.DajTjeme(2),t2.DajTjeme(1),t2.DajTjeme(3)) ) return true;
            
            if(std::abs(t1.DajStranicu(1) -t2.DajStranicu(3))<EPS && std::abs(t1.DajStranicu(2)-t2.DajStranicu(2))<EPS && std::abs(t1.DajStranicu(3)-t2.DajStranicu(1))<EPS &&
            t1.Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3))==t2.Orijentacija(t2.DajTjeme(3),t2.DajTjeme(2),t2.DajTjeme(1)) ) return true;
           
      return false;
     }
   bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2) {
       if(std::abs(t1.DajUgao(1) -t2.DajUgao(1))<EPS && std::abs(t1.DajUgao(2)-t2.DajUgao(2))<EPS &&
            t1.Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3))==t2.Orijentacija(t2.DajTjeme(1),t2.DajTjeme(2),t2.DajTjeme(3)) ) return true;
            
            if(std::abs(t1.DajUgao(1) -t2.DajUgao(1))<EPS && std::abs(t1.DajUgao(2)-t2.DajUgao(3))<EPS &&
            t1.Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3))==t2.Orijentacija(t2.DajTjeme(1),t2.DajTjeme(3),t2.DajTjeme(2)) ) return true;
            
            if(std::abs(t1.DajUgao(1) -t2.DajUgao(2))<EPS && std::abs(t1.DajUgao(2)-t2.DajUgao(3))<EPS &&
            t1.Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3))==t2.Orijentacija(t2.DajTjeme(2),t2.DajTjeme(3),t2.DajTjeme(1)) ) return true;
            
            if(std::abs(t1.DajUgao(1) -t2.DajUgao(3))<EPS && std::abs(t1.DajUgao(2)-t2.DajUgao(1))<EPS &&
            t1.Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3))==t2.Orijentacija(t2.DajTjeme(3),t2.DajTjeme(1),t2.DajTjeme(2)) ) return true;
            
            if(std::abs(t1.DajUgao(1) -t2.DajUgao(2))<EPS && std::abs(t1.DajUgao(2)-t2.DajUgao(1))<EPS &&
            t1.Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3))==t2.Orijentacija(t2.DajTjeme(2),t2.DajTjeme(1),t2.DajTjeme(3)) ) return true;
            
            if(std::abs(t1.DajUgao(1) -t2.DajUgao(3))<EPS && std::abs(t1.DajUgao(2)-t2.DajUgao(2))<EPS  &&
            t1.Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3))==t2.Orijentacija(t2.DajTjeme(3),t2.DajTjeme(2),t2.DajTjeme(1)) ) return true;
           
      return false;
     }
int main ()
{
    Tacka t1,t2,t3;
    std::cout<<"Koliko zelite kreirati trouglova: ";
    int n(-1);
    while(n<=0) {
        std::cin>>n;
    }
    std::vector<std::shared_ptr<Trougao>> vektor;
    vektor.resize(n);
    for(int i=0; i<n; i++) {
        std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        double x1,x2,x3,y1,y2,y3;
        std::cin>>x1>>y1>>x2>>y2>>x3>>y3;
        Tacka t1({x1,y1});
        Tacka t2({x2,y2});
        Tacka t3({x3,y3});
        try {
            vektor[i]=std::make_shared<Trougao>(t1,t2,t3);
        }
        catch(std::domain_error greska) {
            std::cout<<greska.what()<<", ponovite unos!"<<std::endl;
            i--;
        }
    }
    
    std::cout<<"Unesite vektor translacije (dx dy): ";
    double dx,dy;
    std::cin>>dx>>dy;
    
    std::cout<<"Unesite ugao rotacije: ";
    double ugao;
    std::cin>>ugao;
    
    std::cout<<"Unesite faktor skaliranja: ";
    double f;
    std::cin>>f;
    
    std::cout<<"Trouglovi nakon obavljenih transformacija:"<<std::endl;
    std::transform(vektor.begin(), vektor.end(), vektor.begin(), [dx,dy,ugao,f](std::shared_ptr<Trougao> t1) {
       t1->Transliraj(dx,dy);
       t1->Rotiraj(ugao);
        t1->Skaliraj(t1->DajTjeme(1), f);
        return t1;
    });
    
    std::sort(vektor.begin(), vektor.end(), [](const std::shared_ptr<Trougao> t1, const std::shared_ptr<Trougao> t2) {
        return t1->DajPovrsinu()<t2->DajPovrsinu();
    });
    
    std::for_each(vektor.begin(), vektor.end(), [](std::shared_ptr<Trougao> t) {
        t->Ispisi();
        std::cout<<std::endl;
    });
    
    std::cout<<"Trougao sa najmanjim obimom: ";
    auto pok(std::min_element(vektor.begin(), vektor.end(), [](const std::shared_ptr<Trougao> t1, const std::shared_ptr<Trougao> t2 ) {
        return t1->DajObim()<t2->DajObim();
    }));
    if(n!=0) (*pok)->Ispisi();
    std::cout<<std::endl;
    
    std::vector<std::pair<std::shared_ptr<Trougao>, std::shared_ptr<Trougao>>> parovi;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(DaLiSuIdenticni(*vektor[i],*vektor[j])==1){
                parovi.push_back(std::make_pair(vektor[i],vektor[j]));
            }
        }
    }
    if(parovi.size()!=0){
        std::cout<<"Parovi identicnih trouglova:"<<std::endl;
        for(int i=0; i<parovi.size(); i++){
            parovi[i].first->Ispisi();
            std::cout<<" i ";
            parovi[i].second->Ispisi();
            std::cout<<std::endl;
        }
    }
    else {
        std::cout<< "Nema identicnih trouglova!"<< std::endl;
    }
    
    std::vector<std::pair<std::shared_ptr<Trougao>, std::shared_ptr<Trougao>>> podudarni;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(DaLiSuPodudarni(*vektor[i],*vektor[j])){
                podudarni.push_back(std::make_pair(vektor[i],vektor[j]));
            }
        }
    }
    if(podudarni.size()!=0){
        std::cout<<"Parovi podudarnih trouglova:" <<std::endl;
        for(int i=0; i<podudarni.size(); i++){
            podudarni[i].first->Ispisi();
            std::cout<<" i ";
            podudarni[i].second->Ispisi();
            std::cout<<std::endl;
        }
    }
    else {
        std::cout<< "Nema podudarnih trouglova!" <<std::endl;
    }
    
    std::vector<std::pair<std::shared_ptr<Trougao>, std::shared_ptr<Trougao>>> slicni;
    
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(DaLiSuSlicni(*vektor[i],*vektor[j])){
                slicni.push_back(std::make_pair(vektor[i],vektor[j]));
            }
        }
    }
    if(slicni.size()!=0){
        std::cout<<"Parovi slicnih trouglova:" <<std::endl;
        for(int i=0; i<slicni.size(); i++){
            slicni[i].first->Ispisi();
            std::cout<<" i ";
            slicni[i].second->Ispisi();
            std::cout<<std::endl;
        }
    }
    else {
        std::cout<< "Nema slicnih trouglova!" << std::endl;
    }
    
    
  /*  Trougao t1(std::make_pair(1,3),std::make_pair(1,5),std::make_pair(3,3)), t2(std::make_pair(1,3),std::make_pair(3,3),std::make_pair(1,5));
    auto rez=DaLiSuPodudarni(t1,t2);
    std::cout<<rez;*/
    
	return 0;
}