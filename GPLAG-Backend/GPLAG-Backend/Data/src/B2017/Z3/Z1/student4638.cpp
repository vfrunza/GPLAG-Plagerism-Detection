/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include<functional>
#include <utility>
#include <cmath>
#include <stdexcept>

bool Jednako(double x, double y) {
 const double eps(1e-15);
 if((x < 0 && y > 0) || (x > 0 && y < 0)) return false;
 return std::fabs(x - y) <= eps * (std::fabs(x) + std::fabs(y));
}

std::function< double(double) > LinearnaInterpolacija(std::vector<std::pair<double,double>> &v) {
     std::sort(v.begin(),v.end(), [] (const std::pair<double, double> &prvi, const std::pair<double, double> &drugi) { if(prvi.first < drugi.first) return true;
                                                                                                                       return false; } );
     for(int i(0); i < v.size(); i++) {
      for(int j(i + 1); j < v.size(); j++) {
       if(Jednako(v.at(i).first, v.at(j).first)) throw std::domain_error("Neispravni cvorovi");
      }
     }
    return [v] (double x) {
           if(x < v.at(0).first || x > v.at(v.size() - 1).first) throw std::range_error("Argument izvan opsega");
           
           if(Jednako(v.at(v.size() - 1).first, x)) return v.at(v.size() - 1).second;
           
           std::pair<double, double> prviPar, drugiPar;
           for(int i(0); i < v.size(); i++) {
            if((v.at(i).first >= x) || Jednako(v.at(i).first, x)) {
             prviPar = v.at(i - 1);
             drugiPar = v.at(i);
             break;
            }
           }
           
           return prviPar.second + ((drugiPar.second-prviPar.second)/(drugiPar.first-prviPar.first))*(x-prviPar.first);
    };
}

std::function<double(double)> LinearnaInterpolacija(std::function<double(double)> f,double xmin,double xmax,double deltax) {
  if(((xmin > xmax) && !Jednako(xmin, xmax)) || ((deltax <= 0) || Jednako(deltax, 0))) throw std::domain_error("Nekorektni parametri");
  std::vector<std::pair<double,double>> v1;
  double x = xmin;
  while(x <= xmax || Jednako(x, xmax)) {
   v1.push_back(std::make_pair(x, f(x)));
   x += deltax;
  }
  return LinearnaInterpolacija(v1);
}

double fun(double x) {
 return x*x+std::sin(x);
}

int main() {
 std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
 int m;
 std::cin>>m;
 if (m==1) {
  std::cout<<"Unesite broj cvorova: ";
  int n;
  std::cin>>n;
  std::vector<std::pair<double, double>> vektor;
  std::cout<<"Unesite cvorove kao parove x y: ";
  for(int i(0); i < n; i++) {
   double x, y;
   std::cin >> x >> y;
   std::pair<double, double> par = std::make_pair(x, y);
   vektor.push_back(par);
  }
  std::function<double(double)> funkcija;
  try {
   funkcija = LinearnaInterpolacija(vektor);
  }
  catch(std::domain_error izuzetak) {
   std::cout << izuzetak.what();
   return 0;
  }
  for(;;) {
   std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
   double x;
   std::cin >> x;
   if(!std::cin || std::cin.peek() != '\n') break;
   try {
    std::cout << "f(" << x << ") = " << funkcija(x) << std::endl;
   }
   catch(std::range_error izuzetak) {
    std::cout << izuzetak.what() << std::endl;
   }
  }
 }
 else if(m == 2) {
  std::cout<<"Unesite krajeve intervala i korak: ";
  double xmin, xmax, deltax;
  std::cin >> xmin >> xmax >> deltax;
  std::function<double(double)> funkcija;
  try {
   funkcija = LinearnaInterpolacija(fun, xmin, xmax, deltax);
  }
  catch(std::domain_error izuzetak) {
   std::cout << izuzetak.what();
   return 0;
  }
  for(;;) {
   std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
   double x;
   std::cin >> x;
   if(!std::cin || std::cin.peek() != '\n') break;
   try {
    std::cout << "f(" << x << ") = " << fun(x) << " fapprox(" << x << ") = " << funkcija(x) << std::endl;
   }
   catch(std::range_error izuzetak) {
    std::cout << izuzetak.what() << std::endl;
   }
  }
 }
 return 0;
}