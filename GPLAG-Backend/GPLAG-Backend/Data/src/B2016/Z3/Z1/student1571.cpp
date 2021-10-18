#include <iostream>
#include <stdexcept>
#include <functional>
#include <utility>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <cstdio>

const double EPS = 0.00001;
std::pair<double,double> kreiraj_par(double x, double y) {
  return std::make_pair (x, y);
}
int max (int x, int y) {
  if (x > y) return x;
  return y;
}
int min (int x, int y) {
  if (x < y) return x;
  return y;
}
double fun (double x) {
  return x*x + std::sin(x);
}
std::function<double(double)> BaricentricnaInterpolacija (std::vector<std::pair<double,double>> vek, double d) {
  if (d < 0 || d >= vek.size()) throw std::domain_error ("Nedozvoljen red");
  int n = (vek.size());
  std::vector<double> vektor_w (n);
  double proizvod(1);
  for (int i=1; i<=n; i++) {
    double suma(0);
    vektor_w[i-1] = 0;
    for (int k=max(1,i-d); k<=min(i,n-d); k++) {
      proizvod = 1.;
      for (int j=k; j<=k+d; j++) {
        if (j != i) {
          if (std::abs(vek[i-1].first - vek[j-1].first) < EPS) throw std::domain_error ("Neispravni cvorovi");
          proizvod /= (vek[i-1].first - vek[j-1].first);
        }
      }
      if (k % 2 == 0) proizvod *= -1;
      suma += proizvod;
    }
    vektor_w[i-1] =  suma;
  }
  return [vek, d, n, vektor_w] (double x) {
    double prva_suma(0), druga_suma(0);
    for (int i=1; i<=n; i++) {
      if (std::abs(x - vek[i-1].first) < EPS) return vek[i-1].second;
      prva_suma += (vektor_w[i-1] / (x - vek[i-1].first)) * vek[i-1].second;
      druga_suma += (vektor_w[i-1] / (x - vek[i-1].first));
    }
    return (prva_suma / druga_suma);
  };
}
std::function<double(double)> BaricentricnaInterpolacija (std::function<double(double)> f, double x_min, double x_max, double d_x, double d) {
  if (x_min > x_max || d_x <= 0) throw std::domain_error ("Nekorektni parametri");
  std::vector<std::pair<double,double>> vek;
  for (double i=x_min; i<=x_max; i=i+d_x) {
    std::pair<double,double> pom;
    pom.first = i;
    pom.second = f(i);
    std::pair<double,double> ubacivanje;
    ubacivanje = kreiraj_par(pom.first, pom.second);
    vek.push_back (ubacivanje);
  }
  auto f_u_n = BaricentricnaInterpolacija(vek, std::abs(d));
  return f_u_n;
}
int main ()
{
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int izbor, n;
    double red;
    std::vector<std::pair<double,double>> vek;
    std::cin >> izbor;
      if (izbor ==1) {
        std::cout << "Unesite broj cvorova: ";
        std::cin >> n;
        vek.resize(n);
        std::cout << "Unesite cvorove kao parove x y: ";  
        double x, y;
        for (int i=0; i<n; i++) {
          std::cin >> x >> y;
          vek[i] = kreiraj_par(x, y);
        }
        std::cout << "Unesite red interpolacije: ";
        std::cin >> red;
        try {
          auto f (BaricentricnaInterpolacija (vek, red));
          double arg;
          std::cin.ignore (10000, '\n');
          do {
            std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
            std::cin >>arg;
            if (!arg) break;
            double vr = f(arg);
            std::cout << "f(" << arg << ") = " << vr << std::endl;
        } while (arg);
      }
      catch (std::domain_error poruka) {
        std::cout << poruka.what();
      }
    }
    else if (izbor == 2) {
      std::cout << "Unesite krajeve intervala i korak: ";
      double korak, poc, kr;
      std::cin >> poc >> kr >> korak;
      std::cout << "Unesite red interpolacije: ";
      double red1;
      std::cin >> red1;
      double arg;
      std::cin.ignore (10000,'\n');
      do {
        std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
        std::cin >> arg;
        if (!arg) break;
        double x = arg;
        try {
          auto f = BaricentricnaInterpolacija ([] (double x) { return x*x+std::sin(x);}, poc, kr, korak, red1);
          double vr = f(x);
          std::cout << "f(" << x << ") = " << fun(x) << " fapprox(" << x << ") = " << vr << std::endl;
        }
        catch (std::domain_error poruka) {
          std::cout << poruka.what();
          return 0;
        }
      } while (arg);
    }
	return 0;
}