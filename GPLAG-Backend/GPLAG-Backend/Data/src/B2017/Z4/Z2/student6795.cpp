/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <cmath>
#include <algorithm>
#include <vector>
#include <memory>

const double PI = 4. * atan(1);

class NepreklapajucaKugla
{
    double x,y,z;
    double poluprecnik;
    NepreklapajucaKugla *pokazivac_na_prethodnu;
    static NepreklapajucaKugla *zadnja_kreirana;

    bool DaLiSuIdenticne(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2) const {
        double udaljenost(RastojanjeCentara(k1, k2));
        if(std::fabs(udaljenost - 0) <= 1e-10 * (std::fabs(udaljenost) + std::abs(0)) && (std::fabs(k1.poluprecnik - k2.poluprecnik) < 1e-10*(std::fabs(k1.poluprecnik) + std::fabs(k2.poluprecnik)))) return true;
        return false;

        if(k1.x == k2.x && k1.y == k2.y && k1.z == k2.z && k1.poluprecnik == k2.poluprecnik) return true;
        return false;
    }
    bool DaLiSuPodudarne(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2) const {
        if(std::fabs(k1.poluprecnik - k2.poluprecnik) < 1e-10 * (std::fabs(k1.poluprecnik) + std::fabs(k2.poluprecnik))) return true;
        return false;
    }
    bool DaLiSuKoncentricne(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2) const {
        double udaljenost = RastojanjeCentara(k1, k2);
        if(std::fabs(udaljenost - 0) <= 1e-10 * (std::fabs(udaljenost) + fabs(0))) return true;
        return false;
    }
    bool DaLiSeDodirujuIzvana(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2) const {
        double udaljenost = RastojanjeCentara(k1, k2);
        double dr(k1.poluprecnik + k2.poluprecnik);
        if(std::fabs(dr - udaljenost) <= 1e-10 * (std::fabs(dr) + std::fabs(udaljenost))) return true;
        return false;
    }
    bool DaLiSeDodirujuIznutra(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2) const {
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
    bool DaLiSeSijeku(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2) const {
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

public:

    explicit NepreklapajucaKugla(double r = 0) {
        if(r < 0) throw std::domain_error("Ilegalan poluprecnik");
        poluprecnik = r;
        x = y = z = 0;
        pokazivac_na_prethodnu = zadnja_kreirana;
        zadnja_kreirana = this;
    }
    NepreklapajucaKugla(double x, double y, double z, double r = 0) {
        if(r < 0) throw std::domain_error("Ilegalan poluprecnik");
        NepreklapajucaKugla::x = x;
        NepreklapajucaKugla::y = y;
        NepreklapajucaKugla::z = z;
        poluprecnik = r;
        pokazivac_na_prethodnu = zadnja_kreirana;
        zadnja_kreirana = this;
    }
    ~NepreklapajucaKugla() {
        //Ako je zadnji u lancu
        if(zadnja_kreirana == this) {
            zadnja_kreirana = this->pokazivac_na_prethodnu;
            this->pokazivac_na_prethodnu = nullptr;
            return;
        }

        //Ako nije zadnji, a ni prvi
        if(zadnja_kreirana != this && this->pokazivac_na_prethodnu != nullptr) {
            for(auto i = zadnja_kreirana; i != this; i = i->pokazivac_na_prethodnu) {
                if(i->pokazivac_na_prethodnu == this) {
                    i->pokazivac_na_prethodnu = this->pokazivac_na_prethodnu;
                    break;
                }
            }
            this->pokazivac_na_prethodnu = nullptr;
            return;
        }

        //Ako je prvi :(
        if(this->pokazivac_na_prethodnu == nullptr) {
            for(auto i = zadnja_kreirana; i != this; i = i->pokazivac_na_prethodnu) {
                if(i->pokazivac_na_prethodnu == this) {
                    i->pokazivac_na_prethodnu = nullptr;
                    break;
                }
            }
            this->pokazivac_na_prethodnu = nullptr;
        }

    }
    explicit NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r = 0) {
        if(r < 0) throw std::domain_error("Ilegalan poluprecnik");
        x = std::get<0>(centar);
        y = std::get<1>(centar);
        z = std::get<2>(centar);
        pokazivac_na_prethodnu = zadnja_kreirana;
        zadnja_kreirana = this;
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
    NepreklapajucaKugla &PostaviX(double x) {
        NepreklapajucaKugla::x = x;
        return *this;
    }
    NepreklapajucaKugla &PostaviY(double y) {
        NepreklapajucaKugla::y = y;
        return *this;
    }
    NepreklapajucaKugla &PostaviZ(double z) {
        NepreklapajucaKugla::z = z;
        return *this;
    }
    NepreklapajucaKugla &PostaviCentar(double x, double y, double z) {
        NepreklapajucaKugla::x = x;
        NepreklapajucaKugla::y = y;
        NepreklapajucaKugla::z = z;
        return *this;
    }
    NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar) {
        x = std::get<0>(centar);
        y = std::get<1>(centar);
        z = std::get<2>(centar);
        return *this;
    }
    NepreklapajucaKugla &PostaviPoluprecnik(double r) {
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
    double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2) const {
        return std::sqrt(pow((k1.x - k2.x),2) + pow((k1.y - k2.y),2) + pow((k1.z - k2.z),2));
    }
    bool DaLiSadrzi(const NepreklapajucaKugla &k) const {
        if(k.poluprecnik > poluprecnik) return false;
        double d, dr;
        d = std::sqrt(pow((x - k.x),2) + pow((y - k.y),2) + pow((z - k.z),2));
        dr = poluprecnik - k.poluprecnik;
        if(std::abs(d - 0) <= 1e-10 * (std::fabs(d) + std::fabs(0))) return true;
        else if(std::fabs(d - dr) < 1e-10 * (std::fabs(d) + std::fabs(dr))) return true;
        else if(d < dr) return true;
        return false;
    }

    bool DaLiSePreklapaju(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2) {
        if(DaLiSeDodirujuIznutra(k1, k2)) return true;
        if(DaLiSeDodirujuIzvana(k1, k2)) return true;
        if(DaLiSuIdenticne(k1, k2)) return true;
        if(DaLiSuKoncentricne(k1, k2)) return true;
        if(DaLiSeSijeku(k1, k2)) return true;
        if(k1.DaLiSadrzi(k2)) return true;
        if(k2.DaLiSadrzi(k1)) return true;
        return false;
    }
    bool ImaLiPreklapanjaSaPrethodnim(const NepreklapajucaKugla &k1) {
        for(NepreklapajucaKugla *i = k1.pokazivac_na_prethodnu; i != nullptr; i = i->pokazivac_na_prethodnu) {
            if(DaLiSePreklapaju(*i, k1))
                return true;
        }
        return false;
    }
};

NepreklapajucaKugla* NepreklapajucaKugla::zadnja_kreirana = nullptr;

int main ()
{
    std::cout<<"Unesite broj kugli: ";
    int broj_kugla;
    std::cin>>broj_kugla;
    while(!(std::cin) || broj_kugla <= 0) {
        std::cout<<"Neispravan broj kugli, unesite ponovo!\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cin>>broj_kugla;
    }
    std::vector<std::shared_ptr<NepreklapajucaKugla>> kugle;
    int brojac(1);
    while(kugle.size() != broj_kugla) {
        std::cout<<"Unesite centar za "<<brojac<<". kuglu: ";
        double x,y,z;
        for(;;) {
            std::cin>>x;
            if(!std::cin) {
                std::cout<<"Neispravan centar, unesite ponovo:\n";
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                continue;
            }
            std::cin>>y;
            if(!std::cin) {
                std::cout<<"Neispravan centar, unesite ponovo:\n";
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                continue;
            }
            std::cin>>z;
            if(!std::cin) {
                std::cout<<"Neispravan centar, unesite ponovo:\n";
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                continue;
            }
            break;
        }
        std::cout<<"Unesite poluprecnik: ";
        double r;
        std::cin>>r;
        while(!std::cin || r < 0) {
            std::cout<<"Neispravan poluprecnik, unesite ponovo:\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cin>>r;
            continue;
        }
        try {
            auto p = std::make_shared<NepreklapajucaKugla>(x, y, z, r);
            if(p->ImaLiPreklapanjaSaPrethodnim(*p)) {
                std::cout<<"Nedozvoljeno preklapanje\n";
                continue;
            }
            kugle.emplace_back(p);
        } catch(std::logic_error e) {
            std::cout<<e.what();
            continue;
        }

        ++brojac;
    }

    std::cout<<"\nKugle nakon obavljenog sortiranja: \n";
    std::sort(std::begin(kugle), std::end(kugle), [=](const std::shared_ptr<NepreklapajucaKugla> k1, const std::shared_ptr<NepreklapajucaKugla> k2) -> bool {
        return k1->DajZapreminu() < k2->DajZapreminu();
    });
    std::for_each(std::begin(kugle), std::end(kugle), [=](const std::shared_ptr<NepreklapajucaKugla> k) {
        k->Ispisi();
    });



    return 0;
}