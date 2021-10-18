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

enum Smjer {Rastuci, Opadajuci};

bool DaLiJeStepenDvojke (int broj) {
	if (broj<=0) return false;
	while (broj>1) {
		if (broj%2!=0) return false;
		broj = broj/2;
	}
	return true;
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke (std::vector<int> v, Smjer k) {
	
	std::vector<int> pom;
	std::deque<std::vector<int>> rast, opad;
	
	if (DaLiJeStepenDvojke(v.at(0))) pom.push_back(v.at(0));
	
	for (int i=1; i<v.size(); i++) {											// RASTUCI
		if (DaLiJeStepenDvojke(v.at(i))) {
			if (v.at(i) > v.at(i-1)) {
				pom.push_back(v.at(i));
			}
			else {
				if (pom.size()>1) rast.push_back(pom);
				pom.resize(0);
				pom.push_back(v.at(i));
			}
		}
		else if (pom.size()>1) {
			rast.push_back(pom);
			pom.resize(0);
		}
	}
	
	
	for (int i=1; i<v.size(); i++) {											// OPADAJUCI
		if (DaLiJeStepenDvojke(v.at(i))) {
			if (v.at(i) < v.at(i-1)) {
				pom.push_back(v.at(i));
			}
			else {
				if (pom.size()>1) opad.push_back(pom);
				pom.resize(0);
				pom.push_back(v.at(i));
			}
		}
		else if (pom.size()>1) {
			opad.push_back(pom);
			pom.resize(0);
		}
	}
	
	
	if (k==Rastuci) return rast;
	if (k==Opadajuci) return opad;
}



int main ()
{
	int n;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	int broj;
	std::vector<int> v(n);
	std::cout << "Unesite elemente vektora: ";
	for (int i=0; i<n; i++) {
		std::cin >> broj;
		v.push_back(broj);
	}
	
	int x;
	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin >> x;
	std::deque<std::vector<int>> podnizovi;
	
	if (x==1) {
		podnizovi = MaksimalniPodnizoviStepenaDvojke(v, Rastuci);
		std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	}
	else if (x==2) {
		podnizovi = MaksimalniPodnizoviStepenaDvojke(v, Opadajuci);
		std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	}
	else std::cout << "Niste unijeli 1 ili 2";
	
	for (std::vector<int> red : podnizovi) {
		for (int i : red) std::cout << i << " ";
		std::cout << std::endl;
	}
	
	return 0;
}