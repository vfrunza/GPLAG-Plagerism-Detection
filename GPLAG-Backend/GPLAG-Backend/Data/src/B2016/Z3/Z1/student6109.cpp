/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <utility>
#include <functional>
#include <algorithm>
#include <cmath>
#include <stdexcept>

#define epsilon 0.000000001

double Provjera(std::vector<std::pair<double, double>> brojevi3, int red3, int k, int i) {
    double proizvod=1;
    for(int j=k-1;j<k+red3; j++) {
        if(j!=i) proizvod*=1./(brojevi3[i].first-brojevi3[j].first);
    }
    return proizvod;
}

double TezinskiKoeficijent(std::vector<std::pair<double, double>> brojevi2, int red2, int i) {
    double suma=0;
    int test;
    int gornja, k;
    int duzina=brojevi2.size();
    
    if(i<(duzina-red2)) { //MIN{i, n-d} GORNJA GRANICA
        gornja=i;
    } else {
        gornja=duzina-red2;
    }
    if(i-red2>1) { //k=MAX{1, i-d} DONJA GRANICA
        k=i-red2;
    } else {
        k=1;
    }
    
    for(int a=k; a<=gornja; a++) {
        test=std::pow(-1, a-1);
        suma+=(test*Provjera(brojevi2, red2, a, i-1));
    }
    return suma;
}

double Gornji (std::vector<std::pair<double, double>>brojevi, int red, double x) {
    double suma=0;
    for(int i=0; i<brojevi.size(); i++) {
        suma+=(TezinskiKoeficijent(brojevi, red, i+1)*brojevi[i].second)/(x-brojevi[i].first);
    }
    return suma;
}

double Donji (std::vector<std::pair<double, double>>brojevi, int red, double x) {
    double suma=0;
    for(int i=0; i<brojevi.size(); i++) {
        suma+=(TezinskiKoeficijent(brojevi, red, i+1))/(x-brojevi[i].first);
    }
    return suma;
}

std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double, double>> brojevi1, int red1) {
    if(red1<0 || red1>=brojevi1.size()) throw std::domain_error("Nepostojeci red");
    for(int i=0; i<brojevi1.size(); i++) {
        for(int j=i+1; j<brojevi1.size(); j++) {
            if(std::fabs(brojevi1[i].first-brojevi1[j].first)<epsilon) throw std::domain_error("Neispravni cvorovi");
        }
    }
    return [brojevi1, red1](double x) {
        double suma1;
        double suma2;
        for(int i=0; i<brojevi1.size(); i++) {
            if(std::fabs(x-brojevi1[i].first)<epsilon) return brojevi1[i].second;    
        }
        suma1=Gornji(brojevi1, red1, x);
        suma2=Donji(brojevi1, red1, x);
        return suma1/suma2;
    };
}

std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> f, double xmin, double xmax, double korak, int red) {
    if(xmin>xmax || korak<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double, double>> brojevi;
    int brojac=0;
    while(1) {
        double par=xmin+korak*brojac;
        if(par>xmax) break;
        brojevi.push_back(std::make_pair(par, f(par)));
        brojac++;
    }
    return BaricentricnaInterpolacija(brojevi, red);
}

int main() {
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int opcija;
    std::cin >> opcija;
    int cvorovi;
    char glupost='"';
    
    if(opcija==1) { //ODABIR 1
        std::vector<std::pair<double, double>>brojevi;
        std::cout << "Unesite broj cvorova: ";
        std::cin >> cvorovi;
        std::cout << "Unesite cvorove kao parove x y: ";
        for(int i=0; i<cvorovi; i++) { //UNOS PAROVA
            double x, y;
            std::cin >> x >> y;
            brojevi.push_back(std::make_pair(x, y));
        }
        std::cout << "Unesite red interpolacije: ";
        int red;
        std::cin >> red;
        try {    
            auto f=BaricentricnaInterpolacija(brojevi, red);
            while(1) {    
                std::cout << "Unesite argument (ili " << glupost << "kraj" << glupost << " za kraj): ";
                double argument;
                std::cin >> argument;
                if(!std::cin) break;
                std::cout << "f(" << argument << ") = " << f(argument) << std::endl;
                }
            } catch (std::domain_error izuzetak) {
                std::cout << izuzetak.what();
                return 1;
            }
        }
            if(opcija==2) {
                std::cout << "Unesite krajeve intervala i korak: ";
                double a, b, korak;
                std::cin >> a >> b >> korak;
                std::cout << "Unesite red interpolacije: ";
                int red;
                std::cin >> red;
        
                try {
                    auto f=(BaricentricnaInterpolacija([](double x) { return x*x+std::sin(x);}, a, b, korak, red));
                    while(1) {
                        std::cout << "Unesite argument (ili " << glupost << "kraj" << glupost << " za kraj): ";
                        double argument;
                        std::cin >> argument;
                        if(!std::cin) break;
                        std::cout << "f(" << argument << ") = " << argument*argument+std::sin(argument) << " fapprox(" << argument << ") = " << f(argument) << std::endl;
                    }
                } catch (std::domain_error izuzetak) {
                    std::cout << izuzetak.what();
            }
        }
return 0;
}
