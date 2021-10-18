/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <tuple>
#include <new>
#include <memory>
#include <vector>

const double PI(4*atan(1));
const double EPSILON(0.0000000001);

class Kugla
{
    double x,y,z,r;
public:
    explicit Kugla(double r = 0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        x=0;
        y=0;
        z=0;
        Kugla::r=r;
    }
    Kugla(double x = 0, double y=0, double z=0, double r = 0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::x=x;
        Kugla::y=y;
        Kugla::z=z;
        Kugla::r=r;
    }
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::r=r;
        Kugla::x=std::get<0>(centar);
        Kugla::y=std::get<1>(centar);
        Kugla::z=std::get<2>(centar);
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
        std::tuple<double,double,double> t;
        t=std::make_tuple(x,y,z);
        return t;
    }
    double DajPoluprecnik() const {
        return r;
    }
    double DajPovrsinu() const {
        return (4*r*r*PI);
    }
    double DajZapreminu() const {
        return (4*r*r*r*PI/3);
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
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar) {
        Kugla::x=std::get<0>(centar);
        Kugla::y=std::get<1>(centar);
        Kugla::z=std::get<2>(centar);
        return *this;
    }
    Kugla &PostaviPoluprecnik(double r) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::r=r;
        return *this;

    }
    void Ispisi() const {
        std::cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}"<<std::endl;
    }
    void Transliraj(double delta_x, double delta_y, double delta_z) {
        x+=delta_x;
        y+=delta_y;
        z+=delta_z;
    }
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2) {
        return((fabs(k1.DajX()-k2.DajX())<EPSILON*(fabs(k1.DajX())+fabs(k2.DajX())) || (fabs(k1.DajX())<EPSILON && fabs(k2.DajX())<EPSILON)) && (fabs(k1.DajY()-k2.DajY())<EPSILON*(fabs(k1.DajY())+fabs(k2.DajY())) || (fabs(k1.DajY())<EPSILON && fabs(k2.DajY())<EPSILON)) && (fabs(k1.DajZ()-k2.DajZ())<EPSILON*(fabs(k1.DajZ())+fabs(k2.DajZ())) || (fabs(k1.DajZ())<EPSILON && fabs(k2.DajZ())<EPSILON)) && (fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik())<EPSILON*(fabs(k1.DajPoluprecnik())+fabs(k2.DajPoluprecnik())) || (k1.DajPoluprecnik()<EPSILON && k2.DajPoluprecnik()<EPSILON)));
    }
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2) {
        return(fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik())<EPSILON*(fabs(k1.DajPoluprecnik())+fabs(k2.DajPoluprecnik())) || (k1.DajPoluprecnik()<EPSILON && k2.DajPoluprecnik()<EPSILON));
    }
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2) {
        return((fabs(k1.DajX()-k2.DajX())<EPSILON*(fabs(k1.DajX())+fabs(k2.DajX())) || (fabs(k1.DajX())<EPSILON && fabs(k2.DajX())<EPSILON)) && (fabs(k1.DajY()-k2.DajY())<EPSILON*(fabs(k1.DajY())+fabs(k2.DajY())) || (fabs(k1.DajY())<EPSILON && fabs(k2.DajY())<EPSILON)) && (fabs(k1.DajZ()-k2.DajZ())<EPSILON*(fabs(k1.DajZ())+fabs(k2.DajZ())) || (fabs(k1.DajZ())<EPSILON && fabs(k2.DajZ())<EPSILON)));
    }
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2) {
        double u(k1.DajPoluprecnik()+k2.DajPoluprecnik());
        return(fabs(RastojanjeCentara(k1,k2)-u)<EPSILON*(RastojanjeCentara(k1,k2)+u) || (RastojanjeCentara(k1,k2)<EPSILON && k1.DajPoluprecnik()<EPSILON && k2.DajPoluprecnik()<EPSILON));
    }
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2) {
        double u(fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik()));
        return((fabs(RastojanjeCentara(k1,k2)-u)<EPSILON*(RastojanjeCentara(k1,k2)+u) || (RastojanjeCentara(k1,k2)<EPSILON && k1.DajPoluprecnik()<EPSILON && k2.DajPoluprecnik()<EPSILON)) && !DaLiSuIdenticne(k1,k2));
    }
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2) {
        return((k1.DajPoluprecnik()+k2.DajPoluprecnik()-RastojanjeCentara(k1,k2))>EPSILON);
    }
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2) {
        return((k1.DajPoluprecnik()+k2.DajPoluprecnik()-RastojanjeCentara(k1,k2))>EPSILON && (RastojanjeCentara(k1,k2)-fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik()))>EPSILON);
    }
    bool DaLiSadrzi(const Kugla &k) const {
        double rastojanje(sqrt((x-k.DajX())*(x-k.DajX())+(y-k.DajY())*(y-k.DajY())+(z-k.DajZ())*(z-k.DajZ())));
        return((r-(rastojanje+k.DajPoluprecnik()))>-EPSILON);
    }
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2) {
        return(sqrt((k1.DajX()-k2.DajX())*(k1.DajX()-k2.DajX())+(k1.DajY()-k2.DajY())*(k1.DajY()-k2.DajY())+(k1.DajZ()-k2.DajZ())*(k1.DajZ()-k2.DajZ())));
    }
};

int main ()
{
    int n;
    std::cout<<"Unesite broj kugla: ";
    std::cin>>n;
    while(n<=0 || !(std::cin)) {
        std::cin.clear();
        std::cin.ignore(1000,'\n');
        std::cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;
        std::cin>>n;
    }
    std::vector<std::shared_ptr<Kugla>>v;
    for(int i(0); i<n; i++) {
        bool T(false);
        double x,y,z,r;
        std::cout<<"Unesite centar "<<i+1<<". kugle: ";
        std::cin>>x;
        std::cin>>y;
        std::cin>>z;
        if(!(std::cin)) {
            while(!(std::cin)) {
                std::cout<<"Neispravan centar "<<std::endl;
                std::cin.clear();
                std::cin.ignore(1000,'\n');
                std::cout<<"Unesite centar "<<i+1<<". kugle: ";
                std::cin>>x;
                std::cin>>y;
                std::cin>>z;
            }
        }
        std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
        std::cin>>r;
        if(!(std::cin) || r<0) {
            std::cout<<"Ilegalan poluprecnik"<<std::endl;
            std::cin.clear();
            std::cin.ignore(1000,'\n');
            i--;
            T=true;
        }
        if(!T) {
            std::shared_ptr<Kugla> p(std::make_shared<Kugla>(Kugla(x,y,z,r)));
            v.push_back(p);
        }
    }
    std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double delta_x,delta_y,delta_z;
    std::cin>>delta_x>>delta_y>>delta_z;
    while(!(std::cin)) {
        std::cout<<"Neispravni parametri translacije, unesite ponovo!"<<std::endl;
        std::cin.clear();
        std::cin.ignore(1000,'\n');
        std::cin>>delta_x>>delta_y>>delta_z;
    }
    std::transform(v.begin(),v.end(),v.begin(), [delta_x,delta_y,delta_z]  (std::shared_ptr<Kugla> p)  {
        double a(p->DajX()),b(p->DajY()),c(p->DajZ());
        a+=delta_x;
        b+=delta_y;
        c+=delta_z;
        p->PostaviX(a);
        p->PostaviY(b);
        p->PostaviZ(c);
        return p;
    });
    std::sort(v.begin(),v.end(), [] (std::shared_ptr<Kugla> p1, std::shared_ptr<Kugla> p2) {
        return (p1->DajZapreminu()<p2->DajZapreminu());
    });
    std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<std::endl;
    std::for_each(v.begin(),v.end(), [] (std::shared_ptr<Kugla> p) {
        p->Ispisi();
    });
    auto pok(std::max_element(v.begin(),v.end(), [] (std::shared_ptr<Kugla> p1, std::shared_ptr<Kugla> p2) {
        return ((p2->DajPovrsinu())>(p1->DajPovrsinu()));
    }));
    std::cout<<"Kugla sa najvecom povrsinom je: ";
    if(pok!=v.end()) (*pok)->Ispisi();
    int brojac(0);
    int br(0);
    std::for_each(v.begin(),v.end()-1, [&brojac,&br,v] (std::shared_ptr<Kugla> p) {
        br++;
        std::for_each(v.begin()+br,v.end(), [&brojac,p] (std::shared_ptr<Kugla> pok) {
            if(DaLiSeSijeku(*p,*pok)) {
                brojac++;
                std::cout<<"Presjecaju se kugle: ";
                p->Ispisi();
                pok->Ispisi();
            };
        });
    });
    if(brojac==0) std::cout<<"Ne postoje kugle koje se presjecaju!";

    return 0;
}
