/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <stdexcept>
#include <cmath>

int min(int a, int b)
{
    if (a < b) return a;
    else return b;
}

int max(int a, int b)
{
    if (a > b) return a;
    else return b;
}

double w(int i, int d, std::vector <std::pair<double, double>> cvorovi)
{
    double W(0);
    
    for (int k = max(1, i - d); k <= min(i, cvorovi.size() - d); k++)
    {
        double proizvod(1);
        for (int j = k; j <= k + d; j++)
        {
            if (j != i) 
                proizvod *= 1/(cvorovi[i - 1].first - cvorovi[j - 1].first); 
        }
        W += std::pow(-1, k - 1)*proizvod;
    }
    return W;
}

std::function<double(double)> BaricentricnaInterpolacija(std::vector <std::pair<double, double>> cvorovi, int d)
{
    if (d < 0 || d >= cvorovi.size())
        throw std::domain_error("Nedozvoljen red");
    for (int i = 0; i < int(cvorovi.size()) - 1; i++)
        for (int j = i + 1; j < cvorovi.size(); j++)
            if (cvorovi[i] == cvorovi[j])
                throw std::domain_error("Neispravni cvorovi");
    std::vector<double>W;
    for (int i = 0; i < cvorovi.size(); i++)
        W.push_back(w(i + 1, d, cvorovi));
    return 
    [cvorovi, d, W](double x)
    {
         double brojnik(0), nazivnik(0);
         
         for (int i = 0; i < cvorovi.size(); i++) if (cvorovi[i].first == x) return cvorovi[i].second; 
         for (int i = 0; i < cvorovi.size(); i++)
         {
             brojnik += (W[i]/(x - cvorovi[i].first))*cvorovi[i].second;
             nazivnik +=  W[i]/(x - cvorovi[i].first);
         }
         return brojnik/nazivnik;
    };
}

std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> f, double xmin, double xmax, double dx, int d)
{
    if (xmin > xmax || dx <= 0) throw std::domain_error("Nekorektni parametri");
    std::vector <std::pair<double, double>> cvorovi;
    while (xmin <= xmax)
    {
        cvorovi.push_back(std::make_pair(xmin, f(xmin)));
        xmin += dx;
    }
    return BaricentricnaInterpolacija(cvorovi, d);
}

double f(double x)
{
    return x*x + std::sin(x);
}

int main ()
{
    int opcija;
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin >> opcija;
    try
    {
        if (opcija == 1)
        {
            int br_cvorova;
            std::cout << "Unesite broj cvorova: ";
            std::cin >> br_cvorova;
            std::vector<std::pair<double, double>> cvorovi(br_cvorova);
            std::cout << "Unesite cvorove kao parove x y: ";
            for (int i = 0; i < br_cvorova; i++) 
                std::cin >> cvorovi[i].first >> cvorovi[i].second;
            int red;
            std::cout << "Unesite red interpolacije: ";
            std::cin >> red;
            for(;;)
            {
                double argument;
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                std::cin >> argument;
                if (!std::cin) break;
                std::cout << "f(" << argument << ") = " << BaricentricnaInterpolacija(cvorovi, red)(argument) << "\n";
            }
        }
        else if (opcija == 2)
        {
            double xmin, xmax, dx;
            std::cout << "Unesite krajeve intervala i korak: ";
            std::cin >> xmin >> xmax >> dx;
            int red;
            std::cout << "Unesite red interpolacije: ";
            std::cin >> red;
            for (;;)
            {
                double argument;
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                std::cin >> argument;
                if (!std::cin) break;
                std::cout << "f(" << argument << ") = " << f(argument) << " fapprox(" << argument << ") = " 
                << BaricentricnaInterpolacija(f, xmin, xmax, dx, red)(argument) << "\n";
            }
        }
    }
    catch (std::domain_error e)
    {
        std::cout << e.what();
    }
	return 0;
}