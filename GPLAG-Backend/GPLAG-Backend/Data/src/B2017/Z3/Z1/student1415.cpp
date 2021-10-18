/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <functional>
#include <utility>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <cmath>

typedef std::vector<std::pair<double,double>> VektorParova;

std::function <double (double)> LinearnaIterpolacija (VektorParova kontejner)
{
    std::sort(kontejner.begin(), kontejner.end());

    for(int i = 0; i < kontejner.size(); i++) {
        int temp (std::count_if (kontejner.begin(), kontejner.end(), [kontejner,i] (std::pair<double,double> x ) {
            return x.first == kontejner.at(i).first;
        }));

        if (temp != 1) throw std::domain_error("Neispravni cvorovi");
    }

    return [kontejner] (double x ) {

        if (x < (*kontejner.begin()).first || x > (*(kontejner.end() - 1)).first)
            throw std::range_error ("Argument izvan opsega");
        std::pair<double,double> test {x,0};

        std::pair<double,double> veci {*std::lower_bound(kontejner.begin(), kontejner.end(), test)};
        std::pair<double,double> manji {*(std::upper_bound(kontejner.begin(), kontejner.end(), test) -1) };
        return manji.second + ((veci.second - manji.second)/ (veci.first - manji.first)) * (x - manji.first);
    };
}

std::function <double(double)> LinearnaIterpolacija(std::function<double(double)> f, double min, double max, double korak)
{
    VektorParova aproksimacija;
    while (min <= max) {
        std::pair <double, double> trenutni {min, f(min)};
        aproksimacija.push_back(trenutni);
        min+= korak;
    }
    return [aproksimacija](double x) {
        auto nova ( LinearnaIterpolacija(aproksimacija));
        return nova(x);
    };

}

int main ()
{
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int opcija;
    std::cin >> opcija;

    if(opcija == 1) {
        try {
            std::cout << "Unesite broj cvorova: ";
            int broj_cvorova;
            std::cin >> broj_cvorova;

            std::cout << "Unesite cvorove kao parove x y: ";

            VektorParova kontejner;

            for(int i = 0; i < broj_cvorova; i++) {
                double x, y;
                std::cin >> x >> y;
                std::pair<double, double> trenutni {x , y};
                kontejner.push_back(trenutni);
            }

            auto f(LinearnaIterpolacija(kontejner));
            double argument;

            std::cout << "Unesite argument (ili \"kraj\" za kraj): ";

            while(std::cin >> argument) {
                try {
                    std::cout << "f(" << argument << ") = " << f(argument) << std::endl;
                } catch(const std::exception &e) {
                    std::cout << e.what() << std::endl;
                    std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                    continue;
                }
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
            }
        } catch (const std::exception & e) {
            std::cout << e.what() << std::endl;
        }

    }

    else if(opcija == 2) {
        std::cout << "Unesite krajeve intervala i korak: ";
        double min, max, korak;
        std::cin >> min >> max >> korak;

        auto g (LinearnaIterpolacija([](double x) {
            return x*x + std::sin(x);
        }, min, max, korak));

        double argument;
        std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
        while (std::cin >> argument) {
            try {
                std::cout << "f(" << argument << ") = " << argument * argument + std::sin(argument)
                          << " fapprox(" << argument << ") = " << g(argument) << std::endl;
            } catch(const std::exception &e) {
                std::cout << e.what() << std::endl;
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                continue;
            }

            std::cout << "Unesite argument (ili \"kraj\" za kraj): ";

        }
    }



    return 0;
}
