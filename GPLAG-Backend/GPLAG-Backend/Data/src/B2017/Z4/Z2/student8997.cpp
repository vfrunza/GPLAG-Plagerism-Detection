#include <iostream>
#include <stdexcept>
#include <tuple>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>

class NepreklapajucaKugla {
    
  
  double x,y,z,r;
  static NepreklapajucaKugla *posk;
  // kako incijalizirati static pointer na nullptr kao atribut
  
  NepreklapajucaKugla *prethk;
  public:
  
    explicit NepreklapajucaKugla (double r = 0){
      
      NepreklapajucaKugla(0,0,0,r);
    
  } 
  
  
  NepreklapajucaKugla (double x,double y, double z, double ar = 0) {
      
      
      if(r < 0 ) throw std::domain_error ("Ilegalan poluprecnik");
      
      
      
      if(posk == nullptr) {
            this->x = x;
            this->y = y;
            this->z = z;
            this->r = ar;
            prethk = nullptr;
            posk = this;
      } else {
          
       NepreklapajucaKugla *r = posk;
       
       while(r!=nullptr) {
           
           
            if ((std::sqrt( std::pow( r->x - this->x, 2  ) + std::pow( r->y - this->y, 2) + std::pow( r->z - this->z, 2)) < (r->r + this->r))) 
            throw std::logic_error ("Nedozvoljeno preklapanje");
              
            else {
                r = this->prethk;
            }
            
           
       }
        this->x = x;
        this->y = y;
        this->z = z;
        this->r = ar;
        prethk = posk;
        posk = this;
          
          
      }
      
  };
  
  
  
  
      ~NepreklapajucaKugla() {
          
          
          
          if(posk == this) posk = this->prethk;
          
          else {
              
              NepreklapajucaKugla *r = posk;
              
              while (r->prethk!= this ){
                  
                  
                  r = r->prethk;
              }
              r->prethk = this->prethk;
              
          }
          
      }
      
      
      
      
     
     
     
     
explicit NepreklapajucaKugla (const std::tuple<double, double, double> &centar, double r = 0){
    

   NepreklapajucaKugla(std::get<0>(centar),std::get<1>(centar),std::get<2>(centar),r);
   
   
        
    
}
  void Transliraj(double delta_x,double delta_y,double delta_z){
    
        x+= delta_x;
        y+= delta_y;
        z+= delta_z;
    }
  
  
    double DajPoluprecnik () const { return NepreklapajucaKugla::r;  }   
    
    double DajPovrsinu () const { return     4*(NepreklapajucaKugla::r*NepreklapajucaKugla::r)*(4*atan(1));}  

    double DajZapreminu() const { return (4./3)*(NepreklapajucaKugla::r*NepreklapajucaKugla::r*NepreklapajucaKugla::r)*(4*atan(1));}  
    
    
         

    
    NepreklapajucaKugla &PostaviX (double x) {   NepreklapajucaKugla::x=x; return *this;}  
    NepreklapajucaKugla &PostaviY (double y) {   NepreklapajucaKugla::y=y; return *this;}    
    NepreklapajucaKugla &PostaviZ (double z) {   NepreklapajucaKugla::z=z; return *this;} 
    
    NepreklapajucaKugla &PostaviPoluprecnik (double r) {
    if( r < 0) throw std::domain_error("Ilegalan poluprecnik");
    
    NepreklapajucaKugla::r = r; return *this;  }
  
  
  
  double DajX () const {  return NepreklapajucaKugla::x;  }
  double DajY () const {  return NepreklapajucaKugla::y;  }    
  double DajZ () const {  return NepreklapajucaKugla::z;  }

  std::tuple<double, double, double> DajCentar() const {
     
       return std::make_tuple(NepreklapajucaKugla::x,NepreklapajucaKugla::y,NepreklapajucaKugla::z);
     }
  
  
  
  
  
  void Ispisi () const  {
    
    std::cout<<"{("<<NepreklapajucaKugla::x<<","<<NepreklapajucaKugla::y<<","<<NepreklapajucaKugla::z<<")"<<","<<NepreklapajucaKugla::r<<"}";    
    
  }
  
  
  
  friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);


  bool DaLiSadrzi(const NepreklapajucaKugla &k) const{
    
        return ((std::sqrt( std::pow(  NepreklapajucaKugla::x - k.x, 2  ) + std::pow( NepreklapajucaKugla::y - k.y, 2) + std::pow(NepreklapajucaKugla::z - k.z, 2)) + k.r) <= NepreklapajucaKugla::r );
}
  
};




double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){
    
    
    return (std::sqrt( std::pow(  k1.x - k2.x, 2  ) + std::pow( k1.y - k2.y, 2) + std::pow( k1.z - k2.z, 2)));
}
NepreklapajucaKugla *NepreklapajucaKugla::posk=nullptr;

int main ()
{
 
	return 0;
}
