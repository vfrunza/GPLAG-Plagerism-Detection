/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <utility>
#include <cmath>
#include <stdexcept>
#include <tuple>
#include <vector>
#include <memory> 
#include <algorithm>


class Kugla
{
    double x,y,z,r;
    static bool Jednaki(double x, double y);
    static bool StraniceTrougla(double a, double b, double c);

public:
    explicit Kugla(double r);
    Kugla (double x, double y, double z, double r);
    explicit Kugla(const std::tuple<double, double, double> &centar, double r);
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
 
Kugla::Kugla(double r = 0) : x(0), y(0), z(0)
{
    PostaviPoluprecnik(r);
}

Kugla::Kugla (double x, double y, double z, double r = 0) : x(x), y(y), z(z)
{
    PostaviPoluprecnik(r);
}

Kugla::Kugla(const std::tuple<double, double, double> &centar, double r = 0)
{
    std::tie(x,y,z) = centar;
    PostaviPoluprecnik(r);
}

double Kugla::DajX() const
{
    return x;
}

double Kugla::DajY() const
{
    return y;
}

double Kugla::DajZ() const
{
    return z;
}

std::tuple<double, double, double> Kugla::DajCentar() const
{
    return std::make_tuple(x,y,z);
}

double Kugla::DajPoluprecnik() const
{
    return r;
}

double Kugla::DajPovrsinu() const
{
    return 4*4*atan(1)*r*r;
}

double Kugla::DajZapreminu() const
{
    return (4./3)*4*atan(1)*r*r*r;
}

Kugla& Kugla::PostaviX(double x)
{
    Kugla::x = x;
    return *this;
}

Kugla& Kugla::PostaviY(double y)
{
    Kugla::y = y;
    return *this;
}

Kugla& Kugla::PostaviZ(double z)
{
    Kugla::z = z;
    return *this;
}

Kugla& Kugla::PostaviCentar(double x, double y, double z)
{
    PostaviX(x);
    PostaviY(y);
    PostaviZ(z);
    return *this;
}

Kugla& Kugla::PostaviCentar(const std::tuple<double, double, double> &centar)
{
    std::tie(x,y,z) = centar;
    return *this;
}
 
Kugla& Kugla::PostaviPoluprecnik(double r)
{
    if(r < 0) throw std::domain_error ("Ilegalan poluprecnik");
    Kugla::r = r;
    return *this;
}

void Kugla::Ispisi() const
{
    std::cout << "{(" << x << "," << y << "," << z << ")," << r << "}" << std::endl;
}

void Kugla::Transliraj(double delta_x, double delta_y, double delta_z)
{
    PostaviX(x+delta_x);
    PostaviY(y+delta_y);
    PostaviZ(z+delta_z);
}

bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2)
{
    return (Kugla::Jednaki(k1.x, k2.x) && Kugla::Jednaki(k1.y, k2.y) &&
            Kugla::Jednaki(k1.z, k2.z) && Kugla::Jednaki(k1.r, k2.r));
}

bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2)
{
    return Kugla::Jednaki(k1.r, k2.r);
}

bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2)
{
    return (Kugla::Jednaki(k1.x, k2.x) && Kugla::Jednaki(k1.y, k2.y) &&
            Kugla::Jednaki(k1.z, k2.z));
}

bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2)
{
    return Kugla::Jednaki(RastojanjeCentara(k1,k2),k1.r + k2.r);
}

bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2)
{
    return Kugla::Jednaki(RastojanjeCentara(k1,k2), fabs(k1.r-k2.r));
}
bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2)
{
    if(k1.DaLiSadrzi(k2) || k2.DaLiSadrzi(k1)) return true;
    return DaLiSeSijeku(k1,k2);
}

bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2)
{
    return !DaLiSuIdenticne(k1,k2) && !DaLiSeDodirujuIzvana(k1,k2) && !DaLiSeDodirujuIznutra(k1,k2) && Kugla::StraniceTrougla(RastojanjeCentara(k1,k2), k1.r, k2.r);
}

bool Kugla::DaLiSadrzi(const Kugla &k) const
{
    return RastojanjeCentara(*this, k) + r < k.r || Kugla::Jednaki(RastojanjeCentara(*this, k) + r, k.r);
}

double RastojanjeCentara(const Kugla &k1, const Kugla &k2)
{
    double x1,y1,z1,x2,y2,z2;
    std::tie(x1,y1,z1) = k1.DajCentar();
    std::tie(x2,y2,z2) = k2.DajCentar();
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) + (z2-z1)*(z2-z1));
}

bool Kugla::Jednaki(double x, double y)
{
    return (fabs(x-y) <= pow(10, -10) * (fabs(x) + fabs(y)));
}

bool Kugla::StraniceTrougla(double a, double b, double c)
{
    return a + b > c && a + c > b && b + c > a;
}

typedef std::shared_ptr<Kugla> PokNaKuglu;

int main ()
{
    std::cout << "Unesite broj kugla: ";
    int broj_kugli;
    for(;;) {
        std::cin >> broj_kugli;
        if(!std::cin || broj_kugli<=0 ) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Neispravan broj kugli, unesite ponovo!" << std::endl;
        } else break;
    }
    std::vector<PokNaKuglu> kugle;
    for(int i=0; i<broj_kugli; i++) {
        double x,y,z;
        std::cout << "Unesite centar " << i+1<< ". kugle: ";
        std::cin >> x >> y >> z;
        if(!std::cin ) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Neispravan centar" << std::endl;
            i--;
            continue;
        }
        double r;
        std::cout << "Unesite poluprecnik " << i+1 << ". kugle: ";
        std::cin >> r;
        if(!std::cin || r<0 ) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Ilegalan poluprecnik" << std::endl;
            i--;
            continue;
        }
        PokNaKuglu pok_na_kuglu(std::make_shared<Kugla>(Kugla(x,y,z,r)));
        kugle.push_back(pok_na_kuglu);

    }

    std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double delta_x, delta_y, delta_z;
    for(;;) {
        std::cin >> delta_x >> delta_y >> delta_z;
        if(!std::cin ) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Neispravni parametri translacije, unesite ponovo!" << std::endl;
        } else break;
    }


    std::transform(kugle.begin(), kugle.end(), kugle.begin(), [delta_x, delta_y, delta_z](PokNaKuglu pok_na_kuglu) {
        pok_na_kuglu->Transliraj(delta_x, delta_y, delta_z);
        return pok_na_kuglu;
    });


    std::sort(kugle.begin(), kugle.end(), [](PokNaKuglu p1, PokNaKuglu p2) {
        return p1->DajZapreminu() < p2->DajZapreminu();
    });

    std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: " << std::endl;
    std::for_each(kugle.begin(), kugle.end(), [](PokNaKuglu pok_na_kuglu) {
        pok_na_kuglu->Ispisi();
    });


    auto it(std::max_element(kugle.begin(), kugle.end(), [](PokNaKuglu p1, PokNaKuglu p2) {
        return p1->DajPovrsinu() < p2->DajPovrsinu();
    }));


    std::cout << "Kugla sa najvecom povrsinom je: ";
    (*it)->Ispisi();

    bool postoji(false);
    auto iter(kugle.begin());
    std::for_each(kugle.begin(), kugle.end(), [&kugle, &postoji, &iter](PokNaKuglu p1) {
        std::for_each(iter, kugle.end(), [p1, &postoji](PokNaKuglu p2) {
            if(DaLiSeSijeku(*p1, *p2) && p1!=p2) {
                std::cout << "Presjecaju se kugle: ";
                p1->Ispisi();
                p2->Ispisi();
                postoji = true;
            }
        });
        iter++;
    });

    if(postoji == false)
        std::cout << "Ne postoje kugle koje se presjecaju!" << std::endl;

    return 0;
}
