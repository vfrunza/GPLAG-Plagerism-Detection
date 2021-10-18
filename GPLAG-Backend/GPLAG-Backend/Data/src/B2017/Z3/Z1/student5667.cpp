/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <utility>
#include <cmath>
#include <functional>

bool funkcija (const std::pair<double, double> &prvi, const std::pair<double, double> &drugi)
{
    if(prvi.first < drugi.first) return true;
    return false;
}

std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double, double>> cvorovi)
{
    std::sort (cvorovi.begin(), cvorovi.end(), funkcija);
    for(int i(0); i < cvorovi.size(); i++) {
        for(int j(i+1); j < cvorovi.size(); j++) {
            if(cvorovi.at(i).first == cvorovi.at(j).first) {
                throw std::domain_error ("Neispravni cvorovi");
            }
        }
    }
    return [cvorovi] (double x) {
        if(x < cvorovi.at(0).first || x > cvorovi.at(cvorovi.size()-1).first) {
            throw std::range_error ("Argument izvan opsega");
        }


        auto it = std::lower_bound (cvorovi.begin(), cvorovi.end(), x, [] (const std::pair<double, double> &par, double x) {
            if(par.first < x) return true;
            return false;
        });
        auto drugiit = it;
        if(it == cvorovi.begin()) drugiit = it + 1;
        else drugiit = it - 1;
        return it-> second + ((drugiit-> second - it-> second)/ (drugiit -> first - it -> first)) * (x - it-> first);

    };
}

std::function<double(double)>LinearnaInterpolacija(std::function<double(double)> f, double mini, double maxi, double delta)
{
    if(mini > maxi || delta <= 0) {
        throw std::domain_error ("Nekorektni parametri");
    }
    std::vector<std::pair<double, double>> cvor;
    while(mini <= maxi) {
        cvor.push_back(std::make_pair(mini, f(mini)));
        mini+=delta;
    }
    return LinearnaInterpolacija(cvor);
}

double sinus (double x)
{
    return x * x + std::sin (x);
}

int main ()
{
    std::vector<std::pair<double, double>> v;
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int n;
    std::cin >> n;
    if(n == 1) {

        std::cout << "Unesite broj cvorova: ";
        int s;
        std::cin>> s;
        std::cout << "Unesite cvorove kao parove x y: ";
        try {
            double x, y;
            for(int i(0); i < s; i++) {
                std::cin>> x >> y;
                v.push_back({x, y});
            }
            auto funkcija(LinearnaInterpolacija(v));

            while(1) {
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                double h;
                std::cin>> h;

                if(!std::cin || std::cin.get() != '\n') {
                    std::cin.ignore(10000, '\n');
                    break;
                }
                try {

                    std::cout << "f(" << h << ") = " << funkcija(h);
                    std::cout << std::endl;
                }

                catch (std::range_error e) {
                    std::cout << e.what() << std::endl;
                }
            }
        } catch (std::domain_error e) {
            std::cout << e.what() << std::endl;
        }
    } else if(n == 2) {

        std::cout << "Unesite krajeve intervala i korak: ";
        double a, b, c;
        try {
            std::cin>> a >> b >> c;
            auto funkcija(LinearnaInterpolacija(sinus, a, b, c));
            while(1) {
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                double n;
                std::cin>> n;
                if(!std::cin || std::cin.get() != '\n') {
                    std::cin.ignore(10000, '\n');
                    break;
                }
                try {
                    std::cout << "f(" << n << ") = " << sinus(n) << " fapprox(" << n << ") = " << funkcija(n);
                    std::cout << std::endl;
                } catch(std::range_error e) {
                    std::cout << e.what() << std::endl;
                }
            }
        } catch(std::domain_error e) {
            std::cout << e.what() << std::endl;


        }
    }

    return 0;
}
