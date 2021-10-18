/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <utility>
#include <stdexcept>
#include <vector>
#include <functional>

std::function<std::vector<std::pair<double,double>>,int> BaricenticnaInterpolacija(std::vector<std::pair<double,double>> par,int d){
    if(d<0) throw std::domain_error("Nedozvoljen red");
    int n=par.size();
    double iznad(0),ispod(0);
    for(int i=0;i<n;i++){
        iznad+=w(i)*y(i)/(x-x(i));
        ispod+=w[i]/(x-x(i));
    }
    double f=iznad/ispod;
}
catch(std::domain_error poruka){
    std::cout<<poruka.what();
}
int main ()
{
    int n,brcvorova;
    double x,y;
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin>>n;
    if(n==1){
    std::cout<<"Unesite broj cvorova: ";
    std::cin>>brcvorova;
    std::vector<std::pair<double, double>> par (brcvorova);
    std::cout<<"Unesite cvorove kao parove x y: ";
    for(int i=0;i<brcvorova;i++){
        std::cin>>x;
        std::cin>>y;
        par[i].first=x;
        par[i].second=y;
        }
        int red;
       std::cout<<"Unesite red interpolacije: ";
       std::cin>>red;
       double arg;
       for( ; ; ){
           std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
           std::cin>>arg;
           if(!std::cin) break;
       }
    }
    else if(n==2){
        double korak,i1,i2;
        std::cout<<"Unesite krajeve intervala i korak: ";
        std::cin>>i1>>i2>>korak;
        int red;
        std::cout<<"Unesite red interpolacije: ";
        std::cin>>red;
        double arg;
        for(;;){
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            std::cin>>arg;
            if(!std::cin) break;
         }
    }
   
    
	return 0;
}