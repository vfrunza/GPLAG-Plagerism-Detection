/B2017/2018: Zadaća 4, Zadatak 2
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <algorithm>
#include <tuple>
#include <memory>
#include <vector>
const double PI=4*std::atan(1);
const double EP=1e-10;
using std::cout;
using std::cin;
using std::vector;
using std::shared_ptr;

bool Poredi(double a,double b) {
  return std::abs(a-b)<EP*(std::abs(a)+std::abs(b));
}
class NepreklapajucaKugla {
  double x,y,z,r;
  static NepreklapajucaKugla *pocetni;
  NepreklapajucaKugla *prethodni=nullptr;
  void Testiraj(NepreklapajucaKugla *pocetni,NepreklapajucaKugla *ovaj,double x1=0,double y1=0,double z1=0,double r1=0) {
  auto poc(pocetni);
  if(!pocetni) {
    pocetni=ovaj;
    return;
  }
  double d(std::sqrt((pocetni->DajX()-x1)*(pocetni->DajX()-x1)+(pocetni->DajY()-y1)*(pocetni->DajY()-y1)+
                     (pocetni->DajZ()-z1)*(pocetni->DajZ()-z1)));
  while(poc!=nullptr) {
    if(d<poc->r+r1 || Poredi(d,poc->r+r1)) throw std::logic_error("Nedozvoljeno preklapanje");
    poc=poc->prethodni;
  }
  if(!prethodni) prethodni=pocetni;
}
public:
  explicit NepreklapajucaKugla(double r = 0) {
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    Testiraj(pocetni,this,x,y,z,r); pocetni=this;
    NepreklapajucaKugla::r=r; x=y=z=0;
  }
  NepreklapajucaKugla(double x, double y, double z, double r = 0) {
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    Testiraj(pocetni,this,x,y,z,r); pocetni=this;
    NepreklapajucaKugla::x=x;
    NepreklapajucaKugla::y=y;
    NepreklapajucaKugla::z=z;
    NepreklapajucaKugla::r=r;
  }
  explicit NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r = 0) {
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    Testiraj(pocetni,this,std::get<0>(centar),std::get<1>(centar),std::get<2>(centar),r); pocetni=this;
    x=std::get<0>(centar);
    y=std::get<1>(centar);
    z=std::get<2>(centar);
    NepreklapajucaKugla::r=r;
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
  std::tuple<double, double, double> DajCentar() const {
    return std::make_tuple(x,y,z);
  }
  double DajPoluprecnik() const {
    return r;
  }
  double DajPovrsinu() const {
    return 4./3*PI*r*r*r;
  }
  double DajZapreminu() const {
    return 4.*PI*r*r;
  }
  NepreklapajucaKugla &PostaviX(double x) {
    double pom(NepreklapajucaKugla::x);
    NepreklapajucaKugla::x=x;
    try{
      Testiraj(pocetni,this,x,y,z,r);
    }
    catch(...){
      NepreklapajucaKugla::x=pom; throw;
    }
    return *this;
  }
  NepreklapajucaKugla &PostaviY(double y) {
    double pom(NepreklapajucaKugla::y);
    NepreklapajucaKugla::y=y;
    try{
      Testiraj(pocetni,this,x,y,z,r);
    }
    catch(...){
      NepreklapajucaKugla::y=pom; throw;
    }
    return *this;
  }
  NepreklapajucaKugla &PostaviZ(double z) {
    double pom(NepreklapajucaKugla::z);
    NepreklapajucaKugla::z=z;
    try{
      Testiraj(pocetni,this,x,y,z,r);
    }
    catch(...){
      NepreklapajucaKugla::z=pom; throw;
    }
    return *this;
  }
  NepreklapajucaKugla &PostaviCentar(double x, double y, double z) {
    double pom1(NepreklapajucaKugla::x),pom2(NepreklapajucaKugla::y),pom3(NepreklapajucaKugla::z);
    NepreklapajucaKugla::x=x;
    NepreklapajucaKugla::y=y;
    NepreklapajucaKugla::z=z;
    try{
      Testiraj(pocetni,this,x,y,z,r);
    }
    catch(...){
      NepreklapajucaKugla::x=pom1; NepreklapajucaKugla::y=pom2; NepreklapajucaKugla::z=pom3; throw;
    }
    return *this;
  }
  NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar) {
    double pom1(NepreklapajucaKugla::x),pom2(NepreklapajucaKugla::y),pom3(NepreklapajucaKugla::z);
    x=std::get<0>(centar);
    y=std::get<1>(centar);
    z=std::get<2>(centar);
    try{
      Testiraj(pocetni,this,x,y,z,r);
    }
    catch(...){
      NepreklapajucaKugla::x=pom1; NepreklapajucaKugla::y=pom2; NepreklapajucaKugla::z=pom3; throw;
    }
    return *this;
  }
  NepreklapajucaKugla &PostaviPoluprecnik(double r) {
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    double pom(r);
    NepreklapajucaKugla::r=r;
    try{
      Testiraj(pocetni,this,x,y,z,r);
    }
    catch(...){
      NepreklapajucaKugla::r=pom; throw;
    }
    return *this;
  }
  void Ispisi() const {
    cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}";
  }
  void Transliraj(double delta_x, double delta_y, double delta_z) {
    double pom1(x),pom2(y),pom3(z);
    x+=delta_x;
    y+=delta_y;
    z+=delta_z;
    try{
      Testiraj(pocetni,this,x,y,z,r);
    }
    catch(...){
      x=pom1; y=pom2; z=pom3; throw;
    }
  }
  bool DaLiSadrzi(const NepreklapajucaKugla &k) const{
    if(NepreklapajucaKugla::r<k.r) return false;
    double d(RastojanjeCentara(*this,k));
    if(d+k.r>NepreklapajucaKugla::r) return false;
    return true;
  }
  friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2) {
    return std::sqrt((k2.x-k1.x)*(k2.x-k1.x)+(k2.y-k1.y)*(k2.y-k1.y)+(k2.z-k1.z)*(k2.z-k1.z));
  }
  NepreklapajucaKugla(const NepreklapajucaKugla &k)=delete;
  NepreklapajucaKugla &operator=(const NepreklapajucaKugla &k)=delete;
};
NepreklapajucaKugla *NepreklapajucaKugla::pocetni(nullptr);

typedef shared_ptr<NepreklapajucaKugla> pok_na_k;
void Unos(vector<pok_na_k> &vec,int n){
  double x(0),y(0),z(0),r(0);
    for(int i(0);i<n;i++){
      try{
        cout<<"Unesite centar za "<<i+1<<". kuglu: ";
        for(;;){
        try{
        cin>>x; if(!cin) throw std::logic_error("Neispravan centar, unesite ponovo:");
        cin>>y; if(!cin) throw std::logic_error("Neispravan centar, unesite ponovo:");
        cin>>z; if(!cin) throw std::logic_error("Neispravan centar, unesite ponovo:");
        break;
        }
        catch(std::logic_error izuzetak){
          cout<<izuzetak.what()<<std::endl;
          cin.clear();
          cin.ignore(1000,'\n');
        }}
        cout<<"Unesite poluprecnik: ";
        for(;;){
          cin>>r; if(!cin || r<0) cout<<"Neispravan poluprecnik, unesite ponovo:"<<std::endl;
          else break;
          cin.clear();
          cin.ignore(1000,'\n');
        }
        auto pok(std::make_shared<NepreklapajucaKugla>(x,y,z,r));
        vec.emplace_back(pok);
      }
      catch(std::bad_alloc){ throw; }
      catch(std::logic_error izuzetak){
        cout<<izuzetak.what()<<std::endl;
        i--;
        cin.clear();
        cin.ignore(1000,'\n');
      }
    }
}

int main ()
{
  vector<pok_na_k> vec;
  int n(0);
  cout<<"Unesite broj kugli: ";
  for(;;){
    cin>>n;
    if(!cin || n<1){
      cin.clear();
      cin.ignore(1000,'\n');
      cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;
    }
    else break;
  }
  try {
    Unos(vec,n);
    std::sort(vec.begin(),vec.end(),[](pok_na_k k1,pok_na_k k2) {
      return k1->DajPovrsinu()<k2->DajPovrsinu();});
    cout<<std::endl<<"Kugle nakon obavljenog sortiranja: "<<std::endl;
    for_each(vec.begin(),vec.end(),[](pok_na_k k){ k->Ispisi(); cout<<std::endl; });
  } catch(...) {
    cout<<"Problemi sa memorijom!";
  }
  
  return 0;
}
