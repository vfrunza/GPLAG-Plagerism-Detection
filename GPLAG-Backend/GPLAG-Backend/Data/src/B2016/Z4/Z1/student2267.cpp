/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <utility>
#include <vector>
#include <memory>
#include <algorithm>
#define epsilon 0.0000000001

typedef std::pair<double,double> Tacka;

class Trougao
{
private:
    Tacka  t1,t2,t3;
    static bool PorediNaJednakost(const Tacka &koordinata_1,const Tacka &koordinata_2);
    static bool Poredi(double d1, double d2);
    double DuzinaStranice(const Tacka &t_prvo, const Tacka &t_drugo)const {
        double duzina=std::sqrt((t_drugo.first-t_prvo.first)*(t_drugo.first-t_prvo.first)+(t_drugo.second-t_prvo.second)*(t_drugo.second-t_prvo.second));
        return duzina;
    }
    double DuzinaStranice(const Tacka &t_prvo, const Tacka &t_drugo) {
        double duzina=std::sqrt((t_drugo.first-t_prvo.first)*(t_drugo.first-t_prvo.first)+(t_drugo.second-t_prvo.second)*(t_drugo.second-t_prvo.second));
        return duzina;
    }
    double PovrsinaTrougla(const Tacka &t1, const Tacka &t2, const Tacka &t3)const {
        double P=std::abs(t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second));
        P=P/2.;
        return P;
    }
public:

    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        if(Orjentacija(t1,t2,t3)==0 && (!(std::fabs(t1.first-t1.second)<epsilon && std::fabs(t2.first-t2.second)<epsilon && std::fabs(t3.first-t3.second)<epsilon))) throw std::domain_error("Nekorektne pozicije tjemena");
        Postavi(t1,t2,t3);
    }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        Trougao::t1=t1;
        Trougao::t2=t2;
        Trougao::t3=t3;
    }
    void Postavi(int indeks,const Tacka &t) {
        if(indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error("Nekorektan indeks");
          DajTjeme(indeks)=t;
           if(Orjentacija(t1,t2,t3)==0)  throw std::domain_error("Nekorektne pozicije tjemena");
    }
    static int Orjentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    Tacka DajTjeme(int indeks) const {
        if(indeks==1)   return t1;
        if(indeks==2)   return t2;
        if(indeks==3)   return t3;
    }
    double DajStranicu(int indeks) const;
    double DajUgao(int indeks) const;
    Tacka DajCentar()const;
    double DajObim()const;
    double DajPovrsinu()const {
        double P=PovrsinaTrougla(t1,t2,t3);
        return P;
    }
    bool DaLiJePozitivnoOrijentiran()const {
        if(Orjentacija(t1,t2,t3)>0)     return true;
        return false;
    }
    bool DaLiJeUnutra(const Tacka &t) const;
    void Ispisi()const {
        std::cout<<"(("<<t1.first<<","<<t1.second<<"),("<<t2.first<<","<<t2.second<<"),("<<t3.first<<","<<t3.second<<"))";
    }
    void Transliraj(double delta_x,double delta_y);
    void Centriraj(const Tacka &t);
    void Rotiraj(const Tacka &t,double ugao);
    void Skaliraj(const Tacka &t, double faktor);
    void Rotiraj(double ugao);
    void Skaliraj(double faktor);
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);

};
bool Trougao::Poredi(double d1, double d2)
{

    if(std::fabs(d1-d2)<epsilon)    return true;
    return false;
}

bool Trougao::PorediNaJednakost(const Tacka &prva, const Tacka &druga)
{

    if(std::fabs(prva.first-druga.first)<epsilon && std::fabs(prva.second-druga.second)<epsilon)    return true;
    return false;
}


Tacka Trougao::DajCentar()const
{
    Tacka t;
    t.first=(t1.first+t2.first+t3.first)/3.;
    t.second=(t1.second+t2.second+t3.second)/3.;
    return t;
}



double Trougao::DajUgao(int indeks)const
{
    if(indeks!=1 && indeks!=2 && indeks!=3)     throw std::range_error("Nekorektan indeks");
    double b=DuzinaStranice(Trougao::t1,Trougao::t3);
    double c=DuzinaStranice(t1,t2);
    double a=DuzinaStranice(t2,t3);
    double ugao;
    if(indeks==1) {
        ugao=std::acos((double)((b*b+c*c-a*a)/(2*b*c)));
    }
    if(indeks==2) {
        ugao=std::acos((double)((a*a+c*c-b*b)/(2*a*c)));
    }
    if(indeks==3) {
        ugao=std::acos((double)((a*a+b*b-c*c)/(2*a*b)));
    }

    return ugao;
}



double Trougao::DajStranicu(int indeks) const
{   
    if(indeks!=1 && indeks!=2 && indeks!=3)     throw std::range_error("Nekorektan indeks");
    double d;
    if(indeks==1)   d=DuzinaStranice(t2,t3);
    if(indeks==2)   d=DuzinaStranice(t1,t3);
    if(indeks==3)   d=DuzinaStranice(t1,t2);
    return d;
}

double Trougao::DajObim()const
{

    double d1=DuzinaStranice(t1,t2);
    double d2=DuzinaStranice(t2,t3);
    double d3=DuzinaStranice(t1,t3);
    double O(d1+d2+d3);
    return O;
}

int Trougao::Orjentacija(const Tacka &t1,const Tacka &t2,const Tacka &t3)
{
    double P=(t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second));
    if(P>0) return 1;
    if(P<0) return -1;
    if(std::fabs(P-0)<epsilon) return 0;

}

bool Trougao::DaLiJeUnutra(const Tacka &t)const
{
    double P=PovrsinaTrougla(t1,t2,t3);
    double P_1=PovrsinaTrougla(t1,t2,t);
    double P_2=PovrsinaTrougla(t2,t3,t);
    double P_3=PovrsinaTrougla(t1,t3,t);

    if(std::fabs(P-(P_1+P_2+P_3))<epsilon)  return true;
    return false;
}

void Trougao::Transliraj(double delta_x, double delta_y)
{
    t1.first=t1.first+delta_x;
    t1.second=t1.second+delta_y;
    t2.first=t2.first+delta_x;
    t2.second=t2.second+delta_y;
    t3.first=t3.first+delta_x;
    t3.second=t3.second+delta_y;
}

void Trougao::Centriraj(const Tacka &t)
{

    Tacka c=DajCentar();
    double delta_x=t.first-c.first;
    double delta_y=t.second-c.second;
    Transliraj(delta_x,delta_y);

}

void Trougao::Rotiraj(const Tacka &t,double ugao)
{
    auto x=t1.first;
    auto x1=t2.first;
    auto x2=t3.first;
    t1.first=t.first+(t1.first-t.first)*std::cos(ugao)-std::sin(ugao)*(t1.second-t.second);
    t1.second=t.second+(x-t.first)*std::sin(ugao)+std::cos(ugao)*(t1.second-t.second);
    t2.first=t.first+(t2.first-t.first)*std::cos(ugao)-std::sin(ugao)*(t2.second-t.second);
    t2.second=t.second+(x1-t.first)*std::sin(ugao)+std::cos(ugao)*(t2.second-t.second);
    t3.first=t.first+(t3.first-t.first)*std::cos(ugao)-std::sin(ugao)*(t3.second-t.second);
    t3.second=t.second+(x2-t.first)*std::sin(ugao)+std::cos(ugao)*(t3.second-t.second);

}

void Trougao::Skaliraj(const Tacka &t,double faktor)
{

    if(std::fabs(faktor)<epsilon)   throw std::domain_error("Nekorektan faktor skaliranja");

    t1.first=t.first+faktor*(t1.first-t.first);
    t1.second=t.second+faktor*(t1.second-t.second);
    t2.first=t.first+faktor*(t2.first-t.first);
    t2.second=t.second+faktor*(t2.second-t.second);
    t3.first=t.first+faktor*(t3.first-t.first);
    t3.second=t.second+faktor*(t3.second-t.second);

}

void Trougao::Rotiraj(double ugao)
{
    auto xc=DajCentar().first;
    auto yc=DajCentar().second;
    t1.first=xc+(t1.first-xc)*std::cos(ugao)-std::sin(ugao)*(t1.second-yc);
    t1.second=yc+(t1.first-xc)*std::sin(ugao)+std::cos(ugao)*(t1.second-yc);
    t2.first=xc+(t2.first-xc)*std::cos(ugao)-std::sin(ugao)*(t2.second-yc);
    t2.second=yc+(t2.first-xc)*std::sin(ugao)+std::cos(ugao)*(t2.second-yc);
    t3.first=xc+(t3.first-xc)*std::cos(ugao)-std::sin(ugao)*(t3.second-yc);
    t3.second=yc+(t3.first-xc)*std::sin(ugao)+std::cos(ugao)*(t3.second-yc);

}

void Trougao::Skaliraj(double faktor)
{

    if(std::fabs(faktor)<epsilon)   throw std::domain_error("Nekorektan faktor skaliranja");
    t1.first=DajCentar().first+faktor*(t1.first-DajCentar().first);
    t1.second=DajCentar().second+faktor*(t1.second-DajCentar().second);
    t2.first=DajCentar().first+faktor*(t2.first-DajCentar().first);
    t2.second=DajCentar().second+faktor*(t2.second-DajCentar().second);
    t3.first=DajCentar().first+faktor*(t3.first-DajCentar().first);
    t3.second=DajCentar().second+faktor*(t3.second-DajCentar().second);
}

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2)
{
    int br_1(0);

    if(Trougao::PorediNaJednakost(t1.t1,t2.t1)) br_1++;
    if(Trougao::PorediNaJednakost(t1.t1,t2.t2))  br_1++;
    if(Trougao::PorediNaJednakost(t1.t1,t2.t3))  br_1++;

    int br_2(0);
    if(Trougao::PorediNaJednakost(t1.t2,t2.t1))  br_2++;
    if(Trougao::PorediNaJednakost(t1.t2,t2.t2))  br_2++;
    if(Trougao::PorediNaJednakost(t1.t2,t2.t3))  br_2++;
    int br_3(0);
    if(Trougao::PorediNaJednakost(t1.t3,t2.t1))  br_3++;
    if(Trougao::PorediNaJednakost(t1.t3,t2.t2))  br_3++;
    if(Trougao::PorediNaJednakost(t1.t3,t2.t3))  br_3++;
    if((br_1+br_2+br_3)==3 && br_1!=0 && br_2!=0 && br_3!=0)  return true;
    return false;
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
    
    double ugao1=t1.DajUgao(1);
    double ugao2=t1.DajUgao(2);
    double ugao3=t1.DajUgao(3);
    double ugao1_=t2.DajUgao(1);
    double ugao2_=t2.DajUgao(2);
    double ugao3_=t2.DajUgao(3);
    double d1=t1.DuzinaStranice(t1.DajTjeme(1),t1.DajTjeme(2)); double d1_=t2.DuzinaStranice(t2.DajTjeme(1),t2.DajTjeme(2));
    double d2=t1.DuzinaStranice(t1.DajTjeme(2),t1.DajTjeme(3)); double d2_=t2.DuzinaStranice(t2.DajTjeme(2),t2.DajTjeme(3));
    double d3=t1.DuzinaStranice(t1.DajTjeme(3),t1.DajTjeme(1)); double d3_=t2.DuzinaStranice(t2.DajTjeme(3),t2.DajTjeme(1));
    if((std::fabs(d1-d1_)<epsilon || std::fabs(d1-d2_)<epsilon || std::fabs(d1-d3_)<epsilon) && (std::fabs(d2-d1_)<epsilon || std::fabs(d2-d2_)<epsilon || std::fabs(d2-d3_)<epsilon) && (std::fabs(d3-d1_)<epsilon || std::fabs(d3-d2_)<epsilon || std::fabs(d3-d3_)<epsilon)){
    
    std::vector<std::pair<double,Tacka>>v1;
    v1.push_back(std::make_pair(ugao1,t1.DajTjeme(1)));
    v1.push_back(std::make_pair(ugao2,t1.DajTjeme(2)));
    v1.push_back(std::make_pair(ugao3,t1.DajTjeme(3)));
    std::sort(v1.begin(),v1.end(),[](std::pair<double,Tacka> m,std::pair<double,Tacka>n){
        return m.first<n.first;
    });
    std::vector<std::pair<double,Tacka>>v2;
    v2.push_back(std::make_pair(ugao1_,t2.DajTjeme(1)));
    v2.push_back(std::make_pair(ugao2_,t2.DajTjeme(2)));
    v2.push_back(std::make_pair(ugao3_,t2.DajTjeme(3)));
     std::sort(v2.begin(),v2.end(),[](std::pair<double,Tacka> m,std::pair<double,Tacka>n){
        return m.first<n.first;
    });
    
    if(t1.Orjentacija(v1[0].second,v1[1].second,v1[2].second)==t2.Orjentacija(v2[0].second,v2[1].second,v2[2].second))
            return true;
    }
    
return false;
    
}

bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
    double d1=t1.DuzinaStranice(t1.DajTjeme(1),t1.DajTjeme(2)); double d1_=t2.DuzinaStranice(t2.DajTjeme(1),t2.DajTjeme(2));
    double d2=t1.DuzinaStranice(t1.DajTjeme(2),t1.DajTjeme(3)); double d2_=t2.DuzinaStranice(t2.DajTjeme(2),t2.DajTjeme(3));
    double d3=t1.DuzinaStranice(t1.DajTjeme(3),t1.DajTjeme(1)); double d3_=t2.DuzinaStranice(t2.DajTjeme(3),t2.DajTjeme(1));
    if(DaLiSuPodudarni(t1,t2)==true){
        if(std::fabs(d1/d2/d3-d1_/d2_/d3_)<epsilon ||  std::fabs(d1/d2/d3-d1_/d3_/d2_)<epsilon  ||  std::fabs(d1/d2/d3-d2_/d3_/d1_)<epsilon  || std::fabs(d1/d2/d3-d2_/d1_/d3_)<epsilon  ||  std::fabs(d1/d2/d3-d3_/d1_/d2_)<epsilon || std::fabs(d1/d2/d3-d3_/d2_/d1_)<epsilon) 
                return true;
    }

    return false;
}




int main ()
{
   
    try {
         int n;
         std::cout<<"Koliko zelite kreirati trouglova: ";
         std::cin>>n;
        std::vector<std::shared_ptr<Trougao>> v;
        for(int i=0; i<n; i++) {
            Tacka tacka1, tacka2, tacka3;
            std::cout<<"Unesite podatke za "<<i+1<<"."<<" trougao (x1 y1 x2 y2 x3 y3): ";
            std::cin>>tacka1.first>>tacka1.second;
            std::cin>>tacka2.first>>tacka2.second;
            std::cin>>tacka3.first>>tacka3.second;
            double a=std::sqrt((tacka2.first-tacka1.first)*(tacka2.first-tacka1.first)+(tacka2.second-tacka1.second)*(tacka2.second-tacka1.second));
            double b=std::sqrt((tacka3.first-tacka2.first)*(tacka3.first-tacka2.first)+(tacka3.second-tacka2.second)*(tacka3.second-tacka2.second));
            double c=std::sqrt((tacka1.first-tacka3.first)*(tacka1.first-tacka3.first)+(tacka1.second-tacka3.second)*(tacka1.second-tacka3.second));
            if(!(a>0 && b>0 && c>0 && (a+b)>c && (a+c)>b && (b+c)>a))     {
                std::cout<<"Nekorektne pozicije tjemena, ponovite unos!";
                i--;
                std::cout<<std::endl;
                continue;
            }
            auto t=std::make_shared<Trougao>(tacka1,tacka2,tacka3);
            v.push_back(t);

        }
        double x,y,faktor,ugao;


        std::cout<<"Unesite vektor translacije (dx dy): ";
        std::cin>>x>>y;
        std::cout<<"Unesite ugao rotacije: ";
        std::cin>>ugao;
        std::cout<<"Unesite faktor skaliranja:";
        std::cin>>faktor;
        std::transform(v.begin(),v.end(),v.begin(),[x,y,ugao,faktor]( std::shared_ptr<Trougao> &a) {
            a->Transliraj(x,y);
            a->Rotiraj(a->DajCentar(),ugao);
            a->Skaliraj(a->DajTjeme(1),faktor);
            return a;
        });
        

        std::cout<<" Trouglovi nakon obavljenih transformacija: "<<std::endl;
        std::sort(v.begin(),v.end(),[](std::shared_ptr<Trougao> a, std::shared_ptr<Trougao> b) {
            double P1=a->DajPovrsinu();
            double P2=b->DajPovrsinu();
            return P1<P2;
        });

        std::for_each(v.begin(),v.end(),[](std::shared_ptr<Trougao> a) {
            a->Ispisi();
            std::cout<<std::endl;
        });


        auto it=*std::min_element(v.begin(),v.end(),[](std::shared_ptr<Trougao> a, std::shared_ptr<Trougao> b) {
            double O1=a->DajObim();
            double O2=b->DajObim();
            return O1<O2;
        });
        int br(0),brojac(0);
        
        std::cout<<"Trougao sa najmanjim obimom: ";
        it->Ispisi();
        std::cout<<std::endl;
        
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(DaLiSuIdenticni(*v[i],*v[j])==1) {
                    if(brojac==0)     std::cout<<"Parovi identicnih trouglova: "<<std::endl;
                   v[i]->Ispisi();
                    std::cout<<" i ";
                    v[j]->Ispisi();
                     std::cout<<std::endl;
                     brojac++;
                }
             
            }
        }
        if(brojac==0)std::cout<<"Nema identicnih trouglova!"<<std::endl;
        
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(DaLiSuPodudarni(*v[i],*v[j])==1) {
                    if(br==0) std::cout<<"Parovi podudarnih trouglova: "<<std::endl;
                    v[i]->Ispisi();
                    std::cout<<" i ";
                    v[j]->Ispisi();
                    std::cout<<std::endl;
                    br++;
                }
             
            }
        }
        if(br==0)   std::cout<<"Nema podudarnih trouglova!"<<std::endl;
        br=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(DaLiSuSlicni(*v[i],*v[j])==1){
                    if(br==0) std::cout<<"Parovi slicnih trouglova: "<<std::endl;
                    v[i]->Ispisi();
                    std::cout<<" i ";
                    v[j]->Ispisi();
                    std::cout<<std::endl;
                    br++;
                }
            }
        }
        
        if(br==0)   std::cout<<"Nema slicnih trouglova!"<<std::endl;
        

        
    } catch(std::domain_error e) {
        std::cout<<e.what();
    }

    catch(std::range_error e) {
        std::cout<<e.what();
    }

    return 0;
}