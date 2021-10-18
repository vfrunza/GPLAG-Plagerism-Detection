#include <iostream>
#include <vector>
#include <deque>

enum Smjer {Rastuci, Opadajuci};

bool DaLiJeStepenDvojke(int n)
{
	if (n==0) return false;
	while (n!=1) {
		if (n%2!=0)
			return false;
		n=n/2;
	}
	return true;
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke (std::vector<int> vektor, Smjer s)
{

	std::deque<std::vector<int>>zavracanje;
	int brojac {0};

	//MONOTONO RASTUCI PODNIZ

	if (s==Rastuci) {

		for (int i=0; i<vektor.size(); i++ ) {
			std::vector<int> temp;
			if (DaLiJeStepenDvojke(vektor.at(i))==true) {
				temp.push_back(vektor.at(i));
				zavracanje.push_back(temp);

				while (i+1<vektor.size() && DaLiJeStepenDvojke(vektor.at(i+1))==true && vektor.at(i)<=vektor.at(i+1)) {


					zavracanje.at(brojac).push_back(vektor.at(i+1));
					i++;
				}
				if (zavracanje.at(brojac).size()>1) brojac++;
				else zavracanje.pop_back();


			}
		}
	}

	brojac=0;

	//MONOTONO OPADAJUCI PODNIZ

	if (s==Opadajuci) {

		for (int i=0; i<vektor.size(); i++ ) {
			std::vector<int> temp;
			if (DaLiJeStepenDvojke(vektor.at(i))) {
				temp.push_back(vektor.at(i));
				zavracanje.push_back(temp);

				while (i+1<vektor.size() && DaLiJeStepenDvojke(vektor.at(i+1))==true && vektor.at(i)>=vektor.at(i+1)) {


					zavracanje.at(brojac).push_back(vektor.at(i+1));
					i++;
				}
				if (zavracanje.at(brojac).size()>1) brojac++;
				else zavracanje.pop_back();


			}
		}
	}

	return zavracanje;
}


int main ()
{
	int n;

	std::vector<int> v;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	std::cout << "Unesite elemente vektora: ";
	int broj;
	for (int i=0; i<n; i++) {
		std::cin >> broj;
		v.push_back(broj);
	}

	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int a;
	std::cin >> a;

	/*  if (a!=1 && a!=2){
		std::cout << "Neispravan unos! Unesite ponovo: ";
		do{
			std::cin >> a;
		}while (a!=1 && a!=2);
	}
	*/
	std::deque<std::vector<int>> novi;

	if (a==1) {
		std::cout << "Maksimalni rastuci podnizovi: ";
		std::cout << std::endl;
		novi = MaksimalniPodnizoviStepenaDvojke(v, Rastuci);
		//ispisivanje matrice samo zapamti ovo

		for (int i=0; i<novi.size(); i++) {
			for (int j=0; j<novi.at(i).size() ; j++) {


				std::cout << novi.at(i).at(j) << " ";

			}
			std::cout << std::endl;
		}

	}

	else if (a==2) {
		std::cout << "Maksimalni opadajuci podnizovi: ";
		std::cout << std::endl;
		novi = MaksimalniPodnizoviStepenaDvojke(v, Opadajuci);

		for (int i=0; i<novi.size(); i++) {
			for (int j=0; j<novi.at(i).size() ; j++) {

				std::cout << novi.at(i).at(j) << " ";

			}
			std::cout << std::endl;
		}

	}

	return 0;
}