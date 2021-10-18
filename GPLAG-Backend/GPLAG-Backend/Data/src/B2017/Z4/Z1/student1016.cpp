/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <algorithm>
#include <tuple>
#include <vector>
#include <memory>

const double PI(4*atan(1));

template <typename Tip>
bool JesuLiJednaki(Tip x, Tip y, double eps=1e-10) {
    if ((x<0 && y>0) || (x>0 && y<0)) return false;
    return std::fabs(x-y) <= eps*(std::fabs(x)+std::fabs(y));
}

class Kugla {
    double x, y, z, r;
    public:
        explicit Kugla(double r=0) { x=y=z=0; }
        
        Kugla(double x, double y, double z, double r=0) {
            if (r<0) throw std::domain_error ("Ilegalan poluprecnik");
            Kugla::x=x; Kugla::y=y; Kugla::z=z; Kugla::r=r;
        }
        explicit Kugla(const std::tuple<double, double, double> &centar, double r=0) {
            if (r<0) throw std::domain_error ("Ilegalan poluprecnik");
            x=std::get<0>(centar); y=std::get<1>(centar); z=std::get<2>(centar);
            Kugla::r=r;
        }
        
        double DajX() const;
        double DajY() const;
        double DajZ() const; 
        std::tuple<double, double, double> DajCentar() const;
        double DajPoluprecnik() const;
        double DajPovrsinu() const;
        double DajZapreminu() const;
        Kugla &PostaviX (double x);
        Kugla &PostaviY (double y);
        Kugla &PostaviZ (double z);
        Kugla &PostaviCentar(double x, double y, double z);
        Kugla &PostaviCentar(const std::tuple<double, double, double> &centar);
        Kugla &PostaviPoluprecnik(double r);
        void Ispisi() const;
        void Transliraj (double delta_x, double delta_y, double delta_z);
        friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
        friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
        friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
        friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
        friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
        friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
        friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
        
        bool DaLiSadrzi (const Kugla &k) const {
            double d(std::sqrt((k.x-x)*(k.x-x) + (k.y-y)*(k.y-y) + (k.z-z)*(k.z-z)));
            if (d<std::fabs(r-k.r)) return true;
            else return false;
        }
        
        friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);
}; // KRAJ KLASE

double Kugla::DajX() const { return x; }
double Kugla::DajY() const { return y; }
double Kugla::DajZ() const { return z; }

std::tuple<double, double, double> Kugla::DajCentar() const {
    std::tuple<double, double, double> pomocna;
    std::get<0>(pomocna)=x; std::get<1>(pomocna)=y; std::get<2>(pomocna)=z;
    return pomocna;
}

double Kugla::DajPoluprecnik() const { return r; }
double Kugla::DajPovrsinu() const { return(4*r*r*PI); }
double Kugla::DajZapreminu() const { return(4/3.*r*r*r*PI); }

Kugla &Kugla::PostaviX (double x) { Kugla::x=x; return *this; }
Kugla &Kugla::PostaviY (double y) { Kugla::y=y; return *this; }
Kugla &Kugla::PostaviZ (double z) { Kugla::z=z; return *this; }

Kugla &Kugla::PostaviCentar(double x, double y, double z) {
    Kugla::x=x; Kugla::y=y; Kugla::z=z; 
    return *this; 
}

Kugla &Kugla::PostaviCentar(const std::tuple<double, double, double> &centar) {
    Kugla::x=std::get<0>(centar); Kugla::y=std::get<1>(centar); Kugla::z=std::get<2>(centar);
    return *this;
}

Kugla &Kugla::PostaviPoluprecnik(double r) { 
    if (r<0) throw std::domain_error ("Ilegalan poluprecnik"); 
    Kugla::r=r; 
    return *this;
}

void Kugla::Ispisi() const { std::cout<<"{("<<DajX()<<","<<DajY()<<","<<DajZ()<<"),"<<r<<"}"; }

void Kugla::Transliraj(double delta_x, double delta_y, double delta_z) { x+=delta_x; y+=delta_y; z+=delta_z; }

bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2) {
    return (JesuLiJednaki(k1.x, k2.x) && JesuLiJednaki(k1.y, k2.y) && JesuLiJednaki(k1.z, k2.z) && JesuLiJednaki(k1.r, k2.r));
}

bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2) {
    return (JesuLiJednaki(k1.r, k2.r));
}

bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2) {
    return (JesuLiJednaki(k1.x, k2.x) && JesuLiJednaki(k1.y, k2.y) && JesuLiJednaki(k1.z,k2.z));
}

bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2) {
    if (JesuLiJednaki(k1.r+k2.r, RastojanjeCentara(k1, k2))) return true;
    else return false;
}

bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2) {
    if (JesuLiJednaki(k1.r-k2.r, RastojanjeCentara(k1, k2))) return true;
    else return false;
}

bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2) {
    if (DaLiSeSijeku(k1, k2)) return true;
    else return false;
}

bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2) {
    if ((std::fabs(k2.r-k1.r) < std::fabs(RastojanjeCentara(k1, k2))) && (std::fabs(RastojanjeCentara(k1, k2))<k1.r+k2.r)) return true;
    return false;
}

double RastojanjeCentara(const Kugla &k1, const Kugla &k2) {
    return (std::sqrt((k1.x-k2.x)*(k1.x-k2.x) + (k1.y-k2.y)*(k1.y-k2.y) + (k1.z-k2.z)*(k1.z-k2.z)));
}


int main () {
    int n;
    double pom1, pom2, pom3, pom4;
    double p1, p2, p3;
    std::cout<<"Unesite broj kugla: ";
    
    do {
        std::cin>>n;
        if (n<=0 || !std::cin) {
            std::cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;
            std::cin.clear();
            std::cin.ignore(10000,'\n');
        }
    } while (n<=0 || !std::cin);
    
    std::vector<std::shared_ptr<Kugla>>vektor_kugli(n);
    
    for (int i=0; i<n; i++) {
        BA:
        std::cout<<"Unesite centar "<< i+1 <<". kugle: ";
        std::cin>>pom1>>pom2>>pom3;
        while (!std::cin) {
            std::cout<<"Neispravan centar"<<std::endl;
            std::cout<<"Unesite centar "<< i+1 <<". kugle: ";
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            std::cin>>pom1>>pom2>>pom3;
        } 

        std::cout<<"Unesite poluprecnik "<< i+1 <<". kugle: ";
        std::cin>>pom4;
        while (!std::cin || pom4<0) {
            std::cout<<"Ilegalan poluprecnik"<<std::endl;
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            goto BA;
        }
        try {
            Kugla kugla(pom1, pom2, pom3, pom4);
            vektor_kugli[i]=std::make_shared<Kugla>(kugla);
        } 
        catch (std::domain_error izuzetak1) {
            std::cout<<izuzetak1.what();
            std::cout<<std::endl;
            i--;
        }
        catch (...) {
            std::cout<<"Ponovite unos: "<<std::endl;
            i--;
        }
        
    }
    
    std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    std::cin>>p1>>p2>>p3;
    while (!std::cin) {
        std::cout<<"Neispravni parametri translacije, unesite ponovo!"<<std::endl;
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::cin>>p1>>p2>>p3;
    }
    
    std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: ";
    std::cout<<std::endl;
    std::transform(std::begin(vektor_kugli), std::end(vektor_kugli), std::begin(vektor_kugli), [p1,p2,p3](std::shared_ptr<Kugla> &k){
        k->Transliraj(p1,p2,p3);
        return k;
    });
    
    std::sort(std::begin(vektor_kugli), std::end(vektor_kugli), [](const std::shared_ptr<Kugla> &k1, const std::shared_ptr<Kugla> &k2){
        return (k1->DajZapreminu() < k2->DajZapreminu());
    });
    
    std::for_each(std::begin(vektor_kugli), std::end(vektor_kugli), [](const std::shared_ptr<Kugla> &k){ 
        k->Ispisi();
        std::cout<<std::endl;
    });
    
    std::cout<<"Kugla sa najvecom povrsinom je: ";
    auto max_povrsina(*std::max_element(std::begin(vektor_kugli), std::end(vektor_kugli), [](const std::shared_ptr<Kugla> &k1, const std::shared_ptr<Kugla> &k2){
        return (k1->DajPovrsinu() < k2->DajPovrsinu());
    }));
    max_povrsina->Ispisi();
    std::cout<<std::endl;
    
    bool sijeku_se(false);
    int brojac(0);
    
    std::for_each(std::begin(vektor_kugli), std::end(vektor_kugli), [&brojac, &sijeku_se, vektor_kugli](const std::shared_ptr<Kugla> &k1){
        brojac++;
        std::for_each(std::begin(vektor_kugli)+brojac, std::end(vektor_kugli), [&k1, &sijeku_se](const std::shared_ptr<Kugla> &k2){
           if (DaLiSeSijeku(*k1, *k2)) {
               sijeku_se=true;
               std::cout<<"Presjecaju se kugle: ";
               k1->Ispisi(); std::cout<<std::endl;
               k2->Ispisi(); std::cout<<std::endl;
           }
       }); 
    });
    
    if (!(sijeku_se)) {
        std::cout<<"Ne postoje kugle koje se presjecaju!";
    }
    
    
	return 0;
}
