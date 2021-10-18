/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <cmath>
#include <stdexcept>

typedef std::pair<double, double> Tacka;

class Trougao
{
    Tacka tac1, tac2, tac3;
    double x, y, z;
    Tacka ind;
    void TestIndeksa(int indeks) const 
    {
        if(indeks != 1 || indeks != 2 || indeks != 3) throw std::range_error("Pogrešan indeks!");
    }
    public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) : tac1(t1), tac2(t2), tac3(t3) {Postavi(t1, t2, t3);}
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3)
    {
        tac1 = t1;
        tac2 = t2;
        tac3 = t3;
    }
    void Postavi(int indeks, const Tacka &t) { TestIndeksa(indeks);}
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    Tacka DajTjeme(int indeks) const { Tacka t; TestIndeksa(indeks); return t;}
    double DajStranicu(int indeks) const {TestIndeksa(indeks);}
    double DajUgao(int indeks) const {TestIndeksa(indeks);}
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
};


int main ()
{
	return 0;
}