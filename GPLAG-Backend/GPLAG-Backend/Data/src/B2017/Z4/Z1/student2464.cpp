/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <tuple>
#include <cmath>
#include <vector>
#include <stdexcept>
#include <memory>
#include <algorithm>
#include <set>
#include <utility>
#include <map>
#include <type_traits>

#define PI 4*atan(1)
#define e pow(10, -10)
bool Jednakost(double x, double y)
{
    return std::abs(x-y)<e*(std::abs(x) + std::abs(y));
}
bool Jednakost(std::tuple<double, double, double> c1, std::tuple<double, double, double> c2)
{
    double x1=std::get<0>(c1);
    double y1=std::get<1>(c1);
    double z1=std::get<2>(c1);
    double x2=std::get<0>(c2);
    double y2=std::get<1>(c2);
    double z2=std::get<2>(c2);
    return ((std::abs(x1-x2)<e*(std::abs(x1) + std::abs(x2))) && (std::abs(y1-y2)<e*(std::abs(y1) + std::abs(y2)))&& (std::abs(z1-z2)<e*(std::abs(z1) + std::abs(z2))));
}


class Kugla
{
    double X, Y, Z, R;

public:

    //konstruktori
    explicit Kugla (double r = 0) {
        if(r<0) throw std::domain_error ("Ilegalan poluprecnik");
        X=0;
        Y=0;
        Z=0;
        R=r;
    }
    Kugla(double x, double y, double z, double r = 0) {
        if(r<0) throw std::domain_error ("Ilegalan poluprecnik");
        X=x;
        Y=y;
        Z=z;
        R=r;
    }
    explicit Kugla (const std::tuple<double, double, double> &centar, double r = 0) {
        if(r<0) throw std::domain_error ("Ilegalan poluprecnik");
        X=std::get<0>(centar);
        Y=std::get<1>(centar);
        Z=std::get<2>(centar);
        R=r;
    }

    //geteri
    double DajX() const {
        return X;
    }
    double DajY() const {
        return Y;
    }
    double DajZ() const {
        return Z;
    }
    const std::tuple<double, double, double> DajCentar() const {
        auto c = std::make_tuple (X, Y, Z);
        return c;
    }
    double DajPoluprecnik() const {
        return R;
    }
    double DajPovrsinu() const {
        return (4.* R * R * PI);
    }
    double DajZapreminu() const {
        return ((4./3 )* R * R * R * PI);
    }

    //seteri
    Kugla &PostaviX (double x) {
        X = x;
        return *this;
    }
    Kugla &PostaviY (double y) {
        Y = y;
        return *this;
    }
    Kugla &PostaviZ (double z) {
        Z = z;
        return *this;
    }
    Kugla &PostaviCentar (double x, double y, double z) {
        X = x;
        Y = y;
        Z = z;
        return *this;
    }
    Kugla &PostaviCentar (const std::tuple<double, double, double> &centar) {
        X = std::get<0>(centar);
        Y = std::get<1>(centar);
        Z = std::get<2>(centar);
        return *this;
    }
    Kugla &PostaviPoluprecnik (double r) {
        if(r<0) throw std::domain_error ("Ilegalan poluprecnik");
        R = r;
        return *this;
    }

    //ispis i friend fje
    void Ispisi() const {
        std::cout<<  "{(" << DajX() << "," << DajY() << "," << DajZ() << "),"<< DajPoluprecnik() << "}";
    }

    void Transliraj (double delta_x, double delta_y, double delta_z) {
        X+=delta_x;
        Y+=delta_y;
        Z+=delta_z;
    }
    friend bool DaLiSuIdenticne (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuPodudarne (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuKoncentricne (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIzvana (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSePreklapaju (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeSijeku (const Kugla &k1, const Kugla &k2);
    bool DaLiSadrzi(const Kugla &k) const {
        if(DaLiSePreklapaju(*this, k) && !(DaLiSeSijeku(*this,k))) return true;
        return false;
    }
    friend double RastojanjeCentra (const Kugla &k1, const Kugla &k2);

};

bool DaLiSuIdenticne (const Kugla &k1, const Kugla &k2)
{
    if(Jednakost(k1.DajCentar(),k2.DajCentar()) && Jednakost(k1.DajPoluprecnik(),k2.DajPoluprecnik())) return true;
    return false;
}

bool DaLiSuPodudarne (const Kugla &k1, const Kugla &k2)
{
    if (Jednakost(k1.DajPoluprecnik(),k2.DajPoluprecnik())) return true;
    return false;
}

bool DaLiSuKoncentricne (const Kugla &k1, const Kugla &k2)
{
    if(Jednakost(k1.DajCentar(),k2.DajCentar())) return true;
    return false;
}

bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2)
{
    if(Jednakost(RastojanjeCentra(k1,k2), (k1.DajPoluprecnik()+k2.DajPoluprecnik()))) return true;
    return false;
}
bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2)
{
    if(Jednakost(RastojanjeCentra(k1,k2), std::abs(k1.DajPoluprecnik()-k2.DajPoluprecnik()))) return true;
    return false;
}

bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2)
{
    if(std::abs(k1.DajPoluprecnik()-k2.DajPoluprecnik()) < RastojanjeCentra(k1,k2) &&
            RastojanjeCentra(k1,k2)<(k1.DajPoluprecnik()+k2.DajPoluprecnik())) return true;
    return false;
}


bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2)
{
    if(DaLiSeSijeku(k1,k2) || k1.DaLiSadrzi(k2) || k2.DaLiSadrzi(k1)) return true;
    return false;
}

double RastojanjeCentra(const Kugla &k1, const Kugla &k2)
{
    return sqrt( (k1.DajX()-k2.DajX())*(k1.DajX()-k2.DajX()) + (k1.DajY()-k2.DajY())*(k1.DajY()-k2.DajY()) + (k1.DajZ()-k2.DajZ())*(k1.DajZ()-k2.DajZ()));
}



int main ()
{

    int n;
    double x, y, z, r;
    std::cout<<"Unesite broj kugla: ";
    do {
        std::cin>>n;
        if(!std::cin) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;
            continue;
        }
        if(n<=0) std::cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;
        if(n>0) break;
    } while(1);
    std::vector<std::shared_ptr<Kugla>> v;
    for (int i=0; i<n; i++) {
        std::cout<<"Unesite centar "<<i+1<<". kugle: ";
        std::cin>>x >> y >>z;
        if(!std::cin) {
            std::cout<<"Neispravan centar"<<std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            i--;
            continue;
        }

        std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";;
        std::cin>> r;
        if(!std::cin || r<0) {
            std::cout<<"Ilegalan poluprecnik"<<std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            i--;
            continue;
        }
        try {
            auto pok = std::make_shared<Kugla>(x,y,z,r);
            v.push_back(pok);
        } catch(std::domain_error izuzetak) {
            std::cout<<izuzetak.what()<<std::endl;
            i--;
            continue;
        }


    }
    double dx, dy, dz;
    std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    for(;;){
    std::cin >> dx>> dy>>dz;
    if(!std::cin || dx<0 ||dy<0 ||dz<0) {
         std::cin.clear();
            std::cin.ignore(1000, '\n');
        std::cout<<"Neispravni parametri translacije, unesite ponovo!"<<std::endl;
    }
    else break;
    }

    std::transform (v.begin(), v.end(), v.begin(), [dx,dy,dz](std::shared_ptr<Kugla> pok) {
        pok->Transliraj(dx, dy, dz);
        return pok;
    });
    std::sort(v.begin(), v.end(), [](std::shared_ptr<Kugla> p1, std::shared_ptr<Kugla> p2) {
        return p1->DajZapreminu() < p2 -> DajZapreminu();
    } );
    std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<std::endl;
    std::for_each(v.begin(), v.end(), [](std::shared_ptr<Kugla> pok) {
        pok->Ispisi();
        std::cout<<std::endl;
    });
    //std::sort(v.begin(), v.end(), [](std::shared_ptr<Kugla> p1, std::shared_ptr<Kugla> p2){ return p1->DajPovrsinu() < p2 -> DajPovrsinu();} );
    auto poks=std::max_element(v.begin(), v.end(), [](std::shared_ptr<Kugla> p1, std::shared_ptr<Kugla> p2 ) {
        return p1->DajPovrsinu() < p2->DajPovrsinu();
    });
    std::cout<<"Kugla sa najvecom povrsinom je: ";
    (*poks)->Ispisi();
    std::cout<<std::endl;

    bool Istina(true);


    std::for_each(v.begin(), v.end(), [v, &Istina](std::shared_ptr<Kugla> p1) {
        bool logicka(false);
        std::for_each(v.begin(), v.end(), [p1, &Istina, &logicka](std::shared_ptr<Kugla> p2) {
            if(p1==p2) logicka=true;
            if (logicka) {
                if ( DaLiSeSijeku(*p1,*p2) && !DaLiSuIdenticne(*p1, *p2)) {

                    Istina=false;
                    std::cout <<"Presjecaju se kugle: ";
                    p1->Ispisi();
                    std::cout<<std::endl;
                    p2->Ispisi();
                    std::cout<<std::endl;
                }
            }
        });
    });
    if (Istina) std::cout<<"Ne postoje kugle koje se presjecaju!";




    return 0;
}
