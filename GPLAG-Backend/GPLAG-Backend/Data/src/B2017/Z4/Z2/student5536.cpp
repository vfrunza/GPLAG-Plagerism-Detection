/B2017/2018: Zadaća 4, Zadatak 2 // Kopirao sam kod zadatka 1 u ovaj zadatak
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

class NepreklapajucaKugla
{
  double x,y,z,r;
  NepreklapajucaKugla *veza;
  static NepreklapajucaKugla *posljednji;

  bool DaLiSePreklapaju (const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2) {
    // preklapaju se akko je rastojanje centara manji od zbira poluprecnika
    return (RastojanjeCentara(k1,k2) <= (k1.DajPoluprecnik()+k2.DajPoluprecnik()));
  }// Problem: kad se u nekoj metodi promjeni nesto, promjeni se i this a samim time i veza pa se nece ocuvati ono od ranije

  void Izuzetak (NepreklapajucaKugla *k) {
    bool nema(true); // pretpostavljam da je k novi element liste
    for (NepreklapajucaKugla *p=posljednji; p!=nullptr; p=p->veza ) {
      if (p==k)  { nema=false;  // ako je pokazivac jednak znaci da je dati element vec u listi mada je sad promjenio vrijednost, zbog kopiranja pokazivaca on p ce vec imati novu vrijesdnot pa nema potrebe praviti novu vezu
      continue; }
    if (DaLiSePreklapaju(*p,*k)) 
    throw std::logic_error ("Nedozvoljeno preklapanje");
    }
    if (nema)  // ako nema elementa k u listi onda ga je potrebno uvezati
    veza=posljednji;  // postavljam vezu na posljednji ili bolje reci prijasnji element
    posljednji=k; // posljednji tj. sljedeci element jese onaj koji je prosao test i on se uvezuje u listu

  }
public:

  NepreklapajucaKugla (const NepreklapajucaKugla &k) = delete; // zabrana kopiranja
   
  NepreklapajucaKugla &operator = (const NepreklapajucaKugla &k) = delete;  // zabrana dodjele

  explicit NepreklapajucaKugla (double r = 0) {
    x=0;
    y=0;
    z=0;
    if (r<0) throw std::domain_error ("Ilegalan poluprecnik");
    NepreklapajucaKugla::r=r;
    Izuzetak(this);
  }

  NepreklapajucaKugla (double x, double y, double z, double r=0) {
    NepreklapajucaKugla::x=x;
    NepreklapajucaKugla::y=y;
    NepreklapajucaKugla::z=z;
    if (r<0) throw std::domain_error ("Ilegalan poluprecnik");
    NepreklapajucaKugla::r=r;
    Izuzetak(this);
  }

  explicit NepreklapajucaKugla (const XYZ &centar, double r = 0) {
    x=std::get<0>(centar);
    y=std::get<1>(centar);
    z=std::get<2>(centar);
    if (r<0) throw std::domain_error ("Ilegalan poluprecnik");
    NepreklapajucaKugla::r=r;
    Izuzetak(this);
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

  NepreklapajucaKugla &PostaviX (double x) {
    NepreklapajucaKugla::x=x;
    Izuzetak(this);
    return *this;
  }

  NepreklapajucaKugla &PostaviY (double y) {
    NepreklapajucaKugla::y=y;
    Izuzetak(this);
    return *this;
  }

  NepreklapajucaKugla &PostaviZ (double z) {
    NepreklapajucaKugla::z=z;
    Izuzetak(this);
    return *this;
  }

  NepreklapajucaKugla &PostaviCentar (double x, double y, double z) {
    NepreklapajucaKugla::x=x;
    NepreklapajucaKugla::y=y;
    NepreklapajucaKugla::z=z;
    Izuzetak(this);
    return *this;
  }

  NepreklapajucaKugla &PostaviCentar(const XYZ &centar) {
    PostaviCentar(std::get<0>(centar),std::get<1>(centar), std::get<2>(centar));
    Izuzetak(this);
    return *this;
  }

  NepreklapajucaKugla &PostaviPoluprecnik (double r) {
    if (r<0) throw std::domain_error ("Ilegalan poluprecnik");
    NepreklapajucaKugla::r=r;
    Izuzetak(this);
    return *this;
  }

  void Ispisi () const {
    std::cout<<"{("<<DajX()<<","<<DajY()<<","<<DajZ()<<"),"<<DajPoluprecnik()<<"}"<<std::endl;
  }

  void Transliraj (double delta_x, double delta_y, double delta_z) {
    PostaviCentar(x+delta_x,y+delta_y, z+delta_z);
    Izuzetak(this);
  }

  bool DaLiSadrzi (const NepreklapajucaKugla &k) {
    return ( (RastojanjeCentara(k,*this) - DajPoluprecnik()) + k.DajPoluprecnik() <= EPS);
  }

  friend double RastojanjeCentara (const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
};
NepreklapajucaKugla* NepreklapajucaKugla::posljednji=nullptr;  // postavljam statickii atribut na nullptr

double Kvadrat(double x)
{
  return x*x;
}

double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2)
{
  return sqrt( Kvadrat( k1.DajX() - k2.DajX() ) + Kvadrat( k1.DajY() - k2.DajY() ) + Kvadrat ( k1.DajZ() - k2.DajZ() ) );
}

typedef std::vector<std::shared_ptr<NepreklapajucaKugla>> VektorPametnihKugli;
typedef std::shared_ptr<NepreklapajucaKugla> PametnaKugla;

int main ()
{
  try {
    int n;
    std::cout<<"Unesite broj kugli: ";
    while(1) {
      std::cin>>n;
      if (n<=0 || !std::cin || std::cin.peek()!='\n') {
        std::cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;
        std::cin.clear();
        std::cin.ignore(10000,'\n');
      } else break;
    }
    VektorPametnihKugli kugle (n,nullptr);

    for (int i = 0; i<n; i++) {
      double x,y,z,r;

      std::cout<<"Unesite centar za "<<i+1<<". kuglu: ";
      while (1) {
        std::cin>>x>>y>>z;
        if (!std::cin){
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::cout<<"Neispravan centar, unesite ponovo: \n";}
        else break;
      }

      try {
        std::cout<<"Unesite poluprecnik: ";
        while (1) {
          std::cin>>r;
          if (!std::cin || r<0){
          std::cin.clear();
          std::cin.ignore(10000,'\n');
          std::cout<<"Neispravan poluprecnik, unesite ponovo: \n";
          }
          else break;
        }
        kugle.at(i) = PametnaKugla (new NepreklapajucaKugla(x,y,z,r));
      } catch (std::domain_error izuzetak) {
        std::cout<<izuzetak.what()<<std::endl;
        i--;
      }
      catch (std::logic_error izuzetak) {
        std::cout<<izuzetak.what()<<std::endl;
        i--;
      }
    }

    VektorPametnihKugli::iterator it(kugle.begin()); // postavljam iterator na pocetak vektora pametnih kugli

    std::sort (it, it+n, [] (PametnaKugla k1, PametnaKugla k2) {
      return k1->DajPovrsinu()<k2->DajPovrsinu();
    });

    std::cout<<"\nKugle nakon obavljenog sortiranja: \n";
    std::for_each (it, it+n, [] (PametnaKugla k) {
      k->Ispisi();
    });
  } catch (std::domain_error izuzetak) {
    std::cout<<izuzetak.what();
  }
  catch (std::logic_error izuzetak){
    std::cout<<izuzetak.what();
  }
  return 0;
}