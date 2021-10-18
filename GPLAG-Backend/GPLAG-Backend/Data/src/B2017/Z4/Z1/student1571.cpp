#include <iostream>
#include<utility>
#include <stdexcept>
#include<map>
#include<memory>
#include <vector> 
#include <cmath>
#include <algorithm>

const double PI(4*std::atan(1));
const double epsilon=0.0000000010;

class Kugla{
    double x,y,z;
    double r;
    
    public:
    explicit Kugla(double r=0){
        
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");    
        Kugla::r=r;
        Kugla::x=0;
        Kugla::y=0;
        Kugla::z=0;
           
     
 
    
    }
    Kugla(double x,double y,double z, double r=0){
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        
        Kugla::r=r;
        Kugla::x=x;
        Kugla::y=y;
        Kugla::z=z;
       
    }
    explicit  Kugla(const std::tuple<double,double,double>&centar,double r=0){
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::r=r;
        double a,b,c;
        std::tie(a,b,c)=centar;
        Kugla::x=a;
        Kugla::y=b;
        Kugla::z=c;
        
    
      
    }
    Kugla &PostaviPoluprecnik(double r){
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::r=r;
        return *this;
    }
    std::tuple<double,double,double> DajCentar() const {
        std::tuple<double,double,double> centar;
        centar=std::make_tuple(Kugla::x,Kugla::y,Kugla::z);
        return centar;
        
    }
    double DajPoluprecnik() const{
        return r;
    }
   double DajPovrsinu() const{
        
        return 4*r*r*PI;
        
    }
    double DajZapreminu() const{
        return (4/3.)*r*r*r*PI;
    }
    void Ispisi() const {
        std::cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}";
    }
    
    void Transliraj(double delta_x,double delta_y,double delta_z){
        Kugla::x+=delta_x;
        Kugla::y+=delta_y;
        Kugla::z+=delta_z;
    }
    
    friend bool DaLiSuIdenticne(const Kugla &k1,const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1,const Kugla &k2);
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
    bool DaLiSadrzi(const Kugla &k) const ;
    friend bool DaLiSuKocentricne (const Kugla &k1,const Kugla &k2);
    friend bool DaLiSeSijeku(const Kugla &k1,const Kugla &k2);
    friend bool DaLiSeDodirujuIzvana (const Kugla &k1,const Kugla &k2);
    friend double RastojanjeCentara(const Kugla &k1,const Kugla &k2);
    
    
    
};

bool DaLiSuIdenticne(const Kugla &k1,const Kugla &k2){
    if(fabs(k1.x-k2.x)<epsilon*(fabs(k1.x)+fabs(k2.x)) && fabs(k1.y-k2.y)<epsilon*(fabs(k1.y)+fabs(k2.y)) && fabs(k1.z-k2.z)<epsilon*(fabs(k1.z)+fabs(k2.z)) && fabs(k1.r-k2.r)<epsilon*(fabs(k1.r)+fabs(k2.r))) return true;
    return false;
}

bool DaLiSeDodirujuIznutra(const Kugla &k1,const Kugla &k2) {
    if((RastojanjeCentara(k1,k2)+k1.r==k2.r) || (RastojanjeCentara(k1,k2)+k2.r==k1.r)) return true;
    return false;
    
}

bool DaLiSeSijeku(const Kugla &k1,const Kugla &k2){
    
    return ((RastojanjeCentara(k1,k2)<=(k1.r+k2.r)) && (RastojanjeCentara(k1,k2) > fabs(k1.r-k2.r))) ;

    
    
}
bool DaLiSePreklapaju(const Kugla &k1,const Kugla &k2){
    if(DaLiSeSijeku(k1,k2)==true) return true;
    return false ;
    
  
    }
    
    bool Kugla::DaLiSadrzi(const Kugla &k) const {
        if(fabs(Kugla::x-k.x)<epsilon*(fabs(Kugla::x)+fabs(k.x)) && fabs(Kugla::y-k.y)<epsilon*(fabs(Kugla::y)+fabs(k.y)) && fabs(Kugla::z-k.z)<epsilon*(fabs(Kugla::z)+fabs(k.z)) && fabs(Kugla::r-k.r)<epsilon*(fabs(Kugla::r)+fabs(k.r))) return true;
        return false ;
    }
    
    
    bool DaLiSuKocentricne(const Kugla &k1,const Kugla &k2){
        if(fabs(k1.x-k2.x)<epsilon*(fabs(k1.x)+fabs(k2.x)) && fabs(k1.y-k2.y)<epsilon*(fabs(k1.y)+fabs(k2.y)) && fabs(k1.z-k2.z)<epsilon*(fabs(k1.z)+fabs(k2.z))) return true;
        return false;
   
    }
   
    

double RastojanjeCentara(const Kugla &k1,const Kugla &k2){
    double rastojanje;
    rastojanje=sqrt(pow((k1.x-k2.y),2)+pow((k1.y-k2.y),2)+pow((k1.z-k2.z),2));
    return rastojanje;
}


int main ()
{ int n;
double a,b,c,r1;
double a1,b1,c1;

    std::cout<<"Unesite broj kugla: ";
 std::cin>>n;
 std::vector<std::shared_ptr<Kugla>> v1(n);

for(int i(0);i<v1.size();i++){
     std::cout<<"Unesite centar "<<i+1<<". kugle: ";
     std::cin>>a>>b>>c;
     std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
     std::cin>>r1;
     
    
     v1[i]=std::make_shared<Kugla>  (Kugla (a,b,c,r1));
  
  
    
    
     
     
 } std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
 std::cin>>a1>>b1>>c1;


 
 
 std::transform(v1.begin(),v1.end(),v1.begin(),[a1,b1,c1] (std::shared_ptr<Kugla> p) {
    p->Transliraj(a1,b1,c1);
    return p;
    
  }); 
  
  
  
  std::sort(v1.begin(),v1.end(),[]( std::shared_ptr<Kugla> p, std::shared_ptr<Kugla> c) {
      return p->DajZapreminu()<c->DajZapreminu();
  });
 
 std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<std::endl;

for_each(v1.begin(),v1.end(),[](std::shared_ptr<Kugla> p) {
    p->Ispisi();
    std::cout<<std::endl;
});
 
std::cout<<"Kugla sa najvecom povrsinom je: ";

auto rez=* std::max_element(v1.begin(),v1.end(),[](std::shared_ptr<Kugla> p,std::shared_ptr<Kugla>c){
    if( p->DajPovrsinu()<c->DajPovrsinu()) return true;
    return false;
});
rez->Ispisi();



std::cout<<std::endl;

int brojac(0);
 std::pair <Kugla,Kugla> par;
 std::vector<std::pair<Kugla,Kugla>> vek;  

 
 std::shared_ptr<Kugla>ss;
 std::shared_ptr<Kugla> saa;
 for(int i(0);i<v1.size()-1;i++){
     for(int j(i+1);j<v1.size();j++){
 if(DaLiSeSijeku(*v1[i],*v1[j])==true){  
     par=std::make_pair(*v1[i],*v1[j]); 
                vek.push_back(par); }
     }
 }
                 
                   
                  
for_each(std::begin(v1),std::end(v1),[&v1,&par,&vek,&brojac](std::shared_ptr<Kugla> &p) {
    for_each(std::begin(v1),std::end(v1),[&v1,&p,&par,&vek,&brojac] (std::shared_ptr<Kugla> &s){
       
         
         if( DaLiSeSijeku(*p,*s)==true ){
         //(DaLiSuIdenticne(vek[i].first,vek[j].first)==false &&  DaLiSuIdenticne(vek[i].second,vek[j].second)==false) ){
         //(DaLiSuIdenticne(vek[i].first,vek[j].second)==false && DaLiSuIdenticne(vek[i].second,vek[j].first)==false)){
             std::cout<<"Presjecaju se kugle: "<<std::endl;
             p->Ispisi();
             s->Ispisi();
             std::cout<<std::endl;
             brojac++;
           
             
             
            
              
                
                    
                
                
               
               
                
               
    
            }
         }); }); 
      
      if(brojac!=0) std::cout<<"Ne postoje kugle koje se presjecaju!";
      
      
   
    







 
 


 
 
 
 







  

    
	return 0;
}
