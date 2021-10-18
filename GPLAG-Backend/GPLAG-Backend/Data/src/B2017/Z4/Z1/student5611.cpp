/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <tuple>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>



class Kugla
{
    double x, y, z, r;
    static bool Sadrzi(const Kugla &k1, const Kugla &k2);
    static bool DaLiSuJednaki(double prvi, double drugi);
public:
    explicit Kugla(double poluprecnik); 
    Kugla(double x, double y, double z, double r); 
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

Kugla::Kugla (double poluprecnik = 0)
{
    if(r<0) throw std::domain_error ("Ilegalan poluprecnik");
    r = poluprecnik;
    x = 0;
    y = 0;
    z = 0;
}

Kugla::Kugla(double x, double y, double z, double r = 0)
{
    if(r<0) throw std::domain_error ("Ilegalan poluprecnik");
    Kugla::r = r;
    Kugla::x = x;
    Kugla::y = y;
    Kugla::z = z;
}

Kugla::Kugla(const std::tuple<double, double, double> &centar, double r = 0)
{
    if(r<0) throw std::domain_error ("Ilegalan poluprecnik");
    Kugla::x = std::get<0>(centar);
    Kugla::y = std::get<1>(centar);
    Kugla::z = std::get <2>(centar);
    Kugla::r = r;
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
    return std::make_tuple(x, y, z);
}

double Kugla::DajPoluprecnik() const
{
    return r;
}

double Kugla::DajPovrsinu() const
{
    return 16*atan(1)*r*r;
}

double Kugla::DajZapreminu() const
{
    return (4./3.)*r*r*r*atan(1)*4.;
}

Kugla & Kugla::PostaviX(double x)
{
    Kugla::x = x;
    return *this;
}

Kugla & Kugla::PostaviY(double y)
{
    Kugla::y = y;
    return *this;
}

Kugla & Kugla::PostaviZ(double z)
{
    Kugla::z = z;
    return *this;
}

Kugla & Kugla::PostaviCentar(double x, double y, double z)
{
    Kugla::x = x;
    Kugla::y = y;
    Kugla::z = z;
    return *this;
}

Kugla & Kugla::PostaviCentar(const std::tuple<double, double, double> &centar)
{
    Kugla::x = std::get<0>(centar);
    Kugla::y = std::get<1>(centar);
    Kugla::z = std::get<2>(centar);
    return *this;
}

Kugla & Kugla::PostaviPoluprecnik(double r)
{
    if(r<0) throw std::domain_error ("Ilegalan poluprecnik"); 
    Kugla::r = r;
    return *this;
}

void Kugla::Ispisi() const
{
    std::cout << "{(" << DajX() << "," << DajY() << "," << DajZ() << ")," << DajPoluprecnik() << "}" << std::endl;
}

void Kugla::Transliraj(double delta_x, double delta_y, double delta_z)
{
    PostaviX(delta_x+x);
    PostaviY(delta_y+y);
    PostaviZ(delta_z+z);
}

bool Kugla::DaLiSuJednaki( double prvi, double drugi) {
    return (fabs(prvi-drugi) <= pow(10,-10)*(fabs(prvi)+fabs(drugi)));
}

bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2)
{
    return Kugla::DaLiSuJednaki(k1.x,k2.x) && Kugla::DaLiSuJednaki(k1.y,k2.y) && Kugla::DaLiSuJednaki(k1.z,k2.z) && Kugla::DaLiSuJednaki(k1.r,k2.r);
}

bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2)
{
    return Kugla::DaLiSuJednaki(k1.r,k2.r);
}

bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2)
{
    return Kugla::DaLiSuJednaki(k1.x,k2.x) && Kugla::DaLiSuJednaki(k1.y,k2.y) && Kugla::DaLiSuJednaki(k1.z,k2.z);
}

bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2)
{
    return Kugla::DaLiSuJednaki(RastojanjeCentara(k1,k2),k1.r+k2.r);
}

bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2)
{
    return Kugla::DaLiSuJednaki(RastojanjeCentara(k1,k2),fabs(k1.r-k2.r));
}

bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2)
{
    double temp(RastojanjeCentara(k1,k2));
    if(k1.r+k2.r>temp && temp+k2.r>k1.r && temp+k1.r>k2.r && !DaLiSuIdenticne(k1,k2) && !DaLiSeDodirujuIznutra(k1,k2) && !(DaLiSeDodirujuIzvana(k1,k2))) return true;
    return false;
}

double RastojanjeCentara(const Kugla &k1, const Kugla &k2)
{
    return sqrt((k1.x-k2.x)*(k1.x-k2.x) + (k1.y-k2.y)*(k1.y-k2.y) + (k1.z-k2.z)*(k1.z-k2.z));
}

bool Kugla::DaLiSadrzi(const Kugla &k) const
{
    return (Kugla::DaLiSuJednaki(k.r, RastojanjeCentara(*this,k)+r) || RastojanjeCentara(k,*this) + r < k.r);
}

bool Kugla::Sadrzi(const Kugla &k1, const Kugla &k2)
{
    return (k1.r+k2.r>RastojanjeCentara(k1,k2)) && k1.r > 2*k2.r;
}

bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2)
{
    return DaLiSeSijeku(k1,k2) || Kugla::Sadrzi(k1,k2) || Kugla::Sadrzi(k2,k1);
}


typedef std::shared_ptr<Kugla> pametni_pok;

int main ()
{

    std::cout << "Unesite broj kugla: ";
    int br_kugli;
    std::cin >> br_kugli;
    while(br_kugli <= 0 || !std::cin || std::cin.peek() != '\n') {
        std::cout << "Neispravan broj kugli, unesite ponovo!" << std::endl;
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cin >> br_kugli;
    }

    std::vector<std::shared_ptr<Kugla>> pokazivaci;
    int brojac(0);

    while(br_kugli != 0) {
        brojac++;
        
        double x, y, z;
        std::cout << "Unesite centar " << brojac << ". kugle: ";
        std::cin >> x >> y >> z;
        if(!std::cin) {
            std::cout << "Neispravan centar" << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            brojac--;
            continue;
        }

        double r;
        std::cout << "Unesite poluprecnik " << brojac << ". kugle: ";
        std::cin >> r;
        if(r<0 || !std::cin) {
            std::cout << "Ilegalan poluprecnik" << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            brojac--;
            continue;
        }

        Kugla kugla(x,y,z,r);
        std::shared_ptr<Kugla> pomocni(std::make_shared<Kugla> (kugla));
        pokazivaci.push_back(pomocni);
        
        br_kugli--;
    }

    std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double delta_x, delta_y, delta_z;
    for(;;) {
        std::cin >> delta_x >> delta_y >> delta_z;
        if(!std::cin) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Neispravni parametri translacije, unesite ponovo!" << std::endl;
        } else break;
    }
    //std::cout << delta_z << " " << delta_y << std::endl;
    std::transform(pokazivaci.begin(), pokazivaci.end(), pokazivaci.begin(),
    [delta_x, delta_y, delta_z] (pametni_pok kugla) {
        kugla->Transliraj(delta_x, delta_y, delta_z);
        return kugla;
    });

    std::sort(pokazivaci.begin(), pokazivaci.end(), [] (pametni_pok kugla_1, pametni_pok kugla_2) {
        return (*kugla_1).DajZapreminu() < (*kugla_2).DajZapreminu();
    });

    std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: " << std::endl;
    std::for_each(pokazivaci.begin(), pokazivaci.end(), [] (pametni_pok kugla) {
        kugla->Ispisi();
    });

    auto max_povrsina = std::max_element(pokazivaci.begin(), pokazivaci.end(), [] (pametni_pok kugla_1, pametni_pok kugla_2) {
        return kugla_1->DajPovrsinu() < kugla_2->DajPovrsinu();
    });

    std::cout << "Kugla sa najvecom povrsinom je: ";
    (*(*max_povrsina)).Ispisi();

    auto pokazivac(pokazivaci.begin());
    bool pronasao(false);
    std::for_each(pokazivaci.begin(), pokazivaci.end(), [&pokazivac, &pokazivaci, &pronasao] (pametni_pok prva) {
        std::for_each(pokazivac, pokazivaci.end(), [&pronasao, prva] (pametni_pok druga) {
            if(prva!=druga && DaLiSeSijeku(*prva, *druga)) {
                pronasao = true;
                std::cout << "Presjecaju se kugle: ";
                (*prva).Ispisi();
                (*druga).Ispisi();
            }
        });
        pokazivac++;
    });

    if(pronasao==false) std::cout << "Ne postoje kugle koje se presjecaju!" << std::endl;
    return 0;
}
