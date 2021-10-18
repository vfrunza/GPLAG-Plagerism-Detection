/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <cmath>
#include <tuple>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <memory>
#include <utility>


#define e 0.0000000001
class Kugla
{
    std::tuple<double,double,double> c;
    double r;
public:
    explicit Kugla(double r = 0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        std::get<0>(c)=0;
        std::get<1>(c)=0;
        std::get<2>(c)=0;
        Kugla::r=r;
    }
    Kugla(double x, double y, double z, double r = 0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        std::get<0>(c)=x;
        std::get<1>(c)=y;
        std::get<2>(c)=z;
        Kugla::r=r;
    }
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        c=centar;
        Kugla::r=r;
    }
    double DajX() const {
        return std::get<0>(c);
    }
    double DajY() const {
        return std::get<1>(c);
    }
    double DajZ() const {
        return std::get<2>(c);
    }
    std::tuple<double, double, double> DajCentar() const {
        return c;
    }
    double DajPoluprecnik() const {
        return r;
    }
    double DajPovrsinu() const {
        return 16*atan(1)*r*r;
    }
    double DajZapreminu() const {
        return (16*atan(1)*r*r*r)/3;
    }
    Kugla &PostaviX(double x) {
        std::get<0>(c)=x;
        return *this;
    }
    Kugla &PostaviY(double y) {
        std::get<1>(c)=y;
        return *this;
    }
    Kugla &PostaviZ(double z) {
        std::get<2>(c)=z;
        return *this;
    }
    Kugla &PostaviCentar(double x, double y, double z) {
        std::get<0>(c)=x;
        std::get<1>(c)=y;
        std::get<2>(c)=z;
        return *this;
    }
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar) {
        c=centar;
        return *this;
    }
    Kugla &PostaviPoluprecnik(double r) {
        Kugla::r = r;
        return *this;
    }
    void Ispisi() const {
        std::cout << "{(" << std::get<0>(c) << "," << std::get<1>(c) << "," << std::get<2>(c) << ")," << r << "}";
    }
    void Transliraj(double delta_x, double delta_y, double delta_z) {
        std::get<0>(c)+=delta_x;
        std::get<1>(c)+=delta_y;
        std::get<2>(c)+=delta_z;
    }
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
    bool DaLiSadrzi(const Kugla &k) const {
        return (sqrt((k.DajX()-DajX())*(k.DajX()-DajX())+(k.DajY()-DajY())*(k.DajY()-DajY())+(k.DajZ()-DajZ())*(k.DajZ()-DajZ()))<=fabs(DajPoluprecnik()-k.DajPoluprecnik()));
    }

    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);

};
bool Isti(double a, double b)
{
    return (fabs(a-b) < e * (fabs(a)+fabs(b)));
}
bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2)
{
    return Isti(k1.DajPoluprecnik(),k2.DajPoluprecnik()) && Isti(k1.DajX(),k2.DajX()) && Isti(k1.DajY(),k2.DajY()) && Isti(k1.DajZ(),k2.DajZ());
}
bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2)
{
    return Isti(k1.DajPoluprecnik(),k2.DajPoluprecnik());
}
bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2)
{
    return Isti(k1.DajX(),k2.DajX()) && Isti(k1.DajY(),k2.DajY()) && Isti(k1.DajZ(),k2.DajZ());
}
bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2)
{
    return Isti(RastojanjeCentara(k1,k2),k1.DajPoluprecnik()+k2.DajPoluprecnik());
}
bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2)
{
    return Isti(RastojanjeCentara(k1,k2),fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik()));
}
bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2)
{
    if(RastojanjeCentara(k1,k2)<(k1.DajPoluprecnik()+k2.DajPoluprecnik())) return true;
    else return k1.DaLiSadrzi(k2);
}
bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2)
{
    return (RastojanjeCentara(k1,k2)<(k1.DajPoluprecnik()+k2.DajPoluprecnik())) && (RastojanjeCentara(k1,k2)>fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik()));
}
double RastojanjeCentara(const Kugla &k1, const Kugla &k2)
{
    return sqrt((k1.DajX()-k2.DajX())*(k1.DajX()-k2.DajX())+(k1.DajY()-k2.DajY())*(k1.DajY()-k2.DajY())+(k1.DajZ()-k2.DajZ())*(k1.DajZ()-k2.DajZ()));
}
int main ()
{
    try{
    int broj_kugli;
    std::cout << "Unesite broj kugla: ";
    while(1) {
        std::cin >> broj_kugli;
        if(broj_kugli<1 || !std::cin) {
            std::cout << "Neispravan broj kugli, unesite ponovo!" << std::endl;
            std::cin.clear();
            std::cin.ignore(1000,'\n');
            continue;
        } else break;
    }
    std::vector<std::shared_ptr<Kugla>> vektor_kugli;
    for(int i = 0; i < broj_kugli; i++) {
        try {
            std::cout << "Unesite centar " << i+1 << ". kugle: ";
            double x,y,z;
            std::cin >> x;
            std::cin >> y;
            std::cin >> z;
            if(!std::cin) {
                std::cout << "Neispravan centar" << std::endl;
                i--;
                std::cin.clear();
                std::cin.ignore(1000,'\n');
                continue;
            }
            std::cout << "Unesite poluprecnik " << i+1 << ". kugle: ";
            double r;
            std::cin >> r;
            if(!std::cin) {
                std::cout << "Ilegalan poluprecnik" << std::endl;
                i--;
                std::cin.clear();
                std::cin.ignore(1000,'\n');
                continue;
            }
            auto pomocni_vektor(std::make_shared<Kugla>(x,y,z,r));
            vektor_kugli.push_back(pomocni_vektor);
        } catch(std::domain_error izuzetak) {
            std::cout << izuzetak.what() << std::endl;
            i--;
        }
    }
    double delta_x,delta_y,delta_z;
    std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    while(1) {
        std::cin >> delta_x;
        std::cin >> delta_y;
        std::cin >> delta_z;
        if(!std::cin) {
            std::cout << "Neispravni parametri translacije, unesite ponovo!" << std::endl;
            std::cin.clear();
            std::cin.ignore(1000,'\n');
            continue;
        } else break;
    }
    std::transform(vektor_kugli.begin(),vektor_kugli.end(),vektor_kugli.begin(),[delta_x,delta_y,delta_z](std::shared_ptr<Kugla> kugla) {
        kugla->Transliraj(delta_x,delta_y,delta_z);
        return kugla;
    });
    std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: " << std::endl;
    std::sort(vektor_kugli.begin(),vektor_kugli.end(),[](std::shared_ptr<Kugla> kugla_1, std::shared_ptr<Kugla> kugla_2) {
        return kugla_1->DajZapreminu() < kugla_2->DajZapreminu();
    });
    std::for_each(vektor_kugli.begin(),vektor_kugli.end(),[](std::shared_ptr<Kugla> kugla) {
        kugla->Ispisi();
        std::cout << std::endl;
    });
    auto najveca_kugla=*std::max_element(vektor_kugli.begin(),vektor_kugli.end(),[](std::shared_ptr<Kugla> kugla_1, std::shared_ptr<Kugla> kugla_2){
       if(kugla_1->DajPovrsinu()<kugla_2->DajPovrsinu()) return true;
       return false;
    });
    std::cout << "Kugla sa najvecom povrsinom je: ";
    najveca_kugla->Ispisi();
    std::cout << std::endl;
    int i=0;
    bool Postoji=false;
    std::for_each(vektor_kugli.begin(),vektor_kugli.end(),[vektor_kugli,&Postoji,&i](std::shared_ptr<Kugla> kugla_1) {
       std::for_each(vektor_kugli.begin()+i,vektor_kugli.end(),[kugla_1,&Postoji](std::shared_ptr<Kugla> kugla_2){
           if(DaLiSeSijeku(*kugla_1,*kugla_2)){
               std::cout << "Presjecaju se kugle: ";
               kugla_1->Ispisi();
               std::cout << std::endl;
               kugla_2->Ispisi();
               std::cout << std::endl;
               Postoji=true;
           }
    });
    i++;
    });
    if(!Postoji) std::cout << "Ne postoje kugle koje se presjecaju!" << std::endl;
    }
    catch(std::domain_error izuzetak){
        std::cout << izuzetak.what() << std::endl;
    }
    return 0;
}
