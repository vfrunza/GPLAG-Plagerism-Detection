/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <functional>
#include <vector>
#include <utility>
#include <algorithm>
#include <stdexcept>
#include <cmath>

typedef std::vector<std::pair<double,double>> Cvor;

bool Provjera(Cvor &cvorovi)
{
    int brojac(0);
    auto it(cvorovi.begin());
    for(int i = 0; i < cvorovi.size(); i++) {
        for(int j = 0; j < cvorovi.size(); j++) {
            if(it->first == cvorovi[j].first) brojac++;
        }
        if(brojac > 1) return false;
        it++;
        brojac = 0;
    }
    return true;
}

std::function<double(double)> LinearnaInterpolacija(Cvor &cvorovi)
{
    if(!Provjera(cvorovi)) throw std::domain_error("Neispravni cvorovi");
    std::sort(cvorovi.begin(), cvorovi.end(), [] (std::pair<double,double> par1, std::pair<double,double> par2) {
        return par1.first < par2.first;
    });
    
    return [cvorovi] (double x) {
        if(cvorovi.size() == 0 || cvorovi[0].first > x || cvorovi[cvorovi.size()-1].first < x) throw std::range_error("Argument izvan opsega");
        auto Z(std::make_pair(x,0.));
        auto it = std::upper_bound(cvorovi.begin(), cvorovi.end(), Z);
        if(x == it->first && *it == cvorovi[cvorovi.size()-1]) return cvorovi[cvorovi.size()-1].second;
            auto tmp = it;
            tmp--;
        double rezultat = tmp->second + ((it->second - tmp->second)/(it->first - tmp->first))*(x - tmp->first);
        return rezultat;
    };
}

std::function<double(double)> LinearnaInterpolacija(std::function<double(double)> f, double Xmin, double Xmax, double deltaX)
{
    if(deltaX <= 0 || Xmin > Xmax) throw std::domain_error("Nekorektni parametri");
    Cvor cvorovi;
    double x,y;
      x = Xmin ; 
      y = f(x);
      std::pair<double,double> par{x,y};
      cvorovi.push_back(par);  
    for(int i = 0; i < abs(Xmax - Xmin) / deltaX; i++) {
      x += deltaX; 
      y = f(x);
      std::pair<double,double> par{x,y};
      cvorovi.push_back(par);    
    }
    auto f1(LinearnaInterpolacija(cvorovi));
    
    return f1;
}

int main ()
{
    Cvor cvorovi;
    int opcija;
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin >> opcija;
    if(opcija == 1) {
        int broj;
        std::cout << "Unesite broj cvorova: ";
        std::cin >> broj;
        std::cout << "Unesite cvorove kao parove x y: ";
        double x,y;
        for(int i = 0; i < broj; i++) {
            std::cin >> x >> y;
            std::pair<double, double> par{x, y};
            cvorovi.push_back(par);
        }
        try {
        auto f(LinearnaInterpolacija(cvorovi));
            double argument;
            for(;;) {
             std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
             std::cin >> argument;
             if(!std::cin) break;
             try {
             std::cout << "f(" << argument << ") = " << f(argument) << std::endl;
                
             } catch(std::range_error izuzetak) {
                 std::cout <<  izuzetak.what() << std::endl;
             }
          }
          std::cin.clear();
          std::cin.ignore(10000, '\n');
          
        } catch (std::domain_error izuzetak) {
            std::cout << izuzetak.what() ;
        }
        
    } else {
        double min,max,korak;
       std::cout << "Unesite krajeve intervala i korak: ";
       std::cin >> min >> max >> korak;
       try {
       auto f(LinearnaInterpolacija([] (double x) {return x * x + sin(x);}, min, max, korak));
       auto f1([] (double x) {return x * x + sin(x);});
       double argument;
            for(;;) {
             std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
             std::cin >> argument;
             if(!std::cin) break;
             try {
             std::cout << "f(" << argument << ") = " << f1(argument) << " fapprox(" << argument << ") = "<< f(argument) << std::endl;
             } catch(std::range_error izuzetak) {
                 std::cout <<  izuzetak.what() << std::endl;
             }
          }
          std::cin.clear();
          std::cin.ignore(10000, '\n');
        } catch (std::domain_error izuzetak) {
                std::cout <<  izuzetak.what();
        }
    
    
    }
    
    /*auto f(LinearnaInterpolacija(cvorovi));
    for(auto x : cvorovi) std::cout << x.first << " \n";
    std::cout << f(2.5) << std::endl;
    auto f1(LinearnaInterpolacija([] (double x) -> double {return x*x + sin(x);}, 0., 1., 0.1));
    std::cout << " " << f1(0.57);*/
	return 0;
}
