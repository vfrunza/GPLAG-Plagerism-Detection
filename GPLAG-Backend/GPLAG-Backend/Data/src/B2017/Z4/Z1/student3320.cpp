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

class Kugla {
double x_pr, y_pr, z_pr, r_pr;
//int brojac_pr=0;
public:    
explicit Kugla(double r = 0) {
    if(r<0 || !(std::cin)) throw std::domain_error("Ilegalan poluprecnik"); 
    Kugla::r_pr=r;
    Kugla::x_pr=0;
    Kugla::y_pr=0;
    Kugla::z_pr=0;
}
Kugla(double x, double y, double z, double r = 0) {
    if(r<0 || !(std::cin)) throw std::domain_error("Ilegalan poluprecnik");
    Kugla::r_pr=r;
    Kugla::x_pr=x;
    Kugla::y_pr=y;
    Kugla::z_pr=z;
}
explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0) {
    if(r<0 || !(std::cin)) throw std::domain_error("Ilegalan poluprecnik");
    Kugla::r_pr=r;
    Kugla::x_pr=std::get<0>(centar);
    Kugla::y_pr=std::get<1>(centar);
    Kugla::z_pr=std::get<2>(centar);
}
//int DajBrojac() const {return brojac_pr;}
double DajX() const {return this->x_pr;}
double DajY() const {return this->y_pr;}
double DajZ() const {return this->z_pr;}
std::tuple<double, double, double> DajCentar() const {return std::make_tuple(x_pr, y_pr, z_pr);}
double DajPoluprecnik() const {return r_pr;}
double DajPovrsinu() const {return (4*PI*r_pr*r_pr);}
double DajZapreminu() const {return ((4./3)*(PI*r_pr*r_pr*r_pr));}
Kugla &PostaviX(double x) {Kugla::x_pr=x; return *this;}
Kugla &PostaviY(double y) {Kugla::y_pr=y; return *this;}
Kugla &PostaviZ(double z) {Kugla::z_pr=z; return *this;}
Kugla &PostaviCentar(double x, double y, double z) {
    Kugla::x_pr=x;
    Kugla::y_pr=y;
    Kugla::z_pr=z;
    return *this;
}
Kugla &PostaviCentar(const std::tuple<double, double, double> &centar) {
    Kugla::x_pr=std::get<0>(centar);
    Kugla::y_pr=std::get<1>(centar);
    Kugla::z_pr=std::get<2>(centar);
    return *this;
}
Kugla &PostaviPoluprecnik(double r) {
    if(r<0 || !(std::cin)) throw std::domain_error("Ilegalan poluprecnik");
    Kugla::r_pr=r;
    return *this;
}  
void Ispisi() const {std::cout << "{(" << x_pr << "," << y_pr << "," << z_pr << ")," << r_pr << "}";};
void Transliraj(double delta_x, double delta_y, double delta_z) {
    this->x_pr+=delta_x;
    this->y_pr+=delta_y;
    this->z_pr+=delta_z;
}
friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2); //
friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2); //
friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2); //
friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2); //**
friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2); //**
friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2); //
friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2); //
bool DaLiSadrzi(const Kugla &k) const {
    if(RastojanjeCentara(*this, k)+k.Kugla::DajPoluprecnik()<r_pr) return true;
    return false;
}
friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);  
};

bool DaLiSuIdenticni(const Kugla &k1, const Kugla &k2) {

    if(fabs(k1.Kugla::DajPoluprecnik()-k2.Kugla::DajPoluprecnik())<eps*((fabs(k1.Kugla::DajPoluprecnik()))+(fabs(k2.Kugla::DajPoluprecnik())))) return false;
    if(fabs(k1.Kugla::DajX()-k2.Kugla::DajX())<eps*((fabs(k1.Kugla::DajX()))+(fabs(k2.Kugla::DajX())))) return false;
    if(fabs(k1.Kugla::DajY()-k2.Kugla::DajY())<eps*((fabs(k1.Kugla::DajY()))+(fabs(k2.Kugla::DajY())))) return false;
    if(fabs(k1.Kugla::DajZ()-k2.Kugla::DajZ())<eps*((fabs(k1.Kugla::DajZ()))+(fabs(k2.Kugla::DajZ())))) return false;
    return true;
}

bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2) {
    if(fabs(k1.Kugla::DajPoluprecnik()-k2.Kugla::DajPoluprecnik())<eps*((fabs(k1.Kugla::DajPoluprecnik()))+(fabs(k2.Kugla::DajPoluprecnik())))) return false;
    return true;
}

bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2) {
    if(fabs(k1.Kugla::DajX()-k2.Kugla::DajX())<eps*((fabs(k1.Kugla::DajX()))+(fabs(k2.Kugla::DajX())))) return false;
    if(fabs(k1.Kugla::DajY()-k2.Kugla::DajY())<eps*((fabs(k1.Kugla::DajY()))+(fabs(k2.Kugla::DajY())))) return false;
    if(fabs(k1.Kugla::DajZ()-k2.Kugla::DajZ())<eps*((fabs(k1.Kugla::DajZ()))+(fabs(k2.Kugla::DajZ())))) return false;   
    return true;
}

bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2) {
    if((fabs(RastojanjeCentara(k1, k2)-k1.Kugla::DajPoluprecnik()-k2.Kugla::DajPoluprecnik()))<eps*(fabs(k1.DajPoluprecnik()+k2.DajPoluprecnik())+fabs(RastojanjeCentara(k1, k2)))) return true;
    return false;
}

bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2) {
    if((fabs(RastojanjeCentara(k1, k2)-k1.Kugla::DajPoluprecnik()-k2.Kugla::DajPoluprecnik()))<eps*(fabs(k1.DajPoluprecnik()+k2.DajPoluprecnik())+fabs(RastojanjeCentara(k1, k2)))) return false;
    if(RastojanjeCentara(k1,k2)<(k1.Kugla::DajPoluprecnik()+k2.Kugla::DajPoluprecnik()) && (k1.Kugla::DajPoluprecnik()==(k2.Kugla::DajPoluprecnik()-RastojanjeCentara(k1,k2))) || (k2.Kugla::DajPoluprecnik()==(k1.Kugla::DajPoluprecnik()-RastojanjeCentara(k1,k2)))) return true;
    return false;   
}

bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2) {
    double d(RastojanjeCentara(k1,k2));
    if(d<(k1.Kugla::DajPoluprecnik()+k2.Kugla::DajPoluprecnik()) && ((k1.Kugla::DajPoluprecnik()>(k2.Kugla::DajPoluprecnik()-d)) || (k2.Kugla::DajPoluprecnik()>(k1.Kugla::DajPoluprecnik()+d))) && k1.Kugla::DajCentar()!=k2.Kugla::DajCentar()) return true;
    return false;
}

bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2) {
    double d(RastojanjeCentara(k1, k2));
    if(d<(k1.Kugla::DajPoluprecnik()+k2.Kugla::DajPoluprecnik())) return true;
    return false;
}

double RastojanjeCentara(const Kugla &k1, const Kugla &k2) {
    return (sqrt(((k1.Kugla::DajX()-k2.Kugla::DajX())*(k1.Kugla::DajX()-k2.Kugla::DajX())) + ((k1.Kugla::DajY()-k2.Kugla::DajY())*(k1.Kugla::DajY()-k2.Kugla::DajY())) + ((k1.Kugla::DajZ()-k2.Kugla::DajZ())*(k1.Kugla::DajZ()-k2.Kugla::DajZ()))));
}

int main () {
    std::cout << "Unesite broj kugla: ";
    int n;
    std::cin >> n;
    while((n<=0) || (!std::cin)) {
        std::cout << ("Neispravan broj kugli, unesite ponovo!") << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cin >> n;
    }
    std::vector<std::shared_ptr<Kugla>>kugle;
    kugle.resize(n);
    for(int i=0; i<n; i++) {
back:        
        std::cout << "Unesite centar " << i+1 << ". kugle: ";
        double x, y, z, r;
        std::cin >> x >> y >> z;
        while(!std::cin) {
            std::cout << "Neispravan centar" << std::endl;
            std::cout << "Unesite centar " << i+1 << ". kugle: ";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cin >> x >> y >> z;
        }
        std::cout << "Unesite poluprecnik " << i+1 << ". kugle: ";
        std::cin >> r;
        while(!std::cin) {
            std::cout << "Ilegalan poluprecnik" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            goto back;
        }
        try {
            kugle[i]=std::make_shared<Kugla>(Kugla{x, y, z, r});
        }catch(std::domain_error jedan) {
            std::cout << jedan.what() << std::endl;
            i--;
        }
    }
    
    std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double x, y, z;
    std::cin >> x >> y >> z;
    while(!std::cin) {
        std::cout << "Neispravni parametri translacije, unesite ponovo!" << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cin >> x >> y >> z;
    }
    std::transform(kugle.begin(), kugle.end(), kugle.begin(), [x, y, z](std::shared_ptr<Kugla>temp) {
        temp->Transliraj(x, y, z);
        return temp;
    });
    
    std::sort(kugle.begin(), kugle.end(), [](std::shared_ptr<Kugla>a, std::shared_ptr<Kugla>b){return a->DajZapreminu()<b->DajZapreminu();});
    
    std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: " << std::endl;
    std::for_each(kugle.begin(), kugle.end(), [](std::shared_ptr<Kugla>temp) {
        temp->Ispisi();
        std::cout << std::endl;
    });
    
    std::cout << "Kugla sa najvecom povrsinom je: ";
    auto povrsina=std::max_element(kugle.begin(), kugle.end(), [](std::shared_ptr<Kugla>a, std::shared_ptr<Kugla>b) {
        return a->DajPovrsinu()<b->DajPovrsinu();
    });
    (*povrsina)->Ispisi();
    std::cout << std::endl;

    auto t1(kugle.begin());
    auto t2(kugle.end());
    std::for_each(t1, t2-1, [t1, t2](std::shared_ptr<Kugla>a){
        std::for_each(t1+1, t2, [a, t1, t2](std::shared_ptr<Kugla>b) {
           if(DaLiSeSijeku(*a, *b) && t1!=t2) {
               provjera=true;
               std::cout << "Presjecaju se kugle: ";
               (*a).Ispisi();
               std::cout <<std::endl;
               (*b).Ispisi();
               std::cout << std::endl;
           } 
        });
    });
    if(!provjera) std::cout << "Ne postoje kugle koje se presjecaju!";
	return 0;
}
