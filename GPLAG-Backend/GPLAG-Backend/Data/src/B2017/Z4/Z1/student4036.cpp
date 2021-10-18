/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <tuple>
#include <vector>
#include <iomanip>
#include <utility>
#include <memory>
#include <algorithm>

bool JesuLiJednake(double x, double y, double eps=1e-10)
{
    if((x<0 && y>0) || (x>0 && y<0)) return false;
    return std::fabs(x-y) <= eps*(std::fabs(x)+ std::fabs(y));
}
const double PI(4*atan(1));
class Kugla
{
    double x,y,z,r;
public:
    explicit Kugla(double r = 0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        x=0;y=0;z=0;
    }
    Kugla(double x, double y, double z, double r = 0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::x=x;
        Kugla::y=y;
        Kugla::z=z;
        Kugla::r=r;
    }
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0) {
        double x1,y1,z1;
        std::tie(x1,y1,z1)=centar;
        Kugla::x=x1; Kugla::y=y1; Kugla::z=z1;
        Kugla::r=r;
    }
    double DajX() const {
        return x;
    };
    double DajY() const {
        return y;
    };
    double DajZ() const {
        return z;
    };
    std::tuple<double, double, double> DajCentar() const { 
        return std::make_tuple(x,y,z);
    }

    double DajPoluprecnik() const {
        return r;
    }
    double DajPovrsinu() const {
        return 4*PI*pow(r,2);
    }
    double DajZapreminu() const {
        return 4*pow(r,3)*PI/3.;
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
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar){
        double x2,y2,z2;
        std::tie(x2,y2,z2)=centar;
        Kugla::x=x2; Kugla::y=y2; Kugla::z=z2;
        return *this;
    }
    Kugla &PostaviPoluprecnik(double r) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::r=r;
        return *this;
    }
    void Ispisi() const {
        std::cout << "{(" << DajX() << "," << DajY() << "," << DajZ() << ")," << DajPoluprecnik() << "}" << std::endl;
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
        double d(std::sqrt((std::fabs(std::pow(x-k.x,2) + std::pow(y-k.y,2) + std::pow(z-k.z,2)))));
        if(d<std::fabs(r-k.r) && !DaLiSeSijeku(*this, k)) return true;
        return false;
    }
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);

};

bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2)
{
    if(JesuLiJednake(k1.x, k2.x) && JesuLiJednake(k1.y, k2.y) && JesuLiJednake(k1.z, k2.z) && JesuLiJednake(k1.r, k2.r)) return true;
    return false;
}

bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2)
{
    if(JesuLiJednake(k1.r, k2.r)) return true;
    return false;
}

bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2)
{
    if(JesuLiJednake(k1.x, k2.x) && JesuLiJednake(k1.y, k2.y) && JesuLiJednake(k1.z, k2.z)) return true;
    return false;
}
bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2)
{
    double d(std::sqrt(std::pow(k1.x-k2.x,2) + std::pow(k1.y-k2.y,2) + std::pow(k1.z-k2.z, 2)));
    if(JesuLiJednake(std::fabs(d), std::fabs(k1.r+k2.r))) return true;
    return false;
}

bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2)
{
    double d(std::sqrt(std::pow(k1.x-k2.x,2)+std::pow(k1.y-k2.y,2)+ std::pow(k1.z-k2.z, 2)));
    if (DaLiSeDodirujuIzvana(k1,k2) == true) return false;
    if(JesuLiJednake(d, std::fabs(k1.r - k2.r))) return true;
    return false;

}
bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2)
{
    if(DaLiSeSijeku(k1,k2) == true && !(RastojanjeCentara(k1,k2) > std::fabs(k1.r+k2.r))) return true;
    return false;
}

bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2)
{
    double d(std::sqrt(std::pow(k1.x-k2.x,2)+std::pow(k1.y-k2.y,2)+ std::pow(k1.z-k2.z, 2)));

    if(std::fabs(k2.r-k1.r) < std::fabs(d) && std::fabs(d) < k1.r+k2.r) return true;
    return false;
}

double RastojanjeCentara(const Kugla &k1, const Kugla &k2)
{
    double d(sqrt(pow(k1.x-k2.x,2)+pow(k1.y-k2.y,2)+ pow(k1.z-k2.z, 2)));
    return d;
}
int main ()
{
    int n;
    Kugla kuglica;
    std::cout << "Unesite broj kugla: ";
    std::cin >> n;

    while(n<=0 || !std::cin) {
        std::cout << "Neispravan broj kugli, unesite ponovo!" << std::endl;
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cin >> n;
    }


    std::vector<std::shared_ptr<Kugla>> vektor(n);

    for(int i=0; i<n; i++) {
        double x,y,z,r;
        try {
            do {
                std::cin.clear();
                std::cin.ignore(1000,'\n');

                std::cout << "Unesite centar " << i+1 << ". kugle: ";
                std::cin >> x >> y >> z;

                if(!std::cin) {
                    std::cout << "Neispravan centar" << std::endl;
                    //std::cout <<"Unesite centar " << i+1 << ". kugle: ";
                    std::cin >> x >> y >> z;
                    continue;
                }
                std::cout << "Unesite poluprecnik " << i+1 << ". kugle: " ;
                std::cin >> r;
                if(!std::cin) {
                    std::cout << "Ilegalan poluprecnik" << std::endl;
                }
            } while(!std::cin);
            kuglica.PostaviX(x);
            kuglica.PostaviY(y);
            kuglica.PostaviZ(z);
            kuglica.PostaviPoluprecnik(r);
            vektor[i]=std::make_shared<Kugla>(kuglica);
        } catch(std::domain_error izuzetak) {
            std::cout << izuzetak.what() << std::endl;
            i--;
        } catch(std::bad_alloc izuzetak) {
            std::cout << "Nema dovoljno memorije!" << std::endl;
            return 0;
        } catch(...) {
            std::cout <<"nadam se da je ovaj ";
        }
    }

    std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): " ;
    double delta_x, delta_y, delta_z;

    std::cin >> delta_x >> delta_y >> delta_z;
    while(!std::cin) {
        std::cout << "Neispravni parametri translacije, unesite ponovo!" << std::endl;
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cin >> delta_x >> delta_y >> delta_z;
    }
    std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: " << std::endl;
    std::transform(vektor.begin(), vektor.end(), vektor.begin(), [delta_x, delta_y, delta_z](std::shared_ptr<Kugla> &p) {
        p->Transliraj(delta_x, delta_y, delta_z);
        return p;
    });

    std::sort(vektor.begin(), vektor.end(), [](const std::shared_ptr<Kugla> &p1, const std::shared_ptr<Kugla> &p2) {
        return p1->DajZapreminu()<p2->DajZapreminu();
    });


    for_each(vektor.begin(), vektor.end(), [](const std::shared_ptr<Kugla> &p) {
        p->Ispisi();
    });
    auto pom (*std::max_element(vektor.begin(), vektor.end(), [](const std::shared_ptr<Kugla> &p1, const std::shared_ptr<Kugla> &p2) {
        return p1->DajPovrsinu() < p2->DajPovrsinu();
    }));

    std::cout << "Kugla sa najvecom povrsinom je: ";
    pom->Ispisi();

    bool ima(false);
    int indeks(0);
    for_each(vektor.begin(), vektor.end(), [&indeks, &ima, vektor](const std::shared_ptr<Kugla>&p) {
        indeks++;
        for_each(vektor.begin()+indeks, vektor.end(), [&p, &ima](const std::shared_ptr<Kugla> &p2) {
            if(DaLiSeSijeku(*p, *p2) == true) {
                std::cout << "Presjecaju se kugle: " ;
                p->Ispisi();
                p2->Ispisi();
                ima=true;
            }
        });
    });
    if(ima==false) std::cout << "Ne postoje kugle koje se presjecaju!" << std::endl;
    
    return 0;
}
