/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <tuple>
#include <vector>
#include <memory>
#include <algorithm>

#define PI 4*atan(1)
#define epsilon 0.00000000001

class Kugla
{
    double x, y, z, r;
    
   public:
   
    explicit Kugla(double r = 0);
    Kugla(double x, double y, double z, double r = 0);
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0);
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

Kugla::Kugla(double r)
{
    if(r<0)
    throw std::domain_error ("Ilegalan poluprecnik");
    
    Kugla::r=r;
    x=0;
    y=0;
    z=0;
}

Kugla::Kugla(double x, double y, double z, double r)
{
    if(r<0)
    throw std::domain_error ("Ilegalan poluprecnik");
    
    Kugla::r=r;
    Kugla::x=x;
    Kugla::y=y;
    Kugla::z=z;
}

Kugla::Kugla(const std::tuple<double, double, double> &centar, double r)
{
    if(r<0)
    throw std::domain_error ("Ilegalan poluprecnik");
    
    Kugla::r=r;
    x = std::get<0>(centar);
    y = std::get<1>(centar);
    z = std::get<2>(centar);
}

double Kugla::DajX() const
{
    return x;
}

double Kugla::DajY() const
{
    return y;
}

double Kugla::DajZ() const
{
    return z;
}

std::tuple<double, double, double> Kugla::DajCentar() const
{
    return std::make_tuple(x, y, z);
}

double Kugla::DajPoluprecnik() const
{
    return r;
}

double Kugla::DajPovrsinu() const
{
    return 4*r*r*PI;
}

double Kugla::DajZapreminu() const
{
    return (4./3)*r*r*r*PI;
}

Kugla &Kugla::PostaviX(double x)
{
    Kugla::x=x;
    return *this;
}

Kugla &Kugla::PostaviY(double y)
{
    Kugla::y=y;
    return *this;
}

Kugla &Kugla::PostaviZ(double z)
{
    Kugla::z=z;
    return *this;
}

Kugla &Kugla::PostaviCentar(double x, double y, double z)
{
    Kugla::x=x;
    Kugla::y=y;
    Kugla::z=z;
    return *this;
}

Kugla &Kugla::PostaviCentar(const std::tuple<double, double, double> &centar)
{
    x = std::get<0>(centar);
    y = std::get<1>(centar);
    z = std::get<2>(centar);
    
    return *this;
}

Kugla &Kugla::PostaviPoluprecnik(double r)
{
    if(r<0)
    throw std::domain_error ("Ilegalan poluprecnik");
    
    Kugla::r=r;
    return *this;
}

void Kugla::Ispisi() const
{
    std::cout<< "{(" <<x<< "," <<y<< "," <<z<< ")," <<r<< "}" <<std::endl;
}

void Kugla::Transliraj(double delta_x, double delta_y, double delta_z)
{
    x+=delta_x;
    y+=delta_y;
    z+=delta_z;
}

double RastojanjeCentara(const Kugla &k1, const Kugla &k2)
{
    return  sqrt( (k1.x-k2.x)*(k1.x-k2.x) + (k1.y-k2.y)*(k1.y-k2.y) + (k1.z-k2.z)*(k1.z-k2.z) );
}

bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2)
{
    if(k1.x-k2.x<epsilon && k1.y-k2.y<epsilon && k1.z-k2.z<epsilon && k1.r-k2.r<epsilon)
    return true;
    return false;
}

bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2)
{
    if(k1.r-k2.r<epsilon)
    return true;
    return false;
}

bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2)
{
    if(k1.x-k2.x<epsilon && k1.y-k2.y<epsilon && k1.z-k2.z<epsilon)
    return true;
    return false;
}

bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2)
{
    if(RastojanjeCentara(k1, k2)-(k1.r+k2.r)<epsilon )
    return true;
    return false;
}

bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2)
{
    if( (RastojanjeCentara(k1, k2)+ k1.r) - k2.r <epsilon || (RastojanjeCentara(k1, k2)+k2.r) - k1.r<epsilon )
    return true;
    return false;
}

bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2)
{
    if( RastojanjeCentara(k1, k2)<(k1.r+k2.r))
    return true;
    return false;
}
bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2)
{
    //if(RastojanjeCentara(k1, k2)<(k1.r+k2.r) && ( (RastojanjeCentara(k1, k2)+k1.r >= k2.r || RastojanjeCentara(k1, k2)+k2.r >= k1.r ) ) )
    if(RastojanjeCentara(k1, k2) < (k1.r+k2.r) && RastojanjeCentara(k1, k2)> fabs(k1.r-k2.r) )
    return true;
    return false;
}
    
bool Kugla::DaLiSadrzi(const Kugla &k) const
{
    if( (RastojanjeCentara(k, *this) + k.r )<= r)
    return true;
    return false;
}

/*bool NeispravanUnos(double &broj)
{
    double pomocna;
    
    if(!(std::cin>>pomocna) || std::cin.peek()!='\n')
    {
        std::cout<<"neispravan unos, unesite ponovo kuglu"<<std::endl;
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        
        return true;
    }
    
    broj=pomocna;
    return false;
}


for(int i=0; i<v.size(); i++)
    {
        double x, y, z, r;
        std::cout<<"Unesite centar "<<i+1<<". kugle: "<<std::endl;
        
        if(NeispravanUnos(x) || NeispravanUnos(y) || NeispravanUnos(z) )
        {
            i--;
            continue;
        }
        
        std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: "<<std::endl;
        
        if(NeispravanUnos(r) || r<0)
        {
            std::cout<<"neispravan unos, unesite ponovo kuglu"<<std::endl;
            i--;
            continue;
        }
        
        v.at(i)=std::make_shared<Kugla>(x, y, z, r);
    }

*/

int main ()
{
    int n;
    std::cout<<"Unesite broj kugla: ";
    
    while(true)
    {
        std::cin>>n;
        
        if(std::cin && n>0)
        break;
        
        std::cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }
    std::vector<std::shared_ptr<Kugla>> v(n);
    
    
    std::shared_ptr<Kugla> pok;
    
    for(int i=0; i<v.size(); i++)
    {
        double x, y, z, r;
        std::cout<<"Unesite centar "<<i+1<<". kugle: ";
        
        std::cin>>x>>y>>z;
        
        if(!std::cin)
        {
            std::cout<<"Neispravan centar "<<std::endl;;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            i--;
            continue;
        }
        
        std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
        
        std::cin>>r;
        
        if(!std::cin )
        {
            std::cout<<"Ilegalan poluprecnik"<<std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            i--;
            continue;
        }
        
        if(r<0)
        {
            std::cout<<"Ilegalan poluprecnik"<<std::endl;
            i--;
            continue;
        }
        
        v.at(i)=std::make_shared<Kugla>(x, y, z, r);
    }
    
    std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double xt, yt, zt;
    
    while(true)
    {
        std::cin>>xt>>yt>>zt;
        
        if(std::cin)
        break;
        
        std::cout<<"Neispravni parametri translacije, unesite ponovo!"<<std::endl;
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }
    
    std::transform(v.begin(), v.end(), v.begin(), [xt, yt, zt](std::shared_ptr<Kugla> prvi)
    {
         prvi->Transliraj(xt, yt, zt);
         return prvi;
    });
    
    std::sort(v.begin(), v.end(), [](std::shared_ptr<Kugla> prvi, std::shared_ptr<Kugla> drugi )
    {
        return prvi->DajZapreminu() < drugi->DajZapreminu();
    });
    
    std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<std::endl;
    
    std::for_each(v.begin(), v.end(), [](std::shared_ptr<Kugla> prvi)
    {
        prvi->Ispisi();
    });
    
   auto najveca_povrsina = *std::max_element(v.begin(), v.end(), [](std::shared_ptr<Kugla> prvi, std::shared_ptr<Kugla> drugi ) 
    {
       if(prvi->DajPovrsinu() < drugi->DajPovrsinu() )
       return true;
       
       return false;
    });
    
    std::cout<<"Kugla sa najvecom povrsinom je: ";
    najveca_povrsina->Ispisi();
    
    int brojac(0);
    bool ne_sijeku(true);
    
    std::for_each(v.begin(), v.end(), [&v, &brojac, &ne_sijeku](std::shared_ptr<Kugla> trenutna)
    {
        brojac++;
        std::for_each(v.begin()+brojac, v.end(), [&trenutna, &ne_sijeku](std::shared_ptr<Kugla> ostale)
        {
            if(DaLiSeSijeku( *trenutna, *ostale ))
            {
                std::cout<<"Presjecaju se kugle: ";
                trenutna->Ispisi();
                ostale->Ispisi();
                ne_sijeku=false;
            }
            
        });
    });
    
    if(ne_sijeku)
    std::cout<<"Ne postoje kugle koje se presjecaju!";
    
	return 0;
}
