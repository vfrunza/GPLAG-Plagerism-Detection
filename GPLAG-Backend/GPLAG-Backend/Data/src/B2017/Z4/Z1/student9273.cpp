#include <iostream>
#include <vector>
#include <tuple>


class Kugla{
    double x, y, z, r;
    public:
    
    explicit Kugla(double r = 0){
        this->x=0;
        this->y=0;
        this->z=0;
        this->r=r;
    }
    Kugla(double x, double y, double z, double r = 0){
        this->x=x;
        this->y=y;
        this->z=z;
        this->r=r;
    }
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0){
        this->x=std::get<0>(centar);
        this->y=std::get<1>(centar);
        this->z=std::get<2>(centar);
        this->r=r;
    }
    double DajX() const {return x;}
    double DajY() const{return y;}
    double DajZ() const {return z;}
    std::tuple<double, double, double> DajCentar() const{return std::make_tuple(x,y,z);}
    double DajPoluprecnik() const{return r;}
    double DajPovrsinu() const{return r*r*3.14;}
    double DajZapreminu() const{return (4/3*r*r*r*3.14);}
    Kugla &PostaviX(double x)
    Kugla &PostaviY(double y);
    Kugla &PostaviZ(double z);
    Kugla &PostaviCentar(double x, double y, double z);
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar);
    Kugla &PostaviPoluprecnik(double r);
    void Ispisi() const{
        std::cout <<" { ("<<x<<" , "<<y<<" , "<<z<<" ) , "<<r <<"} "<< std::endl;
    }
    void Transliraj(double delta_x, double delta_y, double delta_z);
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
    bool DaLiSadrzi(const Kugla &k) const;
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);
};

int main(){
    
    Kugla Kugla1=Kugla();
    Kugla1.Ispisi();
    
    
    
    return 0;
}


