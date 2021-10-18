/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <tuple>
#include <cmath>
#include <vector>
#include <memory>

class Kugla{
    double x,y,z,r;
    public:
    explicit Kugla(double r=0){ Kugla::r=r; }
    Kugla(double x, double y, double z, double r=0){
        Kugla::x=x;Kugla::y=y;Kugla::z=z;Kugla::r=r;
    }
    explicit Kugla(std::tuple<double, double, double> &centar,double r=0){
        Kugla::x=std::get<0>(centar);Kugla::y=std::get<1>(centar);
        Kugla::z=std::get<2>(centar);Kugla::r=r;
    }
    double DajX()const{ return x; }
    double DajY()const{ return y; }
    double DajZ()const{ return z; }
    std::tuple<double, double, double>DajCentar()const{ return std::tie(x,y,z); }
    double DajPoluprecnik()const{ return r; }
    double DajPovrsinu() const{ return r*r*4*atan(1); }
    double DajZapreminu()const{ return (4/3)*r*r*r*4*atan(1); }
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
        Kugla::x=x;Kugla::y=y;Kugla::z=z;
        return *this;
    }
    Kugla &PostaviCentar(std::tuple<double, double, double> &centar){
        Kugla::x=std::get<0>(centar);Kugla::y=std::get<1>(centar);
        Kugla::z=std::get<2>(centar);
        return *this;
    }
    Kugla &PostaviPoluprecnik(double r){
        Kugla::r=r;
        return *this;
    }
    void Ispisi() const{
        std::cout<<"{ ("<<x<<","<<y<<","<<z<<"),"<<r<<"}";
    }
    void Transliraj(double delta_x, double delta_y, double delta_z){
        Kugla::x+=delta_x;Kugla::y+=delta_y;Kugla::z+=delta_z;
    }
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
    bool DaLiSadrzi(const Kugla &k);
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);
};

bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2){
    bool a(true);
    if(k1.x!=k2.x || k1.y!=k2.y || k1.z!=k2.z || k1.r!=k2.r){
        a=false;
    }
    return a;
}
bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2){
    bool a(true);
    if(k1.r!=k2.r){
        a=false;
    }
    return a;
}
bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2){
    bool a(true);
    if(k1.x!=k2.x || k1.y!=k2.y || k1.z!=k2.z)a=false;
    return a;
}
bool Kugla::DaLiSadrzi(const Kugla &k){
    bool a(true);
    if((Kugla::x+Kugla::r)<(k.x+k.r) || (Kugla::y+Kugla::r)<(k.y+k.r) || (Kugla::z+Kugla::r)<(k.z+k.r) || (Kugla::x-Kugla::r)>(k.x-k.r) ||
         (Kugla::y-Kugla::r)>(k.y-k.r) || (Kugla::z-Kugla::r)>(k.z-k.r)){
        a=false;
    }
    return a;
}
double RastojanjeCentara(const Kugla &k1, const Kugla &k2){
    return fabs(k1.r-k2.r);
}
int main ()
{
    int n;
    std::cout<<"Unesite broj kugla: ";
    std::cin>>n;
    std::vector<std::shared_ptr<Kugla>> p_kugli(n);
    for(int i(0);i<n;i++){
        std::cout<<"Unesite centar "<<i+1<<". kugle: ";
        double x,y,z,r;
        std::cin>>x>>y>>z;
        if(!std::cin){
            std::cout<<"Ilegalan centar!";
            std::cin.clear();
            std::cin.ignore(1000,'\n');
            i--;
            continue;
        }
        std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
        std::cin>>r;
        if(!std::cin || r<0){
            std::cout<<"Ilegalan poluprecnik!";
            std::cin.clear();
            std::cin.ignore(1000,'\n');
            i--;
            continue;
        }
        p_kugli[i]=std::make_shared<Kugla>(Kugla(x,y,z,r));
    }
    
	return 0;
}

