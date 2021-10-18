#include <iostream>
#include <vector>
#include <deque>

enum Smjer {Rastuci, Opadajuci};

bool DaLiJeStepenDvojke (int br) {
	if(br>0)
		return (br != 0 && (br&(br-1)) == 0);
	else return false;
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke (std::vector<int>brojevi, Smjer s) {
	std::deque<std::vector<int>> deka;
	for(int i=0; i<brojevi.size(); i++) {
		std::vector<int>pomocni ;
		int j=i;
		if (s == Smjer::Rastuci){
			while (j + 1 < brojevi.size() && brojevi.at(j) <= brojevi.at(j + 1) && DaLiJeStepenDvojke(brojevi.at(j + 1))) {
				pomocni.push_back(brojevi.at(j));
				j++;
			}
			pomocni.push_back(brojevi.at(j));
		} else {
			while (j + 1 < brojevi.size() && brojevi.at(j) >= brojevi.at(j + 1) && DaLiJeStepenDvojke(brojevi.at(j + 1))) {
				pomocni.push_back(brojevi.at(j));
				j++;
			}
			pomocni.push_back(brojevi.at(j));
		}
		
		bool nizJeOk = true;
		for (int k : pomocni) {
			if (! DaLiJeStepenDvojke(k)) {
				nizJeOk = false;
				break;
			}
		}
		if (nizJeOk && pomocni.size() > 1) {
			deka.push_back(pomocni);
		}
		
		i = j;
		
	}
	
	return deka;
}  
int main ()
{
	std::vector<int> v1 ;
	std::cout << "Unesite broj elemenata vektora: ";
	int BrElem;
	std::cin >> BrElem;
	std::cout << "Unesite elemente vektora: ";
	for (int i = 0; i < BrElem; i++) {
		int element;
		std::cin >> element;
		v1.push_back(element);
	}
	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int unos;
	std::cin >> unos;
	if (unos==1) {
		std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
		for(auto a: MaksimalniPodnizoviStepenaDvojke(v1,Smjer::Rastuci)) {
			for(int x: a)
				std::cout << x << " ";
			std::cout << std::endl;
		}
	}
	else if (unos==2) {
		std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
		for(auto a: MaksimalniPodnizoviStepenaDvojke(v1,Smjer::Opadajuci)) {
			for(int x: a)
				std::cout << x << " ";
			std::cout << std::endl;
		}
	}
	else do {
		if(unos != 1 && unos != 2) std::cout << "Pogresan unos! Unesite opet: ";
		std::cin >> unos;
	} while (unos != 1 && unos != 2);
	return 0;
}