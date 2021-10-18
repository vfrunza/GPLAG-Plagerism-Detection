/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <cmath>
#include <functional>
#include <algorithm>
#include <stdexcept>


double Aproksimacija(double x, std::pair<double, double> a, std::pair<double, double> b)
{
    double rezultat;
    rezultat=a.second+(b.second-a.second)*(x-a.first)/(b.first-a.first);
    return rezultat;
}


std::function <double(double)> LinearnaInterpolacija(std::function <double(double)> f, double x_min, double x_max, double dx)
{
    if(x_min>x_max || dx<0) throw std::domain_error("Nekorektni argumenti");
    std::vector<std::pair<double, double>> cvorovi;
    cvorovi.push_back(std::make_pair(x_min, f(x_min)));
    double pom=x_min+dx;
    while(pom<x_max) {
        cvorovi.push_back(std::make_pair(pom, f(pom)));
        pom+=dx;
    }
    cvorovi.push_back(std::make_pair(x_max, f(x_max)));
    std::function <double(double)> LinearnaInterpolacija(std::vector<std::pair<double, double>> cvorovi);
    return LinearnaInterpolacija(cvorovi);
}

std::function <double(double)> LinearnaInterpolacija(std::vector<std::pair<double, double>> cvorovi)
{
    std::sort(cvorovi.begin(), cvorovi.end(),
    [](std::pair<double, double> a, std::pair<double, double> b) {
        if(!(std::fabs(a.first-b.first)>0)) throw std::domain_error("Neispravni cvorovi");
        return a<b;
    });
    return [cvorovi](double x) {
        if(x<cvorovi.at(0).first || x>cvorovi.at(cvorovi.size()-1).first) throw std::range_error("Argument izvan opsega");
        if(!(std::fabs(x-cvorovi.at(cvorovi.size()-1).first)>0)) return cvorovi.at(cvorovi.size()-1).second;
        double rezultat;
        auto p(cvorovi.end());
        p--;
        auto gornja=std::upper_bound(cvorovi.begin(), p, std::make_pair(x, 0.0));
        auto donja(gornja);
        donja--;
        rezultat=Aproksimacija(x, *donja, *gornja);
        return rezultat;
    };
}

int main ()
{
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int n;
    std::cin >> n;
    if(n==1) {
        std::cout << "Unesite broj cvorova: ";
        int duzina;
        while(!(std::cin >> duzina), !(duzina>=0));
        try {
            std::vector<std::pair<double, double>> cvorovi(duzina);
            std::cout << "Unesite cvorove kao parove x y: ";
            for(int i(0); i<duzina; i++) {
                std::cin >> cvorovi.at(i).first >> cvorovi.at(i).second;
                std::cin.ignore(2, '\n');
            }
            auto funkcija(LinearnaInterpolacija(cvorovi));
            while(true) {
                std::printf("Unesite argument (ili \"kraj\" za kraj): ");
                std::string kraj("");
                double argument;
                if(!(std::cin >> argument)) break;
                try {
                    double rezultat(funkcija(argument));
                    std::cout << "f(" << argument << ") = " <<  rezultat << std::endl;
                } catch(std::domain_error p) {
                    throw;
                } catch(std::range_error p) {
                    std::cout << p.what() << std::endl;
                }
            }
        } catch(std::domain_error p) {
            std::cout << p.what() << std::endl;
        } catch(...) {
            std::cout << "Nedovoljno memorije!" << std::endl;
        }
    } else if(n==2) {
        std::cout << "Unesite krajeve intervala i korak: ";
        double x_min, x_max, korak;
        std::cin >> x_min >> x_max >> korak;
        std::cin.ignore(2, '\n');
        try {
            auto f([](double x) {
                return std::pow(x, 2)+std::sin(x);
            });
            auto funkcija(LinearnaInterpolacija(f, x_min, x_max, korak));
            while(true) {
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                std::string kraj("");
                double argument;
                if(!(std::cin >> argument)) break;
                try {
                    double rezultat(funkcija(argument));
                    std::cout << "f(" << argument << ") = " << f(argument) <<
                              " fapprox(" << argument << ") = " << rezultat << std::endl;
                } catch(std::domain_error) {
                    throw;
                } catch(std::range_error p) {
                    std::cout << p.what() << std::endl;
                }
            }
        } catch(std::domain_error p) {
            std::cout << p.what() << std::endl;
        }
    }
    return 0;
}
