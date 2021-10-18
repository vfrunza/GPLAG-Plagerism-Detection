/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <functional>
#include <stdexcept>
#include <cmath>
#include <algorithm>
#include <iterator>

typedef std::vector<std::pair<double, double>> vektor_parova;

std::function<double(double)>LinearnaInterpolacija(vektor_parova v){
    if(v.size()>0){
    for(int i=0; i<v.size()-1; i++){
        for(int j=i+1; j<v.size(); j++){
            if(abs(v.at(i).first-v.at(j).first)<0.0001) throw std::domain_error("Neispravni cvorovi");
        }
    }}
    std::vector<double> v1;
    if(v.size()>0){
    for(int i=0; i<v.size(); i++)
    v1.push_back(v.at(i).first);
    sort(v.begin(), v.end());}
    return [v, v1](double x){
        int n(v.size()-1);
        if(v.size()==0||x<v.at(0).first||x>v.at(n).first) throw std::range_error("Argument izvan opsega");
        if(abs(x-v.at(n).first)<0.0001) return v.at(n).second;
        auto it1=std::upper_bound(v1.begin(), v1.end(), x);
        int m2(it1-v1.begin());
        int m1(m2-1);
        double brojnik, nazivnik, yi, xi;
        brojnik=v.at(m2).second-v.at(m1).second;
        nazivnik=v.at(m2).first-v.at(m1).first;
        xi=v.at(m1).first;
        yi=v.at(m1).second;
        return (yi+(brojnik/nazivnik)*(x-xi));
    };
}

std::function<double(double)>LinearnaInterpolacija(std::function<double(double)>F, double xmin, double xmax, double delta_x){
    if(xmin>xmax||delta_x<=0) throw std::domain_error("Nekorektni parametri");
    double pom(xmin);
    vektor_parova v;
    std::vector<double> v1;
    if(abs(xmin-xmax)>0.0001){
    while(pom<xmax){
        v.push_back(std::make_pair(pom, F(pom)));
        v1.push_back(pom);
        pom+=delta_x;
    }}
    else{
        v.push_back(std::make_pair(pom, F(pom)));
        v1.push_back(pom);
    }
    return [v, v1](double x){
        int n(v.size()-1);
        if(x<v.at(0).first||x>v.at(n).first) throw std::range_error("Argument izvan opsega");
        if(n>0){
        double brojnik, nazivnik, yi, xi;
        auto it1=std::upper_bound(v1.begin(), v1.end(), x);
        int m2(it1-v1.begin());
        int m1(m2-1);
        brojnik=v.at(m2).second-v.at(m1).second;
        nazivnik=v.at(m2).first-v.at(m1).first;
        xi=v.at(m1).first;
        yi=v.at(m1).second;
        return (yi+(brojnik/nazivnik)*(x-xi)); }
        return v.at(0).second; 
    };
}

int main ()
{
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int a;
    std::cin>>a;
    if(a==1){
        vektor_parova v;
        std::cout<<"Unesite broj cvorova: ";
        int n;
        std::cin>>n;
        std::cout<<"Unesite cvorove kao parove x y: ";
        while(n!=0){
            double x, y;
            std::cin>>x>>y;
            v.push_back(std::make_pair(x,y));
            n--;
        }
    try{
       auto f(LinearnaInterpolacija(v));
        while(1){
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            double q;
            std::cin>>q;
            if(!std::cin)
            return 0;
            try{
                std::cout<<"f("<<q<<") = "<<f(q)<<std::endl;
            }
            catch(std::range_error iz){
                std::cout<<iz.what()<<std::endl;
               // return 0;
            }
        }
    }
        catch(std::domain_error iz){
        std::cout<<iz.what()<<std::endl;
    }
    }
    if(a==2){
        std::cout<<"Unesite krajeve intervala i korak: ";
        double xmin, xmax, delta_x;
        std::cin>>xmin>>xmax>>delta_x;
        try{
        auto f(LinearnaInterpolacija([](double x){return x*x+sin(x);}, xmin, xmax, delta_x));
        while(1){
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            double q;
            std::cin>>q;
            if(!std::cin)
            return 0;
            try{
                double funk(q*q+sin(q));
                std::cout<<"f("<<q<<") = "<<funk<<" fapprox("<<q<<") = "<<f(q)<<std::endl;
            }
            catch(std::range_error iz){
                std::cout<<iz.what()<<std::endl;
            }
        }
    }
    catch(std::domain_error iz){
        std::cout<<iz.what()<<std::endl;
    }}
	return 0;
}
