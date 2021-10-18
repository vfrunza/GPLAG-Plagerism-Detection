/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <utility>
#include <functional>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>

template <typename Tip> std::string PretvoriUString(Tip x) { std::ostringstream s; s << x; return s.str(); }

int Min(int x, int y) { if (x<y) return x; return y; }
int Max(int x, int y) { if (x>y) return x; return y; }

double f(double x) { return x*x+sin(x); }

std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double, double>> cvorovi, int d)
{
    int n(cvorovi.size());
    if (d<0 or d>=n) throw std::domain_error("Nedozvoljen red");
    for (int i=0; i<n; i++) 
        for (int j=i+1; j<n; j++) 
            if (cvorovi[i].first==cvorovi[j].first) throw std::domain_error("Neispravni cvorovi");
    double suma(0), proizvod(1);
    std::vector<double> w;
    for (int i=1; i<=n; i++)
    {
        suma=0;
        for (int k=Max(1, i-d); k<=Min(i, n-d); k++)
        {
            int j=k;
            proizvod=1;
            for (j=k; j<=k+d; j++) if (i!=j) proizvod*=(1./(cvorovi[i-1].first-cvorovi[j-1].first));
            proizvod*=pow(-1, k-1);
            suma+=proizvod;
        }
        w.push_back(suma);
    }
    return [w, cvorovi] (double x)
    {
        double suma_brojnik(0), suma_nazivnik(0);
        for (int i=1; i<=cvorovi.size(); i++)
        {
            if (x!=cvorovi[i-1].first)
            {
                suma_brojnik+=((w[i-1]/(x-cvorovi[i-1].first))*cvorovi[i-1].second);
                suma_nazivnik+=(w[i-1]/(x-cvorovi[i-1].first));
            }
            else return cvorovi[i-1].second;
        }
       return suma_brojnik/suma_nazivnik;
    };
}

std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> f, double xmin, double xmax, double dx, int d)
{
    if (xmin>xmax or dx<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double, double>> cvorovi;
    double i(xmin);
    while (i<=xmax)
    {
        double x=i;
        double y=f(i);
        cvorovi.push_back(std::make_pair(x, y));
        i+=dx;
    }
    return BaricentricnaInterpolacija(cvorovi, d);
}

int main ()
{
    
    int n;
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin >> n;
    if (n==1)
    {
        int broj;
        std::cout << "Unesite broj cvorova: ";
        std::cin >> broj;
        std::cout << "Unesite cvorove kao parove x y: ";
        std::vector<std::pair<double, double>> vektor_cvorova;
        for (int i=0; i<broj; i++)
        {
            std::pair<double, double> cvor;
            std::cin >> cvor.first >> cvor.second;
            vektor_cvorova.push_back(cvor);
        }
        int red;
        std::cout << "Unesite red interpolacije: ";
        std::cin >> red;
        std::string kraj_unosa("kraj");
        double argument;
        for (;;)
        {
            try
            {
                auto fun=BaricentricnaInterpolacija(vektor_cvorova, red);
                std::cout << "Unesite argument (ili " << '"'+kraj_unosa+'"' << " za kraj): ";
                std::cin >> argument;
                if (PretvoriUString(argument)==kraj_unosa or !std::cin) return 0;
                std::cout << "f(" << argument << ") = " << fun(argument) << std::endl;
            }
            catch(std::domain_error izuzetak)
            {
                std::cout << izuzetak.what() << std::endl;
                return 0;
            }
        }
    }
    else if (n==2) 
    {
        double poc, kraj, korak;
        std::cout << "Unesite krajeve intervala i korak: ";
        std::cin >> poc >> kraj >> korak;
        int red;
        std::cout << "Unesite red interpolacije: ";
        std::cin >> red;
        std::string kraj_unosa("kraj");
        double argument;
        for (;;)
        {
            try
            {
                auto nova=BaricentricnaInterpolacija(f, poc, kraj, korak, red);
                std::cout << "Unesite argument (ili " << '"'+kraj_unosa+'"' << " za kraj): ";
                std::cin >> argument;
                if (PretvoriUString(argument)==kraj_unosa or !std::cin) return 0;
                std::cout << "f(" << argument << ") = " << f(argument) << " " 
                    << "fapprox(" << argument << ") = " << nova(argument) << std::endl;
            }
            catch(std::domain_error izuzetak)
            {
                std::cout << izuzetak.what() << std::endl;
                return 0;
            }
        }
    }
	return 0;
}