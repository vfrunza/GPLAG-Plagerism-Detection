#include <iostream>
#include <vector>
#include <cmath>
#include <deque>

enum Smjer {Rastuci=1, Opadajuci};

bool DaLiJeStepenDva (int broj)
{
	if (broj==0) return false;
	if (broj<0) return false;
	while (broj!=0) {
		if (broj==1) return true;
		if (broj%2!=0) return false;
		broj = broj / 2;
	}
	return true;
}

std::deque<std::vector<int>>  MaksimalniPodnizoviStepenaDvojke (std::vector<int> v, Smjer smjer)
{
	std::deque<std::vector<int>> konacni;
	std::vector<int> podniz;
	//Trazenje rastucih podnizova
	if (smjer==Rastuci) {
		for (int i(0); i<v.size()-1; i++) {
			if (DaLiJeStepenDva(v.at(i))) {

				while (v.at(i)<=v.at(i+1) && i<v.size()-1 && DaLiJeStepenDva(v.at(i))) {
					podniz.push_back(v.at(i));
					i++;
					if (i==v.size()-1) break;
				}
				//Spremanje vektora u dek i provjera ispravnosti krajnjih clanova
				if (i==0 && DaLiJeStepenDva(v.at(i))) podniz.push_back(v.at(i)); // Da ne dode do izlaska u zabranjeni dio memorije
				else if (v.at(i)>=v.at(i-1) && DaLiJeStepenDva(v.at(i))) podniz.push_back(v.at(i));
				if (podniz.size()==1) {
					podniz.resize(0);
					continue;
				}
				bool ima=false;
				for (int i(0); i<konacni.size(); i++) {
					if (podniz==konacni.at(i)) ima=true;
				}
				if (!ima) konacni.push_back(podniz);
				podniz.resize(0);

			}
		}
	}
	//Trazenje opadajucih podnizova
	if (smjer==Opadajuci) {
		for (int i(0); i<v.size()-1; i++) {
			if (DaLiJeStepenDva(v.at(i))) {
				while (v.at(i)>=v.at(i+1) && i<v.size()-1 && DaLiJeStepenDva(v.at(i))) {
					podniz.push_back(v.at(i));
					i++;
					if (i==v.size()-1) break;
				}
				if (i==0 && DaLiJeStepenDva(v.at(i))) podniz.push_back(v.at(i));
				else if (v.at(i)<=v.at(i-1) && DaLiJeStepenDva(v.at(i))) podniz.push_back(v.at(i));
				if (podniz.size()==1) {
					podniz.resize(0);
					continue;
				}
				bool ima=false;
				for  (int i(0); i<konacni.size(); i++) {
					if (podniz==konacni.at(i))  ima=true;
				}

				if (!ima) konacni.push_back(podniz);
				podniz.resize(0);
			}
		}
	}

	return konacni;
}

int main ()
{
	std::vector<int> niz_brojeva;
	std::cout << "Unesite broj elemenata vektora: ";
	int broj_elemenata;
	std::cin >> broj_elemenata;
	std::cout << "Unesite elemente vektora: ";
	for (int i(0); i < broj_elemenata; i++) {
		int broj;
		std::cin >> broj;
		niz_brojeva.push_back(broj);
	}

	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int smjer;
	std::cin >> smjer;
	std::deque<std::vector<int>> max_niz;
	if (smjer==1) {
		max_niz=MaksimalniPodnizoviStepenaDvojke(niz_brojeva, Rastuci);
		std::cout<<"Maksimalni rastuci podnizovi: \n";
		for (int i(0); i<max_niz.size(); i++) {
			for (int j(0); j<max_niz.at(i).size(); j++) {
				std::cout << max_niz.at(i).at(j) << " ";
				if (j==max_niz.at(i).size()-1) std::cout << std::endl;
			}
		}
	}

	else if (smjer==2) {
		max_niz=MaksimalniPodnizoviStepenaDvojke(niz_brojeva, Opadajuci);
		std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
		for (int i(0); i<max_niz.size(); i++) {
			for (int j(0); j<max_niz.at(i).size(); j++) {
				std::cout << max_niz.at(i).at(j) << " ";
				if (j==max_niz.at(i).size()-1) std::cout << std::endl;
			}
		}


	}
	return 0;
}