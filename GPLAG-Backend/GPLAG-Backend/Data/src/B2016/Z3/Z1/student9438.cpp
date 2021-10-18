/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <utility>
#include <functional>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <cmath>

int Predznak(int x){
    int p(1);
    for(int i=1; i<=x; i++) p*=(-1);
    return p;
}

double Wi(int i, int vel, int d, const std::vector<std::pair<double, double>> &v){
    int maksimalni=std::max(1, i-d);
    int minimalni=std::min(i, vel-d);
    double suma(0);
    for(int k=maksimalni; k<=minimalni; k++){
        double proizvod(1);
        for(int j=k; j<=k+d; j++){
            if(j==i) continue;
            proizvod*=1/(v[i-1].first-v[j-1].first);
        }
        proizvod*=Predznak(k-1);
        suma+=proizvod;
    }
    return suma;
}


std::function<double(double)> BaricentricnaInterpolacija(const std::vector<std::pair<double, double>> &v, int d){
    if(d>v.size()) throw std::domain_error("Nedozvoljen red");
    for(int i=0; i<v.size(); i++){
        for(int j=i+1; j<v.size(); j++){
        if(v[i].first==v[j].first)  throw std::domain_error("Neispravni cvorovi");
        }
    }
    std::vector<double> w(v.size());
    int vel=v.size();
    for(int i=1; i<=v.size(); i++){
        w[i-1]=Wi(i, vel, d, v);
    }
    //for(auto x:w) std::cout<<x<<" ";
    return [v, w](double x){
        for(std::pair<double, double> pii: v) if(pii.first==x) return pii.second;
        double brojnik(0);
        for(int i=1; i<=v.size(); i++) brojnik+=w[i-1]*v[i-1].second/(x-v[i-1].first);
        double nazivnik(0);
        for(int i=1; i<=v.size(); i++) nazivnik+=w[i-1]/(x-v[i-1].first);
        double rezultat=brojnik/nazivnik;
        return rezultat;
    };
}

std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> f, double  min, double max,double delta, int d){
    if(min>max) throw std::domain_error("Nekorektni parametri");
    if(delta<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> v;
    double x(min);
    while(x<=max){
        v.push_back({x, f(x)});
        x+=delta;
    }
    return BaricentricnaInterpolacija(v, d);
}

int main ()
{
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int unos;
    std::cin>>unos;
    if(unos==1){
        std::cout<<"Unesite broj cvorova: ";
        int n;
        std::cin>>n;
        if(n==0) return 0;
        std::cout<<"Unesite cvorove kao parove x y: ";
        std::vector<std::pair<double,double>> v;
        for(int i=0; i<n; i++){
            double z, y;
            std::cin>>z>>y;
            std::pair<double,double> par=std::make_pair(z,y);
            v.push_back(par);
        }
        std::cout<<"Unesite red interpolacije: ";
        int d;
        std::cin>>d;
        std::cin.ignore(100, '\n');
        while(std::cin){
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            double argument;
            std::cin>>argument;
            if(std::cin.peek()!='\n') return 0;
            if(!std::cin) break;
            try{
            auto fun=BaricentricnaInterpolacija(v, d);
            std::cout<<"f("<<argument<<") = "<<fun(argument);
            std::cout<<std::endl;
            }
            catch(std::domain_error izuzetak){
                std::cout<<izuzetak.what();
                return 0;
            }
        }
    }
    else if(unos==2){
        std::cout<<"Unesite krajeve intervala i korak: ";
        double mi, ma, delta;
        std::cin>>mi>>ma>>delta;
        std::cout<<"Unesite red interpolacije: ";
        int d;
        std::cin>>d;
        std::cin.ignore(100, '\n');
        while(std::cin){
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            double argument;
            std::cin>>argument;
            if(std::cin.peek()!='\n') return 0;
            if(!std::cin) break;
            try{
                auto fapprox=BaricentricnaInterpolacija([](double x){return x*x+sin(x);}, mi, ma, delta, d);
                std::cout<<"f("<<argument<<") = "<<argument*argument+sin(argument)<<" fapprox("<<argument<<") = "<<fapprox(argument);
                std::cout<<std::endl;
            }
            catch(std::domain_error izuzetak){
                std::cout<<izuzetak.what();
                return 0;
            }
        }
    }
	return 0;
}