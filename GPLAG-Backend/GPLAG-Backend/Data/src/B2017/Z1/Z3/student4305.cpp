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
#include <deque>
#include <vector>
#include <stdexcept>

typedef std::deque<std::vector<int>> Deque_vector;
enum Smjer {Opadajuci, Rastuci};

bool StepenDvojke (int broj)
{
	int temp(1);
	while (temp < broj)
		temp *= 2;

	return temp == broj;
}

Deque_vector MaksimalniPodnizoviStepenaDvojke (std::vector<int> v, Smjer smjer)
{
	Deque_vector rezultat;

	for (int i = 0 ; i < v.size() ; i++) {
		if (StepenDvojke(v.at(i)) == true) {
			int pocetak(i);
			int j(i + 1);
			while ( j < v.size() && StepenDvojke(v.at(j)) == true && (smjer == Rastuci && v.at(j) > v.at(i) || smjer == Opadajuci && v.at(j) < v.at(i))) {
				i++;
				j++;
			}
			if (j - pocetak > 1) {
				std::vector<int> temp;

				for (int k = pocetak ; k < j ; k++)
					temp.push_back(v.at(k));

				rezultat.push_back(temp);
			}
			i = j - 1;
		}
	}

	return rezultat;
}

int main ()
{
	std::cout << "Unesite broj elemenata vektora: ";
	int br_elemenata;
	std::cin >> br_elemenata;
	std::vector<int> v(br_elemenata);
	std::cout << "Unesite elemente vektora: ";
	int element;
	for (int i = 0 ; i < br_elemenata ; i++) {
		std::cin >> element;
		v.push_back(element);
	}
	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int vrijednost;
	std::cin >> vrijednost;
	if (vrijednost == 1) {
		try {
			Deque_vector rastuci_deque;
			rastuci_deque = MaksimalniPodnizoviStepenaDvojke(v, Rastuci);
			std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
			for (int i = 0 ; i < rastuci_deque.size() ; i++) {
				for (int j = 0 ; j < rastuci_deque.at(i).size() ; j++) {
					std::cout << rastuci_deque.at(i).at(j) << " ";
				}
				std::cout << std::endl;
			}
		} catch (std::out_of_range izuzetak) {
			std::cout << izuzetak.what() << std::endl;
		}
	} else if (vrijednost == 2) {
		try {
			Deque_vector opadajuci_deque;
			opadajuci_deque = MaksimalniPodnizoviStepenaDvojke(v, Opadajuci);
			std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
			for (int i = 0 ; i < opadajuci_deque.size() ; i++) {
				for (int j = 0 ; j < opadajuci_deque.at(i).size() ; j++) {
					std::cout << opadajuci_deque.at(i).at(j) << " ";
				}
				std::cout << std::endl;
			}
		} catch (std::out_of_range izuzetak) {
			std::cout << izuzetak.what() << std::endl;
		}
	}


	return 0;
}