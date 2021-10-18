/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>

typedef std::pair<double, double> Tacka;

class Trougao {
    Tacka A, B, C;
    static bool JesuLiJednaki(double x, double y, double eps=1e-10) {
        return std::fabs(x-y)<=eps*(std::fabs(x)+std::fabs(y));
    }
    static bool Tacke(const Tacka &t1, const Tacka &t2) {
        if(JesuLiJednaki(t1.first, t2.first) && JesuLiJednaki(t1.second, t2.second)) return true;
        else return false;
    }
    void ProvjeriIndeks(int indeks) const {
        if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
    }
    static double DajOrijentaciju(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        return t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
    }
 public: 
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        if(Orijentacija(t1, t2, t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
        A=t1; B=t2; C=t3;
    }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        if(Orijentacija(t1, t2, t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
        A=t1; B=t2; C=t3;
    }
    void Postavi(int indeks, const Tacka &t);
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        double izraz(DajOrijentaciju(t1, t2, t3));
        if(izraz<0) return -1;
        else if(izraz>0) return 1;
        return 0;
    }
    Tacka DajTjeme(int indeks) const;
    double DajStranicu(int indeks) const;
    double DajUgao(int indeks) const;
    Tacka DajCentar() const;
    double DajPovrsinu() const;
    double DajObim() const;
    bool DaLiJePozitivnoOrijentiran() const;
    bool DaLiJeUnutra(const Tacka &t) const;
    void Ispisi() const {std::cout << "((" << A.first << "," << A.second << ")" << "," << "(" << B.first << "," << B.second << ")" << "," << "(" << C.first << "," << C.second << "))";}
    void Transliraj(double delta_x, double delta_y);
    void Transliraj(const Tacka &t);
    void Centriraj(const Tacka &t);
    void Rotiraj(const Tacka &t, double alfa);
    void Skaliraj(const Tacka &t, double k);
    void Rotiraj(double alfa);
    void Skaliraj(double k);
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(Trougao &t1, Trougao &t2);
    friend bool DaLiSuSlicni(Trougao &t1, Trougao &t2);
};

void Trougao::Postavi(int indeks, const Tacka &t) {
    ProvjeriIndeks(indeks);
    switch(indeks) {
        case 1: A=t;
        case 2: B=t;
        case 3: C=t;
    }
    if(Orijentacija(A, B, C)==0) throw std::domain_error("Nekorektne pozicije tjemena");
}

Tacka Trougao::DajTjeme(int indeks) const {
    ProvjeriIndeks(indeks);
    switch(indeks) {
        case 1: return A;
        case 2: return B;
    }
    return C;
}

double Trougao::DajStranicu(int indeks) const {
    ProvjeriIndeks(indeks);
    switch(indeks) {
        case 1: return sqrt((C.first-B.first)*(C.first-B.first)+(C.second-B.second)*(C.second-B.second));
        case 2: return sqrt((A.first-C.first)*(A.first-C.first)+(A.second-C.second)*(A.second-C.second));
    }
    return sqrt((B.first-A.first)*(B.first-A.first)+(B.second-A.second)*(B.second-A.second));
}

double Trougao::DajUgao(int indeks) const {
    ProvjeriIndeks(indeks);
    switch(indeks) {
        case 1: {
            double k1((B.second-A.second)/(B.first-A.first));
            double k2((C.second-A.second)/(C.first-A.first));
            return std::atan((k2-k1)/(1+k1*k2));
        }
        case 2: {
            double k1((A.second-B.second)/(A.first-B.first));
            double k2((C.second-B.second)/(C.first-B.first));
            return std::atan((k2-k1)/(1+k1*k2));
        }
    }
    double k1((B.second-C.second)/(B.first-C.first));
    double k2((A.second-C.second)/(A.first-C.first));
    return std::atan((k2-k1)/(1+k1*k2));
}

Tacka Trougao::DajCentar() const {
    return {(A.first+B.first+C.first)/3, (A.second+B.second+C.second)/3};
}

double Trougao::DajPovrsinu() const {
    return std::abs(DajOrijentaciju(A, B, C))/2;
}

double Trougao::DajObim() const {
    return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
}

bool Trougao::DaLiJePozitivnoOrijentiran() const {
    if(Orijentacija(A, B, C)) return true;
    return false;
}

bool Trougao::DaLiJeUnutra(const Tacka &T) const {
    if(Orijentacija(A, B, C)==Orijentacija(A, B, T) && Orijentacija(A, B, T)==Orijentacija(B, C, T) && Orijentacija(B, C, T)==Orijentacija(C, A, T)) return true;
    return false;
}

void Trougao::Transliraj(double delta_x, double delta_y) {
    A.first+=delta_x; B.first+=delta_x; C.first+=delta_x;
    A.second+=delta_y; B.second+=delta_y; C.second+=delta_y;
}

void Trougao::Centriraj(const Tacka &t) {
    double dx((3*t.first-A.first-B.first-C.first)/3);
    double dy((3*t.second-A.second-B.second-C.second)/3);
    this->Transliraj(dx, dy);
}

void Trougao::Transliraj(const Tacka &t) {
    this->Centriraj(t);
}

void Trougao::Rotiraj(const Tacka &t, double alfa) {
    Tacka Apom(A), Bpom(B), Cpom(C);
    A.first=t.first+(Apom.first-t.first)*cos(alfa)-(Apom.second-t.second)*sin(alfa);
    B.first=t.first+(Bpom.first-t.first)*cos(alfa)-(Bpom.second-t.second)*sin(alfa);
    C.first=t.first+(Cpom.first-t.first)*cos(alfa)-(Cpom.second-t.second)*sin(alfa);
    A.second=t.second+(Apom.first-t.first)*sin(alfa)+(Apom.second-t.second)*cos(alfa);
    B.second=t.second+(Bpom.first-t.first)*sin(alfa)+(Bpom.second-t.second)*cos(alfa);
    C.second=t.second+(Cpom.first-t.first)*sin(alfa)+(Cpom.second-t.second)*cos(alfa);
}

void Trougao::Skaliraj(const Tacka &t, double k) {
    if(JesuLiJednaki(k, 0)) throw std::domain_error("Nekorektan faktor skaliranja");
    A.first=t.first+k*(A.first-t.first);
    B.first=t.first+k*(B.first-t.first);
    C.first=t.first+k*(C.first-t.first);
    A.second=t.second+k*(A.second-t.second);
    B.second=t.second+k*(B.second-t.second);
    C.second=t.second+k*(C.second-t.second);
}

void Trougao::Rotiraj(double alfa) {
    Tacka teziste{(A.first+B.first+C.first)/3,(A.second+B.second+C.second)/3};
    this->Rotiraj(teziste, alfa);
}

void Trougao::Skaliraj(double k) {
    Tacka teziste{(A.first+B.first+C.first)/3,(A.second+B.second+C.second)/3};
    this->Skaliraj(teziste, k);
}

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2) {
    if(Trougao::Tacke(t1.DajCentar(), t2.DajCentar()) && (Trougao::Tacke(t1.A, t2.A) || Trougao::Tacke(t1.A, t2.B) || Trougao::Tacke(t1.A, t2.C)) && (Trougao::Tacke(t1.B, t2.A) || Trougao::Tacke(t1.B, t2.B) || Trougao::Tacke(t1.B, t2.C))) return true;
    return false;
}

bool DaLiSuPodudarni(Trougao &t1, Trougao &t2) {
    t2.Transliraj(t1.DajCentar());
    t2.Rotiraj(asin(((t2.DajTjeme(1).first-t1.DajCentar().first)*(t1.DajTjeme(1).second-t1.DajCentar().second)+(t2.DajTjeme(1).second-t1.DajCentar().second)*(t1.DajCentar().first-t1.DajTjeme(1).first))/((t2.DajTjeme(1).first-t1.DajCentar().first)*(t2.DajTjeme(1).first-t1.DajCentar().first)+(t2.DajTjeme(1).second-t1.DajCentar().second)*(t2.DajTjeme(1).second-t1.DajCentar().second))));
    if(DaLiSuIdenticni(t1, t2)) return true;
    else return false;
}

bool DaLiSuSlicni(Trougao &t1, Trougao &t2) {
    double k((t1.DajTjeme(1).first-t1.DajCentar().first)/(t2.DajTjeme(1).first-t1.DajCentar().first));
    t2.Skaliraj(k);
    if(DaLiSuPodudarni(t1, t2)) return true;
    else return false;
}

int main ()
{
  
	return 0;
}