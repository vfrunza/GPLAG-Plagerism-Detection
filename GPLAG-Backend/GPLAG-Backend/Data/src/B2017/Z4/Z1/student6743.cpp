#include <iostream>
#include<tuple>
#include<cmath>
#include<stdexcept>

class Kugla{
static const double eps(std::pow(10,-10));
double x,y,z,r;
public:    
explicit Kugla(double r = 0){ if(r<0) throw std::domain_error("Ilegalan poluprecnik"); Kugla::r=r; x=0;y=0;z=0; }
Kugla(double x, double y, double z, double r = 0): x(x),y(y),z(z),r(r) {if(r<0) throw std::domain_error("Ilegalan poluprecnik");}
explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0);
double DajX() const{ return x; }
double DajY() const{ return y; }
double DajZ() const{ return z; }
std::tuple<double, double, double> DajCentar() const{ return std::make_tuple(x,y,z); }
double DajPoluprecnik() const{ return r; }
double DajPovrsinu() const{ return 16.*r*r*atan(1.); }
double DajZapreminu() const{ return ((4./3)*r*r*r*4.*atan(1.)); }
Kugla &PostaviX(double x){ Kugla::x=x; return *this;}
Kugla &PostaviY(double y){ Kugla::y=y; return *this;}
Kugla &PostaviZ(double z){ Kugla::z=z; return *this;}
Kugla &PostaviCentar(double x, double y, double z){ Kugla::x=x; Kugla::y=y; Kugla::z=z; return *this;}
Kugla &PostaviCentar(const std::tuple<double, double, double> &centar);
Kugla &PostaviPoluprecnik(double r){ Kugla::r=r; return *this;}
void Ispisi() const;
void Transliraj(double delta_x, double delta_y, double delta_z){ x+=delta_x; y+=delta_y; z+=delta_z; }
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
 
Kugla::Kugla(const std::tuple<double, double, double> &centar, double r = 0){
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    x=std::get<0>(centar); y=std::get<1>(centar); z=std::get<2>(centar);
    Kugla::r=r;
}
 
Kugla &Kugla::PostaviCentar(const std::tuple<double, double, double> &centar){
    x=std::get<0>(centar); y=std::get<1>(centar); z=std::get<2>(centar);
    return *this;
} 
 
bool Kugla::DaLiSuIdenticne(const Kugla &k1, const Kugla &k2){
    if(std::abs(k1.x-k2.x)<eps*(std::abs(k1.x)+std::abs(k2.x) && std::abs(k1.y-k2.y)<eps*(std::abs(k1.y)+std::abs(k2.y)) && 
    std::abs(k1.z-k2.z)<eps*(std::abs(k1.z)+std::abs(k2.z) && std::abs(k1.r-k2.r)<eps*(std::abs(k1.r)+std::abs(k2.r)) 
     return true;
     return false;
}

int main ()
{
	return 0;
}
