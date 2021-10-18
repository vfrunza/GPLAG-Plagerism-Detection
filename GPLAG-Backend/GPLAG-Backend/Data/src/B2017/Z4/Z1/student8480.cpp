/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <tuple>
#include <cmath>
#include <memory>
#include <vector>
#include <algorithm>

bool JesuLiJednaki(double x, double y, double Eps = 1e-10)
{
    return std::fabs(x - y) <= Eps * (std::fabs(x) + std::fabs(y));
}

class Kugla
{
private:
    double x, y, z, r;
public:
    explicit Kugla(double r = 0);
    Kugla(double x, double y, double z, double r = 0);
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0);
    double DajX() const;
    double DajY() const;
    double DajZ() const;
    std::tuple<double, double, double> DajCentar() const;
    double DajPoluprecnik() const;
    double DajPovrsinu() const;
    double DajZapreminu() const;
    Kugla &PostaviX(double x);
    Kugla &PostaviY(double y);
    Kugla &PostaviZ(double z);
    Kugla &PostaviCentar(double x, double y, double z);
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar);
    Kugla &PostaviPoluprecnik(double r);
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

Kugla::Kugla(double r) : Kugla(0,0,0,r) {}
Kugla::Kugla(double x, double y, double z, double r)
{
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    this->x = x;
    this->y = y;
    this->z = z;
    this->r = r;
}
Kugla::Kugla(const std::tuple<double, double, double> &centar, double r) :
    Kugla(std::get<0>(centar), std::get<1>(centar), std::get<2>(centar), r) {}
double Kugla::DajX() const
{
    return this->x;
}
double Kugla::DajY() const
{
    return this->y;
}
double Kugla::DajZ() const
{
    return this->z;
}
std::tuple<double, double, double> Kugla::DajCentar() const
{
    return std::tuple<double, double, double>(this->x, this->y, this->z);
}
double Kugla::DajPoluprecnik() const
{
    return this->r;
}
double Kugla::DajPovrsinu() const
{
    return 4*r*r*std::atan(1)*4;
}
double Kugla::DajZapreminu() const
{
    return (4/3)*r*r*r*std::atan(1)*4;
}
Kugla &Kugla::PostaviX(double x)
{
    this->x = x;
    return *this;
}
Kugla &Kugla::PostaviY(double y)
{
    this->y = y;
    return *this;
}
Kugla &Kugla::PostaviZ(double z)
{
    this->z = z;
    return *this;
}
Kugla &Kugla::PostaviCentar(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
    return *this;
}
Kugla &Kugla::PostaviCentar(const std::tuple<double, double, double> &centar)
{
    this->x = std::get<0>(centar);
    this->y = std::get<1>(centar);
    this->z = std::get<2>(centar);
    return *this;
}
Kugla &Kugla::PostaviPoluprecnik(double r)
{
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    this->r = r;
    return *this;
}
void Kugla::Ispisi() const
{
    std::cout << "{(" << this->x << "," << this->y << "," << this->z << "),"
              << this->r << "}" << std::endl;
    return;
}
void Kugla::Transliraj(double delta_x, double delta_y, double delta_z)
{
    this->x += delta_x;
    this->y += delta_y;
    this->z += delta_z;
    return;
}
bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2)
{
    return JesuLiJednaki(k1.DajX(), k2.DajX()) &&
           JesuLiJednaki(k1.DajY(), k2.DajY()) &&
           JesuLiJednaki(k1.DajZ(), k2.DajZ()) &&
           JesuLiJednaki(k1.DajPoluprecnik(),
                         k2.DajPoluprecnik());
}
bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2)
{
    return JesuLiJednaki(k1.DajPoluprecnik(), k2.DajPoluprecnik());
}
bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2)
{
    return JesuLiJednaki(k1.DajX(), k2.DajX()) &&
           JesuLiJednaki(k1.DajY(), k2.DajY()) &&
           JesuLiJednaki(k1.DajZ(), k2.DajZ());
}
bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2)
{
    return JesuLiJednaki(RastojanjeCentara(k1, k2),
                         k1.DajPoluprecnik()+k2.DajPoluprecnik());
}
bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2)
{
    return JesuLiJednaki(RastojanjeCentara(k1, k2),
                         std::fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik()));
}
bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2)
{
    return k1.DaLiSadrzi(k2) || DaLiSeSijeku(k1, k2);
}
bool Kugla::DaLiSadrzi(const Kugla &k) const
{
    return RastojanjeCentara(*this,k) <
           std::fabs(this->DajPoluprecnik()-k.DajPoluprecnik());
}
bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2)
{
    return RastojanjeCentara(k1,k2) < k1.DajPoluprecnik()+k2.DajPoluprecnik()
           && RastojanjeCentara(k1,k2) > std::fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik());
}
double RastojanjeCentara(const Kugla &k1, const Kugla &k2)
{
    return std::sqrt(std::pow(k1.DajX()-k2.DajX(),2) +
                     std::pow(k1.DajY()-k2.DajY(),2) +
                     std::pow(k1.DajZ()-k2.DajZ(),2));
}

int main ()
{
    std::cout << "Unesite broj kugla: ";
    int n;
    std::cin >> n;
    while(!std::cin || n<1) {
        std::cout << "Neispravan broj kugli, unesite ponovo!" << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cin >> n;
    }
    std::vector<std::shared_ptr<Kugla>> kugle(n);

    double x,y,z,r;
    for(int i=0; i<n; i++) {
        bool input = true;
        while(true) {
            if(!input) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
            }

            std::cout << "Unesite centar " << i+1 << ". kugle: ";
            std::cin >> x >> y >> z;

            if(!std::cin) {
                std::cout << "Neispravan centar" << std::endl;
                input = false;
                continue;
            }

            std::cout << "Unesite poluprecnik " << i+1 << ". kugle: ";
            std::cin >> r;
            if(!std::cin || r<0) {
                std::cout << "Ilegalan poluprecnik" << std::endl;
                input = false;
                continue;
            }
            break;
        }

        try {
            kugle[i] = std::make_shared<Kugla>(x,y,z,r);
        } catch(std::domain_error izuzetak) {
            std::cout << izuzetak.what() << std::endl;
            i--;
        }
    }
    std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    std::cin >> x >> y >> z;
    while(!std::cin) {
        std::cout << "Neispravni parametri translacije, unesite ponovo!" << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cin >> x >> y >> z;
    }

    std::transform(kugle.begin(), kugle.end(), kugle.begin(), [x,y,z](std::shared_ptr<Kugla> k) {
        k->Transliraj(x, y, z);
        return k;
    });

    std::sort(kugle.begin(), kugle.end(), [](std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2) {
        return k1->DajZapreminu() < k2->DajZapreminu();
    });

    std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: " << std::endl;
    std::for_each(kugle.begin(), kugle.end(), [](std::shared_ptr<Kugla> k) {
        k->Ispisi();
    });

    std::cout << "Kugla sa najvecom povrsinom je: ";
    auto k = *std::max_element(kugle.begin(), kugle.end(),
    [](std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2) {
        return k1->DajPovrsinu() < k2->DajPovrsinu();
    });

    k->Ispisi();
    bool presjek = false;
    auto it = kugle.begin();
    std::for_each(kugle.begin(), kugle.end(), [&kugle, &presjek, &it](std::shared_ptr<Kugla> k1) {
        std::for_each(it, kugle.end(), [k1, &presjek](std::shared_ptr<Kugla> k2) {
            if(k1!=k2) {
                if(DaLiSeSijeku(*k1,*k2)) {
                    presjek = true;
                    std::cout << "Presjecaju se kugle: ";
                    k1->Ispisi();
                    k2->Ispisi();
                }
            }
        });
        it++;
    });
    if(!presjek) {
        std::cout << "Ne postoje kugle koje se presjecaju!";
    }

    return 0;
}