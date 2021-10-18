/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <functional>
#include <stdexcept>
#include <cmath>
#include <utility>
double IzracunajTezinski(int iBroj, int d, int n, std::vector<std::pair<double, double> > xevi) {
    double rezultat(0);
    int k, gornjagranica;
    if(iBroj-d<0) k=0;
    else k=iBroj-d;
    if(iBroj<n-1-d) gornjagranica=iBroj;
    else gornjagranica=n-1-d;
    for(int i=k; i<=gornjagranica; i++) {
        double proizvod(pow(-1,i));
        if(k+d<xevi.size()) {
        for(int j=i; j<=i+d; j++) {
            if(j!=iBroj) {proizvod*=(1/(xevi[iBroj].first-xevi[j].first));}
        } rezultat+=proizvod;}
        else { for(int j=k; j<i+d; j++) {
            if(j==iBroj) j++;
            proizvod*=(1./(xevi[iBroj].first-xevi[j].first));
        } rezultat+=proizvod;}
    } return rezultat;
}

std::function<double(double)> BaricentricnaInterpolacija (std::vector<std::pair<double, double> > v, int d){
    if(d<0 || d>v.size()) throw std::domain_error("Nedozvoljen red");
    for(int i=0; i<v.size(); i++) {
        for(int j=0; j<v.size(); j++) {
            if(v[i].first==v[j].first && i!=j) throw std::domain_error("Neispravni cvorovi");}}
    return [v,d] (double x) {
        for(int i=0; i<v.size(); i++) if(x==v[i].first) return v[i].second;
        std::vector<double> tezinski(v.size());
        for(int i=0; i<tezinski.size(); i++) tezinski[i]=IzracunajTezinski(i, d, v.size(),  v);
        double fja(0), brojnik(0), nazivnik(0);
        for(int i=0; i<v.size(); i++) {
            if(x!=v[i].first){
            brojnik+=(tezinski[i]*v[i].second)/(x-v[i].first);
            nazivnik+=(tezinski[i])/(x-v[i].first);
        }} fja=brojnik/nazivnik;
            return fja;
        };    }

std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)>f, double xmin, double xmax, double deltax, int d) {
    if(xmin>xmax || deltax<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<double> xkord;
        for(double i=xmin; i<xmax; i=i+deltax) xkord.push_back(i);
        std::vector<std::pair<double, double> > cvorovi(xkord.size());
        for(int i=0; i<cvorovi.size(); i++) {
            cvorovi[i].first=xkord[i];
            cvorovi[i].second=f(xkord[i]);}
            return [cvorovi, d] (double x) {
        for(int i=0; i<cvorovi.size(); i++) if(x==cvorovi[i].first) return cvorovi[i].second;
        std::vector<double> tezinski(cvorovi.size());
        for(int i=0; i<tezinski.size(); i++) tezinski[i]=IzracunajTezinski(i, d, cvorovi.size(),  cvorovi);
        double fja(0), brojnik(0), nazivnik(0);
        for(int i=0; i<cvorovi.size(); i++) {
            if(x!=cvorovi[i].first){
            brojnik+=(tezinski[i]*cvorovi[i].second)/(x-cvorovi[i].first);
            nazivnik+=(tezinski[i])/(x-cvorovi[i].first);
        }} fja=brojnik/nazivnik;
            return fja;
        };   
    
}
double funkcija(double x) {
    return x*x+std::sin(x);
}
    
int main ()
{
int d, opcija, vel;
std::vector<std::pair<double, double> > cvorovi;
double xmin, xmax, deltax;
for(;;){
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin>>opcija;
    if(opcija==1) {
        std::cout<<"Unesite broj cvorova: ";
        std::cin>>vel;
        double iks, ips;
        std::cout<<"Unesite cvorove kao parove x y: ";
        for(int i=0; i<vel; i++) {std::cin>>iks; 
        std::cin>>ips;
        cvorovi.push_back(std::make_pair(iks, ips));}
        std::cout<<"Unesite red interpolacije: ";
        std::cin>>d;
        try{
        auto f(BaricentricnaInterpolacija(cvorovi, d));
        for(;;) {
        std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
        double arg;
        std::cin>>arg;
            if(!std::cin) break;
            std::cout<<"f("<<arg<<") = "<<f(arg)<<std::endl;
        } } catch(std::domain_error e) {std::cout<<e.what();} } 
     if(opcija==2) {   std::cout<<"Unesite krajeve intervala i korak: ";
            std::cin>>xmin>>xmax>>deltax;
            std::cout<<"Unesite red interpolacije: ";
            std::cin>>d;
            try{
            auto g(BaricentricnaInterpolacija(funkcija, xmin, xmax, deltax, d));
            for(;;){
                std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                double arg;
                std::cin>>arg;
                if(!std::cin) break;
                std::cout<<"f("<<arg<<") = "<<funkcija(arg)<<" fapprox("<<arg<<") = "<<g(arg)<<std::endl; }
        }  catch(std::domain_error greska) {std::cout<<greska.what();}}
        break;
    
    }
    
	return 0;
}