/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <utility>
#include <vector>
#include <functional>
#include <stdexcept>
#include <algorithm>
#include <cmath>

typedef std::vector<std::pair<double, double>> VektorP;


double Funkcija(double x) {
    return x*x +sin(x);
}


std::function<double(double)> LinearnaInterpolacija (VektorP v) {
    
    for (int i=0; i<v.size(); i++) // ILI v.size()-1?   
        for (int j=i+1; j<v.size(); j++)
            if (v[i].first==v[j].first)
                throw std::domain_error ("Neispravni cvorovi");

    std::sort(std::begin(v), std::end(v), [](std::pair<double, double> prvi, std::pair<double, double> drugi) {return prvi.first<drugi.first;});
    
    return [v] (double x) {
        
        int zadnji=v.size()-1;
        
        if (x<v[0].first || x>v[zadnji].first) throw std::range_error ("Argument izvan opsega");
        
        double n, xi, yi, xi2, yi2;
        
        if (x==v[zadnji].first) return v[zadnji].second;
        
        auto it(std::upper_bound(std::begin(v), std::end(v), std::make_pair(x, 0), [](std::pair<double, double> prvi, std::pair<double, double> drugi) {return prvi.first<drugi.first;}));
        
        xi2=it->first;
        yi2=it->second;
        it--;
        xi=it->first;
        yi=it->second;
        
        n=yi+(((yi2-yi)/double(xi2-xi))*(x-xi));
        
        return n;
    };
}


std::function<double(double)> LinearnaInterpolacija (std::function<double(double)> f, double xmin, double xmax, double dx) {
    
    if (xmin>xmax || dx<=0) throw std::domain_error ("Nekorektni parametri");
    
    VektorP v;
    
    for (; xmin<=xmax; xmin+=dx)
        v.push_back(std::make_pair(xmin, f(xmin)));
    
    return LinearnaInterpolacija(v);
}




int main ()
{
    int opcija;
    

    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin >> opcija;
    
    if (opcija==1) {
        
        int n;
        std::cout << "Unesite broj cvorova: ";
        std::cin >> n;
        VektorP v(n);
        std::cout << "Unesite cvorove kao parove x y: ";
        for (int i=0; i<n; i++)
            std::cin >> v[i].first >> v[i].second;
        try {
            auto g(LinearnaInterpolacija(v));
            
            for (;;) {
                double x;
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                std::cin >> x;
                if (!std::cin) return 0;
                
                try {
                    std::cout << "f(" << x << ") = " << g(x) << std::endl;
                }
                catch (std::range_error e) {
                    std::cout << e.what() << std::endl;
                }
            }
        }
        catch (std::domain_error e) {
            std::cout << e.what() << std::endl;
            return 0;
        }
    }
    
    if (opcija==2) {
        
        double xmin, xmax, dx;
        std::cout << "Unesite krajeve intervala i korak: ";
        std::cin >> xmin >> xmax >> dx;
        
        try {
            auto g(LinearnaInterpolacija(Funkcija, xmin, xmax, dx));
            
            for (;;) {
                double x;
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                std::cin >> x;
                if (!std::cin) return 0;
                
                try {
                    std::cout << "f(" << x << ") = " << Funkcija(x) << " fapprox(" << x << ") = " << g(x) << std::endl;
                }
                catch (std::range_error e) {
                    std::cout << e.what() << std::endl;
                }
            }
        }
        catch (std::domain_error e) {
            std::cout << e.what() << std::endl;
            return 0;
        }
    }
    
	return 0;
}
