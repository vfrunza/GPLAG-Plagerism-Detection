/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <cmath>
#include <utility>
#include <functional>


std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double,double>> vek)
{
    for(int i = 0; i < vek.size(); i++)
        for(int j = i+1; j < vek.size(); j++)
            if(vek.at(i).first == vek.at(j).first)
               throw std::domain_error("Neispravni cvorovi");
               
    
    for(int i = 0; i < vek.size(); i++)
        for(int j = i+1; j < vek.size(); j++)
            {
                std::pair<double,double> pomocni;
                if(vek.at(i).first > vek.at(j).first)
                {
                    pomocni = vek.at(i);
                    vek.at(i) = vek.at(j);
                    vek.at(j) = pomocni;
                }
            }
    
    
    return [vek](double x) {
        if(x < vek.at(0).first || x > vek.at(vek.size()-1).first)
          throw std::range_error("Argument izvan opsega");
          
        int k(0);  
        for(int i = 0; i < vek.size(); i++)
            if(std::lower_bound(vek.begin(), vek.end(), ))
            //if(vek.at(i).first <= x && vek.at(i + 1).first > x)
            //   k = i;
               
        return vek.at(k).second+((vek.at(k+1).second - vek.at(k).second)/(vek.at(k+1).first - vek.at(k).first))*(x - vek.at(k).first);       
    };
}

std:function<double(double)> LinearnaInterpolacija (std::function<double(double)> f, double xmin, double xmax, double dx)
{
    if(xmin > xmax || dx <= 0)
        throw std::domain_error("Nekorektni parametri");
        
    std::vector<std::pair<double, double>> vek;
     for(double i = xmin; i <= xmax; i += dx)
    {
        std::pair<double, double> p = std::make_pair(i, f(i));
        vek.push_back(i);
    }
    
    
}
int main ()
{
    //std::vector<std::pair<double,double>> pll
    
    auto f(LinearnaInterpolacija({{1, 3}, {2, 5}, {4, 4}, {5, 2}, {7, 1}}));
    double fun = f(2.5);
    std::cout << fun;
    
	return 0;
}
