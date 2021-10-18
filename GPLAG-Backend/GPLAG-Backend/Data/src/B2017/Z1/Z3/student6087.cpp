#include <iostream>
#include <vector>
#include <deque>
#include <cmath>

typedef std::vector<int> vektor;
typedef std::deque<int> dek;
typedef std::deque<std::vector<int>> dekvektora;

enum Smjer {Rastuci, Opadajuci};

bool DaLiJeStepenDvojke(long long int x)
{
    if(x < 0) return false;
	while(x != 0) {
	    if(x == 1) return true;
	   	if(x% 2 != 0) return false;
		if(x == 2) 	return true;
		x /= 2;
	}
	return false;
}

dekvektora MaksimalniPodnizoviStepenaDvojke (vektor v1, Smjer smjer)
{
	dekvektora dv;
	int brojac(0);
	if(smjer == Rastuci) {
		for(int i = 0; i < v1.size()-1; i++) {
			if((v1.at(i) <= v1.at(i+1))  && DaLiJeStepenDvojke(v1.at(i))) {
				dv.resize(brojac+1);
				int j; 
				for(j = i; j < v1.size()-1; j++) {
					if(v1.at(j) <= v1.at(j+1)) {
						if(DaLiJeStepenDvojke(v1.at(j))) {
						dv.at(brojac).push_back(v1.at(j));
						} else break;
					} else break;
				}
				if(DaLiJeStepenDvojke(v1.at(j)))
				dv.at(brojac).push_back(v1.at(j));
				i = j;
				brojac++;
			}
			for(int i = 0; i < dv.size(); i++) {
				if(dv.at(i).size() < 2) {
				dv.erase(dv.begin()+i);
				i--;
			}
		}
	}
	} else { 
		for(int i = 0; i < v1.size()-1; i++) {
			if((v1.at(i) >= v1.at(i+1)) && DaLiJeStepenDvojke(v1.at(i))) {
				dv.resize(brojac+1);
				int j; 
				for(j = i; j < v1.size()-1; j++) {
					if(v1.at(j) >= v1.at(j+1)) {
						if(DaLiJeStepenDvojke(v1.at(j))) {
						dv.at(brojac).push_back(v1.at(j));
						} else { 
							break;
						}
					} else break;
				}
				if(DaLiJeStepenDvojke(v1.at(j)))
				dv.at(brojac).push_back(v1.at(j));
				i = j;
				brojac++;
			}
		}
	}
	for(int i = 0; i < dv.size(); i++) {
		if(dv.at(i).size() < 2) {
			dv.erase(dv.begin()+i);
			i--;
		}
	}
	return dv;
}

	int main () {
		vektor v;
		std::cout << "Unesite broj elemenata vektora: ";
		int n;
		std::cin >> n;
		v.resize(n);
		std::cout << "Unesite elemente vektora: ";
		for(int i = 0; i < v.size(); i++) {
			std::cin >> v.at(i);
		}
		std::cin.ignore(10000,'\n');
		int tip(0);
		std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
		std::cin >> tip;
		Smjer vrsta = Smjer(tip - 1);

		dekvektora dekvek;
		dekvek = MaksimalniPodnizoviStepenaDvojke(v,vrsta);
		if(tip == 1) std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
		else std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
		for(int i = 0; i <dekvek.size(); i++) {
			for(int j = 0; j < dekvek.at(i).size(); j++) {
				std::cout << dekvek.at(i).at(j) << " ";
			}
			std::cout << std::endl;
		}

		return 0;
	}