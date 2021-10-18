/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <tuple>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>
#include <utility>
const double PI= 4*std::atan(1);
const double e=0.0000000001;
class NepreklapajucaKugla
{
    double x,y,z,r;
   
public:
    explicit NepreklapajucaKugla(double r=0) {
        if(r<0)throw std::domain_error("Ilegalan poluprecnik");
        NepreklapajucaKugla::r=r;
        x=0;
        y=0;
        z=0;
    }
    NepreklapajucaKugla(double x,double y,double z,double r=0) {
        if(r<0)throw std::domain_error("Ilegalan poluprecnik");
        NepreklapajucaKugla::x=x;
        NepreklapajucaKugla::y=y;
        NepreklapajucaKugla::z=z;
        NepreklapajucaKugla::r=r;
    }
    explicit NepreklapajucaKugla(const std::tuple<double,double,double> &centar, double r=0) {
        if(r<0)throw std::domain_error("Ilegalan poluprecnik");
        x=std::get<0>(centar);
        y=std::get<1>(centar);
        z=std::get<2>(centar);
        NepreklapajucaKugla::r=r;
    }
    double DajX()const {
        return x;
    }
    double DajY()const {
        return y;
    }
    double DajZ()const {
        return z;
    }
    std::tuple<double,double,double> DajCentar() const {
        return std::make_tuple(x,y,z);
    }
    double DajPoluprecnik() const {
        return r;
    }
    double DajPovrsinu() const {
        return 4*PI*r*r;
    }
    double DajZapreminu() const {
        return (4./3)*PI*r*r*r;
    }
    NepreklapajucaKugla &PostaviX(double x){
        NepreklapajucaKugla::x=x;
        return *this;
    }
    NepreklapajucaKugla &PostaviY(double y){
        NepreklapajucaKugla::y=y;
        return *this;
    }
    NepreklapajucaKugla &PostaviZ(double z){
        NepreklapajucaKugla::z=z;
        return *this;
    }
    NepreklapajucaKugla &PostaviCentar(double x, double y, double z){
        NepreklapajucaKugla::x=x;
        NepreklapajucaKugla::y=y;
        NepreklapajucaKugla::z=z;
        return *this;
    }
    NepreklapajucaKugla &PostaviCentar(const std::tuple<double,double,double> &centar){
        x=std::get<0>(centar);
        y=std::get<1>(centar);
        z=std::get<2>(centar);
        return *this;
    }
    NepreklapajucaKugla &PostaviPoluprecnik(double r){
        if(r<0)throw std::domain_error("Ilegalan poluprecnik");
        NepreklapajucaKugla::r=r;
        return *this;
    }
    void Ispisi() const{
        std::cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}";
    }
    void Transliraj(double delta_x, double delta_y, double delta_z){
        x+=delta_x;
        y+=delta_y;
        z+=delta_z;
    }

    friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
    //RastojanjeCentara(k1,k2)<(k1.r+k2.r)&&RastojanjeCentara(k1,k2)>std::fabs(k1.r-k2.r)
};


 double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){
     return std::sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z));
 }


 
int main ()
{
   int n;
    std::cout<<"Unesite broj kugli: ";
    std::cin>>n;
    while(n<=0||!std::cin){
        std::cout<<"Neispravan broj kugli, unesite ponovo!\n";
        std::cin.clear();
        std::cin.ignore(100000,'\n');
        std::cin>>n;
    }
    std::vector<std::shared_ptr<NepreklapajucaKugla>> vektor;
    double x,y,z,r;
    for(int i=0;i<n;i++){
        while(vektor.size()!=i+1){
        try{
        std::cout<<"Unesite centar za "<<i+1<<". kuglu: ";
        std::cin>>x>>y>>z;
        if(!std::cin){
            std::cin.clear();
            std::cin.ignore(100000,'\n');
            throw std::domain_error("Neispravan centar");
        }
        std::cout<<"Unesite poluprecnik: ";
        std::cin>>r;
        if(!std::cin){
            std::cin.clear();
            std::cin.ignore(100000,'\n');
            throw std::domain_error("Ilegalan poluprecnik");
        }
        vektor.push_back(std::make_shared<NepreklapajucaKugla>(x,y,z,r));
        }
        catch(std::domain_error e){
            std::cout<<e.what()<<std::endl;
        }
        }
        
    }
  
    std::sort(vektor.begin(),vektor.end(),[](std::shared_ptr<NepreklapajucaKugla> pok1,std::shared_ptr<NepreklapajucaKugla>pok2){return pok1->DajPovrsinu()<pok2->DajPovrsinu();});
    std::cout<<"\nKugle nakon obavljenog sortiranja: \n";
    std::for_each(vektor.begin(),vektor.end(),[](std::shared_ptr<NepreklapajucaKugla>pok){pok->Ispisi();std::cout<<std::endl;});
    return 0;
}
