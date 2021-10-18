#include <iostream>
#include <cmath>
#include <stdexcept>
#include <tuple>
#include <vector>
#include <memory>
#define eps 10e-10

class Kugla {
    double x, y, z, r;
public:
    explicit Kugla (double r=0) : r(r) { if (r<0) throw std::domain_error("Ilegalan poluprecnik"); }
    Kugla (double x, double y, double z, double r=0) : x(x), y(y), z(z), r(r) { if (r<0) throw std::domain_error("Ilegalan poluprecnik"); }
    explicit Kugla (const std::tuple<double, double, double> &centar, double r=0); //ispod
    double DajX() const { return x; }
    double DajY() const { return y; }
    double DajZ() const { return z; }
    std::tuple<double, double, double> DajCentar() const { auto t=std::make_tuple(x,y,z); return t; }
    double DajPoluprecnik() const { return r; }
    double DajPovrsinu() const { return 4*4*atan(1)*r*r; }
    double DajZapremni() const { return (4/3.)*4*atan(1)*r*r*r; }
    Kugla &PostaviX(double x) { Kugla::x=x; return *this; }
    Kugla &PostaviY(double y) { Kugla::y=y; return *this; }
    Kugla &PostaviZ(double z) { Kugla::z=z; return *this; }
    Kugla &PostaviCentar(double x, double y, double z) { Kugla::x=x; Kugla::y=y; Kugla::z=z; return *this; }
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar) { Kugla::x=std::get<0>(centar); Kugla::y=std::get<1>(centar);
        Kugla::z=std::get<2>(centar);
        return *this;
    }
    Kugla &PostaviPoluprecnik(double r) { Kugla::r=r; return *this; }
    void Ispisi() { std::cout <<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}"; }
    void Transliraj(double delta_x, double delta_y, double delta_z) { x+=delta_x; y+=delta_y; z+=delta_z; }
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2){
        if ((k1.x-k2.x)>-eps and (k1.x-k2.x)<eps and (k1.y-k2.y)>-eps and (k1.y-k2.y)<eps and (k1.z-k2.z)>-eps and (k1.z-k2.z)<eps 
        and (k1.r-k2.r)>-eps and (k1.r-k2.r)<eps)
            return true;
        return false;
    }
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2) { 
        if ((k1.r-k2.r)>-eps and (k1.r-k2.r)<eps) 
            return true;
        return false;
    }
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2) {
        if ((k1.x-k2.x)>-eps and (k1.x-k2.x)<eps and (k1.y-k2.y)>-eps and (k1.y-k2.y)<eps and (k1.z-k2.z)>-eps and (k1.z-k2.z)<eps)
            return true;
        return false;
    }
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2) { double potkorjena((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z));
        if (sqrt(potkorjena)-k1.r-k2.r>-eps and sqrt(potkorjena)-k1.r-k2.r<eps) 
            return true;
        return false;
    }
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);// { double potkorjena((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z));
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
    bool DaLiSadrzi(const Kugla &k) const;
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2) { return sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z)); }
};

Kugla::Kugla (const std::tuple<double, double, double> &centar, double r){
    Kugla::x=std::get<0>(centar);
    Kugla::y=std::get<1>(centar);
    Kugla::z=std::get<2>(centar);
    if (r<0) throw std::domain_error("Ilegalan poluprecnik");
    Kugla::r=r;
}

int main (){
    int n;
    std::cout<<"Unesite broj kugla: ";
    std::cin>>n;
    while (!std::cin or n<=0){
        std::cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::cin>>n;
    }
    try{
    std::vector<std::shared_ptr<Kugla>> vek(n);
    }
    catch (std::domain_error e){
        std::cout<<e.what()<<std::endl;
    }
	return 0;
}
