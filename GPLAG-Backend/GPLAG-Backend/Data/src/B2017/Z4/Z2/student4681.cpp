/B2017/2018: Zadaća 4, Zadatak 2
#include <iostream>
#include "cmath"
#include "stdexcept"
#include "tuple"
#include "memory"
#include "vector"
#include "algorithm"
double pi = 3.14159265359;
 bool jednako(double x, double y = 0) {
        double epsi(std::pow(10,-10));
        return (std::abs(x-y)<epsi*(std::abs(x)+std::abs(y)));
    }
class NepreklapajucaKugla {
  static NepreklapajucaKugla* start;
  NepreklapajucaKugla* next;
  double x, y, z, r;
  public:
  explicit Kugla(double r = 0) { 
      if(r < 0) throw std::domain_error("Ilegalan poluprecnik");
      this->r = r; this->x = 0; this->y = 0; this->z = 0;
  }
  Kugla(double x, double y, double z, double r = 0) {
      if(r < 0) throw std::domain_error("Ilegalan poluprecnik");
      this->x = x;
      this->y = y;
      this->z = z;
      this->r = r;
  }
  
  explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0) {
      if(r < 0) throw std::domain_error("Ilegalan poluprecnik");
      this->x = std::get<0>(centar);
      this->y = std::get<1>(centar);
      this->z = std::get<2>(centar);
      this->r = r;
  }
  
  ~NepreklapajucaKugla() {
      
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
      return std::make_tuple(x, y, z);
  }
  
  double DajPoluprecnik() const {
      return r;
  }
  
  double DajPovrsinu() const {
      return 4 * pi * std::pow(r,2);
  }
  
  double DajZapreminu() const {
      return (DajPovrsinu() * r) / 3;
  }
  
  Kugla &PostaviX(double x) {
      this->x = x;
      return *this;
  }
  
  Kugla &PostaviY(double y) {
      this->y = y;
      return *this;
  }
  
  Kugla &PostaviZ(double z) {
      this->z = z;
      return *this;
  }
  
  Kugla &PostaviCentar(double x, double y, double z) {
      this->x = x;
      this->y = y;
      this->z = z;
      return *this;
  }
  
  Kugla &PostaviCentar(const std::tuple<double, double, double> &centar) {
      this->x = std::get<0>(centar);
      this->y = std::get<1>(centar);
      this->z = std::get<2>(centar);
      return *this;
  }
  
  Kugla &PostaviPoluprecnik(double r) {
      if(r < 0) throw std::domain_error("Ilegalan poluprecnik");
      this->r = r;
      return *this;
  }
  
  void Ispisi() const {
      std::cout << "{(" << x << "," << y << "," << z << ")," << r << "}";
  }
  
  void Transliraj(double delta_x, double delta_y, double delta_z) {
      x += delta_x;
      y += delta_y;
      z += delta_z;
  }
 
  bool DaLiSadrzi(const Kugla &k) const {
      double distance = std::sqrt(std::pow(k.DajX()-x, 2) + std::pow(k.DajY()-y, 2) + std::pow(k.DajZ()-z, 2));
      double x(distance - k.r); if(x<0) x*=-1;
    double y(distance + k.r); if(y<0) y*=-1;
        if(!jednako(k.r)&& !jednako(r))
        if(x < r && y < r) return true;
      return false;
  }
  
  friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);
};
    double RastojanjeCentara(const Kugla &k1, const Kugla &k2) {
        return std::sqrt(std::pow(k2.DajX()-k1.DajX(), 2) + std::pow(k2.DajY()-k1.DajY(), 2) + std::pow(k2.DajZ()-k1.DajZ(), 2));
    }
    
int main ()
{
	return 0;
}
