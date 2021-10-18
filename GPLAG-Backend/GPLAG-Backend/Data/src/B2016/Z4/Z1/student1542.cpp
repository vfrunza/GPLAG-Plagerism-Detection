/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream
typedef std::pair<double,double> Tacka;
class Trougao {
    Tacka a,b,c;
    int pomocna_fja(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        return (t1.first*(t2.second-t3.second)-t2.first(t1.second-t3.second)-t3.first(t1.second-t3.second));
    }
public: 
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        a=t1;
        b=t2;
        c=t3;
    }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        int izraz=pomocna_fja(t1,t2,t3);
        if(izraz==0) throw std::domain_error("Nekorektne pozicije tjemena");
        a=t1;
        b=t2;
        c=t3;
    }
    void Postavi (int indeks, const Tacka &t) {
        if(indeks!=1 || indeks!=2 || indeks!=3) throw std::range_error("Nekorektan indeks");
    }
    static int Orijentacija (const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        int izraz=pomocna_fja(t1,t2,t3);
        if(izraz>0) return 1;
        else if(izraz<0) return -1;
        else return 0;
    }
    Tacka DajCentar() const {
        Tacka nova;
        nova.first=(a.first+b.first+c.first)/3;
        nova.second=(a.second+b.second+c.second)/3;
        return nova;
    }
    Tacka DajTjeme (int indeks) const {
        if(indeks!=1 || indeks!=2 || indeks!=3) throw std::range_error("Nekorektan indeks");
        int indeks_a=0;
        int indeks_b=1;
        int indeks_c=2;
        if(indeks_a==indeks-1) return a;
        else if(indeks_b==indeks-1) return b;
        else return c;
    }
    double DajStranicu(int indeks) const {
        
    }
    double DajObim() const {
        
        
    }
    double DajPovrsinu() const {
        int povrsina=pomocna_fja(a,b,c);
        return povrsina;
    }
    
    
    
    
    
    
    
    
}
int main ()
{
	return 0;
}