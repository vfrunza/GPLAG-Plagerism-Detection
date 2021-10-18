/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include<utility>
#include <functional>
#include <stdexcept>
#include <limits>
#include <cmath>

const double e=std::numeric_limits<double>::epsilon();

double Proizvod(std::vector<std::pair<double, double>> parovi, int d, int k, int i){
    double proizvod(1);
    for (int j(k-1); j<k+d; j++){
        if(j!=i) proizvod*=1./(parovi[i].first - parovi[j].first);
    }
    return proizvod;
}
double Wi (std::vector<std::pair<double, double>> parovi, int d, int i){
    int donja_granica, gornja_granica;
    double w(0);
    if(i-d>1) donja_granica = i-d;
    else donja_granica=1;
    if(i<parovi.size()-d) gornja_granica=i;
    else gornja_granica=parovi.size()-d;
    for(int k(donja_granica); k<=gornja_granica; k++){
        w+=std::pow(-1,k-1)*Proizvod(parovi,d,k,i-1);
    }
    return w;
}
double Brojnik(std::vector<std::pair<double, double>> parovi, int d, double x){
    double suma(0);
    for(int i(0); i<parovi.size(); i++){
        suma+=(Wi(parovi, d, i+1))*parovi[i].second/(x-parovi[i].first);
    }
    return suma;
}
double Nazivnik(std::vector<std::pair<double, double>> parovi, int d, double x){
    double suma(0);
    for (int i(0); i<parovi.size(); i++){
        suma+=(Wi(parovi, d, i+1))/(x-parovi[i].first);
    }
    return suma;
}
std::function<double(double)>BaricentricnaInterpolacija(std::vector<std::pair<double, double>> parovi, int d){
    if(d<0 || d>=parovi.size()) throw std::domain_error ("Nedozvoljen red");
    for (int i(0); i<parovi.size(); i++)
        for(int j(i+1); j<parovi.size(); j++)
            if(std::fabs(parovi[i].first-parovi[j].first)<e) throw std::domain_error ("Neispravni cvorovi");
            return [parovi, d] (double x){
                for (int i(0); i<parovi.size(); i++)
                    if(std::fabs(x-parovi[i].first)<e) return parovi[i].second;
                    return Brojnik(parovi, d, x) / Nazivnik(parovi, d, x);
            };
}

std::function<double(double)> BaricentricnaInterpolacija (std::function<double (double)> f, double xmin, double xmax, double dx, int d){
    if(xmin>xmax || dx<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double, double>> parovi;
    for(double x(xmin); x<=xmax;x+=dx){
        parovi.push_back(std::make_pair(x, f(x)));
    }
    return BaricentricnaInterpolacija(parovi, d);
}
int main ()
{
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int odabir;
    std::cin>>odabir;
    if(odabir==1){
        std::vector<std::pair<double, double>> parovi;
        std::cout<<"Unesite broj cvorova: ";
        int cvorovi;
        std::cin>>cvorovi;
        std::cout<<"Unesite cvorove kao parove x y: ";
        for(int i(0); i<cvorovi; i++){
            double x,y;
            std::cin>>x>>y;
            parovi.push_back(std::make_pair(x, y));
        }
        std::cout<<"Unesite red interpolacije: ";
        int d;
        std::cin>>d;
        try{
            auto f=BaricentricnaInterpolacija(parovi, d);
            for(;;){
                char navodnici='"';
                std::cout<<"Unesite argument (ili "<<navodnici<<"kraj"<<navodnici<<" za kraj): ";
                double argument;
                std::cin>>argument;
                if(!std::cin) break;
                std::cout<<"f("<<argument << ") = "<< f(argument) << std::endl;
            }
        }
        catch(std::domain_error e){
            std::cout<<e.what();
        }
    }
    if(odabir==2){
        std::cout<<"Unesite krajeve intervala i korak: ";
        double kraj1, kraj2, korak;
        std::cin>>kraj1>>kraj2>>korak;
        std::cout<<"Unesite red interpolacije: ";
        int d;
        std::cin>> d;
        try{
            auto f=BaricentricnaInterpolacija([] (double x) { return x*x+std::sin(x);}, kraj1, kraj2, korak, d);
            for(;;){
                char navodnici='"';
                std::cout<<"Unesite argument (ili "<<navodnici<<"kraj"<<navodnici<<" za kraj): ";
                double argument;
                std::cin>>argument;
                if(!std::cin) break;
                std::cout<<"f("<<argument<<") = "<<argument*argument+std::sin(argument)<<" fapprox("<<argument<<") = "<<f(argument)<<std::endl;
            }
        }
        catch(std::domain_error e){
            std::cout<<e.what();
        }
    }
	return 0;
}