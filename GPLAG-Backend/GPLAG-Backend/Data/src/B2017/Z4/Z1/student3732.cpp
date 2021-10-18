/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>
#include <vector>
#include <utility>
#define PI 4*atan(1)
#define EPSILON 0.000000001
class Kugla
{
    double x,y,z,r;
public:
    explicit Kugla(double r=0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik ");
        Kugla::r=r;
    }
    Kugla (double x,double y,double z,double r=0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik ");
        Kugla::x=x;
        Kugla::y=y;
        Kugla::z=z;
        Kugla::r=r;
    }
    explicit Kugla(const std::tuple<double,double,double> &centar,double r=0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik ");
        Kugla::x=std::get<0>(centar);
        Kugla::y=std::get<1>(centar);
        Kugla::z=std::get<2>(centar);
        Kugla::r=r;
    }
    double DajX() const {
        return x;
    }
    double DajY()const {
        return y;
    }
    double DajZ()const {
        return z;
    }
    std::tuple<double,double,double> DajCentar() const {
        return std::tie(x,y,z);
    }
    double DajPoluprecnik()const {
        return r;
    }
    double DajPovrsinu()const {
        return (4.0*r*r*PI);
    }
    double DajZapreminu()const {
        return (4.0/3.0*(r*r*r)*PI);
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
    Kugla &PostaviCentar(double x,double y,double z) {
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
    void Ispisi()const {
        std::cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}";
    }
    void Transliraj(double delta_x,double delta_y,double delta_z) {
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
        Kugla k1;
        k1.x=x;
        k1.y=y;
        k1.z=z;
        k1.r=r;
        if(RastojanjeCentara(k1,k)<k1.r || RastojanjeCentara(k1,k)<k.r) return true;
        return false;
    }
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);

};

bool DaLiSuIdenticne(const Kugla &k1,const Kugla &k2)
{
    if(fabs(k1.x-k2.x)<=EPSILON*(fabs(k1.x)+fabs(k2.x)) && fabs(k1.y-k2.y)<=EPSILON*(fabs(k1.y)+fabs(k2.y)) && fabs(k1.z-k2.z)<=EPSILON*(fabs(k1.z)+fabs(k2.z)) && fabs(k1.r-k2.r)<=EPSILON*(fabs(k1.r)+fabs(k2.r))) return true;
    return false;
}
bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2)
{
    if(fabs(k1.r-k2.r)<EPSILON*(fabs(k1.r)+fabs(k2.r))) return true;
    return false;
}
bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2)
{
    if(fabs(k1.x-k2.x)<EPSILON*(fabs(k1.x)+fabs(k2.x)) && fabs(k1.y-k2.y)<EPSILON*(fabs(k1.y)+fabs(k2.y)) && fabs(k1.z-k2.z)<EPSILON*(fabs(k1.z)+fabs(k2.z))) return true;
    return false;
}

bool DaLiSeDodirujuIznutra(const Kugla &k1,const Kugla &k2){
    double x=RastojanjeCentara(k1,k2);
    if(fabs(x-fabs(k1.r-k2.r))<=EPSILON*(fabs(x)+fabs(k1.r-k2.r))) return true;
    return false;
}
bool DaLiSeDodirujuIzvana(const Kugla &k1,const Kugla &k2){
    double x=RastojanjeCentara(k1,k2);
    if(fabs(x-fabs(k1.r+k2.r))<=EPSILON*(fabs(x)+fabs(k1.r+k2.r))) return true;
    return false;
}
bool DaLiSeSijeku(const Kugla &k1,const Kugla &k2){
    double x=RastojanjeCentara(k1,k2);
    if(x>fabs(k1.r-k2.r)) return true;
    return false;
}
double RastojanjeCentara(const Kugla &k1,const Kugla &k2){
    return sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z));
}
bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2){
    if(DaLiSeSijeku(k1,k2)) return true;
    return false;
}


int main ()
{
    int n(0),a(0),b(0),c(0),r(0);
    std::cout<<"Unesite broj kugla: ";
    for(;;){
    if(!(std::cin>>n) || n<=0){ std::cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;
        std::cin.clear();
        std::cin.ignore(1000,'\n');
    }
    else break;    
    }
    std::vector<std::shared_ptr<Kugla>> v(n);
    for(int i=0; i<n; i++) {
        for(;;){
        std::cout<<"Unesite centar "<<i+1<<". kugle: ";
        if(!(std::cin>>a>>b>>c)){std::cout<<"Neispravan centar"<<std::endl; std::cin.clear(); std::cin.ignore(1000,'\n');}
        else break;    
        }
        for(;;){
        std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
        if(!(std::cin>>r)){std::cout<<"Ilegalan poluprecnik"<<std::endl; std::cin.clear(); std::cin.ignore(1000,'\n');for(;;){
        std::cout<<"Unesite centar "<<i+1<<". kugle: ";
        if(!(std::cin>>a>>b>>c)){std::cout<<"Neispravan centar"<<std::endl; std::cin.clear(); std::cin.ignore(1000,'\n');}
        else break;    
        }}
        else break;
        }
        try {
            v[i]=std::make_shared<Kugla>(a,b,c,r);
        } catch(std::domain_error izuzetak) {
            std::cout<<izuzetak.what()<<std::endl;
            i--;
        }
    }
    double x1,y1,z1;
    std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    for(;;){
    if(!(std::cin>>x1>>y1>>z1)){ std::cout<<"Neispravni parametri translacije, unesite ponovo!"<<std::endl; std::cin.clear();std::cin.ignore(1000,'\n');}
    else break;
    }
    std::transform(v.begin(),v.end(),v.begin(),[x1,y1,z1](std::shared_ptr<Kugla> pok) {
        std::shared_ptr<Kugla> pokic;
        pokic=std::make_shared<Kugla>(pok->DajX()+x1,pok->DajY()+y1,pok->DajZ()+z1,pok->DajPoluprecnik());
        return pokic;
    });
    std::sort(v.begin(),v.end(),[](std::shared_ptr<Kugla> pok1,std::shared_ptr<Kugla> pok2) {
        return pok1->DajZapreminu()<pok2->DajZapreminu();
    });
    std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<std::endl;
    for_each(v.begin(),v.end(),[](std::shared_ptr<Kugla> pok) {
        Kugla pom;
        pom.PostaviCentar(pok->DajX(),pok->DajY(),pok->DajZ());
        pom.PostaviPoluprecnik(pok->DajPoluprecnik());
        pom.Ispisi();
        std::cout<<std::endl;
    });
    auto maxic=std::max_element(v.begin(),v.end(),[](std::shared_ptr<Kugla> x,std::shared_ptr<Kugla> y) {
        return x->DajPovrsinu()<y->DajPovrsinu();
    });
    std::cout<<"Kugla sa najvecom povrsinom je: ";
    std::cout<<"{("<<(*maxic)->DajX()<<","<<(*maxic)->DajY()<<","<<(*maxic)->DajZ()<<"),"<<(*maxic)->DajPoluprecnik()<<"}"<<std::endl;
    std::vector<std::pair<Kugla,Kugla>> provjera;
   for_each(v.begin(),v.end(),[v,&provjera](std::shared_ptr<Kugla> pok){
      for_each(v.begin(),v.end(),[pok,&provjera](std::shared_ptr<Kugla> pokic){
          if(DaLiSeSijeku(*pok,*pokic))
             {Kugla pom;
              pom.PostaviCentar(pok->DajX(),pok->DajY(),pok->DajZ());
        pom.PostaviPoluprecnik(pok->DajPoluprecnik());
         Kugla pom1;
        pom1.PostaviCentar(pokic->DajX(),pokic->DajY(),pokic->DajZ());
        pom1.PostaviPoluprecnik(pokic->DajPoluprecnik());
        std::pair<Kugla,Kugla> a;
             a=std::make_pair(pom,pom1);
             int br=count_if(provjera.begin(),provjera.end(),[a](std::pair<Kugla,Kugla> b){if(((DaLiSuIdenticne(a.second,b.first) && DaLiSuIdenticne(a.first,b.second)) || ((DaLiSuIdenticne(a.first,b.first)) && DaLiSuIdenticne(a.second,b.second)))) return true; return false;});
          if(br==0){
          std::cout<<"Presjecaju se kugle: ";
        pom.Ispisi();
        std::cout<<std::endl;
        pom1.Ispisi();
              std::cout<<std::endl;
              provjera.push_back(std::make_pair(pom,pom1));
          }}
      });
   });
   if(provjera.size()==0) std::cout<<"Ne postoje kugle koje se presjecaju!";
   
    return 0;
}
