/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <stdexcept>
#include <cmath>
#include <algorithm>

std::function<double(double)> BaricentricnaInterpolacija (std::vector<std::pair<double,double>> c, int d) {
    if (d<0 || d>=c.size()) throw std::domain_error ("Nedozvoljen red");
    for (int i=0; i<c.size(); i++) 
        for (int j=i+1; j<c.size(); j++) {
            if (c[i].first==c[j].first) throw std::domain_error("Neispravni cvorovi");
        }
    std::vector<double> tez_koef;
    int m=0,n=c.size()-d;
    for (int i=1; i<=c.size(); i++) {
        m=std::min(i,n);
        double suma=0;
        for (int k=std::max(1,i-d); k<=m; k++) {
            double proizvod=1;
            for (int j=k; j<=k+d; j++)
                if (j!=i)
                    proizvod*=1/(c[i-1].first-c[j-1].first);
            suma+= pow(-1,k-1)*proizvod;
        }
        tez_koef.push_back(suma);
    }
    return [c,tez_koef,d] (double x) {
        double nova=0,pomocna=0;
        for (int i=0; i<c.size(); i++)
            if (x==c[i].first) return c[i].second;
        for (int i=1; i<=c.size(); i++) {
            nova+=(tez_koef[i-1]/(x-c[i-1].first))*c[i-1].second;
            pomocna+=tez_koef[i-1]/(x-c[i-1].first); 
        } return (nova/pomocna); };
}

std::function<double(double)> BaricentricnaInterpolacija (double f(double), double x_min, double x_max, double delta_x, int d) {
    if (x_min>x_max || delta_x<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> c;
    for (auto i=x_min; i<=x_max; i+=delta_x) {
        double y=f(i);
//std::cout<<"x="<<i<<" y="<<y<<"\n";
        c.push_back(std::make_pair(i,y));
    }
    return BaricentricnaInterpolacija(c,d);
}

std::string Kraj () {
    std::string s="Unesite argument (ili ";
    s+='"';
    s+="kraj";
    s+='"';
    s+=" za kraj): ";
    return s;
}

int main ()
{
    int opcija;
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin>>opcija;
    if (opcija==1) {
        int broj_cvorova;
        std::cout<<"Unesite broj cvorova: ";
        std::cin>>broj_cvorova;
        std::cout<<"Unesite cvorove kao parove x y: ";
        std::vector<std::pair<double,double>> cvorovi;
        double x,y;
        for (int i=0; i<broj_cvorova; i++) {
            std::cin>>x>>y;
            cvorovi.push_back(std::make_pair(x,y));
        }
        int red_interpolacije;
        std::cout<<"Unesite red interpolacije: ";
        std::cin>>red_interpolacije;
        try {
            auto funkcija=BaricentricnaInterpolacija(cvorovi,red_interpolacije);
            double argument;
            for (;;) {
                std::cout<<Kraj();
                std::cin>>argument;
                if (!(argument)) return 0;
                std::cout<<"f("<<argument<<") = "<<funkcija(argument)<<std::endl;
            }
        }
        catch (std::domain_error a) {
            std::cout<<a.what();
        }
    }
    else if (opcija ==2) {
        double x_min, x_max, delta_x;
        std::cout<<"Unesite krajeve intervala i korak: ";
        std::cin>>x_min>>x_max>>delta_x;
        int red_interpolacije;
        std::cout<<"Unesite red interpolacije: ";
        std::cin>>red_interpolacije;
        try {
            auto f=[] (double x) {return x*x+sin(x);};
            auto f_aprox=BaricentricnaInterpolacija(f,x_min,x_max,delta_x,red_interpolacije);
            double argument;
            for (;;) {
                std::cout<<Kraj();
                std::cin>>argument;
                if (!(argument)) return 0;
                std::cout<<"f("<<argument<<") = "<<f(argument)<<" fapprox("<<argument<<") = "<<f_aprox(argument)<<std::endl;
            }
        }
        catch (std::domain_error b) {
            std::cout<<b.what();
        }
    }
	return 0;
}