/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <tuple>
#include <vector>
#include <algorithm>
#include <memory>

const double EPSILON = 1e-10;
const double PI = 4*atan(1);

class NepreklapajucaKugla
{   
    static NepreklapajucaKugla *posljednja;
    NepreklapajucaKugla *prethodni;
    double x,y,z,poluprecnik;
    bool DaLiSePreklapaju(const NepreklapajucaKugla &k){
        for(NepreklapajucaKugla *p = k.posljednja; p != nullptr ; p=p->prethodni){
         if (RastojanjeCentara(k, *p) <= (k.poluprecnik + p->poluprecnik)) return true;
        }
    return false;
    }
public:
    NepreklapajucaKugla(const NepreklapajucaKugla &k) = delete;
    NepreklapajucaKugla &operator = (const NepreklapajucaKugla &k) = delete;
    explicit NepreklapajucaKugla(double r = 0){
        x=0; y=0; z=0;
        if(poluprecnik<0)throw std::domain_error("Ilegalan poluprecnik");
        poluprecnik=r;
    }
    NepreklapajucaKugla(double x, double y, double z, double r = 0){
        NepreklapajucaKugla::x=x; NepreklapajucaKugla::y=y; NepreklapajucaKugla::z=z; poluprecnik=r;
        if(DaLiSePreklapaju(*this)) {
            throw std::logic_error("Nedozvoljeno preklapanje");
        }
        prethodni=posljednja;
        posljednja=this;
    }
    explicit NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r = 0){
        x=std::get<0>(centar); y=std::get<1>(centar); z=std::get<2>(centar); poluprecnik=r;
        if(DaLiSePreklapaju(*this)) {
            throw std::logic_error("Nedozvoljeno preklapanje");
        }
        prethodni=posljednja;
        posljednja=this;
    }
    double DajX() const{ return x;}
    double DajY() const { return y;}
    double DajZ() const { return z;}
    std::tuple<double, double, double> DajCentar() const{
        std::tuple<double, double, double> pomocni(DajX(), DajY(), DajZ());
        return pomocni;
    }
    double DajPoluprecnik() const{ return poluprecnik;}
    double DajPovrsinu() const { return 4*PI*pow(poluprecnik, 2);}
    double DajZapreminu() const { return (3./4)*pow(poluprecnik, 3)*PI;}
    
    NepreklapajucaKugla &PostaviX(double x){
        double pomocna (NepreklapajucaKugla::x);
        NepreklapajucaKugla::x=x;
        if(DaLiSePreklapaju(*this)){
            NepreklapajucaKugla::x = pomocna;
            throw std::logic_error("Nedozvoljeno preklapanje");
        }
        return *this;
    }
    NepreklapajucaKugla &PostaviY(double y){
        double pomocna (NepreklapajucaKugla::y);
        NepreklapajucaKugla::y=y;
        if(DaLiSePreklapaju(*this)){
            NepreklapajucaKugla::y = pomocna;
            throw std::logic_error("Nedozvoljeno preklapanje");
        }
        return *this;
    }
    NepreklapajucaKugla &PostaviZ(double z){
        double pomocna (NepreklapajucaKugla::z);
        NepreklapajucaKugla::z=z;
        if(DaLiSePreklapaju(*this)){
            NepreklapajucaKugla::z = pomocna;
            throw std::logic_error("Nedozvoljeno preklapanje");
        }
        return *this;
    }
    NepreklapajucaKugla &PostaviCentar(double x, double y, double z){
        double pomocna1(NepreklapajucaKugla::x), pomocna2(NepreklapajucaKugla::y), pomocna3(NepreklapajucaKugla::z);
        NepreklapajucaKugla::x=x;
        NepreklapajucaKugla::y=y;
        NepreklapajucaKugla::z=z;
        if(DaLiSePreklapaju(*this)){
            NepreklapajucaKugla::x = pomocna1;
            NepreklapajucaKugla::y = pomocna2;
            NepreklapajucaKugla::z = pomocna3;
            throw std::logic_error("Nedozvoljeno preklapanje");
        }
        return *this;
    }
    NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar){
        PostaviCentar(std::get<0> (centar), std::get<1> (centar), std::get<2> (centar));
        return *this;
    }
    NepreklapajucaKugla &PostaviPoluprecnik(double r) {
        double pomocna = poluprecnik;
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        poluprecnik=r;
        if(DaLiSePreklapaju(*this)){
            poluprecnik = pomocna;
            throw std::logic_error("Nedozvoljeno preklapanje");
        }
        return *this;
    }
    void Ispisi() const{
        std::cout << "{(" << DajX() << "," <<DajY() << "," <<DajZ() << ")," << DajPoluprecnik() << "}" << std::endl;
    }
    void Transliraj(double delta_x, double delta_y, double delta_z){
        x+=delta_x;
        y+=delta_y;
        z+=delta_z;
        if(DaLiSePreklapaju(*this)){
            x-=delta_x;
            y-=delta_y;
            z-=delta_z;
            throw std::logic_error("Nedozvoljeno preklapanje");
        }
    }
    friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
};
double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){
    return sqrt( (k2.x-k1.x)*(k2.x-k1.x) + (k2.y-k1.y)*(k2.y-k1.y) + (k2.z-k1.z)*(k2.z-k1.z) );
}
NepreklapajucaKugla *NepreklapajucaKugla::posljednja=nullptr;
int main ()
{   
    std::cout << "Unesite broj kugli: ";
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
    std::vector<std::shared_ptr<NepreklapajucaKugla>> kugle(broj_kugli);
    for (int i = 0; i < broj_kugli; i++) {
        std::cout << "Unesite centar za " << i+1 << ". kuglu: ";
        double x, y, z;
        for(;;){
        std::cin>>x>>y>>z;
        if(!std::cin) {
            std::cout<<"Neispravan centar, unesite ponovo: "<<std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }
        break;
        }
        std::cout <<"Unesite poluprecnik: ";
        double r;
        for(;;){
        std::cin>>r;
        if(!std::cin || r<0) {
            std::cout<<"Neispravan poluprecnik, unesite ponovo: "<<std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }
        break;
        }
        try{
            kugle[i]=std::make_shared<NepreklapajucaKugla>(x,y,z,r);
        }
        catch(std::domain_error e){
            i--;
            std::cout<<e.what()<<std::endl;
        }
        catch(std::logic_error e){
            i--;
            std::cout<<e.what()<<std::endl;
        }
        
        
    }
    
     std::cout << "\nKugle nakon obavljenog sortiranja: " << std::endl;
     sort(kugle.begin(), kugle.end(), [] (std::shared_ptr<NepreklapajucaKugla> k1,std::shared_ptr<NepreklapajucaKugla> k2) {
        return k1->DajPovrsinu() < k2->DajPovrsinu();
    });
    for_each(kugle.begin(), kugle.end(), [] (std::shared_ptr<NepreklapajucaKugla> k) {k->Ispisi();});
    return 0;
}
