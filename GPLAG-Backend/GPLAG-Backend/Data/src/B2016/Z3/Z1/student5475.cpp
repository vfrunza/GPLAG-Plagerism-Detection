#include <iostream>
#include <limits>
#include <vector>
#include <utility>
#include <functional>
#include <cmath>

typedef std::vector<std::pair<double, double>> VParova;

int max(int k) {
    if(k > 1) return k;
    return 1;
}
int min(int i, int n) {
    if(i < n) return i;
    return n;
}
bool Isti(double a, double b) {
    return std::fabs(a - b) <= std::numeric_limits<double>::min();
}
double Proizvod(int k, int d, int i, const std::vector<double> &x) {
    double proizvod(1); 
    for(int j = k; j <= k+d; j++) 
        if(j != i)
            proizvod *= 1/(x[i-1] - x[j-1]);
    return proizvod;
}
bool Neispravni(const VParova &cvorovi) {
    for(int i = 0; i < cvorovi.size(); i++) 
        for(int j = i+1; j < cvorovi.size(); j++)
            if(Isti(cvorovi[j].first, cvorovi[i].first)) return true;
    return false;
}
std::function<double(double)> BaricentricnaInterpolacija(const VParova &cvorovi, int d) {
    if(d < 0 || d >= cvorovi.size()) throw std::domain_error("Nedozvoljen red");
    if(Neispravni(cvorovi)) throw std::domain_error("Neispravni cvorovi");
    std::vector<double> x, y, w;
    double n(cvorovi.size());
    for(auto it = cvorovi.begin(); it != cvorovi.end(); it++) {
        x.push_back(it->first);
        y.push_back(it->second);
    }
    for(int i = 1; i <= n; i++) {
        double glavna(0);
        for(int k = max(i-d); k <= min(i, n-d); k++) 
            glavna += Proizvod(k, d, i, x) * std::pow(-1, k-1);
        w.push_back(glavna);
    }
   return [x, y, w](double z) {
        double suma1(0), suma2(0);
        for(int i = 0; i < w.size(); i++) {
            if(Isti(z, x[i])) return y[i];
            suma2 += w[i] / (z - x[i]);
            suma1 += w[i] / (z - x[i]) * y[i];
        }
        return suma1/suma2;
    }; 
}
std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> f, 
        double xmin, double xmax, double dx, int d) {
    if(xmin > xmax || dx <= 0) throw std::domain_error("Nekorektni parametri");
    VParova cvorovi;
    for(double i = xmin; i <= xmax; i += dx) 
        cvorovi.push_back({i, f(i)});
    return BaricentricnaInterpolacija(cvorovi, d);
}
bool Provjera(bool &kraj) {
    if(!std::cin) {
        std::cin.clear(); 
        std::cin.ignore(1000, '\n');
        kraj = true;
    }
    return kraj;
}
int main () {
    try {
        auto f = [](double a) { return a*a + std::sin(a); };
    for(;;) {
        int opcija;
        bool kraj(false);
        std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        std::cin >> opcija;
        if(opcija == 1) {
            int br_cvorova, d;
            std::cout << "Unesite broj cvorova: ";
            std::cin >> br_cvorova;
            VParova v(br_cvorova);
            std::cout << "Unesite cvorove kao parove x y: ";
            for(int i = 0; i < br_cvorova; i++) {
                std::cin >> v[i].first; 
                std::cin >> v[i].second;
            }
            if(Neispravni(v)) throw std::domain_error("Neispravni cvorovi");
            std::cout << "Unesite red interpolacije: ";
            std::cin >> d;
            if(d < 0 || d >= br_cvorova) throw std::domain_error("Nedozvoljen red");
            for(;;){ 
                double arg;
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                std::cin >> arg;
                if(Provjera(kraj)) break;
                double temp(BaricentricnaInterpolacija(v, d)(arg));
                std::cout << "f(" << arg << ") = " << temp << std::endl;
            }
        }
    else {
        double xmin, xmax, dx, d;
        std::cout << "Unesite krajeve intervala i korak: ";
        std::cin >> xmin >> xmax >> dx;
        if(xmin > xmax || dx <= 0) throw std::domain_error("Nekorektni parametri");
        std::cout << "Unesite red interpolacije: ";
        std::cin >> d;
        for(;;) {
            double arg;
            std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
            std::cin >> arg;
            if(Provjera(kraj)) break;
            double a(f(arg)), b(BaricentricnaInterpolacija(f, xmin, xmax, dx, d)(arg));
            std::cout << "f(" << arg << ") = " << a << " fapprox(" << arg << ") = " << b << std::endl;
        }
    } if(kraj) break;
    }
    }
    catch(std::domain_error e) {
        std::cout << e.what();
    }
    catch(...) {
    }
	return 0;
}