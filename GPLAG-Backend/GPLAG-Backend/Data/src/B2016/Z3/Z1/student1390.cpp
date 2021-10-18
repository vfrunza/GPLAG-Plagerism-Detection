/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <utility>
#include <stdexcept>
#include <functional>
#include <cmath>
#include <algorithm>

double fun(double x){
    return x*x+std::sin(x);
}

std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double,double>> v, int d){
    int n=v.size();
    if(d<0 || d>n)throw std::domain_error("Nedozvoljen red");
    for(int i=0;i<v.size()-1;i++){
        for(int j=i+1;j<v.size();j++)
        if(v[i].first==v[j].first)throw std::domain_error("Neispravni cvorovi");
    }
    std::vector<double> w;
    for(int i=1;i<=n;i++){
        double suma(0),proizvod(1);
        for(int k=std::max(1,i-d);k<=std::min(i,n-d);k++){
            proizvod=1;
            for(int j=k;j<=k+d;j++){
                if(i!=j){
                double broj=1/(v[i-1].first-v[j-1].first);
                proizvod*=broj;
                }
            }
            double broj2=pow(-1,k-1)*proizvod;
            suma+=broj2;
        }
        w.push_back(suma);
    }
    return [w,n,v](double x){
        double suma(0);
        for(int i=1;i<=n;i++){
            if(v[i-1].first!=x){
            double broj=(w[i-1]/(x-v[i-1].first))*v[i-1].second;
            suma+=broj;
              }
            else return v[i-1].second;
        }
        double suma2(0);
        for(int i=1;i<=n;i++){
            if(v[i-1].first!=x){
            double broj=w[i-1]/(x-v[i-1].first);
            suma2+=broj;
            }
            else return v[i-1].second;
        }
        return suma/suma2;
    };
}

std::function<double(double)> BaricentricnaInterpolacija(double fun(double), double x_min, double x_max, double delta_x, int d){
    if(x_min>x_max || delta_x<=0)throw std::domain_error("Nekorektni parametri");
    double x,y;
    std::vector<std::pair<double,double>> v;
    for(double i=x_min;i<=x_max;i+=delta_x){
        x=i;
        y=fun(i);
        v.push_back(std::make_pair(x,y));
    }
    auto f(BaricentricnaInterpolacija(v,d));
    return f;
}

int main ()
{
    std::vector<std::pair<double,double>> v;
    int n;
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    try{
    std::cin >> n;
    if(n==1){
        std::cout << "Unesite broj cvorova: " ;
        int broj_cvorova;
        std::cin >> broj_cvorova;
        std::cout << "Unesite cvorove kao parove x y: ";
        double x,y;
        std::pair<double,double> par_brojeva;
        int i(0);
        do{
            std::cin >> x >> y;
            par_brojeva=std::make_pair(x,y);
            v.push_back(par_brojeva);
            i++;
        }while(i<broj_cvorova);
        std::cout << "Unesite red interpolacije: " ;
        int d;
        std::cin >> d;
        if(d>broj_cvorova || d<0)throw std::domain_error("Nedozvoljen red");
        double argument;
        std::cout << "Unesite argument (ili \"kraj\" za kraj): " ;
        do{
            std::cin >> argument;
            if(!argument)return 0;
            auto f(BaricentricnaInterpolacija(v,d));
            std::cout << "f("<<argument<<") = " <<f(argument)<< std::endl;
            std::cout << "Unesite argument (ili \"kraj\" za kraj): " ;
            std::cin.ignore(10000,'\n');
        }while(argument);
    }
    if(n==2){
        double min,max,delta;
        std::cout << "Unesite krajeve intervala i korak: " ;
        std::cin>>min >> max >> delta;
        std::cout << "Unesite red interpolacije: " ;
        int d;
        std::cin >> d;
        std::cout << "Unesite argument (ili \"kraj\" za kraj): " ;
        double argument;
        do{
            std::cin>>argument;
            if(!argument)return 0;
            double broj(fun(argument));
            auto f(BaricentricnaInterpolacija([](double x){return x*x+std::sin(x);},min,max,delta,d));
            std::cout << "f("<<argument<<") = "<<broj<<" fapprox("<<argument<<") = "<<f(argument) << std::endl;
            std::cout << "Unesite argument (ili \"kraj\" za kraj): " ;
            std::cin.ignore(10000,'\n');
        }while(argument);
    }
    }catch(std::domain_error e){
        std::cout << e.what() << std::endl;
    }
	return 0;
}