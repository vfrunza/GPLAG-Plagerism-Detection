/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <functional>
#include <algorithm>
double xsinx(double x) {
    return x*x+std::sin(x);
}
std::function<double(double)>LinearnaInterpolacija(std::vector<std::pair<double, double>>Par) {
    for(int i=0; i<Par.size(); i++) {
        for(int j=0; j<Par.size(); j++) {
            if(fabs(Par[i].first-Par[j].first)<0) throw std::domain_error("Neispravni cvorovi");
        }
    }
    sort(Par.begin(), Par.end(), [](std::vector<std::pair<double,double>prvi, std::pair<double,double>drugi){
        return prvi.first<drugi.first; });
    auto f=[Par](double x)->double {
         double rez;
        if(binary_search(Par.begin(), Par.end(),x,[x](std::vector<std::pair<double,double>>Par) {
            for(int i=0; i<Par.size(); i++)
            if(x>Par[i].first && x<Par[i+1].first) return true;
            return false;})) {
            for(int i=0; i<Par.size(); i++) {
                if(x>Par[i].first && x<Par[i+1].first) {
                    double clan;
                    clan=(Par[i+1].second-Par[i].second)/(Par[i+1].first-Par[i].first);
                    double clan2;
                    clan2=clan*(x-Par[i].first);
                    rez=Par[i].second+clan2;
                }
            }
        }
        return rez;
    };
    return f;
}
std::function<double(double)>LinearnaInterpolacija(std::function<double(double)>f, double xmin, double xmax, double deltax){
    if(xmin>xmax || deltax<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>>parovi;
    for(auto x=xmin; x<xmax; x+=deltax) {
        std::pair<double, double>par;
        par.first=x; par.second=f(x);
        parovi.push_back(par);
    }
    auto f1=LinearnaInterpolacija(parovi);
    return f1;
} 

int main ()
{
    try{
        int n;
        std::vector<std::pair<double, double>>vektorcvorova;
        std::cout<<"Odaberite opciju (1-unos cvora, 2-aproksimacija): ";
        std::cin>>n;
        switch(n) {
            case 1: {
            std::cout<<"Unesite broj cvora: ";
            int a;
            std::cin>>a;
            std::cout<<"Unesite cvorove kao parove x y: ";
            std::pair<double, double>cvor;
            for(int i=0; i<a; i++) {
                std::cin>>cvor.first;
                std::cin>>cvor.second;
                vektorcvorova.push_back(cvor);
            }
            for(;;) {
                double arg;
                std::cout<<"Unesite argument (ili \"kraj\"za kraj): ";
                std::cin>>arg;
                if(!std::cin) break;
                auto f(LinearnaInterpolacija(vektorcvorova));
                std::cout<<"f("<<arg<<")="<<f(arg)<<std::endl;
            }
            return 0;
        }
        case 2: {
            double i1,i2,k;
            std::cout<<"Unesite krajeve intervala i korak: ";
            std::cin>>i1>>i2>>k;
            for(;;) {
                double arg;
                std::cout<<"Unesite argument (ili\"kraj\"za kraj): ";
                std::cin>>arg;
                if(!std::cin) break;
                auto fun=[](double x) {return x*x+std::sin(x);};
                auto f(LinearnaInterpolacija(xsinx, i1, i2, k));
                std::cout<<"f("<<arg<<")="<<fun(arg)<<"fapprox("<<arg<<")="<<f(arg)<<std::endl;
        }
        return 0;
    }
    }
    }
    catch(std::domain_error e) {
        std::cout<<e.what();
    }
	return 0;
}
