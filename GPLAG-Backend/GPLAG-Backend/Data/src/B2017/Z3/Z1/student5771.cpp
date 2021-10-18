/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <utility>
#include <vector>
#include <functional>
#include <stdexcept>
#include <algorithm>
#include <cmath>
bool Kriterij(std::pair<double, double>p1, std::pair<double, double>p2){
    return (p1.first<p2.first);
}

double Funkcija(double x){
    return x*x+sin(x);
}

std::function<double(double)>LinearnaInterpolacija(std::vector<std::pair<double, double>> v) {
    std::sort(v.begin(), v.end(),Kriterij);
    return [&v](double x){ 
        if(x<(v.begin()->first) || (x>(v.end()-1)->first)) throw std::range_error("Argument izvan opsega");
        std::pair<double,double>p;
        p.first=x;
        p.second=0;
        auto it1(lower_bound(v.begin(),v.end(), p, Kriterij));
        it1--;
        auto it2(upper_bound(v.begin(),v.end(), p, Kriterij));
        double x1=it1->first;
        double x2=it2->first;
        double y1=it1->second;
        double y2=it2->second;
        return (y1+(((y2-y1)/(x2-x1))*(x-x1)));
    };
}
std::function<double(double)> LinearnaInterpolacija(std::function<double(double)> f, double x_min, double x_max, double delta_x){
    if(x_min>x_max || delta_x<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double, double>> v;
    for (auto i = x_min; i <= x_max; i+=delta_x) {
        v.push_back(std::make_pair(i,f(i)));
    }
    return LinearnaInterpolacija(v);
}

void Opcija1(){
    std::cout<<"Unesite broj cvorova: ";
        int broj_cvorova;
        std::cin>>broj_cvorova;
        std::cout<<"Unesite cvorove kao parove x y: ";
        std::vector<std::pair<double, double>> v;
        for(int i=0;i<broj_cvorova;i++){
            std::pair<double, double> p;
            std::cin>>p.first;
            std::cin>>p.second;
            v.push_back(p);
        }
        for(;;){
            auto f=LinearnaInterpolacija(v);
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            double argument;
            std::cin>>argument;
            if(!std::cin) return;
            std::cout<<"f("<<argument<<") = "<<f(argument)<<std::endl;
        }
}

void Opcija2(){
    std::cout<<"Unesite krajeve intervala i korak: ";
        double korak, interval_poc, interval_kraj;
        std::cin>>interval_poc;
        std::cin>>interval_kraj;
        std::cin>>korak;
        for(;;){
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            double argument;
            std::cin>>argument;
            if(!std::cin) return;
            auto f(LinearnaInterpolacija([](double x){return ((x*x)+sin(x));},interval_poc,interval_kraj,korak));
            std::cout<<"f("<<argument<<") = "<<Funkcija(argument)<<" fapprox("<<argument<<") = "<<f(argument)<<std::endl;
        }
}
int main ()
{
    try{
        std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        int opcija;
        std::cin>>opcija;
        if(opcija==1) Opcija1();
        if(opcija==2) Opcija2();	
    }
    catch(std::domain_error e){
        std::cout<<e.what()<<std::endl;
    }
    catch(std::range_error e){
        std::cout<<e.what()<<std::endl;
    }
    return 0;
}