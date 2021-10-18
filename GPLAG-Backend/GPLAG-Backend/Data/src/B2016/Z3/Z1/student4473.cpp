/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <stdexcept>
#include <functional>
#include <cmath>
#include <utility>

std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double,double>> v, int d){
    if (d<0 or d>v.size()) throw std::domain_error("Nedozvoljen red");
    //identicne koordinate
    for(int i=0;i<v.size();i++)
        for(int k=i+1;k<v.size();k++)
            if(v[i].first==v[k].first)
                throw std::domain_error("Neispravni cvorovi");
    std::vector<double> glavni;
    for(int i=1;i<=v.size();i++){
        double suma(0);
        for(int k=std::max(1,i-d);k<=std::min(i,(int)v.size()-d);k++){
            double pomoc(1);
            for(int j=k;j<=k+d;j++){
                if(j==i) continue;
                pomoc*=1/(v[i-1].first-v[j-1].first);
            }
            pomoc*=pow(-1,k-1);
            suma+=pomoc;
        }
        glavni.push_back(suma);
    }
    return [glavni,v] (double x) {
        double suma(0),suma1(0);
        for(int i=1;i<=v.size();i++){
            if(x==v[i-1].first) return v[i-1].second;
            suma+=(glavni[i-1]*v[i-1].second)/(x-v[i-1].first);
            suma1+=(glavni[i-1]/(x-v[i-1].first));
        }
         return suma/suma1;
    };
}


std::function<double (double)> BaricentricnaInterpolacija(double f (double), double min,double max,double delta,int d){
    if(min>max or delta<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> glavni;
    for(double i=min;i<=max;i+=delta){
        glavni.push_back(std::make_pair(i,f(i)));
    }
    return BaricentricnaInterpolacija(glavni,d);
}
int main ()
{   std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int n;
    std::cin>>n;
    if(n==1){
        std::cout<<"Unesite broj cvorova: ";
        int k;
        std::cin>>k;
        std::vector<std::pair<double,double>> glavni;
        std::cout<<"Unesite cvorove kao parove x y: ";
        for(int i=0;i<k;i++){
            std::pair<double,double> cvor;
            std::cin>>cvor.first>>cvor.second;
            glavni.push_back(cvor);
        }
    int d;
    std::cout<<"Unesite red interpolacije: ";
    std::cin>>d;
    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
    double x;
    std::cin>>x;
    try{
        auto f(BaricentricnaInterpolacija(glavni,d));
        while(std::cin){
            std::cout<<"f("<<x<<") = "<<f(x)<<std::endl;
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            std::cin>>x;
        }
        }
    catch(std::domain_error err){
        std::cout<<err.what();
        return 0;
        }
    }
    if(n==2){
        std::cout<<"Unesite krajeve intervala i korak: ";
        double min,max,delta;
        std::cin>>min>>max>>delta;
        int d;
        std::cout<<"Unesite red interpolacije: ";
        std::cin>>d;
        std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
        double x;
        std::cin>>x;
        try{
            auto fun(BaricentricnaInterpolacija([] (double x) { return x*x+sin(x);},min,max,delta,d));
            while(std::cin){
                std::cout<<"f("<<x<<") = "<<x*x+sin(x)<<" fapprox("<<x<<") = "<<fun(x)<<std::endl;
                  std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                  std::cin>>x;
            }
            
        }
        catch(std::domain_error err){
            std::cout<<err.what();
            return 0;
        }
    }
	return 0;
}