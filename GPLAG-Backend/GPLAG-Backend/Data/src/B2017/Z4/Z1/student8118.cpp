/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <tuple>
#include <memory>
#include <vector>
const double pi=4*std::atan(1);
class Kugla{
  double X,Y,Z,R;
  public:
  explicit Kugla(double r=0){
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
      X=0; Y=0; Z=0;
      Kugla::R=r;
  }
  Kugla(double x, double y, double z, double r=0){
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    Kugla::X=x; Kugla::Y=y; Kugla::Z=z; Kugla::R=r;
  }
  explicit Kugla(const std::tuple<double, double, double> &centar, double r=0){
      if(r<0) throw std::domain_error("Ilegalan poluprecnik");
      double x=std::get<0>(centar), y=std::get<1>(centar), z=std::get<2>(centar);
      Kugla::X=x; Kugla::Y=y; Kugla::Z=z; Kugla::R=r;
  }
  double DajX() const { return X;}
  double DajY() const{ return Y;}
  double DajZ() const{ return Z;}
  std::tuple<double, double, double> DajCentar() const{
    std::tuple<double, double, double> pom(X,Y,Z);
    return pom;
  }
  double DajPoluprecnik() const{return R;}
  double DajPovrsinu() const{
      return 4*R*R*pi;
  }
  double DajZapreminu() const{
      return 4*R*R*R*pi/3;
  }
  Kugla &PostaviX(double x){
    Kugla::X=x;
    return *this;
  }
  Kugla &PostaviY(double y){
    Kugla::Y=y;
    return *this;
  }
  Kugla &PostaviZ(double z){
    Kugla::Z=z;
    return *this;
  }
  Kugla &PostaviCentar(double x, double y, double z){
    Kugla::X=x;
    Kugla::Y=y;
    Kugla::Z=z;
    return *this;
  }
  Kugla &PostaviCentar(const std::tuple<double, double, double> &centar);
  Kugla &PostaviPoluprecnik(double r){
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    Kugla::R=r;
    return *this;
  }
  void Ispisi() const{
    std::cout<<"{("<<X<<","<<Y<<","<<Z<<"),"<<R<<"}";
  }
  void Transliraj(double delta_x, double delta_y, double delta_z){
    X+=delta_x;
    Y+=delta_y;
    Z+=delta_z;
  }
  friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSePoklapaju(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
  bool DaLiSadrzi(const Kugla &k) const;
  friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);
};
Kugla &Kugla::PostaviCentar(const std::tuple<double,double,double> &centar){
  double x=std::get<0>(centar), y=std::get<1>(centar), z=std::get<2>(centar);
  Kugla::X=x;
  Kugla::Y=y;
  Kugla::Z=z;
  return *this;
}
bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2){
  if(k1.X==k2.X && k1.Y==k2.Y && k1.Z==k2.Z && k1.R==k2.R) return true;
  return false;
}
bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2){
  if(k1.R==k2.R) return true;
  return false;
}
bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2){
  if(k1.X==k2.X && k1.Y==k2.Y && k1.Z==k2.Z) return true;
  return false;
}
bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2){
  double epsilon(0.000000001), r(RastojanjeCentara(k1,k2)), aps(std::fabs(k1.R+k2.R));
  return (aps-r)<epsilon*aps;
}
bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2){
  double epsilon(0.000000001), r(RastojanjeCentara(k1,k2)), aps(std::fabs(k1.R-k2.R));
  return (aps-r)<epsilon*aps;
}
bool DaLiSePoklapaju(const Kugla &k1, const Kugla &k2){
  double r(RastojanjeCentara(k1, k2));
  return (std::fabs(k1.R-k2.R)<r);
}
bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2){
  double r(RastojanjeCentara(k1, k2));
  return ((std::fabs(k1.R-k2.R)<r) && (std::fabs(k1.R+k2.R)>r));
}
bool Kugla::DaLiSadrzi(const Kugla &k) const{
  double x(k.X-X),y(k.Y-Y),z(k.Z-Z);
  double pom(std::sqrt(x*x + y*y + z*z));
  return pom<k.R+R;
}
double RastojanjeCentara(const Kugla &k1, const Kugla &k2){
  double x, y(k2.Y-k1.Y), z(k2.Z-k1.Z);
  return std::sqrt(x*x + y*y + z*z);
}
int main ()
{
  int n;
  std::cout<<"Unesite broj kugla: ";
  do{
    std::cin>>n;
    if(n>0) break;
    std::cout<<"Neispravan broj kugli, unesite ponovo!";
  }while(n<=0);
  std::vector<std::shared_ptr<Kugla>>
  for(int i=0; i<n; i++){
    std::cout<<"Unesite centar "<<i+1<<". kugle: ";
    Kugla k;
    double pomx, pomy, pomz, pomr;
    std::cin>>pomx>>pomy>>pomz;
    if(pomx)    k.X=pomx; k.Y=pomy; k.Z=pomz;
    std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: "
  }
	return 0;
}
