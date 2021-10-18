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

bool JeLiStepenDvojke(int x) {
	if (x <= 0) return false;
	// broj je stepen dvojke ukoliko je rezultat AND operacije izmedju
	// broj i (broj - 1) (napisanih binarno naravno) 0
	else {
		bool a = !(x & (x-1));
		return a;
	}
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> v, Smjer s) {
	std::deque<std::vector<int>> pom;
	if (v.size() == 0) return pom;
	if (s == Rastuci) {
		for (int i=0; i<v.size()-1; i++) {
			if ((v.at(i) <= v.at(i+1)) && JeLiStepenDvojke(v.at(i))) {
				std::vector<int> pom2;
				while ((v.at(i) <= v.at(i+1)) && JeLiStepenDvojke(v.at(i))) {
					pom2.push_back(v.at(i));
					i++;
					if (i >= v.size()-1) break;
				}
			
			    if (JeLiStepenDvojke(v.at(i))) pom2.push_back(v.at(i));
				if (pom2.size() > 1) pom.push_back(pom2);
			}
		}
	
	}
	
	else if (s == Opadajuci) {
		for (int i=0; i<v.size()-1; i++) {
			if ((v.at(i) >= v.at(i+1)) && JeLiStepenDvojke(v.at(i))) {
				std::vector<int> pom2;
				while((v.at(i) >= v.at(i+1)) && JeLiStepenDvojke(v.at(i))) {
					pom2.push_back(v.at(i));
					i++;
					if (i >= v.size()-1) break;
				}
				
				if (JeLiStepenDvojke(v.at(i))) pom2.push_back(v.at(i));
				if (pom2.size() > 1) pom.push_back(pom2);
			}
		}
	
	}
	
	return pom;
}

int main ()
{
	int n{};
	std::vector<int> v;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	for (int i=0; i<n; i++) {
		int broj{};
		std::cin>>broj;
		v.push_back(broj);
	}
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin>>n;
	if (n == 1) {
		std::cout<<"Maksimalni rastuci podnizovi: \n";
		std::deque<std::vector<int>> d = MaksimalniPodnizoviStepenaDvojke(v, Rastuci);
		for(auto x:d) {
			for (auto y:x)
				std::cout<<y<<" ";
			std::cout<<std::endl;
		}
	}
	else if (n == 2) {
		std::cout<<"Maksimalni opadajuci podnizovi: \n";
		std::deque<std::vector<int>> d = MaksimalniPodnizoviStepenaDvojke(v, Opadajuci);
		for (auto x:d) {
			for (auto y:x) 
				std::cout<<y<<" ";
			std::cout<<std::endl;
		}
	}
	return 0;
	
}