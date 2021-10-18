/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <utility>
#include <vector>
#include <functional>
#include <stdexcept>

//typedef double (double) f;

int stepenuj (int &b, int s){
    int p(b);
    b=1;
    for(int i=1; i<=s; i++) b*=p;
    return b;
}

std::function<double(double)> BaricentricnaInterpolacija ( std::vector<std::pair<double,double>> v , int d ){
    int n(v.size());
    if(d>=n || d<0) throw std::domain_error ("Nedozvoljen red");
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(v[i].first==v[j].first) throw std::domain_error ("Neispravni cvorovi");
        }
    }
    
    std::vector<double> Wi;
    for(int i=1; i<=n; i++){
        double wi(0);
        int z(1), visina_reda(n-d);
        if(1<i-d) z=i-d;
        if(i<visina_reda) visina_reda=i;
        for(int k=z; k<=visina_reda; k++){
            int koef (-1);
            koef=stepenuj(koef,k-1);
            double proizvod(1);
            for(int j=k; j<=k+d; j++){
                if(j!=i) proizvod*=1. / (v[i-1].first - v[j-1].first );
            }
            proizvod*=koef;
            wi+=proizvod;
        }
        //std::cout << "w"<<i<< " koeficijent je: "<<wi << std::endl;
        Wi.push_back(wi);
    }
    std::function<double(double)> f = [Wi, v] (double x) {
        double brojnik(0), nazivnik(0);
        int indeks(0);
        bool postoji(false);
        for (int i=0; i<v.size(); i++){
            if(x!=v[i].first) brojnik+= Wi[i]*v[i].second/(x-v[i].first);
            else { postoji=true; indeks=i; }
            
        }
        for(int i=0; i<v.size(); i++){
            if(x!=v[i].first) nazivnik+=Wi[i]/(x-v[i].first);
            else { postoji=true; indeks=i; }
        }
        
        if(postoji) return v[indeks].second;
        return brojnik/nazivnik;
    };
    
    return f;
}


std::function<double(double)> BaricentricnaInterpolacija (std::function<double(double)> f, double xmin, double xmax, double delta, int d){
    if(xmin>xmax || delta<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double, double>> v ;
    double p(xmin);
    std::function<double(double)> fun;
    while (p<=xmax) {
        v.push_back(std::make_pair(p, f(p)));
        p+=delta;
    }
    try{
        fun= BaricentricnaInterpolacija(v,d);
    }
    catch(...){
        throw;
    }
    return fun;
}

#include <cmath>
double Pomocna (double x){
    return x*x+std::sin(x);
}

int main ()
{ 
    int opcija;
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): " ;
    std::cin >> opcija;
    if(opcija==1){
        int cvorova;
        std::cout << "Unesite broj cvorova: " ;
        std::cin>> cvorova;
        std::cout << "Unesite cvorove kao parove x y: " ;
        std::vector<std::pair<double,double>> vek_cvorova;
        for(int i=0; i<cvorova; i++ ) {
            double prvi, drugi;
            std::cin>>prvi>>drugi;
            vek_cvorova.push_back(std::make_pair(prvi,drugi));
        }
        int red;
        std::cout << "Unesite red interpolacije: " ;
        std::cin >> red;
        try{
            for(;;){
                double x;
                std::cout << "Unesite argument (ili \"kraj\" za kraj): " ;
                if(std::cin>>x) std::cout << "f("<<x<<") = "<< BaricentricnaInterpolacija(vek_cvorova,red)(x) << std::endl;
                else break;
            }
        }
        catch(std::domain_error i){
            std::cout << i.what() << std::endl;
        }
    }
    else{
        double xmin,xmax,delta;
        std::cout << "Unesite krajeve intervala i korak: " ;
        std::cin >> xmin>> xmax>> delta;
        std::cout << "Unesite red interpolacije: " ;
        int d;
        std::cin >> d;
        try {
            for(;;){
                double arg;
                std::cout << "Unesite argument (ili \"kraj\" za kraj): " ;
                if(std::cin >> arg) std::cout << "f("<<arg<<") = "<<Pomocna(arg)<<" fapprox("<<arg<<") = "<<BaricentricnaInterpolacija(Pomocna,xmin,xmax,delta,d)(arg) << std::endl;
                else break;
            }
        }
        catch (std::domain_error i) {
            std::cout << i.what() << std::endl;
        }
        
    }
	return 0;
}