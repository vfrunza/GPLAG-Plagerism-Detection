/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <cmath>

typedef std::pair<double,double>Tacka;
const double PI=4*atan(1);

class Trougao {
    Tacka t1, t2, t3;
    
    public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        Postavi(t1, t2, t3);
    }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        *this=Trugao(t1, t2, t3);
    }
    void Postavi(int indeks, const Tacka &t) {
        *this=Trougao(indeks, t);
    }
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        int d,x1,x2,x3,y1,y2,y3;
        t1=(x1, y1); t2=(x2,y2); t3=(x3,y3);
        d=x1(y2-y3)-x2(y1-y3)+x3(y1-y2);
        if(d>0) return 1;
        else if(d<0) return -1;
        else return 0;
    }
    Tacka DajTjeme(int indeks) const {
        if(indeks==1) return t1;
        if(indeks==2) return t2;
        if(indeks==3) return t3;
    }
    double DajStranicu(int indeks) const {
        double a,b,c;
        if(indeks==1) return a;
        if(indeks==2) return b; 
        if(indeks==3) return c;
        
    }
    double DajUgao(int indeks) const {
        double radians,a,b,c;
        if(indeks==1) {
            double alfa;
           alfa=arccos((b*b+c*c-a*a)/2*b*c);
           radians=alfa*(PI/180);
           return radians;
        }
        if(indeks==2) {
            double beta;
            beta=arccos((c*c+a*a-b*b)/2*c*a);
            radians=beta*(PI/180);
            return beta;
        }
        if(indeks==3) {
            double gama;
            gama=arccos((a*a+b*b-c*c)/2*a*b);
            radians=gama*(PI/180);
            return radians;
        }
    }
    
};
int main ()
{
	return 0;
}