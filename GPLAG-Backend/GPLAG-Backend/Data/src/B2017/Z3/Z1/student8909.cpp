/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <stdexcept>
#include <cmath>
#include <algorithm>

bool DaLiJeSortirano(std::vector<std::pair<double, double>> v)
{
    int vel;
    vel = v.size();
    
    for(int i=0; i<vel-1; i++)
    {
        for(int j=i+1; j<vel; j++)
        {
            if(v[i].first >= v[j].first) return false;
        }
    }
    return true;
}

std::function <double(double)> LinearnaInterpolacija(std::vector<std::pair<double, double>> v)
{
  for(int i(0); i<v.size(); i++)
  {
      for(int j(i+1); j<v.size(); j++)
      {
          if(v[i].first == v[j].first) throw std::domain_error("Neispravni cvorovi");
      }
  }
  
  int sortirano (DaLiJeSortirano(v));
    
    return [v] (double x)
    {
        int vel(v.size());
        if(x<v[1].first || x>v[vel-1].first) throw std::range_error("Argumenti izvan opsega");
    
    
    int n = v.size();
    double fx(0);
    int br(0);
    
    for(int i(0); i<v.size(); i++)
    {
        while(v[i].first <= x)
            br = i;
    }
    
    fx = v[br].second + ((v[br+1].second - v[br].second)/(v[br+1].first - v[br].first)) * (x - v[br].first);
    
    return fx;
    };
}

std::function<double (double)> LinearnaInterpolacija(std::function<double (double)>f, double xmin, double xmax, double deltax)
{
    if(xmin > deltax <= 0)
        throw std::domain_error("Nekorektni parametri");
        
    std::vector<std::pair<double, double>> v;
    double x = xmin;
    while(x<xmax)
    {
        v.push_back(std::make_pair(x, f(x)));
        x+=deltax;
    }
    return LinearnaInterpolacija(v);
}




int main ()
{
    
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int opcija;
    std::cin >> opcija;
    
    if(opcija == 1)
    {
        std::cout << "Unesite broj cvorova: ";
        int broj_cvorova;
        std::cin >> broj_cvorova;
        std::cout << "Unesite cvorove kao parove x y: ";
        std::vector<std::pair<double, double>> v;
        double x, y;
        for(int i=0; i<broj_cvorova; i++)
        {
            std::cin >> x;
            std::cin >> y;
            v.push_back(std::make_pair(x,y));
        }
       try
       {
           auto f(LinearnaInterpolacija(v));
           double argument;
           while(1)
           {
               std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
               std::cin >> argument;
               if(!std::cin) return 0;
               std::cout << "f(" << argument << ") = " << f(argument) << std::endl;
           }
       }
       catch (std::domain_error izuzetak)
       {
           std::cout << izuzetak.what();
       }
    }
    
    else if(opcija == 2)
    {
        std::cout << "Unesite krajeve intervala i korak: ";
        double xmin, xmax, delta;
        
        std::cin >> xmin >> xmax >> delta;
        
        double argument;
        
        try
        {
            auto f = LinearnaInterpolacija([] (double x)
            {return x*x + std::sin(x);}, xmin, xmax, delta);
            
            while(1)
            {
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                std::cin >> argument;
                if(!std::cin) return 0;
                
                std::cout << "f(" << argument << ") =" << [](double x) {
                    return x*x + std::sin(x);
                }
                (argument) << " fapprox(" << argument << ") = " << f(argument) << std::endl;
            }
        }
        catch(std::domain_error izuzetak)
        {
            std::cout << izuzetak.what();
        }
    }
    
	return 0;
}
