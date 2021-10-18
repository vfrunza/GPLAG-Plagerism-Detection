/B2016/2017: Zadaća 3, Zadatak 1
#include <functional>
#include <stdexcept>
#include <iostream>
#include <utility>
#include <vector>
#include <cmath>

bool JesuLiJednaki (double x, double y, double Eps = 1e-10) {
    return std::fabs(x - y)<= Eps * (std::fabs(x) +std::fabs(y));
}

int VratiVeciBroj (int x, int y) {
    if (x > y)  return x;   else return y;
}

int VratiManjiBroj (int x, int y) {
    if (x < y)  return x;   else return y;
}

std::function<double(double)> BaricentricnaInterpolacija (const std::vector<std::pair<double, double>> &cvorovi, const int &d)
{
    if (d < 0 or d >= cvorovi.size())     throw std::domain_error ("Nedozvoljen red");
    for (int i=0; i<cvorovi.size()-1; ++i) for (int j=i+1; j<cvorovi.size(); ++j)
    if (JesuLiJednaki(cvorovi[i].first, cvorovi[j].first)) throw std::domain_error ("Neispravni cvorovi");
            
    return [=] (double x) -> double {
        
        std::vector<double> Wi;
        for (int i=1; i<=cvorovi.size(); ++i) {
            double Wi_(0); int gr1{VratiVeciBroj(1, i-d)}; int gr2{VratiManjiBroj(i, cvorovi.size() - d)};
            for (int k=gr1; k<=gr2; ++k) {
                double proizvod(1);
                for (int j=k; j<=k+d; ++j) {
                    if (i==j)   continue;
                    else proizvod *= 1./(cvorovi[i-1].first - cvorovi[j-1].first);
                }   Wi_ += std::pow(-1, k-1) * proizvod;
            }   Wi.push_back(Wi_);
        }
        
        double suma_brojnika(0);
        for (int i=1; i<=cvorovi.size(); ++i) {
            if (JesuLiJednaki(x, cvorovi[i-1].first)) return cvorovi[i-1].second;
            else suma_brojnika += (Wi[i-1] * cvorovi[i-1].second) / (x - cvorovi[i-1].first);
        }
        
        double suma_nazivnika(0);
        for (int i=1; i<=cvorovi.size(); ++i) {
            if (JesuLiJednaki(x, cvorovi[i-1].first)) return cvorovi[i-1].second;
            else suma_nazivnika += Wi[i-1] / (x - cvorovi[i-1].first);
        }   return suma_brojnika/suma_nazivnika;
    };
}

typedef std::function<double(double)> dabl_fun;
dabl_fun BaricentricnaInterpolacija (dabl_fun fun, const double &xmin, const double &xmax, const double &deltax, const int &d) {
    if (xmin > xmax or deltax <= 0) throw std::domain_error ("Nekorektni parametri");

    std::vector<std::pair<double, double>> cvorovi;
    for (double i = xmin; i<=xmax; i += deltax) {
        std::pair<double, double> raspodjela_parova;
        raspodjela_parova.first = i;
        raspodjela_parova.second = fun(i);
        cvorovi.push_back(raspodjela_parova);
    }
    
    return [=] (double x) -> double {
        
        std::vector<double> Wi;
        for (int i=1; i<=cvorovi.size(); ++i) {
            double Wi_(0);  int gr1{VratiVeciBroj(1, i-d)}; int gr2{VratiManjiBroj(i, cvorovi.size() - d)};
            for (int k=gr1; k<=gr2; ++k) {
                double proizvod(1);
                for (int j=k; j<=k+d; ++j) {
                    if (i==j)   continue;
                    else proizvod *= 1./(cvorovi[i-1].first - cvorovi[j-1].first);
                }   Wi_ += std::pow(-1, k-1) * proizvod;
            }   Wi.push_back(Wi_);
        }
        
        double suma_brojnika(0);
        for (int i=1; i<= cvorovi.size() ; ++i) {
            if (JesuLiJednaki(x, cvorovi[i-1].first))       return cvorovi[i-1].second;
            else        suma_brojnika += (Wi[i-1] * cvorovi[i-1].second) / (x - cvorovi[i-1].first);
        }
        
        double suma_nazivnika (0);
        for (int i=1; i<=  cvorovi.size(); ++i) {
            if (JesuLiJednaki(x, cvorovi[i-1].first))               return cvorovi[i-1].second;
                                     else    suma_nazivnika += Wi[i-1] / (x- cvorovi[i-1].first);
        }   return suma_brojnika / suma_nazivnika;
    };
} 

int main ()
{
    try {
        int Odabrana_opcija;
        std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        std::cin >> Odabrana_opcija;
    
        if (Odabrana_opcija == 1) {
            int Broj_cvorova;
            std::cout << "Unesite broj cvorova: ";
            std::cin >> Broj_cvorova;
            std::cin.ignore(10000, '\n');
        
            std::vector<std::pair<double, double>> cvorovi;
            std::cout << "Unesite cvorove kao parove x y: ";
            for (int i=0; i<Broj_cvorova; ++i) {
                std::pair<double, double> unos_parova;
                std::cin >> unos_parova.first;
                std::cin >> unos_parova.second;
                cvorovi.push_back(unos_parova);
            }
        
            int red_interpolacije;
            std::cout << "Unesite red interpolacije: ";
            std::cin >> red_interpolacije;
            
            auto f(BaricentricnaInterpolacija(cvorovi, red_interpolacije));
        
            for (;;) {
                double argument_funkcije;
                std::cout << "Unesite argument (ili " << '"';
                std::cout << "kraj" << '"' << " za kraj): ";
                std::cin >> argument_funkcije;
                if (not(std::cin))  break;
                std::cout << "f(" << argument_funkcije << ") = ";
                std::cout << f(argument_funkcije) << std::endl;
            }
        }
        else if (Odabrana_opcija == 2) {
            double xmin, xmax, korak;
            std::cout << "Unesite krajeve intervala i korak: ";
            std::cin >> xmin;   std::cin >> xmax;   std::cin >> korak;
            
            int red_interpolacije;
            std::cout << "Unesite red interpolacije: ";
            std::cin >> red_interpolacije;
            
            auto f(BaricentricnaInterpolacija ([] (double x) { return (x*x + std::sin(x)); }, xmin, xmax, korak, red_interpolacije));
            
            for (;;) {
                double argument_funkcije;
                std::cout << "Unesite argument (ili " << '"';
                std::cout << "kraj" << '"' <<  " za kraj): ";
                std::cin >> argument_funkcije;
                if (not(std::cin))  break; // Ovo iz nekog razloga drugi put pišem :/
                std::cout << "f(" << argument_funkcije << ") = ";
                std::cout << std::pow(argument_funkcije, 2) + std::sin(argument_funkcije);
                std::cout << " fapprox(" << argument_funkcije << ") = " ;
                std::cout << f(argument_funkcije) << std::endl;
            }
        }
    }   catch (std::domain_error txt) {
        std::cout << txt.what() << std::endl;
    }   return 0;
}