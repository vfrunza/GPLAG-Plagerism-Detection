/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <functional>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>

bool DaLiJeSortiran (const std::vector<std::pair<double, double>> &v) {
    for (int i = 0; i < v.size()-1; i++) {
        for (int j = 1; j < v.size(); j++) {
            if (v[i].first > v[j].first) return false;
        }
    }
    return true;
}

void Sortiraj (std::vector<std::pair<double, double>> &v) {
    for (int i = 0; i < v.size(); i++) {
        int min = i;
        for (int j = i+1; j < v.size(); j++) {
            if (v[i].first > v[min].first) min = j;
        }
        double temp = v[min].first;
        v[min].first = v[i].first;
        v[i].first = temp;
    }
}

std::function<double(double)> LinearnaInterpolacija (std::vector<std::pair<double, double>> v) {
    if (!DaLiJeSortiran (v)) Sortiraj (v);
    for (int i = 0; i < v.size(); i++) {
        for (int j = i+1; j < v.size(); j++) {
            if (v[i].first == v[j].first) {
                throw std::domain_error ("Neispravni cvorovi");
            }
        }
    }
    return [v] (double x) {
        if (x < v[0].first || x > v[v.size()-1].first) throw std::range_error ("Argument izvan opsega");
        if (x == v[v.size()-1].first) return v[v.size()-1].second;
        std::pair<double, double> par {x, 0};
        auto it = std::upper_bound (v.begin(), v.end(), par);
        if (it != v.end()) return it->second + (((it-1)->second - it->second)*(x - it->first))/((it-1)->first - it->first);
    };
 }
 
std::function<double(double)> LinearnaInterpolacija (std::function<double(double)> f, double xmin, double xmax, double deltax) {
     if (xmin > xmax || deltax <= 0) throw std::domain_error ("Nekorektni parametri");
     std::vector<std::pair<double, double>> v;
     for (double x = xmin; x <= xmax; x += deltax) {
        v.push_back (std::make_pair(x, f(x)));
     }
     auto novafunkcija = LinearnaInterpolacija(v);
     return novafunkcija;
 }
 
double f (double x) {
    return x*x + std::sin(x);
}

int main ()
{
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int opcija;
    std::cin >> opcija;
    if (opcija == 1) {
        std::cout << "Unesite broj cvorova: ";
        int n;
        std::cin >> n;
        std::vector<std::pair<double, double>> v(n);
        std::cout << "Unesite cvorove kao parove x y: ";
        for (int i = 0; i < n; i++) {
            std::cin >> v[i].first >> v[i].second;
        }
        do {
            std::function<double(double)> rezultat;
            try {
                rezultat = LinearnaInterpolacija(v);
            } catch (std::range_error e) {
                std::cout << e.what() << std::endl;
                return 0;
            } catch (std::domain_error e) {
                std::cout << e.what() << std::endl;
                return 0;
            }
            std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
            double x;
            std::cin >> x;
            if (!std::cin.fail()) {
               try {
                    std::cout << "f(" << x << ") = " << rezultat(x) << std::endl;
                } catch (std::range_error e) {
                     std::cout << e.what() << std::endl;
                 } catch (std::domain_error e) {
                  std::cout << e.what() << std::endl;
              }
            }
        } while (!std::cin.fail()); 
    } else if (opcija == 2) {
        std::cout << "Unesite krajeve intervala i korak: ";
        double poc, kraj, korak;
        std::cin >> poc >> kraj >> korak;
        do {
            std::function<double(double)> rezultat;
            try {
                rezultat = LinearnaInterpolacija (f, poc, kraj, korak);
            } catch (std::range_error e) {
                std::cout << e.what() << std::endl;
                return 0;
            } catch (std::domain_error e) {
                std::cout << e.what() << std::endl;
                return 0;
            }
            std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
            double x;
            std::cin >> x;
            if (!std::cin.fail()) {
                try {
                    std::cout << "f(" << x << ") = " << f(x) << " fapprox(" << x << ") = " << rezultat (x) << std::endl;
                } catch (std::range_error e) {
                    std::cout << e.what() << std::endl;
                } 
                catch (std::domain_error e) {
                    std::cout << e.what() << std::endl;
                }
            }
        } while (!std::cin.fail());
    }
	return 0;
}
