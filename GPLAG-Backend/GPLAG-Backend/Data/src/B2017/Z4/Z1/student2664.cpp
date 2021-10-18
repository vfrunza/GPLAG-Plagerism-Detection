/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <cmath>

const double PI = 4*std::atan(1);

class Kugla {
  double x , y , z;
  double poluprecnik;
  public: 
  explicit Kugla(double r = 0){
      poluprecnik = r;
  }
  Kugla (double x , double y, double z, double r = 0){
      Kugla::x = x;
      Kugla::y = y;
      Kugla::z = z;
      Kugla::poluprecnik = r;
  }
 // explicit Kugla(const std::tuple<double,double,double> &centar,double r = 0);
  
  double DajX() const{ return x;}
  double DajY() const{ return y;}
  double DajZ() const{return z;}
  
  //std::tuple<double,double,double> DajCentar() const;
  double DajPoluprecnik() const {return poluprecnik; }
  double DajPovrsinu() const { return poluprecnik*poluprecnik*PI; }
  double DajZapreminu() const { return (4/3)*poluprecnik*poluprecnik*poluprecnik*PI;}
  
  Kugla &PostaviX(double x) { Kugla::x = x; return *this;}
  Kugla &PostaviY(double y) {Kugla::y = y; return *this;}
  Kugla &PostaviZ(double z) { Kugla::z = z; return *this;}
  Kugla &PostaviCentar(double x, double y , double z){ Kugla::x = x; Kugla::y = y; Kugla::z = z;}
/*  Kugla &PostaviCentar(std::tuple<double,double,double> &centar){
      centa
  }*/
  Kugla &PostaviPoluprecnik(double r){
      if(r < 0) throw std::domain_error ("Neispravan poluprecnik");
      Kugla::poluprecnik = r;
      return *this;
  }
  void Ispisi() const {
      std::cout<<"{("<<x<<","<<y<<","<<z<<"),"<<poluprecnik<<"}"<<std::endl;
  }
  void Transliraj(double delta_x, double delta_y, double delta_z){
      x += delta_x;
      y += delta_y;
      z += delta_z;
  }
  
  friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2) {
      if(k1.x == k2.x && k1.y == k2.y && k1.z == k2.z && k1.poluprecnik == k2.poluprecnik) return true;
      else return false;
  }
  friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2){
      if(k1.poluprecnik == k2.poluprecnik) return true;
      else return false;
  }
  friend bool DaLiSuKoncentricne (const Kugla &k1, const Kugla &k2){
      if(k1.x == k2.x && k1.y == k2.y && k1.z == k2.z) return true;
      else return false;
  }
  
  friend bool DaLiSeDodirujuIzvana (const Kugla &k1, const Kugla &k2);
  friend bool DaLiSeDodirujuIznutra (const Kugla &k1, const Kugla &k2);
  friend bool DaLiSePreklapaju (const Kugla &k1, const Kugla &k2);
  friend bool DaLiSeSijeku (const Kugla &k1, const Kugla &k2);
  bool DaLiSadrzi(const Kugla &k) const{
      if(k.poluprecnik < poluprecnik){
          if(k.x < x && k.y < y && k.z < z) return true;
          else return false;
      }
  }
  friend double RastojanjeCentara (const Kugla &k1, const Kugla &k2){
      return std::sqrt((k2.x - k1.x)*(k2.x - k1.x) + (k2.y - k1.y)*(k2.y - k1.y) + (k2.z - k1.z)*(k2.z - k1.z));
  }
    
};

bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2){
    double d = RastojanjeCentara(k1,k2);
    if( d == std::fabs(k2.poluprecnik - k1.poluprecnik)) return true;
    else return false;
}
bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2){
    double d = RastojanjeCentara(k1,k2);
    if(d == (k1.poluprecnik + k2.poluprecnik)) return true;
    else return false;
}

bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2){
    double d = RastojanjeCentara(k1,k2);
    if( k2.poluprecnik > k1.poluprecnik){
        if((k2.poluprecnik - k1.poluprecnik) < d && d > (k1.poluprecnik + k2.poluprecnik)) return true;
        else return false;
    } else if(k1.poluprecnik > k2. poluprecnik){
        if((k1.poluprecnik - k2.poluprecnik) < d && d > (k1.poluprecnik + k2.poluprecnik)) return true;
        else return false;
    }
}

bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2){
    double d = RastojanjeCentara(k1,k2);
    if(d < std::fabs(k1.poluprecnik - k2. poluprecnik)) return true;
    else return false;
}
int main ()
{
    int n;
    Kugla k;
    std::cout<<"Unesite broj n: ";
    std::cin>>n;
    std::vector<std::shared_ptr<Kugla>> vektor;
    for(int i = 0 ; i < n ; i++){
        v.push_back(std:make_shared<Kugla> k);
    }
    
    return 0;
}
