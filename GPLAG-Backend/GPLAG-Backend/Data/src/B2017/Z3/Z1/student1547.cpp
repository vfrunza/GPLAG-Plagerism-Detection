/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <functional>
#include <stdexcept>
#include <cmath>

const double epsilon(0.00001);
std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double,double>> &v)
{
    std::sort(v.begin(),v.end());
    auto it = std::unique(v.begin(),v.end(),[](std::pair<double,double> a, std::pair<double,double> b){return a.first==b.first;});
    if(it!=v.end()) throw std::domain_error("Neispravni cvorovi");
    
    return[v](double x)
    {
        std::pair<double,double> trazen;
        trazen={x,0};
        if(v.size()==0) throw std::range_error("Argument izvan opsega");
        double zadnji=(*(v.end()-1)).first;
        double prvi=(*(v.begin())).first;
        auto p=std::lower_bound(v.begin(),v.end(),trazen,[](std::pair<double,double> ba, std::pair<double,double> ca){return ba.first<=ca.first;});
        
        if(fabs(x-zadnji)<epsilon) return (*(p-1)).second;
        
        if(x>zadnji || x<prvi) throw std::range_error("Argument izvan opsega");
        
        p--;
        double yi=(*p).second;
        double yi1=(*(p+1)).second;
        double xi=(*p).first;
        double xi1=(*(p+1)).first;
        return yi+((yi1-yi)/(xi1-xi))*(x-xi);
    };
}
template <typename F>
std::function<double(double)> LinearnaInterpolacija(F funkcija,double xmin, double xmax, double dx)
{
    if(xmin>xmax || dx<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> v;
    for(xmin;xmin<=xmax;xmin+=dx)
    {
        std::pair<double,double> a;
        a={xmin,funkcija(xmin)};
        v.push_back(a);
    }
    return LinearnaInterpolacija(v);
}
double fja(double x)
{
    return x*x+std::sin(x);
}
int main ()
{/*
    std::vector<std::pair<double,double>> v;
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int unos;
    std::cin>>unos;
    if(unos==1)
    {
        std::cout<<"Unesite broj cvorova: ";
        int broj;
        std::cin>>broj;
        std::cout<<"Unesite cvorove kao parove x y: ";
        for(int i=0;i<broj;i++)
        {
            double x,y;
            std::cin>>x>>y;
            std::pair<double,double> par;
            par={x,y};
            v.push_back(par);
        }
        try
        {
            auto f=LinearnaInterpolacija(v);
            while(1)
            {
                std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                double unesen;
                std::cin>>unesen;
                if(std::cin.peek()!='\n' || !std::cin) 
                {
                    std::cin.clear();
                    std::cin.ignore(10000,'\n');
                    break;
                }
                
                try
                {
                    auto vrijednost=f(unesen);
                    std::cout<<"f("<<unesen<<") = "<<vrijednost<<std::endl;
                }
                catch(std::domain_error izuzetak)
                {
                    std::cout<<izuzetak.what()<<std::endl;
                }
                catch(std::range_error izuzetak)
                {
                    std::cout<<izuzetak.what()<<std::endl;
                }
            }
        }
        catch(std::domain_error izuzetak)
        {
            std::cout<<izuzetak.what()<<std::endl;
        }
        catch(std::range_error izuzetak)
        {
            std::cout<<izuzetak.what()<<std::endl;
        }
    }
    else
    {
        std::cout<<"Unesite krajeve intervala i korak: ";
        double xmin,xmax,dx;
        std::cin>>xmin>>xmax>>dx;
        try
        {
            
            auto f=LinearnaInterpolacija(fja,xmin,xmax,dx);
            while(1)
            {
                std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                double unesen;
                std::cin>>unesen;
                if(std::cin.peek()!='\n' || !std::cin) 
                {
                    std::cin.clear();
                    std::cin.ignore(10000,'\n');
                    break;
                }
                
                try
                {
                    auto vrijednost=f(unesen);
                    std::cout<<"f("<<unesen<<") = "<<fja(unesen)<<" "<<"fapprox("<<unesen<<") = "<<vrijednost<<std::endl;
                }
                catch(std::domain_error izuzetak)
                {
                    std::cout<<izuzetak.what()<<std::endl;
                }
                catch(std::range_error izuzetak)
                {
                    std::cout<<izuzetak.what()<<std::endl;
                }
            }
        }
        catch(std::domain_error izuzetak)
        {
            std::cout<<izuzetak.what()<<std::endl;
        }
        catch(std::range_error izuzetak)
        {
            std::cout<<izuzetak.what()<<std::endl;
        }
    }*///AT-10 (zamger) Izuzetak-neispravni cvorovi
try
{
   auto li2(LinearnaInterpolacija({{3,3},{3,3},{1,1},{6,6},{2,2},{5,5}}));

}
catch (std::domain_error e)
{
    std::cout << "'" << e.what() << "'";
}
catch (...)
{
    std::cout << "Pogresan tip izuzetka";
}
	return 0;
}
