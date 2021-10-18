#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <algorithm>


// Provjerava da li je element prost
bool DaLiJeProst (int n) {
	if (n == 0) return false;
	for (int i = 2; i < n; i++) if (n % i == 0) return false;
	return true;
}


// Provjerava simetricnost
bool Simetricna (std::vector <int> v1) {
	std::vector <int> v2;
	std::vector <int> v3;
	
	v2 = v1;
	v3 = v1;
	
	  std::reverse (v3.begin(), v3.end());
	
	int n = v1.size();
	
	for (int i = 0; i < n; i++) 
		if (v2.at(i) != v3.at(i)) return false;
	
	return true;
}


// Pretvara element u ternarni sistem
std::vector <int> TurnToTernarni (int n) {
	std::vector <int> temp;

	int x (n);
	
	while (x != 0) {
		int cifra = x % 3;
		temp.push_back (cifra);
		x = x / 3;
	}
	
	return temp;
}



// Glavna funkcija
std::vector <int> IzdvojiSimetricneTernarne (std::vector <int> vektor, bool prost) {
	std::vector <int> Novi;
	int prostih (0);
	int slozenih (0);
	std::vector <int> Nema (0);

	
	if (prost == true) {
		for (int i = 0; i < vektor.size(); i++)
			if (DaLiJeProst (vektor.at(i)) == true) {
				prostih ++;
				std::vector <int> uternarnom = TurnToTernarni (vektor.at(i));
				if (Simetricna (uternarnom) == true) Novi.push_back (vektor.at(i));
			}
		if (prostih == 0) {
			//std::cout << "Nema prostih simetricnih brojeva u vektoru.";
			return Nema;
		}
	
	} else {
		for (int i = 0; i < vektor.size(); i++)
			if (DaLiJeProst (vektor.at(i)) == false) {
				slozenih ++;
				std::vector <int> uternarnom = TurnToTernarni (vektor.at(i));
				if (Simetricna (uternarnom) == true) Novi.push_back (vektor.at(i));
			}
		if (slozenih == 0) {
		//	std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
			return Nema;
		}
	}	
		
	
	if (slozenih == 0 && prostih > 1 || prostih == 0 && slozenih > 1)	
	for (int i = 0; i < Novi.size(); i++) {
		for (int j = i + 1; j < Novi.size(); j++) {
			if (Novi.at(i) == Novi.at(j)) {
				Novi.erase(Novi.begin() + j);
				i--;
			}
		}
	}
	
	return Novi;
}



int main () {
	std::vector <int> PocetniVektor;
	bool provjera;
	int b;
	int a;
	
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	
	
	// Unos brojeva
	for (int i = 0; ; i++) {
		std::cin >> b;
		if (b == -1) break;
		while (!std::cin) {
			std::cout << "Neispravan unos";
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
		PocetniVektor.push_back(b);
	}
	
	if (PocetniVektor.size() == 0) {
		std::cout << "Niste unijeli brojeve";
		return 1;
	}
	
	
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	std::cin >> a;
	
	
	while (a != 1 && a != 0) {
		std::cout << "Neispravan unos! Unesite ponovo: ";
		std::cin >> a;
	}
	if (a == 1) provjera = true;
	if (a == 0) provjera = false;

	
	
	std::vector <int> Rezultat = IzdvojiSimetricneTernarne (PocetniVektor, provjera);
	
	if (Rezultat.size() == 0 && a == 1) std::cout << "Nema prostih simetricnih brojeva u vektoru.";
	if (Rezultat.size() == 0 && a == 0) std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
	
	if (a == 1 && Rezultat.size() != 0) std::cout << "Prosti simetricni brojevi iz vektora su: ";
	if (a == 0 && Rezultat.size() != 0) std::cout << "Slozeni simetricni brojevi iz vektora su: ";
	
	// Ispis
	if (Rezultat.size() != 0) {
		for (int i = 0; i < Rezultat.size(); i++) {
			std::cout << Rezultat.at(i);
			if (i != Rezultat.size() - 1) std::cout << ", ";
			else std::cout << ".";
		}
	}
	
	return 0;
}