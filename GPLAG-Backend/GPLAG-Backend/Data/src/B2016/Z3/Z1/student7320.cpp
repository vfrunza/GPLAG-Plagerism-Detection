/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <functional>
#include <vector>
#include <cmath>
#include <stdexcept>

#define pb push_back
#define mp std::make_pair
#define ff first
#define ss second
const double eps = 0.000000001;
int Stepen(int a, int b) {
  if (b % 2 != 0) return a;
  else return -a;
}
std::vector<double> FormirajWove(std::vector<std::pair<double, double> > vect, int d) {
  std::vector<double> w;
  int n = vect.size();
  for(int i = 1; i <= n; i++) {
    double suma = 0;
    for (int k = std::max(1, i - d); k <= std::min(i, n - d); k++) {
      double proizvod = 1;
      for (int j = k; j <= k + d; j++)
        if (i != j)
          proizvod *= (1 / (vect[i-1].ff - vect[j-1].ff));
      proizvod *= Stepen(-1, k - 1);
      suma += proizvod;
    }
    w.pb(suma);
    //std::cout << suma << " ";
  }
  return w;
}
std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double, double> > vect, int d) {
  if (d < 0 || d > vect.size()) throw std::domain_error("Nedozvoljen red");
  for (int i = 0; i < vect.size(); i++) {
    for (int j = 0; j < vect.size(); j++)
      if (i != j && fabs(vect[i].ff - vect[j].ff) < eps) throw std::domain_error("Neispravni cvorovi");
  }
  std::vector<double> w = FormirajWove(vect, d);
  return [w, vect](double x) {
    double brojnik = 0, nazivnik = 0;
    int n = vect.size();
    for (int i = 0; i < n; i++) {
      if (fabs(x - vect[i].ff) > eps) {
        brojnik += (w[i] / (x - vect[i].ff) * vect[i].ss);
        nazivnik += w[i] / (x - vect[i].ff);
      }
      else return vect[i].ss;
    }
    return brojnik / nazivnik;
  };
}
std::function<double(double)> BaricentricnaInterpolacija(double Fun(double), double xmin, double xmax, double deltax, int d) {
  if (xmin > xmax || deltax < 0 || d < 0) throw std::domain_error("Nekorektni parametri");
  double currVal = xmin;
  std::vector<std::pair<double, double> > vect;
  for (int i = 0;;i++) {
      if (currVal > xmax) break;
      else vect.pb(mp(currVal, Fun(currVal)));
      currVal += deltax;
  }
  std::vector<double> w = FormirajWove(vect, d);
  return [w, vect](double x) {
    double brojnik = 0, nazivnik = 0;
    int n = vect.size();
    for (int i = 0; i < n; i++) {
      if (fabs(x - vect[i].ff) > eps) {
        brojnik += (w[i] / (x - vect[i].ff) * vect[i].ss);
        nazivnik += w[i] / (x - vect[i].ff);
      }
      else return vect[i].ss;
    }
    return brojnik / nazivnik;
  };
}
int main() {
  while (1) {
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): "; int query; std::cin >> query;
    if (query == 1) {
      std::cout << "Unesite broj cvorova: "; int n; std::cin >> n;
      std::cout << "Unesite cvorove kao parove x y: "; std::vector<std::pair<double, double> > vect; 
      std::pair<double, double> tmp;
      for (int i = 0; i < n; i++) {
        std::cin >> tmp.ff >> tmp.ss;
        vect.pb(tmp);
      }
      std::cout << "Unesite red interpolacije: "; int d; std::cin >> d;
      try {
        auto f = BaricentricnaInterpolacija(vect, d);
      	while (1) {
      	  std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
      	  double argu; std::cin >> argu;
      	  if (!std::cin) return 0;
      	  else std::cout << "f(" << argu << ") = " << f(argu) << "\n";
      	}
      }
      catch (std::domain_error c) {
        std::cout << c.what();
        return 0;
      }
    }
    else {
      double xmin, xmax, deltax;
      int d;
      std::cout << "Unesite krajeve intervala i korak: "; std::cin >> xmin >> xmax >> deltax;
      std::cout << "Unesite red interpolacije: "; std::cin >> d;
      try {
        auto g = BaricentricnaInterpolacija([](double A) { return A * A + std::sin(A); }, xmin, xmax, deltax, d);
        while (1) {
          std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
          double argu; std::cin >> argu;
          if (!std::cin) return 0;
          else std::cout << "f(" << argu << ") = " << argu*argu + std::sin(argu) << " fapprox(" << argu << ") = " << g(argu) << "\n";
        }    
      }
      catch (std::domain_error c) {
        std::cout << c.what();
        return 0;
      }
    }
  }
	return 0;
}