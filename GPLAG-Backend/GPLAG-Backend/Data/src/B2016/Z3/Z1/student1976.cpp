/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <functional>
#include <cmath>
#include <stdexcept>
#include <vector>
#include <utility>
#define eps 0.000001

using std::cout;
using std::cin;
using std::endl;
typedef std::vector<std::pair<double, double>> Cvorovi;
typedef std::vector<double> Vektor;

Vektor TezinskiKoeficijenti(Cvorovi v, int d)
{
    int n(v.size());
    if(d > n || d <= 0) throw std::domain_error ("Nedozvoljen red");
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < v.size(); j++)
            if(std::fabs(v[i].first - v[j].first) < eps) throw std::domain_error ("Neispravni cvorovi");
    }
    
    Vektor temp;
    for(int i = 1; i <= n; i++) {
        double w(0);
        for(int k = std::max(1, i - d); k <= std::min(i, n - d); k++) {
            double proizvod(1);
            for(int j = k; j <= k + d; j++) {
                if(i != j)
                    proizvod *= double(1/(v[i - 1].first - v[j - 1].first));
            }
            if(k % 2 == 0)
                w += (-1) * proizvod;
            else w += proizvod;
        }
        temp.push_back(w);
    }
    return temp;
}

std::function<double(double)> BaricentricnaInterpolacija(Cvorovi v, int d)
{
    int n(v.size());
    if(d > n || d <= 0) throw std::domain_error ("Nedozvoljen red");
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < v.size(); j++)
            if(fabs(v[i].first - v[j].first) < eps) throw std::domain_error ("Neispravni cvorovi");
    }

    try {
        Vektor temp(TezinskiKoeficijenti(v, d));
        return [temp, v] (double x) {
            double brojnik(0), nazivnik(0);
            for(int i = 0; i < v.size(); i++) {
                if(fabs(x - v[i].first) < eps) return v[i].second;
                brojnik += (temp[i]/(x - v[i].first)) * v[i].second;
                nazivnik += temp[i]/(x - v[i].first);
            }
            return double (brojnik/nazivnik);
        };
    } catch (...) {
        throw;
    }
}

template <typename FunTip>
std::function<double(double)> BaricentricnaInterpolacija (FunTip f, double x_min, double x_max, double delta_x, int d)
{
    if(x_min > x_max || delta_x <= 0) throw std::domain_error ("Nekorektni parametri");

    Cvorovi c;
    int j(0);
    for(int i = 0; i <= (x_max - x_min)/delta_x; i++) {
        std::pair<double, double> cvor = std::make_pair((x_min + j*delta_x), f(x_min + j*delta_x));
        c.push_back(cvor);
        j++;
    }

    try {
        auto temp(TezinskiKoeficijenti(c, d));
        return [temp, c] (double x) {
            double brojnik(0), nazivnik(0);
            for(int i = 0; i < c.size(); i++) {
                if(fabs(x - c[i].first) < eps) return c[i].second;
                brojnik += double ((temp[i]/(x - c[i].first)) * c[i].second);
                nazivnik += double (temp[i]/(x - c[i].first));
            }
            return double (brojnik/nazivnik);
        };
    } catch(...) {
        throw;
    }
}

int main ()
{
    try {
        cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        int opcija;
        cin >> opcija;

        if(opcija == 1) {
            cout << "Unesite broj cvorova: ";
            int br;
            cin >> br;
            cout << "Unesite cvorove kao parove x y: ";
            Cvorovi v;
            for(int i = 0; i < br; i++) {
                double x, y;
                cin >> x >> y;
                std::pair<double, double> cvor = std::make_pair(x, y);
                v.push_back(cvor);
            }
            cout << "Unesite red interpolacije: ";
            int d;
            cin >> d;
            for(;;) {
                cout << "Unesite argument (ili \"kraj\" za kraj): ";
                double x;
                cin >> x;
                if(!cin) break;
                cout << "f(" << x <<") = " << BaricentricnaInterpolacija(v, d)(x) <<endl;
            }
        }

        if(opcija == 2) {
            cout << "Unesite krajeve intervala i korak: ";
            double x_min, x_max, delta_x;
            cin >> x_min >> x_max >> delta_x;
            cout << "Unesite red interpolacije: ";
            int d;
            cin >> d;
            for(;;) {
                cout << "Unesite argument (ili \"kraj\" za kraj): ";
                double x;
                cin >> x;
                if(!cin) break;
                cout << "f(" << x <<") = " << x*x + std::sin(x) << " fapprox(" << x <<") = " << BaricentricnaInterpolacija( [](double x) {
                    return x*x + std::sin(x);
                }, x_min, x_max, delta_x, d)(x);
                cout <<endl;
            }
        }
    } catch(std::domain_error e) {
        cout << e.what();
    }
    return 0;
}