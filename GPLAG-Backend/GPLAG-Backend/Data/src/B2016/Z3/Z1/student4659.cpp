/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <utility>
#include <vector>
#include <functional>
#include <cmath>
#include <stdexcept>
#include <algorithm>
double WI(std::vector<std::pair<double,double>> v , int i,int d){
    double sum(0);
    for(int k=std::max(1,i-d);k<=std::min(i,(int)v.size()-d);k++){
        double p(1);
        for(int j=k;j<=k+d;j++)if(j!=i)p=p*1/(v[i-1].first-v[j-1].first);
        sum=sum+pow(-1,k-1)*p;
    }
    return sum;
}

std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double,double>>v , int d){
    int n(v.size());
    
    if(d<0 || d>=n)throw std::domain_error("Nedozvoljen red");
    for(auto it=v.begin();it!=v.end(); it++){
        for(auto it2=it+1;it2!=v.end();it2++){
            if(it->first==it2->first)throw std::domain_error("Neispravni cvorovi");
        }
    }
        
        std::function<double(double)> f;
        
        auto sum1([v,n,d](double x){ 
            double suma(0);
            for(int i=0;i<n;i++){
                if(x==v[i].first)return v[i].second;
                suma=suma+WI(v,i+1,d)*v[i].second/(x-v[i].first);
            }
            return suma;
        });   
            auto sum2([v,n,d](double x){ 
                double suma(0);
                for(int i=0;i<n;i++){
                    if(x==v[i].first)return 1.;
                    suma=suma+WI(v,i+1,d)/(x-v[i].first);
                }
                return suma;
            });
            
    return [sum1,sum2](double x){return sum1(x)/sum2(x);};
}

std::function<double(double)>BaricentricnaInterpolacija(std::function <double(double)> f,double a,double b,double c,int d){
    if(a>b || c<=0)throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> v;
    
    for(double i=a;i<b;i=i+c){
        v.push_back(std::make_pair(i,f(i)));
    }
    try{
        auto funk(BaricentricnaInterpolacija(v,d));
        return funk;
    }
    catch(...){
        throw;
    }
}

int main ()
{
    int a(0);
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin >> a;
    
        if(a==1){
            int n(0);
            std::cout << "Unesite broj cvorova: ";
            std::cin >> n;
                
                std::vector<std::pair<double,double>> v ;
                std::cout << "Unesite cvorove kao parove x y: ";
                for(int i=0;i<n;i++ ){
                    int x(0),y(0);
                    std::cin >> x >> y ;
                    v.push_back(std::make_pair(x,y));
                }
                    
                    int d(0);
                    std::cout << "Unesite red interpolacije: ";
                    std::cin >> d;
                    try{
                        auto f(BaricentricnaInterpolacija(v,d));
                    
                        while(1){
                            double c(0);
                            std::cout << "Unesite argument (ili \"kraj\" za kraj): " ;
                            std::cin >> c;
                            if(!std::cin && std::cin.peek()!='\n')break;
                            std::cout << "f(" << c << ") = " << f(c) << std::endl;
                        }
                    }
                    catch(std::domain_error e){
                        std::cout << e.what();
                        return 0;
                    }    
        }
        if(a==2){
            double a,b,c;
            std::cout << "Unesite krajeve intervala i korak: ";
            std::cin >> a >> b >> c;
                
                int d(0);            
                std::cout << "Unesite red interpolacije: ";
                std::cin >> d;
                
                try{
                    std::function<double(double)>funkcija=[](double x){return x*x+std::sin(x);};
                    auto faprox(BaricentricnaInterpolacija(funkcija,a,b,c,d));
    
                    while(1){
                            double c(0);
                            std::cout << "Unesite argument (ili \"kraj\" za kraj): " ;
                            std::cin >> c;
                            if(!std::cin || std::cin.peek()!='\n')break;
                            std::cout << "f(" << c << ") = "<< funkcija(c) << " fapprox(" << c << ") = " << faprox(c) << std::endl;
                    }
                }
                catch(std::domain_error e){
                    std::cout << e.what();
                    return 0;
                }    
        }
    
	return 0;
}