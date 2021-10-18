/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <cmath>
#include <tuple>
#include <stdexcept>
#include <algorithm>
#include <memory>
#include <vector>

class Kugla {
      private: 
      double x, y, z; 
      double r; 
      const long double EPSILON=10e-10; //razmisli
      void TestPoluprecnika(double poluprecnik)  { if(poluprecnik<0) throw std::domain_error("Ilegalan poluprecnik"); } 
      static bool TestJednakosti(double a, double b) { return std::abs(a-b)<(10e-10)*(std::abs(a)+std::abs(b)); }
      static double mini(double r1, double r2) { if(r1<r2) return r1; return r2; }
      static double maxi(double r1, double r2) { if(r1>r2) return r1; return r2; }
      const double PI=atan(1)*4; //razmisli
      public: 
      explicit Kugla(double r=0) { PostaviPoluprecnik(r); PostaviCentar(0,0,0); }
      Kugla(double x, double y, double z, double r=0) { PostaviPoluprecnik(r); PostaviCentar(x,y,z); }
      explicit Kugla(const std::tuple<double, double, double> &centar, double r=0) { PostaviPoluprecnik(r); Kugla::PostaviCentar(centar); }
      double DajX() const { return x; }
      double DajY() const { return y; }
      double DajZ() const { return z; }
      std::tuple<double, double, double> DajCentar() const { return std::tie(x,y,z); }
      double DajPoluprecnik() const { return r; }
      double DajPovrsinu() const { return PI*4*DajPoluprecnik()*DajPoluprecnik(); }
      double DajZapreminu() const { return (DajPovrsinu()*DajPoluprecnik())/3; }
      Kugla &PostaviX(double x) { this->x=x; return *this; }
      Kugla &PostaviY(double y) { this->y=y; return *this;}
      Kugla &PostaviZ(double z) { this->z=z; return *this; }
      Kugla &PostaviCentar(double x, double y, double z) { PostaviX(x); PostaviY(y); PostaviZ(z); return *this;} 
      Kugla &PostaviCentar(const std::tuple<double, double, double> &centar) { PostaviCentar(std::get<0>(centar), std::get<1>(centar), std::get<2>(centar)); return *this;}
      Kugla &PostaviPoluprecnik(double r) { TestPoluprecnika(r); this->r=r; return *this;}
      void Ispisi() const { std::cout << "{(" << DajX() << "," << DajY() << "," << DajZ() << ")," << DajPoluprecnik() << "}" << std::endl;  }
      void Translatiraj(double delta_x, double delta_y, double delta_z) { PostaviX(x+delta_x); PostaviY(y+delta_y); PostaviZ(z+delta_z); } 
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

bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2) { return Kugla::TestJednakosti(k1.DajPoluprecnik(), k2.DajPoluprecnik()); }
bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2) { if(Kugla::TestJednakosti(k1.DajX(), k2.DajX()) && Kugla::TestJednakosti(k1.DajY(), k2.DajY()) && Kugla::TestJednakosti(k1.DajZ(), k2.DajZ())) return true; return false; }
bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2) { if(DaLiSuKoncentricne(k1, k2) && DaLiSuPodudarne(k1, k2)) return true; return false; }

bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2) {
      double veciprecnik(Kugla::maxi(k1.DajPoluprecnik(),k2.DajPoluprecnik()));
      double manjiprecnik(Kugla::mini(k1.DajPoluprecnik(), k2.DajPoluprecnik()));
      return Kugla::TestJednakosti(manjiprecnik+RastojanjeCentara(k1,k2), veciprecnik); 
}

bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2) { return Kugla::TestJednakosti(RastojanjeCentara(k1,k2), k1.DajPoluprecnik()+k2.DajPoluprecnik()); }
bool Kugla::DaLiSadrzi(const Kugla &k1) const { //da li se preklapaju i ako se dodiruju or?
      double veciprecnik(Kugla::maxi(k1.DajPoluprecnik(), this->r)); 
      double manjiprecnik(Kugla::mini(k1.DajPoluprecnik(), this->r));
      return manjiprecnik+RastojanjeCentara(k1,*this)<veciprecnik; //vidi ovdje ovo manje ili jednako da li test jednakosti or what
}
bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2) {
      return k1.DajPoluprecnik()+k2.DajPoluprecnik()<RastojanjeCentara(k1, k2); 
}
double RastojanjeCentara(const Kugla &k1, const Kugla &k2) { return std::sqrt((k2.DajX()-k1.DajX())*(k2.DajX()-k1.DajX())+(k2.DajY()-k1.DajY())*(k2.DajY()-k1.DajY())+(k2.DajZ()-k1.DajZ())*(k2.DajZ()-k1.DajZ())); }

bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2) {
      //opet da li je sjeci se i dodirivati isto vidi nekako ako jeste dodaj ona 2 uvijeta i eto
      //ovo ispod daj boze da je ovako kako si ti navela ali eto hajde treba mastati
      if((k1.DajPoluprecnik()+k2.DajPoluprecnik()>RastojanjeCentara(k1,k2)) && RastojanjeCentara(k1,k2)>Kugla::maxi(k1.r, k2.r)-Kugla::mini(k1.r, k2.r))return true;
      return false;

      
}

int main ()
{
      double n; 
     std::cout << "Unesite broj kugla: "; 
     while(1) {
           std::cin >> n; 
           if(std::cin) {if(n>0 && n-(int)n==0) break; }
           std::cin.clear();
           std::cout << "Neispravan broj kugli, unesite ponovo!" << std::endl;
           
           std::cin.ignore(1000, '\n');
     } 
      
      std::vector<std::shared_ptr<Kugla>> vektor_pok_na_klasu(n);
      for(int i=0; i<n; i++) {
            
      std::cout << "Unesite centar " << i+1 << ". kugle: ";
      double koordinatax, koordinatay, koordinataz; 
      while(1) {
      std::cin >> koordinatax >> koordinatay >> koordinataz;
      if(std::cin) break;
      std::cin.clear(); std::cin.ignore(1000, '\n'); 
      std::cout << "Neispravan centar\n"; std::cout << "Unesite centar " << i+1 << ". kugle: ";  }
      std::cout << "Unesite poluprecnik " << i+1 << ". kugle: "; 
      double pp; 
      while(!(std::cin >> pp) || pp<0) {
            std::cin.clear(); std::cin.ignore(1000,'\n');
            std::cout << "Ilegalan poluprecnik\n"; 
            std::cout << "Unesite centar " << i+1 << ". kugle: "; 
            while(!(std::cin >> koordinatax >> koordinatay >> koordinataz)) {
                  std::cin.clear(); std::cin.ignore(1000,'\n'); 
                  std::cout << "Neispravan centar\n"; std::cout << "Unesite centar " << i+1 << ". kugle: "; 
            }
            std::cout << "Unesite poluprecnik " << i+1 << ". kugle: "; 
      }
      
      vektor_pok_na_klasu[i]=std::make_shared<Kugla>(koordinatax, koordinatay, koordinataz, pp);            
      }
      
      std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
      double dx, dy, dz; 
      //uradi provjeru
      
      while(!(std::cin >> dx >> dy >> dz)) {
            std::cin.clear(); std::cin.ignore(1000, '\n');
            std::cout << "Neispravni parametri translacije, unesite ponovo!\n"; 
      } 
      std::transform(vektor_pok_na_klasu.begin(), vektor_pok_na_klasu.end(), vektor_pok_na_klasu.begin(), [dx,dy,dz](std::shared_ptr<Kugla> k){ (*k).Translatiraj(dx,dy,dz);  return k; }); 
      std::sort(vektor_pok_na_klasu.begin(), vektor_pok_na_klasu.end(), [](std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2) { return (*k1).DajZapreminu()<(*k2).DajZapreminu(); });  
      std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: " << std::endl;
      std::for_each(vektor_pok_na_klasu.begin(), vektor_pok_na_klasu.end(), [](std::shared_ptr<Kugla> k) {(*k).Ispisi(); });
      std::cout << "Kugla sa najvecom povrsinom je: "; 
      auto nesto=std::max_element(vektor_pok_na_klasu.begin(), vektor_pok_na_klasu.end(), [](std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2) {return (*k1).DajPovrsinu()<(*k2).DajPovrsinu(); }); 
      (*nesto)->Ispisi();
      int na=0;
      bool barjednasepresjeka(false); 
      std::for_each(vektor_pok_na_klasu.begin(), vektor_pok_na_klasu.end(), [&na, &barjednasepresjeka,vektor_pok_na_klasu](std::shared_ptr<Kugla> k)
      {na++; std::for_each(vektor_pok_na_klasu.begin()+na, vektor_pok_na_klasu.end(), [k, &barjednasepresjeka](std::shared_ptr<Kugla> k2)
      { if(DaLiSeSijeku(*k, *k2)) {barjednasepresjeka=true; std::cout << "Presjecaju se kugle: ";(*k).Ispisi(); std::cout << std::endl; (*k2). Ispisi();   } }); });
	if(!barjednasepresjeka) std::cout << "Ne postoje kugle koje se presjecaju!";
	return 0;
}
//ispravi u ispisi da ide samo u novi red ili vidi s nekim kako su oni u toj postupili, provjeri rade li ti ostale funkcije i provjeri nazive funkcija