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

bool DaLiJeProst (int n) {
	if (n<0) n*=(-1);
	for (int i=2; i<n; i++) if (n%i==0) return false;
	return true;
}

int PretvoriUTernarni (int n) {
	if (n<0) n*=(-1);
	int suma(0),k(1);
	while(n>=3) {
		int cifra(n%3);
		suma = suma + cifra*k;
		n/=3;
		k*=10;
	}
	suma = suma + n*k;
	return suma;
}

bool DaLiJeSimetrican (int n) {
	if (n<0) n*=(-1);
	int suma(0),m(n);
	while(m!=0) {
		int cifra(m%10);
		suma = suma*10 + cifra;
		m/=10;
	}
	if (suma==n) return true;
	return false;
}

bool DaLiVecPostoji (std::vector<int> v, int n) {
	for (int i=0; i<v.size(); i++) if (v.at(i)==n) return true;
	return false;
}

std::vector<int> IzdvojiSimetricneTernarne (std::vector<int> v, bool a) {
	std::vector<int> v1;
	for (int i=0; i<v.size(); i++) {
		int x(PretvoriUTernarni(v.at(i)));
		if (a==true && DaLiJeProst(v.at(i))==true && DaLiJeSimetrican(x)==true && DaLiVecPostoji(v1,v.at(i))==false) v1.push_back(v.at(i));
		if (a==false && DaLiJeProst(v.at(i))==false && DaLiJeSimetrican(x)==true && DaLiVecPostoji(v1,v.at(i))==false) v1.push_back(v.at(i));
	}
	return v1;
}

int main ()
{
	int n;
	std::vector<int> v;
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	do {
		std::cin >> n;
		if (n!=-1) v.push_back(n);
	}while (n!=-1);
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int b;
	do {
		std::cin >> b;
		if (b!=0 && b!=1) std::cout << "Neispravan unos! Unesite ponovo: ";
	}while(b!=0 && b!=1);
	bool a(b);
	std::vector<int> v1;
	v1=IzdvojiSimetricneTernarne(v,a);
	if (a==true) {
		if (v1.size()==0) {
			std::cout << "Nema prostih simetricnih brojeva u vektoru.";
			return 0;
		}
		std::cout << "Prosti simetricni brojevi iz vektora su: ";
		for (int i=0; i<v1.size(); i++) {
			if (i!=v1.size()-1) std::cout << v1.at(i) << ", ";
			else std::cout << v1.at(i) << ".";
		}
	}
	if (a== false) {
		if (v1.size()==0) {
			std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
			return 0;
		}
		std::cout << "Slozeni simetricni brojevi iz vektora su: ";
		for (int i=0; i<v1.size(); i++) {
			if (i!=v1.size()-1) std::cout << v1.at(i) << ", ";
			else std::cout << v1.at(i) << ".";
		}
	}
	return 0;
}