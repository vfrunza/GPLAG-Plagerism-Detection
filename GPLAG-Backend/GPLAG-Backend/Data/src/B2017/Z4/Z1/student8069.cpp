/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <tuple>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>

const double pi(4*atan(1));
const double eps(1e-10);

class Kugla {
    double x,y,z,r;
    public:
    explicit Kugla(double r = 0) {
      x=0; y=0; z=0;
      r=0;
    }
    
    Kugla(double x, double y, double z, double r = 0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik\n");
        Kugla::x=x; Kugla::y=y; Kugla::z=z;
        Kugla::r=r;
    }
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik\n");
        double a,b,c;
        std::tie(a,b,c)=centar;
        x=a; y=b; z=c; 
        Kugla::r=r;
    }    
    double DajX() const;
    double DajY() const;
    double DajZ() const;
    std::tuple<double, double, double> DajCentar() const;
    double DajPoluprecnik() const;
    double DajPovrsinu() const;
    double DajZapreminu() const;
    Kugla &PostaviX(double x);
    Kugla &PostaviY(double y);
    Kugla &PostaviZ(double z);
    Kugla &PostaviCentar(double x, double y, double z);
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar);
    Kugla &PostaviPoluprecnik(double r);
    void Ispisi() const;
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

double Kugla::DajX() const { return x; }

double Kugla::DajY() const { return y; }

double Kugla::DajZ() const { return z; }

std::tuple<double, double, double> Kugla::DajCentar() const {
    return std::make_tuple(x,y,z);
}

double Kugla::DajPoluprecnik() const { return r; }

double Kugla::DajPovrsinu() const { return 4*pi*r*r; }

double Kugla::DajZapreminu() const {
    return (4/3.*std::pow(r,3)*pi);
}

Kugla &Kugla::PostaviX(double x) {
    Kugla::x=x;
    return *this;
}

Kugla &Kugla::PostaviY(double y) {
    Kugla::y=y;
    return *this;
}

Kugla &Kugla::PostaviZ(double z) {
    Kugla::z=z;
    return *this;
}

Kugla &Kugla::PostaviCentar(double x, double y, double z) {
    Kugla::x=x; Kugla::y=y; Kugla::z=z;
    return *this;
}

Kugla &Kugla::PostaviCentar(const std::tuple<double, double, double> &centar) {
    double a,b,c;
    std::tie(a,b,c)=centar;
    PostaviCentar(a,b,c);
    return *this;
}

Kugla &Kugla::PostaviPoluprecnik(double r) {
    if(r<0) throw std::domain_error("Ilegalan poluprecnik\n");
    Kugla::r=r;
    return *this;
}

void Kugla::Ispisi() const {
    std::cout<<"{("<<DajX()<<","<<DajY()<<","<<DajZ()<<"),"<<DajPoluprecnik()<<"}"<<std::endl;
}

void Kugla::Transliraj(double delta_x, double delta_y, double delta_z) {
    x+=delta_x; y+=delta_y; z+=delta_z;
}

bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2) {
    if(fabs(k1.x-k2.x)<=(eps*(fabs(k1.x)+fabs(k2.x))) || fabs(k1.y-k2.y)<(eps*(fabs(k1.y)+fabs(k2.y))) || fabs(k1.z-k2.z)<(eps*(fabs(k1.z)+fabs(k2.z))) || fabs(k1.r-k2.r)<(eps*(fabs(k1.r)+fabs(k2.r)))) return 1;
    return 0;
}

bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2) {
    if(fabs(k1.r-k2.r)<=(eps*(fabs(k1.r)+fabs(k2.r)))) return 1;
    return 0;
}

bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2) {
    if(fabs(k1.x-k2.x)<=(eps*(fabs(k1.x)+fabs(k2.x))) || fabs(k1.y-k2.y)<(eps*(fabs(k1.y)+fabs(k2.y))) || fabs(k1.z-k2.z)<(eps*(fabs(k1.z)+fabs(k2.z)))) return 1;
    return 0;
}

bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2) {
    double zbir_r(k1.r+k2.r);
    double udaljenost_c(RastojanjeCentara(k1,k2));
    if(fabs(zbir_r-udaljenost_c)<=(eps*(fabs(zbir_r)+fabs(udaljenost_c)))) return 1;
    return 0;
}

bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2) {
    double veci_poluprecnik, manji_poluprecnik;
    if(k1.r>k2.r) {
        veci_poluprecnik=k1.r; manji_poluprecnik=k2.r;
    }
    else {
        veci_poluprecnik=k2.r; manji_poluprecnik=k1.r;
    }
    double udaljenost_c(RastojanjeCentara(k1,k2));
    if(fabs(udaljenost_c+manji_poluprecnik-veci_poluprecnik)<=eps*(fabs(udaljenost_c+manji_poluprecnik)+fabs(veci_poluprecnik))) return 1;
    return 0;
}

bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2) {
    double veci_poluprecnik, manji_poluprecnik;
    if(k1.r>k2.r) {
        veci_poluprecnik=k1.r; manji_poluprecnik=k2.r;
    }
    else {
        veci_poluprecnik=k2.r; manji_poluprecnik=k1.r;
    }
    double udaljenost_c(RastojanjeCentara(k1,k2));
    if((udaljenost_c+manji_poluprecnik)<veci_poluprecnik) return 1;
    return 0;
}

bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2) {
    double zbir_r(k1.r+k2.r);
    double udaljenost_c(RastojanjeCentara(k1,k2));
    if((udaljenost_c<zbir_r || udaljenost_c>fabs(k1.r-k2.r)) && k1.r<udaljenost_c+k2.r && k2.r<udaljenost_c+k1.r ) return 1;
    return 0;
}

bool Kugla::DaLiSadrzi(const Kugla &k) const {
    if(k.r>this->r) return 0;
    return DaLiSePreklapaju(*this, k);
}


double RastojanjeCentara(const Kugla &k1, const Kugla &k2) {
    return std::sqrt(std::pow(k1.x-k2.x,2)+std::pow(k1.y-k2.y,2)+std::pow(k1.z-k2.z,2));
}


int main() {
    std::cout<<"Unesite broj kugla: ";
    int n;
    std::cin>>n;
    while(n<=0 || !std::cin || int(n)!=n) {
        std::cout<<"Neispravan broj kugli, unesite ponovo!\n";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cin>>n;
    }
    std::vector<std::shared_ptr<Kugla>> kugle;
   double unos[4];
    for(int i=0; i<n; i++) {
        greska:
        std::cout<<"Unesite centar "<<i+1<<". kugle: ";
            for(int j=0; j<3; j++) {
                std::cin>>unos[j];
                if(!std::cin) {
                    std::cout<<"Neispravan centar\n";
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    goto greska;
                }
                }
       
        std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
        std::cin>>unos[3];
        while(!std::cin || unos[3]<0) {
            std::cout << "Ilegalan poluprecnik" << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            goto greska;
        }
        
    try {
        auto pok(std::make_shared<Kugla>(unos[0], unos[1], unos[2], unos[3]));
        kugle.push_back(pok);
    }
    catch(std::domain_error izuzetak) {
        std::cout<<izuzetak.what();
        //i--;
    }
    catch(std::bad_alloc ) {
        std::cout<<"Nedovoljno memorije";
    }
    }
    std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    greska2:
    double delta_x, delta_y, delta_z;
    std::cin>>delta_x;
    if(!std::cin){
            std::cout << "Neispravni parametri translacije, unesite ponovo!" << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            goto greska2;
    }
    std::cin>>delta_y; 
    if(!std::cin) {
            std::cout << "Neispravni parametri translacije, unesite ponovo!" << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            goto greska2;
    }
    std::cin>>delta_z;
    if(!std::cin) {
            std::cout << "Neispravni parametri translacije, unesite ponovo!" << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            goto greska2;
    }
    
    std::transform(kugle.begin(), kugle.end(), kugle.begin(), [delta_x, delta_y, delta_z] (std::shared_ptr<Kugla> k) {
        k->Transliraj(delta_x, delta_y, delta_z);
        return k;
    });
    
    std::sort(kugle.begin(), kugle.end(), [] (std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2) {
        return k1->DajZapreminu()<k2->DajZapreminu();
    });
    
    std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<std::endl;
    std::for_each(kugle.begin(), kugle.end(), [] (std::shared_ptr<Kugla> k) {
        k->Ispisi();
    });
    
    auto max(*std::max_element(kugle.begin(), kugle.end(), [] (std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2) {
        return (k1->DajPovrsinu()<k2->DajPovrsinu());
    }));
    std::cout<<"Kugla sa najvecom povrsinom je: ";
    max->Ispisi();
    bool pronadjeno(false);
   std::for_each(kugle.begin(), kugle.end(), [&] (const std::shared_ptr<Kugla> &k1 ) {
        std::for_each(kugle.begin(), kugle.end(), [&k1, &pronadjeno](const std::shared_ptr<Kugla> &k2) {
            if(&k2>&k1) {
              //  k1->Ispisi();
            if(DaLiSeSijeku(*k1, *k2))  {
                pronadjeno=true;
                std::cout<<"Presjecaju se kugle: ";
                k1->Ispisi(); k2->Ispisi();
                std::cout<<std::endl;
                }
            }    
        });
    });
    if(!pronadjeno) std::cout<<"Ne postoje kugle koje se presjecaju!";
    return 0;
}

