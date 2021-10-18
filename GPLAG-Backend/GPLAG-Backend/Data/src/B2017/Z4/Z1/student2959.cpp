/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <cmath>
#include <memory>
#include <vector>
#include <algorithm>

class Kugla
{
    double x,y,z,r;
    static double DajUdaljenost(double x1, double y1, double z1, double x2, double y2, double z2) {
        return sqrt(pow((x2-x1),2)+pow((y2-y1),2)+pow((z2-z1),2));
    }
    static bool Jednako(double x, double y) {
        return fabs(x-y)<=1e-10*(fabs(x)+fabs(y));
    }
public:
    explicit Kugla(double r=0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        x=y=z=0;
        Kugla::r=r;
    }
    Kugla(double x, double y, double z, double r=0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::x=x;
        Kugla::y=y;
        Kugla::z=z;
        Kugla::r=r;
    }
    explicit Kugla(const std::tuple<double,double,double> &centar, double r=0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        std::tie(x,y,z)=centar;
        Kugla::r=r;
    }
    double DajX() const {
        return x;
    }
    double DajY() const {
        return y;
    }
    double DajZ() const {
        return z;
    }
    std::tuple<double, double, double> DajCentar() const {
        return std::make_tuple(x,y,z);
    }
    double DajPoluprecnik() const {
        return r;
    }
    double DajPovrsinu() const {
        return 4*DajPoluprecnik()*DajPoluprecnik()*4*atan(1);
    }
    double DajZapreminu() const {
        return (4*DajPoluprecnik()*DajPoluprecnik()*DajPoluprecnik()*4*atan(1))/3.;
    }
    Kugla &PostaviX(double x) {
        Kugla::x=x;
        return *this;
    }
    Kugla &PostaviY(double y) {
        Kugla::y=y;
        return *this;
    }
    Kugla &PostaviZ(double z) {
        Kugla::z=z;
        return *this;
    }
    Kugla &PostaviCentar(double x, double y, double z) {
        Kugla::x=x;
        Kugla::y=y;
        Kugla::z=z;
        return *this;
    }
    Kugla &PostaviCentar(const std::tuple<double,double,double> &centar) {
        std::tie(x,y,z)=centar;
        return *this;
    }
    Kugla &PostaviPoluprecnik(double r) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::r=r;
        return *this;
    }
    void Ispisi() const {
        std::cout<<"{("<<DajX()<<","<<DajY()<<","<<DajZ()<<"),"<<DajPoluprecnik()<<"}"<<std::endl;
    }
    void Transliraj(double delta_x, double delta_y, double delta_z) {
        x+=delta_x;
        y+=delta_y;
        z+=delta_z;
    }
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2) {
        return Jednako(k1.DajX(),k2.DajX()) && Jednako(k1.DajY(),k2.DajY()) && Jednako(k1.DajZ(),k2.DajZ())
               && Jednako(k1.DajPoluprecnik(),k2.DajPoluprecnik());
    }
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2) {
        return Jednako(k1.DajPoluprecnik(),k2.DajPoluprecnik());
    }
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2) {
        return Jednako(k1.DajX(),k2.DajX()) && Jednako(k1.DajY(),k2.DajY()) && Jednako(k1.DajZ(),k2.DajZ());
    }
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2) {
        return Jednako(DajUdaljenost(k1.DajX(),k1.DajY(),k1.DajZ(),k2.DajX(),k2.DajY(),k2.DajZ()),k1.DajPoluprecnik()+k2.DajPoluprecnik());
    }
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2) {
        return Jednako(DajUdaljenost(k1.DajX(),k1.DajY(),k1.DajZ(),k2.DajX(),k2.DajY(),k2.DajZ()),fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik()));
    }
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2) {
        return DaLiSeSijeku(k1,k2) || k1.DaLiSadrzi(k2) || k2.DaLiSadrzi(k1);
    }
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2) {
        return (DajUdaljenost(k1.DajX(),k1.DajY(),k1.DajZ(),k2.DajX(),k2.DajY(),k2.DajZ())<k1.DajPoluprecnik()+k2.DajPoluprecnik() &&
                DajUdaljenost(k1.DajX(),k1.DajY(),k1.DajZ(),k2.DajX(),k2.DajY(),k2.DajZ())>fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik()));
    }
    bool DaLiSadrzi(const Kugla &k) const {
        return DajUdaljenost(DajX(),DajY(),DajZ(),k.DajX(),k.DajY(),k.DajZ())<=fabs(DajPoluprecnik()-k.DajPoluprecnik());
    }
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2) {
        return DajUdaljenost(k1.DajX(),k1.DajY(),k1.DajZ(),k2.DajX(),k2.DajY(),k2.DajZ());
    }
};

int main ()
{
    int n;
    std::cout<<"Unesite broj kugla: ";
    for(;;) {
        std::cin>>n;
        if(!std::cin || n<1) {
            std::cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;
            std::cin.clear();
            std::cin.ignore(1000,'\n');
        } else break;
    }
    std::vector<std::shared_ptr<Kugla>>v;
    for(int i=0; i<n; i++) {
        try {
            double x,y,z,r;
            std::cout<<"Unesite centar "<<i+1<<". kugle: ";
            if(!(std::cin>>x) || !(std::cin>>y) || !(std::cin>>z)) throw std::domain_error("Neispravan centar");
            std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
            if(!(std::cin>>r)) throw std::domain_error("Ilegalan poluprecnik");
            v.emplace_back(std::make_shared<Kugla>(Kugla {x,y,z,r}));
        } catch(std::domain_error e) {
            std::cout<<e.what()<<std::endl;
            i--;
            std::cin.clear();
            std::cin.ignore(10000,'\n');
        }
    }
    std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double d_x,d_y,d_z;
    for(;;){
        if(!(std::cin>>d_x) || !(std::cin>>d_y) || !(std::cin>>d_z)) {
            std::cout<<"Neispravni parametri translacije, unesite ponovo!"<<std::endl;
            std::cin.clear();
            std::cin.ignore(10000,'\n');
        }
        else break;
    }
    std::transform(v.begin(),v.end(),v.begin(),[d_x,d_y,d_z](std::shared_ptr<Kugla> p) {
        p->Transliraj(d_x,d_y,d_z);
        return p;
    });
    std::sort(v.begin(),v.end(),[](std::shared_ptr<Kugla> p1,std::shared_ptr<Kugla> p2) {
        return p1->DajZapreminu()<p2->DajZapreminu();
    });
    std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<std::endl;
    std::for_each(v.begin(),v.end(),[](std::shared_ptr<Kugla> p) {
        p->Ispisi();
    });
    auto max=std::max_element(v.begin(),v.end(),[](std::shared_ptr<Kugla> p1,std::shared_ptr<Kugla> p2) {
        return p1->DajPovrsinu()<p2->DajPovrsinu();
    });
    std::shared_ptr<Kugla>m(*max);
    std::cout<<"Kugla sa najvecom povrsinom je: ";
    m->Ispisi();
    int broj_presjeka(0), br_el(0);
    std::for_each(v.begin(),v.end(),[v,&broj_presjeka,&br_el](std::shared_ptr<Kugla> p) {
        for_each(v.begin()+br_el,v.end(),[p,&broj_presjeka](std::shared_ptr<Kugla> q) {
            if(!DaLiSuIdenticne(*p,*q) && DaLiSeSijeku(*p,*q)) {
                std::cout<<"Presjecaju se kugle: ";
                p->Ispisi();
                q->Ispisi();
                broj_presjeka++;
            }
        });
        br_el++;
    });
    if(broj_presjeka==0) std::cout<<"Ne postoje kugle koje se presjecaju!";
    return 0;
}
