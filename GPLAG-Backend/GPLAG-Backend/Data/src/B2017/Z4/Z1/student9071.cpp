#include <iostream>
#include <tuple>
#include <cmath>
#include <memory>
#include <vector>
#include <new>
#include <algorithm>
#define pi (4*atan(1))

bool comp(double a, double b)
{
    return (fabs(a-b)<(10e-10*(fabs(a)+fabs(b))));
}
class Kugla
{
    double r,x,y,z;
public:
    explicit Kugla(double r=0) {
        Kugla::r=r;
        Kugla::x=0;
        Kugla::y=0;
        Kugla::z=0;
    }
    Kugla(double x, double y, double z, double r=0) {
        Kugla::r=r;
        Kugla::x=x;
        Kugla::y=y;
        Kugla::z=z;
    }
    explicit Kugla(const std::tuple<double, double, double> &centar, double r=0) {
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
    std::tuple<double, double, double> DajCentar() const {
        return std::make_tuple(x,y,z);
    }
    double DajPoluprecnik() const {
        return r;
    }
    double DajPovrsinu() const {
        return 4*pi*r*r;
    }
    double DajZapreminu() const {
        return 4./3*r*r*r*pi;
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
        Kugla::r=r;
        return *this;
    }
    void Ispisi() const {
        std::cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}"<<"\n";
    }
    void Transliraj(double deltax, double deltay, double deltaz) {
        Kugla::x+=deltax;
        Kugla::y+=deltay;
        Kugla::z+=deltaz;
    }
    bool DaLiSadrzi(const Kugla &k) const {
        return(RastojanjeCentara(k,*this)+k.r<r||comp(RastojanjeCentara(k,*this)+k.r,r));
       // return (k.x<=x&&k.y<=y&&k.z<=z&&k.r<=r);
        
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
double RastojanjeCentara(const Kugla &k1, const Kugla &k2)//
{
    return sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z));
}
bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2)//
{
    return(comp(k1.x,k2.x)&&comp(k1.y,k2.y)&&comp(k1.z,k2.z)&&comp(k1.r,k2.r));
}
bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2)//
{
    return comp(k1.r,k2.r);
}
bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2)//
{
    return(comp(k1.x,k2.x)&&comp(k1.y,k2.y)&&comp(k1.z,k2.z));
}
bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2)
{
    return(!k1.DaLiSadrzi(k2)&&(comp(RastojanjeCentara(k1,k2),k1.r+k2.r)))
          ||(!k2.DaLiSadrzi(k1)&&(comp(RastojanjeCentara(k1,k2),k1.r+k2.r)));
}
bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2)
{
    return (k1.DaLiSadrzi(k2)&&comp(k1.r,k2.r+RastojanjeCentara(k1,k2)))
           ||(k2.DaLiSadrzi(k1)&&comp(k2.r,k1.r+RastojanjeCentara(k1,k2)));
}
bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2)
{
    return (k1.r+k2.r>RastojanjeCentara(k1,k2));
}
bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2)
{
return (DaLiSePreklapaju(k1,k2)&&!k1.DaLiSadrzi(k2)&&!k2.DaLiSadrzi(k1));
    
}

int main ()
{
    int n;
    std::cout<<"Unesite broj kugla: ";
    while(1) {
        
        std::cin>>n;
        if(!std::cin||n<=0) {
            std::cout<<"Neispravan broj kugli, unesite ponovo!\n";
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            continue;
        }
        break;
    }
    std::vector<std::shared_ptr<Kugla>> vektor(n);
    double x,y,z,r;
    for(int i=0; i<n; i++) {
        std::cout<<"Unesite centar "<<i+1<<". kugle: ";
        std::cin>>x>>y>>z;
        if(!std::cin) {
            std::cout<<"Neispravan centar\n";
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            i--;
            continue;
        }
        std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";


        std::cin>>r;
        if(!std::cin||r<0) {
            std::cout<<"Ilegalan poluprecnik\n";
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            i--;
            continue;
        }
        vektor[i]=std::make_shared<Kugla>(Kugla(x,y,z,r));
    }
    
    std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    int deltax,deltay,deltaz;
    while(1) {
        std::cin>>deltax>>deltay>>deltaz;
        if(!std::cin) {
            std::cout<<"Neispravni parametri translacije, unesite ponovo!\n";
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            continue;
        }
        break;
    }
    std::transform(vektor.begin(),vektor.end(),vektor.begin(),[deltax,deltay,deltaz](std::shared_ptr<Kugla> kugla) {
        kugla->Transliraj(deltax,deltay,deltaz);
        return kugla;
    });
    std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: \n";
    std::sort(vektor.begin(),vektor.end(),[](std::shared_ptr<Kugla> kugla1,std::shared_ptr<Kugla> kugla2) {
        return (kugla1->DajZapreminu()<kugla2->DajZapreminu());
    });
    std::for_each(vektor.begin(),vektor.end(),[](std::shared_ptr<Kugla> kugla) {
        kugla->Ispisi();
    });

    auto pozicija(*std::max_element(vektor.begin(),vektor.end(),[](std::shared_ptr<Kugla> kugla1,std::shared_ptr<Kugla> kugla2) {
        return (kugla1->DajPovrsinu()<kugla2->DajPovrsinu());
    }));
    std::cout<<"Kugla sa najvecom povrsinom je: ";
    pozicija->Ispisi();
    std::vector<std::shared_ptr<Kugla>> presjeci1,presjeci2;
    bool nadjeno(false);
    auto pocetak(vektor.begin());
    auto kraj(vektor.end());
    std::for_each(pocetak,kraj-1,[&](std::shared_ptr<Kugla> kugla1) {
        std::for_each(pocetak+1,kraj,[&](std::shared_ptr<Kugla> kugla2) {
            if(DaLiSeSijeku(*kugla1,*kugla2)) {
                //std::cout<<kugla1->DaLiSadrzi(*kugla2)||kugla2->DaLiSadrzi(*kugla1);
                std::cout<<"Presjecaju se kugle: ";
                kugla1->Ispisi();
                kugla2->Ispisi();
                nadjeno=true;
            }
        });
    });
    if(!nadjeno) {
        std::cout<<"Ne postoje kugle koje se presjecaju!";
    }
    /*
    Kugla kugla1(1,1,1,2);
    Kugla kugla2(1,0,1,3);
    std::cout
    <<kugla2.DaLiSadrzi(kugla1)<<"\n"
    <<DaLiSuIdenticne(kugla1,kugla2)<<"\n"
    <<DaLiSuPodudarne(kugla1,kugla2)<<"\n"
    <<DaLiSuKoncentricne(kugla1,kugla2)<<"\n"
    <<DaLiSeDodirujuIzvana(kugla1,kugla2)<<"\n"
    <<DaLiSeDodirujuIznutra(kugla1,kugla2)<<"\n"
    <<DaLiSePreklapaju(kugla1,kugla2)<<"\n"
   <<DaLiSeSijeku(kugla1,kugla2)<<"\n"
    <<RastojanjeCentara(kugla1,kugla2);
    */

    return 0;
}
