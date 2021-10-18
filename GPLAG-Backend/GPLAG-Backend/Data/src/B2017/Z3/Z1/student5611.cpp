/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <iterator>
#include <cmath>
#include <functional>

typedef std::vector<std::pair<double,double>> Vektor;
typedef std::pair<double, double> Par;
typedef std::function<double(double)> Omotac;

bool FunkcijaKriterija(const Par &p1, const Par &p2)
{
    if(p1.first == p2.first) throw std::domain_error ("Neispravni cvorovi");
    return p1.first < p2.first;
}

void SortirajVektor(Vektor &parovi)
{
    return std::sort(parovi.begin(), parovi.end(), FunkcijaKriterija);
}

bool FunkcijaKriterija_2(Par prvi, Par drugi)
{
    return prvi.first < drugi.first;
}

double Formula(const Par &prvi, const Par &drugi, double x)
{
    return prvi.second + ((drugi.second - prvi.second)/(drugi.first-prvi.first))*(x-prvi.first);
}

Omotac LinearnaInterpolacija(Vektor &parovi)
{

    SortirajVektor(parovi); //sortira vektor i provjerava da li postoje iste x koordinate parova u vektoru

    try {
        return[parovi](double x) {
            if(x<parovi[0].first || x>parovi[parovi.size()-1].first) throw std::range_error ("Argument izvan opsega");
            Par pomocni_par;
            pomocni_par.first = x;
            pomocni_par.second = std::numeric_limits<double>::min();
            auto iter(lower_bound(parovi.begin(), parovi.end(), pomocni_par, FunkcijaKriterija_2));
            if(iter != parovi.end()) {
                return Formula(*(iter-1), *iter, x);
            }
            return parovi[parovi.size()-1].second;
        };
    } catch(...) {
        throw;
    }
}

Omotac LinearnaInterpolacija(Omotac funkcija, double xmin, double xmax, double deltax)
{
    if(deltax <= 0 || xmin>xmax) throw std::domain_error ("Nekorektni parametri");
    return[funkcija, xmin, xmax, deltax](double x) {
        if(x<xmin || x>xmax) throw std::range_error ("Argument izvan opsega");
        int brojac(0);
        Par prvi_par, drugi_par;
        while((xmin + brojac*deltax)<xmax) {
            prvi_par.first = xmin + brojac*deltax;
            prvi_par.second = funkcija(xmin + brojac*deltax);
            //brojac++;
            drugi_par.first = xmin + (brojac+1)*deltax;
            drugi_par.second = funkcija(xmin + (brojac+1)*deltax);
            if(prvi_par.first<=x && x<drugi_par.first) break;
            brojac++;
        }
        return Formula(prvi_par, drugi_par, x);
    };
}

int main ()
{
    int opcija(0);
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin >> opcija;   
    try {
        if(opcija == 1) {
            Vektor parovi;
            std::cout << "Unesite broj cvorova: ";
            int br_cvorova;
            std::cin >> br_cvorova;
            std::cout << "Unesite cvorove kao parove x y: ";
            for(int i=0; i<br_cvorova; i++) {
                double prva_koordinata, druga_koordinata;
                std::cin >> prva_koordinata;
                std::cin >> druga_koordinata;
                Par pomocni;
                pomocni=std::make_pair(prva_koordinata, druga_koordinata);
                parovi.push_back(pomocni);
            }

            double argument(0);

            do {
                auto funkcija(LinearnaInterpolacija(parovi));

                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                std::cin >> argument;
                if(!std::cin) break;
                double rezultat(funkcija(argument));

                std::cout << "f(" << argument << ") = " << rezultat;
                std::cout << std::endl;

            } while(std::cin);
        }
    } catch (std::domain_error IZUZETAK) {
        std::cout << IZUZETAK.what() << std::endl;
    } catch (std::range_error IZUZETAK) {
        std::cout << IZUZETAK.what() << std::endl;
    }

    if(opcija == 2) {
        std::cout << "Unesite krajeve intervala i korak: ";
        double xmin, xmax, deltax;
        std::cin >> xmin >> xmax >> deltax;

        double argument(0);

        do {

            try {
                auto funkcija(LinearnaInterpolacija([](double x) {
                    return x*x + sin(x);
                }, xmin, xmax, deltax));

                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                std::cin >> argument;
                if(!std::cin) break;

                double rezultat(argument*argument + sin(argument));
                std::cout << "f(" << argument << ") = " << rezultat << " fapprox(" << argument << ") = " << funkcija(argument) << std::endl;
            } catch (std::domain_error IZUZETAK) {
                std::cout << IZUZETAK.what() << std::endl;
            } catch (std::range_error IZUZETAK) {
                std::cout << IZUZETAK.what() << std::endl;
            }

        } while(std::cin);
    }
    return 0;
}
