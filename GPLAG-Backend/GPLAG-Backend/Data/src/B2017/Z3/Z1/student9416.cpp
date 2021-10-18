/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <functional>
#include <vector>
#include <utility>
#include <stdexcept>
#include <algorithm>
#include <cmath>
#include <limits>

std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double, double>> v)
{
    for(int i=0; i<v.size()-1; i++)
        for(int j=i+1; j<v.size(); j++) {
            if(v[j].first==v[i].first) throw std::domain_error("Neispravni cvorovi");
        }

    std::sort(v.begin(), v.end(), [](std::pair<double, double> x, std::pair<double, double> y) {
        return x.first<y.first;
    });

    return [v](double x) {

        if(x<v[0].first || x>v[v.size()-1].first) throw std::range_error("Argument izvan opsega");

        auto low=std::lower_bound(v.begin(), v.end(), std::make_pair(x, std::numeric_limits<double>::min()));
        auto up= std::upper_bound(v.begin(), v.end(), std::make_pair(x, std::numeric_limits<double>::min()));
        low--;

        return (low->second +
                (
                    (up->second - low->second)/(up->first - low->first))* (x-low->first)
              );
    };
}

std::function<double(double)> LinearnaInterpolacija(std::function<double(double)> fun, double min, double max, double D)
{

    if((min-max)>0.000001 || D<=0) throw std::domain_error("Nekorektni primjeri");
    std::vector<std::pair<double, double>> v;
    int k(0);
    while(min+k*D<max) {
        v.push_back(std::make_pair(min+k*D, fun(min+k*D)));

        k++;
    }
    v.push_back(std::make_pair(max, fun(max)));

    return [v](double x) {
        if(x<v[0].first || x>v[v.size()-1].first) throw std::range_error("Argument izvan opsega");
        auto low=std::lower_bound(v.begin(), v.end(), std::make_pair(x, std::numeric_limits<double>::min()));
        auto up= std::upper_bound(v.begin(), v.end(), std::make_pair(x, std::numeric_limits<double>::min()));
        low--;

        return (low->second +
                (
                    (up->second - low->second)/(up->first - low->first))* (x-low->first)
               );
    };
}

double fja (double x)
{
    return x*x + std::sin(x);
}

int main ()
{
    try {
        int opcija;
        std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        std::cin>>opcija;
        if(opcija==1) {

            int broj_cvorova;
            std::cout<<"Unesite broj cvorova: ";
            std::cin>>broj_cvorova;
            std::vector<std::pair<double, double>> v(broj_cvorova);
            std::cout<<"Unesite cvorove kao parove x y: ";
            for(int i=0; i<broj_cvorova; i++) {

                std::cin>> v[i].first >>v[i].second;
            }
            for(;;) {
                try {

                    double arg;
                    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    std::cin>>arg;
                    if(!std::cin) break;
                    auto f= LinearnaInterpolacija(v);
                    std::cout<< "f("<< arg <<") = " << f(arg) <<std::endl;
                } catch(std::range_error  izuzetak) {
                    std::cout<<izuzetak.what()<<std::endl;
                }

            }
        } else if (opcija==2) {
            double xmin, xmax, D;
            std::cout<<"Unesite krajeve intervala i korak: ";
            std::cin >> xmin>> xmax>> D;
            for(;;) {
                try {
                    double arg;
                    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    std::cin>>arg;
                    if(!std::cin) break;
                    auto f=LinearnaInterpolacija([](double x) {
                        return x*x+std::sin(x);
                    }, xmin, xmax, D);
                    std::cout<<"f(" <<arg <<") = "<<fja(arg)<< " fapprox(" <<arg <<") = " << f(arg) <<std::endl;
                } catch(std::range_error  izuzetak) {
                    std::cout<<izuzetak.what()<<std::endl;
                }

            }
        }

    } catch(std::domain_error izuzetak) {
        std::cout<<izuzetak.what()<<std::endl;
    }

    return 0;
}
