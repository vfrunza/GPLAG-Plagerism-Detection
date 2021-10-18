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

class FourierovRed
{
    double a0;
    std::vector<double> ak;
    std::vector<double> bk;
    double T;
    int N;
    double b0;

  public:

  FourierovRed(double period, std::initializer_list<double> a, std::initializer_list<double> b) : T(period)
  {
      if(a.size() == b.size())
      {
          a0 = *(a.begin()); //nulti clan
          N = a.size();
          ak.resize(N); bk.resize(N);
          int i(0); auto it(a.begin()); it++;
          for(; it != a.end() ; it++)
          {
              ak[i] = *it; i++;
          }
          ak[i+1] = 0; int j(0);
          for(auto it1(b.begin()); it1 != b.end(); it1++)
          {
              bk[j] = *it1; j++;
          }
      }
      if(a.size() < b.size())
      {
           a0 = *(a.begin());
           N = b.size();
           ak.resize(N); bk.resize(N); int i(0), j(0);// bk[0] = 0;
           for(auto it(b.begin()); it != b.end(); it++)
           {
               bk[i] = *it;
               i++;
           }
           auto it2(a.begin());
           if(it2 != a.end()){it2++;
           for(; it2 != a.end(); it2++)
           {
               ak[j] = *it2; j++;
           }}
           for(int k(j); k < N; k++)
           {
               ak[k] = 0;
           }
      }
      if(a.size() > b.size())
      {
          a0 = *(a.begin());
          N = a.size();
          ak.resize(N); bk.resize(N); int i(0), j(0);
          auto it(a.begin()); it++;
          for(; it != a.end(); it++)
           {
               ak[i] = *it; i++;
           }
           //bk[0] = 0;
           for(auto it1(b.begin()); it1 != b.end(); it1++)
           {
               bk[j] = *it1;
               j++;
           }
           for(int k(j); k < i; k++)
           {
               bk[k] = 0;
           }
          // for(int i(0); i < N; i++) std::cout<<ak[i]<<" ";
          //for(int i(0); i < N; i++) std::cout<<bk[i]<<" ";
      }
  };
  FourierovRed(int n, double period, std::function<double(int)> f1, std::function<double(int)> f2) : T(period)
  {
      if(n < 0) throw std::domain_error("Stepen mora biti pozitivan\n");
      N = n;
      ak.resize(N); bk.resize(N);
      a0 = f1(0);
      for(int i(1); i < n; i++)
      {
          ak[i-1] = f1(i);
          bk[i-1] = f2(i);
          //if(i == 0) bk[0] = 0;
      }
  };
  FourierovRed(int n, double p, double q, std::function<double(double)> f, int M)
  {
      if(n < 0) throw std::domain_error("Stepen mora biti pozitivan\n");
      if(M < 0) throw std::domain_error("Broj podintervala mora biti pozitivan\n");
      if(p > q) throw std::range_error("Neispravan interval\n");
      N = n; T = q - p;
      ak.resize(N); bk.resize(N);
      for(int k(0); k <= n; k++)
      {
          double sumaA(0), sumaB(0);
          for(int i(1); i <= M-1; i++)
          {
              sumaA += f(p + (i*T)/M)*std::cos(2*k*PI*(p/T + i/M));
              if(k != 0) sumaB += f(p + (i*T)/M)*std::sin(2*k*PI*(p/T + i/M));
          }
          if(k == 0) {a0 = (2*sumaA)/M + ((f(p) + f(q))/M); }//bk[0] = 0;}
          if(k != 0) ak[k-1] = (2*sumaA)/M + ((f(p) + f(q))/M)*std::cos((2*k*PI*p)/T);
          if(k != 0) bk[k-1] = (2*sumaB)/M + ((f(p) + f(q))/M)*std::sin((2*k*PI*p)/T);
      }
  };
  FourierovRed(const FourierovRed &r) : N(r.N), T(r.T), a0(r.a0)
  {
       ak.resize(N); bk.resize(N);
       for(int i(0); i < r.N; i++)
       {
           ak[i] = r.ak[i]; bk[i] = r.bk[i];
       }
  };
  FourierovRed(FourierovRed &&r) : N(r.N), T(r.T), a0(r.a0)
  {
      ak = std::move(r.ak);
      bk = std::move(r.bk);
      /*double *pomocni1(r.ak);
      double *pomocni2(r.bk);
      ak = pomocni1;
      bk = pomocni2;
      pomocni1 = pomocni2 = r.ak = r.bk = nullptr;*/
  };
  FourierovRed &operator =(const FourierovRed &r)
  {
     N = r.N; T = r.T; a0 = r.a0;
     ak.clear(); bk.clear();
     //ak = nullptr; bk = nullptr;
     ak.resize(r.N); bk.resize(r.N);
     for(int i(0); i < r.N; i++)
       {
           ak[i] = r.ak[i]; bk[i] = r.bk[i];
       }
     return *this;
  };
  FourierovRed &operator =(FourierovRed &&r)
  {
     N = r.N; T = r.T; a0 = r.a0;
     //delete [] ak; delete [] bk;
     //ak = nullptr; bk = nullptr;
     //ak = new double[r.N]; bk = new double[r.N];
     ak.clear(); bk.clear();
     /*double *pomocni1(r.ak); double *pomocni2(r.bk);
     ak = pomocni1;
     bk = pomocni2;
     pomocni1 = pomocni2 = r.ak = r.bk = nullptr;*/
     ak = std::move(r.ak);
     bk = std::move(r.bk);
     return *this;
  };
 /* ~FourierovRed()
  {
     delete [] ak;
     delete [] bk;
  };*/
  double operator ()(double x)
  {
      double rezultat(a0/2);
      for(int k(1); k <= N; k++)
      {
          rezultat += ak[k-1]*std::cos((2*k*PI*x)/T) + bk[k-1]*std::sin((2*k*PI*x)/T);
      }
      return rezultat;
  };
  std::pair<double, double> operator [](int k) const
  {
      double pomocni(a0);
      if(k < 0 || k > N) throw std::range_error("Neispravan indeks\n");
      if(k == 0) return std::make_pair<double, double>(std::remove_reference<double&>::type(pomocni), 0.);
      else return std::make_pair<double, double>(std::remove_reference<double&>::type(ak[k-1]), std::remove_reference<double&>::type(bk[k-1]));
  };
  std::pair<double&, double&> operator [](int k)
  {
      b0 = 0.;
      double pomocni(a0), pomocni1(b0);
      if(k < 0 || k > N) throw std::range_error("Neispravan indeks\n");
      if(k == 0) {std::pair<double&, double&> p0(pomocni, pomocni1); return p0; }
      std::pair<double&, double&> p(ak[k - 1],bk[k - 1]);
      return p;
  };
};

int main ()
{
    FourierovRed f(4, {}, {-1.27324, 0.63662, -0.42441, 0.31831, -0.25465, 0.21221, -0.18189, 0.15915, -0.14147, 0.12732});
    try{
        for(int i(0); i <= 10; i++) std::cout<<f[i].second<<" ";
        std::cout<<"\n";
    }
    catch(std::range_error r)
    {
        std::cout<<r.what();
    }
    FourierovRed f1(4, {4, 1}, {});
    try{
        for(int i(0); i <= 2; i++) std::cout<<f1[i].first<<" ";
        std::cout<<"\n";
        for(int i(0); i <= 2; i++) std::cout<<f1[i].second<<" ";
        std::cout<<"\n";
    }
    catch(std::range_error r)
    {
        std::cout<<r.what();
    }
	return 0;
}
