/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <functional>
#include <utility>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <cmath>

std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double,double>> cvorovi) {
    
      
    for(auto it=cvorovi.begin();it!=cvorovi.end();it++) {
        
        if(std::count_if(it,cvorovi.end(),[it] (std::pair<double,double>par){
           if(fabs(it->first-par.first)<0.000001)return true;
           return false;
       })>1) throw std::domain_error("Neispravni cvorovi");
    } 
    
    std::sort(cvorovi.begin(),cvorovi.end(), [] (std::pair<double,double> prvi, std::pair<double,double>drugi){
        return prvi.first<drugi.first;} );
        
    return [cvorovi] (double x) {
        
        if(x<cvorovi[0].first || x>cvorovi[cvorovi.size()-1].first) throw std::range_error("Argument izvan opsega");
        auto manji=cvorovi.begin();
        while(manji!=cvorovi.end() && manji->first<x)manji++;
       if(manji!=cvorovi.begin()) manji--;
        auto veci=cvorovi.begin();
        while(veci!= cvorovi.end()&&veci->first <x)veci++;
            
            return manji->second + (x-manji->first)*(veci->second - manji->second)/(veci->first - manji->first);
    };
    
} 

std::function<double(double)>LinearnaInterpolacija(std::function<double(double)>f, double xmin, double xmax, double deltax){
    
    if(xmin>xmax || deltax<=0)throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> cvorovi;
    double x=xmin;
    while(x<=xmax){
        cvorovi.push_back(std::make_pair(x,f(x)));
        x+=deltax;
    }
   
    return LinearnaInterpolacija(cvorovi);
}


int main ()
{
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int opcija; std::cin>>opcija;
   
   try{ 
    if(opcija==1) {
    std::cout<<"Unesite broj cvorova: ";
    int brojcvorova; std::cin>>brojcvorova;
    std::cout<<"Unesite cvorove kao parove x y: ";
    double x, y;
    std::vector<std::pair<double,double>>vektor;
    for(int i=0;i<brojcvorova;i++) {
        std::cin>>x;
        std::cin>>y;
        vektor.push_back(std::make_pair(x,y));
    }
     while(1) {
         try {
            LinearnaInterpolacija(vektor)(1); //da baci izuzetak prije nego sto se ispise tekst
    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
    double argument;
    std::cin>>argument;
    if(!std::cin)return 0;
    std::cout<<"f("<<argument<<") = "<<LinearnaInterpolacija(vektor)(argument)<<std::endl;     
         }
            catch(std::range_error izuzetak) {
       std::cout<<izuzetak.what()<<std::endl;
   }
   catch(std::domain_error izuzetak) {
       throw;
   }
   
     }



    }
    if(opcija==2) {
        
    std::cout<<"Unesite krajeve intervala i korak: ";
    double xmin,xmax,deltax;
    std::cin>>xmin; std::cin>>xmax; std::cin>>deltax;
    while(1) {
        try{
    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";   
    double argument;
    std::cin>>argument;
    if(!std::cin)return 0;
    std::cout<<"f("<<argument<<") = "<<std::sin(argument)+argument*argument<<" fapprox("<<argument<<") = "<<LinearnaInterpolacija([](double x){return std::sin(x)+x*x;},xmin,xmax,deltax )(argument)<<std::endl;
        }
        catch(std::range_error izuzetak){
            std::cout<<izuzetak.what()<<std::endl;
        }
        catch(std::domain_error izuzetak) {
            throw;
        }
    }
        
    }
   }
    catch(std::domain_error izuzetak) {
        std::cout<<izuzetak.what();
    }
    

    
	return 0;
}
