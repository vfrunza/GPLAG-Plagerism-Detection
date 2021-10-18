/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>
#define pi 4*std::atan(1)
#define eps 10e-10
class Kugla {
    double x,y,z,r;
    public:
    explicit Kugla(double r=0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::r=r;
    }
    Kugla(double x, double y, double z, double r=0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::r=r;
        Kugla::x=x;
        Kugla::y=y;
        Kugla::z=z;
    }
    explicit Kugla(const std::tuple<double, double, double> &centar, double r=0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::r=r;
        Kugla::x=std::get<0>(centar);
        Kugla::y=std::get<1>(centar);
        Kugla::z=std::get<2>(centar);
    }
    double DajX() const {
        return Kugla::x;
    }
    double DajY() const {
        return Kugla::y;
    }
    double DajZ() const {
        return Kugla::z;
    }
    std::tuple<double,double,double> DajCentar() const {
        std::tuple<double,double,double>k;
        std::get<0>(k)=Kugla::x;
        std::get<1>(k)=Kugla::y;
        std::get<2>(k)=Kugla::z;
        return k;
    }
    double DajPoluprecnik() const {
        return r;
    }
    double DajPovrsinu() const {
        return 4*r*r*pi;
    }
    double DajZapreminu() const {
        return (4*r*r*r*pi)/3;
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
    Kugla &PostaviCentar(const std::tuple<double,double,double> &centar) {
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
        std::cout<<"{("<<DajX()<<","<<DajY()<<","<<DajZ()<<")"<<","<<DajPoluprecnik()<<"}";
    }
    void Transliraj(double delta_x, double delta_y, double delta_z) {
        Kugla::x+=delta_x;
        Kugla::y+=delta_y;
        Kugla::z+=delta_z;
    }
    friend bool DaLiSuIdenticne (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuPodudarne (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuKoncentricne (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIzvana (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSePreklapaju (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
    bool DaLiSadrzi(const Kugla &k) const {
        double s(std::sqrt((k.x-x)*(k.x-x)+(k.y-y)*(k.y-y)+(k.z-z)*(k.z-z)));
        if(s<std::fabs(r-k.r)) return true;
        else return false;
    }
    friend double RastojanjeCentara (const Kugla &k1, const Kugla &k2);
};
bool DaLiSuIdenticne (const Kugla &k1, const Kugla &k2) {
    if(std::fabs(k1.r-k2.r)<eps*(std::fabs(k1.r)+std::fabs(k2.r)) && std::fabs(k1.x-k2.x)<eps*(std::fabs(k1.x)+std::fabs(k2.x)) && std::fabs(k1.y-k2.y)<eps*(std::fabs(k1.y)+std::fabs(k2.y)) && std::fabs(k1.z-k2.z)<eps*(std::fabs(k1.z)+std::fabs(k2.z))) return true;
    return false;
}
bool DaLiSuPodudarne (const Kugla &k1, const Kugla &k2) {
    if(std::fabs(k1.r-k2.r)<eps*(std::fabs(k1.r)+std::fabs(k2.r))) return true;
    return false;
}
bool DaLiSuKoncentricne (const Kugla &k1, const Kugla &k2) {
    if(std::fabs(k1.x-k2.x)<eps*(std::fabs(k1.x)+std::fabs(k2.x)) && std::fabs(k1.y-k2.y)<eps*(std::fabs(k1.y)+std::fabs(k2.y)) && std::fabs(k1.z-k2.z)<eps*(std::fabs(k1.z)+std::fabs(k2.z))) return true;
    return false;
}
bool DaLiSeDodirujuIzvana (const Kugla &k1, const Kugla &k2) {
    double s=RastojanjeCentara(k1,k2);
    if(std::fabs(s-(k1.r+k2.r))<eps*(std::fabs(s)+std::fabs(k1.r+k2.r))) return true;
    return false;
}
bool DaLiSeDodirujuIznutra (const Kugla &k1, const Kugla &k2) {
    double s=RastojanjeCentara(k1,k2);
    if(std::fabs(s-(k1.r-k2.r))<eps*(std::fabs(s)+std::fabs(k1.r-k2.r))) return true;
    return false;
}
bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2) {
    double s=RastojanjeCentara(k1,k2);
    if((std::fabs(k2.r-k1.r)<std::fabs(s)) &&(std::fabs(s)<k1.r+k2.r)) return true;
     return false;
}
bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2) {
    if(DaLiSeSijeku(k1,k2)) return true;
    return false;
}

double RastojanjeCentara (const Kugla &k1, const Kugla &k2) {
    return sqrt((k2.x-k1.x)*(k2.x-k1.x)+(k2.y-k1.y)*(k2.y-k1.y)+(k2.z-k1.z)*(k2.z-k1.z));
}

int main ()
{
    int n;
    std::cout<<"Unesite broj kugla: ";
    std::cin>>n;
    while(!(std::cin) || n<=0) {
        std::cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::cin>>n;
    }
    std::vector<std::shared_ptr<Kugla>>vektor(n);
    double x, y, z, r;
    Kugla k;
    for(int i=0; i<n; i++) {
        std::cout<<"Unesite centar "<<i+1<<". kugle: ";
        std::cin>>x>>y>>z;
        while(!(std::cin)) {
            std::cout<<"Neispravan centar"<<std::endl;
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            std::cout<<"Unesite centar "<<i+1<<". kugle: ";
            std::cin>>x>>y>>z;
        }
        std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
        std::cin>>r;
        while(!(std::cin) || r<0) {
            std::cout<<"Ilegalan poluprecnik"<<std::endl;
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            std::cout<<"Unesite centar "<<i+1<<". kugle: ";
            std::cin>>x>>y>>z;
            std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
            std::cin>>r;
        }
        Kugla k(x,y,z,r);
      vektor[i]=std::make_shared<Kugla>(k);
    }
    double delta_x, delta_y, delta_z;
    std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    std::cin>>delta_x>>delta_y>>delta_z;
    while(!(std::cin)) {
        std::cout<<"Neispravni parametri translacije, unesite ponovo!"<<std::endl;
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            std::cin>>delta_x>>delta_y>>delta_z;
    }
    std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<std::endl;
    std::transform(vektor.begin(), vektor.end(), vektor.begin(), [delta_x,delta_y,delta_z](std::shared_ptr<Kugla>&k){
      k->Transliraj(delta_x, delta_y, delta_z);
      return k; });
    std::sort(vektor.begin(), vektor.end(),[](const std::shared_ptr<Kugla>&k1, const std::shared_ptr<Kugla>&k2){
         return k1->DajZapreminu()<k2->DajZapreminu(); });
    std::for_each(vektor.begin(),vektor.end(),[](const std::shared_ptr<Kugla>&k){
        k->Ispisi();
        std::cout<<std::endl; });
    std::cout<<"Kugla sa najvecom povrsinom je: ";
    auto max_kugla=*std::max_element(vektor.begin(),vektor.end(),[](const std::shared_ptr<Kugla>&k1, const std::shared_ptr<Kugla>&k2){
        return k2->DajPovrsinu()>k1->DajPovrsinu();
    });
    max_kugla->Ispisi();
    std::cout<<std::endl;
   
    std::vector<std::pair<Kugla,Kugla>>parovi;
    int cnt=0;
    bool prom(false);
    std::for_each(vektor.begin(), vektor.end(),[&parovi,&vektor,&cnt,&prom](std::shared_ptr<Kugla>&k1) {
        cnt++;
        std::for_each(vektor.begin()+cnt,vektor.end(), [&parovi,&k1,&vektor,&prom](std::shared_ptr<Kugla>&k2) {
            if(DaLiSeSijeku(*k1,*k2))  {
            prom=true;
            parovi.push_back(std::pair<Kugla,Kugla>(*k1,*k2));
            std::cout<<"Presjecaju se kugle: ";
            k1->Ispisi();
            std::cout<<std::endl;
            k2->Ispisi();
            std::cout<<std::endl;
            }
        });
    });
    if(!prom) std::cout<<"Ne postoje kugle koje se presjecaju!";
	return 0;
}
