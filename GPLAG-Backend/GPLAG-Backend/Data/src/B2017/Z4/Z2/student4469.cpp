/B2017/2018: Zadaća 4, Zadatak 2
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <cmath>
#include <memory>
#include <vector>
#include <algorithm>
#include <map>


class NepreklapajucaKugla {
  
  double x,y,z,r;
  NepreklapajucaKugla * pok;
  static NepreklapajucaKugla *zadnji;
  void Test (double x, double y, double z, double r) {
      auto pomocni_pok=zadnji;
      
      while(1){
        if(pomocni_pok==this)break;
        double rastojanje=sqrt( pow((pomocni_pok->DajX()-x),2) + pow((pomocni_pok->DajY()-y),2) + pow((pomocni_pok->DajZ()-z),2) );
        
         if( (rastojanje
         <= pomocni_pok->DajPoluprecnik()+r) && (rastojanje>= fabs((pomocni_pok->DajPoluprecnik()-r) )) ) throw std::logic_error("Nedozvoljeno preklapanje"); 
   
      if   ( ((rastojanje <fabs(pomocni_pok->DajPoluprecnik() -r) ) && r<pomocni_pok->DajPoluprecnik()) || 
         ((rastojanje <fabs(r-pomocni_pok->DajPoluprecnik()) ) && pomocni_pok->DajPoluprecnik()<r)) throw std::logic_error("Nedozvoljeno preklapanje");

        if (pomocni_pok->pok!=nullptr)pomocni_pok=pomocni_pok->pok;
        else break;
      }
  
  }
  
  
  
  public:
 
  explicit NepreklapajucaKugla(double r=0) {
      if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    if(zadnji!=nullptr){
    Test(x,y,z,r);
   
      pok=zadnji; 
      
    }
    else pok=nullptr; zadnji=this;
    
      x=0; y=0; z=0; NepreklapajucaKugla::r=r;
  }
 NepreklapajucaKugla(double x, double y, double z, double r=0) {
      if(r<0)throw std::domain_error("Ilegalan poluprecnik");
     if(zadnji!=nullptr){
    Test(x,y,z,r);
     pok=zadnji;
    }
    else pok=nullptr; 
    zadnji=this;
      NepreklapajucaKugla::x=x; NepreklapajucaKugla::y=y; NepreklapajucaKugla::z=z; NepreklapajucaKugla::r=r;
  }
  
  explicit NepreklapajucaKugla(const std::tuple<double,double,double>&centar, double r=0) {
    if(r<0)throw std::domain_error("Ilegalan poluprecnik");
    if(zadnji!=nullptr){
    Test(std::get<0>(centar),std::get<1>(centar),std::get<2>(centar),r);
    pok=zadnji;
    }else pok=nullptr; zadnji=this;
      std::tie(x,y,z)=centar; NepreklapajucaKugla::r=r;
  }
  double DajX()const {return x;}
  double DajY()const {return y;}
  double DajZ()const {return z;}
  std::tuple<double, double, double> DajCentar() {return std::make_tuple(x,y,z);}
  double DajPoluprecnik()const {return r;}
  double DajPovrsinu()const {return 4*r*r*4*atan(1);}
  double DajZapreminu()const {return r*r*r*4*atan(1)*4/3;}
  NepreklapajucaKugla& PostaviX(double x) {
    Test(x+NepreklapajucaKugla::x,y,z,DajPoluprecnik());
    NepreklapajucaKugla::x=x; return*this;
  }
  NepreklapajucaKugla& PostaviY(double y){
    Test(x,y+NepreklapajucaKugla::y,z,DajPoluprecnik());
    NepreklapajucaKugla::y=y; return *this;
  }
  NepreklapajucaKugla& PostaviZ(double z){
    Test(x,y,NepreklapajucaKugla::z+z,DajPoluprecnik());
    NepreklapajucaKugla::z=z; return *this;
  }
  NepreklapajucaKugla& PostaviCentar(double x, double y, double z) {
    NepreklapajucaKugla::x=x; NepreklapajucaKugla::y=y; NepreklapajucaKugla::z=z; return *this;
  }
  NepreklapajucaKugla& PostaviCentar(const std::tuple<double,double,double> &centar) {
    Test(std::get<0>(centar),std::get<1>(centar),std::get<2>(centar),DajPoluprecnik());
    std::tie(x,y,z)=centar; return *this;
  }
  NepreklapajucaKugla& PostaviPoluprecnik(double r) {
    if(r<0)throw std::domain_error("Ilegalan poluprecnik");
    Test(x,y,z,r);
    NepreklapajucaKugla::r=r; return *this;
  }
  void Ispisi()const {
    std::cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}"<<std::endl;
  }
  void Transliraj(double delta_x, double delta_y, double delta_z) {
    Test(x+delta_x,y+delta_y,z+delta_z,DajPoluprecnik());
    x+=delta_x; y+=delta_y; z+=delta_z;
  }

  friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){
    return sqrt( pow((k2.x-k1.x),2) + pow((k2.y-k1.y),2) + pow((k2.z-k1.z),2) );
  }
  bool DaLiSadrzi(const NepreklapajucaKugla &k)const {
    
    if(k.x+k.r<=x+r && k.y+k.r<=y+r && k.z+k.r<=z+r)return true;
    return false;
  }
  ~NepreklapajucaKugla() {
    
 
    auto pomocni=zadnji;
    
    if(this!=zadnji) {
      while(pomocni->pok!=this)pomocni=pomocni->pok;
      if(this->pok==nullptr)pomocni->pok=nullptr; //ako brisemo prvi kreirani
      else {
        pomocni->pok=this->pok;   //ako je izmedju zadnjeg i prvog
        this->pok=nullptr;
      }
    }
    else {
      if(zadnji->pok!=nullptr) {
        zadnji=zadnji->pok;
        this->pok=nullptr;
      }
      
    }
    
  }
  
  NepreklapajucaKugla(const NepreklapajucaKugla &k)=delete;
  NepreklapajucaKugla &operator=(const NepreklapajucaKugla &k)=delete;
  
}; NepreklapajucaKugla* NepreklapajucaKugla ::zadnji=nullptr;



int main ()
{
    std::cout<<"Unesite broj kugli: "; int n; 
    do{
      if(!std::cin) {
        std::cin.clear();
        std::cin.ignore(10000,'\n');
      }
      std::cin>>n;
      if(!std::cin || n<=0) std::cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;
    }
     while(!std::cin || n<=0);
    std::vector<std::shared_ptr<NepreklapajucaKugla>> vektor;
    for(int i=0;i<n;i++) {
      double r,x,y,z;
      bool baceno=false;
       std::cout<<"Unesite centar za "<<i+1<<". kuglu: "; 
      do{
        if(baceno)std::cout<<"Unesite centar za "<<i+1<<". kuglu: ";
        baceno=false;
        if(!std::cin) {
          std::cin.clear();
          std::cin.ignore(10000,'\n');
        }
        std::cin>>x;
        if(!std::cin) {
          std::cout<<"Neispravan centar, unesite ponovo:"<<std::endl;
        }
        else {
          std::cin>>y; 
          if(!std::cin) {
            std::cout<<"Neispravan centar, unesite ponovo:"<<std::endl;
          } else {
            std::cin>>z; 
            if(!std::cin) {
              std::cout<<"Neispravan centar, unesite ponovo:"<<std::endl;
            }
            else {
              std::cout<<"Unesite poluprecnik: ";
              do{
                if(!std::cin) {
                  std::cin.clear();
                  std::cin.ignore(10000,'\n');
                }
                std::cin>>r;
              
               if(r<0 || !std::cin) std::cout<<"Neispravan poluprecnik, unesite ponovo:"<<std::endl;
              }
               while(r<0 || !std::cin);
               
              
                  try {
      vektor.push_back(std::make_shared<NepreklapajucaKugla>(x,y,z,r));
    }
    catch(std::logic_error) {
      std::cout<<"Nedozvoljeno preklapanje"<<std::endl; baceno=true;
    }
               }
            }
          }
        }while(!std::cin || baceno);

    } 
       
      
      
 
  std::sort(vektor.begin(),vektor.end(),[] (std::shared_ptr<NepreklapajucaKugla> k1, std::shared_ptr<NepreklapajucaKugla> k2){
    return (k1->DajPovrsinu()<k2->DajPovrsinu());
  });
  std::cout<<std::endl;
  std::cout<<"Kugle nakon obavljenog sortiranja: "<<std::endl;
    for(int i=0;i<vektor.size();i++) {
      vektor[i]->Ispisi();
    }
    
	return 0;
}
