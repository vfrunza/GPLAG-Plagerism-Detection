/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <stdexcept>
#include <cmath>
#include <functional>

std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double,double>> v){
            std::sort(v.begin(),v.end(),[](std::pair<double,double> p1,std::pair<double,double> p2){ return p1.first<p2.first; });
            for(int i=0;i<v.size()-1;i++){
                if(v.at(i).first==v.at(i+1).first)
                    throw std::domain_error("Neispravni cvorovi");
            }
            
    return [v](double x){ 
        if(x<v.at(0).first||x>v.at(v.size()-1).first)
            throw std::range_error("Argument izvan opsega");
            
            auto xi1=lower_bound(v.begin(),v.end(),x,[](std::pair<double,double> par, double vr){ return par.first<vr;});
            if(std::fabs(x-(*xi1).first)<0.000001){
                return (*xi1).second;
            }
            auto xi=xi1;
            xi--;
            return (*xi).second+((*xi1).second-(*xi).second)/((*xi1).first-(*xi).first)*(x-(*xi).first);
            
        };
}
std::function<double(double)> LinearnaInterpolacija(std::function<double(double)> f,double xmin,double xmax,double xdelta){
    if(xmin>xmax||xdelta<=0){
        throw std::domain_error("Nekorektni parametri");
    }
    std::vector<std::pair<double,double>> v;
    while(!std::fabs(xmax-xmin)<0.00001){
        v.push_back(std::make_pair(xmin,f(xmin)));
        xmin+=xdelta;
    }
    
    return [v](double x){ 
        if(x<v.at(0).first||x>v.at(v.size()-1).first)
            throw std::range_error("Argument izvan opsega");
            auto xi1=lower_bound(v.begin(),v.end(),x,[](std::pair<double,double> par, double vr){ return par.first<vr;});
            if(std::fabs(x-(*xi1).first)<0.000001){
                return (*xi1).second;
            }
            auto xi=xi1;
            xi--;
            return (*xi).second+((*xi1).second-(*xi).second)/((*xi1).first-(*xi).first)*(x-(*xi).first);
        };
}
double g(double x){
    return x*x+std::sin(x);
}
int main ()
{
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int unos;
    double unos2;
    std::cin>>unos;
    if(unos==1){
        try{
        std::cout<<"Unesite broj cvorova: ";
        int  n;
        std::cin>>n;
        std::cout<<"Unesite cvorove kao parove x y: ";
        std::vector<std::pair<double,double>> v;
        double x,y;
        for(int i=0;i<n;i++){
            std::cin>>x>>y;
            v.push_back(std::make_pair(x,y));
        }
        while(1){
        try{
        auto f(LinearnaInterpolacija(v));
        std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
        std::cin>>unos2;
        if(!std::cin) break;
        std::cout<<"f("<<unos2<<") = "<<f(unos2)<<std::endl;
        }
        catch(std::range_error e)
        {
            std::cout<<e.what()<<std::endl;
        }
        }
        }
        catch(std::domain_error e)
        {
            std::cout<<e.what();
        }
    }
    else if(unos==2){
        try{
        std::cout<<"Unesite krajeve intervala i korak: ";
        double p,z,k;
        std::cin>>p>>z>>k;
        auto f(LinearnaInterpolacija(g,p,z,k));
        while(1){
            try{
        double unos3;
        std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
        std::cin>>unos3;
        if(!std::cin) break;
        std::cout<<"f("<<unos3<<") = "<<g(unos3)<<" fapprox("<<unos3<<") = "<<f(unos3)<<std::endl;
            }
        catch(std::range_error e)
        {
            std::cout<<e.what()<<std::endl;
        }
        }
        }
        catch(std::domain_error e)
        {
            std::cout<<e.what()<<std::endl;
        }
        }
   
	return 0;
}
