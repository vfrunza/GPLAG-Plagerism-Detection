/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <tuple>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>

const double pi = 4*std::atan(1);
const double eps = std::pow(10, -10);

bool Isti(double x, double y)
{
    return (std::fabs(x - y) <= eps * (std::fabs(x) + std::fabs(y)));
}

double Rastojanje(double x1, double y1, double z1, double x2, double y2, double z2)
{
    return std::sqrt(std::pow(x1-x2, 2) + std::pow(y1-y2, 2) + std::pow(z1-z2, 2));
}

class Kugla
{
    double x, y, z, r;
public:
    explicit Kugla(double r = 0) {
        if (r<0)
            throw std::domain_error("Ilegalan poluprecnik");
        x=0;
        y=0;
        z=0;
        Kugla::r=r;
    }
    Kugla(double x, double y, double z, double r = 0) {
        if (r<0)
            throw std::domain_error("Ilegalan poluprecnik");
        Kugla::x=x;
        Kugla::y=y;
        Kugla::z=z;
        Kugla::r=r;
    }
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0) {
        if (r<0)
            throw std::domain_error("Ilegalan poluprecnik");
        Kugla::x=std::get<0>(centar);
        Kugla::y=std::get<1>(centar);
        Kugla::z=std::get<2>(centar);
        Kugla::r=r;
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
        return 4*r*r*pi;
    }
    double DajZapreminu() const {
        return 4*r*r*r*pi/3;
    }
    Kugla &PostaviX(double x) {
        Kugla::x=x;
        return *this;
    }
    Kugla &PostaviY(double y) {
        Kugla::y=y;
        return *this;
    }
    Kugla &PostaviZ(double z) {
        Kugla::z=z;
        return *this;
    }
    Kugla &PostaviCentar(double x, double y, double z) {
        Kugla::x=x;
        Kugla::y=y;
        Kugla::z=z;
        return *this;
    }
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar) {
        Kugla::x=std::get<0>(centar);
        Kugla::y=std::get<1>(centar);
        Kugla::z=std::get<2>(centar);
        return *this;
    }
    Kugla &PostaviPoluprecnik(double r) {
        if (r<0)
            throw std::domain_error("Ilegalan poluprecnik");
        Kugla::r=r;
        return *this;
    }
    void Ispisi() const {
        std::cout << "{(" << x << "," << y << "," << z << ")," << r << "}" << std::endl;
    }
    void Transliraj(double delta_x, double delta_y, double delta_z) {
        x+=delta_x;
        y+=delta_y;
        z+=delta_z;
    }
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
    bool DaLiSadrzi(const Kugla &k) const {
        return (k.r<this->r && RastojanjeCentara(*this, k) <= std::fabs(r - k.r));
    }
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);

};

bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2)
{
    return (Isti(k1.x, k2.x) && Isti(k1.y, k2.y) && Isti(k1.z, k2.z) && Isti(k1.r, k2.r));
}

bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2)
{
    return Isti(k1.r, k2.r);
}

bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2)
{
    return (Isti(k1.x, k2.x) && Isti(k1.y, k2.y) && Isti(k1.z, k2.z));
}

bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2)
{
    return Isti(k1.r + k2.r, RastojanjeCentara(k1,k2));
}

bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2)
{
    return (Isti(std::fabs(k1.r-k2.r), RastojanjeCentara(k1, k2)) && (!Isti(k1.r, k2.r) || Isti(k1.r,0) || Isti(k2.r,0)));
}

bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2)
{
    return (RastojanjeCentara(k1, k2) < (k1.r+k2.r));
}

bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2)
{
    return (((k1.r + k2.r) > RastojanjeCentara(k1, k2)) && (std::fabs(k1.r - k2.r) <= RastojanjeCentara(k1, k2)) && !DaLiSeDodirujuIznutra(k1, k2) && !DaLiSeDodirujuIzvana(k1, k2));
}

double RastojanjeCentara(const Kugla &k1, const Kugla &k2)
{
    return Rastojanje(k1.x, k1.y, k1.z, k2.x, k2.y, k2.z);
}

int main ()
{
    int n;
    std::cout << "Unesite broj kugla: ";
    do {
        std::cin >> n;
        if (!std::cin || n<=0) {
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            std::cout << "Neispravan broj kugli, unesite ponovo!" << std::endl;
        } else
            break;
    } while (true);
    std::vector<std::shared_ptr<Kugla>> niz(n, nullptr);
    for (int i = 0; i < n; i++) {
        double x, y, z, r;
        do {
            bool valja1(false), valja2(false);
            if (!valja1) {
                std::cout << "Unesite centar " << i+1 << ". kugle: ";
                std::cin >> x >> y >> z;
                if (!std::cin) {
                    std::cin.clear();
                    std::cin.ignore(10000,'\n');
                    std::cout << "Neispravan centar" << std::endl;
                    continue;
                } else
                    valja1=true;
            }
            if (!valja2) {
                std::cout << "Unesite poluprecnik " << i+1 << ". kugle: ";
                std::cin >> r;
                if (!std::cin || r<0) {
                    std::cin.clear();
                    std::cin.ignore(10000,'\n');
                    std::cout << "Ilegalan poluprecnik" << std::endl;
                } else
                    valja2=true;
            }
            if (valja1 && valja2)
                break;
        } while(true);
        std::shared_ptr<Kugla> pomoc(nullptr);
        try {
            pomoc = std::make_shared<Kugla>(x, y, z, r);
        } catch (const std::exception &greska) {
            std::cout << greska.what() << std::endl;
            i--;
            continue;
        }
        niz.at(i)=pomoc;
    }
    {
        std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
        double x, y, z;
        do {
            std::cin >> x >> y >> z;
            if (!std::cin) {
                std::cin.clear();
                std::cin.ignore(10000,'\n');
                std::cout << "Neispravni parametri translacije, unesite ponovo!" << std::endl;
            } else
                break;
        } while (true);
        std::transform(niz.begin(), niz.end(), niz.begin(), [&x, &y, &z] (std::shared_ptr<Kugla> element) {
            element->Transliraj(x, y, z);
            return element;
        });
    }
    std::sort(niz.begin(), niz.end(), [] (std::shared_ptr<Kugla> p1, std::shared_ptr<Kugla> p2) {
        return (p1->DajZapreminu() < p2->DajZapreminu());
    });
    std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: " << std::endl;
    std::for_each(niz.begin(), niz.end(), [] (std::shared_ptr<Kugla> element) {
        element->Ispisi();
    });
    std::cout << "Kugla sa najvecom povrsinom je: ";
    (*std::max_element(niz.begin(), niz.end(), [] (std::shared_ptr<Kugla> p1, std::shared_ptr<Kugla> p2) {
        return (p1->DajPovrsinu() < p2->DajPovrsinu());
    }))->Ispisi();
    int i(0);
    bool postoji(false);
    std::for_each(niz.begin(), niz.end(), [niz, &i, &postoji] (std::shared_ptr<Kugla> element) {
        i++;
        std::for_each(niz.begin()+i, niz.end(), [&element, &postoji] (std::shared_ptr<Kugla> element2) {
            if (DaLiSeSijeku(*element, *element2)) {
                std::cout << "Presjecaju se kugle: ";
                element->Ispisi();
                element2->Ispisi();
                if (!postoji)
                    postoji=true;
            }
        });
    });
    if (!postoji)
        std::cout << "\nNe postoje kugle koje se presjecaju!";
    return 0;
}
