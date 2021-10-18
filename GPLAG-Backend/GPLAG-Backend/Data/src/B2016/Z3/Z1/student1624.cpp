/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <utility>
#include <vector>
#include <stdexcept>
#include <functional>
#include <cmath>
std::function<double (double)> BaricentricnaInterpolacija(std::vector<std::pair<double, double>> parovi, int d) {
    if(d<0 || d>parovi.size()) throw std::domain_error("Nedozvoljen red");
    bool ispravni_cvorovi=true;
    for(int i=0; i<parovi.size(); i++) {
        for(int j=0; j<parovi.size() && j!=i; j++) if(parovi[i].first==parovi[j].first && parovi[i].second!=parovi[j].second) ispravni_cvorovi=false;
    } if(!ispravni_cvorovi) throw std::domain_error("Neispravni cvorovi");
    return[parovi, d] (double x) {
        double suma1(0), suma2(0), fun(0);
        for(int i=0; i<parovi.size(); i++) {
            double w(0);
            int k, stop;
            if(i-d<0) k=0; 
            else k=i-d;
            if(parovi.size()-1-d<i)  stop=parovi.size()-1-d;
            else stop=i;
            for(int l=k; l<=stop; l++) {
                double razlomak(pow(-1, l));
                if(k+d<parovi.size()) {
                for(int j=l; j<=l+d; j++) {
                  if(j!=i)  razlomak*=(1./(parovi[i].first-parovi[j].first));
                } w=w+razlomak;}
                else {
                    for(int j=k; j<l+d; j++) {
                        if(j!=i)
                        razlomak*=(1./(parovi[i].first-parovi[j].first));
                    } w=w+razlomak;
                }}
              suma1=suma1+(w*parovi[i].second)/(x-parovi[i].first);
            suma2=suma2+(w)/(x-parovi[i].first);
        } bool nijeapscisa=true;
        for(int i=0; i<parovi.size(); i++) if(x==parovi[i].first) {fun=parovi[i].second;
        nijeapscisa=false;}
        if(nijeapscisa) fun=suma1/suma2;
        return fun;
    };}
std::function<double(double)> BaricentricnaInterpolacija(double fun(double), double xmin, double xmax, double korak, int d) {
    if(korak<=0 || xmin>xmax || d<0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double, double>> parovi;
    for(double i=xmin; i<xmax; i+=korak){
        double x, y;
        x=i;
        y=fun(i);
        parovi.push_back(std::make_pair(x, y));} 
        return[parovi, d] (double x) {
            double suma1(0), suma2(0), fun(0);
            for(int i=0; i<parovi.size(); i++) {
                double w(0);
                int k, stop;
            if(i-d<0) k=0; 
            else k=i-d;
               if(parovi.size()-1-d<i)  stop=parovi.size()-1-d;
            else stop=i;
                for(int l=k; l<=stop; l++) {
                    double razlomak(pow(-1,l));
                    if(k+d<parovi.size()) {
                        for(int j=l; j<=l+d; j++) if(j!=i) razlomak=razlomak*(1./(parovi[i].first-parovi[j].first));
                        w=w+razlomak;}
                        else {for(int j=k; j<l+d; j++){
                            if(j!=i) razlomak=razlomak*(1./(parovi[i].first-parovi[j].first));
                        } w=w+razlomak;}}
                        suma1=suma1+(w*parovi[i].second)/(x-parovi[i].first);
                        suma2=suma2+w/(x-parovi[i].first);
                } bool nijeapscisa=true;
                for(int i=0; i<parovi.size(); i++) if(x==parovi[i].first) {
                    fun=parovi[i].second;
                    nijeapscisa=false;
                } if(nijeapscisa) fun=suma1/suma2;
                return fun;
            };
            }
int main ()
{
    int opcija, d, koliko;
    double xmin, xmax, korak;
    std::vector<std::pair<double, double>> parovi;
    for(;;) {
        std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        std::cin>>opcija;
        if(opcija==1) {
            std::cout<<"Unesite broj cvorova: ";
            std::cin>>koliko;
            std::cout<<"Unesite cvorove kao parove x y: ";
            for(int i=0; i<koliko; i++) {
                double x, y;
                std::cin>>x>>y;
                parovi.push_back(std::make_pair(x,y));}
                std::cout<<"Unesite red interpolacije: ";
                std::cin>>d;
                try{
                    std::function<double(double)> funk=BaricentricnaInterpolacija(parovi, d);
                    do{
                        double argument;
                        std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                        std::cin>>argument;
                        if(!std::cin) break;
                        else std::cout<<"f("<<argument<<") = "<<funk(argument)<<std::endl;
                    } while(std::cin);
                } catch(std::domain_error redilicvorovi) {std::cout<<redilicvorovi.what();}
        }
        else if(opcija==2) {
            std::cout<<"Unesite krajeve intervala i korak: ";
            std::cin>>xmin>>xmax>>korak;
            std::cout<<"Unesite red interpolacije: ";
            std::cin>>d;
            try{
                std::function<double(double)> aproksimacija=BaricentricnaInterpolacija([] (double x) {return x*x + std::sin(x);}, xmin, xmax, korak, d);
                do{
                    double argument;
                    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    std::cin>>argument;
                    if(!std::cin) break;
                    else std::cout<<"f("<<argument<<") = "<<argument*argument + std::sin(argument)<<" fapprox("<<argument<<") = "<<aproksimacija(argument)<<std::endl;
                } while(std::cin);
                } catch(std::domain_error korektni) {std::cout<<korektni.what();}
        } break;
    }
	return 0;
}