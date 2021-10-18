/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <utility>
#include <vector>
#include <functional>
#include <algorithm>

std::function<double(double)> BaricentricnaIneterpolacija(std::vector<std::pair> cvorovi, int red){
    int n(cvorovi.size());
    
}

int main ()
{
    do{
        int izbor;
        std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        std::cin >> izbor;
        if(izbor==1){
            int broj_cvorova;
            std::cout << "Unesite broj cvorova: ";
            std::cin >> broj_cvorova;
            std::cout << "Unesite cvorove kao parove x y: ";
            for(int i=0; i<broj_cvorova; i++){
                
            }
        }
    }while()
	return 0;
}