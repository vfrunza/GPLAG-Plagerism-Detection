/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <tuple>
#include <algorithm>
#include <cmath>
#include <memory>
#include <vector>
#include <stdexcept>
#define eps pow(10, -10)
#define PI 3.14159
class Kugla{
  double poluprecnik;
  std::tuple<double, double, double> cent;
  public:
  explicit Kugla(double r = 0){
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    poluprecnik=r;
    std::get<0>(cent)=0; std::get<1>(cent)=0; std::get<2>(cent)=0;
  }; 
  
  Kugla(double x, double y, double z, double r = 0){
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    poluprecnik=r;
    std::get<0>(cent)=x; std::get<1>(cent)=y; std::get<2>(cent)=z;
  }; 
  
  explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0){
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
 
  Kugla &PostaviX(double x) {
    std::get<0>(cent)=x;
    return *this;
  }; 
  Kugla &PostaviY(double y){
    std::get<1>(cent)=y;
    return *this;
  }; 
  Kugla &PostaviZ(double z){
    std::get<2>(cent)=z;
    return *this;
  }; 
  
  Kugla &PostaviCentar(double x, double y, double z){
    std::get<0>(cent)=x; std::get<1>(cent)=y; std::get<2>(cent)=z;
    return *this;
  }; 
  Kugla &PostaviCentar(const std::tuple<double, double, double> &centar){
    cent = centar;
    return *this;
  }; 
  Kugla &PostaviPoluprecnik(double r) {
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
  friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2); 
  friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2); 
  friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2); 
  friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2); 
  friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2); 
  friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2); 
  friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2); 
  bool DaLiSadrzi(const Kugla &k) const{
    return(poluprecnik>=k.poluprecnik && (sqrt(pow(std::get<0>(k.cent)-std::get<0>(cent),2) + pow(std::get<1>(k.cent)-std::get<1>(cent),2) + pow(std::get<2>(k.cent)-std::get<2>(cent),2))<=poluprecnik-k.poluprecnik));
  };
  friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);   
};
double RastojanjeCentara(const Kugla &k1, const Kugla &k2){
  return (sqrt(pow(std::get<0>(k1.cent)-std::get<0>(k2.cent),2) + pow(std::get<1>(k1.cent)-std::get<1>(k2.cent),2) + pow(std::get<2>(k1.cent)-std::get<2>(k2.cent),2)));
} 

bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2){
  return(fabs(k1.poluprecnik-k2.poluprecnik)<eps*(fabs(k1.poluprecnik)+fabs(k2.poluprecnik)) && k1.cent==k2.cent);
}

bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2){
  return(fabs(k1.poluprecnik-k2.poluprecnik)<eps*(fabs(k1.poluprecnik)+fabs(k2.poluprecnik)));
}

bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2){
  return(k1.cent==k2.cent);
}

bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2){
  float udaljenost = k1.poluprecnik + k2.poluprecnik;
  return((fabs(RastojanjeCentara(k1, k2)) - udaljenost)<eps*(fabs(RastojanjeCentara(k1, k2))+fabs(udaljenost)));
}

bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2){
  float udaljenost = k1.poluprecnik - k2.poluprecnik;
  return((fabs(RastojanjeCentara(k1, k2)) - udaljenost)<eps*(fabs(RastojanjeCentara(k1, k2))+fabs(udaljenost)));
}

bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2){
  double UdaljenostCentara = RastojanjeCentara(k1, k2);
  return(UdaljenostCentara < k1.poluprecnik + k2.poluprecnik);
}

bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2){
  double UdaljenostCentara = RastojanjeCentara(k1, k2);
  return (DaLiSePreklapaju(k1, k2) && (UdaljenostCentara > fabs(k1.poluprecnik - k2.poluprecnik)));
}

int main ()
{
  int n(0);
  while(n==0){
  std::cout<<"Unesite broj kugla: ";
  std::cin>>n;
  if(!(n>0)){
    std::cin.clear();
    std::cin.ignore();
    n=0;
    std::cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;
  }
  }
  std::vector<std::shared_ptr<Kugla>> v_pok(n);
  for(int i(0); i<n; i++){
    std::cout<<"Unesite centar "<<i+1<<". kugle: ";
    double x,y,z;
    std::cin>>x>>y>>z;
    std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
    double r;
    std::cin>>r;
    
    try{
      std::shared_ptr<Kugla> temp (new Kugla(x, y, z, r));
      v_pok.at(i)=std::make_shared<Kugla>(*temp);
    }
    catch(std::domain_error izuzetak){
      std::cout<<izuzetak.what();
      std::cout<<std::endl;
      i--;
    }
    
  }
  std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
  double delta_x, delta_y, delta_z;
  std::cin>>delta_x>>delta_y>>delta_z;
  std::transform(v_pok.begin(), v_pok.end(), v_pok.begin(), [delta_x, delta_y, delta_z](std::shared_ptr<Kugla> k) -> std::shared_ptr<Kugla>{
    k->Transliraj(delta_x, delta_y, delta_z);
    return k;
  });
  std::sort(v_pok.begin(), v_pok.end(), [](std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2){
    double zap1(k1->DajZapreminu());
    double zap2(k2->DajZapreminu());
    return(zap1<zap2);
  });
  std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<std::endl;
  for_each(v_pok.begin(), v_pok.end(), [](std::shared_ptr<Kugla> k){
    k->Ispisi();
    std::cout<<std::endl;
  });
  
  auto max_povrsina = *std::max_element(v_pok.begin(), v_pok.end(), [](std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2){
    return (k1->DajPovrsinu() < k2->DajPovrsinu());
  });
  
  std::cout<<"Kugla sa najvecom povrsinom je: ";
  max_povrsina->Ispisi(); std::cout<<std::endl;
  int br(0);
  //std::vector<std::shared_ptr<Kugla>>::const_iterator it=v_pok.begin();
  int i(0);
  for_each(v_pok.begin(), v_pok.end(), [v_pok, &br, &i](std::shared_ptr<Kugla> k1){
    i++;
    for_each(v_pok.begin()+i, v_pok.end(), [k1, &br](std::shared_ptr<Kugla> k2) {
      if(DaLiSeSijeku(*k1, *k2)) { std::cout<<"Presjecaju se kugle: "; 
      k1->Ispisi(); std::cout<<std::endl; k2->Ispisi(); std::cout<<std::endl;
      br++;
      }
    });
  });
  if(br==0) std::cout<<"Ne postoje kugle koje se presjecaju!";
  
	return 0;
}
