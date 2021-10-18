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

enum Smjer {Rastuci, Opadajuci};

bool StepenDvojke (int n)
{

	int i=1;
	while(1) {
		if (i==n)
			return true;
		if (i>n)
			break;
		i*=2;
	}
	return false;
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke (std::vector<int> v, Smjer f)
{
	std::deque<std::vector<int>> dek;
	bool s (true);
	if (f==Opadajuci) s=false;

	if (s) {
		std::vector<int> pom;
		for (int i=0; i<v.size(); i++) {
			if (StepenDvojke(v.at(i))) {
				if (pom.size()!=0 && pom.at(pom.size()-1)<v.at(i)) {
					pom.push_back(v.at(i));
					if (i==v.size()-1)
						dek.push_back(pom);
				} else if (pom.size()==0)
					pom.push_back(v.at(i));
				else {
					if (pom.size()>1) {
						dek.push_back(pom);
					}
					pom.resize(0);
					i--;
				}
			} else {
				if (pom.size()>1) {
					dek.push_back(pom);
				}
				pom.resize(0);
			}
		}
	} else {
		std::vector<int> pom;
		for (int i=0; i<v.size(); i++) {
			if (StepenDvojke(v.at(i))) {
				if (pom.size()!=0 && pom.at(pom.size()-1)>v.at(i)) {
					pom.push_back(v.at(i));
					if (i==v.size()-1)
						dek.push_back(pom);
				} else if (pom.size()==0) {
					pom.push_back(v.at(i));
				} else {
					if (pom.size()>1) {
						dek.push_back(pom);
					}
					pom.resize(0);
					i--;
				}
			} else {
				if (pom.size()>1) {
					dek.push_back(pom);
				}
				pom.resize(0);
			}
		}
	}
	return dek;
}

int main ()
{

	std::cout<< "Unesite broj elemenata vektora: ";
	int broj;
	std::cin>> broj;
	int temp;
	std::cout<< "Unesite elemente vektora: ";
	std::vector<int> v;
	for (int i=0; i<broj; i++) {
		std::cin>> temp;
		v.push_back(temp);
	}
	int a;
	std::deque<std::vector<int>> novi;
	std::cout<< "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin>> a;

	if (a==1) {
		std::cout<< "Maksimalni rastuci podnizovi: " <<std::endl;
		novi=MaksimalniPodnizoviStepenaDvojke (v, Smjer(Rastuci));
	} else if (a==2) {
		std::cout<< "Maksimalni opadajuci podnizovi: " <<std::endl;
		novi=MaksimalniPodnizoviStepenaDvojke (v, Smjer(Opadajuci));
	}
	for (int i=0; i<novi.size(); i++) {
		for (int j=0; j<novi.at(i).size(); j++) {
			std::cout<< novi.at(i).at(j)<< " ";
		}
		std::cout<< std::endl;
	}
	return 0;
}