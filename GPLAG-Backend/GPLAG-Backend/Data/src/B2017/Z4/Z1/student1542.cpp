/B2017/2018: Zadaća 4, Zadatak 1

#include <iostream>
#include <stdexcept>
#include <tuple>
#include <cmath>
#include <algorithm>
#include <memory>
#include <vector>
const double Eps(0.000000001);
const double PI(atan(1)*4);

class Kugla
{
  double x,y,z,r;
public:
  explicit Kugla(double r=0) {
    Kugla::r=r;
  }
  Kugla(double x,double y,double z,double r=0) {
    if(r<0)throw std::domain_error("Ilegalan poluprecnik");
    else {
      Kugla::x=x;
      Kugla::y=y;
      Kugla::z=z;
      Kugla::r=r;
    }
  }
  explicit Kugla(const std::tuple<double,double,double>&centar,double r=0) {
    if(r<0)throw std::domain_error("Ilegalan poluprecnik");
    else {
      Kugla::x=std::get<0>(centar);
      Kugla::y=std::get<1>(centar);
      Kugla::z=std::get<2>(centar);
      Kugla::r=r;
    }
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

  std::tuple<double,double,double>DajCentar()const {
    std::tuple<double,double,double>centar;
    std::get<0>(centar)=DajX();
    std::get<1>(centar)=DajY();
    std::get<2>(centar)=DajZ();
    return centar;
  }
  double DajPoluprecnik()const {
    return r;
  }
  double DajPovrsinu()const {
    return 4*r*r*PI;
  }
  double DajZapreminu()const {
    return (4/3)*r*r*r*PI;
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
  Kugla &PostaviCentar(double x,double y,double z) {
    Kugla::x=x;
    Kugla::y=y;
    Kugla::z=z;
    return *this;
  }

  Kugla &PostaviCentar(const std::tuple<double,double,double> &centar) {
    Kugla::x=std::get<0>(centar);
    Kugla::y=std::get<1>(centar);
    Kugla::z=std::get<2>(centar);
    return *this;
  }
  Kugla &PostaviPoluprecnik(double R) {
    if(r<0)throw std::domain_error("Ilegalan poluprecnik");
    else {
      Kugla::r=R;
      return *this;
    }
  }
  void Ispisi()const {
    std::cout << "{("<<DajX()<<","<<DajY()<<","<<DajZ()<<"),"<<DajPoluprecnik()<<"}" << std::endl;
  }
  void Transliraj(double delta_x,double delta_y,double delta_z);
  friend bool DaLiSuIdenticne(const Kugla &k1,const Kugla &k2);
  friend bool DaLiSuPodudarne(const Kugla &k1,const Kugla &k2);
  friend bool DaLiSuKoncentricne(const Kugla &k1,const Kugla &k2);
  friend bool DaLiSeDodirujuIzvana(const Kugla &k1,const Kugla &k2);
  friend bool DaLiSeDodirujuIznutra(const Kugla &k1,const Kugla &k2);
  friend bool DaLiSePreklapaju(const Kugla &k1,const Kugla &k2);
  friend bool DaLiSeSijeku(const Kugla &k1,const Kugla &k2);
  bool DaLiSadrzi(const Kugla &k)const;
  friend double RastojanjeCentara(const Kugla &k1,const Kugla &k2);
};

void Kugla::Transliraj(double delta_x,double delta_y,double delta_z)
{
  Kugla::x+=delta_x;
  Kugla::y+=delta_y;
  Kugla::z+=delta_z;
}
bool DaLiSuIdenticne(const Kugla &k1,const Kugla &k2)
{
  if(fabs(k1.x-k2.x)<Eps*(fabs(k1.x)+fabs(k2.x)) && fabs(k1.y-k2.y)<Eps*(fabs(k1.y)+fabs(k2.y)) && fabs(k1.z-k2.z)<Eps*(fabs(k1.z)+fabs(k2.z)) && fabs(k1.r-k2.r)<Eps*(fabs(k1.r)+fabs(k2.r)))return true;
  return false;
}
bool DaLiSuPodudarne(const Kugla &k1,const Kugla &k2)
{
  if(fabs(k1.r-k2.r)<Eps*(fabs(k1.r)+fabs(k2.r)))return true;
  return false;
}
bool DaLiSuKoncentricne(const Kugla &k1,const Kugla &k2)
{
  if(fabs(k1.x-k2.x)<Eps*(fabs(k1.x)+fabs(k2.x)) && fabs(k1.y-k2.y)<Eps*(fabs(k1.y)+fabs(k2.y)) && fabs(k1.z-k2.z)<Eps*(fabs(k1.z)+fabs(k2.z)))return true;
  return false;
}
double RastojanjeCentara(const Kugla &k1, const Kugla &k2)
{
  double d;
  d=std::sqrt((k2.x-k1.x)*(k2.x-k1.x)+(k2.y-k1.y)*(k2.y-k1.y)+(k2.z-k1.z)*(k2.z-k1.z));
  return d;
}
bool DaLiSeDodirujuIzvana(const Kugla &k1,const Kugla &k2)
{
  if(fabs(RastojanjeCentara(k1,k2)-(k1.r+k2.r))<Eps*((fabs(RastojanjeCentara(k1,k2))) + fabs(k1.r+k2.r)))return true;
  return false;
}
bool DaLiSeDodirujuIznutra(const Kugla &k1,const Kugla &k2)
{
  if(fabs(RastojanjeCentara(k1,k2)-(k2.r-k1.r))<Eps*((fabs(RastojanjeCentara(k1,k2))) +fabs(k2.r-k1.r)))return true;
  return false;
}
bool DaLiSeSijeku(const Kugla &k1,const Kugla &k2)
{
  if((k2.r-k1.r)<RastojanjeCentara(k1,k2) && RastojanjeCentara(k1,k2)<(k1.r+k2.r))return true;
  return false;
}
bool DaLiSePreklapaju(const Kugla &k1,const Kugla &k2)
{
  return DaLiSuIdenticne(k1,k2);
}
bool Kugla::DaLiSadrzi(const Kugla &k)const
{
  if(RastojanjeCentara(*this,k)<(*this).r-k.r)return true;
  return false;
}

int main ()
{
  int n(0);
  std::cout <<"Unesite broj kugla: ";
  std::cin >> n;
  while(n<=0 || !std::cin) {
    std::cout << "Neispravan broj kugli, unesite ponovo!" <<std::endl;
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    std::cin>>n;
  }
  std::vector<std::shared_ptr<Kugla>>v;
  double dx,dy,dz;
  try {
    for(int i=0; i<n; i++) {

      std::cout << "Unesite centar "<<i+1<<". kugle: " ;
      double x,y,z,r;
      std::cin >> x>>y>>z;
      while(!std::cin) {
        std::cout << "Neispravan centar"<<std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Unesite centar "<<i+1<<". kugle: " ;
        std::cin >>x>>y>>z;
      }

      std::cout << "Unesite poluprecnik "<<i+1<<". kugle: ";
      std::cin >> r;
      while(r<0 || !std::cin){
        std::cout << "Ilegalan poluprecnik" << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
           std::cout << "Unesite centar "<<i+1<<". kugle: " ;
      std::cin >> x>>y>>z;
      while(!std::cin) {
        std::cout << "Neispravan centar"<<std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Unesite centar "<<i+1<<". kugle: " ;
        std::cin >>x>>y>>z;
      }
        std::cout << "Unesite poluprecnik "<<i+1<<". kugle: ";
        std::cin >> r;
      }
      Kugla kug(x,y,z,r);
      v.push_back(std::make_shared<Kugla>(kug));
    }
    std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): " ;
    std::cin >> dx>>dy>>dz;
     while(!std::cin) {
        std::cout << "Neispravni parametri translacije, unesite ponovo!"<<std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cin >>dx>>dy>>dz;
     }
    std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<std::endl ;
    std::transform(v.begin(),v.end(),v.begin(),[dx,dy,dz](std::shared_ptr<Kugla> k) {
      k->Transliraj(dx,dy,dz);
      return k;
    });
    std::sort(v.begin(),v.end(),[](std::shared_ptr<Kugla>k1,std::shared_ptr<Kugla>k2 ) {
      return k1->DajZapreminu() < k2->DajZapreminu();
    });
    std::for_each(v.begin(),v.end(),[](std::shared_ptr<Kugla>k) {
      k->Ispisi();
    });
    std::cout << "Kugla sa najvecom povrsinom je: ";
    auto  K=*(std::max_element(v.begin(),v.end(),[](std::shared_ptr<Kugla>k1,std::shared_ptr<Kugla>k2) {
      return k1->DajPovrsinu() < k2->DajPovrsinu();
    }));
    K->Ispisi();
    std::vector<std::pair<Kugla,Kugla>>parovi ;
    auto it1(v.begin());
    std::for_each(it1,v.end(),[&v,&parovi,it1](std::shared_ptr<Kugla> k1) {
      auto it2(it1+1);
      if(it2!=v.begin()) {
        std::for_each(it2,v.end(),[&v,k1,&parovi](std::shared_ptr<Kugla>k2) {
          if(DaLiSeSijeku(*k1,*k2)) {
            parovi.push_back(std::make_pair(*k1,*k2));
          }

        });


      }
    });



    if(parovi.size()==0)std::cout << "Ne postoje kugle koje se presjecaju!" ;
    else {

      for(int i=0; i<parovi.size()-1; i++) {
        std::cout << "Presjecaju se kugle: " ;
        std::shared_ptr<Kugla> pok(new Kugla(parovi[i].first));
        pok->Ispisi();
        std::shared_ptr<Kugla> pok1(new Kugla(parovi[i].second));
        pok1->Ispisi();
      }
    }
  } catch(std::domain_error izuzetak) {
    std::cout << izuzetak.what() ;
  }

  return 0;
}
