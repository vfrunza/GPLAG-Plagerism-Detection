#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <cmath>
#include <stdexcept>

std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double, double>> vektor, int d) {
   if(d < 0 || d >= vektor.size()) throw std::domain_error ("Nedozvoljen red");
  for(int i = 0; i < vektor.size(); i++) {
      for(int k = 0; k < vektor.size(); k++) {
          if(i == k) continue;
          if(vektor[i].first == vektor[k].first) throw std::domain_error ("Neispravni cvorovi");
      }
  }
   return [vektor, d] (double x) -> double {
    double p = 1;
    std::vector<double> W(vektor.size(), 0);
    int l = vektor.size();
    for(int i(1); i <= vektor.size(); i++) {
        for(int k(std::max(1, i-d)); k <= std::min(i, l - d); k++) {
            p = 1;
            for(int j(k); j <= k + d; j++) {
                if(i == j) continue;
                p = p * (1/(vektor[i - 1].first - vektor[j-1].first));
            }
            W[i-1] = W[i-1] + std::pow(-1, k-1) * p;
        }
    }
    
    double funkcija, suma (0), suma2(0);
    for(int i(0); i < vektor.size(); i++) {
        if(x == vektor[i].first) return vektor[i].second;
        suma += (W[i]/(x - vektor[i].first)) * vektor[i].second;
        suma2 += (W[i]/(x - vektor[i].first));
    }
    funkcija = suma/suma2;
};
}

std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> funkcija, double xmin, double xmax, double deltax, int d) {
    if((xmin > xmax) || (deltax <= 0)) throw std::domain_error ("Nekorektni parametri");
    std::vector<std::pair<double, double >> vektor;
    while(xmin <= xmax) {
      std::pair<double, double>  s = std::make_pair(xmin, funkcija(xmin));
        vektor.push_back(s);
        xmin += deltax;
    }
    return BaricentricnaInterpolacija(vektor, d);
}
int main () {
    while(1) {
   int n;
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin >> n;
    if(n == 1) {
        int d;
        std::vector<std::pair<double, double>> vektor;
        std::cout << "Unesite broj cvorova: ";
        std::cin >> d;
        std::cout << "Unesite cvorove kao parove x y: ";
        for(int i(0); i < d; i++) {
            int br, br1;
            std::cin >> br >> br1;
            vektor.push_back(std::make_pair(br, br1));
        }
        std::cout << "Unesite red interpolacije: ";
        int r;
        std::cin >>r;
        while(1) {
            std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
            double arg;
            std::cin >> arg;
            if(!std::cin) {
                std::cin.clear();
                std::cin.ignore(10000, '\0');
                return 0;
            }
            try {
                auto funkcija = BaricentricnaInterpolacija(vektor, r);
                double konacno = funkcija(arg);
                std::cout << "f("<<arg<<") = "<< konacno<< std::endl;
            }
            catch(std::domain_error Izuzetak) {
                std::cout <<Izuzetak.what()<< std::endl;
                return 0;
            }
        }
    }
    else if(n == 2) {
        std::cout << "Unesite krajeve intervala i korak: ";
        double xmin, xmax, deltax;
        std::cin >> xmin >> xmax >> deltax;
        std::cout << "Unesite red interpolacije: ";
        int r;
        std::cin >> r;
        while(1) {
            std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
            double arg;
            std::cin >> arg;
            if(!std::cin) {
                std::cin.clear();
                std::cin.ignore(10000, '\0');
                return 0;
            }
            try {
                std::function<double(double)> funkcija2 = BaricentricnaInterpolacija([] (double x) { return std::pow(x, 2) + std::sin(x); }, xmin, xmax, deltax, r);
                double konacno = funkcija2(arg);
                std::cout << "f("<<arg<<") = "<< std::pow(arg,2) +std::sin(arg) << " fapprox("<<arg<<") = " << konacno << std::endl;
            }
            catch (std::domain_error Izuzetak) {
                std::cout << Izuzetak.what() << std::endl;
                return 0;
            }
            }
    }
    }
	return 0;
}