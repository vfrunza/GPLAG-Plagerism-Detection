/B2017/2018: Zadaća 4, Zadatak 2
#include <iostream>
#include <cmath>
#include <tuple>

class NepreklapajucaKugla{
    double x, y, z, r;
    Kugla* p;
     bool Sadrzi(double a1, double r1, double a2, double r2)const{
        double eps(0.000000001);
        if(fabs(a1-r1-(a2-r2))<eps*(fabs(a1-r1)+fabs(a2-r2))&&(fabs(a1+r1-(a2+r2))<eps*(fabs(a1+r1)+fabs(a2+r2))))
        return true;
        return false;
    }
    public:
    explicit NepreklapajucaKugla(double r = 0){PostaviCentar(0,0,0); PostaviPoluprecnik(r);}
    NepreklapajucaKugla(double x, double y, double z, double r = 0){if(r<0) throw std::domain_error("Ilegalan poluprecnik"); PostaviCentar(x, y, z); PostaviPoluprecnik(r);}
    explicit NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r = 0){PostaviCentar(centar); PostaviPoluprecnik(r);}
    double DajX() const{return x;}
    double DajY() const{return y;}
    double DajZ() const{return z;}
    std::tuple<double, double, double> DajCentar() const{return std::make_tuple(x,y,z);};
    double DajPoluprecnik() const{return r;}
    double DajPovrsinu() const{return 4*r*r*4*std::atan(1);}
    double DajZapreminu() const{return (4/3)*r*r*r*4*std::atan(1);}
    NepreklapajucaKugla &PostaviX(double x){NepreklapajucaKugla::x=x; return *this;}
    NepreklapajucaKugla &PostaviY(double y){NepreklapajucaKugla::y=y; return *this;}
    NepreklapajucaKugla &PostaviZ(double z){NepreklapajucaKugla::z=z; return *this;}
    NepreklapajucaKugla &PostaviCentar(double x, double y, double z){PostaviX(x); PostaviY(y); PostaviZ(z); return *this;}
    NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar){
            PostaviX(std::get<0>(centar));
            PostaviY(std::get<1>(centar));
            PostaviZ(std::get<2>(centar));
            return *this;
    }
    NepreklapajucaKugla &PostaviPoluprecnik(double r){NepreklapajucaKugla::r=r; return *this;}
    void Ispisi() const{std::cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}"<<std::endl;}
    void Transliraj(double delta_x, double delta_y, double delta_z){
        x+=delta_x;
        y+=delta_y;
        z+=delta_z;
    }
    bool DaLiSadrzi(const NepreklapajucaKugla &k) const{
    if(Sadrzi(DajX(), DajPoluprecnik(), k.DajX(), k.DajPoluprecnik())&&Sadrzi(DajY(), DajPoluprecnik(), k.DajY(), k.DajPoluprecnik())&&Sadrzi(DajZ(), DajPoluprecnik(), k.DajZ(), k.DajPoluprecnik()))
    return true;
    return false;
}
    friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
};

double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){
    return std::sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z));
}

int main ()
{
	return 0;
}
