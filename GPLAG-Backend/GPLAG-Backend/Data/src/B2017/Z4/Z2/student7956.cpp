/B2017/2018: Zadaća 4, Zadatak 2
#include <iostream>
#include <exception>
#include <tuple>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>
#include <iterator>
const double Eps(1e-10);
using namespace std;

bool JesuLiJednaki(double a, double b) {
 
 return fabs(a - b) <= Eps * (fabs(a) + fabs(b));
}

class NepreklapajucaKugla
{
  double poluprecnik, x, y, z;
  NepreklapajucaKugla *prethodni;
  static NepreklapajucaKugla *posljednji;
  static bool prvi;
public:

  explicit NepreklapajucaKugla(double r = 0)
  {
      if (r < 0) throw domain_error ("Ilegalan poluprecnik");
      poluprecnik = r;
      this->x = 0;
      this->y = 0;
      this->z = 0;
      NepreklapajucaKugla *pomocni;
      pomocni = posljednji;
     
      if (prvi == true)
        pomocni = nullptr;
      while (pomocni != nullptr)
      {
          double a, b, c, d;
          a = pomocni->DajX();
          b = pomocni->DajY();
          c = pomocni->DajX();
          d = pomocni->DajPoluprecnik();
          DaLiSadrzi(x, y, z, poluprecnik, a, b, c, d);
          pomocni = pomocni -> prethodni;
      }
      
      if (prvi == false)
      {
          this->prethodni = posljednji;
          posljednji = this;
          
      }
      else
      {
          prethodni = nullptr;
          posljednji = this;
          prvi = false;
      }
  }
  NepreklapajucaKugla(double x, double y, double z, double r = 0)
  {
      if (r < 0) throw domain_error ("Ilegalan poluprecnik");
      NepreklapajucaKugla::x = x;
      NepreklapajucaKugla::y = y;
      NepreklapajucaKugla::z = z;
      NepreklapajucaKugla::poluprecnik = r;
      NepreklapajucaKugla *pomocni;
      pomocni = posljednji;
     
      if (prvi == true)
        pomocni = nullptr;
      while (pomocni != nullptr)
      {
          double a, b, c, d;
          a = pomocni->DajX();
          b = pomocni->DajY();
          c = pomocni->DajX();
          d = pomocni->DajPoluprecnik();
          DaLiSadrzi(x, y, z, poluprecnik, a, b, c, d);
          pomocni = pomocni -> prethodni;
      }
      
      if (prvi == false)
      {
          this->prethodni = posljednji;
          posljednji = this;
          
      }
      else
      {
          prethodni = nullptr;
          posljednji = this;
          prvi = false;
      }
  }
  explicit NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r = 0)
  {
      if (r < 0) throw domain_error ("Ilegalan poluprecnik");
      poluprecnik = r;
      x = get<0>(centar);
      y = get<1>(centar);
      z = get<2>(centar);
      NepreklapajucaKugla *pomocni;
      pomocni = posljednji;
     
      if (prvi == true)
        pomocni = nullptr;
      while (pomocni != nullptr)
      {
          double a, b, c, d;
          a = pomocni->DajX();
          b = pomocni->DajY();
          c = pomocni->DajX();
          d = pomocni->DajPoluprecnik();
          DaLiSadrzi(x, y, z, poluprecnik, a, b, c, d);
          pomocni = pomocni -> prethodni;
      }
      
      if (prvi == false)
      {
          this->prethodni = posljednji;
          posljednji = this;
          
      }
      else
      {
          prethodni = nullptr;
          posljednji = this;
          prvi = false;
      }
  }
  ~NepreklapajucaKugla () = default;
  
  double DajX() const
  {
      return x;
  }
  double DajY() const
  {
      return y;
  }
  double DajZ() const
  {
      return z;
  }
  tuple<double, double, double> DajCentar() const
  {
      return make_tuple(x, y, z);
  }
  double DajPoluprecnik() const
  {
      return poluprecnik;
  }
  double DajPovrsinu() const
  {
      return 4 * M_PI * poluprecnik * poluprecnik;
  }
  double DajZapreminu() const
  {
      return 4/3. * M_PI * poluprecnik * poluprecnik * poluprecnik; 
  }
  NepreklapajucaKugla &PostaviX(double x)
  {
      this-> x = x;
      return *this;
  }
  NepreklapajucaKugla &PostaviY(double y)
  {
      this-> y = y;
      return *this;
  }
  NepreklapajucaKugla &PostaviZ(double z)
  {
      this-> z = z;
      return *this;
  }
  NepreklapajucaKugla &PostaviCentar(double x, double y, double z)
  {
      this-> x = x;
      this-> y = y;
      this-> y = z;
      NepreklapajucaKugla *pomocni;
      pomocni = posljednji;
      if (prvi == true)
        pomocni = nullptr;
      while (pomocni != nullptr)
        {
            double a, b, c, d;
          a = pomocni->DajX();
          b = pomocni->DajY();
          c = pomocni->DajX();
          d = pomocni->DajPoluprecnik();
          if (JesuLiJednaki(a, x) && JesuLiJednaki(b, y) && JesuLiJednaki(c, y) && JesuLiJednaki(d, poluprecnik))
            goto Preskoci;
        DaLiSadrzi(x, y, z, poluprecnik, a, b, c, d);
          
        Preskoci:
            pomocni = pomocni -> prethodni;
        }
      return *this;
  }
  
  NepreklapajucaKugla &PostaviPoluprecnik(double r)
  {
      if (r < 0) throw domain_error ("Ilegalan poluprecnik");
      poluprecnik = r;
      NepreklapajucaKugla *pomocni;
      pomocni = posljednji;
      if (prvi == true)
        pomocni = nullptr;
      while (pomocni != nullptr)
        {
            double a, b, c, d;
          a = pomocni->DajX();
          b = pomocni->DajY();
          c = pomocni->DajX();
          d = pomocni->DajPoluprecnik();
          if (JesuLiJednaki(a, x) && JesuLiJednaki(b, y) && JesuLiJednaki(c, y) && JesuLiJednaki(d, poluprecnik))
            goto Preskoci;
        DaLiSadrzi(x, y, z, poluprecnik, a, b, c, d);
          
        Preskoci:
            pomocni = pomocni -> prethodni;
        }
      return *this;
  }
  void Ispisi() const
  {
      cout << "{(" << DajX() << "," << DajY() << "," << DajZ() << ")," << DajPoluprecnik() << "}" << endl;
  }
   void DaLiSadrzi(double a, double b, double c, double d, double x, double y, double z, double r) const
  {
      double e = sqrt( (a - x) * (a - x) + (b - y) * (b - y) + (c - z) * (c - z) );
      if (d + r > e) throw logic_error ("Presjeca se");
      
  }
  friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2)
  {
      double udaljenost = sqrt( (k1.x - k2.x) * (k1.x - k2.x) + (k1.y - k2.y) * (k1.y - k2.y) + (k1.z - k2.z) * (k1.z - k2.z) );
      return udaljenost;
  }
};

NepreklapajucaKugla* NepreklapajucaKugla::posljednji {nullptr};

bool NepreklapajucaKugla::prvi {true};


int main ()
{
  int n, m = 1;
    cout << "Unesite broj kugla: ";
    while (1)
            {
                if (cin >> n && n > 0)
                    break;
                else
                {
                cout << "Neispravan broj kugli, unesite ponovo!\n";
                cin.clear();
                cin.ignore(100000, '\n');
                }
            }
    vector<shared_ptr<NepreklapajucaKugla>> kugle;
    
    double a, b, c, r;
    while (n > 0)
    {
        cout << "Unesite centar " << m << ". kugle: ";
        
        cin >> a >> b >> c;
        if (!cin)
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Neispravan centar\n";
            continue;
        }
        cout << "Unesite poluprecnik " << m << ". kugle: ";
         cin >> r;
         if (!cin || r < 0)
        {
            cin.clear();
            cin.ignore(100000, '\n');
            cout << "Ilegalan poluprecnik\n";
            continue;
        }
        try 
        {
          kugle.push_back(make_shared<NepreklapajucaKugla>(a, b, c, r));
        }
        catch (logic_error e)
        {
          cout << e.what();
          return 0;
        }
        n--;
        m++;
    }
	return 0;
}
