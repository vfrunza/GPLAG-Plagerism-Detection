#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <stdexcept>
#include <algorithm>
#include <cmath>

typedef std::pair<double, double> Par;

bool JesuLiJednaki(double x, double y, double Eps = 1e-10) {
    return fabs(x - y) <= Eps * (fabs(x) + fabs(y));
}

std::function<double(double)> LinearnaInterpolacija(std::vector<Par> v) {
    std::sort(v.begin(), v.end(), [](Par a, Par b) {
        if (JesuLiJednaki(a.first, b.first)) throw std::domain_error("Neispravni cvorovi");
        return a.first < b.first; 
    });
    return [v] (double x) {
        if (v.empty() || x < v[0].first || x > v[v.size()-1].first)
            throw std::range_error("Argument izvan opsega");
        Par nepoznati {x, 0}; 
        auto xi1(std::upper_bound(v.begin(), v.end(), nepoznati,
            [](Par a, Par b) { return a.first < b.first; }));
        if (xi1 == v.end()) return v[v.size()-1].second;
        auto xi(xi1-1);
        return xi->second + (xi1->second - xi->second)*(x - xi->first)/(xi1->first - xi->first);
    };
}

std::function<double(double)> LinearnaInterpolacija(std::function<double(double)> f,
    double xmin, double xmax, double dx) {
        if (xmin > xmax || dx <= 0) throw std::domain_error("Neispravni parametri");
        std::vector<Par> v;
        do {
            v.push_back({xmin, f(xmin)});
            xmin += dx;
        } while (xmin < xmax || JesuLiJednaki(xmin, xmax));
        return LinearnaInterpolacija(v);
    }

int main ()
{
    try {
        int opcija;
        std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        std::cin >> opcija;
        if (opcija == 1) {
            int n;
            std::cout << "Unesite broj cvorova: ";
            std::cin >> n;
            std::vector<Par> v(n);
            std::cout << "Unesite cvorove kao parove x y: ";
            for (auto &a : v) std::cin >> a.first >> a.second;
            auto f(LinearnaInterpolacija(v));
            double x;
            do {
                std::cout << "Unesite argument (ili \"kraj\" za kraj): "; 
                if (!(std::cin >> x) || std::cin.peek() != '\n') return 0;
               try {
                   std::cout << "f(" << x << ") = " << f(x) << std::endl;
               }
               catch (std::range_error e) {
                   std::cout << e.what() << std::endl;
               }
            } while (1);
        }
        else if (opcija == 2) {
            double kraj1, kraj2, korak;
            std::cout << "Unesite krajeve intervala i korak: ";
            std::cin >> kraj1 >> kraj2 >> korak;
            auto f(LinearnaInterpolacija([](double x){ return x*x + sin(x); }, 
                kraj1, kraj2, korak));
            double x;
            do {
                std::cout << "Unesite argument (ili \"kraj\" za kraj): "; 
                if (!(std::cin >> x) || std::cin.peek() != '\n') return 0;
               try {
                   std::cout << "f(" << x << ") = " << x*x + sin(x) 
                   << " fapprox(" << x << ") = " << f(x) << std::endl;
               }
               catch (std::range_error e) {
                   std::cout << e.what() << std::endl;
               }
            } while (1);
        }
    }
    catch (std::domain_error e) {
        std::cout << e.what();
    }
    catch (...) {
    }
	return 0;
}
