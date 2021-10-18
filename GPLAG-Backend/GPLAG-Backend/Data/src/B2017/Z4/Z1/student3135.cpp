/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include<tuple>
#include <cmath>
#include <vector>
#include <memory>
#include <stdexcept>
#include <iterator>
#include <cstring>
#include <algorithm>

const double PI(4*std::atan(1));
const double eps(0.0000000001);
class Kugla
{
    double x,y,z;
    double r;
public:
    explicit Kugla(double r=0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::r=r;
    }
    Kugla(double x, double y, double z, double r = 0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::x=x;
        Kugla::y=y;
        Kugla::z=z;
        Kugla::r=r;
    }
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0) {
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
        std::tuple<double, double, double> vrati;
        std::get<0>(vrati)=x;
        std::get<1>(vrati)=y;
        std::get<2>(vrati)=z;
        return vrati;
    }
    double DajPoluprecnik() const {
        return r;
    }
    double DajPovrsinu() const {
        return 4*r*r*PI;
    }
    double DajZapreminu() const {
        return 4/3*r*r*r*PI;
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
        std::cout << "{("<<x<<","<<y<<","<<z<<"),"<<r<<"}";
        std::cout  << std::endl;
    }
    void Transliraj(double delta_x, double delta_y, double delta_z) {
        Kugla::x+=delta_x;
        Kugla::y+=delta_y;
        Kugla::z+=delta_z;
    }
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);//ovo napisati
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);//i ovu
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
    bool DaLiSadrzi(const Kugla &k) const;
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);

};
bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2)
{
    if((k1.x-k2.x)<eps and (k1.y-k2.y)<eps and (k1.z-k2.z)<eps and (k1.r-k2.r)<eps) return true;
    return false;
}
bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2)
{
    if((k1.r-k2.r)<eps) return true;
    return false;
}
bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2)
{
    if((k1.x-k2.x)<eps and (k1.y-k2.y)<eps and (k1.z-k2.z)<eps) return true;
    return false;
}
bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2)
{
    if(((k1.r+k2.r)-RastojanjeCentara(k1,k2))<0.00000000001) return true;
    return false;
}
bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2)
{
    if((RastojanjeCentara(k1,k2)-std::fabs(k1.r-k2.r))<eps)return true;
    else return false;
}
bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2)
{
    if(std::fabs(k1.r-k2.r)> RastojanjeCentara(k1,k2)) return true;
    return false;
}
bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2)
{
    if((k1.r+k2.r)>RastojanjeCentara(k1,k2) and std::fabs(k1.r-k2.r)<RastojanjeCentara(k1,k2)) return true;
    return false;
}
double RastojanjeCentara(const Kugla &k1, const Kugla &k2)
{
    return std::sqrt((k1.x-k2.x)*(k1.x-k2.x) +(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z));
}
int main ()
{
    int n;
    std::cout << "Unesite broj kugla: ";
    std::cin >> n;
    while(!std::cin or std::cin.peek() != '\n' or n<=0) {
        std::cout << "Neispravan broj kugli, unesite ponovo!"<<std::endl;
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::cin >> n;
    }
    //while(1);
    std::vector<std::shared_ptr<Kugla>> v(n,nullptr);
    double x1,y1,z1,p;
    for(int i(0); i<n; i++) {
        std::cout << "Unesite centar "<<i+1<<". kugle: " ;
        std::cin >> x1>>y1>>z1;
        while(!std::cin) {
            std::cout<<"Neispravan centar"<<std::endl<<"Unesite centar "<<i+1<<". kugle: ";
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            std::cin >> x1;
            std::cin >> y1;
            std::cin >> z1;
        }
        std::cout << "Unesite poluprecnik "<<i+1<<". kugle: ";
        std::cin >> p;
        if(!std::cin or p<0) {
            std::cout<<"Ilegalan poluprecnik"<<std::endl;
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            i--;
            continue;
        }
        v[i]=std::make_shared<Kugla>(x1,y1,z1,p);
    }

    std::cout  << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double delta_x,delta_y,delta_z;
    std::cin >> delta_x>>delta_y>>delta_z;
    while(!std::cin){
        std::cout << "Neispravni parametri translacije, unesite ponovo!" << std::endl;
        std::cin.clear();
            std::cin.ignore(10000,'\n');
            std::cin >> delta_x;
            std::cin >> delta_y;
            std::cin >> delta_z;
    }
    std::transform(v.begin(),v.end(),v.begin(),[delta_x,delta_y,delta_z](std::shared_ptr<Kugla> k) {
        std::shared_ptr<Kugla> vrati=std::make_shared<Kugla>(k->DajX()+delta_x,k->DajY()+delta_y,k->DajZ()+delta_z,k->DajPoluprecnik());
        return  vrati;
    });
    std::sort(v.begin(),v.end(),[](std::shared_ptr<Kugla> k1,std::shared_ptr<Kugla> k2) {
        return k1->DajZapreminu()<k2->DajZapreminu();
    });
    std::cout <<  "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti:" << std::endl;
    std::for_each(v.begin(),v.end(),[](std::shared_ptr<Kugla> k) {
        k->Ispisi();
    });
    std::shared_ptr<Kugla> maxpov(*std::max_element(v.begin(),v.end(),[](std::shared_ptr<Kugla> k1,std::shared_ptr<Kugla> k2) {
        return k1->DajPovrsinu()<k2->DajPovrsinu();
    }));
    std::cout << "Kugla sa najvecom povrsinom je: " ;
    maxpov->Ispisi();
    int brojac(0);
    auto pom(v.begin());
    std::for_each(v.begin(),v.end(),[&](std::shared_ptr<Kugla> k) {
        pom++;
        std::for_each(pom,v.end(),[&](std::shared_ptr<Kugla> l) {
            if(DaLiSeSijeku(*k,*l)==true) {
                std::cout << "Presjecaju se kugle: ";
                brojac++;
                k->Ispisi();
                l->Ispisi();
            }
        });
    });
    if(brojac==0) std::cout <<  "Ne postoje kugle koje se presjecaju!"<< std::endl;
    return 0;
}
