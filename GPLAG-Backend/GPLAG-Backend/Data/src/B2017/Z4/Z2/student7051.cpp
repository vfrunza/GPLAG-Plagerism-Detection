/B2017/2018: Zadaća 4, Zadatak 2
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <cmath>
#include <new>
#include <vector>
#include <memory>
#include <algorithm>
#include <utility>
const double e = 0.0000000001;
class NepreklapajucaKugla
{
    static NepreklapajucaKugla *posljednja;
    NepreklapajucaKugla *prethodna;
    double x, y, z, r;
    
    bool DaLiSeSijeku(double x, double y, double z, double r, NepreklapajucaKugla k){
        double d (sqrt(pow(x-k.x,2)+pow(y-k.y,2)+pow(z-k.z,2)));
        return (d<k.r+r&&d>fabs(k.r-r));
    }
public:
    explicit NepreklapajucaKugla(double r = 0);
    NepreklapajucaKugla(double x, double y, double z, double r = 0);
    explicit NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r = 0);
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
        return std::make_tuple (x,y,z);
    }
    double DajPoluprecnik() const {
        return r;
    };
    double DajPovrsinu() const {
        return r*r*atan(1)*4;
    }
    double DajZapreminu() const {
        return ((4.0/3.0)*r*r*r*atan(1)*4);
    }
    NepreklapajucaKugla &PostaviX(double x) {
        NepreklapajucaKugla::x=x;
        return *this;
    }
    NepreklapajucaKugla &PostaviY(double y) {
        NepreklapajucaKugla::y=y;
        return *this;
    }
    NepreklapajucaKugla &PostaviZ(double z) {
        NepreklapajucaKugla::z=z;
        return *this;
    }
    NepreklapajucaKugla &PostaviCentar(double x, double y, double z) {
        NepreklapajucaKugla::x=x;
        NepreklapajucaKugla::y=y;
        NepreklapajucaKugla::z=z;
        return *this;
    }
    NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar);
    NepreklapajucaKugla &PostaviPoluprecnik(double r);
    void Ispisi() const {
        std::cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}";
    } 
    void Transliraj(double delta_x, double delta_y, double delta_z);
    friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
    ~NepreklapajucaKugla(){
        /*NepreklapajucaKugla* pom(posljednja);
        if (pom==this) posljednja=pom->prethodna;
        else {
            while (pom->prethodna!=this) pom=pom->prethodna;
            pom->prethodna=pom->prethodna->prethodna;
        }*/
    }
};

NepreklapajucaKugla* NepreklapajucaKugla::posljednja=nullptr;

NepreklapajucaKugla::NepreklapajucaKugla(double r)
{
    prethodna=posljednja;
    
    NepreklapajucaKugla* drugaKugla=prethodna;
    while(drugaKugla!=nullptr){
        if(DaLiSeSijeku(x,y,z,r,*drugaKugla))
            throw std::logic_error("Nedozvoljeno preklapanje");
        drugaKugla=drugaKugla->prethodna;
    }
    
    if (r>=0) {
        x=0;
        y=0;
        z=0;
        NepreklapajucaKugla::r=r;
    } else {
        throw std::domain_error ("Ilegalan poluprecnik");
    }
    posljednja=this;
}
NepreklapajucaKugla::NepreklapajucaKugla(double x, double y, double z, double r)
{
    prethodna=posljednja;
    
    NepreklapajucaKugla *drugaKugla=prethodna;
    while(drugaKugla!=nullptr){
        if(DaLiSeSijeku(x,y,z,r,*drugaKugla))
            throw std::logic_error("Nedozvoljeno preklapanje");
        drugaKugla=drugaKugla->prethodna;
    }
    
    if (r>=0) {
        NepreklapajucaKugla::x=x;
        NepreklapajucaKugla::y=y;
        NepreklapajucaKugla::z=z;
        NepreklapajucaKugla::r=r;
    } else {
        throw std::domain_error ("Ilegalan poluprecnik");
    }
    
    posljednja=this;
}
NepreklapajucaKugla::NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r)
{
    prethodna=posljednja;
    
    NepreklapajucaKugla *drugaKugla=prethodna;
    while(drugaKugla!=nullptr){
        if(DaLiSeSijeku(x,y,z,r,*drugaKugla))
            throw std::logic_error("Nedozvoljeno preklapanje");
        drugaKugla=drugaKugla->prethodna;
    }
    
    x=std::get<0>(centar);
    y=std::get<1>(centar);
    z=std::get<2>(centar);
    NepreklapajucaKugla::r=r;
    
    posljednja=this;
}
NepreklapajucaKugla &NepreklapajucaKugla::PostaviCentar(const std::tuple<double, double, double> &centar)
{
    x=std::get<0>(centar);
    y=std::get<1>(centar);
    z=std::get<2>(centar);
    return *this;
}
NepreklapajucaKugla &NepreklapajucaKugla::PostaviPoluprecnik(double r)
{
    if (r>=0) NepreklapajucaKugla::r=r;
    else throw std::domain_error ("Ilegalan poluprecnik");
    return *this;
}
void NepreklapajucaKugla::Transliraj(double delta_x, double delta_y, double delta_z)
{
    x+=delta_x;
    y+=delta_y;
    z+=delta_z;
}
double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2)
{
    double d (sqrt(pow(k2.x-k1.x,2)+pow(k2.y-k1.y,2)+pow(k2.z-k1.z,2)));
    return d;
}
int main ()
{
    try {
        int n;
        std::cout<<"Unesite broj kugli: ";
        do {
            std::cin>>n;
            if (n<=0 || !std::cin) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;
            }
        } while (n<=0 || !std::cin);
        std::vector<std::shared_ptr<NepreklapajucaKugla>> pok (n,nullptr);
        for (int i=0; i<n; i++) {
            double x,y,z,r;
            bool greska (false);
            do {
                greska=false;
                std::cout<<"Unesite centar za "<<i+1<<". kuglu: ";
                std::cin>>x>>y>>z;
                if (!std::cin) {
                    greska=true;
                    std::cin.clear();
                    std::cin.ignore(1000,'\n');
                    std::cout<<"Neispravan centar"<<std::endl;
                    continue;
                }
                greska=false;
                std::cout<<"Unesite poluprecnik: ";
                std::cin>>r;
                if (!std::cin || r<0) {
                    greska=true;
                    std::cin.clear();
                    std::cin.ignore(1000,'\n');
                    std::cout<<"Ilegalan poluprecnik"<<std::endl;
                    continue;
                }
            } while (greska);
            try{
                pok[i]=std::make_shared<NepreklapajucaKugla>(x,y,z,r);
            } catch(std::logic_error e){
                std::cout<<e.what()<<std::endl;
                i--;
            }
        }
        std::sort(pok.begin(), pok.end(), [] (std::shared_ptr<NepreklapajucaKugla> k1, std::shared_ptr<NepreklapajucaKugla> k2){
            return k1->DajPovrsinu()<k2->DajPovrsinu();
        });
        std::cout<<std::endl<<"Kugle nakon obavljenog sortiranja: "<<std::endl;
        std::for_each(pok.begin(), pok.end(), [] (std::shared_ptr<NepreklapajucaKugla> kugla){
            kugla->Ispisi();
            std::cout<<std::endl;
        });
        
    } catch(std::domain_error e) {
        std::cout<<e.what();
    } catch(std::logic_error e){
        std::cout<<e.what();
    }

    return 0;
}
