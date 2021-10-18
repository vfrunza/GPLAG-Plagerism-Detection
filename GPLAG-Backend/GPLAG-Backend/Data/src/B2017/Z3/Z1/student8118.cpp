/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <utility>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double,double>> v) {
    auto Sortiraj=[](std::pair<double,double> par1, std::pair<double,double> par2) { return par1.first<par2.first; };
    std::sort(v.begin(), v.end(), Sortiraj);
    for (auto it=v.begin();it!=v.end();it++) {
        if (std::count_if(it,v.end(),[it](std::pair<double,double> par1) { return par1.first==it->first; })>1) throw std::domain_error("Neispravni cvorovi");
    }
    return [v,Sortiraj](double x)->double {
        if (x<v.at(0).first || x>v.at(v.size()-1).first) throw std::range_error("Argument izvan opsega");
        auto it=std::lower_bound(v.begin(),v.end(),std::make_pair(x,x), Sortiraj);
        if (x==it->first) return it->second;
        auto it2=it-1;
        return it2->second+(it->second-it2->second)*(x-it2->first)/(it->first-it2->first);
    };
}
std::function<double(double)> LinearnaInterpolacija(std::function<double(double)> f, double xmin, double xmax, double dx) {
    if (xmin>xmax || dx<=0) throw std::domain_error("Nekorektni parametri");
    return [=](double x)->double {
        if (x<xmin || x>xmax) throw std::range_error("Argument izvan opsega");
        if (xmin==xmax) return f(xmin);
        long long donja=int((x-xmin)/dx);
        std::vector<std::pair<double,double>> v={std::make_pair(xmin+donja*dx,f(xmin+donja*dx)),std::make_pair(xmin+(donja+1)*dx,f(xmin+(donja+1)*dx))};
        return v[0].second+(v[1].second-v[0].second)*(x-v[0].first)/(v[1].first-v[0].first);
    };
}
int main ()
{
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int odabir;
    std::cin>>odabir;
    auto f=[](double x) { return std::sin(x)+std::pow(x,2); };
    if (odabir==1) {
        std::cout<<"Unesite broj cvorova: ";
        int brojcvorova;
        std::cin>>brojcvorova;
        std::vector<std::pair<double,double>> v;
        v.resize(brojcvorova);
        std::cout<<"Unesite cvorove kao parove x y: ";
        std::for_each(v.begin(), v.end(), [](std::pair<double,double> &par) { std::cin>>par.first; std::cin>>par.second; });
        try {
            auto lininterp=LinearnaInterpolacija(v);
        for (;;) {
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            double argument;
            std::cin>>argument;
            if (!std::cin) break;
            try {
            std::cout<<"f("<<argument<<") = "<<lininterp(argument)<<std::endl;
            }
            catch(std::exception &e) {
                std::cout<<e.what()<<std::endl;
            }
        }
        }
        catch(std::exception &e) {
            std::cout<<e.what()<<std::endl;
        }
    }
    else {
        std::cout<<"Unesite krajeve intervala i korak: ";
        double xmin, xmax, dx;
        std::cin>>xmin>>xmax>>dx;
        try {
            auto lininterp=LinearnaInterpolacija(f,xmin,xmax,dx);
        for (;;) {
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            double argument;
            std::cin>>argument;
            if (!std::cin) break;
            try {
                std::cout<<"f("<<argument<<") = "<<f(argument)<<" fapprox("<<argument<<") = "<<lininterp(argument)<<std::endl;
            }
            catch(std::exception &e) {
                std::cout<<e.what()<<std::endl;
            }
        }
        }
        catch(std::exception &e) {
            std::cout<<e.what()<<std::endl;
        }
    }
	return 0;
}
