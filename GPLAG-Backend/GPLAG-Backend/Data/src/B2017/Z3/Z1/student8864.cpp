/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <functional>
#include <utility>
#include <algorithm>
#include <vector>
#include <iterator>
#include <limits>
#include <stdexcept>
#include <cmath>

typedef std::vector<std::pair<double, double>> VektorParova;


std::function<double(double)> LinearnaInterpolacija (VektorParova cvorovi)
{
    try {
        std::sort(cvorovi.begin(), cvorovi.end(), [](std::pair<double,double> p1, std::pair<double, double> p2) {
            if(p1.first == p2.first) throw std::domain_error ("Neispravni cvorovi");
            return p1<p2;
        });
        return [cvorovi](double x) {
            if (x<cvorovi[0].first || x>cvorovi[cvorovi.size()-1].first) throw std::range_error ("Argument izvan opsega");
            auto it(std::upper_bound(cvorovi.begin(), cvorovi.end(), std::make_pair(x, std::numeric_limits<double>::max())));
            if(it!= cvorovi.end()) {
                //return (*(it-1)).second + (x-(*(it-1)).first)*((*it).second - (*(it-1)).second)/((*it).first - (*(it-1)).first);
                return (it-1)->second + (x-(it-1)->first)*(it->second - (it-1)->second)/(it->first - (it-1)->first);

            }
            return cvorovi[cvorovi.size()-1].second;
        };
    } catch(...) {
        throw;
    }

}

std::function<double(double)> LinearnaInterpolacija (std::function<double(double)> f, double x_min, double x_max, double delta_x)
{
    if(x_min>x_max || delta_x <= 0) throw std::domain_error ("Nekorektni parametri");
    return [f,x_min,x_max,delta_x](double x) {
        if(x<x_min ) throw std::range_error ("Argument izvan opsega");
        std::pair<double,double> tmp1, tmp2;
        int i(0), pronadjeno(0);
        do {
            tmp1= {x_min + i*delta_x, f(x_min+ i*delta_x)};
            if(tmp1.first == x_max) return f(x_max);
            tmp2= {x_min + (i+1)*delta_x, f(x_min+ (i+1)*delta_x)};
            if(tmp1.first<=x && x<tmp2.first) {
                pronadjeno=1;
                break;
            }
            i++;

        } while (x_min + i*delta_x < x_max);
        if(!pronadjeno) throw std::range_error("Argument izvan opsega");

        return tmp1.second + (x-tmp1.first)*(tmp2.second - tmp1.second)/(tmp2.first - tmp1.first);
    };
}


int main ()
{

    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int izbor;
    std::cin >> izbor;
    VektorParova cvorovi;
    if(izbor == 1) {
        std::cout << "Unesite broj cvorova: ";
        int br_cvorova;
        std::cin >> br_cvorova;
        std::cout << "Unesite cvorove kao parove x y: ";
        for(int i=0; i<br_cvorova; i++) {
            double x,y;
            std::cin >> x >> y;
            cvorovi.push_back(std::make_pair(x,y));
        }

        for(;;) {

            try {
                auto f(LinearnaInterpolacija(cvorovi));
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                double argument;
                std::cin >> argument;
                if(!std::cin) break;
                std::cout << "f("<<argument<<") = " << f(argument) << std::endl;
            } catch(std::domain_error izuzetak) {
                std::cout << izuzetak.what() << std::endl;
                return 0;
            } catch(std::range_error izuzetak) {
                std::cout << izuzetak.what() << std::endl;
            }

        }

    } else {
        std::cout << "Unesite krajeve intervala i korak: ";
        double x_min, x_max, delta_x;
        std::cin >> x_min >> x_max >> delta_x;

        for(;;) {
            try {
                auto f(LinearnaInterpolacija([](double x) {
                    return x*x + sin(x);
                } ,x_min,x_max,delta_x));
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                double argument;
                std::cin >> argument;
                if(!std::cin) break;
                std::cout << "f("<< argument <<") = " << argument*argument + sin(argument)
                          << " fapprox(" << argument << ") = " << f(argument)<<std::endl;
            } catch(std::domain_error izuzetak) {
                std::cout << izuzetak.what() << std::endl;
                return 0;
            } catch(std::range_error izuzetak) {
                std::cout << izuzetak.what() << std::endl;
            }
        }

    }


    return 0;
}
