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
#include <limits>

using std::vector;

bool DaLiJeProst(int n) {
	
	if(abs(n)<=1)
		return false;
	for(int i=2;i<=sqrt(abs((long long int)(n)));i++) {
		if(n%i==0) 
			return false;
	}
	return true;
}

bool TernarnoSimetrican(int broj) {
	vector<int> cifreTernarnog;
	while(broj!=0) {
		cifreTernarnog.push_back(abs(broj%3));
		broj/=3;
	}
	int duzina = cifreTernarnog.size(); // Zbog preglednosti
	for(int i=0;i<duzina/2 ; i++){
		if(cifreTernarnog.at(i) != cifreTernarnog.at(duzina-1-i))
			return false;
	}
	return true;
}

vector<int> IzdvojiSimetricneTernarne(vector<int> numbers,bool check) {
	vector<int> finalVector;
	if(check) { // Ako je check "true" onda izdvajamo proste brojeve
		for(int x : numbers) 
			if(DaLiJeProst(x) && TernarnoSimetrican(x)) 
				finalVector.push_back(x);
	}
	else {  // Izdvajamo slozene brojeve
		for(int x : numbers) 
			if(!(DaLiJeProst(x)) && TernarnoSimetrican(x) && abs(x)!=1 )
				finalVector.push_back(x);
	}
	return finalVector;
}


int main ()
{
	vector<int> brojevi;
	int a;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	while(true) {
		std::cin>>a;
        if(a==-1)
			break;
		brojevi.push_back(a);
	}
	int unos;
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	while(true) {
		std::cin>>unos;
		if(!(std::cin)) {
			std::cout<<"Neispravan unos! Unesite ponovo: ";
			std::cin.clear();
            std::cin.ignore(10000,'\n');
		}
		else if(unos != 0 && unos!= 1)
			std::cout<<"Neispravan unos! Unesite ponovo: ";
		else 
			break;
	}
	
	
	vector<int> rezultatObrade = IzdvojiSimetricneTernarne(brojevi,unos);
	std::cout<<"ima ih: "<<rezultatObrade.size()<<"\n";
	
	if(rezultatObrade.size() > 0) {
		// Izbacivanje duplikata
		for(int i=0;i<rezultatObrade.size();i++) {
			for(int j=i+1;j<rezultatObrade.size();j++) {
				if (rezultatObrade.at(j) == rezultatObrade.at(i)) {
					rezultatObrade.erase(rezultatObrade.begin() + j);
					j--;
				}
			}
		}
		if(unos==1)
			std::cout<<"Prosti simetricni brojevi iz vektora su: ";
		else if(unos==0)
			std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
		for(int i=0;i<rezultatObrade.size();i++) {
			if(i==rezultatObrade.size()-1)
				std::cout<<rezultatObrade.at(i)<<".";
			else
				std::cout<<rezultatObrade.at(i)<<", ";
		}
	}
	else {
	    if(unos==1)
			std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
		else 
			std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
	}
	return 0;
}