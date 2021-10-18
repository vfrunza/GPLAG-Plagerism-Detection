/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <stdexcept>
#include <functional>
#include <vector>
#include <cmath>
std::function<double(double)>BaricentricnaInterpolacija(std::vector<std::pair<double,double>>parovi,int a){
    if(a<0 || a>parovi.size())throw std::domain_error("Nedozvoljeni red");
    for(int i(0);i<parovi.size();i++){
        for(int j(i+1);j<parovi.size();j++){
            const double E(1e-10);
            if(std::fabs(parovi[i].first-parovi[j].first)<=E*(std::fabs(parovi[i].first)+std::fabs(parovi[j].first)))throw std::domain_error("Neispravni cvorovi");
        }
    }
    std::vector<double>pom;
    for(int b(0);b<parovi.size();b++){
}
    
int main ()
{   
  
	return 0;
}