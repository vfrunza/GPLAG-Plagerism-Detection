/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <cmath>

std::function<double(double)> BaricentricnaInterpolacija (std::vector<std::pair<double, double>> v, int d) {
    int n(v.size());
    bool ok(true);
    
    if (d < 0 || d >= n) {
        throw std::domain_error("Nedozvoljen red");
    }
    
    for (int i(0); i < n-1; i++) {
        for (int j(i+1); j < n; j++) {
            if (fabs(v[i].first - v[j].first) < 0.0001) {
                ok = false;
                break;
            }
        }
    }
    
    if (!ok) {
        throw std::domain_error("Neispravni cvorovi");
    }
        
    return [v, d, n] (double x) {
    
        double a(0), b(0), w, proizvod, x_i, y_i;
        
        for (int i(1); i <= n; i++) {
            w = 0;
            x_i = v[i-1].first;
            y_i = v[i-1].second;
            
            if (fabs(x - x_i) < 0.0001) {
                return y_i;
            }
            
            for (int j(std::max(1, i-d)); j <= std::min(i, n-d); j++) {
                proizvod = 1;
                for (int k = j; k <= j+d; k++) {
                    if (k != i) {
                        proizvod *= 1 / (x_i - v[k-1].first);
                    }
                }
                w += pow(-1, j-1) * proizvod;
            }
            a += y_i * w / (x - x_i);
            b += w / (x - x_i);
        }
        return a/b;
    };
}

std::function<double(double)> BaricentricnaInterpolacija (std::function<double(double)> f, double x_min, double x_max, double x_delta, int d) {
    if (x_min > x_max || x_delta <= 0) {
        throw std::domain_error("Nekorektni parametri”");
    }
    
    std::vector<std::pair<double, double>> v;
    for (double i(x_min); i <= x_max; i += x_delta) {
        v.push_back(std::make_pair(i, f(i)));
    }
    return BaricentricnaInterpolacija(v, d);
}

int main () {
    
    try {
        int izbor;
        std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        std::cin >> izbor;
        if (izbor == 1) { //unos zvorova
            int n;
            std::cout << "Unesite broj cvorova: ";
            std::cin >> n;
            std::vector<std::pair<double, double>> cvorovi;
            std::cout << "Unesite cvorove kao parove x y: ";
            for (int i = 0; i < n; i++) {
                double x, y;
                std::cin >> x >> y;
                cvorovi.push_back(std::make_pair(x, y));
            }
            int d;
            std::cout << "Unesite red interpolacije: ";
            std::cin >> d;
            auto f(BaricentricnaInterpolacija(cvorovi, d));
            while (true) {
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                double x;
                std::cin >> x;
                if (!std::cin) {
                    break;
                }
                std::cout << "f(" << x << ") = " << f(x) << std::endl;
            }
        } else { //aproksimacija
            double x_min, x_max, x_delta, x;
            std::cout << "Unesite krajeve intervala i korak: ";
            std::cin >> x_min >> x_max >> x_delta;
            int d;
            std::cout << "Unesite red interpolacije: ";
            std::cin >> d;
            auto f1([](double x) -> double{ return x * x + std::sin(x); });
            auto f2(BaricentricnaInterpolacija(f1, x_min, x_max, x_delta, d));
            while (true) {
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                std::cin >> x;
                if (!std::cin) {
                    break;
                }
                std::cout << "f(" << x << ") = " << f1(x) << " fapprox(" << x << ") = " << f2(x) << std::endl;
            }
        }
    }
    catch (std::domain_error e) {
        std::cout << e.what() << std::endl;
    }
	return 0;
}