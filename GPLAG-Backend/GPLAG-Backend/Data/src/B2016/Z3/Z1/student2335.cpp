/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <functional>
#include <vector>
#include <utility>
#include <stdexcept>
#include <cmath>

std::function<double(double)> BaricentricnaInterpolacija(const std::vector<std::pair<double, double>> &v, const int &d) {
    if(d<0 || d>=v.size()) throw std::domain_error("Nedozvoljen red");
    for(int i=0; i<v.size(); i++) {
        for(int j=i+1; j<v.size(); j++) {
            if(v[i].first==v[j].first) throw std::domain_error("Neispravni cvorovi");
        }
    }
    std::vector<double> w;
    for(int i=1; i<=v.size(); i++) {
        double suma(0);
        int granica_sume(i);
        if(i>(v.size()-d)) granica_sume=(v.size()-d);
        int k(1);
        if((i-d)>1) k=(i-d);
        for(; k<=granica_sume; k++) {
            double produkt(1);
            if((k-1)%2!=0) produkt=-1;
            for(int j=k; j<=k+d; j++) {
                if(j==i) continue;
                produkt*=1/(v[i-1].first-v[j-1].first);
            }
            suma+=produkt;
        }
        w.push_back(suma);
    }
    return [w, v] (double x) {
        double interpolacija(0), gornja_suma(0), donja_suma(0);
        for(int i=1; i<=v.size(); i++) if(x==v[i-1].first) return v[i-1].second;
        for(int i=1; i<=v.size(); i++) {
            donja_suma+=w[i-1]/(x-v[i-1].first);
            gornja_suma+=w[i-1]/(x-v[i-1].first)*v[i-1].second;
        }
        return interpolacija=gornja_suma/donja_suma;
    };
}

std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> f, double x_min, const double &x_max, const double &dx, const int &d) {
    if(x_min>x_max || dx<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double, double>> v;
    for(; x_min<=x_max; x_min+=dx) {
        std::pair<double, double> xy;
        xy.first=x_min; xy.second=f(x_min);
        v.push_back(xy);
    }
    return BaricentricnaInterpolacija(v, d);
}

int main ()
{   
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int opcija;
    std::cin >> opcija;
    if(opcija==1) {
        std::cout << "Unesite broj cvorova: ";
        int broj_cvorova;
        std::cin >> broj_cvorova;
        if(broj_cvorova<=0) return 0;
        std::cout << "Unesite cvorove kao parove x y: ";
        std::vector<std::pair<double, double>> v;
        for(int i=0; i<broj_cvorova; i++) {
            std::pair<double, double> cvor;
            double prvi, drugi;
            std::cin >> prvi >> drugi;
            cvor.first=prvi; cvor.second=drugi;
            v.push_back(cvor);
        }
        std::cout << "Unesite red interpolacije: ";
        int d;
        std::cin >> d;
        try {
            while(1) {
                std::cout << "Unesite argument (ili " << char(34) << "kraj" << char(34) << " za kraj): ";
                double x;
                std::cin >> x;
                if(!std::cin) break;
                if(std::cin.peek()!='\n') break;
                auto f(BaricentricnaInterpolacija(v, d));
                std::cout << "f(" << x << ") = " << f(x) << std::endl;
            }
        }
        catch(std::domain_error e) {
            std::cout << e.what();
        }
    }
    if(opcija==2) {
        std::cout << "Unesite krajeve intervala i korak: ";
        double x_min, x_max, dx;
        std::cin >> x_min >> x_max >> dx;
        std::cout << "Unesite red interpolacije: ";
        int d;
        std::cin >> d;
        try {
            while(1) {
                std::cout << "Unesite argument (ili " << char(34) << "kraj" << char(34) << " za kraj): ";
                double x;
                std::cin >> x;
                if(!std::cin) break;
                if(std::cin.peek()!='\n') break;
                auto f(BaricentricnaInterpolacija([] (double x) {return x*x+std::sin(x);} ,x_min, x_max, dx, d));
                std::cout << "f(" << x << ") = " << [] (double x) {return x*x+std::sin(x);} (x) <<" fapprox(" << x << ") = " << f(x) << std::endl;
            } 
        }
        catch(std::domain_error e) {
            std::cout << e.what();
        }
    }
	return 0;
}