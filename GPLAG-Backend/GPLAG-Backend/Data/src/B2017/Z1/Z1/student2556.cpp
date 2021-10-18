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
#include <cstdbool>
#include <cmath>
bool DaLiJeTernarnoSimetrican(int broj)
{
	std::vector<int> ternarni;
	bool simetrija=true;
	if(broj<0) broj=abs(broj);
	while(broj!=0) {
		ternarni.push_back(broj%3);
		broj/=3;
	} 
	for(int i=0;i<ternarni.size();i++){
		if(ternarni.at(i)==ternarni.at(ternarni.size()-i-1))
			simetrija=true;
		else if(ternarni.at(i)!=ternarni.at(ternarni.size()-i-1)){
			simetrija=false;
			break;
		}
	}
	if(simetrija) return true;
	return false;
}
std::vector<int> IzdvojiSimetricneTenarne(std::vector<int> v, bool logicka)
{
	std::vector<int> s;
	bool prost = true;
	if(!logicka) {
		for(int i=0; i<v.size(); i++) {
			int pomocna(v.at(i));
			if(pomocna<0) pomocna*=(-1);
			for(int j=2; j<=sqrt(abs(v.at(i))); j++) {
				if(pomocna%j==0)
					prost = false;
			}
			if(!prost && pomocna!=1)
				s.push_back(v.at(i));
			prost = true;
		}
	}
	prost = true;
	if(logicka) {
		for(int i=0; i<v.size(); i++) {
			int pomocna(v.at(i));
			if(pomocna<0) pomocna*=(-1);
			for(int j=2; j<=sqrt(abs(v.at(i))); j++) {
				if(pomocna%j==0)
					prost = false;
			}
			if(prost && pomocna!=1)
				s.push_back(v.at(i));
			prost = true;
		}
	}
	if(s.size()==0) return s;

	std::vector<int> konacni;
	for(int i=0; i<s.size(); i++) {
		if(DaLiJeTernarnoSimetrican(s.at(i)))
			konacni.push_back(s.at(i));
	}
	
	std::vector<int> povratni;
	
	for(int i=0; i<konacni.size(); i++) {
		if(i>0){
			if(konacni.at(i)==konacni.at(i-1))
			continue;
		}
		povratni.push_back(konacni.at(i));
	}

	return povratni;
}

int main ()
{
	std::vector<int> v;
	int broj;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	do {
		std::cin>>broj;
		if(broj!=-1)v.push_back(broj);
	} while(broj!=-1);
	int logicka;
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	do{
		std::cin>>logicka;
		if(logicka!=0 && logicka!=1)
			std::cout<<"Neispravan unos! Unesite ponovo: ";
	}while(logicka!=0 && logicka!=1) ;
	std::vector<int> vektor(IzdvojiSimetricneTenarne(v, logicka));
	if(vektor.size()==0) {
		if(!logicka){
			std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
			return 0;
		}
		if(logicka){
			std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
			return 0;
		}
	} else {
		if(logicka)
			std::cout<<"Prosti simetricni brojevi iz vektora su: ";
		else
			std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
		for(int i=0; i<vektor.size(); i++) {
			if(i<vektor.size()-1)
				std::cout<<vektor.at(i)<<", ";
			else
				std::cout<<vektor.at(i)<<".";
		}
	}

	return 0;
}