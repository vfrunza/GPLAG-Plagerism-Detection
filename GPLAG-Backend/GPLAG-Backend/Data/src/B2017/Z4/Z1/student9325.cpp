/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <tuple>
#include <algorithm>
#include <stdexcept>
#include <cmath>
#include <memory>
#include <vector>
#include <iterator>

const double PI(4*std::atan(1));
const double EPSILON(1e-10);

class Kugla {
    double x, y, z;
    double r;
    static bool JednakiRealni(double prvi, double drugi) {
        return std::fabs(prvi-drugi)<EPSILON*(std::fabs(prvi)+std::fabs(drugi));
    }
    static bool VeciRealni(double prvi, double drugi) {
        return std::fabs(prvi-drugi)>=EPSILON*(std::fabs(prvi)+std::fabs(drugi)) && prvi>drugi;
    }
    static bool ManjiRealni(double prvi, double drugi) {
        return std::fabs(prvi-drugi)>=EPSILON*(std::fabs(prvi)+std::fabs(drugi)) && prvi<drugi;
    }
public:
    explicit Kugla(double r=0) {
        if (Kugla::ManjiRealni(r, 0)) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::r=r;
        x=0; y=0; z=0;
    }
    Kugla(double x, double y, double z, double r=0) {
        if (Kugla::ManjiRealni(r, 0)) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::r=r;
        Kugla::x=x; Kugla::y=y; Kugla::z=z;
    }
    explicit Kugla(const std::tuple<double, double, double> &centar, double r=0) {
        if (Kugla::ManjiRealni(r, 0)) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::r=r;
        std::tie(x, y, z)=centar;
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
        return 4*DajPoluprecnik()*DajPoluprecnik()*PI;
    }
    double DajZapreminu() const {
        return (4./3)*DajPoluprecnik()*DajPoluprecnik()*DajPoluprecnik()*PI;
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
        Kugla::x=x; Kugla::y=y; Kugla::z=z;
        return *this;
    }
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar) {
        std::tie(x, y, z)=centar;
        return *this;
    }
    Kugla &PostaviPoluprecnik(double r) {
        if (Kugla::ManjiRealni(r, 0)) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::r=r;
        return *this;
    }
    void Ispisi() const {
        std::cout << "{(" << DajX() << "," << DajY() << "," << DajZ() << ")," << DajPoluprecnik() << "}" << std::endl; 
    }
    void Transliraj(double delta_x, double delta_y, double delta_z) {
        x+=delta_x; y+=delta_y; z+=delta_z;
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

bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2) {
    return Kugla::JednakiRealni(k1.x, k2.x) && Kugla::JednakiRealni(k1.y, k2.y) 
    && Kugla::JednakiRealni(k1.z, k2.z) && Kugla::JednakiRealni(k1.r, k2.r);
}

bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2) {
    return Kugla::JednakiRealni(k1.r, k2.r);
}

bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2) {
    return Kugla::JednakiRealni(k1.x, k2.x) && Kugla::JednakiRealni(k1.y, k2.y) 
    && Kugla::JednakiRealni(k1.z, k2.z);
}

bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2) {
    return Kugla::JednakiRealni(RastojanjeCentara(k1, k2), k1.r+k2.r);
}

bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2) {
    return Kugla::JednakiRealni(RastojanjeCentara(k1, k2), std::fabs(k1.r-k2.r));
}

bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2) {
    return Kugla::ManjiRealni(RastojanjeCentara(k1, k2), k1.r+k2.r);
}

bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2) {
    return Kugla::ManjiRealni(RastojanjeCentara(k1, k2), k1.r+k2.r) && Kugla::VeciRealni(RastojanjeCentara(k1, k2), std::fabs(k1.r-k2.r));
}

double RastojanjeCentara(const Kugla &k1, const Kugla &k2) {
    return std::sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z));
}

bool Kugla::DaLiSadrzi(const Kugla &k) const {
    return (Kugla::ManjiRealni(k.r, r) || Kugla::JednakiRealni(k.r, r)) && 
    (Kugla::JednakiRealni(RastojanjeCentara(*this, k), std::fabs(r-k.r)) 
    || Kugla::ManjiRealni(RastojanjeCentara(*this, k), std::fabs(r-k.r)));
}

int main ()
{
    std::cout << "Unesite broj kugla: ";
    int n(0);
    while (1) {
        std::cin >> n;
        if (std::cin && n>0) break;
        std::cout << "Neispravan broj kugli, unesite ponovo!" << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
    std::vector<std::shared_ptr<Kugla>> vektor_pokazivaca;
    for (int i=1; i<=n; i++) {
        std::cout << "Unesite centar " << i << ". kugle: ";
        double x(0.), y(0.), z(0.);
        std::cin >> x;
        std::cin >> y;
        std::cin >> z;
        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Neispravan centar" << std::endl;
            i--;
            continue;
        }
        std::cout << "Unesite poluprecnik " << i << ". kugle: ";
        double r(0.);
        std::cin >> r;
        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Ilegalan poluprecnik" << std::endl;
            i--;
            continue;
        }
        try {
            vektor_pokazivaca.push_back(std::make_shared<Kugla>(x, y, z, r));
        }
        catch(std::domain_error greska) {
            std::cout << greska.what() << std::endl;
            i--;
        }
    }
    std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double delta_x(0.), delta_y(0.), delta_z(0.);
    while (1) {
        std::cin >> delta_x >> delta_y >> delta_z;
        if (std::cin) break;
        std::cout << "Neispravni parametri translacije, unesite ponovo!" << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
    std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: ";
    std::cout << std::endl;
    std::transform(vektor_pokazivaca.begin(), vektor_pokazivaca.end(), vektor_pokazivaca.begin(), 
    [delta_x, delta_y, delta_z](std::shared_ptr<Kugla> pok_na_kuglu) {
        pok_na_kuglu->Transliraj(delta_x, delta_y, delta_z);
        return pok_na_kuglu;
    });
    std::sort(vektor_pokazivaca.begin(), vektor_pokazivaca.end(), 
    [](std::shared_ptr<Kugla> prvi, std::shared_ptr<Kugla> drugi) {
        return (prvi->DajZapreminu())<(drugi->DajZapreminu());
    });
    std::for_each(vektor_pokazivaca.begin(), vektor_pokazivaca.end(), 
    [](std::shared_ptr<Kugla> pokazivac) {
        pokazivac->Ispisi();
    });
    std::cout << "Kugla sa najvecom povrsinom je: ";
    (*std::max_element(vektor_pokazivaca.begin(), vektor_pokazivaca.end(), 
    [](std::shared_ptr<Kugla> prvi, std::shared_ptr<Kugla> drugi) {
        return (prvi->DajPovrsinu())<(drugi->DajPovrsinu());
    }))->Ispisi();
    int broj_presjecanja(0);
    int broj(0);
    std::for_each(vektor_pokazivaca.begin(), vektor_pokazivaca.end(), 
    [vektor_pokazivaca, &broj, &broj_presjecanja](std::shared_ptr<Kugla> prvi) {
        std::for_each(vektor_pokazivaca.begin()+broj, vektor_pokazivaca.end(), 
        [prvi, &broj_presjecanja](std::shared_ptr<Kugla> drugi) {
            if (DaLiSeSijeku(*prvi, *drugi)) {
                broj_presjecanja++;
                std::cout << "Presjecaju se kugle: ";
                prvi->Ispisi();
                drugi->Ispisi();
            }
        });
        broj++;
    });
    if (broj_presjecanja==0) std::cout << "Ne postoje kugle koje se presjecaju!";
	return 0;
}
