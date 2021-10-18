#include <iostream>
#include <deque>
#include <vector>

enum Smjer {Rastuci=1, Opadajuci=2};

bool StepenDvojke(int n)
{
	long int k(1);
	for (;;) {
		if (n==k)
			return true;
		if (k>n)
			return false;
		k*=2;
	}
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> v, Smjer s)
{
	std::deque<std::vector<int>> rez;
	if (v.size()==0)
		return rez;
	bool kontrola(false);
	int brojac(0);
	int i(0), j(0);
	for (i = 0; i < v.size()-1; i++) {
		if (!StepenDvojke(v.at(i)))
			continue;
		else {
			for (j = i+1; j < v.size(); j++) {
				if (!StepenDvojke(v.at(j)))
					break;
				if ((s==Rastuci && v.at(i)<=v.at(j)) || (s==Opadajuci && v.at(i)>=v.at(j))) {
					rez.resize(brojac+1);
					rez.at(brojac).push_back(v.at(i));
					i++;
					kontrola=true;
				} else
					break;
			}
			if (kontrola) {
				rez.at(brojac).push_back(v.at(j-1));
				brojac++;
			}
			kontrola=false;
		}
	}
	return rez;
}

int main ()
{
	std::vector<int> v;
	int broj_el(0), izbor(0);
	std::cout << "Unesite broj elemenata vektora: ";
	do {
		std::cin >> broj_el;
		if (!std::cin || broj_el<0) {
			if (!std::cin) {
				std::cin.clear();
				std::cin.ignore(10000, '\n');
			}
			std::cout << "Neispravan unos! Unesite ponovo: ";
		} else
			break;
	} while(1);
	v.resize(broj_el);
	std::cout << "Unesite elemente vektora: ";
	for (int i = 0; i < v.size(); i++) {
		std::cin >> v.at(i);
		if (!std::cin) {
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout << "Neispravan unos! Unesite ponovo: ";
			i--;
		}
	}

	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	do {
		std::cin >> izbor;
		if (!std::cin || (izbor!=1 && izbor!=2)) {
			if (!std::cin) {
				std::cin.clear();
				std::cin.ignore(10000, '\n');
			}
			std::cout << "Neispravan unos! Unesite ponovo: ";
		}
	} while(izbor!=1 && izbor!=2);


	std::deque<std::vector<int>> rez(MaksimalniPodnizoviStepenaDvojke(v, Smjer(izbor)));

	if (rez.size()==0) {
		std::cout << "Ne postoji ni jedan monoton podniz stepena dvojke.\n";
		return 0;
	}

	if (izbor==1)
		std::cout << "Maksimalni rastuci podnizovi: \n";
	else
		std::cout << "Maksimalni opadajuci podnizovi: \n";

	for (int i = 0; i < rez.size(); i++) {
		for (int j = 0; j < rez.at(i).size(); j++) {
			std::cout << rez.at(i).at(j) << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}