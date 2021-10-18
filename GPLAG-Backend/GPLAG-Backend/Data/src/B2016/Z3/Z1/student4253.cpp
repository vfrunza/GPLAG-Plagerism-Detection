/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <functional>
#include <vector>
#include <utility>
#include <cmath>

bool JesuLiJednaki(double x, double y, double Eps=1e-10){
    return std::fabs(x-y)<=Eps*(std::fabs(x)+std::fabs(y));
}

double Pomocna (double x, std::vector<std::pair<double,double>> v,int p){
    double dio(1);
    for(int i(0); i<int(v.size()); i++){
        if(i==p) continue;
        dio*=(x-v.at(i).first);
    }
    return dio;
}

std::function<double(double)> BaricentricnaInterpolacija ( std::vector<std::pair<double,double>> v, int d ){
    if(d<0) throw std::domain_error ("Nedozvoljen red");
    if(int(v.size())<=d) throw std::domain_error ("Nedozvoljen red");
    for(int i(0); i<int(v.size()); i++){
        for(int j(i+1); j<int(v.size()); j++){
            if(JesuLiJednaki(v.at(i).first,v.at(j).first)) throw std::domain_error ("Neispravni cvorovi");
        }
    }
    
    std::vector<double> w;
    int n(int(v.size()));
    
    for(int i(1); i<=int(v.size()); i++){
        int poc, kraj;
        if(i<n-d) kraj=i;
        else kraj=n-d;
        if(i-d>1) poc=i-d;
        else poc=1;
        double suma(0);
        for(int k(poc); k<=kraj; k++){
            double proizvod(1);
            
            for(int j(k); j<=k+d; j++){
                if(i==j) continue;
                proizvod*=1./(v.at(i-1).first-v.at(j-1).first);
            }
            
            suma+=proizvod*pow(-1,k-1);
        }
        w.push_back(suma);
    }
    return [v,w](double x) { double sumag(0), sumad(0);
                        double suma;
                        for(int i(0); i<int(v.size()); i++){
                            sumag+=Pomocna(x,v,i)*v.at(i).second*w.at(i);
                            sumad+=Pomocna(x,v,i)*w.at(i);
                        } 
                        suma=sumag/sumad;
                        return suma; };
}

std::function<double(double)> BaricentricnaInterpolacija (std::function<double(double)> fun, double pocetak, double kraj, double x, int d){
    if(pocetak>kraj || x<=0) throw std::domain_error ("Nekorektni parametri");
    
    std::vector<std::pair<double,double>> cvorovi;
    double p(pocetak), k(kraj);
    
    for(p; p<=k || JesuLiJednaki(p,k); p+=x ) cvorovi.push_back(std::make_pair(p,fun(p)));
    
    return BaricentricnaInterpolacija(cvorovi,d);
}

void Cvorovi(){
    std::cout<<"Unesite broj cvorova: ";
            int br_cvorova;
            std::cin>>br_cvorova;
            std::vector<std::pair<double,double>> parovi;
            std::cout<<"Unesite cvorove kao parove x y: ";
            for(int i(0); i<br_cvorova; i++){
                int prvi, drugi;
                std::cin>>prvi>>drugi;
                parovi.push_back(std::make_pair(prvi,drugi));
            }
            std::cout<<"Unesite red interpolacije: ";
            int d;
            std::cin>>d;
        try{
            for(;;){
                double argument;
                auto f(BaricentricnaInterpolacija(parovi,d));
                std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                std::cin>>argument;
                if(!std::cin) break;
                std::cout<<"f("<<argument<<") = "<<f(argument)<<std::endl;
            }
        }
        catch(...){
            throw;
        }
}

void Aproksimacija(){
    std::cout<<"Unesite krajeve intervala i korak: ";
    double pocetak, kraj;
    double korak;
    std::cin>>pocetak>>kraj;
    std::cin>>korak;
    std::cout<<"Unesite red interpolacije: ";
    int d;
    std::cin>>d;
    try{
    for(;;){
        auto f([](double x){return x*x+std::sin(x);});
        auto fapr(BaricentricnaInterpolacija(f, pocetak, kraj, korak, d));
        double argument;
        std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
        std::cin>>argument;
        if(!std::cin ) break;
        std::cout<<"f("<<argument<<") = "<<f(argument)<<" fapprox("<<argument<<") = "<<fapr(argument)<<std::endl;
    }}
    catch(...){
        throw;
    }
}

int main ()
{
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int opcija;
    std::cin>>opcija;
    
    try{
        if(opcija==1){
            Cvorovi();
        }
        else if(opcija==2){
            Aproksimacija();
        }
    }
    catch(std::domain_error izuzetak){
        std::cout<<izuzetak.what();
    }
    
	return 0;
}