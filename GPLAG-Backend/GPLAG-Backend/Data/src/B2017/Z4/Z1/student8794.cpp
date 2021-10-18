/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <tuple>
#include <stdexcept>
#include <memory>
#include <cmath>
#include <vector>
#include <algorithm>

const double PI=4*atan(1);
const double epsilon=0.0000000001;
class Kugla{
    
double r ,x,y,z;

public:

explicit Kugla(double r=0) {
   
    if(r<0) throw std::domain_error ("Ilegalan poluprecnik\n");
    Kugla::x=0;
    Kugla::y=0;
    Kugla::z=0;
    Kugla::r=r;
}
Kugla(double x, double y, double z, double r = 0){
    if(r<0) throw std::domain_error("Ilegalan poluprecnik\n");
    Kugla::x=x;
    Kugla::y=y;
    Kugla::z=z;
    Kugla::r=r;
}
explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0){
    if(r<0) throw std::domain_error("Ilegalan poluprecnik\n");
    
    Kugla::x=std::get<0>(centar);
    Kugla::y=std::get<1>(centar);
    Kugla::z=std::get<2>(centar);
    Kugla::r=r;
    
}
double DajX() const {
    return x;
}
double DajY() const{
    return y;
}
double DajZ() const{
    return z;
} 
std::tuple<double, double, double> DajCentar() const{
    
    return std::make_tuple('x','y','z');
}
double DajPoluprecnik() const{
    return r;
}
double DajPovrsinu() const {
    
    return 4*r*r*PI;
}; 
double DajZapreminu() const{
    
    return (4*r*r*r*PI)/3;
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
Kugla &PostaviCentar(const std::tuple<double, double, double> &centar){
    Kugla::x=std::get<0>(centar);
    Kugla::y=std::get<1>(centar);
    Kugla::z=std::get<2>(centar);
    Kugla::r=r;
     return *this;

}
Kugla &PostaviPoluprecnik(double r) {
    Kugla::r=r;
    return *this;
}
void Ispisi() const {
    //{( x,y ,z ), r}
    std::cout<<"{("<<DajX()<<","<<DajY()<<","<<DajZ()<<"),"<<DajPoluprecnik()<<"}\n";
    
}
void Transliraj(double delta_x, double delta_y, double delta_z){
    
    Kugla::x=x+delta_x;
    Kugla::y=y+delta_y;
    Kugla::z=z+delta_z;
}
friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2){
    // |   −   | < ε (|   |+|   |) 
    if(!(fabs(k1.x-k2.x)<epsilon*(fabs(k1.x)+fabs(k2.x)))&&(fabs(k1.r-k2.r)<epsilon*(fabs(k1.r)+fabs(k2.r))) && (fabs(k1.y-k2.y)<epsilon*(fabs(k1.y)+fabs(k2.y))) && (fabs(k1.z-k2.z)<epsilon*(fabs(k1.z)+fabs(k2.z)))) return false;
    return true ;
}
friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2){
    if(!(fabs(k1.r-k2.r)<epsilon*(fabs(k1.r)+fabs(k2.r)))) return false;
    return true ;
}
friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2){
    
    if(!(fabs(k1.x-k2.x)<epsilon*(fabs(k1.x)+fabs(k2.x)))&& (fabs(k1.y-k2.y)<epsilon*(fabs(k1.y)+fabs(k2.y))) && (fabs(k1.z-k2.z)<epsilon*(fabs(k1.z)+fabs(k2.z)))) return false;
    return true;
}
friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2){
    //udaljenost izmedju dva centra mora biti jednaka zbiru poluprecnika
    double udaljenost(sqrt(pow(k2.x-k1.x,2)+ pow(k2.y-k1.y,2)+ pow(k2.z-k1.z,2)));
    if((fabs(udaljenost-(k1.r + k2.r))<epsilon*(fabs(udaljenost)+fabs(k1.r + k2.r)))) return true ;
    
     return false;
}
friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2){

    double udaljenost(sqrt(pow(k2.x-k1.x,2)+ pow(k2.y-k1.y,2)+ pow(k2.z-k1.z,2)));
    if((udaljenost<k1.r + k2.r) && (udaljenost>(abs(k1.r-k2.r)))) return true;
    return false;
}

friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2){
    
   if( DaLiSeSijeku(k1,k2)) return true;
   if(k1.DaLiSadrzi(k2)) return true;
   if(k2.DaLiSadrzi(k1)) return true;
   if(DaLiSeDodirujuIznutra(k1,k2)) return true ;
   if(DaLiSuIdenticne(k1,k2)) return true ;
   return false ;
    
}

friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2){
    
    double udaljenost (sqrt(pow(k2.x-k1.x,2)+ pow(k2.y-k1.y,2)+ pow(k2.z-k1.z,2)));
    if((udaljenost<k1.r + k2.r) && (udaljenost>(abs(k1.r-k2.r)))) return true;
    return false;
}

bool DaLiSadrzi(const Kugla &k) const{
    double udaljenost=(sqrt(pow(Kugla::x-k.DajX(),2)+ pow(Kugla::y-k.DajY(),2)+ pow(Kugla::z-k.DajZ(),2)));
    if(udaljenost<abs(Kugla::r-k.DajPoluprecnik())) return true;
    return false ;
}
friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2){
    
   
    return (sqrt(pow(k2.x-k1.x,2)+ pow(k2.y-k1.y,2)+ pow(k2.z-k1.z,2)));
}
};

int main ()

{
    double n ;
    
    std::cout<<"Unesite broj kugla: ";
    std::cin>> n;
    
    while (n<=0 || !std::cin)  {
    std::cout<<"Neispravan broj kugli, unesite ponovo!\n"; 
    std::cin.clear();
    std::cin.ignore(1000,'\n');
    std::cin>>n ;
    
    }
    std::vector<std::shared_ptr<Kugla>> v;
    v.resize(n);
    
    for(int i{0};i<n;i++) {
        double x,y,z,r;
        
        std::cout<<"Unesite centar "<< i+1 <<". kugle: ";
        std::cin>>x>>y>>z ;
       if(!std::cin) {
           i--;
           std::cout << "Neispravan centar" << std::endl; 
            std::cin.clear();
           std::cin.ignore(10000,'\n');
           continue ;
       }
        std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
        std::cin>> r;
        if(!std::cin || r < 0) {
            std::cout << "Ilegalan poluprecnik" << std::endl; 
           i--;
           std::cin.clear();
           std::cin.ignore(10000,'\n');
           continue ;
       }
        try{
        v[i]=std::make_shared<Kugla>(x,y,z,r);
        }
        catch(std::domain_error d) {
            std::cout<<d.what();
            i--;
        }
        
    }
    double dx,dy,dz;
    std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    std::cin>> dx>>dy>>dz ;
    while(!std::cin){
        std::cout << "Neispravni parametri translacije, unesite ponovo!" << std::endl; 
        std::cin.clear();
        std::cin.ignore(10000, '\n'); 
        std::cin >> dx >> dy >> dz; 
    }
   // std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: " ;
    std::transform(v.begin(), v.end(), v.begin(),[dx,dy,dz](std::shared_ptr<Kugla> pomocna){
    pomocna->Transliraj(dx,dy,dz);
    return pomocna;
    });
    std::sort(v.begin(), v.end(),[](std::shared_ptr<Kugla> pomocna1,std::shared_ptr<Kugla> pomocna2){
    return pomocna1->DajZapreminu()<pomocna2->DajZapreminu();
    });
    std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: \n";
    
    std::for_each(v.begin(), v.end(),[](std::shared_ptr<Kugla> pomocna1){
        pomocna1->Ispisi();
    //std::cout<<"{("<<pomocna1->DajX()<<","<<pomocna1->DajY()<<","<<pomocna1->DajZ()<<") ,"<<pomocna1->DajPoluprecnik()<<"}";
    });
    
    auto maxpovrsina=std::max_element(v.begin(), v.end(),[](std::shared_ptr<Kugla> pomocna1,std::shared_ptr<Kugla> pomocna2) {
        
        return pomocna1->DajPovrsinu()<pomocna2->DajPovrsinu();
    });
  
  std::cout<<"Kugla sa najvecom povrsinom je: ";
  (*maxpovrsina)->Ispisi();
  static bool stanje=false;
  static std::vector<std::pair<std::shared_ptr<Kugla>,std::shared_ptr<Kugla>>> parovikugla ;
  std::for_each(v.begin(),   v.end(),    [v] (std::shared_ptr<Kugla> pomocna1){
    //decltype(v.begin()) iter(&pomocna1);
    //std::remove_reference<decltype(iter)>(iter);
    
    std::for_each(v.begin(), v.end(),[pomocna1,v](std::shared_ptr<Kugla> pomocna2){
    
     if(DaLiSeSijeku(*pomocna1,*pomocna2)) {
        auto pomocnipar=std::make_pair(pomocna2,pomocna1);
        auto pomocnipar1=std::make_pair(pomocna1,pomocna2);
        auto iteratorpokvektoru=std::find(parovikugla.begin(),parovikugla.end(),pomocnipar);
        if(iteratorpokvektoru==parovikugla.end()){
     parovikugla.push_back(pomocnipar1);
     std::cout<<"Presjecaju se kugle: "; 
     stanje=true;
     pomocna1->Ispisi(); pomocna2->Ispisi(); }
     }  
     });
                                                                              });
  if (stanje==false) std::cout<<"Ne postoje kugle koje se presjecaju!\n";

	return 0;
	
}
