/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include<stdexcept>
#include<cmath>
#include<tuple>
#include<vector>
#include<memory>
#define pi 4*atan(1.)
#define eps pow(10,-10)
class NepreklapajucaKugla{
     
     double x,y,z,r;
     double udaljenost(const NepreklapajucaKugla &k1,const NepreklapajucaKugla &k2){
       double  d=sqrt((k2.x-k1.x)*(k2.x-k1.x) +(k2.y-k1.y)*(k2.y-k1.y)+(k2.z-k1.z)*(k2.z-k1.z));
         return d;
     }
public:
explicit NepreklapajucaKugla(double r = 0){
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    x=r;
}
NepreklapajucaKugla(double x, double y, double z, double r = 0){
    NepreklapajucaKugla::x=x;
    NepreklapajucaKugla::y=y;
    NepreklapajucaKugla::z=z;
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    NepreklapajucaKugla::r=r;
}
explicit NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r = 0){
  x=std::get<0>(centar);
  y=std::get<1>(centar);
  z=std::get<2>(centar);
  if(r<0) throw std::domain_error("Ilegalan poluprecnik");
  NepreklapajucaKugla::r=r;
}
double DajX() const{ return x;}
double DajY() const{ return y;}
double DajZ() const{return z;}
std::tuple<double, double, double> DajCentar() const{std::tuple<double,double,double> t;
t=std::make_tuple(r);
return t;}
double DajPoluprecnik() const{ return r;}
double DajPovrsinu() const{return (4*r*r*pi);}
double DajZapreminu() const{return ((4.)/3*r*r*r*pi);}
NepreklapajucaKugla &PostaviX(double x) {NepreklapajucaKugla::x=x; return *this;}
NepreklapajucaKugla &PostaviY(double y){NepreklapajucaKugla::y=y; return *this;}
NepreklapajucaKugla &PostaviZ(double z){NepreklapajucaKugla::z=z; return *this;}
NepreklapajucaKugla &PostaviCentar(double x, double y, double z){NepreklapajucaKugla::x=x; NepreklapajucaKugla::y=y; NepreklapajucaKugla::z=z; return *this;}
NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar);
NepreklapajucaKugla &PostaviPoluprecnik(double r){
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    NepreklapajucaKugla::r=r;
    return *this;
    }
void Ispisi() const{std::cout<<"{ ("<<x<<","<<y<<","<<z<<"),"<<r<<" }";}

void Transliraj(double delta_x, double delta_y, double delta_z){ x+=delta_x; y+=delta_y; z+=delta_z;}

bool DaLiSadrzi(const NepreklapajucaKugla &k) const;
friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
};


double RastojanjeCentara(const NepreklapajucaKugla &k1,const NepreklapajucaKugla &k2){
    return sqrt((k1.r-k2.r)*(k1.r-k2.r));
}
int main ()
{
    std::cout<<"Unesite prirodan broj n";
    int n;
    std::cin>>n;
    std::vector<std::unique.ptr<double>>pok;    
	return 0;
}
