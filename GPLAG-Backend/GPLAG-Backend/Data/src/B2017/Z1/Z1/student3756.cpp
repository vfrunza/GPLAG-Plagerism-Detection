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

bool PonavljaSe(std::vector<int> v, int n){
	for(int i=0; i < v.size(); i++){
		if(v.at(i) == n) return true; 
	}
	return false; 
}

bool DaLiJeProst(int n){
	n = abs(n); 
	if(n == 0) return false; 
	for(int i=2; i < n; i++){
		if(n % i == 0) return false;  
	}
	return true; 
}

std::vector<int> PrebaciUTernarni(int n){
	std::vector<int> ternarni; 
	std::vector<int> pomocni; 
	while(n != 0){
		pomocni.push_back(abs(n % 3)); 
		n = n / 3; 
	}
	for(int i = pomocni.size()-1; i >= 0; i--){
		ternarni.push_back(pomocni.at(i)); 
	}
	
	
	return ternarni; 
}

bool DaLiJeSimetrican(int n){
	n = abs(n); 

	std::vector<int> ternarni; 
	ternarni = PrebaciUTernarni(n); 
	if(n == 2) return false; 
	int j(ternarni.size()-1); 
	for(int i = 0; i < ternarni.size()/2; i++){
		if(ternarni.at(i) != ternarni.at(j)) return false; 
		j--; 
	}
	
	return true; 
}


std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> v, bool istinitost){
	std::vector<int> vektor;
	
	
	if(istinitost){
		for(int i = 0; i < v.size(); i++){
			if(v.at(i) == 0 || v.at(i) == 1) continue; 
			if(!DaLiJeProst(v.at(i))) continue; 
			if(DaLiJeSimetrican(v.at(i)) && !PonavljaSe(vektor, v.at(i))){
				vektor.push_back(v.at(i)); 
			}  		
	}
	}
	else{
		for(int i = 0; i < v.size(); i++){
			if(DaLiJeProst(v.at(i))) continue; 
			if(DaLiJeSimetrican(v.at(i)) && !PonavljaSe(vektor, v.at(i))){
				vektor.push_back(v.at(i)); 
			}
		}
	}
	
	
	return vektor; 
}



int main ()
{
	std::cout << "Unesite elemente vektora (-1 za kraj): "; 
	int k(0);
	std::vector<int>v;
	while(k != -1){
		std::cin >> k; 
		if(k == -1) break; 
		v.push_back(k); 
	}
	
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: "; 
	int ist; 
	std::cin >> ist; 
	while ((ist != 0 && ist != 1)) {   
			std::cout << "Neispravan unos! Unesite ponovo: "; 
			std::cin >> ist; 
	}
	bool istinitost(ist); 
	std::vector<int> vektor = IzdvojiSimetricneTernarne(v, istinitost);

	if(istinitost){
		if(vektor.size() == 0){ 
			std::cout << "Nema prostih simetricnih brojeva u vektoru. " << std::endl; 
			return 0;
		}
	std::cout << "Prosti simetricni brojevi iz vektora su: ";
	for(int i = 0; i < vektor.size(); i++){
		if(i < vektor.size()-1) std::cout << vektor.at(i) << ", ";   
			else std::cout << vektor.at(i) << "." << std::endl;
	}
	}
	else{
		
		if(vektor.size() == 0){ 
			std::cout << "Nema slozenih simetricnih brojeva u vektoru. " << std::endl; 
			return 0;
		}
	std::cout << "Slozeni simetricni brojevi iz vektora su: ";
	for(int i = 0; i < vektor.size(); i++){
		if(i < vektor.size()-1) std::cout << vektor.at(i) << ", ";   
			else std::cout << vektor.at(i) << "." << std::endl;
	}
		
	}
	return 0;
}