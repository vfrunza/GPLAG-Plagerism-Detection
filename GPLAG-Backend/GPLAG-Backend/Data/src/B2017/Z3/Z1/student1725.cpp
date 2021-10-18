/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <functional>
#include <cmath>
#include <algorithm>
#include <utility>
#include <iterator>
#include <stdexcept>


double Funkcija(double x) {
return x*x+std::sin(x);    
} 

std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double,double>> Vektor) {
   
 
   std::sort(Vektor.begin(), Vektor.end());
   
    for(int i=0; i<Vektor.size();i++) {
        if(i==Vektor.size()-1) break;
       if(Vektor.at(i).first==Vektor.at(i+1).first) throw std::domain_error("Neispravni cvorovi");
    }
        
    
   return [Vektor] (double koordinata1) {
       std::pair <double, double> Par(koordinata1,0);
       auto iterator=std::lower_bound(Vektor.begin(), Vektor.end(), Par);
       std::pair<double,double> PrviPar(*iterator);
       iterator--;
       std::pair<double,double> DrugiPar(*iterator);
     if(koordinata1<Vektor[0].first || koordinata1>Vektor[Vektor.size()-1].first) throw std::range_error("Argument izvan opsega");
       koordinata1=PrviPar.second+((DrugiPar.second-PrviPar.second)/(DrugiPar.first-PrviPar.first))*(koordinata1-PrviPar.first);
       return koordinata1;
   };
   
}


std::function<double(double)> LinearnaInterpolacija(double(double), double minX, double maxX, double deltaX) {
   
    std::vector<std::pair< double, double>> Vektor {};
   
    std::pair<double, double> Par(0,0);
    
    int i(0);
    while(1) {
        if(Par.first>maxX) break;
        Par=std::make_pair(minX+deltaX*i, Funkcija(minX+deltaX*i));
        Vektor.push_back(Par);
        i++;
    }
    
    return [Vektor] (double koordinata1) {
        std::pair<double,double> Par(koordinata1,0);
        auto Iterator=std::lower_bound(Vektor.begin(), Vektor.end(), Par);
        
        std::pair<double, double> PrviPar(*Iterator);
        Iterator--;
        std::pair<double,double> DrugiPar(*Iterator);
        koordinata1=PrviPar.second+((DrugiPar.second-PrviPar.second)/(DrugiPar.first-PrviPar.first))*(koordinata1-PrviPar.first);
        return koordinata1;
    };
}

int main ()
{
    std::vector<std::pair<double,double>> Vektor;
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int option;
    std::cin>>option;
    if(option==1) { //za poziv prve funkcije
        std::cout<<"Unesite broj cvorova: ";
        int br_cvor;
        std::cin>>br_cvor;
        double x,y;
        std::cout<<"Unesite cvorove kao parove x y: ";
        for(int i=0;i<br_cvor; i++) {
            std::cin>>x;
            std::cin>>y;
            Vektor.push_back(std::make_pair(x,y));
        }
         try {
             auto F(LinearnaInterpolacija(Vektor));
         }
         catch(std::domain_error Izuzetak) {
             std::cout<<Izuzetak.what();
             return 0;
         }
         
         double argument;
         while(1) {
             std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
             std::cin>>argument;
             if(std::cin) {
                 auto F(LinearnaInterpolacija(Vektor));
                 std::cout<<"f("<<argument<<") = "<<F(argument);
                 std::cout<<std::endl;
             }
             else break;
         }
    }
    
    double end1,end2, step;
    if(option==2) { //za poziv druge funkcije
        std::cout<<"Unesite krajeve intervala i korak: ";
        std::cin>>end1;
        std::cin>>end2;
        std::cin>>step;
        double argument;
        while(std::cin) {
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            do {
                std::cin>>argument;
                if(!std::cin) {
                    std::cin.ignore(10000, '\n');
                    break;
                }
                if(argument<end1 || argument>=end2) {
                    std::cout<<"Argument izvan opsega"<<std::endl;
                    break;
                }
                auto fapprox(LinearnaInterpolacija(Funkcija,end1,end2,step));
                std::cout<<"f("<<argument<<") = "<<Funkcija(argument)<<" fapprox("<<argument<<") = "<<fapprox(argument);
            } while(argument<end1 || argument>end2);
            std::cout<<std::endl;
        }
    }
	return 0;  
}
