/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <tuple>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>

const double EP(1e-10);
const double PI(4*std::atan(1.));

class Kugla{
  double x, y, z, r;
  public:
  explicit Kugla(double r=0){
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    x=0; y=0; z=0; this->r=r;
  }
  Kugla(double x, double y, double z, double r=0){
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    this->x=x; this->y=y; this->z=z; this->r=r;
  }
  explicit Kugla(const std::tuple<double, double, double> &centar, double r=0){
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    x=std::get<0>(centar); y=std::get<1>(centar); z=std::get<2>(centar); this->r=r;
  }
  double DajX() const {return this->x;}
  double DajY() const {return this->y;}
  double DajZ() const {return this->z;}
  std::tuple<double, double, double> DajCentar() const { return std::tuple<double, double, double> (x, y, z);}
  double DajPoluprecnik() const {return this->r;}
  double DajPovrsinu() const {return 4*PI*std::pow(r, 2);}
  double DajZapreminu() const {return 4*PI*std::pow(r, 3)/3;}
  Kugla &PostaviX(double x){
    this->x=x;
    return *this;
  }
  Kugla &PostaviY(double y){
    this->y=y;
    return *this;
  }
  Kugla &PostaviZ(double z){
    this->z=z;
    return *this;
  }
  Kugla &PostaviCentar(double x, double y, double z){
    this->x=x; this->y=y; this->z=z;
    return *this;
  }
  Kugla &PostaviCentar(const std::tuple<double, double, double> &centar){
    x=std::get<0>(centar);
    y=std::get<1>(centar);
    z=std::get<2>(centar);
    return *this;
  }
  Kugla &PostaviPoluprecnik(double r){
    this->r=r;
    return *this;
  }
  
  void Ispisi() const {
      std::cout << "{(" << Kugla::DajX() << "," << Kugla::DajY() << "," << Kugla::DajZ() << ")," << Kugla::DajPoluprecnik() << "}";
  }
  void Translatiraj(double delta_x, double delta_y, double delta_z){
    x+=delta_x; y+=delta_y; z+=delta_z;
  }
  friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
  bool DaLiSadrzi(const Kugla &k) const;
  friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);
};

bool Kugla::DaLiSadrzi(const Kugla &k) const {
  return this->DajPoluprecnik()-k.DajPoluprecnik()-RastojanjeCentara(*this, k)>EP*(this->DajPoluprecnik()+k.DajPoluprecnik()+RastojanjeCentara(*this, k));
}

bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2){
  return (k1.DajCentar()==k2.DajCentar()) && std::fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik())<EP*(k1.DajPoluprecnik()+k2.DajPoluprecnik());
}

bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2){
  return std::fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik())<EP;
}

bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2){
  return k1.DajCentar()==k2.DajCentar();
}

bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2){
  return std::fabs(RastojanjeCentara(k1, k2)-k1.DajPoluprecnik()-k2.DajPoluprecnik())<EP*(RastojanjeCentara(k1, k2)+k1.DajPoluprecnik()+k2.DajPoluprecnik());
}

bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2){
  return std::fabs(RastojanjeCentara(k1, k2)-std::fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik()))<
    EP*(RastojanjeCentara(k1, k2)+std::fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik()));
}

bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2){
  if(DaLiSuKoncentricne(k1, k2) || DaLiSeSijeku(k1, k2) || k1.DaLiSadrzi(k2)) return true;
  return false;
}

bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2){
  if(DaLiSuKoncentricne(k1, k2) || DaLiSeDodirujuIznutra(k1, k2) || DaLiSeDodirujuIzvana(k1, k2)) return false;
  return k1.DajPoluprecnik()+k2.DajPoluprecnik()-RastojanjeCentara(k1, k2)>2*EP*(k1.DajPoluprecnik()+k2.DajPoluprecnik()+RastojanjeCentara(k1, k2)) &&
    RastojanjeCentara(k1, k2)-std::fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik())>2*EP*(RastojanjeCentara(k1, k2)+std::fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik()));
}

double RastojanjeCentara(const Kugla &k1, const Kugla &k2){
  return std::fabs(std::pow(k1.DajX()-k2.DajX(), 2)+std::pow(k1.DajY()-k2.DajY(), 2))+std::pow(k1.DajZ()-k2.DajZ(), 2);
}

int main ()
{
  std::cout << "Unesite broj kugla: ";
  int n;
  while(true){
    if(std::cin >> n && n>0){
      char a=std::cin.peek();
      if(a=='\n' || a==' ' || a=='\t'){
        if(a!='\n') std::cin.ignore(100, '\n');
        break;
      }
    }
    std::cin.clear();
    std::cin.ignore(100, '\n');
    std::cout << "Neispravan broj kugli, unesite ponovo!\n";
  }
  int brojac(0);
  bool dovoljnozavektor(false);
  std::vector<std::shared_ptr<Kugla>> niz_kugli;
  try{
    niz_kugli.resize(n);
    dovoljnozavektor=true;
    for(int i(0); i<n; i++){
      std::cout << "Unesite centar " << i+1 << ". kugle: ";
      double x, y, z;
      if(!(std::cin >> x >> y >> z)){
        std::cin.clear();
        std::cin.ignore(10, '\n');
        std::cout << "Neispravan centar" << std::endl;
        i--;
        continue;
      }
      std::cout << "Unesite poluprecnik " << i+1 << ". kugle: ";
      double r;
      if(!(std::cin >> r) || r<0){
        std::cin.clear();
        std::cin.ignore(10,'\n');
        std::cout << "Ilegalan poluprecnik\n";
        i--;
        continue;
      }
      niz_kugli.at(i)=std::make_shared<Kugla>(Kugla(x, y, z, r));
      brojac++;
    }
    std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double dx, dy, dz;
    while(!(std::cin >> dx >> dy >> dz)){
      std::cin.clear();
      std::cin.ignore(10, '\n');
      std::cout << "Neispravni parametri translacije, unesite ponovo!\n";
    }
    std::transform(niz_kugli.begin(), niz_kugli.end(), niz_kugli.begin(), [dx, dy, dz](std::shared_ptr<Kugla> a){a->Translatiraj(dx, dy, dz); return a;});
    std::sort(niz_kugli.begin(), niz_kugli.end(), [](std::shared_ptr<Kugla> a, std::shared_ptr<Kugla> b){
      return a->DajZapreminu()<b->DajZapreminu();
    });
    std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: \n";
    std::for_each(niz_kugli.begin(), niz_kugli.end(), [](std::shared_ptr<Kugla> a){
      a->Ispisi(); std::cout << std::endl;
    });
    auto najveca_povrsina=std::max_element(niz_kugli.begin(), niz_kugli.end(), [](std::shared_ptr<Kugla> a, std::shared_ptr<Kugla> b){
      return a->DajPovrsinu()<b->DajPovrsinu();
    });
    std::cout << "Kugla sa najvecom povrsinom je: "; (*najveca_povrsina)->Ispisi(); std::cout << std::endl;
    int brojac2(0);
    std::for_each(niz_kugli.begin(), niz_kugli.end(), [&brojac2, niz_kugli](std::shared_ptr<Kugla> &a){
      auto pom=std::find(niz_kugli.begin(), niz_kugli.end(), a);
      pom++;
        std::for_each(pom, niz_kugli.end(), [&brojac2, a](std::shared_ptr<Kugla> b){
          if(DaLiSeSijeku(*a, *b)){
            brojac2++;
            std::cout << "Presjecaju se kugle: "; a->Ispisi(); std::cout << std::endl;
            b->Ispisi(); std::cout << std::endl;
          }
        });
      });
    if(brojac2==0) std::cout << "Ne postoje kugle koje se presjecaju!\n";
  } catch(std::bad_alloc){
    std::cout << "Problemi sa memorijom";
    if(dovoljnozavektor){
      for(int i(0); i<brojac; i++) niz_kugli.at(i)=nullptr;
    }
  }
  return 0;
}
