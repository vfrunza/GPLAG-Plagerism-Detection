/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include<vector>
#include<functional>
#include<algorithm>
#include<stdexcept>
#include<cmath>

std::function<double(double)> BaricentricnaInterpolacija (std::vector<std::pair<double,double>> v, int d) {
    if(d < 0 || d >= v.size()) throw std::domain_error("Nedozvoljen red");
    for(int i=0;i<v.size(); i++) {
      for(int j=i+1; j<v.size(); j++) {
         if(v[i].first == v[j].first) throw std::domain_error("Neispravni cvorovi");
      }
    }
    std::vector<double> w;
    double proizvod(1);
    double suma(0);
    for(int i=1; i<=v.size(); i++) {
        const int l = i;
        const int a = i - d;
        const int b = v.size() - d;
        for(int k=std::max(1,a); k<=std::min(l,b); k++) {
            proizvod = 1;
            for(int j=k; j<=k+d; j++) {
                if(j == i) continue;
                proizvod*=1/(v[i-1].first - v[j-1].first);
            }
            if((k-1)%2!=0) proizvod*=-1;
            suma+=proizvod;
        }
        w.push_back(suma);
        suma = 0;
    }
    return [v,w] (double x) {
        double suma1(0);
        double suma2(0);
        for(int i=1; i<=v.size(); i++) {
            if(x == v[i-1].first) return v[i-1].second;
            suma1+=w[i-1]/(x-v[i-1].first)*v[i-1].second;
            suma2+=w[i-1]/(x-v[i-1].first);
        }
        return suma1/suma2; };
}

double fun(double x) {return x*x+std::sin(x); }

template <typename Tip>
std::function<double(double)> BaricentricnaInterpolacija(Tip f, double x_min, double x_max, double x, int d) {
    if(x_min>x_max || x<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> v;
    for(auto i=x_min; i<=x_max; i+=x) {
        v.push_back(std::make_pair(i,f(i)));
    }
    return BaricentricnaInterpolacija(v,d);
}

int main () {
    try{
        int izbor;
        std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        std::cin >> izbor;
        if(izbor == 1) {
            int n;
            std::cout << "Unesite broj cvorova: ";
            std::cin >> n;
            std::vector<std::pair<double,double>> v(n);
            std::cout << "Unesite cvorove kao parove x y: ";
            for(int i=0; i<n; i++) {
                std::cin >> v[i].first;
                std::cin >> v[i].second;
            }
            int d1;
            std::cout << "Unesite red interpolacije: ";
            std::cin >> d1;
            double x1;
            std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
            auto f(BaricentricnaInterpolacija(v,d1));
            while(std::cin >> x1) {
                std::cout << "f(" << x1 << ") = " << f(x1) << std::endl;
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
            }
        }
        else if(izbor == 2) {
            double x_min, x_max, x;
            std::cout << "Unesite krajeve intervala i korak: ";
            std::cin >> x_min >> x_max >> x;
            int d2;
            std::cout << "Unesite red interpolacije: ";
            std::cin >> d2;
            double x2;
            std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
            auto fapprox(BaricentricnaInterpolacija(fun,x_min,x_max,x,d2));
            while(std::cin >> x2) {
                std::cout << "f(" << x2 << ") = " << fun(x2) << " fapprox(" << x2 << ") = " << fapprox(x2) << std::endl;
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
            }
        }
    } catch(std::domain_error e) {
        std::cout << e.what();
    }
	return 0;
}