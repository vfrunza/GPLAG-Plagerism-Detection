/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <functional>
#include <utility>
#include <stdexcept>
#include <cmath>


double fja (double x) {return x * x + std::sin(x);}

std::function < double(double) > BaricentricnaInterpolacija (std::vector<std::pair<double,double>> parovi, int d){
    for (int i=0; i<parovi.size(); i++){
        for (int j=i+1; j<parovi.size(); j++){
            if (fabs(parovi[j].first - parovi[i].first)<0.000000001) throw std::domain_error ("Neispravni cvorovi");
        }
    }
    if (d<0 || d>parovi.size()) throw std::domain_error ("Nedozvoljen red");
    std::vector<double> koef;
    for ( int i=1; i<=parovi.size(); i++){
        double w(0);
        int poc(0), kraj(0);
        if (1> (i-d)) poc = 1; else poc = i-d;
        if (i< (parovi.size()-d)) kraj = i; else kraj = (parovi.size()-d);
            for ( int k=poc; k<=kraj; k++){
                double p(1);
                    for ( int j=k; j<=k+d; j++){
                        if ((j-1)!=(i-1)){
                            p = p/(parovi[i-1].first-parovi[j-1].first);
                        }
                    }
                if (k%2==0) p = -p;
                w+=p;
            }
        koef.push_back(w);
    }
    
    
    return [koef,parovi] (double x){
        double suma1(0),suma2(0);
        for (int i=0; i<parovi.size(); i++){
            if (fabs(x - parovi[i].first)<0.000000001) return parovi[i].second;
            suma2+=(koef[i]/(x-parovi[i].first));
            suma1+=((koef[i]/(x-parovi[i].first))*parovi[i].second);
        }
        return (suma1/suma2);
    };
    
}

std::function < double(double) > BaricentricnaInterpolacija (double f(double), double xmin, double xmax, double dx, int d){
    if (xmax < xmin || dx<=0) throw std::domain_error ("Nekorektni parametri");
    std::vector<std::pair<double,double>> parovi;
    for (auto i=xmin; i<xmax; i+=dx){
        parovi.push_back(std::make_pair(i,f(i)));
    }
    
    return BaricentricnaInterpolacija(parovi,d);
}



int main ()
{
    try{
        std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        int odluka(0);
        std::cin>>odluka;
        if (odluka == 1){
            std::cout<<"Unesite broj cvorova: ";
            int n;
            std::cin>>n;
            std::cout<<"Unesite cvorove kao parove x y: ";
            std::vector<std::pair<double,double>> parovi (n);
            for (int i=0; i<n; i++){
                std::cin>>parovi[i].first;
                std::cin>>parovi[i].second;
            }
            std::cout<<"Unesite red interpolacije: ";
            int d;
            std::cin>>d;
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            double x;
            auto f (BaricentricnaInterpolacija(parovi,d));
            while (std::cin>>x){
                std::cout<<"f("<<x<<") = "<<f(x)<<std::endl;
                std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            }
            
            
        } else if (odluka == 2){
            std::cout<<"Unesite krajeve intervala i korak: ";
            double xmin,xmax,dx;
            std::cin>>xmin>>xmax>>dx;
            std::cout<<"Unesite red interpolacije: ";
            int d2;
            std::cin>>d2;
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): "; 
            double x2;
            auto fapprox (BaricentricnaInterpolacija(fja,xmin,xmax,dx,d2));
            while (std::cin>>x2){
                std::cout<<"f("<<x2<<") = "<<fja(x2)<<" fapprox("<<x2<<") = "<<fapprox(x2)<<std::endl;
                std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            }
        }
        
        
    } catch (std::domain_error greska){
        std::cout<<greska.what();
    }
    
	return 0;
}