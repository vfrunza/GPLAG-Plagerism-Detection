/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iterator>
#include <cmath>
#define EPSILON 0.0001
bool funkcijica(std::pair<double,double> a,std::pair<double,double> b) {
    return a.first<b.first;
}
std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double,double>> tackice){
    std::sort(tackice.begin(),tackice.end(),[] (std::pair<double,double> a, std::pair<double,double> b){
        if(fabs(a.first-b.first)<EPSILON || fabs(a.second-b.second)<EPSILON) throw std::domain_error("Neispravni cvorovi");
        return a.first<b.first;
    });
    return [tackice](double x){
    std::pair<double,double> paric=std::make_pair(x,0);
    auto it=std::lower_bound(tackice.begin(),tackice.end(),paric,funkcijica);
    auto it1=std::upper_bound(tackice.begin(),tackice.end(),paric,funkcijica);
    it1--;
    if(x<it1->first || x>tackice[tackice.size()-1].first) throw std::range_error("Argument izvan opsega");
    if(fabs(it1->first-it->first)<EPSILON) it1++;
    if(fabs(it->first-tackice[tackice.size()-1].first)<EPSILON && fabs(it->first-x)<EPSILON) return tackice[tackice.size()-1].second;
    return it1->second+((it->second-it1->second)/(it->first-it1->first))*(x-it1->first);
    };
}
double sinus(double x){
    return (x*x+sin(x));
}
std::function<double(double)> LinearnaInterpolacija(double f(double),double x_min,double x_max,double delta_x){
    if(x_min>x_max || delta_x<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> v;
        double a=x_min;
        int br(0);
        while(!(fabs(a-x_max)<EPSILON)){
            double b=f(a);
            std::pair<double,double> par=std::make_pair(a,b);
            v.push_back(par);
            br++;
            a=x_min+br*delta_x;
        }
        return LinearnaInterpolacija(v);
}
int main ()
{
   
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int n(0);
    std::cin>>n;
    if(n==1){
        std::vector<std::pair<double,double>> v;
        std::cout<<"Unesite broj cvorova: ";
        int m(0);
        std::cin>>m;
        std::cout<<"Unesite cvorove kao parove x y: ";
        for(int i=0;i<m;i++){
            std::pair<double,double> par;
            int a(0),b(0);
            std::cin>>a>>b;
            par=std::make_pair(a,b);
            v.push_back(par);
        }
        try{
            for(;;){
                try{
            auto f(LinearnaInterpolacija(v));
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            double c(0);
            if(!(std::cin>>c)) break;
            else std::cout<<"f("<<c<<") "<<"= "<<f(c)<<std::endl;
            }
            catch(std::range_error izuzetak){
                std::cout<<izuzetak.what();
            }
        }
        }
        catch(std::domain_error izuzetak){
            std::cout<<izuzetak.what();
        }
    }
    else if(n==2){
        std::cout<<"Unesite krajeve intervala i korak: ";
        double k(0),d(0),e(0);
        std::cin>>k>>d>>e;
        try{
        for(;;){
            try{
        std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
        double arg(0);
        if(!(std::cin>>arg)) break;
        auto funk=LinearnaInterpolacija(sinus,k,d,e);
         std::cout<<"f("<<arg<<")"<<" = "<<sinus(arg)<<" fapprox("<<arg<<") = "<<funk(arg)<<std::endl;
    }
        catch(std::range_error izuzetak){
            std::cout<<izuzetak.what()<<std::endl;
        }
        }
        }
        catch(std::domain_error izuzetak){
            std::cout<<izuzetak.what();
        }
    }
	return 0;
}
