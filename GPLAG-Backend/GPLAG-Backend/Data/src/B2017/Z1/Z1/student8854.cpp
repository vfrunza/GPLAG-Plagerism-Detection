/*B 2017/2018, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

bool DaLiJeProst (int n){
    if (n==0 || n==1) return false;
    for (int i{2};i<=std::sqrt(n);i++)
        if (n%i==0)
        	return false;
    return true;
}

std::vector<int> PretvoriUTernarni (int n){
	std::vector<int> ternarni;
	int ostatak;
	while (n!=0){
	    ostatak=n%3;
	    ternarni.push_back(ostatak);
	    n/=3;
	}
	return ternarni;
}

bool DaLiJeTernarniSimetrican (int n){
	std::vector<int>ternarni{PretvoriUTernarni(n)};
	for (int i{0};i<ternarni.size()/2;i++){
	    if (ternarni.at(i)!=ternarni.at(ternarni.size()-i-1)) 
	        return false;
	}
	return true;
}

std::vector<int> IzdvojiSimetricneTernarne (std::vector<int> v, bool logicka){
	
    for (int i {0}; i<int(v.size()); i++){
        for (int j {i+1}; j<int(v.size()); j++){
            if (v.at(i) == v.at(j)) 
                v.erase (v.begin()+j);
        }
    }
   
    std::vector<int> ternarni;
    if (logicka){
    	for (int i{0}; i<int(v.size()); i++)
    		if (DaLiJeProst(std::abs(v.at(i)))==true && DaLiJeTernarniSimetrican(std::abs(v.at(i))))
     			ternarni.push_back(v.at(i));
    }
    else {
    	for (int i{0}; i<int(v.size()); i++)
    	if (DaLiJeProst(std::abs(v.at(i)))==false && DaLiJeTernarniSimetrican(std::abs(v.at(i))))
    		ternarni.push_back(v.at(i));
    }
    return ternarni;
}

int main (){
    std::vector<int> v;
    int broj;
    std::cout<<"Unesite elemente vektora (-1 za kraj): ";
    for (;;){
    	std::cin>>broj;
    	if (broj==-1) break;
    	v.push_back(broj);
    }
    int logi;
    std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
    std::cin>>logi;
    while (1){
        if (logi == 0 || logi == 1) break;
        std::cout<<"Neispravan unos! Unesite ponovo: ";
        std::cin>>logi;
        
    }
    std::vector<int> ternarni {IzdvojiSimetricneTernarne(v,logi)};
    
    if (ternarni.size()==0 && logi==1)
        std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
        
    else if (ternarni.size()==0 && logi==0)
        std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
        
    else if (logi){
        std::cout<<"Prosti simetricni brojevi iz vektora su: ";
        for (int i {0};i<int(ternarni.size());i++){
    	    if (i==ternarni.size()-1) 
    		    std::cout<<ternarni.at(i)<<".";
    	    else
    		    std::cout<<ternarni.at(i)<<", ";
        }
    }
    
    else {
        std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
        for (int i{0};i<int(ternarni.size());i++){
            if (i==ternarni.size()-1)
                std::cout<<ternarni.at(i)<<".";
            else
                std::cout<<ternarni.at(i)<<", ";
        }
    }
    	
	return 0;
}