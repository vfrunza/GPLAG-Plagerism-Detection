/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <stdexcept>
#include <cmath>


double stepenuj (int a, int b=-1){
    double suma(1);
    for(int i(0);i<a;i++){
        suma*=b;
    }
    return suma;
}

double w(int i, int d, int n, std::vector<std::pair<double,double>> v ){
    double suma(0);
    int poc,kraj;
    if(i<n-d) kraj=i;
    else kraj=n-d;
    if(1>i-d) poc=1;
    else poc=i-d;
    for(int p(poc);p<=kraj;p++){
    double proizvod(1);
    for(int j(p);j<=p+d;j++){
        if(i!=j) proizvod*=(1./(v[i-1].first-v[j-1].first));
    }
    double b=stepenuj(p-1);
    proizvod*=b;
    suma+=proizvod;
    }
return suma;
}

std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double, double>> v, int d){
    int n=v.size();
    if(d<0 || d>=n) throw std::domain_error("Nedozvoljen red");
    for(int i(0);i<v.size();i++){
            for(int j(i+1);j<v.size();j++) if(v[i].first==v[j].first) throw std::domain_error("Neispravni cvorovi");
        }
    return [v,d](double x) {
        int n=v.size();
        
        double suma1(0),suma2(0);
        for(int i(1);i<=n;i++){
            if(x==v[i-1].first) return v[i-1].second;
            suma1+=((w(i,d,n,v)/(x-v[i-1].first))*v[i-1].second);
            suma2+=(w(i,d,n,v)/(x-v[i-1].first));
        }
        return suma1/suma2;};
}

std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> f, double xmin, double xmax, double deltax, int d){
    if(xmin>xmax || deltax<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double, double>> v;
    double x=xmin;
    while(x<=xmax){
        v.push_back(std::make_pair(x, f(x)));
        x+=deltax;
    }
    return BaricentricnaInterpolacija(v,d);
    
}
int main ()
{

std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
int opcija;
std::cin >> opcija;
if(opcija==1){
    std::cout << "Unesite broj cvorova: " ;
    int broj_cvorova;
    std::cin >> broj_cvorova;
    std::cout << "Unesite cvorove kao parove x y: " ;
    std::vector<std::pair<double,double>> v;
    double x, y;
    for(int i(0);i<broj_cvorova;i++){
    std::cin >> x;
    std::cin >> y;
    v.push_back(std::make_pair(x,y));
    }
    std::cout << "Unesite red interpolacije: ";
    int d;
    std::cin >> d;
    try{
    std::function<double(double)> f(BaricentricnaInterpolacija(v,d));
    double argument;
    while(1){
        std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
        std::cin>> argument;
        if(!std::cin) return 0;
        std::cout << "f("<<argument<<") = "<<f(argument) << std::endl;
    }
    }
    catch(std::domain_error izuzetak){
        std::cout << izuzetak.what() ;
    }
}
else if(opcija==2){
    std::cout << "Unesite krajeve intervala i korak: " ;
    double xmin,xmax,delta;
    std::cin>>xmin>>xmax>>delta;
    std::cout << "Unesite red interpolacije: ";
    int d;
    std::cin >> d;
    double argument;
    try{
    auto f=BaricentricnaInterpolacija([](double x){return x*x+std::sin(x);}, xmin, xmax, delta, d);
    while(1){
        std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
        std::cin>>argument;
        if(!std::cin) return 0;
        std::cout << "f("<<argument<<") = " << [](double x) {return x*x+std::sin(x);}(argument)<<" fapprox("
        <<argument<<") = "<<f(argument)<< std::endl;
    }
    }
    catch(std::domain_error izuzetak){
        std::cout << izuzetak.what();
    }
}


	return 0;
}