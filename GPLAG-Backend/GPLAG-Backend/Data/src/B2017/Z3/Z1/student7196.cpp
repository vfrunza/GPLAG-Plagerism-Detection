/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <stdexcept>
#include <iterator>

std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double, double>> vektor) {
    std::sort(vektor.begin(), vektor.end(), [](std::pair<double, double> prvi, std::pair<double, double> drugi) {
        return prvi.first<drugi.first;
    });
    for (int i=vektor.size()-1; i>0; i--) {
        if (vektor.at(i).first==vektor.at(i-1).first) throw std::domain_error("Neispravni cvorovi");
    }
    double x1(0.), xn(0.);
    std::vector<std::pair<double, double>>::iterator pocetak;
    std::vector<std::pair<double, double>>::iterator kraj(vektor.end());
    if (vektor.size()!=0) {
        pocetak=vektor.begin();
        kraj=vektor.end()-1;
        x1=(*pocetak).first;
        xn=(*kraj).first;
    }
    return [x1, xn, vektor, kraj](double x) {
        if (vektor.size()==0) throw std::range_error("Argument izvan opsega");
        if (x<x1) throw std::range_error("Argument izvan opsega");
        if (x>xn) throw std::range_error("Argument izvan opsega");
        if (x==xn) return (*kraj).second;
        else {
            auto donji(std::upper_bound(vektor.begin(), vektor.end(), std::make_pair(x, 1.)));
            auto gornji(donji);
            donji--;
            double x_i((*donji).first);
            double x_i1((*gornji).first);
            double y_i((*donji).second);
            double y_i1((*gornji).second);
            return y_i+((y_i1-y_i)/(x_i1-x_i))*(x-x_i);
        }
    };
}

std::function<double(double)> LinearnaInterpolacija(std::function<double(double)> fun, double prvi, double drugi, double korak) {
    if (prvi>drugi) throw std::domain_error("Nekorektni parametri");
    if (korak<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double, double>> vektor_parova;
    do {
        std::pair<double, double> par;
        par=std::make_pair(prvi, fun(prvi));
        vektor_parova.push_back(par);
        prvi+=korak;
    } while (prvi<=drugi);
    return LinearnaInterpolacija(vektor_parova);
}

int main ()
{
    int opcija;
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin >> opcija;
    if (opcija==1) {
        int n;
        std::cout << "Unesite broj cvorova: ";
        std::cin >> n;
        std::vector<std::pair<double, double>> vektor_parova;
        std::cout << "Unesite cvorove kao parove x y: ";
        for (int i=0; i<n; i++) {
            double prvi, drugi;
            std::cin >> prvi >> drugi;
            std::pair<double, double> par;
            par=std::make_pair(prvi, drugi);
            vektor_parova.push_back(par);
        }
        try {
            auto funkcija(LinearnaInterpolacija(vektor_parova));
        }
        catch(std::domain_error domenski) {
            std::cout << domenski.what();
            return 1;
        }
        double argument;
        while (std::cout << "Unesite argument (ili \"kraj\" za kraj): ") {
            std::cin >> argument;
            if (!std::cin) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                break;
            }
            try {
                auto rezultat(LinearnaInterpolacija(vektor_parova)(argument));
                std::cout << "f(" << argument << ") = " << rezultat;
            }
            catch(std::domain_error domenski) {
                std::cout << domenski.what();
            }
            catch(std::range_error rangovski) {
                std::cout << rangovski.what();
            }
            std::cout << std::endl;
        }
    }
    else if (opcija==2) {
        double prvi, drugi, korak;
        std::cout << "Unesite krajeve intervala i korak: ";
        std::cin >> prvi >> drugi >> korak;
        try {
            auto druga(LinearnaInterpolacija([](double x) { return x*x+std::sin(x); }, prvi, drugi, korak));
        }
        catch(std::domain_error domenski) {
            std::cout << domenski.what();
            return 2;
        }
        double argument;
        while (std::cout << "Unesite argument (ili \"kraj\" za kraj): ") {
            std::cin >> argument;
            if (!std::cin) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                break;
            }
            try {
                auto rezultat_prvi([](double x) { return x*x+std::sin(x); }(argument));
                auto rezultat_drugi(LinearnaInterpolacija([](double x) { return x*x+std::sin(x); }, prvi, drugi, korak)(argument));
                std::cout << "f(" << argument << ") = " << rezultat_prvi;
                std::cout << " ";
                std::cout << "fapprox(" << argument << ") = " << rezultat_drugi;
            }
            catch(std::domain_error domenski) {
                std::cout << domenski.what();
            }
            catch(std::range_error rangovski) {
                std::cout << rangovski.what();
            }
            std::cout << std::endl;
        }
    }
	return 0;
}
