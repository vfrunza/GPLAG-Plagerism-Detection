/*B 2017/2018, Zadaća 1, Zadatak 1
	
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
#include <cstdlib>

std::vector <int> IzdvojiSimetricneTernarne (std::vector <int> v, bool a){
	std::vector<int> prost_slozen;
	std::vector<int> ternarni_1;
	std::vector<int> ternarni_2;
	std::vector<int> simetricni;
	
	if(a==0){
	
		for(int i=0; i<std::abs(v.size()); i++){
			int prost(1);
			for(int j=2; j<std::abs(v.at(i)); j++){
				if(std::abs(v.at(i))%j==0) prost=0;
				
			} 
			if(prost==0)
			prost_slozen.push_back(v.at(i));
		
		}
		
	} else {
		
		for(int i=0; i<std::abs(v.size()); i++){
			int prost(1);
			for(int j=2; j<std::abs(v.at(i)); j++){
				if(std::abs(v.at(i))%j==0) prost=0;
				
			} 
			if(prost==1)
			prost_slozen.push_back(v.at(i));
		
		}
	}
		
	
	 for(int i=0; i<prost_slozen.size(); i++){
	
	int temp=std::abs(prost_slozen.at(i));
	
	do{
		int modul(temp%3);
			temp=temp/3;
			
				ternarni_2.push_back(modul);
	}
		while(temp!=0);

		
			for(int m=ternarni_2.size()-1; m>=0; m--){
				ternarni_1.push_back(ternarni_2.at(m));
			}
			
			
			if(ternarni_1==ternarni_2) {
				
			simetricni.push_back(prost_slozen.at(i));
	
		}
		
			ternarni_1.resize(0);
			ternarni_2.resize(0);
	
	 }
	
	
		for(int i=0; i<simetricni.size(); i++){
			for(int j=i+1; j<simetricni.size(); j++){
				if(simetricni.at(i)==simetricni.at(j)) {
				for(int k=j; k<simetricni.size()-1; k++){
						simetricni.at(k)=simetricni.at(k+1);
					
				}
				simetricni.resize(simetricni.size()-1);
					j--;
			}
		}
	}
	
	

		
		
	
	return simetricni;
	
	
	
	
	
	}
	

int main ()
{
	
	bool a;
	std::vector<int> v;
	
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	int broj;
	do {
 		std::cin >> broj;
	 	if(broj != -1) v.push_back(broj);
	} while(broj != -1);
	
	
	int prost_ili_slozen;
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	std::cin>>prost_ili_slozen;
	
	while(prost_ili_slozen!=0 && prost_ili_slozen!=1){
		std::cout<<"Neispravan unos! Unesite ponovo: ";
		std::cin>>prost_ili_slozen;
	}
	if(prost_ili_slozen==1) a=1;
	else a=0;
	
	
	std::vector<int> simetricni = IzdvojiSimetricneTernarne (v,a);

	if(simetricni.size()==0){
		if(a==1) std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
		else  std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
	}
	else {
		if(a==1) std::cout<<"Prosti simetricni brojevi iz vektora su: ";
		else std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
		
		int brojac(0);
		for(int d: simetricni){
			std::cout<<d;
			if(brojac<simetricni.size()-1) std::cout<<", ";
			else std::cout<<".";
			brojac++;
		}
	}
	
	return 0;
}



