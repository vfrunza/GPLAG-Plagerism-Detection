/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>
using namespace std;

typedef pair<double,double>Tacka;
class Trougao{
    Tacka t1,t2,t3;
    
    public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3)
    {
        int a=Orijentacija(t1,t2,t3);
        if(a==0) throw domain_error("Nekorektne pozicije tjemena");
        Trougao::t1=t1;
        Trougao::t2=t2;
        Trougao::t3=t3;
        
    }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3)
    {
        int a=Orijentacija(t1,t2,t3);
        if(a==0) throw domain_error("Nekorektne pozicije tjemena");
        Trougao::t1=t1;
        Trougao::t2=t2;
        Trougao::t3=t3;
    }
    void Postavi(int indeks, const Tacka &t);
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3)
    {
        double x1=t1.first,y1=t1.second,x2=t2.first,y2=t2.second,x3=t3.first,y3=t3.second;
        double a=x1*(y2-y3)-x2*(y1-y3)+x3*(y1-y2);
        if(a>0) return 1;
        else if(a<0) return -1;
        else return 0;
    }
    Tacka DajTjeme(int indeks) const{
        if(indeks <1 || indeks>3) throw range_error("Nekorektan indeks");
        if(indeks==1) return t1;
        else if(indeks==2) return t2;
        else return t3;
    }
    double DajStranicu(int indeks) const;
    double DajUgao(int indeks) const;
    Tacka DajCentar() const;
    double DajObim() const;
    double DajPovrsinu() const;
    bool DaLiJePozitivnoOrijentiran() const;
    bool DaLiJeUnutra(const Tacka &t) const;
    void Ispisi() const{
        cout<<"(("<<t1.first<<","<<t1.second<<"),("<<t2.first<<","<<t2.second<<"),("<<t3.first<<","<<t3.second<<"))";
    }
    void Transliraj(double delta_x, double delta_y);
    void Centriraj(const Tacka &t);
    void Rotiraj(const Tacka &t, double ugao);
    void Skaliraj(const Tacka &t, double faktor);
    void Rotiraj(double ugao);
    void Skaliraj(double faktor);
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};
void Trougao::Postavi(int indeks,const Tacka &t){
    if(indeks<1 || indeks>3) throw range_error("Nekorektan indeks");
    if(indeks==1) Trougao::t1=t;
    else if(indeks==2) Trougao::t2=t;
    else Trougao::t3=t3;
    
    if(Orijentacija(t1,t2,t3)==0) throw;
}
double Trougao::DajStranicu(int indeks) const{
    if(indeks<1 || indeks>3) throw range_error("Nekorektan indeks");
    double x1=t1.first,y1=t1.second,x2=t2.first,y2=t2.second,x3=t3.first,y3=t3.second;
    if(indeks==1){
        double a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        return a;
    }
    else if(indeks==2){
        double a=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
        return a;
    }
    else {
        double a=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
        return a;
    }
    
    
}
double Trougao::DajObim() const{
    double a=DajStranicu(1),b=DajStranicu(2),c=DajStranicu(3);
    double O=a+b+c;
    return O;
}
double Trougao::DajUgao(int indeks) const{
    if(indeks<1 || indeks>3) throw range_error("Nekorektan indeks");
    double a=DajStranicu(1),b=DajStranicu(2),c=DajStranicu(3);
    if(indeks==1){
        double alfa=acos(((b*b)+(c*c)-(a*a))/(2*b*c));
        return alfa;
    }
    else if(indeks==2){
        double beta=acos(((a*a)+(c*c)-(b*b))/(2*a*c));
        return beta;
    }
    else{
        double gama=acos(((a*a)+(b*b)-(c*c))/(2*a*b));
        return gama;
    }
}
double Trougao::DajPovrsinu() const{
    double x1=t1.first,y1=t1.second,x2=t2.first,y2=t2.second,x3=t3.first,y3=t3.second;
        double a=x1*(y2-y3)-x2*(y1-y3)+x3*(y1-y2);
        return fabs(a)/2;
}


int main ()
{
    
	return 0;
}