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

bool DaLiJeProst (int n){
	
	if (n<0 || n==1) return false;
	for (int i=2; i<=int(std::sqrt(n)); i++){
		if (n%i==0) return false;
	}

	
return true;
}

std::vector<int> VratiTernarni (int broj){
	std::vector<int>vrati;
	while (broj!=0){
		vrati.push_back(broj%3);
		broj/=3;
	}
	return vrati;
}

bool JelSimetrican (std::vector<int> v){
	int i;
	for ( i=0; i<v.size(); i++){
		int vel=v.size();
		if (v.at(i)!= v.at(vel-i-1)) return false;
	}
	return true;
}

std::vector<int> IzdvojiSimetricneTernarne (std::vector<int> v, bool vrijednost){
	std::vector<int> prosti;
	std::vector<int> vratiProste;
	std::vector<int> slozeni;
	std::vector<int> vratiSlozene;
	if (vrijednost==true){
		
		for (int i=0; i<v.size(); i++){
			if (DaLiJeProst(v.at(i))) prosti.push_back(v.at(i));
		}
		
		for (int i=0; i<prosti.size(); i++){
			if (JelSimetrican(VratiTernarni(prosti.at(i)))) 
			vratiProste.push_back(prosti.at(i));
		}
		return vratiProste;
	}
	
	else if (vrijednost==false){
		for (int i=0; i<v.size(); i++){
			if (!(DaLiJeProst(v.at(i)))) slozeni.push_back(v.at(i));
			
		}
		for (int i=0; i<slozeni.size(); i++){
			if (JelSimetrican(VratiTernarni(slozeni.at(i))))
			vratiSlozene.push_back(slozeni.at(i));
		}
		return vratiSlozene;
	}
	
	return prosti;
}

int main ()
{
	std::vector<int>v;
	
	int element;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	do{
		std::cin>>element;
		if (element==-1) break;
		else v.push_back(element);
	}while (element!=-1);
	
	
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int opcija;

while (std::cin>>opcija){
	if (opcija == 0 || opcija == 1) break;
	else std::cout<<"Neispravan unos! Unesite ponovo: ";
}
	
	std::vector<int> vraceni= IzdvojiSimetricneTernarne(v, opcija);
	
	
	
	if (opcija==1){
		if (vraceni.size()==0)
			std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
		else
		std::cout<<"Prosti simetricni brojevi iz vektora su: ";
	}
	
	if (opcija==0){
		if (vraceni.size()==0)
			std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		else
		std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
	}
	for (int i=0; i<vraceni.size(); i++){
		if(i!=vraceni.size()-1) std::cout<<vraceni.at(i)<<", ";
		else std::cout<<vraceni.at(i)<<".";
	}
	
	return 0;
}