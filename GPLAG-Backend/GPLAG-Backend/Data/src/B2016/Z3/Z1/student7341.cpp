/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include<stdexcept>
#include <cmath>



 std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double, double>> parovi, int d){
    
    //provjera izuzetaka
    
   
    if(d>parovi.size() || d<0) throw std::domain_error ("Nedozvoljen red");
   
    for( auto i=0; i<int(parovi.size())-1; i++) {
        for( auto j=i+1; j<parovi.size(); j++) {
            if(parovi[i].first==parovi[j].first) throw std::domain_error ("Neispravni cvorovi");
        }
    }
   
   std::vector<double>koeficijenti(parovi.size(), 0);
    //izracunati svi koeficijenti u vektor se guraju
    
    
   for(int i=1; i<=parovi.size(); i++){
       
        for(int k=std::max(1,i-d); k<=(std::min(i,int(parovi.size())-d)); k++){
        double proizvod=1;
        for(int j=k; j<=k+d; j++){
            if(i==j) continue;
            proizvod=proizvod*(1./(parovi[i-1].first-parovi[j-1].first));
        }
        koeficijenti[i-1]+=(std::pow(int(-1),k-1)*proizvod);
    }
   }
   

    
    return [koeficijenti,parovi] (double x){ 
        double suma_gore=0;
        double suma_dole=0;
        for(int i=1; i<=parovi.size(); i++){
            if(parovi[i-1].first==x) return parovi[i-1].second;
            suma_gore+=(koeficijenti[i-1]*parovi[i-1].second)/(x-parovi[i-1].first);
            suma_dole+=(koeficijenti[i-1])/(x-parovi[i-1].first);
            
        }
        return double(suma_gore/suma_dole);
    };
 }    

std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> fja, double min, double max, double razmak, int d){
    if(min>max || razmak<=0) throw std::domain_error ("Nekorektni parametri");
    std::vector<std::pair<double, double>> parovi;
    for(double i=min; i<=max; i+=razmak){ 
        parovi.push_back(std::make_pair(i,fja(i)));
    }   
    
    return BaricentricnaInterpolacija(parovi,d);
    
}
    
        
int main (){
    int naredba;
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin>> naredba;
    std::vector<std::pair<double,double>> parovi;
    if(naredba==1){
        
        std::cout<<"Unesite broj cvorova: ";
        int br_cvorova;
        std::cin>>br_cvorova;
        std::cout<<"Unesite cvorove kao parove x y: ";
        
        for(int i=0;i<br_cvorova; i++){
            double x,y;
            std::cin>>x;
            std::cin>>y;
            parovi.push_back(std::make_pair(x,y));
        }
        int d;
        std::cout<<"Unesite red interpolacije: ";
        std::cin>>d;
        double x;
        std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
        std::cin>>x;
        try{
           auto f( BaricentricnaInterpolacija(parovi,d));
            while(std::cin){
             std::cout<<"f(" <<x<< ") = " <<f(x)<<std::endl;
             std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
             std::cin>>x;
            }
            }catch( std::domain_error Izuzetak){
                std::cout<<Izuzetak.what()<<std::endl;
                return 0;
            }
        }
        
     
     
     if(naredba==2){
         std::cout<<"Unesite krajeve intervala i korak: ";
         double min, max;
         double korak;
         std::cin>>min>>max>>korak;
         std::cout<<"Unesite red interpolacije: ";
         int d;
         std::cin>>d;
         std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
         double x;
         
         std::cin>>x;
         try{
            
             auto g(BaricentricnaInterpolacija([](double x) {return x*x+std::sin(x);},min,max,korak,d));
             while(std::cin){
                 std::cout<<"f(" <<x<< ") = " <<x*x+std::sin(x)<<" fapprox("<<x<<") = "<<g(x)<<std::endl;
                 std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                 std::cin>>x;
             }
         } catch( std::domain_error Izuzetak){
                std::cout<<Izuzetak.what()<<std::endl;
                return 0;
            }
        }
     
        return 0;
}