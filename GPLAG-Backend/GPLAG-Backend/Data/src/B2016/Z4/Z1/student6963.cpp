/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <pair>

typedef std::pair<double, double> Tacka;

class Trougao
{
    
    public:
        Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3)
        void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3)
        void Postavi(int indeks, const Tacka &t)
        static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3)
        Tacka DajTjeme(int indeks) const
        double DajStranicu(int indeks) const
        double DajUgao(int indeks) const
        Tacka DajCentar() const
        double DajObim() const
        double DajPovrsinu() const
        bool DaLiJePozitivnoOrijentiran
};

int main ()
{
	return 0;
}