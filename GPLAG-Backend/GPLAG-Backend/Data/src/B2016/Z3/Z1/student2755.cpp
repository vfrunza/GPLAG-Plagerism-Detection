#include <iostream>
#include <functional>
#include <utility>
#include <vector>
#include <stdexcept>
#include <cmath>
#include <algorithm>
#define EPS 0.001

typedef std::vector<std::pair<double,double>> parovi;

double zadana(double x) {
    return x*x+std::sin(x);
}

template<typename tip>
tip Stepenovanje(const tip n, const int stepen) {
    if(stepen<0) throw;
    if(stepen==0) return 1.;
    if(stepen==1) return n;
    tip rez(1.);
    for(int i(0); i<stepen; i++) rez*=n;
    return rez;
}

double wi (parovi v, const int i, const int d=6) {
    double rez(0.);
    int n(v.size());
    int k(std::max(1, i-d));
    //std::cout << "k za i = " << i << ", d = " << d << " je:  " << k << std::endl;
    int gornjagranica(std::min(i, n-d));
    //std::cout << "Gornja granica za i = " << i << ", n - d = " << n - d << " je: " << gornjagranica << std::endl;
    double faktor1(Stepenovanje(-1, k-1));
    while(k<=gornjagranica){
        double faktor2(1.);
        for(int j(k); j<=k+d; j++){
            if(j!=i) faktor2*=1./(v[i-1].first-v[j-1].first);
        }
        rez+=faktor1*faktor2;
        faktor1*=-1.;
        k++;
    }
    return rez;
}

bool Poredi(const double a, const double b) {
    return fabs(a-b)<EPS;
}

double DioRazlomka(parovi v, const double x, const std::string dio, const int d=6){
    int vel(v.size());
    double suma(0.);
    for(int i(1), j(0); i<=vel; i++, j++) {
        double faktor(wi(v, i, d)/(x-v[j].first));
        if(dio=="gore") suma+=faktor*v[j].second;
        else suma+=faktor*1.;
    }
    return suma;
}

std::function<double(double)> BaricentricnaInterpolacija(parovi v, const int d){
    int vel(v.size());
    if(d<0 || d>vel) throw std::domain_error("Nedozvoljen red");
    for(std::pair<double,double> p : v) {
        if(std::count_if(v.begin(), v.end(), [p](std::pair<double,double> a){ return Poredi(p.first, a.first); }) != 1)
            throw std::domain_error("Neispravni cvorovi");
    }
    return [=](double x) -> double { //ovako sve zarobljavamo
        auto it(std::find_if(v.begin(), v.end(), [x](std::pair<double,double> p){ return Poredi(p.first, x); }));
        if(it!=v.end()) return it->second;
        return DioRazlomka(v, x, "gore", d)/DioRazlomka(v, x, "dole", d);
    };
}

template<typename tip, typename targ>
std::function<double(double)> BaricentricnaInterpolacija(tip (*f)(targ), double xmin, const double xmax, const double deltax, const int d) {
    parovi v;
    while(xmin<xmax) {
        v.push_back(std::pair<double, double> {xmin, f(xmin)});
        xmin+=deltax;
    }
    return BaricentricnaInterpolacija(v, d);
}

int main () {
    int opcija;
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin >> opcija;
    if(opcija==1){
        try{
            int brojcvorova;
            std::cout << "Unesite broj cvorova: ";
            std::cin >> brojcvorova;

            parovi cvorovi;
            std::cout << "Unesite cvorove kao parove x y: ";
            for(int i(0); i<brojcvorova; i++) {
                double broj1, broj2;
                std::cin >> broj1 >> broj2;
                cvorovi.push_back(std::make_pair(broj1, broj2));
            }
            int red;
            std::cout << "Unesite red interpolacije: ";
            std::cin >> red;
            double argument;
            do {
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                std::cin >> argument;
                if(!std::cin) break;
                auto f(BaricentricnaInterpolacija(cvorovi, red));
                std::cout << "f(" << argument << ") = " << f(argument);
                std::cout << std::endl;
            } while(std::cin);
        }
        catch(std::domain_error e) {
            std::cout << e.what() << std::endl;
        }
    }
    else if(opcija==2) {
        try{
            std::cout << "Unesite krajeve intervala i korak: ";
            double kraj1, kraj2, korak;
            std::cin >> kraj1 >> kraj2 >> korak;
            std::cout << "Unesite red interpolacije: ";
            int red;
            std::cin >> red;
            double argument;
            do {
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                std::cin >> argument;
                if(!std::cin) break;
                auto f(BaricentricnaInterpolacija(zadana, kraj1, kraj2, korak, red));
                std::cout << "f(" << argument << ") = " << zadana(argument) << " fapprox(" << argument << ") = " << f(argument);
                std::cout <<std::endl;
            } while(std::cin);
        }
        catch(std::domain_error e) {
            std::cout << e.what() << std::endl;
        }
    }
	return 0;
}