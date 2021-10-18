#include <iostream>
#include <vector>
#include <functional>
#include <utility>
#include <cmath>
#include <algorithm>
#include <stdexcept>

const double eps(1e-10);

std::function<double(double)> f (const std::vector<double> &w, const std::vector<std::pair<double, double>> &v) {
    return [w, v] (double x) {
        double y(0), z(0);
        for (int i = 1; i < v.size(); i++) {
            if (!(std::fabs(x-v[i].first)<eps)) {
                y += w[i]*v[i].second/(x-v[i].first);
                z += w[i]/(x-v[i].first);
            } else {
                return v[i].second;
            }
        }
        return y/z;
    };
}

std::function<double(double)> BaricentricnaInterpolacija (std::vector<std::pair<double, double>> v, int d) {
    if (d < 0 || d >= v.size()) throw std::domain_error("Nedozvoljen red");
    for (int i = 0; i < v.size(); i++) for (int j = i+1; j < v.size(); j++)
            if (std::fabs(v[i].first - v[j].first) < eps) throw std::domain_error("Neispravni cvorovi");
            
    v.insert(v.begin(), std::make_pair(0,0));
    std::vector<double> w(v.size());
    for (int i = 1; i < v.size(); i++) {
        std::vector<int> bounds{1, i-d, i, int(v.size()-1)-d};
        int from (*std::max_element(bounds.begin(), bounds.begin()+2));
        int to   (*std::min_element(bounds.begin()+2, bounds.end()));
        w[i] = 0;
        for (int k = from; k <= to; k++) {
            double w_el(std::pow(-1, k-1));
            for (int j = k; j <= k+d; j++) if (j!=i) w_el*=(1/(v[i].first-v[j].first));
            w[i]+=w_el;
        }
    }
    return f(w, v);
}

std::function<double(double)> BaricentricnaInterpolacija (std::function<double(double)> f, double x_min, double x_max, double dx, int d) {
    if (x_min > x_max || dx<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double, double>> v;
    for (double i = x_min; i <= x_max; i+=dx) v.push_back(std::make_pair(i, f(i)));
    return BaricentricnaInterpolacija(v, d);
}


int main () {
    
    while(1) {
        std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        int option;
        std::cin >> option;
        if (option == 1) {
            std::cout << "Unesite broj cvorova: ";
            int n;
            std::cin >> n;
            std::cout << "Unesite cvorove kao parove x y: ";
            std::vector<std::pair<double, double>> v;
            for (int i = 0; i < n; i++) {
                double x, y;
                std::cin >> x >> y;
                v.push_back(std::make_pair(x, y));
            }
            std::cout << "Unesite red interpolacije: ";
            int d;
            std::cin >> d;
            while(1) {
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                double arg;
                std::cin >> arg;
                if (!std::cin) return 0;
                try {
                    auto f = BaricentricnaInterpolacija(v, d);
                    std::cout << "f(" << arg << ") = " << f(arg) << std::endl;
                } catch (std::domain_error err) {
                    std::cout << err.what();
                    return 0;
                }
            }
        } else if (option == 2) {
            std::cout << "Unesite krajeve intervala i korak: ";
            double x_min, x_max, dx;
            std::cin >> x_min >> x_max >> dx;
            std::cout << "Unesite red interpolacije: ";
            int d;
            std::cin >> d;
            while (1) {
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                double arg;
                std::cin >> arg;
                if (!std::cin) return 0;
                try {
                    auto f = BaricentricnaInterpolacija([] (double x) {return x*x+std::sin(x);}, x_min, x_max, dx, d);
                    std::cout << "f(" << arg << ") = " << arg*arg+std::sin(arg) << " fapprox(" << arg << ") = " << f(arg) << std::endl;
                } catch (std::domain_error err) {
                    std::cout << err.what();
                    return 0;
                }
            }
        }
        
    }
	return 0;
}