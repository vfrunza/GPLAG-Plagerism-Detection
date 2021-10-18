/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <functional>
#include <stdexcept>
#include <vector>
#include <cmath>
std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double,double>> vektor,int d){
    const double Eps(1e-10);
    int n(vektor.size());
    if(d<0 || d>n) throw std::domain_error("Nedozvoljen red");
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(std::fabs(vektor[i].first-vektor[j].first)<=Eps*(std::fabs(vektor[i].first)+std::fabs(vektor[j].first))) throw std::domain_error("Neispravni cvorovi");
        }
    }
    std::vector<double> w(n);
    for(int i=1;i<=n;i++){
        int max,min;
        if(i-d>1)max=i-d;
        else max=1;
        if(i<n-d)min=i;
        else min=n-d;
        for(int k=max;k<=min;k++){
            double temp;
            if((k-1)%2==0) temp=1;
            else temp=-1;
            for(int j=k;j<=k+d;j++){
                if(i!=j)temp*=1/(vektor[i-1].first-vektor[j-1].first);
            }
            w[i-1]+=temp;
        }
    }
    return [vektor,Eps,w](double x){
        double brojnik(0),nazivnik(0);
        int n(vektor.size());
        for(int i=0;i<n;i++){
            if(std::fabs(x-vektor[i].first)<= Eps*(x+vektor[i].first)){
            return vektor[i].second;
            }
            brojnik+=w[i]/(x-vektor[i].first)*vektor[i].second;
            nazivnik+=w[i]/(x-vektor[i].first);
        }
        return brojnik/nazivnik;
    };
}
std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> funkcija,double xmin,double xmax,double delta,int d){
    if(xmin>xmax || delta<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> cvojovi;
    double temp(xmin);
    while(temp<=xmax){
        cvojovi.push_back({temp,funkcija(temp)});
        temp+=delta;
    }
    return BaricentricnaInterpolacija(cvojovi,d);
}
int main (){
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int opcija;
    std::cin>>opcija;
    if(opcija==1){
        std::cout<<"Unesite broj cvorova: ";
        int brcvr;
        std::cin>>brcvr;
        std::vector<std::pair<double,double>> cvojovi;
        std::cout<<"Unesite cvorove kao parove x y: ";
        double x,y;
        for(int i=0;i<brcvr;i++){
            std::cin>>x>>y;
            cvojovi.push_back({x,y});
        }
        std::cout<<"Unesite red interpolacije: ";
        int red;
        std::cin>>red;
        std::function<double(double)> f;
        try{
            f=BaricentricnaInterpolacija(cvojovi,red);
        }catch (std::domain_error a){std::cout<<a.what(); return 0;}
        while(true){
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            double arg;
            std::cin>>arg;
            if(!std::cin) return 0;
            std::cout<<"f("<<arg<<") = "<<f(arg)<<std::endl;
        }
    }
    else if(opcija==2){
        std::cout<<"Unesite krajeve intervala i korak: ";
        double xmin,xmax,delta;
        std::cin>>xmin>>xmax>>delta;
        std::cout<<"Unesite red interpolacije: ";
        int red;
        std::cin>>red;
        auto funkcija([](double x){return x*x+std::sin(x);});
        std::function<double(double)> f;
        try{
            f=BaricentricnaInterpolacija([](double x){return x*x+std::sin(x);},xmin,xmax,delta,red);
        }catch (std::domain_error a){std::cout<<a.what();return 0;}
        while(true){
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            double arg;
            std::cin>>arg;
            if(!std::cin) return 0;
            std::cout<<"f("<<arg<<") = "<<funkcija(arg)<<" fapprox("<<arg<<") = "<<f(arg)<<std::endl;
        }
    }
	return 0;
}