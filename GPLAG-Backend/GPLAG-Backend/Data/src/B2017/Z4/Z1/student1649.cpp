/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <cmath>
#include <tuple>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <memory>

class Kugla{
    double xk, yk, zk, rk;
    public:

    explicit Kugla(double r = 0){ 
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        xk = 0; yk = 0; zk = 0; rk = r;}
    
    Kugla(double x, double y, double z, double r = 0){
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        xk = x; yk = y; zk = z; rk = r;
    }
    
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0){
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        xk = std::get<0>(centar); yk = std::get<1>(centar); zk = std::get<2>(centar); rk = r;
    }
    
    double DajX() const{ return xk;}
    double DajY() const{ return yk;}
    double DajZ() const{ return zk;}
    std::tuple<double,double,double> DajCentar() const{ return std::make_tuple(xk,yk,zk);}
    double DajPoluprecnik() const{ return rk;}
    double DajPovrsinu() const{ return 4*4*atan(1)*rk*rk;}
    double DajZapreminu() const{ return (4./3)*4*atan(1)*rk*rk*rk;}
    
    Kugla &PostaviX(double x){
        xk = x;
        return *this;
    }
    
    Kugla &PostaviY(double y){
        yk = y;
        return *this;
    }
    
    Kugla &PostaviZ(double z){
        zk = z;
        return *this;
    }
    
    Kugla &PostaviCentar(double x, double y, double z){
        xk = x; yk = y; zk = z;
        return *this;
    }
    
    Kugla &PostaviCentar(std::tuple<double, double, double> &centar){
        xk = std::get<0>(centar);
        yk = std::get<1>(centar);
        zk = std::get<2>(centar);
        return *this;
    }
    
    Kugla &PostaviPoluprecnik(double r){
        rk = r;
        return *this;
    }
    
    void Ispisi() const{
       std::cout<<"{("<<xk<<","<<yk<<","<<zk<<"),"<<rk<<"}"; 
    }
    
    void Transliraj(double delta_x, double delta_y, double delta_z){
        xk+=delta_x; yk+=delta_y; zk+=delta_z;
    }
    
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
    
    bool DaLiSadrzi(const Kugla &k) const{
        return true;
    }
    
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);
    
};

bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2){
    if(k1.xk != k2.xk || k1.yk != k2.yk || k1.zk != k2.zk || k1.rk != k2.rk) return false;
    return true;
}

bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2){
    if(k1.rk != k2.rk) return false;
    return true;
}

bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2){
    if(k1.xk == k2.xk && k1.yk == k2.yk && k1.zk == k2.zk) return true;
    return false;
}

double RastojanjeCentara(const Kugla &k1, const Kugla &k2){
    return std::sqrt((k1.xk-k2.xk)*(k1.xk-k2.xk)+(k1.yk-k2.yk)*(k1.yk-k2.yk)+(k1.zk-k2.zk)*(k1.zk-k2.zk));
}


int main ()
{
    std::vector<std::shared_ptr<Kugla>> vektor, novi;
    int n;
    std::cout<<"Unesite broj kugla: ";
    std::cin>>n;
    double x, y, z, r;
    for(int i = 0; i < n; i++){
        std::cout<<"Unesite centar "<<i+1<<". kugle: ";
        std::cin>>x>>y>>z;
        std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
        std::cin>>r;
        std::shared_ptr<Kugla> pok = std::make_shared<Kugla>(x,y,z,r);
        vektor.push_back(pok);
    }
    double delx, dely, delz;
    std::cout<<"Unesite parametre translacije (delta_x, delta_y, delta_z) :";
    std::cin>>delx>>dely>>delz;
    std::cout<<"Kugle nakon obavljene transformacije imaju sljedece vrijednosti: ";
    for(Kugla x: vektor) x.Ispisi();
    
	return 0;
}
