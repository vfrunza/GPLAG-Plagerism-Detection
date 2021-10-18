/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <vector>
#include <memory>
#include <cmath>
#include <algorithm>
#include <stdexcept>
using std::vector;

typedef std::pair<double, double> Tacka;

class Trougao {
    Tacka t1, t2, t3;
    static double Povrsina (const Tacka &t1, const Tacka &t2, const Tacka &t3);
    static double DuzinaStranice (const Tacka &t1, const Tacka &t2);
    static bool JesuLiJednaki (double x, double y);
public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3);
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
};

Trougao::Trougao (const Tacka &t1, const Tacka &t2, const Tacka &t3) : t1(t1), t2(t2), t3(t3) {
    if (Orijentacija(t1, t2, t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
}

void Trougao::Postavi (const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    Trougao::t1=t1;
    Trougao::t2=t2;
    Trougao::t3=t3;
    if (Orijentacija(t1, t2, t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
}

void Trougao::Postavi (int indeks, const Tacka &t) {
    if (indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error("Nekorektan indeks");
    if (indeks==1)
        t1=t;
    else if (indeks==2)
        t2=t;
    else if (indeks==3)
        t3=t;
    if (Orijentacija(t1, t2, t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
}

bool Trougao::JesuLiJednaki (double x, double y) {
    const double Eps(1e-10);
    return fabs(x-y)<=Eps*(fabs(x)+fabs(y));
}


double Trougao::Povrsina (const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    return t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
}

int Trougao::Orijentacija (const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    if (Povrsina(t1, t2, t3)>0)
        return 1;
    else if (Povrsina(t1, t2, t3)<0)
        return -1;
    return 0;
}

Tacka Trougao::DajTjeme (int indeks) const {
    if (indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error("Nekorektan indeks");
    if (indeks==1)
        return t1;
    else if (indeks==2)
        return t2;
    return t3;
}

double Trougao::DuzinaStranice (const Tacka &t1, const Tacka &t2) {
    return sqrt((t2.first-t1.first)*(t2.first-t1.first)+(t2.second-t1.second)*(t2.second-t1.second));
}

double Trougao::DajStranicu (int indeks) const {
    if (indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error("Nekorektan indeks");
    if (indeks==1)
        return DuzinaStranice(t2, t3);
    else if (indeks==2)
        return DuzinaStranice(t1, t3);
    return DuzinaStranice(t1, t2);
}

double Trougao::DajUgao (int indeks) const {
    if (indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error("Nekorektan indeks");
    double duzina12(DuzinaStranice(t1, t2)), duzina13(DuzinaStranice(t1, t3)), duzina23(DuzinaStranice(t2, t3));
    if (indeks==1)
        return acos((duzina13*duzina13+duzina12*duzina12-duzina23*duzina23)/(2*duzina12*duzina13));
    else if (indeks==2)
        return acos((duzina23*duzina23+duzina12*duzina12-duzina13*duzina13)/(2*duzina12*duzina23));
    return acos((duzina13*duzina13+duzina23*duzina23-duzina12*duzina12)/(2*duzina23*duzina13));
}

Tacka Trougao::DajCentar () const {
    return std::make_pair((t1.first+t2.first+t3.first)/3., (t1.second+t2.second+t3.second)/3.);
}

double Trougao::DajObim () const {
    return DuzinaStranice(t1, t2)+DuzinaStranice(t1, t3)+DuzinaStranice(t2, t3);
}

double Trougao::DajPovrsinu () const {
    return fabs(Povrsina(t1, t2, t3))/2;
}

bool Trougao::DaLiJePozitivnoOrijentiran () const {
    if (Orijentacija(t1, t2, t3)==1)
        return true;
    return false;
}

bool Trougao::DaLiJeUnutra (const Tacka &t) const {
    if ((Orijentacija(t1, t2, t3)==1 && Orijentacija(t1, t2, t)==1 && Orijentacija(t2, t3, t)==1 && Orijentacija(t3, t1, t)==1) || (Orijentacija(t1, t2, t3)==-1 && Orijentacija(t1, t2, t)==-1 && Orijentacija(t2, t3, t)==-1 && Orijentacija(t3, t1, t)==-1))
        return true;
    return false;
}

void Trougao::Transliraj (double delta_x, double delta_y) {
    t1.first+=delta_x;
    t1.second+=delta_y;
    t2.first+=delta_x;
    t2.second+=delta_y;
    t3.first+=delta_x;
    t3.second+=delta_y;
}

void Trougao::Centriraj (const Tacka &t) {
    double delta_x(t.first-DajCentar().first), delta_y(t.second-DajCentar().second);
    t1.first+=delta_x;
    t1.second+=delta_y;
    t2.first+=delta_x;
    t2.second+=delta_y;
    t3.first+=delta_x;
    t3.second+=delta_y;
}

void Trougao::Rotiraj (const Tacka &t, double ugao) {
    Tacka tac1(DajTjeme(1)), tac2(DajTjeme(2)), tac3(DajTjeme(3));
    t1.first=t.first+(tac1.first-t.first)*cos(ugao)-(tac1.second-t.second)*sin(ugao);
    t1.second=t.second+(tac1.first-t.first)*sin(ugao)+(tac1.second-t.second)*cos(ugao);
    t2.first=t.first+(tac2.first-t.first)*cos(ugao)-(tac2.second-t.second)*sin(ugao);
    t2.second=t.second+(tac2.first-t.first)*sin(ugao)+(tac2.second-t.second)*cos(ugao);
    t3.first=t.first+(tac3.first-t.first)*cos(ugao)-(tac3.second-t.second)*sin(ugao);
    t3.second=t.second+(tac3.first-t.first)*sin(ugao)+(tac3.second-t.second)*cos(ugao);
}

void Trougao::Skaliraj (const Tacka &t, double faktor) {
    if (JesuLiJednaki(faktor, 0)) throw std::domain_error("Nekorektan faktor skaliranja");
        t1.first=t.first+faktor*(t1.first-t.first);
        t1.second=t.second+faktor*(t1.second-t.second);
        t2.first=t.first+faktor*(t2.first-t.first);
        t2.second=t.second+faktor*(t2.second-t.second);
        t3.first=t.first+faktor*(t3.first-t.first);
        t3.second=t.second+faktor*(t3.second-t.second);
}

void Trougao::Rotiraj (double ugao) {
    Tacka tac1(DajTjeme(1)), tac2(DajTjeme(2)), tac3(DajTjeme(3)), centar(DajCentar());
    t1.first=centar.first+(tac1.first-centar.first)*cos(ugao)-(tac1.second-centar.second)*sin(ugao);
    t1.second=centar.second+(tac1.first-centar.first)*sin(ugao)+(tac1.second-centar.second)*cos(ugao);
    t2.first=centar.first+(tac2.first-centar.first)*cos(ugao)-(tac2.second-centar.second)*sin(ugao);
    t2.second=centar.second+(tac2.first-centar.first)*sin(ugao)+(tac2.second-centar.second)*cos(ugao);
    t3.first=centar.first+(tac3.first-centar.first)*cos(ugao)-(tac3.second-centar.second)*sin(ugao);
    t3.second=centar.second+(tac3.first-centar.first)*sin(ugao)+(tac3.second-centar.second)*cos(ugao);
}

void Trougao::Skaliraj (double faktor) {
    if (JesuLiJednaki(faktor, 0)) throw std::domain_error("Nekorektan faktor skaliranja");
        Tacka centar(DajCentar());
        t1.first=centar.first+faktor*(t1.first-centar.first);
        t1.second=centar.second+faktor*(t1.second-centar.second);
        t2.first=centar.first+faktor*(t2.first-centar.first);
        t2.second=centar.second+faktor*(t2.second-centar.second);
        t3.first=centar.first+faktor*(t3.first-centar.first);
        t3.second=centar.second+faktor*(t3.second-centar.second);
}

bool DaLiSuIdenticni (const Trougao &t1, const Trougao &t2) {
    if ((t1.DajTjeme(1)==t2.DajTjeme(1) && t1.DajTjeme(2)==t2.DajTjeme(2) && t1.DajTjeme(3)==t2.DajTjeme(3)) ||
        (t1.DajTjeme(1)==t2.DajTjeme(1) && t1.DajTjeme(2)==t2.DajTjeme(3) && t1.DajTjeme(3)==t2.DajTjeme(2)) ||
        (t1.DajTjeme(1)==t2.DajTjeme(2) && t1.DajTjeme(2)==t2.DajTjeme(1) && t1.DajTjeme(3)==t2.DajTjeme(3)) ||
        (t1.DajTjeme(1)==t2.DajTjeme(2) && t1.DajTjeme(2)==t2.DajTjeme(3) && t1.DajTjeme(3)==t2.DajTjeme(1)) ||
        (t1.DajTjeme(1)==t2.DajTjeme(3) && t1.DajTjeme(2)==t2.DajTjeme(1) && t1.DajTjeme(3)==t2.DajTjeme(2)) ||
        (t1.DajTjeme(1)==t2.DajTjeme(3) && t1.DajTjeme(2)==t2.DajTjeme(2) && t1.DajTjeme(3)==t2.DajTjeme(1)))
        return true;
    return false;
}

bool DaLiSuPodudarni (const Trougao &t1, const Trougao &t2) {
    if (Trougao::JesuLiJednaki(t1.DajStranicu(1), t1.DajStranicu(2)) && Trougao::JesuLiJednaki(t2.DajStranicu(1), t2.DajStranicu(2)) && Trougao::JesuLiJednaki(t1.DajStranicu(1), t2.DajStranicu(1)))
        return true;
    else if (Trougao::JesuLiJednaki(t1.DajStranicu(1), t1.DajStranicu(2)) && Trougao::JesuLiJednaki(t2.DajStranicu(1), t2.DajStranicu(3)) && Trougao::JesuLiJednaki(t1.DajStranicu(1), t2.DajStranicu(1)))
        return true;
    else if (Trougao::JesuLiJednaki(t1.DajStranicu(1), t1.DajStranicu(2)) && Trougao::JesuLiJednaki(t2.DajStranicu(2), t2.DajStranicu(3)) && Trougao::JesuLiJednaki(t1.DajStranicu(1), t2.DajStranicu(2)))
        return true;    
    else if (Trougao::JesuLiJednaki(t1.DajStranicu(1), t1.DajStranicu(3)) && Trougao::JesuLiJednaki(t2.DajStranicu(1), t2.DajStranicu(2)) && Trougao::JesuLiJednaki(t1.DajStranicu(1), t2.DajStranicu(1)))
        return true;    
    else if (Trougao::JesuLiJednaki(t1.DajStranicu(1), t1.DajStranicu(3)) && Trougao::JesuLiJednaki(t2.DajStranicu(1), t2.DajStranicu(3)) && Trougao::JesuLiJednaki(t1.DajStranicu(1), t2.DajStranicu(1)))
        return true;
    else if (Trougao::JesuLiJednaki(t1.DajStranicu(1), t1.DajStranicu(3)) && Trougao::JesuLiJednaki(t2.DajStranicu(2), t2.DajStranicu(3)) && Trougao::JesuLiJednaki(t1.DajStranicu(1), t2.DajStranicu(2)))
        return true;
    else if (Trougao::JesuLiJednaki(t1.DajStranicu(2), t1.DajStranicu(3)) && Trougao::JesuLiJednaki(t2.DajStranicu(1), t2.DajStranicu(2)) && Trougao::JesuLiJednaki(t1.DajStranicu(2), t2.DajStranicu(1)))
        return true;
    else if (Trougao::JesuLiJednaki(t1.DajStranicu(2), t1.DajStranicu(3)) && Trougao::JesuLiJednaki(t2.DajStranicu(1), t2.DajStranicu(3)) && Trougao::JesuLiJednaki(t1.DajStranicu(2), t2.DajStranicu(1)))
        return true;
    else if (Trougao::JesuLiJednaki(t1.DajStranicu(2), t1.DajStranicu(3)) && Trougao::JesuLiJednaki(t2.DajStranicu(2), t2.DajStranicu(3)) && Trougao::JesuLiJednaki(t1.DajStranicu(2), t2.DajStranicu(2)))
        return true;
        
    if (Trougao::JesuLiJednaki(t1.DajUgao(1), t2.DajUgao(1)) && Trougao::JesuLiJednaki(t1.DajStranicu(1), t2.DajStranicu(1))) {
        if (Trougao::JesuLiJednaki(t1.DajUgao(2), t2.DajUgao(2))) {
            if (Trougao::Orijentacija(t1.DajTjeme(1), t1.DajTjeme(2), t1.DajTjeme(3))==Trougao::Orijentacija(t2.DajTjeme(1), t2.DajTjeme(2), t2.DajTjeme(3)))
                return true;
        }
        else if (Trougao::JesuLiJednaki(t1.DajUgao(2), t2.DajUgao(3))) {
            if (Trougao::Orijentacija(t1.DajTjeme(1), t1.DajTjeme(2), t1.DajTjeme(3))==Trougao::Orijentacija(t2.DajTjeme(1), t2.DajTjeme(3), t2.DajTjeme(2)))
                return true;
        }
    }
    else if (Trougao::JesuLiJednaki(t1.DajUgao(1), t2.DajUgao(2)) && Trougao::JesuLiJednaki(t1.DajStranicu(1), t2.DajStranicu(2))) {
        if (Trougao::JesuLiJednaki(t1.DajUgao(2), t2.DajUgao(1))) {
            if (Trougao::Orijentacija(t1.DajTjeme(1), t1.DajTjeme(2), t1.DajTjeme(3))==Trougao::Orijentacija(t2.DajTjeme(2), t2.DajTjeme(1), t2.DajTjeme(3)))
                return true;
        }
        else if (Trougao::JesuLiJednaki(t1.DajUgao(2), t2.DajUgao(3))) {
            if (Trougao::Orijentacija(t1.DajTjeme(1), t1.DajTjeme(2), t1.DajTjeme(3))==Trougao::Orijentacija(t2.DajTjeme(2), t2.DajTjeme(3), t2.DajTjeme(1)))
                return true;
        }
    }
    else if (Trougao::JesuLiJednaki(t1.DajUgao(1), t2.DajUgao(3)) && Trougao::JesuLiJednaki(t1.DajStranicu(1), t2.DajStranicu(3))) {
        if (Trougao::JesuLiJednaki(t1.DajUgao(2), t2.DajUgao(1))) {
            if (Trougao::Orijentacija(t1.DajTjeme(1), t1.DajTjeme(2), t1.DajTjeme(3))==Trougao::Orijentacija(t2.DajTjeme(3), t2.DajTjeme(1), t2.DajTjeme(2)))
                return true;
        }
        else if (Trougao::JesuLiJednaki(t1.DajUgao(2), t2.DajUgao(2))) {
            if (Trougao::Orijentacija(t1.DajTjeme(1), t1.DajTjeme(2), t1.DajTjeme(3))==Trougao::Orijentacija(t2.DajTjeme(3), t2.DajTjeme(2), t2.DajTjeme(1)))
                return true;
        }        
    }
    return false;
}

bool DaLiSuSlicni (const Trougao &t1, const Trougao &t2) {
    if (Trougao::JesuLiJednaki(t1.DajStranicu(1), t1.DajStranicu(2)) && Trougao::JesuLiJednaki(t2.DajStranicu(1), t2.DajStranicu(2)) && Trougao::JesuLiJednaki(t1.DajUgao(3), t2.DajUgao(3)))
        return true;
    else if (Trougao::JesuLiJednaki(t1.DajStranicu(1), t1.DajStranicu(2)) && Trougao::JesuLiJednaki(t2.DajStranicu(1), t2.DajStranicu(3)) && Trougao::JesuLiJednaki(t1.DajUgao(3), t2.DajUgao(2)))
        return true;
    else if (Trougao::JesuLiJednaki(t1.DajStranicu(1), t1.DajStranicu(2)) && Trougao::JesuLiJednaki(t2.DajStranicu(2), t2.DajStranicu(3)) && Trougao::JesuLiJednaki(t1.DajUgao(3), t2.DajUgao(1)))
        return true;    
    else if (Trougao::JesuLiJednaki(t1.DajStranicu(1), t1.DajStranicu(3)) && Trougao::JesuLiJednaki(t2.DajStranicu(1), t2.DajStranicu(2)) && Trougao::JesuLiJednaki(t1.DajUgao(2), t2.DajUgao(3)))
        return true;    
    else if (Trougao::JesuLiJednaki(t1.DajStranicu(1), t1.DajStranicu(3)) && Trougao::JesuLiJednaki(t2.DajStranicu(1), t2.DajStranicu(3)) && Trougao::JesuLiJednaki(t1.DajUgao(2), t2.DajUgao(2)))
        return true;
    else if (Trougao::JesuLiJednaki(t1.DajStranicu(1), t1.DajStranicu(3)) && Trougao::JesuLiJednaki(t2.DajStranicu(2), t2.DajStranicu(3)) && Trougao::JesuLiJednaki(t1.DajUgao(2), t2.DajUgao(1)))
        return true;
    else if (Trougao::JesuLiJednaki(t1.DajStranicu(2), t1.DajStranicu(3)) && Trougao::JesuLiJednaki(t2.DajStranicu(1), t2.DajStranicu(2)) && Trougao::JesuLiJednaki(t1.DajUgao(1), t2.DajUgao(3)))
        return true;
    else if (Trougao::JesuLiJednaki(t1.DajStranicu(2), t1.DajStranicu(3)) && Trougao::JesuLiJednaki(t2.DajStranicu(1), t2.DajStranicu(3)) && Trougao::JesuLiJednaki(t1.DajUgao(1), t2.DajUgao(2)))
        return true;
    else if (Trougao::JesuLiJednaki(t1.DajStranicu(2), t1.DajStranicu(3)) && Trougao::JesuLiJednaki(t2.DajStranicu(2), t2.DajStranicu(3)) && Trougao::JesuLiJednaki(t1.DajUgao(1), t2.DajUgao(1)))
        return true;
    
    if (Trougao::JesuLiJednaki(t1.DajUgao(1), t2.DajUgao(1))) {
        if (Trougao::JesuLiJednaki(t1.DajUgao(2), t2.DajUgao(2))) {
            if (Trougao::Orijentacija(t1.DajTjeme(1), t1.DajTjeme(2), t1.DajTjeme(3))==Trougao::Orijentacija(t2.DajTjeme(1), t2.DajTjeme(2), t2.DajTjeme(3)))
                return true;
        }
        else if (Trougao::JesuLiJednaki(t1.DajUgao(2), t2.DajUgao(3))) {
            if (Trougao::Orijentacija(t1.DajTjeme(1), t1.DajTjeme(2), t1.DajTjeme(3))==Trougao::Orijentacija(t2.DajTjeme(1), t2.DajTjeme(3), t2.DajTjeme(2)))
                return true;
        }
    }
    else if (Trougao::JesuLiJednaki(t1.DajUgao(1), t2.DajUgao(2))) {
        if (Trougao::JesuLiJednaki(t1.DajUgao(2), t2.DajUgao(1))) {
            if (Trougao::Orijentacija(t1.DajTjeme(1), t1.DajTjeme(2), t1.DajTjeme(3))==Trougao::Orijentacija(t2.DajTjeme(2), t2.DajTjeme(1), t2.DajTjeme(3)))
                return true;
        }
        else if (Trougao::JesuLiJednaki(t1.DajUgao(2), t2.DajUgao(3))) {
            if (Trougao::Orijentacija(t1.DajTjeme(1), t1.DajTjeme(2), t1.DajTjeme(3))==Trougao::Orijentacija(t2.DajTjeme(2), t2.DajTjeme(3), t2.DajTjeme(1)))
                return true;
        }
    }
    else if (Trougao::JesuLiJednaki(t1.DajUgao(1), t2.DajUgao(3))) {
        if (Trougao::JesuLiJednaki(t1.DajUgao(2), t2.DajUgao(1))) {
            if (Trougao::Orijentacija(t1.DajTjeme(1), t1.DajTjeme(2), t1.DajTjeme(3))==Trougao::Orijentacija(t2.DajTjeme(3), t2.DajTjeme(1), t2.DajTjeme(2)))
                return true;
        }
        else if (Trougao::JesuLiJednaki(t1.DajUgao(2), t2.DajUgao(2))) {
            if (Trougao::Orijentacija(t1.DajTjeme(1), t1.DajTjeme(2), t1.DajTjeme(3))==Trougao::Orijentacija(t2.DajTjeme(3), t2.DajTjeme(2), t2.DajTjeme(1)))
                return true;
        }        
    }
    return false;   
}

void Trougao::Ispisi () const {
    std::cout << "((" << t1.first << "," << t1.second << "),(" << t2.first << "," << t2.second << "),(" << t3.first << "," << t3.second << "))";
}

int main ()
{
    int n;
    std::cout << "Koliko zelite kreirati trouglova: ";
    std::cin >> n;
    vector<std::shared_ptr<Trougao>> v(n);
    for (int i=0; i<n; i++) {
        try {
            Tacka t1, t2, t3;
            std::cout << "Unesite podatke za " << i+1 << ". trougao (x1 y1 x2 y2 x3 y3): ";
            std::cin >> t1.first >> t1.second >> t2.first >> t2.second >> t3.first >> t3.second;
            v[i]=std::make_shared<Trougao>(t1, t2, t3);
        }
        catch (std::domain_error izuzetak) {
            std::cout << izuzetak.what() << ", ponovite unos!" << std::endl;
            i--;
        }
    }
	double dx, dy, ugao, faktor;
	std::cout << "Unesite vektor translacije (dx dy): ";
	std::cin >> dx >> dy;
	std::cout << "Unesite ugao rotacije: ";
	std::cin >> ugao;
	std::cout << "Unesite faktor skaliranja: ";
	std::cin >> faktor;
	try {
	    std::transform(v.begin(), v.end(), v.begin(), [dx, dy, ugao, faktor](std::shared_ptr<Trougao> p) {
	        p->Transliraj(dx, dy);
	        p->Rotiraj(p->DajCentar(), ugao);
	        p->Skaliraj(p->DajTjeme(1), faktor);
	        return p;
	    });
	}
	catch (std::domain_error e) {
	    std::cout << e.what() << std::endl;
	}
	
	std::sort(v.begin(), v.end(), [](std::shared_ptr<Trougao> p1, std::shared_ptr<Trougao> p2) {
	    return p1->DajPovrsinu()<p2->DajPovrsinu();
	});
	
	std::cout << "Trouglovi nakon obavljenih transformacija: " << std::endl;
	std::for_each(v.begin(), v.end(), [](std::shared_ptr<Trougao> p) {
	    p->Ispisi();
	    std::cout << std::endl;
	});
	auto p(*std::min_element(v.begin(), v.end(), [](std::shared_ptr<Trougao> p1, std::shared_ptr<Trougao> p2) {
	   return p1->DajObim()<p2->DajObim(); 
	}));
	std::cout << "Trougao sa najmanjim obimom: ";
    p->Ispisi();
    std::cout << std::endl;
    int br(0);
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (DaLiSuIdenticni(*v[i], *v[j])) {
                br++;
                if (br==1) 
                    std::cout << "Parovi identicnih trouglova: " << std::endl;    
                v[i]->Ispisi();
                std::cout << " i ";
                v[j]->Ispisi();
                std::cout << std::endl;
            }
        }
    }
    if (br==0)
        std::cout << "Nema identicnih trouglova!" << std::endl;
    br=0;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (DaLiSuPodudarni(*v[i], *v[j])) {
                br++;
                if (br==1) 
                    std::cout << "Parovi podudarnih trouglova: " << std::endl;    
                v[i]->Ispisi();
                std::cout << " i ";
                v[j]->Ispisi();
                std::cout << std::endl;
            }
        }
    }
    if (br==0)
        std::cout << "Nema podudarnih trouglova!" << std::endl;
    br=0;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (DaLiSuSlicni(*v[i], *v[j])) {
                br++;
                if (br==1) 
                    std::cout << "Parovi slicnih trouglova: " << std::endl;    
                v[i]->Ispisi();
                std::cout << " i ";
                v[j]->Ispisi();
                std::cout << std::endl;
            }
        }
    }
    if (br==0)
        std::cout << "Nema slicnih trouglova!" << std::endl;
	return 0;
}