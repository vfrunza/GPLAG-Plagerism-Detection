/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include<vector>
#include<utility>
#include <functional>
#include <algorithm>
#include <stdexcept>
#include <cmath>

bool Sortiraj(const std::pair<double, double> &prvi, const std::pair<double, double> &drugi) {
    if(prvi.first < drugi.first) return true;
    return false;
}

bool Poredi(const std::pair<double, double> &par, double poredjenje) {
    if(par.first < poredjenje) return true;
    return false;
}

bool Jednaki(double x, double y) {
    const double epsilon = 1e-10;
    if((x < 0 && y > 0) || (x > 0 && y < 0)) return false;
    return std::fabs(x - y) <= epsilon * (std::fabs(x) + std::fabs(y));
}

std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double,double>> cvorovi) {
    std::sort(cvorovi.begin(), cvorovi.end(), Sortiraj);
    for(int i(0); i < cvorovi.size(); i++) {
        for(int j(i + 1); j < cvorovi.size(); j++) {
            if(Jednaki(cvorovi.at(i).first, cvorovi.at(j).first)) throw std::domain_error("Neispravni cvorovi"); 
        }
    }
    return [cvorovi](double x) {
        if(cvorovi.size() != 0) {
            double najmanji = cvorovi.at(0).first;
            double najveci = cvorovi.at(cvorovi.size() - 1).first;
            if((x < najmanji && !Jednaki(x, najmanji)) || (x > najveci && !Jednaki(x, najveci))) throw std::range_error("Argument izvan opsega");
            if(Jednaki(x,najveci)) return cvorovi.at(cvorovi.size() - 1).second;
        }
        auto iterator_ii = std::lower_bound(cvorovi.begin(), cvorovi.end(), x, Poredi);
        auto iterator_i = iterator_ii;
        if(iterator_ii == cvorovi.begin()) iterator_i++;
        else iterator_i--;
        double yi = iterator_i->second;
        double xi = iterator_i->first;
        double yii = iterator_ii->second;
        double xii = iterator_ii->first;
        return yi + ((yii - yi) / (xii - xi)) * (x - xi);
    };
}

std::function<double(double)> LinearnaInterpolacija(std::function<double(double)> f, double xmin, double xmax, double delta) {
    if((xmin > xmax && !Jednaki(xmin, xmax)) || (delta <= 0 || Jednaki(delta, 0))) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double, double>> cvorovi;
    double x = xmin;
    while(x <= xmax || Jednaki(x, xmax)) {
        double y = f(x);
        cvorovi.push_back(std::make_pair(x, y));
        x += delta;
    }
    return LinearnaInterpolacija(cvorovi);
}

double f(double x) {
    return  x * x + std::sin(x);
}

int main () {
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int unos(0);
    std::cin >> unos;
    if(unos == 1) {
        std::cout << "Unesite broj cvorova: ";
        int broj;
        std::cin >> broj;
        std::cout << "Unesite cvorove kao parove x y: ";
        std::vector<std::pair<double, double>> cvorovi(broj);
        for(int i(0); i < broj; i++) {
            double x, y;
            std::cin >> x >> y;
            cvorovi.at(i).first = x;
            cvorovi.at(i).second = y;
        }
        try {
            auto linearna = LinearnaInterpolacija(cvorovi);
            for(;;) {
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                double arg;
                std::cin >> arg;
                if(!std::cin || std::cin.peek() != '\n') break;
                try {
                    std::cout << "f(" << arg << ") = " << linearna(arg) << std::endl;
                }
                catch(std::range_error e) {
                    std::cout << e.what() << std::endl;
                }
            }
        }
        catch(std::domain_error e) {
            std::cout << e.what();
            return 0;
        }
    }
    else if(unos == 2) {
        std::cout << "Unesite krajeve intervala i korak: ";
        double xmin, xmax, delta;
        std::cin >> xmin >> xmax >> delta;
        try {
            auto linearna = LinearnaInterpolacija(f, xmin, xmax, delta);
            for(;;) {
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                double arg;
                std::cin >> arg;
                if(!std::cin || std::cin.peek() != '\n') break;
                try {
                    std::cout << "f(" << arg << ") = " << f(arg) << " fapprox(" << arg << ") = " << linearna(arg) << std::endl;
                }        
                catch(std::range_error e) {
                    std::cout << e.what() << std::endl;
                }
            }
        }
        catch(std::domain_error e) {
            std::cout << e.what();
            return 0;
        }        
    }
	return 0;
}
