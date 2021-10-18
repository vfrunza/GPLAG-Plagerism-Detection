/B2017/2018: Zadaća 4, Zadatak 1
//Prolazi 17/23 ATT ipravljeno sad prolazi 22/23
//Ostao još jedan ATT koji poziva funkciju DaLiSePoklapaju nije OK!
#include <iostream>
#include <tuple>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>
#define PI (4*atan(1))
const double epsilon = 1E-10;
class Kugla{
    double x, y, z, r;
    public:
    explicit Kugla(double r=0){
        if(r < 0 ) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::x=0;
        Kugla::y=0;
        Kugla::z=0;
        Kugla::r=r;
    }
    Kugla(double x, double y, double z, double r=0){
        if(r < 0 ) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::x=x;
        Kugla::y=y;
        Kugla::z=z;
        Kugla::r=r;
    }
    explicit Kugla(const std::tuple<double, double, double> &centar, double r=0){
        if(r < 0 ) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::x=std::get<0>(centar);
        Kugla::y=std::get<1>(centar);
        Kugla::z=std::get<2>(centar);
        Kugla::r=r;
    }
    double DajX() const{
        return Kugla::x;
    }
    double DajY() const{
        return Kugla::y;
    }
    double DajZ() const{
        return Kugla::z;
    }
    std::tuple<double,double,double> DajCentar() const{
        return {std::make_tuple(Kugla::x,Kugla::y,Kugla::z)};
    }
    double DajPoluprecnik() const{
        return Kugla::r;
    }
    double DajPovrsinu() const{
        return 4*Kugla::r*Kugla::r*PI;
    }
    double DajZapreminu() const{
        return 4./3*Kugla::r*Kugla::r*Kugla::r*PI;
    }
    Kugla &PostaviX(double x){
        Kugla::x=x;
        return *this;
    }
    Kugla &PostaviY(double y){
        Kugla::y=y;
        return *this;
    }
    Kugla &PostaviZ(double z){
        Kugla::z=z;
        return *this;
    }
    Kugla &PostaviCentar(double x, double y, double z){
        Kugla::x=x;
        Kugla::y=y;
        Kugla::z=z;
        return *this;
    }
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar){ //Greska pada 4 ATT zaboravio const dodati, sad je OK!
        Kugla::x=std::get<0>(centar);
        Kugla::y=std::get<1>(centar);
        Kugla::z=std::get<2>(centar);
        return *this;
    }
    Kugla &PostaviPoluprecnik(double r){
        if(r < 0 ) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::r=r;
        return *this;
    }
    void Ispisi() const{
        std::cout<<"{("<<Kugla::x<<","<<Kugla::y<<","<<Kugla::z<<"),"<<Kugla::r<<"}"<<std::endl;
    }
    void Transliraj(double delta_x, double delta_y, double delta_z){
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
    bool DaLiSadrzi(const Kugla &k) const{
        Kugla k1;
        k1.PostaviCentar(Kugla::x,Kugla::y,Kugla::z);
        k1.PostaviPoluprecnik(Kugla::r);
        return !(RastojanjeCentara(k1,k)<fabs(k1.r-k.r) && k.r<k1.r);
    }
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);
};
bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2){
    return (fabs(k1.x-k2.x)<epsilon && fabs(k1.y-k2.y)<epsilon && fabs(k1.z-k2.z)<epsilon && fabs(k1.r-k2.r)<epsilon);
}
bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2){
    return (fabs(k1.r-k2.r)<epsilon);
}
bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2){
    return (fabs(k1.x-k2.x)<epsilon && fabs(k1.y-k2.y)<epsilon && fabs(k1.z-k2.z)<epsilon);
}
bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2){
    return (fabs(RastojanjeCentara(k1,k2)-fabs(k1.r+k2.r))<epsilon && DaLiSuIdenticne(k1,k2)==0);
}
bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2){
    return (fabs(RastojanjeCentara(k1,k2)-fabs(k1.r-k2.r))<epsilon && DaLiSuIdenticne(k1,k2)==0);
}
bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2){
    return (RastojanjeCentara(k1,k2)<fabs(k1.r-k2.r)); //Nije okej ova funkcija pada ATT
}
bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2){
    return (RastojanjeCentara(k1,k2)<fabs(k1.r+k2.r) && RastojanjeCentara(k1,k2)>fabs(k1.r-k2.r));
}
double RastojanjeCentara(const Kugla &k1, const Kugla &k2){
    return sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z));
}
class SistemKugli{
    std::vector<std::shared_ptr<Kugla>> elementi;
    public:
    SistemKugli(){}
    void RegistrujElement(Kugla *e){
        elementi.push_back(std::shared_ptr<Kugla>(e));
    }
    void TranslirajSve(double delta_x, double delta_y, double delta_z){
        std::transform(std::begin(elementi),std::end(elementi),std::begin(elementi), [delta_x,delta_y,delta_z](std::shared_ptr<Kugla> p){p->Transliraj(delta_x,delta_y,delta_z);return p;});
        
    }
    void SortirajPoZapreminama(){
        std::sort(std::begin(elementi),std::end(elementi),[](std::shared_ptr<Kugla> k1,std::shared_ptr<Kugla> k2){return k1->DajZapreminu()<k2->DajZapreminu();});
    }
    std::shared_ptr<Kugla> DajNajvecuPovrsinu(){
        return *(std::max_element(std::begin(elementi),std::end(elementi),[](std::shared_ptr<Kugla> k1,std::shared_ptr<Kugla> k2){return k1->DajPovrsinu()<k2->DajPovrsinu();}));
    }
    void Presjek(){
        auto it=elementi;
        if(std::distance(std::begin(elementi),std::end(elementi))==1) std::cout<<"Ne postoje kugle koje se presjecaju!";
        std::for_each(std::begin(elementi),std::end(elementi),[it](std::shared_ptr<Kugla> k){
            int brojac(std::distance(std::begin(it),std::find(std::begin(it),std::end(it),k))+1);
            return std::for_each(std::begin(it)+(brojac++), std::end(it),[k,brojac,it](std::shared_ptr<Kugla> k1){
                if(DaLiSeSijeku(*k1,*k)) std::cout<<"Presjecaju se kugle: ",k->Ispisi(), k1->Ispisi();
                else if(DaLiSeSijeku(*k,*k1)==0 && DaLiSuIdenticne(*k,*k1)==0 && brojac==std::distance(std::begin(it),std::end(it))-1) std::cout<<"Ne postoje kugle koje se presjecaju!";
            });
        });
    }
    void Test(){
        auto k1=*elementi[0];
        auto k2=*elementi[1];
        std::cout<<"Identicne su: "<<DaLiSuIdenticne(k1,k2);
        std::cout<<std::endl;
        std::cout<<"Podudarne  su: "<<DaLiSuPodudarne(k1, k2);
        std::cout<<std::endl;
        std::cout<<"Koncentricne su: "<<DaLiSuKoncentricne(k1, k2);
        std::cout<<std::endl;
        std::cout<<"Dodiruju se izvana: "<<DaLiSeDodirujuIzvana(k1, k2);
        std::cout<<std::endl;
        std::cout<<"Dodiruju se iznutra: "<<DaLiSeDodirujuIznutra(k1, k2);
        std::cout<<std::endl;
        std::cout<<"Preklapaju se: "<<DaLiSePreklapaju(k1, k2);
        std::cout<<std::endl;
        std::cout<<"Sijeku se: "<<DaLiSeSijeku(k1, k2);
        std::cout<<std::endl;
    }
    void IspisiSve(){
        std::for_each(std::begin(elementi),std::end(elementi),[](std::shared_ptr<Kugla> k){return k->Ispisi();});
    }
};
int main ()
{
    try{
        int n;
        std::cout<<"Unesite broj kugla: ";
        do{
            std::cin>>n;
            if(n<=0 || !std::cin){
                std::cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;
                std::cin.clear();
                std::cin.ignore(1000,'\n');
            }
        }while(n<=0 || !std::cin);
        SistemKugli s{};
        for(int i=0; i<n; i++){
            double x,y,z,r;
            std::cin.ignore(1000,'\n');
            std::cout<<"Unesite centar "<<i+1<<". kugle: ";
            std::cin>>x>>y>>z;
            while(!std::cin){
                  std::cout<<"Neispravan centar"<<std::endl;
                  std::cin.clear();
                  std::cin.ignore(1000,'\n');
                  std::cout<<"Unesite centar "<<i+1<<". kugle: ";
                  std::cin>>x>>y>>z;
            }
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
            s.RegistrujElement(new Kugla(x,y,z,r));
        }
        //s.Test();
        int delta_x(0), delta_y(0), delta_z(0);
        std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
        do{
            std::cin>>delta_x>>delta_y>>delta_z;
            if(!std::cin){
                std::cout<<"Neispravni parametri translacije, unesite ponovo!"<<std::endl;
                std::cin.clear(); //Anomalija morao sam in. delte na nulu jer u slučaju da se unese prvo neseto sto nije broj pa onda nule javlja gresku cudne prirode ali samo u ATT 
                std::cin.ignore(1000,'\n');
            }
        }while(!std::cin);
        std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<std::endl;
        s.TranslirajSve(delta_x,delta_y,delta_z);
        s.SortirajPoZapreminama();
        s.IspisiSve();
        std::cout<<"Kugla sa najvecom povrsinom je: ";
        s.DajNajvecuPovrsinu()->Ispisi();
        s.Presjek();
    }catch(std::domain_error Izuzetak){
        std::cout<<Izuzetak.what()<<std::endl;
    }
	return 0;
}
