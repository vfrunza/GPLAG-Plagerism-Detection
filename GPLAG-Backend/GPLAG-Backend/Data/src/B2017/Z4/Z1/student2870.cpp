/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <utility>
#include <tuple>
#include <cmath>
#include <algorithm>
#include <vector>
#include <memory>
#include <iterator>

const double epsilon(std::pow(10,-10));

class Kugla
{
    double x,y,z;
    double r;
public:

    explicit Kugla (double r=0): x(0), y(0), z(0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        else Kugla::r=r;
    }

    Kugla(double x, double y, double z, double r=0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        else {
            Kugla::x=x;
            Kugla::y=y;
            Kugla::z=z;
            Kugla::r=r;
        }
    }

    explicit Kugla(const std::tuple<double, double, double> &centar, double r=0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        double x,y,z;
        std::tie(x,y,z)=centar;
        Kugla::x=x;
        Kugla::y=y;
        Kugla::z=z;
        Kugla::r=r;
    }

    double DajX() const {
        return x;
    }
    double DajY() const {
        return y;
    }
    double DajZ() const {
        return z;
    }

    std::tuple<double,double,double> DajCentar() const {
        return std::make_tuple(Kugla::x, Kugla::y, Kugla::z);
    }

    double DajPoluprecnik() const {
        return r;
    }
    double DajPovrsinu() const {
        return 4*std::pow(r,2)*4*atan(1);
    }
    double DajZapreminu() const {
        return ((r*r*r)*(4*atan(1)*4.0)/3.0);
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
    Kugla &PostaviCentar(const std::tuple<double,double,double> &centar) {
        std::tie(Kugla::x,Kugla::y,Kugla::z)=centar;
        return *this;
    }
    Kugla &PostaviPoluprecnik(double r) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::r=r;
        return *this;
    }

    void Ispisi() const {
        std::cout <<"{(" << x << "," << y << "," << z << ")," << r << "}" << std::endl;
    }
    void Transliraj(double delta_x, double delta_y, double delta_z) {
        this->x+=delta_x;
        this->y+=delta_y;
        this->z+=delta_z;
    }

    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);//OK
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);//OK
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);//OK
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);//OK
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);//OK
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);//OK
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);//OK
    bool DaLiSadrzi(const Kugla &k) const; //OK
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);//OK

};

double RastojanjeCentara(const Kugla &k1, const Kugla &k2)
{
    return (std::sqrt(std::pow(k2.x-k1.x,2)+std::pow(k2.y-k1.y,2)+std::pow(k2.z-k1.z,2)));
}

bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2)
{
    return ((std::fabs(k1.x-k2.x))<epsilon*(std::fabs(k1.x)+std::fabs(k2.x)) &&
            (std::fabs(k1.y-k2.y))<epsilon*(std::fabs(k1.y)+std::fabs(k2.y)) &&
            (std::fabs(k1.z-k2.z))<epsilon*(std::fabs(k1.z)+std::fabs(k2.z)) &&
            (std::fabs(k1.r-k2.r))<epsilon*(std::fabs(k1.r)+std::fabs(k2.r)));
}

bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2)
{
    return (std::fabs(k1.r-k2.r))<epsilon*(std::fabs(k1.r)+std::fabs(k2.r));
}

bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2)
{
    return ((std::fabs(k1.x-k2.x))<epsilon*(std::fabs(k1.x)+std::fabs(k2.x)) &&
            (std::fabs(k1.y-k2.y))<epsilon*(std::fabs(k1.y)+std::fabs(k2.y)) &&
            (std::fabs(k1.z-k2.z))<epsilon*(std::fabs(k1.z)+std::fabs(k2.z)));
}

bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2)
{
    double d=RastojanjeCentara(k1,k2);
    return (std::fabs(k1.r+k2.r-d)<epsilon*(std::fabs(k1.r+k2.r)+std::fabs(d)));
}

bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2)
{
    double d=RastojanjeCentara(k1,k2);
    return (std::fabs(k1.r-k2.r-d)<epsilon*(std::fabs(k1.r-k2.r)+std::fabs(d)));
}

bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2)  //prepraviti sa epsilon
{
    double d=RastojanjeCentara(k1,k2);
    double veci_poluprecnik(k2.r);
    if(k1.r>k2.r) veci_poluprecnik=k1.r;
    return (d+k1.r+k2.r<2*veci_poluprecnik);
}

bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2)  //prepraviti za epsilon
{
    double d=RastojanjeCentara(k1,k2);
    return ((d<(k1.r+k2.r)&&(d>std::fabs(k1.r-k2.r))));
}

bool Kugla::DaLiSadrzi(const Kugla &k) const   //prepraviti sa epsilon
{
    double d=RastojanjeCentara(*this,k);
    return d+this->r+k.r<2*(this->r);
}


int main ()
{
    Kugla kugla(1,2,3,4);
    int n,brojac(0);
    std::cout << "Unesite broj kugla: " ;
    while(1) {
        std::cin >> n;
        if(std::cin && n>0) break;
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::cout << "Neispravan broj kugli, unesite ponovo!" << std::endl;
    }
    std::vector<std::shared_ptr<Kugla>> vektor_pametnih (n);
   
    double x,y,z,r;
    while(brojac<n){
        while(1){
            while(1){
                std::cout << "Unesite centar " << brojac+1 << ". kugle: " ;
                std::cin >> x >> y >> z;
                if(std::cin) break;
                std::cin.clear();
                std::cin.ignore(10000,'\n');
                std::cout << "Neispravan centar" << std::endl;
            }
            
            std::cout << "Unesite poluprecnik " << brojac+1 << ". kugle: " ;
            std::cin >> r;
            if(std::cin && r>=0) break;
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            std::cout << "Ilegalan poluprecnik" << std::endl;
        }
        vektor_pametnih[brojac]=std::make_shared<Kugla> (Kugla(x,y,z,r));
        brojac++;
    }

    int delta_x,delta_y,delta_z;
    std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    while(1){
    std::cin >> delta_x >> delta_y >> delta_z;
    if(std::cin) break;
    std::cin.clear();
    std::cin.ignore(10000,'\n');
    std::cout << "Neispravni parametri translacije, unesite ponovo!" << std::endl;
        
    }

    std::transform(vektor_pametnih.begin(),vektor_pametnih.end(),vektor_pametnih.begin(),[delta_x,delta_y,delta_z] (std::shared_ptr<Kugla> &test) {
        test->Transliraj(delta_x,delta_y,delta_z);
        return test;
    });

    std::sort(vektor_pametnih.begin(),vektor_pametnih.end(),[](const std::shared_ptr<Kugla> &k1, const std::shared_ptr<Kugla> &k2) {
        return k1->DajZapreminu()<k2->DajZapreminu();
    });

    std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: " << std::endl;
    std::for_each(vektor_pametnih.begin(),vektor_pametnih.end(),[](const std::shared_ptr<Kugla> &k) {
        return k->Ispisi();
    });

    std::cout << "Kugla sa najvecom povrsinom je: ";
    (*std::max_element(vektor_pametnih.begin(),vektor_pametnih.end(),[](const std::shared_ptr<Kugla> &k1, const std::shared_ptr<Kugla> &k2) {
        return k1->DajPovrsinu()<k2->DajPovrsinu();
    }))->Ispisi();

    int pomjerajuci(0);
    int postoji_li(0);
    std::for_each(vektor_pametnih.begin(),vektor_pametnih.end(),[&pomjerajuci,&postoji_li,vektor_pametnih](const std::shared_ptr<Kugla> &k1) {
        pomjerajuci++;
        std::for_each(vektor_pametnih.begin()+pomjerajuci,vektor_pametnih.end(),[&postoji_li,k1](const std::shared_ptr<Kugla> &k2) {
            if(DaLiSeSijeku(*k1,*k2)) {
                std::cout << "Presjecaju se kugle: ";
                postoji_li++;
                k1->Ispisi();
                k2->Ispisi();

            }
        });
    } );
    if(!postoji_li) std::cout << "Ne postoje kugle koje se presjecaju!";

    return 0;
}
