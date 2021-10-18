/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <utility>
#include <string>

std::vector



int main () {
    
    int opcija;
    std::cout<<"Odaberite opciju (1 - unos cvorova,2 - aproksimacija) : ";
    std::cin>>opcija;
    
    if(opcija==1) {
        int broj_cvorova;
        std::cout<<"Unesite broj cvorova: ";
        std::cin>>broj_cvorova;
        
        std::cout<<"Unesite covorove kao parove x y: ";
        std::vector<std::pair<double,double>> v;
        for(int i(0);i<broj_cvorova;i++) {
            std::pair<double,double> par;
            double x; std::cin>>x;
            par.first=x;
            double y; std::cin>>y;
            par.second=y;
            v.push_back(par);
        }
        
        while(1) {
            double argument;
            std::cout<<"Unesite argument (ili kraj za kraj ): ";
            std::cin>>argument;
            if(!std::cin) break;
        }
        
        
    }
    
    
    
    
	return 0;
}
