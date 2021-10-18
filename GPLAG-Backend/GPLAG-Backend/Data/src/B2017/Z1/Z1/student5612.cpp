#include <iostream>
#include <vector>
#include <cmath>
#include<limits>
#include <cstdlib>

bool DaLiJeProst(int n)
{
	bool prost(true);
	if(n < 0) n = std::abs(n);
	if(n < 2) return false;
	int i(2);
	while(i <= sqrt(double(n))) {
		if(n % i == 0) {
			prost = false;
			break;
		}
		i++;
	}
	return prost;
}

bool TernarySimetric (int broj)
{
	long long int br(broj);
	int cifra;

	std::vector<int> cifre;
	std::vector<int> pomocni;
	
	while(br != 0) {
		cifra = br % 3;
		cifre.push_back(cifra);
		br = br/3;
	}
	
	if(cifre.size() == 0) return false;
	int i(0), j(cifre.size() - 1);
	bool simetric(true);

	while(i != j) {
		if(cifre.at(i) != cifre.at(j)) simetric = false;
		if(i != cifre.size() - 1) i++;
		if(i == j) break;
		if(j != 1) j--;
		}
	
	return simetric;
}

std::vector<int> IzbaciIste (std::vector<int> v1)
{
	for(unsigned int i = 0; i < v1.size(); i++) {
		if(i == v1.size() - 1) break;
		for(unsigned int j = i+1; j < v1.size(); j++) {
			if(v1.at(i) == v1.at(j)) {
			v1.erase(v1.begin() + j);	v
				i--;
				break;
			}

		}
	}
	return v1;
}
std::vector<int> IzdvojiSimetricneTernarne (std::vector<int> v, bool logic)
{
	std::vector<int> novi_vektor;

	if(logic == true) {

		for(int i = 0; i < v.size(); i++) {
			if(DaLiJeProst(v.at(i)) == true && TernarySimetric(v.at(i)) == true) {
				novi_vektor.push_back(v.at(i));
			}
		}
		if(novi_vektor.size() == 0) {
			std::cout << "Nema prostih simetricnih brojeva u vektoru.";
		}
	} else if(logic == false) {
		for(int i = 0; i < v.size(); i++) {
			if(v.at(i)==1){
			}
			else if(DaLiJeProst(v.at(i)) == false && TernarySimetric(v.at(i)) == true) {
				novi_vektor.push_back(v.at(i));
			}
		}
		if(novi_vektor.size() == 0) {
			std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
		}
	}
	novi_vektor = IzbaciIste(novi_vektor);

	return novi_vektor;
}

int main ()
{
	std::vector<int> a;
	int n,l;

	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	do {
		std::cin >> n;
		if(n == -1) break;
		a.push_back(n);

	} while(n != -1);

	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	do {
		std::cin >> l;
		if(l == 1 || l == 0) break;
		else std::cout << "Neispravan unos! Unesite ponovo: ";
	} while(l != 1 || l != 0);

	std::vector<int> b = IzdvojiSimetricneTernarne(a,l);

	if(l == 1 && b.size() != 0) {

		std::cout << "Prosti simetricni brojevi iz vektora su: ";
		for(int i = 0; i < b.size(); i++) {
			if(i != b.size() - 1) std::cout << b.at(i) << ", ";
			else std::cout << b.at(i) << "." ;
		}
	} else if(l == 0 && b.size() != 0) {
		std::cout << "Slozeni simetricni brojevi iz vektora su: ";
		for(int i = 0; i < b.size(); i++) {
			if(i != b.size() - 1) std::cout << b.at(i) << ", ";
			else std::cout << b.at(i) << ".";
		}
	}

	return 0;
}