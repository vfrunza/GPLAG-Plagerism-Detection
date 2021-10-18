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

bool JeLiProst(int a) {
	for (int i=2; i <= sqrt(a); i++) 
		if(!(a%i)) return false;
	return a>=2;
}

int PretvoriUTernarni(int n) {
	std::vector<int> ternarni;
	do {
		int b = n % 3;
		ternarni.push_back(b);
		n /= 3;
	}
	while (n != 0);
	
	int pom{}, br{1};
	for (auto x:ternarni) {
		pom += x*br;
		br *= 10;
	}
	
	return pom;
}

bool JeLiSimetricno(int broj) {
	int br = broj, obrnuti{};
	do {
		int cifra = br % 10;
		obrnuti = obrnuti*10 + cifra;
		br /= 10;
	}
	while(br != 0);
	if (obrnuti == broj) return true;
	return false;
} 

std::vector<int> IzbaciDuple(std::vector<int> v) {
	std::vector<int> pom;
	for (auto a:v) {
		bool nema_duplih = true;
		for (auto b:pom) if (a == b) nema_duplih = false;
		if (nema_duplih) pom.push_back(a);
	}
	return pom;
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> v, bool x) {
	std::vector<int> pom;
	std::vector<int> pom2;
	for (int i=0; i<v.size(); i++) {
		int n = v.at(i);
		if (n < 0) n *= -1;
		
		if (x == true && JeLiProst(n)) {
		    int n2 = PretvoriUTernarni(n);
		    bool simetrican = JeLiSimetricno(n2);
		    if (simetrican) {
		    	pom.push_back(v.at(i));
		    	pom2 = IzbaciDuple(pom);
		    }
		    
		}
		else if (x == false && !JeLiProst(n)) {
			int n2 = PretvoriUTernarni(n);
			bool simetrican = JeLiSimetricno(n2);
			if (simetrican) {
				pom.push_back(v.at(i));
				pom2 = IzbaciDuple(pom);
			}
		}
	}
	return pom2;
}


int main ()
{
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	std::vector<int> v;
	int n{};
	do {
		std::cin>>n;
		if (n == -1) break;
		v.push_back(n);
	}
	while (n != -1);

	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	do {
		std::cin>>n;
		if (n != 0 && n != 1) {
			std::cout<<"Neispravan unos! Unesite ponovo: ";
			continue;
		}
	}
	while(n != 0 && n != 1);
	
	if (n == 1) {
		std::vector<int> v2 = IzdvojiSimetricneTernarne(v, true);
		if (v2.size() == 0) std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
		else {
			std::cout<<"Prosti simetricni brojevi iz vektora su: ";
			for (int i=0; i<v2.size(); i++) {
				if (i != 0) std::cout<<", ";
				std::cout<<v2.at(i);
			}
			std::cout<<".";
		}
	}
	else {
		std::vector<int> v2 = IzdvojiSimetricneTernarne(v, false);
		if (v2.size() == 0) std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		else {
			std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
			for (int i=0; i<v2.size(); i++) {
				if (i != 0) std::cout<<", ";
				std::cout<<v2.at(i);
			}
			std::cout<<".";
		}
	}
	return 0;
}