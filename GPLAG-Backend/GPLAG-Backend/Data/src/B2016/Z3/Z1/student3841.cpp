/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <stdexcept>
#include <functional>
#include <utility>
#include <algorithm>
#include <cmath>

std::function<double(double)> BaricentricnaInterpolacija (std::vector<std::pair<double, double>> ci, int d)
{
    int n = ci.size();
    std::vector<double> w(ci.size());
    
    if(d < 0 || d >= n)
        throw std::domain_error("Nedozvoljen red");
        
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            if(ci.at(i).first == ci.at(j).first)
                throw std::domain_error("Neispravni cvorovi");
    
    double proizvod = 1;
    for(int i = 1; i <= n; i++)
        for(int k = std::max(1, i - d); k <= std::min(i, n - d); k++)
        { 
            proizvod = 1;
            for(int j = k; j <= k + d; j++)
                {
                    if(i == j)
                        continue;
                        
                    proizvod *= 1 / (ci.at(i - 1).first - ci.at(j - 1).first);
                }
            w.at(i - 1) += std::pow(-1, k - 1) * proizvod;
        }
        
    return [w, n, ci](double x)
            {
                double suma1 = 0, suma2 = 0;
                for(int i = 0; i < n; i++)
                {   
                    if(x == ci.at(i).first)
                        return ci.at(i).second;
                        
                    suma1 += (w.at(i)/(x - ci.at(i).first)) * ci.at(i).second;
                    suma2 += w.at(i) / (x - ci.at(i).first);
                }   
                return suma1/suma2;
            };
}

std::function<double(double)> BaricentricnaInterpolacija (std::function<double(double)> f, double xmin, double xmax, double dx, int d)
{
    if(xmin > xmax || dx <= 0)
        throw std::domain_error("Nekorektni parametri");
    
    std::vector<std::pair<double, double>> vek;
    
    for(double i = xmin; i <= xmax; i += dx)
    {
        std::pair<double, double> p = std::make_pair(i, f(i));
        vek.push_back(p);
    }
    
    return BaricentricnaInterpolacija(vek, d);
}

double f(double x)
{
    return x * x + std::sin(x);
}

int main ()
{
    int a;
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin >> a;
    
    std::vector<std::pair<double, double>> vek;
    if(a == 1)
    {
        int n, r;
        std::cout << "Unesite broj cvorova: ";
        std::cin >> n;
        std::cout << "Unesite cvorove kao parove x y: ";
        for(int i = 0; i < n; i++)
        {
            double x, y;
            std::pair<double, double> p;
            std::cin >> x >> y;
            p = std::make_pair(x, y);
            vek.push_back(p);
        }
        std::cout << "Unesite red interpolacije: ";
        std::cin >> r;
        double arg;
        double vr = 0;
        try
        {
            std::function<double(double)> fu = BaricentricnaInterpolacija(vek, r);
            
            for(; ;)
            {
                vr = 0;
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                std::cin >> arg;
            
                if(!std::cin)
                    break;
                
                vr = fu(arg);
                std::cout << "f(" << arg << ") = " << vr << std::endl;
            }
        }
        catch(std::domain_error e)
        {
            std::cout << e.what();
        }
    }
    
    if(a == 2)
    {
        double poc, kr, dx, arg;
        int r;
        double vr1 = 0, vr2 = 0;
        std::cout << "Unesite krajeve intervala i korak: ";
        std::cin >> poc >> kr >> dx;
        
        std::cout << "Unesite red interpolacije: ";
        std::cin >> r;
        
        try
        {
            std::function<double(double)> fu = BaricentricnaInterpolacija(f, poc, kr, dx, r);
            for(; ;)
            {
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                std::cin >> arg;
            "
                if(!std::cin)
                    break;
                    
            
                vr1 = f(arg);
                vr2 = fu(arg);
                std::cout << "f(" << arg << ") = " << vr1 << " fapprox(" << arg << ") = " << vr2 << std::endl;
            }
        }
        
        catch(std::domain_error e)
        {
            std::cout << e.what();
        }
    }
	return 0;
}