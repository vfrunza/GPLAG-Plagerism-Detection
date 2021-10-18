/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <tuple>
#include <algorithm>
#include <memory>
#include <vector>
#include <iomanip>

class Kugla {
    double x,y,z,r;
    static constexpr double PI{4*atan(1.)};
    static bool DaliSuJednaki(double x1, double x2) { return fabs(x1-x2)<=pow(10,-10)*(fabs(x1)+fabs(x2)); }
    static bool DaLiJeCentarUnutar(double x,double y, double z, const Kugla &k1);
    static bool DaLiJeCentarIzvan(double x, double y, double z, const Kugla &k1);
    static double RastojanjeCentara2(double x, double y, double z, const Kugla &k2);
public:
    explicit Kugla(double r=0);
    Kugla(double x, double y, double z, double r=0);
    explicit Kugla(const std::tuple<double,double,double> &centar, double r=0);
    double DajX() const { return x; }
    double DajY() const { return y; }
    double DajZ() const { return z; }
    std::tuple<double,double,double> DajCentar() const { return std::make_tuple(x,y,z); }
    double DajPoluprecnik() const { return r; }
    double DajPovrsinu() const { return 4*r*r*PI; }
    double DajZapreminu() const { return 4*r*r*r*PI/3; }
    Kugla &PostaviX(double x) { Kugla::x=x; return *this; }
    Kugla &PostaviY(double y) { Kugla::y=y; return *this; }
    Kugla &PostaviZ(double z) { Kugla::z=z; return *this; }
    Kugla &PostaviCentar(double x, double y, double z);
    Kugla &PostaviCentar(const std::tuple<double,double,double> &centar);
    Kugla &PostaviPoluprecnik(double r);
    void Ispisi() const { std::cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}"<<std::endl; }
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

int _main ()
{
    std::cout<<"Unesite broj kugla: ";
    int brojkugla;
    std::cin>>brojkugla;
    if (!std::cin || brojkugla<=0) {
        do {
            std::cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;
            std::cin.clear();
            std::cin.ignore(1000,'\n');
            std::cin>>brojkugla;
        }while(brojkugla<=0 || !std::cin); 
    }
    std::vector<std::shared_ptr<Kugla>> VektorKugli(brojkugla);
    for (int i=0;i<brojkugla;i++) {
        std::cout<<"Unesite centar "<<i+1<<". kugle: ";
        double x,y,z;
        std::cin>>x>>y>>z;
        if (!std::cin) {
            do {
                std::cout<<"Neispravan centar"<<std::endl<<"Unesite centar "<<i+1<<". kugle: ";
                std::cin.clear();
                std::cin.ignore(1000,'\n');
                std::cin>>x>>y>>z;
            } while (!std::cin);
        }
        std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
        double r;
        std::cin>>r;
        if (r<0 || !std::cin) {
            std::cout<<"Ilegalan poluprecnik"<<std::endl;
            std::cin.clear();
            std::cin.ignore(1000,'\n');
            i--; continue;
        }
        VektorKugli.at(i)=std::make_shared<Kugla>(x,y,z,r);
    }
    std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double dx,dy,dz;
    std::cin>>dx>>dy>>dz;
    if (!std::cin) {
        do {
            std::cout<<"Neispravni parametri translacije, unesite ponovo!"<<std::endl;
            std::cin.clear();
            std::cin.ignore(1000,'\n');
            std::cin>>dx>>dy>>dz;
        } while (!std::cin);
    }
    std::transform(VektorKugli.begin(),VektorKugli.end(),VektorKugli.begin(),[dx,dy,dz](std::shared_ptr<Kugla> k) { k->Transliraj(dx,dy,dz); return k;});
    std::sort(VektorKugli.begin(),VektorKugli.end(),[](std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2) { return k1->DajZapreminu()<k2->DajZapreminu();});
    std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<std::endl;
    std::for_each(VektorKugli.begin(),VektorKugli.end(),[](std::shared_ptr<Kugla> k1) { k1->Ispisi();});
    std::cout<<"Kugla sa najvecom povrsinom je: ";
    (**(std::max_element(VektorKugli.begin(),VektorKugli.end(),[](std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2) { return k1->DajPovrsinu()<k2->DajPovrsinu();}))).Ispisi();
    int brojacpresjeka(0), i(1);
    std::for_each(VektorKugli.begin(),VektorKugli.end(), [&brojacpresjeka,VektorKugli,&i](std::shared_ptr<Kugla> k1) {
        std::for_each(VektorKugli.begin()+i,VektorKugli.end(),[&brojacpresjeka,k1,VektorKugli](std::shared_ptr<Kugla> k2) {
            if (DaLiSeSijeku(*k1,*k2)) {
                std::cout<<"Presjecaju se kugle: ";
                k1->Ispisi();k2->Ispisi(); brojacpresjeka++;
            }
        }); i++;
    });
    if (!brojacpresjeka) std::cout<<"Ne postoje kugle koje se presjecaju!";
	return 0;
}

//IMPLEMENTACIJA
Kugla::Kugla(double r) {
    if (r<0) throw std::domain_error("Ilegalan poluprecnik");
    x=0;y=0;z=0;Kugla::r=r;
}
Kugla::Kugla(double x, double y, double z, double r) {
    if (r<0) throw std::domain_error("Ilegalan poluprecnik");
    Kugla::x=x; Kugla::y=y; Kugla::z=z; Kugla::r=r;
}
Kugla::Kugla(const std::tuple<double,double,double> &centar, double r) {
    if (r<0) throw std::domain_error("Ilegalan poluprecnik");
    x=std::get<0>(centar); y=std::get<1>(centar); z=std::get<2>(centar); Kugla::r=r;
} 
Kugla& Kugla::PostaviCentar(double x, double y, double z) {
    Kugla::x=x; Kugla::y=y; Kugla::z=z; return *this;
}
Kugla& Kugla::PostaviCentar(const std::tuple<double,double,double> &centar) {
    x=std::get<0>(centar); y=std::get<1>(centar); z=std::get<2>(centar); return *this; 
}
Kugla& Kugla::PostaviPoluprecnik(double r) { 
    if (r<0) throw std::domain_error("Ilegalan poluprecnik");
    Kugla::r=r; return *this; 
}
void Kugla::Transliraj(double delta_x, double delta_y, double delta_z) {
    x+=delta_x; y+=delta_y; z+=delta_z;
}
bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2) {
    return (DaLiSuKoncentricne(k1,k2) && DaLiSuPodudarne(k1,k2));
}
bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2) {
    return (Kugla::DaliSuJednaki(k1.x,k2.x) && Kugla::DaliSuJednaki(k1.y,k2.y) && Kugla::DaliSuJednaki(k1.z,k2.z));
}
bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2) {
    return Kugla::DaliSuJednaki(k1.r,k2.r);
}
bool Kugla::DaLiJeCentarUnutar(double x,double y, double z, const Kugla &k1) {
    return (RastojanjeCentara2(x,y,z,k1)<k1.r || DaliSuJednaki(RastojanjeCentara2(x,y,z,k1),k1.r)); 
}
bool Kugla::DaLiJeCentarIzvan(double x, double y, double z, const Kugla &k1) {
    return ((x>=k1.x+k1.r || x<=k1.x-k1.r) || (y>=k1.y+k1.r || y<=k1.y-k1.r) || (z>=k1.z+k1.r || z<=k1.z-k1.r));
}
bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2) {
    bool logicka(false);
    if (Kugla::DaLiJeCentarUnutar(k1.x,k1.y,k1.z,k2)) {
        logicka=Kugla::DaliSuJednaki(RastojanjeCentara(k1,k2)+k1.r,k2.r);
    }
    if (!logicka) {
        if (Kugla::DaLiJeCentarUnutar(k2.x,k2.y,k2.z,k1)) {
            logicka=Kugla::DaliSuJednaki(RastojanjeCentara(k1,k2)+k2.r,k1.r);
        }
    }
    return logicka;
}
bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2) {
    return (Kugla::DaLiJeCentarIzvan(k1.x,k1.y,k1.z,k2) && Kugla::DaliSuJednaki(RastojanjeCentara(k1,k2),k1.r+k2.r));
}
double RastojanjeCentara(const Kugla &k1, const Kugla &k2) {
    return sqrt(pow(k2.x-k1.x,2)+pow(k2.y-k1.y,2)+pow(k2.z-k1.z,2));
}
bool Kugla::DaLiSadrzi(const Kugla &k) const {
    return (Kugla::DaLiJeCentarUnutar(k.DajX(),k.DajY(),k.DajZ(),*this) && r>=RastojanjeCentara(k,*this)+k.DajPoluprecnik());
}
bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2) {
    return (Kugla::DaLiJeCentarUnutar(k1.x,k1.y,k1.z,k2) || Kugla::DaLiJeCentarUnutar(k2.x,k2.y,k2.z,k1) || DaLiSeSijeku(k1,k2));
}
bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2) {
    bool logicka(false);
    if (Kugla::DaLiJeCentarUnutar(k1.x,k1.y,k1.z,k2)) {
        logicka=(k1.r+RastojanjeCentara(k1,k2)>k2.r);
    }
    else if (Kugla::DaLiJeCentarUnutar(k2.x,k2.y,k2.z,k1)) {
        logicka=(k2.r+RastojanjeCentara(k1,k2)>k1.r);
    }
    else 
        logicka=(RastojanjeCentara(k1,k2)<k1.r+k2.r);
    return logicka;
}
double Kugla::RastojanjeCentara2(double x, double y, double z, const Kugla &k2) {
    return sqrt(pow(k2.x-x,2)+pow(k2.y-y,2)+pow(k2.z-z,2));
}