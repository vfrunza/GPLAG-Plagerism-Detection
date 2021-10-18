/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <stdexcept>
#include <algorithm>
#include <cmath>

std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double,double>> v)
{
    for(int i(0); i<v.size()-1; i++) {
        for(int j(i+1); j<v.size(); j++) {
            if(v[i].first==v[j].first) throw std::domain_error("Neispravni cvorovi");
        }
    }
    sort(v.begin(),v.end(),[](std::pair<double,double> x,std::pair<double,double> y) {
        return x.first<y.first;
    });
    return [v](double x) {
        if(x<v[0].first or x>v[v.size()-1].first) throw std::range_error("Argument izvan opsega");
     /*  auto poslije(lower_bound(v.begin(),v.end(),x,[](std::pair<double,double> x,std::pair<double,double> y) {
        return x.first<y.first;));
       */
        std::pair<double,double> prije,poslije;
        for(int i(0); i<v.size()-1; i++) {
            if(x==v[0].first) return v[0].second;
            if(x==v[i+1].first)  return v[i+1].second;
            if( v[i].first<x and v[i+1].first>x) {
                prije.first=v[i].first;
                poslije.first=v[i+1].first;
                prije.second=v[i].second;
                poslije.second=v[i+1].second;
            }
        }
        return prije.second+(poslije.second-prije.second)/(poslije.first-prije.first)*(x-prije.first);
    };
}
std::function<double(double)> LinearnaInterpolacija(std::function<double(double)> fun,double xmin,double xmax,double deltax)
{
    if(xmin>xmax or deltax<=0) throw std::domain_error("Nekorektni parametri");
    auto pom(xmin);
    int broji(0);
    while(pom<=xmax) {
        broji++;
        pom+=deltax;
    }
    std::vector<std::pair<double,double>>  v(broji);
    for(int i(0); i<broji; i++) {
        v[i].first=xmin+i*deltax;
        v[i].second=fun(v[i].first);
    }
    return LinearnaInterpolacija(v);
}
int main ()
{
    int opcija;
    std::cout<< "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin >> opcija;
    if(opcija==1) {
        int brcvorova;
        std::cout << "Unesite broj cvorova: " ;
        std::cin >> brcvorova;
        std::vector<std::pair<double,double>> v(brcvorova);
        std::cout <<"Unesite cvorove kao parove x y: " ;
        for(int i(0); i<brcvorova; i++) {
            double x,y;
            std::cin >> x;
            std::cin >> y;
            v[i].first=x;
            v[i].second=y;
        }
        try {
            auto f(LinearnaInterpolacija(v));
            for( ; ; ) {
                try {
                    std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                    double unos;
                    std::cin >> unos;
                    if(!std::cin) break;
                    std::cout << "f("<< unos <<") = " << f(unos)<< std::endl;
                } catch(std::range_error poruka) {
                    std::cout << poruka.what()  << std::endl;
                }
            }
        } catch(std::domain_error poruka) {
            std::cout << poruka.what() << std::endl;
        }
    } else if(opcija==2) {
        std::cout << "Unesite krajeve intervala i korak: ";
        double min,max,korak;
        std::cin >> min;
        std::cin >> max;
        std::cin >> korak;
        try {
            auto f(LinearnaInterpolacija([](double x) {
                return x*x+std::sin(x);
            },min,max,korak));
            for(;;){
                try {
                    std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                    double unos;
                    std::cin >> unos;
                    if(!std::cin) break;
                    std::cout <<"f("<<unos<<") = " << unos*unos+std::sin(unos)<<" fapprox("<<unos<<") = "<<f(unos)<< std::endl;
                }
                catch (std::range_error por) {
                    std::cout << por.what()<<std::endl ;
                }
            }
        } catch(std::domain_error poruka) {
            std::cout << poruka.what();
        }
    }
    return 0;
}