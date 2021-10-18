/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <vector>
#include <cmath>
#include <memory>
#include <algorithm>

const double PI = atan(1) * 4;
const double eps = pow(10,-10);
bool Jednak(double x, double y)
{
    return(sqrt((x-y)*(x-y)) < eps*(sqrt(x*x)+sqrt(y*y)));
}

class Kugla
{
    double x, y, z, p;
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
    x=0;
    y=0;
    z=0;
}
Kugla::Kugla(double x, double y, double z, double r) 
{
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    Kugla::x=x;
    Kugla::y=y;
    Kugla::z=z;
    Kugla::p=r;
}
Kugla::Kugla(const std::tuple<double, double, double> &centar, double r) 
{
    double x, y, z;
    std::tie(x,y,z)=centar;
    Kugla::p=r;
}
double Kugla::DajX() const {return Kugla::x;}
double Kugla::DajY() const {return Kugla::y;}
double Kugla::DajZ() const {return Kugla::z;}
std::tuple<double, double, double> Kugla::DajCentar() const
{
    return std::make_tuple(Kugla::DajX(), Kugla::DajY(), Kugla::DajZ());
}
double Kugla::DajPoluprecnik() const {return Kugla::p;}
double Kugla::DajPovrsinu() const {return 4.*PI*Kugla::DajPoluprecnik()*Kugla::DajPoluprecnik();}
double Kugla::DajZapreminu() const {return (4./3)*PI*Kugla::DajPoluprecnik()*Kugla::DajPoluprecnik()*Kugla::DajPoluprecnik();}
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
    Kugla::p=r;
    return *this;
}
void Kugla::Ispisi() const
{
    std::cout << "{(" << Kugla::DajX() << "," <<  Kugla::DajY() << "," <<  Kugla::DajZ() << ")," << Kugla::DajPoluprecnik() << "}" << std::endl;
}
void Kugla::Transliraj(double delta_x, double delta_y, double delta_z)
{
    x+=delta_x;
    y+=delta_y;
    z+=delta_z;
}
bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2)
{
    return(Jednak(k1.x, k2.x) && Jednak(k1.y, k2.y) && Jednak(k1.z, k2.z) && Jednak(k1.p, k2.p));
}
bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2)
{
    return Jednak(k1.p, k2.p);
}
bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2)
{
    return(Jednak(k1.x, k2.x) && Jednak(k1.y, k2.y) && Jednak(k1.z, k2.z));
}
bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2)
{
    double d(std::sqrt(std::pow(k1.x-k2.x,2) + std::pow(k1.y-k2.y,2) + std::pow(k1.z-k2.z, 2)));
    return Jednak(std::fabs(d), std::fabs(k1.p+k2.p));
}
bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2)
{
    double d(std::sqrt(std::pow(k1.x-k2.x,2)+std::pow(k1.y-k2.y,2)+ std::pow(k1.z-k2.z, 2)));
    if(DaLiSeDodirujuIzvana(k1,k2)) return false;
    return Jednak(d, std::fabs(k1.p - k2.p));
}
bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2)
{
    if(DaLiSeSijeku(k1,k2) == true && !(RastojanjeCentara(k1,k2) > std::fabs(k1.p+k2.p))) return true;
    return false;
}
bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2)
{
    double d(sqrt(pow(k1.x-k2.x,2)+pow(k1.y-k2.y,2)+ pow(k1.z-k2.z, 2)));
    if(std::fabs(k2.p-k1.p) < std::fabs(d) && std::fabs(d) < k1.p+k2.p) return true;
    return false;
}
bool Kugla::DaLiSadrzi(const Kugla &k) const
{
    double d(std::sqrt((std::fabs(std::pow(x-k.x,2) + std::pow(y-k.y,2) + std::pow(z-k.z,2)))));
    if(d<std::fabs(p-k.p) && !DaLiSeSijeku(*this, k)) return true;
    return false;
}
double RastojanjeCentara(const Kugla &k1, const Kugla &k2)
{
    return sqrt(pow(k1.x-k2.x,2)+pow(k1.y-k2.y,2)+pow(k1.z-k2.z,2));
}
int main ()
{
    std::cout << "Unesite broj kugla: ";
    int n;
    while(1)
    {
        try{
            std::cin >> n;
            if(!std::cin || n<1)throw std::domain_error("Neispravan broj kugli, unesite ponovo!");
            else break;
        }
        catch(std::domain_error izuzetak)
        {
            std::cout << izuzetak.what() << std::endl;
            std::cin.clear();
            std::cin.ignore(10000,'\n');
        }
    }
    Kugla k;
    std::vector<std::shared_ptr<Kugla>> v(n);
    for(int i=0; i<n; i++)
    {
        double x, y, z;
        while(1)
        {   
            std::cout << "Unesite centar " << i+1 << ". kugle: ";
            try{
                std::cin >> x >> y >> z;
                if(!std::cin)throw std::domain_error("Neispravan centar");
                else break;
            }
            catch(std::domain_error izuzetak)
            {
                std::cout << izuzetak.what() << std::endl;
                std::cin.clear();
                std::cin.ignore(10000,'\n');
            }
        }
        k.PostaviX(x);
        k.PostaviY(y);
        k.PostaviZ(z);
        try{
            std::cout << "Unesite poluprecnik " << i+1 << ". kugle: ";
            double r;
            std::cin >> r;
            if(!std::cin)throw std::domain_error("Ilegalan poluprecnik");
            k.PostaviPoluprecnik(r);
        }
        catch(std::domain_error izuzetak)
        {
            std::cout << izuzetak.what() << std::endl;
            i--;
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            continue;
        }
        v[i]=std::make_shared<Kugla>(k);
    }
    std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double x, y, z;
    while(1)
    {   
        try{
            std::cin >> x >> y >> z;
            if(!std::cin)throw std::domain_error("Neispravni parametri translacije, unesite ponovo!");
            else break;
        }
        catch(std::domain_error izuzetak)
        {
            std::cout << izuzetak.what() << std::endl;
            std::cin.clear();
            std::cin.ignore(10000,'\n');
        }
    }
    std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: " << std::endl;
    std::transform(v.begin(), v.end(), v.begin(), [x,y,z](std::shared_ptr<Kugla> &p){p->Kugla::Transliraj(x,y,z); return p;});
    std::sort(v.begin(), v.end(), [](const std::shared_ptr<Kugla> &p1, const std::shared_ptr<Kugla> &p2) { return p1->Kugla::DajZapreminu()<p2->Kugla::DajZapreminu();});
    std::for_each(v.begin(), v.end(), [](const std::shared_ptr<Kugla> &p){p->Kugla::Ispisi();});
    std::cout << "Kugla sa najvecom povrsinom je: ";
    auto it = *std::max_element(v.begin(), v.end(), [](const std::shared_ptr<Kugla> &p1, const std::shared_ptr<Kugla> &p2) { return p1->Kugla::DajPovrsinu()<p2->Kugla::DajPovrsinu();});
    it->Ispisi();
    bool presjek(false);
    int poc(0);
    std::for_each(v.begin(), v.end(), [&poc, v, &presjek](const std::shared_ptr<Kugla> &p1)
    { 
        poc++;
        std::for_each(v.begin()+poc, v.end(), [p1, &presjek](const std::shared_ptr<Kugla> &p2)
        {
            if(DaLiSeSijeku(*p1, *p2))
            {
                std::cout << "Presjecaju se kugle: ";
                p1->Ispisi();
                p2->Ispisi();
                presjek=true;
            }
        });
    });
    if(presjek==false) std::cout << "Ne postoje kugle koje se presjecaju!" << std::endl;
    return 0;
}
