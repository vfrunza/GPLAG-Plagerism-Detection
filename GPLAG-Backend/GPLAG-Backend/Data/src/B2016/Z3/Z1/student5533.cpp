/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <stdexcept>
#include <functional>
#include <vector>
#include <map>
#include <cmath>

using std::domain_error;

double test(double x) {
    return std::sin(x) + x * x;
}

int manji(int a, int b) {
    if (a < b) return a;
    return b;
}

int veci(int a, int b) {
    if (a > b) return a;
    return b;
}

std::function<double (double)> BaricentricnaInterpolacija(std::vector<std::pair<double, double>> v, int d) {
    if (d >= v.size() || d < 0) throw domain_error("Nedozvoljen red");
    int step[2]{-1, 1};
    for (int i = 0; i < v.size(); i++)
        for (int j = i + 1; j < v.size(); j++)
            if (v[i].first == v[j].first) throw domain_error("Neispravni cvorovi");
    std::vector<double> w(v.size(), 0);
    for (int i = 1; i <= v.size(); i++) {
        for (int k = veci(1, i - d); k <= manji(i, v.size() - d); k++) {
            double suma(1);
            for (int j = k; j <= k + d; j++) {
                if (i != j) suma = suma * (1 / (v[i - 1].first - v[j - 1].first));
            }
            w[i - 1]= w[i - 1] + suma * step[k % 2];
        }
    }
    return [w, v](double x) {
        double a(0), b(0), temp;
        for (int i = 1; i <= v.size(); i++) {
            if (x == v[i - 1].first) return v[i - 1].second;
            temp = w[i - 1] / (x - v[i - 1].first);
            a = a + temp * v[i - 1].second;
            b = b + temp;
        }
        return a / b;
    };
}

template <typename T>
std::function<double (double)> BaricentricnaInterpolacija(T f, double minx, double maxx, double deltax, int d) {
    if (deltax <= 0 || minx > maxx) throw domain_error("Nekorektni parametri");
    std::vector<std::pair<double, double>> v;
    while (minx <= maxx) {
        v.push_back(std::make_pair(minx, f(minx)));
        minx = minx + deltax;
    }
    return BaricentricnaInterpolacija(v, d);
}


int main () {
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int n, m, d;
    double maxx, minx, deltax;
    std::cin >> n;
    if (n == 1) {
        std::cout << "Unesite broj cvorova: ";
        std::cin >> m;
        std::vector<std::pair<double, double>> v(m);
        std::cout << "Unesite cvorove kao parove x y: ";
        for (int i = 0; i < m; i++) {
            std::cin >> v[i].first >> v[i].second;
        }
        std::cout << "Unesite red interpolacije: ";
        std::cin >> d;
        std::cin.ignore(100000, '\n');
        try {
            auto f = BaricentricnaInterpolacija(v, d);
            double x;
            for (;;) {
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                std::cin >> x;
                if (!std::cin) return 0;
                std::cout << "f(" << x << ") = " << f(x) << std::endl;
            }
        }
        catch(domain_error e) {
            std::cout << e.what() << std::endl;
            return 0;
        }
    } 
    else if (n == 2) {
        std::cout << "Unesite krajeve intervala i korak: ";
        std::cin >> minx >> maxx >> deltax;
        std::cout << "Unesite red interpolacije: ";
        std::cin >> d;
        try {
            auto f = BaricentricnaInterpolacija(test, minx, maxx, deltax, d);
            double x;
            for (;;) {
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                std::cin >> x;
                if (!std::cin) return 0;
                std::cout << "f(" << x << ") = " << test(x) << " fapprox(" << x << ") = " << f(x) << std::endl;
            }
        }
        catch(domain_error e) {
            std::cout << e.what() << std::endl;
            return 0;
        }
    }
	return 0;
}