/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <vector>
#include <memory>
#include <tuple>
#include <cmath>
#include <algorithm>
#include <stdexcept>
using namespace std;

double eps=0.0000000001;
double pi=atan(1) * 4;

class NepreklapajucaKugla
{
private:
    double xk,yk,zk,p;
public:
    explicit NepreklapajucaKugla(double r = 0){
        if(r<0) throw domain_error("Ilegalan poluprecnik");
        p=r;
        xk=0; yk=0; zk=0;
    }
    NepreklapajucaKugla(double x, double y, double z, double r = 0){
        if(r<0) throw domain_error("Ilegalan poluprecnik");
        p=r;
        xk=x; yk=y; zk=z;
    }
    explicit NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r = 0){
        
        if(r<0) throw domain_error("Ilegalan poluprecnik");
        p=r;
        xk=get<0>(centar);
        yk=get<1>(centar);
        zk=get<2>(centar);
    }
    double DajX() const { return xk;}
    double DajY() const {return yk;}
    double DajZ() const {return zk;}
    std::tuple<double, double, double> DajCentar() const { return make_tuple(xk,yk,zk);}
    double DajPoluprecnik() const { return p;}
    double DajPovrsinu() const {return 4*pi*p*p;}
    double DajZapreminu() const {return (4*pi*p*p*p)/3;}
    NepreklapajucaKugla &PostaviX(double x) { xk=x; return *this;}
    NepreklapajucaKugla &PostaviY(double y) {yk=y;return *this;}
    NepreklapajucaKugla &PostaviZ(double z) {zk=z;return *this;}
    NepreklapajucaKugla &PostaviCentar(double x, double y, double z){
        xk=x;
        yk=y;
        zk=z;
        return *this;
    }
    NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar){
        xk=get<0>(centar);
        yk=get<1>(centar);
        zk=get<2>(centar);
        return *this;
    }
    NepreklapajucaKugla &PostaviPoluprecnik(double r) { if(r<0) throw domain_error("Ilegalan poluprecnik");p=r;return *this;}
    void Ispisi() const{
        cout<<"{("<<xk<<","<<yk<<","<<zk<<"), "<<p<<"}"<<endl;
    }
    void Transliraj(double delta_x, double delta_y, double delta_z){
        xk+=delta_x; yk+=delta_y; zk+=delta_z;
    }
    friend bool DaLiSuIdenticne(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){
        
    }
    friend bool DaLiSuPodudarne(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
    friend bool DaLiSuKoncentricne(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
    friend bool DaLiSeDodirujuIzvana(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
    friend bool DaLiSeDodirujuIznutra(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
    friend bool DaLiSePreklapaju(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
    friend bool DaLiSeSijeku(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
    bool DaLiSadrzi(const NepreklapajucaKugla &k) const;
    friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
    
};

int main ()
{
	return 0;
}
