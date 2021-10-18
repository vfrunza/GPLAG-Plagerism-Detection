#include <iostream>
#include <tuple>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>

const double pi(4*atan(1));
const double eps=pow(10,-10);

class Kugla
{
    double x,y,z;
    double poluprecnik;
    static bool Jednako (double k1,double k2) {
        if (abs(k1-k2)<=eps*(abs(k1)+abs(k2))) return true;
        return false;
    }
public:
    explicit Kugla (double r = 0) {
        if (r<0) throw std::domain_error ("Ilegalan poluprecnik");
        x=y=z=0;
        poluprecnik=r;
    }
    Kugla (double x, double y, double z, double r=0) {
        if (r<0) throw std::domain_error ("Ilegalan poluprecnik");
        Kugla::x=x;
        Kugla::y=y;
        Kugla::z=z;
        poluprecnik=r;
    }
    explicit Kugla (const std::tuple<double, double, double> &centar, double r=0) {
        if (r<0) throw std::domain_error ("Ilegalan poluprecnik");
        poluprecnik=r;
        x=std::get<0>(centar);
        y=std::get<1>(centar);
        z=std::get<2>(centar);
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
        return std::tuple<int,int,int> (x,y,z);
    }
    double DajPoluprecnik() const {
        return poluprecnik;
    }
    double DajPovrsinu() const {
        return 4*pi*poluprecnik*poluprecnik;
    }
    double DajZapreminu() const {
        return (4./3)*(poluprecnik*poluprecnik*poluprecnik)/pi;
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
        if (r<0) throw std::domain_error ("Ilegalan poluprecnik");
        poluprecnik=r;
        return *this;
    }
    void Ispisi() const {
        std::cout<<"{("<<x<<","<<y<<","<<z<<"),"<<poluprecnik<<"}"<<std::endl;
    }
    void Transliraj(double delta_x, double delta_y, double delta_z) {
        Kugla::x+=delta_x;
        Kugla::y+=delta_y;
        Kugla::z+=delta_z;
    }
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2) {
        if (Jednako(k1.DajX(),k2.DajX())==true && Jednako(k1.DajY(),k2.DajY())==true && Jednako(k1.DajZ(),k2.DajZ())==true && Jednako(k1.DajPoluprecnik(),k2.DajPoluprecnik())==true) return true;
        return false;
    }
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2) {
        if (Jednako(k1.DajPoluprecnik(),k2.DajPoluprecnik())==true) return true;
        return false;
    }
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2) {
        if (Jednako(k1.DajX(),k2.DajX())==true && Jednako(k1.DajY(),k2.DajY())==true && Jednako(k1.DajZ(),k2.DajZ())==true) return true;
        return false;
    }
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2) {
        double udaljenost=sqrt((k2.DajX()-k1.DajX())*(k2.DajX()-k1.DajX())+(k2.DajY()-k1.DajY())*(k2.DajY()-k1.DajY())+(k2.DajZ()-k1.DajZ())*(k2.DajZ()-k1.DajZ()));
        double duzina=k1.DajPoluprecnik()+k2.DajPoluprecnik();
        if (Jednako(udaljenost,duzina)==true) return true;
        return false;
    }
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2) {
        double udaljenost=sqrt((k2.DajX()-k1.DajX())*(k2.DajX()-k1.DajX())+(k2.DajY()-k1.DajY())*(k2.DajY()-k1.DajY())+(k2.DajZ()-k1.DajZ())*(k2.DajZ()-k1.DajZ()));
        double duzina=fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik());
        if (Jednako(udaljenost,duzina)==true) return true;
        return false;
    }
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2) {
        double udaljenost=sqrt((k2.DajX()-k1.DajX())*(k2.DajX()-k1.DajX())+(k2.DajY()-k1.DajY())*(k2.DajY()-k1.DajY())+(k2.DajZ()-k1.DajZ())*(k2.DajZ()-k1.DajZ()));
        double duzina=k1.DajPoluprecnik()+k2.DajPoluprecnik();
        if (udaljenost<duzina) return true;
        return false;
    }
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2) {
        double udaljenost=sqrt((k2.DajX()-k1.DajX())*(k2.DajX()-k1.DajX())+(k2.DajY()-k1.DajY())*(k2.DajY()-k1.DajY())+(k2.DajZ()-k1.DajZ())*(k2.DajZ()-k1.DajZ()));
        double zbir=k1.DajPoluprecnik()+k2.DajPoluprecnik();
        double razlika=abs(k1.DajPoluprecnik()-k2.DajPoluprecnik());
        if (udaljenost<zbir && udaljenost>razlika) return true;
        return false;
    }
    bool DaLiSadrzi(const Kugla &k) const {
        double udaljenost=sqrt((k.DajX()-DajX())*(k.DajX()-DajX())+(k.DajY()-DajY())*(k.DajY()-DajY())+(k.DajZ()-DajZ())*(k.DajZ()-DajZ()));
        double duzina=abs(DajPoluprecnik()-k.DajPoluprecnik());
        if (udaljenost<=duzina) return true;
        return false;
    }
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2) {
        double udaljenost=sqrt((k2.DajX()-k1.DajX())*(k2.DajX()-k1.DajX())+(k2.DajY()-k1.DajY())*(k2.DajY()-k1.DajY())+(k2.DajZ()-k1.DajZ())*(k2.DajZ()-k1.DajZ()));
        return udaljenost;
    }
};

int main ()
{
    try {
        std::cout<<"Unesite broj kugla: ";
        int n;
        for (;;) {
            std::cin>>n;
            if (n<1 || !std::cin) {
                std::cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;
                std::cin.clear();
                std::cin.ignore(1000,'\n');
                continue;
            } else break;
        }
        std::vector<std::shared_ptr<Kugla>> vektor;
        for (int i=1; i<=n; i++) {
            try {
                std::cout<<"Unesite centar "<<i<<". kugle: ";
                double x,y,z;
                std::cin>>x>>y>>z;
                if (!std::cin) {
                    std::cout<<"Neispravan centar"<<std::endl;
                    i--;
                    std::cin.clear();
                    std::cin.ignore(1000,'\n');
                    continue;
                }
                std::cout<<"Unesite poluprecnik "<<i<<". kugle: ";
                double r;
                std::cin>>r;
                if (!std::cin) {
                    std::cout<<"Ilegalan poluprecnik"<<std::endl;
                    i--;
                    std::cin.clear();
                    std::cin.ignore(1000,'\n');
                    continue;
                }
                auto pom (std::make_shared<Kugla>(x,y,z,r));
                vektor.push_back(pom);
            } catch (std::domain_error d) {
                std::cout<<d.what()<<std::endl;
                i--;
            }
        }
        std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
        double delta_x,delta_y,delta_z;
        for (;;) {
            std::cin>>delta_x>>delta_y>>delta_z;
            if (!std::cin) {
                std::cout<<"Neispravni parametri translacije, unesite ponovo!"<<std::endl;
                std::cin.clear();
                std::cin.ignore(1000,'\n');
                continue;
            } else break;
        }
        std::transform (vektor.begin(),vektor.end(),vektor.begin(),[delta_x,delta_y,delta_z] (std::shared_ptr<Kugla> k) {
            k->Transliraj(delta_x,delta_y,delta_z);
            return k;
        });
        std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<std::endl;
        std::sort (vektor.begin(),vektor.end(),[] (std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2) {
            return k1->DajZapreminu()<k2->DajZapreminu();
        });
        std::for_each (vektor.begin(),vektor.end(),[] (std::shared_ptr<Kugla> k) {
            k->Ispisi();
        });
        auto maks=*std::max_element(vektor.begin(),vektor.end(),[] (std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2) {
            if (k1->DajPovrsinu()<k2->DajPovrsinu()) return true;
            return false;
        });
        std::cout<<"Kugla sa najvecom povrsinom je: ";
        maks->Ispisi();
        int i(1);
        bool tacnost(true);
        std::for_each (vektor.begin(),vektor.end(),[vektor,&i,&tacnost] (std::shared_ptr<Kugla> k1) {
            std::for_each(vektor.begin()+i,vektor.end(),[k1,&tacnost] (std::shared_ptr<Kugla> k2) {
                if (DaLiSeSijeku(*k1,*k2)) {
                    std::cout<<"Presjecaju se kugle: " ;
                    k1->Ispisi();
                    k2->Ispisi();
                    tacnost=false;
                }
            });
            i++;
        });
        if (tacnost) std::cout<<"Ne postoje kugle koje se presjecaju!";

    } catch (std::domain_error d) {
        std::cout<<d.what()<<std::endl;
    }
    return 0;
}
