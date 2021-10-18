#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <stdexcept>
#include <cmath>
#include <string>

bool Jednaki (double a, double b) {
    return fabs(a - b) < 0.0000001;
}

int max(int a, int b) { 
    if(a >= b) return a;
    return b;
}

int min(int a, int b) {
    if(a <= b) return a;
    return b;
}

double Stepen(double baza, int stepen) {
    double proizvod(1);
    for(int i = 0; i < abs(stepen); i++) proizvod *= baza;
    if(stepen < 0) { proizvod = 1. / proizvod; return proizvod; }
    return proizvod;
}

std::vector<double> IzracunajWeove(std::vector<std::pair<double, double>> cvorovi, int d) {
    std::vector<double> w(cvorovi.size());
    
    for(int i = 0; i < cvorovi.size(); i++) {
        double suma(0);
        for(int k(max(1, i + 1 - d)); k <= min(i + 1, cvorovi.size() - d); k++) {
            double proizvod(1);
            for(int j = k; j <= k + d; j++) {
                if(j - 1 == i) continue;
                proizvod *= 1. / (cvorovi[i].first - cvorovi[j - 1].first);
            }
            proizvod *= Stepen(-1, k - 1);
            suma += proizvod;
        }
        w[i] = suma;
    }
    
    return w;
}

std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double, double>> cvorovi, int d) {
    if(d < 0 || d >= cvorovi.size()) throw std::domain_error("Nedozvoljen red");
    return [cvorovi, d](double x) {
        for(int i = 0; i < cvorovi.size(); i++) {
            for(int j = 0; j < cvorovi.size(); j++) {
                if(i == j) continue;
                if(Jednaki(cvorovi[i].first, cvorovi[j].first)) throw std::domain_error("Neispravni cvorovi");
            }
        }
        
        std::vector<double> w(IzracunajWeove(cvorovi, d));
        
        double brojnik(0), nazivnik(0);
        for(int i = 0; i < cvorovi.size(); i++) {
            if(Jednaki(x, cvorovi[i].first)) return cvorovi[i].second;
            brojnik += ((w[i] * cvorovi[i].second) / (x - cvorovi[i].first));
            nazivnik += (w[i] / (x - cvorovi[i].first));
        }
        
        return brojnik / nazivnik;
    };
}

std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> f, double x_min, double x_max, double x_delta, int d) {
    if(x_min > x_max || x_delta <= 0) throw std::domain_error("Nekorektni parametri");
    
    std::vector<std::pair<double, double>> cvorovi;
    while(x_min <= x_max) {
        cvorovi.push_back(std::make_pair(x_min, f(x_min)));
        x_min += x_delta;
    }
    return BaricentricnaInterpolacija(cvorovi, d);
}

int main() {
    
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int n;
    std::cin >> n;
    
    try {
        if(n == 1) {
            std::cout << "Unesite broj cvorova: ";
            std::cin >> n;
            std::vector<std::pair<double, double>> cvorovi(n);
            std::cout << "Unesite cvorove kao parove x y: ";
            for(int i = 0; i < n; i++) {
                int x, y;
                std::cin >> x >> y;
                cvorovi[i] = std::make_pair(x, y);
            }
            std::cout << "Unesite red interpolacije: ";
            int d;
            std::cin >> d;
            auto f(BaricentricnaInterpolacija(cvorovi, d));
            for(;;) {
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                double x;
                std::cin >> x;
                if(!std::cin) {
                    std::cin.ignore(10000, '\n');
                    std::cin.clear();
                    break;
                }
                std::cout << "f(" << x << ") = " << f(x) << std::endl;
            }
        }
        else {
            std::cout << "Unesite krajeve intervala i korak: ";
            double x_min, x_max, x_delta;
            std::cin >> x_min >> x_max >> x_delta;
            
            std::cout << "Unesite red interpolacije: ";
            int d;
            std::cin >> d;
            for(;;) {
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                double x;
                std::cin >> x;
                if(!std::cin) {
                    std::cin.ignore(10000, '\n');
                    std::cin.clear();
                    break;
                }
                auto f(BaricentricnaInterpolacija([](double x) {return x * x + std::sin(x);}, x_min, x_max, x_delta, d));
                std::cout << "f(" << x << ") = " << x * x + std::sin(x) << " fapprox(" << x << ") = " << f(x) << std::endl;
            }
        }
    }
    catch(std::domain_error izuzetak) { std::cout << izuzetak.what(); }
    
    return 0;
}