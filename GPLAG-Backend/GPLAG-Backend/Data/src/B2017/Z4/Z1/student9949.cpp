/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>

const double PI(4*atan(1));
const double e(1e-10);

class Kugla
{
private:
  double x,y,z,r;
public:
  explicit Kugla(double r1=0) {
    if(r1<0) throw std::domain_error("Ilegalan poluprecnik");
    x=0;
    y=0;
    z=0;
    r=r1;
  }
  Kugla(double x1, double y1, double z1, double r1=0) {
    if(r1<0) throw std::domain_error("Ilegalan poluprecnik");
    r=r1;
    x=x1;
    y=y1;
    z=z1;
  }
  explicit Kugla(const std::tuple<double,double,double> &centar, double r1=0) {
    if(r1<0) throw std::domain_error("Ilegalan poluprecnik");
    r=r1;
    x=std::get<0>(centar);
    y=std::get<1>(centar);
    z=std::get<2>(centar);
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
  std::tuple<double,double,double> DajCentar() const {
    return std::make_tuple(x,y,z);
  }
  double DajPoluprecnik() const {
    return r;
  }
  double DajPovrsinu() const {
    return 4*PI*r*r;
  }
  double DajZapreminu() const {
    return (4/3.)*r*r*r*PI;
  }
  Kugla &PostaviX(double X) {
    x=X;
    return *this;
  }
  Kugla &PostaviY(double Y) {
    y=Y;
    return *this;
  }
  Kugla &PostaviZ(double Z) {
    z=Z;
    return *this;
  }
  Kugla &PostaviCentar(double x1, double y1, double z1) {
    x=x1;
    y=y1;
    z=z1;
    return *this;
  }
  Kugla &PostaviCentar(const std::tuple<double, double, double> &centar) {
    x=std::get<0>(centar);
    y=std::get<1>(centar);
    z=std::get<2>(centar);
    return *this;
  }
  Kugla &PostaviPoluprecnik(double r1) {
    if(r1<0) throw std::domain_error("Ilegalan poluprecnik");
    r=r1;
    return *this;
  }
  void Ispisi() const {
    std::cout << "{(" << DajX() << "," << DajY() << "," << DajZ() << ")," << DajPoluprecnik() << "}";
  }
  void Transliraj(double delta_x, double delta_y, double delta_z) {
    x=x+delta_x;
    y=y+delta_y;
    z=z+delta_z;
  }
  friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
  bool DaLiSadrzi(const Kugla &K) const {
    if(std::sqrt((K.DajX()-x)*(K.DajX()-x)+(K.DajY()-y)*(K.DajY()-y)+(K.DajZ()-z)*(K.DajZ()-z))<(r-K.DajPoluprecnik())) return true;
    return false;
  }
  friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);
};

bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2)
{
  if(fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik())<=e*(fabs(k1.DajPoluprecnik())+fabs(k2.DajPoluprecnik())) &&
      fabs(k1.DajX()-k2.DajX())<=e*(fabs(k1.DajX())+fabs(k2.DajX())) &&
      fabs(k1.DajY()-k2.DajY())<=e*(fabs(k1.DajY())+fabs(k2.DajY())) &&
      fabs(k1.DajZ()-k2.DajZ())<=e*(fabs(k1.DajZ())+fabs(k2.DajZ()))) return true;
  return false;
}

bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2)
{
  if(fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik())<=e*(fabs(k1.DajPoluprecnik())+fabs(k2.DajPoluprecnik()))) return true;
  return false;
}

bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2)
{
  if(fabs(k1.DajX()-k2.DajX())<=e*(fabs(k1.DajX())+fabs(k2.DajX())) &&
      fabs(k1.DajY()-k2.DajY())<=e*(fabs(k1.DajY())+fabs(k2.DajY()))&&
      fabs(k1.DajZ()-k2.DajZ())<=e*(fabs(k1.DajZ())+fabs(k2.DajZ()))) return true;
  return false;
}

bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2)
{
  if(fabs(RastojanjeCentara(k1,k2))<(k1.DajPoluprecnik()+k2.DajPoluprecnik()) &&
      fabs(RastojanjeCentara(k1,k2))>fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik())) return true;
  return false;
}

bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2)
{
  if(fabs(RastojanjeCentara(k1,k2)-fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik()))<=e*(fabs(RastojanjeCentara(k1,k2))+fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik()))) return true;
  return false;
}

bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2)
{
  if(fabs(RastojanjeCentara(k1,k2)-(k1.DajPoluprecnik()+k2.DajPoluprecnik()))<=e*(fabs(RastojanjeCentara(k1,k2))+fabs(k1.DajPoluprecnik()+k2.DajPoluprecnik()))) return true;
  return false;
}

double RastojanjeCentara(const Kugla &k1, const Kugla &k2)
{
  return std::sqrt((k1.DajX()-k2.DajX())*(k1.DajX()-k2.DajX())+(k1.DajY()-k2.DajY())*(k1.DajY()-k2.DajY())+(k1.DajZ()-k2.DajZ())*(k1.DajZ()-k2.DajZ()));
}

bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2)
{
  if(RastojanjeCentara(k1,k2)<k1.DajPoluprecnik()+k2.DajPoluprecnik() || DaLiSeSijeku(k1,k2)) return true;
  return false;
}
int main ()
{
  try {
    int n(0);
    std::cout << "Unesite broj kugla: ";
    for(;;) {
      try {
        std::cin >> n;
        if(n>0) break;
        if(std::cin.peek()!='\n') throw std::domain_error("Neispravan broj kugli, unesite ponovo!");
        if(n<=0) throw std::domain_error ("Neispravan broj kugli, unesite ponovo!");
      } catch(std::domain_error izuzetak) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << izuzetak.what() << std::endl;
      }
    }
    std::vector<std::shared_ptr<Kugla>> VektorKugli(n);
    double x,y,z,r;
    for(int i=0; i<n; i++) {
      try {
        std::cout << "Unesite centar " << i+1 <<". kugle: ";
        std::cin >> x >> y >> z;
        if(std::cin.peek()!='\n') {
          std::cin.ignore(1000,'\n');
          throw std::domain_error("Neispravan centar");
        }
        std::cout << "Unesite poluprecnik " << i+1 << ". kugle: ";
        std::cin >> r;
        if(!std::cin || r<0) {
          throw std::domain_error("Ilegalan poluprecnik");
        }
        std::shared_ptr<Kugla> p(std::make_shared<Kugla>(Kugla(x,y,z,r)));
        VektorKugli[i]=p;
        p=nullptr;
      } catch(std::domain_error izuzetak) {
        std::cin.clear();
        std::cin.ignore(1000,'\n');
        std::cout << izuzetak.what() << std::endl;
        i--;
      }
    }
    std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double dx, dy, dz;
    for(;;) {
      std::cin >> dx >> dy >> dz;
      if(!std::cin || (dx<0 || dy<0 || dz<0)) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Neispravni parametri translacije, unesite ponovo!" << std::endl;
      } else break;
    }
    std::transform(VektorKugli.begin(),VektorKugli.end(),VektorKugli.begin(),[=](const std::shared_ptr<Kugla> &k) {
      k->Transliraj(dx,dy,dz);
      return k;
    });
    std::sort(VektorKugli.begin(),VektorKugli.end(),[](const std::shared_ptr<Kugla> &k1, const std::shared_ptr<Kugla> &k2) {
      return k1->DajZapreminu()<k2->DajZapreminu();
    });
    std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: " << std::endl;
    std::for_each(VektorKugli.begin(),VektorKugli.end(),[](const std::shared_ptr<Kugla> &k) {
      k->Ispisi();
      std::cout << std::endl;
    });
    auto pom=std::max_element(VektorKugli.begin(),VektorKugli.end(),[](const std::shared_ptr<Kugla> &k1, const std::shared_ptr<Kugla> &k2) {
      return k1->DajPovrsinu()<k2->DajPovrsinu();
    });
    std::cout << "Kugla sa najvecom povrsinom je: ";
    (*pom)->Ispisi();

    std::vector<std::pair<Kugla,Kugla>> PresjecneKugle;
    if(VektorKugli.size()>=2) {
      std::for_each(VektorKugli.begin(),VektorKugli.end(),[VektorKugli, &PresjecneKugle](const std::shared_ptr<Kugla> &k1)->void {
        std::for_each(VektorKugli.begin(), VektorKugli.end(),[VektorKugli, &PresjecneKugle, k1](const std::shared_ptr<Kugla> &k2) {
          if(DaLiSeSijeku(*k1,*k2)) {
            std::pair<Kugla,Kugla> Par;
            Par=std::make_pair(*k1,*k2);
            PresjecneKugle.push_back(Par);
          }
        });
      });
    } else {
      std::cout << std::endl << "Ne postoje kugle koje se presjecaju!";
      return 0;
    }
    std::cout << std::endl;
    if(PresjecneKugle.size()==0) {
      std::cout << "Ne postoje kugle koje se presjecaju!";
    } else {
      for(int i=0; i<PresjecneKugle.size(); i++) {
        for(int j=i+1; j<PresjecneKugle.size(); j++) {
          if(fabs(PresjecneKugle[i].first.DajPoluprecnik()-PresjecneKugle[j].second.DajPoluprecnik())<=e*(fabs(PresjecneKugle[i].first.DajPoluprecnik())+fabs(PresjecneKugle[j].second.DajPoluprecnik())) &&
              fabs(PresjecneKugle[j].first.DajPoluprecnik()-PresjecneKugle[i].second.DajPoluprecnik())<=e*(fabs(PresjecneKugle[j].first.DajPoluprecnik())+fabs(PresjecneKugle[i].second.DajPoluprecnik())) &&
              fabs(PresjecneKugle[i].first.DajX()-PresjecneKugle[j].second.DajX())<=e*(fabs(PresjecneKugle[i].first.DajX())+fabs(PresjecneKugle[j].second.DajX())) &&
              fabs(PresjecneKugle[j].first.DajX()-PresjecneKugle[i].second.DajX())<=e*(fabs(PresjecneKugle[j].first.DajX())+fabs(PresjecneKugle[i].second.DajX())) &&
              fabs(PresjecneKugle[i].first.DajY()-PresjecneKugle[j].second.DajY())<=e*(fabs(PresjecneKugle[i].first.DajY())+fabs(PresjecneKugle[j].second.DajY())) &&
              fabs(PresjecneKugle[j].first.DajY()-PresjecneKugle[i].second.DajY())<=e*(fabs(PresjecneKugle[j].first.DajY())+fabs(PresjecneKugle[i].second.DajY())) &&
              fabs(PresjecneKugle[i].first.DajZ()-PresjecneKugle[j].second.DajZ())<=e*(fabs(PresjecneKugle[i].first.DajZ())+fabs(PresjecneKugle[j].second.DajZ())) &&
              fabs(PresjecneKugle[j].first.DajZ()-PresjecneKugle[i].second.DajZ())<=e*(fabs(PresjecneKugle[j].first.DajZ())+fabs(PresjecneKugle[i].second.DajZ()))) {
            PresjecneKugle.erase(PresjecneKugle.begin()+j);
            j--;
          }
        }
      }
      std::for_each(PresjecneKugle.begin(),PresjecneKugle.end(),[](const std::pair<Kugla,Kugla> &K) {
        std::cout << "Presjecaju se kugle: ";
        K.first.Ispisi();
        std::cout << std::endl;
        K.second.Ispisi();
        std::cout << std::endl;
      });
    }
  } catch(...) {
  }
  return 0;
}
