/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <cmath>
#include <vector>
#include <tuple>
#include <algorithm>
#include <memory>
#include <stdexcept>
const double EPSILON=0.000000001;
const double PI=4*atan(1.);

class Kugla
{
 double x,y,z,r;
 public:
 explicit Kugla(double r=0) 
 {
  if(std::cin && r>=0)
  {
   x=0; 
   y=0; 
   z=0; 
   Kugla::r=r;
  }
  else throw std::domain_error("Ilegalan poluprecnik");
 }
 Kugla(double x, double y, double z, double r=0)
 {
  if(std::cin && r>=0) 
  {
   Kugla::x=x; 
   Kugla::y=y; 
   Kugla::z=z;
   Kugla::r=r;
  }
  else throw std::domain_error("Ilegalan poluprecnik");
 }
 explicit Kugla(const std::tuple<double,double,double> &centar, double r=0)
 {
  if(std::cin && r>=0)
  {
   x=std::get<0>(centar);
   y=std::get<1>(centar);
   z=std::get<2>(centar);
   Kugla::r=r;
  }
  else throw std::domain_error("Ilegalan poluprecnik");
 }
 double DajX() const { return x; }
 double DajY() const { return y; }
 double DajZ() const { return z; }
 std::tuple<double,double,double> DajCentar() const 
 {
  auto pomocni=std::make_tuple(x,y,z);
  return pomocni;
 }
 double DajPoluprecnik() const { return r; }
 double DajPovrsinu() const { return 4*r*r*PI; }
 double DajZapreminu() const { return (4./3)*r*r*r*PI; }
 Kugla &PostaviX(double x) { Kugla::x=x; return *this; }
 Kugla &PostaviY(double y) { Kugla::y=y; return *this; }
 Kugla &PostaviZ(double z) { Kugla::z=z; return *this; }
 Kugla &PostaviCentar(double x, double y, double z) 
 {
  Kugla::x=x;
  Kugla::y=y;
  Kugla::z=z;
  return *this;
 }
 Kugla &PostaviCentar(const std::tuple<double,double,double> &centar)
 {
  Kugla::x=std::get<0> (centar);
  Kugla::y=std::get<1> (centar);
  Kugla::z=std::get<2> (centar);
  return *this;
 }
 Kugla &PostaviPoluprecnik(double r)
 {
  Kugla::r=r;
  return *this;
 }
 void Ispisi() const
 {
  std::cout << "{(" << DajX() << "," << DajY() << "," << DajZ() << ")," << DajPoluprecnik() << "}";
 }
 void Transliraj(double delta_x, double delta_y, double delta_z)
 {
  x+=delta_x;
  y+=delta_y;
  z+=delta_z;
 }
 friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
 friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
 friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
 friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
 friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
 friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
 friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
 bool DaLiSadrzi(const Kugla &k) const
 {
  auto rastojanje=std::sqrt(((x-k.x)*(x-k.x))+((y-k.y)*(y-k.y))+((z-k.z)*(z-k.z)));
  auto ukupno=rastojanje+k.r;
  if(ukupno<=r) return true;
  return false;
 }
 friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);
};

double RastojanjeCentara(const Kugla &k1, const Kugla &k2)
{
 return std::sqrt(((k1.x-k2.x)*(k1.x-k2.x))+((k1.y-k2.y)*(k1.y-k2.y))+((k1.z-k2.z)*(k1.z-k2.z)));
}

bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2)
{
 if((std::fabs(k1.r-k2.r)<=EPSILON*(std::fabs(k1.r)+std::fabs(k2.r))) && (std::fabs(k1.x-k2.x)<=EPSILON*(std::fabs(k1.x)+std::fabs(k2.x))) && (std::fabs(k1.y-k2.y)<=EPSILON*(std::fabs(k1.y)+std::fabs(k2.y))) && (std::fabs(k1.z-k2.z)<=EPSILON*(std::fabs(k1.z)+std::fabs(k2.z)))) return true;
 return false;
}

bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2)
{
 if(std::fabs(k1.r-k2.r)<=EPSILON*(std::fabs(k1.r)+std::fabs(k2.r))) return true;
 return false;
}

bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2)
{
 if((std::fabs(k1.x-k2.x)<=EPSILON*(std::fabs(k1.x)+std::fabs(k2.x))) && (std::fabs(k1.y-k2.y)<=EPSILON*(std::fabs(k1.y)+std::fabs(k2.y))) && (std::fabs(k1.z-k2.z)<=EPSILON*(std::fabs(k1.z)+std::fabs(k2.z)))) return true;
 return false;
}

bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2)
{
 auto rastojanje=RastojanjeCentara(k1,k2);
 auto ukupni_poluprecnik=(k1.r+k2.r);
 if(std::fabs(rastojanje-ukupni_poluprecnik)<EPSILON*(std::fabs(rastojanje)+std::fabs(ukupni_poluprecnik))) return true;
 return false;
}

bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2)
{
 auto rastojanje=RastojanjeCentara(k1,k2);
 if(k1.r>k2.r)
 {
  auto ukupno1=rastojanje+k2.r;
  if((std::fabs(ukupno1-k1.r)<EPSILON*(std::fabs(ukupno1)+std::fabs(k1.r)))) return true;
 }
 else if(k1.r<k2.r)
 {
  auto ukupno2=rastojanje+k1.r;
  if((std::fabs(ukupno2-k2.r)<EPSILON*(std::fabs(ukupno2)+std::fabs(k2.r)))) return true;
 }
 return false;
}

bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2)
{
 if(DaLiSeDodirujuIzvana(k1,k2)==true) return false;
 if(DaLiSeDodirujuIznutra(k1,k2)==true) return false;
 if(k1.DaLiSadrzi(k2)==true) return false;
 auto rastojanje=RastojanjeCentara(k1,k2);
 auto zbir_poluprecnika=(k1.r+k2.r);
 if(rastojanje<zbir_poluprecnika) return true;
 return false;
}

bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2)
{
 if(DaLiSeSijeku(k1,k2)==true) return true;
 return false;
}

int main ()
{
 int n;
 double x,y,z,r;
 std::cout << "Unesite broj kugla: ";
 unos: std::cin >> n;
 if(std::cin && n>0)
 {
  std::vector<std::shared_ptr<Kugla>> kugle(n);
  for(int i(0);i<n;i++)
  {
   unos2: std::cout << "Unesite centar " << i+1 << ". kugle: ";
   std::cin >> x >> y >> z;
   if(std::cin)
   {
    std::cout << "Unesite poluprecnik " << i+1 << ". kugle: ";
    std::cin >> r;
    try
    {
     kugle[i]=std::make_shared<Kugla> (x,y,z,r);
    }
    catch(std::domain_error e)
    {
     --i;
     std::cout << e.what() << std::endl;
     std::cin.clear();
     std::cin.ignore(10000,'\n');
    }
   }
   else 
   {
    std::cout << "Neispravan centar" <<  std::endl;
    std::cin.clear();
    std::cin.ignore(10000,'\n');
    goto unos2;
   }
  }
  double delta_x, delta_y, delta_z;
  std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
  unos3: std::cin >> delta_x >> delta_y >> delta_z;
  if(std::cin)
  {
   std::transform(kugle.begin(),kugle.end(),kugle.begin(),[=](std::shared_ptr<Kugla> pok) { pok->Transliraj(delta_x, delta_y, delta_z); return pok; });
   std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: " << std::endl;
   std::sort(kugle.begin(),kugle.end(),[](std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2) { return k1->DajZapreminu() < k2->DajZapreminu(); });
   std::for_each(kugle.begin(),kugle.end(),[](std::shared_ptr<Kugla> k) { k->Ispisi(); std::cout << std::endl; });
   std::cout << "Kugla sa najvecom povrsinom je: ";
   auto pokazivac=*std::max_element(kugle.begin(),kugle.end(),[](std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2) { return k1->DajPovrsinu() < k2->DajPovrsinu(); });
   pokazivac->Ispisi();
   std::cout << std::endl;
   int brojac(0);
   std::for_each(kugle.begin(),kugle.end(), [kugle,&brojac](std::shared_ptr<Kugla> k) 
   { 
    int pozicija(0);
    for(int i(0);i<kugle.size();i++)
    {
     if(k==kugle[i]) pozicija=i;
    }
    std::for_each(kugle.begin()+pozicija,kugle.end(),[k, &brojac] (std::shared_ptr<Kugla> k2) 
    { 
     if(k!=k2 && DaLiSeSijeku(*k,*k2)==true) 
     { 
      brojac++;
      std::cout << "Presjecaju se kugle: ";
      k->Ispisi();
      std::cout << std::endl;
      k2->Ispisi(); 
      std::cout << std::endl;
     } 
    });
   });
   if(brojac<=0) std::cout << "Ne postoje kugle koje se presjecaju!";
  }
  else 
  {
   std::cout << "Neispravni parametri translacije, unesite ponovo!" << std::endl;
   std::cin.clear();
   std::cin.ignore(10000,'\n');
   goto unos3;
  }
 }
 else 
 {
  std::cout << "Neispravan broj kugli, unesite ponovo!" << std::endl;
  std::cin.clear();
  std::cin.ignore(10000,'\n');
  goto unos;
 }
 return 0;
}
