/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <tuple>
#include <vector>
#include <memory>
#include <algorithm>

const double eps(1e-10);
const double PI=(4.*std::atan(1.));

bool suJednaki(double x, double y)
{
    return std::fabs(x-y)<=eps*(std::fabs(x)+std::fabs(y));
}
double Kvadrat(double x)
{
    return x*x;
}
class Kugla
{
    double x,y,z,r;
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
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    x = 0; y = 0; z = 0;
    Kugla::r=r;
}
Kugla::Kugla(double x, double y, double z, double r)
{
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    Kugla::x=x; Kugla::y=y; Kugla::z=z; Kugla::r=r;
}
Kugla::Kugla(const std::tuple<double, double, double> &centar, double r)
{
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    Kugla::x=std::get<0>(centar); Kugla::y=std::get<1>(centar); Kugla::z=std::get<2>(centar); Kugla::r=r;
}
std::tuple<double, double, double> Kugla::DajCentar() const
{
    return std::make_tuple(x,y,z);
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
double Kugla::DajPoluprecnik() const
{
    return r;
}
double Kugla::DajZapreminu() const
{
    return (4*r*r*r*PI)/3;
}
double Kugla::DajPovrsinu() const
{
    return 4*r*r*PI;
}
double RastojanjeCentara(const Kugla &k1, const Kugla &k2)
{
    return std::sqrt(Kvadrat(k2.x-k1.x)+Kvadrat(k2.y-k1.y)+Kvadrat(k2.z-k1.z));
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
    Kugla::x=std::get<0>(centar);
    Kugla::y=std::get<1>(centar);
    Kugla::z=std::get<2>(centar);
    return *this;
}
Kugla &Kugla::PostaviPoluprecnik(double r)
{
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    Kugla::r=r;
    return *this;
}
void Kugla::Ispisi() const
{
    std::cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}"<<std::endl;
}
void Kugla::Transliraj(double delta_x, double delta_y, double delta_z)
{
    Kugla::x+=delta_x;
    Kugla::y+=delta_y;
    Kugla::z+=delta_z;
}
bool Kugla::DaLiSadrzi(const Kugla &k) const
{
    return (RastojanjeCentara(*this,k)+k.r)<=this->r && k.r<=this->r;
}
bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2)
{
    return suJednaki(k1.r,k2.r) && suJednaki(k1.x,k2.x) && suJednaki(k1.y,k2.y) && suJednaki(k1.z,k2.z);
}
bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2)
{
    return suJednaki(k1.r,k2.r);
}
bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2)
{
    return suJednaki(k1.x,k2.x) && suJednaki(k1.y,k2.y) && suJednaki(k1.z,k2.z);
}
bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2)
{
    return RastojanjeCentara(k1,k2)>=k1.r && RastojanjeCentara(k1,k2)>=k2.r && suJednaki(RastojanjeCentara(k1,k2),k1.r+k2.r);
}
bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2)
{
    return (RastojanjeCentara(k1,k2)<=k1.r || RastojanjeCentara(k1,k2)<=k2.r) && suJednaki(RastojanjeCentara(k1,k2),std::fabs(k1.r-k2.r));
}
bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2)
{
    return RastojanjeCentara(k1,k2)<k1.r+k2.r;
}
bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2)
{
    return RastojanjeCentara(k1,k2)<k1.r+k2.r && RastojanjeCentara(k1,k2)>std::fabs(k1.r-k2.r);
}
int main ()
{
    std::cout<<"Unesite broj kugla: ";
    int n;
    while(true)
    {
        std::cin>>n;
        if(!std::cin || std::cin.peek()!='\n' || n<=0)
        {
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            std::cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;
        }
        else break;
    }
    std::vector<std::shared_ptr<Kugla>> kugle;
    for(int i=0;i<n;i++)
    {
        while(true)
        {
            std::cout<<"Unesite centar "<<i+1<<". kugle: ";
            double x,y,z;
            std::cin>>x;
            std::cin>>y;
            std::cin>>z;
            if(!std::cin || std::cin.peek()!='\n')
            {
                std::cin.clear();
                std::cin.ignore(10000,'\n');
                std::cout<<"Neispravan centar"<<std::endl;
                continue;
            }
            std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
            double r;
            std::cin>>r;
            if(!std::cin || r<0)
            {
                std::cout<<"Ilegalan poluprecnik"<<std::endl;
                std::cin.clear();
                std::cin.ignore(10000,'\n');
            }
            else
            {
                std::shared_ptr<Kugla> p(new Kugla(x,y,z,r));
                kugle.push_back(p);
                break;
            }
        }
    }
    std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double dx,dy,dz;
    while(true)
    {
        std::cin>>dx>>dy>>dz;
        if(!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            std::cout<<"Neispravni parametri translacije, unesite ponovo!"<<std::endl;
        }
        else break;
    }
    std::transform(kugle.begin(),kugle.end(),kugle.begin(),[dx,dy,dz](std::shared_ptr<Kugla> &x)
    {
        x->Transliraj(dx,dy,dz);
        return x;
    });
    std::sort(kugle.begin(),kugle.end(),[](const std::shared_ptr<Kugla> &x,const std::shared_ptr<Kugla> &y)
    {
        return x->DajZapreminu()<y->DajZapreminu();
    });
    std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: ";
    std::cout<<std::endl;
    std::for_each(kugle.begin(),kugle.end(),[](const std::shared_ptr<Kugla> &x){
        x->Ispisi();
    });
    auto p=std::max_element(kugle.begin(),kugle.end(),[](const std::shared_ptr<Kugla> &x, const std::shared_ptr<Kugla> &y)
    {
        return x->DajPovrsinu()<y->DajPovrsinu();
    });
    std::cout<<"Kugla sa najvecom povrsinom je: ";
    (*p)->Ispisi();
    
    int i(1);
    bool nekeSeSijeku(false);
    std::for_each(kugle.begin(),kugle.end(),[&i,&kugle, &nekeSeSijeku](const std::shared_ptr<Kugla> &x)
    {
        std::for_each(kugle.begin()+i,kugle.end(),[&kugle, &x, &nekeSeSijeku](const std::shared_ptr<Kugla> &y)
        {
            if(DaLiSeSijeku(*x,*y))
            {
                std::cout<<"Presjecaju se kugle: ";
                x->Ispisi();
                y->Ispisi();
                nekeSeSijeku=true;
            }
        });
        i++;
    });
    if(!nekeSeSijeku) std::cout<<"Ne postoje kugle koje se presjecaju!";
    
    
	return 0;
}
//2 0 0 0 3 0 1 0 2 1 0 1
//3 0 0 0 4 2 0 0 2 1 2 3 4 0 0 0