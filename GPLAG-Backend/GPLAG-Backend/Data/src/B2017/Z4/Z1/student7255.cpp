/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <utility>
#include <tuple>
#include <algorithm>
#include <vector>
#include <memory>

class Kugla {
    double x, y, z, r;
    static constexpr double PI=4*std::atan(1);
    public:
    explicit Kugla(double r=0) { 
        if(r<0) throw std::domain_error ("Ilegalan poluprecnik");
        Kugla::r=r;
        }
    Kugla(double x, double y, double z, double r=0) {
        if(r<0) throw std::domain_error ("Ilegalan poluprecnik");
        Kugla::x=x; Kugla::y=y; Kugla::z=z; Kugla::r=r;
    }
    explicit Kugla(const std::tuple<double, double, double> &centar, double r=0) {
        if(r<0) throw std::domain_error ("Ilegalan poluprecnik");
        Kugla::r=r;
        Kugla::x=std::get<0>(centar);
        Kugla::y=std::get<1>(centar);
        Kugla::z=std::get<2>(centar);
    }
    double DajX() const { return x; }
    double DajY() const { return y; }
    double DajZ() const { return z; }
    std::tuple<double,double,double> DajCentar() const {
        auto t(std::make_tuple(x,y,z));
        return t;
    }
    double DajPoluprecnik() const { return r; }
    double DajPovrsinu() const { return 4*r*r*PI; }
    double DajZapreminu() const { return (4*r*r*r*PI)/3; }
    Kugla &PostaviX(double x) { Kugla::x=x; return *this; }
    Kugla &PostaviY(double y) { Kugla::y=y; return *this; }
    Kugla &PostaviZ(double z) { Kugla::z=z; return *this; }
    Kugla &PostaviCentar(double x, double y, double z) {
        Kugla::x=x; Kugla::y=y; Kugla::z=z;
         return *this;
    }
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar) {
        x=std::get<0>(centar);
        y=std::get<1>(centar);
        z=std::get<2>(centar);
        return *this;
    }
    Kugla &PostaviPoluprecnik(double r) {
        if(r<0) throw std::domain_error ("Ilegalan poluprecnik");
        Kugla::r=r;
        return *this;
    }
    void Ispisi() const {
        std::cout<<"{("<<DajX()<<","<<DajY()<<","<<DajZ()<<"),"<<DajPoluprecnik()<<"}\n";
    }
    void Transliraj(double delta_x, double delta_y, double delta_z) {
        x+=delta_x; y+=delta_y; z+=delta_z;
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

bool Jednako(double x, double y) {
    return fabs(x-y)<10e-10;
}
bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2) {
    return Jednako(k1.x,k2.x) && Jednako(k1.y,k2.y) && Jednako(k1.z,k2.z) && 
           Jednako(k1.r,k2.r);
}
bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2) {
    return Jednako(k1.r,k2.r);
}
bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2) {
    return Jednako(k1.x,k2.x) && Jednako(k1.y,k2.y) && Jednako(k1.z,k2.z);
}
bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2) {
    return Jednako(RastojanjeCentara(k1,k2),(k1.DajPoluprecnik()+k2.DajPoluprecnik()));
}
bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2) {
    return Jednako(RastojanjeCentara(k1,k2),fabs(k2.DajPoluprecnik()-k1.DajPoluprecnik()));
}
bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2) {
    
}

double RastojanjeCentara(const Kugla &k1, const Kugla &k2) {
    return std::sqrt( (k2.x-k1.x)*(k2.x-k1.x)+(k2.y-k1.y)*(k2.y-k1.y)+(k2.z-k1.z)*(k2.z-k1.z) );
}

int main ()
{

    std::cout<<"Unesite broj kugla: ";
    int br_kugla;
    std::cin>>br_kugla;
    std::vector<std::shared_ptr<Kugla>> v(br_kugla);
    for(int i=0; i<br_kugla; i++) {
        std::cout<<"Unesite centar "<<i+1<<". kugle: ";
        double x,y,z;
        if(!(std::cin>>x>>y>>z)) {
            std::cout<<"Pogresan unos!";
            i--;
            break;
        }
        std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
        double r;
        if(!(std::cin>>r) || r<0) {
            std::cout<<"Pogresan unos!";
            i--;
            break;
        }
        try {
            v[i]=std::make_shared<Kugla>(x,y,z,r);
        }
        catch(...) {
            std::cout<<"Greska";
        }
    }
    std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double delta_x, delta_y, delta_z;
    std::cin>>delta_x>>delta_y>>delta_z;
    
    std::transform(v.begin(),v.end(), v.begin(), 
        [delta_x,delta_y,delta_z] (std::shared_ptr<Kugla> &t) {
        t->Transliraj(delta_x,delta_y,delta_z);
        return *t;
        } );
    
    
    std::sort(v.begin(),v.end(), [] (std::shared_ptr<Kugla> t1, std::shared_ptr<Kugla> t2) {
            return t1->DajZapreminu()<t2->DajZapreminu();
        } );
    std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: \n";
    std::for_each(v.begin(), v.end(), [] (std::shared_ptr<Kugla> t) { t->Ispisi(); } );
    auto p=std::max_element(v.begin(), v.end(),
        [] (std::shared_ptr<Kugla> t1, std::shared_ptr<Kugla> t2) { 
            return t1->DajPovrsinu()<t2->DajPovrsinu(); } );
    std::cout<<"Kugla sa najvecom povrsinom je: ";
    for(int i=0; i<br_kugla; i++) {
        if(v[i]==*p) v[i]->Ispisi();
    }
    
    std::for_each(v.begin(), v.end(), [] (std::shared_ptr<Kugla> t1, std::shared_ptr<Kugla> t2) {
                   
                } );
    
   
	return 0;
}
