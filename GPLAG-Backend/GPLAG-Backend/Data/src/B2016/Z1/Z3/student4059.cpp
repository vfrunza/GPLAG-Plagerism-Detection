/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include<iostream>
#include<vector>

using namespace std;

std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> niz) {
	std::vector<std::vector<double>> podnizovi;
	
	if(niz.size() < 2)
		return podnizovi;
	
	bool podniz = false;
	int temp = 0;
	for(int i = 0; i < niz.size() - 1; i++) {
		if(podniz == false) { // nije jos otkriven novi podniz
			if(niz[i] <= niz[i+1]) { // ubacujemo oba u novi podniz
				podnizovi.resize(podnizovi.size() + 1);
				podnizovi[temp].push_back(niz[i]);
				podnizovi[temp].push_back(niz[i+1]);
				podniz = true;
			}
		}
		else {
			if(niz[i] <= niz[i+1]) {
				podnizovi[temp].push_back(niz[i+1]);
				podniz = true;
			}
			else { // treba eventualno praviti novi podniz
				podniz = false;
				temp++;
			}
		}
	}
	return podnizovi;
}

std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> niz) {
	std::vector<std::vector<double>> podnizovi;
	
	if(niz.size() < 2) 
		return podnizovi;
		
	bool podniz = false;
	int temp = 0;
	for(int i = 0; i < niz.size() - 1; i++) {
		if(podniz == false) {
			if(niz[i] >= niz[i+1]) {
				podnizovi.resize(podnizovi.size() + 1);
				podnizovi[temp].push_back(niz[i]);
				podnizovi[temp].push_back(niz[i+1]);
				podniz = true;
			}
		}
		else {
			if(niz[i] >= niz[i+1]) {
				podnizovi[temp].push_back(niz[i+1]);
				podniz = true;
			}
			else {
				podniz = false;
				temp++;
			}
		}
	}
	return podnizovi;
}

int main ()
{
	std::cout << "Unesite broj elemenata vektora: ";
	int broj_elemenata;
	double broj;
	std::vector<double> niz;
	std::cin >> broj_elemenata;
	std::cout << "Unesite elemente vektora: ";
	for(int i = 0; i < broj_elemenata; i++) {
		std::cin >> broj;
		niz.push_back(broj);
	}
	int max_rastuci = 0;
	int max_opadajuci = 0;
	
	std::vector<std::vector<double>> rastuci = RastuciPodnizovi(niz);
	std::vector<std::vector<double>> opadajuci = OpadajuciPodnizovi(niz);
	
	for(int i = 0; i < rastuci.size(); i++) {
		if(rastuci[i].size() > max_rastuci)
			max_rastuci = rastuci[i].size();
	}
	
	for(int i = 0; i < opadajuci.size(); i ++) {
		if(opadajuci[i].size() > max_opadajuci)
			max_opadajuci = opadajuci[i].size();
	}
	
	std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	for(int i = 0; i < rastuci.size(); i++) {
		if(rastuci[i].size() == max_rastuci) {
			for(int j = 0; j < rastuci[i].size(); j++) {
				std::cout << rastuci[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
	std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	for(int i = 0; i < opadajuci.size(); i++) {
		if(opadajuci[i].size() == max_opadajuci) {
			for(int j = 0; j < opadajuci[i].size(); j++) {
				std::cout << opadajuci[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
	
	return 0;
}