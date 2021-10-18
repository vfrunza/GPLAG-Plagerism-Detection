/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)

#include <iostream>
#include <algorithm>
#include <cmath>
#include <functional>
#include <unordered_set>
#include <stdexcept>
#include <vector>
#include <utility>

double test(double x) 
{
    return x*x + std::sin(x);
}

double Wi (std::vector<std::pair<double,double>> v1,int d,int i)
{

    double suma(0);

    for (int k = (1 >= (i-d) ? 1 : i-d); k <= (i < (v1.size()-d) ? i : (v1.size()-d)); k++) {
        double p(1);
        for (int j = k; j <= k+d; j++) {
            if (i == j) continue;

            p *= 1./(v1[i-1].first-v1[j-1].first);
        }
        p *= std::pow(-1,k-1);
        suma += p;
    }

    return suma;
}

std::function<double(double)> BaricentricnaInterpolacija (std::vector<std::pair<double,double>> v1,int d)
{
    if (d < 0 or d> v1.size()) throw std::domain_error("Nedozvoljen red");
    std::unordered_set<double> s;
    for (auto &i : v1) {
        s.insert(i.first);
    }
    if (s.size() != v1.size()) throw std::domain_error("Neispravni cvorovi");
    std::vector<double> W(0);
    for (int i = 1; i <= v1.size(); i++) {
        W.push_back(Wi(v1,d,i));
    }
    
    return [v1,W,d](double x) {
        for (auto i : v1) {
            if(x == i.first) return i.second;
        }
        double suma1(0);
        for (int i = 1; i <= v1.size(); i++) {
            suma1+= (W[i-1]*v1[i-1].second)/double((x-v1[i-1].first));
        }
        double suma2(0);
        for (int i = 1; i <= v1.size(); i++) {
            suma2+= (W[i-1])/(x-v1[i-1].first);
        }
        return suma1/suma2;
    };
}

std::function<double(double)> BaricentricnaInterpolacija (std::function<double(double)> f,double Xmin, double Xmax, double dX,int d)
{
    if (Xmin > Xmax or dX <= 0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> v1;
    auto t(Xmin);
    while (Xmax > Xmin) {
        v1.push_back({Xmin,f(Xmin)});
        Xmin +=dX;
    }
    
    return BaricentricnaInterpolacija(v1,d);
}

int main ()
{
    int t(0);
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin >> t;
    try {
        if(t == 1) {
            int n;
            std::cout << "Unesite broj cvorova: ";
            std::cin >> n;
            std::cout << "Unesite cvorove kao parove x y: ";
            std::vector<std::pair<double,double>> v1(n);
            for (auto &i : v1) {
                std::cin >> i.first >> i.second;
            }
            std::cout << "Unesite red interpolacije: ";
            int d;
            std::cin >> d;
            auto fun(BaricentricnaInterpolacija(v1,d));
            while (1) {
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                double x;
                std::cin >> x;
                if (!std::cin) break;
                std::cout << "f(" <<x <<") = " <<fun(x) << std::endl;
            }
        } else if (t == 2) {
            std::cout << "Unesite krajeve intervala i korak: ";
            double Xmax,Xmin,dX;
            std::cin >> Xmin >> Xmax >>dX;
            std::cout << "Unesite red interpolacije: ";
            int d;
            std::cin >> d;
            auto fun(BaricentricnaInterpolacija(test,Xmin,Xmax,dX,d));
            while (true) {
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                double x;
                std::cin >> x;
                if (!std::cin) break;
                std::cout << "f(" << x << ") = " << test(x) << " fapprox(" <<x <<") = " <<fun(x) << std::endl;
            }
        }
    } catch (std::domain_error izuzetak) {
        std::cout << izuzetak.what() << std::endl;
    }
    return 0;
}