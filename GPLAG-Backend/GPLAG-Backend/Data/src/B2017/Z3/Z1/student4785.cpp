/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <utility>
#include <stdexcept>
#include <functional>
#include <algorithm>
#include <cmath>

bool Kriterij(std::pair<double,double>p1, std::pair<double,double> p2)
{
    return p1.first<p2.first;
}

double F(double x)
{
    return x*x+sin(x);
}

std::function<double(double)>LinearnaInterpolacija(std::vector<std::pair<double,double>> cvorovi)
{
    for(int i=0; i<cvorovi.size(); i++) {
        for(int j=0; j<i; j++) {
            if(cvorovi.at(i).first==cvorovi.at(j).first) throw std::domain_error("Neispravni cvorovi");
        }
    }
    std::sort(cvorovi.begin(),cvorovi.end(),Kriterij);
    return [cvorovi](double x)->double {
        if(cvorovi.size()==0)  throw std::range_error("Argument izvan opsega");
        if(x<cvorovi.at(0).first || x>cvorovi.at(cvorovi.size()-1).first) throw std::range_error("Argument izvan opsega");
        if(x==cvorovi.at(cvorovi.size()-1).first) return cvorovi.at(cvorovi.size()-1).second;
        auto veci=upper_bound(cvorovi.begin(),cvorovi.end(),std::make_pair(x,std::numeric_limits<double>::min()),Kriterij);
        auto manji=veci;
        manji--;
        return manji->second+((veci->second-manji->second)/(veci->first-manji->first))*(x-manji->first);
    };
}

std::function<double(double)>LinearnaInterpolacija(std::function<double(double)> fun,double x_min, double x_max, double d_x)
{
    if(x_min>x_max || d_x<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> cvorovi;
    double pomocna(x_min);
    do {
        cvorovi.push_back({pomocna,fun(pomocna)});
        pomocna+=d_x;
    } while(pomocna<=x_max);
    return LinearnaInterpolacija(cvorovi);
}

int main ()
{
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int opcija;
    std::cin>>opcija;

    try {
        if(opcija==1) {
            std::cout<<"Unesite broj cvorova: ";
            int br_cvorova;
            std::cin>>br_cvorova;
            std::vector<std::pair<double,double>> cvorovi(br_cvorova);
            std::cout<<"Unesite cvorove kao parove x y: ";
            for (auto &c:cvorovi) {
                std::cin>>c.first;
                std::cin>>c.second;
            }
            auto f=LinearnaInterpolacija(cvorovi);
            for(;;) {
                std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                double x;
                std::cin>>x;
                if(!std::cin || std::cin.peek()!='\n') break;
                try {
                    std::cout<<"f("<<x<<") = "<<f(x)<<std::endl;
                } catch(std::range_error e) {
                    std::cout<<e.what()<<std::endl;
                }
            }
        } else {
            std::cout<<"Unesite krajeve intervala i korak: ";
            double x_min,x_max,d_x;
            std::cin>>x_min>>x_max>>d_x;
            auto f=LinearnaInterpolacija(F,x_min,x_max,d_x);
            for(;;) {
                std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                double x;
                std::cin>>x;
                if(!std::cin || std::cin.peek()!='\n') break; 
                try {
                    std::cout<<"f("<<x<<") = "<<F(x)<<" fapprox("<<x<<") = "<<f(x)<<std::endl;
                } catch(std::range_error e) {
                    std::cout<<e.what()<<std::endl;
                }
            }
        }
    } catch(std::domain_error e) {
        std::cout<<e.what();
    }
    return 0;
}
