/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)

#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <cmath>

std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double, double>> v, int d) {
    if(d < 0 || d > v.size()) throw std::domain_error("Nedozvoljen red");
     return [v, d](double x) -> double {
        double prva_suma(0), druga_suma(0);
        for(int i(1); i <= v.size(); i++) {
            int donja_granica_sume, gornja_granica_sume;
        if(i - d < 1) donja_granica_sume = 1;
        else donja_granica_sume = i - d;
        if(i < v.size() - d) gornja_granica_sume = i;
        else gornja_granica_sume = v.size() - d;
        
        double w(0);
        for(int k(donja_granica_sume); k <= gornja_granica_sume; k++) {
            double proizvod(1);
            for(int j(k); j <= k + d; j++)
                if(j != i) proizvod *= 1. / (v[i - 1].first - v[j - 1].first);
            w += std::pow(-1, k - 1) * proizvod;
        }
            const double Eps(1e-10);
            if(std::abs(x - v[i - 1].first) < Eps) return v[i - 1].second;
            else {
                prva_suma += (w * v[i - 1].second * 1.) / (x - v[i - 1].first);
                druga_suma += (w * 1.) / (x - v[i - 1].first);
            }
        }
            return(prva_suma / druga_suma);
    };
}

std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> f, double x_min, double x_max, double delta_x, double d) {
    if(x_min > x_max || delta_x <= 0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double, double>> cvorovi;
    int i(0);
    while(x_min + i * delta_x <= x_max) {
        cvorovi.push_back(std::make_pair(x_min + i * delta_x, f(x_min + i * delta_x)));
        i++;
    }
    return BaricentricnaInterpolacija(cvorovi, d);
}

int main ()
{
    try {
        std::vector<std::pair<double, double>> v;
        std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        int opcija;
        std::cin >> opcija;
        if(opcija == 1) {
            std::cout << "Unesite broj cvorova: ";
            int n;
            std::cin >> n;
            std::cout << "Unesite cvorove kao parove x y: ";
            for(unsigned int i(0); i < n; i++) {
                int x, y;
                std::cin >> x >> y;
                v.push_back(std::make_pair(x, y));
            }
            std::cout << "Unesite red interpolacije: ";
            int d;
            std::cin >> d;
            auto f(BaricentricnaInterpolacija(v, d));
            std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
            double argument;
            while(std::cin >> argument) {
                std::cout << "f(" << argument << ") = " << f(argument) << std::endl;
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
            }
            
        }
        if(opcija == 2) {
            std::cout << "Unesite krajeve intervala i korak: ";
            double x_min, x_max, delta_x;
            std::cin >> x_min >> x_max >> delta_x;
            std::cout << "Unesite red interpolacije: ";
            int d;
            std::cin >> d;
            auto g(BaricentricnaInterpolacija([](double x) { return x * x + std::sin(x); }, x_min, x_max, delta_x, d));
            std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
            double argument;
            while(std::cin >> argument) {
                std::cout << "f(" << argument << ") = " << argument * argument + std::sin(argument) << " fapprox(" << argument << ") = ";
                std::cout << g(argument) << std::endl;
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
            }
        }
    }
    catch(std::domain_error izuzetak) {
        std::cout << izuzetak.what();
    }
	return 0;
}