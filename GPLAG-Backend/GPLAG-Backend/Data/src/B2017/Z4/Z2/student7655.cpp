/B2017/2018: Zadaća 4, Zadatak 2
#include <iostream>
#include <tuple>
#include <cmath>
#include <vector>
class NeprklapajucaKugla
{
    public:
    double x,y,z,poluprecnik;
    mutable int brojac=1;
    explicit NeprklapajucaKugla(double r=0) { x=0;y=0;z=0;poluprecnik=r; }
    NeprklapajucaKugla(double x, double y, double z, double r=0) {
        NeprklapajucaKugla::x=x;
        NeprklapajucaKugla::y=y;
        NeprklapajucaKugla::z=z;
        poluprecnik=r;
    }
    explicit NeprklapajucaKugla(const std::tuple<double,double,double> &centar, double r=0) {
        x=std::get<0>(centar);
        y=std::get<1>(centar);
        z=std::get<2>(centar);
        poluprecnik=r;
    }
    double DajX() const { return x; }
    double DajY() const { return y; }
    double DajZ() const { return z; }
    std::tuple<double,double,double>DajCentar() const {
        std::tuple<double,double,double>koordinate;
        koordinate=std::make_tuple(x,y,z);
        return koordinate;
    }
    double DajPoluprecnik() const { return poluprecnik; }
    double DajPovrsinu() const { return poluprecnik*poluprecnik*4*4*atan(1); }
    double DajZapreminu() const { return (4./3)*pow(poluprecnik,3)*4*atan(1); }
    NeprklapajucaKugla &PostaviX(double x) { NeprklapajucaKugla::x=x; return *this;}
    NeprklapajucaKugla &PostaviY(double y) { NeprklapajucaKugla::y=y; return *this;}
    NeprklapajucaKugla &PostaviZ(double z) { NeprklapajucaKugla::z=z; return *this; }
    NeprklapajucaKugla &PostaviCentar(double x, double y,double z) {
        NeprklapajucaKugla::x=x;
        NeprklapajucaKugla::y=y;
        NeprklapajucaKugla::z=z;
        return *this;
    }
    NeprklapajucaKugla &PostaviCentar(const std::tuple<double,double,double>&centar) {
        x=std::get<0>(centar);
        y=std::get<1>(centar);
        z=std::get<2>(centar);
        return *this;
    }
    NeprklapajucaKugla &PostaviPoluprecnik(double r) { poluprecnik=r; return *this; }
    void Ispisi() const { std::cout <<"{("<<x<<","<<y<<","<<z<<"),"<<poluprecnik<<"}"  << std::endl; }
    void Transliraj(double delta_x,double delta_y,double delta_z) {
        x+=delta_x; y+=delta_y; z+=delta_z;
    }
    friend double RastojanjeCentara(const NeprklapajucaKugla &k1, const NeprklapajucaKugla &k2);
    bool DaLiSadrzi(const NeprklapajucaKugla &k) const {
        double r_min,r_max;
        if(k.poluprecnik<poluprecnik) r_min=k.poluprecnik, r_max=poluprecnik;
        else r_min=poluprecnik, r_max=k.poluprecnik;
        return (RastojanjeCentara(k,*this)+r_min<r_max);
    }
};
double RastojanjeCentara (const NeprklapajucaKugla &k1, const NeprklapajucaKugla &k2) {
  return (std::sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z)));  
}
int main ()
{
    NeprklapajucaKugla k(1,1,1,1);
    NeprklapajucaKugla k1(2,2,2,2);
    k1.Ispisi();
    k1.trenutni->Ispisi();
    std::vector<NeprklapajucaKugla>v;
    v.push_back(k);
    v.push_back(k1);
 	return 0;
}
