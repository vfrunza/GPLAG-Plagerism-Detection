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
#include <iomanip>

enum Smjer {Rastuci, Opadajuci};

// Provjeravam da li je broj stepen dvojke
bool StepenDvojke (int n)
{
	if (n < 1) return false;
	for (int i = 2; i < n; i++) {
		while (n != 1) {
			if(n % 2 == 0) {
				n /= 2;
			} else

				return false;

		}
	}
	return true;
}

std::deque < std::vector < int >> MaksimalniPodnizoviStepenaDvojke (std::vector < int > a, Smjer s)
{
	std::deque < std::vector < int >> Podnizovi;
	if(s == Rastuci) {
		int k(0);
		for(int i = 0; i < a.size()-1; i++) {
			if(StepenDvojke(a.at(i))) {
				int m(0);
				if(a.at(i) <= a.at(i+1) && StepenDvojke(a.at(i+1)) ) {
					Podnizovi.resize(k+1);
					Podnizovi.at(k).resize(1);
					Podnizovi.at(k).at(0) = a.at(i);
					m = 1;
					while ((i+1) < a.size() && StepenDvojke(a.at(i+1)) && a.at(i) <= a.at(i+1)) {
						
						Podnizovi.at(k).resize(m+1);
						Podnizovi.at(k).at(m) = a.at(i+1);
						m = m + 1;
						i = i + 1;
					}
					k = k + 1;
				}
			}
		}
	} else {

		int k(0);
		for(int i = 0; i < a.size()-1; i++) {
			if(StepenDvojke(a.at(i))) {
				int m(0);
				if(a.at(i) >= a.at(i+1) && StepenDvojke(a.at(i+1))) {
					Podnizovi.resize(k+1);
					Podnizovi.at(k).resize(1);
					Podnizovi.at(k).at(0) = a.at(i);
					m = 1;
					while ((i+1) < a.size() && StepenDvojke(a.at(i+1)) && a.at(i) >= a.at(i+1)) {
					
						Podnizovi.at(k).resize(m+1);
						Podnizovi.at(k).at(m) = a.at(i+1);
						m = m +1;
						i = i+1;
					}
					k = k+1;
				}
			}
		}

	}

	return Podnizovi;
}

int main ()
{
	int broj_el;
	double broj;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> broj_el;
	std::vector < int > v;
	std::cout << "Unesite elemente vektora: ";

	for(int i = 0; i < broj_el ; i++) {
		std::cin >> broj;
		if(broj != 0) v.push_back(broj);
		if(broj <= 0) break;
	}
	int ulaz;
	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin >> ulaz;
	std::deque < std::vector < int >> rastuci;
	rastuci = MaksimalniPodnizoviStepenaDvojke(v,Rastuci);
	if(ulaz == 1) {
		std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
		for(int i = 0; i < rastuci.size(); i++) {
			for(int j = 0; j < rastuci.at(i).size(); j++) {


				std::cout << rastuci.at(i).at(j) << " ";
			}
			std::cout << std::endl;
		}
	}
	std::deque < std::vector < int >> opadajuci;
	opadajuci = MaksimalniPodnizoviStepenaDvojke(v,Opadajuci);
	if(ulaz == 2) {
		std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
		for(int i = 0; i < opadajuci.size(); i++) {
			for(int j = 0; j < opadajuci.at(i).size(); j++) {
				std::cout << opadajuci.at(i).at(j) << " ";
			}
			std::cout << std::endl;
		}
	}



	return 0;
}