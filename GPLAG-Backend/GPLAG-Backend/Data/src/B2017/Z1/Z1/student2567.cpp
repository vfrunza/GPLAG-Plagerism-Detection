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

int prost(int broj) {
	for(int i(2);i<broj;i++)
		if(broj%i==0) return 0;
	return 1;
}

int PretvoriUTernarni(int broj) {
	broj=std::abs(broj);
	int stepen=1,ternarni=0;
	while(broj>0) {
		ternarni+=(broj%3)*stepen;
		stepen*=10;
		broj/=3;
	}
	return ternarni;
}

int DajBrojNaopako(int broj) {
	int temp=broj,brojCifri=0,obrnuti=0;
	while(temp>0) {
		brojCifri++;
		temp/=10;
	}
	for(int i(0);i<brojCifri;i++) {
		obrnuti+=(broj%10)*std::pow(10,brojCifri-i-1);
		broj/=10;
	}
	return obrnuti;
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> v, bool prosti) {
	std::vector<int> novi;
	if(prosti) {
		for(int i(0);i<v.size();i++)
			if(prost(v.at(i))) {
				bool imaGa=false;
				int t=PretvoriUTernarni(v.at(i));
				if(t==DajBrojNaopako(t)) {
					for(int j(0);j<novi.size();j++)
						if(v.at(i)==novi.at(j)) imaGa=1;
					if(!imaGa) novi.push_back(v.at(i));
				}
			}
	}
	else {
		for(int i(0);i<v.size();i++)
			if(!prost(v.at(i))) {
				bool imaGa=false;
				int t=PretvoriUTernarni(v.at(i));
				if(t==DajBrojNaopako(t)) {
					for(int j(0);j<novi.size();j++)
						if(v.at(i)==novi.at(j)) imaGa=1;
					if(!imaGa) novi.push_back(v.at(i));
				}
			}
	}
	return novi;
}

int main () {
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	std::vector<int> v;
	while(1) {
		int broj;
		std::cin >> broj;
		if(broj==-1) break;
		v.push_back(broj);
	}
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int prosti;
	while(1) {
		std::cin >>prosti;
		if(prosti!=0 && prosti!=1) std::cout << "Neispravan unos! Unesite ponovo: ";
		else break;
	}
	std::vector<int> v2=IzdvojiSimetricneTernarne(v,prosti);
	if(v2.size()==0) {
		if(prosti) std::cout << "Nema prostih simetricnih brojeva u vektoru.";
		else std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
	}
	else {
		if(prosti) std::cout << "Prosti simetricni brojevi iz vektora su: ";
		else std::cout << "Slozeni simetricni brojevi iz vektora su: ";
		for(int i(0);i<v2.size()-1;i++) std::cout << v2.at(i) << ", ";
		std::cout << v2.at(v2.size()-1) << ".";
	}
	return 0;
}