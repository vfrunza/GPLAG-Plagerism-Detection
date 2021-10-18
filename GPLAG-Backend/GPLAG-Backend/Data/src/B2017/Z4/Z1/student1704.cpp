/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <cmath>
#include <memory>
#include <vector>
#include <algorithm>

const double PI(4*atan(1));
const double eps(0.0000000001);

class Kugla {
  double x,y,z,r;
  public:
  explicit Kugla(double r=0) : x(0), y(0), z(0) {if(r<0) throw std::domain_error("Ilegalan poluprecnik"); r=r;}
  Kugla(double x, double y, double z, double r=0) : x(x), y(y), z(z), r(r) {if(r<0) throw std::domain_error("Ilegalan poluprecnik");}
  explicit Kugla(const std::tuple<double, double, double> &centar, double r=0) : r(r) {
      if(r<0) throw std::domain_error("Ilegalan poluprecnik");
      x=std::get<0>(centar); y=std::get<1>(centar); z=std::get<2>(centar);
  }
  double DajX() const {return x;}
  double DajY() const {return y;}
  double DajZ() const {return z;}
  std::tuple<double, double, double> DajCentar() const {
      std::tuple<double, double, double> t;
      t=std::make_tuple(x,y,z);
      return t;
  }
  double DajPoluprecnik() const {return r;}
  double DajPovrsinu() const {return 4*PI*r*r;}
  double DajZapreminu() const {return (4*r*r*r*PI)/3;}
  Kugla &PostaviX(double x) {Kugla::x=x; return *this;}
  Kugla &PostaviY(double y) {Kugla::y=y; return *this;}
  Kugla &PostaviZ(double z) {Kugla::z=z; return *this;}
  Kugla &PostaviCentar(double x, double y, double z) {
      Kugla::x=x; Kugla::y=y; Kugla::z=z;
      return *this;
  }
  Kugla &PostaviCentar(const std::tuple<double, double, double> &centar) {
      x=std::get<0>(centar); y=std::get<1>(centar); z=std::get<2>(centar);
      return *this;
  }
  Kugla &PostaviPoluprecnik(double r) {
      if(r<0) throw std::domain_error("Ilegalan poluprecnik");
      Kugla::r=r;
      return *this;
  }
  void Ispisi() const {
      std::cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}"<<std::endl;
  }
  void Transliraj(double delta_x, double delta_y, double delta_z) {
      x+=delta_x; y+=delta_y; z+=delta_z;
  }
  friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
  bool DaLiSadrzi (const Kugla &k) const {
      if(DaLiSuKoncentricne(*this, k) && k.r<=r) return true;
      if(k.r<r && RastojanjeCentara(*this, k)+k.r<r) return true;
      return false;
  }
  friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);
};

 bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2) {
    if(abs(k1.x-k2.x)<=eps*(abs(k1.x)+abs(k2.x)) && abs(k1.y-k2.y)<=eps*(abs(k1.y)+abs(k2.y)) &&
    abs(k1.z-k2.z)<=eps*(abs(k1.z)+abs(k2.z)) && abs(k1.r-k2.r)<=eps*(abs(k1.r)+abs(k2.r))) return true;
    return false;
}
 bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2) {
    if(abs(k1.r-k2.r)<=eps*(abs(k1.r)+abs(k2.r))) return true;
    return false;
}
bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2) {
    if(abs(k1.x-k2.x)<=eps*(abs(k1.x)+abs(k2.x)) && abs(k1.y-k2.y)<=eps*(abs(k1.y)+abs(k2.y)) &&
    abs(k1.z-k2.z)<=eps*(abs(k1.z)+abs(k2.z))) return true;
    return false;
}
bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2) {
    if(abs(RastojanjeCentara(k1,k2)-(k1.r+k2.r))<=eps*(abs(RastojanjeCentara(k1,k2))+abs(k1.r+k2.r))) return true;
    return false;
}
bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2) {
    if(k1.r>k2.r) {
        if(abs(k1.r-(RastojanjeCentara(k1,k2)+k2.r))<=eps*(abs(k1.r)+abs(k2.r+RastojanjeCentara(k1,k2)))) return true;
    }
    else {
        if(abs(k2.r-(RastojanjeCentara(k1,k2)+k1.r))<=eps*(abs(k2.r)+abs(k1.r+RastojanjeCentara(k1,k2)))) return true;
    }
    return false;
}
bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2) {
    if(DaLiSuKoncentricne(k1,k2) || DaLiSeDodirujuIznutra(k1,k2) || DaLiSeSijeku(k1,k2) ||
    k1.DaLiSadrzi(k2) || k2.DaLiSadrzi(k1)) return true;
    return false;
}
bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2) {
    if(k1.r+k2.r>RastojanjeCentara(k1,k2) && k1.r+RastojanjeCentara(k1,k2)>k2.r && k2.r+RastojanjeCentara(k1,k2)>k1.r) return true;
    return false;
}
double RastojanjeCentara(const Kugla &k1, const Kugla &k2) {
    return sqrt((k1.x-k2.x)*(k1.x-k2.x) + (k1.y-k2.y)*(k1.y-k2.y) + (k1.z-k2.z)*(k1.z-k2.z));
}



int main ()
{
    int n;
    std::cout<<"Unesite broj kugla: ";
    std::cin>>n;
        while(n<=0 || !std::cin) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;
            std::cin>>n;
        }
        std::vector<std::shared_ptr<Kugla>> v(n);
    try {
        for(int i=0; i<n; i++) {
            double x,y,z,r;
            std::cout<<"Unesite centar "<<i+1<<". kugle: ";
            std::cin>>x>>y>>z;
            while(!std::cin) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout<<"Neispravan centar"<<std::endl;
                std::cout<<"Unesite centar "<<i+1<<". kugle: ";
                std::cin>>x>>y>>z;
            }
            std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
            std::cin>>r;
            while(r<0 || !std::cin) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout<<"Ilegalan poluprecnik"<<std::endl;
                std::cout<<"Unesite centar "<<i+1<<". kugle: ";
                std::cin>>x>>y>>z;
                while(!std::cin) {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    std::cout<<"Neispravan centar"<<std::endl;
                    std::cout<<"Unesite centar"<<i+1<<". kugle: ";
                    std::cin>>x>>y>>z;
                }
                std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
                std::cin>>r;
            }
            v[i]=std::make_shared<Kugla>(x,y,z,r);
        }
    }
    catch(...) {
        std::cout<<"Nedovoljno memorije";
    }
    double delta_x, delta_y, delta_z;
    std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    std::cin>>delta_x>>delta_y>>delta_z;
    while(!std::cin) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout<<"Neispravni parametri translacije, unesite ponovo!"<<std::endl;
        std::cin>>delta_x>>delta_y>>delta_z;
    }
    std::transform(v.begin(), v.end(), v.begin(), [delta_x,delta_y,delta_z](std::shared_ptr<Kugla> k) {
     k->Transliraj(delta_x,delta_y,delta_z);
        return k;});
   std::sort(v.begin(), v.end(), [](std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2) {return k1->DajZapreminu()<k2->DajZapreminu();});
    std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<std::endl;
    std::for_each(v.begin(), v.end(), [](std::shared_ptr<Kugla> k) {k->Ispisi();});
    auto it(std::max_element(v.begin(), v.end(), [](std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2) {
        return k1->DajPovrsinu()<k2->DajPovrsinu();}));
        std::cout<<"Kugla sa najvecom povrsinom je: ";
        (*it)->Ispisi();
        static bool ispisan(false);
        std::for_each(v.begin(), v.end(), [v,ispisan](std::shared_ptr<Kugla> k1) {
            int i(0);
            while(v[i]!=k1) i++;
            std::for_each(v.begin()+i, v.end(), [k1,ispisan](std::shared_ptr<Kugla> k2) {
                if(DaLiSeSijeku(*k1, *k2)) {
                    ispisan=true;
                    std::cout<<"Presjecaju se kugle: ";
                    k1->Ispisi(); k2->Ispisi();
                }
            });
        });
        if(!ispisan) std::cout<<"Ne postoje kugle koje se presjecaju!";

    
	return 0;
}
