/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)

#include <iostream>
#include <vector>
#include <utility>
#include <stdexcept>
#include <algorithm>
#include <cmath>
#include <functional>


double xsinx (double x){
    return x*x+std::sin(x);
}

std::function<double(double)> BaricentricnaInterpolacija (std::vector<std::pair<double,double> > Par, int d){

    if(d<0 || d>Par.size()) throw std::domain_error("Nedozvoljen red");
    
    for(int i(0); i<Par.size();i++){
    for(int j(0);j<Par.size();j++){
    if(fabs(Par[i].first-Par[j].first)<0) throw std::domain_error("Neispravni cvorovi");
    }}
    
    std::vector<double> w;
    for(int i(1); i<=(int)Par.size(); i++){
        double s(0);
        double a(std::max(1,i-d));
        double b(std::min(i,(int)Par.size()-d));
            for(int k(a); k<=b; k++){
                double p(1);
                for(int j(k); j<=k+d; j++){
                    if (i == j) continue;
                p*=1.0/(Par[i-1].first-Par[j-1].first);
            }
            if((k-1)%2 == 0)
                s+=p;
            else 
                s-=p;
        }
        w.push_back(s);
    }
    
    auto f = [w,Par] (double x)->double {
        double suma1(0),suma2(0);
    
        for(int i=0; i<Par.size(); i++){
            if(fabs(x-Par[i].first)<1e-4) return Par[i].second;
          suma1+=w[i]*Par[i].second/(x-Par[i].first);
        }
        for(int i=0; i<Par.size(); i++){
            if(fabs(x-Par[i].first)<1e-4) return Par[i].second;
            suma2+=w[i]/(x-Par[i].first);
        }
        return suma1/suma2;
    };
    return f;

}

std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> f, double xmin, double xmax, double deltax, int d){

    if(xmax<xmin || deltax<=0) throw std::domain_error("Nekorektni parametri");
    
    std::vector<std::pair<double,double>> parovi;
    for(auto x=xmin; x<xmax; x+=deltax){
        std::pair<double,double> par;
        par.first = x; par.second = f(x);
        parovi.push_back(par);

    }
    auto f1 = BaricentricnaInterpolacija(parovi, d);
    
    return f1;

}
int main ()
{  try{
    int n;
    std::vector<std::pair<double,double>> vektorcvorova;
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin>>n;
    switch(n){
        case 1: {
                std::cout<<"Unesite broj cvorova: ";
                int a;
                std::cin>>a;
                std::cout<<"Unesite cvorove kao parove x y: ";
                std::pair<double,double> cvor;
                for(int i=0; i<a; i++){
                 std::cin>>cvor.first;
                 std::cin>>cvor.second;
                 vektorcvorova.push_back(cvor);
                }
                
                std::cout<<"Unesite red interpolacije: ";
                int b;
                std::cin>>b;
              
               
                for(;;){
                    double arg;
                    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    std::cin>>arg;
                    if(!std::cin) break; 
                    auto f(BaricentricnaInterpolacija(vektorcvorova,b));
                    std::cout<<"f("<<arg<<") = "<<f(arg)<<std::endl;
                }
                return 0;
        } 
                
        case 2: {
                double i1,i2,k,red;
                std::cout<<"Unesite krajeve intervala i korak: ";
                std::cin>>i1>>i2>>k;
                std::cout<<"Unesite red interpolacije: ";
                std::cin>>red;
                
                for(;;){
                    double arg;
                    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    std::cin>>arg;
                    if(!std::cin) break;
                    
                    auto fun = [](double x) {return x*x + std::sin(x); };
                    auto f(BaricentricnaInterpolacija(xsinx,i1,i2,k,red));
        
                  std::cout<<"f("<<arg<<") = "<<fun(arg)<<" fapprox("<<arg<<") = "<<f(arg)<<std::endl;
                }
                return 0;
        }
    }
}
catch(std::domain_error e){
    std::cout<<e.what();
}
	return 0;
}