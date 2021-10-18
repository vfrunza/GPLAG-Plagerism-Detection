/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <utility>
#include <vector>
#include <functional>
#include <stdexcept>
#include <cmath>

std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double,double>> vepar,int d )
{
    if(d<0||d>=vepar.size()) throw std::domain_error("Nedozvoljen red");
    for(int i=0;i<vepar.size()-1;i++)
        for(int j=i+1;j<vepar.size();j++)
            if(vepar[i].first==vepar[j].first) throw std::domain_error("Neispravni cvorovi");
    std::vector<double> w(vepar.size());
    for(int i=1;i<=vepar.size();i++)
    {
        w[i-1]=0;
        std::cout << "(" << std::max(1,i-d) <<")(" << std::min(i,int(vepar.size())-d) << ")";
        for(int k=std::max(1,i-d);k<=std::min(i,int(vepar.size())-d);k++)
        {
            double pro=1;
            for(int j=k;j<=k+d;j++)
            {
                if(i==j) continue;
                pro*=1/(vepar[i-1].first-vepar[j-1].first);
            }
            if((k-1)&1) w[i-1]-=pro;
            else w[i-1]+=pro;
            std::cout << pro << "\n";
        }
    }
    for(int i=0;i<vepar.size();i++) std::cout << "w" <<i << "=" << w[i] << "\n";
    return [w,vepar](double x)
    {
        double suma1{},suma2{};
        for(int i=0;i<vepar.size();i++)
        {
            if(vepar[i].first==x) return vepar[i].second;
            suma1+=(w[i]*vepar[i].second)/(x-vepar[i].first);
            suma2+=w[i]/(x-vepar[i].first);
        }
        return suma1/suma2;
    };
}


std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> f,double x1,double x2, double dx, double d)
{
    if(x2<x1 || dx<0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> vepar;
    std::pair<double,double> pom;
    for(double x=x1;x<x2;x+=dx)
    {
        pom.first=x;
        pom.second=f(x);
        vepar.push_back(pom);
    }
    return BaricentricnaInterpolacija(vepar,d);
}

int main ()
{
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int n;
    std::cin >> n;
    try
    {
        if(!(n^1))
        {
            std::cout << "Unesite broj cvorova: ";
            std::cin >> n;
            std::cout << "Unesite cvorove kao parove x y: ";
            std::vector<std::pair<double,double>> vepar(n);
            for(auto &pr:vepar)
                std::cin >> pr.first >> pr.second;
            int d;
            std::cout << "Unesite red interpolacije: ";
            std::cin >> d;
            auto f=BaricentricnaInterpolacija(vepar,d);
            double x;
            while(std::cout << "Unesite argument (ili \"kraj\" za kraj): ",std::cin >> x) std::cout << "f(" << x << ") = " << f(x) << "\n";
        }
        else if(!(n^2))
        {
            std::cout << "Unesite krajeve intervala i korak: ";
            double x1,x2,dx;
            std::cin >> x1 >>x2 >> dx;
            int d;
            std::cout << "Unesite red interpolacije: ";
            std::cin >> d;
            auto f=BaricentricnaInterpolacija([](double a){return a*a+sin(a);},x1,x2,dx,d);
            double x;
            while(std::cout << "Unesite argument (ili \"kraj\" za kraj): ",std::cin >> x) std::cout << "f(" << x << ") = " << x*x+sin(x) << " fapprox("  << x << ") = " << f(x)<< "\n";
        }
    }
    catch(std::domain_error x)
    {
        std::cout << x.what();
    }
	return 0;
}