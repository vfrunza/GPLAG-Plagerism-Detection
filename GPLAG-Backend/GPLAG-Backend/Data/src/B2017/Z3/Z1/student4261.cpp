/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>
#include <stdexcept>
#include <cmath>
#include <new>


double funkcija (double x) { return x*x+std::sin(x); }

bool NijeSortiran (std::vector<std::pair<double, double>> v) {
    for (int i=0; i<v.size()-1; i++) {
        if (v.at(i).first>v.at(i+1).first) return true;
    }
    return false;
}
bool ImaJednakih (std::vector<std::pair<double, double>> v) {
    for (int i=0; i<v.size()-1; i++) {
        if (std::fabs(v.at(i).first-v.at(i+1).first)<0.000001) return true;
    }
    return false;
}

std::function<double(double)> LinearnaInterpolacija (std::vector<std::pair<double, double>> cvorovi) {
    
    if (cvorovi.size()) if (NijeSortiran(cvorovi)) std::sort(cvorovi.begin(), cvorovi.end(), [](std::pair<double, double> x1, std::pair<double, double> x2){ return x1.first<x2.first; });
    if (cvorovi.size()) if (ImaJednakih(cvorovi)) throw std::domain_error("Neispravni cvorovi");
    
    return [cvorovi] (double x) {
        
        if (cvorovi.size()==0) throw std::range_error("Argument izvan opsega");
        if (x<(*cvorovi.begin()).first || x>(*(cvorovi.end()-1)).first) throw std::range_error("Argument izvan opsega");
        
        auto par(std::make_pair(x, 0));
        
        auto it(std::upper_bound(cvorovi.begin(), cvorovi.end(), par,  [](std::pair<double, double> x1, std::pair<double, double> x2){ return x1.first<x2.first; }));
        
        if (it==cvorovi.end()) return (*(cvorovi.end()-1)).second;
        
        double x1, x2, y1, y2;
        x2=(*it).first; y2=(*it).second;
        it--;
        x1=(*it).first; y1=(*it).second;
        
        return y1+((y2-y1)/(x2-x1))*(x-x1);
    };
}

std::function<double(double)> LinearnaInterpolacija (double f(double), double x_min, double x_max, double x) {
    
    if (x_min>x_max || x<0.000001) throw std::domain_error("Nekorektni parametri");
    
    std::vector<std::pair<double, double>> cvorovi;
    
    for (double i=x_min; i<x_max+0.0001; i+=x) {
        cvorovi.push_back(std::make_pair(i, f(i)));
    }
    return LinearnaInterpolacija(cvorovi);
}

int main ()
{
    try {
        int opcija, br_cvorova;
        std::function<double(double)> f;
        std::vector<std::pair<double, double>> cvorovi;
        
        std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        std::cin >> opcija;
        double x_min, x_max, korak, argument;
        
        if (opcija==1) {
            double x, y;
            std::cout << "Unesite broj cvorova: "; std::cin >> br_cvorova;
            std::cout << "Unesite cvorove kao parove x y: ";
            for (int i=0; i<br_cvorova; i++) {
                std::cin >> x >> y;
                cvorovi.push_back(std::make_pair(x, y));
            }
            f=LinearnaInterpolacija(cvorovi);
        }
        else if (opcija==2) {
            std::cout << "Unesite krajeve intervala i korak: "; std::cin >> x_min >> x_max >> korak;
            f=LinearnaInterpolacija(funkcija, x_min, x_max, korak);
        }
        for (;;) {
            std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
            std::cin >> argument;
            if (!std::cin) return 0;
            
            try {
                if (opcija==1) std::cout << "f(" << argument << ") = " << f(argument);
                else std::cout << "f(" << argument << ") = " << funkcija(argument) << " fapprox(" << argument << ") = " << f(argument);
            }
            catch (std::range_error &izuzetak) {
                std::cout << izuzetak.what();
            }
            std::cout <<std::endl;
        }
    }
    catch (std::exception &izuzetak) {
        std::cout << izuzetak.what();
    }
    
	return 0;
}
