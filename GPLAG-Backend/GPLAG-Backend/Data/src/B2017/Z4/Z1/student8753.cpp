/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <tuple>
#include <cmath>
#include <stdexcept>
#include <vector>
#include <memory>
#include <algorithm>
const double PI=4*std::atan(1);
const double EP=1e-10;
using std::cout;
using std::cin;
using std::shared_ptr;
using std::vector;

bool Poredi(double a,double b)
{
  return (std::abs(a-b)<EP*(std::abs(a)+std::abs(b)));
}

class Kugla
{
  double x,y,z,r;
public:
  explicit Kugla(double r = 0) {
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    Kugla::r=r; x=y=z=0;
  }
  Kugla(double x, double y, double z, double r = 0) {
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    Kugla::x=x;
    Kugla::y=y;
    Kugla::z=z;
    Kugla::r=r;
  }
  explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0) {
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    x=std::get<0>(centar);
    y=std::get<1>(centar);
    z=std::get<2>(centar);
    Kugla::r=r;
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
  Kugla &PostaviX(double x) {
    Kugla::x=x;
    return *this;
  }
  Kugla &PostaviY(double y) {
    Kugla::y=y;
    return *this;
  }
  Kugla &PostaviZ(double z) {
    Kugla::z=z;
    return *this;
  }
  Kugla &PostaviCentar(double x, double y, double z) {
    Kugla::x=x;
    Kugla::y=y;
    Kugla::z=z;
    return *this;
  }
  Kugla &PostaviCentar(const std::tuple<double, double, double> &centar) {
    x=std::get<0>(centar);
    y=std::get<1>(centar);
    z=std::get<2>(centar);
    return *this;
  }
  Kugla &PostaviPoluprecnik(double r) {
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    Kugla::r=r;
    return *this;
  }
  void Ispisi() const {
    cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}";
  }
  void Transliraj(double delta_x, double delta_y, double delta_z) {
    x+=delta_x;
    y+=delta_y;
    z+=delta_z;
  }
  friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2) {
    return Poredi(k1.x,k2.x) && Poredi(k1.y,k2.y) && Poredi(k1.z,k2.z) && Poredi(k1.r,k2.r);
  }
  friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2) {
    return Poredi(k1.r,k2.r);
  }
  friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2) {
    return Poredi(k1.x,k2.x) && Poredi(k1.y,k2.y) && Poredi(k1.z,k2.z);
  }
  friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2) {
    double d(RastojanjeCentara(k1,k2));
    return Poredi(k1.r+k2.r,d);
  }
  friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2) {
    double d(RastojanjeCentara(k1,k2));
    return (Poredi(k1.r,d+k2.r) || Poredi(k2.r,d+k1.r));
  }
  friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2) {
    double d(RastojanjeCentara(k1,k2));
    return (d<k1.r+k2.r || Poredi(d,k1.r+k2.r));
  }
  friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2) {
    double d(RastojanjeCentara(k1,k2));
      if(k2.r>k1.r) return (d<k2.r+k1.r && d>k2.r-k1.r);
      return (d<k2.r+k1.r && d>k1.r-k2.r);
  }
  bool DaLiSadrzi(const Kugla &k) const {
    if(Kugla::r<k.r) return false;
    double d(RastojanjeCentara(*this,k));
    if(d+k.r>Kugla::r) return false;
    return true;
  }
  friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2) {
    return std::sqrt((k2.x-k1.x)*(k2.x-k1.x)+(k2.y-k1.y)*(k2.y-k1.y)+(k2.z-k1.z)*(k2.z-k1.z));
  }
};

typedef shared_ptr<Kugla> pok_na_k;

void Unos(vector<pok_na_k> &vec,int n)
{
  double x(0),y(0),z(0),r(0);
  for(int i(0); i<n; i++) {
    try {
      cout<<"Unesite centar "<<i+1<<". kugle: ";
      cin>>x;
      if(!cin) throw std::logic_error("Neispravan centar");
      cin>>y;
      if(!cin) throw std::logic_error("Neispravan centar");
      cin>>z;
      if(!cin) throw std::logic_error("Neispravan centar");
      cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
      cin>>r;
      if(!cin || r<0) throw std::logic_error("Ilegalan poluprecnik");
      vec.emplace_back(std::make_shared<Kugla>(x,y,z,r));
    } catch(std::bad_alloc) {
      throw;
    } catch(std::logic_error izuzetak) {
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
  cout<<"Unesite broj kugla: ";
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
    double dx(0),dy(0),dz(0);
    cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    for(;;){
      cin>>dx;
      if(!cin){
        cout<<"Neispravni parametri translacije, unesite ponovo!"<<std::endl;
        cin.clear();
        cin.ignore(1000,'\n');
      }
      else{
        cin>>dy;
        if(!cin){
          cout<<"Neispravni parametri translacije, unesite ponovo!"<<std::endl;
          cin.clear();
          cin.ignore(1000,'\n');
        }
        else{
          cin>>dz;
          if(!cin){
            cout<<"Neispravni parametri translacije, unesite ponovo!"<<std::endl;
            cin.clear();
            cin.ignore(1000,'\n');
          }
          else break;
        }
      }
    }
    std::transform(vec.begin(),vec.end(),vec.begin(),[dx,dy,dz](pok_na_k k)->pok_na_k
    { k->Transliraj(dx,dy,dz); return k; });
    std::sort(vec.begin(),vec.end(),[](pok_na_k k1,pok_na_k k2) {
      return k1->DajZapreminu()<k2->DajZapreminu();
    });
    cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<std::endl;
    for_each(vec.begin(),vec.end(),[](pok_na_k k){ k->Ispisi(); cout<<std::endl; });
    auto max_p(std::max_element(vec.begin(),vec.end(),[](pok_na_k k1,pok_na_k k2) {
      return k1->DajPovrsinu()<k2->DajPovrsinu();
    }));
    cout<<"Kugla sa najvecom povrsinom je: ";
    (*max_p)->Ispisi();
    int brojac(0);
    auto it(vec.begin());
    std::for_each(vec.begin(),vec.end(),[&brojac,&vec,&it](pok_na_k k1) {
      std::for_each(it,vec.end(),[&brojac,k1](pok_na_k k2) {
        if(DaLiSeSijeku(*k1,*k2) && k1!=k2) {
          cout<<std::endl<<"Presjecaju se kugle: ";
          k1->Ispisi(); cout<<std::endl;
          k2->Ispisi();
          brojac++;
        }
      });
      it++;
    });
    if(brojac==0) cout<<std::endl<<"Ne postoje kugle koje se presjecaju!";
  } catch(...) {
    cout<<"Problemi sa memorijom!";
  }
  
  return 0;
}
