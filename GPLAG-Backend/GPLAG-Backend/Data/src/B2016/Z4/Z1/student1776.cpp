/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!

#include <iostream>
#include <stdexcept>
#include <math.h>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>

const double eps(1e-10);

typedef std::pair<double, double> Tacka;

class Trougao {
    Tacka A, B, C;
    public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    void Postavi(int indeks, const Tacka &t);
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        int suma(0);
        suma = t1.first * (t2.second - t3.second) - t2.first * (t1.second - t3.second) + t3.first * (t1.second - t2.second);
        if (suma > 0) return 1;
        else if (suma < 0) return -1;
        else return 0;
    }
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

Trougao::Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    if (Orijentacija(t1,t2,t3) == 0) throw std::domain_error ("Nekorektne pozicije tjemena");
    A.first = t1.first; A.second = t1.second;
    B.first = t2.first; B.second = t2.second;
    C.first = t3.first; C.second = t3.second;
}

void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    if (Orijentacija(t1,t2,t3) == 0) throw std::domain_error ("Nekorektne pozicije tjemena");
    A.first = t1.first; A.second = t1.second;
    B.first = t2.first; B.second = t2.second;
    C.first = t3.first; C.second = t3.second;
}

void Trougao::Postavi(int indeks, const Tacka &t) {
    if (indeks < 1 || indeks > 3) throw std::range_error ("Nekorektan indeks");
    if (indeks == 1) {
        A.first = t.first;
        A.second = t.second;
    }
    else if (indeks == 2) {
        B.first = t.first;
        B.second = t.second;
    }
    else {
        C.first = t.first;
        C.second = t.second;
    }
}

Tacka Trougao::DajTjeme(int indeks) const {
    if (indeks < 1 || indeks > 3) throw std::range_error ("Nekorektan indeks");
    if (indeks == 1) return A;
    else if (indeks == 2) return B;
    else return C;
}

double Trougao::DajStranicu(int indeks) const {
    if (indeks < 1 || indeks > 3) throw std::range_error ("Nekorektan indeks");
    if (indeks == 1) {
        return sqrt((B.first - C.first) * (B.first - C.first) + (B.second - C.second) * (B.second - C.second));
    }
    else if (indeks == 2) {
        return sqrt((A.first - C.first) * (A.first - C.first) + (A.second - C.second) * (A.second - C.second));
    }
    else {
        return sqrt((B.first - A.first) * (B.first - A.first) + (B.second - A.second) * (B.second - A.second));
    }
}

double Trougao::DajUgao(int indeks) const {
    if (indeks < 1 || indeks > 3) throw std::range_error ("Nekorektan indeks");
    if (indeks == 1) {
        return acos((DajStranicu(2) * DajStranicu(2) + DajStranicu(3) * DajStranicu(3) - DajStranicu(1) * DajStranicu(1)) / (2 * DajStranicu(2) * DajStranicu(3)));
    }
    else if (indeks == 2) {
        return acos((DajStranicu(1) * DajStranicu(1) + DajStranicu(3) * DajStranicu(3) - DajStranicu(2) * DajStranicu(2)) / (2 * DajStranicu(1) * DajStranicu(3)));
    }
    else {
        return acos((DajStranicu(1) * DajStranicu(1) + DajStranicu(2) * DajStranicu(2) - DajStranicu(3) * DajStranicu(3)) / (2 * DajStranicu(1) * DajStranicu(2)));
    }
}

Tacka Trougao::DajCentar() const {
    Tacka centar;
    centar.first =  (A.first + B.first + C.first) / 3.;
    centar.second = (A.second + B.second + C.second) / 3.;
    return centar;
}

double Trougao::DajObim() const {
    return DajStranicu(1) + DajStranicu(2) + DajStranicu(3);
}

double Trougao::DajPovrsinu() const {
    return 1./2 * abs(A.first * (B.second - C.second) - B.first * (A.second - C.second) + C.first * (A.second - B.second));
}

bool Trougao::DaLiJePozitivnoOrijentiran() const {
    if (Orijentacija(A,B,C) == 1) return true;
    return false;
}

bool Trougao::DaLiJeUnutra(const Tacka &t) const {
    if (Orijentacija(A,B,C) == 1 && Orijentacija(A,B,t) == 1 && Orijentacija(B,C,t) == 1 && Orijentacija(C,A,t) == 1) return true;
    return false;
}

void Trougao::Ispisi() const {
    std::cout << "((" << A.first << "," << A.second << "),(" << B.first << "," << B.second << "),(" << C.first << "," << C.second << "))";
}

void Trougao::Transliraj(double delta_x, double delta_y) {
    A.first += delta_x; A.second += delta_y;
    B.first += delta_x; B.second += delta_y;
    C.first += delta_x; C.second += delta_y;
}

void Trougao::Centriraj(const Tacka &t) {
    Tacka centar_stari(DajCentar());
    A.first += t.first - centar_stari.first;
    A.second += t.second - centar_stari.second;
    B.first += t.first - centar_stari.first;
    B.second += t.second - centar_stari.second;
    C.first += t.first - centar_stari.first;
    C.second += t.second - centar_stari.second;
}

void RotacijaJedneTacke(Tacka &t, const Tacka &tc, double ugao) {
    double kosinus = cos (ugao);
    double sinus = sin (ugao);
    t.first = tc.first + (t.first - tc.first) * kosinus - (t.second - tc.second) * sinus;
    t.second = tc.second + (t.first - tc.first) * sinus + (t.second - tc.second) * kosinus;
}

void Trougao::Rotiraj(const Tacka &t, double ugao) {
    RotacijaJedneTacke(A,t,ugao);
    RotacijaJedneTacke(B,t,ugao);
    RotacijaJedneTacke(C,t,ugao);
}

void SkalirajJednuTacku(Tacka &t, const Tacka &tc, double faktor) {
    t.first = tc.first + faktor * (t.first - tc.first);
    t.second = tc.second + faktor * (t.second - tc.second);
}

void Trougao::Skaliraj(const Tacka &t, double faktor) {
    if (faktor <= eps && faktor >= 0) throw std::domain_error ("Nekorektan faktor skaliranja");
    SkalirajJednuTacku(A,t,faktor);
    SkalirajJednuTacku(B,t,faktor);
    SkalirajJednuTacku(C,t,faktor);
}

void Trougao::Rotiraj(double ugao) {
    Tacka centar(DajCentar());
    RotacijaJedneTacke(A,centar,ugao);
    RotacijaJedneTacke(B,centar,ugao);
    RotacijaJedneTacke(C,centar,ugao);
}

void Trougao::Skaliraj(double faktor) {
    if (faktor <= eps && faktor >= 0) throw std::domain_error ("Nekorektan faktor skaliranja");
    Tacka centar(DajCentar());
    SkalirajJednuTacku(A,centar,faktor);
    SkalirajJednuTacku(B,centar,faktor);
    SkalirajJednuTacku(C,centar,faktor);
}

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2) {
    if (t1.A == t2.A && t1.B == t2.B && t1.C == t2.C) return true;
    else if (t1.A == t2.A && t1.B == t2.C && t1.C == t2.B) return true;
    else if (t1.A == t2.B && t1.B == t2.A && t1.C == t2.C) return true;
    else if (t1.A == t2.B && t1.B == t2.C && t1.C == t2.A) return true;
    else if (t1.A == t2.C && t1.B == t2.B && t1.C == t2.A) return true;
    else if (t1.A == t2.C && t1.B == t2.A && t1.C == t2.C) return true;
    else return false;
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2) {
    std::vector<double> v1 { t1.DajStranicu(1), t1.DajStranicu(2), t1.DajStranicu(3) };
    std::vector<double> v2 { t2.DajStranicu(1), t2.DajStranicu(2), t2.DajStranicu(3) };
    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());
    if (std::fabs(v1[0] - v2[0]) <= eps && std::fabs(v1[1] - v2[1]) <= eps && std::fabs(v1[2] - v2[2]) <= eps) return true;
    return false;
}

bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2) {
    double odnos1ab(0), odnos1bc(0), odnos1ac(0);
    double odnos2ab(0), odnos2bc(0), odnos2ac(0);
    odnos1ab = t1.DajStranicu(1) / t1.DajStranicu(2);
    odnos1bc = t1.DajStranicu(2) / t1.DajStranicu(3);
    odnos1ac = t1.DajStranicu(1) / t1.DajStranicu(3);
    odnos2ab = t2.DajStranicu(1) / t2.DajStranicu(2);
    odnos2bc = t2.DajStranicu(2) / t2.DajStranicu(3);
    odnos2ac = t2.DajStranicu(1) / t2.DajStranicu(3);
    if (std::fabs(odnos1ab - odnos2ab) <= eps && std::fabs(odnos1bc - odnos2bc) <= eps && std::fabs(odnos1ac - odnos2ac) <= eps)
        return true;
    return false;
}


int main ()
{
    std::cout << "Koliko zelite kreirati trouglova: ";
    int n;
    std::cin >> n;
    std::vector<std::shared_ptr<Trougao>> v;
    for (int i = 0; i < n; i++) {
        Tacka A, B, C;
        std::cout << "Unesite podatke za " << i + 1 << ". trougao (x1 y1 x2 y2 x3 y3): ";
        std::cin >> A.first >> A.second >> B.first >> B.second >> C.first >> C.second;
        if (Trougao::Orijentacija(A,B,C) == 0) {
            std::cout << "Nekorektne pozicije tjemena, ponovite unos!\n";
            i--;
            continue;
        }
        v.push_back(std::make_shared<Trougao> (A,B,C));
    }
    std::cout << "Unesite vektor translacije (dx dy): ";
    double dx, dy;
    std::cin >> dx >> dy;
    std::cout << "Unesite ugao rotacije: ";
    double ugao;
    std::cin >> ugao;
    std::cout << "Unesite faktor skaliranja: ";
    double faktor;
    std::cin >> faktor;
    std::transform(v.begin(), v.end(), v.begin(), [dx,dy,ugao,faktor](std::shared_ptr<Trougao> p) {
        (*p).Transliraj(dx, dy);
        (*p).Rotiraj(/*(*p).DajCentar(),*/ ugao);
        (*p).Skaliraj((*p).DajTjeme(1), faktor);
        return p;
    });
    std::sort(v.begin(), v.end(), [](std::shared_ptr<Trougao> p1, std::shared_ptr<Trougao> p2) {
        return ((*p1).DajPovrsinu() < (*p2).DajPovrsinu());    
    });
    std::cout <<"Trouglovi nakon obavljenih transformacija: " << std::endl;
    std::for_each(v.begin(), v.end(), [](std::shared_ptr<Trougao> p) {
        (*p).Ispisi();
        std::cout << std::endl;
    });
    std::shared_ptr<Trougao> min_obim;
    min_obim = *(std::min_element(v.begin(), v.end(), [](std::shared_ptr<Trougao> p1, std::shared_ptr<Trougao> p2) {
        return ((*p1).DajObim() < (*p2).DajObim());
    }));
    std::cout << "Trougao sa najmanjim obimom: ";
    (*min_obim).Ispisi();
    int brojac(0);
    for (int i = 0; i < n; i++) {
        Trougao t1(*(v[i]));
        for (int j = i + 1; j < n; j++) {
            Trougao t2(*(v[j]));
            if (DaLiSuIdenticni(t1,t2)) {
                brojac++;
            }
        }
    }
    std::cout << std::endl;
    if (brojac == 0) std::cout << "Nema identicnih trouglova!" << std::endl;
    else {
        std::cout << "Parovi identicnih trouglova: " << std::endl;
        for (int i = 0; i < n; i++) {
            Trougao t1(*(v[i]));
            for (int j = i + 1; j < n; j++) {
                Trougao t2(*(v[j]));
                if (DaLiSuIdenticni(t1,t2)) {
                    t1.Ispisi();
                    std::cout << " i ";
                    t2.Ispisi();
                    std::cout << std::endl;
                }
            }
        }
    }
    brojac = 0;
    for (int i = 0; i < n; i++) {
        Trougao t1(*(v[i]));
        for (int j = i + 1; j < n; j++) {
            Trougao t2(*(v[j]));
            if (DaLiSuPodudarni(t1,t2)) {
                brojac++;
            }
        }
    }
    if (brojac == 0) std::cout << "Nema podudarnih trouglova!" << std::endl;
    else {
        std::cout << "Parovi podudarnih trouglova:" << std::endl;
        for (int i = 0; i < n; i++) {
            Trougao t1(*(v[i]));
            for (int j = i + 1; j < n; j++) {
                Trougao t2(*(v[j]));
                if (DaLiSuPodudarni(t1,t2)) {
                    t1.Ispisi();
                    std::cout << " i ";
                    t2.Ispisi();
                    std::cout << std::endl;
                }
            }
        }
    }
    brojac = 0;
    for (int i = 0; i < n; i++) {
        Trougao t1(*(v[i]));
        for (int j = i + 1; j < n; j++) {
            Trougao t2(*(v[j]));
            if (DaLiSuSlicni(t1,t2)) {
                brojac++;
            }
        }
    }
    if (brojac == 0) std::cout << "Nema slicnih trouglova!" << std::endl;
    else {
        std::cout << "Parovi slicnih trouglova:" << std::endl;
        for (int i = 0; i < n; i++) {
            Trougao t1(*(v[i]));
            for (int j = i + 1; j < n; j++) {
                Trougao t2(*(v[j]));
                if (DaLiSuSlicni(t1,t2)) {
                    t1.Ispisi();
                    std::cout << " i ";
                    t2.Ispisi();
                    std::cout << std::endl;
                }
            }
        }
    }
	return 0;
}