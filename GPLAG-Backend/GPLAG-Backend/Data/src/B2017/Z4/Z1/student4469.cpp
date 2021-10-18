/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <cmath>
#include <memory>
#include <vector>
#include <algorithm>
#include <map>
int brojac=0;
class Kugla
{

  double x,y,z,r;
public:
  explicit Kugla(double r=0) {
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    x=0;
    y=0;
    z=0;
    Kugla::r=r;
  }
  Kugla(double x, double y, double z, double r=0) {
    if(r<0)throw std::domain_error("Ilegalan poluprecnik");
    Kugla::x=x;
    Kugla::y=y;
    Kugla::z=z;
    Kugla::r=r;
  }
  explicit Kugla(const std::tuple<double,double,double>&centar, double r=0) {
    if(r<0)throw std::domain_error("Ilegalan poluprecnik");
    std::tie(x,y,z)=centar;
    Kugla::r=r;
  }
  double DajX()const {
    return x;
  }
  double DajY()const {
    return y;
  }
  double DajZ()const {
    return z;
  }
  std::tuple<double, double, double> DajCentar() {
    return std::make_tuple(x,y,z);
  }
  double DajPoluprecnik()const {
    return r;
  }
  double DajPovrsinu()const {
    return 4*r*r*4*atan(1);
  }
  double DajZapreminu()const {
    return r*r*r*4*atan(1)*4/3;
  }
  Kugla& PostaviX(double x) {
    Kugla::x=x;
    return*this;
  }
  Kugla& PostaviY(double y) {
    Kugla::y=y;
    return *this;
  }
  Kugla& PostaviZ(double z) {
    Kugla::z=z;
    return *this;
  }
  Kugla& PostaviCentar(double x, double y, double z) {
    Kugla::x=x;
    Kugla::y=y;
    Kugla::z=z;
    return *this;
  }
  Kugla& PostaviCentar(const std::tuple<double,double,double> &centar) {
    std::tie(x,y,z)=centar;
    return *this;
  }
  Kugla& PostaviPoluprecnik(double r) {
    if(r<0)throw std::domain_error("Ilegalan poluprecnik");
    Kugla::r=r;
    return *this;
  }
  void Ispisi()const {
    std::cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}"<<std::endl;
  }
  void Transliraj(double delta_x, double delta_y, double delta_z) {
    x+=delta_x;
    y+=delta_y;
    z+=delta_z;
  }
  friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2) {
    if(k1.x==k2.x && k1.y==k2.y && k1.z==k2.z && k1.r==k2.r)return true;
  
  
    return false;
  }
  friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2) {
   if(k1.r==k2.r)return true;
  
    return false;
  }
  friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2) {
    if(k1.x==k2.x && k1.y==k2.y && k1.z==k2.z)return true;
   
    
    return false;
  }
  friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2) {
    double epsilon=0.0000000001;
    if(fabs(RastojanjeCentara(k1,k2)-k2.r-k1.r)<epsilon*(fabs(RastojanjeCentara(k1,k2)+ fabs(k1.r+k2.r))))return true;
    return false;
  }
  friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2) {
    double epsilon=0.0000000001;
    if(k1.DaLiSadrzi(k2)) {
      if(fabs(RastojanjeCentara(k1,k2) + k2.r - k1.r )<epsilon*(fabs(RastojanjeCentara(k1,k2) +k2.r) +fabs(k1.r)))return true;
    }
    if(k2.DaLiSadrzi(k1)) {
      if(fabs(RastojanjeCentara(k1,k2) + k1.r - k2.r )<epsilon*(fabs(RastojanjeCentara(k1,k2) +k1.r) +fabs(k2.r)))return true;
    }
    return false;
  }
  friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2) {
    if(DaLiSeSijeku(k1,k2))return true;
    if(k1.DaLiSadrzi(k2)||k2.DaLiSadrzi(k1))return true;
    return false;
  }
  friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2) {
    return sqrt( pow((k2.x-k1.x),2) + pow((k2.y-k1.y),2) + pow((k2.z-k1.z),2) );
  }
  bool DaLiSadrzi(const Kugla &k)const {

    if(k.x+k.r<=x+r && k.y+k.r<=y+r && k.z+k.r<=z+r)return true;
    return false;

  }
  friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2) {
    if(RastojanjeCentara(k1,k2)<k1.r+k2.r && RastojanjeCentara(k1,k2)>fabs(k1.r-k2.r) ) return true;
    return false;
  }


};

int main ()
{
  std::cout<<"Unesite broj kugla: ";
  int n;
  do {
    if(!std::cin) {
      std::cin.clear();
      std::cin.ignore(10000,'\n');
    }
    std::cin>>n;
    if(!std::cin || n<=0)std::cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;

  } while(!std::cin || n<=0);

  std::vector<std::shared_ptr<Kugla>> vektor;
  for(int i=0; i<n; i++) {
    double r;
    double x,y,z;
    do {
      if(!std::cin) {
        std::cin.clear();
        std::cin.ignore(10000,'\n');
      }
      std::cout<<"Unesite centar "<<i+1<<". kugle: ";
      std::cin>>x;
      if(!std::cin) std::cout<<"Neispravan centar"<<std::endl;
      else {
        std::cin>>y;
        if(!std::cin)std::cout<<"Neispravan centar"<<std::endl;
        else {
          std::cin>>z;
          if(!std::cin)std::cout<<"Neispravan centar"<<std::endl;
          else {
            std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
            std::cin>>r;
            if(r<0 || !std::cin) std::cout<<"Ilegalan poluprecnik"<<std::endl;
          }
        }
      }

    } while(!std::cin || r<0);
    vektor.push_back(std::make_shared<Kugla>(Kugla(x,y,z,r)));
  }


  
  std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): "; double deltax, deltaz, deltay;
  do{
    if(!std::cin) {
      std::cin.clear();
      std::cin.ignore(10000,'\n'); }
  std::cin>>deltax; std::cin>>deltay; std::cin>>deltaz;
  if(!std::cin)std::cout<<"Neispravni parametri translacije, unesite ponovo!"<<std::endl;
  }
  while(!std::cin);

  std::transform(vektor.begin(),vektor.end(),vektor.begin(),[deltax, deltaz, deltay] (std::shared_ptr<Kugla> pok) {

    pok->Transliraj(deltax,deltay,deltaz);
    return pok;

  } );
  std::sort(vektor.begin(),vektor.end(),[] (std::shared_ptr<Kugla> pok1, std::shared_ptr<Kugla> pok2) {
    return pok1->DajZapreminu()<pok2->DajZapreminu();
  } );

  std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<std::endl;
  std::for_each(vektor.begin(),vektor.end(),[] (std::shared_ptr<Kugla> pok1) {
   pok1->Ispisi();
  });
  auto it= std::max_element(vektor.begin(),vektor.end(),[] (std::shared_ptr<Kugla> pok1, std::shared_ptr<Kugla> pok2) {
    return pok1->DajPovrsinu()<pok2->DajPovrsinu();
  });
  std::cout<<"Kugla sa najvecom povrsinom je: "; (*it)->Ispisi();

    std::vector<std::tuple<double,double,double,double>> vektor_tupleova1;
    std::vector<std::tuple<double,double,double,double>> vektor_tupleova2;

  std::for_each(vektor.begin(),vektor.end(),[&vektor,&vektor_tupleova1,&vektor_tupleova2] (std::shared_ptr<Kugla> pok1) {

    std::for_each(vektor.begin(),vektor.end(),[&pok1,&vektor_tupleova1,&vektor_tupleova2] (std::shared_ptr<Kugla> pok2) {

      if(pok1!=pok2 && DaLiSeSijeku(*pok1, *pok2)) {
         int i=0;
         for(;i<vektor_tupleova1.size();i++) {
          if(std::get<0>(vektor_tupleova1[i])==pok1->DajX() && std::get<1>(vektor_tupleova1[i])==pok1->DajY()
           && std::get<2>(vektor_tupleova1[i])==pok1->DajZ() &&std::get<3>(vektor_tupleova1[i])==pok1->DajPoluprecnik()
           ) {
             int j=i;
             for(;j<vektor_tupleova2.size();j++)
             if(std::get<0>(vektor_tupleova2[j])==pok2->DajX() && std::get<1>(vektor_tupleova2[j])==pok2->DajY()
           && std::get<2>(vektor_tupleova2[j])==pok2->DajZ() &&std::get<3>(vektor_tupleova2[j])==pok2->DajPoluprecnik()
           )break;
            if(j!=vektor_tupleova2.size())
              break;

           }

         }
         
          
    
         int k=0;
         
         for(;k<vektor_tupleova2.size();k++) {
       
           
           
           if(std::get<0>(vektor_tupleova2[k])==pok1->DajX() && std::get<1>(vektor_tupleova2[k])==pok1->DajY()
           && std::get<2>(vektor_tupleova2[k])==pok1->DajZ() &&std::get<3>(vektor_tupleova2[k])==pok1->DajPoluprecnik()
           ) {
             int z=k;
             for(;z<vektor_tupleova1.size();z++)
             if(std::get<0>(vektor_tupleova1[z])==pok2->DajX() && std::get<1>(vektor_tupleova1[z])==pok2->DajY()
           && std::get<2>(vektor_tupleova1[z])==pok2->DajZ() &&std::get<3>(vektor_tupleova1[z])==pok2->DajPoluprecnik()
           )break;
            if(z!=vektor_tupleova1.size())
              break;

           } 

         }

         if(i==vektor_tupleova1.size() && k==vektor_tupleova2.size()) {

        std::cout<<"Presjecaju se kugle: "; pok1->Ispisi(); pok2->Ispisi();
        brojac++;
        vektor_tupleova1.push_back(std::make_tuple(pok1->DajX(),pok1->DajY(),pok1->DajZ(),pok1->DajPoluprecnik()));
        vektor_tupleova2.push_back(std::make_tuple(pok2->DajX(),pok2->DajY(),pok2->DajZ(),pok2->DajPoluprecnik()));
         }
      }

    });

  });

  if(brojac==0) std::cout<<"Ne postoje kugle koje se presjecaju!";
  


  return 0;
}
