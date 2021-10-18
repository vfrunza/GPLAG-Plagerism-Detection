/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <functional>
#include <stdexcept>
#include <cmath>

int max(int x, int y)
{
    if(x>y) return x;
    else return y;
}

int min(int x, int y)
{
    if(x<y) return x;
    else return y;
}

std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double ,double>> v,int d)
{
    if(d<0 || d>v.size()) throw std::domain_error("Nedozvoljen red");
    for(int i(0);i<v.size();i++)
        for(int j(i+1);j<v.size();j++)
            if(v[i].first==v[j].first) throw std::domain_error("Neispravni cvorovi");
    std::vector<double> teskasi(v.size());
    for(int i(1);i<=v.size();i++)
    {
        int poc(max(1,i-d));
        int kraj(min(i,v.size()-d));
        teskasi[i-1]=0;
        for(int k(poc);k<=kraj;k++)
        {
            int znak; if((k-1)%2==0) znak=1; else znak=-1; //ako je paran + ako je neparan -
            double proizvod(1);
            for(int j(k);j<=k+d;j++)
            {
                if(i==j) continue;
                proizvod*=(1./(v[i-1].first-v[j-1].first));
            }
            proizvod*=znak;
            teskasi[i-1]+=proizvod;
        }
    }
    return [v,teskasi](double x)
    {
        double suma(0),sumay(0);
        for(int i(0);i<v.size();i++)
          {
              if(v[i].first==x) return v[i].second;
            sumay+=((teskasi[i]/(x-v[i].first))*v[i].second);
            suma+=(teskasi[i]/(x-v[i].first));
          }
          return sumay/suma;
    };
}

template <typename Baklava>

std::function<double(double)> BaricentricnaInterpolacija(Baklava f,double xmin, double xmax,double deltax,int d)
{
    if(xmin>xmax || deltax<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> v;
    for(;xmin<=xmax;xmin+=deltax)
        v.push_back(std::make_pair(xmin,f(xmin)));
    return BaricentricnaInterpolacija(v,d);
}

int main ()
{
    try
    {
        std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        int izbor(0); std::cin>>izbor;
        if(izbor==1)
        {
            std::cout<<"Unesite broj cvorova: ";
            int n; std::cin>>n;
            std::vector<std::pair<double,double>> v(n);
            std::cout<<"Unesite cvorove kao parove x y: ";
            for(int i(0);i<n;i++)
                std::cin>>v[i].first>>v[i].second;
            std::cout<<"Unesite red interpolacije: ";
            int d; std::cin>>d;
            auto f(BaricentricnaInterpolacija(v,d));
            for(;;)
            {
                std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                double x; std::cin>>x;
                if(!std::cin) return 0;
                std::cout<<"f("<<x<<") = "<<f(x)<<std::endl;
            }
        }
        else if(izbor==2)
        {
            std::cout<<"Unesite krajeve intervala i korak: ";
            double xmin,xmax,deltax; std::cin>>xmin>>xmax>>deltax;
            std::cout<<"Unesite red interpolacije: ";
            int d; std::cin>>d;
            auto f([](double x){ return x*x+std::sin(x); });
            auto fapprox(BaricentricnaInterpolacija(f,xmin,xmax,deltax,d));
            for(;;)
            {
                std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                double x; std::cin>>x;
                if(!std::cin) return 0;
                std::cout<<"f("<<x<<") = "<<f(x)<<" ";
                std::cout<<"fapprox("<<x<<") = "<<fapprox(x)<<std::endl;
            }
        }
    }
    catch(std::domain_error izuzetak)
    {
        std::cout<<izuzetak.what();
    }
    	return 0;
}