#include <iostream>
#include <cmath>
#include <stdexcept>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <type_traits> 
#include <tuple>
const double pi(4*atan(1));
const double eps(1e-10);
class NepreklapajucaKugla{
     double x=0,y=0,z=0;
     double r;
      public: 
     explicit NepreklapajucaKugla (double r=0): r(r){
          if(r<0) throw std::domain_error ("Ilegalan poluprecnik");
          else 
              PostaviPoluprecnik(r);
          
     }
     NepreklapajucaKugla(double x, double y, double z, double r=0){
          if(r<0) throw std::domain_error("Ilegalan poluprecnik");
          else{
               PostaviX(x);
               PostaviY(y);
               PostaviZ(z);
               PostaviPoluprecnik(r);
          }
          
     }
explicit NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r=0){
     if(r<0) throw std::domain_error("Ilegalan poluprecnik");
          else{
               x=std::get<0>(centar);
               y=std::get<1>(centar);
               z=std::get<2>(centar);
               PostaviPoluprecnik(r);
     
}}
double DajX() const {return x;}
double DajY() const {return y;}
double DajZ() const {return z;}
std::tuple<double, double, double> DajCentar() const{
    std::tuple<double, double, double> centar{x,y,z};
    return centar;
}
double DajPoluprecnik() const {return r;}
double DajPovrsinu() const {
     return (4*pi*r*r);
}
double DajZapreminu() const{
     return ((4/3.)*pi*r*r*r);
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
     
}
NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar){}
NepreklapajucaKugla &PostaviPoluprecnik(double r){
     NepreklapajucaKugla::r=r;
     return *this;
}
void Ispisi() const{ 
     std::cout <<"{("<<x<<","<<y <<","<< z<<"),"<<r<<"}"<<std::endl; 
     
}
void Transliraj(double delta_x, double delta_y, double delta_z){
     x+=delta_x; 
     y+=delta_y; 
     z+=delta_z;
}
friend bool DaLiSuIdenticne(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){
     return (k1.x==k2.x && k1.y==k2.y && k1.z==k2.z && k1.r==k2.r);
}
friend bool DaLiSuPodudarne(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){
     return (k1.r==k2.r);
}
friend bool DaLiSuKoncentricne(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){
     return (k1.x==k2.x && k1.y==k2.y && k1.z==k2.z);
}
friend bool DaLiSeDodirujuIzvana(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){
     double udaljenost(sqrt(pow((k2.x-k1.x),2)+pow((k2.y-k1.y),2)+pow((k2.z-k1.z),2)));
     return (fabs((k1.r+k2.r) - udaljenost)<eps*fabs(k1.r+k2.r));
}
friend bool DaLiSeDodirujuIznutra(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){
     double udaljenost(sqrt(pow((k2.x-k1.x),2)+pow((k2.y-k1.y),2)+pow((k2.z-k1.z),2)));
     return (fabs((k1.r-k2.r) - udaljenost)<eps*fabs(k1.r-k2.r));
}
friend bool DaLiSePreklapaju(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){
     double udaljenost(sqrt(pow((k2.x-k1.x),2)+pow((k2.y-k1.y),2)+pow((k2.z-k1.z),2)));
     return ((fabs(k1.r-k2.r)<udaljenost));
}
friend bool DaLiSeSijeku(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){
     double udaljenost(sqrt(pow((k2.x-k1.x),2)+pow((k2.y-k1.y),2)+pow((k2.z-k1.z),2)));
     return ((fabs(k1.r-k2.r)<udaljenost) && (fabs(k1.r+k2.r) > udaljenost));
}
bool DaLiSadrzi(const NepreklapajucaKugla &k) const{
      double udaljenost(sqrt(pow((k.x-x),2) + pow((k.y-y),2) + pow((k.z-z),2)));
            return (fabs(k.r-r)-udaljenost<0);
}

friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){
     return (sqrt(pow((k2.x-k1.x),2) + pow((k2.y-k1.y),2) + pow((k2.z-k1.z),2)));
} };
int main (){
      std::cout<<"Unesite broj nepreklapajucaKugla: " ;
    int n ;
    std::cin>>n ;
    std::vector<NepreklapajucaKugla*> vektor;
    try {
        for(int i=0;i<n;i++) {
            double x,y,z,r;
            std::cout<<"Unesite centar "<<i+1<<". kugle: ";
            std::cin>>x>>y>>z;
            std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
            std::cin>>r ;
            try {
                vektor.push_back(new NepreklapajucaKugla(x,y,z,r)) ;
            }
             catch (std::domain_error e) {
        std::cout<<e.what()<<std::endl;
       i--;
    }
           
        }
    }
    
    catch (...) {
        std::cout<<"Problemi sa memorijom!";
    }
    
    //sort 
    for(int i=0; i<vektor.size(); i++){
         for(int j=0; j<vektor.size(); j++){
              NepreklapajucaKugla *temp;
              double Zx,Zy;
              Zx=vektor[i]->DajZapreminu();
              Zy=vektor[j]->DajZapreminu();
              if(Zy>Zx){
                   temp=vektor[j];
                   vektor[j]=vektor[i];
                   vektor[i]=temp;
              }
         }
    }
    
    
    std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double delta_x,delta_y,delta_z;
    std::cin>>delta_x;
    std::cin>>delta_y;
    std::cin>>delta_z;
    for(int i=0; i<vektor.size(); i++){
         vektor[i]->Transliraj(delta_x,delta_y,delta_z);
    }
    
   //std::transform(vektor[0], vektor[0]+n, vektor[0], [&] (NepreklapajucaKugla k)->NepreklapajucaKugla { k.Transliraj(delta_x,delta_y,delta_z); return k; });
    std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<std::endl;
   for(int i=0; i<vektor.size(); i++){
         vektor[i]->Ispisi();
    }
   // std::for_each(vektor[0], vektor[0]+n, [] (NepreklapajucaKugla k)->void{ k.Ispisi(); });
    double najvecaP=0;
    int mjesto=0;
    for(int i=0;i<vektor.size();i++) {
            double povrsina=0;
            povrsina=vektor[i]->DajPovrsinu();
            if(povrsina>najvecaP) {najvecaP=povrsina;
                 mjesto=i;
            }
    }
    
    
    //auto najveci(std::max_element(vektor[0],vektor[0]+n, [](const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2)->bool{return k1.DajPovrsinu()<k2.DajPovrsinu();}));
    std::cout<<"NepreklapajucaKugla sa najvecom povrsinom je: "; 
    //(*najveci).Ispisi();
    vektor[mjesto]->Ispisi();
    
    bool postoji(false);
    for(int i=0;i<vektor.size();i++) {
        for(int j=i;j<vektor.size();j++) {
            if(DaLiSeSijeku(*vektor[i], *vektor[j])) {
                std::cout<<"Presjecaju se kugle: ";
                vektor[i]->Ispisi();
                vektor[j]->Ispisi();
                postoji=true;
            }
        }
    }
    if(!postoji) std::cout<<"Ne postoje kugle koje se presjecaju!" ;
    for(int i=0;i<vektor.size();i++) {
        delete vektor[i];
    }
	return 0;
}
