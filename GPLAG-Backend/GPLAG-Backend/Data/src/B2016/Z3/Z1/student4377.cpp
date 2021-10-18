/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <functional>
#include <vector>
#include <cmath>

double w(int i,std::vector<std::pair<double, double>> cvorovi, int d)
{
    int gornja(i), donja(1);
    if(i-d>1) donja = i-d;
    if(cvorovi.size()-d<i) gornja = cvorovi.size()-d;
    double suma(0);
    for(int k=donja; k<=gornja; k++)
    {
        double proizvod(1);
        for(int j=k; j<=k+d; j++)
        {
            if(i==j) continue;
            proizvod *= (1./(cvorovi[i-1].first - cvorovi[j-1].first));
        }
        suma += proizvod*pow(-1, k-1);
    }
    return suma;
}

std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double, double>> cvorovi, int d)
{
    if(d < 0 || d>cvorovi.size()) throw std::domain_error("Nedozvoljen red");
    for(int i=0; i<cvorovi.size(); i++)
    for(int j=0; j<cvorovi.size(); j++)
    if(i != j && cvorovi[i].first == cvorovi[j].first) throw std::domain_error("Neispravni cvorovi");
    return [cvorovi, d] (double x) 
    {
        double suma1(0), suma2(0);
        for(int i=1; i<=cvorovi.size(); i++)
        if(x-cvorovi[i-1].first != 0)
        suma1 += w(i, cvorovi, d)*cvorovi[i-1].second/(x-cvorovi[i-1].first);
        else return cvorovi[i-1].second;
        for(int i=1; i<=cvorovi.size(); i++)
        if(x-cvorovi[i-1].first != 0)
        suma2 += w(i, cvorovi, d)/(x-cvorovi[i-1].first);
        else return cvorovi[i-1].second;
        return suma1/suma2;
    };
}


std::function<double(double)> BaricentricnaInterpolacija(double f(double), double xmin, double xmax, double delta, int d)
{
    if(xmin > xmax || delta <= 0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double, double>> cvorovi;
    while(xmin <= xmax)
    {
        auto fun(f(xmin));
        cvorovi.push_back(std::make_pair(xmin, fun));
        xmin+=delta;
    }
    return BaricentricnaInterpolacija(cvorovi, d);
}
int main ()
{
    try
    {
        std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        int n;
        std::cin >> n;
        if(n == 1)
        {
            std::cout << "Unesite broj cvorova: ";
            int br;
            std::cin >> br;
            std::vector<std::pair<double, double>> cvorovi(br);
            std::cout << "Unesite cvorove kao parove x y: ";
            for(int i=0; i<br; i++)
            {
                double a,b;
                std::cin >> a >> b;
                cvorovi[i] = std::make_pair(a,b);
            }
            std::cout << "Unesite red interpolacije: ";
            int d;
            std::cin >> d;
            double x;
            for(;;)
            {
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                if(!(std::cin >> x)) break;
                std::cout << "f(" << x << ") = " << BaricentricnaInterpolacija(cvorovi, d)(x) << std::endl;
            }
        }
        else if(n == 2)
        {
            std::cout << "Unesite krajeve intervala i korak: ";
            double x1,x2,delta;
            std::cin >> x1 >> x2 >> delta;
            int d;
            std::cout << "Unesite red interpolacije: ";
            std::cin >> d;
            double x;
            for(;;)
            {
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                if(!(std::cin >> x)) break;
                std::cout << "f(" << x << ") = " << x*x + sin(x) << " fapprox(" << x << ") = " << BaricentricnaInterpolacija([] (double e) {return e*e + sin(e);}, x1,x2,delta,d)(x) << std::endl;
            }
        }
    } 
    catch(std::domain_error a) 
    {
        std::cout << a.what() << std::endl;
    }
    return 0;
}