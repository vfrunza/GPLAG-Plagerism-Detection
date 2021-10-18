/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath>
#include <tuple>
#include <cctype>
#include <utility>
#include <algorithm>
#include <memory>
#include <iomanip>

const double PI=4*atan(1);
const double eps(10E-10);
bool provjera=false;

class NepreklapajucaKugla {
double x_pr, y_pr, z_pr, r_pr;
//int brojac_pr=0;
public:    
explicit NepreklapajucaKugla(double r = 0) {
    if(r<0 || !(std::cin)) throw std::domain_error("Ilegalan poluprecnik"); 
    NepreklapajucaKugla::r_pr=r;
    NepreklapajucaKugla::x_pr=0;
    NepreklapajucaKugla::y_pr=0;
    NepreklapajucaKugla::z_pr=0;
}
NepreklapajucaKugla(double x, double y, double z, double r = 0) {
    if(r<0 || !(std::cin)) throw std::domain_error("Ilegalan poluprecnik");
    NepreklapajucaKugla::r_pr=r;
    NepreklapajucaKugla::x_pr=x;
    NepreklapajucaKugla::y_pr=y;
    NepreklapajucaKugla::z_pr=z;
}
explicit NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r = 0) {
    if(r<0 || !(std::cin)) throw std::domain_error("Ilegalan poluprecnik");
    NepreklapajucaKugla::r_pr=r;
    NepreklapajucaKugla::x_pr=std::get<0>(centar);
    NepreklapajucaKugla::y_pr=std::get<1>(centar);
    NepreklapajucaKugla::z_pr=std::get<2>(centar);
}
//int DajBrojac() const {return brojac_pr;}
double DajX() const {return this->x_pr;}
double DajY() const {return this->y_pr;}
double DajZ() const {return this->z_pr;}
std::tuple<double, double, double> DajCentar() const {return std::make_tuple(x_pr, y_pr, z_pr);}
double DajPoluprecnik() const {return r_pr;}
double DajPovrsinu() const {return (4*PI*r_pr*r_pr);}
double DajZapreminu() const {return ((4./3)*(PI*r_pr*r_pr*r_pr));}
NepreklapajucaKugla &PostaviX(double x) {NepreklapajucaKugla::x_pr=x; return *this;}
NepreklapajucaKugla &PostaviY(double y) {NepreklapajucaKugla::y_pr=y; return *this;}
NepreklapajucaKugla &PostaviZ(double z) {NepreklapajucaKugla::z_pr=z; return *this;}
NepreklapajucaKugla &PostaviCentar(double x, double y, double z) {
    NepreklapajucaKugla::x_pr=x;
    NepreklapajucaKugla::y_pr=y;
    NepreklapajucaKugla::z_pr=z;
    return *this;
}
NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar) {
    NepreklapajucaKugla::x_pr=std::get<0>(centar);
    NepreklapajucaKugla::y_pr=std::get<1>(centar);
    NepreklapajucaKugla::z_pr=std::get<2>(centar);
    return *this;
}
NepreklapajucaKugla &PostaviPoluprecnik(double r) {
    if(r<0 || !(std::cin)) throw std::domain_error("Ilegalan poluprecnik");
    NepreklapajucaKugla::r_pr=r;
    return *this;
}  
void Ispisi() const {std::cout << "{(" << x_pr << "," << y_pr << "," << z_pr << ")," << r_pr << "}";};
void Transliraj(double delta_x, double delta_y, double delta_z) {
    this->x_pr+=delta_x;
    this->y_pr+=delta_y;
    this->z_pr+=delta_z;
}
bool DaLiSadrzi(const NepreklapajucaKugla &k) const {
    if(RastojanjeCentara(*this, k)+k.NepreklapajucaKugla::DajPoluprecnik()<r_pr) return true;
    return false;
}
friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);  
};

double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2) {
    return (sqrt(((k1.NepreklapajucaKugla::DajX()-k2.NepreklapajucaKugla::DajX())*(k1.NepreklapajucaKugla::DajX()-k2.NepreklapajucaKugla::DajX())) + ((k1.NepreklapajucaKugla::DajY()-k2.NepreklapajucaKugla::DajY())*(k1.NepreklapajucaKugla::DajY()-k2.NepreklapajucaKugla::DajY())) + ((k1.NepreklapajucaKugla::DajZ()-k2.NepreklapajucaKugla::DajZ())*(k1.NepreklapajucaKugla::DajZ()-k2.NepreklapajucaKugla::DajZ()))));
}

int main () {
    std::cout << "Unesite broj kugli: ";
    int n;
    std::cin >> n;
    while((n<=0) || (!std::cin)) {
        std::cout << ("Neispravan broj kugli, unesite ponovo!") << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cin >> n;
    }
    std::vector<std::shared_ptr<NepreklapajucaKugla>>kugle;
    kugle.resize(n);
    for(int i=0; i<n; i++) {
        std::cout << "Unesite centar " << i+1 << ". kugle: ";
        double x, y, z, r;
        std::cin >> x >> y >> z;
        while(!std::cin) {
            std::cout << "Neispravan centar" << std::endl;
            std::cout << "Unesite centar, unesite ponovo: ";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cin >> x >> y >> z;
        }
        std::cout << "Unesite poluprecnik: ";
        std::cin >> r;
        while(!std::cin) {
            std::cout << "Neispravan poluprecnik, unesite ponovo:" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cin >> r;
        }
        try {
            kugle[i]=std::make_shared<NepreklapajucaKugla>(NepreklapajucaKugla{x, y, z, r});
        }catch(std::domain_error jedan) {
            std::cout << jedan.what() << std::endl;
            i--;
        }
    }
    
    std::sort(kugle.begin(), kugle.end(), [](std::shared_ptr<NepreklapajucaKugla>a, std::shared_ptr<NepreklapajucaKugla>b){return a->DajZapreminu()<b->DajZapreminu();});
    
    std::cout << "Kugle nakon obavljenog sortiranja:" << std::endl;
    std::for_each(kugle.begin(), kugle.end(), [](std::shared_ptr<NepreklapajucaKugla>temp) {
        temp->Ispisi();
        std::cout << std::endl;
    });
    
	return 0;
}
