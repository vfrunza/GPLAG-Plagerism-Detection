/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <stdexcept>
#include <vector>
#include <utility>
#include <cmath>
#include <functional>

double stepen(int x, int y)
{
    if(y==0) return 1;
    int z=1;
    for(int i=0;i<y;i++) z*=x;
    return z;
}
std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double,double>> cvorovi, int d)
{
    if(d<0 || d>=cvorovi.size()) throw std::domain_error ("Nedozvoljen red");
    if(cvorovi.size()>1)
    {
        for(int i=0;i<cvorovi.size()-1;i++)
        {
            for(int j=i+1;j<cvorovi.size();j++)
            {
                if(cvorovi[i].first==cvorovi[j].first) throw std::domain_error("Neispravni cvorovi");
            }
        }
    }
    
    return [cvorovi,d] (double x)
    {
        double brojnik=0, nazivnik=0;
        int n=cvorovi.size();
        if(n!=0)
        {
            for(int i=1;i<=n;i++)
            {
                int k,k2,trenutni=i-1;
                if(x==cvorovi[trenutni].first) return cvorovi[trenutni].second;
                double w=0;
                if(i-d>1) k=i-d;
                else k=1;
                if(n-d<i) k2=n-d;
                else k2=i;
                for(int s=k;s<=k2;s++)
                {
                    double proizvod=1;
                    for(int j=s;j<=s+d;j++)
                    {
                        if(j==i) continue;
                        proizvod*=1./(cvorovi[trenutni].first-cvorovi[j-1].first);
                    } 
                    w+=(proizvod*stepen(-1,s));
                } 
                brojnik+=(w*cvorovi[trenutni].second)/(x-cvorovi[trenutni].first);
                nazivnik+=w/(x-cvorovi[trenutni].first);
            }
            return brojnik/nazivnik;
        }
        
        
    };
    }

std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> f, double min, double max, double delta, int d)
{
    if(min>max || delta<=0) throw std::domain_error("Nekorektni parametri");
    double t=min;
    std::vector<std::pair<double,double>> cvorovi;
    while(t<=max)
    {
        if(t>max) break;
        cvorovi.push_back(std::make_pair(t,f(t)));
        t+=delta;
    }
    return BaricentricnaInterpolacija(cvorovi,d);
}

int main ()
{
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int opcija;
    std::cin>>opcija;
    try {
    if(opcija==1)
    {
        int broj;
        std::cout<<"Unesite broj cvorova: ";
        std::cin>>broj;
        std::cout<<"Unesite cvorove kao parove x y: ";
        std::vector<std::pair<double,double>> cvorovi;
        for(int i=0;i<broj;i++)
        {
        double x, y;
        std::cin>>x>>y;
        cvorovi.push_back(std::make_pair(x,y));
        }
        std::cout<<"Unesite red interpolacije: ";
        int d;
        std::cin>>d;
        while (1)
        {
            char znak=34;
            std::cout<<"Unesite argument (ili "<<znak<<"kraj"<<znak<<" za kraj): ";
            double arg;
            std::cin>>arg;
            if(!std::cin) break;
            auto f=BaricentricnaInterpolacija(cvorovi,d);
            std::cout<<"f("<<arg<<") = "<<f(arg)<<std::endl;
        }
    }
    if(opcija==2)
    {
        std::cout<<"Unesite krajeve intervala i korak: ";
        double poc,kraj,delta;
        std::cin>>poc>>kraj>>delta;
        int d;
        std::cout<<"Unesite red interpolacije: ";
        std::cin>>d;
        std::function<double(double)> fun = [](double r) { return r*r+sin(r);}  ;
        while(1)
        {
            char znak=34;
            std::cout<<"Unesite argument (ili "<<znak<<"kraj"<<znak<<" za kraj): ";
            double arg;
            std::cin>>arg;
            if(!std::cin) break;
            std::cout<<"f("<<arg<<") = "<<fun(arg)<<" fapprox("<<arg<<") = "<<BaricentricnaInterpolacija(fun,poc,kraj,delta,d)(arg)<<std::endl;
        }
    
    }
    }
    catch(std::domain_error e)
    {
        std::cout<<e.what();
    }
    return 0;
}