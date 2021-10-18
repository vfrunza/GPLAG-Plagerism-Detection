/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <cmath>
#include <algorithm>
#include <vector>
#include <memory>

const double PI = 4. * atan(1);

class Kugla
{
    double x,y,z;
    double poluprecnik;
public:

    explicit Kugla(double r = 0) {
        if(r < 0) throw std::domain_error("Ilegalan poluprecnik");
        poluprecnik = r;
        x = y = z = 0;
    }
    Kugla(double x, double y, double z, double r = 0) {
        if(r < 0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::x = x;
        Kugla::y = y;
        Kugla::z = z;
        poluprecnik = r;
    }
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0) {
        if(r < 0) throw std::domain_error("Ilegalan poluprecnik");
        x = std::get<0>(centar);
        y = std::get<1>(centar);
        z = std::get<2>(centar);
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
        auto centar = std::make_tuple(x, y, z);
        return centar;
    }
    double DajPoluprecnik() const {
        return poluprecnik;
    }
    double DajPovrsinu() const {
        return 4. * poluprecnik * poluprecnik * PI;
    }
    double DajZapreminu() const {
        return 4/3. * poluprecnik * poluprecnik * poluprecnik * PI;
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
        x = std::get<0>(centar);
        y = std::get<1>(centar);
        z = std::get<2>(centar);
        return *this;
    }
    Kugla &PostaviPoluprecnik(double r) {
        poluprecnik = r;
        return *this;
    }
    void Ispisi() const {
        std::cout<<"{("<<x<<","<<y<<","<<z<<"),"<<poluprecnik<<"}"<<std::endl;
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
    bool DaLiSadrzi(const Kugla &k) const {
        if(k.poluprecnik > poluprecnik) return false;
        double d, dr;
        d = std::sqrt(pow((x - k.x),2) + pow((y - k.y),2) + pow((z - k.z),2));
        dr = poluprecnik - k.poluprecnik;
        if(std::abs(d - 0) <= 1e-10 * (std::fabs(d) + std::fabs(0))) return true;
        else if(std::fabs(d - dr) < 1e-10 * (std::fabs(d) + std::fabs(dr))) return true;
        else if(d < dr) return true;
        return false;
    }
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);
};
bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2)
{
    double udaljenost(RastojanjeCentara(k1, k2));
    if(std::fabs(udaljenost - 0) <= 1e-10 * (std::fabs(udaljenost) + std::fabs(0)) && (std::fabs(k1.poluprecnik - k2.poluprecnik) < 1e-10*(std::fabs(k1.poluprecnik) + std::fabs(k2.poluprecnik)))) return true;
    return false;

    if(k1.x == k2.x && k1.y == k2.y && k1.z == k2.z && k1.poluprecnik == k2.poluprecnik) return true;
    return false;
}
bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2)
{
    if(std::fabs(k1.poluprecnik - k2.poluprecnik) < 1e-10 * (std::fabs(k1.poluprecnik) + std::fabs(k2.poluprecnik))) return true;
    return false;
}
bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2)
{
    double udaljenost = RastojanjeCentara(k1, k2);
    if(std::fabs(udaljenost - 0) <= 1e-10 * (std::fabs(udaljenost) + fabs(0))) return true;
    return false;
}
bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2)
{
    double udaljenost = RastojanjeCentara(k1, k2);
    double dr(k1.poluprecnik + k2.poluprecnik);
    if(std::fabs(dr - udaljenost) <= 1e-10 * (std::fabs(dr) + std::fabs(udaljenost))) return true;
    return false;
}
bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2)
{
    double udaljenost = RastojanjeCentara(k1, k2);
    double dr(k1.poluprecnik - k2.poluprecnik);
    if(k1.poluprecnik > k2.poluprecnik) {
        if(std::fabs(dr - udaljenost) <= 1e-10 * (std::fabs(dr) + std::fabs(udaljenost))) return true;
        else return false;
    } else {
        dr = k2.poluprecnik - k1.poluprecnik;
        if(std::fabs(dr - udaljenost) <= 1e-10 * (std::fabs(dr) + std::fabs(udaljenost))) return true;
        return false;
    }
}
bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2)
{
    if(DaLiSeDodirujuIznutra(k1, k2)) return true;
    if(DaLiSeDodirujuIzvana(k1, k2)) return true;
    if(DaLiSuIdenticne(k1, k2)) return true;
    if(DaLiSuKoncentricne(k1, k2)) return true;
    if(DaLiSeSijeku(k1, k2)) return true;
    if(k1.DaLiSadrzi(k2)) return true;
    if(k2.DaLiSadrzi(k1)) return true;
    return false;
}
bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2)
{
    if(DaLiSeDodirujuIznutra(k1, k2)) return false;
    if(DaLiSeDodirujuIzvana(k1, k2)) return true;
    if(k1.DaLiSadrzi(k2)) return false;
    else {
        double udaljenost = RastojanjeCentara(k1, k2);
        double dr = k1.poluprecnik + k2.poluprecnik;
        if(udaljenost < dr) return true;
        else return false;
    }

    return false;
}
double RastojanjeCentara(const Kugla &k1, const Kugla &k2)
{
    return std::sqrt(pow((k1.x - k2.x),2) + pow((k1.y - k2.y),2) + pow((k1.z - k2.z),2));
}

int main ()
{
    std::cout<<"Unesite broj kugla: ";
    int broj_kugla;
    std::cin>>broj_kugla;
    while(!(std::cin) || broj_kugla <= 0) {
        std::cout<<"Neispravan broj kugli, unesite ponovo!\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cin>>broj_kugla;
    }
    std::vector<std::shared_ptr<Kugla>> kugle;
    int brojac(1);
    while(kugle.size() != broj_kugla) {
        std::cout<<"Unesite centar "<<brojac<<". kugle: ";
        double x,y,z;
        std::cin>>x;
        if(!std::cin) {
            std::cout<<"Neispravan centar\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }
        std::cin>>y;
        if(!std::cin) {
            std::cout<<"Neispravan centar\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }
        std::cin>>z;
        if(!std::cin) {
            std::cout<<"Neispravan centar\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }
        std::cout<<"Unesite poluprecnik "<<brojac<<". kugle: ";
        double r;
        std::cin>>r;
        if(!std::cin) {
            std::cout<<"Ilegalan poluprecnik\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }
        if(r < 0) {
            std::cout<<"Ilegalan poluprecnik\n"<<std::endl;
            continue;
        }
        auto p = std::make_shared<Kugla>(x, y, z, r);
        kugle.emplace_back(p);
        ++brojac;
    }

    std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double dx, dy, dz;
    for(;;) {
        std::cin>>dx;
        if(!std::cin) {
            std::cout<<"Neispravni parametri translacije, unesite ponovo!\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }
        std::cin>>dy;
        if(!std::cin) {
            std::cout<<"Neispravni parametri translacije, unesite ponovo!\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }
        std::cin>>dz;
        if(!std::cin) {
            std::cout<<"Neispravni parametri translacije, unesite ponovo!\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }
        break;
    }
    std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: \n";
    std::transform(std::begin(kugle), std::end(kugle), std::begin(kugle), [=](std::shared_ptr<Kugla> k1) {
        k1->Transliraj(dx, dy, dz);
        return k1;
    });
    std::sort(std::begin(kugle), std::end(kugle), [=](const std::shared_ptr<Kugla> k1, const std::shared_ptr<Kugla> k2) -> bool {
        return k1->DajZapreminu() < k2->DajZapreminu();
    });
    std::for_each(std::begin(kugle), std::end(kugle), [=](const std::shared_ptr<Kugla> k) {
        k->Ispisi();
    });

    /**Nadji najvecu povrsinu **/
    auto NP(*max_element(std::begin(kugle), std::end(kugle), [=](const std::shared_ptr<Kugla> k1, const std::shared_ptr<Kugla> k2) {
        return k1->DajPovrsinu() < k2->DajPovrsinu();
    }));
    std::cout<<"Kugla sa najvecom povrsinom je: ";
    NP->Ispisi();
    std::cout<<"\n";

    auto it(std::begin(kugle));
    ++it;
    auto end_it(std::end(kugle));
    --end_it;
    int brojac_sjece(0);
    std::for_each(std::begin(kugle), end_it, [&](std::shared_ptr<Kugla> k1) {
        std::for_each(it, std::end(kugle), [&](std::shared_ptr<Kugla> k2) {
            if(DaLiSeSijeku(*k1, *k2)) {
                ++brojac_sjece;
                std::cout<<"Presjecaju se kugle: ";
                k1->Ispisi();
                std::cout<<"\n";
                k2->Ispisi();
                std::cout<<"\n";
            }
        });
        ++it;
    });
    if(brojac_sjece == 0) std::cout<<"Ne postoje kugle koje se presjecaju!";

    return 0;
}