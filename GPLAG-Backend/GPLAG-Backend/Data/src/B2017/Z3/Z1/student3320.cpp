/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <utility>
#include <algorithm>
#include <vector>
#include <functional>
#include <string>
#include <cstring>

typedef std::vector<std::pair<double, double>>par;

const double eps=0.000000001;

int Opseg(par brojevi, double x, int &a) {
    int temp;
    int a1=0;
    for(int i=0; i<brojevi.size()-1; i++) {
        if(x>=brojevi.at(i).first && x<=brojevi.at(i+1).first) {
            temp=i;
            a1=i+1;
            break;
        }
    }
    if(a1==0) throw std::range_error("Argument izvan opsega");
    a=a1;
    return temp;
}

std::function<double(double)>LinearnaInterpolacija(par brojevi) {
    for(int i=0; i<brojevi.size()-1; i++) {
        for(int j=i+1; j<brojevi.size(); j++) {
            if(std::fabs(brojevi.at(i).first-brojevi.at(j).first)<eps) throw std::domain_error("Neispravni cvorovi");
        }
    }
    std::sort(brojevi.begin(), brojevi.end());
    return[brojevi](double x) {
        double temp;
        double suma1;
        if(x>brojevi.at(brojevi.size()-1).first || x<brojevi.at(0).first) throw std::range_error("Argument izvan opsega");
        for(int i=0; i<brojevi.size(); i++) {
            if(std::fabs(x-brojevi.at(i).first)<eps) return brojevi.at(i).second;
        }
        int a=0;
        int i=Opseg(brojevi, x, a);
        temp=((brojevi.at(a).second-brojevi.at(i).second)*(x-brojevi.at(i).first))/(brojevi.at(a).first-brojevi.at(i).first);
        suma1=brojevi.at(i).second+temp;
        return suma1;
    };
}

std::function<double(double)>LinearnaInterpolacija(std::function<double(double)> f, double xmin, double xmax, double korak) {
    if(xmin>xmax || korak<=0) throw std::domain_error("Nekorektni parametri");
    par brojevi;
    int brojac=0;
    for(;;) {
        double temp=xmin+korak*brojac;
        if(temp>xmax) break;
        brojevi.push_back(std::make_pair(temp, f(temp)));
        brojac++;
    }
    return LinearnaInterpolacija(brojevi);
}

int main () {
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int opcija;
    std::cin >> opcija;
    char temp='"';
    
    if(opcija==1) {
        int cvorovi;
        par brojevi;
        std::cout << "Unesite broj cvorova: ";
        std::cin >> cvorovi;
        std::cout << "Unesite cvorove kao parove x y: ";
        for(int i=0; i<cvorovi; i++) {
            double x, y;
            std::cin >> x >> y;
            brojevi.push_back(std::make_pair(x, y));
        }
        for(;;) {
            try {
                auto f=LinearnaInterpolacija(brojevi);
                std::cout << "Unesite argument (ili " << temp << "kraj" << temp << " za kraj): ";
                double argument;
                std::cin >> argument;
                if(!std::cin) break;
                std::cout << "f(" << argument << ") = " << f(argument) << std::endl;
            }catch(std::domain_error jedan) {
                std::cout << jedan.what();
                return 1;
            }catch(std::range_error dva) {
                std::cout << dva.what() << std::endl;
            }
        }
    } else {
        if(opcija==2) {
            std::cout << "Unesite krajeve intervala i korak: ";
            double a, b, korak;
            std::cin >> a >> b >> korak;
            for(;;) {
                try {
                    auto f=LinearnaInterpolacija([](double x){return x*x+std::sin(x);}, a, b, korak);
                    std::cout << "Unesite argument (ili " << temp << "kraj" << temp << " za kraj): ";
                    double argument;
                    std::cin >> argument;
                    if(!std::cin) break;
                    std::cout << "f(" << argument << ") = " << argument*argument+std::sin(argument) << " fapprox(" << argument << ") = " << f(argument) << std::endl;
                }catch(std::domain_error jedan) {
                    std::cout << jedan.what();
                    return 1;
                }catch(std::range_error dva) {
                    std::cout << dva.what() << std::endl;
                }
            }
        }
    }
	return 0;
}

//auto f(LinearnaInterpolacija({{1, 3}, {2, 5}, {4, 4}, {5, 2}, {7, 1}}));