/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <utility>
#include <tuple>
#include <cmath>
#include <algorithm>
#include <vector>
#include <memory>
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

class Kugla 
{
  double x,y,z,r;
  public:
    explicit Kugla(double r = 0)
    {
        if(r<0)throw std::domain_error("Ilegalan poluprecnik");
        x=y=z=0;
        Kugla::r=r;
    }
    Kugla(double x, double y, double z, double r = 0)
    {
        if(r<0)throw std::domain_error("Ilegalan poluprecnik");
        Kugla::x=x;
        Kugla::y=y;
        Kugla::z=z;
        Kugla::r=r;
    }
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0)
    {
        if(r<0)throw std::domain_error("Ilegalan poluprecnik");
        x=std::get<0>(centar);
        y=std::get<1>(centar);
        z=std::get<2>(centar);
        Kugla::r=r;
    }
    double DajX() const
    {
        return x;
    }
    double DajY() const
    {
        return y;
    }
    double DajZ() const
    {
        return z;
    }
    std::tuple<double, double, double> DajCentar() const
    {
        return std::tie(x,y,z);
    }
    double DajPoluprecnik() const
    {
        return r;
    }
    double DajPovrsinu() const
    {
        return 4*r*r*pi;
    }
    double DajZapreminu() const
    {
        return 4./3*r*r*r*pi;
    }
    Kugla &PostaviX(double x)
    {
        Kugla::x=x;
        return *this;
    }
    Kugla &PostaviY(double y)
    {
        Kugla::y=y;
        return *this;
    }
    Kugla &PostaviZ(double z)
    {
        Kugla::z=z;
        return *this;
    }
    Kugla &PostaviCentar(double x, double y, double z)
    {
        Kugla::x=x;
        Kugla::y=y;
        Kugla::z=z;
        return *this;
    }
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar)
    {
        double x,y,z;
        std::tie(x,y,z)=centar;
        Kugla::x=x;
        Kugla::y=y;
        Kugla::z=z;
        return *this;
        
    }
    Kugla &PostaviPoluprecnik(double r)
    {
        Kugla::r=r;
        return *this;
    }
    void Ispisi() const
    {
        std::cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}\n";
    }
    void Transliraj(double delta_x, double delta_y, double delta_z)
    {
        x+=delta_x;
        y+=delta_y;
        z+=delta_z;
    }
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2)
    {
        return (jednako(k1.x,k2.x) && jednako(k1.y,k2.y) && jednako(k1.z,k2.z) && jednako(k1.r,k2.r));
    }
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2)
    {
        return jednako(k1.r,k2.r);
    }
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2)
    {
        return (jednako(k1.x,k2.x) && jednako(k1.y,k2.y) && jednako(k1.z,k2.z));
    }
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2)
    {
        return jednako(RastojanjeCentara(k1,k2),k1.r+k2.r);
    }
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2)
    {
        return jednako(RastojanjeCentara(k1,k2),std::fabs(k1.r-k2.r));
    }
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2)
    {
        return (k1.r+k2.r>RastojanjeCentara(k1,k2));
    }
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2)
    {
        return DaLiSePreklapaju(k1,k2) && (std::fabs(k1.r-k2.r)<RastojanjeCentara(k1,k2));
    }
    bool DaLiSadrzi(const Kugla &k) const
    {
        return ( RastojanjeCentara(k,*this) < std::fabs(k.r-this->r) && this->r > k.r ) || jednako(RastojanjeCentara(k,*this),std::fabs(k.r- this->r));
    }
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2)
    {
        return udaljenost(k1.x,k1.y,k1.z,k2.x,k2.y,k2.z);
    }
};

typedef std::shared_ptr<Kugla> ptrk;


int main ()
{
    
    int n;
    std::cout<<"Unesite broj kugla: ";
    for(;;)
    {
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
    for(int i=0;i<n;i++)
    {
        std::cout<<"Unesite centar "<<i+1<<". kugle: ";
            std::cin>>x>>y>>z;
        if(!std::cin){std::cout<<"Neispravan centar\n";
        i--;
        if(!std::cin){
        std::cin.clear();
        std::cin.ignore(1000,'\n');}
        continue;}
            
   
        std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
            std::cin>>r;
 
        if(!std::cin || r<0){std::cout<<"Ilegalan poluprecnik\n";
        i--;
        if(!std::cin){
        std::cin.clear();
        std::cin.ignore(1000,'\n');}
        continue;}
       
        bure.at(i)=std::make_shared<Kugla>(x,y,z,r);
    }
     
        std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
        for(;;)
        {
            std::cin>>x>>y>>z;
            if(std::cin)break;
            std::cout<<"Neispravni parametri translacije, unesite ponovo!\n";
            std::cin.clear();
            std::cin.ignore(1000,'\n');
        }
    std::transform(bure.begin(), bure.end(), bure.begin(), [x,y,z](ptrk a){ a.get()->Transliraj(x,y,z);return a;});
    std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: \n";
    std::sort(bure.begin(), bure.end(), [](ptrk a, ptrk b){return a.get()->DajZapreminu() < b.get()->DajZapreminu();});
    std::for_each(bure.begin(), bure.end(), [](ptrk a){a.get()->Ispisi(); });
    std::cout<<"Kugla sa najvecom povrsinom je: ";
    (*std::max_element(bure.begin(),bure.end(),[](ptrk a, ptrk b){ return a->DajPovrsinu() < b->DajPovrsinu();}))->Ispisi();
  
    bool ima(false);
    bool moze(false);
  
    std::for_each(bure.begin(), bure.end(), 
        [&bure,&ima,&moze](ptrk a)
            {
             std::for_each(bure.begin(), bure.end(),[a,&ima,&moze]( ptrk b)
             {
                 if(moze)
                 {
                     if(DaLiSeSijeku(*a,*b))
                     {
                         std::cout<<"Presjecaju se kugle: ";
                         a->Ispisi();
                         
                         b->Ispisi();
                         ima=true;
                     }
                 }
                 if(a==b)moze=true;
             });
             moze=false;
            });
            if(!ima)std::cout<<"Ne postoje kugle koje se presjecaju!";
    
	return 0;
}
