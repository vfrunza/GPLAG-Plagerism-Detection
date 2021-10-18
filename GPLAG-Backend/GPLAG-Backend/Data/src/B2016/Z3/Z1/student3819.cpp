/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <functional>
#include <vector>
#include <utility>
#include <stdexcept>
#include <cmath>
double fun(double x) {
    return x*x+std::sin(x);
}
std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double,double>> cvorovi, int d) {
    if(d<0 || d>=cvorovi.size()) throw std::domain_error("Nedozvoljen red");
    for(int i(0); i<cvorovi.size()-1; i++) {
        for(int j(i+1); j<cvorovi.size(); j++) {
            if(fabs(cvorovi[i].first-cvorovi[j].first)<0.00001) throw std::domain_error("Neispravni cvorovi");
        }
    }
    std::vector<double> wi;
    double proizvod;
    int mind(cvorovi.size()-d), min, k;
    for(int l(0); l<cvorovi.size(); l++) {
        double suma(0);
        if(mind<l+1) min=mind;
        else min=l+1;
        if(l+1-d>1) k=l+1-d;
        else k=1;
        //std::cout << "k = " << k << "   min = " << min << std::endl;
        for(int i(k); i<=min; i++) {
            proizvod=1;
            for(int j(i); j<=i+d; j++) {
                if(j-1!=l) {
                    proizvod*=1/(cvorovi[l].first-cvorovi[j-1].first);
                }
                //std::cout << "proizvod=" << proizvod << "   ";
            }
            suma+=pow(-1,i-1)*proizvod;
        }
        wi.push_back(suma);
    }
    /*for(int i(0); i<wi.size(); i++) {
        std::cout << wi[i] << "   ";
    }*/
    return [cvorovi, d, wi](double x){
        double nazivnik(0), brojnik(0);
        for(int i(0); i<cvorovi.size(); i++) {
            if(fabs(x-cvorovi[i].first)<0.000001) {
                return cvorovi[i].second;
            }
            else {
            brojnik+=(wi[i]/(x-cvorovi[i].first))*cvorovi[i].second;
            nazivnik+=wi[i]/(x-cvorovi[i].first);
            }
        }
        //std::cout << std::endl << brojnik << "    " << nazivnik;
        return brojnik/nazivnik;
    };
}
std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> f, double xmin, double xmax, double dx, int d) {
    std::vector<std::pair<double,double>> cvorovi;
    if(xmin>xmax || dx<=0) throw std::domain_error("Nekorektni parametri");
    int brojac(1);
    double temp=xmin;
    while(temp<=xmax) {
        std::pair<double,double> par;
        par=std::make_pair(temp, f(temp));
        cvorovi.push_back(par);
        temp = xmin+brojac*dx;
        brojac++;
    }
    //for(int i(0); i<cvorovi.size(); i++) {
      //  std::cout << cvorovi[i].first << "  " << cvorovi[i].second << std::endl;
    //}
    auto fun=BaricentricnaInterpolacija(cvorovi,d);
    return [fun](double x) {
      return fun(x);
    };
}
int main (){
    std::vector<std::pair<double,double>> cvorovi;
    std::pair<double,double> par;
    int opcija, brojcvorova, d;
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin >> opcija;
    if(opcija==1) {
        std::cout << "Unesite broj cvorova: ";
        std::cin >> brojcvorova;
        double x, y;
        std::cout << "Unesite cvorove kao parove x y: ";
        for(int i(0); i<brojcvorova; i++) {
            std::cin >> x >> y;
            par=std::make_pair(x, y);
            cvorovi.push_back(par);
        }
        std::cout << "Unesite red interpolacije: ";
        std::cin >> d;
        try {
            for(;;) {
                double a;
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                std::cin >> a;
                if(!std::cin) break;
                auto f(BaricentricnaInterpolacija(cvorovi, d));
                std::cout << "f("<< a << ") = " << f(a) << std::endl;
            }
        }
        catch(std::domain_error izuzetak) {
            std::cout << izuzetak.what();
            return 0;
        }
    }
    if(opcija==2) {
        double xmin, xmax, dx;
        std::cout << "Unesite krajeve intervala i korak: ";
        std::cin >> xmin >> xmax >> dx;
        std::cout << "Unesite red interpolacije: ";
        std::cin >> d;
        try {
            for(;;) {
                double a;
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                std::cin >> a;
                if(!std::cin) break;
                auto fapprox(BaricentricnaInterpolacija(fun, xmin, xmax, dx, d));
                std::cout <<  "f("<< a << ") = " << fun(a) << " fapprox(" << a << ") = " << fapprox(a) << std::endl;
            }
        }
        catch(std::domain_error izuzetak) {
            std::cout << izuzetak.what();
            return 0;
        }
    }
	return 0;
}