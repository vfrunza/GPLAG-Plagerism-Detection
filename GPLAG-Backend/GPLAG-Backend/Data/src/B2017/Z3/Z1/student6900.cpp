/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <functional>
#include <utility>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <iterator>
#include <cmath>

std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double, double>> cvorovi)
{
    if (cvorovi.size()!=0) {
        int i(0);
        for (; i < cvorovi.size()-1; i++)
            if (cvorovi.at(i).first>cvorovi.at(i+1).first)
                break;
        if (i!=cvorovi.size()-1)
            std::sort(cvorovi.begin(), cvorovi.end(), [] (std::pair<double, double> cvor1, std::pair<double, double> cvor2) {
            return cvor1.first < cvor2.first;
        });
        for (i = 0; i < cvorovi.size()-1; i++)
            if (cvorovi.at(i).first==cvorovi.at(i+1).first)
                throw std::domain_error("Neispravni cvorovi");
    }
    return [cvorovi] (double x) {
        if (cvorovi.size()==0 || x<cvorovi.at(0).first || x>cvorovi.at(cvorovi.size()-1).first)
            throw std::range_error("Argument izvan opsega");
        if (x==cvorovi.at(cvorovi.size()-1).first)
            return cvorovi.at(cvorovi.size()-1).second;
        auto sljedeci(std::lower_bound(cvorovi.begin(), cvorovi.end(), std::pair<double, double> (x, 0)));
        auto prethodni(sljedeci-1);
        return prethodni->second + (((sljedeci->second - prethodni->second) / (sljedeci->first - prethodni->first)) * (x - prethodni->first));
    };
}

template <typename funkcija>
std::function<double(double)> LinearnaInterpolacija(funkcija f, double min, double max, double delta)
{
    if (min>max || delta<=0)
        throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double, double>> novi_cvorovi;
    for (int i = 0; min+(i*delta)<=max; i++)
        novi_cvorovi.push_back(std::make_pair(min+(i*delta), f(min+(i*delta))));
    return [novi_cvorovi] (double x) {
        return LinearnaInterpolacija(novi_cvorovi)(x);
    };
}

double funkcija(double x)
{
    return x * x + sin(x);
}

bool Unos(double &argument)
{
    std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
    std::cin >> argument;
    if (!std::cin) {
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        return false;
    }
    return true;
}

int main ()
{
    int opcija(0);
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin >> opcija;
    if (opcija==1) {
        int br_cvorova;
        std::cout << "Unesite broj cvorova: ";
        std::cin >> br_cvorova;
        std::cout << "Unesite cvorove kao parove x y: ";
        std::vector<std::pair<double, double>> cvorovi;
        for (int i = 0; i < br_cvorova; i++) {
            double x, y;
            std::cin >> x;
            std::cin >> y;
            cvorovi.push_back(std::make_pair(x, y));
        }
        do {
            try {
                auto rez(LinearnaInterpolacija(cvorovi));
                double argument;
                if (!Unos(argument))
                    return 0;
                std::cout << "f(" << argument << ") = " << rez(argument) << std::endl;
            } catch (const std::domain_error &greska) {
                std::cout << greska.what() << std::endl;
                return 0;
            } catch (const std::range_error &greska) {
                std::cout << greska.what() << std::endl;
            }
        } while(true);
    } else if (opcija==2) {
        std::cout << "Unesite krajeve intervala i korak: ";
        double min, max, korak;
        std::cin >> min >> max >> korak;
        do {
            try {
                auto rez(LinearnaInterpolacija(funkcija, min, max, korak));
                double argument;
                if (!Unos(argument))
                    return 0;
                std::cout << "f(" << argument << ") = " << funkcija(argument) << " fapprox(" << argument << ") = " << rez(argument) << std::endl;
            } catch (const std::domain_error &greska) {
                std::cout << greska.what() << std::endl;
                return 0;
            } catch (const std::range_error &greska) {
                std::cout << greska.what() << std::endl;
            }
        } while(true);
    }
    return 0;
}
