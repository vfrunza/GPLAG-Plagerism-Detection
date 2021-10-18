/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <tuple>
const double pi=4*atan(1.);

class Kugla {
    double x,y,z,r;
    public: 
    explicit Kugla(double r=0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::r=r;
    }
    Kugla (double x, double y, double z, double r=0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::x=x;
        Kugla::y=y;
        Kugla::z=z;
        Kugla::r=r;
    }
    explicit Kugla(const std::tuple<double, double, double> &centar, double r=0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        double x,y,z;
        std::tie(x,y,z)=centar;
        Kugla::x=x;
        Kugla::y=y;
        Kugla::z=z;
        Kugla::r=r;
    }
    double DajX() const {return x;}
    double DajY() const {return y;}
    double DajZ() const {return z;}
    std::tuple<double,double,double> DajCentar() const{
        return std::tie(x,y,z);
    }
    double DajPoluprecnik() const {return r;}
    double DajPovrsinu() const { return 4*pi*r*r;}
    double DajZapreminu() const { return (4./3.)*pi*r*r*r;}
    Kugla &PostaviX(double x) { Kugla::x=x; return *this;} 
    Kugla &PostaviY(double y) { Kugla::y=y; return *this;}
    Kugla &PostaviZ(double z) { Kugla::z=z; return *this;}
    Kugla &PostaviCentar(double x, double y, double z) {
        Kugla::x=x;
        Kugla::y=y;
        Kugla::z=z;
        return *this;
    }
    Kugla &PostaviCentar(const std::tuple<double,double,double> &centar) {
        double x,y,z;
        std::tie(x,y,z)=centar;
        Kugla::x=x;
        Kugla::y=y;
        Kugla::z=z;
        return *this;
    }
    Kugla &PostaviPoluprecnik(double r) {if(r<0) throw std::domain_error("Ilegalan poluprecnik"); Kugla::r=r; return *this;} 
    void Ispisi() const {std::cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}";}
    void Transliraj(double delta_x, double delta_y, double delta_z) {
     x+=delta_x;
     y+=delta_y;
     z+=delta_z;
    }
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
    bool DaLiSadrzi(const Kugla &k) const {
        double a=abs(Kugla::x*k.DajX()+Kugla::y*k.DajY()+Kugla::z*DajZ());
        double R=abs(Kugla::r-k.DajPoluprecnik());
        return a<R;
    }
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);
    
};
bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2) {
        return (k1.DajCentar()==k2.DajCentar() && k1.DajPoluprecnik()==k2.DajPoluprecnik());
}
bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2) {
        return k1.DajPoluprecnik()==k2.DajPoluprecnik();
    }
bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2) {
    return (k1.DajCentar()==k2.DajCentar());
}
bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2) {
    double a=abs(k1.DajX()*k2.DajX()+k1.DajY()*k2.DajY()+k1.DajZ()*k2.DajZ());
    double R1=k1.DajPoluprecnik()+k2.DajPoluprecnik();
    
    return a==R1;
}
bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2) {
double a=abs(k1.DajX()*k2.DajX()+k1.DajY()*k2.DajY()+k1.DajZ()*k2.DajZ());
double R2=abs(k1.DajPoluprecnik()-k2.DajPoluprecnik());
return a==R2;
}

 bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2) {
     double a=abs(k1.DajX()*k2.DajX()+k1.DajY()*k2.DajY()+k1.DajZ()*k2.DajZ());
     double R1=k1.DajPoluprecnik()+k2.DajPoluprecnik();
     double R2=abs(k1.DajPoluprecnik()-k2.DajPoluprecnik());
     return (a<R1 || a>R2);
 }
bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2) {
    return (DaLiSeSijeku(k1,k2));
}
double RastojanjeCentara(const Kugla &k1, const Kugla &k2) {
    return std::sqrt(std::pow(k1.DajX()+k2.DajX(),2)+std::pow(k1.DajY()+k2.DajY(),2)+std::pow(k1.DajZ()+k2.DajZ(),2));
}
int main ()
{
	return 0;
}
