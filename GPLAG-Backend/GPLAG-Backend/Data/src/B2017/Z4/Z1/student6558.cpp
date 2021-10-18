#include <iostream>
#include <tuple>
#include <algorithm>
#include <stdexcept>
#include <cmath>
const double eps=1e-10;
const double PI(4*atan(1));
class Kugla{
  double poluprecnik;
  double x,y,z;
  void ProvjeriPoluprecnik(double r) const {
      if(r<0) throw std::domain_error("Ilegalan poluprecnik");
  }
  public:
  explicit Kugla(double r=0)  { ProvjeriPoluprecnik(r); poluprecnik=r; x=y=z=0; }
  Kugla(double x, double y, double z, double r=0) : x(x), y(y), z(z){ ProvjeriPoluprecnik(r); poluprecnik=r;}
  explicit Kugla(const std::tuple<double,double,double> &centar, double r=0) { ProvjeriPoluprecnik(r); poluprecnik=r; std::tie(x,y,z)=centar;}
  double DajX() const{   return x;}
  double DajY() const{  return y;}
  double DajZ() const{  return z;}
  std::tuple<double,double,double> DajCentar() const{ return std::make_tuple(x,y,z); }
  double DajPoluprecnik() const{ return poluprecnik; }
  double DajPovrsinu() const{ return 4*pow(poluprecnik,2)*PI; }
  double DajZapreminu() const { return (4./3.)*pow(poluprecnik,3)*PI; }
  Kugla &PostaviX(double x){Kugla::x=x; return *this;}
  Kugla &PostaviY(double y){Kugla::y=y; return *this;}
  Kugla &PostaviZ(double z){Kugla::z=z; return *this;}
  Kugla &PostaviCentar(double x, double y, double z){ std::tie(Kugla::x, Kugla::y,Kugla::z)=std::make_tuple(x,y,z); return *this;}
  Kugla &PostaviCentar(const std::tuple<double,double, double> &centar) {std::tie(x,y,z)=centar; return *this; }
  Kugla &PostaviPoluprecnik(double r) { poluprecnik=r; return *this;}
  void Ispisi() const { std::cout<<"{("<<x<<","<<y<<","<<z<<"),"<<poluprecnik<<"}"; }
  void Transliraj(double delta_x, double delta_y, double delta_z) {x+=delta_x; y+=delta_y; z+=delta_z; }
  friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
};
bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2){
  if(fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik())>eps) return false;
  if(fabs(k1.DajX()-k2.DajX())>eps) return false;
  if(fabs(k1.DajY()-k2.DajY())>eps) return false;
  if(fabs(k1.DajZ()-k2.DajZ())>eps) return false;
  return true;
}
bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2){
  if(fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik())>eps) return false;
  return true;
}
bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2){
  if(fabs(k1.DajX()-k2.DajX())>eps) return false;
  if(fabs(k1.DajY()-k2.DajY())>eps) return false;
  if(fabs(k1.DajZ()-k2.DajZ())>eps) return false;
  return true;
}
bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2){
  double udaljenost(std::sqrt(pow(k1.DajX()-k2.DajX(),2)+pow(k1.DajY()-k2.DajY(),2)+pow(k1.DajZ()-k2.DajZ(),2)));
  double zbir(k1.DajPoluprecnik()+k2.DajPoluprecnik());
  if(fabs(zbir-udaljenost)<eps) return true;
  return false;
}
bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2){
  double udaljenost(std::sqrt(pow(k1.DajX()-k2.DajX(),2)+pow(k1.DajY()-k2.DajY(),2)+pow(k1.DajZ()-k2.DajZ(),2)));
  double zbir(fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik()));
  if(fabs(zbir-udaljenost)<eps) return true;
  return false;
}
bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2){
  double udaljenost(std::sqrt(pow(k1.DajX()-k2.DajX(),2)+pow(k1.DajY()-k2.DajY(),2)+pow(k1.DajZ()-k2.DajZ(),2)));
  double zbir(fabs(k1.DajPoluprecnik()+k2.DajPoluprecnik()));
  double razlika(fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik()));
  if(udaljenost<razlika || udaljenost<zbir) return true;
  return false;
}
bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2){
  double udaljenost(std::sqrt(pow(k1.DajX()-k2.DajX(),2)+pow(k1.DajY()-k2.DajY(),2)+pow(k1.DajZ()-k2.DajZ(),2)));
  double zbir(fabs(k1.DajPoluprecnik()+k2.DajPoluprecnik()));
  double razlika(fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik()));
  if(udaljenost<razlika && udaljenost+k2.DajPoluprecnik()>k1.DajPoluprecnik()) return true;
  return false;
}
int main ()
{
  Kugla sfera(2);
  Kugla sfera2(1);
 // sfera2.PostaviX(0.34);
  
  std::cout<<std::boolalpha<<DaLiSeSijeku(sfera,sfera2);
	return 0;
}
