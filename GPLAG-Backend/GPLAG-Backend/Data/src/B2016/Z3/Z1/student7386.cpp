/B2016/2017: Zadaća 3, Zadatak 1.
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)

#include <iostream>
#include <utility>
#include <vector>
#include <stdexcept>
#include <functional>
#include <cmath>

std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double, double>> vektor, int d)
{
    if(d<0 || d > vektor.size()) throw std::domain_error("Nedozvoljen red");
    for(int i=0; i<vektor.size(); i++)
    {
        for(int j=i+1; j<vektor.size(); j++)
        {
            if(vektor.at(i).first == vektor.at(j).first)
            {
                throw std::domain_error("Neispravni cvorovi");
            }
        }
    }
    return [vektor, d](double x) -> double
    {
        int n = vektor.size();
        double brojnik = 0;
        double nazivnik = 0;
        for(int i=0; i<n; i++)
        {
            if(x == vektor.at(i).first)
            {
                return vektor.at(i).second;
            }
            double w = 0;
            int min = i+1;
            int max = 1;
            if((n-d) < min) min = n-d;
            if((i+1-d) > max) max = i+1-d;
            for(int k = max; k<=min; k++)
            {
                double proizvod = 1;
                for(int j = k; j<=k+d; j++)
                {
                    if(j==i+1) continue;
                    proizvod = proizvod*(1/(vektor.at(i).first-vektor.at(j-1).first));
                }
                w += pow(-1, k-1)*proizvod;
            }
            brojnik += (w*vektor.at(i).second)/(x-vektor.at(i).first);
            nazivnik += w/(x-vektor.at(i).first);
        }
        return brojnik/nazivnik;
    };
}

std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> fun, double xmin, double xmax, double dx, int d)
{
    std::vector<std::pair<double, double>> vektor(0);
    if(xmin > xmax || dx <= 0) throw std::domain_error("Nekorektni parametri");
    double x = xmin;
    while(x<=xmax)
    {
        vektor.push_back(std::make_pair(x, fun(x)));
        x = x + dx;
    }
    return BaricentricnaInterpolacija(vektor, d);
}

int main ()
{
    try
    {
        std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        int unos;
        std::vector<std::pair<double, double>> vektor(0);
        std::cin >> unos;
        if(unos == 1)
        {
            int n;
            std::cout << "Unesite broj cvorova: ";
            std::cin >> n;
            std::cout << "Unesite cvorove kao parove x y: ";
            for(int i=0; i<n; i++)
            {
                int x,y;
                std::cin >> x >> y;
                vektor.push_back(std::make_pair(x,y));
            }
            std::cout << "Unesite red interpolacije: ";
            int d;
            std::cin >> d;
            for(;;)
            {
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                double x;
                std::cin >> x;
                if(std::cin.fail())
                {
                    return 0;
                }
                try
                {
                    std::cout << "f(" << x << ") = " << BaricentricnaInterpolacija(vektor, d)(x) << std::endl;    
                }
                catch(std::domain_error e)
                {
                    std::cout << e.what();
                    return 0;
                }
            }
        }
        if(unos == 2)
        {
            std::cout << "Unesite krajeve intervala i korak: ";
            double xmin, xmax, dx;
            std::cin >> xmin >> xmax >> dx;
            std::cout << "Unesite red interpolacije: ";
            int d;
            std::cin >> d;
            for(;;)
            {
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                double x;
                std::cin >> x;
                if(std::cin.fail())
                {
                    return 0;
                }
                try
                {
                    std::cout << "f(" << x << ") = " << x*x+std::sin(x) << " fapprox(" << x << ") = ";
                    std::cout << BaricentricnaInterpolacija([](double x) {return x*x+std::sin(x);}, xmin, xmax, dx, d)(x) << std::endl;
                }
                catch(std::domain_error e)
                {
                    std::cout << e.what();
                }
            }
        }
    }
    catch(std::domain_error e)
    {
        std::cout << e.what();
    }
    catch(...)
    {
        return 0;
    }
	return 0;
}