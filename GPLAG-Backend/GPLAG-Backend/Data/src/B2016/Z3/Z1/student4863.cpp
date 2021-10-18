/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <functional>
#include <stdexcept>
#include <utility>
#include <vector>
#include <cmath>

double funkcija(double x) {
    return x*x + std::sin(x);
}

int min(int a, int b) {
    if(a < b) return a;
    else return b;
}
int max(int a, int b) {
    if(a > b) return a;
    else return b;
}

double pomocna(int i, std::vector<std::pair<double, double>> v, int d) {
    double suma(0);
    int poc(max(1, i-d)), kraj(min(i, v.size()-d));
    while(poc <= kraj) {
        double produkt(1);
        for(int j=poc; j<=poc+d; j++){
            if(i != j) 
                produkt *= 1./(v[i-1].first - v[j-1].first);
        }
        produkt *=double(std::pow(-1, poc-1));
        suma += produkt;
        poc++;
    }
    return suma;
}

std::function<double(double)> BaricentricnaInterpolacija (std::vector<std::pair<double, double>> v, int d) {
    if(d < 0 || d >= v.size())
        throw std::domain_error("Nedozvoljen red");
    int br(0);
    const double eps (1e-12);
    for(int i = 0; i < v.size(); i++) {
        br = 0;
        for(int j = 0; j < v.size(); j++)
            if(v[i].first == v[j].first)
                br++;
        if(br != 1) throw std::domain_error("Neispravni cvorovi");
    }
    std::vector<double> w;
    for(int i = 1; i < v.size()+1; i++)
        w.push_back(pomocna(i,v,d));
    return [v, d, w, eps](double x)->double {
        for(int i = 0; i < v.size(); i++)
            if(x==v[i].first) return v[i].second;
        double suma1(0), suma2(0);
        for(int i=1; i<v.size()+1; i++) {
            suma1+=w[i-1]/(x-v[i-1].first)*v[i-1].second;
            suma2+=w[i-1]/(x-v[i-1].first);
        }
        return suma1/suma2;
    };
}

std::function<double(double)> BaricentricnaInterpolacija (std::function<double(double)> f, double xmin, double xmax, double dx, double d) {
    std::vector<std::pair<double, double>> v;
    if(xmin > xmax || dx <= 0)
        throw std::domain_error("Nekorektni parametri");
    while(xmin <= xmax) {
        v.push_back(std::pair<double,double>{xmin, f(xmin)});
        xmin+=dx;
    }
    return BaricentricnaInterpolacija(v, d);
}
int main ()
{
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int n(0);
    std::cin>>n;
    try {
    switch(n) {
        case 1:{
            std::cout<<"Unesite broj cvorova: ";
            int cvorovi;
            std::cin>>cvorovi;
            std::vector<std::pair<double, double>> v(cvorovi);
            std::cout<<"Unesite cvorove kao parove x y: ";
            for(int i=0; i<cvorovi; i++) {
               double x,y;
               std::cin>>x>>y;
               v[i] = std::pair<double,double> {x,y};
            }
            std::cout<<"Unesite red interpolacije: ";
            int d;
            std::cin>>d;
            for(;;) {
                std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                double arg;
                std::cin>>arg;
                if(!std::cin)
                    break;
                double tmp(BaricentricnaInterpolacija(v, d)(arg));
                std::cout<<"f("<<arg<<") = "<< tmp <<std::endl;
            }
            break;
        }
        case 2:{
            std::cout<<"Unesite krajeve intervala i korak: ";
            double xmin, xmax, dx;
            std::cin>>xmin>>xmax>>dx;
            std::cout<<"Unesite red interpolacije: ";
            double d;
            std::cin>>d;
            for(;;) {
                std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                double arg;
                std::cin>>arg;
                if(!std::cin)
                    break;
                auto tmp (BaricentricnaInterpolacija(funkcija, xmin, xmax, dx, d)(arg));
                std::cout<<"f("<<arg<<") = "<<funkcija(arg)<<" fapprox("<<arg<<") = "<<tmp<<std::endl;
            }
            break;
        }
    }
    }
    catch(std::domain_error e) {
        std::cout<<e.what();
    }
    catch(...) {
        
    }
	return 0;
}