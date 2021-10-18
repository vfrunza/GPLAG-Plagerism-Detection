/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <functional>
#include <vector>
#include <utility>
#include <stdexcept>
#include <cmath>

using std::vector;
using std::pair;

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

typedef pair<double, double> pdd;

std::function<double (double)>
BaricentricnaInterpolacija(vector<pdd> p, int d) {
    int n = p.size();
    vector<double> w(n);
    
    if (d < 0 || d >= n)
        throw std::domain_error("Nedozvoljen red");
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            if (i != j && p[i-1].first == p[j-1].first)
                throw std::domain_error("Neispravni cvorovi");
                
        for (int k = max(1, i-d); k <= min(i, n-d); k++) {
            double proizvod = 1;
            for (int j = k; j <= k+d; j++) {
                if (j == i) continue;
                proizvod *= p[i-1].first - p[j-1].first;
            }
            w[i-1] += (k % 2 ? -1 : 1) / proizvod; 
        }
    }
    
    return [w, p](double x) {
        double gore = 0;
        double dole = 0;
        for (int i = 0; i < p.size(); i++) {
            if (x == p[i].first) return p[i].second;
            double razlomak = w[i] / (x - p[i].first);
            gore += razlomak * p[i].second;
            dole += razlomak;
        }
        return gore/dole;
    };
}

template <typename F>
std::function<double (double)>
BaricentricnaInterpolacija(F f, double mini, double maxi, double step, int d) {
    vector<pdd> p;
    if (mini > maxi || step <= 0)
        throw std::domain_error("Nekorektni parametri");
    
    for (double x = mini; x <= maxi; x += step)
        p.push_back(pdd(x, f(x)));
    return BaricentricnaInterpolacija(p, d);
}

int main() {
    using std::cout;
    using std::cin;
    
    int izbor = -1;
    
    do {
        cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        cin >> izbor;
    } while (izbor != 1 && izbor != 2);
    
    auto lambda = [](double x) {return x*x + std::sin(x);};
    
    std::function<double (double)> f;
    
    try {
        if (izbor == 1) {
            cout << "Unesite broj cvorova: ";
            int n;
            cin >> n;
            vector<pdd> p(n);
            cout << "Unesite cvorove kao parove x y: ";
            for (auto &x : p)
                cin >> x.first >> x.second;
            cout << "Unesite red interpolacije: ";
            int d;
            cin >> d;
            f = BaricentricnaInterpolacija(p, d);
        } else {
            cout << "Unesite krajeve intervala i korak: ";
            double mini, maxi, step;
            cin >> mini >> maxi >> step;
            cout << "Unesite red interpolacije: ";
            int d;
            cin >> d;
            f = BaricentricnaInterpolacija(lambda, mini, maxi, step, d);
        }
    } catch (std::domain_error e) {
        cout << e.what();
        return 0;
    }
    
    while (1) {
        cout << "Unesite argument (ili \"kraj\" za kraj): ";
        double x;
        cin >> x;
        if (!cin) break;
        cout << "f(" << x << ") = " << (izbor == 1 ? f(x) : lambda(x));
        if (izbor == 2)
            cout  << ' ' << "fapprox(" << x << ") = " << f(x);
        cout << '\n';
    }
    
	return 0;
}