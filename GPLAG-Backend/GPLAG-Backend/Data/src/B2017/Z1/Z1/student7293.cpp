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

std::vector<int> IzdvojiDuple (std::vector<int> v) {
	std::vector<int> novi;
	std::vector<bool> dupli(v.size(), false);
	for (int i=0; i<v.size(); i++) {
		for (int j=i+1; j<v.size(); j++) {
			if (v.at(i)==v.at(j)) dupli.at(j)=true;
		}
	}
	for (int i=0; i<dupli.size(); i++) {
		if (dupli.at(i)==false) novi.push_back(v.at(i));
	}
	return novi;
}

bool DaLiJeProst (int n) {														// ispituje da li je broj prost
	n = fabs(n);
	for (int i=2; i<=std::sqrt(n); i++) {
		if (n%i==0) return false;
	}
	return true;
}

std::vector<int> Ternarni (int n) {												// ternarni zapis broja; cifre smjestene u vektor
	std::vector<int> t;
	int cifra(0);
	n = fabs(n);
	while (n!=0) {
		cifra = n%3;
		t.push_back(cifra);
		n = n/3;
	}
	return t;
}

std::vector<int> Simetricni (std::vector<int> v) {								// vraca vektor simetricnih brojeva
	std::vector<int> sim;
	
	for (int i=0; i<v.size(); i++) {
		std::vector<int> temp = Ternarni(v.at(i));
		
		int j(0), br(0);
		int k = temp.size()-1;
		while (j<temp.size() && k>=0) {											// ispituje simetricnost
			
			if (temp.at(j)==temp.at(k)) {
				br++;
				j++;
				k--;
			}
			else break;
		}
		if (br==temp.size()) sim.push_back(v.at(i));
		
	}
	
	return sim;
}

std::vector<int> IzdvojiSimetricneTernarne (std::vector<int> v, bool k) {
	std::vector<int> prosti, slozeni;											// TRUE za PROSTE
	
	for (int i=0; i<v.size(); i++) {
		if (DaLiJeProst(v.at(i))) prosti.push_back(v.at(i));
		else slozeni.push_back(v.at(i));
	}
	
	if (k) return Simetricni(prosti);
	return Simetricni(slozeni);
}

int main ()
{
	int element(0);
	std::vector<int> vektor;
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	for (;;) {
		std::cin >> element;
		if (element==-1) break;
		vektor.push_back(element);
	}														
	
	std::vector<int> v = IzdvojiDuple(vektor);
	
	int x(0);
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	std::cin >> x;
	while (x!=0 && x!=1) {
		std::cout << "Neispravan unos! Unesite ponovo: ";
		std::cin >> x;
	}
	
	if (x==0) {
		std::vector<int> rez = IzdvojiSimetricneTernarne(v, false);
		if (rez.size()==0) {
			std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
			return 0;
		}
		std::cout << "Slozeni simetricni brojevi iz vektora su: ";
		for (int i=0; i<rez.size(); i++) {
			if (i!=rez.size()-1) std::cout << rez.at(i) << ", ";
			else std::cout << rez.at(i) << ".";
		}
	}
	else if (x==1) {
		std::vector<int> rez = IzdvojiSimetricneTernarne(v, true);
		if (rez.size()==0) {
			std::cout << "Nema prostih simetricnih brojeva u vektoru.";
			return 0;
		}
		std::cout << "Prosti simetricni brojevi iz vektora su: ";
		for (int i=0; i<rez.size(); i++) {
			if (i!=rez.size()-1) std::cout << rez.at(i) << ", ";
			else std::cout << rez.at(i) << ".";
		}
	}
	else std::cout << "Niste unijeli 0 ili 1!";
	return 0;
}