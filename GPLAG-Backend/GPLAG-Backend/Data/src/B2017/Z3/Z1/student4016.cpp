/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <stdexcept>
#include <cmath>
#include <functional>

std::function<double( double)> LinearnaInterpolacija(std::vector<std::pair<double, double>> v){
    sort(v.begin(), v.end());
    auto it1=v.begin();
    for(int i=0; i<v.size(); i++){
        auto it2=it1;
        for(;;){
            it2++;
            if(it2==v.end()) break;
            if(it2->first==it1->first) throw std::domain_error("Neispravni cvorovi");
        }
        it1++;
    }
    return [v](double x){
        auto it_pocetak=v.begin();
        auto it_kraj=v.end();
        it_kraj--;
        if(x<it_pocetak->first || x>it_kraj->first) throw std::range_error("Argument izvan opsega");
        double b;
        auto zadnji=lower_bound(v.begin(), v.end(), std::make_pair(x,b),[](std::pair<double, double> vl, std::pair<double, double> vr){return vl.first < vr.first;});
        //auto prvi=upper_bound(v.begin(), v.end(), std::make_pair(x,b),[](std::pair<double, double> vl, std::pair<double, double> vr){return vl.first > vr.first;});
        auto prvi=zadnji;
        prvi--;
        return (prvi->second+((zadnji->second - prvi->second)/(zadnji->first-prvi->first))*(x - prvi->first));
    };
}

std::function<double(double)> LinearnaInterpolacija(std::function<double(double)> f, double x_min, double x_max, double x_delta){
    if(x_min>x_max || x_delta<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double, double>> v;
    while(x_min<x_max){
        v.push_back(std::make_pair(x_min, f(x_min)));
        x_min+=x_delta;
    }
    return [v](double x){
        auto it_pocetak=v.begin();
        auto it_kraj=v.end();
        it_kraj--;
        if(x<it_pocetak->first || x>it_kraj->first) throw std::range_error("Argument izvan opsega");
        it_kraj++;
        double b;
        auto zadnji=lower_bound(v.begin(), v.end(), std::make_pair(x,b),[](std::pair<double, double> vl, std::pair<double, double> vr){return vl.first < vr.first;});
        //auto zadnji=upper_bound(v.begin(), v.end(), std::make_pair(x,b),[](std::pair<double, double> const &vl, std::pair<double, double> const &vr){return vl.first > vr.first;});
        //if(zadnji==v.begin()) zadnji--;
        //if(zadnji->first < x) zadnji++;
        //std::cout<<"Prvi: "<<prvi->first<<" "<<prvi->second<<std::endl;
        //std::cout<<"Zadnji: "<<zadnji->first<<" "<<zadnji->second;
        auto prvi=zadnji;
        prvi--;
        return prvi->second+((zadnji->second - prvi->second)/(zadnji->first-prvi->first))*(x-prvi->first);
    };
    
}
int main ()
{
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int n;
    std::cin>>n;
    if(n==1){
        std::cout<<"Unesite broj cvorova: ";
        int cvorovi;
        std::cin>>cvorovi;
        std::cout<<"Unesite cvorove kao parove x y: ";
        std::vector<std::pair<double, double>> v;
        double a, b;
        for(int i=0; i<cvorovi; i++){
            std::cin>>a>>b;
            v.push_back(std::make_pair(a,b));
        }
        try{
        auto f(LinearnaInterpolacija(v));
        for(;;){
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            double arg;
            std::cin>>arg;
                std::cout<<"f("<<arg<<") = "<<f(arg)<<std::endl;
        }
        }
        catch(std::domain_error izuzetak){
            std::cout<<izuzetak.what();
        }
        catch(std::range_error izuzetak){
            std::cout<<izuzetak.what();
        }
    }
    
    else{
        std::cout<<"Unesite krajeve intervala i korak: ";
        double x_min, x_max, x_delta;
        std::cin>>x_min>>x_max>>x_delta;
        
        try{
        auto g(LinearnaInterpolacija([](double x){return x*x+sin(x);}, x_min, x_max, x_delta));
        for(;;){
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            double arg;
            std::cin>>arg;
                std::cout<<"f("<<arg<<") = "<<arg*arg+sin(arg)<<" fapprox("<<arg<<") = "<<g(arg)<<std::endl;
        }
        }
        catch(std::domain_error izuzetak){
            std::cout<<izuzetak.what();
        }
        catch(std::range_error izuzetak){
            std::cout<<izuzetak.what();
        }
    }
    
	return 0;
}
