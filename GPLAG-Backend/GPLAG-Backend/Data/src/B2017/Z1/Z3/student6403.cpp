/*B 2017/2018, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <deque>
#include <vector>

enum Smjer { Rastuci, Opadajuci };

bool JelStepenDvojke (int n) {
	if (n == 0) return false;
	return (n & (n - 1)) == 0;
}

std::deque<std::vector<int>> Rastuci_pom(std::vector<int> V) {
	
	if (V.size() == 0) return std::deque<std::vector<int>> {};
	int Duzina = 1;
	
	std::deque<std::vector<int>> Vrati;
	
	for (int i = 0; i < V.size() - 1; i++) {
		
		if (V.at(i) <= V.at(i + 1) && JelStepenDvojke(V.at(i)) && JelStepenDvojke(V.at(i + 1))) {
			Duzina++;
			if (i == V.size() - 2 && Duzina > 1) {
				std::vector<int> V1;
				for (int j = i - Duzina + 2; Duzina > 0; Duzina--, j++) {
					V1.push_back(V.at(j));
				}
				Vrati.push_back(V1);
			}
		}
			else {
				if (Duzina > 1) {
					std::vector<int> V1;
					for (int j = i - Duzina + 1; Duzina > 0; Duzina--, j++) {
						V1.push_back(V.at(j));
					}
					Vrati.push_back(V1);
				}
				Duzina = 1;
			}
		}
			return Vrati;
}

std::deque<std::vector<int>> Opadajuci_pom(std::vector<int> V) {
	
	if (V.size() == 0) return std::deque<std::vector<int>>{};
	int Duzina = 1;
	
	std::deque<std::vector<int>> Vrati;
	
	for (int i = 0; i < V.size() - 1; i++) {
		
		if (V.at(i) >= V.at(i + 1) && JelStepenDvojke(V.at(i)) && JelStepenDvojke(V.at(i + 1))) {
			Duzina++;
			if (i == V.size() - 2 && Duzina > 1) {
				std::vector<int> V1;
				for (int j = i - Duzina + 2; Duzina > 0; Duzina--,j++) {
					V1.push_back(V.at(j));
				}
				Vrati.push_back(V1);
			}
		}
		else {
			if (Duzina > 1) {
				std::vector<int> V1;
				for (int j = i - Duzina + 1; Duzina > 0; Duzina--, j++) {
					V1.push_back(V.at(j));
				   }
					Vrati.push_back(V1);
				}
				Duzina = 1;
			}
		}
		return Vrati;
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke (std::vector<int> V1, Smjer Direction) {
	
	if (Direction == Smjer::Rastuci) return Rastuci_pom(V1);
	return Opadajuci_pom(V1);
}

int main ()
{
	std::vector<int> V;
	int n,element,a;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	std::cout << "Unesite elemente vektora: ";
	
	for(int i = 0; i < n; i++) {
		std::cin >> element;
		V.push_back(element);
	}
	
	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin >> a;
		while(a != 1 && a != 2){
		std::cout << "Neispravan unos! Unesite ponovo: ";
		std::cin >> a;
	}
		
	try {
		
		if (a == 1) {
			auto x = MaksimalniPodnizoviStepenaDvojke(V, Smjer::Rastuci);
			
			std::cout << "Maksimalni rastuci podnizovi:\n";
			for (auto i : x) {
			for (auto j : i) {
				std::cout << j << " ";
			}
			std::cout << std::endl;
		}
		}
		else{
			auto x = MaksimalniPodnizoviStepenaDvojke(V, Smjer::Opadajuci);
			
			std::cout << "Maksimalni opadajuci podnizovi:\n";
			for (auto i : x) {
			for (auto j : i) {
				std::cout << j << " ";
			}
			std::cout << std::endl;
		}
	} 
	
	}
	catch(...) {
		std::cout << "Izuzetak!";
	}
	return 0;
}