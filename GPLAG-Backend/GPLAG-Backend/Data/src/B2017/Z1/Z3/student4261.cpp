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

enum Smjer {Rastuci=1, Opadajuci};

bool StepenDvojke (int n) {
	if (n<1) return false;
	while (n!=1) {
		if (n%2!=0) return false;
		n/=2;
	}
	return true;
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke (std::vector<int> v, Smjer izbor) {
	std::deque<std::vector<int>> podniz;
	int duzina, redovi(0);
	
	if (izbor==Rastuci) {
		for (int i=0; i<v.size(); i++) {
			duzina=1;
			for (int j=i; j<v.size()-1; j++) {
				if (StepenDvojke(v.at(j)) && StepenDvojke(v.at(j+1)) && v.at(j)<=v.at(j+1)) duzina++;
				else break;
			}
			if (duzina>1) {
				podniz.resize(redovi+1);
				podniz.at(redovi).resize(duzina);
				for (int k=0; k<duzina; k++) {
					podniz.at(redovi).at(k)=v.at(i);
					i++;
				}
				redovi++;
				i--;
			}
		}
	}
	else {
		for (int i=0; i<v.size(); i++) {
			duzina=1;
			for (int j=i; j<v.size()-1; j++) {
				if ((StepenDvojke(v.at(j)) && StepenDvojke(v.at(j+1))) && v.at(j)>=v.at(j+1)) duzina++;
				else break;
			}
			if (duzina>1) {
				podniz.resize(redovi+1);
				podniz.at(redovi).resize(duzina);
				for (int k=0; k<duzina; k++) {
					podniz.at(redovi).at(k)=v.at(i);
					i++;
				}
				redovi++;
				i--;
			}
		}
	}
	return podniz;
}

int main ()
{
	int br_elemenata;
	std::vector<int> v;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> br_elemenata;
	std::cout << "Unesite elemente vektora: ";
	v.resize(br_elemenata);
	
	for (int i=0; i<br_elemenata; i++) std::cin >> v.at(i);
	
	int izbor_broja;
	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin >> izbor_broja;
	
	Smjer izbor;
	if (izbor_broja==1) izbor=Rastuci;
	else izbor=Opadajuci;
	
	auto podnizovi (MaksimalniPodnizoviStepenaDvojke(v, izbor));
	
	if (izbor==Rastuci) std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	else std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	for (int i=0; i<podnizovi.size(); i++) {
		for (int j=0; j<podnizovi.at(i).size(); j++) {
			std::cout << podnizovi.at(i).at(j) << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}