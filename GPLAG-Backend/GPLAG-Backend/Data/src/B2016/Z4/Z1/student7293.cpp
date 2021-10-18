/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>

typedef std::pair<double, double> Tacka;

class Trougao {
    
    public:
    Trougao (const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        Postavi (t1, t2, t3);
    }
    void Postavi (const Tacka &t1, const Tacka &t2, const Tacka &t3);
    void Postavi (int indeks, const Tacka &t) {
        if (indeks!=1 || indeks!=2 || indeks!=3) throw stad::range_error ("Nekorektan indeks");
    }
    static int Orijentacija (const Tacka &t1, const Tacka &t2, const Tacka &t3);
    Tacka DajTjeme (int indeks) const;
    double DajStranicu (int indeks) const;
    double DajUgao (int indeks) const;
    Tacka DajCentar() const;
    double DajObim () const;
    double DajPovrsinu() const;
    bool DaLiJePozitivnoOrijentiran() const;
    bool DaLiJeUnutra(const Tacka &t) const;
    void Ispisi() const;
    void Transliraj (double delta_x, double delta_y);
    void Centriraj (const Tacka &t);
    void Rotiraj (const Tacka &t, double ugao);
    void Skaliraj (const Tacka &t, double faktor);
    void Rotiraj (double ugao);
    void Skaliraj (double faktor);
    friend bool DaLiSuIdenticni (const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni (const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};

int main ()
{
    try {
	    return 0;
    }
    catch (std::range_error izuzetak) {
        std::cout << izuzetak.what() << std::endl;
    }
}