/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <memory>
#include <vector>
#include <utility>
#include <math.h>
#include <cmath>
#include <functional>

int Poredi(double x, double y)
{
    const double Eps= 1e-10;
    return fabs(x - y) <= Eps * (fabs(x)-fabs(y));
}

double f(double x)
{
    return x * x + sin(x);
}

std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double,double>> cvorovi, int d)
{
    if (d < 0 || d >= cvorovi.size()) {
        throw std::domain_error("Nedozvoljen red");
    }
    //PROVJERA CVOROVA
    for (int i = 0; i < cvorovi.size(); i++) {
        for(int j = i + 1; j < cvorovi.size(); j++) {
            if (Poredi(cvorovi[i].first,cvorovi[j].first)) {
                throw std::domain_error("Neispravni cvorovi");
            }
        }
    }
    int n = cvorovi.size();
    std::vector<double> w;
    for(int i = 1; i <= n; i++) {
        int gornja, dojnja;
        if(i > n - d) gornja = n - d;
        else gornja = i;
        if (1 > i - d) dojnja = 1;
        else dojnja = i - d;
        //W W W W W W  W W W   W
        double wi = 0;
        for(int k = dojnja; k <= gornja; k++) {
            double proizvod = 1;
            for(int j = k; j <= k + d; j++) {
                if (j == i) continue;
                else {
                    proizvod *= (1. / (cvorovi[i-1].first-cvorovi[j-1].first));
                }
            }
            wi += pow(-1,k-1) * proizvod;
        }
        w.push_back(wi);
    } //VRACA
    return[w,d,cvorovi] (double x) {
        double suma1(0),suma2(0);
        for(int i = 0; i < cvorovi.size(); i++) {
            if(Poredi(x,cvorovi[i].first)) {
                return cvorovi[i].second;
            }
        }
        for(int i=0; i < cvorovi.size(); i++) {
            suma1 += (w[i] / (x - cvorovi[i].first)) * cvorovi[i].second;
            suma2 += w[i] / (x - cvorovi[i].first);

        }
        return suma1 / suma2;
    };
}

std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> fcija, double xmin, double xmax, double dx, int d)
{
    if (xmin > xmax || dx <= 0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> cvorovi;
    double pomoc1(0), pomoc2(0);
    pomoc1 = xmin;
    while(pomoc1 <= xmax) {
        pomoc2 = fcija(pomoc1);
        auto par = std::make_pair(pomoc1,pomoc2);
        cvorovi.push_back(par);
        pomoc1 += dx;
    }
    std::function<double(double)> f = BaricentricnaInterpolacija(cvorovi,d);
    return f;
}



int main ()
{
    try {

        std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        int odaberi;
        std::cin >> odaberi;
        if(odaberi == 1) {
            std::cout << "Unesite broj cvorova: ";
            int broj;
            std::cin >> broj;
            std::vector<std::pair<double,double>> cvorovi ;
            std::cout << "Unesite cvorove kao parove x y: ";
            for(int i = 0; i < broj; i++) {
                double x,y;
                std::cin >> x>>y;
                std::pair<double,double> par = std::make_pair(x,y);
                cvorovi.push_back(par);
            }
            std::cout << "Unesite red interpolacije: " ;
            int red;
            std::cin >> red;
            double argument;
            std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
            while (std::cin >> argument) {
                auto f = BaricentricnaInterpolacija(cvorovi,red);
                std::cout << "f(" << argument << ") = " << f(argument) <<std::endl;
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
            }
        } else if(odaberi == 2) {
            std::cout << "Unesite krajeve intervala i korak: " ;
            double x,y,dx;
            std::cin >>x>>y>>dx;
            std::cout << "Unesite red interpolacije: ";
            int red;
            std::cin >> red;
            std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
            double argument;
            while (std::cin >> argument) {
                auto fi=BaricentricnaInterpolacija(f,x,y,dx,red);
                std::cout << "f(" << argument << ") = " << f(argument) << " fapprox(" << argument << ") = " << fi(argument) <<std::endl;
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
            }
        }
    } catch(std::domain_error greska) {
        std::cout << greska.what() << std::endl;
    }
    return 0;
}