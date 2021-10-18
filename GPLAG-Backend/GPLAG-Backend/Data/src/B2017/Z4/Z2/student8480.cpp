/B2017/2018: Zadaća 4, Zadatak 2
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

class NepreklapajucaKugla
{
private:
    double x, y, z, r;
    NepreklapajucaKugla *posljednja;
    bool Preklapanje(double x, double y, double z, double r);
    void Postavi(double x, double y, double z, double r);
public:
    static NepreklapajucaKugla *zadnja;
    explicit NepreklapajucaKugla(double r = 0);
    NepreklapajucaKugla(double x, double y, double z, double r = 0);
    explicit NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r = 0);
    NepreklapajucaKugla(const NepreklapajucaKugla &kugla) = delete;
    NepreklapajucaKugla &operator =(const NepreklapajucaKugla &kugla) = delete;
    ~NepreklapajucaKugla();
    double DajX() const;
    double DajY() const;
    double DajZ() const;
    std::tuple<double, double, double> DajCentar() const;
    double DajPoluprecnik() const;
    double DajPovrsinu() const;
    double DajZapreminu() const;
    NepreklapajucaKugla &PostaviX(double x);
    NepreklapajucaKugla &PostaviY(double y);
    NepreklapajucaKugla &PostaviZ(double z);
    NepreklapajucaKugla &PostaviCentar(double x, double y, double z);
    NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar);
    NepreklapajucaKugla &PostaviPoluprecnik(double r);
    void Ispisi() const;
    void Transliraj(double delta_x, double delta_y, double delta_z);
    friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
};
NepreklapajucaKugla *NepreklapajucaKugla::zadnja = nullptr;
bool NepreklapajucaKugla::Preklapanje(double x, double y, double z, double r)
{
    auto kugla = zadnja;
    double d;
    while(kugla) {
        d = std::sqrt(std::pow(kugla->DajX()-x,2) +
                      std::pow(kugla->DajY()-y,2) +
                      std::pow(kugla->DajZ()-z,2));

        if(kugla==this) {
            kugla = kugla->posljednja;
            continue;
        }
        if(d<=kugla->DajPoluprecnik()+r) return true;
        kugla = kugla->posljednja;
    }
    return false;
}
void NepreklapajucaKugla::Postavi(double x, double y, double z, double r)
{
    if(!Preklapanje(x,y,z,r)) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->r = r;
        return;
    } else throw std::logic_error("Nedozvoljeno preklapanje");
}
NepreklapajucaKugla::NepreklapajucaKugla(double r) : NepreklapajucaKugla(0,0,0,r) {}
NepreklapajucaKugla::NepreklapajucaKugla(double x, double y, double z, double r)
{
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    if(!Preklapanje(x,y,z,r)) {
        if(!zadnja) {
            zadnja=this;
            posljednja=nullptr;
        } else {
            posljednja = zadnja;
            zadnja = this;
        }

        this->x = x;
        this->y = y;
        this->z = z;
        this->r = r;
    } else throw std::logic_error("Nedozvoljeno preklapanje");
}
NepreklapajucaKugla::NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r) :
    NepreklapajucaKugla(std::get<0>(centar), std::get<1>(centar), std::get<2>(centar), r) {}
NepreklapajucaKugla::~NepreklapajucaKugla()
{
    if(!posljednja && this==zadnja) {
        zadnja=nullptr;
    } else if(this == zadnja) {
        zadnja = posljednja;
        posljednja = posljednja->posljednja;
    } else {
        auto kugla = zadnja;
        while(kugla->posljednja != this) {
            kugla = kugla->posljednja;
        }
        kugla->posljednja = posljednja;
    }
}
double NepreklapajucaKugla::DajX() const
{
    return this->x;
}
double NepreklapajucaKugla::DajY() const
{
    return this->y;
}
double NepreklapajucaKugla::DajZ() const
{
    return this->z;
}
std::tuple<double, double, double> NepreklapajucaKugla::DajCentar() const
{
    return std::tuple<double, double, double>(this->x, this->y, this->z);
}
double NepreklapajucaKugla::DajPoluprecnik() const
{
    return this->r;
}
double NepreklapajucaKugla::DajPovrsinu() const
{
    return 4*r*r*std::atan(1)*4;
}
double NepreklapajucaKugla::DajZapreminu() const
{
    return (4/3)*r*r*r*std::atan(1)*4;
}
NepreklapajucaKugla &NepreklapajucaKugla::PostaviX(double x)
{
    Postavi(x, y, z, r);
    return *this;
}
NepreklapajucaKugla &NepreklapajucaKugla::PostaviY(double y)
{
    Postavi(x, y, z, r);
    return *this;
}
NepreklapajucaKugla &NepreklapajucaKugla::PostaviZ(double z)
{
    Postavi(x, y, z, r);
    return *this;
}
NepreklapajucaKugla &NepreklapajucaKugla::PostaviCentar(double x, double y, double z)
{
    Postavi(x, y, z, r);
    return *this;
}
NepreklapajucaKugla &NepreklapajucaKugla::PostaviCentar(const std::tuple<double, double, double> &centar)
{
    Postavi(std::get<0>(centar), std::get<1>(centar), std::get<2>(centar), r);
    return *this;
}
NepreklapajucaKugla &NepreklapajucaKugla::PostaviPoluprecnik(double r)
{
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    Postavi(x, y, z, r);
    return *this;
}
void NepreklapajucaKugla::Ispisi() const
{
    std::cout << "{(" << this->x << "," << this->y << "," << this->z << "),"
              << this->r << "}" << std::endl;
    return;
}
void NepreklapajucaKugla::Transliraj(double delta_x, double delta_y, double delta_z)
{
    Postavi(x+delta_x, y+delta_y, z+delta_z, r);
    return;
}
double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2)
{
    return std::sqrt(std::pow(k1.DajX()-k2.DajX(),2) +
                     std::pow(k1.DajY()-k2.DajY(),2) + std::pow(k1.DajZ()-k2.DajZ(),2));
}

int main ()
{
    std::cout << "Unesite broj kugli: ";
    int n;
    std::cin >> n;
    while(!std::cin || n<1) {
        std::cout << "Neispravan broj kugli, unesite ponovo!" << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cin >> n;
    }

    std::vector<std::shared_ptr<NepreklapajucaKugla>> kugle(n);
    double x,y,z,r;
    for(int i=0; i<n; i++) {

        std::cout << "Unesite centar za " << i+1 << ". kuglu: ";
        std::cin >> x >> y >> z;

        while(!std::cin) {
            std::cout << "Neispravan centar, unesite ponovo:" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cin >> x >> y >> z;
        }

        std::cout << "Unesite poluprecnik: ";
        std::cin >> r;
        while(!std::cin || r<0) {
            std::cout << "Neispravan poluprecnik, unesite ponovo:" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cin >> r;
        }

        try {
            kugle[i] = std::make_shared<NepreklapajucaKugla>(x,y,z,r);
        } catch(std::domain_error izuzetak) {
            std::cout << izuzetak.what() << std::endl;
            i--;
        } catch(std::logic_error izuzetak) {
            std::cout << izuzetak.what() << std::endl;
            i--;
        }
    }

    std::sort(kugle.begin(), kugle.end(), [](std::shared_ptr<NepreklapajucaKugla> k1, std::shared_ptr<NepreklapajucaKugla> k2) {
        return k1->DajPovrsinu() < k2->DajPovrsinu();
    });

    std::cout << std::endl;
    std::cout << "Kugle nakon obavljenog sortiranja: " << std::endl;
    std::for_each(kugle.begin(), kugle.end(),[](std::shared_ptr<NepreklapajucaKugla> k) {
        k->Ispisi();
    });

    return 0;
}