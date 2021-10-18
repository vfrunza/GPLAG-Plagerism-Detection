/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <functional>
#include <utility>
#include <vector>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <cmath>

typedef std::vector<std::pair<double,double>> vektorCvorova;

double f(double x) {
    return x*x + std::sin(x);
}

double MinZaSumu(int index, int n, int d) {
    if(index > n-d) return n-d;
    return index;
}

double MaxZaSumu(int index, int d) {
    if(index - d > 1) return index-d;
    return 1;
}

std::vector<double> TezinskiKoeficijent(vektorCvorova cvorovi, int d) { 
    double nesto = 0;
    std::vector<double> w;
    for(int i = 1; i <= cvorovi.size(); i++) {
        nesto = 0;
    for(int k = MaxZaSumu(i,d); k <= MinZaSumu(i,cvorovi.size(),d); k++) {
        double proizvod = 1.;
        for(int j = k; j <= k+d; j++) {
            if(i != j) proizvod *= 1./(cvorovi[i-1].first - cvorovi[j-1].first); 
        }
        if(k%2 == 0) proizvod *= -1;
        nesto += proizvod;
    }
    w.push_back(nesto);
    }
    
    return w;
}

bool provjeraCvorovaX(vektorCvorova cvorovi) {
    for(int i = 1; i <= cvorovi.size(); i++)
     for(int j = i+1; j <= cvorovi.size(); j++)
     if(cvorovi[i-1].first == cvorovi[j-1].first) return false;
     return true;
}

std::function<double(double)> BaricentricnaInterpolacija( vektorCvorova cvorovi, int dRed) {
    if( dRed < 0 || dRed >= cvorovi.size()) throw std::domain_error("Nedozvoljen red");
    if(!provjeraCvorovaX(cvorovi)) throw std::domain_error("Neispravni cvorovi");
    
    return [cvorovi, dRed] (double x) {
        double nazivnik=0,brojnik = 0;
        auto w = TezinskiKoeficijent(cvorovi,dRed);
        for(int i = 1; i <= cvorovi.size(); i++) {
        if( x == cvorovi[i-1].first ) return cvorovi[i-1].second;
        nazivnik += (w[i-1]/(x - cvorovi[i-1].first));
        brojnik += (w[i-1]/(x - cvorovi[i-1].first))*cvorovi[i-1].second;
        }
        return (brojnik/nazivnik);
    };
}

bool imalBroja(std::string s) {
    int minus = 0,tacka=0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '.') tacka++;
        if(s[i] == '-') minus++;
    }
    if(minus > 1 || tacka > 1) return false;
    if( (minus != 0 || tacka != 0) && s.length() == 1) return false;
    
    for(int i = 0; i < s.length(); i++)
    if( !( (s[i] >= '0' && s[i] <= '9') || s[i] == '.' || s[i] == '-') ) return false;
    return true;
}

std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> fun, double xMin, double xMax, double deltaX, int d) {
    if(xMin > xMax || deltaX <= 0) throw std::domain_error("Nekorektni parametri");
    
        std::vector<std::pair<double,double>> rez;
        for(double i = xMin; i <= xMax; i+=deltaX)
        rez.push_back( std::make_pair(double(i),fun(i)) );
        
        return BaricentricnaInterpolacija(rez,d);
}


int main ()
{
    try{
        std::cout<< "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        int opcija=0; 
    
        std::cin>>opcija;
        switch(opcija) {
        case 1 : {
        vektorCvorova cvorovi;
        std::pair<double,double> parCvorova;
        std::cout<<"Unesite broj cvorova: ";
        int vel=0;
        std::cin>>vel;
        double prvi=0, drugi=0;
        std::cout<<"Unesite cvorove kao parove x y: ";
        for(int i=0; i < vel; i++) {
            std::cin>>prvi;
            std::cin>>drugi;
            parCvorova = std::make_pair(prvi,drugi);
            cvorovi.push_back(parCvorova);
        }
        std::cout<<"Unesite red interpolacije: ";
        int red=0;
        std::cin>>red;
        auto fu(BaricentricnaInterpolacija(cvorovi, red));
       
        std::string argument = "";
        std::cin.ignore(100000, '\n');
        do{
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            std::getline(std::cin, argument);
            if( argument.length() == 0 || argument == "kraj" || !imalBroja(argument)) break;
            double br = stod(argument);
            double vrijednost = fu(br);
            std::cout<< "f("<< br<< ") = "<< vrijednost;
            std::cout<<std::endl;
            
        }while(argument != "kraj" || !imalBroja(argument));
        break;
        }
        case 2 : { 
            std::cout<<"Unesite krajeve intervala i korak: ";
            double interv1=0,interv2=0;
            double korak =0;
            std::cin>>interv1;
            std::cin>>interv2;
            std::cin>>korak;
            std::cout<<"Unesite red interpolacije: ";
            int red=0;
            std::cin>>red;
            std::string arg = "";
            std::cin.ignore(100000, '\n');
            
        do{
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            std::getline(std::cin, arg);
            if( arg.length() == 0 || arg == "kraj" || !imalBroja(arg)) break;
            double br = stod(arg);
         
            double vrijedno = f(br);
            auto fun(BaricentricnaInterpolacija([](double x){return x*x +std::sin(x);},interv1,interv2,korak,red));
            double vrijednost = fun(br);
            
            std::cout<< "f("<< br<< ") = "<< vrijedno<<" "<<"fapprox("<<br<<") = "<<vrijednost;
            std::cout<<std::endl;
            
        }while(arg != "kraj" || !imalBroja(arg));
           
            break;
        }
      
        }
        
    }catch(std::domain_error d) {
        std::cout << d.what() << std::endl;
    }
    
    
	return 0;
}