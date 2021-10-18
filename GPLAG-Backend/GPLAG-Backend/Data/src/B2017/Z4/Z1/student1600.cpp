/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <cmath>
#include <tuple>
#include <stdexcept>
#include <vector>
#include <memory>
#include <algorithm>

const double PI=4*std::atan (1);
const double Eps(1e-10);

class Kugla
{
    double X, Y, Z, R;

public:

    explicit Kugla (double r=0) {
        if(r<0) throw std::domain_error ("Ilegalan poluprecnik");
        X=0;
        Y=0;
        Z=0;
        R=r;
    }

    Kugla (double x, double y, double z, double r=0) {
        if(r<0) throw std::domain_error ("Ilegalan poluprecnik");
        X=x;
        Y=y;
        Z=z;
        R=r;
    }

    explicit Kugla (const std::tuple<double, double, double> &centar, double r=0) {
        if(r<0) throw std::domain_error ("Ilegalan poluprecnik");
        X=std::get<0>(centar);
        X=std::get<1>(centar);
        Z=std::get<2>(centar);
        R=r;
    }

    double DajX () const {
        return X;
    }

    double DajY () const {
        return Y;
    }

    double DajZ () const {
        return Z;
    }

    std::tuple<double, double,double> DajCentar () const {
        std::tuple<double, double, double> t (std::make_tuple(X, Y, Z));
        return t;
    }

    double DajPoluprecnik () const {
        return R;
    }

    double DajPovrsinu () const {
        return 4*R*R*PI;
    }

    double DajZapreminu () const {
        return 4*R*R*R*PI/3.;
    }

    Kugla &PostaviX (double x) {
        X=x;
        return *this;
    }

    Kugla &PostaviY (double y) {
        Y=y;
        return *this;
    }

    Kugla &PostaviZ (double z) {
        Z=z;
        return *this;
    }

    Kugla &PostaviCentar (double x, double y, double z) {
        X=x;
        Y=y;
        Z=z;
        return *this;
    }

    Kugla &PostaviCentar (const std::tuple<double, double, double> &centar) {
        X=std::get<0>(centar);
        Y=std::get<1>(centar);
        Z=std::get<2>(centar);
        return *this;
    }

    Kugla &PostaviPoluprecnik (double r) {
        if(r<0) throw std::domain_error ("Ilegalan poluprecnik");
        R=r;
        return *this;
    }

    void Ispisi () const {
        std::cout<<"{("<<X<<","<<Y<<","<<Z<<"),"<<R<<"}\n";
    }

    void Transliraj (double delta_x, double delta_y, double delta_z) {
        X+=delta_x;
        Y+=delta_y;
        Z+=delta_z;
    }

    friend bool DaLiSuIdenticne (const Kugla &k1, const Kugla &k2) {
        //if(k1.X==k2.X && k1.Y==k2.Y && k1.Z==k2.Z && k1.R==k2.R) return true;
        if(std::fabs(k1.X-k2.X)<Eps*(std::fabs(k1.X)+std::fabs(k2.X)) && std::fabs(k1.Y-k2.Y)<Eps*(std::fabs(k1.Y)+std::fabs(k2.Y)) && std::fabs(k1.Z-k2.Z)<Eps*(std::fabs(k1.Z)+std::fabs(k2.Z)) && std::fabs(k1.R-k2.R)<Eps*(std::fabs(k1.R)+std::fabs(k2.R))) return true;
        return false;
    }

    friend bool DaLiSuPodudarne (const Kugla &k1, const Kugla &k2) {
        // if(k1.R==k2.R) return true;
        if(std::fabs(k1.R-k2.R)<Eps*(std::fabs(k1.R)+std::fabs(k2.R))) return true;
        return false;
    }

    friend bool DaLiSuKoncentricne (const Kugla &k1, const Kugla &k2) {
        //if(k1.X==k2.X && k1.Y==k2.Y && k1.Z==k2.Z) return true;
        if(std::fabs(k1.X-k2.X)<Eps*(std::fabs(k1.X)+std::fabs(k2.X)) && std::fabs(k1.Y-k2.Y)<Eps*(std::fabs(k1.Y)+std::fabs(k2.Y)) && std::fabs(k1.Z-k2.Z)<Eps*(std::fabs(k1.Z)+std::fabs(k2.Z))) return true;
        return false;
    }

    friend bool DaLiSeDodirujuIzvana (const Kugla &k1, const Kugla &k2) {
        //if(k1.R+k2.R==std::sqrt(pow(k2.X-k1.X,2)+pow(k2.Y-k1.Y,2)+pow(k2.Z-k1.Z,2))) return true;
        if(std::fabs(k1.R+k2.R-std::sqrt(pow(k2.X-k1.X,2)+pow(k2.Y-k1.Y,2)+pow(k2.Z-k1.Z,2)))<Eps*(std::fabs(k1.R+k2.R)+std::fabs(std::sqrt(pow(k2.X-k1.X,2)+pow(k2.Y-k1.Y,2)+pow(k2.Z-k1.Z,2))))) return true;
        else return false;
    }

    friend bool DaLiSeDodirujuIznutra (const Kugla &k1, const Kugla &k2) {
        //if(std::sqrt(pow(k1.R-k2.R,2))==std::sqrt(pow(k2.X-k1.X,2)+pow(k2.Y-k1.Y,2)+pow(k2.Z-k1.Z,2))) return true;
        if(std::fabs(std::sqrt(pow(k1.R-k2.R,2))-std::sqrt(pow(k2.X-k1.X,2)+pow(k2.Y-k1.Y,2)+pow(k2.Z-k1.Z,2)))<Eps*(std::fabs(std::sqrt(pow(k1.R-k2.R,2))+std::fabs(std::sqrt(pow(k2.X-k1.X,2)+pow(k2.Y-k1.Y,2)+pow(k2.Z-k1.Z,2)))))) return true;
        return false;
    }

    friend bool DaLiSePreklapaju (const Kugla &k1, const Kugla &k2) {
        if(DaLiSeSijeku(k1, k2)) return true; /*Svake dvije kugle koje se sijeku također se i preklapaju, dok obrnuto ne mora vrijediti*/
        if(std::sqrt(pow(k2.X-k1.X,2)+pow(k2.Y-k1.Y,2)+pow(k2.Z-k1.Z,2))<k1.R+k2.R) return true;
        return false;
    }

    friend bool DaLiSeSijeku (const Kugla &k1, const Kugla &k2) {
        if(std::sqrt(pow(k2.X-k1.X,2)+pow(k2.Y-k1.Y,2)+pow(k2.Z-k1.Z,2))<k1.R+k2.R && std::sqrt(pow(k1.R-k2.R,2))<std::sqrt(pow(k2.X-k1.X,2)+pow(k2.Y-k1.Y,2)+pow(k2.Z-k1.Z,2))) return true;
        return false;
    }

    bool DaLiSadrzi (const Kugla &k) const {
        if(R>=std::sqrt(pow(k.X-X,2)+pow(k.Y-Y,2)+pow(k.Z-Z,2))+k.R) return true;
        return false;
    }
    /*bool DaLiSadrzi (const Kugla &k) const {
        if(R+k.R>std::sqrt(pow(k.X-X,2)+pow(k.Y-Y,2)+pow(k.Z-Z,2))) return true;
        return false;
    }*/

    friend double RastojanjeCentara (const Kugla &k1, const Kugla &k2) {
        return std::sqrt(pow(k2.X-k1.X,2)+pow(k2.Y-k1.Y,2)+pow(k2.Z-k1.Z,2));
    }
};

int main ()
{
    int n;
    std::cout<<"Unesite broj kugla: ";
    for(;;) {
        bool pom(true);
        std::cin>>n;
        if(!std::cin || n<=0)
            pom=false;
        if(pom) break;
        std::cout<<"Neispravan broj kugli, unesite ponovo!\n";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }

    std::vector<std::shared_ptr<Kugla>> v;

    for(int i=0; i<n; i++) {
        double x,y,z,r;
        for(;;) {
UNOS:
            std::cout<<"Unesite centar "<<i+1<<". kugle: ";
            bool pom_x(true), pom_y(true), pom_z(true), pom_r(true);
            std::cin>>x;
            if(!std::cin) pom_x=false;
            std::cin>>y;
            if(!std::cin) pom_y=false;
            std::cin>>z;
            if(!std::cin) pom_z=false;
            if(pom_x==false || pom_y==false || pom_z==false) {
                std::cout<<"Neispravan centar\n";
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                goto UNOS;
            }
            std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
            std::cin>>r;
            if(!std::cin || r<0) {
                pom_r=false;
                std::cout<<"Ilegalan poluprecnik\n";
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            }
            if(pom_x && pom_y && pom_z && pom_r) break;

        }
        try {
            auto pok=new Kugla(x,y,z,r);
            v.push_back(std::shared_ptr<Kugla>(pok));
        } catch (std::bad_alloc) {
            std::cout<<"Problem sa memorijom!";
        } catch (std::domain_error izuzetak) {
            std::cout<<izuzetak.what()<<std::endl;
        } catch(...) {}
    }

    double trans_x, trans_y, trans_z;
    std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    for(;;) {
        bool pom_x(true), pom_y(true), pom_z(true);

        std::cin>>trans_x;
        if(!std::cin) pom_x=false;

        std::cin>>trans_y;
        if(!std::cin) pom_y=false;

        std::cin>>trans_z;
        if(!std::cin) pom_z=false;

        if(pom_x && pom_y && pom_z) break;
        std::cout<<"Neispravni parametri translacije, unesite ponovo!\n";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }

    std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: \n";

    std::transform (v.begin(), v.end(), v.begin(), [trans_x, trans_y, trans_z] (const std::shared_ptr<Kugla> &k) {
        k->Transliraj (trans_x, trans_y, trans_z);
        return k;
    });

    std::sort (v.begin(), v.end(), [] (const std::shared_ptr<Kugla> &k1, const std::shared_ptr<Kugla> &k2) {
        return k1->DajZapreminu()<k2->DajZapreminu();
    });

    for_each(v.begin(), v.end(), [] (const std::shared_ptr<Kugla> &k)->void {k->Ispisi();});

    auto max_pov (max_element(v.begin(), v.end(), [](const std::shared_ptr<Kugla> &k1, const std::shared_ptr<Kugla> &k2)->bool {return k1->DajPovrsinu()<k2->DajPovrsinu();}));
    std::cout<<"Kugla sa najvecom povrsinom je: ";
    (*max_pov)->Ispisi();

    int brojac(0);
    for_each(v.begin(), v.end(), [&](const std::shared_ptr<Kugla> &k1) {
        for_each(v.begin(), v.end(), [&](const std::shared_ptr<Kugla> &k2) {
            if (&k2 > &k1 && DaLiSeSijeku(*k1, *k2)) {
                std::cout<<"Presjecaju se kugle: ";
                k1->Ispisi();
                k2->Ispisi();
                brojac++;
            }
        });
    });

    if(brojac==0)
        std::cout<<"Ne postoje kugle koje se presjecaju!";

    return 0;
}
