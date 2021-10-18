/B2017/2018: Zadaća 4, Zadatak 2
/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <cmath>
#include <new>
#include <vector>
#include <utility>
#include <iterator>
#include <memory>
#include <algorithm>

const double Epsilon=10e-10;
const double PI=4*std::atan(1);

class NepreklapajucaKugla{
    double x,y,z;
    double r;
    mutable int brojac=0;
    NepreklapajucaKugla* pok;
    static NepreklapajucaKugla* pok2=nullptr;
    void Test_Ispravnosti(double poluprecnik){
        if(poluprecnik<0) throw std::domain_error("Ilegalan poluprecnik");
    }
    bool DaLiSePreklapaju(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){
    if(DaLiSeDodirujuIzvana(k1,k2) || RastojanjeCentara(k1,k2)>k1.r+k2.r) return false;
    return true;
    }
    bool DaLiSeDodirujuIzvana(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){
    return std::fabs(RastojanjeCentara(k1,k2)-(k1.r+k2.r))<Epsilon*(std::fabs(RastojanjeCentara(k1,k2))+std::fabs(k1.r+k2.r));
    }
public:
    explicit NepreklapajucaKugla(double r = 0): x(0), y(0), z(0) {Test_Ispravnosti(r); if(brojac==0) NepreklapajucaKugla::r=r;}
    NepreklapajucaKugla(double x, double y, double z, double r = 0): x(x), y(y), z(z) {Test_Ispravnosti(r); NepreklapajucaKugla::r=r;}
    explicit NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r = 0): x(std::get<0>(centar)), y(std::get<1>(centar)), z(std::get<2>(centar)) {Test_Ispravnosti(r); NepreklapajucaKugla::r=r;}
    NepreklapajucaKugla(const NepreklapajucaKugla &k)=delete;
    NepreklapajucaKugla &operator=(const NepreklapajucaKugla &k)=delete;
    double DajX() const {return x;}
    double DajY() const {return y;}
    double DajZ() const {return z;}
    std::tuple<double, double, double> DajCentar() const {return std::make_tuple(x,y,z);}
    double DajPoluprecnik() const {return r;}
    double DajPovrsinu() const {return 4*r*r*PI;}
    double DajZapreminu() const {return (4*r*r*r*PI)/3;}
    NepreklapajucaKugla &PostaviX(double x) {NepreklapajucaKugla::x=x; return *this;}
    NepreklapajucaKugla &PostaviY(double y) {NepreklapajucaKugla::y=y; return *this;}
    NepreklapajucaKugla &PostaviZ(double z) {NepreklapajucaKugla::z=z; return *this;}
    NepreklapajucaKugla &PostaviCentar(double x, double y, double z){ PostaviX(x); PostaviY(y); PostaviZ(z); return *this;}
    NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar) {PostaviX(std::get<0>(centar)); PostaviY(std::get<1>(centar)); PostaviZ(std::get<2>(centar)); return *this;}
    NepreklapajucaKugla &PostaviPoluprecnik(double r) {NepreklapajucaKugla::r=r; return *this;}
    void Ispisi() const {std::cout<<"{("<<DajX()<<","<<DajY()<<","<<DajZ()<<"),"<<DajPoluprecnik()<<"}\n";}
    void Transliraj(double delta_x, double delta_y, double delta_z) {x=x+delta_x; y=y+delta_y; z=z+delta_z;}
    friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
};
double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){
    return std::sqrt((k1.x*k1.x-k2.x*k2.x) + (k1.y*k1.y-k2.y*k2.y) + (k1.z*k1.z-k2.z*k2.z));
}   
NepreklapajucaKugla::NepreklapajucaKugla(double r = 0): x(0), y(0), z(0) {
    Test_Ispravnosti(r); 
    NepreklapajucaKugla::r=r;
    pok2=this;
    if(brojac==0){
        pok=nullptr;
        brojac++;
    }
    else{
        for(auto it(pok2); it!=nullptr; it=it->pok)
            if(DaLiSePreklapaju(*this,*it)) throw std::logic_error("Preklapaju se");
        pok=    
            
            
        
int main ()
{
    int n;
    std::cout<<"Unesite broj kugla: ";
    std::cin>>n;
    std::vector<std::shared_ptr<NepreklapajucaKugla>> vektor;
    for(int i(0); i<n; i++){
        double x,y,z,r;
        std::cout<<"Unesite centar "<<i+1<<". kugle: ";
        std::cin>>x>>y>>z;
        if(!(std::cin)){
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout<<"Ilegalne koordinate\n";
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
        vektor.push_back(std::make_shared<NepreklapajucaKugla>(x,y,z,r));
        }catch(std::logic_error logg){
            std::cout<<logg.what()<<std::endl;
            i--;
        }
    }
    double delta_x, delta_y, delta_z;
    std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    std::cin>> delta_x>>delta_y>>delta_z;
    std::transform(vektor.begin(), vektor.end(), vektor.begin(), [delta_x,delta_y,delta_z] (std::shared_ptr<NepreklapajucaKugla> p) {p->Transliraj(delta_x,delta_y,delta_z); return p;});
    std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti:\n";
    std::sort(vektor.begin(), vektor.end(), [] (std::shared_ptr<NepreklapajucaKugla> p1, std::shared_ptr<NepreklapajucaKugla> p2) {return p1->DajPovrsinu() < p2->DajPovrsinu(); });
    std::for_each(vektor.begin(), vektor.end(), [] (std::shared_ptr<NepreklapajucaKugla> p) {p->Ispisi();});
	return 0;
}
