#include <iostream>
#include <vector>
#include <cmath>

typedef std::vector<int> vektor;

bool Ponavljanja(vektor v, int x)
{
	if(v.size() == 0) return false;
	for(int i : v) {
		if(i == x) return true;
	}
	return false;
}

bool Dalijesimetrican(long long int x)
{
	vektor v;
	while(x != 0) {
		v.push_back(x%10);
		x = x/10;
	}
	for(int i = 0; i < v.size()/2; i++) {
		if(v.at(i) != v.at(v.size() - i -1)) return false;
	}
	return true;
}

bool Ternarni(int x)
{
	if(x < 0) x *= -1;
	long long int ternarni(0);
	while(x != 0) {
		ternarni = ternarni*10 + x % 3;
		x = x/3;
	}
	if(Dalijesimetrican(ternarni)) return true;
    else return false; 
}

bool DaLiJeProst (long long int n)
{
	bool prost(true);
	if(n < 0) n *= -1;
	int x = sqrt(abs(n));
	for(int i = 2; i <= x; i++) {
		if(n%i == 0) {
			prost = false;
			break;
		}
	}
	return prost;
}


vektor IzdvojiSimetricneTernarne(vektor v, bool t)
{
	vektor konacni;
	if(t) {
		for(int i : v) {
			if(i == 1 || i == 0) continue;
			if(DaLiJeProst(i)) {
				if(Ternarni(i)) {
					if(Ponavljanja(konacni, i) == false) konacni.push_back(i);
				}
			}
		}
	} else {
		for(int i : v) {
			if(i == 1 || i == 0) continue;
			if(DaLiJeProst(i) == false) {
				if(Ternarni(i)) {
					if(Ponavljanja(konacni, i) == false) konacni.push_back(i);
				}
			}
		}
	}
	return konacni;
}

int main () 
{
	vektor v,v2;
	int elem;
	
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	do {
		std::cin >> elem;
		if(elem != -1) v.push_back(elem);
	} while(elem != -1);
	
	int vrsta(0);
	do {
		if(vrsta > -1 && vrsta < 2) {
		std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
			}
		std::cin >> vrsta;
		if(!(vrsta > -1 && vrsta < 2)) {
			std::cout << "Neispravan unos! Unesite ponovo: ";
		}
	} while(!(vrsta > -1 && vrsta < 2));
	
	v2 = IzdvojiSimetricneTernarne(v,vrsta);
	if(v2.size() == 0) {
		if (vrsta) {
			std::cout << "Nema prostih simetricnih brojeva u vektoru.";
			return 1;
		}
		else {
			std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
			return 1;
		}
	}
	if (vrsta) {
			std::cout << "Prosti simetricni brojevi iz vektora su: ";
	}  else {
			std::cout << "Slozeni simetricni brojevi iz vektora su: ";
	}
	for(int i = 0; i< v2.size(); i++) {
		if(i == v2.size() - 1) std::cout << v2.at(i) << ".";
		else std::cout << v2.at(i) << ", ";
	}

	return 0;
}