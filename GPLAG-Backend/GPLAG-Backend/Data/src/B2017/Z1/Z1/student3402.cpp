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

bool DaLiJeProst(int n){
	if((unsigned int)fabs(n)==1 || n==0) return false;
	if((unsigned int)fabs(n)==2 || (unsigned int)fabs(n)==3) return true;
	for(unsigned int i=2; i*i<=fabs(n); i++){
		if(n%i==0) return false;
	}
	return true;
}

bool SimetricanTernar(int n){
	std::vector<int> cifre;
	unsigned int broj=fabs(n);
	while(broj>0){
		cifre.insert(cifre.begin(), broj%3);
		broj/=3;
	}
	for(int i=0; i<int(cifre.size())/2; i++){
		if(cifre.at(i)!=cifre.at((int(cifre.size())-1)-i)) return false;
	}
	return true;
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> brojevi, bool t){
	std::vector<int> ternari;
	
	for(int i=0; i<int(brojevi.size()); i++){
		if(t){
			if(DaLiJeProst(brojevi.at(i))){
				if(SimetricanTernar(brojevi.at(i))){
					bool vec_unesen_broj=false;
					for(int j=0; j<int(ternari.size()); j++){
						if(ternari.at(j)==brojevi.at(i)) vec_unesen_broj=true;
					}
					if(!vec_unesen_broj) ternari.push_back(brojevi.at(i));
				} 
			}
		}
		else{
			if(!DaLiJeProst(brojevi.at(i))){
				if(SimetricanTernar(brojevi.at(i))) {
					bool vec_unesen_broj=false;
					for(int j=0; j<int(ternari.size()); j++){
						if(ternari.at(j)==brojevi.at(i)) vec_unesen_broj=true;
					}
					if(!vec_unesen_broj) ternari.push_back(brojevi.at(i));
				}
			}
		}
	}
	return ternari;
}

int main ()
{
	std::vector<int> brojevi;
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	for(;;){
		int broj;
		std::cin >> broj;
		if(broj==-1) break;
		brojevi.push_back(broj);
	}
	bool prost;
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	for(;;){
		int temp;
		std::cin >> temp;
		if(temp==1 || temp==0){
			prost=temp;
			break;
		} 
		else std::cout << "Neispravan unos! Unesite ponovo: ";
		
	}
	if(prost){
		std::vector<int> prosti_ternari=IzdvojiSimetricneTernarne(brojevi,prost);
		if(int(prosti_ternari.size())==0) std::cout << "Nema prostih simetricnih brojeva u vektoru.\n";
		else{
			std::cout << "Prosti simetricni brojevi iz vektora su:";
			for(int i=0; i<int(prosti_ternari.size())-1; i++){
				std::cout << " " << prosti_ternari[i] << ",";
			}
			std::cout << " " << prosti_ternari[int(prosti_ternari.size()-1)] << ".\n";
		}
	}
	else{
		std::vector<int> slozeni_ternari=IzdvojiSimetricneTernarne(brojevi,prost);
		if(int(slozeni_ternari.size())==0) std::cout << "Nema slozenih simetricnih brojeva u vektoru.\n";
		else{
			std::cout << "Slozeni simetricni brojevi iz vektora su:";
			for(int i=0; i<int(slozeni_ternari.size())-1; i++){
				std::cout << " " << slozeni_ternari[i] << ",";
			}
			std::cout << " " << slozeni_ternari[int(slozeni_ternari.size()-1)] << ".\n";
		}
	}
	return 0;
}