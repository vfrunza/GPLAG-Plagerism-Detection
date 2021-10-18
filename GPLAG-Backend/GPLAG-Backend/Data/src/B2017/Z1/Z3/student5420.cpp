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

bool DaLiJeStepenDvojke (int n) {
	int br(1);
	while (br<n) br*=2;
	if (br==n) return true;
	return false;
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke (std::vector<int> v, Smjer s) {
	std::deque<std::vector<int>> mat;
	if (v.size()==0) return mat;
	for (int i=0; i<v.size()-1; i++) {
		int br(0);
		if (DaLiJeStepenDvojke(v.at(i))) {
			std::vector<int> v1;
			v1.push_back(v.at(i));
			br++;
			if (s==Rastuci) {
				while (DaLiJeStepenDvojke(v.at(i+1)) && v.at(i+1)>v.at(i)) {
					v1.push_back(v.at(i+1));
					br++;
					i++;
					if (i==v.size()-1) break;
				}
				if (br>1) mat.push_back(v1);
			}
			if (s==Opadajuci) {
				while (DaLiJeStepenDvojke(v.at(i+1)) && v.at(i+1)<v.at(i)) {
					v1.push_back(v.at(i+1));
					br++;
					i++;
					if (i==v.size()-1) break;
				}
				if (br>1) mat.push_back(v1);
			}
		}
	}
	return mat;
}

int main ()
{
	std::cout << "Unesite broj elemenata vektora: ";
	int n;
	std::cin >> n;
	if (n==0) return 0;
	std::cout << "Unesite elemente vektora: ";
	int x;
	std::vector<int> v;
	for (int i=0; i<n; i++) {
		std::cin >> x;
		v.push_back(x);
	}
	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int b;
	std::cin >> b;
	if (b==1) {
		auto pom(MaksimalniPodnizoviStepenaDvojke(v,Rastuci));
		std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
		for (int i=0; i<pom.size(); i++) {
			for (int j=0; j<pom.at(i).size(); j++)
				std::cout << pom.at(i).at(j) << " ";
			std::cout << std::endl;
		}
	}
	if (b==2) {
		auto pom(MaksimalniPodnizoviStepenaDvojke(v,Opadajuci));
		std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
		for (int i=0; i<pom.size(); i++) {
			for (int j=0; j<pom.at(i).size(); j++)
				std::cout << pom.at(i).at(j) << " ";
			std::cout << std::endl;
		}
	}
	return 0;
}