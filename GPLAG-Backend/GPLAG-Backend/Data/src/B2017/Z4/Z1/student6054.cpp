/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <cmath>
#define PI 4*atan(1);
class Kugla {
  double x,y,z,r;
  public:
  explicit Kugla(double r = 0){
    if(r<0){
      throw std::domain_error("Ilegalan poluprecnik");
    }
    Kugla::x=x;
    x=0;
    Kugla::y=y;
    y=0;
    Kugla::z=z;
    z=0;
    Kugla::r=r;
  }
  Kugla(double x, double y, double z, double r = 0){
    if(r<0){
      throw std::domain_error("Ilegalan poluprecnik");
    }
    Kugla::x=x;
    Kugla::y=y;
    Kugla::z=z;
    Kugla::r=r;
  }
  explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0){
    if(r<0){
      throw std::domain_error("Ilegalan poluprecnik");
    }
  }
  double DajX() const {
    return x;
  }
  double DajY() const{
    return y;
  }
  double DajZ() const{
    return z;
  }
  std::tuple<double, double, double> DajCentar() const{
    return centar;
  }
  double DajPoluprecnik() const{
    return r;
  }
  double DajPovrsinu() const;
  double DajZapreminu() const{
    double v;
    v=(4./3)*PI*std::pow(r,3);
    return v;
  }
  Kugla &PostaviX(double x);
  Kugla &PostaviY(double y);
  Kugla &PostaviZ(double z);
  Kugla &PostaviCentar(double x, double y, double z);
  Kugla &PostaviCentar(const std::tuple<double, double, double> &centar);
  Kugla &PostaviPoluprecnik(double r);
  void Ispisi() const{
    std::cout<<"{("<<this->DajX()<<","<<this->DajY()<<","<<this->DajZ()<<"),"<<this->DajPoluprecnik()<<"}"
  }
  void Transliraj(double delta_x, double delta_y, double delta_z){
    Kugla::x+=delta_x;
    Kugla::y+=delta_y;
    Kugla::z+=delta_z;
  }
  friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2){
    if ()
  }
  friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
  bool DaLiSadrzi(const Kugla&k) const;
  friend double RastojanjeCentara(const Kugla &k1,const Kugla &k2);
  
  

  
};

int main ()
{
  int n;
  std::cout<<"Unesite n: ";
  std::cin>>n;
  std::shared:ptr<double> p;
  p=new Kugla*[n];
  
	return 0;
}
