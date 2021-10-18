#include <vector>
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <utility> 
#include <functional>

double proizvod(const std::vector<std::pair<double, double>> &cvor, double x, int k, int d, int i) {
    double p=1;
    for(int j=k; j<=k+d; j++)
    if(j!=i)
    p=p*(1/(x-cvor[j-1].first));
    return p;
}

std::function<double(double)> BaricentricnaInterpolacija(const std::vector<std::pair<double, double>> &cvor, int d) {
    int n=cvor.size();
    if(d<0 || d>=n) throw std::domain_error("Nedozvoljen red"); ///////////////////////
    for(int i=0; i<cvor.size()-1; i++)
    for(int j=i+1; j<cvor.size(); j++)
    if(cvor[i].first==cvor[j].first) throw std::domain_error("Neispravni cvorovi");
    
    std::vector<double> w(n+1); //tezinski koeficijenti

    for(int i=1; i<=n; i++){
        int min=1;
        if((i-d)>1) min=i-d; 
        int max=i;
        if((n-d)<i) max=n-d; 
        w[i]=0;
        for(int k=min; k<=max; k++) {
            w[i]=w[i]+std::pow(-1,(k-1))*proizvod(cvor, cvor[i-1].first, k, d, i);
        }
    }
    return [w, cvor, n](double x){
        double prvi=0;
        for(int i=1; i<=n; i++) {
            if(x!=cvor[i-1].first)
            prvi=prvi+(w[i]*cvor[i-1].second)/(x-cvor[i-1].first);
            else return cvor[i-1].second;
        }
        double drugi=0;
        for(int i=1; i<=n; i++) {
            if(x!=cvor[i-1].first)
            drugi=drugi+(w[i])/(x-cvor[i-1].first);
            else return cvor[i-1].second;
        }
        return prvi/drugi;
    };
}

std::function<double(double)> BaricentricnaInterpolacija(double f(double), double xmin, double xmax, double delta, int d) {
    if(xmin>xmax || delta<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double, double>> cvor;
    std::pair<double, double>par;
    
    double i=xmin;
    while(i<=xmax) {
        par.first=i;
        i=i+delta;
        par.second=f(par.first);
        cvor.push_back(par);
    }
    
    auto m=BaricentricnaInterpolacija(cvor, d);
    return m;
}

int main ()
{
    int opcija;
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin>>opcija;
    try {
    if(opcija==1) {
        int br;
        std::cout<<"Unesite broj cvorova: ";
        std::cin>>br;
        std::cout<<"Unesite cvorove kao parove x y: ";
        std::vector<std::pair<double, double>> cvor(br);
        for(int i=0; i<br; i++)
        std::cin>>cvor[i].first>>cvor[i].second;
        int d;
        std::cout<<"Unesite red interpolacije: ";
        std::cin>>d;
        double arg;
        std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
        std::cin>>arg;
        if(arg) {
        double x=BaricentricnaInterpolacija(cvor, d)(arg);
        std::cout<<"f("<<arg<<") = "<<x<<std::endl;}
        while(arg) {
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            std::cin>>arg;  
            if(arg) {
            double x=BaricentricnaInterpolacija(cvor, d)(arg);
            std::cout<<"f("<<arg<<") = "<<x<<std::endl;}
        }
        
    }
    if(opcija==2) {
        std::cout<<"Unesite krajeve intervala i korak: ";
        double xmin, xmax;
        double delta;
        std::cin>>xmin>>xmax>>delta;
        std::cout<<"Unesite red interpolacije: ";
        int d;
        std::cin>>d;
        std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
        double arg;
        std::cin>>arg;
        if(arg) {
        std::cout<<"f("<<arg<<") = "<<arg*arg+std::sin(arg)<<" ";
        double rj=BaricentricnaInterpolacija ([](double x) {return x*x+sin(x);} ,xmin, xmax, delta,  d)(arg);
        std::cout<<"fapprox("<<arg<<") = "<<rj<<std::endl;
        }
        while(arg) {
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            std::cin>>arg;  
            if(arg) {
            std::cout<<"f("<<arg<<") = "<<arg*arg+std::sin(arg)<<" ";
            double rj=BaricentricnaInterpolacija([](double x){return x*x+sin(x);},xmin, xmax, delta, d)(arg);
            std::cout<<"fapprox("<<arg<<") = "<<rj<<std::endl;
                
            }
        }
    }
    }
    catch(std::domain_error i) {std::cout<<i.what();}
	return 0;
}