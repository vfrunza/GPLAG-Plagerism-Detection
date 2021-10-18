/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <tuple>
#include <vector>
#include <memory>
#include <algorithm>
#define PI 4*std::atan(1)
#define E 1e-10
class Kugla
{
    double radijus;
    double x,y,z;
public:
    explicit Kugla(double r = 0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        radijus=r;
        x=y=z=0;
    }

    Kugla(double x, double y, double z, double r = 0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        radijus=r;
        Kugla::x=x;
        Kugla::y=y;
        Kugla::z=z;
    }

    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        radijus=r;
        x=std::get<0>(centar);
        y=std::get<1>(centar);
        z=std::get<2>(centar);
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
        std::tuple<double,double,double> VratiCentar;
        VratiCentar=std::make_tuple(x,y,z);
        return VratiCentar;
    }

    double DajPoluprecnik() const {
        return radijus;
    }

    double DajPovrsinu() const {
        return 4*PI*radijus*radijus;
    }

    double DajZapreminu() const {
        return (4./3)*radijus*radijus*radijus*PI;
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
        x=std::get<0>(centar);
        y=std::get<1>(centar);
        z=std::get<2>(centar);
        return *this;
    }

    Kugla &PostaviPoluprecnik(double r) {
        radijus=r;
        return *this;
    }
    void Ispisi() const {
        std::cout<<"{("<<x<<","<<y<<","<<z<<"),"<<radijus<<"}";
    }

    void Transliraj(double delta_x, double delta_y, double delta_z) {
        x=x+delta_x;
        y=y+delta_y;
        z=z+delta_z;
    }

    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2) {
        return (std::abs(k1.x-k2.x)<E*(std::abs(k1.x)+std::abs(k2.x)) && std::abs(k1.y-k2.y)<E*(std::abs(k1.y)+std::abs(k2.y)) && std::abs(k1.z-k2.z)<E*(std::abs(k1.z)+std::abs(k2.z)) && std::abs(k1.radijus-k2.radijus)<E*(std::abs(k1.radijus)+std::abs(k2.radijus)));
    }

    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2) {
        return (std::abs(k1.radijus-k2.radijus)<E*(std::abs(k1.radijus)+std::abs(k2.radijus)));
    }

    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2) {
        return (std::abs(k1.x-k2.x)<E*(std::abs(k1.x)+std::abs(k2.x)) && std::abs(k1.y-k2.y)<E*(std::abs(k1.y)+std::abs(k2.y)) && std::abs(k1.z-k2.z)<E*(std::abs(k1.z)+std::abs(k2.z)));
    }

    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2) {
        return std::abs(RastojanjeCentara(k1,k2)-(k1.radijus+k2.radijus))<E*(std::abs(RastojanjeCentara(k1,k2))+std::abs(k1.radijus+k2.radijus));
    }

    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2) {
        return std::abs(RastojanjeCentara(k1,k2)-(k1.radijus-k2.radijus))<E*(std::abs(RastojanjeCentara(k1,k2))+std::abs(k1.radijus-k2.radijus));
    }

    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2) {
        return RastojanjeCentara(k1,k2)<=k1.radijus+k2.radijus;
    }

    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2) {
        return (RastojanjeCentara(k1,k2)<(k1.radijus+k2.radijus) && RastojanjeCentara(k1,k2)>std::abs(k1.radijus-k2.radijus));
    }

    bool DaLiSadrzi(const Kugla &k) const {
        return RastojanjeCentara(*this,k)<radijus+k.radijus;
    }

    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2) {
        return std::sqrt( (k2.x-k1.x)*(k2.x-k1.x) + (k2.y-k1.y)*(k2.y-k1.y) + (k2.z-k1.z)*(k2.z-k1.z) );
    }
};

int main ()
{
    std::cout<<"Unesite broj kugla: ";
    int br_kugla;
    std::cin>>br_kugla;
    std::vector<std::shared_ptr<Kugla>> kugle(br_kugla);
    double r,x,y,z;
    for (int i = 0; i < br_kugla; i++) {
        std::cout<<"Unesite centar "<<i+1<<". kugle: ";
        std::cin>>x>>y>>z;
        if(!(std::cin)) {
            std::cout<<"Nepravilan unos za centar "<<i+1<<". kugle!\n";
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            i--;
            continue;
        }
        std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
        std::cin>>r;
        if(!(std::cin) || r<0) {
            std::cout<<"Ilegalan poluprecnik"<<std::endl;
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            i--;
            continue;
        }
        kugle.at(i)=std::make_shared<Kugla>(x,y,z,r);
    }
    std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double d_x,d_y,d_z;
    std::cin>>d_x>>d_y>>d_z;
    std::transform(kugle.begin(),kugle.end(),kugle.begin(),[d_x,d_y,d_z](std::shared_ptr<Kugla> kugla) {
        kugla->Transliraj(d_x,d_y,d_z);
        return kugla;
    });
    std::sort(kugle.begin(),kugle.end(),[](std::shared_ptr<Kugla> k1,std::shared_ptr<Kugla> k2) {
        return k1->DajZapreminu()<k2->DajZapreminu();
    });
    std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: \n";
    std::for_each(kugle.begin(),kugle.end(),[](std::shared_ptr<Kugla> k) {
        k->Ispisi();
        std::cout<<std::endl;
    });
    std::cout<<"Kugla sa najvecom povrsinom je: ";
    (*std::max_element(kugle.begin(),kugle.end(),[](std::shared_ptr<Kugla> k1,std::shared_ptr<Kugla> k2) {
        return k1->DajPovrsinu()<k2->DajPovrsinu();
    }))->Ispisi();
    std::cout<<std::endl;
    int brojac_ispisa(0);
    int brojac(-1);
    std::for_each(kugle.begin(),kugle.end(),[&brojac_ispisa,kugle,&brojac](std::shared_ptr<Kugla> k1) {
        brojac++;
        std::for_each(kugle.begin()+brojac,kugle.end(),[k1,&brojac_ispisa](std::shared_ptr<Kugla> k2) {
            if(!(DaLiSuIdenticne(*k1,*k2)) && DaLiSeSijeku(*k1,*k2)) {

                std::cout<<"Presjecaju se kugle: ";
                k1->Ispisi();
                std::cout<<std::endl;
                k2->Ispisi();
                std::cout<<std::endl;
                brojac_ispisa++;
            }

        });

    });
    if(brojac_ispisa==0) std::cout<<"Ne postoje kugle koje se presjecaju!";


    return 0;
}
