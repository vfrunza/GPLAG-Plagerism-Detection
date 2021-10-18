/B2017/2018: Zadaća 4, Zadatak 1

#include <iostream>
#include <tuple>
#include <cmath>
#include <stdexcept>
#include <vector>
#include <memory>
#include <algorithm>
#include <iomanip>

#define PI (atan(1)*4)
#define EPS 1e-10


typedef std::tuple<double, double, double> XYZ;

class Kugla
{
  double x,y,z,r;
public:

  explicit Kugla (double r = 0) {
    if (r<0) throw std::domain_error ("Ilegalan poluprecnik");
    x=0;
    y=0;
    z=0;
    Kugla::r=r;
  }

  Kugla (double x, double y, double z, double r=0) {
    if (r<0) throw std::domain_error ("Ilegalan poluprecnik");
    Kugla::x=x;
    Kugla::y=y;
    Kugla::z=z;
    Kugla::r=r;
  }

  explicit Kugla (const XYZ &centar, double r = 0) {
    if (r<0) throw std::domain_error ("Ilegalan poluprecnik");
    x=std::get<0>(centar);
    y=std::get<1>(centar);
    z=std::get<2>(centar);
    Kugla::r=r;
  }

  double DajX () const {
    return x;
  }

  double DajY () const {
    return y;
  }

  double DajZ () const {
    return z;
  }

  XYZ DajCentar () const {
    XYZ centar(std::tie (x,y,z));
    return centar;
  }

  double DajPoluprecnik () const {
    return r;
  }

  double DajPovrsinu () const {
    return 4*r*r*PI;
  }

  double DajZapreminu () const {
    return 4*r*r*r*PI/3;
  }

  Kugla &PostaviX (double x) {
    Kugla::x=x;
    return *this;
  }

  Kugla &PostaviY (double y) {
    Kugla::y=y;
    return *this;
  }

  Kugla &PostaviZ (double z) {
    Kugla::z=z;
    return *this;
  }

  Kugla &PostaviCentar (double x, double y, double z) {
    Kugla::x=x;
    Kugla::y=y;
    Kugla::z=z;
    return *this;
  }

  Kugla &PostaviCentar(const XYZ &centar) {
    PostaviCentar(std::get<0>(centar),std::get<1>(centar), std::get<2>(centar));
    return *this;
  }

  Kugla &PostaviPoluprecnik (double r) {
    if (r<0) throw std::domain_error ("Ilegalan poluprecnik");
    Kugla::r=r;
    return *this;
  }

  void Ispisi () const {
    std::cout<<"{("<<DajX()<<","<<DajY()<<","<<DajZ()<<"),"<<DajPoluprecnik()<<"}" <<std::endl;
  }

  void Transliraj (double delta_x, double delta_y, double delta_z) {
    PostaviCentar(x+delta_x,y+delta_y, z+delta_z);
  }
// ? ? ? da li se moze uporedjivati tuple koji sadrzi double
  friend bool DaLiSuIdenticne (const Kugla &k1, const Kugla &k2) {
    if (k1.DajCentar()==k2.DajCentar() && fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik()) <= EPS*( fabs(k1.DajPoluprecnik()) + fabs(k2.DajPoluprecnik()) )) return true;
    return false;
  }  
  
  friend bool DaLiSuPodudarne (const Kugla &k1, const Kugla &k2) {
    if (k1.DajPoluprecnik()<EPS && k2.DajPoluprecnik()<EPS) return true;
    return fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik()) < EPS*( fabs(k1.DajPoluprecnik()) + fabs(k2.DajPoluprecnik()) );
    }
    
  friend bool DaLiSuKoncentricne (const Kugla &k1, const Kugla &k2) {
      return (k1.DajCentar()==k2.DajCentar());
    }
  
  friend bool DaLiSeDodirujuIzvana (const Kugla &k1, const Kugla &k2){
    if (DaLiSuKoncentricne(k1,k2) && k1.DajPoluprecnik()<EPS && k2.DajPoluprecnik()<EPS) return true;
    if ( fabs( RastojanjeCentara(k1,k2) - (k1.DajPoluprecnik()+k2.DajPoluprecnik())) < EPS* (fabs(RastojanjeCentara(k1,k2))
    + fabs (k1.DajPoluprecnik()+k2.DajPoluprecnik()) ) )return true;
    return false;
  } // Izvana se dodiruju akko im je rastojanje centara jednako zbiru poluprecnika
  
  friend bool DaLiSeDodirujuIznutra (const Kugla &k1, const Kugla &k2){
    // mora vaziti da je rastojanje centara + poluprecnik manje kugle == poluprecniku vece kugle
    if (DaLiSuKoncentricne(k1,k2) && k1.DajPoluprecnik()<EPS && k2.DajPoluprecnik()<EPS) return true;
    if (DaLiSuIdenticne(k1,k2)) return false;  // ako su iste kugle onda se ne dodiruju iznutra jer imaju beskonacno mnogo tacaka dodira a po definiciji je dodir dvije kugle kad postoji jedna zajednicka tacka
    if (k1.DajPoluprecnik()<k2.DajPoluprecnik()) 
    if ( fabs(RastojanjeCentara(k1,k2)+k1.DajPoluprecnik() - k2.DajPoluprecnik()) < EPS*( fabs(RastojanjeCentara(k1,k2)+k1.DajPoluprecnik() ) + fabs(k2.DajPoluprecnik()) ) ) return true;
    else return false;
    else 
    if ( fabs(RastojanjeCentara(k1,k2)+k2.DajPoluprecnik() - k1.DajPoluprecnik()) < EPS*( fabs(RastojanjeCentara(k1,k2)+k2.DajPoluprecnik() ) + fabs(k1.DajPoluprecnik()) ) ) return true;
    return false;
  }
  
  friend bool DaLiSePreklapaju (const Kugla &k1, const Kugla &k2){
    // preklapaju se akko je rastojanje centara manji od zbira poluprecnika
    if (DaLiSuIdenticne(k1,k2)) return false;
    return RastojanjeCentara(k1,k2) < (k1.DajPoluprecnik()+k2.DajPoluprecnik());
  }  // trebace popraviti
  
  friend bool DaLiSeSijeku (const Kugla &k1, const Kugla &k2){
    if (DaLiSuKoncentricne(k1,k2) && k1.DajPoluprecnik()<EPS && k2.DajPoluprecnik()<EPS) return false;
    if (DaLiSuIdenticne(k1,k2)) return true; // ako su dvije kugle identicne onda se one i sjeku
    // dvije kugle se sjeku akko je rastojanje između centara manje od zbira poluprecnika dvije kugle i rastojanje centara je vece od apsolutne vrijednosti razlike poluprecnika jer u suptortnom bi se jedna kugla mogla u cijelosti nalaziti druge kugle
    if ((RastojanjeCentara(k1,k2) < (k1.DajPoluprecnik()+k2.DajPoluprecnik())) && RastojanjeCentara(k1,k2) >
    fabs (k1.DajPoluprecnik()-k2.DajPoluprecnik()) ) return true; 
    return false;
  }  // trebace popraviti
  
  bool DaLiSadrzi (const Kugla &k) {
    return ( (RastojanjeCentara(k,*this) - DajPoluprecnik()) + k.DajPoluprecnik() <= EPS);
  }

  friend double RastojanjeCentara (const Kugla &k1, const Kugla &k2);
};

double Kvadrat(double x) {
  return x*x;
}

double RastojanjeCentara(const Kugla &k1, const Kugla &k2) {
  return sqrt( Kvadrat( k1.DajX() - k2.DajX() ) + Kvadrat( k1.DajY() - k2.DajY() ) + Kvadrat ( k1.DajZ() - k2.DajZ() ) );
}

typedef std::vector<std::shared_ptr<Kugla>> VektorPametnihKugli;
typedef std::shared_ptr<Kugla> PametnaKugla;

int main ()
{
  /*
  Kugla kugla (2,0,0,2);
  XYZ tapl (1,2,3);
  Kugla kugla2 (2,0,0,2);
  //std::cout<<"R="<<kugla.DajPoluprecnik()<<" X="<<kugla.DajX()<<" Y="<<kugla.DajY()<<" Z="<<kugla.DajZ()<<std::endl;
  kugla.Ispisi();
  std::cout<<std::endl;
  kugla.PostaviX(2).PostaviY(3).PostaviZ(5).PostaviPoluprecnik(6);
  kugla.Ispisi();
  std::cout<<std::endl;
  kugla2.Ispisi();
  std::cout<<std::endl;
  kugla2.PostaviCentar(12,12,13);
  kugla2.Ispisi();
  std::cout<<std::endl;
  kugla2.PostaviCentar(tapl);
  kugla2.Ispisi();
  std::cout<<std::endl;
  kugla.PostaviCentar(4,0,0).PostaviPoluprecnik(2);
  kugla2.PostaviCentar(4,0,0).PostaviPoluprecnik(2);
  std::cout<<std::boolalpha<<"Da li su identicne: "<<DaLiSuIdenticne(kugla, kugla2)<<//" \nRastojanje centara: "<<RastojanjeCentara(kugla, kugla2)<<
  " \nDa li se dodiruju izvana: "<<DaLiSeDodirujuIzvana(kugla, kugla2)<<" \nDa li se dodiruju iznutra: "<<DaLiSeDodirujuIznutra(kugla, kugla2)<<
  " \nDa li se preklapaju: "<<DaLiSePreklapaju(kugla, kugla2)<<" \nDa li se sjeku: "<<DaLiSeSjeku(kugla2,kugla)<<" \nDa li su podudarne: "<<
  DaLiSuPodudarne(kugla,kugla2)<<" \nDa li su koncentricne: "<<DaLiSuKoncentricne(kugla,kugla2)<<"\nDa li sadrzi: "<<
  kugla.Kugla::DaLiSadrzi(kugla2);*/
  
 try {
    int n;
    std::cout<<"Unesite broj kugla: ";
    while(1){
    std::cin>>n;
    if (n<=0 || !std::cin || std::cin.peek()!='\n') {
      std::cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;
      std::cin.clear();
      std::cin.ignore(10000,'\n');
    }
    else break;
    }
    VektorPametnihKugli kugle (n,nullptr);  // 

    for (int i = 0; i<n; i++){
      double x,y,z,r;
      
        std::cout<<"Unesite centar "<<i+1<<". kugle: ";
        std::cin>>x>>y>>z;
        if (!std::cin) {
          std::cin.clear();
        std::cin.ignore(10000,'\n');
          std::cout<<"Neispravan centar \n"; i--; continue;
        }
        kugle.at(i) = PametnaKugla (new Kugla(0));
          
        try {
        kugle.at(i)->PostaviCentar(x,y,z);
        std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
        std::cin>>r;
        if (!std::cin) {
          std::cin.clear();
          std::cin.ignore(10000,'\n');
          std::cout<<"Ilegalan poluprecnik \n"; i--; continue;
        }
        kugle.at(i)->PostaviPoluprecnik(r);}
        catch (std::domain_error izuzetak) {
          std::cout<<izuzetak.what()<<std::endl;
          i--;
        }
    }
        // također implementirati za pogresno unesene podatke
      std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
      
      double delta_x,delta_y,delta_z;
      while (1){
      std::cin>>delta_x>>delta_y>>delta_z;
      if (!std::cin){
        std::cout<<"Neispravni parametri translacije, unesite ponovo!"<<std::endl;
        std::cin.clear();
        std::cin.ignore(10000,'\n');
      }
      else break;
      }
      VektorPametnihKugli::iterator it(kugle.begin()); // postavljam iterator na pocetak vektora pametnih kugli
      
      std::transform (it, it+n,it, [delta_x,delta_y,delta_z] (PametnaKugla k1) {
        k1->Transliraj(delta_x,delta_y,delta_z);
        return k1;
      });
      
      std::sort (it, it+n, [] (PametnaKugla k1, PametnaKugla k2){
        return k1->DajZapreminu()<k2->DajZapreminu();
      });
      
      std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: \n";
      std::for_each (it, it+n, [] (PametnaKugla k) {
        k->Ispisi();
      });
      
      std::cout<<"Kugla sa najvecom povrsinom je: ";
      VektorPametnihKugli::iterator max = std::max_element (it, it+n, [] (PametnaKugla k1, PametnaKugla k2){
        return k1->DajPovrsinu() < k2->DajPovrsinu();
      });
      
      (*max)->Ispisi();  // Ispisuje kuglu sa najvecom povrsinom
      std::cout<<std::endl;
      int brojac(1);
      bool nema(true);
      std::for_each(it, it+n, [&brojac,kugle,&nema] (PametnaKugla k1){
       
        std::for_each (kugle.begin()+brojac, kugle.end(), [k1,&nema] (PametnaKugla k2){
              if (DaLiSeSijeku(*k1,*k2)) {
                nema=false;
                std::cout<<"Presjecaju se kugle: ";
                k1->Ispisi();
                std::cout<<std::endl;
                k2->Ispisi();
                std::cout<<std::endl;
              }    
        }); 
        brojac++;
      }
    );
    if (nema) std::cout<<"Ne postoje kugle koje se presjecaju!";
  }
    
  catch (std::domain_error izuzetak){
    std::cout<<izuzetak.what();
  }
  return 0;
}
