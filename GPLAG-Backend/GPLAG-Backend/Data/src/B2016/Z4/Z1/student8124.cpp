/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;
typedef pair<double,double> Tacka;

class Trougao {
    Tacka tacka1,tacka2,tacka3;
    double alfa,beta,gama;
    public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){ 
        tacka1=t1;
        tacka2=t2;
        tacka3=t3;
        if(Orijentacija(tacka1,tacka2,tacka3)==0) throw domain_error ("Nekorektne pozicije tjemena");
        
    }
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        double a;
        a=t1.first*(t2.second-t3.second)-t2.first(t1.second-t3.second)-t3.first(t1.second-t2.second);
        if (a<0) return -1;
        else if(a>0) return 1;
        else if(a==0) return 0;
    }
    
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        tacka1=t1;
        tacka2=t2;
        tacka3=t3;
    }
    void Postavi(int indeks, const Tacka &t) {
        if(indeks==1) tacka1=t;
        else if(indeks==2) tacka2=t;
        else if(indeks==3) tacka3=t;
        if(indeks<1 or indeks>3) throw range_error("Nekorektan indeks");
        if(Orijentacija(tacka1,tacka2,tacka3)==0) throw domain_error ("Nekorektne pozicije tjemena");
    }
    Tacka DajTjeme(int indeks) const {
        if(indeks==1) return tacka1;
        if(indeks==2) return tacka2;
        if(indeks==3) return tacka3;
        if(indeks<1 or indeks>3) throw range_error("Nekorektan indeks");
    }
    
    double DajStranicu(int indeks) const {
        if(indeks==1) 
        return (sqrt((tacka2.first-tacka3.first)*(tacka2.first-tacka3.first)+(tacka2.second-tacka3.second)*(tacka2.second-tacka3.second)));
        else if(indeks==2)
        return (sqrt((tacka1.first-tacka3.first)*(tacka1.first-tacka3.first)+(tacka1.second-tacka3.second)*(tacka1.second-tacka3.second)));
        else if(indeks==3)
        return (sqrt((tacka1.first-tacka2.first)*(tacka1.first-tacka2.first)+(tacka1.second-tacka2.second)*(tacka1.second-tacka2.second)));
        if(indeks<1 or indeks>3) throw range_error("Nekorektan indeks");
    }
    double DajUgao(int indeks) const {
        double a=DajStranicu(1);
        double b=DajStranicu(2);
        double c=DajStranicu(3);
        if (indeks==1) 
        return ((b*b+c*c-a*a)/2*b*c);
        else if (indeks==2)
        return ((a*a+c*c-b*b)/2*a*c);
        else if (indeks==3)
        return ((a*a+b*b-c*c)/2*a*b);
        if(indeks<1 or indeks>3) throw range_error("Nekorektan indeks");
    }
    Tacka DajCentar() const {
        double x=(tacka1.first+tacka2.first+tacka3.first)/3.;
        double y=(tacka1.second+tacka2.second+tacka3.second)/3.;
        Tacka t;
        t.first=x;
        t.second=y;
        return t;
    }
    
    double DajObim() const {
        double a=DajStranicu(1);
        double b=DajStranicu(2);
        double c=DajStranicu(3);
        return (a+b+c);
    }
    
    double DajPovrsinu() const {
        return (fabs(tacka1.first*(tacka2.second-tacka3.second)-tacka2.first(tacka1.second-tacka3.second)-tacka3.first(tacka1.second-tacka2.second))/2.);
    }
    
    bool DaLiJePozitivnoOrijentiran() const {
        if(Orijentacija(tacka1,tacka2,tacka3)==1) return true;
        else return false;
    }
    
    bool DaLiJeUnutra(const Tacka &t) const {
        
    }
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
    
}
int main ()
{
	return 0;
}