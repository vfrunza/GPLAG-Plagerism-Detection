/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <algorithm>
#include <utility>
#include <tuple>
#include <vector>
#include <memory>


static constexpr double e=std::pow(10,-10);

class Kugla
{
    double x,y,z,r;
    static constexpr double PI=4*std::atan(1);
public:
    explicit Kugla(double r = 0) {
        if(r<0) throw std::domain_error ("Ilegalan poluprecnik");
        Kugla::r=r;
    }
    Kugla(double x, double y, double z, double r = 0) {
        if(r<0) throw std::domain_error ("Ilegalan poluprecnik");
        Kugla::x=x;
        Kugla::y=y;
        Kugla::z=z;
        Kugla::r=r;
    }
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0) {
        if(r<0) throw std::domain_error ("Ilegalan poluprecnik");
        Kugla::x=std::get<0>(centar);
        Kugla::y=std::get<1>(centar);
        Kugla::z=std::get<2>(centar);
        Kugla::r=r;
    }
    double DajX() const {
        return Kugla::x;
    }
    double DajY() const {
        return Kugla::y;
    }
    double DajZ() const {
        return Kugla::z;
    }

    std::tuple<double, double, double> DajCentar() const {
        auto Centar(std::make_tuple(x,y,z));
        return Centar;

    }
    double DajPoluprecnik() const {
        return Kugla::r;
    }
    double DajPovrsinu() const {
        return 4*(PI)*r*r;
    }
    double DajZapreminu() const {
        return(4*r*r*r*(PI)/3);
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
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar) {
        Kugla::x=std::get<0>(centar);
        Kugla::y=std::get<1>(centar);
        Kugla::z=std::get<2>(centar);
        return *this;
    }
    Kugla &PostaviPoluprecnik(double r) {
        if(r<0) throw std::domain_error ("Ilegalan poluprecnik");
        Kugla::r=r;
        return *this;
    }
    void Ispisi() const {
        std::cout<<"{("<<DajX()<<","<<DajY()<<","<<DajZ()<<"),"<<DajPoluprecnik()<<"}"<<std::endl;
    }
    void Transliraj(double delta_x, double delta_y, double delta_z) {
        Kugla::x+=delta_x;
        Kugla::y+=delta_y;
        Kugla::z+=delta_z;
    }
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


bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2)
{
    if((k1.x-k2.x)<e && (k1.y-k2.y)<e && (k1.z-k2.z)<e && (k1.r-k2.r)<e) return true;
    return false;
}
bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2)
{
    if((k1.r-k2.r)<e) return true;
    return false;
}
bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2)
{
    if((k1.x-k2.x)<e && (k1.y-k2.y)<e && (k1.z-k2.z)<e) return true;
    return false;
}

bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2)
{
    if((RastojanjeCentara(k1,k2)-(k1.r+k2.r))<e) return true;
    return false;
}
bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2)
{
    if((RastojanjeCentara(k1,k2)-std::fabs(k1.r-k2.r))<e) return true;
    return false;
}

bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2)
{
    if(RastojanjeCentara(k1,k2)<(k1.r+k2.r)) return true;
    return false;
}
bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2)
{

    if(RastojanjeCentara(k1,k2)<(k1.r+k2.r)&& RastojanjeCentara(k1,k2)>std::fabs(k2.r-k1.r)) return true;
    return false;
}

double RastojanjeCentara(const Kugla &k1, const Kugla &k2)
{
    double rastojanje_centara;
    rastojanje_centara=std::sqrt((k2.x-k1.x)*(k2.x-k1.x)+(k2.y-k1.y)*(k2.y-k1.y)+(k2.z-k1.z)*(k2.z-k1.z));
    return rastojanje_centara;
}


int main ()
{
    int n;
    std::cout<<"Unesite broj kugla: ";
    for(;;) {
        std::cin >> n;
        if(std::cin && n>0) break;
        std::cout << "Neispravan broj kugli, unesite ponovo!\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    std::vector<std::shared_ptr<Kugla>> Kugle(n);
    double X,Y,Z,R;
    int brojac;
    for(int i=0; i<n; i++) {
        for(;;) {
            std::cout<<"Unesite centar "<<i+1<<". kugle: ";
            brojac=0;
            std::cin>>X;
            if(std::cin) brojac++;
            std::cin>>Y;
            if(std::cin) brojac++;
            std::cin>>Z;
            if(std::cin) brojac++;
            if(brojac==3) {
                std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
                std::cin>>R;
                if(std::cin && R>=0) break;
                std::cout<<"Ilegalan poluprecnik\n";
                std::cin.clear();
                std::cin.ignore(10000,'\n');
            } else if (brojac!=3) {
                std::cout << "Neispravan centar\n";
                std::cin.clear();
                std::cin.ignore(10000, '\n');
            }
        }
        Kugle[i]=std::make_shared<Kugla>(X,Y,Z,R);
    }
    std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double dx,dy,dz;
    int brojac2;
    for(;;) {
        brojac2=0;
        std::cin>>dx;
        if(std::cin) brojac2++;
        std::cin>>dy;
        if(std::cin) brojac2++;
        std::cin>>dz;
        if(std::cin) brojac2++;
        if(brojac2==3)break;
        std::cout<<"Neispravni parametri translacije, unesite ponovo!\n";
        std::cin.clear();
        std::cin.ignore(10000,'\n');
    }

    std::transform(Kugle.begin(),Kugle.end(),Kugle.begin(),[dx,dy,dz](std::shared_ptr<Kugla> a) {
        a->Transliraj(dx,dy,dz);
        return a;
    });
    std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: \n";

    std::sort(Kugle.begin(),Kugle.end(),[](std::shared_ptr<Kugla> a, std::shared_ptr<Kugla> b) {
        return a->DajZapreminu()<b->DajZapreminu();
    });
    std::for_each(Kugle.begin(),Kugle.end(),[](std::shared_ptr<Kugla> a) {
        a->Ispisi();
    });

    std::cout<<"Kugla sa najvecom povrsinom je: ";

    auto m=std::max_element(&Kugle[0],&Kugle[Kugle.size()],[](std::shared_ptr<Kugla> a, std::shared_ptr<Kugla> b) {
        return a->DajPovrsinu()<b->DajPovrsinu();
    });
    for(int i=0; i<n; i++) {
        if(*m==Trouglovi[i]) (*Trouglovi[i]).Ispisi();
    }

    int l(1);
    bool sijeku(true);
    std::for_each(Kugle.begin(),Kugle.end(),[&l,&Kugle, &sijeku](const std::shared_ptr<Kugla> &k) {
        std::for_each(Kugle.begin()+l,Kugle.end(),[&Kugle, &k, &sijeku](const std::shared_ptr<Kugla> &y) {
            if(DaLiSeSijeku(*k,*y)) {
                std::cout<<"Presjecaju se kugle: ";
                k->Ispisi();
                y->Ispisi();
                sijeku=false;
            }

        }
                     );
        l++;
    });
    if(sijeku) std::cout<<"Ne postoje kugle koje se presjecaju!";
    return 0;
}
