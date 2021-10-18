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

bool DaLiJeProst(int n) {
	n = abs(n);
	if(n < 2) return false;
	for(int i(2); i<=sqrt(n); i++) {
		if(n%i == 0) return false;
	}
	return true;
}

std::vector<int> ternarni(int n) {
	std::vector<int> tern;
	n = abs(n);
	while(n != 0) {
		int k(n%3);
		tern.push_back(k);
		n/=3;
	}
	return tern;
}

bool DaLiJeSimetrican(std::vector<int> ter) {
	std::vector<int> ter2;
	for(int i(ter.size() - 1); i>=0; i--) {
		ter2.push_back(ter.at(i));
	}
	
	if(ter2 == ter) return true;
	else if(ter2 != ter) return false;
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> a, bool tip) {
	std::vector<int> v;
	std::vector<int> vrati;
	if(tip == true) {
		for(int i(0); i<a.size(); i++) {
			if(DaLiJeProst(a.at(i))) v.push_back(a.at(i));
		}
		for(int i(0); i<v.size(); i++) {
			std::vector<int> ter;
			ter = ternarni(v.at(i));
			if(DaLiJeSimetrican(ter)) vrati.push_back(v.at(i));
		}
		if(vrati.size() == 0) std::cout << "Nema prostih simetricnih brojeva u vektoru.";
		else if(vrati.size() != 0) {
			std::cout << "Prosti simetricni brojevi iz vektora su: ";
			for(int i(0); i<vrati.size(); i++) {
				if(i < (vrati.size() - 1)) std::cout << vrati.at(i) << ", ";
				else if(i == (vrati.size() - 1)) std::cout << vrati.at(i) << ".";
			}
		}
	}
	else if(tip == false) {
		for(int i(0); i<a.size(); i++) {
			if(!DaLiJeProst(a.at(i))) v.push_back(a.at(i));
		}
		for(int i(0); i<v.size(); i++) {
			std::vector<int> ter(ternarni(v.at(i)));
			if(DaLiJeSimetrican(ter)) vrati.push_back(v.at(i));
		}
		if(vrati.size() == 0) std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
		else if(vrati.size() > 0) {
			std::cout << "Slozeni simetricni brojevi iz vektora su: ";
			for(int i(0); i<vrati.size(); i++) {
				if(i != (vrati.size() - 1)) std::cout << vrati.at(i) << ", ";
				else if(i == (vrati.size() - 1)) std::cout << vrati.at(i) << ".";
			}
		}
	}
	return vrati;
}


int main () {
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	std::vector<int> vektor;
	int n;
	while(std::cin >> n, n!= -1) {
		vektor.push_back(n);
	}
	
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int sklj;
	while(std::cin >> sklj && (sklj != 1 || sklj != 0)) {
		if(sklj == 1 || sklj == 0) break;
		std::cout << "Neispravan unos! Unesite ponovo: ";
	}
	
	bool tip1;
	if(sklj == 1) tip1 = true;
	else if(sklj == 0) tip1 = false;
	
	IzdvojiSimetricneTernarne(vektor, tip1);
	
	return 0;
}