#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>

typedef std::deque<std::vector<int>> DV;

enum Smjer {Rastuci, Opadajuci};

bool StepenDvojke(int broj) {
	if (broj <= 0) return false;
	while (broj != 1 && broj != -1) {
		if (broj % 2 != 0) return false;
		broj /= 2;
	}
	return true;
}

DV MaksimalniPodnizoviStepenaDvojke(std::vector<int> v, Smjer s) {
	DV niz;
	for (int i = 0; i < v.size(); i++) {
		int j;
		for (j = i; j < v.size(); j++) 
			if (!StepenDvojke(v.at(j)) || (j > i && s == Rastuci && v.at(j) < v.at(j-1)) || (j > i && s == Opadajuci && v.at(j) > v.at(j-1))) break;
		if (j > i+1) {
			std::vector<int> podniz;
			while (i < j) 
				podniz.push_back(v.at(i++));
			niz.push_back(podniz);
			i--;
		}
	}
	return niz;
}

int main ()
{
	int n;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	std::vector<int> v;
	std::cout << "Unesite elemente vektora: ";
	for (int i = 0; i < n; i++) {
		int broj;
		std::cin >> broj;
		v.push_back(broj);
	}
	int x;
	Smjer s;
	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin >> x;
	if (x != 1 && x != 2) return 0;
	s = Smjer(x-1);
	if (x == 1) std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	else std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	try {
		DV nizovi(MaksimalniPodnizoviStepenaDvojke(v,s));
		for (auto x : nizovi) {
			for (auto y : x) std::cout << y << " ";
			std::cout << std::endl;
		}
	}
	catch(std::range_error izuzetak) {
		std::cout << izuzetak.what();
	}
	
	return 0;
}