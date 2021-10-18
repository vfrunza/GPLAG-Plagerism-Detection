/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <tuple>
#include <cmath>
#include <stdexcept>
#include <vector>
#include <memory>
#include <algorithm>

class Kugla
{
     double x, y, z, r;
     const double PI = 4 * std::atan(1);
     static bool Jednaki(double x, double y, double epsilon = 10e-10) {
          if(std::fabs(x - y) <= epsilon * (std::fabs(x) + std::fabs(y))) return true;
          return false;
     }
public:
     explicit Kugla(double r = 0) {
          if(r < 0) throw std::domain_error("Ilegalan poluprecnik");
          Kugla::r = r;
          Kugla::x = 0;
          Kugla::y = 0;
          Kugla::z = 0;
     }
     Kugla(double x, double y, double z, double r = 0) {
          if(r < 0) throw std::domain_error("Ilegalan poluprecnik");
          Kugla::r = r;
          Kugla::x = x;
          Kugla::y = y;
          Kugla::z = z;
     }
     explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0) {
          if(r < 0) throw std::domain_error("Ilegalan poluprecnik");
          x = std::get<0>(centar);
          y = std::get<1>(centar);
          z = std::get<2>(centar);
          Kugla::r = r;
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
          return std::make_tuple(x, y, z);
     }
     double DajPoluprecnik() const {
          return r;
     }
     double DajPovrsinu() const {
          return 4 * r * r * PI;
     }
     double DajZapreminu() const {
          return r * r * r * PI * 4./3.;
     }
     Kugla &PostaviX(double x) {
          Kugla::x = x;
          return *this;
     }
     Kugla &PostaviY(double y) {
          Kugla::y = y;
          return *this;
     }
     Kugla &PostaviZ(double z) {
          Kugla::z = z;
          return *this;
     }
     Kugla &PostaviCentar(double x, double y, double z) {
          Kugla::x = x;
          Kugla::y = y;
          Kugla::z = z;
          return *this;
     }
     Kugla &PostaviCentar(const std::tuple<double, double, double> &centar) {
          x = std::get<0>(centar);
          y = std::get<1>(centar);
          z = std::get<2>(centar);
          return *this;
     }
     Kugla &PostaviPoluprecnik(double r) {
          if(r < 0) throw std::domain_error("Ilegalan poluprecnik");
          Kugla::r = r;
     }
     void Ispisi() const {
          std::cout<< "{(" << DajX() << "," << DajY() << "," << DajZ() << ")," << DajPoluprecnik() << "}" << std::endl;
     }
     void Transliraj(double delta_x, double delta_y, double delta_z) {
          x += delta_x;
          y += delta_y;
          z += delta_z;
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

bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2)
{
     if(Kugla::Jednaki(k1.DajX(), k2.DajX()) && Kugla::Jednaki(k1.DajY(), k2.DajY()) &&
     Kugla::Jednaki(k1.DajZ(), k2.DajZ()) && Kugla::Jednaki(k1.DajPoluprecnik(), k2.DajPoluprecnik())) return true;
     return false;
}
bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2)
{
     if(Kugla::Jednaki(k1.DajPoluprecnik(), k2.DajPoluprecnik())) return true;
     return false;
}
bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2)
{
     if(Kugla::Jednaki(k1.DajX(), k2.DajX()) && Kugla::Jednaki(k1.DajY(), k2.DajY()) && Kugla::Jednaki(k1.DajZ(), k2.DajZ())) return true;
     return false;
}
bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2)
{
     if(Kugla::Jednaki(RastojanjeCentara(k1, k2), k1.DajPoluprecnik() + k2.DajPoluprecnik())) return true;
     return false;
}
bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2)
{
     if(Kugla::Jednaki(RastojanjeCentara(k1, k2), std::fabs(k1.DajPoluprecnik() - k2.DajPoluprecnik()))) return true;
     return false;
}
bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2)
{
     if(DaLiSeDodirujuIznutra(k1, k2) || DaLiSeSijeku(k1, k2) || DaLiSuIdenticne(k1, k2) || DaLiSuKoncentricne(k1, k2) ||
     k1.DaLiSadrzi(k2) || k2.DaLiSadrzi(k1)) return true;
     return false;
}
bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2)
{
     if(RastojanjeCentara(k1, k2) < k1.DajPoluprecnik() + k2.DajPoluprecnik() &&
     DaLiSeDodirujuIznutra(k1, k2) == false && k1.DaLiSadrzi(k2) == false && k2.DaLiSadrzi(k1) == false &&
     DaLiSuIdenticne(k1, k2) == false && DaLiSuKoncentricne(k1, k2) == false)
          return true;
     return false;
}
bool Kugla::DaLiSadrzi(const Kugla &k) const
{
     if(DajPoluprecnik() > k.DajPoluprecnik()) {
          if(DaLiSuKoncentricne(*this, k)) return true;
     }
     if(DaLiSeDodirujuIznutra(*this, k) || DaLiSuIdenticne(*this, k)) return true;
     double veci, manji;
     if(DajPoluprecnik() > k.DajPoluprecnik()) {
          veci = DajPoluprecnik();
          manji = k.DajPoluprecnik();
     } else {
          veci = k.DajPoluprecnik();
          manji = DajPoluprecnik();
     }
     if(RastojanjeCentara(*this, k) + manji < veci) return true;
     return false;
}
double RastojanjeCentara(const Kugla &k1, const Kugla &k2)
{
     return std::sqrt((k1.DajX() - k2.DajX()) * (k1.DajX() - k2.DajX()) +
     (k1.DajY() - k2.DajY()) * (k1.DajY() - k2.DajY()) +
     (k1.DajZ() - k2.DajZ()) * (k1.DajZ() - k2.DajZ()));
}

int main ()
{
     int a;
     std::cout << "Unesite broj kugla: ";
     for(; ;) {
          std::cin >> a;
          if(!std::cin || a <= 0) {
               std::cout<< "Neispravan broj kugli, unesite ponovo!" << std::endl;
               std::cin.clear();
               std::cin.ignore(10000, '\n');
               continue;
          } break;
     }
     std::vector<std::shared_ptr<Kugla>> vektor(a);
     double x, y, z, r;
     int pomocna(0);
     for(int i(0); i<a; i++) {
          for(; ;) {
               pomocna++;
               std::cout<<"Unesite centar " << pomocna <<". kugle: ";
               std::cin>> x >> y >> z;
               if(!std::cin) {
                    std::cout<< "Neispravan centar" << std::endl;;
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    pomocna--;
                    continue;
               }
               std::cout<< "Unesite poluprecnik " << pomocna << ". kugle: ";
               std::cin>> r;
               if(!std::cin || r < 0) {
                    std::cout << "Ilegalan poluprecnik" <<std::endl;
                    pomocna--;
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    continue;
               }
               break;
          }
          vektor.at(i) = std::make_shared<Kugla> (x,y,z,r);
     }
     double delta_x, delta_y, delta_z;
     std::cout<< "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
     for(; ;) {
          std::cin>> delta_x >> delta_y >> delta_z;
          if(!std::cin) {
               std::cout<< "Neispravni parametri translacije, unesite ponovo!" << std::endl;
               std::cin.clear();
               std::cin.ignore(10000, '\n');
               continue;
          } break;
     }
     std::transform(vektor.begin(), vektor.end(), vektor.begin(), [delta_x, delta_y, delta_z](std::shared_ptr<Kugla> k) {
          k-> Transliraj(delta_x, delta_y, delta_z);
          return k;
     });
     std::sort(vektor.begin(), vektor.end(), [] (std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2) {
          if(k1->DajZapreminu() < k2->DajZapreminu()) return true;
          return false;
     });
     std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: " << std::endl;
     std::for_each(vektor.begin(), vektor.end(), [] (std::shared_ptr<Kugla> k) {
          k-> Ispisi();
     });
     std::cout<<std::endl << "Kugla sa najvecom povrsinom je: ";
     auto iter = std::max_element(vektor.begin(), vektor.end(), [] (std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2) {
          if(k1-> DajPovrsinu() < k2->DajPovrsinu()) return true;
          return false;
     });
     (*iter)->Ispisi();
     int indeks(0);
     bool bio(false);
     std::for_each(vektor.begin(), vektor.end(), [&bio, &indeks, vektor] (std::shared_ptr<Kugla> k1) {
          indeks++;
          std::for_each(vektor.begin()+indeks, vektor.end(), [&bio, k1] (std::shared_ptr<Kugla> k2) {
               if(DaLiSeSijeku(*k1, *k2)) {
                    bio = true;
                    std::cout<<std::endl<< "Presjecaju se kugle: ";
                    k1->Ispisi();
                    k2->Ispisi();
               }

          });
     });
     if(bio == false)
          std::cout<<std::endl<< "Ne postoje kugle koje se presjecaju!";
     return 0;
}