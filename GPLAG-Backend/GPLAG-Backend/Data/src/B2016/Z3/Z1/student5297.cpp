/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <functional>
#include <vector>
#include <utility>
#include <stdexcept>
#include <cmath>

std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double, double>> v, int red) {
    if (red<0 || red>=v.size()) throw std::domain_error("Nedozvoljen red");
    for(int i(0); i<v.size(); i++) {
        for(int j(0); j<v.size(); j++) {
            if(i==j) continue;
            if(v[i].first==v[j].first) throw std::domain_error("Neispravni cvorovi");
        }
    }
    return [v, red] (double x) {
        int n=v.size();
        for(int i(0); i<n; i++) {
            if(v[i].first==x) return v[i].second;
        }
        double diow(1), w(0), f1(0), f2(0);
        for(int i(1); i<=n; i++) {
            w=0;
            for(int k=std::max(1, i-red); k<=std::min(i, n-red); k++) {
                diow=1;
                for(int j=k; j<=k+red; j++) {
                    if(i==j) continue;
                    diow*=(1/(v[i-1].first-v[j-1].first));
                }
                w+=std::pow(-1, k-1)*diow;
            }
            f1+=(w/(x-v[i-1].first))*v[i-1].second;
            f2+=(w/(x-v[i-1].first));
        }
        double rezultat=f1/f2;
        return rezultat;
    };
}

std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> f, double pocetak, double kraj, double delta, int red) {
    if(pocetak>kraj || delta<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> v;
    while(pocetak<=kraj) {
        v.push_back(std::make_pair(pocetak,f(pocetak)));
        pocetak+=delta;
    }
    return BaricentricnaInterpolacija(v, red);
}

int main () {
    for(;;) {
        std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        int odabir;
        std::cin >> odabir;
        if(odabir==1) {
            std::cout << "Unesite broj cvorova: ";
            int br_cvorova;
            std::cin >> br_cvorova;
            std::vector<std::pair<double, double>> v;
            std::cout << "Unesite cvorove kao parove x y: ";
            for(int i(0); i<br_cvorova; i++) {
                int broj1, broj2;
                std::cin >> broj1 >> broj2;
                v.push_back(std::make_pair(broj1, broj2));
            }
            std::cout << "Unesite red interpolacije: ";
            int red;
            std::cin >> red;
            for(;;) {
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                double argument;
                std::cin >> argument;
                if(!std::cin) {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    return 0;
                }
                try {
                    auto f(BaricentricnaInterpolacija(v, red));
                    double rezultat=f(argument);
                    std::cout << "f(" << argument << ") = " << rezultat << std::endl;
                } catch (std::domain_error izuzetak) {
                    std::cout << izuzetak.what() << std::endl;
                    return 0;
                }
            }
        } else if(odabir==2) {
            std::cout << "Unesite krajeve intervala i korak: ";
            double pocetak, kraj, delta;
            std::cin >> pocetak >> kraj >> delta;
            std::cout << "Unesite red interpolacije: ";
            int red;
            std::cin >> red;
            for(;;) {
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                double argument;
                std::cin >> argument;
                if(!std::cin) {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    return 0;
                }
                try {
                    auto fap=BaricentricnaInterpolacija([] (double x) {return x*x+std::sin(x);}, pocetak, kraj, delta, red);
                    double rezultat=fap(argument);
                    std::cout << "f(" << argument << ") = " << argument*argument+std::sin(argument) << " fapprox(" << argument << ") = " << rezultat << std::endl;
                }
                catch (std::domain_error izuzetak) {
                    std::cout << izuzetak.what() << std::endl;
                    return 0;
                }
            }
        }
    }
	return 0;
}