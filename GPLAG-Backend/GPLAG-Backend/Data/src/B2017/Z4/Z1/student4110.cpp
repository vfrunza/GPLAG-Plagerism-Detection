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
class Kugla
{
    double x,y,z,r;
   
public:
    explicit Kugla(double r=0) {
        if(r<0)throw std::domain_error("Ilegalan poluprecnik");
        Kugla::r=r;
        x=0;
        y=0;
        z=0;
    }
    Kugla(double x,double y,double z,double r=0) {
        if(r<0)throw std::domain_error("Ilegalan poluprecnik");
        Kugla::x=x;
        Kugla::y=y;
        Kugla::z=z;
        Kugla::r=r;
    }
    explicit Kugla(const std::tuple<double,double,double> &centar, double r=0) {
        if(r<0)throw std::domain_error("Ilegalan poluprecnik");
        x=std::get<0>(centar);
        y=std::get<1>(centar);
        z=std::get<2>(centar);
        Kugla::r=r;
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
    Kugla &PostaviX(double x){
        Kugla::x=x;
        return *this;
    }
    Kugla &PostaviY(double y){
        Kugla::y=y;
        return *this;
    }
    Kugla &PostaviZ(double z){
        Kugla::z=z;
        return *this;
    }
    Kugla &PostaviCentar(double x, double y, double z){
        Kugla::x=x;
        Kugla::y=y;
        Kugla::z=z;
        return *this;
    }
    Kugla &PostaviCentar(const std::tuple<double,double,double> &centar){
        x=std::get<0>(centar);
        y=std::get<1>(centar);
        z=std::get<2>(centar);
        return *this;
    }
    Kugla &PostaviPoluprecnik(double r){
        if(r<0)throw std::domain_error("Ilegalan poluprecnik");
        Kugla::r=r;
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
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
    
    bool DaLiSadrzi(const Kugla &k) const{
        return(RastojanjeCentara(*this,k)<std::fabs(r-k.r));
    }
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);

};

 bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2){
     return (std::fabs(k1.x-k2.x)<=e*(std::fabs(k1.x)+std::fabs(k2.x)) && std::fabs(k1.y-k2.y)<=e*(std::fabs(k1.y)+std::fabs(k2.y)) && 
     std::fabs(k1.z-k2.z)<=e*(std::fabs(k1.z)+std::fabs(k2.z)) && std::fabs(k1.r-k2.r)<=e*(std::fabs(k1.r)+std::fabs(k2.r))) ;
 }
 bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2){
      return (std::fabs(k1.r-k2.r)<=e*(std::fabs(k1.r)+std::fabs(k2.r)));    
 }
 bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2){
     return (std::fabs(k1.x-k2.x)<=e*(std::fabs(k1.x)+std::fabs(k2.x)) && std::fabs(k1.y-k2.y)<e*(std::fabs(k1.y)+std::fabs(k2.y)) && 
     std::fabs(k1.z-k2.z)<e*(std::fabs(k1.z)+std::fabs(k2.z))); 
 }
 double RastojanjeCentara(const Kugla &k1, const Kugla &k2){
     return std::sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z));
 }
 bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2){
     return(std::fabs(RastojanjeCentara(k1,k2)-(k1.r+k2.r))<=e*(std::fabs(RastojanjeCentara(k1,k2)+std::fabs(k1.r+k2.r))));
 }
 bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2){
     return(std::fabs(RastojanjeCentara(k1,k2)-std::fabs(k1.r-k2.r))<=e*(std::fabs(RastojanjeCentara(k1,k2)+std::fabs(k1.r-k2.r))));
 }
 bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2){
     return(RastojanjeCentara(k1,k2)<(k1.r+k2.r)&&RastojanjeCentara(k1,k2)>std::fabs(k1.r-k2.r));
 }
 bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2){
     return(DaLiSeSijeku(k1,k2));
 }

 
int main ()
{
    int n;
    std::cout<<"Unesite broj kugla: ";
    std::cin>>n;
    while(n<=0||!std::cin){
        std::cout<<"Neispravan broj kugli, unesite ponovo!\n";
        std::cin.clear();
        std::cin.ignore(100000,'\n');
        std::cin>>n;
    }
    std::vector<std::shared_ptr<Kugla>> vektor;
    double x,y,z,r;
    for(int i=0;i<n;i++){
        while(vektor.size()!=i+1){
        try{
        std::cout<<"Unesite centar "<<i+1<<". kugle: ";
        std::cin>>x>>y>>z;
        if(!std::cin){
            std::cin.clear();
            std::cin.ignore(100000,'\n');
            throw std::domain_error("Neispravan centar");
        }
        std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
        std::cin>>r;
        if(!std::cin){
            std::cin.clear();
            std::cin.ignore(100000,'\n');
            throw std::domain_error("Ilegalan poluprecnik");
        }
        vektor.push_back(std::make_shared<Kugla>(x,y,z,r));
        }
        catch(std::domain_error e){
            std::cout<<e.what()<<std::endl;
        }
        }
        
    }
    std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double d_x,d_y,d_z;
    std::cin>>d_x>>d_y>>d_z;
    while(!std::cin){
        std::cout<<"Neispravni parametri translacije, unesite ponovo!\n";
        std::cin.clear();
        std::cin.ignore(100000,'\n');
        std::cin>>d_x>>d_y>>d_z;
    }
    std::transform(vektor.begin(),vektor.end(),vektor.begin(),[d_x,d_y,d_z](std::shared_ptr<Kugla> pok){ pok->Transliraj(d_x,d_y,d_z); return pok;});
    std::sort(vektor.begin(),vektor.end(),[](std::shared_ptr<Kugla> pok1,std::shared_ptr<Kugla>pok2){return pok1->DajZapreminu()<pok2->DajZapreminu();});
    std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: \n";
    std::for_each(vektor.begin(),vektor.end(),[](std::shared_ptr<Kugla>pok){pok->Ispisi();std::cout<<std::endl;});
    std::cout<<"Kugla sa najvecom povrsinom je: ";
    (*(std::max_element(vektor.begin(),vektor.end(),[](std::shared_ptr<Kugla> pok1,std::shared_ptr<Kugla> pok2){return pok1->DajPovrsinu()<pok2->DajPovrsinu();})))->Ispisi();
   std::cout<<std::endl;
   std::vector<std::shared_ptr<Kugla>> pomocni(vektor);
    int brojac{};
        std::for_each(vektor.begin(),vektor.end(),[&pomocni,&brojac,vektor](std::shared_ptr<Kugla> pok1){pomocni.erase(pomocni.begin()+0);
        std::for_each(pomocni.begin(),pomocni.end(),[pok1,&brojac](std::shared_ptr<Kugla> pok2){
       
        if(DaLiSeSijeku(*pok1,*pok2)) {std::cout<<"Presjecaju se kugle: "; pok1->Ispisi();std::cout<<std::endl;pok2->Ispisi();brojac++;std::cout<<std::endl;}
    });});
    if(!brojac)std::cout<<"Ne postoje kugle koje se presjecaju!";
   
     
    return 0;
}
