#include <iostream>
#include <tuple>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>

static constexpr double PI=4*atan(1.);

bool IsteTacke (const double &a, const double &b)
{
    if(a==(int)a && b==(int)b) return a==b;
    double eps(std::pow(10 , -10));
    return std::sqrt((a-b)*(a-b))<(eps*(std::sqrt(a*a)+std::sqrt(b*b)));
}

class Kugla
{
    double x, y, z, r;
public:
    explicit Kugla (double r=0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        x=0;
        y=0;
        z=0;
    };
    Kugla (double x, double y, double z, double r=0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::x=x;
        Kugla::y=y;
        Kugla::z=z;
        Kugla::r=r;
    };
    explicit Kugla (const std::tuple<double, double, double> &centar, double r=0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        double a, b, c;
        std::tie(a,b,c)=centar;
        Kugla::x=a;
        Kugla::y=b;
        Kugla::z=c;
        Kugla::r=r;
    };
    double DajX() const {
        return x;
    };
    double DajY() const {
        return y;
    };
    double DajZ() const {
        return z;
    };
    std::tuple<double, double, double> DajCentar() const {
        double a(x), b(y), c(z);
        return std::tie<double, double, double>(a, b, c);
    };
    double DajPoluprecnik() const {
        return r;
    };
    double DajPovrsinu() const {
        return 2*PI*r*r;
    };
    double DajZapremninu() const {
        return 4/3*r*r*r*PI;
    };
    Kugla &PostaviX(double x) {
        Kugla::x=x;
        return *this;
    };
    Kugla &PostaviY(double y) {
        Kugla::y=y;
        return *this;
    };
    Kugla &PostaviZ(double z) {
        Kugla::z=z;
        return *this;
    };
    Kugla &PostaviCentar(double x, double y, double z) {
        Kugla::x=x;
        Kugla::y=y;
        Kugla::z=z;
        return *this;
    };
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar);
    Kugla &PostaviPoluprecnik(double r) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::r=r;
        return *this;
    };
    void Ispisi() const {
        std::cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}"<<std::endl;
    };
    void Transliraj (double delta_x, double delta_y, double delta_z) {
        x+=delta_x;
        y+=delta_y;
        z+=delta_z;
    };
    friend bool DaLiSuIdenticne (const Kugla &k1, const Kugla &k2) ;
    friend bool DaLiSuPodudarne (const Kugla &k1, const Kugla &k2) ;
    friend bool DaLiSuKoncentricne (const Kugla &k1, const Kugla &k2) ;
    friend bool DaLiSeDodirujuIzvana (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSePreklapaju (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeSjeku(const Kugla &k1, const Kugla &k2);
    bool DaLiSadrzi (const Kugla &k) const;
    friend double RastojanjeCentara (const Kugla &k1, const Kugla &k2);
};

bool DaLiSuIdenticne (const Kugla &k1, const Kugla &k2)
{
    return (IsteTacke(k1.x, k2.x) && IsteTacke(k1.y, k2.y)
            && IsteTacke(k1.z, k2.z) && IsteTacke(k1.r, k2.r));
}

bool DaLiSuPodudarne (const Kugla &k1, const Kugla &k2)
{
    return IsteTacke(k1.r, k2.r);
}

bool DaLiSuKoncentricne (const Kugla &k1, const Kugla &k2)
{
    return IsteTacke(k1.x, k2.x) && IsteTacke(k1.y, k2.y) && IsteTacke(k1.z, k2.z);
}

bool DaLiSeDodirujuIznutra (const Kugla &k1, const Kugla &k2)
{
    double veci, manji;
    if(k1.r>k2.r) {
        veci=k1.r;
        manji=k2.r;
    } else {
        veci=k2.r;
        manji=k1.r;
    }
    return (RastojanjeCentara(k1,k2)==std::sqrt((veci-manji)*(veci-manji)));
}

bool DaLiSeDodirujuIzvana (const Kugla &k1, const Kugla &k2)
{
    return (RastojanjeCentara(k1, k2)==k1.r+k2.r);
}

bool DaLiSePreklapaju (const Kugla &k1, const Kugla &k2)                        // da li unutrasnjosti dvije kugle, bez rubova imaju zajednickih tacaka
{
    return (DaLiSeSjeku(k1, k2) || k1.DaLiSadrzi(k2) || k2.DaLiSadrzi(k1) ||
            DaLiSeDodirujuIznutra(k1, k2));
}

bool DaLiSeSjeku (const Kugla &k1, const Kugla &k2)
{
    double veci(0), manji(0);
    if(k1.r>k2.r) {
        veci=k1.r;
        manji=k2.r;
    } else {
        veci=k2.r;
        manji=k1.r;
    }
    return (RastojanjeCentara(k1, k2)<(k1.r+k2.r) &&
            RastojanjeCentara(k1, k2)>std::sqrt((veci-manji)*(veci-manji)) &&
            DaLiSeDodirujuIznutra(k1, k2)==false &&
            DaLiSeDodirujuIzvana(k1, k2)==false);
}

bool Kugla::DaLiSadrzi (const Kugla &k) const
{
    //da li kugla nad kojoj je pozvana metoda sadrzi kuglu k
    return RastojanjeCentara(*this, k)<std::sqrt((r-k.DajPoluprecnik())*(r-k.DajPoluprecnik())) ||
           DaLiSuIdenticne(*this, k) || 
           RastojanjeCentara(*this, k)==std::sqrt((this->DajPoluprecnik()-k.DajPoluprecnik())*(this->DajPoluprecnik()-k.DajPoluprecnik()));  
}

Kugla &Kugla::PostaviCentar(const std::tuple<double, double, double> &centar)
{
    double a, b, c;
    std::tie(a,b,c)=centar;
    Kugla::x=a;
    Kugla::y=b;
    Kugla::z=c;
    return *this;
}

double RastojanjeCentara (const Kugla &k1, const Kugla &k2)
{
    return std::sqrt((k2.x-k1.x)*(k2.x-k1.x)+(k2.y-k1.y)*(k2.y-k1.y)
                     +(k2.z-k1.z)*(k2.z-k1.z));
}

int main ()
{
    int n;
    std::cout<<"Unesite broj kugla: ";
    for(;;) {
        std::cin>>n;
        if(!std::cin || n<=0 || n!=int(n))
            std::cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;
        else break;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
    std::vector<std::shared_ptr<Kugla>> kugle;
    double a,b,c,r;
    for(int i=0; i<n; i++) {
        for(;;) {
            std::cout<<"Unesite centar "<<i+1<<". kugle: ";
            std::cin>>a>>b>>c;
            if(!std::cin) {
                std::cout<<"Neispravan centar"<<std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                continue;
            }
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
            std::cin>>r;
            if(!std::cin || r<0)
                std::cout<<"Ilegalan poluprecnik"<<std::endl;
            else break;
            /*if(!std::cin) {
                std::cout<<"Ilegalan poluprecnik"<<std::endl; }
            else {try {
                std::shared_ptr<Kugla> pom(std::make_shared<Kugla> (Kugla(a,b,c,r)));
                kugle.push_back(pom);break;
            } catch (std::domain_error izuzetak) {
                std::cout<<izuzetak.what()<<std::endl;
                i--;
            }}*/
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        try {
            std::shared_ptr<Kugla> pom(std::make_shared<Kugla> (Kugla(a,b,c,r)));
            kugle.push_back(pom);
        } catch (std::domain_error izuzetak) {                                  //iako je iznad osigurano da ce ispravan r biti poslan u konstruktor
            std::cout<<izuzetak.what()<<std::endl;
            i--;
        }
    }
    double delta_x, delta_y, delta_z;                                           //transliranje svih unesenih kugli
    std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    for(;;) {
        std::cin>>delta_x>>delta_y>>delta_z;
        if(!std::cin)
            std::cout<<"Neispravni parametri translacije, unesite ponovo!"<<std::endl;
        else break;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
    std::transform(kugle.begin(), kugle.end(), kugle.begin(), [delta_x, delta_y, delta_z] (std::shared_ptr<Kugla> k) {
        std::shared_ptr<Kugla> pom(std::make_shared<Kugla> (Kugla(k->DajX()+delta_x,
                                   k->DajY()+delta_y, k->DajZ()+delta_z, k->DajPoluprecnik())));
        return pom;
    });
    std::sort(kugle.begin(), kugle.end(), [] (std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2) {
        return k1->DajZapremninu()<k2->DajZapremninu();
    });
    std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<std::endl;
    std::for_each(kugle.begin(), kugle.end(), [] (std::shared_ptr<Kugla> k) {
        k->Ispisi();
    });
    std::cout<<"Kugla sa najvecom povrsinom je: ";
    (*std::max_element(kugle.begin(), kugle.end(), [] (std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2) {
        return k1->DajPovrsinu()<k2->DajPovrsinu();
    }))->Ispisi();

    //pronaci sve parove kugli koje se presjecaju
    /*bool sijeku_se(false);
    for(int i=0; i<n-1; i++) {
        for(int j=1; j<n; j++) {
            if(DaLiSeSjeku(*kugle[i], *kugle[j])) {
                std::cout<<"Presjecaju se kugle: ";
                kugle[i]->Ispisi();
                kugle[j]->Ispisi();
                sijeku_se=true;
            }
        }
    }*/
    bool sijeku_se(false);
    std::for_each (kugle.begin(), kugle.end(), [&] (std::shared_ptr<Kugla> k) {
        std::vector<std::shared_ptr<Kugla>>::iterator a=std::find_if(kugle.begin(), kugle.end(), [&] (std::shared_ptr<Kugla> k1) {
            return IsteTacke(k->DajX(), k1->DajX()) && IsteTacke(k->DajY(), k1->DajY())
                   && IsteTacke(k->DajZ(), k1->DajZ()) && IsteTacke(k->DajPoluprecnik(), k1->DajPoluprecnik());
        });
        if(a!=kugle.end())
            a++;
        std::for_each(a, kugle.end(), [&] (std::shared_ptr<Kugla> k2) {
            if(DaLiSeSjeku(*k, *k2)) {
                std::cout<<"Presjecaju se kugle: ";
                k->Ispisi();
                k2->Ispisi();
                sijeku_se=true;
            }
        });
    });
    if(sijeku_se==false) std::cout<<"Ne postoje kugle koje se presjecaju!";
    return 0;
}