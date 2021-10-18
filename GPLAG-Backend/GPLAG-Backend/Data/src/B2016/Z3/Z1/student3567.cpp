/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include <functional>
const double epsilon(0.00001);

int intpow(int x, int y)
{
    int rez = 1;
    for(int i = 0; i < y; i++)
        rez *= x;
    return rez;
}

std::vector<double> racunajKoeficijente(std::vector<std::pair<double, double>> tacke, int d)
{
    std::vector<double> povratni;
    for(int i = 0; i < tacke.size(); i++)
    {
        double koef = 0;
        for(int k = (0 < i-d ? i-d : 0); k <= (i < tacke.size()-d-1 ? i : tacke.size()-d-1); k++)
        {
            double proizvod = 1;
            for(int j = k; j <= k+d; j++)
            {
                if(i == j) continue;
                proizvod *= 1. / (tacke[i].first - tacke[j].first);
            }
            koef += intpow(-1, k) * proizvod;
        }
        povratni.push_back(koef);
    }
    return povratni;
}
double funkcija(double x, std::vector<double> koeficijenti, std::vector<std::pair<double, double>> tacke)
{
    for(int i = 0; i < tacke.size(); i++)
        if(fabs(x - tacke[i].first) < epsilon) return tacke[i].second;
    double  nazivnik = 0, brojnik = 0;
    for(int i = 0; i < tacke.size(); i++)
        brojnik += (koeficijenti[i] / (x - tacke[i].first)) * tacke[i].second;
    for(int i = 0; i < tacke.size(); i++)
        nazivnik += koeficijenti[i] / (x - tacke[i].first);
    return brojnik / nazivnik;
}
std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double, double>> tacke, int d)
{
    if(d < 0 || d > tacke.size())
        throw std::domain_error("Nedozvoljen red");
    for(int i = 0; i < tacke.size()-1; i++)
        for(int j = i+1; j < tacke.size(); j++)
            if(fabs(tacke[i].first - tacke[j].first) < epsilon)
                throw std::domain_error("Neispravni cvorovi");
    std::vector<double> koef(racunajKoeficijente(tacke, d));
    return std::bind(funkcija, std::placeholders::_1, koef, tacke);
    
}
std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> fun, double xMin, double xMax, double deltaX, int d)
{
    if(xMin > xMax || deltaX <= 0)
        throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double, double>> tacke;
    double korak = xMin;
    while(korak <= xMax)
    {
        tacke.push_back(std::make_pair(korak, fun(korak)));
        korak += deltaX;
    }
    return BaricentricnaInterpolacija(tacke, d);
}
double funk(double x)
{
    return x * x + sin(x);
}
int main ()
{
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int izbor;
    std::cin >> izbor;
    if(izbor == 1)
    {
        double x,y;
        std::vector<std::pair<double,double>> tacke;
        std::cout << "Unesite broj cvorova: ";
        std::cin >> izbor;
        std::cout << "Unesite cvorove kao parove x y: ";
        for(int i = 0; i < izbor; i++)
        {
            std::cin >> x >> y;
            tacke.push_back(std::make_pair(x,y));
        }
        std::cout << "Unesite red interpolacije: ";
        std::cin >> izbor;
        std::function<double(double)> f = BaricentricnaInterpolacija(tacke, izbor);
        while(1)
        {
            std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
            while(!(std::cin >> x))
            {
                std::string kraj;
                std::cin.clear();
                std::getline(std::cin, kraj);
                if(kraj == "kraj")
                    return 0;
                
                
                std::cin.ignore(10000, '\n');
                std::cout << "Neispravan unos. Pokusajte ponovo: ";
            }
            std::cout << "f(" << x << ") = " << f(x) << "\n";
        }
    }
    else
    {
        double x, y, deltaX;
        std::cout << "Unesite krajeve intervala i korak: ";
        std::cin >> x >> y >> deltaX;
        std::cout << "Unesite red interpolacije: ";
        std::cin >> izbor;
        std::function<double(double)> f = BaricentricnaInterpolacija(funk, x, y, deltaX, izbor);
        while(1)
        {
            std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
            while(!(std::cin >> x))
            {
                return 0;
            }
            std::cout << "f(" << x << ") = " << funk(x) << " fapprox(" << x << ") = " << f(x) << std::endl;
        }
    }
	return 0;
}