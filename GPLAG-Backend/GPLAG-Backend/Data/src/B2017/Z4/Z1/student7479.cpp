#include <iostream>
#include <cmath>
#include <tuple>
#include <stdexcept>
#include <vector>
#include <memory>
const double pi=4*atan(1);
const double epsilon=1e-10;

class Kugla
{
    double x, y, z , r;
public:
    explicit Kugla (double r=0) {
        Kugla::x=0;
        Kugla::y=0;
        Kugla::z=0;
        Kugla::r=r;
    }

    Kugla (double x, double y, double z, double r=0) {
        if (r<0) {
            throw std::domain_error ("Ilegalan poluprecnik");
        }
        Kugla::x=x;
        Kugla::y=y;
        Kugla::z=z;
        Kugla::r=r;
    }

    explicit Kugla (const std::tuple<double,double,double> &centar, double r=0) {
        if (r<0) {
            throw std::domain_error ("Ilegalan poluprecnik");
        }
        std::tie(Kugla::x, Kugla::y, Kugla::z)=centar;
        Kugla::r=r;
    }

    double DajX () const {
        return x;
    }

    double DajY () const {
        return y;
    }

    double DajZ () const {
        return z;
    }

    std::tuple<double,double,double> DajCentar () const {
        auto centar (std::tie(Kugla::x, Kugla::y, Kugla::z));
        return centar;
    }

    double DajPoluprecnik () const {
        return r;
    }

    double DajPovrsinu () const {
        double P;
        P=4*pow(r,2)*pi;
        return P;
    }

    double DajZapreminu () const {
        double V;
        V=(4*pow(r,3)*pi)/3;
        return V;
    }

    Kugla &PostaviX (double x) {
        Kugla::x=x;
        return *this;
    }

    Kugla &PostaviY (double y) {
        Kugla::y=y;
        return *this;
    }

    Kugla &PostaviZ (double z) {
        Kugla::z=z;
        return *this;
    }

    Kugla &PostaviCentar (double x, double y, double z) {
        Kugla::x=x;
        Kugla::y=y;
        Kugla::z=z;
        return *this;
    }

    Kugla &PostaviCentar (std::tuple<double,double,double> &centar) {
        std::tie(Kugla::x, Kugla::y, Kugla::z)=centar;
        return *this;
    }

    Kugla &PostaviPoluprecnik (double r) {
        if (r<0) {
            throw std::domain_error ("Ilegalan poluprecnik");
        }
        Kugla::r=r;
        return *this;
    }

    void Ispisi () const {
        std::cout<<"{ ("<<x<<","<<y<<","<<z<<") ,"<<r<<"}"<<std::endl;
    }

    void Transliraj (double delta_x, double delta_y, double delta_z) {
        Kugla::x+=delta_x;
        Kugla::y+=delta_y;
        Kugla::z+=delta_z;
    }

    friend bool DaLiSuIndenticne (const Kugla &k1, const Kugla &k2);
    friend bool DaLISuPodudarne (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuKoncentricne (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIzvana (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSePreklapaju (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeSijeku (const Kugla &k1, const Kugla &k2);
    friend double RastojanjeCentara (const Kugla &k1, const Kugla &k2);

    bool DaLiSadrzi (const Kugla &k) const;


};

bool DaLiSuIndenticne (const Kugla &k1, const Kugla &k2)
{
    if (abs(k1.x-k2.x)<epsilon && abs(k1.y-k2.y)<epsilon && abs(k1.z-k2.z)<epsilon && abs(k1.r-k2.r)<epsilon) {
        return true;
    }
    return false;
}

bool DaLISuPodudarne (const Kugla &k1, const Kugla &k2)
{
    if (abs(k1.r-k2.r)<epsilon) {
        return true;
    }
    return false;
}

bool DaLiSuKoncentricne (const Kugla &k1, const Kugla &k2)
{
    if (abs(k1.x-k2.x)<epsilon && abs(k1.y-k2.y)<epsilon && abs(k1.z-k2.z)<epsilon) {
        return true;
    }
    return false;
}

double RastojanjeCentara (const Kugla &k1, const Kugla &k2)
{
    double rastojanje;
    rastojanje=sqrt(pow(k1.x-k2.x,2)+pow(k1.y-k2.y,2)+pow(k1.z-k2.z,2));
    return rastojanje;
}

bool DaLiSeDodirujuIzvana (const Kugla &k1, const Kugla &k2)
{
    if (RastojanjeCentara(k1,k2)==k1.r+k2.r) {
        return true;
    }
    return false;
}

bool DaLiSePreklapaju (const Kugla &k1, const Kugla &k2)
{
    if (DaLiSeSijeku(k1,k2)) {
        return true;
    }
    if (k1.DaLiSadrzi(k2)) {
        return true;
    }
    if (k2.DaLiSadrzi(k1)) {
        return true;
    }
    return false;
}

bool DaLiSeSijeku (const Kugla &k1, const Kugla &k2)
{
    if (RastojanjeCentara(k1,k2)>k1.r+k2.r) {
        return true;
    }
    return false;
}

bool Kugla::DaLiSadrzi (const Kugla &k) const
{
    double rastojanje;
    rastojanje=sqrt(pow(x-k.x,2)+pow(y-k.y,2)+pow(z-k.z,2));
    if (rastojanje+k.r<r) {
        return true;
    }
    return false;
}

int main ()
{
    try {
        int n;
        std::cout<<"Unesite broj kugla: ";
        std::cin>>n;
        std::vector<std::shared_ptr<Kugla>> niz(n);
        for (int i=0; i<n; i++) {
            double x, y, z, r;
            std::cout<<"Unesite centar "<<i+1<<". kugle: ";
            std::cin>>x>>y>>z;
            std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
            std::cin>>r;
            niz[i] = new Kugla[Kugla(z,y,z,r)];
        }
    }
    return 0;
}
