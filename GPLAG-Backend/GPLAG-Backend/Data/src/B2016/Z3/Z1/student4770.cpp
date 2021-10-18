/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <utility>
#include <functional>
#include <cmath>
#include <vector>
#include <stdexcept>
double xsinx (double x)
{
    return x * x + std::sin(x);
}
std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double, double>> v, int d)
{
    if(d < 0 || d >= v.size() ) throw std::domain_error("Nedozvoljen red");
    int n = v.size();
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(v[i].first == v[j].first)
                throw std::domain_error("Neispravni cvorovi");
        }
    }
    std::vector<double>w(n);
    for(int i = 1; i <= n; i++)
    {
        int min = i;
        if(n - d < i) min = n - d;
        int max = 1;
        if(i - d > 1) max = i - d;
        double suma(0);
        for(int k = max; k <= min; k++)
        {
            double proizvod = 1;
            for(int j = k; j <= k + d; j++)
            {
                if(j == i) continue;
                proizvod *= 1./(v[i-1].first - v[j-1].first);
            }
            if(k % 2  == 0) proizvod *= (-1);
            //proizvod *= std::pow(-1, k - 1);
            suma += proizvod;
        }
        w[i-1] = suma;
    }
    return [w, v, n](double x) { 
    for(int i = 0; i < n; i++) if(x == v[i].first) return v[i].second;
    double suma1 = 0, suma2 = 0;
    for(int i = 1; i <= n; i++) suma1 += (w[i-1]/(x-v[i-1].first))*v[i-1].second;
    for(int i = 1; i <= n; i++) suma2 += (w[i-1]/(x-v[i-1].first));
    return suma1/suma2;
    };
}
std::function<double(double)> BaricentricnaInterpolacija(double f(double), double xmin, double xmax, double deltax, int d)
{
    if(xmin > xmax || deltax <= 0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double, double>> v;
    int i(0);
    while(xmin <= xmax)
    {
        v.resize(i+1);
        v[i].first = xmin;
        v[i].second = f(v[i].first);
        xmin += deltax;
        i++;
    }
    std::function<double(double)> g(BaricentricnaInterpolacija(v, d));
    return g;
}
int main ()
{
    try {
        std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        int opcija;
        std::cin>>opcija;
        if(opcija == 1)
        {
            int n;
            std::cout<<"Unesite broj cvorova: ";
            std::cin>>n;
            std::cout<<"Unesite cvorove kao parove x y: ";
            std::vector<std::pair<double, double>>v(n);
            for(int i = 0; i < n; i++)
                std::cin>>v[i].first>>v[i].second;
            int d;
            std::cout<<"Unesite red interpolacije: ";
            std::cin>>d;
            auto f(BaricentricnaInterpolacija(v, d));
            while(1)
            {
                double x;
                std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                std::cin>>x;
                if(!std::cin || std::cin.peek() != '\n') break;
                std::cout<<"f("<<x<<") = "<<f(x);
                std::cout<<std::endl;
            }
        }
        else if(opcija == 2)
        {
            double xmin, xmax, deltax;
            std::cout<<"Unesite krajeve intervala i korak: ";
            std::cin>>xmin>>xmax>>deltax;
            std::cout<<"Unesite red interpolacije: ";
            int d;
            std::cin>>d;
            auto f(BaricentricnaInterpolacija(xsinx, xmin, xmax, deltax, d));
            while(1)
            {
                std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                double x;
                std::cin>>x;
                if(!std::cin || std::cin.peek() != '\n') break;
                std::cout<<"f("<<x<<") = "<<xsinx(x);
                std::cout<<" fapprox("<<x<<") = ";
                std::cout<<f(x);
                std::cout<<std::endl;
            }
        }
    }
    catch(std::domain_error izuzetak) {
          std::cout<<izuzetak.what();
    }
	return 0;
}