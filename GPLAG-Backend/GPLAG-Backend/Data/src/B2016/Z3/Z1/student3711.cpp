/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
#include <cstdlib>

int KonvertujStringUBroj (std::string broj_rijec){
    int broj;
    for(int i=0; i<broj_rijec.size(); i++){
        if(broj_rijec[i] == ' '){
            broj_rijec.erase(i, 1);
        }
    }
    for(int i=0; i<broj_rijec.size(); i++){
        if( !(broj_rijec[i]>='0' && broj_rijec[i]<='9') ){
            throw std::domain_error;
        }
    }
    broj = std::stoi(broj_rijec)
    return broj;
}

int main (){
    int opcija;
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin >> opcija;
    if(opcija == 1){
        std::pair<int,int> cvorovi;
        int broj_cvorova;
        std::cout << "Unesite broj cvorova: ";
        std::cin >> broj_cvorova;
        std::cout << "Unesite cvorove kao parove x y: ";
        for(int i=0; i<5; i++){
            std::cin >> cvorovi.first >> cvorovi.second;
        }
    } else if(opcija == 2){
        try{
            std::string unos, red_int;
            std::cout << "Unesite argument (ili " << "kraj" << " za kraj): ";
            std::cin >> unos;
            std::cout << "Unesite red interpolacije: ";
            std::cin >> red_int;
            KonvertujStringUBroj(unos);
            std::cout << 
        } catch (std::domain_error izuzetak){
            
        }
    } else {
        std::cout << "kraj!";

    }
	return 0;
}