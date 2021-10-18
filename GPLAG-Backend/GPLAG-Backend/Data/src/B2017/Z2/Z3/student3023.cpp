/*B 2017/2018, Zadaća 2, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <limits>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <vector>

bool TestPerioda(std::vector<double>brojevi, int brojac) {
	if(brojevi.size()==1 || brojevi.size() <= brojac) {
		return 0;
	}
	
	for(int i=0; i<brojevi.size()-brojac; i++) {
		if(brojevi[i]!=brojevi[i+brojac]) {
			return 0;
		}
	}
	return 1;
}

int OdrediOsnovniPeriod(std::vector<double>brojevi1) {
	for(int i=1; i<brojevi1.size(); i++) {
		if(TestPerioda(brojevi1, i)) return i;
	}
	return 0;
}

template <typename T>
void AlocirajFragmentirano(const std::vector<T>vec, int &koliko_puta) {
	if(vec.size()==0) throw std::domain_error("Prazan vektor!");
	for(int i=0; i<vec.size(); i++) {
		if(vec.at(i)<=0) throw std::domain_error("Neispravan vektor!");
	}
	int period=OdrediOsnovniPeriod(vec);
	if(!period) throw std::domain_error("Pogresan period!");
	
	try {
		
	}catch(...) {
		for(int i=0; i<a; i++) delete[] novo[i];
		delete[] novo;
		throw std::bad_alloc("Nedovoljno memorije!");
	}
	
}

template <typename T>
void AlocirajKontinualno(const &std::vector<T>vec, int &koliko_puta) {
	if(vec.size()==0) throw std::domain_error("Prazan vektor!");
	for(int i=0; i<vec.size(); i++) {
		if(vec.at(i)<=0) throw std::domain_error("Neispravan vektor!");
	}
	int period=OdrediOsnovniPeriod(vec);
	if(!period) throw std::domain_error("Pogresan period!");
	
	try {
		
	}catch(...) {
		delete[] novo;
		throw std::bad_alloc("Nedovoljno memorije!");
	}
	
}

int main () {
	std::cout << "Unesite broj elemenata vektora: ";
	int element;
	std::cin >> element;
	std::cout << "Unesite elemente vektora: ";
	std::vector<int>vec;
	for(int i=0; i<element; i++) {
		int broj;
		std::cin >> broj;
		vec.push_back(broj);
	}
	
	std::cout << "Odaberi alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
	int a;
	std::cin >> a;
	if(a!=0 && a!=1) {
		std::cout << "Pogresna odabrana alokacija!";
		return 0;
	}
	int koliko_puta=0;
	if(a==1) {
		try {
			AlocirajFragmentirano(vec, koliko_puta);
			for(int i=0; i<koliko_puta; i++) delete[] vec[i];
		}catch(std::domain_error jedan) {
			std::cout << "izuzetak: " << jedan.what();
		}catch(std::bad_alloc dva) {
			std::cout << "Izuzetak: " << dva.what();
		}
	}else{
		if(a==0) {
			try {	
				AlocirajKontinualno(vec, koliko_puta);
				delete[] vec[0];
				delete[] vec;
			}catch(std::domain_error jedan) {
				std::cout << "izuzetak: " << jedan.what();
			}catch(std::bad_alloc dva) {
				std::cout << "Izuzetak: " << dva.what();
			}
		}
	}
	return 0;
}