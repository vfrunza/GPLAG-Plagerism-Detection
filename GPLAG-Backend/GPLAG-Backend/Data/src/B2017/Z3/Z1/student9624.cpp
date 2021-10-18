/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <functional>
#include <vector>
#include <utility>
#include <algorithm>
#include <stdexcept>
#include <cmath>

std::function<double(double)> LinearnaInterpolacija (std::vector<std::pair<double,double>> v)
{

    for (int i= 0 ; i<v.size()-1 ; i++) {
        for(int j=i+1 ; j<v.size() ; j++)
            if(v.at(i).first==v.at(j).first) {
                throw std::domain_error ("Neispravni cvorovi");
            }
    }
    std::sort(v.begin() , v.end() , [] (std::pair<double,double> p1, std::pair<double,double> p2) {
        return p1.first<p2.first;
    });

    return [v] (double x) {
        if(x<v.at(0).first || x>v.at(v.size()-1).first) {
            throw std::range_error ("Argument izvan opsega");
        }
        if(x==v.at(v.size()-1).first) return v.at(v.size()-1).second;
        auto a(std::make_pair(x,0));
        auto p(std::upper_bound(v.begin(), v.end() , a, [](std::pair<double,double> p1, std::pair<double,double> p2)-> bool { return p1.first<p2.first; }));
        int i(p-v.begin());
        double fun;
        fun=v[i-1].second+(v[i].second-v[i-1].second)/(v[i].first-v[i-1].first)*(x-v[i-1].first);
        return fun;
    };

}

std::function<double(double)> LinearnaInterpolacija(std::function<double(double)> fun , double min , double max, double d)
{
    if( min>max || d<=0) throw std::domain_error ("Nekorektni parametri");
    std::vector<std::pair<double,double>> v;
    double pom(min);
    int i=0;
    while(pom<=max) {
        v.push_back(std::make_pair(min+i*d,fun(min+i*d)));
        i++;
        pom += d;
    }
    return LinearnaInterpolacija(v);
}

int main ()
{
    int opcija;
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin>>opcija;
    if(opcija ==1) {
        int n;
        std::cout<<"Unesite broj cvorova: ";
        std::cin>>n;
        std::cout<<"Unesite cvorove kao parove x y: ";
        std::vector<std::pair<double,double>> v;
        for(int i= 0 ; i<n ; i++) {
            double x,y;
            std::cin>>x>>y;
            v.push_back(std::make_pair(x,y));
        }
        try {

            auto f(LinearnaInterpolacija(v));
            while(std::cin) {
                try {
                    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    double x;
                    std::cin>>x;
                    if(!std::cin) return 0;
                    std::cout<<"f("<<x<<") = "<<f(x)<<std::endl ;
                } catch(std::range_error e) {
                    std::cout<<e.what()<<std::endl;
                }

            }
        }

        catch(std::domain_error e) {
            std::cout<<e.what();
        }
    }

    if(opcija == 2) {
        double a,b, c;
        std::cout<<"Unesite krajeve intervala i korak: ";
        std::cin>>a>>b>>c;
        try {



            auto fapr(LinearnaInterpolacija([] (double x) {
                return x*x+std::sin(x);
            },a ,b, c));
            while(1) {
                try {
                    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    double x;
                    std::cin>>x;
                    if(!std::cin) return 0;

                    std::cout<<"f("<<x<<") = "<<x*x+std::sin(x)<<" fapprox("<<x<<") = "<<fapr(x)<<std::endl ;
                } catch(std::range_error e) {
                    std::cout<<e.what()<<std::endl;
                }


            }
        }

        catch(std::domain_error e) {
            std::cout<<e.what();
        }
    }
    return 0;
}
