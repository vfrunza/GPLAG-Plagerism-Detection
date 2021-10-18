/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <utility>
#include <stdexcept>
#include <functional>
#include <cmath>

int max(int a, int b)
{
    if(a>=b) return a;
    else return b;
}
int min(int a, int b)
{
    if(a<=b) return a;
    else return b;
}
int StepenMinusJedan(int x)
{
    if(x%2==0)  return 1;
    else return -1;
}

typedef std::vector<std::pair<double,double>> VektorParova;
std::function<double(double)> BaricentricnaInterpolacija(VektorParova cvor, int d)
{
    const double EPS(0.0000001);
    int n=cvor.size();
    if(d<0 || d>=n)    throw std::domain_error("Nedozvoljen red");
    for(int i=0; i<n-1; i++)
        for(int j=i+1; j<n; j++)
            if(std::fabs(cvor[i].first-cvor[j].first)<EPS)    throw std::domain_error("Neispravni cvorovi");
    std::vector<double> w;
    for(int i=1; i<=n; i++)
    {
        double sum(0);
        if(d<=6)
        {
            for(int k=max(1,i-d); k<=min(i,n-d); k++)
            {
                double proizvod(1);
                for(int j=k; j<=k+d; j++)
                {
                    if(j==i) continue;      //sta ako je d=0? => proizvod=0?
                    proizvod*=(1./(cvor[i-1].first-cvor[j-1].first));
                    if(j==k+d)  break;
                }
                sum+=proizvod*StepenMinusJedan(k-1);
                if(k==min(i,n-d))   break;
            }
        }
        w.push_back(sum);
        if(i==n)    break;
    }
    return[w,cvor, EPS](double x)
    {
        double sum1(0), sum2(0);
        for(int i=0; i<cvor.size(); i++)
        {
            if(std::fabs(x-cvor[i].first)<EPS)  return cvor[i].second;
            double temp(w[i]/(x-cvor[i].first));
            sum1+=temp*cvor[i].second;
            sum2+=temp;
        }
        return sum1/sum2;
    };
}
std::function<double(double)>BaricentricnaInterpolacija(double fun(double), double mini, double maxi, double delta, int d)
{
    if(mini>maxi || delta<=0)   throw std::domain_error("Nekorektni parametri");
    VektorParova cvor;
    double br(mini);
    for(int i=0; br<=maxi; br+=delta, i++) cvor.push_back(std::make_pair(br, fun(br)));
    return BaricentricnaInterpolacija(cvor,d);
}
int main ()
{
    int opcija;
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin>>opcija;
    if(opcija==1)
    {
        int n;
        std::cout<<"Unesite broj cvorova: ";
        std::cin>>n;
        VektorParova cvor;
        std::cout<<"Unesite cvorove kao parove x y: ";
        for(int i=0; i<n; i++)
        {
            double x,y;
            std::cin>>x>>y;
            cvor.push_back(std::make_pair(x,y));
        }
        int d;
        std::cout<<"Unesite red interpolacije: ";
        std::cin>>d;
        for(;;)
        {
            double x;
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            std::cin>>x;
            if(!std::cin)   return 0;
            else 
            {
                try
                {
                    std::cout<<"f("<<x<<") = "<<BaricentricnaInterpolacija(cvor, d)(x)<<std::endl;
                }
                catch(std::domain_error izuzetak)
                {
                    std::cout<<izuzetak.what();
                    return 0;
                }
            }
        }
    }
    if(opcija==2)
    {
        double mini, maxi, delta;
        std::cout<<"Unesite krajeve intervala i korak: ";
        std::cin>>mini>>maxi>>delta;
        int d;
        std::cout<<"Unesite red interpolacije: ";
        std::cin>>d;
        for(;;)
        {
            double x;
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            std::cin>>x;
            if(!std::cin)   return 0;
            else 
            {
                try
                {
                    std::cout<<"f("<<x<<") = "<<x*x+std::sin(x)<<" fapprox("<<x<<") = "<<BaricentricnaInterpolacija([](double x){return x*x+std::sin(x);}, mini, maxi, delta, d)(x)<<std::endl;
                }
                catch(std::domain_error izuzetak)
                {
                    std::cout<<izuzetak.what();
                    return 0;
                }
            }
        }
    }
}