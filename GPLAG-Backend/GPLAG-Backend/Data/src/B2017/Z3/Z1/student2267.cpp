/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <algorithm>
#include <stdexcept>
#include <cmath>
#define eps 0.0001

bool isti(double a, double b) {
    return fabs(a - b) < eps;
}

double sinx2(double x) {
    return x * x + sin(x);
}

std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double, double>> cvorovi) {
    
    std::sort(cvorovi.begin(), cvorovi.end(), [](const std::pair<double, double> &a, const std::pair<double, double> &b){
        return a.first < b.first;
    });
    
    for (int i = 0; i < cvorovi.size()-1; i++) {
        for (int j = i+1; j < cvorovi.size(); j++) {
            if (isti(cvorovi[i].first, cvorovi[j].first)) {
                throw std::domain_error ("Neispravni cvorovi");
            }
        }
    }
    
    std::function<double(double)> funkcija = [cvorovi](double x) {
        if ((cvorovi.size() > 1) && (x > cvorovi[cvorovi.size()-1].first || x < cvorovi[0].first)) {
            throw std::range_error ("Argument izvan opsega");
        }
        
        if (isti(x, cvorovi[cvorovi.size()-1].first)) {
            return cvorovi[cvorovi.size()-1].second;
        }
        int index(0);
        
        for (int i = 0; i < cvorovi.size(); i++) {
            if (x < cvorovi[i].first) {
                index = i-1;
                break;
            }
        }

        return cvorovi[index].second + (cvorovi[index+1].second - cvorovi[index].second)/(cvorovi[index+1].first - cvorovi[index].first) * (x - cvorovi[index].first);
    };
    
    return funkcija;
}

std::function<double(double)> LinearnaInterpolacija(std::function<double(double)> f_aproksimacija, double x_min, double x_max, double x_delta) {
    if (x_min > x_max || isti(x_delta, 0) || x_delta < 0) {
        throw std::domain_error ("Nekorektni parametri");
    }
    
    std::vector<std::pair<double, double>> cvorovi;
    
    for (double x = x_min; x <= x_max; x += x_delta) {
        cvorovi.push_back(std::make_pair(x, f_aproksimacija(x)));
    }
    
    
    std::function<double(double)> funkcija = LinearnaInterpolacija(cvorovi);
    
    
    return funkcija;
}


int main ()
{
    //auto f(LinearnaInterpolacija({ {1, 3}, {2, 5}, {4, 4}, {5, 2}, {7, 1}}));
    //std::cout << f(1) << std::endl;
    try {
        int izbor;
        std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        std::cin >> izbor;
        if (izbor == 1) {
            int broj_cvorova;
            double x, y;
            std::vector<std::pair<double, double>> cvorovi;
            std::cout << "Unesite broj cvorova: ";
            std::cin >> broj_cvorova;
            std::cout << "Unesite cvorove kao parove x y: ";
            for (int i = 0; i < broj_cvorova; i++) {
                std::cin >> x >> y;
                cvorovi.push_back(std::make_pair(x, y));
            }
            
            auto f(LinearnaInterpolacija(cvorovi));
            do {
                try {
                    std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                    std::cin >> x;
                    if (!std::cin) {
                        break;
                    }
                    std::cout << "f(" << x << ") = " << f(x) << std::endl;
                }
                catch (std::domain_error error) {
                    std::cout << error.what() << std::endl;
                }
                catch (std::range_error error) {
                    std::cout << error.what() << std::endl;
                }
            } while(true);
            
        } else if (izbor == 2) {
            double x_min, x_max, x_delta, x;
            std::cout << "Unesite krajeve intervala i korak: ";
            std::cin >> x_min >> x_max >> x_delta;
            auto f(LinearnaInterpolacija(sinx2, x_min, x_max, x_delta));
            do {
                try {
                    std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                    std::cin >> x;
                    if (!std::cin) {
                        break;
                    }
                    std::cout << "f(" << x << ") = " << sinx2(x) << " fapprox(" << x << ") = " << f(x) << std::endl;
                }
                catch (std::domain_error error) {
                    std::cout << error.what() << std::endl;
                }
                catch (std::range_error error) {
                    std::cout << error.what() << std::endl;
                }
                
            } while(true);
        }
    }
    catch (std::domain_error error) {
        std::cout << error.what() << std::endl;
    }
    catch (std::range_error error) {
        std::cout << error.what() << std::endl;
    }
    
	return 0;
}
