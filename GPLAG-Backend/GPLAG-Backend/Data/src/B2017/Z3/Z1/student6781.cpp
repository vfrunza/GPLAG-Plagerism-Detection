/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <functional>

bool kriterij(std::pair<double, double> p1, std::pair<double, double> p2)
{
    return p1.first<p2.first;
}

std::function<double(double)> LinearnaInterpolacija (std::vector<std::pair<double, double>> cvorovi)
{
    std::sort(cvorovi.begin(), cvorovi.end(), kriterij);
    for(int i(0); i<cvorovi.size(); i++) {
        for(int j=i+1; j<cvorovi.size(); j++) if(std::abs(cvorovi[j].first-cvorovi[i].first)<0.000001) throw std::domain_error ("Neispravni cvorovi");
    }

    return [cvorovi](double x) {
        std::pair<double, double> temp {x,0};
        if(x<cvorovi[0].first || x>cvorovi[cvorovi.size()-1].first) throw std::range_error("Argument izvan opsega");
        if(std::abs(x-cvorovi[cvorovi.size()-1].first)<0.000001) return cvorovi[cvorovi.size()-1].second;
      //  auto donji(std::lower_bound(cvorovi.begin(), cvorovi.end(), temp, kriterij));
        auto gornji(std::upper_bound(cvorovi.begin(), cvorovi.end(), temp, kriterij));
        auto donji(gornji);
        donji--;
        double vrijednost(0);
        vrijednost=donji->second +((gornji->second-donji->second)/(gornji->first-donji->first))*(x-donji->first);
        return vrijednost;
    };
}
std::function<double(double)> LinearnaInterpolacija (std::function<double(double)> F, double xmin, double xmax, double delta)
{
    if(xmin>xmax || delta<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> cvorovi;
    double novi(xmin);
    while(novi<=xmax) {
        std::pair<double, double> par {novi, F(novi)};
        cvorovi.push_back(par);
        novi+=delta;
    }
    return LinearnaInterpolacija(cvorovi);
}


double testna(double x)
{
    return x*x+sin(x);
}

int main ()
{
    int izbor(0);
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin >> izbor;
    if(izbor==1) {
        int br_cvorova(0);
        std::cout << "Unesite broj cvorova: ";
        std::cin >> br_cvorova;
        std::vector<std::pair<double, double>> cvorovi (br_cvorova);
        std::cout << "Unesite cvorove kao parove x y: ";
        for(int i=0; i<br_cvorova; i++) std::cin >> cvorovi[i].first >> cvorovi[i].second;
        try {
            auto f(LinearnaInterpolacija(cvorovi));
            for(;;) {
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                double arg;
                std::cin >> arg;
                if(!std::cin) break;
                try {
                    double rezultat(f(arg));
                    std::cout << "f(" << arg << ") = " << rezultat << std::endl;
                } catch(std::range_error greska) {
                    std::cout << greska.what() << std::endl;
                }
            }
        } catch(std::domain_error greska) {
            std::cout << greska.what() << std::endl;
        }
    }
    if(izbor==2) {
        double xmin, xmax, delta;
        std::cout << "Unesite krajeve intervala i korak: ";
        std::cin >> xmin >> xmax >> delta;
        try {
            auto f(LinearnaInterpolacija(testna, xmin, xmax, delta));
            for(;;) {
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                double arg;
                std::cin >> arg;
                if(!std::cin) break;
                try {
                    double rezultat (f(arg));
                    std::cout << "f(" << arg << ") = " << testna(arg) << " fapprox(" << arg << ") = " << rezultat << std::endl;
                } catch(std::range_error greska) {
                    std::cout << greska.what() << std::endl;
                }
            }
        } catch(std::domain_error greska) {
            std::cout << greska.what() << std::endl;
        }
    }
    return 0;
}
