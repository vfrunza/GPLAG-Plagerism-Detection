/B2017/2018: Zadaća 4, Zadatak 1
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

class Kugla
{
  double poluprecnik, x, y, z;
  
public:

  explicit Kugla(double r = 0)
  {
      if (r < 0) throw domain_error ("Ilegalan poluprecnik");
      poluprecnik = r;
      this->x = 0;
      this->y = 0;
      this->z = 0;
  }
  Kugla(double x, double y, double z, double r = 0)
  {
      if (r < 0) throw domain_error ("Ilegalan poluprecnik");
      Kugla::x = x;
      Kugla::y = y;
      Kugla::z = z;
      Kugla::poluprecnik = r;
  }
  explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0)
  {
      if (r < 0) throw domain_error ("Ilegalan poluprecnik");
      poluprecnik = r;
      x = get<0>(centar);
      y = get<1>(centar);
      z = get<2>(centar);
  }
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
  Kugla &PostaviX(double x)
  {
      this-> x = x;
      return *this;
  }
  Kugla &PostaviY(double y)
  {
      this-> y = y;
      return *this;
  }
  Kugla &PostaviZ(double z)
  {
      this-> z = z;
      return *this;
  }
  Kugla &PostaviCentar(double x, double y, double z)
  {
      this-> x = x;
      this-> y = y;
      this-> y = z;
      return *this;
  }
  Kugla &PostaviCentar(const std::tuple<double, double, double> &centar)
  {
      this-> x = get<0>(centar);
      this-> y = get<1>(centar);
      this-> z = get<2>(centar);
      return *this;
  }
  Kugla &PostaviPoluprecnik(double r)
  {
      if (r < 0) throw domain_error ("Ilegalan poluprecnik \n");
      poluprecnik = r;
      return *this;
  }
  void Ispisi() const
  {
      cout << "{(" << DajX() << "," << DajY() << "," << DajZ() << ")," << DajPoluprecnik() << "}" << endl;
  }
  void Transliraj(double delta_x, double delta_y, double delta_z)
  {
      x += delta_x;
      y += delta_y;
      z += delta_z;
  }
  friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2)
  {
      if( JesuLiJednaki(k1.x, k2.x) && JesuLiJednaki(k1.y, k2.y) &&
            JesuLiJednaki(k1.z, k2.z) && JesuLiJednaki(k1.poluprecnik, k2.poluprecnik)) return true;
      return false;
  }
  friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2)
  {
      if (JesuLiJednaki(k1.poluprecnik, k2.poluprecnik)) return true;
      return false;
  }
  friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2)
  {
      if ( JesuLiJednaki(k1.x, k2.x) && JesuLiJednaki(k1.y, k2.y) && JesuLiJednaki(k1.z, k2.z)) return true;
      return false;
  }
  friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2)
  {
      double a = sqrt( (k1.x - k2.x) * (k1.x - k2.x) + (k1.y - k2.y) * (k1.y - k2.y) + (k1.z - k2.z) * (k1.z - k2.z) );
      if (JesuLiJednaki(k2.poluprecnik + k1.poluprecnik, a)) return true;
      return false;
  }
  friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2)
  {
      double b = sqrt( (k1.x - k2.x) * (k1.x - k2.x) + (k1.y - k2.y) * (k1.y - k2.y) + (k1.z - k2.z) * (k1.z - k2.z) );
      if (JesuLiJednaki(k1.poluprecnik + b, k2.poluprecnik)) return true;
      else if (JesuLiJednaki(k2.poluprecnik + b, k1.poluprecnik)) return true;
      return false;
  }
  friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2)
  {
      double c = sqrt( (k1.x - k2.x) * (k1.x - k2.x) + (k1.y - k2.y) * (k1.y - k2.y) + (k1.z - k2.z) * (k1.z - k2.z) );
      if ( (k1.poluprecnik + c < k2.poluprecnik) || JesuLiJednaki(k1.poluprecnik + c, k2.poluprecnik)) return true;
      else if ( (k2.poluprecnik + c < k1.poluprecnik) || JesuLiJednaki(k2.poluprecnik + c, k1.poluprecnik)) return true;
      return false;
  }
  friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2)
  {
      double d = sqrt( (k1.x - k2.x) * (k1.x - k2.x) + (k1.y - k2.y) * (k1.y - k2.y) + (k1.z - k2.z) * (k1.z - k2.z) );
      if (d < k1.poluprecnik + k2.poluprecnik && !k1.DaLiSadrzi(k2) && !k2.DaLiSadrzi(k1)) return true;
      return false;
  }
  
 
  bool DaLiSadrzi(const Kugla &k) const
  {
      double e = sqrt( (this->x - k.x) * (this->x - k.x) + (this-> y - k.y) * (this->y - k.y) + (this->z - k.z) * (this->z - k.z) );
      
        if (k.poluprecnik + e <= this->poluprecnik) return true;
      return false;
  }
  friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2)
  {
      double udaljenost = sqrt( (k1.x - k2.x) * (k1.x - k2.x) + (k1.y - k2.y) * (k1.y - k2.y) + (k1.z - k2.z) * (k1.z - k2.z) );
      return udaljenost;
  }
};

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
    vector<shared_ptr<Kugla>> kugle;
    
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
        kugle.push_back(make_shared<Kugla>(a, b, c, r));
        n--;
        m++;
    }
    double o, p, l;
    
    cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    while(1)
    {
    cin >> o >> p >> l;
    if (!cin)
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Neispravni parametri translacije, unesite ponovo!\n";
            continue;
        }
    else break;
    }
    transform(kugle.begin(), kugle.end(), kugle.begin(), [o, p, l] (shared_ptr<Kugla> k)
                 {
                     k->Transliraj(o, p, l);
                     return k;
                 } );
    sort(kugle.begin(), kugle.end(), [] (shared_ptr<Kugla> k1, shared_ptr<Kugla> k2)
                 {
                     if (k1->DajZapreminu() < k2->DajZapreminu()) 
                        return true;
                     else
                        return false;
                 } );
    cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: " << endl;
    for_each(kugle.begin(), kugle.end(), [](shared_ptr<Kugla> k)
                 {
                    return k->Ispisi();
                 } );
    cout << "Kugla sa najvecom povrsinom je: ";
    (* max_element(kugle.begin(), kugle.end(), [] (shared_ptr<Kugla> k1, shared_ptr<Kugla> k2)
                 {
                     if (k1->DajPovrsinu() < k2->DajPovrsinu()) 
                        return true;
                     else
                        return false;
                 }))->Ispisi();
    int i(1);
   
    
    bool sijeku(false);
 
    std::for_each(kugle.begin(),kugle.end(),[&i, &kugle, &sijeku](const std::shared_ptr<Kugla> &k)
    {
        std::for_each(kugle.begin()+i,kugle.end(),[&k, &sijeku](const std::shared_ptr<Kugla> &y)
        {
            if(DaLiSeSijeku(*k, *y))
            {
                std::cout<<"Presjecaju se kugle: ";
                k->Ispisi();
                y->Ispisi();
                sijeku=true;
            }
        });
        i++;
    });
    if(!sijeku) std::cout<<"Ne postoje kugle koje se presjecaju!"<<std::endl;
	return 0;
}
