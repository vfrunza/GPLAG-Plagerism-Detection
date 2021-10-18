/B2017/2018: Zadaća 4, Zadatak 4
#include <iostream>
#include <stdexcept>
#include <vector> 
#include <cmath>
#include <tuple>
#include <algorithm>
#include <memory>
#include <iomanip>
#define eps 0.0000000001
#define PI 4*atan(1)
using namespace std;


double kvadratich(double x){
    return x*x;
}

class Kugla{
  double x,y,z,r;
  
  public:
  explicit Kugla(double r=0){
      if(r<0)throw domain_error("Ilegalan poluprecnik");
      Kugla::r=r;
      Kugla::x=0;
      Kugla::y=0;
      Kugla::z=0;
      
  }
  Kugla(double x, double y, double z, double r=0){
      if(r<0)throw domain_error("Ilegalan poluprecnik");
      Kugla::r=r;
      Kugla::x=x;
      Kugla::y=y;
      Kugla::z=z;
  }
  explicit Kugla(const tuple<double,double,double> &centar, double r=0){
      if(r<0)throw domain_error("Ilegalan poluprecnik");
      Kugla::r=r;
      Kugla::x=get<0>(centar);
      Kugla::y=get<1>(centar);
      Kugla::z=get<2>(centar);
  }
  double DajX()const{return x;}
  double DajY()const{return y;}
  double DajZ()const{return z;}
  tuple<double,double,double>DajCentar()const{
    return tuple<double,double,double>(x,y,z);
}
double DajPoluprecnik()const{return r;}
double DajPovrsinu()const{return 4*PI*r*r;}
double DajZapreminu()const{return ((4*PI*r*r*r)/3);}
Kugla &PostaviX(double x){
    Kugla::x=x;
    return *this;
}
Kugla &PostaviY(double y){
    Kugla::y=y;
    return *this;
}
Kugla &PostaviZ(double z){
    Kugla::z=z;
    return *this;
}
Kugla &PostaviCentar(double x, double y, double z){
    Kugla::x=x;
    Kugla::y=y;
    Kugla::z=z;
    return *this;
}
Kugla &PostaviCentar(const tuple<double,double,double>&centar){
    Kugla::x=get<0>(centar);
    Kugla::y=get<1>(centar);
    Kugla::z=get<2>(centar);
    return *this;
}
Kugla &PostaviPoluprecnik(double r){
    if(r<0)throw domain_error("Ilegalan poluprecnik");
    Kugla::r=r;
}
void Ispisi()const{
    cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}";
}
void Transliraj(double delta_x, double delta_y, double delta_z){
    this->x+=delta_x;
    this->y+=delta_y;
    this->z+=delta_z;
}
friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2){
    if(fabs(k1.Kugla::DajX()-k2.DajX())<eps*(fabs(k1.Kugla::DajX())+fabs(k2.Kugla::DajX()))){
    if(fabs(k1.Kugla::DajY()-k2.DajY())<eps*(fabs(k1.Kugla::DajY())+fabs(k2.Kugla::DajY()))){
    if(fabs(k1.Kugla::DajZ()-k2.DajZ())<eps*(fabs(k1.Kugla::DajZ())+fabs(k2.Kugla::DajZ()))){
    if(fabs(k1.Kugla::DajPoluprecnik()-k2.Kugla::DajPoluprecnik())<eps*(fabs(k1.Kugla::DajPoluprecnik())+fabs(k2.Kugla::DajPoluprecnik()))){
    return true;
    }else return false;
    }else return 0;
    }else return false;
    }else return 0;
    return 1;
}
friend bool DaLiSuPodudarne(const Kugla &k1,const Kugla &k2){
    if(k1.Kugla::DajPoluprecnik()-k2.Kugla::DajPoluprecnik()<eps*(fabs(k1.Kugla::DajPoluprecnik())+fabs(k2.Kugla::DajPoluprecnik()))){
    return 1;
    }else return false;
    return 0;
}
friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2){
    if(fabs(k1.Kugla::DajX()-k2.DajX())<eps*(fabs(k1.Kugla::DajX())+fabs(k2.Kugla::DajX()))){
    if(fabs(k1.Kugla::DajY()-k2.DajY())<eps*(fabs(k1.Kugla::DajY())+fabs(k2.Kugla::DajY()))){
    if(fabs(k1.Kugla::DajZ()-k2.DajZ())<eps*(fabs(k1.Kugla::DajZ())+fabs(k2.Kugla::DajZ()))){
    return true;
    }else return 0;
    }else return false;
    }else return 0;
    return 1;
}
    


friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2){
    return k1.Kugla::DajPoluprecnik()+k2.Kugla::DajPoluprecnik()-RastojanjeCentra(k1,k2)<eps*(fabs(k1.Kugla::DajPoluprecnik()+k2.Kugla::DajPoluprecnik())+fabs(RastojanjeCentra(k1,k2)));
}
friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2){
    return fabs(k1.Kugla::DajPoluprecnik()-k2.Kugla::DajPoluprecnik())-RastojanjeCentra(k1,k2)<eps*(fabs(k1.Kugla::DajPoluprecnik()-k2.Kugla::DajPoluprecnik())+fabs(RastojanjeCentra(k1,k2)));
}
friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2){
    if(DaLiSeSijeku(k1,k2)){
        return true;
    }else{
    if(fabs(k1.Kugla::DajX()-k2.DajX())<eps*(fabs(k1.Kugla::DajX())+fabs(k2.Kugla::DajX())))return true;
    if(fabs(k1.Kugla::DajY()-k2.DajY())<eps*(fabs(k1.Kugla::DajY())+fabs(k2.Kugla::DajY())))return 1;
    if(fabs(k1.Kugla::DajZ()-k2.DajZ())<eps*(fabs(k1.Kugla::DajZ())+fabs(k2.Kugla::DajZ())))return true;
    if(fabs(k1.Kugla::DajPoluprecnik()-k2.Kugla::DajPoluprecnik())<eps*(fabs(k1.Kugla::DajPoluprecnik())+fabs(k2.Kugla::DajPoluprecnik())))return 1;
        return 0;
    }
    return 0;
    //ako ne bude radilo napadni vujeta .!.
}
friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2){
    if(fabs(k1.Kugla::DajX()-k2.DajX())<eps*(fabs(k1.Kugla::DajX())+fabs(k2.Kugla::DajX())))return true;
    if(fabs(k1.Kugla::DajY()-k2.DajY())<eps*(fabs(k1.Kugla::DajY())+fabs(k2.Kugla::DajY())))return 1;
    if(fabs(k1.Kugla::DajZ()-k2.DajZ())<eps*(fabs(k1.Kugla::DajZ())+fabs(k2.Kugla::DajZ())))return true;
    if(fabs(k1.Kugla::DajPoluprecnik()-k2.Kugla::DajPoluprecnik())<eps*(fabs(k1.Kugla::DajPoluprecnik())+fabs(k2.Kugla::DajPoluprecnik())))return 1;
    return 0;
}
bool DaLiSadrzi(const Kugla &k)const{
    return 0;
}
friend double RastojanjeCentra(const Kugla &k1, const Kugla &k2){
    return sqrt(kvadratich(k1.Kugla::DajX()-k2.Kugla::DajX())+kvadratich(k1.Kugla::DajY()-k2.Kugla::DajY())+kvadratich(k1.Kugla::DajZ()-k2.Kugla::DajZ()));
}


};

int main(){
    
	return 0;
}
