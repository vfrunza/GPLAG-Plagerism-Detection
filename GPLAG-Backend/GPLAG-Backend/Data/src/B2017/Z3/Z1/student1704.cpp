/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>
#include <stdexcept>
#include <cmath>

std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double, double>> &v) {
    std::sort(v.begin(), v.end(), [](std::pair<double, double> x, std::pair<double, double> y) {return x.first<y.first;});
    if(v.size()!=0) {
        for(int i=0; i<v.size()-1; i++) 
        for(int j=i+1; j<v.size(); j++)
        if(v[i].first==v[j].first) throw std::domain_error("Neispravni cvorovi");
    }
        
        return [&v] (double x) {
            std::pair<double, double> a {x,0};
            if(v.size()==0) throw std::range_error("Argument izvan opsega");
            if(x<v[0].first || x>v[v.size()-1].first) throw std::range_error("Argument izvan opsega");
            if(x==v[v.size()-1].first) return v[v.size()-1].second;
            auto it_max(std::lower_bound(v.begin(), v.end(), a));
            if(it_max->first==x) it_max++;
            auto it_min(std::upper_bound(v.begin(), v.end(), a));
            it_min--;
            return it_min->second + ((it_max->second-it_min->second)/(it_max->first-it_min->first)) * (x-it_min->first);
        };
    
}

template <typename FunTip>
std::function<double(double)> LinearnaInterpolacija(FunTip f, double x_min, double x_max, double korak) {
    if(x_min>x_max || korak<=0) throw std::domain_error("Nekorektni parametri");
    return [f,x_min,x_max,korak] (double x) {
        if(x<x_min || x>x_max) throw std::range_error("Argument izvan opsega");
        if(x==x_max) return f(x);
        double min(x_min), max(x_min+korak);
        for(;;) {
            if(max<=x_max) {
                if(x>=min && x<max) return f(min) + ((f(max)-f(min))/(max-min))*(x-min);
                min=max;
                max+=korak;
            }
            else break;
        }
        if(max!=x_max) {
            max=x_max;
            if(x>=min && x<max) return f(min) + ((f(max)-f(min))/(max-min))*(x-min);
        }
    };
}


int main ()
{
    int opcija;
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin>>opcija;
    if(opcija==1) {
        int n;
        std::cout<<"Unesite broj cvorova: ";
        std::cin>>n;
        std::vector<std::pair<double, double>> v;
        std::cout<<"Unesite cvorove kao parove x y: ";
        for(int i=0; i<n; i++) {
            std::pair<double, double> par;
            std::cin>>par.first>>par.second;
            v.push_back(par);
        }
        try {
            LinearnaInterpolacija(v);
        }
        catch(std::domain_error poruka) {
            std::cout<<poruka.what();
            return 0;
        }
       for(;;) {
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            std::cin.ignore(10000, '\n');
            double arg;
            std::cin>>arg;
            if(!std::cin) break;
            
           auto f (LinearnaInterpolacija(v));
            try {
                std::cout<<"f("<<arg<<") = "<<f(arg)<<std::endl;
            }
            catch (std::range_error poruka) {
                std::cout<<poruka.what()<<std::endl;
            
        }
    }
    }
    
    else {
        std::cout<<"Unesite krajeve intervala i korak: ";
        double x_min, x_max, korak;
        std::cin>>x_min>>x_max>>korak;
        try {
            LinearnaInterpolacija([] (double x) {return x*x+std::sin(x);}, x_min, x_max, korak);
        }
        catch(std::domain_error poruka) {
            std::cout<<poruka.what();
            return 0;
        }
        for(;;) {
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            std::cin.ignore(10000, '\n');
            double arg;
            std::cin>>arg;
            if(!std::cin) break;
                auto f(LinearnaInterpolacija([] (double x) {return x*x+std::sin(x);}, x_min, x_max, korak));
                try {
                    std::cout<<"f("<<arg<<") = "<<arg*arg+std::sin(arg)<<" fapprox("<<arg<<") = "<<f(arg)<<std::endl;
                }
                catch(std::range_error poruka) {
                    std::cout<<poruka.what()<<std::endl;
                }
        
    }
    }
    
	return 0;
}
