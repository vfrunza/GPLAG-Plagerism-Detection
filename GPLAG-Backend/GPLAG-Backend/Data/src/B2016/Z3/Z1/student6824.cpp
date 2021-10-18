/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <utility>
#include <stdexcept>
#include <vector>
void BaricentricnaInterpolacija(std::vector<std::pair<double,double>> v, int d){
    if(d<0 || d>v.size()) throw std::domain_error("Nedozvoljeni red");
    for(int i=0; i<v.size()-1; i++){
        for(int j=i+1; j<v.size(); j++){
            if(v[i].first==v[j].first) throw std::domain_error("Neispravni cvorovi");
        }
    }
    
 std::cout <<"2";
}
void BaricentricnaInterpolacija(double fun(double), double xmin, double xmax, double dx, int d)
int main (){
    try{
    int izbor, cvor, d;
    double arg;
    std::vector<std::pair<double,double>> v;
    std::pair<double,double>par;
    std::cout <<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin >>izbor;
    std::cout <<"Unesite broj cvorova: ";
    std::cin >>cvor;
    std::cout <<"Unesite cvorove kao parove x y: ";
    for(int i=0; i<cvor; i++){
        std::cin >>par.first;
        std::cin >>par.second;
        v.push_back(par);
    }
    std::cout <<"Unesite red interpolacije: ";
    std::cin >>d;
    std::cout <<"Unesite argument (ili ""kraj"" za kraj): ";
   // std::cin >>arg;
    for(;;){
     std::cin >>arg;
//     std::cout <<f(arg);
     BaricentricnaInterpolacija(v,d);
     if(!std::cin || std::cin.peek()!='\n'){
         return 0;
     }     
     std::cout <<"Unesite argument (ili ""kraj"" za kraj): ";
    }
  /*  for(int i=0; i<cvor; i++){
        std::cout <<v[i].first<<" "<<v[i].second<<std::endl;
    }*/
    std::cout <<"1"; 
    }
    catch(std::domain_error izuzetak){
        std::cout <<izuzetak.what()<<std::endl;
    }
	return 0;
}