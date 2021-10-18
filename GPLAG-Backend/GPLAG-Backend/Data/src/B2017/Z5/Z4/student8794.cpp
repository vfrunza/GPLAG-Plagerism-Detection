/B2017/2018: Zadaća 5, Zadatak 4
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <stdexcept>
#include <algorithm>
#include <string>
#include <memory>
#include <map>
#include <utility>
#include <type_traits>
#include <vector>
#include <cmath>
#include <initializer_list>
#include <functional>

const double PI = 4*std::atan(1);
const double AT_PI1=4 * std::atan(1);
const double AT_eps1=1e-10;
int AT_sirina_ispisa1=14;
template <typename T>
void AT_Ispisi1(T s1, T s2, bool withEndl=true) {
    std::cout << std::setw(AT_sirina_ispisa1) << s1 << std::setw(AT_sirina_ispisa1) << s2;
    if (withEndl) std::cout<<std::endl;
}
template <typename T>
T AT_zaokruzi1(T x) { 
    auto oldPrec=std::cout.precision();
    return std::floor( x * std::pow(10, oldPrec) + 0.5 ) / std::pow(10, oldPrec)+AT_eps1;
}
template <typename T>
void AT_Ispisi1(std::pair<T, T> p, bool withEndl=true) {
    std::cout << std::setw(AT_sirina_ispisa1) << AT_zaokruzi1(p.first) << std::setw(AT_sirina_ispisa1) << AT_zaokruzi1(p.second);
    if (withEndl) std::cout<<std::endl;
}

class FourierovRed
{
    //double a0;
    double *ak;
    double *bk;
    double T;
    int N;
  
  public:
  
  FourierovRed(double period, std::initializer_list<double> a, std::initializer_list<double> b) : T(period)
  {
      if(a.size() == b.size()) 
      {
          //a0 = *(a.begin()); //nulti clan
          N = a.size() + 1;
          ak = new double[a.size() + 1]; bk = new double[a.size() + 1];
          int i(0);
          for(auto it(a.begin()); it != a.end() ; it++)
          {
              ak[i] = *it; i++;
          }
          ak[i] = 0; bk[0] = 0; int j(1);
          for(auto it(b.begin()); it != b.end(); it++)
          {
              bk[j] = *it; j++;
          }
      }   
      if(a.size() < b.size())
      {
           N = b.size() + 1;
           ak = new double[b.size() + 1]; bk = new double[b.size() + 1]; int i(1), j(0); bk[0] = 0;
           for(auto it(b.begin()); it != b.end(); it++)
           {
               bk[i] = *it; 
               i++;
           }
           
           for( auto it(a.begin()); it != a.end(); it++)
           {
               ak[j] = *it; j++;
           }
           for(int k(j); k < N; k++)
           {
               ak[k] = 0;
           }
        //   for(int i(0); i < N; i++) std::cout<<bk[i]<<" ";
      }
      if(a.size() > b.size())
      {
          N = a.size() + 1;
          ak = new double[a.size() + 1]; bk = new double[a.size() + 1]; int i(0), j(1);
          for(auto it(a.begin()); it != a.end(); it++)
           {
               ak[i] = *it; i++;
           }
           ak[i] = 0; bk[0] = 0;
           for(auto it1(b.begin()); it1 != b.end(); it1++)
           {
               bk[j] = *it1;
               j++;
           }
           for(int k(j); k < N; k++)
           {
               bk[k] = 0;
           }
      }
  };
  FourierovRed(int n, double period, std::function<double(int)> f1, std::function<double(int)> f2) : T(period)
  {
      if(n < 0) throw std::domain_error("Stepen mora biti pozitivan\n");
      N = n;
      ak = new double[n]; bk = new double[n];
      //a0 = f1(0);
      for(int i(0); i < n; i++)
      {
          ak[i] = f1(i); 
          if(i != 0) bk[i] = f2(i-1);
          if(i == 0) bk[0] = 0;
      }
  };
  FourierovRed(int n, double p, double q, std::function<double(double)> f, int M)
  {
      if(n < 0) throw std::domain_error("Stepen mora biti pozitivan\n");
      if(M < 0) throw std::domain_error("Broj podintervala mora biti pozitivan\n");
      if(p > q) throw std::range_error("Neispravan interval\n");
      N = n; T = q - p;
      ak = new double[n]; bk = new double[n];
      for(int k(0); k <= n; k++)
      {
          double sumaA(0), sumaB(0);
          for(int i(1); i <= M-1; i++)
          {
              sumaA += f(p + (i*T)/M)*std::cos(2*k*PI*(p/T + i/M));
              if(k != 0) sumaB += f(p + (i*T)/M)*std::sin(2*k*PI*(p/T + i/M));
          }
          if(k == 0) {ak[0] = (2*sumaA)/M + ((f(p) + f(q))/M); bk[0] = 0;}
          if(k != 0) ak[k] = (2*sumaA)/M + ((f(p) + f(q))/M)*std::cos((2*k*PI*p)/T);
          if(k != 0) bk[k] = (2*sumaB)/M + ((f(p) + f(q))/M)*std::sin((2*k*PI*p)/T);
      }
  };
  FourierovRed(const FourierovRed &r) : N(r.N), T(r.T)//, a0(r.a0)
  {
       ak = new double[r.N]; bk = new double[r.N];
       for(int i(0); i < r.N; i++)
       {
           ak[i] = r.ak[i]; bk[i] = r.bk[i];
       }
  };
  FourierovRed(FourierovRed &&r) : N(r.N), T(r.T)//, a0(r.a0)
  {
      double *pomocni1(r.ak);
      double *pomocni2(r.bk);
      ak = pomocni1;
      bk = pomocni2;
      pomocni1 = pomocni2 = r.ak = r.bk = nullptr;
  };
  FourierovRed &operator =(const FourierovRed &r) 
  {
     N = r.N; T = r.T;// a0 = r.a0;
     delete [] ak; delete [] bk;
     ak = nullptr; bk = nullptr;
     ak = new double[r.N]; bk = new double[r.N];
     for(int i(0); i < r.N; i++)
       {
           ak[i] = r.ak[i]; bk[i] = r.bk[i];
       }
     return *this;
  };
  FourierovRed &operator =(FourierovRed &&r)
  {
     N = r.N; T = r.T;// a0 = r.a0;
     delete [] ak; delete [] bk;
     ak = nullptr; bk = nullptr;
     //ak = new double[r.N]; bk = new double[r.N];
     double *pomocni1(r.ak); double *pomocni2(r.bk);
     ak = pomocni1;
     bk = pomocni2;
     pomocni1 = pomocni2 = r.ak = r.bk = nullptr;
     return *this;
  };
  ~FourierovRed()
  {
     delete [] ak;
     delete [] bk;
  };
  double operator ()(double x)
  {
      double rezultat(ak[0]/2);
      for(int k(1); k <= N; k++)
      {
          rezultat += ak[k]*std::cos((2*k*PI*x)/T) + bk[k]*std::sin((2*k*PI*x)/T);
      }
      return rezultat;
  };
  std::pair<double, double> operator [](int k) const
  {
      //double pomocni(a0);
      if(k < 0 || k >= N - 1) throw std::range_error("Neispravan indeks\n");
      if(k == 0) return std::make_pair<double, double>(std::remove_reference<double&>::type(ak[0]), std::remove_reference<double&>::type(bk[0]));
      else return std::make_pair<double, double>(std::remove_reference<double&>::type(ak[k]), std::remove_reference<double&>::type(bk[k]));
  };
  std::pair<double&, double&> operator [](int k)
  {
      //double pomocni(a0);
      if(k < 0 || k >= N - 1) throw std::range_error("Neispravan indeks\n");
      //if(k == 0) return std::make_pair<double&, double&>(pomocni);
      std::pair<double&, double&> p(ak[k],bk[k]);
      return p;
  };
};

int main ()
{
    double L=2;
    std::cout << std::fixed << std::setprecision(5);
    FourierovRed f22(2*L, {}, {-1.27324, 0.63662, -0.42441, 0.31831, -0.25465, 0.21221, -0.18189, 0.15915, -0.14147, 0.12732});
    auto k1=[](int k) { return (k == 0) ? 8 * AT_PI1 * AT_PI1 / 3 : 4. / (k * k); };
    auto k2=[](int k) { return -4 * AT_PI1 / k; };
    auto f=[](double x) { return x * x; };
    FourierovRed f1(50, 2*AT_PI1, k1, k2);
    FourierovRed f2(50, 0, 2*AT_PI1, f, 1000);
    FourierovRed f11(2*L, {2*L, 1}, {});
    FourierovRed f33(2*L, {2*L}, {-1.27324, 0.63662, -0.42441, 0.31831, -0.25465, 0.21221, -0.18189, 0.15915, -0.14147, 0.12732});

    try {
        std::cout<<"Koeficijenti:"<<std::endl;
        AT_Ispisi1("f2.a", "f2.b", 0);
        // AT_Ispisi("a", "b");
        AT_Ispisi1("f3.a", "f3.b");
        for(int i = 0; i <= 10; i++) {
            AT_Ispisi1(f22[i], 0);
            // AT_Ispisi(f1[i]);
            AT_Ispisi1(f33[i]);
        }
        std::cout << std::endl;
        std::cout << "Pokusaj ispisa prva 3 koeficijenta iz f1:"<<std::endl;
        AT_Ispisi1(f11[0]);
        AT_Ispisi1(f11[1]);
        AT_Ispisi1(f11[2]);
    }
    catch (std::range_error e) {
        std::cout<<e.what()<<std::endl;
    }
    std::cout<<"Koeficijenti:"<<std::endl;
    // AT_Ispisi("a", "b", 0);
    AT_Ispisi1("a", "b");
    // AT_Ispisi("a(apr)", "b(apr)");
    for(int i = 0; i <= 10; i++) {
        // AT_Ispisi(f1[i], 0);
        AT_Ispisi1(f1[i]);
        // AT_Ispisi(f2[i]);
    }
    std::cout << std::endl;
    // AT_Ispisi("f1(3)", "f2(3)");
    // AT_Ispisi(f1(3), f2(3));
    // Treba biti priblizno 9
    double stv=f1(3);
    double apr=f2(3);
    if (apr<=stv+0.004 && apr>=stv-0.004) std::cout<<"f1(3)\u2248f2(3) OK";
    else std::cout<<"Stvarna i aproksimirana vrijednost polinoma se previse razlikuju"<<std::endl;
    
    std::cout << std::endl;
    std::cout<<"Dodjela f2=f1;"<<std::endl<<std::endl;
    f2=f1=f2=f1; // Operator dodjele
    AT_Ispisi1("f1(3)", "f2(3)");
    AT_Ispisi1(f1(3), f2(3));
	return 0;
}
