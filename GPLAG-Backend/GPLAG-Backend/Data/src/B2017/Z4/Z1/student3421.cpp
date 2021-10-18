/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <cmath>
#include <vector>
#include <memory>
#include <new>

const double pi=4*atan(1);
const int epsilon = 0.0000000001;

class Kugla{
    double x,y,z,r;
   
    public:
    
explicit Kugla(double r = 0): x(0), y(0), z(0){};
Kugla(double x, double y, double z, double r = 0): x(x), y(y), z(z){
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
}


explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0): x(std::get<0>(centar)), y(std::get<1>(centar)), z(std::get<2>(centar)) {
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
}

double DajX() const {return x;}
double DajY() const {return y;}
double DajZ() const {return z;}

std::tuple<double, double, double> DajCentar() const {
     auto v3(std::tie(x, y, z));
     return v3;
}
double DajPoluprecnik() const {return r;}
double DajPovrsinu() const {return 4*pi*r*r;}
double DajZapreminu() const {return (4/3)*r*r*r*pi;}
Kugla &PostaviX(double x) { Kugla::x=x;  return *this;} 
Kugla &PostaviY(double y) { Kugla::y=y; return *this;}
Kugla &PostaviZ(double z) { Kugla::z=z; return *this;}

Kugla &PostaviCentar(double x, double y, double z){
    Kugla::x=x; Kugla::y=y; Kugla::z=z;
    return *this;
}
    
Kugla &PostaviCentar(const std::tuple<double, double, double> &centar){
    Kugla::x=std::get<0>(centar);
    Kugla::y=std::get<1>(centar);
    Kugla::z=std::get<2>(centar);
     return *this;
}
Kugla &PostaviPoluprecnik(double r){
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    Kugla::r=r;
    return *this;
}
void Ispisi() const{
    std::cout<<"{ ("<<x<<", "<<y<<", "<<z<<"), "<<r<<"}";
}
void Transliraj(double delta_x, double delta_y, double delta_z){
    Kugla::x += delta_x;
    Kugla::y += delta_y;
    Kugla::z += delta_z;
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

bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2){
    if((abs(k1.x-k2.x))<epsilon*(abs(k1.x)+abs(k2.x)) && (abs(k1.y-k2.y))<epsilon*(abs(k1.y)+abs(k2.y)) && 
    (abs(k1.z-k2.z))<epsilon*(abs(k1.z)+abs(k2.z)) && (abs(k1.r-k2.r))<epsilon*(abs(k1.r)+abs(k2.r))) return true;
    return false;
}

bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2){
    if((abs(k1.r-k2.r))<epsilon*(abs(k1.r)+abs(k2.r))) return true;
    return false;
}

bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2){
    if((abs(k1.x-k2.x))<epsilon*(abs(k1.x)+abs(k2.x)) && (abs(k1.y-k2.y))<epsilon*(abs(k1.y)+abs(k2.y)) && 
    (abs(k1.z-k2.z))<epsilon*(abs(k1.z)+abs(k2.z))) return true;
    return false;
}

bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2){
    if((abs(k1.x*k2.x + k1.y*k2.y + k1.z*k2.z) < abs(k1.r - k2.r)) || (abs(k1.x*k2.x + k1.y*k2.y + k1.z*k2.z) > abs(k1.r - k2.r)) )return false;
    return true;
}

bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2){
    if((abs(k1.x*k2.x + k1.y*k2.y + k1.z*k2.z) < (k1.r+k2.r)) && (abs(k1.x*k2.x + k1.y*k2.y + k1.z*k2.z) > abs(k1.r - k2.r))) return true;
    return false;
}



int main ()
{
    Kugla k;
    std::shared_ptr<Kugla> pok_na_k;
    int n; 
    std::cout<<"Unesite broj kugla: ";
    std::cin>>n;
    std::vector<std::shared_ptr<Kugla>> v;
    double x,y,z,r;
    for(int i=0; i<n; i++){
        std::cout<<"Unesite centar "<<i+1<<". kugle: ";
        std::cin>>x;
        std::cin>>y;
        std::cin>>z;
        std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
        std::cin>>r;
     k.PostaviCentar(x,y,z);
     k.PostaviPoluprecnik(r);
     v.push_back(std::make_shared<Kugla>(x,y,z,r));
   
       
        
    }
     
    
}
