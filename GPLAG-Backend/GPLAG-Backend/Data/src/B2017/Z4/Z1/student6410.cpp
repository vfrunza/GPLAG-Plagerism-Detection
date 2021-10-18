#include <iostream>
#include <cmath>
#include <stdexcept>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <type_traits>
#include <tuple>
#include <memory>

const double pi(4*atan(1));
const double eps(1e-10);
static bool postoji;


class Kugla{
     double x=0,y=0,z=0;
     double r;
      public: 
     explicit Kugla (double r=0): r(r){
          if(r<0) throw std::domain_error ("Ilegalan poluprecnik");
          else 
              PostaviPoluprecnik(r);
          
     }
     Kugla(double x, double y, double z, double r=0){
          if(r<0) throw std::domain_error("Ilegalan poluprecnik");
          else{
               PostaviX(x);
               PostaviY(y);
               PostaviZ(z);
               PostaviPoluprecnik(r);
          }
          
     }
explicit Kugla(const std::tuple<double, double, double> &centar, double r=0){
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
             PostaviX(x);
               PostaviY(y);
               PostaviZ(z);
     return *this;
}
Kugla &PostaviCentar(const std::tuple<double, double, double> &centar){
             x=std::get<0>(centar);
               y=std::get<1>(centar);
               z=std::get<2>(centar);
               return *this;
}

Kugla &PostaviPoluprecnik(double r){
     Kugla::r=r;
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
friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2){
     if(abs(k1.x-k2.x)>(eps*(abs(k1.x)+abs(k2.x))) || 
     abs(k1.y-k2.y)>(eps*(abs(k1.y)+abs(k2.y))) || 
     abs(k1.z-k2.z)>(eps*(abs(k1.z)+abs(k2.z))) || 
     abs(k1.r-k2.r)>(eps*(abs(k1.r)+abs(k2.r)))) return false;
     return true;
}
friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2){
     if (abs(k1.r-k2.r)>(eps*(abs(k1.r)+abs(k2.r)))) return false;
     return true;
}
friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2){
    if(abs(k1.x-k2.x)>(eps*(abs(k1.x)+abs(k2.x))) 
    || abs(k1.y-k2.y)>(eps*(abs(k1.y)+abs(k2.y))) 
    || abs(k1.z-k2.z)>(eps*(abs(k1.z)+abs(k2.z))))
    return false;
    return true;
}
friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2){
     double udaljenost(sqrt(pow((k2.x-k1.x),2)+pow((k2.y-k1.y),2)+pow((k2.z-k1.z),2)));
     return (fabs((k1.r+k2.r) - udaljenost)<eps*fabs(k1.r+k2.r));
}
friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2){
     double udaljenost(sqrt(pow((k2.x-k1.x),2)+pow((k2.y-k1.y),2)+pow((k2.z-k1.z),2)));
     return (fabs((k1.r-k2.r) - udaljenost)<eps*fabs(k1.r-k2.r));
}
friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2){
     double udaljenost(sqrt(pow((k2.x-k1.x),2)+pow((k2.y-k1.y),2)+pow((k2.z-k1.z),2)));
     return ((fabs(k1.r-k2.r)<udaljenost));
}
friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2){ 
     double udaljenost(sqrt(pow((k2.x-k1.x),2)+pow((k2.y-k1.y),2)+pow((k2.z-k1.z),2)));
     return ((fabs(k1.r-k2.r)<udaljenost) && (fabs(k1.r+k2.r) > udaljenost));
}
bool DaLiSadrzi(const Kugla &k) const{
      double udaljenost(sqrt(pow((k.x-x),2) + pow((k.y-y),2) + pow((k.z-z),2)));
            return (fabs(k.r-r)-udaljenost<0);
}

friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2){
     return (sqrt(pow((k2.x-k1.x),2) + pow((k2.y-k1.y),2) + pow((k2.z-k1.z),2)));
} };



int main (){
    int n;
    std::cout<<"Unesite broj kugla: " ;
   while((!(std::cin>>n)) || n<=0){
         std::cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;
         std::cin.clear();
         std::cin.ignore(1000,'\n');
        
    }
   std::vector<std::shared_ptr<Kugla>> vektor;
    try {   
        for(int i=0;i<n;i++) {
            double x,y,z,r;
            std::cout<<"Unesite centar "<<i+1<<". kugle: ";
            if(!(std::cin>>x>>y>>z)){
                 std::cout<<"Neispravan centar"<<std::endl;
                 std::cin.clear();
                 std::cin.ignore(1000,'\n');
                 i--;
                continue;
            }
            std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
            if(!(std::cin>>r) || r<0){
                 std::cout<<"Ilegalan poluprecnik"<<std::endl;
                 std::cin.clear();
                 std::cin.ignore(1000,'\n');
                 i--;
                 continue;
            }
            
            vektor.push_back(std::make_shared<Kugla>(x,y,z,r)) ;
             
        }
           
        
    }
    
    catch (...) {
        std::cout<<"Problemi sa memorijom!";
    }
    
 std::sort(vektor.begin(),vektor.end(),[](std::shared_ptr<Kugla> k1,std::shared_ptr<Kugla> k2){
        return (*k1).DajZapreminu()<(*k2).DajZapreminu();
    } );
    
   std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double delta_x,delta_y,delta_z;
  if(!(std::cin>>delta_x)  || delta_x<0){
                 std::cout<<"Neispravni parametri translacije, unesite ponovo!"<<std::endl;
                 std::cin.clear();
                 std::cin.ignore(1000,'\n');
            }
 if(!(std::cin>>delta_y) || delta_y<0){
                 std::cout<<"Neispravni parametri translacije, unesite ponovo!"<<std::endl;
                 std::cin.clear();
                 std::cin.ignore(1000,'\n');
            }
     if(!(std::cin>>delta_z) || delta_z<0){
                 std::cout<<"Neispravni parametri translacije, unesite ponovo!"<<std::endl;
                 std::cin.clear();
                 std::cin.ignore(1000,'\n');
            }
     std::transform(vektor.begin(),vektor.end(),vektor.begin(),[delta_x,delta_y,delta_z](std::shared_ptr<Kugla> k) { 
        (*k).Transliraj(delta_x,delta_y,delta_z);
        return k;
    } );
    
    
    std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<std::endl;
    std::for_each(vektor.begin(),vektor.end(),[](std::shared_ptr<Kugla> k) {
        (*k).Ispisi(); 
    }); 


  std::cout<<"Kugla sa najvecom povrsinom je: "; 
   auto max_el(std::max_element(vektor.begin(),vektor.end(),[](std::shared_ptr<Kugla> k1,std::shared_ptr<Kugla> k2){
        return (*k1).DajPovrsinu()<(*k2).DajPovrsinu();
    }));
    (*(*max_el)).Ispisi(); 
   
    auto pocetak(vektor.begin());
    auto kraj(vektor.end());

    std::for_each(pocetak,kraj-1,[pocetak,kraj](std::shared_ptr<Kugla> k1){
        std::for_each(pocetak+1,kraj,[k1,pocetak](std::shared_ptr<Kugla> k2) {;
            if(DaLiSeSijeku(*k1,*k2)) {
                std::cout<<"Presjecaju se kugle: "; 
                (*k1).Ispisi();
                (*k2).Ispisi();
                postoji=true;
            }
        });
    });
    if(!postoji) std::cout<<"Ne postoje kugle koje se presjecaju!"; 
    
	return 0;
}
