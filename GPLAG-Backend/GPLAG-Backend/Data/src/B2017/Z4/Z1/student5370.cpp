/B2017/2018: Zadaća 4, Zadatak 1
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
class Kugla
{
    double x, y, z, r;
public:
    explicit Kugla(double r = 0);
    Kugla(double x, double y, double z, double r = 0);
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0);
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
        return 4*r*r*atan(1)*4;
    }
    double DajZapreminu() const {
        return ((4.0/3.0)*r*r*r*atan(1)*4);
    }
    Kugla &PostaviX(double x) {
        Kugla::x=x;
        return *this;
    }
    Kugla &PostaviY(double y) {
        Kugla::y=y;
        return *this;
    }
    Kugla &PostaviZ(double z) {
        Kugla::z=z;
        return *this;
    }
    Kugla &PostaviCentar(double x, double y, double z) {
        Kugla::x=x;
        Kugla::y=y;
        Kugla::z=z;
        return *this;
    }
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar);
    Kugla &PostaviPoluprecnik(double r);
    void Ispisi() const {
        std::cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}";
    } 
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
    if (r>=0) {
        x=0;
        y=0;
        z=0;
        Kugla::r=r;
    } else {
        throw std::domain_error ("Ilegalan poluprecnik");
    }
}
Kugla::Kugla(double x, double y, double z, double r)
{
    if (r>=0) {
        Kugla::x=x;
        Kugla::y=y;
        Kugla::z=z;
        Kugla::r=r;
    } else {
        throw std::domain_error ("Ilegalan poluprecnik");
    }
}
Kugla::Kugla(const std::tuple<double, double, double> &centar, double r)
{
    if(r<0)
        throw std::domain_error("Ilegalan poluprecnik");
    x=std::get<0>(centar);
    y=std::get<1>(centar);
    z=std::get<2>(centar);
    Kugla::r=r;
}
Kugla &Kugla::PostaviCentar(const std::tuple<double, double, double> &centar)
{
    x=std::get<0>(centar);
    y=std::get<1>(centar);
    z=std::get<2>(centar);
    return *this;
}
Kugla &Kugla::PostaviPoluprecnik(double r)
{
    if (r>=0) Kugla::r=r;
    else throw std::domain_error ("Ilegalan poluprecnik");
    return *this;
}
void Kugla::Transliraj(double delta_x, double delta_y, double delta_z)
{
    x+=delta_x;
    y+=delta_y;
    z+=delta_z;
}
bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2)
{
    if (fabs(k1.x-k2.x)<e && fabs(k1.y-k2.y)<e && fabs(k1.z-k2.z)<e && fabs(k1.r-k2.r)<e) return true;
    else return false;
}
bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2)
{
    if (fabs(k1.r-k2.r)<e) return true;
    else return false;
}
bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2)
{
    if (fabs(k1.x-k2.x)<e && fabs(k1.y-k2.y)<e && fabs(k1.z-k2.z)<e) return true;
    else return false;
}

bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2)
{
    double d (sqrt(pow(k2.x-k1.x,2)+pow(k2.y-k1.y,2)+pow(k2.z-k1.z,2)));
    return (fabs(d-(fabs(k1.r)+fabs(k2.r)))<e);
}
bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2)
{
    double d (sqrt(pow(k2.x-k1.x,2)+pow(k2.y-k1.y,2)+pow(k2.z-k1.z,2)));
    return (fabs(d-fabs(k1.r-k2.r))<e);
}
bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2)
{
    double d (sqrt(pow(k2.x-k1.x,2)+pow(k2.y-k1.y,2)+pow(k2.z-k1.z,2)));
    return (d<k1.r+k2.r&&d>fabs(k1.r-k2.r));
}
bool Kugla::DaLiSadrzi(const Kugla &k) const
{
    double d (sqrt(pow(k.x-x,2)+pow(k.y-y,2)+pow(k.z-z,2)));
    return (d-fabs(k.r-r))<0;
}
double RastojanjeCentara(const Kugla &k1, const Kugla &k2)
{
    double d (sqrt(pow(k2.x-k1.x,2)+pow(k2.y-k1.y,2)+pow(k2.z-k1.z,2)));
    return d;
}
int main ()
{
    try {
        int n;
        std::cout<<"Unesite broj kugla: ";
        do {
            std::cin>>n;
            if (n<=0 || !std::cin) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;
            }
        } while (n<=0 || !std::cin);
        std::vector<std::shared_ptr<Kugla>> pok (n,nullptr);
        for (int i=0; i<n; i++) {
            double x,y,z,r;
            bool greska (false);
            do {
                greska=false;
                std::cout<<"Unesite centar "<<i+1<<". kugle: ";
                std::cin>>x>>y>>z;
                if (!std::cin) {
                    greska=true;
                    std::cin.clear();
                    std::cin.ignore(1000,'\n');
                    std::cout<<"Neispravan centar"<<std::endl;
                    continue;
                }
                greska=false;
                std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
                std::cin>>r;
                if (!std::cin || r<0) {
                    greska=true;
                    std::cin.clear();
                    std::cin.ignore(1000,'\n');
                    std::cout<<"Ilegalan poluprecnik"<<std::endl;
                    continue;
                }
            } while (greska);
            pok[i]=std::make_shared<Kugla>(x,y,z,r);
        }
        double delta_x,delta_y,delta_z;
        std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
        bool greska=false;
        do {
            greska=false;
            std::cin>>delta_x>>delta_y>>delta_z;
            if (!std::cin) {
                greska=true;
                std::cout<<"Neispravni parametri translacije, unesite ponovo!"<<std::endl;
                std::cin.clear();
                std::cin.ignore();
                continue;
            }
        } while(greska);
        std::transform(pok.begin(), pok.end(), pok.begin(), [delta_x, delta_y, delta_z] (std::shared_ptr<Kugla> k) {
            k->Transliraj(delta_x,delta_y,delta_z);
            return k;
        });
        std::sort(pok.begin(), pok.end(), [] (std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2){
            return k1->DajZapreminu()<k2->DajZapreminu();
        });
        std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<std::endl;
        std::for_each(pok.begin(), pok.end(), [] (std::shared_ptr<Kugla> k){
            k->Ispisi();
            std::cout<<std::endl;
        });
        Kugla max(**std::max_element(pok.begin(), pok.end(), [](std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2){
        return k1->DajPovrsinu()<k2->DajPovrsinu();}));
        std::cout<<"Kugla sa najvecom povrsinom je: ";
        max.Ispisi();
        std::cout<<std::endl;
        int brojac(0);
        std::vector<std::pair<std::shared_ptr<Kugla>,std::shared_ptr<Kugla>>> jednaki_parovi;
        std::for_each(pok.begin(), pok.end(), [pok, &brojac, &jednaki_parovi] (std::shared_ptr<Kugla> prva_k){
            std::for_each(pok.begin(), pok.end(), [prva_k, &brojac, &jednaki_parovi] (std::shared_ptr<Kugla> druga_k){
                if (prva_k==druga_k) return;
                else if (DaLiSeSijeku(*prva_k,*druga_k)) {
                    for(int i=0;i<jednaki_parovi.size();i++){
                        if((prva_k==jednaki_parovi.at(i).first&&druga_k==jednaki_parovi.at(i).second)||(prva_k==jednaki_parovi.at(i).second&&druga_k==jednaki_parovi.at(i).first))
                            return;
                    }
                    brojac++;
                    jednaki_parovi.push_back(std::make_pair(prva_k,druga_k));
                }
            });
        });
        std::for_each(jednaki_parovi.begin(),jednaki_parovi.end(), [] (std::pair<std::shared_ptr<Kugla>,std::shared_ptr<Kugla>> par){
           std::cout<<"Presjecaju se kugle: ";
           par.first->Ispisi();
           std::cout<<std::endl;
           par.second->Ispisi();
           std::cout<<std::endl;
        });
        if (brojac==0) std::cout<<"Ne postoje kugle koje se presjecaju!";
    } catch(std::domain_error e) {
        std::cout<<e.what();
    } catch(...){
        
    }

    return 0;
}
