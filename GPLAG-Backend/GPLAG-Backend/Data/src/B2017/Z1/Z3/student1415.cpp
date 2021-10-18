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
#include <cmath>
#include <deque>

#define E 0.000001

typedef std::deque<std::vector<int>> DekVektora;

bool ProvjeraStepenaDvojke (int broj)

{

	for(int i = 0; ; i++) {
		if(fabs(pow(2,i) - broj) < E) return true;

		if ((pow(2,i)) > broj) break;
	}

	return false;
}

enum Smjer {Rastuci = 1, Opadajuci};

std::vector<int> VratiRastuciPodniz (std::vector<int> ulaz, int index)
{

	std::vector<int> izlaz(0);
	int brojac(-1);

	for(int i = index; i < ulaz.size(); i++) {

		if(!ProvjeraStepenaDvojke(ulaz.at(i))) break;

		if(!(izlaz.size() == 0 || (ulaz.at(i) >= izlaz.at(brojac) ))) break;
		else {
			izlaz.push_back(ulaz.at(i));
			brojac++;
		}

	}

	if(izlaz.size() == 1) izlaz.erase(izlaz.begin());

	return izlaz;
}

std::vector<int> VratiOpadajuciPodniz (std::vector<int> ulaz, int index)
{

	std::vector<int> izlaz(0);
	int brojac(-1);

	for(int i = index; i < ulaz.size(); i++) {

		if(!ProvjeraStepenaDvojke(ulaz.at(i))) break;

		if(!(izlaz.size() == 0 || (ulaz.at(i) <= izlaz.at(brojac) ))) break;
		else {
			izlaz.push_back(ulaz.at(i));
			brojac++;
		}

	}

	if(izlaz.size() == 1) izlaz.erase(izlaz.begin());

	return izlaz;
}

DekVektora MaksimalniPodnizoviStepenaDvojke (std::vector<int> ulaz, Smjer uslov)
{

	DekVektora A;
	if(ulaz.size() < 2) return A;
	int brojac(0);

	if(uslov == Rastuci) {
		for(int i = 0; i < ulaz.size(); i++) {
			if(ProvjeraStepenaDvojke(ulaz.at(i))) {
				if(VratiRastuciPodniz(ulaz,i).size() == 0)
					continue;

				A.push_back(VratiRastuciPodniz(ulaz,i));
				i+= A.at(brojac).size();
				brojac++;
				i--;

			}
		}
	} else {
		for(int i = 0; i < ulaz.size(); i++) {
			if(ProvjeraStepenaDvojke(ulaz.at(i))) {
				if(VratiOpadajuciPodniz(ulaz,i).size() == 0)
					continue;

				A.push_back(VratiOpadajuciPodniz(ulaz,i));
				i+= A.at(brojac).size();
				brojac++;
				i--;

			}
		}

	}

	return A;
}


int main ()
{
	std::cout << "Unesite broj elemenata vektora: ";
	int broj;
	std::cin >> broj;

	if( broj < 0 || !std::cin) {

		for(;;) {
			if(broj >= 0 && std::cin)break;
			std::cout << "Neispravan unos! Unesite ponovo: ";
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cin >> broj;

		}
	}

	std::cout << "Unesite elemente vektora: ";

	std::vector<int> v;

	for(int i = 0; i < broj; i++) {
		int privremena(0);
		std::cin >> privremena;
		v.push_back(privremena);
	}

	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	Smjer uslov;
	int testna;

	std::cin >> testna;

	while (testna != 1 && testna != 2) {
		std::cout << "Neispravan unos! Unesite ponovo: ";
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cin >> testna;
	}

	uslov = Smjer(testna);

	DekVektora finalni (MaksimalniPodnizoviStepenaDvojke(v, uslov));

	if(uslov == Rastuci) std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	else std::cout << "Maksimalni opadajuci podnizovi: " <<std:: endl;

	for(int i = 0; i < finalni.size(); i++) {
		for(int j = 0; j < finalni.at(i).size(); j++)
			std::cout << finalni.at(i).at(j) << " ";

		std::cout << std::endl;
	}


	return 0;
}