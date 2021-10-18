/B2017/2018: Zadaća 4, Zadatak 2
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>

const double PI(4*std::atan(1));

class NepreklapajucaKugla {
    double r,x,y,z;
    NepreklapajucaKugla *pok_na_kuglu;
    static NepreklapajucaKugla *posljednja;
    static bool DaLiSePreklapaju (const NepreklapajucaKugla &k, double x, double y, double z, double r);
    static double Rastojanje (const NepreklapajucaKugla &k, double x, double y, double z);
    static bool JesuLiJednaki (double x, double y, double eps=1e-10) {return std::fabs(x-y)<=eps*(std::fabs(x)+std::fabs(y));}
    static bool Preklapanje (double x, double y, double z, double r, NepreklapajucaKugla *pokazivac=nullptr);
public:
    explicit NepreklapajucaKugla (double r=0);
    NepreklapajucaKugla (double x, double y, double z, double r=0);
    explicit NepreklapajucaKugla (const std::tuple<double,double,double> &centar, double r=0);
    NepreklapajucaKugla (const NepreklapajucaKugla &k) = delete;
    NepreklapajucaKugla &operator = (const NepreklapajucaKugla &k) = delete;
    ~NepreklapajucaKugla();
    double DajX () const {return x;}
    double DajY () const {return y;}
    double DajZ () const {return z;}
    std::tuple<double,double,double> DajCentar() const {return std::make_tuple(x,y,z);}
    double DajPoluprecnik() const {return r;}
    double DajPovrsinu () const {return 4*PI*r*r;}
    double DajZapreminu () const {return (4*PI*r*r*r)/3;}
    NepreklapajucaKugla &PostaviX (double x) {if(Preklapanje(x,NepreklapajucaKugla::y,NepreklapajucaKugla::z,r,this)) throw std::logic_error ("Nedozvoljeno preklapanje"); NepreklapajucaKugla::x=x; return *this;}
    NepreklapajucaKugla &PostaviY (double y) {if(Preklapanje(NepreklapajucaKugla::x,y,NepreklapajucaKugla::z,r,this)) throw std::logic_error ("Nedozvoljeno preklapanje"); NepreklapajucaKugla::y=y; return *this;}
    NepreklapajucaKugla &PostaviZ (double z) {if(Preklapanje(NepreklapajucaKugla::x,NepreklapajucaKugla::y,z,r,this)) throw std::logic_error ("Nedozvoljeno preklapanje"); NepreklapajucaKugla::z=z; return *this;}
    NepreklapajucaKugla &PostaviCentar (double x, double y, double z);
    NepreklapajucaKugla &PostaviCentar (const std::tuple<double,double,double> &centar);
    NepreklapajucaKugla &PostaviPoluprecnik (double r);
    void Ispisi () const {std::cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}\n";}
    void Transliraj (double delta_x, double delta_y, double delta_z) {if (Preklapanje(x+delta_x,y+delta_y,z+delta_z,r,this)) throw std::logic_error("Nedozvoljeno preklapanje"); x+=delta_x; y+=delta_y; z+=delta_z;}
    friend double RastojanjeCentara (const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
};

NepreklapajucaKugla* NepreklapajucaKugla::posljednja(nullptr);

NepreklapajucaKugla &NepreklapajucaKugla::PostaviCentar (double x, double y, double z)
{
    if (Preklapanje(x,y,z,r,this))
        throw std::logic_error("Nedozvoljeno preklapanje");
    NepreklapajucaKugla::x=x; NepreklapajucaKugla::y=y; NepreklapajucaKugla::z=z;
    return *this;
}

NepreklapajucaKugla &NepreklapajucaKugla::PostaviCentar(const std::tuple<double,double,double> &centar)
{
    if (Preklapanje(std::get<0>(centar),std::get<1>(centar),std::get<2>(centar),r,this))
        throw std::logic_error("Nedozvoljeno preklapanje");
    x=std::get<0>(centar); y=std::get<1>(centar); z=std::get<2>(centar);
    return *this;
}

NepreklapajucaKugla &NepreklapajucaKugla::PostaviPoluprecnik (double r)
{
    if (r<0) throw std::domain_error ("Ilegalan poluprecnik");
    if (Preklapanje(x,y,z,r,this)) throw std::logic_error ("Nedozvoljeno preklapanje");
    NepreklapajucaKugla::r=r;
    return *this;
}

double NepreklapajucaKugla::Rastojanje (const NepreklapajucaKugla &k, double x, double y, double z)
{
    return std::sqrt((k.x-x)*(k.x-x)+(k.y-y)*(k.y-y)+(k.z-z)*(k.z-z));
}

bool NepreklapajucaKugla::DaLiSePreklapaju (const NepreklapajucaKugla &k, double x, double y, double z, double r)
{
    return !(Rastojanje(k,x,y,z)>k.r+r);
}

NepreklapajucaKugla::NepreklapajucaKugla (double r)
{
    if (r<0) throw std::domain_error ("Ilegalan poluprecnik");
    if (Preklapanje(0,0,0,r))
        throw std::logic_error("Nedozvoljeno preklapanje");
    NepreklapajucaKugla::r=r; NepreklapajucaKugla::x=0; NepreklapajucaKugla::y=0; NepreklapajucaKugla::z=0;
    if (NepreklapajucaKugla::posljednja==nullptr)
    pok_na_kuglu=nullptr;
    else
    pok_na_kuglu=posljednja;
    posljednja=this;
}

NepreklapajucaKugla::NepreklapajucaKugla(double x, double y, double z, double r)
{
    if (r<0) throw std::domain_error("Ilegalan poluprecnik");
    if (Preklapanje(x,y,z,r))
        throw std::logic_error ("Nedozvoljeno preklapanje");
    NepreklapajucaKugla::r=r; NepreklapajucaKugla::x=x; NepreklapajucaKugla::y=y; NepreklapajucaKugla::z=z;
    if (NepreklapajucaKugla::posljednja==nullptr)
    pok_na_kuglu=nullptr;
    else
    pok_na_kuglu=posljednja;
    posljednja=this;
}

NepreklapajucaKugla::NepreklapajucaKugla(const std::tuple<double,double,double> &centar, double r)
{
    if (r<0) throw std::domain_error ("Ilegalan poluprecnik");
    if (Preklapanje(std::get<0>(centar),std::get<1>(centar),std::get<2>(centar),r))
        throw std::logic_error ("Nedozvoljeno preklapanje");
    NepreklapajucaKugla::r=r; NepreklapajucaKugla::x=std::get<0>(centar); NepreklapajucaKugla::y=std::get<1>(centar); NepreklapajucaKugla::z=std::get<2>(centar);
    if (NepreklapajucaKugla::posljednja==nullptr)
    pok_na_kuglu=nullptr;
    else
    pok_na_kuglu=posljednja;
    posljednja=this;
}

double RastojanjeCentara (const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2)
{
    return std::sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z));
}

bool NepreklapajucaKugla::Preklapanje (double x, double y, double z, double r, NepreklapajucaKugla *pokazivac)
{
    NepreklapajucaKugla *pok(NepreklapajucaKugla::posljednja);
    while (pok!=nullptr)
    {
        if (pok!=pokazivac && NepreklapajucaKugla::DaLiSePreklapaju(*pok,x,y,z,r))
        return true;
        pok=pok->pok_na_kuglu;
    }
    return false;
}

NepreklapajucaKugla::~NepreklapajucaKugla()
{
    NepreklapajucaKugla *pok(NepreklapajucaKugla::posljednja);
    if (this==NepreklapajucaKugla::posljednja)
    {
        posljednja=this->pok_na_kuglu;
        this->pok_na_kuglu=nullptr;
        pok=nullptr;
    }
    while (pok!=nullptr)
    {
        if (pok->pok_na_kuglu==this)
        {
            pok->pok_na_kuglu=this->pok_na_kuglu;
            this->pok_na_kuglu=nullptr;
        }
        pok=pok->pok_na_kuglu;
    }
}

int main ()
{
    int n;
    std::cout<<"Unesite broj kugli: ";
    while (std::cin>>n,!std::cin || n<=0)
    {
        std::cin.clear(); std::cin.ignore(10000,'\n');
        std::cout<<"Neispravan broj kugli, unesite ponovo!\n";
    }
    std::vector<std::shared_ptr<NepreklapajucaKugla>> vec(n);
    for (int i=0;i<n;i++)
    {
        double x,y,z,r;
        try {
        std::cout<<"Unesite centar za "<<i+1<<". kuglu: ";
        while (std::cin>>x>>y>>z,!std::cin)
        {
            std::cin.clear(); std::cin.ignore(10000,'\n');
            std::cout<<"Neispravan centar, unesite ponovo: \n";
        }
        std::cout<<"Unesite poluprecnik: ";
        while (std::cin>>r, !std::cin || r<0)
        {
            std::cin.clear(); std::cin.ignore(10000,'\n');
            std::cout<<"Neispravan poluprecnik, unesite ponovo: \n";
        }
        vec[i]=std::make_shared<NepreklapajucaKugla> (x,y,z,r);}
        catch(std::logic_error izuz2)
        {
            std::cout<<izuz2.what()<<"\n";
            --i;
        }
    }
    std::cout<<"\nKugle nakon obavljenog sortiranja: \n";
    std::sort(vec.begin(),vec.end(),[] (std::shared_ptr<NepreklapajucaKugla> p1, std::shared_ptr<NepreklapajucaKugla> p2) {
       return p1->DajZapreminu()<p2->DajZapreminu(); 
    });
    std::for_each(vec.begin(),vec.end(),[] (std::shared_ptr<NepreklapajucaKugla> p) {p->Ispisi();});
    return 0;
}
