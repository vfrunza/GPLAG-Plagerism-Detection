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
#include <deque>

bool DaLiJeBrojProst(int x) {
	x=abs(x);
	if (x==0 || x==1) return false;
	else {
		for (int i=2; i<x; i++) {
			if (x%i==0) return false;
		}
	}
	return true;
}

std::vector<int> IzbaciDuplikate(std::vector<int> vektor) {
	std::vector<int> bez_duplikata{};
	bool pronadjen=false;
	for (int i=0; i<vektor.size(); i++) {
		for (int j=0; j<bez_duplikata.size(); j++) 
			if (vektor.at(i)==bez_duplikata.at(j)) {pronadjen=true; break;}
		if (!pronadjen) bez_duplikata.push_back(vektor.at(i));
		pronadjen=false;
	}
	return bez_duplikata;
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> vektor, bool tacnost) {
	std::vector<int> rezultat;
	int tmp, brojac; bool valjanost;
	vektor=IzbaciDuplikate(vektor);
	for (int i=0; i<vektor.size(); i++) {
		if (tacnost) {
			if (DaLiJeBrojProst(vektor.at(i))) {
				tmp=abs(vektor.at(i));
				std::deque<int> ternarna_reprezentacija;
				while(tmp!=0) {
					ternarna_reprezentacija.push_front(tmp%3);
					tmp/=3;
				}
				brojac=ternarna_reprezentacija.size()-1;
				valjanost=true;
				for (int j=0; j<ternarna_reprezentacija.size()/2; j++) {
					if(ternarna_reprezentacija.at(j)!=ternarna_reprezentacija.at(brojac)) { valjanost=false; break; }
					brojac--;
				}
				if (valjanost) rezultat.push_back(vektor.at(i));
			}
		}
		else {
			if(!DaLiJeBrojProst(vektor.at(i))) {
				tmp=abs(vektor.at(i));
				std::deque<int> ternarna_reprezentacija;
				while(tmp!=0) {
					ternarna_reprezentacija.push_front(tmp%3);
					tmp/=3;
				}
				brojac=ternarna_reprezentacija.size()-1;
				valjanost=true;
				for (int j=0; j<ternarna_reprezentacija.size()/2; j++) {
					if(ternarna_reprezentacija.at(j)!=ternarna_reprezentacija.at(brojac)) { valjanost=false; break; }
					brojac--;
				}
				if(valjanost) rezultat.push_back(vektor.at(i));
			}
		}
	}
	return rezultat;
}

int main ()
{
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	std::vector<int> v(0);
	while(1) {
		int broj;
		std::cin >> broj;
		if(broj==-1) break;
		else v.push_back(broj);
	}
	int izbor;
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	while(1) {
		std::cin >> izbor;
		if (izbor==0 || izbor==1) break;
		else std::cout << "Neispravan unos! Unesite ponovo: ";
	}
	auto tmp=IzdvojiSimetricneTernarne(v, bool(izbor));
	if (tmp.size()==0 && izbor==1) {std::cout << "Nema prostih simetricnih brojeva u vektoru."; return 0;}
	else if (tmp.size()==0 && izbor==0) {std::cout << "Nema slozenih simetricnih brojeva u vektoru."; return 0;}
	if (izbor) std::cout << "Prosti simetricni brojevi iz vektora su: ";
	else std::cout << "Slozeni simetricni brojevi iz vektora su: ";
	for (int i=0; i<tmp.size(); i++)
		if (tmp.size()-1!=i) std::cout << tmp.at(i) << ", ";
		else std::cout << tmp.at(i) << ".";
	return 0;
}