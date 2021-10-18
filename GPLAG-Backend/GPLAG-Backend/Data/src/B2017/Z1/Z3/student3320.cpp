/*B 2017/2018, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>
#include <stdexcept>
#include <cmath>

enum Smjer{Rastuci=1, Opadajuci} smjer;

bool StepenDvojke(int n) {
	int brojac=0;
	int test=0;
	
	while(1) {
		test=pow(2, brojac);
		brojac++;
		if(test==n) break;
		else if(test>n) return false;
	}
	return true;
}

std::deque<std::vector<int>>MaksimalniPodnizoviStepenaDvojke(std::vector<int>niz, Smjer smjer) {
	std::deque<std::vector<int>>dek;
	int red=0;
	int brojac=1;
	
	switch (smjer) {
		case 1:
			for(int i=1; i<niz.size(); i++) {
				if((niz.at(i)>=niz.at(i-1)) && StepenDvojke(niz.at(i)) && StepenDvojke(niz.at(i-1))) {
					if(brojac && StepenDvojke(niz.at(i-1))) {
						dek.resize(red+1);
						dek.at(red).push_back(niz.at(i-1));
						brojac=0;
					}
					dek.at(red).push_back(niz.at(i));
				} else {
					brojac=1;
					if(dek.size()!=red) {
						red++;
					}
				}
			}
			break;
		default:	
			for(int i=1; i<niz.size(); i++) {
				if((niz.at(i)<=niz.at(i-1)) && StepenDvojke(niz.at(i-1)) && StepenDvojke(niz.at(i))) {
					if(brojac) {
						dek.resize(red+1);
						dek.at(red).push_back(niz.at(i-1));		
						brojac=0;
					}
					dek.at(red).push_back(niz.at(i));
				} else {
					brojac=1;
					if(dek.size()!=red) {
						red++;
					}
				}
			}
			break;
		}
	return dek;
}

int main () {
	int n;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	
	std::vector<int>niz;
	std::cout << "Unesite elemente vektora: ";
	for(int i=0; i<n; i++) {
		int broj;
		std::cin >> broj;
		niz.push_back(broj);
	}

	int broj;
	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin >> broj;
	
	std::cin.ignore(10000, '\n');
	std::deque<std::vector<int>>rez;
	rez=MaksimalniPodnizoviStepenaDvojke(niz, Smjer(broj));
	if(broj==1) {
		std::cout << "Maksimalni rastuci podnizovi: \n";
		for(int i=0; i<rez.size(); i++) {
			for(int j=0; j<rez.at(i).size(); j++) {
				std::cout << rez.at(i).at(j) << " ";
			}
			std::cout << std::endl;
		}
	} else {
		if(broj==2) {
			std::cout << "Maksimalni opadajuci podnizovi: \n";
			for(int i=0; i<rez.size(); i++) {
				for(int j=0; j<rez.at(i).size(); j++) {
					std::cout << rez.at(i).at(j) << " ";
				}
				std::cout << std::endl;
			}
		}
	}
	return 0;
}