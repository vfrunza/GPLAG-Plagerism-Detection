/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <tuple>
#include <memory>
#include <vector>
#include <algorithm>

const double EPSILON = 1e-10;
const double PI = 4*atan(1);

class Kugla
{
    double x,y,z,poluprecnik;
public:
    explicit Kugla(double r = 0) {
        x=0;
        y=0;
        z=0;
        if(poluprecnik<0)throw std::domain_error("Ilegalan poluprecnik");
        poluprecnik=r;
    }
    Kugla(double x, double y, double z, double r = 0) {
        Kugla::x=x;
        Kugla::y=y;
        Kugla::z=z;
        poluprecnik=r;
    }
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0) {
        x=std::get<0>(centar);
        y=std::get<1>(centar);
        z=std::get<2>(centar);
        poluprecnik=r;
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
    std::tuple<double, double, double> DajCentar() const {
        std::tuple<double, double, double> pomocni(DajX(), DajY(), DajZ());
        return pomocni;
    }
    double DajPoluprecnik() const {
        return poluprecnik;
    }
    double DajPovrsinu() const {
        return 4*PI*pow(poluprecnik, 2);
    }
    double DajZapreminu() const {
        return (3./4)*pow(poluprecnik, 3)*PI;
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
        x=std::get<0>(centar);
        y=std::get<1>(centar);
        z=std::get<2>(centar);
        return *this;
    }
    Kugla &PostaviPoluprecnik(double r) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        poluprecnik=r;
        return *this;
    }
    void Ispisi() const {
        std::cout << "{(" << DajX() << "," <<DajY() << "," <<DajZ() << ")," << DajPoluprecnik() << "}" << std::endl;
    }
    void Transliraj(double delta_x, double delta_y, double delta_z) {
        x+=delta_x;
        y+=delta_y;
        z+=delta_z;
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

double RastojanjeCentara(const Kugla &k1, const Kugla &k2)
{
    return sqrt( (k2.x-k1.x)*(k2.x-k1.x) + (k2.y-k1.y)*(k2.y-k1.y) + (k2.z-k1.z)*(k2.z-k1.z) );
}
bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2)
{
    if( fabs(k1.x-k2.x) > EPSILON*(fabs(k1.x)+fabs(k2.x)) || fabs(k1.y - k2.y) > EPSILON*(fabs(k1.y) + fabs(k2.y)) || fabs(k1.z - k2.z) > EPSILON*(fabs(k1.z)+fabs(k2.z)) || fabs(k1.poluprecnik - k2.poluprecnik) > EPSILON*(fabs(k1.poluprecnik)+ fabs(k2.poluprecnik))) return false;
    return true;
}
bool DaLiSuPodudarne (const Kugla &k1, const Kugla &k2)
{
    if (fabs(k1.poluprecnik - k2.poluprecnik) > EPSILON*(fabs(k1.poluprecnik) + fabs(k2.poluprecnik))) return false;
    return true;
}
bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2)
{
    if(fabs(k1.x-k2.x) > EPSILON*(fabs(k1.x)+fabs(k2.x)) || fabs(k1.y - k2.y) > EPSILON*(fabs(k1.y) + fabs(k2.y)) || fabs(k1.z - k2.z) > EPSILON*(fabs(k1.z)+fabs(k2.z))) return false;
    return true;
}
bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2)
{
    if( fabs( fabs(k1.poluprecnik - k2.poluprecnik) - RastojanjeCentara(k1, k2) ) < EPSILON*(fabs(k1.poluprecnik-k2.poluprecnik) + fabs(RastojanjeCentara(k1,k2)) ) )return true;
    return false;
}
bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2)
{
    if( (fabs( (k1.poluprecnik+k2.poluprecnik) - RastojanjeCentara(k1, k2)) )< EPSILON*( fabs( k1.poluprecnik+k2.poluprecnik )+ fabs( RastojanjeCentara(k1,k2) )) ) return true;
    return false;
}
bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2)
{
    if (RastojanjeCentara(k1, k2) < (k1.poluprecnik + k2.poluprecnik)) return true;
    return false;
}
bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2)
{
    if(DaLiSePreklapaju(k1,k2) && (RastojanjeCentara(k1, k2) > fabs(k1.poluprecnik - k2.poluprecnik))) return true;
    return false;
}
bool Kugla::DaLiSadrzi(const Kugla &k) const
{
    if( this->poluprecnik > k.poluprecnik) return false;
    if( RastojanjeCentara(*this, k) < fabs(this->poluprecnik - k.poluprecnik))return true;
    return false;
}
int main ()
{
    std::vector<std::shared_ptr<Kugla>> kugle;
    std::cout << "Unesite broj kugla: ";
    int broj_kugli;

    for(;;) {
        std::cin>>broj_kugli;
        if(!std::cin || broj_kugli <= 0) {
            std::cout<<"Neispravan broj kugli, unesite ponovo!"<< std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        } else break;
    }

    for (int i = 0; i < broj_kugli; i++) {
        std::cout << "Unesite centar " << i+1 << ". kugle: ";
        double x, y, z;
        std::cin>>x>>y>>z;
        if(!std::cin) {
            std::cout<<"Neispravan centar"<<std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            i--;
            continue;
        }
        std::cout <<"Unesite poluprecnik "<<i+1 <<". kugle: ";
        double r;
        std::cin>>r;
        if(!std::cin || r<0) {
            std::cout<<"Ilegalan poluprecnik"<<std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            i--;
            continue;
        }

        kugle.push_back(std::make_shared<Kugla>(x,y,z,r));
    }

    double delta_x, delta_y, delta_z;
    std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    for(;;){
    std::cin>>delta_x >> delta_y >> delta_z;
    if(!std::cin){
        std::cout << "Neispravni parametri translacije, unesite ponovo!" << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        continue;
    }
    else break;
    }
    transform(kugle.begin(), kugle.end(), kugle.begin(), [delta_x, delta_y, delta_z] (std::shared_ptr<Kugla> k) {
        k->Transliraj(delta_x, delta_y, delta_z);
        return k;
    });
    
    std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<std::endl;
    sort(kugle.begin(), kugle.end(), [] (std::shared_ptr<Kugla> k1,std::shared_ptr<Kugla> k2) {
        return k1->DajZapreminu() < k2->DajZapreminu();
    });
    for_each(kugle.begin(), kugle.end(), [] (std::shared_ptr<Kugla> k1) {
        k1->Ispisi();
    });
    std::cout<<"Kugla sa najvecom povrsinom je: ";
    auto najveca = *max_element(kugle.begin(), kugle.end(),[] (std::shared_ptr<Kugla> k1,std::shared_ptr<Kugla> k2) {
        return k1->DajPovrsinu() < k2->DajPovrsinu();
    });
    najveca->Ispisi();
    int i(1), brojac(0);
    for_each(kugle.begin(), kugle.end(), [kugle, &i, &brojac] (std::shared_ptr<Kugla> k1) {
        for_each(kugle.begin() + i, kugle.end(), [k1, &brojac] (std::shared_ptr<Kugla> k2) {
            if(DaLiSeSijeku(*k1, *k2)) {
                brojac++;
                std::cout<<"Presjecaju se kugle: ";
                k1->Ispisi();
                k2->Ispisi();
            }
        });
        i++;

    });
    if(brojac==0) std::cout<<"Ne postoje kugle koje se presjecaju!";

    return 0;
}
