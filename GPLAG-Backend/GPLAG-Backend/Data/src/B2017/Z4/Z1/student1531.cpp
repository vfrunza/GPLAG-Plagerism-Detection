/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <tuple>
#include <vector>
#include <memory>
#include <algorithm>


class Kugla
{
    double x, y, z;
    double r;
    static constexpr double PI {4.*(std::atan(1))};
    static bool JesuLiJednaki(double x, double y, double Eps = 1e-10) {
        return ( std::fabs(x-y) <= Eps*(std::fabs(x)+std::fabs(y)) );
    }

public:
    explicit Kugla(double r = 0) : x(0), y(0), z(0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::r = r;
    }
    Kugla(double x, double y, double z, double r = 0) : x(x), y(y), z(z) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::r = r;
    }
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        x = std::get<0>(centar);
        y = std::get<1>(centar);
        z = std::get<2>(centar);
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
        std::tuple<double, double, double> t {x, y, z};
        return t;
    }
    double DajPoluprecnik() const {
        return r;
    }
    double DajPovrsinu() const {
        return 4.*r*r*PI;
    }
    double DajZapreminu() const {
        return (4*PI*r*r*r)/3.;
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
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::r = r;
        return *this;
    }
    void Ispisi() const;
    void Transliraj(double delta_x, double delta_y, double delta_z);
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

void Kugla::Ispisi() const
{
    std::cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}"<<std::endl;
}
void Kugla::Transliraj(double delta_x, double delta_y, double delta_z)
{
    x += delta_x;
    y += delta_y;
    z += delta_z;
}

bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2)
{
    return (Kugla::JesuLiJednaki(k1.x, k2.x) && Kugla::JesuLiJednaki(k1.y, k2.y) && Kugla::JesuLiJednaki(k1.z, k2.z) && Kugla::JesuLiJednaki(k1.r, k2.r));
}
bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2)
{
    return Kugla::JesuLiJednaki(k1.r, k2.r);
}

bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2)
{
    return (Kugla::JesuLiJednaki(k1.x, k2.x) && Kugla::JesuLiJednaki(k1.y, k2.y) && Kugla::JesuLiJednaki(k1.z, k2.z));
}

bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2)
{
    return Kugla::JesuLiJednaki((k1.r + k2.r), RastojanjeCentara(k1, k2)) && !DaLiSuIdenticne(k1, k2);
}

bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2)
{

    return Kugla::JesuLiJednaki(std::fabs(k1.r - k2.r), RastojanjeCentara(k1, k2)) && !DaLiSuIdenticne(k1, k2);
}

bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2)
{
    return ((k1.r + k2.r) > RastojanjeCentara(k1, k2));
}

bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2)
{
    return ((k1.r + k2.r) > RastojanjeCentara(k1, k2) && !k1.DaLiSadrzi(k2) && !k2.DaLiSadrzi(k1));
}

bool Kugla::DaLiSadrzi(const Kugla &k) const
{
    if(((*this).r - k.r)<0) return false;
    return (((*this).r - k.r) >= RastojanjeCentara(*this, k));
}

double RastojanjeCentara(const Kugla &k1, const Kugla &k2)
{
    return std::sqrt( std::pow((k1.x-k2.x), 2) + std::pow((k1.y-k2.y), 2) + std::pow((k1.z-k2.z), 2) );
}

int main ()
{
    try {
        std::cout<<"Unesite broj kugla: ";
        int n;
        for(;;) {
            std::cin>>n;
            if(!std::cin) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout<<"Neispravan broj kugli, unesite ponovo!\n";
            } else if(n<=0) {
                std::cout<<"Neispravan broj kugli, unesite ponovo!\n";
            } else break;
        }
        std::vector<std::shared_ptr<Kugla>> vektor(n);
        for(int i=0; i<n; i++) {
            std::cout<<"Unesite centar "<<i+1<<". kugle: ";
            double a, b, c, d;
            std::cin>>a>>b>>c;
            if(std::cin) {
                std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
                std::cin>>d;
                if(std::cin && d>=0) {
                    vektor.at(i) = std::make_shared<Kugla>(a, b, c, d);
                } else {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    std::cout<<"Ilegalan poluprecnik\n";
                    i--;
                }
            } else {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout<<"Neispravan centar\n";
                i--;
            }
        }
        std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
        double delta_x, delta_y, delta_z;
        for(;;) {
            std::cin>>delta_x>>delta_y>>delta_z;
            if(std::cin) break;
            else {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout<<"Neispravni parametri translacije, unesite ponovo!\n";
            }
        }
        std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti:\n";
        std::transform(vektor.begin(), vektor.end(), vektor.begin(), [delta_x, delta_y, delta_z] (std::shared_ptr<Kugla> pnk) {
            pnk->Transliraj(delta_x, delta_y, delta_z);
            return pnk;
        });

        std::sort(vektor.begin(), vektor.end(), [](std::shared_ptr<Kugla> pnk1, std::shared_ptr<Kugla> pnk2) {
            return (*pnk1).DajZapreminu() < (*pnk2).DajZapreminu();
        });
        std::for_each(vektor.begin(), vektor.end(), [](std::shared_ptr<Kugla> pnk) {
            pnk->Ispisi();
        });
        auto it (std::max_element(vektor.begin(), vektor.end(), [](std::shared_ptr<Kugla> pnk1, std::shared_ptr<Kugla> pnk2) {
            return (*pnk1).DajPovrsinu() < (*pnk2).DajPovrsinu();
        }) );
        std::cout<<"Kugla sa najvecom povrsinom je: ";
        (*it)->Ispisi();
        
        int brojac(0);
        bool sijeku(false);
        std::for_each(vektor.begin(), vektor.end(), [vektor, &brojac, &sijeku](std::shared_ptr<Kugla> pnk) {
            brojac++;
            if(vektor.begin() + brojac != vektor.end()) {
                std::for_each(vektor.begin() + brojac, vektor.end(), [pnk, &sijeku](std::shared_ptr<Kugla> pnk2) {
                    if(DaLiSeSijeku(*pnk, *pnk2)) {
                        if(!sijeku) {
                            sijeku = true;
                        }
                        std::cout<<"Presjecaju se kugle: ";
                        pnk->Ispisi();
                        pnk2->Ispisi();
                    }
                });
            }
        });
        if(!sijeku) std::cout<<"Ne postoje kugle koje se presjecaju!";

    } catch(std::domain_error izuzetak) {
        std::cout<<"Izuzetak: "<<izuzetak.what()<<std::endl;
    } catch(...) {
        std::cout<<"Doslo je do greske!"<<std::endl;
    }

    return 0;
}
