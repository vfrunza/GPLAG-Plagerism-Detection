/B2017/2018: Zadaća 4, Zadatak 2
#include <iostream>
#include <iostream>
#include <cmath>
#include <memory>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <tuple>
#include <utility>

const double PI(4*std::atan(1));
const double EPSILON(pow(10,-10));
class NepreklapajucaKugla{
    double x,y,z,r;
    public: 
    explicit NepreklapajucaKugla(double r = 0);
    NepreklapajucaKugla(double x, double y, double z, double r = 0);
    explicit NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r = 0);
    double DajX() const{ return x;}
    double DajY() const{ return y;}
    double DajZ() const{ return z;}
    std::tuple<double, double, double> DajCentar() const{ return std::make_tuple(x,y,z); }
    double DajPoluprecnik() const{return r;}
    double DajPovrsinu() const { return 4*r*r*PI;}
    double DajZapreminu() const {return (4*r*r*r*PI)/3. ;}
    NepreklapajucaKugla &PostaviX(double x);
    NepreklapajucaKugla &PostaviY(double y);
    NepreklapajucaKugla &PostaviZ(double z);
    NepreklapajucaKugla &PostaviCentar(double x, double y, double z); 
    NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar);
    NepreklapajucaKugla &PostaviPoluprecnik(double r);
    void Ispisi() const{std::cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}"<<std::endl;}
    void Transliraj(double delta_x, double delta_y, double delta_z);
    bool DaLiSadrzi(const NepreklapajucaKugla &k) const;
    friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
};

int main ()
{
	return 0;
}
