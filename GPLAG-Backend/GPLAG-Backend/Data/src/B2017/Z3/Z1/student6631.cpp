/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <functional>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
#include <cmath>
#include <stdexcept>

typedef std::vector<std::pair<double, double>> Parovi;

std::function<double(double)> LinearnaInterpolacija(Parovi v)
{
    for(int i=0; i<v.size(); i++)
    {
        for(int j=i+1; j<v.size(); j++)if(v[i].first==v[j].first)throw std::domain_error("Neispravni cvorovi");
    }
    std::function<double(double)> f = [v](double x) 
    { 
        if(x<v[0].first && x>v[v.size()-1].first)throw std::range_error("Argument izvan opsega");
        double x1(0), y1(0), x2(0), y2(0);
        auto it1(&v[0]);
        auto it2(&v[1]);
       // if(v.size()==1)exit(1);
        if(x==v[v.size()-1].first)return v[v.size()-1].second;
        while(!std::binary_search(&v[0].first, &v[v.size()].first, x))
        {
            if(x>=it1->first){x1=it1->first;y1=it1->second;}
            else it1++;
            if(x<it2->first){x2=it2->first;y2=it2->second;}
            else {it1++; it2++;}
            if(x>=x1 && x<x2)break;
        }
        return ((y1+(y2-y1)/(x2-x1)*(x-x1)));
    };
    return [f](double x){return f(x);};
}

std::function<double(double)> LinearnaInterpolacija(double (*fun)(double), double start, double stop, double step)
{
    if(start>stop || step<=0)throw std::domain_error("Nekorektni parametri");
    Parovi v;
    for(double i=start; i<stop; i+=step)v.push_back(std::make_pair(i,fun(i)));
    auto f(LinearnaInterpolacija(v));
    return [f](double x) {return f(x);};
}

int main ()
{
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int opcija(0);
    std::cin >> opcija;
    Parovi v;
    if(opcija==1)
    {
        std::cout << "Unesite broj cvorova: ";
        int n;
        std::cin >> n;
        std::cout << "Unesite cvorove kao parove x y: ";
        for(int i=0; i<n; i++)
        {
            double x, y;
            std::cin >> x >> y;
            v.push_back(std::make_pair(x,y));
        }
        try
        {
            auto f(LinearnaInterpolacija(v));
        }
        catch(std::domain_error izuzetak)
        {
            std::cout << izuzetak.what();
            return 0;
        }
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        while(1)
        {
            std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
            std::string s;
            std::getline(std::cin,s);
            if(s=="kraj")break;
            try
            {
                if(!std::stod(s))
                throw std::invalid_argument("");
            }
            catch(std::invalid_argument izuzetak)
            {
                return 0;
            }
            auto f(LinearnaInterpolacija(v));
            try
            {
                f(std::stod(s));
            }
            catch(std::range_error izuzetak)
            {
                std::cout << izuzetak.what();
                return 0;
            }
            std::cout << "f(" <<std::stod(s) <<") = ";
            std::cout << f(std::stod(s)) << std::endl;
        }
    }  
    else if(opcija==2)
    {
        std::cout << "Unesite krajeve intervala i korak: ";
        double min, max, korak;
        try
        {
            std::cin >> min >> max;
            auto f(LinearnaInterpolacija([](double x){return x*x+sin(x);}, min, max, 0.1));
            std::cin >> korak;
            f=LinearnaInterpolacija([](double x){return x*x+sin(x);}, min, max, korak);
        }
        catch(std::domain_error izuzetak)
        {
            std::cout << izuzetak.what();
            return 0;
        }
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        while(1)
        {
            std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
            std::string s;
            std::getline(std::cin,s);
            if(s=="kraj")break;
            try
            {
                if(!std::stod(s))
                throw std::invalid_argument("");
            }
            catch(std::invalid_argument izuzetak)
            {
                return 0;
            }
            if(std::stod(s)>max)                                               
            {
                std::cout << "Argument izvan opsega " << std::endl;
                continue;
            }
            std::cout << "f(" <<std::stod(s) <<") = ";
            std::cout << std::stod(s)*std::stod(s) + sin(std::stod(s));
            std::cout << " fapprox(" <<std::stod(s) <<") = ";
            auto f(LinearnaInterpolacija([](double x){return x*x+sin(x);}, min, max, korak));
            std::cout << f(std::stod(s)) << std::endl;
        }
    }
    return 0;
}
