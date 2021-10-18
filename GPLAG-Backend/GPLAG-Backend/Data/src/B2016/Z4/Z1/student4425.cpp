#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <memory>

typedef std::pair<double, double> Tacka;
static double eps(1e-10);

class Trougao {
private:
    Tacka X, Y, Z;
    
    static double Formula (const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        return (t1.first)*(t2.second - t3.second) + (t2.first)*(t3.second - t1.second) + (t3.first)*(t1.second - t2.second);
    }
    Tacka DajTacku (int indeks) const {
        if (indeks == 1) return X;
        else if (indeks == 2) return Y;
        else if (indeks == 3) return Z;
        else throw std::range_error("Nekorektan indeks");
    }
    static double DajDuzinu (const Tacka &t1, const Tacka &t2) {
        return std::sqrt((t2.first - t1.first)*(t2.first - t1.first) + (t2.second - t1.second)*(t2.second - t1.second));
    }
public:
    Trougao (const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        Postavi(t1, t2, t3);
    }
    void Postavi (const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        if (Orijentacija(t1, t2, t3) == 0) throw std::domain_error("Nekorektne pozicije tjemena");
        X = t1; Y = t2; Z = t3;
    }
    void Postavi (int indeks, const Tacka &t) {
        if (indeks == 1) X = std::make_pair(t.first, t.second);
        else if (indeks == 2) Y = std::make_pair(t.first, t.second);
        else if (indeks == 3) Z = std::make_pair(t.first, t.second);
        else throw std::range_error("Nekorektan indeks");
    }
    static int Orijentacija (const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        double expression = Formula(t1, t2, t3);
        if (expression == 0.0f) return 0;
        else if (expression < 0) return -1;
        else return 1;
    }
    Tacka DajTjeme (int indeks) const {
        return this->DajTacku(indeks);
    }
    double DajStranicu (int indeks) const;
    double DajUgao (int indeks) const {
        if (indeks == 1) {
            return std::acos((DajStranicu(2)*DajStranicu(2)+DajStranicu(3)*DajStranicu(3)-DajStranicu(1)*DajStranicu(1))/(2*DajStranicu(2)*DajStranicu(3)));
        } else if (indeks == 2) {
            return std::acos((DajStranicu(3)*DajStranicu(3)+DajStranicu(1)*DajStranicu(1)-DajStranicu(2)*DajStranicu(2))/(2*DajStranicu(3)*DajStranicu(1)));
        } else if (indeks == 3) {
            return std::acos((DajStranicu(1)*DajStranicu(1)+DajStranicu(2)*DajStranicu(2)-DajStranicu(3)*DajStranicu(3))/(2*DajStranicu(1)*DajStranicu(2)));
        } else throw std::range_error("Nekorektan indeks");
    }
    Tacka DajCentar() const {
        double x = (X.first + Y.first + Z.first)/3.;
        double y = (X.second + Y.second + Z.second)/3.;
        return std::make_pair(x, y);
    }
    double DajObim() const {
        return DajStranicu(1) + DajStranicu(2) + DajStranicu(3);
    }
    double DajPovrsinu() const {
        return 0.5*std::fabs(Formula(X, Y, Z));
    }
    bool DaLiJePozitivnoOrijentiran() const { 
        double value(Formula(X, Y, Z));
        if (value - eps > 0 && value!=0) return true;
        else return false;
    }
    bool DaLiJeUnutra (const Tacka &t) const {
        if (Orijentacija(DajTjeme(1), DajTjeme(2), DajTjeme(3)) == 1 &&
            Orijentacija(DajTjeme(1), DajTjeme(2), t) == 1 &&
            Orijentacija(DajTjeme(2), DajTjeme(3), t) == 1 &&
            Orijentacija(DajTjeme(3), DajTjeme(1), t) == 1) return true;
        else return false;
    }
    void Ispisi() const {
        std::cout << "((" << X.first << "," << X.second << "),("
                  << Y.first << "," << Y.second << "),(" 
                  << Z.first << "," << Z.second << "))";
    }
    void Transliraj (double delta_x, double delta_y) {
        (X.first)+=delta_x; (Y.first)+=delta_x; (Z.first)+=delta_x;
        (X.second)+=delta_y; (Y.second)+=delta_y; (Z.second)+=delta_y;
    }
    void Centriraj (const Tacka &t) {
        Tacka C(DajCentar());
        double delta_x(t.first - C.first);
        double delta_y(t.second - C.second);
        Transliraj(delta_x, delta_y);
    }
    void Rotiraj (const Tacka &t, double ugao) {
        X = std::make_pair(t.first + (X.first - t.first)*std::cos(ugao) - (X.second - t.second)*std::sin(ugao), t.second + (X.first - t.first)*std::sin(ugao) - (X.second - t.second)*std::cos(ugao));
        Y = std::make_pair(t.first + (Y.first - t.first)*std::cos(ugao) - (Y.second - t.second)*std::sin(ugao), t.second + (Y.first - t.first)*std::sin(ugao) - (Y.second - t.second)*std::cos(ugao));
        Z = std::make_pair(t.first + (Z.first - t.first)*std::cos(ugao) - (Z.second - t.second)*std::sin(ugao), t.second + (Z.first - t.first)*std::sin(ugao) - (Z.second - t.second)*std::cos(ugao));
    }
    void Skaliraj (const Tacka &t, double faktor) {
        if (faktor == 0.0f) throw std::domain_error("Nekorektan faktor skaliranja");
        X = std::make_pair(t.first + (X.first - t.first)*faktor, t.second + (X.second - t.second)*faktor);
        Y = std::make_pair(t.first + (Y.first - t.first)*faktor, t.second + (Y.second - t.second)*faktor);
        Z = std::make_pair(t.first + (Z.first - t.first)*faktor, t.second + (Z.second - t.second)*faktor);
    }
    void Rotiraj (double ugao) {
        if (ugao == 0) return;
        Rotiraj(DajCentar(), ugao);
    }
    void Skaliraj (double faktor) {
        Skaliraj(DajCentar(), faktor);
    }
    friend bool DaLiSuIdenticni (const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni (const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni (const Trougao &t1, const Trougao &t2);
};

bool DaLiSuSlicni (const Trougao &t1, const Trougao &t2) {
    double a1 (t1.DajUgao(1));
    double a2 (t1.DajUgao(2));
    double a3 (t1.DajUgao(3));
    double b1 (t2.DajUgao(1));
    double b2 (t2.DajUgao(2));
    double b3 (t2.DajUgao(3));
    double angles1[]{a1,a2,a3};
    double angles2[]{b1,b2,b3};
    std::sort(angles1, angles1+3);
    std::sort(angles2, angles2+3);
    if (std::fabs(angles1[0]-angles2[0]) < eps && std::fabs(angles1[1]-angles2[1]) < eps && std::fabs(angles1[2]-angles2[2]) < eps) return true;
    else return false;
    
}

bool DaLiSuPodudarni (const Trougao &t1, const Trougao &t2) {
    double a1 (t1.DajStranicu(1));
    double a2 (t1.DajStranicu(2));
    double a3 (t1.DajStranicu(3));
    double b1 (t2.DajStranicu(1));
    double b2 (t2.DajStranicu(2));
    double b3 (t2.DajStranicu(3));
    double sides1[]{a1,a2,a3};
    double sides2[]{b1,b2,b3};
    std::sort(sides1, sides1+3);
    std::sort(sides2, sides2+3);
    bool sides(false);
    if (std::fabs(sides1[0]-sides2[0]) < eps && std::fabs(sides1[1]-sides2[1]) < eps && std::fabs(sides1[2]-sides2[2]) < eps) sides = true;
    if (!sides) return false;
    a1 = t1.DajUgao(1);
    a2 = t1.DajUgao(2);
    a3 = t1.DajUgao(3);
    b1 = t2.DajUgao(1);
    b2 = t2.DajUgao(2);
    b3 = t2.DajUgao(3);
    double angles1[]{a1,a2,a3};
    double angles2[]{b1,b2,b3};
    std::sort(angles1, angles1+3);
    std::sort(angles2, angles2+3);
    if (std::fabs(angles1[0]-angles2[0]) < eps && std::fabs(angles1[1]-angles2[1]) < eps && std::fabs(angles1[2]-angles2[2]) < eps && sides) return true;
    else return false;
}

bool DaLiSuIdenticni (const Trougao &t1, const Trougao &t2) {
    Tacka A1 (t1.DajTjeme(1));
    Tacka A2 (t1.DajTjeme(2));
    Tacka A3 (t1.DajTjeme(3));
    Tacka B1 (t2.DajTjeme(1));
    Tacka B2 (t2.DajTjeme(2));
    Tacka B3 (t2.DajTjeme(3));
    if (std::fabs(A1.first - B1.first) < eps && std::fabs(A1.second - B1.second) < eps && 
        std::fabs(A2.first - B2.first) < eps && std::fabs(A2.second - B2.second) < eps &&
        std::fabs(A3.first - B3.first) < eps && std::fabs(A3.second - B3.second) < eps) return true;
    else return false;
}

double Trougao::DajStranicu (int indeks) const {
    if (indeks == 1) {
        Tacka t1 = this->Trougao::DajTacku(2);
        Tacka t2 = this->Trougao::DajTacku(3);
        return Trougao::DajDuzinu(t1, t2);
    } else if (indeks == 2) {
        Tacka t1 = this->Trougao::DajTacku(1);
        Tacka t2 = this->Trougao::DajTacku(3);
        return Trougao::DajDuzinu(t1, t2);
    } else if (indeks == 3) {
        Tacka t1 = this->Trougao::DajTacku(1);
        Tacka t2 = this->Trougao::DajTacku(2);
        return Trougao::DajDuzinu(t1, t2);
    } else throw std::range_error("Nekorektan indeks");
}

int main () {
    
    std::cout << "Koliko zelite kreirati trouglova: ";
    int br;
    std::cin >> br;
    std::vector<Trougao> trouglovi;
    for (int i = 0; i < br; i++) {
        std::cout << "Unesite podatke za " << i+1 << ". trougao (x1 y1 x2 y2 x3 y3): ";
        double x1, y1, x2, y2, x3, y3;
        std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        Trougao tmp({x1,y1},{x2,y2},{x3,y3});
        trouglovi.emplace_back(tmp);
    }
    std::cout << "Unesite vektor translacije: ";
    double dx, dy;
    std::cin >> dx >> dy;
    std::cout << "Unesite ugao rotacije: ";
    double ugao;
    std::cin >> ugao;
    std::cout << "Unesite faktor skaliranja: ";
    double faktor;
    std::cin >> faktor;
    for (int i = 0; i < br; i++) {
        trouglovi[i].Transliraj(dx, dy);
        trouglovi[i].Rotiraj(ugao);
        trouglovi[i].Skaliraj(faktor);
    }
    std::cout << "Trouglovi nakon obavljenih transformacija: ";
    for (int i = 0; i < br; i++) trouglovi[i].Ispisi(), std::cout<<std::endl;
    std::cout << "Trougao sa najmanjim obimom: ";
    (*std::max_element(trouglovi.begin(), trouglovi.end(), [] (Trougao t1, Trougao t2) {if (t1.DajObim()<t2.DajObim()) return true; else return false;})).Ispisi();
    
	return 0;
}