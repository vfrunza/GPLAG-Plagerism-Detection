
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <functional>
#include <stdexcept>
#include <cmath>

typedef std::pair<double, double> ParDoublovaT;

double CalculateLinearInterpolation(const std::vector<ParDoublovaT>&  vpd, double x)
{
    if(x < vpd.front().first || x > vpd.back().first){
        throw std::range_error("Argument izvan opsega");
    }
    
    const auto par_i1 = std::upper_bound(vpd.begin(), vpd.end(), std::make_pair(x, 0.));
    const auto par_i = par_i1 - 1;
    
    return par_i->second + ((par_i1->second - par_i->second) / (par_i1->first - par_i->first)) * (x - par_i->first);
}

std::function<double(double)> LinearnaInterpolacija(std::vector<ParDoublovaT> vpd)
{
    std::sort(vpd.begin(), vpd.end());
    constexpr auto Eps = 1e-10;
    
    for(std::size_t i = 0; i < vpd.size() - 1; ++i) {
        if(std::fabs (vpd[i].first - vpd[i + 1].first) < Eps ) {
            throw std::domain_error("Neispravni cvorovi");
        }
    }
    
    return [vpd](double x){
        return CalculateLinearInterpolation(vpd, x);
    };
}

template<typename DoubleLike>
std::function<double(double)> LinearnaInterpolacija(DoubleLike f(DoubleLike), double x_min, double x_max, double dx)
{
    if(x_min > x_max || dx < 0) {
        throw std::domain_error("Nekorektni parametri");
    }
    
    std::vector<ParDoublovaT> vpd;
    
    for(; x_min < x_max; x_min += dx){
        vpd.emplace_back(x_min, f(x_min));
    }
    
   return [vpd](double x){
        return CalculateLinearInterpolation(vpd, x);
    };
    
}

double test_funkcija(double x)
{
    return x*x + std::sin(x);
}

int main ()
{
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int opcija;
    std::cin >> opcija; 
    
    
    if(opcija == 1){
        std::cout << "Unesite broj cvorova: ";
        int br_cvorova;
        std::cin >> br_cvorova;
        std::cout << "Unesite cvorove kao parove x y: ";
        std::vector<ParDoublovaT> pd;
        for(int i = 0; i < br_cvorova; ++i){
            double x, y;
            std::cin >> x >> y;
            pd.emplace_back(x, y);
        }
        try {
            auto lin_inter = LinearnaInterpolacija(pd);
            for(;;){
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                double arg;
                std::cin >> arg;
                if(!std::cin)
                    return 0;
                try {
                    auto x = lin_inter(arg);
                    std::cout << "f(" << arg << ") = " << x << '\n';
                }
                catch (std::range_error e) {
                    std::cout << e.what() << '\n';
                }
            }
        }
        catch (std::domain_error e) {
            std::cout << e.what() << '\n';
        }
    
        
    }
    
    if(opcija == 2){
        std::cout << "Unesite krajeve intervala i korak: ";
        double x_min, x_max, dx;
        std::cin >> x_min >> x_max >> dx;
        
        try {
            auto lin_inter = LinearnaInterpolacija(test_funkcija, x_min, x_max, dx);
            for(;;){
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                double arg;
                std::cin >> arg;
                if(!std::cin)
                    return 0;
               try {
                    auto x = lin_inter(arg);
                    std::cout << "f(" << arg << ") = " << test_funkcija(arg);
                    std::cout << " fapprox(" << arg << ") = " << x << '\n';
               }
               catch (std::range_error e) {
                    std::cout << e.what() << '\n';
               }
            }
            
        }
        catch (std::domain_error e) {
            std::cout << e.what() << '\n';
        }
        
    }
    
    
    
	return 0;
}