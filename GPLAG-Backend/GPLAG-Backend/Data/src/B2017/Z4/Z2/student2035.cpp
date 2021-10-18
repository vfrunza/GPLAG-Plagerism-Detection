/B2017/2018: Zadaća 4, Zadatak 2
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <cmath>
#include <memory>
#include <tuple>
#include <stdexcept>

class NepreklapajucaKugla {
      private: 
      static constexpr double PI=atan(1)*4;
      double x,y,z,r; 
      NepreklapajucaKugla *ona_prije_mene; 
      static NepreklapajucaKugla *pok_na_zadnju;
      static int kolikoihjekreirano;

      void TestPreklapanja(double x, double y, double z, double r) {
            NepreklapajucaKugla *pokazivac(pok_na_zadnju);
            while(pokazivac!=nullptr) { 
                  if(r+pokazivac->r >= std::sqrt((x-pokazivac->x)*(x-pokazivac->x)+(y-pokazivac->y)*(y-pokazivac->y)+(z-pokazivac->z)*(z-pokazivac->z))) throw std::logic_error("Nedozvoljeno preklapanje"); 
              //    else std::cout << "prosao sam provjeru_ \n";                  
                  pokazivac=pokazivac->ona_prije_mene;
            }
      }
      
      void Postavi(double x, double y, double z, double r) {
            if(kolikoihjekreirano==0) { pok_na_zadnju=nullptr; /*pok_na_zadnju=this; kolikoihjekreirano++; TestPreklapanja(x,y,z,r); */}
            else {
                  TestPreklapanja(x,y,z,r);
             //     ona_prije_mene=pok_na_zadnju;
               /*   pok_na_zadnju=this;*/
              //    kolikoihjekreirano++;
            }
            this->x=x; this->y=y; this->z=z; this->r=r;
            ona_prije_mene=pok_na_zadnju;
            pok_na_zadnju=this;
          //  if(kolikoihjekreirano!=1) TestPreklapanja(); }
      }
      void Promijeni(double x, double y, double z, double r) {
            TestPreklapanja(x,y,z,r);
            this->x=x; this->y=y; this->z=z; this->r=r; 
           // TestPreklapanja();  }
      }
      void TestPoluprecnika(double r) { if (r<0) throw std::domain_error("Ilegalan poluprecnik"); }
      public: 
      //delete operator =
      //delete inciijalizacija kopirajuca
      //
      ~NepreklapajucaKugla() = default; 
      explicit NepreklapajucaKugla(double r=0) { TestPoluprecnika(r); Postavi(0,0,0,r); kolikoihjekreirano++;}
      NepreklapajucaKugla(double x, double y, double z, double r=0) { TestPoluprecnika(r); Postavi(x,y,z,r); kolikoihjekreirano++; }
      explicit NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r=0) { TestPoluprecnika(r); Postavi(std::get<0>(centar), std::get<1>(centar), std::get<2>(centar), r); kolikoihjekreirano++;}
      double DajX() const { return x; }
      double DajY() const { return y; }
      double DajZ() const { return z; }
      std::tuple<double, double, double> DajCentar() const { return std::tie(x,y,z); } 
      double DajPoluprecnik() const { return r; }
      double DajPovrsinu() const { return 4*PI*r*r; }
      double DajZapreminu() const { return DajPovrsinu()*r/3; }
      NepreklapajucaKugla &PostaviX(double x) { Promijeni(x, this->y, this->z, this->r); return *this; }
      NepreklapajucaKugla &PostaviY(double y) { Promijeni(this->x, y, this->z, this->r); return *this; }
      NepreklapajucaKugla &PostaviZ(double z) { Promijeni(this->x, this->y, z, this->r); return *this; }
      NepreklapajucaKugla &PostaviCentar(double x, double y, double z) { Promijeni(x, y, z, this->r); return *this; }
      NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar) { Promijeni(std::get<0>(centar), std::get<1>(centar), std::get<2>(centar), this->r); return *this; }
      NepreklapajucaKugla &PostaviPoluprecnik(double r) { TestPoluprecnika(r);  Promijeni(this->x, this->y, this->z, r); return *this; }
      void Ispisi() const { std::cout << "{(" << x << "," << y << "," << z << ")," << r << "}" << std::endl;  } //provjeri
      void Translatiraj(double delta_x, double delta_y, double delta_z) { Promijeni(this->x+delta_x, this->y+delta_y, this->z+delta_z, this->r); } 
      friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
      
};

double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2) {
      return std::sqrt((k2.x-k1.x)*(k2.x-k1.x)+(k2.y-k1.y)*(k2.y-k1.y)+(k2.z-k1.z)*(k2.z-k1.z));
}

NepreklapajucaKugla* NepreklapajucaKugla::pok_na_zadnju(nullptr);
int NepreklapajucaKugla::kolikoihjekreirano(0);

int main ()
{
      int n; 
      std::cout << "Unesite broj kugli: ";
      while(!(std::cin >> n) || n<1) {
            std::cin.clear(); 
            std::cin.ignore(10000, '\n');
            std::cout << "Neispravan broj kugli, unesite ponovo!\n"; 
      }
      
      std::vector<std::shared_ptr<NepreklapajucaKugla>> vektor(n); 
      
      for(int i=0; i<n; i++) {
            std::cout << "Unesite centar za " << i+1 << ". kuglu: ";
            double a, b, c; 
            while(!(std::cin >> a >> b >> c)) {
                  std::cin.clear(); 
                  std::cin.ignore(1000,'\n'); 
                  std::cout << "Neispravan centar, unesite ponovo: \n";           }
      
            
            std::cout << "Unesite poluprecnik: "; 
            double pp; 
            while(!(std::cin >> pp) || pp<0) {
                  std::cin.clear();
                  std::cin.ignore(1000, '\n');
                  std::cout << "Neispravan poluprecnik, unesite ponovo: \n"; 
            //      while(!(std::cin >> a >> b >> c)) {
                 //       std::cin.clear(); 
                   //     std::cin.ignore(1000,'\n');
                     //   std::cout << "Neispravan centar\nUnesite centar za "<< i+1 << ". kuglu: "; 
               //   }
                 // std::cout << "Unesite poluprecnik"; 
            }
            try {
            vektor[i]=std::make_shared<NepreklapajucaKugla>(a,b,c,pp); }
            catch(std::logic_error m) {
                  std::cout << m.what() << std::endl; 
                  i--;
            }
            
      }
      
      std::cout << "\nKugle nakon obavljenog sortiranja: \n"; 
      std::sort(vektor.begin(), vektor.end(), [](std::shared_ptr<NepreklapajucaKugla> k1, std::shared_ptr<NepreklapajucaKugla> k2) { return (*k1).DajPovrsinu()<(*k2).DajPovrsinu(); } ); 
      std::for_each(vektor.begin(), vektor.end(), [](std::shared_ptr<NepreklapajucaKugla> k) { k->Ispisi(); });

	return 0;
}
