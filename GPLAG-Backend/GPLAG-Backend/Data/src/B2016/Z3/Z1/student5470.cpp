/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <utility>
#include <functional>
#include <vector>
#include <stdexcept>
#include <cmath>

double suma1 (double x, std::vector<double> w, std::vector<std::pair<double, double>> cvorovi) {
    double suma(0);
    for (int i = 0; i < cvorovi.size(); i++) {
            suma += (w[i] / (x - cvorovi[i].first)) * cvorovi[i].second;
    }
    return suma;
}

double suma2 (double x, std::vector<double> w, std::vector<std::pair<double, double>> cvorovi) {
    double suma(0);
    for (int i = 0; i < cvorovi.size(); i++) {
            suma += w[i] / (x - cvorovi[i].first);
    }
    return suma;
}

std::function<double(double)> BaricentricnaInterpolacija (std::vector<std::pair<double,double>> cvorovi, int d) {
    if(d<0 || d>cvorovi.size()) throw std::domain_error("Nedozvoljen red");
    for (int i=0; i<cvorovi.size(); i++) 
        for (int j = i+1; j < cvorovi.size(); j++)
            if (cvorovi[i].first == cvorovi[j].first) throw std::domain_error("Neispravni cvorovi");
        int n(cvorovi.size());
        std::vector<double> w;
    for (int i = 0; i < n; i++) {
        int min,max;
        if (1 > (i+1-d)) max=0;
        else max=(i-d);
        if (i+1> (n-d)) min=(n-d)-1;
        else min = i;
        double suma(0);
        for (int k = max; k <= min; k++) {
            double proizvod(1);
            for (int j = k; j <=(k+d); j ++) {
                if (i==j) continue;
                proizvod *= (1. / (cvorovi[i].first - cvorovi[j].first));
            }
            suma += (pow(-1, (k-1)) * proizvod);
        }
        w.push_back(suma);
    }
    return [cvorovi, w, n] (double x) { 
        for (int i = 0; i < n; i++)
            if (x == cvorovi[i].first) return cvorovi[i].second;
        return suma1(x,w,cvorovi) / suma2(x,w,cvorovi);
    };
}


std::function<double(double)> BaricentricnaInterpolacija (double f(double), double x_min, double x_max, double delta_x, int d) {
    if ((x_min > x_max) || delta_x <= 0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> cvorovi;
    for (double i = x_min; i < x_max; i+=delta_x) {
        auto par(std::make_pair(i, f(i)));
        cvorovi.push_back(par);
    }
    return BaricentricnaInterpolacija(cvorovi, d);
} 

double pomocna (double x) {
    return x*x+sin(x);
}

int main ()
{  
    try {   
        std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        int opcija;
        std::cin >> opcija;
        if (opcija == 1) {
            std::cout << "Unesite broj cvorova: ";
            int broj_cvorova;
            std::cin >> broj_cvorova;
            std::cout << "Unesite cvorove kao parove x y: ";
            std::vector<std::pair<double,double>> cvorovi(broj_cvorova);
            for (auto &x : cvorovi) std::cin >> x.first >> x.second;
            std::cout << "Unesite red interpolacije: "; 
            int interp;
            std::cin >> interp;
            for (;;) {
                std::cout << "Unesite argument (ili \"kraj\" za kraj): " ;
                double x;
                std::cin >> x;
                if (!std::cin) break;
                std::cout << "f(" << x <<") = " << BaricentricnaInterpolacija(cvorovi, interp)(x) << std::endl;
            }
        }
        if (opcija == 2) {
            std::cout << "Unesite krajeve intervala i korak: ";
            double min, max, korak;
            std::cin >> min >> max >> korak;
            std::cout << "Unesite red interpolacije: ";
            int interp;
            std::cin >> interp;
            for (;;) {
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                double x;
                std::cin >> x;
                if (!std::cin) break;
                auto f(BaricentricnaInterpolacija(pomocna, min, max, korak, interp));
               std::cout << "f(" << x <<") = " << pomocna(x) << 
                " fapprox(" << x << ") = " << f(x) << std::endl;            
            }
        }
    }
    catch (std::domain_error e) {
        std::cout << e.what();
    }
	return 0;
}