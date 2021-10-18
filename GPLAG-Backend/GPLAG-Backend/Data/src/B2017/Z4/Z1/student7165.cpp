/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <new>
#include <vector>
#include <utility>
#include <iterator>
#include <memory>
#include <algorithm>

const double Epsilon=10e-10;
const double PI=4*std::atan(1);
class Kugla{
    double x,y,z;
    double r;
    void Test_Ispravnosti(double poluprecnik){
        if(poluprecnik<0) throw std::domain_error("Ilegalan poluprecnik");
    }
public:
    explicit Kugla(double r = 0): x(0), y(0), z(0) {
        Test_Ispravnosti(r); 
        Kugla::r=r;
    }
    Kugla(double x, double y, double z, double r = 0): x(x), y(y), z(z) {
        Test_Ispravnosti(r);
        Kugla::r=r;
    }
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0): x(std::get<0>(centar)), y(std::get<1>(centar)), z(std::get<2>(centar)) {
            Test_Ispravnosti(r);
            Kugla::r=r;
    }
    double DajX() const {return x;}
    double DajY() const {return y;}
    double DajZ() const {return z;}
    std::tuple<double, double, double> DajCentar() const {return std::make_tuple(x,y,z);}
    double DajPoluprecnik() const {return r;}
    double DajPovrsinu() const {return 4*r*r*PI;}
    double DajZapreminu() const {return (4*r*r*r*PI)/3;}
    Kugla &PostaviX(double x) {Kugla::x=x; return *this;}
    Kugla &PostaviY(double y) {Kugla::y=y; return *this;}
    Kugla &PostaviZ(double z) {Kugla::z=z; return *this;}
    Kugla &PostaviCentar(double x, double y, double z){ PostaviX(x); PostaviY(y); PostaviZ(z); return *this;}
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar) {PostaviX(std::get<0>(centar)); PostaviY(std::get<1>(centar)); PostaviZ(std::get<2>(centar)); return *this;}
    Kugla &PostaviPoluprecnik(double r) {Kugla::r=r; return *this;}
    void Ispisi() const {std::cout<<"{("<<DajX()<<","<<DajY()<<","<<DajZ()<<"),"<<DajPoluprecnik()<<"}"<<std::endl;}
    void Transliraj(double delta_x, double delta_y, double delta_z) {x=x+delta_x; y=y+delta_y; z=z+delta_z;}
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
bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2){
    return std::fabs(k1.x-k2.x)<Epsilon*(std::fabs(k1.x)+std::fabs(k2.x)) && std::fabs(k1.y-k2.y)<Epsilon*(std::fabs(k1.y)+std::fabs(k2.y)) && std::fabs(k1.z-k2.z)<Epsilon*(std::fabs(k1.z)+std::fabs(k2.z)) && std::fabs(k1.r-k2.r)<Epsilon*(std::fabs(k1.r)+std::fabs(k2.r));
}
bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2){
    return std::fabs(k1.r-k2.r)<Epsilon*(std::fabs(k1.r)+std::fabs(k2.r));
}
bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2){
    return std::fabs(k1.x-k2.x)<Epsilon*(std::fabs(k1.x)+std::fabs(k2.x)) && std::fabs(k1.y-k2.y)<Epsilon*(std::fabs(k1.y)+std::fabs(k2.y)) && std::fabs(k1.z-k2.z)<Epsilon*(std::fabs(k1.z));
}
bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2){
    return std::fabs(RastojanjeCentara(k1,k2)-(k1.r+k2.r))<Epsilon*(std::fabs(RastojanjeCentara(k1,k2))+std::fabs(k1.r+k2.r));
}
bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2){
    return std::fabs(RastojanjeCentara(k1,k2)-std::fabs(k1.r-k2.r))<Epsilon*(std::fabs(RastojanjeCentara(k1,k2))+std::fabs(k1.r-k2.r));
}
bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2){
    if(DaLiSeDodirujuIzvana(k1,k2) || RastojanjeCentara(k1,k2)>k1.r+k2.r) return false;
    return true;
}
bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2){
    if(DaLiSeDodirujuIzvana(k1,k2) || DaLiSeDodirujuIznutra(k1,k2) || RastojanjeCentara(k1,k2)<std::fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik()) ||
    RastojanjeCentara(k1,k2)>k1.DajPoluprecnik()+k2.DajPoluprecnik()) return false;
    return true;
}
bool Kugla::DaLiSadrzi (const Kugla &k) const {
    return RastojanjeCentara(k,*this)<std::fabs(k.r-this->r);
}
double RastojanjeCentara(const Kugla &k1, const Kugla &k2){
    return std::sqrt((k1.x-k2.x)*(k1.x-k2.x) + (k1.y-k2.y)*(k1.y-k2.y) + (k1.z-k2.z)*(k1.z-k2.z));
}   
int main ()
{
    int n;
    std::cout<<"Unesite broj kugla: ";
    do{
        std::cin>>n;
        if(!(std::cin)){
            std::cout<<"Neispravan broj kugli, unesite ponovo!\n";
            std::cin.clear();
            std::cin.ignore(10000,'\n');
        }
        else if(n<=0) std::cout<<"Neispravan broj kugli, unesite ponovo!\n";
        else break;
    }while(true);
    std::vector<std::shared_ptr<Kugla>> vektor(n);
    for(int i(0); i<n; i++){
        double x,y,z,r;
        std::cout<<"Unesite centar "<<i+1<<". kugle: ";
        std::cin>>x>>y>>z;
        if(!(std::cin)){
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout<<"Neispravan centar\n";
            i--;
            continue;
        }
        std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
        std::cin>>r;
        if(!(std::cin)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout<<"Ilegalan poluprecnik\n";
            i--;
            continue;
        }
        else if(r<0) {
            std::cout<<"Ilegalan poluprecnik\n";
            i--;
            continue;
        }
        try{
        vektor.at(i)=std::make_shared<Kugla>(x,y,z,r);
        }catch()
    }
    double delta_x, delta_y, delta_z;
    std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    do{
        std::cin>> delta_x>>delta_y>>delta_z;
        if(!std::cin){
            std::cout<<"Neispravni parametri translacije, unesite ponovo!\n";
            std::cin.clear();
            std::cin.ignore(10000,'\n');
        }
        else break;
    }while(true);
    std::transform(vektor.begin(), vektor.end(), vektor.begin(), [delta_x,delta_y,delta_z] (std::shared_ptr<Kugla> p) {p->Transliraj(delta_x,delta_y,delta_z); return p;});
    std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti:\n";
    std::sort(vektor.begin(), vektor.end(), [] (std::shared_ptr<Kugla> p1, std::shared_ptr<Kugla> p2) {return p1->DajZapreminu() < p2->DajZapreminu(); });
    std::for_each(vektor.begin(), vektor.end(), [] (std::shared_ptr<Kugla> p) {p->Ispisi();});
    std::cout<<"Kugla sa najvecom povrsinom je: ";
    auto pok(std::max_element(vektor.begin(), vektor.end(), [] (std::shared_ptr<Kugla> p1, std::shared_ptr<Kugla> p2) {return p1->DajPovrsinu() < p2->DajPovrsinu();}));
    (*pok)->Ispisi(); 
    int brojac(0);
    int brojac2(0);
    std::for_each(vektor.begin(), vektor.end(), [&brojac, vektor, &brojac2] (std::shared_ptr<Kugla> p)->void {
        brojac2++;
        std::for_each(vektor.begin()+brojac2, vektor.end(), [p,&brojac] (std::shared_ptr<Kugla> q)->void { if(DaLiSeSijeku( *p , *q)){
            std::cout<<"Presjecaju se kugle: "; p->Ispisi(); q->Ispisi();
            brojac++;
        }
        });
    });
    if(brojac==0) std::cout<<"Ne postoje kugle koje se presjecaju!";
	return 0;
}
