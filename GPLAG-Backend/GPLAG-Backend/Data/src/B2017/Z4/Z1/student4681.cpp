/B2017/2018: Zadaća 4, Zadatak 1
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
class Kugla {
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
  
  friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
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

    bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2) {
        return (jednako(k1.DajX(), k2.DajX()) && jednako(k1.DajY(), k2.DajY()) && jednako(k1.DajZ(), k2.DajZ()) && jednako(k1.DajPoluprecnik(), k2.DajPoluprecnik()));
    }
    bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2) {
        return (jednako(k1.DajPoluprecnik(), k2.DajPoluprecnik()));
    }
    bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2) {
        return (jednako(k1.DajX(), k2.DajX()) && jednako(k1.DajY(), k2.DajY()) && jednako(k1.DajZ(), k2.DajZ()));
    }
    bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2) {
        double distance(std::sqrt(std::pow(k2.DajX()-k1.DajX(), 2) + std::pow(k2.DajY()-k1.DajY(), 2) + std::pow(k2.DajZ()-k1.DajZ(), 2)));
        double x(distance - k2.r); if(x<0) x*=-1;
        double y(distance + k2.r); if(y<0) y*=-1;
        if(!jednako(k1.r) && !jednako(k2.r))
        if(jednako(x, k1.r) && y > k1.r) return true;
        return false;
    }
    bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2) {
        double distance(std::sqrt(std::pow(k2.DajX()-k1.DajX(), 2) + std::pow(k2.DajY()-k1.DajY(), 2) + std::pow(k2.DajZ()-k1.DajZ(), 2)));
        double x(distance - k2.r); if(x<0) x*=-1;
        double y(distance + k2.r); if(y<0) y*=-1;
        double x1(distance - k1.r); if(x1<0) x1*=-1;
        double y1(distance + k1.r); if(y1<0) y1*=-1;
        if(!jednako(k1.r) && !jednako(k2.r))
        if((jednako(y, k1.r) && x < k1.r) || (jednako(y1, k2.r) && x1 < k2.r)) return true;
        return false;
    }
    bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2) {
        if(DaLiSeSijeku(k1, k2)) return true;
        double distance(std::sqrt(std::pow(k2.DajX()-k1.DajX(), 2) + std::pow(k2.DajY()-k1.DajY(), 2) + std::pow(k2.DajZ()-k1.DajZ(), 2)));
         double x(distance - k2.r); if(x<0) x*=-1;
        double y(distance + k2.r); if(y<0) y*=-1;
        double x1(distance - k1.r); if(x1<0) x1*=-1;
        double y1(distance + k1.r); if(y1<0) y1*=-1;
        if(jednako(k2.DajPoluprecnik())|| jednako(k1.DajPoluprecnik())) return false;
        else
            if((y < k1.DajPoluprecnik() && x < k1.DajPoluprecnik()) || (y1 < k2.DajPoluprecnik() && x1 < k2.DajPoluprecnik())) return true;
        return false;
    }
    bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2) {
        if(DaLiSuIdenticne(k1, k2)) return false;
        double distance(std::sqrt(std::pow(k2.DajX()-k1.DajX(), 2) + std::pow(k2.DajY()-k1.DajY(), 2) + std::pow(k2.DajZ()-k1.DajZ(), 2)));
        double x(distance - k1.r);
        double y(distance + k1.r);
        if(x < 0) x *= -1;
        if(y < 0) y *= -1;
        if(jednako(k2.r) || jednako(k1.r)) return false;
        else
            if(x < k2.r && y > k2.r) return true;
        return false;
    }
    double RastojanjeCentara(const Kugla &k1, const Kugla &k2) {
        return std::sqrt(std::pow(k2.DajX()-k1.DajX(), 2) + std::pow(k2.DajY()-k1.DajY(), 2) + std::pow(k2.DajZ()-k1.DajZ(), 2));
    }
    
   
int main ()
{
    std::cout << "Unesite broj kugla: ";
    int n;
    do{
    std::cin >> n;
    
    if(n<=0) std::cout << "Neispravan broj kugli, unesite ponovo!\n";
    std::cin.clear(); std::cin.ignore(10000, '\n');
    }while(n<=0 || std::cin.fail());
    std::vector<std::shared_ptr<Kugla>> vector(n);
    bool out(false);
    for(int i = 1; i <= n; i++) {
        double x, y, z, r;
        std::cout << "Unesite centar " << i << ". kugle: ";
        std::cin >> x >> y >> z;
        while(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Neispravan centar\n";
            --i; out = true;
        }
        if(out) {out = false; continue; }
        std::cout << "Unesite poluprecnik " << i << ". kugle: ";
        std::cin >> r;
        if(r < 0 || std::cin.fail()) {if(std::cin.fail()) {std::cin.clear(); std::cin.ignore(10000, '\n');} std::cout << "Ilegalan poluprecnik\n"; --i; continue; }
        vector.at(i-1) = std::make_shared<Kugla>(x, y, z, r);
    }
    
    std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double x, y, z;
    do {
    std::cin >> x >> y >> z;
    if(/*std::cin >> x || std::cin >> y || std::cin >> z*/std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Neispravni parametri translacije, unesite ponovo!\n";
    } else break;
    }while(true);
    
    std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: \n";
    std::transform(vector.begin(), vector.end(), vector.begin(), [x, y, z](std::shared_ptr<Kugla> k)->std::shared_ptr<Kugla>{(*k).Transliraj( x, y, z); return k;});
    std::sort(vector.begin(), vector.end(), [] (std::shared_ptr<Kugla>k1, std::shared_ptr<Kugla> k2)->bool{if((*k1).DajZapreminu()<(*k2).DajZapreminu()) return true; return false;});
    std::for_each(vector.begin(), vector.end(), [](std::shared_ptr<Kugla> k) {(*k).Ispisi(); std::cout << std::endl;});
    auto bla = std::max_element(vector.begin(), vector.end(), [](std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2)->bool {return((*k1).DajPovrsinu()<(*k2).DajPovrsinu());});
    if(bla != vector.end()) {std::cout << "Kugla sa najvecom povrsinom je: "; (*bla)->Ispisi();}/*else ???*/
    std::cout << std::endl;
    bool imal(false); int c(-1);
    std::for_each(vector.begin(), vector.end(), [vector, &imal, &c](std::shared_ptr<Kugla> k1){c++; std::for_each(vector.begin() + c, vector.end(), [k1, &imal](std::shared_ptr<Kugla> k2){
        if(DaLiSeSijeku(*k1, *k2)) {std::cout << "Presjecaju se kugle: ";
        k1->Ispisi();
        std::cout << std::endl;
        (*k2).Ispisi(); 
        std::cout << std::endl;
        imal = true;}
    });});
    if(!imal) std::cout << "Ne postoje kugle koje se presjecaju!";
    return 0;
}
