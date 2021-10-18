/B2017/2018: Zadaća 4, Zadatak 1
//udaljenost_koordinata predstavlja udaljenost izmedu 2 centra kruznica
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <utility>
#include <stdexcept>
#include <map>
#include <algorithm>
#include <memory>

#define epsilon 0.0000000001
const double PI = 4. * atan(1.);

class Kugla
{
    double x, y, z;
    double r;

public:
    explicit Kugla(double poluprecnik = 0) {
        if(poluprecnik < 0 || !std::cin) throw std::domain_error ("Ilegalan poluprecnik");
        r = poluprecnik;
        x = 0;
        y = 0;
        z = 0;
    }
    Kugla (double x, double y, double z, double poluprecnik = 0) {
        if (poluprecnik < 0 || !std::cin) throw std::domain_error ("Ilegalan poluprecnik");
        r = poluprecnik;
        Kugla::x = x;
        Kugla::y = y;
        Kugla::z = z;
    }
    explicit Kugla(const std::tuple<double, double, double> &centar, double poluprecnik = 0) {
        if (poluprecnik < 0 || !std::cin) throw std::domain_error ("Ilegalan poluprecnik");
        r = poluprecnik;
        x = std::get<0> (centar);
        y = std::get<1> (centar);
        z = std::get<2> (centar);
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
        return r;
    }
    double DajPovrsinu () const {
        return 4.*r*r*PI;
    }
    double DajZapreminu() const {
        return 4./3. * r*r*r*PI;
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
        x = std::get<0> (centar);
        y = std::get<1> (centar);
        z = std::get<2> (centar);
        return *this;

    }
    Kugla &PostaviPoluprecnik(double poluprecnik) {
        if (poluprecnik < 0) throw;
        r = poluprecnik;
        return *this;
    }
    void Ispisi() const {
        std::cout << "{(" << this->DajX() << "," << this->DajY() << "," << this->DajZ() <<")," << this->DajPoluprecnik() << "}"<<std::endl;
    }
    void Transliraj(double delta_x, double delta_y, double delta_z) {
        Kugla::x += delta_x;
        Kugla::y += delta_y;
        Kugla::z += delta_z;
    }
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
    bool DaLiSadrzi(const Kugla &k) const {
        double udaljenost_koordinata;
        udaljenost_koordinata = std::sqrt ((k.x-x)*(k.x-x)+(k.y-y)*(k.y-y)+(k.z-z)*(k.z-z));
        if (std::fabs(r-0) <= epsilon*(std::fabs(r)+std::fabs(0)) && x < k.r && y < k.r && z < k.r) return true;
        if (std::fabs(k.r-0) <= epsilon*(std::fabs(k.r)+std::fabs(0)) && k.x < r && k.y < r && k.z < r) return true;
        if (k.r > Kugla::r) {
            auto udaljenost = r+udaljenost_koordinata;
            if (udaljenost < k.r) return true;
        } else {
            auto udaljenost = k.r+udaljenost_koordinata;
            if (udaljenost < r) return true;
        }
        return false;
    }
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);
};

double RastojanjeCentara (const Kugla &k1, const Kugla &k2)
{
    double udaljenost_koordinata;
    udaljenost_koordinata = std::sqrt (((k1.x-k2.x)*(k1.x-k2.x))+((k1.y-k2.y)*(k1.y-k2.y))+((k1.z-k2.z)*(k1.z-k2.z)));
    return udaljenost_koordinata;
}

bool DaLiSuIdenticne (const Kugla &k1, const Kugla &k2)
{
    double udaljenost_koordinata;
    udaljenost_koordinata = std::sqrt(((k1.x-k2.x)*(k1.x-k2.x))+((k1.y-k2.y)*(k1.y-k2.y))+((k1.z-k2.z)*(k1.z-k2.z)));
    if ((std::fabs(udaljenost_koordinata-0) <= epsilon*(std::fabs(udaljenost_koordinata)+std::fabs(0)))&& (std::fabs(k1.r-k2.r) < epsilon*(std::fabs(k1.r) + std::fabs(k2.r)))) return true;
    return false;
}

bool DaLiSuPodudarne (const Kugla &k1, const Kugla &k2)
{
    if (std::fabs(k1.r-k2.r) <= epsilon*(std::fabs(k1.r) + abs(k2.r))) return true;
    return false;
}

bool DaLiSuKoncentricne (const Kugla &k1, const Kugla &k2)
{
    double udaljenost_koordinata;
    udaljenost_koordinata = std::sqrt ((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z));
    if (std::fabs(udaljenost_koordinata-0) <= epsilon*(std::fabs(udaljenost_koordinata)+std::fabs(0))) return true;
    return false;
}

bool DaLiSeDodirujuIzvana (const Kugla &k1, const Kugla &k2)
{
    double udaljenost_koordinata;
    udaljenost_koordinata = std::sqrt ((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z));
    double udaljenost_poluprecnika;
    udaljenost_poluprecnika = k1.r+k2.r;
    if (std::fabs(udaljenost_poluprecnika-udaljenost_koordinata) < epsilon*(std::fabs(udaljenost_poluprecnika)+std::fabs(udaljenost_koordinata))) return true;
    return false;
}

bool DaLiSeDodirujuIznutra (const Kugla &k1, const Kugla &k2)
{
    double udaljenost_koordinata;
    udaljenost_koordinata = RastojanjeCentara(k1, k2);
    double udaljenost_poluprecnika ;
    if (k1.r > k2.r) {
        udaljenost_poluprecnika = k1.r-k2.r;
        if (std::fabs(udaljenost_poluprecnika-udaljenost_koordinata) <= epsilon*(std::fabs(udaljenost_poluprecnika)+std::fabs(udaljenost_koordinata))) return true;
        else return false;
    }

    else {
        udaljenost_poluprecnika = k2.r - k1.r;
        if (std::fabs(udaljenost_poluprecnika-udaljenost_koordinata) <= epsilon*(std::fabs(udaljenost_poluprecnika)+std::fabs(udaljenost_koordinata))) return true;
        return false;
    }



}

bool DaLiSeSijeku (const Kugla &k1, const Kugla &k2)
{
    if (DaLiSeDodirujuIznutra(k1, k2)) return false;
    if (DaLiSeDodirujuIzvana(k1, k2)) return false;
    if (k1.DaLiSadrzi(k2)) return false;
    double udaljenost_koordinata;
    udaljenost_koordinata = RastojanjeCentara(k1, k2);
    double udaljenost_poluprecnika;
    udaljenost_poluprecnika = k1.r+k2.r;
    if (udaljenost_koordinata<udaljenost_poluprecnika) return true;
    return false;
}

bool DaLiSePreklapaju (const Kugla &k1, const Kugla &k2)
{
    if (DaLiSeDodirujuIznutra(k1, k2)==true || DaLiSuIdenticne(k1, k2) == true || DaLiSuKoncentricne(k1, k2) == true || DaLiSeSijeku(k1, k2) == true || k1.DaLiSadrzi(k2) == true) return true;
    return false;
}


int main ()
{
    std::cout << "Unesite broj kugla: ";
    int n;
    std::cin >> n;
    if (n<=0 || !std::cin) {
        while (!std::cin || n<=0) {
            std::cout << "Neispravan broj kugli, unesite ponovo!\n";
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            std::cin>>n;
        }
    }
    std::vector<std::shared_ptr<Kugla>> vektor (n, nullptr);
    int i(0);
    while (i<n) {
        std::cout << "Unesite centar " << i+1 << ". kugle: ";
        int x, y, z;
        std::cin >> x >> y >> z;
        while (!std::cin) {
            std::cout << "Neispravan centar\n";
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            std::cout << "Unesite centar " << i+1 << ". kugle: ";
            std::cin>>x>>y>>z;
        }
        std::cout << "Unesite poluprecnik " << i+1 << ". kugle: ";
        double r;
        std::cin >> r;
        try {
            vektor[i]=std::make_shared<Kugla> (x, y, z, r);
        } catch (std::domain_error greska) {
            std::cout << greska.what() << std::endl;
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            i--;
        }
        i++;
    }

    std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double dx, dy, dz;
    std::cin >> dx >> dy >> dz;
    if (!std::cin) {
        while (!std::cin) {
            std::cout << "Neispravni parametri translacije, unesite ponovo!\n";
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            std::cin >> dx >>dy>>dz;
        }
    }

    std::transform(vektor.begin(), vektor.end(), vektor.begin(), [dx, dy, dz](std::shared_ptr<Kugla> k) {
        k->Transliraj(dx, dy, dz);
        return k;
    });
    std::sort(vektor.begin(), vektor.end(), [](std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2) {
        return k1->DajZapreminu() < k2->DajZapreminu();
    });
    std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: \n";
    std::for_each(vektor.begin(), vektor.end(), [](std::shared_ptr<Kugla> k) {
        k->Ispisi();
    });

    auto najveca = *max_element (vektor.begin(), vektor.end(), [] (std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2) {
        return k1->DajPovrsinu() < k2->DajPovrsinu();
    });

    std::cout << "Kugla sa najvecom povrsinom je: ";
    najveca->Ispisi();
    std::cout << std::endl;
    bool sijeku_se=false;
    std::vector<std::pair<Kugla, Kugla>> Sijeku_se;
    int pozicija(0);
    std::for_each(vektor.begin(), vektor.end(), [&sijeku_se,&pozicija, vektor](std::shared_ptr<Kugla> k1) {
        for (int i(0); i<vektor.size(); i++) {
            if(k1==vektor[i]) {
                std::for_each(vektor.begin()+i, vektor.end(), [&sijeku_se, k1, vektor, &pozicija] (std::shared_ptr<Kugla> k2) {
                    if (DaLiSeSijeku(*k1, *k2) && k1!=k2) {
                        std::cout << "Presjecaju se kugle: ";
                        (*k1).Ispisi();
                        (*k2).Ispisi();
                        sijeku_se=true;
                    }

                });
            }
        }
    });
    if (!sijeku_se) std::cout << "Ne postoje kugle koje se presjecaju!";



    return 0;
}
