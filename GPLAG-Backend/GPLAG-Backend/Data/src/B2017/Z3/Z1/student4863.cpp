#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <algorithm>
#include <stdexcept>
#include <cmath>

std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double, double>> v){
    try{
        for(int i=0; i<v.size(); i++){
        for(int j=i+1; j<v.size(); j++){
            if(i==v.size()-1) break;
            if(v[i].first==v[j].first) throw std::domain_error("Neispravni cvorovi");
        }
    }
    std::sort(v.begin(), v.end(), [](std::pair<double, double> a, std::pair<double, double> b){return a.first<b.first;});
    return([v](double x){
        try{
            if(v.empty()) throw std::range_error("Argument izvan opsega");
            if(x<v[0].first || x>v[v.size()-1].first) throw std::range_error("Argument izvan opsega");
            if(x==v[v.size()-1].first) return v[v.size()-1].second;
            auto it(std::lower_bound(v.begin(), v.end(), std::make_pair(x,0.)));
            std::pair<double, double> prva(*(it-1));
            std::pair<double, double> druga(*(it));
            return(prva.second+((druga.second-prva.second)/(druga.first-prva.first))*(x-prva.first));

        }catch(std::range_error e){
            std::cout<<e.what()<<std::endl;
            throw;
        }
    });
    }catch(std::domain_error e){
        std::cout<<e.what();
        throw;
    }
}

std::function<double(double)> LinearnaInterpolacija(std::function<double(double)> f,  double min, double max, double delta){
    std::vector<std::pair<double, double>> v;
    try{
        if(min>max || delta<=0) throw std::domain_error("Nekorektni parametri");
    int k((max-min)/delta);
    v.push_back(std::make_pair(min, f(min)));
    for(int i=1; i<k; i++){
        v.push_back(std::make_pair(min+i*delta, f(min+i*delta)));
    }
    }catch(std::domain_error e){
        std::cout<<e.what();
        throw;
    }
    return(LinearnaInterpolacija(v));
}

int main ()
{
    try{
        std::vector<std::pair<double, double>> v;
   std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
   int k(0);
   std::cin>>k;
   if(k==1){
       std::cout<<"Unesite broj cvorova: ";
       int a;
       std::cin>>a;
       std::cout<<"Unesite cvorove kao parove x y: ";
       for(int i=0; i<a; i++){
           int b,c;
           std::cin>>b>>c;
           v.push_back(std::make_pair(b, c));
       }
       auto f(LinearnaInterpolacija(v));
       for(;;){
           try{
       std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
       double d;
       std::cin>>d;
       if(!std::cin) return 0;
       std::cout<<"f("<<d<<")"<<" = "<<f(d)<<std::endl;
           }catch(std::range_error e){
               //std::cout<<e.what()<<std::endl;
               continue;
           }
       }
   }
   if(k==2){
       std::cout<<"Unesite krajeve intervala i korak: ";
       double e,p,h;
       std::cin>>e>>p>>h;
       //auto t(LinearnaInterpolacija(v));
       auto g(LinearnaInterpolacija([](double x){return x*x+std::sin(x);}, e, p, h));
        for(;;){
            try{
       std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
       double d;
       std::cin>>d;
       if(!std::cin) return 0;
       std::cout<<"f("<<d<<")"<<" = "<<d*d+std::sin(d)<<" "<<"fapprox("<<d<<") = "<<g(d)<<std::endl;
            }catch(std::range_error e){
                continue;
            }
       }
   }
    }catch(std::domain_error e){
        //std::cout<<e.what();
        return 0;
    }
	return 0;
}