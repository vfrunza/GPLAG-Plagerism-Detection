/B2017/2018: Zadaća 4, Zadatak 2
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <algorithm>
#include <tuple>
#include <vector>
#include <memory>

const double PI(4*atan(1));

bool JesuLiJednaki(double x, double y, double eps=1e-10) {
    if ((x<0 && y>0) || (x>0 && y<0)) return false;
    return std::fabs(x-y) <= eps*(std::fabs(x)+std::fabs(y));
}

class NepreklapajucaKugla {
    double x, y, z, r;
    mutable int brojac_ispisa{0};
    int DajBrojIspisa() const { return brojac_ispisa; }
    void Ispisi1() const { 
        brojac_ispisa++;
        std::cout<<"{("<<DajX()<<","<<DajY()<<","<<DajZ()<<"),"<<r<<"}"; 
    }
    public:
        explicit NepreklapajucaKugla(double r=0) { x=y=z=0; }
        
        NepreklapajucaKugla(double x, double y, double z, double r=0) {
            if (r<0) throw std::domain_error ("Ilegalan poluprecnik");
            NepreklapajucaKugla::x=x; NepreklapajucaKugla::y=y; NepreklapajucaKugla::z=z; NepreklapajucaKugla::r=r;
        }
        explicit NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r=0) {
            x=std::get<0>(centar); y=std::get<1>(centar); z=std::get<2>(centar);
        }
        
        double DajX() const;
        double DajY() const;
        double DajZ() const; 
        std::tuple<double, double, double> DajCentar() const;
        double DajPoluprecnik() const;
        double DajPovrsinu() const;
        double DajZapreminu() const;
        NepreklapajucaKugla &PostaviX (double x);
        NepreklapajucaKugla &PostaviY (double y);
        NepreklapajucaKugla &PostaviZ (double z);
        NepreklapajucaKugla &PostaviCentar(double x, double y, double z);
        NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar);
        NepreklapajucaKugla &PostaviPoluprecnik(double r);
        void Ispisi() const;
        void Transliraj (double delta_x, double delta_y, double delta_z);

        bool DaLiSadrzi (const NepreklapajucaKugla &k) {
            double d(std::sqrt((k.x-x)*(k.x-x) + (k.y-y)*(k.y-y) + (k.z-z)*(k.z-z)));
            if (d<std::fabs(r-k.r)) return true;
            else return false;
        }
        
        friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
}; // KRAJ KLASE

double NepreklapajucaKugla::DajX() const { return x; }
double NepreklapajucaKugla::DajY() const { return y; }
double NepreklapajucaKugla::DajZ() const { return z; }

std::tuple<double, double, double> NepreklapajucaKugla::DajCentar() const {
    std::tuple<double, double, double> pomocna;
    std::get<0>(pomocna)=x; std::get<1>(pomocna)=y; std::get<2>(pomocna)=z;
    return pomocna;
}

double NepreklapajucaKugla::DajPoluprecnik() const { return r; }
double NepreklapajucaKugla::DajPovrsinu() const { return(4*pow(r,2)*PI); }
double NepreklapajucaKugla::DajZapreminu() const { return(4/3.*pow(r,3)*PI); }

NepreklapajucaKugla &NepreklapajucaKugla::PostaviX (double x) { NepreklapajucaKugla::x=x; return *this; }
NepreklapajucaKugla &NepreklapajucaKugla::PostaviY (double y) { NepreklapajucaKugla::y=y; return *this; }
NepreklapajucaKugla &NepreklapajucaKugla::PostaviZ (double z) { NepreklapajucaKugla::z=z; return *this; }

NepreklapajucaKugla &NepreklapajucaKugla::PostaviCentar(double x, double y, double z) {
    NepreklapajucaKugla::x=x; NepreklapajucaKugla::y=y; NepreklapajucaKugla::z=z; 
    return *this; 
}

NepreklapajucaKugla &NepreklapajucaKugla::PostaviCentar(const std::tuple<double, double, double> &centar) {
    NepreklapajucaKugla::x=std::get<0>(centar); NepreklapajucaKugla::y=std::get<1>(centar); NepreklapajucaKugla::z=std::get<2>(centar);
    return *this;
}

NepreklapajucaKugla &NepreklapajucaKugla::PostaviPoluprecnik(double r) { 
    if (r<0) throw std::domain_error ("Ilegalan poluprecnik"); 
    NepreklapajucaKugla::r=r; 
    return *this;
}

void NepreklapajucaKugla::Ispisi() const { std::cout<<"{("<<DajX()<<","<<DajY()<<","<<DajZ()<<"),"<<r<<"}"; }

void NepreklapajucaKugla::Transliraj(double delta_x, double delta_y, double delta_z) { x+=delta_x; y+=delta_y; z+=delta_z; }


double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2) {
    return (std::sqrt((k1.x-k2.x)*(k1.x-k2.x) + (k1.y-k2.y)*(k1.y-k2.y) + (k1.z-k2.z)*(k1.z-k2.z)));
}


int main () {
    int n;
    double pom1, pom2, pom3, pom4;
    double p1, p2, p3;
    NepreklapajucaKugla kugla;
    std::cout<<"Unesite broj kugla: ";
    std::cin>>n;

    std::vector<std::shared_ptr<NepreklapajucaKugla>>vektor_kugli(n);
    
    for (int i=0; i<n; i++) {
        std::cout<<"Unesite centar "<< i+1 <<". kugle: ";
        std::cin>>pom1>>pom2>>pom3;
        kugla.PostaviX(pom1); 
        kugla.PostaviY(pom2);
        kugla.PostaviZ(pom3);
        std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
        std::cin>>pom4;
        try {
            kugla.PostaviPoluprecnik(pom4);
        } catch (std::domain_error izuzetak1) {
            std::cout<<izuzetak1.what();
            std::cout<<std::endl;
            i--;
        }
        try {
            vektor_kugli[i]=std::make_shared<Kugla>(kugla);
        }
        catch (...) {
            std::cout<<"Ponovite unos: "<<std::endl;
            i--;
        }
    }
    std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    std::cin>>p1>>p2>>p3;
    
    std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: ";
    std::cout<<std::endl;
    std::transform(vektor_kugli.begin(), vektor_kugli.end(), vektor_kugli.begin(), [p1,p2,p3](std::shared_ptr<Kugla> &k){
        k->Transliraj(p1,p2,p3);
        return k;
    });
    
    std::sort(vektor_kugli.begin(), vektor_kugli.end(), [](const std::shared_ptr<Kugla> &k1, const std::shared_ptr<Kugla> &k2){
        return k1->DajZapreminu() < k2->DajZapreminu();
    });
    
    std::for_each(vektor_kugli.begin(), vektor_kugli.end(), [](const std::shared_ptr<Kugla> &k){
        k->Ispisi();
        std::cout<<std::endl;
    });
    
    std::cout<<"Kugla sa najvecom povrsinom je: ";
    auto max(*std::max_element(vektor_kugli.begin(), vektor_kugli.end(), [](const std::shared_ptr<Kugla> &k1, const std::shared_ptr<Kugla> &k2){
        return k1->DajPovrsinu() < k2->DajPovrsinu();
    }));
    max->Ispisi();
    std::cout<<std::endl;
    
    std::cout<<"Presjecaju se kugle: ";
    std::for_each(vektor_kugli.begin(), vektor_kugli.end(), [vektor_kugli](const std::shared_ptr<Kugla> &k1){
        std::for_each(vektor_kugli.begin(), vektor_kugli.end(), [k1](const std::shared_ptr<Kugla> &k2){
            if (DaLiSeSijeku(*k1, *k2) && k1!=k2) {
                k1->Ispisi1(); 
                k2->Ispisi1();
                std::cout<<std::endl;
            }
        });
    });
    if (DajBrojIspisa()==0) {
        std::cout<<"Ne postoje kugle koje se presjecaju!";
    }
    
	return 0;
}