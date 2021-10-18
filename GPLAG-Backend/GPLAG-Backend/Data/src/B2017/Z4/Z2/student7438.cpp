/B2017/2018: Zadaća 4, Zadatak 2
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <tuple>
#include <new>
#include <memory>
#include <vector>

const double PI(4*atan(1));
const double EPSILON(0.0000000001);

class NepreklapajucaKugla
{
    double x,y,z,r;
public:
    explicit NepreklapajucaKugla(double r = 0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        x=0;
        y=0;
        z=0;
        NepreklapajucaKugla::r=r;
    }
    NepreklapajucaKugla(double x = 0, double y=0, double z=0, double r = 0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        NepreklapajucaKugla::x=x;
        NepreklapajucaKugla::y=y;
        NepreklapajucaKugla::z=z;
        NepreklapajucaKugla::r=r;
    }
    explicit NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r = 0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        NepreklapajucaKugla::r=r;
        NepreklapajucaKugla::x=std::get<0>(centar);
        NepreklapajucaKugla::y=std::get<1>(centar);
        NepreklapajucaKugla::z=std::get<2>(centar);
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
        std::tuple<double,double,double> t;
        t=std::make_tuple(x,y,z);
        return t;
    }
    double DajPoluprecnik() const {
        return r;
    }
    double DajPovrsinu() const {
        return (4*r*r*PI);
    }
    double DajZapreminu() const {
        return (4*r*r*r*PI/3);
    }
    NepreklapajucaKugla &PostaviX(double x) {
        NepreklapajucaKugla::x=x;
        return *this;
    }
    NepreklapajucaKugla &PostaviY(double y) {
        NepreklapajucaKugla::y=y;
        return *this;
    }
    NepreklapajucaKugla &PostaviZ(double z) {
        NepreklapajucaKugla::z=z;
        return *this;
    }
    NepreklapajucaKugla &PostaviCentar(double x, double y, double z) {
        NepreklapajucaKugla::x=x;
        NepreklapajucaKugla::y=y;
        NepreklapajucaKugla::z=z;
        return *this;
    }
    NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar) {
        NepreklapajucaKugla::x=std::get<0>(centar);
        NepreklapajucaKugla::y=std::get<1>(centar);
        NepreklapajucaKugla::z=std::get<2>(centar);
        return *this;
    }
    NepreklapajucaKugla &PostaviPoluprecnik(double r) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        NepreklapajucaKugla::r=r;
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
    friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2) {
        return(sqrt((k1.DajX()-k2.DajX())*(k1.DajX()-k2.DajX())+(k1.DajY()-k2.DajY())*(k1.DajY()-k2.DajY())+(k1.DajZ()-k2.DajZ())*(k1.DajZ()-k2.DajZ())));
    }
};

int main ()
{
    int n;
    std::cout<<"Unesite broj kugla: ";
    std::cin>>n;
    while(n<=0 || !(std::cin)) {
        std::cin.clear();
        std::cin.ignore(1000,'\n');
        std::cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;
        std::cin>>n;
    }
    std::vector<std::shared_ptr<NepreklapajucaKugla>>v;
    for(int i(0); i<n; i++) {
        bool T(false);
        double x,y,z,r;
        std::cout<<"Unesite centar "<<i+1<<". kugle: ";
        std::cin>>x;
        std::cin>>y;
        std::cin>>z;
        if(!(std::cin)) {
            while(!(std::cin)) {
                std::cout<<"Neispravan centar "<<std::endl;
                std::cin.clear();
                std::cin.ignore(1000,'\n');
                std::cout<<"Unesite centar "<<i+1<<". kugle: ";
                std::cin>>x;
                std::cin>>y;
                std::cin>>z;
            }
        }
        std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
        std::cin>>r;
        if(!(std::cin) || r<0) {
            std::cout<<"Ilegalan poluprecnik"<<std::endl;
            std::cin.clear();
            std::cin.ignore(1000,'\n');
            i--;
            T=true;
        }
        if(!T) {
            std::shared_ptr<NepreklapajucaKugla> p(std::make_shared<NepreklapajucaKugla>(NepreklapajucaKugla(x,y,z,r)));
            v.push_back(p);
        }
    }
        std::cout<<"Kugle nakon obavljenog sortiranja: "<<std::endl;
    std::for_each(v.begin(),v.end(), [] (std::shared_ptr<NepreklapajucaKugla> p) {
        p->Ispisi();
    });
    std::sort(v.begin(),v.end(), [] (std::shared_ptr<NepreklapajucaKugla> p1, std::shared_ptr<NepreklapajucaKugla> p2) {
        return (p1->DajPovrsinu()<p2->DajPovrsinu());
    });
    return 0;
}
