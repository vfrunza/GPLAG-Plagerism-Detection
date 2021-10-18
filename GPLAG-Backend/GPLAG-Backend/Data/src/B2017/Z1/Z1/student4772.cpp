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

bool prost (int broj) {
	if(broj<0) broj*=-1;
	else if (broj<=1) return false;
	
	for (int i=2; i<broj; i++) {
		if(broj%i==0) return false;
	}
	
	return true;
}

bool simetrican (int broj) {
	int ternarni(0), brojac(1);
	while (broj!=0) {
		ternarni+=(broj%3)*brojac;
		brojac*=10;
		broj/=3;
	}
	
	int pomocni(ternarni), brojcifara(0);
	while (ternarni!=0) {
		ternarni/=10;
		brojcifara++;
	}
	ternarni=pomocni;
	int obrnut(0);
	while (ternarni!=0) {
		obrnut+=(ternarni%10)*pow(10, brojcifara-1);
		ternarni/=10;
		brojcifara--;
	}
	return (obrnut==pomocni);
}

std::vector<int> IzdvojiSimetricneTernarne (std::vector<int> vektor, bool opcija) {
	std::vector<int>novi_vektor;
	bool ponavljase(false);
	if (opcija) {
		for (int i=0; i<int (vektor.size()); i++) {
			ponavljase=false;
			if (prost(vektor.at(i)) && simetrican(vektor.at(i))) {
				for (int j=0; j<int(novi_vektor.size()); j++) {
					if(vektor.at(i)==novi_vektor.at(j)) {
						ponavljase=true;
						break;
					}
				}
				if(ponavljase==false) novi_vektor.push_back(vektor.at(i));
			}
		}
	} else {
		for (int i=0; i<int (vektor.size()); i++) {
			ponavljase=false;
			if (!prost(vektor.at(i)) && simetrican(vektor.at(i))) {
				for (int j=0; j<int(novi_vektor.size()); j++) {
					if(vektor.at(i)==novi_vektor.at(j)) {
						ponavljase=true;
						break;
					}
				}
				if (ponavljase==false) novi_vektor.push_back(vektor.at(i));
			}
		}
	}
	
	return novi_vektor;
}


int main ()
{
	
	std::vector<int> vektor;
	std::cout << "Unesite elemente vektora (-1 za kraj): " ;
	int broj;
	do {
		std::cin >> broj;
		if (broj!=-1) vektor.push_back(broj);
	} while (broj!=-1);
	
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: " ;
	int opcija;
	do {
		std::cin >> opcija;
		if (opcija!=1 && opcija!=0) std::cout << "Neispravan unos! Unesite ponovo: " ;
	} while (opcija!=1 && opcija!=0);
	
	
	if(opcija) {
		if(IzdvojiSimetricneTernarne(vektor, opcija).size()==0) std::cout << "Nema prostih simetricnih brojeva u vektoru.";
		else {
			std::cout << "Prosti simetricni brojevi iz vektora su: ";
			for (int i=0; i<int(IzdvojiSimetricneTernarne(vektor, opcija).size()); i++) {
				if (i==int (IzdvojiSimetricneTernarne(vektor, opcija).size()) - 1) std::cout << IzdvojiSimetricneTernarne(vektor, opcija).at(i) << ".";
				else std::cout << IzdvojiSimetricneTernarne(vektor, opcija).at(i) << ", ";
			}
		}
	} else {
		if(IzdvojiSimetricneTernarne(vektor, opcija).size()==0) std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
		else {
			std::cout << "Slozeni simetricni brojevi iz vektora su: ";
			for (int i=0; i<int(IzdvojiSimetricneTernarne(vektor, opcija).size()); i++) {
				if (i==int (IzdvojiSimetricneTernarne(vektor, opcija).size()) - 1) std::cout << IzdvojiSimetricneTernarne(vektor, opcija).at(i) << ".";
				else std::cout << IzdvojiSimetricneTernarne(vektor, opcija).at(i) << ", ";
			}
		}
	}
	
	return 0;
}