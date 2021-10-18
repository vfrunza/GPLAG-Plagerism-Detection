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

// Funkcija koja provjerava da li je broj simentrican (palindrom)
bool DaLiJeSimetrican (int n) {
	int pocetni_broj(n), novi_broj(0);
	while (n!=0) {
		int cifra=n%10;
		novi_broj=novi_broj*10+cifra;
		n/=10;
	}
	if (novi_broj==pocetni_broj) return true;
	return false;
}

// Funkcija koja provjerava da li je broj prost
bool DaLiJeProst (int n) {
	bool prost(true);
	for (int i=2; i<=std::sqrt(n); i++) {
		if (n%i==0) {
			prost=false;
			break;
		}
	}
	return prost;
}

// Funkcija koja pretvara broj iz dekadskog u ternarni brojni sistem
int PretvoriUTernarni (int n) {
	int broj(0);
	while (n!=0) {
		int cifra(n%3);
		broj=broj*10+cifra;
		n/=3;
	}
	int broj2(0);
	while (broj!=0) {
		int cifra2(broj%10);
		broj2=broj2*10+cifra2;
		broj/=10;
	}
	return broj2;
}

// Funkcija koja razvrstava elemente u vektore po kriteriju prost/slozen i simetrican
std::vector<int> IzdvojiSimetricneTernarne (std::vector<int>v, bool logic) {
	std::vector<int>prosti;
	std::vector<int>slozeni;
	
	for (int i=0; i<int(v.size()); i++) {
		bool neg(false);
		if ((v.at(i))<0) {
			neg=true;
			(v.at(i))*=(-1);
		}
		if (DaLiJeProst(v.at(i)) && DaLiJeSimetrican(PretvoriUTernarni(v.at(i)))) {
			if (neg) (v.at(i))*=(-1);
			prosti.push_back(v.at(i));
		}
		if (!(DaLiJeProst(v.at(i))) && DaLiJeSimetrican(PretvoriUTernarni(v.at(i)))) {
			if (neg) (v.at(i))*=(-1);
			slozeni.push_back(v.at(i));
		}
	}
	// Izbacivanje elemenata koji se ponavljaju u vektoru prostih simetricnih brojeva
	for (int i=0; i<prosti.size(); i++) {
		for (int j=0; j<prosti.size(); j++) {
			if (prosti.at(i)==prosti.at(j) && i!=j) {
				prosti.erase(prosti.begin()+j);
				j--;
			}
		}
	}
	// Izbacivanje elemenata koji se ponavljaju u vektoru slozenih simetricnih brojeva
	for (int i=0; i<slozeni.size(); i++) {
		for (int j=0; j<slozeni.size(); j++) {
			if (slozeni.at(i)==slozeni.at(j) && i!=j) {
				slozeni.erase(slozeni.begin()+j);
				j--;
			}
		}
	}

	if (logic) return prosti;
	return slozeni;
}

int main () {
	std::vector<int>v;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	int broj;
	do {
		std::cin>>broj;
		if (broj!=(-1)) {
			v.push_back(broj);
		}
		else break;
	} while (broj!=(-1));
	
	
	int ulaz;
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	do {
		std::cin>>ulaz;
		if (ulaz!=0 && ulaz!=1) {
			std::cout<<"Neispravan unos! Unesite ponovo: ";
		}
	} while (ulaz!=0 && ulaz!=1);
	
	
	if (ulaz==1) {
		auto v1(IzdvojiSimetricneTernarne(v,true));
		
		if (v1.size()==0) {
			std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
			return 0;
		}
		std::cout<<"Prosti simetricni brojevi iz vektora su: ";
		for (int i=0; i<v1.size(); i++) {
			if (i==(v1.size()-1)) std::cout<<v1.at(i)<<".";
			else std::cout<<v1.at(i)<<", ";
		}
	}
	
	if (ulaz==0) {
		auto v2(IzdvojiSimetricneTernarne(v,false));
		
		if (v2.size()==0) {
			std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
			return 0;
		}
		std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
		for (int i=0; i<v2.size(); i++) {
			if (i==(v2.size()-1)) std::cout<<v2.at(i)<<".";
			else std::cout<<v2.at(i)<<", ";
		}
	}
	
	return 0;
}