/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <cmath>
#include <memory>
#include <vector>
#include <algorithm>

const double PI
{
    4 * atan(1.)
};
const double epsilon
{
    1e-10
};

double RastojanjeTacaka(double x1, double y1, double z1, double x2, double y2, double z2)
{
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2));
}

class Kugla
{
    double x, y, z, r;
public:
    explicit Kugla(double r = 0) {
        if(r < 0) throw std::domain_error("Neispravan poluprecnik");
        x = 0;
        y = 0;
        z = 0;
        Kugla::r = r;
    }
    Kugla(double x, double y, double z, double r = 0) {
        Kugla::x = x;
        Kugla::y = y;
        Kugla::z = z;
        Kugla::r = r;
    }
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0) {
        std::tie(x, y, z) = centar;
        Kugla::r = r;
    }
    double DajX() const {
        return x;
    }
    double DajY() const {
        return y;
    }
    double DajZ() const {
        return z;
    }
    std::tuple<double, double, double> DajCentar() const {
        return std::make_tuple(x, y, z);
    }
    double DajPoluprecnik() const {
        return r;
    }
    double DajPovrsinu() const {
        return 4 * r * r * PI;
    }
    double DajZapreminu() const {
        return 4*pow(r, 3)*PI/3;
    }
    Kugla &PostaviX(double x) {
        Kugla::x = x;
        return *this;

    }
    Kugla &PostaviY(double y) {
        Kugla::y = y;
        return *this;
    }
    Kugla &PostaviZ(double z) {
        Kugla::z = z;
        return *this;
    }
    Kugla &PostaviCentar(double x, double y, double z) {
        Kugla::x = x;
        Kugla::y = y;
        Kugla::z = z;
        return *this;
    }
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar) {
        Kugla::x = std::get<0>(centar);
        Kugla::y = std::get<1>(centar);
        Kugla::z = std::get<2>(centar);
        return *this;
    }
    Kugla &PostaviPoluprecnik(double r) {
        if(r < 0) throw std::domain_error("Neispravan poluprecnik");
        Kugla::r = r;
        return *this;
    }
    void Ispisi() const {
        std::cout << "{(" << DajX() << "," << DajY() << "," << DajZ() << ")," << DajPoluprecnik() << "}" << std::endl;
    }
    void Transliraj(double delta_x, double delta_y, double delta_z) {
        x += delta_x;
        y += delta_y;
        z += delta_z;
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

bool TestiranjeJednakosti (double x, double y)
{
    return fabs(x - y) <= epsilon * (fabs(x) + fabs(y));
}

bool IstiCentar(const Kugla &k1, const Kugla &k2)
{
    return (TestiranjeJednakosti(k1.DajX(), k2.DajX()) && TestiranjeJednakosti(k1.DajY(), k2.DajY()) && TestiranjeJednakosti(k1.DajZ(), k2.DajZ()));
}

bool IstiPoluprecnik(const Kugla &k1, const Kugla &k2)
{
    return TestiranjeJednakosti(k1.DajPoluprecnik(), k2.DajPoluprecnik());
}

bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2)
{
    return (IstiCentar(k1, k2) && IstiPoluprecnik(k1, k2));
}

bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2)
{
    return IstiPoluprecnik(k1, k2);
}

bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2)
{
    return IstiCentar(k1, k2);
}
double RastojanjeCentara(const Kugla &k1, const Kugla &k2)
{
    return sqrt((k1.DajX()-k2.DajX())*(k1.DajX()-k2.DajX()) + (k1.DajY()-k2.DajY())*(k1.DajY()-k2.DajY()) + (k1.DajZ()-k2.DajZ())*(k1.DajZ()-k2.DajZ()));
}
bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2)
{
    double rastojanje_centara(RastojanjeCentara(k1, k2));
    return TestiranjeJednakosti(rastojanje_centara, k1.DajPoluprecnik() + k2.DajPoluprecnik());
}

bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2)
{
    double rastojanje_centara(RastojanjeCentara(k1, k2));
    return TestiranjeJednakosti(rastojanje_centara, fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik()));
}

bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2)
{
    double rastojanje_centara(RastojanjeCentara(k1, k2));
    return rastojanje_centara < k1.DajPoluprecnik() + k2.DajPoluprecnik() && rastojanje_centara > fabs(k1.DajPoluprecnik() - k2.DajPoluprecnik());
}

bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2)
{
    return DaLiSeSijeku(k1, k2);
}

bool Kugla::DaLiSadrzi(const Kugla &k) const
{
    return !DaLiSeSijeku(*this, k) && r < k.r;
}

int main ()
{
    int br_kugla;
    std::cout << "Unesite broj kugla: ";
    for(;;) {
        std::cin >> br_kugla;
        if(std::cin && br_kugla > 0) break;
        else if(!std::cin || br_kugla <= 0) {
            std::cout << "Neispravan broj kugli, unesite ponovo!" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
    }
    std::vector<std::shared_ptr<Kugla>> v(br_kugla);
    int i = 0;
    double poluprecnik, x, y, z, delta_x, delta_y, delta_z;
    while (i < br_kugla) {
        for(;;) {
            for(;;) {
                std::cout << "Unesite centar " << i+1 << ". kugle: ";
                std::cin >> x >> y >> z;
                if(std::cin) break;
                else if(!std::cin) {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                }
            }
            std::cout << "Unesite poluprecnik " << i+1 << ". kugle: ";
            std::cin >> poluprecnik;
            if(std::cin && poluprecnik >=0) {
                v.at(i) = std::make_shared<Kugla>(Kugla(x, y, z, poluprecnik));
                i++;
                break;
            } else if(!std::cin || poluprecnik < 0) {
                std::cout << "Ilegalan poluprecnik" << std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
            }
        }
    }
    for(;;) {
        std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
        std::cin >> delta_x >> delta_y >> delta_z;
        if(std::cin) break;
        else if(!std::cin) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
    }
    std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: " << std::endl;

    std::transform(v.begin(), v.end(), v.begin(), [delta_x, delta_y, delta_z] (std::shared_ptr<Kugla> k) {
        k->Transliraj(delta_x, delta_y, delta_z);
        return k;
    });

    std::sort(v.begin(), v.end(), [] (std::shared_ptr<Kugla> p1, std::shared_ptr<Kugla> p2) {
        return p1->DajZapreminu() < p2->DajZapreminu();
    });
    std::for_each(v.begin(), v.end(), [] (std::shared_ptr<Kugla> p) {
        p->Ispisi();
    });
    auto it(std::max_element(v.begin(), v.end(), [] (std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2) {
        return  k1->DajPovrsinu() < k2->DajPovrsinu();
    }));
    std::cout << "Kugla sa najvecom povrsinom je: ";
    (**it).Ispisi();

    int brojac(0), brojac2(0);
    auto it1 = v.begin();
    int vel(v.size());
    std::for_each(it1, it1 + vel, [v, &brojac2, &brojac, vel, it1] (std::shared_ptr<Kugla> k1) {
        std::for_each(it1+brojac2+1, it1 + vel, [it1, &brojac, v, k1] (std::shared_ptr<Kugla> k2) {
            if(DaLiSeSijeku(*k1, *k2) && !k1->DaLiSadrzi(*k2)) {
                brojac++;
                if(!DaLiSuIdenticne(*k1, *k2)){
                std::cout << "Presjecaju se kugle: ";
                k1->Ispisi();
                k2->Ispisi();
                }
            }
        });
        brojac2++;
    });
    if(brojac == 0) std::cout << "Ne postoje kugle koje se presjecaju!";
    return 0;
}