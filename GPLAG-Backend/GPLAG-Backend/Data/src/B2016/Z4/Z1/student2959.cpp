/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <set>
#include <vector>
#include <memory>
#include <algorithm>
typedef std::pair<double,double> Tacka;

bool JesuLiJednaki1(double x, double y, double eps=1e-10){
        return std::fabs(x-y)<=eps*(std::fabs(x)+std::fabs(y));
    }
class Trougao{
    Tacka t1, t2, t3;
    static int Izraz(Tacka t1, Tacka t2, Tacka t3) {
        return t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
    }
    void KorektanIndeks(int indeks) const{
        if(indeks>=1 && indeks<=3) return;
        else throw std::domain_error("Nekorektne pozicije tjemena");
    }
    bool JesuLiJednaki(double x, double y, double eps=1e-10){
        return std::fabs(x-y)<=eps*(std::fabs(x)+std::fabs(y));
    }
    
    public:
    Trougao(const Tacka& t1, const Tacka& t2, const Tacka& t3){ Postavi(t1, t2, t3); }
    
    void Postavi(const Tacka& t1, const Tacka& t2, const Tacka& t3) { 
        if(Orijentacija(t1, t2, t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
        else Trougao::t1=t1; Trougao::t2=t2; Trougao::t3=t3;
        
    }
    void Postavi(int indeks, const Tacka& t){
        KorektanIndeks(indeks);
        if(indeks==1) t1=t;
        else if(indeks==2) t2=t;
        else t3=t;
    }
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        if(Izraz(t1, t2, t3)>0) return 1;
        else if(Izraz(t1, t2, t3)<0) return -1;
        else return 0;
    }
    Tacka DajTjeme(int indeks) const{
        KorektanIndeks(indeks);
        if(indeks==1) return t1;
        else if(indeks==2) return t2;
        else return t3;
    }
    double DajStranicu(int indeks) const;
    double DajUgao(int indeks) const;
    Tacka DajCentar() const{
        return std::make_pair((t1.first+t2.first+t3.first)/3, (t1.second+t2.second+t3.second)/3);
    }
    double DajObim() const{
        return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
    }
    double DajPovrsinu() const{
        return std::abs(Izraz(t1, t2, t3))/2.;
    }
    bool DaLiJePozitivnoOrijentiran() const { if(Orijentacija(t1,t2,t3)==1) return true; else return false; }
    bool DaLiJeUnutra(const Tacka &t) const;
    void Ispisi() const{
        std::cout<<"(("<<t1.first<<","<<t1.second<<"),"<<"("<<t2.first<<","<<t2.second<<"),"<<"("<<t3.first<<","<<t3.second<<"))";
    }
    void Transliraj(double delta_x, double delta_y){
        t1.first+=delta_x; t2.first+=delta_x; t3.first+=delta_x; 
        t1.second+=delta_y; t2.second+=delta_y; t3.second+=delta_y; 
    }
    void Centriraj(const Tacka &t);
    void Rotiraj(const Tacka &t, double ugao);
    void Skaliraj(const Tacka &t, double faktor);
    void Rotiraj(double ugao);
    void Skaliraj(double faktor);
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};
 double Trougao::DajStranicu(int indeks) const{
        KorektanIndeks(indeks);
        if(indeks==1) return (std::sqrt((t2.first-t3.first)*(t2.first-t3.first)+(t2.second-t3.second)*(t2.second-t3.second)));
        else if(indeks==2) return (std::sqrt((t1.first-t3.first)*(t1.first-t3.first)+(t1.second-t3.second)*(t1.second-t3.second)));
        else return (std::sqrt((t2.first-t1.first)*(t2.first-t1.first)+(t2.second-t1.second)*(t2.second-t1.second)));
    }
 double Trougao::DajUgao(int indeks) const{
        KorektanIndeks(indeks);
        double str1(DajStranicu(1)), str2(DajStranicu(2)), str3(DajStranicu(3));
        if(indeks==1) 
            return std::acos((str2*str2+str3*str3-str1*str1)/(2*str2*str3));
        else if(indeks==2)
            return std::acos((str1*str1+str3*str3-str2*str2)/(2*str1*str3));
        else return std::acos((str2*str2+str1*str1-str3*str3)/(2*str2*str1));
    }
 bool Trougao::DaLiJeUnutra(const Tacka &t) const{
        if(Orijentacija(t1,t2,t)==0 || Orijentacija(t1,t3,t)==0 || Orijentacija(t2,t3,t)==0) return false;
        if(Orijentacija(t1,t2,t3)==Orijentacija(t1,t2,t) && Orijentacija(t1,t2,t3)==Orijentacija(t2,t3,t) && Orijentacija(t1,t2,t3)==Orijentacija(t3,t1,t)) return true;
        else return false;
    }
 void Trougao::Centriraj(const Tacka &t){
        Tacka centar(DajCentar());
        int pomjerx(t.first-centar.first), pomjery(t.second-centar.second);
        t1.first+=pomjerx; t2.first+=pomjerx; t3.first+=pomjerx;
        t1.second+=pomjery; t2.second+=pomjery; t3.second+=pomjery;
    }
 void Trougao::Rotiraj(const Tacka &t, double ugao){
        t1.first=t.first+(t1.first-t.first)*std::cos(ugao)-(t1.second-t.second)*std::sin(ugao);
        t2.first=t.first+(t2.first-t.first)*std::cos(ugao)-(t2.second-t.second)*std::sin(ugao);
        t3.first=t.first+(t3.first-t.first)*std::cos(ugao)-(t3.second-t.second)*std::sin(ugao);
        
        t1.second=t.second+(t1.first-t.first)*std::sin(ugao)+(t1.second-t.second)*std::cos(ugao);
        t2.second=t.second+(t2.first-t.first)*std::sin(ugao)+(t2.second-t.second)*std::cos(ugao);
        t3.second=t.second+(t3.first-t.first)*std::sin(ugao)+(t3.second-t.second)*std::cos(ugao);
    }
 void Trougao::Skaliraj(const Tacka &t, double faktor){
     if(JesuLiJednaki(faktor, 0)) throw std::domain_error("Nekorektan faktor skaliranja");     
     else{
         t1.first=t.first+faktor*(t1.first-t.first);
         t2.first=t.first+faktor*(t2.first-t.first);
         t3.first=t.first+faktor*(t3.first-t.first);
         t1.second=t.second+faktor*(t1.second-t.second);
         t2.second=t.second+faktor*(t2.second-t.second);
         t3.second=t.second+faktor*(t3.second-t.second);
      }
    }
 void Trougao::Rotiraj(double ugao){
     Tacka t(DajCentar());
     Tacka t1k(t1), t2k(t2), t3k(t3);
     
     t1.first=t.first+(t1.first-t.first)*std::cos(ugao)-(t1.second-t.second)*std::sin(ugao);
     t2.first=t.first+(t2.first-t.first)*std::cos(ugao)-(t2.second-t.second)*std::sin(ugao);
     t3.first=t.first+(t3.first-t.first)*std::cos(ugao)-(t3.second-t.second)*std::sin(ugao);
        
     t1.second=t.second+(t1k.first-t.first)*std::sin(ugao)+(t1.second-t.second)*std::cos(ugao);
     t2.second=t.second+(t2k.first-t.first)*std::sin(ugao)+(t2.second-t.second)*std::cos(ugao);
     t3.second=t.second+(t3k.first-t.first)*std::sin(ugao)+(t3.second-t.second)*std::cos(ugao);
    }
 void Trougao::Skaliraj(double faktor){
     if(JesuLiJednaki(faktor, 0)) throw std::domain_error("Nekorektan faktor skaliranja");     
     else{
         Tacka t(DajCentar());
         t1.first=t.first+faktor*(t1.first-t.first);
         t2.first=t.first+faktor*(t2.first-t.first);
         t3.first=t.first+faktor*(t3.first-t.first);
         t1.second=t.second+faktor*(t1.second-t.second);
         t2.second=t.second+faktor*(t2.second-t.second);
         t3.second=t.second+faktor*(t3.second-t.second);
      }
    }
 bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
     std::set<Tacka> skup1{t1.t1, t1.t2, t1.t3}, skup2{t2.t1, t2.t2, t2.t3};
     if(skup1==skup2) return true;
     else return false;
 }
 bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
      Trougao trokut1{t1.t1,t1.t2,t1.t3}, trokut2{t2.t1, t2.t2, t2.t3};
     if(Trougao::Orijentacija(trokut1.t1,trokut1.t2,trokut1.t3)!=Trougao::Orijentacija(trokut2.t1,trokut2.t2,trokut2.t3)){
             Tacka pomocna=trokut2.t1;
             trokut2.t1=trokut2.t2;
             trokut2.t2=pomocna;
         }
         bool odnosi_isti(false);
         for(int i=0; i<3; i++)
         {
             if(JesuLiJednaki1(trokut1.DajStranicu(1),trokut2.DajStranicu(1)) && JesuLiJednaki1(trokut1.DajStranicu(2),trokut2.DajStranicu(2)) && JesuLiJednaki1(trokut1.DajStranicu(3),trokut2.DajStranicu(3)))
             {
                      
     std::vector<double>uglovi1{trokut1.DajUgao(1), trokut1.DajUgao(2), trokut1.DajUgao(3)}, uglovi2{trokut2.DajUgao(1), trokut2.DajUgao(2), trokut2.DajUgao(3)};
                if(uglovi2==uglovi1) odnosi_isti=true;
                 
             }
             else{
                 Tacka pomocna=trokut2.t1;
                 trokut2.t1=trokut2.t2;
                 trokut2.t2=trokut2.t3;
                 trokut2.t3=pomocna;
             }
         }
          return odnosi_isti;
         
 }
 
 bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
     Trougao trokut1{t1.t1,t1.t2,t1.t3}, trokut2{t2.t1, t2.t2, t2.t3};
     if(Trougao::Orijentacija(trokut1.t1,trokut1.t2,trokut1.t3)!=Trougao::Orijentacija(trokut2.t1,trokut2.t2,trokut2.t3)){
             Tacka pomocna=trokut2.t1;
             trokut2.t1=trokut2.t2;
             trokut2.t2=pomocna;
         }
         bool odnosi_isti(false);
         for(int i=0; i<3; i++)
         {
             if(JesuLiJednaki1(trokut1.DajStranicu(1)/trokut2.DajStranicu(1), trokut1.DajStranicu(2)/trokut2.DajStranicu(2)) &&  JesuLiJednaki1(trokut1.DajStranicu(1)/trokut2.DajStranicu(1), trokut1.DajStranicu(3)/trokut2.DajStranicu(3)))
             {
                      
     std::vector<double>uglovi1{trokut1.DajUgao(1), trokut1.DajUgao(2), trokut1.DajUgao(3)}, uglovi2{trokut2.DajUgao(1), trokut2.DajUgao(2), trokut2.DajUgao(3)};
                if(uglovi2==uglovi1) odnosi_isti=true;
                 
             }
             else{
                 Tacka pomocna=trokut2.t1;
                 trokut2.t1=trokut2.t2;
                 trokut2.t2=trokut2.t3;
                 trokut2.t3=pomocna;
             }
         }
          return odnosi_isti;
         
 }
 
 
 
int main ()
{
    try{
        
        int n; double x1,y1,x2,y2,x3,y3;
        std::cout<<"Koliko zelite kreirati trouglova: ";
        std::cin>>n;
        std::vector<std::shared_ptr<Trougao>> vektor(n);
        for(int i=0; i<n; i++)
        {
            try{
            std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
            std::cin>>x1>>y1>>x2>>y2>>x3>>y3;
            std::shared_ptr<Trougao> pok(new Trougao({{x1,y1},{x2,y2},{x3,y3}}));
            vektor[i]=pok;
            
            }
            catch(std::domain_error poruka) {std::cout<<poruka.what()<<", ponovite unos!\n"; i--;}
            
        }
        double translx,transly;
        std::cout<<"Unesite vektor translacije (dx dy): ";
        std::cin>>translx>>transly;
        std::cout<<"Unesite ugao rotacije: ";
        double ugao;
        std::cin>>ugao;
        double faktorsk;
        std::cout<<"Unesite faktor skaliranja: ";
        std::cin>>faktorsk;
        std::cout<<"Trouglovi nakon obavljenih transformacija:\n";
        
        std::transform(vektor.begin(), vektor.end(), vektor.begin(), [translx,transly, ugao, faktorsk](std::shared_ptr<Trougao> t){ (*t).Transliraj(translx,transly); (*t).Rotiraj(ugao); (*t).Skaliraj((*t).DajTjeme(1),faktorsk); return t;});
        std::sort(vektor.begin(), vektor.end(), [](std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2) {return (*t1).DajPovrsinu()<(*t2).DajPovrsinu();});
        std::for_each(vektor.begin(), vektor.end(), [](std::shared_ptr<Trougao> t) { t->Ispisi(); std::cout<<std::endl;});
        std::cout<<"Trougao sa najmanjim obimom: ";
        auto p=std::min_element(vektor.begin(), vektor.end(), [](std::shared_ptr<Trougao> t, std::shared_ptr<Trougao> t1) { return (*t).DajObim()<(*t1).DajObim();});
        (*p)->Ispisi();
        
        
        int brojac_identicnih(0);
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(DaLiSuIdenticni(*vektor[i],*vektor[j]))
                brojac_identicnih++;
            }
            
        }
        
        if(brojac_identicnih!=0)
        {
            std::cout<<"\nParovi identicnih trouglova:\n";
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(DaLiSuIdenticni(*vektor[i],*vektor[j]))
                {vektor[i]->Ispisi(); std::cout<<" i "; vektor[j]->Ispisi(); std::cout<<std::endl;}
            }
            
        }
        }
        else{
            std::cout<<"\nNema identicnih trouglova!";
        }
        
        
        
        int brojac_podudarnih(0);
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(DaLiSuPodudarni(*vektor[i],*vektor[j]))
                brojac_podudarnih++;
            }
            
        }
        
        if(brojac_podudarnih!=0)
        {
            std::cout<<"\nParovi podudarnih trouglova:\n";
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(DaLiSuPodudarni(*vektor[i],*vektor[j]))
                {vektor[i]->Ispisi(); std::cout<<" i "; vektor[j]->Ispisi(); std::cout<<std::endl;}
            }
            
        }
        }
        else{
            std::cout<<"\nNema podudarnih trouglova!";
        }
        
        
        
        int brojac_slicnih(0);
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(DaLiSuSlicni(*vektor[i],*vektor[j]))
                brojac_slicnih++;
            }
            
        }
        
        if(brojac_slicnih!=0)
        {
        std::cout<<"\nParovi slicnih trouglova:\n";
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(DaLiSuSlicni(*vektor[i],*vektor[j]))
                {vektor[i]->Ispisi(); std::cout<<" i "; vektor[j]->Ispisi(); std::cout<<std::endl;}
            }
            
        }
        }
        else{
            std::cout<<"\nNema slicnih trouglova!";
        }
    
    }
    catch(std::domain_error poruka) { std::cout<<poruka.what();}
    catch(std::range_error poruka1) {std::cout<<poruka1.what();}
    
	return 0;
}