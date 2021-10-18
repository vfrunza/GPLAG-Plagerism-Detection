/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <utility>
#include <stdexcept>
#include <algorithm>
#include <functional>
#include <string>
#include <cmath>

std::function<double(double)> LinearnaInterpolacija (std::vector<std::pair<double, double>> v) {
    
    std::sort (v.begin(), v.end(), [](std::pair<double, double> p1, std::pair<double, double> p2) {return p1.first < p2.first;});
    
    for (int i = 1; i < v.size(); i++) if(v[i].first == v[i-1].first) throw std::domain_error ("Neispravni cvorovi");
    
    std::function<double(double)> f = [v](double x)->double {
        
        double brojnik, nazivnik;
        if (x < v[0].first || x > v[v.size()-1].first) throw std::range_error ("Argument izvan opsega");
        auto it = lower_bound(v.begin(), v.end(), std::pair<double,double>(x,0))-1;
            double rez (0);
            brojnik = ((it+1)->second - it->second)*(x-it->first);
            nazivnik = ((it+1)->first - it->first);
            rez += it->second + (brojnik/nazivnik);
            
        return rez;
    };

    return f;    
}

std::function <double(double)> LinearnaInterpolacija(double fun (double), double x_min, double x_max, double delta_x) {
    
    std::vector<std::pair<double, double>> vp;
    if (x_min > x_max || delta_x <= 0) throw std::domain_error ("Nekorektni parametri");
    while (x_min <= x_max) {
        
        vp.push_back({x_min, fun(x_min)});
        x_min += delta_x;
    }
    try {
        auto f=LinearnaInterpolacija(vp);
        return f;
    }
    catch(...) {
        throw;
    }
}
int main ()
{
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int opt;
    std::cin >> opt;
    if (opt == 1) {
        std::cout << "Unesite broj cvorova: ";
        int brojac;
        std::cin >> brojac;
        std::vector<std::pair<double, double>> v (brojac);
        std::cout << "Unesite cvorove kao parove x y: ";
        for (int i=0; i < brojac; i++) {
            std::cin >> v[i].first >> v[i].second;
        }
    try {
        auto f(LinearnaInterpolacija(v));
        for (;;) {
            std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
            double argument;
            if(!(std::cin >> argument)) break;
            std::string s;
            std::getline(std::cin, s);
            try {
            if (s.size() != std::count (s.begin(), s.end(), ' ')) break;
            std::cout << "f("<<argument<<") = " << f(argument) << "\n";
            }
            catch (std::range_error r) {
                std::cout << r.what();
                std::cout << std::endl;
            }
        }
    }
    catch (std::domain_error izuzetak) {
        std::cout << izuzetak.what();
    }
    
    }
    else if (opt == 2) {
        std::cout << "Unesite krajeve intervala i korak: ";
        double min, max, korak;
        std::cin >> min >> max >> korak;
        auto fun = [] (double x) {return x*x+std::sin(x);};
        try {
            auto f(LinearnaInterpolacija(fun, min, max, korak));
            for(;;) {
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                double argument;
                if(!(std::cin >> argument)) break;
                std::string s;
                std::getline (std::cin, s);
                try {
                if (s.size() != std::count (s.begin(), s.end(), ' ')) break;
                std::cout << "f("<<argument<<") = " << fun(argument) << " fapprox("<<argument<<") = "<<f(argument)<<"\n";
                }
                catch (std::range_error r) {
                    std::cout << r.what();
                    std::cout << std::endl;
                }
            }
        }
        catch (std::domain_error izuzetak) {
            std::cout << izuzetak.what();
        }
    }
    return 0;
}
