/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <functional>
#include <stdexcept>
#include <algorithm>
#include <cmath>

double fun(double x) {
    return x*x + std::sin(x);
}

std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double, double>> vp) {
    for(int i = 0; i < (int) vp.size() - 1; i++) 
        for(int j = i+1; j < vp.size(); j++)
            if(vp.at(i).first == vp.at(j).first) throw std::domain_error("Neispravni cvorovi");
    
    std::sort(vp.begin(), vp.end(), [](const std::pair<double, double> &a, const std::pair<double, double> &b) {
        return a.first < b.first;
    });
    
   return [vp](double x) -> double {
       if(x < vp[0].first || x > vp[vp.size()-1].first) throw std::range_error("Argument izvan opsega");
       auto it = std::lower_bound(vp.begin(), vp.end(), std::pair<double,double>{x,0});
       if(it->first == x) return it->second;
       int ind = std::distance(vp.begin(), it) - 1;
       return vp[ind].second + (vp[ind+1].second - vp[ind].second)*(x - vp[ind].first) / (vp[ind+1].first - vp[ind].first);
   };
}

std::function<double(double)> LinearnaInterpolacija(std::function<double(double)> f, double xmin, double xmax, double dx) {
    if(xmin > xmax || dx <= 0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double, double>> vp;
    while(xmin <= xmax) {
        vp.push_back(std::pair<double,double>{xmin, f(xmin)});
        xmin += dx;
    }
    return LinearnaInterpolacija(vp);
}

int main ()
{
    try {
        int opcija = 0;
        std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        std::cin >> opcija;
        if(opcija == 1) {
            int brCvorova = 0;
            std::cout << "Unesite broj cvorova: ";
            std::cin >> brCvorova;
            std::cout << "Unesite cvorove kao parove x y: ";
            std::vector<std::pair<double,double>> vp;
            for(int i = 0; i < brCvorova; i++) {
                double x, y;
                std::cin >> x >> y;
                vp.push_back(std::pair<double,double>{x,y});
            }
            auto f = LinearnaInterpolacija(vp);
            for(;;) {
                    double argument = 0;
                    std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                    std::cin >> argument;
                    if(!std::cin) break;
                    try{
                        std::cout << "f(" << argument << ") = " << f(argument) << "\n";
                    }
                    catch(std::range_error e) {
                        std::cout << e.what() << "\n";
                    } 
            }
        }
        if(opcija == 2) {
            double xmin = 0, xmax = 0, dx = 0;
            std::cout << "Unesite krajeve intervala i korak: ";
            std::cin >> xmin >> xmax >> dx;
            auto f = LinearnaInterpolacija(fun, xmin, xmax, dx);
            for(;;) {
                double argument = 0;
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                std::cin >> argument;
                if(!std::cin) break;
                try{
                    std::cout << "f(" << argument << ") = " << fun(argument) << " fapprox(" << argument << ") = " << f(argument) << "\n"; 
                }
                catch(std::range_error e) {
                    std::cout << e.what() << "\n";
                }
            }
            
        }
    }
    catch(std::domain_error e) {
        std::cout << e.what() << "\n";
    }
   	return 0;
}
