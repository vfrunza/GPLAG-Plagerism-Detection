/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <functional>
#include <stdexcept>
#include <vector>
#include <utility>
#include <cmath>

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

bool cmp(double x, double y) {
    return fabs(x - y) < 0.0000001;
}

void TestIstihX(std::vector<std::pair<double, double>> v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            if (cmp(v[i].first, v[j].first)) {
                throw std::domain_error("Neispravni cvorovi");
            }
        }
    }
}

std::vector<double> wGenerator(std::vector<std::pair<double, double>> v, int d) {
    std::vector<double> w(v.size());

    for (int i = 1; i <= v.size(); i++) {
        double suma(0);

        for (int k = max(1, i - d); k <= min(i, v.size() - d); k++) {
            double produkt(1);
            
            for (int j = k; j <= k + d; j++) {
                if (j != i) {
                    produkt *= 1 / (v[i - 1].first - v[j - 1].first);
                }
            }
            
            if ((k - 1) % 2 == 0) {
                suma += produkt;
            } else {
                suma -= produkt;
            }
        }
        
        w[i - 1] = suma;
    }
    
    return w;
}

std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double, double>> v, int d) {
    if (d < 0 || d >= v.size()) {
        throw std::domain_error("Nedozvoljen red");
    }
    
    TestIstihX(v);
    
    std::vector<double> w(wGenerator(v, d));

    return [v, w](double x) -> double {
        double suma1(0), suma2(0);
        
       for (int i = 0; i < v.size(); i++) {
            if (cmp(x, v[i].first)) {
                return v[i].second;
            }

            suma1 += (w[i] * v[i].second) / (x - v[i].first);
            suma2 += w[i] / (x - v[i].first);
        }
        
        return suma1 / suma2;
    };
}

std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> f, double xmin, double xmax, double deltax, int d) {
        if (xmin > xmax || deltax <= 0) {
            throw std::domain_error("Nekorektni parametri");
        }
    
        std::vector<std::pair<double, double>> cvorovi;
        
        for (double x = xmin; x <= xmax; x += deltax) {
            cvorovi.push_back({x, f(x)});
        }
        
        return BaricentricnaInterpolacija(cvorovi, d);
}

int main () {
    std::vector<std::pair<double, double>> v({{1, 3}, {2, 5}, {4, 4}, {5, 2}, {7, 1}});
    int d(2);
    
    std::cout << BaricentricnaInterpolacija(v, d)(4);
	return 0;
}