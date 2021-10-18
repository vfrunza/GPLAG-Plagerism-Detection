/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>

const double epsilon=pow(10,-10);

class Kugla
{
    double x, y, z, r;
public:
    explicit Kugla(double r = 0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::r=r;
        Kugla::x=0;
        Kugla::y=0;
        Kugla::z=0;
    }
    Kugla(double x, double y, double z, double r = 0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::r=r;
        Kugla::x=x;
        Kugla::y=y;
        Kugla::z=z;
    }
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::r=r;
        Kugla::x=std::get<0>(centar);
        Kugla::y=std::get<1>(centar);
        Kugla::z=std::get<2>(centar);
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
    std::tuple<double, double, double> DajCentar() const {      //Provjeriti
        return std::tie(x,y,z);
    }
    double DajPoluprecnik() const {
        return r;
    }
    double DajPovrsinu() const {
        return 16*r*r*atan(1);
    }
    double DajZapreminu() const {
        return (16*r*r*r*atan(1))/3;
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
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::r=r;
        return *this;
    }
    void Ispisi() const {
        std::cout << "{" << "(" << x << "," << y << "," << z << ")," << r << "}" << std::endl;
    }
    void Transliraj(double delta_x, double delta_y, double delta_z) {
        Kugla::x+=delta_x;
        Kugla::y+=delta_y;
        Kugla::z+=delta_z;
    }

    bool DaLiSadrzi(const Kugla &k) const {
        double manji, veci;
        if(r<k.r) manji=r, veci=k.r;
        else manji=k.r, veci=r;
        if(RastojanjeCentara(k,*this)+manji<veci) return true;
        return false;
    }

    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);
};

bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2)
{
    if(fabs(k1.x-k2.x)<epsilon*(fabs(k1.x)+fabs(k2.x)) && fabs(k1.y-k2.y)<epsilon*(fabs(k1.y)+fabs(k2.y)) && fabs(k1.z-k2.z)<epsilon*(fabs(k1.z)+fabs(k2.z)) && fabs(k1.r-k2.r)<epsilon*(fabs(k1.r)+fabs(k2.r))) return true;
    return false;
}

bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2)
{
    if(fabs(k1.r-k2.r)<epsilon*(fabs(k1.r)+fabs(k2.r))) return true;
    return false;
}

bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2)
{
    if(fabs(k1.x-k2.x)<epsilon*(fabs(k1.x)+fabs(k2.x)) && fabs(k1.y-k2.y)<epsilon*(fabs(k1.y)+fabs(k2.y)) && fabs(k1.z-k2.z)<epsilon*(fabs(k1.z)+fabs(k2.z))) return true;
    return false;
}

bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2)
{
    if(fabs(RastojanjeCentara(k1,k2)-k1.r-k2.r)<epsilon*(fabs(RastojanjeCentara(k1,k2))+fabs(k1.r+k2.r))) return true;
    return false;
}

bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2)
{
    double manji, veci;
    if(k1.r<k2.r) manji=k1.r, veci=k2.r;
    else manji=k2.r, veci=k1.r;
    if(fabs(RastojanjeCentara(k1,k2)-veci+manji)<epsilon*(fabs(RastojanjeCentara(k1,k2))+fabs(veci-manji))) return true;
    return false;
}

bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2)
{
    if(DaLiSeSijeku(k1,k2) || k1.DaLiSadrzi(k1) || k2.DaLiSadrzi(k2)) return true;
    return false;
}

bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2)
{
    if(RastojanjeCentara(k1,k2)<k1.r+k2.r && (!k1.DaLiSadrzi(k2) || !k2.DaLiSadrzi(k1)) && !DaLiSeDodirujuIznutra(k1,k2)) return true;
    return false;
}

double RastojanjeCentara(const Kugla &k1, const Kugla &k2)
{
    return sqrt((k1.x-k2.x)*(k1.x-k2.x) + (k1.y-k2.y)*(k1.y-k2.y) + (k1.z-k2.z)*(k1.z-k2.z));
}

int main ()
{

    int n;
    std::cout << "Unesite broj kugla: ";
    while(true) {
        try {
            std::cin >> n;
            if(!std::cin || n<=0) {
                std::cin.clear();
                std::cin.ignore(100000,'\n');
                throw std::domain_error("Neispravan broj kugli, unesite ponovo!");
            }
            break;
        } catch(std::domain_error izuzetak) {
            std::cout << izuzetak.what() << std::endl;
        }
    }


    double x, y, z, r;
    std::vector<std::shared_ptr<Kugla>> kugle(n);
    for(int i=0; i<n; i++) {
        try {
            std::cout << "Unesite centar "  << i+1 << ". kugle: ";
            std::cin >> x;
            if(!std::cin) {
                std::cin.clear();
                std::cin.ignore(100000,'\n');
                throw std::domain_error("Neispravan centar");
            }
            std::cin >> y;
            if(!std::cin) {
                std::cin.clear();
                std::cin.ignore(100000,'\n');
                throw std::domain_error("Neispravan centar");
            }
            std::cin >> z;
            if(!std::cin) {
                std::cin.clear();
                std::cin.ignore(100000,'\n');
                throw std::domain_error("Neispravan centar");
            }
            std::cout << "Unesite poluprecnik " << i+1 << ". kugle: ";
            std::cin >> r;
            if(!std::cin) {
                std::cin.clear();
                std::cin.ignore(100000,'\n');
                throw std::domain_error("Ilegalan poluprecnik");
            }
            kugle[i]=std::make_shared<Kugla>(x,y,z,r);
        } catch(std::domain_error izuzetak) {
            std::cout << izuzetak.what() << std::endl;
            i--;
        }
    }

    double delta_x, delta_y, delta_z;
    std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    while(true) {
        try {
            std::cin >> delta_x >> delta_y >> delta_z;
            if(!std::cin) {
                std::cin.clear();
                std::cin.ignore(100000,'\n');
                throw std::domain_error("Neispravni parametri translacije, unesite ponovo!");
            }
            break;
        } catch(std::domain_error izuzetak) {
            std::cout << izuzetak.what() << std::endl;
        }
    }
    
    for(int i=0; i<kugle.size(); i++) {
        kugle[i]->Transliraj(delta_x,delta_y,delta_z);
    }
    
    std::sort(kugle.begin(), kugle.end(), [](std::shared_ptr<Kugla> a, std::shared_ptr<Kugla> b) {
        return a->DajZapreminu()<b->DajZapreminu();
    });

    std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: " << std::endl;
    std::for_each(kugle.begin(), kugle.end(), [](std::shared_ptr<Kugla> a) {
        return a->Ispisi();
    });

    auto max(std::max_element(kugle.begin(), kugle.end(), [](std::shared_ptr<Kugla> a, std::shared_ptr<Kugla> b) {
        return a->DajPovrsinu()<b->DajPovrsinu();
    }));
    std::cout << "Kugla sa najvecom povrsinom je: ";
    (*max)->Ispisi();

    bool ispisano(false);
    for(int i=0; i<kugle.size(); i++) {
        for(int j=i+1; j<kugle.size(); j++) {
            if(DaLiSeSijeku(*kugle[i],*kugle[j])) {
                ispisano=true;
                std::cout << "Presjecaju se kugle: ";
                kugle[i]->Ispisi();
                kugle[j]->Ispisi();
            }
        }
    }
    if(!ispisano) std::cout << "Ne postoje kugle koje se presjecaju!";

    return 0;
}

