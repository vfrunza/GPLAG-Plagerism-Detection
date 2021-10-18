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
class NepreklapajucaKugla
{
    NepreklapajucaKugla* prethodna;
    static NepreklapajucaKugla* pocetak;
    double x,y,z,r;
    bool Test(const NepreklapajucaKugla &k) const;
    public:
        explicit NepreklapajucaKugla(double r = 0);
        NepreklapajucaKugla(double x, double y, double z, double r = 0);
        explicit NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r = 0);
        NepreklapajucaKugla(const NepreklapajucaKugla &k) = delete;
        NepreklapajucaKugla(NepreklapajucaKugla &&k) = delete;
        NepreklapajucaKugla &operator=(const NepreklapajucaKugla &k) = delete;
        NepreklapajucaKugla &operator=(NepreklapajucaKugla &&k) = delete;
        ~NepreklapajucaKugla()
        {
            if(pocetak==this) pocetak=prethodna; 
            else
            {
                auto pom(pocetak); 
                while(pom->prethodna!=this) pom=pom->prethodna; 
                pom->prethodna=prethodna;
            }
        }
        double DajX() const;
        double DajY() const;
        double DajZ() const;
        std::tuple<double, double, double> DajCentar() const;
        double DajPoluprecnik() const;
        double DajPovrsinu() const;
        double DajZapreminu() const;
        NepreklapajucaKugla &PostaviX(double x);
        NepreklapajucaKugla &PostaviY(double y);
        NepreklapajucaKugla &PostaviZ(double z);
        NepreklapajucaKugla &PostaviCentar(double x, double y, double z);
        NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar);
        NepreklapajucaKugla &PostaviPoluprecnik(double r);
        void Ispisi() const;
        void Transliraj(double delta_x, double delta_y, double delta_z);
        friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
};
NepreklapajucaKugla* NepreklapajucaKugla::pocetak=nullptr;

/******** TEST ********/
bool NepreklapajucaKugla::Test(const NepreklapajucaKugla &k) const 
{
    auto pom(pocetak);
    while(pom!=nullptr)
    {
        if(RastojanjeCentara(k,*pom)<=k.r+pom->r) return false;
        pom=pom->prethodna;
    }
    return true;
}
/**********************/

NepreklapajucaKugla::NepreklapajucaKugla(double rr) : x(0), y(0), z(0), r(rr)
{
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    if(!Test(*this)) throw std::logic_error("Nedozvoljeno preklapanje");
    prethodna=pocetak;
    pocetak=this;
}
NepreklapajucaKugla::NepreklapajucaKugla(double xx, double yy, double zz, double rr) : x(xx), y(yy), z(zz), r(rr)
{
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    if(!Test(*this)) throw std::logic_error("Nedozvoljeno preklapanje");
    
    prethodna=pocetak;
    pocetak=this;
}
NepreklapajucaKugla::NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double rr) : x(std::get<0>(centar)), y(std::get<1>(centar)), z(std::get<2>(centar)), r(rr)
{
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    if(!Test(*this)) throw std::logic_error("Nedozvoljeno preklapanje");
    prethodna=pocetak;
    pocetak=this;
}
std::tuple<double, double, double> NepreklapajucaKugla::DajCentar() const
{
    return std::make_tuple(x,y,z);
}
double NepreklapajucaKugla::DajX() const
{
    return x;
}
double NepreklapajucaKugla::DajY() const
{
    return y;
}
double NepreklapajucaKugla::DajZ() const
{
    return z;
}
double NepreklapajucaKugla::DajPoluprecnik() const
{
    return r;
}
double NepreklapajucaKugla::DajZapreminu() const
{
    return (4*r*r*r*PI)/3;
}
double NepreklapajucaKugla::DajPovrsinu() const
{
    return 4*r*r*PI;
}
double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2)
{
    return std::sqrt(Kvadrat(k2.x-k1.x)+Kvadrat(k2.y-k1.y)+Kvadrat(k2.z-k1.z));
}
NepreklapajucaKugla &NepreklapajucaKugla::PostaviX(double x)
{
    double pom(NepreklapajucaKugla::x);
    NepreklapajucaKugla::x=x;
    if(!Test(*this)) 
    {
        NepreklapajucaKugla::x=pom;
        throw std::logic_error("Nedozvoljeno preklapanje");
    }
    return *this;
}
NepreklapajucaKugla &NepreklapajucaKugla::PostaviY(double y)
{
    double pom(NepreklapajucaKugla::y);
    NepreklapajucaKugla::y=y;
    if(!Test(*this)) 
    {
        NepreklapajucaKugla::y=pom;
        throw std::logic_error("Nedozvoljeno preklapanje");
    }
    NepreklapajucaKugla::y=y;
    return *this;
}
NepreklapajucaKugla &NepreklapajucaKugla::PostaviZ(double z)
{
    double pom(NepreklapajucaKugla::z);
    NepreklapajucaKugla::z=z;
    if(!Test(*this)) 
    {
        NepreklapajucaKugla::z=pom;
        throw std::logic_error("Nedozvoljeno preklapanje");
    }
    return *this;
}
NepreklapajucaKugla &NepreklapajucaKugla::PostaviCentar(double x, double y, double z)
{
    double pom1(NepreklapajucaKugla::x),pom2(NepreklapajucaKugla::y),pom3(NepreklapajucaKugla::z);
    NepreklapajucaKugla::x=x;
    NepreklapajucaKugla::y=y;
    NepreklapajucaKugla::z=z;
    if(!Test(*this)) 
    {
        NepreklapajucaKugla::x=pom1;
        NepreklapajucaKugla::y=pom2;
        NepreklapajucaKugla::z=pom3;
        throw std::logic_error("Nedozvoljeno preklapanje");
    }
    return *this;
}
NepreklapajucaKugla &NepreklapajucaKugla::PostaviCentar(const std::tuple<double, double, double> &centar)
{
    double pom1(NepreklapajucaKugla::x),pom2(NepreklapajucaKugla::y),pom3(NepreklapajucaKugla::z);
    NepreklapajucaKugla::x=std::get<0>(centar);
    NepreklapajucaKugla::y=std::get<1>(centar);
    NepreklapajucaKugla::z=std::get<2>(centar);
    if(!Test(*this)) 
    {
        NepreklapajucaKugla::x=pom1;
        NepreklapajucaKugla::y=pom2;
        NepreklapajucaKugla::z=pom3;
        throw std::logic_error("Nedozvoljeno preklapanje");
    }
    return *this;
}
NepreklapajucaKugla &NepreklapajucaKugla::PostaviPoluprecnik(double r)
{
    double pom(NepreklapajucaKugla::r);
    NepreklapajucaKugla::r=r;
    if(!Test(*this)) 
    {
        NepreklapajucaKugla::r=pom;
        throw std::logic_error("Nedozvoljeno preklapanje");
    }
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    return *this;
}
void NepreklapajucaKugla::Ispisi() const
{
    std::cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}"<<std::endl;
}
void NepreklapajucaKugla::Transliraj(double delta_x, double delta_y, double delta_z)
{
    double pom1(NepreklapajucaKugla::x),pom2(NepreklapajucaKugla::y),pom3(NepreklapajucaKugla::z);
    NepreklapajucaKugla::x+=delta_x;
    NepreklapajucaKugla::y+=delta_y;
    NepreklapajucaKugla::z+=delta_z;
    if(!Test(*this)) 
    {
        NepreklapajucaKugla::x=pom1;
        NepreklapajucaKugla::y=pom2;
        NepreklapajucaKugla::z=pom3;
        throw std::logic_error("Nedozvoljeno preklapanje");
    }
}

int main ()
{/*
    std::cout<<"Unesite broj kugli: ";
    int n;
    while(true)
    {
        std::cin>>n;
        if(std::cin.peek()!='\n' || n<=0)
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;
        }
        else break;
    }
    std::vector<std::shared_ptr<NepreklapajucaKugla>> kugle;
    for(int i=0;i<n;i++)
    {
        while(true)
        {
            double x,y,z;
            double r;
            std::cout<<"Unesite centar za "<<i+1<<". kuglu: ";
            std::cin>>x>>y>>z;
            while(true)
            {
                if(std::cin.peek()!='\n')
                {
                    std::cout<<"Neispravan centar, unesite ponovo: "<<std::endl;
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    std::cin>>x>>y>>z;
                }
                else break;
            }
            std::cout<<"Unesite poluprecnik: ";
            while(true)
            {
                std::cin>>r;
                if(!std::cin || r<0)
                {
                    std::cout<<"Neispravan poluprecnik, unesite ponovo: "<<std::endl;
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                }
                else break;
            }       
            try
            {
                std::shared_ptr<NepreklapajucaKugla> p(new NepreklapajucaKugla(x,y,z,r));
                kugle.push_back(p);
                break;
            }
            catch(...)
            {
                std::cout<<"Nedozvoljeno preklapanje"<<std::endl;
            }
            
        }
    }
    std::sort(kugle.begin(),kugle.end(),[](const std::shared_ptr<NepreklapajucaKugla> &x,const std::shared_ptr<NepreklapajucaKugla> &y)
    {
        return x->DajPovrsinu()<y->DajPovrsinu();
    });
    std::cout<<std::endl<<"Kugle nakon obavljenog sortiranja: ";
    std::cout<<std::endl;
    std::for_each(kugle.begin(),kugle.end(),[](const std::shared_ptr<NepreklapajucaKugla> &x){
        x->Ispisi();
    });*/
    
        NepreklapajucaKugla k(std::make_tuple(8,16,32), 30.3);
        k.PostaviX(-1).PostaviY(-2).PostaviZ(-3);
        k.Ispisi();
    
	return 0;
}