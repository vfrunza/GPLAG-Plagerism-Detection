/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <tuple>
#include <cmath>

class Kugla {
    double x,y,z,r;
    bool IspravanPoluprecnik(double r){
        if(r<0) return false;
        return true;
    }    
    static constexpr double PI=atan(1);
    static constexpr double eps=std::pow(10,-10);
    static bool Identicne(double a, double b) {
        if(std::abs(a-b)<eps*(std::abs(a)+std::abs(b))) return true;
        else return false;
    }
    static double Udaljenost(double a, double b){
        return std::abs(a-b);
    }
    public:
    explicit Kugla(double r=0) { Kugla::x=0; Kugla::y=0; Kugla::z=0; Kugla::r=r; };
    Kugla(double x, double y, double z, double r=0) {Kugla::x=x; Kugla::y=y; Kugla::z=z; Kugla::r=r;} 
    explicit Kugla(const std::tuple<double, double, double> &centar, double r=0) { Kugla::x=std::get<0>(centar); Kugla::y=std::get<1>(centar); Kugla::z=std::get<1>(centar); Kugla::r=r; }
    double DajX() const { return x; }
    double DajY() const { return y; }
    double DajZ() const { return z; }
    std::tuple<double, double, double> DajCentar() const { return std::make_tuple(x,y,z); }
    double DajPoluprecnik() const { return r; }
    double DajPovrsinu() const { return r*r*PI; }
    double DajZapreminu() const { return (4/3.)*r*r*r*PI; }
    Kugla &PostaviX(double x) { Kugla::x=x; return *this; }
    Kugla &PostaviY(double y) { Kugla::y=y; return *this; }
    Kugla &PostaviZ(double z) { Kugla::z=z; return *this; }
    Kugla &PostaviCentar(double x, double y, double z) { Kugla::x=x; Kugla::y=y; Kugla::z=z; return *this; }
    Kugla &PostaviCentar(std::tuple<double, double, double> &centar) { Kugla::x=std::get<0>(centar); Kugla::y=std::get<1>(centar); Kugla::z=std::get<2>(centar); return *this; }
    Kugla &PostaviPoluprecnik(double r) { Kugla::r=r; return *this; }
    void Ispisi() const { std::cout<<"{ ("<<x<<","<<y<<","<<z<<") , "<<r<<"}"; }
    void Transliraj(double delta_x, double delta_y, double delta_z) { x+=delta_x; y+=delta_y; z+=delta_z; }
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2) {
        return (Identicne(k1.x,k2.x) && Identicne(k1.y,k2.y) && Identicne(k1.z,k2.z) && Identicne(k1.r,k2.r));
    }
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2) {
        return Identicne(k1.r,k2.r);
    }
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2) {
        return (Identicne(k1.x,k2.x) && Identicne(k1.y,k2.y) && Identicne(k1.z,k2.z));
    }
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2){
        return std::sqrt(std::pow(Udaljenost(k1.x,k2.x),2)+std::pow(Udaljenost(k1.y,k2.y),2)+std::pow(Udaljenost(k1.z,k2.z),2));
    }
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2) {
        return Identicne(k1.r+k2.r,RastojanjeCentara(k1,k2));
    }
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2){
        return k1.r+k2.r>RastojanjeCentara(k1,k2);
    }
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
    bool DaLiSadrzi(const Kugla &k);
};

int main ()
{
	return 0;
}
