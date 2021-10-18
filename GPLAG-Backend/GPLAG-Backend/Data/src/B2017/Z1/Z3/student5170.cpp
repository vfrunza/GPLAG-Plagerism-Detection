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

bool JeLiStepenDvojke(int n) {
	if(n == 0) return 0;
	while(n != 1) {
		if(n%2 != 0) return 0;
		n/=2;
	}
	return 1;
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> v, enum Smjer e) {
	std::deque<std::vector<int>> vrati;
	if(e == 1) {
		
	}
	
	return vrati;
}


int main () {
	std::cout << "Unesite broj elemenata vektora: ";
	int n;
	std::cin >> n;
	std::vector<int> v;
	std::cout << "Unesite elemente vektora: ";
	for(int i(0); i<n; i++) {
		int a;
		std::cin >> a;
		v.push_back(a);
	}
	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int b;
	std::cin >> b;
	
	enum Smjer {Rastuci = 1, Opadajuci = 2};
	
	std::deque<std::vector<int>> dv;
	if(b == 1) dv = MaksimalniPodnizoviStepenaDvojke(v, Rastuci);
	else if(b == 2) dv = MaksimalniPodnizoviStepenaDvojke(v, Opadajuci);
	
	
	return 0;
}