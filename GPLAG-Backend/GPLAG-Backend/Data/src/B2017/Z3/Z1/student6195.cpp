/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <utility>
#include <vector>
#include <map>
#include <string>
#include <functional>
#include <stdexcept>
#include <iterator>
#include <algorithm>
#include <cmath>
#define epsilon 10e-7

double funkcija (double x) {
    return x*x + std::sin(x);
}

std::function<double (double)> LinearnaInterpolacija (std::vector<std::pair <double, double>> &v) {
    for(int i(1); i < v.size(); i++) {
        for(int j(0); j < i; j++) {
            std::pair<double, double> it1 = v.at(i);
            std::pair<double, double> it2 = v.at(j);
            if(std::fabs(it1.first) - std::fabs(it2.first) < epsilon) throw std::domain_error("Neispravni cvorovi");
        }
    }
    std::sort(v.begin(), v.end(), [](std::pair<double, double> p1, std::pair<double, double> p2) {
        return p1.first < p2.first; });
    return [v] (double x) { 
        std::pair<double, double> pocetak = v.at(0); std::pair<double, double> kraj = v.at(v.size()-1);
        if(std::fabs(x - kraj.first) < epsilon)     return kraj.second;
        if(!(x > pocetak.first && x < kraj.first)) throw std::range_error("Argument izvan opsega");
        std::pair<double, double> uporedbena; uporedbena.first = x; uporedbena.second = 0.0;
        auto najblizi_manji = std::upper_bound(v.begin(), v.end(), uporedbena);
        najblizi_manji--;
        double xi = najblizi_manji->first;
        double yi = najblizi_manji->second;
        auto najblizi_veci = std::lower_bound(v.begin(), v.end(), uporedbena);
        double xii = najblizi_veci->first;
        double yii = najblizi_veci->second;
        return yi + ((yii - yi)/(xii - xi))*(x - xi);   
    };
}

std::function<double(double)> LinearnaInterpolacija (double f(double), double x_min, double x_max, double delta_x) {
    std::vector<std::pair <double, double>> cvorovi;
    int brojac(0);
    if((x_min > x_max) || (delta_x < 0)) throw std::domain_error("Nekorektni parametri");
    while(x_min + brojac*delta_x < x_max) {
        std::pair<double, double> cvor{x_min + brojac*delta_x, funkcija(x_min + brojac*delta_x)};
        cvorovi.insert(cvorovi.begin()+brojac, cvor);
        brojac++;
    }
    return[cvorovi] (double x) {
        std::pair<double, double> pocetak = cvorovi.at(0); std::pair<double, double> kraj = cvorovi.at(cvorovi.size()-1);
        if(std::fabs(x - kraj.first) < epsilon) return kraj.second;
        if(!(x > pocetak.first && x < kraj.first))  throw std::range_error("Argument izvan opsega");
        std::pair<double, double> uporedbena; uporedbena.first = x; uporedbena.second = 0.0;
        auto najblizi_manji = std::upper_bound(cvorovi.begin(), cvorovi.end(), uporedbena);
        najblizi_manji--;
        double xi = najblizi_manji->first;
        double yi = najblizi_manji->second;
        auto najblizi_veci = std::lower_bound(cvorovi.begin(), cvorovi.end(), uporedbena);
        double xii = najblizi_veci->first;
        double yii = najblizi_veci->second;
        return yi + ((yii - yi)/(xii - xi))*(x - xi); 
    };
}

int main ()
{
    int option;
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin>>option;
    if(option == 1) {
        std::cout<<"Unesite broj cvorova: ";
        int br_cvorova; std::cin>>br_cvorova;
        std::cout<<"Unesite cvorove kao parove x y: ";
        std::vector<std::pair<double, double>> cvorovi(br_cvorova);
        for(int i(0); i < br_cvorova; i++) std::cin>>cvorovi.at(i).first>>cvorovi.at(i).second;
        try {
            LinearnaInterpolacija(cvorovi);
            for(;;) {
                std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                double argument;
                if(!(std::cin>>argument)) {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    break;
                }
                try {
                auto fun(LinearnaInterpolacija(cvorovi));
                }catch(std::domain_error e) {
                    std::cout<<e.what()<<std::endl;
                }
                try {
                    std::cout<<"f("<<argument<<") = "<<LinearnaInterpolacija(cvorovi)(argument)<<std::endl;
                }catch(std::range_error f) {
                    std::cout<<f.what()<<std::endl;
                }
            }
        }catch(std::domain_error q) {
            std::cout<<q.what()<<std::endl;
        }
    }
    else if(option == 2) {
        std::cout<<"Unesite krajeve intervala i korak: ";
        double x_min, x_max, delta_x;
        std::cin>>x_min>>x_max>>delta_x;
        try {
            LinearnaInterpolacija(funkcija, x_min, x_max, delta_x);
            for(;;) {
                std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                double argument;
                if(!(std::cin>>argument)) {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    break;
                }
                try {
                    auto fun(LinearnaInterpolacija(funkcija, x_min, x_max, delta_x));
                    try {
                        std::cout<<"f("<<argument<<") = "<<funkcija(argument)<<" fapprox("<<argument<<") = "<<LinearnaInterpolacija(funkcija, x_min, x_max, delta_x)(argument)<<std::endl;
                }catch(std::range_error f) {
                    std::cout<<f.what()<<std::endl;
                }
            }catch(std::domain_error e) {
                    std::cout<<e.what()<<std::endl;
                }
            }
        }catch(std::domain_error q) {
            std::cout<<q.what()<<std::endl;
        }
    }
	return 0;
}
