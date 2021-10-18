/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <utility>
#include <iomanip>
#include <stdexcept>
#include <functional>
#include <cmath>

std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double, double>> v, int d)
{
    if(d<0 || d>=v.size()) throw std::domain_error("Nedozvoljen red");
    try{
    bool isto(false);
    for(int i=0; i<v.size(); i++) {
        for(int j=i+1; j<v.size(); j++) {
            if(v[i].first==v[j].first) {
                isto=true;
                break;
            }
        }
        if(isto) break;
    }
    
    if(isto) throw std::domain_error("Neispravni cvorovi");
    }
    catch(...)
    {
        throw;
    }
    return [v, d] (double x)
    {
        for(int i=0; i<v.size(); i++) {
            if(x==v[i].first) return v[i].second;
        }
        int n(v.size());
        double saberi_br(0), saberi_nz(0);
        for(int i=1; i<=n; i++) {
            double w(0);
            int manji(i);
            if(i>n-d) manji=n-d;
            int veci(1);
            if(1<i-d) veci=i-d;
            for(int k=veci; k<=manji; k++) {
                double proizvod(1);
                for(int j=k; j<=k+d; j++) {
                    if((j-1)!=(i-1)) proizvod*=(1/(v[i-1].first-v[j-1].first));
                }
                if((k-1)%2==0) w+=proizvod;
                else w-=proizvod;
            }
            if(x!=v[i-1].first) saberi_br+=w/(x-v[i-1].first)*v[i-1].second;
            if(x!=v[i-1].first) saberi_nz+=w/(x-v[i-1].first);
        }
        return saberi_br/saberi_nz;
    };
}

std::function<double(double)>BaricentricnaInterpolacija(double f(double), double xmin, double xmax, double deltax,  int d)
{
    if(xmin>xmax || deltax<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double, double>> v;
    double x(xmin);
    while(x<=xmax) {
        v.push_back(std::pair<double, double>(x, f(x)));
        x=x+deltax;
        if(x>xmax) break;
    }
    return BaricentricnaInterpolacija(v, d);
}

int main ()
{ try{
    int opcija;
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin >> opcija;
    std::vector<std::pair<double, double>> v;
    if(opcija==1) {
        std::cout << "Unesite broj cvorova: ";
        int br_cvorova;
        std::cin >> br_cvorova;
        std::cout << "Unesite cvorove kao parove x y: ";
        for(int i=0; i<br_cvorova; i++) {
            std::pair<double, double> pomocni;
           double broj1, broj2;
           std::cin >> broj1 >> broj2;
           pomocni.first=broj1;
           pomocni.second=broj2;
           v.push_back(pomocni);
        }
        std::cout << "Unesite red interpolacije: ";
        int d;
        std::cin >> d;
        if(d<0 || d>=br_cvorova) throw std::domain_error("Nedozvoljen red");
        auto f(BaricentricnaInterpolacija(v, d));
        double arg;
        std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
        std::cin >> arg;
        while(std::cin) {
            std::cout << "f(" << arg << ") = " << f(arg) << std::endl;
            std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
            std::cin >> arg;
        }
        }
        
        
    if(opcija==2) {
        std::cout << "Unesite krajeve intervala i korak: ";
        double  xmin, xmax; int d;
        double deltax;
        std::cin >> xmin >> xmax >> deltax;
        std::cout << "Unesite red interpolacije: ";
        std::cin >> d;
        auto f(BaricentricnaInterpolacija([](double x) { return x*x+std::sin(x);}, xmin, xmax, deltax, d));
        double arg;
        std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
        std::cin >> arg;
        while(std::cin) {
            std::cout << "f(" << arg << ") = " << arg*arg+std::sin(arg)  << " fapprox(" << arg << ") = " << f(arg) << std::endl;
            std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
            std::cin >> arg;
        }
    }
    }
    catch(std::domain_error tekst)
    {
        std::cout << tekst.what() << std::endl;
    }
    
	return 0;
}