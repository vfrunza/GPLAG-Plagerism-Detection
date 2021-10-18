#include <iostream>
#include <functional>
#include <vector>
#include <utility>
#include <algorithm>
#include <stdexcept>
#include <cmath>

double funkcija (double x)
{
    return x*x+std::sin(x);
}
std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double,double>> tacke)
{
    std::sort(tacke.begin(),tacke.end(),[](const std::pair<double,double> & x,const std::pair<double,double> & y) {
        return x.first<y.first;
    });
    for (int i = 0; i < tacke.size()-1; i++) {
        if(tacke.at(i).first==tacke.at(i+1).first)
            throw std::domain_error("Neispravni cvorovi");
    }
    return [tacke](double x)->double {
        if(x<(*tacke.begin()).first || x>(*(tacke.end()-1)).first)
            throw std::range_error("Argument izvan opsega");
        auto it=std::lower_bound(tacke.begin(),tacke.end(),std::make_pair(x,0.));
        if(x==it->first)
            return it->second;
        return (it-1)->second+(it->second-(it-1)->second)*(x-(it-1)->first)/(it->first-(it-1)->first);
    };
}
std::function<double(double)> LinearnaInterpolacija(double f(double), double x1, double x2, double delta_x)
{
    if(x1>x2 || delta_x<0)
        throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double >> tacke  ;
    for (int i = 0; x1+i*delta_x <x2 ; i++) {
        tacke.push_back(std::make_pair(x1+delta_x*i,f(x1+delta_x*i)));
    }
    tacke.push_back(std::make_pair(x2,f(x2)));
    return [tacke](double x)->double {
        if(x<(*tacke.begin()).first || x>(*(tacke.end()-1)).first)
            throw std::range_error("Argument izvan opsega");
        auto it=std::lower_bound(tacke.begin(),tacke.end(),std::make_pair(x,0.));
        if(x==it->first)
            return it->second;
        return (it-1)->second+(it->second-(it-1)->second)*(x-(it-1)->first)/(it->first-(it-1)->first);
    };
}
int main ()
{
    try {
        std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        int unos;
        std::vector<std::pair<double,double>> tacke;
        std::cin>>unos;
        if (unos==1) {
            std::cout<<"Unesite broj cvorova: ";
            int broj;
            std::cin>>broj;
            std::cout<<"Unesite cvorove kao parove x y: ";
            double x,y;
            int brojac(0);
            std::pair<double,double> par;
            while (brojac!=broj) {
                std::cin>>x>>y;
                par=std::make_pair(x,y);
                tacke.push_back(par);
                brojac++;
            }
            auto f(LinearnaInterpolacija(tacke));
            for (;;) {
                try {
                    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    double argument;
                    std::cin>>argument;
                    if (!std::cin) break;
                    std::cout<<"f("<<argument<<") = "<<f(argument)<<std::endl;
                } catch (std::range_error r) {
                    std::cout<<r.what()<<std::endl;
                }
            }
        } else if (unos==2) {
            std::cout<<"Unesite krajeve intervala i korak: ";
            double x,y,z;
            std::cin>>x>>y>>z;
            auto f(LinearnaInterpolacija(funkcija,x,y,z));
            for (;;) {
                try {
                    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    double argument;
                    std::cin>>argument;
                    if (!std::cin) break;
                    auto pom(funkcija(argument));
                    std::cout<<"f("<<argument<<") = "<<pom<<" fapprox("<<argument<<") = "<<f(argument)<<std::endl;
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