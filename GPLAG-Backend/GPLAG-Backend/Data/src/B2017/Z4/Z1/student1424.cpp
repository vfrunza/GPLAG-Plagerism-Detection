/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <vector>
#include <cstdlib>
#include <memory>
#include <algorithm>
#include <stdexcept>
#include <tuple>
#include <cmath>

 const double PI(4*std::atan(1));
 const double eps(1e-10);
 bool Jednakost(double prvi, double drugi){
     return std::abs(prvi-drugi)<eps*(std::abs(prvi)+std::abs(drugi));
 }

class Kugla{
    double x,y,z, r;
    //friend bool Unos(Kugla &k);
    
    public:
    explicit Kugla(double r=0){
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::r=r;  Kugla::x=0; Kugla::y=0; Kugla::z=0;
        }
    Kugla(double x, double y, double z, double r=0): Kugla(r){
        Kugla::x=x; Kugla::y=y; Kugla::z=z;
    }
    explicit Kugla (const std::tuple<double, double, double>&centar, double r=0)
    : Kugla(std::get<0>(centar), std::get<1>(centar),std::get<2>(centar),r){}
  
    double DajX() const {return x;}
    double DajY() const {return y;}
    double DajZ() const {return z;}
    std::tuple <double, double, double> DajCentar () const { return std::make_tuple(x,y,z);}
    double DajPoluprecnik() const { return r;}
    double DajPovrsinu() const {return 4*PI*r*r;}
    double DajZapreminu() const { return double(4./3)*PI*r*r*r;}
    Kugla &PostaviX(double x) { Kugla::x=x; return *this;}
    Kugla &PostaviY(double y) { Kugla::y=y; return *this;}
    Kugla &PostaviZ(double z) { Kugla::z=z; return *this;}
    Kugla &PostaviCentar(double x, double y, double z) {Kugla::x=x; Kugla::y=y; Kugla::z=z; return *this;}
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar){  std::tie(x,y,z)=centar; return *this;}
    Kugla &PostaviPoluprecnik(double r){
    if(r<0) throw std::domain_error("Ilegalan poluprecnik"); Kugla::r=r; return *this;}
    //Provjeriti je li se ispisuje novi red u Ispisi
    void Ispisi() const {std::cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}"<<std::endl;}
    void Transliraj(double delta_x, double delta_y, double delta_z){ x+=delta_x; y+=delta_y;z+=delta_z;}
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIzvana (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
    friend bool  DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
    bool DaLiSadrzi(const Kugla &k) const{
        return DaLiSePreklapaju(*this, k) && !DaLiSeSijeku(*this, k) && (r>k.r || (Jednakost(r,k.r) && DaLiSeSijeku(*this, k)));}
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);
};
typedef std::shared_ptr<Kugla> pametni;
double RastojanjeCentara(const Kugla &k1, const Kugla &k2){
    return std::sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z));}
bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2){
   return (Jednakost(k1.r, k2.r) && Jednakost(k1.x, k2.x) && Jednakost(k1.y, k2.y) && Jednakost(k1.z, k2.z));}
bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2){ return Jednakost(k1.r, k2.r);}   
bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2){ 
    return (Jednakost(k1.x, k2.x) && Jednakost(k1.y, k2.y) && Jednakost(k1.z, k2.z));}
bool DaLiSeDodirujuIzvana (const Kugla &k1, const Kugla &k2){
    return Jednakost(k1.r+k2.r, RastojanjeCentara(k1,k2));}
bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2){
    return Jednakost(std::abs(k1.r-k2.r), RastojanjeCentara(k1,k2));}
 bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2){  
    return (k1.r+k2.r)>RastojanjeCentara(k1,k2);}
 bool  DaLiSeSijeku(const Kugla &k1, const Kugla &k2){
     double maksi(k1.r), mini(k2.r);
     if(k2.r>k1.r) {maksi=k2.r; mini=k1.r;};
     return (DaLiSePreklapaju(k1,k2) && (maksi<RastojanjeCentara(k1,k2)+mini));
 }
 template <typename NekiTip>
 bool ProvjeraUnosa(NekiTip &broj){
     std::cin>>broj;
     if(!std::cin ){//|| (std::cin.peek()!=' ' && std::cin.peek()!='\n')){
         std::cin.clear();
         std::cin.ignore(1000,'\n');
         return false;
     }
     return true;
}
 bool Unos(Kugla &k, int i){ 
     double r,x,y,z;
     std::cout<<"Unesite centar "<<i+1<<". kugle: ";
     if(!ProvjeraUnosa(x) || !ProvjeraUnosa(y) || !ProvjeraUnosa(z)) { std::cout<<"Neispravan centar"<<std::endl;
         return false;}
     std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
     if(!ProvjeraUnosa(r) || r<0) { std::cout<<"Ilegalan poluprecnik"<<std::endl;
         return false;}
     k.PostaviPoluprecnik(r);k.PostaviCentar(x,y,z);
     return true;
}

int main ()
{
    try{
    int n;
    
    std::cout<<"Unesite broj kugla: ";
    do{
   
        if(!ProvjeraUnosa(n) || n<=0) std::cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;
        else break;
    } while(true);
    //provjeriti treba li provjera za n i sta se desava za n=0
    std::vector<pametni> Kugle(n);
    for(int i=0;i<n;i++){
        Kugla a;
        if(Unos(a,i)){
            Kugle[i]=std::make_shared<Kugla>(a);
        }
        else {
            //std::cout<<"Neispravan unos;";
            i--;
        }
    }
    double delta_x,delta_y,delta_z;
    std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
do{    
    
    if(!ProvjeraUnosa(delta_x) || !ProvjeraUnosa(delta_y) || !ProvjeraUnosa(delta_z)) 
    std::cout<<"Neispravni parametri translacije, unesite ponovo!"<<std::endl;
    else break;} while(true);
    
    
    std::transform(Kugle.begin(), Kugle.end(), Kugle.begin(), [delta_x,delta_y,delta_z](pametni p)->pametni{
        (*p).Transliraj(delta_x,delta_y,delta_z); return p;
    });
     std::sort(Kugle.begin(), Kugle.end(), [](pametni p1, pametni p2){
        return p1->DajZapreminu()<p2->DajZapreminu();});
    
    std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti:"<<std::endl;
    std::for_each(Kugle.begin(), Kugle.end(), [](pametni p1)->void{
        //provjeriti gdje treba razmak ili novi red
        p1->Ispisi();
    }) ;
   
    std::vector<pametni>::iterator it(std::max_element(Kugle.begin(), Kugle.end(),[](pametni p1, pametni p2)->bool{
        return p1->DajPovrsinu()<p2->DajPovrsinu();})); 
        std::cout<<"Kugla sa najvecom povrsinom je: "; (*it)->Ispisi();
           int brojac(0),i(0);
    std::for_each(Kugle.begin(), Kugle.end(),[&brojac,Kugle,&i](pametni p1){
        std::for_each(Kugle.begin()+i, Kugle.end(), [&brojac, p1](pametni p2)->void{
            if(DaLiSeSijeku(*p1, *p2)){ brojac++;
             std::cout<<"Presjecaju se kugle: ";
            p1->Ispisi(); p2->Ispisi(); 
                
            }
        }); i++;
    });
    if(brojac==0) std::cout<<"Ne postoje kugle koje se presjecaju!";
  
    }
    catch(std::domain_error iz){
        std::cout<<iz.what();
    }
	return 0;
}
