#include <iostream>
#include <deque>
#include <vector>

enum Smjer {Rastuci, Opadajuci};

bool StepenDvojke(int a)
{
	if(a > 0 && (a & (a-1)) == 0) return true;
	else return false;
/*
	Moglo je i ovako:

	while(a % 2 == 0 && a > 1) {
		a = a / 2;
	}

	if(a == 1) return true;
	else return false;
	*/

}

std::deque<std::vector<int> > MaksimalniPodnizoviStepenaDvojke (std::vector<int> v,Smjer a)
{

	std::deque<std::vector<int> > d;

	if(a == Rastuci) {
		for(unsigned int i = 0; i < v.size(); i++) {
			std::vector<int> V;
			if(i == v.size() - 1) {
				if(StepenDvojke(v.at(i)) == true && v.at(i) >= v.at(i-1) && StepenDvojke(v.at(i-1)))
					V.push_back(v.at(i));
				break;
			}
			if(StepenDvojke(v.at(i)) && StepenDvojke(v.at(i+1)) && v.at(i) <= v.at(i+1)) {
				V.push_back(v.at(i));

			}

			if(StepenDvojke(v.at(i+1)) == true && v.at(i) <= v.at(i+1) && StepenDvojke(v.at(i)) == true) {
				V.push_back(v.at(i+1));
				i++;
				if(i == v.size() - 1) {
					d.push_back(V);
					break;
				}
				while(v.at(i) <= v.at(i+1) && StepenDvojke(v.at(i)) == true && StepenDvojke(v.at(i+1))) {
					V.push_back(v.at(i+1));
					i++;
					if(i == v.size() - 1) {
						break;
					}
				}
			}
			if(V.size() > 1) d.push_back(V);
		}
	}

	else if (a == Opadajuci) {

		for(unsigned int i = 0; i < v.size(); i++) {
			std::vector<int> V;
			if(i == v.size() - 1) {
				if(StepenDvojke(v.at(i)) == true && v.at(i) <= v.at(i-1) && StepenDvojke(v.at(i-1)) == true)
					V.push_back(v.at(i));
				break;
			}

			if(StepenDvojke(v.at(i)) == true && StepenDvojke(v.at(i+1)) == true && v.at(i) >= v.at(i+1)) {
				V.push_back(v.at(i));
			}

			if(StepenDvojke(v.at(i+1)) == true && v.at(i) >= v.at(i+1) && StepenDvojke(v.at(i)) == true) {
				V.push_back(v.at(i+1));
				i++;
				if(i == v.size() - 1) {
					d.push_back(V);
					break;
				}

				while(v.at(i) >= v.at(i+1) && StepenDvojke(v.at(i)) == true && StepenDvojke((v.at(i+1))) == true) {
					V.push_back(v.at(i+1));
					i++;
					if(i == v.size() - 1) {
						break;
					}
				}
			}
			if(V.size() > 1) {
				d.push_back(V);
			}
		}
	}
	return d;
}

int main ()
{
	std::vector<int> a;
	int n(0);
	int element(0);

	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	std::cout << "Unesite elemente vektora: ";

	for(unsigned int i = 0; i < n; i++) {
		while(!(std::cin >> element)) {
			std::cout << "Neispravan unos! Unesite ponovo: ";
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
		a.push_back(element);
	}
	std::deque<std::vector<int> > D1 = MaksimalniPodnizoviStepenaDvojke(a,Rastuci);
	std::deque<std::vector<int> > D2 = MaksimalniPodnizoviStepenaDvojke(a,Opadajuci);

	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";

	int l(0);

	do {
		std::cin >> l;
		if(l == 1 || l == 2) break;
		std::cout << "Neispravan unos! Unesite ponovo: ";
	} while(l != 1 || l != 2);

	if(l == 1) {

		std::cout << "Maksimalni rastuci podnizovi: \n";
		for(unsigned int i = 0; i < D1.size(); i++) {
			for(unsigned int j = 0; j < D1.at(i).size(); j++) {
				std::cout << D1.at(i).at(j) << " ";
			}
			std::cout << "\n";
		}
	} else if(l == 2) {
		std::cout << "Maksimalni opadajuci podnizovi: \n";
		for(unsigned int i = 0; i < D2.size(); i++) {
			for(unsigned int j = 0; j < D2.at(i).size(); j++) {
				std::cout << D2.at(i).at(j) << " ";
			}
			std::cout<<"\n";
		}
	}

	return 0;

}