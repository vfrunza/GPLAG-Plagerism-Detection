                /B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <tuple>
#include <vector>
#include <algorithm>
#include <memory>

const double eps = 0.0000000001;

class Kugla
{
    double poluprecnik;
    std::tuple<double, double, double> koordinate_centra;
public:
    explicit Kugla(double r = 0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        poluprecnik = r;
    }
    Kugla(double x, double y, double z, double r = 0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        poluprecnik = r;
        std::get<0>(koordinate_centra) = x;
        std::get<1>(koordinate_centra) = y;
        std::get<2>(koordinate_centra) = z;
    }
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        poluprecnik = r;
        std::get<0>(koordinate_centra) = std::get<0>(centar);
        std::get<1>(koordinate_centra) = std::get<1>(centar);
        std::get<2>(koordinate_centra) = std::get<2>(centar);
    }
    double DajX() const {
        return std::get<0>(koordinate_centra);
    }
    double DajY() const {
        return std::get<1>(koordinate_centra);
    }
    double DajZ() const {
        return std::get<2>(koordinate_centra);
    }
    std::tuple<double, double, double> DajCentar() const {
        return koordinate_centra;
    }
    double DajPoluprecnik() const {
        return poluprecnik;
    }
    double DajPovrsinu() const {
        return 4*4*atan(1)*DajPoluprecnik()*DajPoluprecnik();
    }
    double DajZapreminu() const {
        return (4/3)*4*atan(1)*DajPoluprecnik()*DajPoluprecnik()*DajPoluprecnik();
    }
    Kugla &PostaviX(double x) {
        std::get<0>(koordinate_centra) = x;
        return *this;
    }
    Kugla &PostaviY(double y) {
        std::get<1>(koordinate_centra) = y;
        return *this;
    }
    Kugla &PostaviZ(double z) {
        std::get<2>(koordinate_centra) = z;
        return *this;
    }
    Kugla &PostaviCentar(double x, double y, double z) {
        Kugla::koordinate_centra = std::make_tuple(x, y, z);
        return *this;
    }
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar) {
        Kugla::koordinate_centra = centar;
        return *this;
    }
    Kugla &PostaviPoluprecnik(double r) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::poluprecnik = r;
        return *this;
    }
    void Ispisi() const {
        std::cout << "{(" << DajX() << "," << DajY() << "," << DajZ() << ")," << DajPoluprecnik() << "}";
    }
    void Transliraj(double delta_x, double delta_y, double delta_z) {
        *this = Kugla(DajX()+delta_x, DajY()+delta_y, DajZ()+delta_z);
    }
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
    bool DaLiSadrzi(const Kugla &k) const;
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);
};
template <typename Tip>
bool TestiranjeNaJednakost(Tip x, Tip y) {
    if(fabs(x-y) < (eps*(fabs(x) + fabs(y)))) return true;
    return false;
}
bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2)
{
    if(TestiranjeNaJednakost(k1.DajX(),k2.DajX()) && TestiranjeNaJednakost(k1.DajY(),k2.DajY()) && TestiranjeNaJednakost(k1.DajZ(),k2.DajZ()) && TestiranjeNaJednakost(k1.DajPoluprecnik(),k2.DajPoluprecnik())) 
        return true;
    return false;
}
bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2)
{
    if(TestiranjeNaJednakost(k1.DajPoluprecnik(),k2.DajPoluprecnik())) 
        return true;
    return false;
}
bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2)
{
    if(TestiranjeNaJednakost(k1.DajX(),k2.DajX()) && TestiranjeNaJednakost(k1.DajY(),k2.DajY()) && TestiranjeNaJednakost(k1.DajZ(),k2.DajZ())) 
        return true; 
    return false;
}
bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2) //udaljenost centara = zbir poluprecnika
{
    if(TestiranjeNaJednakost(RastojanjeCentara(k1,k2), (k1.DajPoluprecnik()+k2.DajPoluprecnik())))
        return true;
    return false;
}
// udaljenost dvije tacke - d = korijen((x2-x1)^2 + (y2-y1)^2 + (z2-z1)^2)
bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2) { // udaljenost centara = | r1 - r2 |
    if(TestiranjeNaJednakost(RastojanjeCentara(k1,k2), fabs(k1.DajPoluprecnik() - k2.DajPoluprecnik())))
        return true;
    return false;
}
bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2) { // d < r1 + r2 
    if(RastojanjeCentara(k1,k2) < (k1.DajPoluprecnik() + k2.DajPoluprecnik()))
        return true;
    return false;
}
bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2) { //d < r1 + r2 && d > |r1 - r2|
    if(RastojanjeCentara(k1,k2) < (k1.DajPoluprecnik() + k2.DajPoluprecnik()) && RastojanjeCentara(k1,k2) > fabs(k1.DajPoluprecnik() - k2.DajPoluprecnik()))
        return true;
    return false;
}
double RastojanjeCentara(const Kugla &k1, const Kugla &k2) {
    return sqrt(pow(k2.DajX()-k1.DajX(), 2) + pow(k2.DajY()-k1.DajY(), 2) + pow(k2.DajZ()-k1.DajZ(), 2));
}

int main ()
{
    int n;
    for(;;) {
    std::cout << "Unesite broj kugla: ";
    std::cin >> n;
    if(n>0 && std::cin) break;
    std::cout << "Neispravan broj kugli, unesite ponovo!" << std::endl;
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    }
    std::vector<std::shared_ptr<Kugla>> v(n);/*
    for(int i(0); i<n; i++) {
    for(;;) {
    std::cout << "Unesite centar " << i+1 << ". kugle: ";
    if()
    }
    
    
    std::cout << "Unesite poluprecnik 1. kugle: " << std::endl;*/
    return 0;
}
