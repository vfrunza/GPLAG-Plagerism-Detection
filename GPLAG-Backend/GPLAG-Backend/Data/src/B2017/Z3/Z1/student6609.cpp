/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <algorithm>
#include <cmath>
#define eps pow(10,-10)

double funkcija (double x) { return x*x+std::sin(x); }

bool FunkcijaKriterija (std::pair<double, double> par1, std::pair<double, double> par2) {
    return (!(fabs(par1.first-par2.first)<=eps*(fabs(par1.first)+fabs(par2.first))) && par1.first<par2.first);
}

std::function<double(double)> LinearnaInterpolacija (std::vector<std::pair<double, double>> v) {
    std::sort(v.begin(), v.end(), FunkcijaKriterija);
    for (auto it1=v.begin(); it1!=v.end()-1; it1++) {
        for (auto it2=it1+1; it2!=v.end(); it2++) {
            if (fabs(it1->first-it2->first) <= eps*(fabs(it1->first)+fabs(it2->first))) throw std::domain_error ("Neispravni cvorovi");
        }
    }
    return [v] (double x) {
                            auto pocetak(v.begin()), kraj(v.end()-1);
                            if (!(fabs(x-pocetak->first)<=eps*(fabs(x)+fabs(pocetak->first))) && (x<pocetak->first || x>kraj->first)) 
                                throw std::range_error ("Argument izvan opsega");
                            if (fabs(x-kraj->first) <= eps*(fabs(x)+fabs(kraj->first))) return kraj->second;
                            std::pair<double, double> pomocna = std::make_pair (x,0.);
                            auto it = std::upper_bound(v.begin(), v.end(), pomocna, FunkcijaKriterija);
                            double x2 = it->first;  double y2 = it->second;
                            it--;
                            double x1 = it->first;  double y1 = it->second;
                            double izraz = y1 + ((y2-y1)/(x2-x1))*(x-x1);
                            return izraz;
                        };
}

std::function<double(double)> LinearnaInterpolacija (std::function<double(double)> fun, double x_min, double x_max, double delta_x) {
    if (x_min>x_max || delta_x<=0) throw std::domain_error ("Nekorektni parametri");
    std::vector<std::pair<double, double>> v;
    double x(x_min), korak(0);
    for (int i=0; ; i++) {
        x = x + korak;
        if (x>x_max) break;
        korak = delta_x;
        double y = fun(x);
        std::pair<double, double> par = std::make_pair (x, y);
        v.push_back(par);
    }
    return LinearnaInterpolacija(v);
}

int main ()
{
    try {
        int opcija;
        std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        std::cin >> opcija;
        int br_cvorova;
        double kraj1, kraj2, korak;
        if (opcija==1) {
            std::cout << "Unesite broj cvorova: ";
            std::cin >> br_cvorova;
            std::vector<std::pair<double, double>> vp;
            std::cout << "Unesite cvorove kao parove x y: ";
            for (int i=0; i<br_cvorova; i++) {
                std::pair<double, double> temp;
                std::cin >> temp.first >> temp.second;
                vp.push_back(temp);
            }
            for(;;) {
                try {
                    auto f(LinearnaInterpolacija(vp));
                }
                catch (std::range_error izuzetak) {
                    std::cout << izuzetak.what() << std::endl;
                }
                double argument;
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                std::cin >> argument;
                if (!std::cin) break;
                double vr = LinearnaInterpolacija(vp)(argument);
                std::cout << "f("<< argument << ") = " << vr << std::endl;
            }
        }
        else if (opcija==2) {
            std::cout << "Unesite krajeve intervala i korak: ";
            std::cin >> kraj1 >> kraj2 >> korak;
            for (;;) {
                double argument;
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                std::cin >> argument;
                if (!std::cin) break;
                try {
                    auto f = LinearnaInterpolacija(funkcija, kraj1, kraj2, korak)(argument);
                    std::cout << "f(" << argument << ") = " << funkcija(argument) << " fapprox(" << argument << ") = " << f << std::endl;
                }
                catch (std::range_error izuzetak) {
                    std::cout << izuzetak.what() << std::endl;
                }
            }
        }
    }
    catch (std::domain_error izuzetak) {
        std::cout << izuzetak.what() << std::endl;
    }
	return 0;
}
