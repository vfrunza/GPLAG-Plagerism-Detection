#include <iostream>
#include <stdexcept>
#include <utility>
#include <cmath>
#include <vector> 
#include <memory>
#include <algorithm>
#include <sstream>

typedef std::pair<double, double> Tacka;

class Trougao {
    Tacka t1, t2, t3;
    template <typename T> 
    std::string PretvoriUString(T x) {
    std::ostringstream s; s << x; return s.str();
    }
    static double izraz (Tacka t1, Tacka t2, Tacka t3) {
        double pom(0);
        pom = t1.first*(t2.second - t3.second) - t2.first*(t1.second - t3.second) + t3.first*(t1.second - t2.second);
        return pom;
    }
    bool da_li_je_index_ok (int indeks) const {
        if (indeks != 1 && indeks != 2 && indeks != 3) return false;
        return true;
    }
    static double duzina_stranice (Tacka t1, Tacka t2) { //OK
        double izraz = std::sqrt(((t1.first - t2.first) * (t1.first - t2.first) + (t1.second - t2.second) * (t1.second - t2.second)));
        return izraz;
    }
    static bool da_li_su_isti (double x, double y) {
        double eps (1e-10);
        return std::fabs (x - y) <= eps * (std::fabs(x) + std::fabs(y));
    }
    bool da_li_je_nula (double x) {
        double eps(1e-10);
        return x<=eps;
    }
    double izracunaj_rotaciju_x (Tacka t, Tacka t1, double ugao) {
        double nesto = (t1.first + (t.first - t1.first) * cos(ugao)) - ((t.second - t1.second) * sin(ugao));
        return nesto;
    }
    double izracunaj_rotaciju_y (Tacka t, Tacka t1, double ugao) {
        double nesto = (t1.second + (t.first - t1.first) * sin(ugao)) + ((t.second - t1.second) * cos(ugao));
        return nesto;
    }
    double skaliraj_x (Tacka t, Tacka t1, double ska) {
        double nesto = t1.first + (ska * (t.first - t1.first));
        return nesto;
    }
    double skaliraj_y (Tacka t, Tacka t1, double ska) {
        std::string x =  PretvoriUString (2.5);
        double nesto = t1.second + (ska * (t.second - t1.second)); // popravljeno y-yc
        return nesto;
    }
    static bool SUS (double s1, double s2, double s3, double s4, double ugao, double ugao1) {
        if (da_li_su_isti(s1,s2) && da_li_su_isti(s3,s4) && da_li_su_isti(ugao,ugao1)) return true;
        return false;
    }
    static bool USU (double ugao, double ugao1, double ugao2, double ugao3, double s1, double s2) {
        if (da_li_su_isti(ugao,ugao1) && da_li_su_isti(ugao2,ugao3) && da_li_su_isti(s1,s2)) return true;
        return false;
    }
    public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) { Postavi(t1, t2, t3); } // OK
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3); // OK
    void Postavi(int indeks, const Tacka &t); // OK
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3); // OK
    Tacka DajTjeme(int indeks) const; //  OK
    double DajStranicu(int indeks) const; // OK
    double DajUgao(int indeks) const; // OK
    Tacka DajCentar() const; // OK
    double DajObim() const { return DajStranicu(1) + DajStranicu(2) + DajStranicu(3); } // ok
    double DajPovrsinu() const {return std::abs(izraz(t1,t2,t3)/2); } // OK
    bool DaLiJePozitivnoOrijentiran() const; // OK
    bool DaLiJeUnutra(const Tacka &t) const; // OK
    void Ispisi() const; // OK
    void Transliraj(double delta_x, double delta_y); // ok
    void Centriraj(const Tacka &t); // 
    void Rotiraj(const Tacka &t, double ugao); //
    void Skaliraj(const Tacka &t, double faktor);// valjda radi nemam pojma
    void Rotiraj(double ugao);// moguce da radi 
    void Skaliraj(double faktor);// OK
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2); //
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2); //NOK
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);// OK
};
void Trougao::Postavi (const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    if (izraz(t1, t2, t3) == 0.0) throw std::domain_error ("Nekorektne pozicije tjemena");
    Trougao::t1.first = t1.first; Trougao::t2.first = t2.first; Trougao::t3.first = t3.first;
    Trougao::t1.second = t1.second; Trougao::t2.second = t2.second; Trougao::t3.second = t3.second;
}
void Trougao::Postavi (int indeks, const Tacka &t) {
    if (izraz(t1, t2, t3) == 0.0) throw std::domain_error ("Nekorektne pozicije tjemena");
    if (!(da_li_je_index_ok(indeks))) throw std::domain_error ("Nekorektan indeks");
    if (indeks == 1)  { Trougao::t1.first = t.first; Trougao::t1.second = t.second; }
    else if (indeks == 2) { Trougao::t2.first = t.first; Trougao::t2.second = t.second; }
    Trougao::t3.first = t.first; Trougao::t3.second = t.second;
}
int Trougao::Orijentacija (const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    if (izraz(t1, t2, t3) > 0) return 1;
    else if (izraz(t1, t2, t3) < 0) return -1;
    return 0;
}
Tacka Trougao::DajTjeme (int indeks) const {
    if (!(da_li_je_index_ok(indeks))) throw std::domain_error ("Nekorektan indeks");
    if (indeks == 1) return Trougao::t1;
    else if (indeks == 2) return Trougao::t2;
    return Trougao::t3;
}
double Trougao::DajStranicu (int indeks) const {
    if (!(da_li_je_index_ok(indeks))) throw std::domain_error ("Nekorektan indeks");
    if (indeks == 1) return duzina_stranice(t2, t3);
    else if (indeks == 2) return duzina_stranice(t1, t3);
    return duzina_stranice(t1, t2);
}
double Trougao::DajUgao (int indeks) const { //OK
    if (!(da_li_je_index_ok(indeks))) throw std::domain_error ("Nekorektan indeks");
    double alfa, beta, gama;
    double a (duzina_stranice(t2, t3)), b (duzina_stranice(t1, t3)), c (duzina_stranice(t1, t2));
    alfa = (std::acos ((b*b + c*c - a*a) / (2*b*c)));
    beta = (std::acos ((a*a + c*c - b*b) / (2*a*c)));
    gama = (std::acos ((a*a + b*b - c*c) / (2*a*b)));
    if (indeks == 1) return alfa;
    else if (indeks == 2) return beta;
    return gama;
}
Tacka Trougao::DajCentar() const {
    Tacka centar;
    centar.first = (t1.first + t2.first + t3.first) / 3.;
    centar.second = (t1.second + t2.second + t3.second) / 3.;
    return centar;
}
bool Trougao::DaLiJePozitivnoOrijentiran() const { //OK
    if (izraz(t1, t2, t3) > 0) return true;
    return false;
}
void Trougao::Ispisi() const { //OK
    std::cout << "((" << t1.first << "," << t1.second << ")";
    std::cout << ",(" << t2.first << "," << t2.second << ")";
    std::cout << ",(" << t3.first << "," << t3.second << "))";
}
void Trougao::Transliraj (double delta_x, double delta_y) {
    t1.first += delta_x; t2.first += delta_x; t3.first += delta_x;
    t1.second += delta_y; t2.second += delta_y; t3.second += delta_y;
}
void Trougao::Skaliraj (const Tacka &t, double faktor) {
    if (da_li_je_nula(faktor)) throw std::domain_error ("Nekorektan faktor skaliranja");
    Tacka pomocna1 = t1, pomocna2 = t2, pomocna3 = t3;
    t1.first = skaliraj_x(pomocna1, t, faktor); t2.first = skaliraj_x(pomocna2, t, faktor); t3.first = skaliraj_x(pomocna3, t, faktor);
    t1.second = skaliraj_y(pomocna1, t, faktor); t2.second = skaliraj_y(pomocna2, t, faktor); t3.second = skaliraj_y(pomocna3, t, faktor);
}
bool Trougao::DaLiJeUnutra (const Tacka &t) const { //OK
    double i1(izraz(t1, t2, t3)), i2(izraz(t1, t2, t)), i3(izraz(t2,t3,t)), i4(izraz(t3, t1, t));
    if (i1 > 0 && i2 > 0 && i3 > 0 && i4 > 0) return true;
    else if (i1 < 0 && i2 < 0 && i3 < 0 && i4 < 0) return true;
    return false;
}
void Trougao::Centriraj (const Tacka &t) {
    Tacka centar = DajCentar();
    double x, y;
    x = t.first - centar.first; y = t.second - centar.second;
    Transliraj(x, y);
}
void Trougao::Rotiraj (const Tacka &t, double ugao) {
    Tacka pomocna1 = t1, pomocna2 = t2, pomocna3 = t3;
    t1.first = izracunaj_rotaciju_x(pomocna1, t, ugao); t2.first = izracunaj_rotaciju_x(pomocna2, t, ugao);t3.first = izracunaj_rotaciju_x(pomocna3, t, ugao);
    t1.second = izracunaj_rotaciju_y(pomocna1, t, ugao);t2.second = izracunaj_rotaciju_y(pomocna2, t, ugao); t3.second = izracunaj_rotaciju_y(pomocna3, t, ugao);
}
void Trougao::Rotiraj (double ugao) {
    Tacka rotaciona = DajCentar();
    Tacka pomocna1 = t1, pomocna2 = t2, pomocna3 = t3;
    t1.first = izracunaj_rotaciju_x(pomocna1, rotaciona, ugao); t2.first = izracunaj_rotaciju_x(pomocna2, rotaciona, ugao); t3.first = izracunaj_rotaciju_x(pomocna3, rotaciona, ugao); 
    t1.second = izracunaj_rotaciju_y(pomocna1, rotaciona, ugao); t2.second = izracunaj_rotaciju_y(pomocna2, rotaciona, ugao); t3.second = izracunaj_rotaciju_y(pomocna3, rotaciona, ugao);
}
void Trougao::Skaliraj (double faktor) {
    Tacka skalarna = DajCentar();
    Tacka pomocna1 = t1, pomocna2 = t2, pomocna3 = t3;
    t1.first = skaliraj_x(pomocna1, skalarna, faktor); t2.first = skaliraj_x(pomocna2, skalarna, faktor); t3.first = skaliraj_x(pomocna3, skalarna, faktor);
    t1.second = skaliraj_y(pomocna1, skalarna, faktor); t2.second = skaliraj_y(pomocna2, skalarna, faktor); t3.second = skaliraj_y(pomocna3, skalarna, faktor);
}
bool DaLiSuPodudarni (const Trougao &t1, const Trougao &t2) {
    double duzina_a = Trougao::duzina_stranice(t1.t2, t1.t3), duzina_b = Trougao::duzina_stranice(t1.t1,t1.t3), duzina_c = Trougao::duzina_stranice(t1.t1,t1.t2);
    double duzina_a1 = Trougao::duzina_stranice(t2.t2,t2.t3), duzina_b1 = Trougao::duzina_stranice(t2.t1,t2.t3), duzina_c1 = Trougao::duzina_stranice(t2.t1,t2.t2);
    
    if (Trougao::SUS(Trougao::duzina_stranice(t1.t1,t1.t3), Trougao::duzina_stranice(t2.t1,t2.t3), Trougao::duzina_stranice(t1.t1,t1.t2), Trougao::duzina_stranice(t2.t1,t2.t2), t1.DajUgao(1), t2.DajUgao(1)))
        return true;
    if (Trougao::SUS (Trougao::duzina_stranice(t1.t1,t1.t3), Trougao::duzina_stranice(t2.t1,t2.t3), Trougao::duzina_stranice(t1.t2,t1.t3), Trougao::duzina_stranice(t2.t2,t2.t3), t1.DajUgao(3), t2.DajUgao(3)))
        return true;
    if (Trougao::SUS (Trougao::duzina_stranice(t1.t1,t1.t2), Trougao::duzina_stranice(t2.t1,t2.t2), Trougao::duzina_stranice(t1.t2,t1.t3), Trougao::duzina_stranice(t2.t2,t2.t3), t1.DajUgao(2), t2.DajUgao(2)))
        return true;
    if (Trougao::USU (t1.DajUgao(1), t2.DajUgao(1), t1.DajUgao(2), t2.DajUgao(2), Trougao::duzina_stranice(t1.t1,t1.t2), Trougao::duzina_stranice(t2.t1,t2.t2)))
        return true;
    if (Trougao::USU (t1.DajUgao(2),t2.DajUgao(2),t1.DajUgao(3),t2.DajUgao(3), Trougao::duzina_stranice(t1.t2,t1.t3), Trougao::duzina_stranice(t2.t2,t2.t3)))
        return true;
    if (Trougao::USU (t1.DajUgao(1),t2.DajUgao(1),t1.DajUgao(3),t2.DajUgao(3), Trougao::duzina_stranice(t1.t1,t1.t3),Trougao::duzina_stranice(t2.t1,t2.t3)))
        return true;
        
    double ugao_za_slanje, ugao_za_slanje1;
    if (duzina_a > duzina_c) {
        ugao_za_slanje = t1.DajUgao(1);
        ugao_za_slanje1 = t2.DajUgao(1);
    }
    else {
        ugao_za_slanje = t1.DajUgao(3);
        ugao_za_slanje1 = t2.DajUgao(3);
    }
    if (Trougao::SUS (duzina_a, duzina_a1, duzina_c, duzina_c1, ugao_za_slanje, ugao_za_slanje1)) 
        return true;
    if (duzina_b > duzina_c) {
        ugao_za_slanje = t1.DajUgao(2);
        ugao_za_slanje1 = t2.DajUgao(2);
    }
    else {
        ugao_za_slanje = t1.DajUgao(3);
        ugao_za_slanje1 = t2.DajUgao(3);
    }
    if (Trougao::SUS (duzina_b, duzina_b1, duzina_c, duzina_c1, ugao_za_slanje, ugao_za_slanje1)) 
        return true;
    if (duzina_a > duzina_b) {
        ugao_za_slanje = t1.DajUgao(1);
        ugao_za_slanje1 = t2.DajUgao(1);
    }
    else {
        ugao_za_slanje = t1.DajUgao(2);
        ugao_za_slanje1 = t2.DajUgao(2);
    }
    if (Trougao::SUS (duzina_a, duzina_a1, duzina_b, duzina_b1, ugao_za_slanje, ugao_za_slanje1)) 
        return true;
        
    if (Trougao::da_li_su_isti(duzina_a,duzina_a1) && Trougao::da_li_su_isti(duzina_b,duzina_b1) && Trougao::da_li_su_isti(duzina_c,duzina_b1) && Trougao::da_li_su_isti(Trougao::izraz(t1.t2,t1.t3,t1.t1), Trougao::izraz(t2.t2,t2.t3,t2.t1))) return true;
    if (Trougao::da_li_su_isti(duzina_a,duzina_a1) && Trougao::da_li_su_isti(duzina_b,duzina_c1) && Trougao::da_li_su_isti(duzina_c,duzina_b1) && Trougao::da_li_su_isti(Trougao::izraz(t1.t2,t1.t3,t1.t1), Trougao::izraz(t2.t3,t2.t2,t2.t1))) return true;
    if (Trougao::da_li_su_isti(duzina_a,duzina_b1) && Trougao::da_li_su_isti(duzina_b,duzina_a1) && Trougao::da_li_su_isti(duzina_c,duzina_c1) && Trougao::da_li_su_isti(Trougao::izraz(t1.t2,t1.t3,t1.t1), Trougao::izraz(t2.t1,t2.t3,t2.t2))) return true;
    if (Trougao::da_li_su_isti(duzina_a,duzina_b1) && Trougao::da_li_su_isti(duzina_b,duzina_c1) && Trougao::da_li_su_isti(duzina_c,duzina_b1) && Trougao::da_li_su_isti(Trougao::izraz(t1.t2,t1.t3,t1.t1), Trougao::izraz(t2.t3,t2.t1,t2.t2))) return true;
    if (Trougao::da_li_su_isti(duzina_a,duzina_c1) && Trougao::da_li_su_isti(duzina_b,duzina_a1) && Trougao::da_li_su_isti(duzina_c,duzina_b1) && Trougao::da_li_su_isti(Trougao::izraz(t1.t2,t1.t3,t1.t1), Trougao::izraz(t2.t1,t2.t2,t2.t3))) return true;
    if (Trougao::da_li_su_isti(duzina_a,duzina_c1) && Trougao::da_li_su_isti(duzina_b,duzina_b1) && Trougao::da_li_su_isti(duzina_c,duzina_a1) && Trougao::da_li_su_isti(Trougao::izraz(t1.t2,t1.t3,t1.t1), Trougao::izraz(t2.t2,t2.t2,t2.t3))) return true;
    return false;
}
bool DaLiSuSlicni (const Trougao &t1, const Trougao &t2) {
    double a, b, c, a1, b1, c1;
    a = Trougao::duzina_stranice(t1.t2,t1.t3); b = Trougao::duzina_stranice(t1.t1,t1.t3); c = Trougao::duzina_stranice(t1.t1,t1.t2);
    a1 = Trougao::duzina_stranice(t2.t2,t2.t3); b1 = Trougao::duzina_stranice(t2.t1,t2.t3); c1 = Trougao::duzina_stranice(t2.t1,t2.t2);
    double prvi [3] = {a,b,c}, drugi[3] = {a1,b1,c1};
    
    //odnos str
    if (Trougao::da_li_su_isti(prvi[0]*drugi[1],drugi[0]*prvi[1]) && Trougao::da_li_su_isti(prvi[2]*drugi[1],drugi[2]*prvi[1])) return true;
    
    //ista stranice i orijentacija
    if (Trougao::da_li_su_isti(a/c1,b/b1) && Trougao::da_li_su_isti(b/b1,c/a1) && Trougao::da_li_su_isti(Trougao::izraz(t1.t2,t1.t3,t1.t1), Trougao::izraz(t2.t2,t2.t2,t2.t3))) return true;
    if (Trougao::da_li_su_isti(a/b1,b/a1) && Trougao::da_li_su_isti(b/a1,c/c1) && Trougao::da_li_su_isti(Trougao::izraz(t1.t2,t1.t3,t1.t1), Trougao::izraz(t2.t1,t2.t3,t2.t2))) return true;
 
    if (Trougao::da_li_su_isti(a/c1,b/a1) && Trougao::da_li_su_isti(b/a1,c/b1) && Trougao::da_li_su_isti(Trougao::izraz(t1.t2,t1.t3,t1.t1), Trougao::izraz(t2.t1,t2.t2,t2.t3))) return true;
    
    if (Trougao::da_li_su_isti(a/b1,b/a1) && Trougao::da_li_su_isti(b/a1,c/c1) && Trougao::da_li_su_isti(Trougao::izraz(t1.t2,t1.t3,t1.t1), Trougao::izraz(t2.t1,t2.t3,t2.t2))) return true;
    if (Trougao::da_li_su_isti(a/a1,b/b1) && Trougao::da_li_su_isti(b/b1,c/c1) && Trougao::da_li_su_isti(Trougao::izraz(t1.t2,t1.t3,t1.t1), Trougao::izraz(t2.t1,t2.t3,t2.t2))) return true;
 
    //isti uglovi
    if (Trougao::da_li_su_isti(t1.DajUgao(1), t2.DajUgao(1))) {
        if (Trougao::da_li_su_isti(t1.DajUgao(2), t2.DajUgao(2))) {
            if (Trougao::da_li_su_isti(t1.DajUgao(3), t2.DajUgao(3))) return true;
        }
        if (Trougao::da_li_su_isti(t1.DajUgao(2), t2.DajUgao(3))) {
            if (Trougao::da_li_su_isti(t1.DajUgao(3), t2.DajUgao(2))) return true;
        }
    }
    if (Trougao::da_li_su_isti(t1.DajUgao(1), t2.DajUgao(3))) {
        if (Trougao::da_li_su_isti(t1.DajUgao(2), t2.DajUgao(1))) {
            if (Trougao::da_li_su_isti(t1.DajUgao(3), t2.DajUgao(2))) return true;
        }
        if (Trougao::da_li_su_isti(t1.DajUgao(2), t2.DajUgao(2))) {
            if (Trougao::da_li_su_isti(t1.DajUgao(3), t2.DajUgao(2))) return true;
        }
    }
    return false;
}
bool DaLiSuIdenticni (const Trougao &t1, const Trougao &t2) {
    bool prva(false), druga(false), treca(false);
    if (Trougao::da_li_su_isti(t1.t1.first, t2.t1.first) && Trougao::da_li_su_isti(t1.t1.second, t2.t1.second)) prva = true;
    if (Trougao::da_li_su_isti(t1.t1.first, t2.t2.first) && Trougao::da_li_su_isti(t1.t1.second, t2.t2.second)) prva = true;
    if (Trougao::da_li_su_isti(t1.t1.first, t2.t3.first) && Trougao::da_li_su_isti(t1.t1.second, t2.t3.second)) prva = true;
    if (!prva) return false;
    if (Trougao::da_li_su_isti(t1.t2.first, t2.t1.first) && Trougao::da_li_su_isti(t1.t2.second, t2.t1.second)) druga = true;
    if (Trougao::da_li_su_isti(t1.t2.first, t2.t2.first) && Trougao::da_li_su_isti(t1.t2.second, t2.t2.second)) druga = true;
    if (Trougao::da_li_su_isti(t1.t2.first, t2.t3.first) && Trougao::da_li_su_isti(t1.t2.second, t2.t3.second)) druga = true;
    if (!druga) return false;
    if (Trougao::da_li_su_isti(t1.t3.first, t2.t1.first) && Trougao::da_li_su_isti(t1.t3.second, t2.t1.second)) treca = true;
    if (Trougao::da_li_su_isti(t1.t3.first, t2.t2.first) && Trougao::da_li_su_isti(t1.t3.second, t2.t2.second)) treca = true;
    if (Trougao::da_li_su_isti(t1.t3.first, t2.t3.first) && Trougao::da_li_su_isti(t1.t3.second, t2.t3.second)) treca = true;
    if (!treca) return false;
    return true;
}
int main ()
{
   int n(0);
   std::cout << "Koliko zelite kreirati trouglova: ";
   std::cin >> n;
   std::vector<std::shared_ptr<Trougao>>v(n);
   for (int i=0; i<n; i++) {
        try { 
            Tacka a, b, c ;
            double t1x, t1y, t2x, t2y, t3x, t3y;
            std::cout << "Unesite podatke za " << i+1 << ". trougao (x1 y1 x2 y2 x3 y3): ";
            std::cin >> t1x >> t1y;
            std::cin >> t2x >> t2y;
            std::cin >> t3x >> t3y;
            a = std::make_pair(t1x, t1y); b = std::make_pair(t2x, t2y); c = std::make_pair(t3x, t3y);
            std::shared_ptr <Trougao> pok (new Trougao(a,b,c));
            v[i] = pok;
        }
        catch (std::domain_error por) {
            std::cout << por.what() << ", ponovite unos!" << std::endl;
            i--; 
        }
        catch (std::bad_alloc ) {
            std::cout << "Nema memorije!" << std::endl;
        }
    }
    double d_x, d_y;
    std::cout << "Unesite vektor translacije (dx dy): ";
    std::cin >> d_x >> d_y;
    std::transform(v.begin(), v.end(), v.begin(), [d_x,d_y] (std::shared_ptr<Trougao> p) { p->Transliraj(d_x, d_y); return p;}); // TRANSLACIJA
    std::cout << "Unesite ugao rotacije: ";
    double ugao;
    std::cin >> ugao;
    std::transform(v.begin(),v.end(), v.begin(), [ugao] (std::shared_ptr<Trougao> p) { //ROTACIJA
        Tacka centar = p->DajCentar();
        p->Rotiraj(centar, ugao);
        return p;
    });
    std::cout << "Unesite faktor skaliranja: ";
    double f_s; std::cin >> f_s;
    std::transform(v.begin(),v.end(),v.begin(), [f_s] (std::shared_ptr<Trougao> p) { //SKALIRANJE
        Tacka centar = p->DajTjeme(1);
        p->Skaliraj(centar, f_s);
        return p;
    });
   std::cout << "Trouglovi nakon obavljenih transformacija:" << std::endl;        
   std::sort (v.begin(), v.end(), [] (std::shared_ptr<Trougao> p, std::shared_ptr<Trougao> p1) { return p->DajPovrsinu() < p1->DajPovrsinu();}); //SORTIRANJE
   std::for_each (v.begin(),v.end(), [] (std::shared_ptr<Trougao> p) { //ISPIS
       p->Ispisi();
       std::cout << std::endl;
   });
   std::cout << "Trougao sa najmanjim obimom: ";
   auto najmanji = std::min_element (v.begin(),v.end(), [] (std::shared_ptr<Trougao> p, std::shared_ptr<Trougao> p1) { //MIN OBIM
       if ((*p).DajObim() < (*p1).DajObim()) return true;
       return false;
   }); (*najmanji)->Ispisi();
   bool uslov = false;
  // std::cout << std::endl << "Parovi identicnih trouglova:" << std::endl;
   for (int i=0; i<n-1; i++) {
       for (int j=i+1; j<n; j++) {
        if (DaLiSuIdenticni(*v[i], *v[j])) {
            if (!uslov) {
                std::cout << std::endl << "Parovi identicnih trouglova:" << std::endl;
                uslov = true;
            }
        v[i]->Ispisi();
        std::cout << " i ";
        v[j]->Ispisi();
        std::cout << std::endl;
        }
    }
   }
   if (!uslov) std::cout << std::endl <<"Nema identicnih trouglova!" << std::endl;
   //std::cout << std::endl<<"Parovi podudarnih trouglova:" <<std::endl;
   uslov = false;
   for (int i=0; i<n-1; i++) {
       for (int j=i+1; j<n; j++) {
           if (DaLiSuPodudarni(*v[i], *v[j])) {
               if (!uslov) {
                   std::cout << std::endl << "Parovi podudarnih trouglova:" << std::endl;
                   uslov = true;
               }
               v[i]->Ispisi();
               std::cout << " i ";
               v[j]->Ispisi();
               std::cout << std::endl;
           }
       }
   }
   if (!uslov) std::cout <<"Nema podudarnih trouglova!" << std::endl;
   uslov = false;

   for (int i=0; i<n-1; i++) {
       for (int j=i+1; j<n; j++) {
           if (DaLiSuSlicni(*v[i], *v[j])) {
               if (!uslov) {
                   std::cout << std::endl <<"Parovi slicnih trouglova:" << std::endl;
                   uslov = true;
               }
               v[i]->Ispisi();
               std::cout << " i ";
               v[j]->Ispisi();
               std::cout << std::endl;
           }
       }   
   }
   if (!uslov) std::cout <<  "Nema slicnih trouglova!" << std::endl;
   return 0;
}