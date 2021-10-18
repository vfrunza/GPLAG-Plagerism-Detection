/B2017/2018: Zadaća 4, Zadatak 2
#include <iostream>
#include <tuple>
#include <algorithm>
#include <cmath>
#include <memory>
#include <vector>
#include <stdexcept>
#define eps pow(10, -10)
#define PI 3.14159
class NepreklapajucaKugla{
  double poluprecnik;
  std::tuple<double, double, double> cent;
  NepreklapajucaKugla* prosla(nullptr);
  public:
  explicit NepreklapajucaKugla(double r = 0){
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    poluprecnik=r;
    std::get<0>(cent)=0; std::get<1>(cent)=0; std::get<2>(cent)=0;
  }; 
  
  NepreklapajucaKugla(double x, double y, double z, double r = 0){
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    poluprecnik=r;
    std::get<0>(cent)=x; std::get<1>(cent)=y; std::get<2>(cent)=z;
  }; 
  
  explicit NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r = 0){
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    poluprecnik=r;
     std::get<0>(cent)=std::get<0>(centar); std::get<1>(cent)=std::get<1>(centar); std::get<2>(cent)=std::get<2>(centar);
  }; 
 
  double DajX() const {return std::get<0>(cent);}; 
  double DajY() const {return std::get<1>(cent);}; 
  double DajZ() const {return std::get<2>(cent);}; 
  std::tuple<double, double, double> DajCentar() const {return cent;}; 
  double DajPoluprecnik() const {return poluprecnik;}; 
  double DajPovrsinu() const {return 4*PI*poluprecnik*poluprecnik;}; 
  double DajZapreminu() const {return (4/3)*PI*poluprecnik*poluprecnik;}; 
 
  NepreklapajucaKugla &PostaviX(double x) {
    std::get<0>(cent)=x;
    return *this;
  }; 
  NepreklapajucaKugla &PostaviY(double y){
    std::get<1>(cent)=y;
    return *this;
  }; 
  NepreklapajucaKugla &PostaviZ(double z){
    std::get<2>(cent)=z;
    return *this;
  }; 
  
  NepreklapajucaKugla &PostaviCentar(double x, double y, double z){
    std::get<0>(cent)=x; std::get<1>(cent)=y; std::get<2>(cent)=z;
    return *this;
  }; 
  NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar){
    cent = centar;
    return *this;
  }; 
  NepreklapajucaKugla &PostaviPoluprecnik(double r) {
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    poluprecnik=r;
    return *this;
  }; 
  void Ispisi() const { std::cout<<"{("<<std::get<0>(cent)<<","<<std::get<1>(cent)<<","<<std::get<2>(cent)<<"),"<<poluprecnik<<"}";}; 
  void Transliraj(double delta_x, double delta_y, double delta_z){
    std::get<0>(cent)+=delta_x; 
    std::get<1>(cent)+=delta_y; 
    std::get<2>(cent)+=delta_z;
  }; 
  
  friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);   
};
double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){
  return (sqrt(pow(std::get<0>(k1.cent)-std::get<0>(k2.cent),2) + pow(std::get<1>(k1.cent)-std::get<1>(k2.cent),2) + pow(std::get<2>(k1.cent)-std::get<2>(k2.cent),2)));
} 


int main ()
{
  int n(0);
  while(n==0){
  std::cout<<"Unesite broj NepreklapajucaKugla: ";
  std::cin>>n;
  if(n<=0){
    n=0;
    std::cout<<"Neispravan broj kugli, unesite ponovo!";
  }
  }
  std::vector<std::shared_ptr<NepreklapajucaKugla>> v_pok(n);
  for(int i(0); i<n; i++){
    std::cout<<"Unesite centar "<<i+1<<". kugle: ";
    double x, y, z;
    std::cin>>x>>y>>z;
    std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
    double r;
    std::cin>>r;
    
    try{
      std::shared_ptr<NepreklapajucaKugla> temp (new NepreklapajucaKugla(x, y, z, r));
      v_pok.at(i)=std::make_shared<NepreklapajucaKugla>(*temp);
    }
    catch(std::domain_error izuzetak){
      std::cout<<izuzetak.what();
      i--;
    }
    
  }
  std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
  double delta_x, delta_y, delta_z;
  std::cin>>delta_x>>delta_y>>delta_z;
  std::transform(v_pok.begin(), v_pok.end(), v_pok.begin(), [delta_x, delta_y, delta_z](std::shared_ptr<NepreklapajucaKugla> k) -> std::shared_ptr<NepreklapajucaKugla>{
    k->Transliraj(delta_x, delta_y, delta_z);
    return k;
  });
  std::sort(v_pok.begin(), v_pok.end(), [](std::shared_ptr<NepreklapajucaKugla> k1, std::shared_ptr<NepreklapajucaKugla> k2){
    double zap1(k1->DajZapreminu());
    double zap2(k2->DajZapreminu());
    return(zap1<zap2);
  });
  std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<std::endl;
  for_each(v_pok.begin(), v_pok.end(), [](std::shared_ptr<NepreklapajucaKugla> k){
    k->Ispisi();
    std::cout<<std::endl;
  });
  
  auto max_povrsina = *std::max_element(v_pok.begin(), v_pok.end(), [](std::shared_ptr<NepreklapajucaKugla> k1, std::shared_ptr<NepreklapajucaKugla> k2){
    return (k1->DajPovrsinu() < k2->DajPovrsinu());
  });
  
  std::cout<<"NepreklapajucaKugla sa najvecom povrsinom je: ";
  max_povrsina->Ispisi(); std::cout<<std::endl;
  int br(0);
  for_each(v_pok.begin(), v_pok.end(), [v_pok, &br](std::shared_ptr<NepreklapajucaKugla> k1){
    for_each(v_pok.begin(), v_pok.end(), [k1, &br](std::shared_ptr<NepreklapajucaKugla> k2) {
      if(DaLiSeSijeku(*k1, *k2)) { std::cout<<"Presjecaju se kugle: "; 
      k1->Ispisi(); std::cout<<std::endl; k2->Ispisi();
      br++;
      }
    });
  });
  if(br==0) std::cout<<"Ne postoje kugle koje se presjecaju!";
  
	return 0;
}
