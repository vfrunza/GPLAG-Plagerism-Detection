#include <iostream>
#include <functional>
#include <vector>
#include <utility>
#include <stdexcept>
#include <algorithm>
#include <cmath>

double funkcija (double x)
{
    return x*x+std::sin(x);
}

bool Veci(std::pair<double,double> x,std::pair<double,double> y)
{
    return x.first<y.first;
}

bool Sortiran (std::vector<std::pair<double,double>> brojevi)
{
    for (int i=0; i<brojevi.size()-1; i++) {
        if (brojevi.at(i).first>brojevi.at(i+1).first) return false;
    }
    return true;
}

std::function<double(double)> LinearnaInterpolacija (std::vector<std::pair<double,double>> brojevi)
{
    bool ponavljanje(false);
    bool sortiranje;
    for (int i=0; i<brojevi.size(); i++) {
        for (int j=i+1; j<brojevi.size(); j++) {
            if (brojevi.at(i).first==brojevi.at(j).first) {
                ponavljanje=true;
                break;
            }
        }
        if (ponavljanje) break;
    }
    if (ponavljanje) throw std::domain_error ("Neispravni cvorovi");
    sortiranje=Sortiran(brojevi);
    if (sortiranje==false) std::sort(brojevi.begin(),brojevi.end(),Veci);
    return [brojevi] (double x) {
        if (x<brojevi.at(0).first || x>brojevi.at(brojevi.size()-1).first) throw std::range_error ("Argument izvan opsega");
        for (int i=0; i<brojevi.size(); i++) {
            if (x==brojevi.at(brojevi.size()-1).first) return brojevi.at(brojevi.size()-1).second;
        }
        std::pair<double,double> X;
        X=std::make_pair(x,x);
        auto pom=std::upper_bound(brojevi.begin(),brojevi.end(),X);
        return (*(pom-1)).second+((*pom).second-(*(pom-1)).second)/((*pom).first-(*(pom-1)).first)*(x-(*(pom-1)).first);
    };
}

std::function<double(double)> LinearnaInterpolacija (double funkcija(double), double x_min, double x_max, double X)
{
    if (x_min>x_max || X<0) throw std::domain_error ("Nekorektni parametri");
    std::vector<std::pair<double,double>> cvorovi;
    double pom(0);
    while (x_min+pom<x_max) {
        cvorovi.push_back(std::make_pair(x_min+pom,funkcija(x_min+pom)));
        pom+=X;
    }
    return LinearnaInterpolacija(cvorovi);
}

int main ()
{
    try {
        std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        int n;
        std::cin>>n;
        if (n==1) {
            std::vector<std::pair<double,double>> cvor;
            std::cout<<"Unesite broj cvorova: ";
            int n1;
            std::cin>>n1;
            cvor.resize(n1);
            std::cout<<"Unesite cvorove kao parove x y: ";
            for (int i=0; i<cvor.size(); i++) {
                double x,y;
                std::cin>>x>>y;
                cvor.at(i)=std::make_pair(x,y);
            }
            auto f(LinearnaInterpolacija(cvor));
            for (;;) {
                try {
                    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    double unos;
                    std::cin>>unos;
                    if (!std::cin || ((std::cin.peek()<'0' || std::cin.peek()>'9') && std::cin.peek()!='\n')) break;
                    std::cout<<"f("<<unos<<") = "<<f(unos)<<std::endl;
                } catch (std::range_error r) {
                    std::cout<<r.what()<<std::endl;
                }
            }
        } else if (n==2) {
            std::cout<<"Unesite krajeve intervala i korak: ";
            double x,y,z;
            std::cin>>x;
            std::cin>>y;
            std::cin>>z;
            auto f2 (LinearnaInterpolacija(funkcija,x,y,z));
            for (;;) {
                try {
                    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    double unos;
                    std::cin>>unos;
                    if (!std::cin || ((std::cin.peek()<'0' || std::cin.peek()>'9') && std::cin.peek()!='\n')) break;
                    auto f1 (funkcija(unos));
                    std::cout<<"f("<<unos<<") = "<<f1<<" fapprox("<<unos<<") = "<<f2(unos)<<std::endl;
                } catch (std::range_error r) {
                    std::cout<<r.what()<<std::endl;
                }
            }
        }
    } catch (std::domain_error d) {
        std::cout<<d.what();
    }

    return 0;
}
