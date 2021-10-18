/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
std::function<double(double)>BaricentricnaInterpolacija(std::vector<double>v, int d){
   int n=v.size();
    std::vector<double>w;
    for(int i=0; i<n; i++) {
        int min,max;
        if(i<n-d)  min=i;
        else min=n-d;
        if(i>n-d) max=i;
        else max=n-d;
    
        for(int k=max;k!=min;k++) {
            double proizvod(1);
            for(int j=k; j!=(k+d); j++) {
                double clan=1/(v[i]-v[j]);
                proizvod*=clan;
            }
           w.push_back(proizvod); 
        }
        
    }
    return [v, w, d](double x) {
        double suma1(0),suma2(0);
        int n=v.size();
        for(int i=0; i<n; i++) {
         double clan=(w[i])/(x-v[i].first))*(v[i].second);
        suma1+=clan;
        }
        for(int i=0; i<n; i++) {
            double clan=w[i]/(x-v[i].first);
            suma2+=clan;
        }
        return suma1/suma2;
    };
}
int main ()
{
    int opcija,x,y;
    std::vector<double> v;
    std::cout<<"Odaberite opciju (1-unos clanova, 2-aproksimacija): ";
    std::cin>>opcija;
    if(opcija==1) {
        int br_cv;
        std::cout<<"Unesite broj cvorova: ";
        std::cin>>br_cv;
        std::pair<double,double> uredjen_par;
        std::cout<<"Unesite cvorove kao parove x y: ";
        for(int i=0; i<br_cv; i++) {
            std::cin>>x>>y;
            uredjen_par=std::make_pair(x,y);
            v.push_back(uredjen_par);
        }
        int d;
        std::cout<<"Unesite red interpolacije: ";
        std::cin>>d;
        double argument;
        std::cout<<"Unesite argument (ili "kraj" za kraj): ";
        std::cin>>argument;
        while(!std::cin) {
            std::cout<<"Unesite argument (ili "kraj" za kraj): ";
            std::cin>>argument;
            std::cout<<f(argument);
        }
        
    }
	return 0;
}