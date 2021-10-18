/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
#include <stdexcept>
#include <algorithm>
#include <functional>

std::function <double(double)> LinearnaInterpolacija (std::vector<std::pair<double, double>> parovi) {
    return [parovi](double x) -> double {
        auto it = parovi.begin();
        auto it1 = parovi.begin();
        double vrijednost(0);
        it = std::lower_bound(parovi.begin(), parovi.end(), std::make_pair(x, std::numeric_limits<double>::min()));
        if (it - parovi.begin() == 0 || it - parovi.end() == 0) {
            if (it - parovi.end() == 0) throw std::range_error("Argument izvan opsega");
            if (x==it->first) return it->second;
            throw std::range_error("Argument izvan opsega");
        }
        it1=it;
        it1--;
        if (x==it->first) return it->second;
        else vrijednost = it1 -> second + (it -> second - it1 -> second)/(it -> first - it1 -> first)*(x-it1 -> first);
        return vrijednost;
    };
}

std::function <double(double)> LinearnaInterpolacija (std::function<double(double)>f, double min, double max, double dx) {
    return[=](double x) -> double{
    if (min > max || dx<0 || dx==0) {
        throw std::domain_error("Nekorektni parametri");
    }
    
    std::vector<std::pair<double, double>> cvorovi;
    
    for(int i(0); i < max/dx - 1; i++) {
        std::pair<double, double> par(min + i*dx, f(min + i*dx));
        cvorovi.push_back(par);
    }
    
        auto it = cvorovi.begin();
        auto it1 = cvorovi.begin();
        double vrijednost(0);
        it = std::lower_bound(cvorovi.begin(), cvorovi.end(), std::make_pair(x, std::numeric_limits<double>::min()));
        if (it - cvorovi.begin() ==0 || it - cvorovi.end() == 0) {
            if (it - cvorovi.end() == 0) throw std::range_error("Argument izvan opsega");
            if (x==it->first) return it->second;
            throw std::range_error("Argument izvan opsega");
        }
        it1=it;
        it1--;
        if (x==it->first) return it->second;
        else vrijednost = it1 -> second + (it -> second - it1 -> second)/(it -> first - it1 -> first)*(x-it1 -> first);
        return vrijednost;
    };
    //return LinearnaInterpolacija(cvorovi);
}

double funkcija(double x) {
    return pow(x, 2) + std::sin(x);
}

int main ()
{
    std::function<double(double)>f;
    double temp1(0);
    try {
        std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        int opcija;
        std::cin >> opcija;
        if(opcija==1) {
            std::cout << "Unesite broj cvorova: ";
            int broj_cvorova;
            std::cin >> broj_cvorova;
            std::cout << "Unesite cvorove kao parove x y: ";
            std::vector<std::pair<double, double>> parovi;
            for (int i(0); i < broj_cvorova; i++) {
                std::pair<double, double> par;
                std::cin >> par.first >> par.second;
                parovi.push_back(par);
    }
    
    std::sort(parovi.begin(), parovi.end(), [](const std::pair<double, double> &prvi, const std::pair<double, double> &drugi) {
        return prvi.first < drugi.first;
    });
    
    auto test = std::unique(parovi.begin(), parovi.end(), [](const std::pair<double, double> &prvi, const std::pair<double, double> &drugi) {
        return prvi.first == drugi.first;
    });
    
    if (test - parovi.end() < 0) throw std::domain_error("Neispravni cvorovi");
    f=LinearnaInterpolacija(parovi);
    
    for (;;) {
        std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
        std::string x;
        std::cin >> x;
        if(x == "kraj") break;
        temp1 = std::stod(x);
        std::cout << "f(" << temp1 << ") = " << f(temp1) << std::endl;
        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            return 0;
        }
    }
}
else if(opcija==2) {
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    std::cout << "Unesite krajeve intervala i korak: ";
    
    double min, max, dx;
    std::cin >> min >> max >> dx;
    f=LinearnaInterpolacija(funkcija, min, max, dx);
    std::string x;
    
    for (;;) {
        try {
        std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
        std::cin >> x;
        if(x == "kraj") break;
        temp1=std::stod(x);
        std::cout << "f(" << temp1 << ") = " << temp1*temp1 + std::sin(temp1) << " fapprox(" << temp1 << ") = " << f(temp1) << std::endl;
        x.clear();
        }
        
        catch(std::range_error izuzetak) {
            std::cout << izuzetak.what() << std::endl;
        }
        catch (std::domain_error izuzetak) {
            std::cout << izuzetak.what() << std::endl;
            return 0;
        }
    }
}
	return 0;
}
catch (std::domain_error izuzetak) {
            std::cout << izuzetak.what() << std::endl;
            return 0;
    }
}
