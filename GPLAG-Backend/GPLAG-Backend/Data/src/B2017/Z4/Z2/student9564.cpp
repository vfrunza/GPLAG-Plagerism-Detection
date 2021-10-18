/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <cmath>
#include <tuple>
#include <stdexcept>
#include <vector>
#include <memory>
#include <algorithm>

static double pi(4*atan(1));




class NepreklapajucaKugla{
  double x,y,z;
  double r;
  NepreklapajucaKugla* poknaprethodni=nullptr;
  static NepreklapajucaKugla* poknazadnju;
  
  public:
  
  
  
  explicit NepreklapajucaKugla(double r=0){
    x=0; y=0; z=0;
    NepreklapajucaKugla *pom=poknaprethodni;
    while(pom!=nullptr){
      if(DaLiSePreklapaju(*this, *pom)) throw std::logic_error("Nedozvoljeno preklapanje");
      pom=pom->poknaprethodni;
    }
    if(poknazadnju!=nullptr) poknaprethodni=poknazadnju;
    poknazadnju=this;
  }
  
  NepreklapajucaKugla (double x, double y, double z, double r=0){
    NepreklapajucaKugla::x=x;
    NepreklapajucaKugla::y=y;
    NepreklapajucaKugla::z=z;
    
    if (r<0) throw std::domain_error("Ilegalan poluprecnik");
    NepreklapajucaKugla::r=r;
    NepreklapajucaKugla *pom=poknaprethodni;
    while(pom!=nullptr){
      if(DaLiSePreklapaju(*this, *pom)) throw std::logic_error("Nedozvoljeno preklapanje");
      pom=pom->poknaprethodni;
    }
    if(poknazadnju!=nullptr) poknaprethodni=poknazadnju;
    poknazadnju=this;
  }
  
  
  explicit NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r=0){
    
   x= std::get<0> (centar);
   y=std::get<1> (centar);
   z=std::get<2> (centar);
   
   if (r<0) throw std::domain_error("Ilegalan poluprecnik");
     NepreklapajucaKugla::r=r;
   
   NepreklapajucaKugla *pom=poknaprethodni;
    while(pom!=nullptr){
      if(DaLiSePreklapaju(*this, *pom)) throw std::logic_error("Nedozvoljeno preklapanje");
      pom=pom->poknaprethodni;
    }
    if(poknazadnju!=nullptr) poknaprethodni=poknazadnju;
    poknazadnju=this;
    
  }
  
  ~NepreklapajucaKugla(){
    if(poknazadnju==this){
      poknazadnju=poknaprethodni;
    }
    else{
      NepreklapajucaKugla* pom=poknazadnju;
      while(pom->poknaprethodni!=this){
        pom=pom->poknaprethodni;
      }
      pom->poknaprethodni=poknaprethodni->poknaprethodni;
    }
  }
  
  
  double DajX() const{
    return x;
  }
  double DajY() const{
    return y;
  }
  double DajZ() const{
    return z;
  }
  
  std::tuple<double, double, double> DajCentar () const{
    return std::make_tuple(x,y,z);
  }
  
  
  double DajPoluprecnik () const{
    return r;
  }
  double DajPovrsinu () const{
    return 4*r*r*pi;
  }
  double DajZapreminu () const{
    return (4*r*r*r*pi)/3;
  }
  
  NepreklapajucaKugla &PostaviX (double x){
    NepreklapajucaKugla::x=x;
    return *this;
  }
  NepreklapajucaKugla &PostaviY (double y){
    NepreklapajucaKugla::y=y;
    return *this;
  }
  NepreklapajucaKugla &PostaviZ (double z){
    NepreklapajucaKugla::z=z;
    return *this;
  }
  NepreklapajucaKugla &PostaviCentar (double x, double y, double z){
    NepreklapajucaKugla::x=x;
    NepreklapajucaKugla::y=y;
    NepreklapajucaKugla::z=z;
    return *this;
  }
  NepreklapajucaKugla &PostaviCentar (const std::tuple <double, double, double> &centar){
    x= std::get<0> (centar);
    y=std::get<1> (centar);
    z=std::get<2> (centar);
    return *this;
  }
  NepreklapajucaKugla &PostaviPoluprecnik(double r){
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    NepreklapajucaKugla::r=r;
    return *this;
  }
  
  
  void Transliraj (double delta_x, double delta_y, double delta_z){
    x+=delta_x;
    y+=delta_y;
    z+=delta_z;
  }
  
  bool DaLiSadrzi(const NepreklapajucaKugla &k) const{
    double rastojanje_centara=sqrt((x-k.x)*(x-k.x)+(y-k.y)*(y-k.y)+(z-k.z)*(z-k.z));
    double razlika_poluprecnika=abs(r-k.r);
    double zbir_poluprecnika=r+k.r;
    
    if(rastojanje_centara>razlika_poluprecnika ) return true;
    //|C1C2|>|r1-r2|
    return false;
  }
  
  friend double RastojanjeCentara (const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){
    double rastojanje_centara=sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z));
    return rastojanje_centara;
    
  }
  
friend bool DaLiSePreklapaju (const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){
    double rastojanje_centara=sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z));
    double razlika_poluprecnika=abs(k1.r-k2.r);
    
    if(rastojanje_centara < razlika_poluprecnika) return true;
    return false;
  }
  
  void Ispisi () const{
    std::cout << "{(" << x << "," << y << ","<< z << ")," << r << "}"; 
    std::cout << std::endl;
  }
    

};


NepreklapajucaKugla NepreklapajucaKugla::*poknazadnju=nullptr;
//int Student::broj studenata(10); iz predavanja vako se deklarise predavanje 9_b

//NepreklapajucaKugla::poknazadnju=nullptr;

int main(){
  int n;
  std::cout << "Unesite broj kugla: ";
  do{
    std::cin>>n;
    if(!(std::cin) || n<1) std::cout << "Neispravan broj kugli, unesite ponovo!"<< std::endl;
    std::cin.clear();
    std::cin.ignore(1000, '\n');
  }while (!(std::cin) || n<1);
  
  /* Ukoliko konstrukcija ne uspije jer se nova kugla preklapa sa do tada unesenim kuglama,
  ili ukoliko su zadani besmisleni podaci, treba ispisati poruku upozorenja i
  zatražiti novi unos podataka za istu kuglu.*/
  
  
  std::vector<std::shared_ptr<NepreklapajucaKugla>> v;
  
  //UNUTRASNJOST FOR PETLJE MORA U TRY CATCH BLOK!!!!!!!!!
  
  for(int i=0; i<n; i++){
    try{
      std::cout << "Unesite centar " << i+1<< ". kugle: ";
    double a , b ,c;
    std::cin>> a >> b >> c; 
    if(!(std::cin)){
      std::cin.clear();
      std::cin.ignore(1000, '\n'); 
      throw std::domain_error("Neispravan centar");
    }
    std::cout << "Unesite poluprecnik " << i+1 << ". kugle: ";
    double r;
    std::cin >> r;
    if(!(std::cin)){
      std::cin.clear();
      std::cin.ignore(1000, '\n'); 
      throw std::domain_error("Ilegalan poluprecnik");
    }
    auto pam_pok=std::make_shared<NepreklapajucaKugla>(a,b,c,r);
    v.push_back(pam_pok);
    //gotov vektor
    }
    
    catch(std::domain_error e){
      std::cout << e.what();
      std::cout << std::endl; 
      i--;
    }
    
  }
  
  
  /*double delta_x, delta_y, delta_z;
  std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
  bool unio=false;
  do{
    try{
      std::cin>> delta_x>> delta_y>> delta_z;
   if(!(std::cin)){
      std::cin.clear();
      std::cin.ignore(1000, '\n'); 
      throw std::domain_error("Neispravni parametri translacije, unesite ponovo!");
     }
     unio=true;
    }
    catch(std::domain_error a){
      std::cout << a.what();
      std::cout << std::endl;
    }
  }while(!unio);
  */
  
  /* Nakon okončanja unosa, program treba sortirati sve unesene kugle u rastući poredak po površini
  (tj. kugla s manjom površinom dolazi prije kugle sa većom površinom) 
  i ispisati podatke o svim kuglama nakon obavljenog sortiranja.
  Za sortiranje obavezno koristite bibliotečku funkciju “sort” uz pogodno definiranu funkciju kriterija kao lambda funkciju. */
  
  /*std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti:";
  std::transform(v.begin(), v.end(), v.begin(), [delta_x, delta_y, delta_z](std::shared_ptr<NepreklapajucaKugla> pampok){
    pampok->Transliraj(delta_x, delta_y, delta_z);
    return pampok;
  });*/
  
  
  
  
  
  std::sort(v.begin(), v.end(),[](std::shared_ptr<NepreklapajucaKugla> pampok1, std::shared_ptr<NepreklapajucaKugla> pampok2){
    return pampok1->DajPovrsinu()<pampok2->DajPovrsinu();
    });
    
    
    std::cout << "Kugle nakon obavljenog sortiranja: " << std::endl;
    
  std::for_each(v.begin(), v.end(), [](std::shared_ptr<NepreklapajucaKugla>pampok){
    std::cout << std::endl;
    pampok->Ispisi();
    
  });
  
  
  
  
  /*
  auto pokazivac=std::max_element(v.begin(), v.end(), [](std::shared_ptr<NepreklapajucaKugla>pampok1, std::shared_ptr<NepreklapajucaKugla> pampok2){
     return  pampok1->DajPovrsinu()< pampok2->DajPovrsinu();
  });
  std::cout << std::endl;
  std::cout << "Kugla sa najvecom povrsinom je: " ;
  std::shared_ptr<NepreklapajucaKugla> novipampok=std::make_shared<NepreklapajucaKugla>(**pokazivac); //pokazivac postao pametan
  novipampok->Ispisi();
  //do ovdje radi vjerovatno **pokazivac je upitno
  int brojac(0);
  //bool sijekuse=false;*/
  
  
  /*
  std::cout << std::endl;
  std::for_each(v.begin(), v.end(), [&brojac, v, &sijekuse](std::shared_ptr<NepreklapajucaKugla>pampok){
    std::for_each(v.begin()+brojac, v.end(), [pampok, &sijekuse](std::shared_ptr<NepreklapajucaKugla>pampok1){
      //int brojac;
      
      
    });
    brojac++;
  });
  if(sijekuse==false){
    std::cout << "Ne postoje kugle koje se presjecaju!";
  }*/
  
  
  return 0;
}