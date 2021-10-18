/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <stdexcept>
#include <algorithm>
#include <cmath>

std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double, double>> v)
{

    std::sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++) {
        for(int j=i+1; j<v.size(); j++) {
            if(fabs(v.at(i).first-v.at(j).first) < 0.001) throw std::domain_error("Neispravni cvorovi");
        }
    }
    return ( [v] (double x) {
        if(x < v.at(0).first || x > v.at(v.size() - 1).first) throw std::range_error ("Argument van opsega");
        /*   for(int i=0; i<v.size()-1; i++)
               if(v.at(i).first <= x && v.at(i+1).first >= x) // manje / manje ili jednako!! tj vece
                   return (v.at(i).second + (v.at(i+1).second-v.at(i).second)/(v.at(i+1).first-v.at(i).first)*(x-v.at(i).first));
           throw std::range_error ("Argument van opsega");
        });*/
        auto it = std::lower_bound(v.begin(), v.end(), x, [] (std::pair<double, double> par, double x) {
            return par.first < x;
        });
        auto it1 = it;
        if(it == v.begin()) it1 = it+1;
        else it1 = it - 1;
        return (it->second + (it1 -> second - it->second) / (it1->first - it->first) * (x - it->first));
    });
}

std::function<double(double)> LinearnaInterpolacija(double f(double), double x_min, double x_max, double x_korak)
{
    if(x_min > x_max || x_korak <= 0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double, double>> cvor;

    for(double i=x_min; i<=x_max; i+=x_korak) {
        cvor.push_back({i, f(i)});
    }

    return ([cvor,f] (double x) {
        std::vector<double> v;
        double a;
        for(int i = 0; i<cvor.size(); i++) v.push_back(cvor.at(i).first);
        auto logi=std::binary_search(v.begin(), v.end(), x);
        if(logi == 0) {
            a = LinearnaInterpolacija(cvor)(x);
        } else if(logi == 1) {
            for(int i = 0; i < cvor.size(); i++) v.push_back(cvor.at(i).second);
            auto vrati = std::lower_bound(v.begin(), v.end(), f(x));
            a = *vrati;
        }
        return a;
    });
}

int main ()
{
    std::vector <std::pair <double, double>> v;
    int opcija, broj_cvorova;
    double argument, x, y, pocetak, kraj, korak;
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin >> opcija;
    if(opcija == 1) {
        std::cout << "Unesite broj cvorova: ";
        std::cin >> broj_cvorova;
        std::cout << "Unesite cvorove kao parove x y: ";
        try {
            while(v.size()<broj_cvorova) {
                std::cin >> x >> y;
                v.push_back({x,y});
            }
            auto fja(LinearnaInterpolacija(v));
            try {

                while(std::cin) {
                    std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                    std::cin >> argument;
                    if(!std::cin) {
                        std::cin.ignore(10000, '\n');
                        break;
                    }
                    std::cout << "f(" << argument << ") = " << LinearnaInterpolacija(v)(argument);
                    std::cout << std::endl;
                }

            } catch(std::range_error e) {
                std::cout << e.what();
            }
        } catch(std::domain_error e) {
            std::cout << e.what();
        }
    } else if(opcija == 2) {
        std::cout << "Unesite krajeve intervala i korak: ";
        try {
            std::cin >> pocetak >> kraj >> korak;
            auto fja(LinearnaInterpolacija([](double x) {
                return x*x + sin(x);
            }, pocetak, kraj, korak));
            while(std::cin) {
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                do {
                    std::cin >> argument;
                    if(!std::cin) {
                        std::cin.ignore(10000, '\n');
                        break;
                    }
                    if(argument<pocetak || argument>=kraj) {
                        std::cout << "Argument izvan opsega " << std::endl;
                        break;
                    }
                    std::cout << "f(" << argument << ") = " << argument*argument + sin(argument) << " fapprox(" << argument << ") = " << fja(argument); //LinearnaInterpolacija([](double x){return x*x + sin(x);}, pocetak, kraj, korak)(argument);
                    std::cout << std::endl;
                } while(argument < pocetak || argument > kraj);
            }
        } catch (std::range_error e) {
            std::cout << e.what();
        }
    }
    return 0;
}
