/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iterator>
#include <cmath>
#include <functional>

std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double,double>> &VektorCvorova)
{

    for(int i=0; i<VektorCvorova.size(); i++) {
        for(int j=i+1; j<VektorCvorova.size(); j++) {
            if (VektorCvorova.at(j).first == VektorCvorova.at(i).first) throw std::domain_error("Neispravni cvorovi");
        }
    }

    std::sort(VektorCvorova.begin(),VektorCvorova.end());

    return [VektorCvorova] (double x) {
        if(VektorCvorova.begin()->first > x || (--VektorCvorova.end())->first < x) throw std::range_error("Argument izvan opsega");

        auto pom=--VektorCvorova.end();
        if(pom->first==x) return pom->second;

        for(auto it=VektorCvorova.begin(); it!=VektorCvorova.end(); it++) {

            auto gornja=std::lower_bound(it,VektorCvorova.end(),x, [] (const std::pair<double,double> &par, const double v) {
                if(par.first<v) return true;
                return false;
            });

            if (gornja->first > x) {
                gornja--;
                if(gornja->first<=x) {
                    auto donja=gornja;
                    gornja++;
                    return donja->second+((gornja->second-donja->second)/(gornja->first-donja->first))*(x-donja->first);
                    break;
                }
            }
        }
        return x;
    };
}

std::function<double(double)> LinearnaInterpolacija(double f(double), double xmin, double xmax, double deltax)
{

    std::vector<std::pair<double,double>> NoviVektorCvorova;

    if(xmin>xmax || deltax<=0) throw std::domain_error("Nekorektrni parametri");

    int i(0);
    for(;;) {
        if ((xmin+i*deltax)>xmax) break;
        NoviVektorCvorova.push_back({xmin+i*deltax, f(xmin+i*deltax)});
        i++;
    }

    return LinearnaInterpolacija(NoviVektorCvorova);
}


int main ()
{
    try {
    int odabir;
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin >>  odabir;

    if(odabir==1) {
        int brojcvorova;
        double x,y;
        std::vector<std::pair<double,double>> VektorCvorova;
        std::cout << "Unesite broj cvorova: ";
        std::cin >> brojcvorova;
        std::cout << "Unesite cvorove kao parove x y: ";
        while(brojcvorova!=0) {
            std::cin >> x >> y;
            VektorCvorova.push_back({x,y});
            brojcvorova--;
        }
        
        auto f(LinearnaInterpolacija(VektorCvorova));
        while (true) {
        try {
            std::cout << "Unesite argument (ili \"kraj\" za kraj): " ;
            double argument;
            std::cin >> argument;
            if(!std::cin) return 0;
           // auto f(LinearnaInterpolacija(VektorCvorova));
            std::cout << "f(" << argument << ") = " << f(argument) << std::endl;
        } catch(std::range_error izuzetak) {
            std::cout << izuzetak.what() << std::endl;
        } /*catch(std::range_error izuzetak) {
            std::cout << izuzetak.what() << std::endl;
        }*/
        }
    }
    

    else if(odabir==2) {
        std::cout << "Unesite krajeve intervala i korak: ";
        double xmin,xmax,deltax;
        std::cin >> xmin >> xmax >> deltax;

        while (true) {
            try {
                std::cout << "Unesite argument (ili \"kraj\" za kraj): " ;
                double argument;
                std::cin >> argument;
                if(!std::cin) return 0;
                auto fapprox(LinearnaInterpolacija([](double x) {
                    return x*x+std::sin(x);
                },xmin,xmax,deltax));
                std::cout << "f(" << argument << ") = " << std::pow(argument,2)+std::sin(argument) <<
                          " fapprox(" << argument << ") = " << fapprox(argument) << std::endl;
            /*} catch(std::domain_error izuzetak) {
                std::cout << izuzetak.what() << std::endl;
            }*/ }catch(std::range_error izuzetak) {
                std::cout << izuzetak.what() << std::endl;
            }
        }
    }
    }catch(std::domain_error izuzetak){
        std::cout << izuzetak.what() << std::endl;
        return 0;
    }
    return 0;
}
