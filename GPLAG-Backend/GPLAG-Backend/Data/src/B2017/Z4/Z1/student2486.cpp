/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>

const double pi=4*atan(1.);
const double epsilon=pow(10,-10);

class Kugla {
    double x1, y1, z1, p;
    public:
    explicit Kugla (double r=0) {
        if (r<0) throw std::domain_error("Ilegalan poluprecnik");
        p=r; x1=0; y1=0; z1=0;
    }
    Kugla(double x, double y, double z, double r = 0) {
        if (r<0) throw std::domain_error("Ilegalan poluprecnik");
        p=r; x1=x; y1=y; z1=z;
    }
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0) {
        p=r;
        x1=std::get<0>(centar);
        y1=std::get<1>(centar);
        z1=std::get<2>(centar);
    }
    double DajX() const { return x1;}
    double DajY() const { return y1;}
    double DajZ() const { return z1;}
    std::tuple<double, double, double> DajCentar() const {
        auto povratna=std::make_tuple(x1,y1,z1);
        return povratna;
    }
    double DajPoluprecnik() const { return p;}
    double DajPovrsinu() const { return 2*pi*p*p;}
    double DajZapreminu() const { return (4./3)*pi*p*p*p;}
    Kugla &PostaviX(double x) { x1=x; return *this;}
    Kugla &PostaviY(double y) { y1=y; return *this;}
    Kugla &PostaviZ(double z) { z1=z; return *this;}
    Kugla &PostaviCentar(double x, double y, double z) {
        x1=x; y1=y; z1=z;
        return *this;
    }
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar) {
        x1=std::get<0>(centar);
        y1=std::get<1>(centar);
        z1=std::get<2>(centar);
        return *this;
    }
    Kugla &PostaviPoluprecnik(double r) {
        if (r<0) throw std::domain_error("Ilegalan poluprecnik");
        p=r;
        return *this;
    }
    void Ispisi() const {
        std::cout<<"{("<<x1<<","<<y1<<","<<z1<<"),"<<p<<"}";
    }
    void Transliraj(double delta_x, double delta_y, double delta_z) {
        x1+=delta_x; 
        y1+=delta_y;
        z1+=delta_z;
    }
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

double RastojanjeCentara(const Kugla &k1, const Kugla &k2) {
    return sqrt((k1.x1-k2.x1)*(k1.x1-k2.x1)+(k1.y1-k2.y1)*(k1.y1-k2.y1)+(k1.z1-k2.z1)*(k1.z1-k2.z1));
}

bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2) {
        if (fabs(k1.x1-k2.x1)<=epsilon*(fabs(k1.x1)+fabs(k2.x1)) && fabs(k1.y1-k2.y1)<=epsilon*(fabs(k1.y1)+fabs(k2.y1)) && fabs(k1.z1-k2.z1)<=epsilon*(fabs(k1.z1)+fabs(k2.z1)) && fabs(k1.p-k2.p)<=epsilon*(fabs(k1.p)+fabs(k2.p))) return true;
        return false;
}

bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2) {
        if (fabs(k1.p-k2.p)<=epsilon*(fabs(k1.p)+fabs(k2.p))) return true;
        return false;
    }

bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2) {
    if (fabs(k1.x1-k2.x1)<=epsilon*(fabs(k1.x1)+fabs(k2.x1)) && fabs(k1.y1-k2.y1)<=epsilon*(fabs(k1.y1)+fabs(k2.y1)) && fabs(k1.z1-k2.z1)<=epsilon*(fabs(k1.z1)+fabs(k2.z1))) return true;
    return false;
}

bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2) {
    double D(sqrt((k1.x1-k2.x1)*(k1.x1-k2.x1)+(k1.y1-k2.y1)*(k1.y1-k2.y1)+(k1.z1-k2.z1)*(k1.z1-k2.z1)));
    if (fabs(k1.p+k2.p-D)<=epsilon*(fabs(k1.p)+fabs(k2.p)+fabs(D))) return true;
    return false;
}

bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2) {
    double unutrasnji(0);
    if (k1.p-k2.p<0) unutrasnji=k1.p;
    else unutrasnji=k2.p;
    if (fabs(unutrasnji-RastojanjeCentara(k1,k2))<=epsilon*(fabs(unutrasnji)+fabs(RastojanjeCentara(k1,k2)))) return true;
    return false;
}

bool Kugla::DaLiSadrzi(const Kugla &k) const {
    if (fabs(p-k.p)<epsilon*(fabs(k.p)+fabs(p))) return false;
    else if (fabs(p+RastojanjeCentara(*this,k)-k.p)<=epsilon*(fabs(k.p)+fabs(RastojanjeCentara(*this,k))+fabs(p))) return true;
    return false;
}

bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2) {
    if (k1.DaLiSadrzi(k2)==true || k2.DaLiSadrzi(k1)==true) return false;
    auto d=RastojanjeCentara(k1,k2);
    auto d_poluprecnika=k1.p+k2.p;
    if (d<d_poluprecnika) return true;
    return false;
}

bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2) {
    auto d=RastojanjeCentara(k1,k2);
    auto d_poluprecnika=k1.p+k2.p;
    if (d<d_poluprecnika) return true;
    return false;
}

void OcistiSpremnik() {
    std::cin.clear();
    std::cin.ignore(10000, '\n');
}




int main ()
{
    std::cout<<"Unesite broj kugla: ";
    int n;
    std::cin>>n;
    while (n<=0 || !std::cin) {
        std::cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;;
        OcistiSpremnik();
        std::cin>>n;
    }
    std::vector<std::shared_ptr<Kugla>> v(n);
    for (int i=0; i<n; i++) {
        std::cout<<"Unesite centar "<<i+1<<". kugle: ";
        double x(0),y(0),z(0);
        std::cin>>x>>y>>z;
        if(!std::cin) {
            std::cout<<"Neispravan centar"<<std::endl;
            OcistiSpremnik();
            i--;
            continue;
        }
        Kugla k(x,y,z);
        try {
            std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
            double r;
            std::cin>>r;
            if (r<0 || !std::cin) {
                std::cout<<"Ilegalan poluprecnik"<<std::endl;
                OcistiSpremnik();
                i--;
                continue;
            }
            k.PostaviPoluprecnik(r);
            v.at(i)=std::make_shared<Kugla>(k);
        }
        catch (std::domain_error d) {
            std::cout<<d.what();
            i--;
        }
    
    }
    
    std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double X,Y,Z;
    std::cin>>X>>Y>>Z;
    while (!std::cin) {
        std::cout<<"Neispravni parametri translacije, unesite ponovo!"<<std::endl;
        OcistiSpremnik();
        std::cin>>X>>Y>>Z;
    }
    
    std::transform(v.begin(), v.end(), v.begin(), [X,Y,Z] (std::shared_ptr<Kugla> k) {
        k->Transliraj(X,Y,Z);
        return k;
    });
    
    std::sort(v.begin(), v.end(), [](std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2) {
        return k1->DajZapreminu()<k2->DajZapreminu();
    });
    
    std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti:"<<std::endl;;
    
    std::for_each(v.begin(), v.end(), [](std::shared_ptr<Kugla> k) {
        k->Ispisi();
        std::cout<<std::endl;
    });
    
    auto trazeni(std::max_element(v.begin(), v.end(), [](std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2) {
        return k1->DajPovrsinu()<k2->DajPovrsinu();
    }));
    
    std::cout<<"Kugla sa najvecom povrsinom je: ";
    (*trazeni)->Ispisi();
    std::cout<<std::endl;
    
    int brojac(1), ispisi(0);
    
    std::for_each(v.begin(), v.end(), [&brojac, v, &ispisi](std::shared_ptr<Kugla> k1) {
        std::for_each(v.begin()+brojac, v.end(), [k1, &ispisi](std::shared_ptr<Kugla> k2) {
            if (DaLiSeSijeku(*k1,*k2)==true) {
                std::cout<<"Presjecaju se kugle: ";
                k1->Ispisi(); std::cout<<std::endl;
                k2->Ispisi(); std::cout<<std::endl;
                ispisi++;
            }
        });
        brojac++;
    });
    
    if (ispisi==0) std::cout<<"Ne postoje kugle koje se presjecaju!";
    
    
	return 0;
}










