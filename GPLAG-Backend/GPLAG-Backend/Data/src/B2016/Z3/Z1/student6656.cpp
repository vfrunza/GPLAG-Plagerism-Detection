/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <cmath>
#include <stdexcept>
using std::vector;
using std::pair;

std::function<double(double)> BaricentricnaInterpolacija (vector<pair<double, double>> cvorovi, int d) {
    if (d<0 || d>=cvorovi.size()) throw std::domain_error("Nedozvoljen red");
    for (int i=0; i<cvorovi.size(); i++)
        for (int j=i+1; j<cvorovi.size(); j++)
            if (fabs(cvorovi[i].first-cvorovi[j].first)<0.0001) throw std::domain_error("Neispravni cvorovi");
    vector<double> tez_koef;
    int n(cvorovi.size());
    for (int i=1; i<=cvorovi.size(); i++) {
        int donja(i-d);
        if (donja<1)
            donja=1;
        int gornja(n-d);
        if (gornja>(i))
            gornja=i;
        double w(0);
        for (int k=donja; k<=gornja; k++) {
            double p(1);
            for (int j=k; j<=k+d; j++) {
                if (j!=i)
                    p*=1/(cvorovi[i-1].first-cvorovi[j-1].first);
            }
            if (k%2==0)
                p=-p;
            w+=p;
        }
        tez_koef.push_back(w);
    }
    return [tez_koef, n, cvorovi](double x) {
        double a(0);
        double b(0);
        for (int i=0; i<n; i++) {
            if (fabs(x-cvorovi[i].first)<0.0001)
                return cvorovi[i].second;
            a+=(tez_koef[i]*cvorovi[i].second)/(x-cvorovi[i].first);
            b+=tez_koef[i]/(x-cvorovi[i].first);
        }
        return a/b;
    };
}

std::function<double(double)> BaricentricnaInterpolacija (std::function<double(double)> f, double x_min, double x_max, double dx, int d) {
    if (x_min>x_max || dx<=0) throw std::domain_error("Nekorektni parametri");
    vector<pair<double, double>> cvorovi;
    for (double i=x_min; i<=x_max; i+=dx) {
        cvorovi.push_back(std::make_pair(i, f(i)));
    }
    auto fun(BaricentricnaInterpolacija(cvorovi, d));
    return [fun](double x) {
        return fun(x);
    };
}

int main ()
{
    try {
        int opcija;
        std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        std::cin >> opcija;
        if (opcija==1) {
            int br_cvorova;
            std::cout << "Unesite broj cvorova: ";
            std::cin >> br_cvorova;
            vector<pair<double, double>> cvorovi(br_cvorova);
            double x, y;
            std::cout << "Unesite cvorove kao parove x y: ";
            for (int i=0; i<br_cvorova; i++) {
                std::cin >> x >> y;
                cvorovi[i].first=x;
                cvorovi[i].second=y;
            }
            int d;
            std::cout << "Unesite red interpolacije: ";
            std::cin >> d;
            double a;
            for (;;) {
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                std::cin >> a;
                if (!std::cin)
                    break;
                auto f(BaricentricnaInterpolacija(cvorovi, d));
                std::cout << "f(" << a << ") = " << f(a) << std::endl;
            }
        }
        else if (opcija==2) {
            double x_min, x_max, dx;
            std::cout << "Unesite krajeve intervala i korak: ";
            std::cin >> x_min >> x_max >> dx;
            int d;
            std::cout << "Unesite red interpolacije: ";
            std::cin >> d;
            double a;
            for (;;) {
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                std::cin >> a;
                if (!std::cin)
                    break;
                auto fapprox(BaricentricnaInterpolacija([](double x) {return x*x+std::sin(x);}, x_min, x_max, dx, d));
                std::cout << "f(" << a << ") = " << a*a+std::sin(a) << " fapprox(" << a << ") = " << fapprox(a) << std::endl;
            }
        }
    }
    catch (std::domain_error izuzetak) {
        std::cout << izuzetak.what();
    }
	return 0;
}