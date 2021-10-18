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
#include <vector>
#include <deque>
#include <cmath>

enum Smjer{Rastuci, Opadajuci};

bool DaLiJeStepenDvojke(int n) {
	for(int i=0; i<n; i++) {
		if(n&(n-1)==0) return true;
	}
	return false;
}

std::deque<std::vector<int>>MaksimalniPodnizoviStepenaDvojke(std::vector<int>v, Smjer smjer) {
	std::deque<std::vector<int>>d;
	int indeks(0), pocetak(0), kraj(0);
	for(int i=0; i<v.size(); i++) {
			for(int j=i+1; j<v.size(); j++) {
				if(smjer==Rastuci && v.at(indeks)<v.at(j) && DaLiJeStepenDvojke(v.at(indeks))) {
					indeks=j;
				}
				else {
					pocetak=i;
					kraj=indeks;
					std::vector<int>v_pom;
					for(int i=pocetak; i<kraj-pocetak; i++) {
						v_pom.push_back(v.at(i));
					}
					d.push_back(v_pom);
				}
			}
	}
	return d;
}

int main ()
{	
	int n, z;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	std::cout << "Unesite elemente vektora: ";
	std::vector<int>v(n);
	for(int i=0; i<n; i++) {
		std::cin >> v.at(i);
	}
	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin >> z;
	std::deque<std::vector<int>>d;
	if(z==1) {
		Smjer z1(Rastuci);
		d=MaksimalniPodnizoviStepenaDvojke(v, z1);
		std::cout << "Maksimalni rastuci podnizovi: ";
		for(int i=0; i<d.size(); i++) {
			for(int j=0; j<d.at(i).size(); j++) {
				std::cout << d.at(i).at(j) << " ";
			}
			std::cout << std::endl;
		}
	}
	if(z==2) {
		Smjer z1(Opadajuci);
		d=MaksimalniPodnizoviStepenaDvojke(v, z1);
		std::cout << "Maksimalni opadajuci podnizovi: ";
		for(int i=0; i<d.size(); i++) {
			for(int j=0; j<d.at(i).size(); j++) {
				std::cout << d.at(i).at(j) << " ";
			}
			std::cout << std::endl;
		}
	}
	
	return 0;
}