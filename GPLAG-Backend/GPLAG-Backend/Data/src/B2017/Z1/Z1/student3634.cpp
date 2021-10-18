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
	for(int i=2; i<n; i++) {
		if(n%i==0) return false;
	}
	return true;
}

bool DaLiJeSimetrican(int n) {
	int eksponent(0), broj(0);
	do{
		int cifra(n%3);
		broj+=cifra*std::pow(10, eksponent);
		eksponent++;
		n/=3;
	}while(n!=0);
	int broj1=broj, izvrnut(0);
	eksponent--;
	do{
		int cifra1(broj1%10);
		izvrnut+=cifra1*std::pow(10, eksponent);
		eksponent--;
		broj1/=10;
	}while(broj1!=0);
	if(broj==izvrnut) return true;
	return false;
}

std::vector<int>IzdvojiSimetricneTernarne(std::vector<int>v, bool p) {
	std::vector<int>v1;
	for(int i=0; i<v.size(); i++) {
		if (p==true && DaLiJeProst(v.at(i)) && DaLiJeSimetrican(v.at(i))) v1.push_back(v.at(i));
		if (p==false && !(DaLiJeProst(v.at(i))) && DaLiJeSimetrican(v.at(i))) v1.push_back(v.at(i)); 
	}
	return v1;
}

int main ()
{	
	int n;
	std::vector<int>v;
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	for(;;) {
		std::cin >> n;
		if(n==-1) break;
		v.push_back(n);
	}
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int p;
	for(;;) {
		std::cin >> p;
		if(p==0 || p==1) break;
		std::cout << "Neispravan unos! Unesite ponovo: ";
	}
	std::vector<int>v1;
	if(p==1) {
		v1=IzdvojiSimetricneTernarne(v, 1);
		if(v1.size()==0) { std::cout << "Nema prostih simetricnih brojeva u vektoru."; return 0; }
		std::cout << "Prosti simetricni brojevi iz vektora su: ";
		for(int i=0; i<v1.size(); i++) {
			if(i<v1.size()-1) std::cout << v1.at(i) << ", ";
			if(i==v1.size()-1) std::cout << v1.at(i) << ".";
		}
	}
	if(p==0) {
		v1=IzdvojiSimetricneTernarne(v, 0);
		if(v1.size()==0) { std::cout << "Nema slozenih simetricnih brojeva u vektoru."; return 0; }
		std::cout << "Slozeni simetricni brojevi iz vektora su: ";
		for(int i=0; i<v1.size(); i++) {
			if(i<v1.size()-1) std::cout << v1.at(i) << ", ";
			if(i==v1.size()-1) std::cout << v1.at(i) << ".";
		}
	}
	return 0;
}