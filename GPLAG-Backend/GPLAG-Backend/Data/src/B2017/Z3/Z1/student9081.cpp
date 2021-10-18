/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <stdexcept>
#include <algorithm>
#include <cmath>

bool JesuLiJednaki (double x, double y, double EPS=1e-10)
{
    if ((x<0  && y>0) || (x>0 && y<0))
        return false;
    return std::fabs(x-y)<=EPS*(std::fabs(x)+std::fabs(y));
}

std::function<double(double)> LinearnaInterpolacija (std::vector<std::pair<double,double>> v)
{
    std::sort(v.begin(),v.end());
    for (int i=0;i<v.size();i++)
    {
        for (int j=i+1;j<v.size();j++)
        {
            if (JesuLiJednaki(v[i].first,v[j].first))
                throw std::domain_error ("Neispravni cvorovi");
        }
    }
    return [v] (double x) {
        if (v.begin()==v.end())
            throw std::range_error ("Argument izvan opsega");
        if ((x<v[0].first && !JesuLiJednaki(x,v[0].first)) || (x>v[v.size()-1].first && !JesuLiJednaki(x,v[v.size()-1].first)))
            throw std::range_error ("Argument izvan opsega");
        if (JesuLiJednaki(x,v[v.size()-1].first))
            return v[v.size()-1].second;
        int cuvaj(std::distance(v.begin(),std::lower_bound(v.begin(),v.end(),std::make_pair(x,0.1))));
        if (JesuLiJednaki(x,v[0].first))
            cuvaj=1;
        return v[cuvaj-1].second+(v[cuvaj].second-v[cuvaj-1].second)/(v[cuvaj].first-v[cuvaj-1].first)*(x-v[cuvaj-1].first);
    };
}
std::function<double(double)> LinearnaInterpolacija (std::function<double(double)> f, double x_min, double x_max, double korak)
{
    if (x_min>x_max || korak<=0)
        throw std::domain_error ("Nekorektni parametri");
    std::vector<std::pair<double,double>> v;
    while (!JesuLiJednaki(x_min,x_max))
    {
        v.push_back({x_min,f(x_min)});
        x_min+=korak;
    }
    if (JesuLiJednaki(x_min,x_max))
        v.push_back({x_min,f(x_min)});
    return LinearnaInterpolacija(v);
}

int main ()
{
    int x;
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin>>x;
    if (x==1)
    {
        int n;
        std::cout<<"Unesite broj cvorova: ";
        std::cin>>n;
        std::vector<std::pair<double,double>> v(n);
        std::cout<<"Unesite cvorove kao parove x y: ";
        for (int i=0;i<n;i++)
            std::cin>>v[i].first>>v[i].second;
        try 
        {
            auto f(LinearnaInterpolacija(v));
            for (;;)
            {    
                double y;
                std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                std::cin>>y;
                if (!std::cin)
                break;
                try
                {
                    std::cout<<"f("<<y<<") = "<<f(y)<<std::endl;
                }
                catch(std::range_error izuz)
                {
                    std::cout<<izuz.what()<<std::endl;
                }
            }
        }
        catch (std::domain_error izuz2)
        {
            std::cout<<izuz2.what()<<std::endl;
        }
    }
    else if (x==2)
    {
        std::function<double(double)> fun{[](double x){return x*x+std::sin(x);}};
        double a,b,c;
        std::cout<<"Unesite krajeve intervala i korak: ";
        std::cin>>a>>b>>c;
        try
        {
            for (;;)
            {
                auto f(LinearnaInterpolacija(fun,a,b,c));
                double z;
                std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                std::cin>>z;
                if (!std::cin)
                break;
                try 
                {  
                    std::cout<<"f("<<z<<") = "<<fun(z)<<" fapprox("<<z<<") = "<<f(z)<<std::endl;
                }
                catch(std::range_error izuz)
                {
                    std::cout<<izuz.what()<<std::endl;
                }
            }
        }
        catch (std::domain_error izuz3)
        {
            std::cout<<izuz3.what()<<std::endl;
        }
        
    }
	return 0;
}
