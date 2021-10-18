/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <cmath>
#include <stdexcept>
#include <vector>
#include <memory>
#include <algorithm>
typedef std::pair<double, double> Tacka;
class Trougao
{
    Tacka t1,t2,t3;
public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        if(Orijentacija(t1,t2,t3)==0) throw std::domain_error ("Nekorektne pozicije tjemena");
        Trougao::t1=t1;
        Trougao::t2=t2;
        Trougao::t3=t3;
    };
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        if(Orijentacija(t1,t2,t3)==0) throw std::domain_error ("Nekorektne pozicije tjemena");
        Trougao::t1=t1;
        Trougao::t2=t2;
        Trougao::t3=t3;
    };
    void Postavi(int indeks, const Tacka &t);
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    Tacka DajTjeme(int indeks) const;
    double DajStranicu(int indeks) const;
    double DajUgao(int indeks) const;
    Tacka DajCentar() const;
    double DajObim() const;
    double DajPovrsinu() const;
    bool DaLiJePozitivnoOrijentiran() const;
    bool DaLiJeUnutra(const Tacka &t) const;
    void Ispisi() const;
    void Transliraj(double delta_x, double delta_y);
    void Centriraj(const Tacka &t);
    void Rotiraj(const Tacka &t, double ugao);
    void Skaliraj(const Tacka &t, double faktor);
    void Rotiraj(double ugao);
    void Skaliraj(double faktor);
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
    static bool Poredi(double x, double y) {
        const double eps(1e-10);
        if(std::fabs(x-y)<=eps* (std::fabs(x) + std::fabs(y))) return true;
        return false;
    };
     static bool Poredi(double x, double y, double z) {
        const double eps(1e-10);
        if(std::fabs(x-y)<=eps* (std::fabs(x) + std::fabs(y)) && std::fabs(x-z)<=eps* (std::fabs(x) + std::fabs(z)) && std::fabs(y-z)<=eps* (std::fabs(y) + std::fabs(z))) return true;
        return false;
    };

};
int main ()
{
    std::cout<<"Koliko zelite kreirati trouglova: ";
    int n;
    std::cin>>n;
    Tacka t1, t2,t3;
    std::vector<std::shared_ptr<Trougao>> v;

    int i(0);
    while(i<n) {
        double x,y,a,b,c,d;
        std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        std::cin>>x >>y >>a >>b >>c >>d;
        t1= std::make_pair(x,y);
        t2= std::make_pair(a,b);
        t3= std::make_pair(c,d);
        if(Trougao::Orijentacija(t1,t2,t3)==0)  {
            std::cout<<"Nekorektne pozicije tjemena, ponovite unos!"<<std::endl;  ;
            i--;
        } else
            try {
                std:: shared_ptr<Trougao> pomocni(std::make_shared<Trougao>(Trougao(t1, t2, t3)));
                v.push_back(pomocni);
            } catch(std::domain_error x) {
                std:: cout<<x.what();
            }
        i++;
    }
    std::vector<std::shared_ptr<Trougao>> v1(v);
    std::cout<<"Unesite vektor translacije (dx dy): ";
    double dx,dy;
    std::cin>>dx >>dy;
    std::cout<<" Unesite ugao rotacije: ";
    double ugao;
    std::cin>>ugao;
    std::cout<<"Unesite faktor skaliranja: ";
    double faktor;
    std::cin>>faktor;
    std::cout<<"Trouglovi nakon obavljenih transformacija: "<<std::endl;
    std::transform(v.begin(), v.end() , v.begin() , [dx,dy](std::shared_ptr<Trougao> t){return t->Transliraj(dx,dy);});
    std::sort(v.begin(), v.end(), [](std::shared_ptr<Trougao> prvi, std::shared_ptr<Trougao> drugi) {
        return (prvi->DajPovrsinu()>drugi->DajPovrsinu());
    });
    std::for_each(v.begin(), v.end(), [](std::shared_ptr<Trougao> t) {
        t->Ispisi();
    });

   
    std::shared_ptr<Trougao> x;
    std::cout<<"Trougao sa najmanjim obimom: ";
   x=*std::min_element(v.begin(), v.end(), [](std::shared_ptr<Trougao> prvi, std::shared_ptr<Trougao> drugi){ return (prvi->DajObim()<drugi->DajObim());});
   x->Ispisi();



    return 0;
}
void Trougao::Postavi (int indeks, const Tacka &t)
{
    if(indeks<1 || indeks>3) throw std::range_error ("Nekorektan indeks");
    if(Poredi(indeks,1)) {
        if(Orijentacija(t,t2,t3)==0) throw std::domain_error ("Nekorektne pozicije tjemena");
        t1=t;
    }
    if(Poredi(indeks,2)) {
        if(Orijentacija(t1,t,t3)==0) throw std::domain_error ("Nekorektne pozicije tjemena");
        t2=t;
    }
    if(Poredi(indeks,3)) {
        if(Orijentacija(t1,t2,t)==0) throw std::domain_error ("Nekorektne pozicije tjemena");
        t3=t;
    }
};

int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3)
{
    double x;
    x=t1.first*(t2.second-t3.second)+t2.first*(t3.second-t1.second)+t3.first*(t1.second-t2.second);
    int l;
    if(x<0) l=-1;
    if(x>0) l=1;
    if(Poredi(x,0))  l=0;
    return l;
};

Tacka Trougao::DajTjeme(int indeks) const
{
    if(indeks<1 || indeks>3) throw std::range_error ("Nekorektan indeks");
    Tacka x;
    if(Poredi(indeks,1)) x=t1;
    if(Poredi(indeks,2))x= t2;
    if(Poredi(indeks,3))x= t3;
    return x;
};

double Trougao::DajStranicu(int indeks) const
{
    if(indeks<1 || indeks>3) throw std::range_error ("Nekorektan indeks");
    double x;

    if(Poredi(indeks,1))  x=sqrt(pow(t2.first-t3.first,2)+pow(t2.second-t3.second,2));
    if(Poredi(indeks,2))  x=sqrt(pow(t1.first-t3.first,2)+pow(t1.second-t3.second,2));
    if(Poredi(indeks,3))  x=sqrt(pow(t1.first-t2.first,2)+pow(t1.second-t2.second,2));
    return x;
};

double Trougao::DajUgao(int indeks) const
{
    if(indeks<1 || indeks>3) throw std::range_error ("Nekorektan indeks");
    double x;
    if(indeks==1)  x=std::acos(((DajStranicu(3)*DajStranicu(3))+(DajStranicu(2)*DajStranicu(2))-(DajStranicu(1)*DajStranicu(1)))/(2*DajStranicu(2)*DajStranicu(3)));
    if(indeks==2)  x=std::acos(((DajStranicu(3)*DajStranicu(3))+(DajStranicu(1)*DajStranicu(1))-(DajStranicu(2)*DajStranicu(2)))/(2*DajStranicu(1)*DajStranicu(3)));
    if(indeks==3) x=std::acos(((DajStranicu(1)*DajStranicu(1))+(DajStranicu(2)*DajStranicu(2))-(DajStranicu(3)*DajStranicu(3)))/(2*DajStranicu(2)*DajStranicu(1)));
    return x;
};


double Trougao::DajObim() const
{
    double o;
    o=DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
    return o;
};

Tacka Trougao::DajCentar() const
{
    Tacka t;
    t.first=(t1.first+t2.first+t3.first)/3;
    t.second=(t1.second+t2.second+t3.second)/3;
    return t;
};

double Trougao::DajPovrsinu() const
{
    double p;
    p=abs( t1.first*(t2.second-t3.second)+t2.first*(t3.second-t1.second)+t3.first*(t1.second-t2.second))/2;
    return p;
};
bool Trougao::DaLiJePozitivnoOrijentiran() const
{
    if(Orijentacija(t1,t2,t3)>0) return true;
    else return false;

};
bool Trougao::DaLiJeUnutra(const Tacka &t) const
{
    if((Orijentacija(t1,t2,t3)>0 && Orijentacija(t1,t2,t)>0 && Orijentacija(t2,t3,t)>0 && Orijentacija(t3,t1,t)>0) ||
            (Orijentacija(t1,t2,t3)<0 && Orijentacija(t1,t2,t)<0 && Orijentacija(t2,t3,t)<0 && Orijentacija(t3,t1,t)<0)) return true;
    else return false;
};
void Trougao::Ispisi() const
{
    std::cout<<"(("<<t1.first<<","<<t1.second<<")"<<","<<"("<<t2.first<<","<<t2.second<<")"<<","<<"("<<t3.first<<","<<t3.second<<"))"<<std::endl;
};

void Trougao::Transliraj(double delta_x, double delta_y)
{
    t1.first += delta_x;
    t2.first += delta_x;
    t3.first += delta_x;
    t1.second += delta_y;
    t2.second += delta_y;
    t3.second += delta_y;
};
void Trougao::Centriraj(const Tacka &t)
{
    double x,y;
    Tacka c;
    c=DajCentar();
    x=c.first+t.first;
    y=c.second+t.second;
    Transliraj(x,y);
};
void Trougao::Rotiraj(const Tacka &t, double ugao)
{
    Centriraj(t);
    t1.first=t.first+(t1.first-t.first)*cos(ugao)-(t1.second-t.second)*sin(ugao);
    t1.second=t.second+(t1.first-t.first)*sin(ugao)+(t1.second-t.second)*cos(ugao);
    t2.first=t.first+(t2.first-t.first)*cos(ugao)-(t2.second-t.second)*sin(ugao);
    t2.second=t.second+(t2.first-t.first)*sin(ugao)+(t2.second-t.second)*cos(ugao);
    t3.first=t.first+(t3.first-t.first)*cos(ugao)-(t3.second-t.second)*sin(ugao);
    t3.second=t.second+(t3.first-t.first)*sin(ugao)+(t3.second-t.second)*cos(ugao);
};
void Trougao::Skaliraj(const Tacka &t, double faktor)
{
    Centriraj(t);
    if(Poredi(faktor,0)) throw std::domain_error ("Neispravan faktor skaliranja");
    if(faktor<0) Rotiraj(4*atan(1));
    t1.first=t.first+faktor*(t1.first-t.first);
    t1.second=t.second+faktor*(t1.second-t.second);
    t2.first=t.first+faktor*(t2.first-t.first);
    t2.second=t.second+faktor*(t2.second-t.second);
    t3.first=t.first+faktor*(t3.first-t.first);
    t3.second=t.second+faktor*(t3.second-t.second);

};
void Trougao::Rotiraj( double ugao)
{
    Tacka t;
    t=DajCentar();
    t1.first=t.first+(t1.first-t.first)*cos(ugao)-(t1.second-t.second)*sin(ugao);
    t1.second=t.second+(t1.first-t.first)*sin(ugao)+(t1.second-t.second)*cos(ugao);
    t2.first=t.first+(t2.first-t.first)*cos(ugao)-(t2.second-t.second)*sin(ugao);
    t2.second=t.second+(t2.first-t.first)*sin(ugao)+(t2.second-t.second)*cos(ugao);
    t3.first=t.first+(t3.first-t.first)*cos(ugao)-(t3.second-t.second)*sin(ugao);
    t3.second=t.second+(t3.first-t.first)*sin(ugao)+(t3.second-t.second)*cos(ugao);
};

void Trougao::Skaliraj( double faktor)
{
    Tacka t;
    t=DajCentar();
    if(Poredi(faktor,0)) throw std::domain_error ("Neispravan faktor skaliranja");
    if(faktor<0) Rotiraj(4*atan(1));
    t1.first=t.first+faktor*(t1.first-t.first);
    t1.second=t.second+faktor*(t1.second-t.second);
    t2.first=t.first+faktor*(t2.first-t.first);
    t2.second=t.second+faktor*(t2.second-t.second);
    t3.first=t.first+faktor*(t3.first-t.first);
    t3.second=t.second+faktor*(t3.second-t.second);

};

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2)
{
    if((t1.t1==t2.t1) && (t1.t2==t2.t2) && (t1.t3==t2.t3)) return true;
    if((t1.t1==t2.t1) && (t1.t2==t2.t3) && (t1.t3==t2.t2)) return true;
    if((t1.t1==t2.t2) && (t1.t2==t2.t1) && (t1.t3==t2.t3)) return true;
    if((t1.t1==t2.t2) && (t1.t2==t2.t3) && (t1.t3==t2.t1)) return true;
    if((t1.t1==t2.t3) && (t1.t2==t2.t1) && (t1.t3==t2.t2)) return true;
    if((t1.t1==t2.t3) && (t1.t2==t2.t2) && (t1.t3==t2.t1)) return true;

    return false;
};
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
    bool x;
    if((Trougao::Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2), t1.DajTjeme(3)) >0 && Trougao::Orijentacija(t2.DajTjeme(1),t2.DajTjeme(2), t2.DajTjeme(3)) >0) || (Trougao::Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2), t1.DajTjeme(3)) <0 && Trougao::Orijentacija(t2.DajTjeme(1),t2.DajTjeme(2), t2.DajTjeme(3)) <0)){
        if(Trougao::Poredi(t1.DajStranicu(1),t2.DajStranicu(1)) && Trougao::Poredi(t1.DajStranicu(2),t2.DajStranicu(2)) && Trougao::Poredi(t1.DajStranicu(3),t2.DajStranicu(3))) x= true;
         if(Trougao::Poredi(t1.DajStranicu(1),t2.DajStranicu(2)) && Trougao::Poredi(t1.DajStranicu(2),t2.DajStranicu(3)) && Trougao::Poredi(t1.DajStranicu(3),t2.DajStranicu(1))) x= true;
          if(Trougao::Poredi(t1.DajStranicu(1),t2.DajStranicu(3)) && Trougao::Poredi(t1.DajStranicu(2),t2.DajStranicu(1)) && Trougao::Poredi(t1.DajStranicu(3),t2.DajStranicu(2))) x= true;
           if(Trougao::Poredi(t1.DajStranicu(1),t2.DajStranicu(1)) && Trougao::Poredi(t1.DajStranicu(2),t2.DajStranicu(3)) && Trougao::Poredi(t1.DajStranicu(3),t2.DajStranicu(2))) x= true;
    }
    else return false;
   return x;
};
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
    bool x;
       if((Trougao::Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2), t1.DajTjeme(3)) >0 && Trougao::Orijentacija(t2.DajTjeme(1),t2.DajTjeme(2), t2.DajTjeme(3)) >0) || (Trougao::Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2), t1.DajTjeme(3)) <0 && Trougao::Orijentacija(t2.DajTjeme(1),t2.DajTjeme(2), t2.DajTjeme(3)) <0)){
        if(Trougao::Poredi(t1.DajStranicu(1)/t2.DajStranicu(1) , t1.DajStranicu(2)/t2.DajStranicu(2),  t1.DajStranicu(3)/t2.DajStranicu(3))) x= true;
         if(Trougao::Poredi(t1.DajStranicu(1)/t2.DajStranicu(2) , t1.DajStranicu(2)/t2.DajStranicu(3) , t1.DajStranicu(3)/t2.DajStranicu(1))) x= true;
          if(Trougao::Poredi(t1.DajStranicu(1)/t2.DajStranicu(3), t1.DajStranicu(2)/t2.DajStranicu(1) , t1.DajStranicu(3)/t2.DajStranicu(2))) x= true;
           if(Trougao::Poredi(t1.DajStranicu(1)/t2.DajStranicu(1) , t1.DajStranicu(2)/t2.DajStranicu(3) , t1.DajStranicu(3)/t2.DajStranicu(2))) x= true;
    }
    else x=false;
   return x;
};