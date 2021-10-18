/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <utility>
#include <vector>
#include <functional>
#include <stdexcept>
#include <string>//za "kraj"
#include <cmath>

int Max(int x, int y) {
    if(x>y) return x;
    else return y;
}

int Min(int x, int y) {
    if(x<y) return x;
    else return y;
}

double proizvod(int k, int i, int d, std::vector<std::pair<double,double>> cvorovi) {
    double proizvod(1);
    for(int j=k; j<=k+d; j++){
    if(i==j) continue;
    proizvod*=(1./(cvorovi[i-1].first-cvorovi[j-1].first));
   }
    
    return proizvod;
}

double TezinskiKoeficijent(int i, int d, std::vector<std::pair<double,double>> cvorovi) {
    
    double suma(0);
    for(int k=Max(1,i-d); k<=Min(i,cvorovi.size()-d); k++)
        {
            suma+=std::pow(-1,(k-1))*proizvod(k,i,d,cvorovi);
        }  
    return suma;    
}

std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double,double>> cvorovi, int d){
    if(d<0 || d>=cvorovi.size()) throw std::domain_error("Nedozvoljen red");
    for(int i=0; i<cvorovi.size();i++)
        for(int j=i+1; j<cvorovi.size(); j++)
            if(cvorovi[i].first == cvorovi[j].first) throw std::domain_error("Neispravni cvorovi");
    std::vector<double> koeficijenti(cvorovi.size());
    for(int i=0; i<cvorovi.size(); i++) {
        koeficijenti[i]=TezinskiKoeficijent(i+1,d,cvorovi);
    }
    return[cvorovi, koeficijenti](double x)->double{
        double suma1(0), suma2(0);
        for(int i=0; i<cvorovi.size(); i++) {
            if(x==cvorovi[i].first) return cvorovi[i].second;
            suma1+=(koeficijenti[i]/(x-cvorovi[i].first))*cvorovi[i].second;
            suma2+=koeficijenti[i]/(x-cvorovi[i].first);
        }
        return suma1/suma2;
    };
}

std::function<double(double)> BaricentricnaInterpolacija(double f(double), double x_min, double x_max, double x_delta, int d ){
    if(x_max<x_min || x_delta<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> cvorovi;
    double n(x_min);
    while(n<=x_max) {
        std::pair<double,double> par;
        par.first=n; 
        par.second=f(n); 
        cvorovi.push_back(par);
        n+=x_delta;
    }
   
    return BaricentricnaInterpolacija(cvorovi,d);
}

double f(double x) {
    return x*x+sin(x);
}

int main ()
{   int opcija;
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin>>opcija;
    if(opcija==1) {
        int broj_cvorova;
        std::cout<<"Unesite broj cvorova: ";
        std::cin>>broj_cvorova;
        //da li provjeravam da li je broj čvorova manji od 0?
        std::cout<<"Unesite cvorove kao parove x y: ";
        std::vector<std::pair<double,double>> cvorovi(broj_cvorova);
        for(auto &x: cvorovi){
            std::cin>>x.first>>x.second;
        }
        std::cout<<"Unesite red interpolacije: ";
        int d;
        std::cin>>d;
        try{
            std::function<double(double)> f(BaricentricnaInterpolacija(cvorovi,d));
            double x;
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            std::cin>>x;
            while(std::cin) {
                std::cout<<"f("<<x<<") = "<<f(x)<<std::endl; 
                std::cout<<"Unesite argument (ili \"kraj\" za kraj): "; 
                std::cin>>x;
            }
        }
        catch(std::domain_error izuzetak){
            std::cout<<izuzetak.what();
        } //možda ovdje treba da se vektor šalje po referenci jer bi mogao biti glomazan           
    }
    if(opcija==2) {
        std::cout<<"Unesite krajeve intervala i korak: ";
        int x_min, x_max;
        double x_delta;
        std::cin>>x_min>>x_max>>x_delta;
        std::cout<<"Unesite red interpolacije: ";
        int d;
        std::cin>>d;
        try{
            auto fapprox(BaricentricnaInterpolacija(f, x_min, x_max, x_delta, d));
            double x;
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            std::cin >> x;
            while(std::cin) {
                if(!(std::cin.peek>='0'&&std::cin.peek<='9')&&std::cin!='\n') return 0; 
                std::cout<< "f(" <<x<<") = "<<f(x)<<" fapprox("<<x<<") = "<<fapprox(x)<<std::endl;
                std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                std::cin>>x;
            }
        }
        catch (std::domain_error izuzetak) {
            std::cout << izuzetak.what() << std::endl;
        }
    }
	return 0;
}