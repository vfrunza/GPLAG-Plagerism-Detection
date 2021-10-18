/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <tuple>
#include <stdexcept>
#include <cmath>
#include <algorithm>
#include <vector> 
#include <memory>

const double pi=4*atan(1);

void PostaviCentar_1(double &x,double &y, double &z,int n){
   for(int i=0; i<n; i++){
  if( !std::cin){
  while( !std::cin){
    std::cout<<"Neispravan centar\n";
    std::cin.clear();
    std::cin.ignore(100000, '\n');
    std::cout<<"Unesite centar "<<i+1<<". kugle: ";
    i++;
    std::cin>>x>>y>>z;
    }
  }
   }
}


void PostaviPoluprecnik_1(double &poluprecnik_1,int n){
  for(int i=0; i<n; i++){
  if(poluprecnik_1<0 || !std::cin){
    while(poluprecnik_1<0 || !std::cin){
      std::cout<<"Ilegalan poluprecnik\n";
      std::cin.clear();
      std::cin.ignore(100000, '\n');
      double x,y,z;
      std::cout<<"Unesite centar "<<i+1<<". kugle: ";
      i++;
      std::cin>>x>>y>>z;
      PostaviCentar_1(x,y,z,n);
      std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
     // i++;
      std::cin>>poluprecnik_1;
    }
  }
  }
}






class Kugla{
  double x,y,z;
  double poluprecnik;
  
  
  public:
  explicit Kugla(double r=0);
  Kugla(double x, double y, double z, double r=0);
  explicit Kugla(const std::tuple<double ,double ,double >&centar,double r=0);
  double DajX()const;
  double DajY()const;
  double DajZ()const;
  std::tuple<double,double,double> DajCentar()const;
  double DajPoluprecnik()const;
  double DajPovrsinu()const;
  double DajZapreminu()const;
  Kugla &PostaviX(double x);
  Kugla &PostaviY(double y);
  Kugla &PostaviZ(double z);
  Kugla &PostaviCentar(double x, double y, double z);
  Kugla &PostaviCentar(const std::tuple<double, double, double>&centar);
  Kugla &PostaviPoluprecnik(double r);
  void Ispisi()const;
  void Transliraj(double delta_x, double delta_y, double delta_z);
  friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
  friend bool Zapremina(const Kugla &k1, const Kugla &k2);
  
  bool DaLiSadrzi(const Kugla &k)const;
  friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);
};


Kugla::Kugla(double r){
    if(r<0)throw std::domain_error("Ilegalan poluprecnik");
    //r=0;
    Kugla::poluprecnik=r;
}

Kugla::Kugla(double x, double y, double z, double r){
  Kugla::x=x;
  Kugla::y=y;
  Kugla::z=z;
  Kugla::poluprecnik=r;
}



Kugla::Kugla( const std::tuple<double,double,double>&centar, double r){
  double a=std::get<0>(centar);
  Kugla::x=a;
  double b=std::get<1>(centar);
  Kugla::y=b;
  double c=std::get<2>(centar);
  Kugla::z=c;
  //centar=std::make_tuple(a,b,c);
}

bool Zapremina(const Kugla &k1, const Kugla &k2){
  return k1.DajZapreminu()>k2.DajZapreminu();
}

double Kugla::DajX()const{
  return Kugla::x;
}
double Kugla::DajY()const{
  return Kugla::y;
}
double Kugla::DajZ()const{
  return Kugla::z;
}
std::tuple<double,double,double> Kugla::DajCentar()const{
  std::tuple<double,double,double>c;
  std::get<0>(c)=Kugla::x;
  std::get<1>(c)=Kugla::y;
  std::get<2>(c)=Kugla::z;
  
  return c ;
}

double Kugla::DajPoluprecnik()const{
  return Kugla::poluprecnik;
  
}

double Kugla::DajPovrsinu()const{
  return DajPoluprecnik()*DajPoluprecnik()*pi;
}

double Kugla::DajZapreminu()const{
  return (4/3)*DajPoluprecnik()*DajPoluprecnik()*DajPoluprecnik()*pi;
}

Kugla &Kugla::PostaviX(double x){
  
  //Kugla::x=x;
  Kugla novi_objekat(x,DajY(),DajZ(),0);
  return novi_objekat;
}

Kugla &Kugla::PostaviY(double y){
  
 // Kugla::y=y;
  Kugla novi_objekat(DajX(),y,DajZ(),0);
  return novi_objekat;
}

Kugla &Kugla::PostaviZ(double z){
  
  //Kugla::z=z;
  Kugla novi_objekat(DajX(), DajY(), z);
  return novi_objekat;
}



Kugla &Kugla::PostaviCentar(double x, double y, double z){
 