/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <tuple>
#include <vector>
#include <memory>
#include <algorithm>
#include <map>
const double e=10e-10;
class Kugla
{
    double x,y,z,poluprecnik;
    public:
    explicit Kugla(double r=0) { x=0; y=0; z=0; Kugla::poluprecnik=r; }
    Kugla(double x, double y, double z, double r=0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::x=x; Kugla::y=y; Kugla::z=z;; Kugla::poluprecnik=r;
    }
    explicit Kugla(const std::tuple<double,double,double> &centar, double r=0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::x=std::get<0>(centar);
        Kugla::y=std::get<1>(centar);
        Kugla::z=std::get<2>(centar);
        Kugla::poluprecnik=r;
    }
    double DajX() const { return x; }
    double DajY() const { return y; }
    double DajZ() const { return z; }
    std::tuple<double,double,double> DajCentar() const {
        std::tuple<double,double,double>c;
        c=std::make_tuple(x,y,z);
        return c;
    }
    double DajPoluprecnik() const { return poluprecnik; }
    double DajPovrsinu() const { return 4*poluprecnik*poluprecnik*4*atan(1); }
    double DajZapreminu() const { return (4/3)*poluprecnik*poluprecnik*poluprecnik*4*atan(1); }
    Kugla &PostaviX(double x) { Kugla::x=x; return *this; }
    Kugla &PostaviY(double y) { Kugla::y=y; return *this; }
    Kugla &PostaviZ(double z) { Kugla::z=z; return *this; }
    Kugla &PostaviCentar(double x, double y, double z) {
        Kugla::x=x; Kugla::y=y; Kugla::z=z;
        return *this;
    }
    Kugla &PostaviCentar(const std::tuple<double,double,double> &centar) {
        Kugla::x=std::get<0>(centar);
        Kugla::y=std::get<1>(centar);
        Kugla::z=std::get<2>(centar);
        return *this;
    }
    Kugla &PostaviPoluprecnik(double r) { 
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::poluprecnik=r;
        return *this;
    }
    void Ispisi() const { std::cout << "{("<<x<<","<<y<<","<<z<<"),"<<poluprecnik<<"}" << std::endl; }
    void Transliraj (double delta_x, double delta_y, double delta_z) {
        x+=delta_x; y+=delta_y; z+=delta_z;
    }
    friend bool DaLiSuIdenticne (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuPodudarne (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuKoncentricne (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIzvana (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSePreklapaju (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeSijeku (const Kugla &k1, const Kugla &k2);
    bool DaLiSadrzi(const Kugla &k) const {
        double r_min,r_max;
        if(poluprecnik<k.poluprecnik) r_min=poluprecnik, r_max=k.poluprecnik;
        else r_min=k.poluprecnik, r_max=poluprecnik;
        return (RastojanjeCentara(k,*this)+r_min<r_max);
    }
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);
    
};
bool DaLiSuIdenticne (const Kugla &k1, const Kugla &k2) {
    int brojac(0);
    if(abs(k1.poluprecnik-k2.poluprecnik)<e*(abs(k1.poluprecnik)+abs(k2.poluprecnik))) brojac++;
    if(abs(k1.x-k2.x)<e*(abs(k1.x)+abs(k2.x))) brojac++;
    if(abs(k1.y-k2.y)<e*(abs(k1.y)+abs(k2.y))) brojac++;
    if(abs(k1.z-k2.z)<e*(abs(k1.z)+abs(k2.z))); brojac++;
    if(brojac==4) return true;
    return false;
}
double RastojanjeCentara (const Kugla &k1, const Kugla &k2) {
   return std::sqrt((k2.x-k1.x)*(k2.x-k1.x)+(k2.y-k1.y)*(k2.y-k1.y)+(k2.z-k1.z)*(k2.z-k1.z)); 
}
bool DaLiSuPodudarne (const Kugla &k1, const Kugla &k2) {
    return (abs(k1.poluprecnik-k2.poluprecnik)<e*(abs(k1.poluprecnik)+abs(k2.poluprecnik)));
}
bool DaLiSuKoncentricne (const Kugla &k1, const Kugla &k2) {
    int brojac(0);
    if(abs(k1.x-k2.x)<e*(abs(k1.x)+abs(k2.x))) brojac++;
    if(abs(k1.y-k2.y)<e*(abs(k1.y)+abs(k2.y))) brojac++;
    if(abs(k1.z-k2.z)<e*(abs(k1.z)+abs(k2.z))) brojac++;
    if(brojac==3) return true;
    return false;
}
bool DaLiSeDodirujuIzvana (const Kugla &k1, const Kugla &k2) {
    double r3(k1.poluprecnik+k2.poluprecnik);
    return (fabs(RastojanjeCentara(k1,k2)-r3)<(e*(fabs(RastojanjeCentara(k1,k2))+fabs(r3))));
    //if(RastojanjeCentara(k1,k2)==k1.poluprecnik+k2.poluprecnik) return true;
    //return false;
}
bool DaLiSeDodirujuIznutra (const Kugla &k1, const Kugla &k2) {
    double r3(k1.poluprecnik-k2.poluprecnik);
    return (fabs(RastojanjeCentara(k1,k2)-r3)<(e*(fabs(RastojanjeCentara(k1,k2))+fabs(r3))));
    //if(RastojanjeCentara(k1,k2)==abs(k1.poluprecnik-k2.poluprecnik)) return true;
    //return false;
}
bool DaLiSePreklapaju (const Kugla &k1, const Kugla &k2) {
    return (RastojanjeCentara(k1,k2)<fabs(k1.poluprecnik+k2.poluprecnik));
}
bool DaLiSeSijeku (const Kugla &k1, const Kugla &k2) {
    double r_min,r_max;
    if(k1.poluprecnik<k2.poluprecnik) r_min=k1.poluprecnik, r_max=k2.poluprecnik;
    else r_min=k2.poluprecnik, r_max=k1.poluprecnik;
    return (RastojanjeCentara(k1,k2)<r_max+r_min&&RastojanjeCentara(k1,k2)>r_max-r_min);
}
int main ()
{
    int n;
    std::vector<std::shared_ptr<Kugla>> niz ;

    std::cout << "Unesite broj kugla: " ;
    std::cin >> n;

    while (!std::cin||n<=0) {
        std::cout << "Neispravan broj kugli, unesite ponovo!" << std::endl;
        std::cin.clear();
        std::cin.ignore(1000,'\n');
        std::cin >> n;
    }
    niz.resize(n);
    for(int i(0);i<n;i++) {
        double x,y,z,r;
        std::cout << "Unesite centar "<<i+1<<". kugle: ";
         std::cin >> x >> y >> z;
         while (!std::cin) {
             std::cout << "Neispravan centar " << std::endl;
             std::cin.clear();
             std::cin.ignore(1000,'\n');
             std::cout << "Unesite centar "<<i+1<<". kugle: ";
             std::cin >> x>>y>>z;
         }
            std::cout << "Unesite poluprecnik "<<i+1<<". kugle: ";
            std::cin >> r;
            if(!std::cin||r<0) { std::cin.clear(); std::cin.ignore(1000,'\n'); std::cout << "Ilegalan poluprecnik" << std::endl; i--; }
               else  niz[i]=std::make_shared<Kugla>(x,y,z,r);

    }
    std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double dx,dy,dz;
    std::cin >> dx >> dy >> dz;
    while (!std::cin) {
       std::cout << "Neispravni parametri translacije, unesite ponovo!" << std::endl; 
       std::cin.clear();
       std::cin.ignore(1000,'\n');
       std::cin >> dx>>dy>>dz;
    }
    std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: " << std::endl;
    std::transform(niz.begin(),niz.end(),niz.begin(),[dx,dy,dz] (std::shared_ptr<Kugla>p) { p->Transliraj(dx,dy,dz); return p; } );
    std::sort(niz.begin(),niz.end(),[] (std::shared_ptr<Kugla>x,std::shared_ptr<Kugla>y) { return x->DajZapreminu()<y->DajZapreminu(); } );
    std::for_each(niz.begin(),niz.end(),[] (std::shared_ptr<Kugla> p) {std::cout << "{("<<p->DajX()<<","<<p->DajY()<<","<<p->DajZ()<<"),"<<p->DajPoluprecnik()<<"}" << std::endl;} );
    auto it(std::max_element(niz.begin(),niz.end(),[] (std::shared_ptr<Kugla>x,std::shared_ptr<Kugla>y) { return x->DajPovrsinu()<y->DajPovrsinu(); } ) );
    int razmak(std::distance(niz.begin(),it));
    std::cout << "Kugla sa najvecom povrsinom je: ";
    niz[razmak]->Ispisi();
   /* std::for_each(niz.begin(),niz.end(),[niz,parovi] (std::shared_ptr<Kugla>p) { 
        std::for_each(niz.begin(),niz.end(),[p,parovi](std::shared_ptr<Kugla>p1) { 
            if(DaLiSeSijeku(*p,*p1)) {
                
            }
        });
    });  */
    int brojac(0);
    for(int i(0);i<niz.size()-1;i++) {
        for(int k(i+1);k<niz.size();k++) {
            if(DaLiSeSijeku(*niz[i],*niz[k])) {
                brojac++;
                std::cout << "Presjecaju se kugle: ";
                niz[i]->Ispisi(); niz[k]->Ispisi();
            }
        }
    }
    if(brojac==0) std::cout << "Ne postoje kugle koje se presjecaju!" << std::endl;
    return 0;
}
