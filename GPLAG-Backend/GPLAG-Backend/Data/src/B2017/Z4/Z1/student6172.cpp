/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <memory>
const double PI(4*atan(1));
const double EPS (10e-7);
class Kugla
{
    double x,y,z,r;
    friend bool jednaki(double x,double y);
public:
    explicit Kugla(double r = 0):x(0),y(0),z(0) {
        if(r<0)throw std::domain_error("Ilegalan poluprecnik");
        Kugla::r=r;
    }
    Kugla(double x, double y, double z, double r = 0):x(x),y(y),z(z) {
        if(r<0)throw std::domain_error("Ilegalan poluprecnik");
        Kugla::r=r;
    }
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0) {
        if(r<0)throw std::domain_error("Ilegalan poluprecnik");
        Kugla::x=std::get<0>(centar);
        Kugla::y=std::get<1>(centar);
        Kugla::z=std::get<2>(centar);
        Kugla::r=r;
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
        return 4*r*r*PI;
    }
    double DajZapreminu() const {
        return (4*r*r*r*PI)/3;
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
        std::tie(x,y,z)=centar;
        return *this;
    }
    Kugla &PostaviPoluprecnik(double r) {
        if(r<0)throw std::domain_error("Ilegalan poluprecnik");
        Kugla::r=r;
        return *this;
    }
    void Ispisi() const {
        std::cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}"<<std::endl;
    }
    void Transliraj(double delta_x, double delta_y, double delta_z) {
        x+=delta_x;
        y+=delta_y;
        z+=delta_z;
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
bool jednaki(double x,double y)
{
    return std::fabs(x-y)<EPS*(std::fabs(x)+std::fabs(y));
}
bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2)
{
    return jednaki(k1.x,k2.x) && jednaki(k1.y,k2.y) && jednaki(k1.z,k2.z) && jednaki(k1.r,k2.r);

}
bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2)
{
    return jednaki(k1.r,k2.r);
}
bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2)
{
    return jednaki(k1.x,k2.x) && jednaki(k1.y,k2.y) && jednaki(k1.z,k2.z);
}
double RastojanjeCentara(const Kugla &k1, const Kugla &k2)
{
    return std::sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z));

}
bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2)
{
    return jednaki(k1.r+k2.r,RastojanjeCentara(k1,k2));
}
bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2)
{
    if(jednaki(k1.r,0) && jednaki(k2.r,0)) return DaLiSuIdenticne(k1,k2);
    return jednaki(std::fabs(k1.r-k2.r),RastojanjeCentara(k1,k2));
}
bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2)
{
    if(DaLiSeDodirujuIzvana(k1,k2)) return false;
    if(DaLiSeDodirujuIznutra(k1,k2)) return false;
    return RastojanjeCentara(k1,k2)<k1.r+k2.r && std::fabs(k1.r-k2.r)<RastojanjeCentara(k1,k2);
}
bool Kugla::DaLiSadrzi(const Kugla &k) const
{
    if(r<k.r) return false;
    if(DaLiSuIdenticne(*this,k)) return true;

    if(DaLiSeDodirujuIznutra(*this,k)) return true;
    if(DaLiSeDodirujuIzvana(*this,k)) return false;
    if(DaLiSeSijeku(*this,k)) return false;
    if(RastojanjeCentara(*this,k)>r+k.r) return false;
    if(DaLiSuKoncentricne(*this,k)) return true;
    if(r> RastojanjeCentara(*this,k)) return true;
    if( jednaki(r,k.r+RastojanjeCentara(*this,k))) return true;
    return RastojanjeCentara(*this,k)<r-k.r;
}
bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2)
{
    if(RastojanjeCentara(k1,k2)>k1.r+k2.r || DaLiSeDodirujuIzvana(k1,k2)) return false;
    if(k1.DaLiSadrzi(k2) || k2.DaLiSadrzi(k1)) return true;
            return  DaLiSeSijeku(k1,k2) || DaLiSeDodirujuIznutra(k1,k2);

}

int main ()
{
    std::cout<<"Unesite broj kugla: ";
    int n;
    while(!(std::cin>>n) || n<=0) {
        std::cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;
        std::cin.clear();
        std::cin.ignore(10000,'\n');
    }
    std::cin.ignore(10000,'\n');
    std::vector<std::shared_ptr<Kugla>> v(n);
    for(int i=0; i<n; i++) {
        int poc(i);
        double x,y,z,r;
        for(;;) {
            std::cout<<"Unesite centar "<<i+1<<". kugle: ";
            std::cin>>x>>y>>z;
            if(std::cin)break;
            std::cout<<"Neispravan centar"<<std::endl;
            std::cin.clear();
            std::cin.ignore(10000,'\n');
        }
        std::cin.ignore(1000,'\n');
        for(;;) {
            std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
            std::cin>>r;
            if(r>=0 && std::cin) break;
            std::cout<<"Ilegalan poluprecnik"<<std::endl;
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            i--;
            break;
        }
        if(i==poc)
            v.at(i)=std::make_shared<Kugla>(x,y,z,r);
    }
std::cin.ignore(10000,'\n');
    std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double delta_x,delta_y,delta_z;
   for(;;) {
    std::cin>>delta_x>>delta_y>>delta_z;
    if(std::cin) break;
   std::cout<<"Neispravni parametri translacije, unesite ponovo!"<<std::endl;
   std::cin.clear();
   std::cin.ignore(10000,'\n');
       
   }
    std::transform(v.begin(),v.end(),v.begin(),[delta_x,delta_y,delta_z](std::shared_ptr<Kugla>p) {
        (*p).Transliraj(delta_x,delta_y,delta_z);
        return p;
    });

    std::sort(v.begin(),v.end(),[](std::shared_ptr<Kugla>p1,std::shared_ptr<Kugla>p2) {
        return p1->DajZapreminu()<p2->DajZapreminu();
    });
    std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<std::endl;
    std::for_each(v.begin(),v.end(),[](std::shared_ptr<Kugla>p) {
        (*p).Ispisi();

    });

    auto itmax(std::max_element(v.begin(),v.end(),[](std::shared_ptr<Kugla>p1,std::shared_ptr<Kugla>p2) {
        return p1->DajPovrsinu()<p2->DajPovrsinu();
    }));
    std::cout<<"Kugla sa najvecom povrsinom je: ";
    //itmax je pok ili iterator na element vektora,tj na pokazivac vektora koji pokazuje na kuglu sa najvecom povrsinom
    (* itmax)->Ispisi();
    bool postoje(false);
    int poz(0);
   std::for_each(v.begin(),v.end(),
    [&postoje,&v,&poz]( std::shared_ptr<Kugla> it1) {
        poz++;
     std::for_each(v.begin()+poz,v.end(),[&postoje,it1](std::shared_ptr<Kugla>it2) {
            if(DaLiSeSijeku((*it1),*it2)) {
                std::cout<<"Presjecaju se kugle: ";
                it1->Ispisi();
                it2->Ispisi();
                postoje=true;

            }
        });});
      if(!postoje) std::cout<<"Ne postoje kugle koje se presjecaju!";
    return 0;
}
