/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <cmath>

typedef std::pair<double, double> Tacka;

class Trougao {
    Tacka tjeme1, tjeme2, tjeme3;
    bool static TestIndexa (int index) {
        return (index == 1 || index == 2 || index == 3);
    }
public:
    Trougao (const Tacka &t1, const Tacka &t2, const Tacka &t3);
    void Postavi (const Tacka &t1, const Tacka &t2, const Tacka &t3);
    void Postavi (int indeks, const Tacka &t);
    static int Orijentacija (const Tacka &t1, const Tacka &t2, const Tacka &t3);
    Tacka DajTjeme (int indeks) const;
    double DajStranicu (int indeks) const;
    double DajUgao (int indeks) const;
    Tacka DajCentar() const;
    double DajObim() const;
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
    friend bool DaLiSuSlicni (const Trougao &t1, const Trougao &t2);
};

Trougao::Trougao (const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    if ((t1.first == t2.first == t3.first) || (t1.second == t2.second == t3.second))
    throw std::domain_error("Nekorektne pozicije tjemena");
    tjeme1 = t1; tjeme2 = t2; tjeme3 = t3; 
}

void Trougao::Postavi (const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    tjeme1 = t1; tjeme2 = t2; tjeme3 = t3;
}

void Trougao::Postavi (int indeks, const Tacka &t) {
    if (!TestIndexa(indeks)) throw std::range_error("Nekorektan index");
    if (indeks == 1) tjeme1 = t;
    else if (indeks == 2 ) tjeme2 = t;
    else tjeme3 = t;
}

int Trougao::Orijentacija (const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    int ort (t1.first * (t2.second - t3.second) - t2.first * (t1.second - t3.second) + t3.first * (t1.second - t2.second));
    if(ort > 0) return 1;
    else if (ort < 0) return -1;
    else return 0;
}

Tacka Trougao::DajTjeme (int indeks) const {
    if (!TestIndexa(indeks)) throw std::range_error("Nekorektan index");
    if (indeks == 1) return tjeme1;
    else if (indeks == 2) return tjeme2;
    else return tjeme3;
}

double Trougao::DajStranicu (int indeks) const {
    if (!TestIndexa(indeks)) throw std::range_error("Nekorektan index");
    if (indeks == 1) 
        return sqrt(pow((tjeme3.second-tjeme2.second),2)+
        ((tjeme2.second-tjeme2.first))*((tjeme3.second-tjeme3.first)));
    else if (indeks == 2) 
        return sqrt();
    else return 
}

int main ()
{
	return 0;
}