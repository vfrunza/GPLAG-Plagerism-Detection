#include <iostream>
#include <vector>
#include <functional>
#include <stdexcept>
#include <cmath>
#include <algorithm>

#define Eps 0.00001

bool kriterij(std::pair<double, double> a, std::pair<double, double> b)
{
    return a.first<b.first;
}

bool kriterij2(std::pair<double, double> a, std::pair<double, double> b)
{
    return a.first>b.first;
}

std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double,double>> v)
{
    for(int i=0;i<v.size();i++)
        for(int j=i+1;j<v.size();j++)
            if(std::fabs(v[i].first-v[j].first)<Eps)
                throw std::domain_error("Neispravni cvorovi");
    
    std::sort(v.begin(),v.end(),[](std::pair<double,double>a,std::pair<double,double>b){
        return a.first<b.first;
    });
    
    return [v](double br){
        
        if(br<v[0].first || br>v[v.size()-1].first)
            throw std::range_error("Argument izvan opsega");
            
        if(std::fabs(br-v[v.size()-1].first)<Eps)
            return v[v.size()-1].second;
            
            
        std::pair<double,double> par(br,0);
        
        auto kraj(std::lower_bound(v.begin(),v.end(),par,kriterij));
        auto poc(kraj-1);
        
        if(std::fabs(kraj->first-v[0].first)<Eps)
        {
            poc=kraj;
            kraj++;
        }
        
        double x(poc->first),y(poc->second),x1(kraj->first),y1(kraj->second);
        
        return y+((y1-y)/(x1-x))*(br-x);
    };
}

template <typename funk>

std::function<double(double)> LinearnaInterpolacija(funk f, double xmin, double xmax, double deltax)
{
    if(xmin>xmax || deltax<=0)
        throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> v;
    for(;xmin<=xmax;xmin+=deltax)
        v.push_back(std::make_pair(xmin,f(xmin)));
    return LinearnaInterpolacija(v);
}

int main ()
{
    try
    {
        std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        int izbor(0);
        std::cin>>izbor;
        if(izbor==1)
        {
            std::cout<<"Unesite broj cvorova: ";
            int n; std::cin>>n;
            std::vector<std::pair<double,double>>v(n);
            
            std::cout<<"Unesite cvorove kao parove x y: ";
            for(int i=0;i<n;i++)
                std::cin>>v[i].first>>v[i].second;
                
            auto f(LinearnaInterpolacija(v));
            for(;;)
            {
                try
                {
                    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    double x; std::cin>>x;
                    if(!std::cin) return 0;
                    auto funk(f(x));
                    std::cout<<"f("<<x<<") = "<<funk<<std::endl;
                }
                catch(std::range_error e)
                {
                    std::cout<<e.what()<<std::endl;
                }
            }
        }
        else if(izbor==2)
        {
            std::cout<<"Unesite krajeve intervala i korak: ";
            double xmin,xmax,deltax; std::cin>>xmin>>xmax>>deltax;
            auto f([](double x){ return x*x+std::sin(x);});
            auto fapprox(LinearnaInterpolacija(f,xmin,xmax,deltax));
            for(;;)
            {
                try
                {
                    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    double x; std::cin>>x;
                    if (!std::cin) return 0;
                    auto funk(f(x));
                    auto funk2(fapprox(x));
                    std::cout<<"f("<<x<<") = "<<funk;
                    std::cout<<" fapprox("<<x<<") = "<<funk2<<std::endl;
                }
                catch(std::range_error e)
                {
                    std::cout<<e.what()<<std::endl;
                }
            }
        }
    }
    catch(std::domain_error e)
    {
        std::cout<<e.what();
    }
    
	return 0;
}
