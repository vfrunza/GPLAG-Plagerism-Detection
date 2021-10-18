/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <functional>
#include <vector>
#include <utility>
#include <algorithm>
#include <stdexcept>
#include <cmath>

double fun(double x)
{
    return x*x+std::sin(x);
}

std::function<double(double)>LinearnaInterpolacija(std::vector<std::pair<double, double>> v)
{
    std::sort(v.begin(),v.end());
    for(int i(0);i<v.size();i++){
        for(int j(i+1);j<v.size();j++){
            if(v.at(i).first==v.at(j).first)throw std::domain_error("Neispravni cvorovi");
        }
    }
    
    return[v](double x)
    {
        //AKO JE PRAZAN VEKTOR???
        
        if(v.size()==0 || x<v.at(0).first || x>v.at(v.size()-1).first)throw std::range_error("Argument izvan opsega");
        if(x==v.at(v.size()-1).first)return v.at(v.size()-1).second;
        auto it(std::lower_bound(v.begin(),v.end(),std::make_pair(x,0.)));
        auto it2(it);
        if(it->first==x)it2++;
        if(it->first>x)it--;
        return it->second+((it2->second-it->second)/(it2->first-it->first))*(x-it->first);
    };
}

std::function<double(double)> LinearnaInterpolacija(std::function<double(double)>fun, double xmin, double xmax, double deltax)
{
    if(xmin>xmax || deltax<=0)throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double, double>> cvorovi;
    while(xmin<=xmax)
    {
        cvorovi.push_back(std::make_pair(xmin,fun(xmin)));
        xmin+=deltax;
    }
    return LinearnaInterpolacija(cvorovi);
}


int main ()
{
    int a;
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin>>a;
try{
    if(a==1)
    {
        std::cout<<"Unesite broj cvorova: ";
        int n;
        std::cin>>n;
        std::cout<<"Unesite cvorove kao parove x y: ";
        std::vector<std::pair<double, double>> v(n);
        for(int i(0);i<n;i++)
        {
            std::cin>>v.at(i).first>>v.at(i).second;
        }
    
        auto f(LinearnaInterpolacija(v));
        
        while(1)
        {
            try{
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            double x;
            std::cin>>x;
            if(!std::cin)break;
            std::cout<<"f("<<x<<") = "<<f(x)<<std::endl;}
                catch(std::range_error Izuzetak)
                {
                    std::cout<<Izuzetak.what()<<std::endl;
                }
        }
     
    }
    if(a==2)
    {
        std::cout<<"Unesite krajeve intervala i korak: ";
        double xmin,xmax,deltax;
        std::cin>>xmin>>xmax>>deltax;
    
        auto funap(LinearnaInterpolacija(fun,xmin,xmax,deltax));
        while(1)
        {
            try{
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            double x;
            std::cin>>x;
            if(!std::cin)break;
            std::cout<<"f("<<x<<") = "<<fun(x)<<" fapprox("<<x<<") = "<<funap(x)<<std::endl;}
            catch(std::range_error Izuzetak)
    {
        std::cout<<Izuzetak.what()<<std::endl;
    }}}

}catch(std::domain_error Izuzetak)
    {
        std::cout<<Izuzetak.what()<<std::endl;
    }

	return 0;
}
