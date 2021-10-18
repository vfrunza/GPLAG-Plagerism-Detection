#include <iostream>
#include <tuple>
#include <cmath>
#include <stdexcept>
#include <memory>
#include <vector>
#include <algorithm>

const double pi (4*std::atan(1.));
const double eps(1e-10);

class Kugla
{
    double x, y, z, r;

public:

    explicit Kugla(double r = 0) : r(r) {
        if(r < 0) throw std::domain_error("Ilegalan poluprecnik");
        x = 0;
        y = 0;
        z = 0;
    }

    Kugla (double x, double y, double z, double r = 0) : x(x), y(y), z(z), r(r) {
        if(r < 0) throw std::domain_error("Ilegalan poluprecnik");
    }

    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0) :  r(r) {
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
        auto t(std::tie(x,y,z));
        return t;
    }

    double DajPoluprecnik() const {
        return r;
    }


    double DajPovrsinu() const {
        return 4*DajPoluprecnik()*pi;
    }

    double DajZapreminu() const {
        return (4*r*r*r*pi)/3.;
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
    Kugla &PostaviCentar(const std::tuple<double, double, double>&centar ) {
        Kugla::x = std::get<0>(centar);
        Kugla::y = std::get<1>(centar);
        Kugla::z = std::get<2>(centar);
        return *this;
    }
    Kugla &PostaviPoluprecnik(double r) {
        if(r < 0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::r = r;
        return *this;
    }
    void Ispisi() const {
        std::cout<<"{("<<DajX()<<","<<DajY()<<","<<DajZ()<<"),"<<DajPoluprecnik()<<"}"<<std::endl;
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
    bool DaLiSadrzi(const Kugla &k) const;
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);

};

bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2)
{
    return (std::fabs(k1.x - k2.x) < eps*(fabs(k1.x) + fabs(k2.x))) && (std::fabs(k1.y - k2.y) < eps*(fabs(k1.y) + fabs(k2.y))) && (std::fabs(k1.z - k2.z) < eps*(fabs(k1.z) + fabs(k2.z))) && (std::fabs(k1.r - k2.r) < eps*(fabs(k1.r) + fabs(k2.r)));
}

bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2)
{
    return (std::fabs(k1.r - k2.r) < eps*(fabs(k1.r) + fabs(k2.r)));
}
bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2)
{
    return (std::fabs(k1.x - k2.x) < eps*(fabs(k1.x) + fabs(k2.x))) && (std::fabs(k1.y - k2.y) < eps*(fabs(k1.y) + fabs(k2.y))) && (std::fabs(k1.z - k2.z) < eps*(fabs(k1.z) + fabs(k2.z)));
}

bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2)
{
    double zbirpoluprecnika(0), udaljenostcentara(0);
    zbirpoluprecnika = k1.r + k2. r;
    udaljenostcentara = RastojanjeCentara(k1,k2);
    if(std::fabs(zbirpoluprecnika - udaljenostcentara) < eps*(fabs(zbirpoluprecnika) + fabs(udaljenostcentara))) return true;
    return false;
}

bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2)
{
    double rastojanje = RastojanjeCentara(k1,k2);
    double r1 = rastojanje + k1.r;
    double r2 = rastojanje + k2.r;
    bool dodir(false);
    if(k1.r < k2.r) {
        if( fabs(r1 - k2.r) < eps*(fabs(r1) + fabs(k2.r))) dodir = true;
        //if(rastojanje + k1.r == k2.r) dodir = true;
    } else if( k2.r < k1.r) {
        if(fabs(r2 - k1.r) < eps*(fabs(r2) + fabs(k1.r))) dodir = true;
        //if(rastojanje + k2.r == k1.r) dodir = true;
    }
    return dodir;
}
bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2)
{
    if(DaLiSeSijeku(k1,k2) || DaLiSuIdenticne(k1,k2) || DaLiSuKoncentricne(k1,k2) || k1.DaLiSadrzi(k2) || k2.DaLiSadrzi(k1)) return true;
    return false;
}
bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2)
{
    if(DaLiSuKoncentricne(k1,k2)) return false;
    double udaljenostcentara(RastojanjeCentara(k1,k2));
    return (udaljenostcentara < k1.r + k2.r && udaljenostcentara > fabs(k1.r - k2.r));
}

bool Kugla::DaLiSadrzi(const Kugla &k) const
{
    if( k.r > this->r) return false;
    else if(RastojanjeCentara(k,*this) + k.r <= this->r) return true; //ako je rastojanje izmedju centara te dvije kugle manje od poluprecnika vece, sadrzi je

    else if( DaLiSuKoncentricne(k,*this) && k.r < this->r) return true; // ako su koncentricne i ako je radijus sadrzane manji
    else if(DaLiSuIdenticne(k,*this)) return true; //ako je to ta ista sfera, sve tacke se sadrze
    return false;
}

double RastojanjeCentara(const Kugla &k1, const Kugla &k2)
{
    return std::sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z));
}

int main ()
{
    std::cout<<"Unesite broj kugla: ";
    int n;
    std::cin>>n;
    std::vector<std::shared_ptr<Kugla>>kugle(n);

    bool greska(true);

    for(int i = 0; i < kugle.size(); i++) {
        greska = true;
        std::shared_ptr<Kugla>pok;
        while(greska) {
            try {
                double x,y,z,r;

                std::cout<<"Unesite centar "<<i + 1<<". kugle: ";
                std::cin>>x>>y>>z;
                std::cout<<"Unesite poluprecnik "<<i + 1<<". kugle: ";
                std::cin>>r;
                if(!std::cin || r < 0) throw std::domain_error("Ilegalan poluprecnik");

                pok = (std::make_shared<Kugla>(x,y,z,r));

                kugle[i] = pok;
                greska = false;

            } catch(std::domain_error e) {
                std::cout<<e.what()<<std::endl;
                std::cin.clear();
                std::cin.ignore(1000,'\n');

            }
        }
    }
    std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double delta_x, delta_y, delta_z;
    std::cin>>delta_x>>delta_y>>delta_z;
    std::transform(kugle.begin(), kugle.end(), kugle.begin(), [delta_x, delta_y, delta_z](std::shared_ptr<Kugla> k) {
        k->Transliraj(delta_x, delta_y, delta_z);
        return k;
    });

    std::sort(kugle.begin(), kugle.end(), [](const std::shared_ptr<Kugla> &k1, const std::shared_ptr<Kugla> &k2) {
        return k1->DajZapreminu() < k2->DajZapreminu();
    });
    std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: " << std::endl;
    std::for_each(kugle.begin(), kugle.end(), [](const std::shared_ptr<Kugla> &k) {
        k->Ispisi();
    });

    auto pok = std::max_element(kugle.begin(), kugle.end(), [](const std::shared_ptr<Kugla>&k1, const std::shared_ptr<Kugla>&k2) {
        return k1->DajPovrsinu() < k2->DajPovrsinu();
    });
    std::cout << "Kugla sa najvecom povrsinom je: ";
    (*pok)->Ispisi();

    bool postoji(false);
    std::for_each(kugle.begin(), kugle.end(), [kugle, &postoji] (const std::shared_ptr<Kugla> &k) {
        auto it = std::find(kugle.begin(), kugle.end(), k);
        int pozicija = it - kugle.begin();
        std::for_each(kugle.begin() + pozicija + 1, kugle.end(), [k, &postoji] (const std::shared_ptr<Kugla> &k2) {
            if(DaLiSeSijeku(*k, *k2)) {
                postoji = true;
                std::cout<<"Presjecaju se kugle: ";
                k->Ispisi();
                k2->Ispisi();
            }
        });
    });
    if(postoji == false) std::cout<<"Ne postoje kugle koje se presjecaju!";
    return 0;
}
