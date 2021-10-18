/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <tuple>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>

class Kugla{
  double x;
  double y;
  double z;
  double r;
  const double pi{4*atan(1)};
  static double Udaljenost(double x1,double y1,double z1,double x2,double y2,double z2);
  static double Kvadrat(double a);
  static double Korijen(double a);
  static bool Jednakost(double m,double n);
  public:
  explicit Kugla(double r = 0);//
  Kugla(double x, double y, double z, double r = 0);//
  explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0); //
  double DajX() const;//
  double DajY() const;//
  double DajZ() const;//
  std::tuple<double, double, double> DajCentar() const;//
  double DajPoluprecnik() const; //
  double DajPovrsinu() const; //
  double DajZapreminu() const; //
  Kugla &PostaviX(double x); //
  Kugla &PostaviY(double y); //
  Kugla &PostaviZ(double z); //
  Kugla &PostaviCentar(double x, double y, double z); //
  Kugla &PostaviCentar(const std::tuple<double, double, double> &centar); //
  Kugla &PostaviPoluprecnik(double r); //
  void Ispisi() const;//
  void Transliraj(double delta_x, double delta_y, double delta_z);//
  friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2); //
  friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2); //
  friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2); //
  friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2); //
  friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2); //
  friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2); //
  friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2); //
  bool DaLiSadrzi(const Kugla &k) const;
  friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2); //
};

double Kugla::Udaljenost(double x1,double y1,double z1,double x2,double y2,double z2){
    return Korijen((x2-x1)+Kvadrat(y2-y1)+Kvadrat(z2-z1));
}

double Kugla::Kvadrat(double a){
    return a*a;
}

double Kugla::Korijen(double a){
    return std::sqrt(a);
}

bool Kugla::Jednakost(double m, double n){
    return fabs(m-n)<pow(10,-10)*(fabs(m)+fabs(n));
}

Kugla::Kugla(double r){
    Kugla::x=0; Kugla::y=0; Kugla::z=0;
    Kugla::r=r;
}

Kugla::Kugla(double x, double y, double z, double r){
    Kugla::x=x; Kugla::y=y; Kugla::z=z;
    Kugla::r=r;
}

Kugla::Kugla(const std::tuple<double, double, double> &centar, double r){
    Kugla::x=std::get<0>(centar); Kugla::y=std::get<1>(centar); Kugla::z=std::get<2>(centar);
    Kugla::r=r;
}

double Kugla::DajX() const{ return x; }
double Kugla::DajY() const{ return y; }
double Kugla::DajZ() const{ return z; }

std::tuple<double, double, double> Kugla::DajCentar() const{
    return std::make_tuple(x,y,z);   
}

double Kugla::DajPoluprecnik() const { return r; }
double Kugla::DajPovrsinu() const { return 4*pi*r*r; }
double Kugla::DajZapreminu() const { return pi*r*r*r*4./3; }

Kugla& Kugla::PostaviX(double x) { Kugla::x=x; return *this; }
Kugla& Kugla::PostaviY(double y) { Kugla::y=y; return *this; }
Kugla& Kugla::PostaviZ(double z) { Kugla::z=z; return *this; }

Kugla& Kugla::PostaviCentar(double x, double y, double z) {
    PostaviX(x);
    PostaviY(y);
    PostaviZ(z);
    return *this;
}
Kugla& Kugla::PostaviCentar(const std::tuple<double, double, double> &centar){
    PostaviCentar(std::get<0>(centar),std::get<1>(centar),std::get<2>(centar));
    return *this;
}

Kugla& Kugla::PostaviPoluprecnik(double r) { Kugla::r=r; return *this; }

void Kugla::Ispisi() const {
    std::cout << "{(" << DajX() << "," << DajY() << "," << DajZ() << ")," << DajPoluprecnik() << "}" << std::endl;
}

void Kugla::Transliraj(double delta_x, double delta_y, double delta_z){
    Kugla::x+=delta_x;
    Kugla::y+=delta_y;
    Kugla::z+=delta_z;
}

 bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2){
     if(DaLiSuPodudarne(k1,k2) && DaLiSuKoncentricne(k1,k2)) return true;
     return false;
 }
 
 bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2){
     if(Kugla::Jednakost(k1.r,k2.r)) return true;
     return false;
 }
 
 bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2){
     if(Kugla::Jednakost(k1.x,k2.x) && Kugla::Jednakost(k1.y,k2.y) && Kugla::Jednakost(k1.z,k2.z)) return true;
     return false;
 }
 
 bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2){
     if(Kugla::Jednakost(k1.r+k2.r,RastojanjeCentara(k1,k2))) return true;
     return false;
 }
 
 bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2){
     if(k1.r>k2.r){
         if(Kugla::Jednakost(k1.r-k2.r,RastojanjeCentara(k1,k2))) return true;
     }
     else {
         if(Kugla::Jednakost(k2.r-k1.r,RastojanjeCentara(k1,k2))) return true;
     }
     return false;
 }
 
bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2){
     if(DaLiSeSijeku(k1,k2)) return true;
     return false;
 }
 
bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2){
    if(k1.r+k2.r>RastojanjeCentara(k1,k2)) return true;
    return false;
}

bool Kugla::DaLiSadrzi(const Kugla &k) const{
    if(k.r+RastojanjeCentara(k,*this)>Kugla::r) return false;
    return true;
}

double RastojanjeCentara(const Kugla &k1,const Kugla &k2){
    return Kugla::Udaljenost(k1.DajX(),k1.DajY(),k1.DajZ(),k2.DajX(),k2.DajY(),k2.DajZ());
}

void UnosKugli(std::vector<std::shared_ptr<Kugla>> &v){ 
    for(int i(0) ; i<v.size() ;){
        std::cout << "Unesite centar " << i+1 << ". kugle: ";
        double x(0),y(0),z(0); std::cin >> x >> y >> z;
        if(!(std::cin) || std::cin.get()!='\n'){
            std::cout << "Neispravni podaci" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            continue;
        }
        std::cout << "Unesite poluprecnik " << i+1 << ". kugle: ";
        double r(0); std::cin >> r;
        if(r<0 || !(std::cin) || std::cin.get()!='\n'){
            std::cout << "Ilegalan poluprecnik" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            continue;
        }
        v[i]=std::make_shared<Kugla>(Kugla(x,y,z,r));
        i++;
    }
}

void Translacija(std::vector<std::shared_ptr<Kugla>> &v){
    std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double delta_x(0),delta_y(0),delta_z(0);
    std::cin >> delta_x >> delta_y >> delta_z;
    std::transform(v.begin(),v.end(),v.begin(),[delta_x,delta_y,delta_z](std::shared_ptr<Kugla> it)
    {it->Transliraj(delta_x,delta_y,delta_z); 
    return std::make_shared<Kugla>(it->DajCentar(),it->DajPoluprecnik());});
}

int main ()
{ 
    
    
    std::cout << "Unesite broj kugla: ";
    int n(0); std::cin >> n;
    std::vector<std::shared_ptr<Kugla>> v(n); // uraditi kontrolu unosa ispravnih parametara
    UnosKugli(v);
    Translacija(v);
    std::sort(v.begin(),v.end(),[](std::shared_ptr<Kugla> it1,std::shared_ptr<Kugla> it2)
    { return it1->DajZapreminu()<it2->DajZapreminu(); });
    std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: \n";
    std::for_each(v.begin(),v.end(),[](std::shared_ptr<Kugla> it){ it->Ispisi(); });
    std::cout << "Kugla sa najvecom povrsinom je: ";
    auto element(std::max_element(v.begin(),v.end(),[](std::shared_ptr<Kugla> it1,std::shared_ptr<Kugla> it2){
        return it2->DajPovrsinu()>it1->DajPovrsinu();}));
    int razmak(element-v.begin());
    v[razmak]->Ispisi();
    
	return 0;
}
/*

3
0 0 0
4 
2 0 0
2
1 2 3
4
0 0 0

*/