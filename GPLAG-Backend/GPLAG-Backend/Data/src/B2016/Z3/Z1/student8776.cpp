#include <iostream>
#include <functional>
#include <vector>
#include <utility>
#include <stdexcept>
#include <cmath>

std::function<double(double)> BaricentricnaInterpolacija (std::vector<std::pair<double,double>> v, int d)
{
    int n = v.size();
    if (d<0 || d>n)
        throw std::domain_error ("Nedozvoljen red");
        
    for (int i{};i<n-1;i++)
        {
            for (int j{i+1};j<n;j++)
                {
                    if (v[i].first == v[j].first)
                        throw std::domain_error ("Neispravni cvorovi");
                }
        }
        
        
    return [v,d,n] (double x)
    {
        double gornja_suma = 0;
        double donja_suma = 0;
        
        for (int i{1};i<=n;i++)
            {
                if (v[i-1].first == x)
                    return v[i-1].second;
                    
                int pocetak;
                if (1>i-d)
                    pocetak = 1;
                else
                    pocetak = i-d;
                    
                int kraj;
                if (i<n-d)
                    kraj = i;
                else
                    kraj = n-d;
                    
                double suma_w = 0;
                for (int k = pocetak;k<=kraj;k++)
                    {
                        double produkt = 1;
                        for (int j{k};j<=k+d;j++)
                            {
                                if (i != j)
                                    produkt = produkt/(v[i-1].first - v[j-1].first);
                            }
                        suma_w += produkt * (double)std::pow(double(-1),double(k-1));
                    }
                
                gornja_suma += suma_w/(x-v[i-1].first)*v[i-1].second;
                donja_suma += suma_w/(x-v[i-1].first);
                
            }
            
        return gornja_suma/donja_suma;
        
    };
    
}

std::function<double(double)> BaricentricnaInterpolacija (std::function<double(double)> f, double x_min, double x_max, double delta_x, int d)
{
    if (x_min>x_max || delta_x<=0)
        throw std::domain_error ("Nekorektni parametri");
        
    std::vector<std::pair<double,double>> v;
    double x = x_min;
    while (true)
        {
            if (x>x_max)
                break;
                
            double y = f(x);
            std::pair<double,double> par;
            par.first = x;
            par.second = y;
            
            v.push_back(par);
            x+=delta_x;
        }
    
    return BaricentricnaInterpolacija(v,d);
}

double Zadana_funkcija (double x)
{
    return x*x+std::sin(x);
}



int main ()
{
    try
    {
        std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        int odabir;
        std::cin>>odabir;
        std::cin.ignore(10000, '\n');
        
        if (odabir == 1)
            {
                std::cout<<"Unesite broj cvorova: ";
                int n;
                std::cin>>n;
                std::cin.ignore(10000, '\n');
                
                std::cout<<"Unesite cvorove kao parove x y: ";
                std::vector<std::pair<double,double>> v;
                for (int i{};i<n;i++)
                    {
                        double x,y;
                        std::cin>>x>>y;
                        std::cin.ignore(10000, '\n');
                        
                        std::pair<double,double> par;
                        par.first = x;
                        par.second = y;
                        v.push_back(par);
                    }
                    
                std::cout<<"Unesite red interpolacije: ";
                int d;
                std::cin>>d;
                std::cin.ignore(10000, '\n');
                
                auto f = BaricentricnaInterpolacija(v,d);
                while (true)
                {
                    std::cout<<"Unesite argument (ili "<<'"'<<"kraj"<<'"'<<" za kraj): ";
                    double x;
                    std::cin>>x;
                    
                    if (!std::cin)
                        break;
                        
                    std::cout<<"f("<<x<<") = "<<f(x)<<std::endl;
                }
            }
        else if (odabir == 2)
            {
                std::cout<<"Unesite krajeve intervala i korak: ";
                double x_min,x_max,delta_x;
                std::cin>>x_min>>x_max>>delta_x;
                std::cin.ignore(10000, '\n');
                
                std::cout<<"Unesite red interpolacije: ";
                int d;
                std::cin>>d;
                std::cin.ignore(10000, '\n');
                
                auto f = BaricentricnaInterpolacija(Zadana_funkcija,x_min,x_max,delta_x,d);
                
                while (true)
                {
                    std::cout<<"Unesite argument (ili "<<'"'<<"kraj"<<'"'<<" za kraj): ";
                    double x;
                    std::cin>>x;
                    
                    if (!std::cin)
                        break;
                        
                    std::cout<<"f("<<x<<") = "<<Zadana_funkcija(x)<<" fapprox("<<x<<") = "<<f(x)<<std::endl;
                }
            }
            
        
    }
    catch (std::domain_error e)
    {
        std::cout<<e.what();
    }
    
	return 0;
}