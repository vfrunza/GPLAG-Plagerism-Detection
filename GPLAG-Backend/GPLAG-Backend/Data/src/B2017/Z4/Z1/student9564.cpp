/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <cmath>
#include <tuple>
#include <stdexcept>
#include <vector>
#include <memory>
#include <algorithm>
static double eps(1e-10);
static double pi(4*atan(1));
//BITNOOOOOOOOOOOOOOOOOOOOOOOOOOO
//1. DODATI EPSILON
//2. KAD DODAM EPSILON <= TREBA STAVLJAT ZA POREDJENJE BITNOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO

class Kugla{
  double x,y,z;
  double r;
  
  public:
  explicit Kugla(double r=0){
    x=0; y=0; z=0;
  }
  Kugla (double x, double y, double z, double r=0){
    Kugla::x=x;
    Kugla::y=y;
    Kugla::z=z;
    
    if (r<0) throw std::domain_error("Ilegalan poluprecnik");
    Kugla::r=r;
  }
  explicit Kugla(const std::tuple<double, double, double> &centar, double r=0){
    
   x= std::get<0> (centar);
   y=std::get<1> (centar);
   z=std::get<2> (centar);
   
   if (r<0) throw std::domain_error("Ilegalan poluprecnik");
     Kugla::r=r;
   
    
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
  
  Kugla &PostaviX (double x){
    Kugla::x=x;
    return *this;
  }
  Kugla &PostaviY (double y){
    Kugla::y=y;
    return *this;
  }
  Kugla &PostaviZ (double z){
    Kugla::z=z;
    return *this;
  }
  Kugla &PostaviCentar (double x, double y, double z){
    Kugla::x=x;
    Kugla::y=y;
    Kugla::z=z;
    return *this;
  }
  Kugla &PostaviCentar (const std::tuple <double, double, double> &centar){
    x= std::get<0> (centar);
    y=std::get<1> (centar);
    z=std::get<2> (centar);
    return *this;
  }
  Kugla &PostaviPoluprecnik(double r){
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    Kugla::r=r;
    return *this;
  }
  
  void Ispisi () const{
    std::cout << "{(" << x << "," << y << ","<< z << ")," << r << "}"; 
    std::cout << std::endl;
  }
  void Transliraj (double delta_x, double delta_y, double delta_z){
    x+=delta_x;
    y+=delta_y;
    z+=delta_z;
  }
  
  friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2){//EPS
    if(fabs(k1.x-k2.x)<=eps*(fabs(k1.x)+fabs(k2.x)) && fabs(k1.y-k2.y)<=eps*(fabs(k1.y)+fabs(k2.y)) && fabs(k1.z-k2.z)<=eps*(fabs(k1.z)+fabs(k2.z)) && 
    fabs(k1.r-k2.r)<=eps*(fabs(k1.r)+fabs(k2.r))) return true;
    return false;
    //fabs(k1.x-k2.x)<=eps*(fabs(k1.x)+fabs(k2.x))
  }
  friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2){
    if(fabs(k1.r-k2.r)<=eps*(fabs(k1.r)+fabs(k2.r))) return true;//EPS DODATI
    return false;
  }
  friend bool DaLiSuKoncentricne( const Kugla &k1, const Kugla &k2){
    if(fabs(k1.x-k2.x)<=eps*(fabs(k1.x)+fabs(k2.x)) && fabs(k1.y-k2.y)<=eps*(fabs(k1.y)+fabs(k2.y)) && fabs(k1.z-k2.z)<=eps*(fabs(k1.z)+fabs(k2.z))) return true;//EPS DODATI
    return false;
  }
  friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2){
    double rastojanje_centara=sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z));
    double zbir_poluprecnika=k1.r+k2.r;
    //rastojanje_centara==zbir_poluprecnik
    if(fabs(rastojanje_centara-zbir_poluprecnika)<=eps*(fabs(rastojanje_centara)+fabs(zbir_poluprecnika))) return true; //EPS DODATI
    return false;
  }
  friend bool DaLiSeDodirujuIznutra (const Kugla &k1, const Kugla &k2){
    double rastojanje_centara=sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z));
    double razlika_poluprecnika=abs(k1.r-k2.r);
    
    if(fabs(rastojanje_centara-razlika_poluprecnika)<=eps*(fabs(rastojanje_centara)+fabs(razlika_poluprecnika))) return true;//EPS DODATI
    return false;
    //rastojanje_centara==razlika_poluprecnika
    
  }
  friend bool DaLiSePreklapaju (const Kugla &k1, const Kugla &k2){
    double rastojanje_centara=sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z));
    double razlika_poluprecnika=abs(k1.r-k2.r);
    
    if(rastojanje_centara < razlika_poluprecnika) return true;
    return false;
  }
  friend bool DaLiSeSijeku (const Kugla &k1, const Kugla &k2){
    double rastojanje_centara=sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z));
    double zbir_poluprecnika=k1.r+k2.r;
    double razlika_poluprecnika=abs(k1.r-k2.r);
    if(zbir_poluprecnika > rastojanje_centara && rastojanje_centara > razlika_poluprecnika) return true;
    return false;
  }
  
  bool DaLiSadrzi(const Kugla &k) const{
    double rastojanje_centara=sqrt((x-k.x)*(x-k.x)+(y-k.y)*(y-k.y)+(z-k.z)*(z-k.z));
    double razlika_poluprecnika=abs(r-k.r);
    double zbir_poluprecnika=r+k.r;
    
    if(rastojanje_centara > razlika_poluprecnika ) return true;
    //|C1C2|>|r1-r2|
    return false;
  }
  
  friend double RastojanjeCentara (const Kugla &k1, const Kugla &k2){
    double rastojanje_centara=sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z));
    return rastojanje_centara;
    
  }
  
};



int main ()
{
  int n;
  std::cout << "Unesite broj kugla: ";
  do{
    std::cin>>n;
    if(!(std::cin) || n<1) std::cout << "Neispravan broj kugli, unesite ponovo!"<< std::endl;
    std::cin.clear();
    std::cin.ignore(1000, '\n');
  }while (!(std::cin) || n<1);
  
  std::vector<std::shared_ptr<Kugla>> v;
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
    auto pam_pok=std::make_shared<Kugla>(a,b,c,r);
    v.push_back(pam_pok);
    //gotov vektor
    }
    catch(std::domain_error e){
      std::cout << e.what();
      std::cout << std::endl; 
      i--;
    }
    
  }
  double delta_x, delta_y, delta_z;
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
  
  std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti:";
  std::transform(v.begin(), v.end(), v.begin(), [delta_x, delta_y, delta_z](std::shared_ptr<Kugla> pampok){
    pampok->Transliraj(delta_x, delta_y, delta_z);
    return pampok;
  });
  std::sort(v.begin(), v.end(),[](std::shared_ptr<Kugla> pampok1, std::shared_ptr<Kugla> pampok2){
    return pampok1->DajZapreminu()<pampok2->DajZapreminu();
    });
    
  std::for_each(v.begin(), v.end(), [](std::shared_ptr<Kugla>pampok){
    std::cout << std::endl;
    pampok->Ispisi();
    
  });
  
  auto pokazivac=std::max_element(v.begin(), v.end(), [](std::shared_ptr<Kugla>pampok1, std::shared_ptr<Kugla> pampok2){
     return  pampok1->DajPovrsinu()< pampok2->DajPovrsinu();
  });
  std::cout << std::endl;
  std::cout << "Kugla sa najvecom povrsinom je: " ;
  std::shared_ptr<Kugla> novipampok=std::make_shared<Kugla>(**pokazivac); //pokazivac postao pametan
  novipampok->Ispisi();
  //do ovdje radi vjerovatno **pokazivac je upitno
  int brojac(0);
  bool sijekuse=false;
  
  std::cout << std::endl;
  std::for_each(v.begin(), v.end(), [&brojac, v, &sijekuse](std::shared_ptr<Kugla>pampok){
    std::for_each(v.begin()+brojac, v.end(), [pampok, &sijekuse](std::shared_ptr<Kugla>pampok1){
      //int brojac;
      if(DaLiSeSijeku(*pampok, *pampok1)){
        std::cout <<"Presjecaju se kugle: ";
        
        pampok->Ispisi(); 
        std::cout << std::endl;
        pampok1->Ispisi();
        std::cout << std::endl;
        sijekuse=true;
      }
      
    });
    brojac++;
  });
  if(sijekuse==false){
    std::cout << "Ne postoje kugle koje se presjecaju!";
  }
	return 0;
}
