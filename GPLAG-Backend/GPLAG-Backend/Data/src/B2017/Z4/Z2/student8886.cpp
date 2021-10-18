/B2017/2018: Zadaća 4, Zadatak 2
#include <iostream>
#include <tuple>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>
#define PI (4*atan(1))
const double epsilon = 1E-10;
class NepreklapajucaKugla{
    double x, y, z, r;
    class cvor* naredni;
    public:
    explicit NepreklapajucaKugla(double r=0){
        if(r < 0 ) throw std::domain_error("Ilegalan poluprecnik");
        NepreklapajucaKugla::x=0;
        NepreklapajucaKugla::y=0;
        NepreklapajucaKugla::z=0;
        NepreklapajucaKugla::r=r;
    }
    NepreklapajucaKugla(double x, double y, double z, double r=0){
        if(r < 0 ) throw std::domain_error("Ilegalan poluprecnik");
        NepreklapajucaKugla::x=x;
        NepreklapajucaKugla::y=y;
        NepreklapajucaKugla::z=z;
        NepreklapajucaKugla::r=r;
    }
    explicit NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r=0){
        if(r < 0 ) throw std::domain_error("Ilegalan poluprecnik");
        NepreklapajucaKugla::x=std::get<0>(centar);
        NepreklapajucaKugla::y=std::get<1>(centar);
        NepreklapajucaKugla::z=std::get<2>(centar);
        NepreklapajucaKugla::r=r;
    }
    double DajX() const{
        return NepreklapajucaKugla::x;
    }
    double DajY() const{
        return NepreklapajucaKugla::y;
    }
    double DajZ() const{
        return NepreklapajucaKugla::z;
    }
    std::tuple<double,double,double> DajCentar() const{
        return {std::make_tuple(NepreklapajucaKugla::x,NepreklapajucaKugla::y,NepreklapajucaKugla::z)};
    }
    double DajPoluprecnik() const{
        return NepreklapajucaKugla::r;
    }
    double DajPovrsinu() const{
        return 4*NepreklapajucaKugla::r*NepreklapajucaKugla::r*PI;
    }
    double DajZapreminu() const{
        return 4./3*NepreklapajucaKugla::r*NepreklapajucaKugla::r*NepreklapajucaKugla::r*PI;
    }
    NepreklapajucaKugla &PostaviX(double x){
        NepreklapajucaKugla::x=x;
        return *this;
    }
    NepreklapajucaKugla &PostaviY(double y){
        NepreklapajucaKugla::y=y;
        return *this;
    }
    NepreklapajucaKugla &PostaviZ(double z){
        NepreklapajucaKugla::z=z;
        return *this;
    }
    NepreklapajucaKugla &PostaviCentar(double x, double y, double z){
        NepreklapajucaKugla::x=x;
        NepreklapajucaKugla::y=y;
        NepreklapajucaKugla::z=z;
        return *this;
    }
    NepreklapajucaKugla &PostaviCentar(std::tuple<double, double, double> &centar){
        NepreklapajucaKugla::x=std::get<0>(centar);
        NepreklapajucaKugla::y=std::get<1>(centar);
        NepreklapajucaKugla::z=std::get<2>(centar);
        return *this;
    }
    NepreklapajucaKugla &PostaviPoluprecnik(double r){
        NepreklapajucaKugla::r=r;
        return *this;
    }
    void Ispisi() const{
        std::cout<<"{("<<NepreklapajucaKugla::x<<","<<NepreklapajucaKugla::y<<","<<NepreklapajucaKugla::z<<"),"<<NepreklapajucaKugla::r<<"}"<<std::endl;
    }
    void Transliraj(double delta_x, double delta_y, double delta_z){
        NepreklapajucaKugla::x+=delta_x;
        NepreklapajucaKugla::y+=delta_y;
        NepreklapajucaKugla::z+=delta_z;
    }
    bool DaLiSadrzi(const NepreklapajucaKugla &k) const{
        NepreklapajucaKugla k1;
        k1.PostaviCentar(NepreklapajucaKugla::x,NepreklapajucaKugla::y,NepreklapajucaKugla::z);
        k1.PostaviPoluprecnik(NepreklapajucaKugla::r);
        std::cout<<RastojanjeCentara(k1,k);
        return (RastojanjeCentara(k1,k)<fabs(k1.r-k.r) && k.r<k1.r);
    }
    friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
};
double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){
    return sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z));
}
class SistemKugli{
    std::vector<std::shared_ptr<NepreklapajucaKugla>> elementi;
    public:
    SistemKugli(){}
    void RegistrujElement(NepreklapajucaKugla *e){
        elementi.push_back(std::shared_ptr<NepreklapajucaKugla>(e));
    }
    void SortirajPoPovrsini(){
        std::sort(std::begin(elementi),std::end(elementi),[](std::shared_ptr<NepreklapajucaKugla> k1,std::shared_ptr<NepreklapajucaKugla> k2){return k1->DajPovrsinu()<k2->DajPovrsinu();});
    }
    void IspisiSve(){
        std::for_each(std::begin(elementi),std::end(elementi),[](std::shared_ptr<NepreklapajucaKugla> k){return k->Ispisi();});
    }
};
int main ()
{
    try{
        int n;
        std::cout<<"Unesite broj kugla: ";
        std::cin>>n;
        SistemKugli s;
        for(int i=0; i<n; i++){
            double x,y,z,r;
            std::cout<<"Unesite centar "<<i+1<<". kugle: ";
            std::cin.ignore(1000,'\n');
            std::cin>>x>>y>>z;
            std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
            std::cin>>r;
            while(!std::cin || r<0){
                std::cout<<"Ilegalan poluprecnik";
                std::cin.clear();
                std::cin.ignore(1000,'\n');
                std::cout<<std::endl;
                std::cout<<"Unesite centar "<<i+1<<". kugle: ";
                std::cin>>x>>y>>z;
                std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
                std::cin>>r;
            } 
            s.RegistrujElement(new NepreklapajucaKugla(x,y,z,r));
        }
        std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<std::endl;
        s.SortirajPoPovrsini();
        s.IspisiSve();
    }catch(std::domain_error Izuzetak){
        std::cout<<Izuzetak.what()<<std::endl;
    }
	return 0;
}
