#include <vector>
#include <iostream>
#include <cmath>
#include <list>
#include <tuple>
#include <stdexcept>
#include <memory>
#include <algorithm>

const double pi=4.*atan(1.);

class NepreklapajucaKugla {
    double x, y, z, r;
    public:
    explicit NepreklapajucaKugla(double r=0) {
        if (r<0) throw std::domain_error("Ilegalan poluprecnik");
        NepreklapajucaKugla::r=r;
    }
    NepreklapajucaKugla (double x, double y, double z, double r=0) {
        if (r<0) throw std::domain_error("Ilegalan poluprecnik");
        NepreklapajucaKugla::x=x;
        NepreklapajucaKugla::y=y;
        NepreklapajucaKugla::z=z;
        NepreklapajucaKugla::r=r;
    }
    explicit NepreklapajucaKugla (const std::tuple<double, double, double> &centar, double r=0) {
        if (r<0) throw std::domain_error("Ilegalan poluprecnik");
        NepreklapajucaKugla::x=std::get<0>(centar);
        NepreklapajucaKugla::y=std::get<1>(centar);
        NepreklapajucaKugla::z=std::get<2>(centar);
        NepreklapajucaKugla::r=r;
    }
    double DajX() const {
        return NepreklapajucaKugla::x;
    }
    double DajY() const {
        return NepreklapajucaKugla::y;
    }
    double DajZ() const {
        return NepreklapajucaKugla::z;
    }
    std::tuple<double, double, double> DajCentar() const {
        return std::make_tuple(NepreklapajucaKugla::x, NepreklapajucaKugla::y, NepreklapajucaKugla::z);
    }
    double DajPoluprecnik() const {
        return NepreklapajucaKugla::r;
    }
    double DajPovrsinu() const {
        return 4.*r*r*pi;
    }
    double DajZapreminu() const {
        return (4./3)*r*r*r*pi;
    }
    NepreklapajucaKugla &PostaviX(double x) {
        NepreklapajucaKugla::x=x;
        return *this;
    }
    NepreklapajucaKugla &PostaviY(double y) {
        NepreklapajucaKugla::y=y;
        return *this;
    }
    NepreklapajucaKugla &PostaviZ(double z) {
        NepreklapajucaKugla::z=z;
        return *this;
    }
    NepreklapajucaKugla &PostaviCentar(double x, double y, double z) {
        NepreklapajucaKugla::x=x;
        NepreklapajucaKugla::y=y;
        NepreklapajucaKugla::z=z;
        return *this;
    }
    NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar) {
        NepreklapajucaKugla::x=std::get<0>(centar);
        NepreklapajucaKugla::y=std::get<1>(centar);
        NepreklapajucaKugla::z=std::get<2>(centar);
        return *this;
    }
    void Ispisi() const {
        std::cout << "{(" << x << "," << y << "," << z << ")" << "," << r << "}";
    }
    void Transliraj(double delta_x, double delta_y, double delta_z) {
        NepreklapajucaKugla::x+=delta_x;
        NepreklapajucaKugla::y+=delta_y;
        NepreklapajucaKugla::z+=delta_z;
    }
    friend double RastojanjeCentara (const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2) {
        return sqrt((k1.DajX()-k2.DajX())*(k1.DajX()-k2.DajX())+(k1.DajY()-k2.DajY())*(k1.DajY()-k2.DajY())+(k1.DajZ()-k2.DajZ()*k1.DajZ()-k2.DajZ()));
    }
};

int main () {
    int n;
    double x, y, z, r;
    std::cout << "Unesite broj kugli: ";
    for (;;) {
        std::cin >> n;
        if (std::cin and n>0) break;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Neispravan broj kugli, unesite ponovo!" << std::endl;
    }
    int i=0;
    std::vector<std::shared_ptr<NepreklapajucaKugla>> v(n);
    for (;;) {
        for (;;) {
            std::cout << "Unesite centar za " << i+1 << ". kuglu: ";
            std::cin >> x >> y >> z;
            if (std::cin) break;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Neispravan centar" << std::endl;
        }
        std::cout << "Unesite poluprecnik: ";
        std::cin >> r;
        try {
            if (!std::cin) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                throw std::domain_error("Ilegalan poluprecnik");
            }
            NepreklapajucaKugla k(x, y, z, r);
            v[i]=std::make_shared<NepreklapajucaKugla>(k);
            i++;
            if (i==n) break;
        }
        catch (std::domain_error izuzetak) {
            std::cout << izuzetak.what() << std::endl;
        }
    }
    std::cout << "Kugle nakon obavljenog sortiranja: " << std::endl;
    std::sort(v.begin(), v.end(), [] (std::shared_ptr<NepreklapajucaKugla> p1, std::shared_ptr<NepreklapajucaKugla> p2) { return (p1->DajZapreminu()<p2->DajZapreminu());});
    for (int i=0; i<n; i++) {
        v[i]->Ispisi();
        std::cout << std::endl;
    }
    return 0;
}
