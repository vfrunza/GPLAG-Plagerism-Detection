/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdexcept>
#include <utility>
#include <new>
#include <memory>
#include <vector>

#define pi 4*atan(1)
#define Epsilon 10e-10

class Kugla {
    double centarx, centary, centarz, poluprecnik;
    public:
       explicit Kugla(double r=0) {
           if(r<0) throw std::domain_error("Ilegalan poluprecnik");
           centarx=0;centary=0;centarz=0;
           poluprecnik=r;
       }
       
       Kugla(double x, double y, double z, double r=0) {
           if(r<0) throw std::domain_error("Ilegalan poluprecnik");
           centarx=x;centary=y;centarz=z;
           poluprecnik=r;
       }
       
       explicit Kugla(const std::tuple<double, double, double> &centar, double r=0) {
           if(r<0) throw std::domain_error("Ilegalan poluprecnik");
           centarx=std::get<0>(centar);
           centary=std::get<1>(centar);
           centarz=std::get<2>(centar);
           poluprecnik=r;
       }
       
       double DajX() const { return centarx; }
       double DajY() const { return centary; }
       double DajZ() const { return centarz; }
       std::tuple<double, double, double> DajCentar() const {
           return std::make_tuple(centarx, centary, centarz);
       }
       
       double DajPoluprecnik() const { return poluprecnik; }
       double DajPovrsinu() const { return 4*poluprecnik*poluprecnik*pi; }
       double DajZapreminu() const { return (4/3.)*poluprecnik*poluprecnik*poluprecnik*pi; }
       
       Kugla &PostaviX(double x) {
           centarx=x;
           return *this;
       }
       
       Kugla &PostaviY(double y) {
           centary=y;
           return *this;
       }
       
       Kugla &PostaviZ(double z) {
           centarz=z;
           return *this;
       }
       
       Kugla &PostaviCentar(double x, double y, double z) {
           centarx=x;
           centary=y;
           centarz=z;
           return *this;
       }
       
       Kugla &PostaviCentar(const std::tuple<double, double, double> &centar) {
           centarx=std::get<0>(centar);
           centary=std::get<1> (centar);
           centarz=std::get<2> (centar);
           return *this;
       }
       
       Kugla &PostaviPoluprecnik(double r) {
           if(r<0) throw std::domain_error("Ilegalan poluprecnik");
           poluprecnik=r;
           return *this;
       }
       
       void Ispisi() const {
           std::cout<<"{"<<"("<<centarx<<","<<centary<<","<<centarz<<"),"<<poluprecnik<<"}";
       }
       
       void Transliraj(double deltax, double deltay, double deltaz) {
           centarx+=deltax;
           centary+=deltay;
           centarz+=deltaz;
       }
       
       friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2) {
           if((fabs(k1.centarx-k2.centarx)<Epsilon*(fabs(k1.centarx)+fabs(k2.centarx))) && (fabs(k1.centary-k2.centary)<Epsilon*(fabs(k1.centary)+fabs(k2.centary))) && (fabs(k1.centarz-k2.centarz)<Epsilon*(fabs(k1.centarz)+fabs(k2.centarz))) && (fabs(k1.poluprecnik-k2.poluprecnik)<Epsilon*(fabs(k1.poluprecnik)+fabs(k2.poluprecnik))))  return true;
           return false;
       }
       
       friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2) {
           if(fabs(k1.poluprecnik-k2.poluprecnik)<Epsilon*(fabs(k1.poluprecnik)+fabs(k2.poluprecnik))) return true;
           return false;
       } 
    
       friend bool DaLiSuKoncentricne( const Kugla &k1, const Kugla &k2) {
           if((fabs(k1.centarx-k2.centarx)<Epsilon*(fabs(k1.centarx)+fabs(k2.centarx))) && (fabs(k1.centary-k2.centary)<Epsilon*(fabs(k1.centary)+fabs(k2.centary))) && (fabs(k1.centarz-k2.centarz)<Epsilon*(fabs(k1.centarz)+fabs(k2.centarz)))) return true;
           return false;
       }
       
       friend bool DaLiSeDodirujuIzvana( const Kugla &k1, const Kugla &k2) {
           if(k1.poluprecnik<Epsilon && k2.poluprecnik<Epsilon) {
                if((fabs(k1.centarx-k2.centarx)<Epsilon*(fabs(k1.centarx)+fabs(k2.centarx))) && (fabs(k1.centary-k2.centary)<Epsilon*(fabs(k1.centary)+fabs(k2.centary))) && (fabs(k1.centarz-k2.centarz)<Epsilon*(fabs(k1.centarz)+fabs(k2.centarz)))) return true;
                return false;
           }
           if(RastojanjeCentara(k1,k2)==k1.poluprecnik+k2.poluprecnik && !DaLiSeDodirujuIznutra(k1,k2)) return true;
           return false;
       }
       
       friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2) {
           if(k1.poluprecnik<Epsilon && k2.poluprecnik<Epsilon) {
                if((fabs(k1.centarx-k2.centarx)<Epsilon*(fabs(k1.centarx)+fabs(k2.centarx))) && (fabs(k1.centary-k2.centary)<Epsilon*(fabs(k1.centary)+fabs(k2.centary))) && (fabs(k1.centarz-k2.centarz)<Epsilon*(fabs(k1.centarz)+fabs(k2.centarz)))) return true;
                return false;
           }
           if(RastojanjeCentara(k1,k2)==k1.poluprecnik-k2.poluprecnik && !DaLiSeDodirujuIzvana(k1,k2)) return true;
           return false;
       }
       
       friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2) {
           if (DaLiSeSijeku(k1,k2)) return true;
           return false;
       }
       
       friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2) {
           return (RastojanjeCentara(k1,k2)<(k1.poluprecnik+k2.poluprecnik) && RastojanjeCentara(k1,k2)>std::abs(k1.poluprecnik-k2.poluprecnik));
       }
       
       bool DaLiSadrzi(const Kugla &k) {
           if((RastojanjeCentara(*this, k)+k.poluprecnik)<=poluprecnik) return true;
           return false;
       }
       
       friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2) {
           return sqrt(pow(k1.centarx-k2.centarx, 2)+ pow(k1.centary-k2.centary, 2)+ pow(k1.centarz-k2.centarz, 2));
       }
};


int main ()
{
    int n;
    std::cout << "Unesite broj kugla: ";
    std::cin>>n;
    while(!std::cin || n<=0) {
        std::cout << "Neispravan broj kugli, unesite ponovo!\n";
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::cin >> n;
    }
    try {
    std::vector<std::shared_ptr<Kugla>> v;
    for(int i=0;i<n;i++) {
        double x,y,z;
        std::cout << "Unesite centar "<<i+1<<". kugle: ";
        std::cin>>x>>y>>z;
        if(!std::cin) {
            std::cout << "Neispravan centar\n";
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            i--;
            continue;
        }
        std::tuple<double, double, double> centar=std::make_tuple(x,y,z);
        double r;
        std::cout << "Unesite poluprecnik "<<i+1<<". kugle: ";
        std::cin >> r;
        if(!(std::cin) || r<0) {
            std::cout << "Ilegalan poluprecnik\n";
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            i--;
            continue;
        }
        std::shared_ptr<Kugla> pok(std::make_shared<Kugla>(centar, r));
        v.push_back(pok);
    }
    double dx, dy,dz;
    std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    std::cin.clear();
    std::cin.ignore(10000,'\n');
    std::cin >> dx>>dy>>dz;
    while(!std::cin) {
        std::cout << "Neispravni parametri translacije, unesite ponovo!" << std::endl;
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::cin >> dx>>dy>>dz;
    }
    std::transform(v.begin(),v.end(), v.begin(), [=] (const std::shared_ptr<Kugla> &poknakuglu) { (*poknakuglu).Transliraj(dx,dy,dz); return poknakuglu; });
    std::sort(v.begin(), v.end(), [] (const std::shared_ptr<Kugla> &x, const std::shared_ptr<Kugla> &y) { 
        if(x->DajPoluprecnik()< y->DajPoluprecnik()) return true;
        else return false;
    });
    std::cout <<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: \n";
    std::for_each(v.begin(), v.end(), [] (const std::shared_ptr<Kugla> &kug) {
        (*kug).Ispisi();
        std::cout<< std::endl;
    });
    std::cout<<"\nKugla sa najvecom povrsinom je: ";
    auto poknamaxele= std::max_element(v.begin(), v.end(), [] (const std::shared_ptr<Kugla> &kugla1, const std::shared_ptr<Kugla> &kugla2) {
        if((*kugla1).DajPoluprecnik()<(*kugla2).DajPoluprecnik()) return true;
        else return false;
    });;
    (*poknamaxele)->Ispisi();
    int brojac=0;
    std::for_each(v.begin(), v.end(), [&] (const std::shared_ptr<Kugla> &k1) {
        std::for_each(v.begin(), v.end(), [&] (const std::shared_ptr<Kugla> &k2) {
            if(DaLiSeSijeku(*k1,*k2) && (&k2>&k1)) {
            std::cout << "\nPresjecaju se kugle: ";
            (*k1).Ispisi();
            std::cout<< std::endl;
            (*k2).Ispisi();
           brojac++;
        }
        });
    });
    if(brojac==0) std::cout << "\nNe postoje kugle koje se presjecaju!" << std::endl;
    }
    
    catch(...) {
        std::cout << "Problemi sa memorijom" << std::endl;
    }
return 0;
}