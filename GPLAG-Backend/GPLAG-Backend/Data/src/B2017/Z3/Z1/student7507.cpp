/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <stdexcept>
#include <algorithm>
#include <cmath>


std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double, double>> parovi)
{

    std::sort(parovi.begin(), parovi.end(), [](std::pair<double, double> prvi, std::pair<double,double> drugi) {
        return prvi.first < drugi.first;
    });


    const double EPS(0.00000000000000000000001);


    for(int i=0; i<parovi.size(); i++) {
        for(int j=i+1; j<parovi.size(); j++) {
            if(std::fabs(parovi[i].first - parovi[j].first) < EPS)
                throw std::domain_error("Neispravni cvorovi");
        }
    }

    return [parovi] (double x) {
        if((x<parovi[0].first  || x>parovi[parovi.size()-1].first))
            throw std::range_error("Argument izvan opsega");

        std::pair<double, double> pom;
        pom.first=x;
        pom.second=0;
        const double EPS(0.00000000000000000000001);
        if(std::fabs(x - parovi[parovi.size()-1].first)<EPS) return parovi[parovi.size()-1].second;
        if(std::fabs(x - parovi[0].first) < EPS) return parovi[0].second;
        auto pok(upper_bound(parovi.begin(), parovi.end(), pom, [](std::pair<double, double> prvi, std::pair<double, double> drugi) {
            return prvi.first < drugi.first;
        }));

        auto pok2(pok-1);
        return pok2->second + ((pok->second - pok2->second)/(pok->first - pok2->first))*(x - pok2->first);
    }

    ;
}

std::function<double(double)>  LinearnaInterpolacija(std::function<double(double)>f, double min, double max, double dx)
{
    if(min > max || dx < 0) {
        throw std::domain_error ("Nekorektni parametri");
    }
    std::vector<std::pair<double,double>> cvorovi;
    for(; min<max; min+=dx) {
        std::pair<double,double> par(min, f(min));
        cvorovi.push_back(par);
    }
    return LinearnaInterpolacija(cvorovi);
}

double fja(double x)
{
    return pow(x,2)+std::sin(x);
}

int main ()
{
    try {
        for(;;) {
            std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): " ;
            int opcija;
            std::cin >> opcija;
            if(opcija == 1) {
                std::cout << "Unesite broj cvorova: ";
                int broj_cvorova;
                std::cin >> broj_cvorova;
                std::cout << "Unesite cvorove kao parove x y: ";
                std::vector<std::pair<double, double>> parovi;
                for(int i=0; i<broj_cvorova; i++) {
                    std::pair<double, double> par;
                    std::cin >> par.first >> par.second;
                    parovi.push_back(par);
                }

                auto f(LinearnaInterpolacija(parovi));

                for(;;) {
                    try {
                        std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                        double x;
                        std::cin >> x;
                        if(!std::cin) {
                            return 0;
                        }

                        auto funkcija(f(x));
                        std::cout << "f(" << x << ") = " << funkcija << std::endl;
                    } catch(std::range_error izuzetak) {
                        std::cout << izuzetak.what() << std::endl;
                    }
                }
            } else {
                std::cout << "Unesite krajeve intervala i korak: " ;

                double min, max, dx;
                std::cin >> min >> max >> dx;
                auto funkcija2(LinearnaInterpolacija(fja, min, max, dx));
                for(;;) {
                    try {
                        std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                        double x;
                        std::cin >> x;
                        if(!std::cin) return 0;

                        auto F(funkcija2(x));
                        std::cout << "f(" << x << ") = " << fja(x) << " fapprox(" << x << ") = " << F << std::endl;


                    } catch(std::range_error izuzetak) {
                        std::cout << izuzetak.what() << std::endl;
                    }
                }
            }
        }
    } catch(std::domain_error izuzetak) {
        std::cout << izuzetak.what() << std::endl;
    }
    return 0;
}
