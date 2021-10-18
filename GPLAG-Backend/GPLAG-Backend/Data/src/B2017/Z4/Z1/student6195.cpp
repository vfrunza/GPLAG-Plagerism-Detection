/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <tuple>
#include <cmath>
#include <stdexcept>
#include <vector>
#include <memory>
#include <new>
#include <iterator>
#include <algorithm>

const double PI(4*std::atan(1));
const double eps(10e-10);

class Kugla {
    double x, y, z, r;
    public:
      explicit Kugla (double r = 0) {
          if(r < 0) throw std::domain_error("Ilegalan poluprecnik");
          else{
              x = 0; y = 0; z = 0;
              Kugla::r = r;
          }
      }
      Kugla (double x, double y, double z, double r = 0) {
          if(r < 0) throw std::domain_error("Ilegalan poluprecnik");
          else{
              Kugla::x = x; Kugla::y = y; Kugla::z = z;
              Kugla::r = r;
          }
      }
      explicit Kugla (const std::tuple<double, double, double> &centar, double r = 0) {
          if(r < 0) throw std::domain_error("Ilegalan poluprecnik");
          else{
              Kugla::x = std::get<0>(centar);
              Kugla::y = std::get<1>(centar);
              Kugla::z = std::get<2>(centar);
              Kugla::r = r;
          }
      }
      double DajX () const { return x; }
      double DajY () const { return y; }
      double DajZ () const { return z; }
      std::tuple<double, double, double> DajCentar () const {
          std::tuple<double, double, double> S;
          S = std::make_tuple(x, y, z);
          return S;
      }
      double DajPoluprecnik () const { return r; }
      double DajPovrsinu () const { return 4*r*r*PI; }
      double DajZapreminu () const { return 4/3.*r*r*r*PI; }
      Kugla &PostaviX (double x) { 
          Kugla::x = x;
          return *this;
      }
      Kugla &PostaviY (double y) {
          Kugla::y = y;
          return *this;
      }
      Kugla &PostaviZ (double z) {
          Kugla::z = z;
          return *this;
      }
      Kugla &PostaviCentar (double x, double y, double z) {
          PostaviX(x); 
          PostaviY(y);
          PostaviZ(z);
          return *this;
      }
      Kugla &PostaviCentar (const std::tuple<double, double, double> &centar) {
          PostaviX(std::get<0>(centar));
          PostaviY(std::get<1>(centar));
          PostaviZ(std::get<2>(centar));
          return *this;
      }
      Kugla &PostaviPoluprecnik (double r) {
          if(r < 0) throw std::domain_error("Ilegalan poluprecnik");
          else{
              Kugla::r = r;
              return *this;
          }
      }
      void Ispisi () const {
          std::cout<<"{("<<DajX()<<","<<DajY()<<","<<DajZ()<<"),"<<DajPoluprecnik()<<"}"<<std::endl;
      }
      void Transliraj (double delta_x, double delta_y, double delta_z);
      friend bool DaLiSuIdenticne (const Kugla &k1, const Kugla &k2);
      friend bool DaLiSuPodudarne (const Kugla &k1, const Kugla &k2);
      friend bool DaLiSuKoncentricne (const Kugla &k1, const Kugla &k2);
      friend bool DaLiSeDodirujuIzvana (const Kugla &k1, const Kugla &k2);
      friend bool DaLiSeDodirujuIznutra (const Kugla &k1, const Kugla &k2);
      friend bool DaLiSePreklapaju (const Kugla &k1, const Kugla &k2);
      friend bool DaLiSeSijeku (const Kugla &k1, const Kugla &k2);
      bool DaLiSadrzi (const Kugla &k) const {
          if(RastojanjeCentara(k, *this) > std::fabs(k.r - this->r)) return false;
          return true;
      }
      friend double RastojanjeCentara (const Kugla &k1, const Kugla &k2);
};

bool DaLiSuIdenticne (const Kugla &k1, const Kugla &k2) {
    if((std::fabs(k1.x - k2.x) < eps*(std::fabs(k1.x) + std::fabs(k2.x))) && (std::fabs(k1.y - k2.y) < eps*(std::fabs(k1.y) + std::fabs(k2.y))) && (std::fabs(k1.z - k2.z) < eps*(std::fabs(k1.z) + std::fabs(k2.z))) && (std::fabs(k1.r - k2.r) < eps*(std::fabs(k1.r) + std::fabs(k2.r)))) return true;
    return false;
}

bool DaLiSuPodudarne (const Kugla &k1, const Kugla &k2) {
    if((std::fabs(k1.r- k2.r) < eps*(std::fabs(k1.r) + std::fabs(k2.r)))) return true;
    return false;
}

bool DaLiSuKoncentricne (const Kugla &k1, const Kugla &k2) {
    if((std::fabs(k1.x - k2.x) > eps*(std::fabs(k1.x) + std::fabs(k2.x))) || (std::fabs(k1.y - k2.y) > eps*(std::fabs(k1.y) + std::fabs(k2.y))) || (std::fabs(k1.z - k2.z) > eps*(std::fabs(k1.z) + std::fabs(k2.z)))) return false;
    return true;
}

double RastojanjeCentara (const Kugla &k1, const Kugla &k2) {
    return std::sqrt((k1.x - k2.x)*(k1.x - k2.x) + (k1.y - k2.y)*(k1.y - k2.y) + (k1.z - k2.z)*(k1.z - k2.z));
}

bool DaLiSeDodirujuIzvana (const Kugla &k1, const Kugla &k2) {
    if(RastojanjeCentara(k1, k2) - (k1.r + k2.r) < eps) return true;
    return false;
}

bool DaLiSeDodirujuIznutra (const Kugla &k1, const Kugla &k2) {
    if(RastojanjeCentara(k1, k2) - std::fabs(k1.r - k2.r) > eps) return false;
    return true;
}

bool DaLiSePreklapaju (const Kugla &k1, const Kugla &k2) {
    if(DaLiSeSijeku(k1, k2) || RastojanjeCentara(k1, k2) < std::fabs(k1.r - k2.r)) return true;
    return false;
}

bool DaLiSeSijeku (const Kugla &k1, const Kugla &k2) {
    if(RastojanjeCentara(k1, k2) < (k1.r + k2.r) && RastojanjeCentara(k1, k2) > std::fabs(k1.r-k2.r)) return true;
    return false;
}

void Kugla::Transliraj (double delta_x, double delta_y, double delta_z) {
    Kugla::x = Kugla::x + delta_x;
    Kugla::y = Kugla::y + delta_y;
    Kugla::z = Kugla::z + delta_z;
}

int main ()
{
    int broj_kugli;
    std::cout<<"Unesite broj kugla: ";
    do{
        std::cin>>broj_kugli;
        if(!std::cin || broj_kugli < 1) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;
        }
    }while(!std::cin || broj_kugli < 1);
    std::vector<std::shared_ptr<Kugla>> vektor_pametnih_p (broj_kugli);
    for(int i = 0; i < broj_kugli; i++) {
        double xi, yi, zi, rr;    
        bool ispravno = true;
        do{
            ispravno = true;
            std::cout<<"Unesite centar "<<i+1<<". kugle: ";
            std::cin>>xi>>yi>>zi;
            if(!std::cin) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout<<"Neispravan centar"<<std::endl;
                ispravno = false;
            }
            if(ispravno) {
                std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
                std::cin>>rr;
                if(!std::cin) {
                    ispravno = false;
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    std::cout<<"Ilegalan poluprecnik"<<std::endl;
                }
                else if(rr < 0) {
                    std::cout<<"Ilegalan poluprecnik"<<std::endl;
                    ispravno = false;
                }
            }
        }while(ispravno == false);
        vektor_pametnih_p.at(i) = std::make_shared<Kugla>(xi, yi, zi, rr);
    }
    double delta_x, delta_y, delta_z;
    std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    do{
        std::cin>>delta_x>>delta_y>>delta_z;
        if(!std::cin) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout<<"Neispravni parametri translacije, unesite ponovo!"<<std::endl;
        }else break;
    }while(1);
    std::transform(vektor_pametnih_p.begin(), vektor_pametnih_p.end(), vektor_pametnih_p.begin(), [delta_x, delta_y, delta_z] (std::shared_ptr<Kugla>pokazivac) {
        pokazivac -> Transliraj(delta_x, delta_y, delta_z);
        return pokazivac;
    });
    std::sort(vektor_pametnih_p.begin(), vektor_pametnih_p.end(), [](std::shared_ptr<Kugla>pokazivac1, std::shared_ptr<Kugla>pokazivac2) {
        return pokazivac1->DajZapreminu() < pokazivac2->DajZapreminu();
    });
    std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<std::endl;
    std::for_each(vektor_pametnih_p.begin(), vektor_pametnih_p.end(), [](std::shared_ptr<Kugla> pokazivac) {pokazivac->Ispisi();});
    std::cout<<"Kugla sa najvecom povrsinom je: ";
    auto ispisni_p(std::max_element(vektor_pametnih_p.begin(), vektor_pametnih_p.end(), [](std::shared_ptr<Kugla>pokazivac1, std::shared_ptr<Kugla>pokazivac2) {
        return pokazivac1->DajPovrsinu() < pokazivac2->DajPovrsinu();    
    }));
    (*ispisni_p)->Ispisi();
    int pomjeri = 0, ispisanih = 0;
    std::for_each(vektor_pametnih_p.begin(), vektor_pametnih_p.end(), [&pomjeri, &vektor_pametnih_p, &ispisanih](std::shared_ptr<Kugla>pokazivac1) {
        pomjeri++;
        std::for_each(vektor_pametnih_p.begin()+pomjeri, vektor_pametnih_p.end(), [&pokazivac1, &ispisanih](std::shared_ptr<Kugla>pokazivac2) {
            if(DaLiSeSijeku(*pokazivac1, *pokazivac2)) {
                ispisanih++;
                std::cout<<"Presjecaju se kugle: ";
                pokazivac1->Ispisi();
                pokazivac2->Ispisi();
        }});
    });
    if(ispisanih == 0) std::cout<<"Ne postoje kugle koje se presjecaju!"<<std::endl;
	return 0;
}
