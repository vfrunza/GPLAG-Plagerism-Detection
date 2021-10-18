/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <functional>
#include <stdexcept>
#include <vector>
#include <utility>
#include <cmath>
std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double,double>> vektor_parova,int d) {
    if(d<0 || d>vektor_parova.size()) throw std::domain_error ("Nedozvoljen red");
    for(int i=0;i<vektor_parova.size();i++) {
        for(int j=i+1;j<vektor_parova.size();j++) {
            if(vektor_parova[i].first==vektor_parova[j].first) throw std::domain_error ("Neispravni cvorovi");
        }
    }
    std::vector<double> wi(vektor_parova.size());
    for(int i=1;i<=vektor_parova.size();i++) {
        int max,min;
        if(i-d>=1) max=i-d;
        else max=1;
        if(i<=vektor_parova.size()-d) min=i;
        else min=vektor_parova.size()-d;
        wi[i-1]=0;
        for(int k=max;k<=min;k++) {
            double proizvod(1);
            for(int j=k;j<=k+d;j++) {
                if(j!=i) proizvod*=1/(vektor_parova[i-1].first-vektor_parova[j-1].first);
            }
            wi[i-1]+=std::pow(-1,k-1)*proizvod;
        }
    }
    return [vektor_parova,wi](double x){double suma1(0),suma2(0);
                                        for(int i=1;i<=vektor_parova.size();i++) {
                                            if(x==vektor_parova[i-1].first) return vektor_parova[i-1].second;
                                            suma1+=(wi[i-1]/(x-vektor_parova[i-1].first));
                                            suma2+=(wi[i-1]/(x-vektor_parova[i-1].first))*vektor_parova[i-1].second;
                                         }
                                        return suma2/suma1;};
}
std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> f,double xmin,double xmax,double dx,int d) {
    if(xmin>xmax || dx<=0) throw std::domain_error ("Nekorektni parametri");
    std::vector<std::pair<double,double>> vektor_parova;
    for(double i=xmin;i<=xmax;i+=dx) {
        std::pair<double,double> par;
        par.first=i;
        par.second=f(i);
        vektor_parova.push_back(par);
    }
    auto fun(BaricentricnaInterpolacija(vektor_parova,d));
    return fun;
}
int main ()
{
    int opcija;
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin>>opcija;
    if(opcija==1) {
        int broj_cvorova;
        std::cout<<"Unesite broj cvorova: ";
        std::cin>>broj_cvorova;
        std::cout<<"Unesite cvorove kao parove x y: ";
        std::vector<std::pair<double,double>> vektor_parova(broj_cvorova);
        for(int i=0;i<broj_cvorova;i++) {
            std::cin>>vektor_parova[i].first>>vektor_parova[i].second;
        }
        int d;
        std::cout<<"Unesite red interpolacije: ";
        std::cin>>d;
        std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
        double argument;
        while(std::cin>>argument) {
            auto f=BaricentricnaInterpolacija(vektor_parova,d);
            std::cout<<"f("<<argument<<") = "<<f(argument);
            std::cout<<"\nUnesite argument (ili \"kraj\" za kraj): ";
        }
    }
    else if(opcija==2) {
        std::cout<<"Unesite krajeve intervala i korak: ";
        double xmin,xmax,dx;
        std::cin>>xmin>>xmax>>dx;
        int d;
        std::cout<<"Unesite red interpolacije: ";
        std::cin>>d;
        std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
        double argument;
        while(std::cin>>argument) {
            auto fun=BaricentricnaInterpolacija([](double x){return x*x+std::sin(x);},xmin,xmax,dx,d);
            auto f=[](double argument){return argument*argument+std::sin(argument);};
            std::cout<<"f("<<argument<<") = "<<f(argument)<<" fapprox("<<argument<<") = "<<fun(argument);
            std::cout<<"\nUnesite argument (ili \"kraj\" za kraj): ";
        }
    }
	return 0;
}