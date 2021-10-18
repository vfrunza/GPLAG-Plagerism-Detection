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
#include <cmath>
#include <vector>


bool DaLiJeProst(int broj){
	
	if(broj == 1){
		std::cout<<"Broj nije ni prost ni slozen!";
		return false;
	}
	else if(broj == 0){
	//std::cout<<"Broj nije ni prost ni slozen!";
	return false;
	}
	
	for(int i(2); i <= std::sqrt(double(broj)); i++){
		if(broj % i == 0)
		return false;
	}
	
	return true;
}

bool PretvorbaUTernarni(int broj){
	
	std::vector<int> v;
	while(broj != 0){
		v.push_back(broj%3);
		broj /= 3;
	}
	
	for(int i(0); i < v.size(); i++){
		if(v.at(i) != v.at(v.size()-1-i))
		return false;
	}
	
	return true;
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> v, bool x){
	
	std::vector<int> t;
	if(x){
		for(int i(0); i < v.size(); i++){
			if(DaLiJeProst(std::abs(v.at(i)))){
			if(PretvorbaUTernarni(v.at(i))){
				
				t.push_back(v.at(i));
			}
		}
		}
	}
	else{
		for(int i(0); i < v.size(); i++){
			if(!DaLiJeProst(std::abs(v.at(i)))){
			if(PretvorbaUTernarni(v.at(i))){
				t.push_back(v.at(i));
			}
		}
		}
	}
	
	for(int i(0); i < t.size(); i++){
		for(int j(i+1); j < t.size(); j++){
			if(t.at(i) == t.at(j)){
			t.erase(t.begin() + j);
			j--;
		}
		}
	}
	
	return t;
}

int main ()
{
	std::vector<int> v;
	int broj;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	do{
		
		std::cin>> broj;
		if(broj == -1)
		break;
		v.push_back(broj);
		
	}while(broj != -1);
	
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	double prost;
	
	for(;;){
		std::cin>>prost;
		if(prost == 1 || prost == 0) break;
		else{
			std::cout<<"Neispravan unos! ";
		std::cout<<"Unesite ponovo: ";
		
		
		}
	}
	std::vector<int> vektor = IzdvojiSimetricneTernarne(v,int(prost));
	if(int(prost)){
		if(vektor.size() != 0){
		std::cout<<"Prosti simetricni brojevi iz vektora su: ";
		for(int i(0); i < vektor.size(); i++){
			if(i == vektor.size()-1)
			std::cout<<vektor.at(i)<<".";
			else
			std::cout<<vektor.at(i)<<", " ;
		}
	}
	else
	std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
	}
	else{
		if(vektor.size() != 0){
		std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
		for(int i(0); i < vektor.size(); i++){
			if(i == vektor.size()-1)
			std::cout <<vektor.at(i)<<".";
			else
			std::cout <<vektor.at(i)<<", ";
		}
		}
		else
		std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
	}
	return 0;
}