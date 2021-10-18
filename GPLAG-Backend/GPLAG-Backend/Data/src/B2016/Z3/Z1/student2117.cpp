/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <functional>
#include <vector>
#include <utility>
#include <stdexcept>
#include <cmath>

std::function<double(double)>BaricentricnaInterpolacija(std::vector<std::pair<double, double>> vektor_parova, int d)
{
    int n(vektor_parova.size());
    if(d>=n || d<0) throw std::domain_error("Nedozvoljen red");
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(vektor_parova[i].first == vektor_parova[j].first) throw std::domain_error("Neispravni cvorovi");
        }
    }
    std::vector<double> w(n);
    for(int i=1; i<=n; i++) {
        
        for(int k=std::max(1, i-d); k<=std::min(i, n-d); k++) {
            double produkt(1);
            for(int j=k; j<=k+d; j++) {
                if(i==j) continue;
                produkt*=(1./(vektor_parova[i-1].first-vektor_parova[j-1].first));
            }
            if((k-1)%2==0) produkt*=1;
            else produkt*=-1;
            w[i-1]+=produkt;
        }
        
    }
    return [vektor_parova, w](double x){
        for(auto i : vektor_parova){
            if(x==i.first) return i.second;
        }
        double suma_brojnik(0), suma_nazivnik(0);
        for(int i=1; i<=vektor_parova.size(); i++){
            suma_brojnik+=((w[i-1]*vektor_parova[i-1].second)/(x-vektor_parova[i-1].first));
            suma_nazivnik+=(w[i-1]/(x-vektor_parova[i-1].first));
        }
        
        return suma_brojnik/suma_nazivnik;
    };
}


std::function<double(double)>BaricentricnaInterpolacija(double f(double), double x_min, double x_max, double delta_x, int d){
    if((x_min>x_max) || delta_x<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double, double>> vp;
    for(double i=x_min; i<=x_max; i+=delta_x){
        vp.push_back(std::make_pair(i, f(i)));
    }
    return BaricentricnaInterpolacija(vp, d);
}

int main ()
{
    int opcija;
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin>>opcija;
    if(opcija == 1){
        int n;
        std::cout<<"Unesite broj cvorova: ";
        std::cin>>n;
        std::vector<std::pair<double, double>> vp;
        std::cout<<"Unesite cvorove kao parove x y: ";
        for(int i=0; i<n; i++){
            double x,y;
            std::cin>>x>>y;
            vp.push_back(std::make_pair(x,y));
        }
        int d;
        std::cout<<"Unesite red interpolacije: ";
        std::cin>>d;
        
        for(;;){
            double argument;
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            std::cin>>argument;
            if(!std::cin) break;
            try{
                auto f(BaricentricnaInterpolacija(vp, d));
                std::cout<<"f("<<argument<<") = "<<f(argument);
            }
            catch(std::domain_error poruka){
                std::cout<<poruka.what()<<std::endl;
                return 0;
            }
            std::cout<<std::endl;
        }
    }
    if(opcija == 2){
        double x_max, x_min, delta_x;
        std::cout<<"Unesite krajeve intervala i korak: "; 
        std::cin>>x_min>>x_max>>delta_x;
        int d;
        std::cout<<"Unesite red interpolacije: ";
        std::cin>>d;
        for(;;){
            double argument;
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            std::cin>>argument;
            if(!std::cin) break;
            try{
                auto f(BaricentricnaInterpolacija([](double argument){ return argument*argument+std::sin(argument);},x_min,x_max, delta_x, d));
                std::cout<<"f("<<argument<<") = "<<argument*argument+std::sin(argument)<<" fapprox("<<argument<<") = "<<f(argument);
            }
            catch(std::domain_error poruka){
                std::cout<<poruka.what()<<std::endl;
                return 0;
            }
            std::cout<<std::endl;
        }
    }
	return 0;
}