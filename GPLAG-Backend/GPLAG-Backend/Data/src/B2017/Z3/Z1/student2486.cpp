/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <functional>
#include <vector>
#include <utility>
#include <algorithm>
#include <stdexcept>
#include <cmath>



std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double,double>> par) {
    for (int i=0; i<par.size(); i++) {
        for (int j=i+1; j<par.size(); j++) {
            if (par[i].first==par[j].first) throw std::domain_error("Neispravni cvorovi");
        }
    }
    std::sort(par.begin(), par.end(), [] (std::pair<double,double> p1, std::pair <double,double> p2) -> bool{
        return p1.first<p2.first;
    });
    return [par] (double x) -> double {
        if (x<par[0].first || x>par[par.size()-1].first) throw std::range_error("Argument izvan opsega");
        auto ZaPoredjenje(std::make_pair(x,0));
        auto a(std::lower_bound(par.begin(), par.end(), ZaPoredjenje, [] (std::pair<double,double> p1, std::pair<double,double> p2)-> bool {
            return p1.first<p2.first;
        }));
        auto b=a-1;
        double povratni(0);
        povratni+=b->second;
        double brojnik(b->second-a->second); double nazivnik(b->first-a->first);
        povratni+=(brojnik/nazivnik)*(x-b->first);
        return povratni;
    };
}

double funk(double x) {
    return (x*x+std::sin(x));
}

std::function<double(double)> LinearnaInterpolacija(double f(double x), double x_min, double x_max, double x_delta) {
    if (x_delta<=0) throw std::domain_error("Nekorektni parametri");
    if (x_min>x_max) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> v;
    auto i=x_min;
    while (i<=x_max) {
        std::pair<double,double> novi_cvor=std::make_pair(i,f(i));
        v.push_back(novi_cvor);
        i+=x_delta;
    }
    return [v](double x) -> double {
        if (x<v[0].first || x>v[v.size()-1].first) throw std::range_error("Argument izvan opsega");
        auto ZaPoredjenje(std::make_pair(x,0));
        auto a(std::lower_bound(v.begin(), v.end(), ZaPoredjenje, [] (std::pair<double,double> p1, std::pair<double,double> p2)-> bool {
            return p1.first<p2.first;
        }));
        auto b=a-1;
        double povratni(0);
        povratni+=b->second;
        double brojnik(b->second-a->second); double nazivnik(b->first-a->first);
        povratni+=(brojnik/nazivnik)*(x-b->first);
        return povratni;
    };
}

int main ()
{
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int opcija;
    std::cin>>opcija;
    std::vector<std::pair<double,double>> cvorovi;
    if (opcija==1) {
        std::cout<<"Unesite broj cvorova: ";
        int broj;
        std::cin>>broj;
        std::cout<<"Unesite cvorove kao parove x y: ";
        for (int i=0; i<broj; i++) {
            std::pair<double,double> cvor;
            double prvi;
            std::cin>>prvi;
            double drugi;
            std::cin>>drugi;
            cvor.first=prvi;
            cvor.second=drugi;
            cvorovi.push_back(cvor);
        }
        try {
                auto f(LinearnaInterpolacija(cvorovi));
        while (1) {
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            double argument;
            std::cin>>argument;
            if (!std::cin) break;
            try {
                std::cout<<"f("<<argument<<") = "<<f(argument)<<std::endl;
            }
            catch (std::range_error m) {
                std::cout<<m.what()<<std::endl;
            }
        }
        }
        catch (std::domain_error e) {
                std::cout<<e.what()<<std::endl;
            }
    }
    else if (opcija==2) {
        std::cout<<"Unesite krajeve intervala i korak: ";
        double x_min, x_max, korak;
        std::cin>>x_min>>x_max>>korak;
        try {
                auto f(LinearnaInterpolacija(funk, x_min, x_max, korak));
            while (1) {
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            double argument;
            std::cin>>argument;
            if (!std::cin) break;
            try {
                std::cout<<"f("<<argument<<") = "<<funk(argument)<<" fapprox("<<argument<<") = "<<f(argument)<<std::endl;
            }
            catch (std::range_error r) {
                std::cout<<r.what()<<std::endl;
            }
        }
    }
    catch (std::domain_error e) {
        std::cout<<e.what()<<std::endl;
        }
    }
	return 0;
}




