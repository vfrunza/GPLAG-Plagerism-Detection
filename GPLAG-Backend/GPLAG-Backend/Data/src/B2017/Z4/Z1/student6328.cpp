/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <tuple>
#include <cmath>
#include <algorithm>
#include <memory>
#include <stdexcept>
#include <iomanip>
#include <vector>
#include <new>
const double PI=4*atan(1.);
const double EPS=1e-10;
class Kugla {
    double x,y,z,r;
public:
    explicit Kugla(double r = 0) {
        if(r<0) throw std::domain_error ("Ilegalan poluprecnik");
        Kugla::r=r;
        x=0;
        y=0;
        z=0;
    };
    Kugla(double x, double y, double z, double r = 0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::x=x;
        Kugla::y=y;
        Kugla::z=z;
        Kugla::r=r;
    };
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0) {
        x=std::get<0>(centar);
        y=std::get<1>(centar);
        z=std::get<2>(centar);
        Kugla::r=r;
    };
    double DajX() const {
        return x;
    };
    double DajY() const {
        return y;
    };
    double DajZ() const {
        return z;
    };
    std::tuple<double, double, double> DajCentar() const {
        std::tuple<double,double,double> pom;
        pom=std::make_tuple(x,y,z);
        return pom;
    };
    double DajPoluprecnik() const {
        return r;
    };
    double DajPovrsinu() const {
        return 4*PI*r*r;
    };
    double DajZapreminu() const {
        return (4*PI*r*r*r)/3;
    };
    Kugla &PostaviX(double x) {
        Kugla::x=x;
        return *this;
    };
    Kugla &PostaviY(double y) {
        Kugla::y=y;
        return *this;
    };
    Kugla &PostaviZ(double z) {
        Kugla::z=z;
        return *this;
    };
    Kugla &PostaviCentar(double x, double y, double z) {
        Kugla::x=x;
        Kugla::y=y;
        Kugla::z=z;
        return *this;
    };
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar) {
        x=std::get<0>(centar);
        y=std::get<1>(centar);
        z=std::get<2>(centar);
        return *this;
    };
    Kugla &PostaviPoluprecnik(double r) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::r=r;
        return *this;
    };
    void Ispisi() const {
        std::cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}"<<std::endl;
    };
    void Transliraj(double delta_x, double delta_y, double delta_z) {
        Kugla::x+=delta_x;
        Kugla::y+=delta_y;
        Kugla::z+=delta_z;
    };
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

bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2){
    double rastojanje(sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z)));
    if(fabs(rastojanje-(k1.r+k2.r))<=EPS*(fabs(rastojanje)+fabs(k1.r+k2.r))) return true;
    return false;
}
bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2){
    if(fabs(k1.x-k2.x)<=EPS*(fabs(k1.x)+fabs(k2.x)) &&  fabs(k1.y-k2.y)<=EPS*(fabs(k1.y)+fabs(k2.y)) && fabs(k1.z-k2.z)<=EPS*(fabs(k1.z)+fabs(k2.z))) return true;
    return false;
}
bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2){
    if(fabs(k1.r-k2.r)<=EPS*(fabs(k1.r)+fabs(k2.r))) return true;
    return false;
}
bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2){
    if(fabs(k1.x-k2.x)<=EPS*(fabs(k1.x)+fabs(k2.x)) && fabs(k1.y-k2.y)<=EPS*(fabs(k1.y)+fabs(k2.y)) && fabs(k1.z-k2.z)<=EPS*(fabs(k1.z)+fabs(k2.z)) && fabs(k1.r-k2.r)<=EPS*(fabs(k1.r)+fabs(k2.r))) return true;
    return false;
}

bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2){
    double rastojanje(sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z)));
    Kugla veca,manja;
    if(k1.r>k2.r) {
        veca=k1;
        manja=k2;
    } else {
        veca=k2;
        manja=k1;
    }
    if(fabs(rastojanje+manja.r-veca.r)<=EPS*(fabs(rastojanje+manja.r)+fabs(veca.r))) return true;
    return false;
}
bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2){
    double rastojanje(sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z)));
    Kugla veca,manja;
    if(k1.r>k2.r) {
        veca=k1;
        manja=k2;
    } else {
        manja=k1;
        veca=k2;
    }
    if(rastojanje<k1.r+k2.r && rastojanje+manja.r>veca.r) return true;
    return false;
}
bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2){
    double rastojanje(sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z)));
    if(rastojanje>k1.r+k2.r || rastojanje<abs(k2.r-k1.r)) return true;
    return false;
}
bool Kugla::DaLiSadrzi(const Kugla &k) const{
    return r+k.r>sqrt(pow(k.x-x,2)+pow(k.y-y,2)+pow(k.z-z,2));
}
double RastojanjeCentara(const Kugla &k1, const Kugla &k2){
    return sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z));
}


int main (){
    std::cout<<"Unesite broj kugla: ";
    int n;
    std::cin>>n;
    while(!std::cin || n<=0) {
        std::cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;
        std::cin.clear();
        std::cin.ignore(100000,'\n');
        std::cin>>n;
    }
    std::vector<std::shared_ptr<Kugla>>v;
    v.resize(n);
    for(int i(0); i<n; i++) {
        std::cout<<"Unesite centar "<<i+1<<". kugle: ";
        double x,y,z,r;
        std::cin>>x>>y>>z;
        if(!std::cin) {
            std::cout<<"Neispravan centar"<<std::endl;
            std::cin.clear();
            std::cin.ignore(100000,'\n');
            i--; 
            continue;
        }
        std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
        std::cin>>r;
        if(!std::cin) {
            std::cout<<"Ilegalan poluprecnik"<<std::endl;
            std::cin.clear();
            std::cin.ignore(100000,'\n');
            i--;
            continue;
        }
        try {
            v.at(i)=std::make_shared<Kugla>(x,y,z,r);
        } catch(std::exception &izuzetak) {
            std::cout<<izuzetak.what()<<std::endl;
            i--;
        }
    }
    double d_x, d_y, d_z;
    std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    std::cin>>d_x>>d_y>>d_z;
    while(!std::cin) {
        std::cout<<"Neispravni parametri translacije, unesite ponovo!"<<std::endl;
        std::cin.clear();
        std::cin.ignore(100000,'\n');
        std::cin>>d_x>>d_y>>d_z;
    }
    std::transform(v.begin(),v.end(),v.begin(), [d_x,d_y,d_z] (std::shared_ptr<Kugla> p1) {
        (*p1).Transliraj(d_x,d_y,d_z);
        return p1;
    });
    std::sort(v.begin(),v.end(), [] (std::shared_ptr<Kugla> p1, std::shared_ptr<Kugla> p2) {
        return (*p1).DajZapreminu()<(*p2).DajZapreminu();
    });
    std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<std::endl;
    std::for_each(v.begin(),v.end(),[] (std::shared_ptr<Kugla>p) {
        (*p).Ispisi();
    });
    auto it(std::max_element(v.begin(),v.end(),[] (std::shared_ptr<Kugla>p1, std::shared_ptr<Kugla> p2) {
        return (*p1).DajPovrsinu()<(*p2).DajPovrsinu();
    }));
    std::cout<<"Kugla sa najvecom povrsinom je: ";
    if(it!=v.end()) (*it)->Ispisi();
    int pom(0);
    bool presjecaju_se(false);
    std::for_each(v.begin(),v.end(),[v,&pom, &presjecaju_se](std::shared_ptr<Kugla> p1) {
        pom++;
        std::for_each(v.begin()+pom,v.end(),[p1,&presjecaju_se](std::shared_ptr<Kugla> p2) {
            if(DaLiSeSijeku(*p1,*p2)) {
                presjecaju_se=true;
                std::cout<<"Presjecaju se kugle: ";
                (*p1).Ispisi();
                (*p2).Ispisi();
                std::cout<<std::endl;
            }
        });
    });
    if(!presjecaju_se) std::cout<<"Ne postoje kugle koje se presjecaju!";
    return 0;
}
