/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <tuple>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>

const double PI(4*std::atan(1));

class Kugla {
    double r,x,y,z;
    static bool JesuLiJednaki (double x, double y, double eps=1e-10) {return std::fabs(x-y)<=eps*(std::fabs(x)+std::fabs(y));}
public:
    explicit Kugla (double r=0) {PostaviPoluprecnik(r); PostaviCentar(0,0,0);}
    Kugla (double x, double y, double z, double r=0) {PostaviPoluprecnik(r); PostaviCentar(x,y,z);}
    explicit Kugla (const std::tuple<double,double,double> &centar, double r=0) {PostaviPoluprecnik(r); PostaviCentar(centar);}
    double DajX () const {return x;}
    double DajY () const {return y;}
    double DajZ () const {return z;}
    std::tuple<double,double,double> DajCentar() const {return std::make_tuple(x,y,z);}
    double DajPoluprecnik () const {return r;}
    double DajPovrsinu () const {return 4*PI*r*r;}
    double DajZapreminu () const {return (4*PI*r*r*r)/3;}
    Kugla &PostaviX (double x) {Kugla::x=x; return *this;}
    Kugla &PostaviY (double y) {Kugla::y=y; return *this;}
    Kugla &PostaviZ (double z) {Kugla::z=z; return *this;}
    Kugla &PostaviCentar (double x, double y, double z) {Kugla::x=x; Kugla::y=y; Kugla::z=z; return *this;}
    Kugla &PostaviCentar (const std::tuple<double,double,double> &centar) {x=std::get<0>(centar); y=std::get<1>(centar); z=std::get<2>(centar); return *this;}
    Kugla &PostaviPoluprecnik (double r) {if (r<0) throw std::domain_error ("Ilegalan poluprecnik"); Kugla::r=r; return *this;}
    void Ispisi () const {std::cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}\n";}
    void Transliraj (double delta_x, double delta_y, double delta_z) {x+=delta_x; y+=delta_y; z+=delta_z;}
    friend bool DaLiSuIdenticne (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuPodudarne (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuKoncentricne (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIzvana (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSePreklapaju (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeSijeku (const Kugla &k1, const Kugla &k2);
    bool DaLiSadrzi (const Kugla &k) const {return RastojanjeCentara(*this,k)<r-k.r || JesuLiJednaki(RastojanjeCentara(*this,k),r-k.r);}
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);
};

bool DaLiSuIdenticne (const Kugla &k1, const Kugla &k2)
{
    return Kugla::JesuLiJednaki(k1.x,k2.x) && Kugla::JesuLiJednaki(k1.y,k2.y) && Kugla::JesuLiJednaki(k1.z,k2.z) && Kugla::JesuLiJednaki(k1.r,k2.r);
}

bool DaLiSuPodudarne (const Kugla &k1, const Kugla &k2)
{
    return Kugla::JesuLiJednaki(k1.r,k2.r);
}

bool DaLiSuKoncentricne (const Kugla &k1, const Kugla &k2)
{
    return Kugla::JesuLiJednaki(k1.x,k2.x) && Kugla::JesuLiJednaki(k1.y,k2.y) && Kugla::JesuLiJednaki(k1.z,k2.z);
}

bool DaLiSeDodirujuIzvana (const Kugla &k1, const Kugla &k2)
{
    return Kugla::JesuLiJednaki(k1.r+k2.r,RastojanjeCentara(k1,k2));
}

double RastojanjeCentara (const Kugla &k1, const Kugla &k2)
{
    return std::sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z));
}

bool DaLiSeDodirujuIznutra (const Kugla &k1, const Kugla &k2)
{
    return Kugla::JesuLiJednaki(std::fabs(k1.r-k2.r),RastojanjeCentara(k1,k2)) && (!DaLiSuIdenticne(k1,k2) || (Kugla::JesuLiJednaki(k1.r,0) && Kugla::JesuLiJednaki(k2.r,0)));
}

bool DaLiSePreklapaju (const Kugla &k1, const Kugla &k2)
{
    return DaLiSuIdenticne(k1,k2) || DaLiSeSijeku(k1,k2) || RastojanjeCentara(k1,k2)<std::fabs(k1.r-k2.r) || Kugla::JesuLiJednaki(RastojanjeCentara(k1,k2),std::fabs(k1.r-k2.r));
}

bool DaLiSeSijeku (const Kugla &k1, const Kugla &k2)
{
    return (RastojanjeCentara(k1,k2)<k1.r+k2.r && RastojanjeCentara(k1,k2)>std::fabs(k1.r-k2.r)) || (DaLiSuIdenticne(k1,k2) && !Kugla::JesuLiJednaki(k1.r,0));
}

int main ()
{
    int n;
    std::cout<<"Unesite broj kugla: ";
    while (std::cin>>n,!std::cin || n<=0)
    {
        std::cin.clear(); std::cin.ignore(10000,'\n');
        std::cout<<"Neispravan broj kugli, unesite ponovo!\n";
    }
    std::vector<std::shared_ptr<Kugla>> vec(n);
    for (int i=0;i<n;i++)
    {
        double x,y,z,r;
        try
        {
            std::cout<<"Unesite centar "<<i+1<<". kugle: ";
            std::cin>>x>>y>>z;
            if (!std::cin) throw "";
            std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
            std::cin>>r;
            if (!std::cin) throw std::domain_error ("Ilegalan poluprecnik");
            vec[i]=std::make_shared<Kugla> (x,y,z,r);
        }
        catch (std::domain_error izuz)
        {
            std::cout<<izuz.what()<<"\n";
            --i;
            std::cin.clear();
            std::cin.ignore(10000,'\n');
        }
        catch (...)
        {
            std::cout<<"Neispravan centar\n";
            --i; std::cin.clear();
            std::cin.ignore(10000,'\n');
        }
    }
    double delta_x,delta_y,delta_z;
    std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    while (std::cin>>delta_x>>delta_y>>delta_z,!std::cin)
    {
        std::cin.clear (); std::cin.ignore(10000,'\n');
        std::cout<<"Neispravni parametri translacije, unesite ponovo!\n";
    }
    std::transform(vec.begin(),vec.end(),vec.begin(),[delta_x,delta_y,delta_z] (std::shared_ptr<Kugla> pok) 
    {
        pok->Transliraj(delta_x,delta_y,delta_z);
        return pok;
    });
    std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: \n";
    std::sort(vec.begin(),vec.end(),[] (std::shared_ptr<Kugla> p1, std::shared_ptr<Kugla> p2) {
       return p1->DajZapreminu()<p2->DajZapreminu(); 
    });
    std::for_each(vec.begin(),vec.end(),[] (std::shared_ptr<Kugla> p) {p->Ispisi();});
    auto pok(std::max_element(vec.begin(),vec.end(),[](std::shared_ptr<Kugla> p1, std::shared_ptr<Kugla> p2) {return p1->DajPovrsinu()<p2->DajPovrsinu();}));
    std::cout<<"Kugla sa najvecom povrsinom je: ";
    (*pok)->Ispisi();
    bool presjek(false); int i(0);
    std::for_each(vec.begin(),vec.end(),[&i,vec,&presjek](std::shared_ptr<Kugla> p)
    {
        std::for_each (vec.begin()+i, vec.end(), [p,&presjek] (std::shared_ptr<Kugla> q) {
            if (p!=q && DaLiSeSijeku(*p,*q))
            {
                presjek=true;
                std::cout<<"Presjecaju se kugle: ";
                p->Ispisi(); q->Ispisi();
            }
        });
        ++i;
    });
    if(!presjek)
    std::cout<<"Ne postoje kugle koje se presjecaju!";
    return 0;
}
