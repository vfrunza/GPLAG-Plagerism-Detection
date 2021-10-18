/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <tuple>
#include <stdexcept>
#include <cmath>

#define pi 3.14159265359
#define eps 10e-10

bool DaLiSuIsti(double x, double y) {
    return fabs(x - y) < eps * (fabs(x) + fabs(y));
}
class Kugla {
private:
    double x, y, z, r;
public:
    explicit Kugla (double r = 0) {
        PostaviCentar(0, 0, 0);
        PostaviPoluprecnik(r);
    }
    Kugla (double x, double y, double z, double r = 0) {
        PostaviCentar(x, y, z);
        PostaviPoluprecnik(r);
    }
    explicit Kugla (const std::tuple <double, double, double> &centar, double r = 0) {
        PostaviCentar(std::get<0>(centar), std::get<1>(centar), std::get<2>(centar));
        PostaviPoluprecnik(r);
    }
    double DajX() const { return x; }
    double DajY() const { return y; }
    double DajZ() const { return z; }
    std::tuple<double, double, double> DajCentar() const { return std::make_tuple(x, y, z); }
    double DajPoluprecnik() const { return r; }
    double DajPovrsinu() const { return 4 * r * r * pi; }
    double DajZapreminu() const { return 4 / 3 * r * r * r * pi; }
    Kugla &PostaviX(double _x) { x = _x; return *this; }
    Kugla &PostaviY(double _y) { y = _y; return *this; }
    Kugla &PostaviZ(double _z) { z = _z; return *this; }
    Kugla &PostaviCentar(double x, double y, double z) {
        PostaviX(x);
        PostaviY(y);
        PostaviZ(z);
        return *this;
    }
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar) {
        PostaviCentar(std::get<0>(centar), std::get<1>(centar), std::get<2>(centar));
        return *this;
    }
    Kugla &PostaviPoluprecnik(double _r) {
        if (r < 0) {
            throw std::domain_error("Ilegalan poluprecnik");
        }
        r = _r;
        return *this;
    }
    void Ispisi() const { std::cout << "{(" << x << ", " << y << ", " << z << "), " << r << "}  " << std::endl; }
    void Translatiraj(double delta_x, double delta_y, double delta_z) { PostaviCentar(x + delta_x, y + delta_y, z + delta_z); }
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2) {
        return (DaLiSuIsti(k1.DajX(), k2.DajX()) && DaLiSuIsti(k1.DajY(), k2.DajY()) && DaLiSuIsti(k1.DajZ(), k2.DajZ()) && DaLiSuIsti(k1.DajPoluprecnik(), k2.DajPoluprecnik()));
    }
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2) {
        return (DaLiSuIsti(k1.DajPoluprecnik(), k2.DajPoluprecnik()));
    }
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2) {
        return (DaLiSuIsti(k1.DajX(), k2.DajX()) && DaLiSuIsti(k1.DajY(), k2.DajY()) && DaLiSuIsti(k1.DajZ(), k2.DajZ()));
    }
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2) {
        return DaLiSuIsti(RastojanjeCentra(k1, k2), k1.DajPoluprecnik() + k2.DajPoluprecnik());
    }
    friend bool DaLiSeDoridujuIznutra(const Kugla &k1, const Kugla &k2) {
        return DaLiSuIsti(RastojanjeCentra(k1, k2) + k1.DajPoluprecnik(), k2.DajPoluprecnik()) || DaLiSuIsti(RastojanjeCentra(k1, k2) + k2.DajPoluprecnik(), k1.DajPoluprecnik()); 
    }
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2) {
        return RastojanjeCentra(k1, k2) < (k1.DajPoluprecnik() + k2.DajPoluprecnik());
    }
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2) {
        return (RastojanjeCentra(k1, k2) > k1.DajPoluprecnik() && RastojanjeCentra(k1, k2) < k2.DajPoluprecnik()) || (RastojanjeCentra(k1, k2) > k2.DajPoluprecnik() && RastojanjeCentra(k1, k2) < k1.DajPoluprecnik());
    }
    bool DaLiSadrzi(const Kugla &k) const {
        return (RastojanjeCentra(*this, k) > k.DajPoluprecnik() && RastojanjeCentra(*this, k) < this->DajPoluprecnik());
    }
    friend double RastojanjeCentra(const Kugla &k1, const Kugla &k2) {
        return pow(k1.DajX() - k2.DajX(), 2) + pow(k1.DajY() - k2.DajY(), 2) + pow(k1.DajZ() - k2.DajZ(), 2);
    }
};

int main ()
{
    int n;
    std::cout << "Unesite broj n:";
    std::cin >> n;
    
	return 0;
}
