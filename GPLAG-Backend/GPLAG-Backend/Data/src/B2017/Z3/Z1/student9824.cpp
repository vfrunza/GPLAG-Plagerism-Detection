#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iterator>
#include <new>
#include <utility>
#include <stdexcept>
#include <memory>
#include <functional>
#include <cmath>
std::function <double(double)> LinearnaInterpolacija(std::vector<std::pair<double,double>> vektor){
    std::sort(vektor.begin(),vektor.end());
    for(int i=0;i<vektor.size();i++){
        double m=(double)vektor[i].first;
        for(int j=i+1;j<vektor.size();j++){
            if(m==(double)vektor[j].first) throw std::domain_error("Neispravni cvorovi");
        }
    }
    return[vektor] (double x){
        if(x<vektor[0].first || x>vektor[vektor.size()-1].first) throw std::range_error("Argument izvan opsega");
        double suma=0;
        int min,max;
        for(int j=0;j<vektor.size();j++){
            if(x<=double(vektor[j].first)){
                min=j-1;
                max=j;
                break;
            }
        }
    if((int)x==(int)vektor[vektor.size()-1].first){
        suma=vektor[vektor.size()-1].second;
        return suma;}
     suma+=vektor[min].second+((vektor[max].second-vektor[min].second)/(vektor[max].first-vektor[min].first))*(x-vektor[min].first);
        return suma;    
    };
    }
std::function <double(double)> LinearnaInterpolacija(double fun(double),double xmin,double xmax,double deltax){
    if(xmin>xmax || deltax<0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> v;
    int i=0;
    while(xmin+i*deltax<=xmax){
    v.push_back(std::make_pair(xmin+i*deltax,fun(xmin+i*deltax)));
    i++;
    }
    return[v] (double x){
        if(x<v[0].first || x>v[v.size()-1].first) throw std::range_error("Argument izvan opsega");
        double suma=0;
        int min,max;
        for(int j=0;j<v.size();j++){
            if(x<v[j].first){
                min=j-1;
                max=j;
                break;
            }
        }
     suma+=v[min].second+((v[max].second-v[min].second)/(v[max].first-v[min].first))*(x-v[min].first);
        return suma;    
    };
    
}


int main(){
    
        
    int a;
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin>>a;
     std::vector<std::pair<double,double>> vektor;
    if(a==1){
        std::cout << "Unesite broj cvorova: ";
        int b;
        std::cin>>b;
        double c,d;
        std::cout << "Unesite cvorove kao parove x y: ";
        for(int i=0;i<b;i++) {
            std::cin>>c>>d;
            vektor.push_back(std::make_pair(c,d));
            std::cin.ignore(1000,'\n');}
            try{
        auto s=LinearnaInterpolacija(vektor);
            }
            catch(std::exception &e){
                std::cout << e.what();
                return 1;
            }
        double m;
        std::cout <<"Unesite argument (ili \"kraj\" za kraj): ";
        while(std::cin>>m){
            try{
            auto f=LinearnaInterpolacija(vektor);
            std::cout <<"f(" << m <<") = " << f(m);}
             catch(std::exception &e){
            std::cout << e.what();
             }
            std::cin.ignore(1000,'\n');
            std::cout <<"\nUnesite argument (ili \"kraj\" za kraj): ";
        }
    
    
    }
    if(a==2){
        std::cout <<"Unesite krajeve intervala i korak: ";
        double xmin,xmax,delta;
        std::cin >>xmin>>xmax>>delta;
        try{
        auto s=LinearnaInterpolacija([](double x){ return x*x+sin((x*4*atan(1.))/180);},xmin,xmax,delta);
            }
            catch(std::exception &e){
                std::cout << e.what();
                return 1;
            }
        double m;
        while(std::cin){
            std::cout <<"Unesite argument (ili \"kraj\" za kraj): ";
            std::cin>>m;
            if(!std::cin) return 1;
            try{
            auto f=LinearnaInterpolacija([](double x){ return x*x+sin(x);},xmin,xmax,delta);
            f(m);
            std::cout <<"f(" << m <<") = " << m*m+sin(m);
            std::cout << " fapprox(" << m <<") = " << f(m);
                }
            catch(std::exception &e){
                std::cout << e.what();
            }
            std::cin.ignore(1000,'\n');
            std::cout << "\n";
        }}
    return 0;
}