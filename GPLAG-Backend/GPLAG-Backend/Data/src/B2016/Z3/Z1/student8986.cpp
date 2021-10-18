#include <iostream>
#include <functional>
#include <utility>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdexcept>

typedef std::vector<std::pair<double,double>> VektorParova;


bool KorektniCvorovi(const VektorParova &cvorovi) {
    for(int i=0; i<cvorovi.size(); i++) {
        for(int j=i+1; j<cvorovi.size(); j++) {
            if(cvorovi[i].first==cvorovi[j].first)
                return false;
        }
    }
    return true;
}

double TezinskiKoeficijent(int i, int k, int maxs, int d, const VektorParova &cvorovi) {
    
    double w(0);
    
    while(k<=maxs) {
        double proizvod(1);
        for(int j=k; j<=k+d; j++) {
            if(j==i) continue;
            proizvod*=1./(cvorovi[i-1].first-cvorovi[j-1].first);
        }
        proizvod*=std::pow(-1, k-1);
        w+=proizvod;
        k++;
    }
    return w;
}

std::function<double(double)> BaricentricnaInterpolacija(VektorParova cvorovi, int d) {
    if(d<0 || d>=cvorovi.size())
            throw std::domain_error ("Nedozvoljen red");
    if(!KorektniCvorovi(cvorovi))
        throw std::domain_error ("Neispravni cvorovi");
    return [=] (double x) {
        double brojnik(0);
        double nazivnik(0);
        for(int i=0; i<cvorovi.size(); i++) {
            if(x==cvorovi[i].first) return cvorovi[i].second;
            double w;
            w=TezinskiKoeficijent(i+1, std::max(1,i+1-d), std::min(i+1,int(cvorovi.size()-d)), d, cvorovi);
            nazivnik+=w/(x-cvorovi[i].first);
            brojnik+=(w/(x-cvorovi[i].first))*cvorovi[i].second;
        }
        return (brojnik/nazivnik);
    };
}

template <typename FunkTip>
std::function<double(double)> BaricentricnaInterpolacija(FunkTip f, double x_min, double x_max, double delta_x, int d) {
    VektorParova cvorovi;
    
    if(x_min>x_max || delta_x<=0)
        throw std::domain_error ("Nekorektni parametri");
            
    for(double i=x_min; i<=x_max; i+=delta_x) {
        cvorovi.push_back(std::make_pair(i,f(i)));
        
    }
    if(d<0 || d>=cvorovi.size())
            throw std::domain_error ("Nedozvoljen red");
    if(!KorektniCvorovi(cvorovi))
        throw std::domain_error ("Neispravni cvorovi");
    return BaricentricnaInterpolacija(cvorovi, d);
}

double fun(double x) {
    return x*x+std::sin(x);
}

int main ()
{
    try {
    
    int opcija;
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin>>opcija;
    if(opcija==1) {
        VektorParova cvorovi;
        int n;
        std::cout<<"Unesite broj cvorova: ";
        std::cin>>n;
        std::cout<<"Unesite cvorove kao parove x y: ";
        for(int i=0; i<n; i++) {
            double x,y;
            std::cin>>x>>y;
            cvorovi.push_back(std::make_pair(x,y));
        }
        if(!KorektniCvorovi(cvorovi))
            throw std::domain_error ("Neispravni cvorovi");
        std::cout<<"Unesite red interpolacije: ";
        int d;
        std::cin>>d;
        if(d<0 || d>=n)
            throw std::domain_error ("Nedozvoljen red");
        
        for(;;) {
            std::cout<<"Unesite argument (ili "<<'"'<<"kraj"<<'"'<<" za kraj): ";
            double x;
            std::cin>>x;
            if(!std::cin) return 0;
            std::cout<<"f("<<x<<") = "<<BaricentricnaInterpolacija(cvorovi,d)(x)<<std::endl;
        }
    }
    else {
        double x_min, x_max, delta_x;
        int d;
        std::cout<<"Unesite krajeve intervala i korak: ";
        std::cin>>x_min>>x_max>>delta_x;
        if(x_min>x_max || delta_x<=0)
            throw std::domain_error ("Nekorektni parametri");
        std::cout<<"Unesite red interpolacije: ";
        std::cin>>d;
        
        for(;;) {
            std::cout<<"Unesite argument (ili "<<'"'<<"kraj"<<'"'<<" za kraj): ";
            double x;
            std::cin>>x;
            if(!std::cin) return 0;
            std::cout<<"f("<<x<<") = "<<fun(x)<<" fapprox("<<x<<") = "<<BaricentricnaInterpolacija(fun, x_min, x_max, delta_x, d)(x)<<std::endl;
        }
    }
    }
    
    catch(std::domain_error greska) {
        std::cout<<greska.what();
    }
	return 0;
}