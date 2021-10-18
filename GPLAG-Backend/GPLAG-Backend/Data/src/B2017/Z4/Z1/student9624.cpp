/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <utility>
#include <memory>
#include <algorithm>
#include <cmath>
#include <vector>


class Kugla
{
    double x,y,z,r;
    static bool Poredi(double x, double y) {
        const double eps(1e-10);
        if(std::fabs(x-y)<=eps* (std::fabs(x) + std::fabs(y))) return true;
        return false;
    };
public:
    explicit Kugla(double r = 0) {
        if(r<0) throw std::domain_error ("Ilegalan poluprecnik");
        Kugla::r=r;
        x=0;
        y=0;
        z=0;
    };
    Kugla(double x, double y, double z, double r = 0) {
        if(r<0) throw std::domain_error ("Ilegalan poluprecnik");
        Kugla::r=r;
        Kugla::x=x;
        Kugla::y=y;
        Kugla::z=z;
    };
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0) {
        if(r<0) throw std::domain_error ("Ilegalan poluprecnik");
        Kugla::r=r;
        Kugla::x=std::get<0>(centar);
        Kugla::y=std::get<1>(centar);
        Kugla::z=std::get<1>(centar);
    };
    double DajX() const {
        return x;
    };
    double DajY() const {
        return y;
    };
    double DajZ() const {
        return z;
    };
    std::tuple<double, double, double> DajCentar() const {
        return std::make_tuple(x,y,z);
    };
    double DajPoluprecnik() const {
        return r;
    };
    double DajPovrsinu() const {
        double PI(4*atan(1));
        return 4*r*r*PI;
    };
    double DajZapreminu() const {
        double PI(4*atan(1));
        return (4*r*r*r*PI)/3;
    };
    Kugla &PostaviX(double x) {
        Kugla::x=x;
        return *this;
    };
    Kugla &PostaviY(double y)  {
        Kugla::y=y;
        return *this;
    };
    Kugla &PostaviZ(double z)  {
        Kugla::z=z;
        return *this;
    };
    Kugla &PostaviCentar(double x, double y, double z) {
        Kugla::x=x;
        Kugla::y=y;
        Kugla::z=z;
        return *this;
    };
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar) {
        Kugla::x=std::get<0>(centar);
        Kugla::y=std::get<1>(centar);
        Kugla::z=std::get<1>(centar);
        return *this;
    };
    Kugla &PostaviPoluprecnik(double r) {
        if(r<0) throw std::domain_error ("Ilegalan poluprecnik");
        Kugla::r=r;
        return *this;
    };
    void Ispisi() const {
        std::cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}"<<std::endl;
    };
    void Transliraj(double delta_x, double delta_y, double delta_z) {
        x += delta_x;
        y += delta_y;
        z += delta_z;
    };
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
    bool DaLiSadrzi(const Kugla &k) const {
        if( DaLiSeSijeku(*this,k)  || RastojanjeCentara(*this,k)>this->r+k.r) return false;
        return true;
    }
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);

};

int main ()
{
    int n;
    std::cout<<"Unesite broj kugla: ";
    
    
    while(1){
        std::cin>>n;
        if(n>0) break;
        else {
            std::cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;
            std::cin.clear(); 
            std::cin.ignore(10000, '\n');
        } 
            
            
        
     
        
    }
    
    std::vector<std::shared_ptr<Kugla>> v(n);
    int i(0);
    while(i<n) {
        double x,y,z,r;
        
        while(1){
            std::cout<<"Unesite centar "<<i+1<<". kugle: ";
            std::cin>>x >>y >>z;
            if(!std::cin){
                std::cout<<"Neispravan centar"<<std::endl;
                std::cin.clear(); 
                std::cin.ignore(10000, '\n');
            }
            else break;
            
        
        }
        
        std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
        std::cin>>r;
        if(r<0 || !std::cin)  {
            std::cout<<"Ilegalan poluprecnik"<<std::endl;  ;
            std::cin.clear(); 
            std::cin.ignore(10000, '\n');
            i--;
        } else
            try {
                std:: shared_ptr<Kugla> pomocni(std::make_shared<Kugla>(Kugla(x,y,z,r)));
                v.at(i)=pomocni;
            } catch(std::domain_error x) {
                std:: cout<<x.what();
            }
        i++;
    }
    std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double dx,dy,dz;
    while(1){
        std::cin>>dx >>dy >>dz;
        if(!std::cin){
            std::cout<<"Neispravni parametri translacije, unesite ponovo!"<<std::endl;
            std::cin.clear(); 
            std::cin.ignore(10000, '\n');
        }
        else break;
    }
    
    std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<std::endl;
    std::transform(v.begin(), v.end() , v.begin() , [dx,dy,dz](std::shared_ptr<Kugla> k) {
        k->Transliraj(dx,dy,dz);
        return k;
    });
    std::sort(v.begin(), v.end(), [](std::shared_ptr<Kugla> prvi, std::shared_ptr<Kugla> drugi) {
        return (prvi->DajZapreminu()<drugi->DajZapreminu());
    });
    std::for_each(v.begin(), v.end(), [](std::shared_ptr<Kugla> k) {
        k->Ispisi();
    });
    std::shared_ptr<Kugla> x;
    std::cout<<"Kugla sa najvecom povrsinom je: ";
    x=*std::max_element(v.begin(), v.end(), [](std::shared_ptr<Kugla> prvi, std::shared_ptr<Kugla> drugi) {
        return prvi->DajPovrsinu()<drugi->DajPovrsinu();
    });
    x->Ispisi();
    int j(1),k(0);
    std::for_each(v.begin(), v.end(),[v,&j,&k](std::shared_ptr<Kugla> k1) {

        for_each(v.begin()+j,v.end(),[k1,&k](std::shared_ptr<Kugla> k2) {
            if(DaLiSeSijeku(*k1,*k2)) {
                std::cout<<"Presjecaju se kugle: ";
                k1->Ispisi();
                k2->Ispisi();
                k++;
            }

        }


                );
        j++;
    });
    if(k==0) std::cout<<"Ne postoje kugle koje se presjecaju!";
    return 0;
}

bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2)
{
    if(Kugla::Poredi(k1.x,k2.x) && Kugla::Poredi(k1.y,k2.y) && Kugla::Poredi(k1.z,k2.z) && Kugla::Poredi(k1.r,k2.r)) return true;
    return false;
}
bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2)
{
    if( Kugla::Poredi(k1.r,k2.r)) return true;
    return false;
}
bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2)
{
    if(Kugla::Poredi(k1.x,k2.x) && Kugla::Poredi(k1.y,k2.y) && Kugla::Poredi(k1.z,k2.z) ) return true;
    return false;
}
bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2)
{
    if(Kugla::Poredi(RastojanjeCentara(k1,k2),k1.r+k2.r)) return true;
    return false;
}
bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2)
{
    double rmanje,rvece;
    if(k1.r<k2.r) {
        rmanje=k1.r;
        rvece=k2.r;
    } else {
        rmanje=k2.r;
        rvece=k1.r;
    }
    if(Kugla::Poredi(RastojanjeCentara(k1,k2)+rmanje, rvece)) return true;
    return false;

}
bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2)
{
    if(DaLiSeSijeku(k1,k2) || RastojanjeCentara(k1,k2)>k1.r+k2.r || DaLiSeDodirujuIzvana(k1,k2)) return true;
    return false;
}
bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2)
{
    if(DaLiSeDodirujuIznutra(k1,k2) || DaLiSeDodirujuIzvana(k1,k2)) return false;
    if(RastojanjeCentara(k1,k2)<k1.r+k2.r) return true;
    return false;
}

double RastojanjeCentara(const Kugla &k1, const Kugla &k2)
{

    return sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z));
}