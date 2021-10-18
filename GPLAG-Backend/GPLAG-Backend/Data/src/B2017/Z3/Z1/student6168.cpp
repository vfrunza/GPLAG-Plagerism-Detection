/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <utility>
#include <stdexcept>
#include <string>

using std::cin;
using std::cout;
using std::endl;
typedef std::pair<double, double> Par;

std::function <double(double)> LinearnaInterpolacija (std::vector<Par> parovi)
{
    std::sort (parovi.begin(), parovi.end(), [](Par prvi, Par drugi) {
        return prvi.first < drugi.first ;
    });

    auto FunckijaZaSortiranje = [](Par prvi, Par drugi) {
        return prvi.first < drugi.first;
    };

    for (auto pocetak(parovi.begin()); pocetak != parovi.end(); pocetak++) {
        int brojac(0);
        for (auto pocetak2(parovi.begin()); pocetak2!= parovi.end(); pocetak2++) {
            if(pocetak2->first == pocetak->first) brojac++;
            if (brojac>=2) throw std::domain_error ("Neispravni cvorovi");
        }
    }
    return [parovi, FunckijaZaSortiranje] (double arg) -> double {
        if (arg < parovi.at(0).first || arg > parovi.at(parovi.size()-1).first) throw std::range_error ("Argument izvan opsega");
        auto poredbeni = std::make_pair(arg, arg);
        auto ggi = std::lower_bound(parovi.begin(), parovi.end(), poredbeni, FunckijaZaSortiranje);
        if (ggi->first == arg)
            return ggi->second; // SPECIJALNI SLUCAJ (X = Xn)

        auto dgi = ggi-1;
        auto vrijednost_po_formuli = dgi->second+((ggi->second-dgi->second)/(ggi->first-dgi->first))*(arg-dgi->first);
        return vrijednost_po_formuli;
    };
}

std::function<double(double)> LinearnaInterpolacija(std::function<double(double)> funkcija, double x_min, double x_max, double dx)
{
    if(dx<=0 || x_max<x_min) throw std::domain_error ("Nekorektni parametri");
    int korak(0);
    std::vector<Par> parametri;
    for (;;) {
        auto element = korak*dx + x_min;
        if(element > x_max) break;
        parametri.push_back(std::make_pair(element, funkcija(element)));
        korak++;
    }

    return LinearnaInterpolacija(parametri);
}


int main ()
{
    cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int opcija;
    cin >> opcija;
    if(opcija == 1) {
        cout << "Unesite broj cvorova: ";
        int n;
        cin >> n;
        std::vector<Par> cvorovi;
        cout << "Unesite cvorove kao parove x y: ";
        for(int i(0); i<n; i++) {
            int x, y;
            cin >> x >> y;
            cvorovi.push_back(std::make_pair(x, y));
        }

        try {
            auto Aproksimacija = LinearnaInterpolacija(cvorovi);
            for(;;) {
                cout << "Unesite argument (ili \"kraj\" za kraj): ";
                double arg;
                cin >> arg;
                if (!cin) break;
                try {
                    cout << "f(" << arg << ") = " << Aproksimacija(arg) << endl;
                } catch(std::exception &poruka) {
                    cout << poruka.what() << endl;
                }
            }
        } catch(std::exception &poruka) {
            cout << poruka.what() << endl;
        }
    }

    else {
        cout << "Unesite krajeve intervala i korak: " ;
        double x_min, x_max, dx;
        cin >> x_min >> x_max >> dx;
        try {
            auto Aproksimacija = LinearnaInterpolacija([](double arg) {
                return arg*arg + std::sin(arg);
            }, x_min, x_max, dx);
            for (;;) {
                cout << "Unesite argument (ili \"kraj\" za kraj): ";
                double arg;
                cin >> arg;
                if(!cin) break;
                try {
                    cout << "f(" << arg << ") = " << arg*arg + std::sin(arg) << " fapprox(" << arg << ") = " << Aproksimacija(arg) << endl;
                } catch(std::exception &poruka) {
                    cout << poruka.what() << endl;
                }
            }
        } catch (std::exception &poruka) {
            cout << poruka.what() << endl;
        }
    }
    return 0;
}
