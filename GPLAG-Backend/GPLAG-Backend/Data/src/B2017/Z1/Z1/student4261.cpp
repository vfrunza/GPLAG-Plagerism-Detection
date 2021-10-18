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

bool Prost (int n) {
	if (n<2) return false;
	for (int i=2; i<=std::sqrt(n); i++) {
		if (n%i==0) return false;
	}
	return true;
}

bool Simetrican (unsigned long long int n) {
	unsigned long long int temp(n), br_cifara(0);
	do {
		br_cifara++;
		temp/=10;
	} while (temp!=0);
	
	unsigned long long int prvi(0), pola(br_cifara/2);
	
	for (int i=0; i<pola; i++) {
		prvi=prvi*10+n%10;
		n/=10;
	}
	if (br_cifara%2!=0) n/=10;
	
	unsigned long long int drugi(n);
	if (prvi==drugi) return true;
	return false;
}

unsigned long long int Ternarni (int n) {
	unsigned long long int x(0), i(1), ostatak;
	do {
		ostatak=n%3;
		x+=ostatak*i;
		n/=3;
		i*=10;
	} while (n!=0);
	return x;
}

std::vector<int> IzbaciDuple (std::vector<int> v) {
	for (int i=0; i<v.size(); i++) {
		if (v.at(i)==1) {
			v.erase(v.begin()+i);
			i--;
		}
		else {
			for (int j=i+1; j<v.size(); j++) {
				if (v.at(i)==v.at(j)) {
					v.erase(v.begin()+j);
					j--;
				}
			}
		}
	}
	return v;
}

std::vector<int> IzdvojiSimetricneTernarne (std::vector<int> v, bool izbor) {
	std::vector<int> c;
	v=IzbaciDuple(v);
	if (izbor) {
		for (int x: v) if (Prost(std::abs(x)) && Simetrican(Ternarni(std::abs(x)))) c.push_back(x);
	}
	else {
		for (int x: v) if (!Prost(std::abs(x)) && Simetrican(Ternarni(std::abs(x)))) c.push_back(x);
	}

	return c;
}

int main ()
{
	std::vector<int> v;
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	
	int n;
	do {
		std::cin >> n;
		if (n!=-1) v.push_back(n);
	} while (n!=-1);
	
	int izbor_broj;
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	do {
		std::cin >> izbor_broj;
		if (izbor_broj>1 || izbor_broj<0) std::cout << "Neispravan unos! Unesite ponovo: ";
	} while (izbor_broj>1 || izbor_broj<0);
	
	bool izbor(izbor_broj);
	
	std::vector<int> izdvojeni(IzdvojiSimetricneTernarne(v, izbor));
	
	if (izbor) {
		if (izdvojeni.size()==0) std::cout << "Nema prostih simetricnih brojeva u vektoru.";
		else {
			std::cout << "Prosti simetricni brojevi iz vektora su: ";
			for (int i=0; i<izdvojeni.size(); i++) {
				std::cout << izdvojeni.at(i);
				if (i<izdvojeni.size()-1) std::cout << ", ";
				else std::cout << ".";
			}
		}
	}
	else {
		if (izdvojeni.size()==0) std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
		else {
			std::cout << "Slozeni simetricni brojevi iz vektora su: ";
			for (int i=0; i<izdvojeni.size(); i++) {
				std::cout << izdvojeni.at(i);
				if (i<izdvojeni.size()-1) std::cout << ", ";
				else std::cout << ".";
			}
		}
	}
	
	return 0;
}