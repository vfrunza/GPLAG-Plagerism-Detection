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

std::vector<int> IzdvojiSimetricneTernarne (std::vector<int> pocetni, bool valid)
{
	std::vector<int> prosti;
	std::vector<int> slozeni;
	
	for(int i(0); i<pocetni.size(); i++) {				// prolazak kroz pocetni vektor
		int num = std::abs(pocetni.at(i));
		bool prost = true;
		for(int j(2); j<num; j++) {			// petlja koja provjerava da li je broj prost ili slozen
			if (num % j == 0) {
				prost = false;
				break;
			}
		}
		std::vector<int> pomocni;
		do {
			pomocni.push_back(num%3);
			num/=3;
		} while(num);
		unsigned long long ternarni = 0, ternarniNaopako = 0;
		for(int k(pomocni.size()-1); k >= 0; k--) {          // (*) petlja
			ternarni += pomocni.at(k)*(std::pow(10, k));
			ternarniNaopako += pomocni.at(k)*(std::pow(10, pomocni.size()-1-k));
		}
		if(prost && ternarni == ternarniNaopako)
			prosti.push_back(pocetni.at(i));
		else if (!prost && pocetni.at(i) != 1 && pocetni.at(i) != -1 && ternarni == ternarniNaopako)
			slozeni.push_back(pocetni.at(i));
	}
	if(valid) {
		return prosti;
	} else {
		return slozeni;
	}
}

int main ()
{
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	int broj;
	std::vector<int> vektor;
	do {
		std::cin >> broj;
		if(broj != -1) vektor.push_back(broj);
	} while(broj != -1);
	int valid;
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	std::cin >> valid;
	while(valid!=1 && valid!=0) {
		std::cout << "Neispravan unos! Unesite ponovo: ";
		std::cin >> valid;
	}
	vektor = IzdvojiSimetricneTernarne(vektor, bool(valid));
	if(valid) {														//ako je true, onda su prosti brojevi
		if(vektor.size()==0) std::cout << "Nema prostih simetricnih brojeva u vektoru.";      // ako je vektor prazan nema prostih simetricnih
		else {
			std::cout << "Prosti simetricni brojevi iz vektora su: ";
			for(int i(0); i<vektor.size(); i++) {
				if(i == vektor.size()-1)
					std::cout << vektor.at(i) << ".";
				else
					std::cout << vektor.at(i) << ", ";
			}
		}
	} else {
		if(vektor.size()==0) std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
		else {
			std::cout << "Slozeni simetricni brojevi iz vektora su: ";
			for(int i(0); i<vektor.size(); i++) {
				if(i == vektor.size()-1)
					std::cout << vektor.at(i) << ".";
				else
					std::cout << vektor.at(i) << ", ";
			}
		}
	}
	return 0;
}