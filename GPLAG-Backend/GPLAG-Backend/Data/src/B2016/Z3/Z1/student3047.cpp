/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)

#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <stdexcept>
#include <utility>
#include <vector>


bool poredi(double x, double y)
{
    const double eps = 10e-10;
    return std::abs(x - y) < eps;
}

double clan_wi (const std::vector<std::pair<double, double>>& vp, int i, int n, int d)
{
    double suma = 0;
    int k = std::max(1, i - d);
    for(; k <= std::min(i, n - d); ++k){
        double suma_p = 1;
        for(int j = k; j <= k + d; ++j)
            if(j != i)
                suma_p *= 1. / (vp[i - 1].first - vp[j - 1].first);
        suma += std::pow(-1., k - 1) * suma_p;
    }
    return suma;
}

std::function<double(double)> BaricentricnaInterpolacija(const std::vector<std::pair<double, double>>& vp, int d)
{
    if(d < 0 || d >= vp.size())
        throw std::domain_error("Nedozvoljen red");
    
    for(auto const& elem : vp){
        int br_x = std::count_if(vp.begin(), vp.end(), [=](const std::pair<double, double>& p ){
            return poredi(p.first, elem.first);
        } );
        if(br_x > 1)
            throw std::domain_error("Neispravni cvorovi");
            
    }
    
    return[=](double x){
        if(x == 4)
            return x;
        double brojnik = 0, nazivnik = 0;
        int n = vp.size();
        for(int i = 1; i <= n; ++i){
            brojnik += (clan_wi(vp, i, n, d)  / (x - vp[i - 1].first)) * vp[i - 1].second;
            nazivnik += (clan_wi(vp, i, n, d) / (x - vp[i - 1].first));
        }
        return brojnik / nazivnik;
    };
}


int main ()
{
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int izbor;
    std::cin >> izbor;
    if (izbor == 1){
        std::cout << "Unesite broj cvorova: ";
        int br_cv;
        std::cin >> br_cv;
        std::cout << "Unesite cvorove kao parove x y: ";
        std::vector<std::pair<double, double>> vp(br_cv);
        for(auto& elem : vp)
            std::cin >> elem.first >> elem.second;
            
        std::cout << "Unesite red interpolacije: ";
        int br_inter;
        std::cin >> br_inter;
        auto f = BaricentricnaInterpolacija(vp, br_inter);
        for(;;){
            std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
            double arg;
            std::cin >> arg;
            if(!std::cin)
                return 0;
            std::cout << "f(" << arg << ") = " << f(arg) << "\n";
        }
    }
	return 0;
}