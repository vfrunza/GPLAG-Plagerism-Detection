/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <functional>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stdexcept>
#include <utility>

double NapraviWi(int d, std::vector<std::pair<double, double>> v, int ii)
{
    int n = v.size();
    std::vector<double> xi, yi;
    for(int i = 0; i < v.size(); i++)
    {
        xi.push_back(v[i].first);
        yi.push_back(v[i].second);
    }
        std::vector<int> v1, v2;
        v2.push_back(ii); v2.push_back(n - d);
        v1.push_back(1); v1.push_back(ii - d);
        int gornja = *std::min_element(v2.begin(), v2.end());
        int k = *std::max_element(v1.begin(), v1.end());
        double suma = 0;
            for(int brojac = k; brojac <= gornja; brojac++)
            {
                double proizvod = 1;

                for(int j = brojac; j <= brojac + d; j++)
                {
                   if(ii != j) proizvod = proizvod*(1/(xi[ii - 1] - xi[j - 1]));
                }
                proizvod = proizvod*pow(-1, (brojac-1));
                suma = suma + proizvod;
            }

return suma;
}

std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double, double>> v, int d)
{
    if(d < 0 || d > v.size()) throw std::domain_error("Nedozvoljen red");

     std::vector<double> xi, yi;
    for(int i = 0; i < v.size(); i++)
    {
        xi.push_back(v[i].first);
        yi.push_back(v[i].second);
    }
    for(auto i = xi.begin(); i != xi.end(); i++)
        for(auto j = i + 1; j != xi.end(); j++)
    {
        if(*i == *j) throw std::domain_error("Neispravni cvorovi");
    }
    return[v, d](double x)
    {
         int n = v.size();
    std::vector<double> xi, yi;
    for(int i = 0; i < v.size(); i++)
    {
        xi.push_back(v[i].first);
        yi.push_back(v[i].second);
    }
        double suma1(0), suma2(0), suma(0);
        for(int i = 1; i <= n; i++)
        {
            double wi = NapraviWi(d, v, i);
            if(x != xi[i - 1]){
                    suma1= suma1 + (wi/(x - xi[i - 1]))*yi[i - 1];
                    suma2 = suma2 + wi/(x - xi[i - 1]);
                    suma = suma1/suma2;
                              }
            else{ return yi[i - 1]; }

        }
        return suma;
    };

}
std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> f, double xmin, double xmax, double deltaX, int d)
{
    if(xmin > xmax || deltaX <= 0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double, double>> v;
    for(double i = xmin; i <= xmax; i = i + deltaX)
    {
        auto temp(std::make_pair(i, f(i)));
        v.push_back(temp);
    }
    return BaricentricnaInterpolacija(v, d);
}

int main()
{
    try
    {

        while(1)
            {
            int opcija(0);
            std::vector<std::pair<double, double>> v;
            std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
            std::cin>>opcija;
        if(opcija == 1)
        {
            int broj_cvorova(0);
            std::cout<<"Unesite broj cvorova: ";
            std::cin>>broj_cvorova;
            std::cout<<"Unesite cvorove kao parove x y: ";
            double x(0), y(0);
            for(int i = 0; i < broj_cvorova; i++)
            {
                std::cin>>x;
                std::cin>>y;
                v.push_back(std::make_pair(x, y));
            }
            std::cout<<"Unesite red interpolacije: ";
            int red_interpolacije(0);
            std::cin>>red_interpolacije;
            while(1)
            {
                double argument(0);
                std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                std::cin>>argument;
                if(!std::cin)
                        {
                            std::cin.clear();
                            std::cin.ignore(10000, '\n');
                            return 0;
                        }
                std::cout<<"f("<<argument<<") = "<<BaricentricnaInterpolacija(v, red_interpolacije)(argument)<<"\n";

            }

        }
        if(opcija == 2)
        {
            std::cout<<"Unesite krajeve intervala i korak: ";
            double poc_int(0), kraj_int(0), korak(0);
            std::cin>>poc_int;
            std::cin>>kraj_int;
            std::cin>>korak;
            std::cout<<"Unesite red interpolacije: ";
            int red_interpolacije(0);
            std::cin>>red_interpolacije;
            while(1)
            {
                double argument(0);
                std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                std::cin>>argument;
                if(!std::cin)
                        {
                            std::cin.clear();
                            std::cin.ignore(10000, '\n');
                            return 0;
                        }
                std::cout<<"f("<<argument<<") = "<<argument*argument + std::sin(argument)<<" fapprox("<<argument<<") = "<<BaricentricnaInterpolacija([](double x){return x*x + std::sin(x);}, poc_int, kraj_int, korak, red_interpolacije)(argument)<<"\n";
            }
        }
        }
    }
    catch(std::domain_error x)
    {
        std::cout<<x.what();
    }
    return 0;
}
