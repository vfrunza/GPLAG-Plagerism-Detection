/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <cmath>
#include <memory>
#include <utility>
#include <vector>
#include <tuple>

bool Jednake(double x, double y, double eps=1e-10) {
 if((x<0 && y>0) ||(x>0 && y<0)) return false;
 return std::fabs(x-y) <= eps*(std::fabs(x) + std::fabs(y));
}
const double PI(4*atan(1));

class Kugla{
 
 double x,y,z;
 double poluprecnik;
 
 public:
 
 explicit Kugla(double r=0) : x(0), y(0), z(0){
     if(r<0) throw std::domain_error("Ilegalan poluprecnik");
     else poluprecnik=r;
 }
 
 Kugla(double x, double y, double z, double r=0) : x(x), y(y), z(z), poluprecnik(r){
     if(r<0) throw std::domain_error("Ilegalan poluprecnik");
 }
 
 explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0) : x(std::get<0>(centar)), y(std::get<1>(centar)), z(std::get<2>(centar)), poluprecnik(r) {
     if(r<0) throw std::domain_error("Ilegalan poluprecnik");
     Kugla::poluprecnik=r;
 }
 
 double DajX() const {
     return x;
 }
 
 double DajY() const {
     return y;
 }
 
 double DajZ() const {
     return z;
 }
 
 std::tuple<double, double, double> DajCentar() const{
     return std::make_tuple(DajX(),DajY(),DajZ());
 }
 
 double DajPoluprecnik() const {
     return poluprecnik;
 }
 
 double DajPovrsinu() const {
     return 4*poluprecnik*poluprecnik*PI;
 }
 
 double DajZapreminu() const {
     return (4*poluprecnik*poluprecnik*poluprecnik*PI)/3.;
 }
 
 Kugla &PostaviX(double x){
     Kugla::x = x;
     return *this;
 }
 
 Kugla &PostaviY(double y){
     Kugla::y = y;
     return *this;
 }
 
 Kugla &PostaviZ(double z){
     Kugla::z = z;
     return *this;
 }
 
 Kugla &PostaviCentar(double x, double y, double z){
     Kugla::x = x; Kugla::y = y; Kugla::z = z;
     return *this;
 }
 
 Kugla &PostaviCentar(const std::tuple<double, double, double> &centar){
     Kugla::x = std::get<0>(centar); 
     Kugla::y = std::get<1>(centar);
     Kugla::z = std::get<2>(centar);
     std::make_tuple(Kugla::x, Kugla::y, Kugla::z);
     return *this;
 }
 
 Kugla &PostaviPoluprecnik(double r){
     if(r<0) throw std::domain_error("Ilegalan poluprecnik");
     Kugla::poluprecnik = r;
     return *this;
 }
 
 void Ispisi() const{
     std::cout << "{(" << DajX() << "," << DajY() << "," << DajZ() << ")," << DajPoluprecnik() << "}";
 }
 
 void Transliraj(double delta_x, double delta_y, double delta_z){
     Kugla::x+=delta_x;
     Kugla::y+=delta_y;
     Kugla::z+=delta_z;
 }
 
 friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2) {
     if(Jednake(k1.x,k2.x) && Jednake(k1.y,k2.y) && Jednake(k1.z,k2.z) && Jednake(k1.poluprecnik,k2.poluprecnik)) return true;
     return false;
 }
 
 friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2) {
     if(Jednake(k1.poluprecnik,k2.poluprecnik)) return true;
     return false;
 }
 
 friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2) {
     if(Jednake(k1.x,k2.x) && Jednake(k1.y,k2.y) && Jednake(k1.z,k2.z)) return true;
     return false;
 }
 
 friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2) {
  double d(sqrt(pow(k2.x-k1.x,2) + pow(k2.y-k1.y,2) + pow(k2.z-k1.z,2)));
  if(Jednake(std::fabs(d), std::fabs(k2.poluprecnik-k1.poluprecnik))) return true;
  return false;
 }
 
 friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2) {
  double d(sqrt(pow(k2.x-k1.x,2) + pow(k2.y-k1.y,2) + pow(k2.z-k1.z,2)));
  if(DaLiSeDodirujuIzvana(k1,k2) == true) return false;
  if(Jednake(d, std::fabs(k2.poluprecnik-k1.poluprecnik))) return true;
  return false;
 }
    
 friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2) {
  double d(sqrt(pow(k2.x-k1.x,2) + pow(k2.y-k1.y,2) + pow(k2.z-k1.z,2)));
  if(std::fabs(k2.poluprecnik-k1.poluprecnik) < std::fabs(d) && std::fabs(d) < (k1.poluprecnik+k2.poluprecnik)) return true;
  return false;
 }
 
 friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2) {
   double d(sqrt(pow(k2.x-k1.x,2) + pow(k2.y-k1.y,2) + pow(k2.z-k1.z,2)));
   return d;
 }
 
 bool DaLiSadrzi(const Kugla &k) const {
  double d(sqrt(std::fabs(pow(x-k.x,2) + pow(y-k.y,2) + pow(z-k.z,2))));
  if(d<std::fabs(poluprecnik-k.poluprecnik)) return true;
  return false;
 }
 
};

int main ()
{
 
   int br_kugli;
   Kugla lopta;
   std::cout << "Unesite broj kugla: ";
   
   for(;;){
    try {
   // std::cin >> br_kugli;
    if(!(std::cin >> br_kugli) || br_kugli<1) throw std::domain_error("Neispravan broj kugli, unesite ponovo!");
    else break;
    
    }catch(std::domain_error izuzetak) {
     std::cout << izuzetak.what() << std::endl;
     std::cin.clear();
     std::cin.ignore(10000, '\n');
    }
   }
   
   std::vector<std::shared_ptr<Kugla>> vektor;
   double x,y,z,r;
   
   for(int i=0; i<br_kugli; i++) {
    int m;
   PETLJA:do{
     std::cout << "Unesite centar " << i+1 << ". kugle: ";
     std::cin >> x >> y >> z;
     
     if(!std::cin){
      std::cout << "Neispravan centar\n";
      std::cin.clear();
      std::cin.ignore(10000, '\n');
     } else break;
    }while(1);
    
     lopta.PostaviX(x);
     lopta.PostaviY(y);
     lopta.PostaviZ(z);

      do {
        std::cout << "Unesite poluprecnik " << i+1 << ". kugle: ";
        std::cin >> r;
      
        if(!std::cin || r<0){
            std::cout << "Ilegalan poluprecnik\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            m = i;
            i--;
        } else {
        lopta.PostaviPoluprecnik(r);
        break;
       }
        if(m>i) {
         i++;
         goto PETLJA;
        }else break;
       
     }while(1);
     
     try {
     
     auto pok(std::make_shared<Kugla>(lopta));
     vektor.push_back(pok);
     
     }catch(std::domain_error izuzetak) {
      std::cout << izuzetak.what() << ", ponovite unos!" << std::endl;
      i--;
     }catch(std::bad_alloc izuzetak) {
      std::cout << "Nema dovoljno memorije!" << std::endl;
      return 0;
     }
    
   }
   
   std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
   double delta_x,delta_y,delta_z;
   
   do {
   std::cin >> delta_x >> delta_y >> delta_z;
   if(!std::cin) {
     std::cout << "Neispravni parametri translacije, unesite ponovo!\n";
     std::cin.clear();
     std::cin.ignore(10000, '\n');
   }else break;
   
   }while(1);
   
   
   
   std::transform(vektor.begin(), vektor.end(), vektor.begin(), [delta_x,delta_y,delta_z](std::shared_ptr<Kugla> k){ k->Transliraj(delta_x,delta_y,delta_z); return k;});
   
  
   std::sort(vektor.begin(), vektor.end(), [](const std::shared_ptr<Kugla> &k1,const std::shared_ptr<Kugla> &k2) {return k1->DajZapreminu() < k2->DajZapreminu();});
   
   std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<< std::endl;
   std::for_each(vektor.begin(), vektor.end(), [](const std::shared_ptr<Kugla> &k){k->Ispisi(); std::cout<<std::endl;});
   
   std::cout << "Kugla sa najvecom povrsinom je: ";
   auto povrs = *std::max_element(vektor.begin(), vektor.end(), [](const std::shared_ptr<Kugla> &k1, const std::shared_ptr<Kugla> &k2){return k1->DajPovrsinu() < k2->DajPovrsinu();});
   povrs->Ispisi();
   std::cout << std::endl;
   
   bool sijeku(false);
   int brojac(1);
   std::for_each(vektor.begin(), vektor.end(), [&sijeku, &brojac, vektor](const std::shared_ptr<Kugla> &k1) {
    
     std::for_each(vektor.begin()+brojac++, vektor.end(), [k1, &sijeku](const std::shared_ptr<Kugla> &k2) {
    
      if(DaLiSeSijeku(*k1,*k2)==true) {
     
       std::cout << "Presjecaju se kugle: ";
       k1->Ispisi();
       std::cout << std::endl;
       k2->Ispisi();
       std::cout << std::endl;
       sijeku=true;
     
      }
    });
   });
  if(sijeku==false) std::cout << "Ne postoje kugle koje se presjecaju!";
	return 0;
}
