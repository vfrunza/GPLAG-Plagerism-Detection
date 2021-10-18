/B2017/2018: Zadaća 4, Zadatak 1
//TEST VERZIJA1
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>

bool Jednakost( double x , double y) {
    
    
    return (std::abs(x-y) <= (1e-10)*(std::abs(x) + std::abs(y)));
    
}





class Kugla{
    
    
  double x,y,z,r;  
    
  public:
  explicit Kugla (double r = 0) {
      
      if( r < 0 ) throw std::domain_error ("Ilegalan poluprecnik");
      Kugla::x = 0;
      Kugla::y = 0;
      Kugla::z = 0;
      Kugla::r = r;
  } 
  
  
  Kugla (double x,double y, double z, double r = 0) {
      
      
      if(r < 0 ) throw std::domain_error ("Ilegalan poluprecnik");
      
      Kugla::x = x;
      Kugla::y = y;
      Kugla::z = z;
      Kugla::r = r;
      
     }
explicit Kugla (const std::tuple<double, double, double> &centar, double r = 0){
    
    if(r < 0) throw std::domain_error ("Ilegalan poluprecnik");
    
        Kugla::x =  std::get<0>(centar);
        Kugla::y =  std::get<1>(centar);
        Kugla::z =  std::get<2>(centar);
        Kugla::r =  r; 
    
}
    
double DajX () const {  return Kugla::x;  }
double DajY () const {  return Kugla::y;  }    
double DajZ () const {  return Kugla::z;  }
    
std::tuple<double, double, double> DajCentar() const {
     
     return std::make_tuple(Kugla::x,Kugla::y,Kugla::z);
     }
     
     
double DajPoluprecnik () const { return Kugla::r;  }     
double DajPovrsinu () const { return     4*(Kugla::r*Kugla::r)*(4*atan(1));}  
double DajZapreminu() const { return (4./3)*(Kugla::r*Kugla::r*Kugla::r)*(4*atan(1));}  
 
Kugla &PostaviX (double x) {   Kugla::x=x; return *this;}  
Kugla &PostaviY (double y) {   Kugla::y=y; return *this;}    
Kugla &PostaviZ (double z) {   Kugla::z=z; return *this;}    

Kugla &PostaviCentar(double x, double y, double z) {    Kugla::x = x; Kugla::y = y ; Kugla::z = z; return *this;}
Kugla &PostaviCentar(const std::tuple<double, double, double> &centar) {
    
    Kugla::x = std::get<0>(centar);
    Kugla::y = std::get<1>(centar);
    Kugla::z = std::get<2>(centar);
    
    return *this;
}


Kugla &PostaviPoluprecnik (double r) {
    if( r < 0) throw std::domain_error("Ilegalan poluprecnik");
    
    Kugla::r = r; return *this;  
    
}

void Ispisi () const  {
    
std::cout<<"{("<<Kugla::x<<","<<Kugla::y<<","<<Kugla::z<<")"<<","<<Kugla::r<<"}";    
    
}

void Transliraj(double delta_x,double delta_y,double delta_z){
    
        x+= delta_x;
        y+= delta_y;
        z+= delta_z;
    }
    
friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);

friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
bool DaLiSadrzi(const Kugla &k) const{
    //stavio si uslov kuglaa::x > k.r
        return (((std::sqrt( std::pow(  Kugla::x - k.x, 2  ) + std::pow( Kugla::y - k.y, 2) + std::pow( Kugla::z - k.z, 2)) + k.r) <= Kugla::r ) && (Kugla::r>k.r));
}
friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);





};






bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2 ){
    
    
    
    return (Jednakost(k1.x,k2.x) && Jednakost(k1.y,k2.y) && Jednakost(k1.z,k2.z) && Jednakost(k1.r,k2.r) );
}

bool DaLiSuPodudarne ( const Kugla &k1, const Kugla  &k2){
    
    
    
    return Jednakost(k1.r,k2.r);
    
}

bool DaLiSuKoncentricne ( const Kugla &k1, const Kugla &k2) {
    
    
    
    return (Jednakost(k1.x,k2.x) && Jednakost(k1.y,k2.y) && Jednakost(k1.z,k2.z)); 
}
bool DaLiSeDodirujuIzvana ( const Kugla &k1, const Kugla &k2) {
    
    
    
    return (Jednakost( std::sqrt( std::pow(  k1.x - k2.x, 2  ) + std::pow( k1.y - k2.y, 2) + std::pow( k1.z - k2.z, 2) ) ,(k1.r+k2.r) ));
    
}

bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2){
    

if(k1.r < k2.r){
    
return (Jednakost(std::sqrt( std::pow(  k1.x - k2.x, 2  ) + std::pow( k1.y - k2.y, 2) + std::pow( k1.z - k2.z, 2)) + k1.r ,k2.r));
}
else if(k2.r < k1.r) {
    
       return (Jednakost( std::sqrt( std::pow(  k1.x - k2.x, 2  ) + std::pow( k1.y - k2.y, 2) + std::pow( k1.z - k2.z, 2)) + k2.r , k1.r));
} 

    
    
}

bool DaLiSeSijeku( const Kugla &k1, const Kugla &k2) {
    
    
    return ((std::sqrt( std::pow(  k1.x - k2.x, 2  ) + std::pow( k1.y - k2.y, 2) + std::pow( k1.z - k2.z, 2)) < (k1.r + k2.r)) && ( std::sqrt( std::pow(  k1.x - k2.x, 2  ) + std::pow( k1.y - k2.y, 2) + std::pow( k1.z - k2.z, 2)) > std::abs(k1.r - k2.r) )) ;
    
    
}

double RastojanjeCentara(const Kugla &k1, const Kugla &k2){
    
    
    return (std::sqrt( std::pow(  k1.x - k2.x, 2  ) + std::pow( k1.y - k2.y, 2) + std::pow( k1.z - k2.z, 2)));
}

bool DaLiSePreklapaju( const Kugla &k1, const Kugla &k2){
    
    //dodao si uslov && ((k1.DaLiSadrzi(k2)) || k2.DaLiSadrzi(k1)))
    return (((std::sqrt( std::pow( k1.x - k2.x, 2  ) + std::pow( k1.y - k2.y, 2) + std::pow( k1.z - k2.z, 2)) < (k1.r + k2.r))) && ((k1.DaLiSadrzi(k2)) || k2.DaLiSadrzi(k1))) ;
    
    
}




int main ()
{
   int n;
   std::string s;
   Kugla k1;
   int br=0;
   bool T=false;
   double x,y,z,r;
   
   Kugla k3(2,0,0,2); 
   Kugla k2(1,2,3,4);

   std::cout<<"Unesite broj kugla: ";
    do{

   std::getline(std::cin, s);
   try{
   n = std::stoi(s);
   } catch (...) {n=0;};
   if(n<=0) std::cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;


    }while(n<=0);
   
   
   std::vector<std::shared_ptr<Kugla>> vek(n); 
   
   
   for(int i=0 ; i < n;i++) {
       
       std::cout<<"Unesite centar "<<i+1<<". kugle: ";
       std::cin>>x;
       std::cin>>y;
       std::cin>>z;
       

       
       
       
                   if(!std::cin) {
                
                std::cout<<"Neispravan centar"<<std::endl;
                std::cin.clear();
                std::cin.ignore(10000,'\n');
                i--;
                
            } else {
                k1.PostaviX(x).PostaviY(y).PostaviZ(z);
                
    
                
                
                try {
                     std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
                    std::cin>>r;
                    if(!std::cin) {
                        r=-1;
                    }
                    k1.PostaviPoluprecnik(r);
                    vek[i] = std::make_shared<Kugla>(k1);
                }
                catch(std::domain_error iz){
                    std::cout<<iz.what()<<std::endl;
                    i--;
                    std::cin.clear();
                std::cin.ignore(10000,'\n');
                }
            }
    }
    
    double dy,dx,dz;
    std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    
    do {
        std::cin.clear();
        std::cin.ignore(10000,'\n');
    std::cin>>dx;
    std::cin>>dy;
    std::cin>>dz;
    
    if(!std::cin) {
        std::cout<<"Neispravni parametri translacije, unesite ponovo!";
        std::cout<<std::endl;
        
    }
    }while(!std::cin);
    

    
   
   
    std::transform(std::begin(vek),std::end(vek),std::begin(vek), [dx,dy,dz] (std::shared_ptr<Kugla> k4) {
        (*k4).Transliraj(dx,dy,dz);
        return k4;
        
        
    });   
   
   
    std::sort(std::begin(vek),std::end(vek), 
    
    []( std::shared_ptr<Kugla> k2, std::shared_ptr<Kugla> k3) {
        
        
        return ((*k2).DajZapreminu() < (*k3).DajZapreminu()); 
    }
    );
    
  
    std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<std::endl;
    
    std::for_each(std::begin(vek),std::end(vek),[](std::shared_ptr<Kugla> k5){
        
        (*k5).Ispisi();
        std::cout<<std::endl;
    } );
    
    
    
    
    auto it=std::max_element(std::begin(vek), std::end(vek), [](std::shared_ptr<Kugla>k1,std::shared_ptr<Kugla>k2) {
        
        return  (*k1).DajPovrsinu() < (*k2).DajPovrsinu();           
        
    }  );
    
    
    std::cout<<"Kugla sa najvecom povrsinom je: ";
    
    (*it)->Ispisi();
    std::cout<<std::endl;
    
    std::for_each(std::begin(vek), std::end(vek), [&vek,&br, &T] (std::shared_ptr<Kugla> k2){
        
        std::for_each(std::begin(vek)+br+1,std::end(vek), [k2, &T](std::shared_ptr<Kugla> k3) {
            
            if(DaLiSeSijeku(*k2,*k3)) {
                T=true;
                std::cout<<"Presjecaju se kugle: ";
                (*k2).Ispisi();
                std::cout<<std::endl;
                (*k3).Ispisi();
                 std::cout<<std::endl;
            } 
            
            
            });
            br++;
        });
        if(T==false) std::cout<<"Ne postoje kugle koje se presjecaju!";
        
  
    
	return 0;
}
