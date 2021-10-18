/B2017/2018: Zadaća 4, Zadatak 2
/B2017/2018: Zadaća 4, Zadatak 1
#include<iostream>
#include<stdexcept>
#include<tuple>
#include<cmath>
#include<vector>
#include<algorithm>
#include<memory>
#include<iterator>
class NepreklapajucaKugla {
    double x,y,z;
    double r;
    NepreklapajucaKugla *prethodni;
    static NepreklapajucaKugla *poc;
    bool PreklapajuSe(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
    public:
    explicit NepreklapajucaKugla(double r=0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        NepreklapajucaKugla::r=r;
    }
    NepreklapajucaKugla(double x, double y, double z, double r=0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        NepreklapajucaKugla::x=x;
        NepreklapajucaKugla::y=y;
        NepreklapajucaKugla::z=z;
        NepreklapajucaKugla::r=r;
    }
    explicit NepreklapajucaKugla(const std::tuple<double,double,double> &centar, double r=0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        x=std::get<0>(centar);
        y=std::get<1>(centar);
        z=std::get<2>(centar);
        NepreklapajucaKugla::r=r;
    }
    double DajX() const { return x; }
    double DajY() const { return y; }
    double DajZ() const { return z; }
    std::tuple<double,double,double> DajCentar() const { return std::make_tuple(x,y,z); }
    double DajPoluprecnik() const { return r; }
    double DajPovrsinu() const { return 16*r*r*atan(1); }
    double DajZapreminu() const { return (16*r*r*r*atan(1))/3; }
    NepreklapajucaKugla &PostaviX(double x) { NepreklapajucaKugla::x=x; return *this; }
    NepreklapajucaKugla &PostaviY(double y) { NepreklapajucaKugla::y=y; return *this; }
    NepreklapajucaKugla &PostaviZ(double z) { NepreklapajucaKugla::z=z; return *this; }
    NepreklapajucaKugla &PostaviCentar(double x, double y, double z);
    NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar);
    NepreklapajucaKugla &PostaviPoluprecnik(double r);
    void Ispisi() const { std::cout<<"{("<<DajX()<<","<<DajY()<<","<<DajZ()<<"),"<<DajPoluprecnik()<<"}"<<std::endl; }
    void Transliraj(double delta_x, double delta_y, double delta_z) { x+=delta_x; y+=delta_y; z+=delta_z; }
    //friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
    //friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
    //friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
    //friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
    //friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
    //friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
    //friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
    //bool DaLiSadrzi(const NepreklapajucaKugla &k) const;
    friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
};
NepreklapajucaKugla *NepreklapajucaKugla::poc=nullptr;
bool NepreklapajucaKugla::PreklapajuSe(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2) {
    if(RastojanjeCentara(k1,k2)<(k1.DajPoluprecnik()+k2.DajPoluprecnik()) && RastojanjeCentara(k1,k2)>std::fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik())) return true;
    return false;
}
NepreklapajucaKugla &NepreklapajucaKugla::PostaviCentar(double x, double y, double z) {
    (*this).PostaviX(x).PostaviY(y).PostaviZ(z);
    return *this;
}
NepreklapajucaKugla &NepreklapajucaKugla::PostaviCentar(const std::tuple<double,double,double> &centar) {
    (*this).PostaviX(std::get<0>(centar)).PostaviY(std::get<1>(centar)).PostaviZ(std::get<2>(centar));
    return *this;
}
NepreklapajucaKugla &NepreklapajucaKugla::PostaviPoluprecnik(double r) {
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    NepreklapajucaKugla::r=r;
    return *this;
}
double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2) {
    return std::sqrt((k2.DajX()-k1.DajX())*(k2.DajX()-k1.DajX())+(k2.DajY()-k1.DajY())*(k2.DajY()-k1.DajY())+(k2.DajZ()-k1.DajZ())*(k2.DajZ()-k1.DajZ()));
}
int main () {
    int broj;
    std::cout<<"Unesite broj kugli: ";
    for(;;) {
        std::cin>>broj;
        if(!std::cin || broj<=0) {
            std::cout<<"Neispravan broj kugli, unesite ponovo: "<<std::endl;
            std::cin.clear();
            std::cin.ignore(1000,'\n');
        }
        else break;
    }
    std::vector<std::shared_ptr<NepreklapajucaKugla>> v(broj);
    for(int i=0; i<broj; i++) {
        double x,y,z;
        std::cout<<"Unesite centar za "<<i+1<<". kugle: ";
        for(;;) {
            std::cin>>x>>y>>z;
            if(!std::cin) {
                std::cout<<"Neispravan centar, unesite ponovo: "<<std::endl;
                std::cin.clear();
                std::cin.ignore(1000,'\n');
            } else break;
        }
        std::cout<<"Unesite poluprecnik: ";
        double r;
        for(;;) {
            std::cin>>r;
            if(!std::cin || r<0) {
                std::cout<<"Neispravan poluprecnik, unesite ponovo: "<<std::endl;
                std::cin.clear();
                std::cin.ignore(1000,'\n');
            } else break;
        }
        try {
            v[i]=std::make_shared<NepreklapajucaKugla>(NepreklapajucaKugla(x,y,z,r));
        } catch(std::domain_error izuz) {
            std::cout<<izuz.what()<<std::endl;
            i--;
        } catch (std::logic_error izuz) {
            std::cout<<izuz.what()<<std::endl;
            i--;
        }
    }
    std::sort(v.begin(),v.end(),[](std::shared_ptr<const NepreklapajucaKugla> k1, std::shared_ptr< const NepreklapajucaKugla> k2) { return k1->DajPovrsinu()<k2->DajPovrsinu(); });
    std::cout<<std::endl<<"Kugle nakon obavljenog sortiranja: "<<std::endl;
    std::for_each(v.begin(),v.end(), [](std::shared_ptr<NepreklapajucaKugla> k) { k->Ispisi(); });
    return 0;
}