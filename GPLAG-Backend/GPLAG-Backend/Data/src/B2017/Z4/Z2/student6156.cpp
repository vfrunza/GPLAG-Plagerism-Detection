/B2017/2018: Zadaća 4, Zadatak 2
#include <iostream>
#include <utility>
#include <tuple>
#include <cmath>
#include <algorithm>
#include <vector>
#include <memory>
#include <stdexcept>
#include <iomanip>


constexpr double eps(1e-10);
constexpr double pi(4*std::atan(1));

bool jednako(double x,double y)
{
    return std::fabs(x-y)<eps*(std::fabs(x)+std::fabs(y));
}
double udaljenost(double a, double b, double c, double x, double y, double z)
{
    return std::sqrt((a-x)*(a-x)+(b-y)*(b-y)+(c-z)*(c-z));
}

class NepreklapajucaKugla
{
    double x,y,z,r;
    NepreklapajucaKugla* prethodna;
    static NepreklapajucaKugla* zadnja;
public:
    explicit NepreklapajucaKugla(double r = 0) {
        if(r<0)throw std::domain_error("Ilegalan poluprecnik");
        prethodna=zadnja;
        for(auto i=zadnja; i; i=i->prethodna) {
            if(!i)break;
            if(i->r + r> udaljenost(0,0,0,i->x,i->y,i->z)|| jednako(i->r + r ,udaljenost(0,0,0,i->x,i->y,i->z)))throw std::logic_error("Nedozvoljeno preklapanje\n");
        }
        zadnja=this;
        x=y=z=0;
        NepreklapajucaKugla::r=r;
    }
    ~NepreklapajucaKugla() {
 
        if(!prethodna)
        {
            zadnja=nullptr;
        }
        else
        {
            auto i=zadnja;
            if(zadnja==this)
            {
                zadnja=prethodna;
                prethodna=prethodna->prethodna;
                
            }else
            for(;;)
            {
                if(!i)break;
                if(i->prethodna==this)break;
                i=i->prethodna;
            }
            
            if(i)i->prethodna=prethodna;
        }
    }
    NepreklapajucaKugla(double x, double y, double z, double r = 0) {
        if(r<0)throw std::domain_error("Ilegalan poluprecnik");
        prethodna=zadnja;
        for(auto i=zadnja; i; i=i->prethodna) {
            if(!i)break;
            if(i->r + r > udaljenost(x,y,z,i->x,i->y,i->z)|| jednako(i->r + r ,udaljenost(x,y,z,i->x,i->y,i->z)))throw std::logic_error("Nedozvoljeno preklapanje\n");
        }
        zadnja=this;
        NepreklapajucaKugla::x=x;
        NepreklapajucaKugla::y=y;
        NepreklapajucaKugla::z=z;
        NepreklapajucaKugla::r=r;
    }
    NepreklapajucaKugla(const NepreklapajucaKugla &x)=delete;
    explicit NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r = 0) {
        prethodna=zadnja;
        for(auto i=zadnja; i; i=i->prethodna) {
            if(!i)break;
            if(i->r + r > udaljenost(std::get<0>(centar),std::get<1>(centar),std::get<2>(centar),i->x,i->y,i->z)
            || jednako(i->r + r ,udaljenost(std::get<0>(centar),std::get<1>(centar),std::get<2>(centar),i->x,i->y,i->z)))throw std::logic_error("Nedozvoljeno preklapanje\n");
        }
        zadnja=this;
        x=std::get<0>(centar);
        y=std::get<1>(centar);
        z=std::get<2>(centar);
        NepreklapajucaKugla::r=r;
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
        return std::tie(x,y,z);
    }
    double DajPoluprecnik() const {
        return r;
    }
    double DajPovrsinu() const {
        return 4*r*r*pi;
    }
    double DajZapreminu() const {
        return 4./3*r*r*r*pi;
    }
    NepreklapajucaKugla &PostaviX(double x) {
        prethodna=zadnja;
        for(auto i=zadnja; i; i=i->prethodna) {
            if(!i)break;
            if(this == i)continue;
            if(i->r + r > udaljenost(x,y,z,i->x,i->y,i->z)|| jednako(i->r + r ,udaljenost(x,y,z,i->x,i->y,i->z)))throw std::logic_error("Nedozvoljeno preklapanje\n");
        }

        NepreklapajucaKugla::x=x;
        return *this;
    }
    NepreklapajucaKugla &PostaviY(double y) {
        prethodna=zadnja;
        for(auto i=zadnja; i; i=i->prethodna) {
            if(!i)break;
            if(this == i)continue;
            if(i->r + r > udaljenost(x,y,z,i->x,i->y,i->z)|| jednako(i->r + r ,udaljenost(x,y,z,i->x,i->y,i->z)))throw std::logic_error("Nedozvoljeno preklapanje\n");
        }
        NepreklapajucaKugla::y=y;
        return *this;
    }
    NepreklapajucaKugla &PostaviZ(double z) {
        prethodna=zadnja;
        for(auto i=zadnja; i; i=i->prethodna) {
            if(!i)break;
            if(this == i)continue;
            if(i->r + r > udaljenost(x,y,z,i->x,i->y,i->z)|| jednako(i->r + r ,udaljenost(x,y,z,i->x,i->y,i->z)))throw std::logic_error("Nedozvoljeno preklapanje\n");
        }
        NepreklapajucaKugla::z=z;
        return *this;
    }
    NepreklapajucaKugla &PostaviCentar(double x, double y, double z) {
        prethodna=zadnja;
        for(auto i=zadnja; i; i=i->prethodna) {
            if(!i)break;
            if(this == i)continue;
            if(i->r + r > udaljenost(x,y,z,i->x,i->y,i->z)|| jednako(i->r + r ,udaljenost(x,y,z,i->x,i->y,i->z)))throw std::logic_error("Nedozvoljeno preklapanje\n");
        }
        NepreklapajucaKugla::x=x;
        NepreklapajucaKugla::y=y;
        NepreklapajucaKugla::z=z;
        return *this;
    }
    NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar) {
        double x,y,z;
        std::tie(x,y,z)=centar;
        prethodna=zadnja;
        for(auto i=zadnja; i; i=i->prethodna) {
            if(!i)break;
            if(this == i)continue;
            if(i->r + r > udaljenost(x,y,z,i->x,i->y,i->z)|| jednako(i->r + r ,udaljenost(x,y,z,i->x,i->y,i->z)))throw std::logic_error("Nedozvoljeno preklapanje\n");
        }
        NepreklapajucaKugla::x=x;
        NepreklapajucaKugla::y=y;
        NepreklapajucaKugla::z=z;
        return *this;

    }
    NepreklapajucaKugla &PostaviPoluprecnik(double r) {
        prethodna=zadnja;
        for(auto i=zadnja; i; i=i->prethodna) {
            if(!i)break;
            if(this == i)continue;
            if(i->r + r > udaljenost(x,y,z,i->x,i->y,i->z) || jednako(i->r + r ,udaljenost(x,y,z,i->x,i->y,i->z)))throw std::logic_error("Nedozvoljeno preklapanje\n");
        }
        NepreklapajucaKugla::r=r;
        return *this;
    }
    void Ispisi() const {
        std::cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}\n";
    }
    void Transliraj(double delta_x, double delta_y, double delta_z) {
        prethodna=zadnja;
        for(auto i=zadnja; i; i=i->prethodna) {
            if(!i)break;
            if(this == i)continue;
            if(i->r + r > udaljenost(x+delta_x,y+delta_y,z+delta_z,i->x,i->y,i->z) || jednako(i->r + r ,udaljenost(x+delta_x,y+delta_y,z+delta_z,i->x,i->y,i->z) ))throw std::logic_error("Nedozvoljeno preklapanje\n");
        }
        x+=delta_x;
        y+=delta_y;
        z+=delta_z;
    }

    friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2) {
        return udaljenost(k1.x,k1.y,k1.z,k2.x,k2.y,k2.z);
    }
    NepreklapajucaKugla* dajp()
    {
        return prethodna;
    }
};

NepreklapajucaKugla* NepreklapajucaKugla::zadnja(nullptr);
typedef std::shared_ptr<NepreklapajucaKugla> ptrk;


int main ()
{

    
    std::cout<<"Unesite broj kugli: ";
    int n;
    for(;;){
        std::cin>>n;
        if(std::cin && n>0)break;
        std::cout<<"Neispravan broj kugli, unesite ponovo!\n";
        if(!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(1000,'\n');
        }
    }
    std::vector<ptrk> bure(n,nullptr);
    double x,y,z,r;
    for(int i=0; i<n; i++) {
        for(;;) {
            std::cout<<"Unesite centar za "<<i+1<<". kuglu: ";
           
                
              for(;;)
              {
                std::cin>>x>>y>>z;
              if(std::cin)break;
              if(!std::cin){
                std::cout<<"Neispravan centar, unesite ponovo: \n";
                std::cin.clear();
                std::cin.ignore(10,'\n');
              }
              }
            std::cout<<"Unesite poluprecnik: ";
            for(;;){
                std::cin>>r;
                if(std::cin && !(r<0))break;
              if(!std::cin || r<0 ){
                std::cout<<"Neispravan poluprecnik, unesite ponovo: \n";
                if(!std::cin){
                std::cin.clear();
                std::cin.ignore(10,'\n');
                }
                  
              }
                
            }
            try
            {
                bure.at(i)=std::make_shared<NepreklapajucaKugla>(x,y,z,r);
                break;
            }
            catch(std::logic_error izuzetak)
            {
              std::cout<<izuzetak.what();
            }
        }
    }
    std::sort(bure.begin(), bure.end(), [](ptrk a, ptrk b){ return a->DajPovrsinu( ) < b->DajPovrsinu();});
    std::cout<<"\nKugle nakon obavljenog sortiranja: \n";
    std::for_each(bure.begin(),bure.end(),[](ptrk a){a->Ispisi();});
    
    
    return 0;
}
