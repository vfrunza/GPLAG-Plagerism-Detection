/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <cmath> 
#include <vector>
#include <memory>
#include <algorithm>

class Kugla {
  double x, y, z, r;
  static constexpr double e=0.0000000001;
public:
    explicit Kugla(double r=0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        x=0; y=0; z=0; Kugla::r=r;
    }
    Kugla(double x, double y, double z, double r=0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::x=x; Kugla::y=y; Kugla::z=z; Kugla::r=r;
    }
    explicit Kugla(const std::tuple<double, double, double> &centar, double r=0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        x=std::get<0>(centar); y=std::get<1>(centar); z=std::get<2>(centar); Kugla::r=r; 
    }
    double DajX() const { return x; }
    double DajY() const { return y; }
    double DajZ() const { return z; }
    std::tuple<double, double, double> DajCentar() const { return std::tie(x,y,z); }
    double DajPoluprecnik() const { return r; }
    double DajPovrsinu() const { return 4*r*r*4*atan(1); }
    double DajZapreminu() const { return (4*r*r*r*4*atan(1))/3; }
    Kugla &PostaviX(double x) { Kugla::x=x; return *this; }
    Kugla &PostaviY(double y) { Kugla::y=y; return *this; }
    Kugla &PostaviZ(double z) { Kugla::z=z; return *this; }
    Kugla &PostaviCentar(double x, double y, double z) { Kugla::x=x; Kugla::y=y; Kugla::y=y; return *this; }
    Kugla &PostaviPoluprecnik(double r) { 
        if(r<0) throw std::domain_error("Ilegalan poluprecnik"); 
        Kugla::r=r; return *this; 
    }
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar) { Kugla::x=std::get<0>(centar); Kugla::y=std::get<1>(centar); Kugla::z=std::get<2>(centar); return *this; }
    void Ispisi() const { std::cout<<"{("<<DajX()<<","<<DajY()<<","<<DajZ()<<"),"<<DajPoluprecnik()<<"}"<<std::endl; }
    void Transliraj(double delta_x, double delta_y, double delta_z) { PostaviX(DajX()+delta_x); PostaviY(DajY()+delta_y); PostaviZ(DajZ()+delta_z); }
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

bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2) {
    return(std::fabs(k1.DajX()-k2.DajX())<Kugla::e && std::fabs(k1.DajY()-k2.DajY())<Kugla::e && std::fabs(k1.DajZ()-k2.DajZ())<Kugla::e && std::fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik())<Kugla::e);
}

bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2) {
    return std::fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik())<Kugla::e*(std::fabs(k1.DajPoluprecnik())+std::fabs(k2.DajPoluprecnik()));
}

bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2) {
    return(std::fabs(k1.DajX()-k2.DajX())<Kugla::e && std::fabs(k1.DajY()-k2.DajY())<Kugla::e && std::fabs(k1.DajZ()-k2.DajZ())<Kugla::e);
}

bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2) {
    if((RastojanjeCentara(k1, k2)+k1.DajPoluprecnik())<k2.DajPoluprecnik()) return true;
    else if((RastojanjeCentara(k1, k2)+k2.DajPoluprecnik())<k1.DajPoluprecnik()) return true;
    return false;
}

bool Kugla::DaLiSadrzi(const Kugla &k2) const {
    if((RastojanjeCentara(*this, k2)+k2.DajPoluprecnik())<=DajPoluprecnik()) return true;
    return false;
}

bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2) {
    if(std::fabs((k1.DajPoluprecnik()-(RastojanjeCentara(k1, k2)+k2.DajPoluprecnik())))<=Kugla::e*(std::fabs(k1.DajPoluprecnik())+std::fabs(RastojanjeCentara(k1, k2)+k2.DajPoluprecnik())) && k1.DaLiSadrzi(k2)) return true;
    if(std::fabs((k2.DajPoluprecnik()-(RastojanjeCentara(k1, k2)+k1.DajPoluprecnik())))<=Kugla::e*(std::fabs(k2.DajPoluprecnik())+std::fabs(RastojanjeCentara(k1, k2)+k1.DajPoluprecnik())) && k2.DaLiSadrzi(k1)) return true;
    return false;
}

bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2) {
    if (std::fabs((k1.DajPoluprecnik()+k2.DajPoluprecnik())-RastojanjeCentara(k1, k2))<=Kugla::e*(std::fabs(k1.DajPoluprecnik()+k2.DajPoluprecnik())+std::fabs(RastojanjeCentara(k1, k2))) && !DaLiSePreklapaju(k1, k2)) return true;
    return false;
}

bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2) {
    return (RastojanjeCentara(k1, k2)<(k1.DajPoluprecnik()+k2.DajPoluprecnik()) && !k1.DaLiSadrzi(k2) && !k2.DaLiSadrzi(k1));
}

double RastojanjeCentara(const Kugla &k1, const Kugla &k2) {
    return std::sqrt((k1.DajX()-k2.DajX())*(k1.DajX()-k2.DajX())+(k1.DajY()-k2.DajY())*(k1.DajY()-k2.DajY())+(k1.DajZ()-k2.DajZ())*(k1.DajZ()-k2.DajZ()));
}

int main ()
{
    int n;
    std::cout<<"Unesite broj kugla: ";
    std::cin>>n;
    while(!std::cin || n<=0) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;
        std::cin>>n;
    }
    std::vector<std::shared_ptr<Kugla>> v(n);
    double a, b, c, R;
    for(int i=0; i<n; i++) {
        std::cout<<"Unesite centar "<<i+1<<". kugle: ";
        std::cin>>a>>b>>c;
        if(!std::cin) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout<<"Neispravan centar"<<std::endl;
            i--;
            continue;
        }
        std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
        std::cin>>R;
        if(!std::cin) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout<<"Ilegalan poluprecnik"<<std::endl;
            i--;
            continue;
        }
        try {
            auto pom(std::make_shared<Kugla>(a,b,c,R));
            v[i]=pom;
        }
        catch(std::domain_error izz) {
            std::cout<<izz.what()<<std::endl;
            i--;
        }
    }
    std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double dx, dy, dz;
    std::cin>>dx>>dy>>dz;
    while(!std::cin) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout<<"Neispravni parametri translacije, unesite ponovo!"<<std::endl;
            std::cin>>dx>>dy>>dz;
        }
    std::transform(v.begin(), v.end(), v.begin(), [dx, dy, dz](std::shared_ptr<Kugla> pok) { pok->Transliraj(dx, dy, dz); return pok; });
    std::sort(v.begin(), v.end(), [](std::shared_ptr<Kugla> pok1, std::shared_ptr<Kugla> pok2) { return pok1->DajZapreminu()<pok2->DajZapreminu(); });
    std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<std::endl;
    std::for_each(v.begin(), v.end(), [](std::shared_ptr<Kugla> pok) { pok->Ispisi(); });
    auto najj(std::max_element(v.begin(), v.end(), [](std::shared_ptr<Kugla> pok1, std::shared_ptr<Kugla> pok2) { return pok1->DajPovrsinu()<pok2->DajPovrsinu(); }));
    if(najj==v.end()) std::cout<<"Ne postoji kugla s najvecom povrsinom!"<<std::endl;
    else {
        std::cout<<"Kugla sa najvecom povrsinom je: "; 
        (*najj)->Ispisi(); 
    }
    bool t(false);
    std::for_each(v.begin(), v.end(), [v, n, &t](std::shared_ptr<Kugla> k1) {
        auto it(std::find(v.begin(), v.end(), k1));
        it++;
        std::for_each(it, v.end(), [k1, &t](std::shared_ptr<Kugla> k2) {
            if(DaLiSeSijeku(*k1, *k2)) {
                std::cout<<"Presjecaju se kugle: ";
                k1->Ispisi(); k2->Ispisi();
                t=true;
            }
        });
    });
    if(!t) std::cout<<"Ne postoje kugle koje se presjecaju!"<<std::endl;
	return 0;
}