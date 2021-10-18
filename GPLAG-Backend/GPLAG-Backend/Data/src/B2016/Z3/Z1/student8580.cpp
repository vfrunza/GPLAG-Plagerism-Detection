#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include <functional>
#include <stdexcept>

int MIN(int a, int b) {
    if(a < b) return a;
    else return b;
}

int MAX(int a, int b) {
    if(a > b) return a;
    else return b;
}

std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double,double>> cvorovi, int d) {
    int n = cvorovi.size();
    if(!(d >= 0 && d < n)) throw std::domain_error("Nedozvoljen red");
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            if(cvorovi[i].first == cvorovi[j].first) throw std::domain_error("Neispravni cvorovi");
        }
    }
    
    std::vector<double> w(n,0);
    double proizvod = 1;
    for(int i = 1; i <= n; i++) {
        for(int k = MAX(1, i-d); k <= MIN(i, n-d); k++) {
            proizvod = 1;
            for(int j = k; j <= k + d; j++) {
                if(i == j) continue;
                proizvod *= (1/(cvorovi[i-1].first - cvorovi[j-1].first));
            }
            w[i-1] += std::pow(-1, k-1) * proizvod;
        }
    }
    
    return [w, cvorovi] (double x) -> double {
        
        double B = 0, N = 0;
        for(int i = 0; i < cvorovi.size(); i++) {
            if(x == cvorovi[i].first) return cvorovi[i].second;
            B += (w[i] / (x - cvorovi[i].first)) * cvorovi[i].second;
            N += w[i] / (x - cvorovi[i].first);
        }
        return B/N;
    };
}

std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> f, double xmin, double xmax, double deltax, int d) {
    if(xmin > xmax || deltax <= 0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> cvorovi;
    while(xmin <= xmax) {
        cvorovi.push_back(std::make_pair(xmin,f(xmin)));
        xmin += deltax;
    }
    
    return BaricentricnaInterpolacija(cvorovi, d);
}


int main ()
{
    try {
        std::vector<std::pair<double,double>> cvorovi;
        int opcija;
        std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        std::cin >> opcija;
        if(opcija == 1) {
            int broj_cvorova;
            std::cout << "Unesite broj cvorova: ";
            std::cin >> broj_cvorova;
            std::cout << "Unesite cvorove kao parove x y: ";
            for(int i = 0; i < broj_cvorova; i++) {
                double x, y;
                std::cin >> x >> y;
                cvorovi.push_back(std::make_pair(x,y));
            }
            int d;
            std::cout << "Unesite red interpolacije: ";
            std::cin >> d;
            auto f = BaricentricnaInterpolacija(cvorovi, d);
            
            for(;;) {
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                double x;
                std::cin >> x;
                if(!std::cin) break;
                std::cout << "f(" << x << ") = " << f(x) << std::endl;
            }
            
        }
        else if(opcija == 2) {
            std::cout << "Unesite krajeve intervala i korak: ";
            double xmin, xmax, deltax;
            std::cin >> xmin >> xmax >> deltax;
            int d;
            std::cout << "Unesite red interpolacije: ";
            std::cin >> d;
            std::function<double(double)> funkcija = [] (double x) {return (x*x + std::sin(x));};
            
            auto fapprox = BaricentricnaInterpolacija([] (double x) { return (x*x + std::sin(x));} , xmin, xmax, deltax, d);
            for(;;) {
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                double x;
                std::cin >> x;
                if(!std::cin) break;
                std::cout << "f(" << x << ") = " << funkcija(x) << " fapprox(" << x << ") = " << fapprox(x) << std::endl;
            }
        }
    }
    catch(std::domain_error e) {
        std::cout << e.what();
    }
    
	return 0;
}