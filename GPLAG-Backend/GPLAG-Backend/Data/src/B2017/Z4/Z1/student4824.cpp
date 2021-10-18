/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdexcept>
#include <tuple>
#include <vector>
#include <memory>
#include <algorithm>
const double epsilon=0.000000001;
class Kugla {
    double x,y,z,r;
    public:
    explicit Kugla(double r=0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        else Kugla::r=r;
    }
    Kugla( double x, double y, double z, double r=0){ 
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        else {
        Kugla::r=r;
        Kugla::x=x;
        Kugla::y=y;
        Kugla::z=z;
        }
    }
    explicit Kugla( const std::tuple<double, double, double> &centar, double r=0){  
    Kugla::x=std::get<0>(centar);
    Kugla::y=std::get<1>(centar);
    Kugla::z=std::get<2>(centar);
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    Kugla::r=r;
    } 
double DajX() const { return x; }
double DajY() const { return y; }
double DajZ() const { return z; }
std::tuple<double, double, double > DajCentar()  const { 
    return std::tie(x,y,z);
}
double DajPoluprecnik() const { return r; }  
double DajPovrsinu() const { double povrsina=4*r*r*(4*atan(1)); return povrsina; }
double DajZapreminu() const {double zapremina=(4./3)*r*r*r*(4*atan(1)); return zapremina; }
Kugla &PostaviX(double x) { Kugla::x=x; }
Kugla &PostaviY(double y) { Kugla::y=y; }
Kugla &PostaviZ(double z) { Kugla::z=z; }
Kugla &PostaviCentar(double x, double y, double z) {  
    Kugla::x=x;
    Kugla::y=y;
    Kugla::z=z;
}
Kugla &PostaviCentar(std::tuple<double, double, double> &centar){  
    Kugla::x=std::get<0>(centar);
    Kugla::y=std::get<1>(centar);
    Kugla::z=std::get<2>(centar);
    
}
Kugla &PostaviPoluprecnik( double r) { 
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    Kugla::r=r;
}
void Ispisi() const { 
    std::cout<<"{"<<"("<<Kugla::DajX()<<","<<Kugla::DajY()<<","<<Kugla::DajZ()<<"),"<<Kugla::DajPoluprecnik()<<"}"<<std::endl;
}
void Transliraj (double delta_x, double delta_y, double delta_z){
    Kugla::x+=delta_x;
    Kugla::y+=delta_y;
    Kugla::z+=delta_z;
}
friend bool DaLiSuIdenticne( const Kugla &k1, const Kugla &k2){
    if(fabs(k1.r-k2.r)<epsilon && fabs(k1.x-k2.x)<epsilon && fabs(k1.y-k2.y)<epsilon && fabs(k1.z-k2.z)<epsilon) return true;
    else return false;
}
friend bool DaLiSuPodudarne (const Kugla &k1, const Kugla &k2) { 
    if(fabs(k1.r-k2.r)<epsilon) return true;
    else return false;
    
}
friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2) {
    if(fabs(k1.x-k2.x)<epsilon && fabs(k1.y-k2.y)<epsilon && fabs(k1.z-k2.z)<epsilon) return true;
    else return false;
}
friend bool DaLiSeDodirujuIzvana( const Kugla &k1, const Kugla &k2) {  
    if(fabs(sqrt(((k2.x-k1.x)*(k2.x-k1.x))+((k2.y-k1.y)*(k2.y-k1.y))+((k2.z-k1.z)*(k2.z-k1.z)))-fabs(k2.r+k1.r))<epsilon) return true;
    else return false;
}
friend bool DaLiSeDodirujuIznutra( const Kugla &k1, const Kugla &k2) {  
    if(fabs(sqrt(((k2.x-k1.x)*(k2.x-k1.x))+((k2.y-k1.y)*(k2.y-k1.y))+(k2.z-k1.z)))-fabs(k2.r-k1.r)<epsilon) return true;
    else return false;
}

friend bool DaLiSePreklapaju (const Kugla &k1, const Kugla &k2) {  
    if((DaLiSeSijeku(k1,k2)==true) || fabs(RastojanjeCentara(k1,k2)-(k1.r+k2.r))<epsilon) return true;
    else return false;
}
friend bool DaLiSeSijeku( const Kugla &k1, const Kugla &k2) {  
    if(((sqrt(((k2.x-k1.x)*(k2.x-k1.x))+((k2.y-k1.y)*(k2.y-k1.y))+((k2.z-k1.z)*(k2.z-k1.z)))-fabs(k2.r+k1.r))<epsilon) 
    && (sqrt(((k2.x-k1.x)*(k2.x-k1.x))+((k2.y-k1.y)*(k2.y-k1.y))+((k2.z-k1.z)*(k2.z-k1.z)))-fabs(k1.r-k2.r))>epsilon) return true;
    else return false;
}
bool DaLiSadrzi(const Kugla &k) const {  
    if(r>k.r && fabs(RastojanjeCentara(*this, k)-r)<epsilon) return true;
    else return false;
}
friend double RastojanjeCentara( const Kugla &k1, const Kugla &k2) {  
    double rastojanje= sqrt(((k2.x-k1.x)*(k2.x-k1.x))+((k2.y-k1.y)*(k2.y-k1.y))+((k2.z-k1.z)*(k2.z-k1.z)));
    return rastojanje;
}
};
int main ()
{
    double x(0),y(0),z(0),r(-1),delta_x(0),delta_y(0),delta_z(0);
    int n(0);
    std::cout<<"Unesite broj kugla: ";
    std::cin>>n;
    while (n<=0 || !(std::cin)){ 
        std::cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cin>>n; 
        
    }
    std::vector<std::shared_ptr<Kugla>>v(n);
    std::vector<std::shared_ptr<Kugla>>rez(n);
    int belaj(0);
    for( int i=0; i<n; i++) {
        do{
            belaj=0;
        std::cout<<"Unesite centar "<<i+1<<". kugle: ";
        std::cin>>x>>y>>z;
        while(!(std::cin)) {
            std::cout<<"Neispravan centar"<<std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout<<"Unesite centar "<<i+1<<". kugle: ";
            std::cin>>x>>y>>z;
        }
            std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
            std::cin>>r; 
            if(r<0 || !(std::cin)){ 
                std::cout<<"Ilegalan poluprecnik"<<std::endl;
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                belaj++;
            }
            
        }while(belaj!=0);
v[i]=std::make_shared<Kugla>(x,y,z,r);
    }
    
    std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    std::cin>>delta_x>>delta_y>>delta_z;
    while(!(std::cin)){
        std::cout<<"Neispravni parametri translacije, unesite ponovo!"<<std::endl;
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cin>>delta_x>>delta_y>>delta_z;
    }
   std::transform(v.begin(), v.end() , v.begin(), [delta_x, delta_y, delta_z ](std::shared_ptr<Kugla>k)
  {
     k->Transliraj(delta_x,delta_y,delta_z);
      return k;
  } ); 
  std::sort(v.begin(), v.end(), []( std::shared_ptr<Kugla>k1, std::shared_ptr<Kugla>k2) { return k2->DajZapreminu()>k1->DajZapreminu();});
  std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<std::endl;
  std::for_each(v.begin(), v.end(),[](std::shared_ptr<Kugla> k) {k->Ispisi();});
      std::cout<<"Kugla sa najvecom povrsinom je: ";
      auto p=std::max_element(v.begin(), v.end(), [](std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2){ return k1->DajPovrsinu()<k2->DajPovrsinu();});
      (*p)->Ispisi();
      int i(0);
      int ima(0);
	for_each(v.begin(), v.end(), [&ima,&i,n,&v]( std::shared_ptr<Kugla> k1) {
	    i++;
	    for_each(v.begin()+i, v.end(), [&i,k1,v,&ima](std::shared_ptr<Kugla> k2){
	        if(DaLiSeSijeku(*k1,*k2)==true){ 
	            std::cout<<"Presjecaju se kugle: ";
	            k1->Ispisi();
	            k2->Ispisi();
	        ima++;
	        } else {
	        ima=0;
	        }
	  	     ;})
	     ; }
	     );   
	     if(ima==0) std::cout<<"Ne postoje kugle koje se presjecaju!"<<std::endl;
	return 0;
}