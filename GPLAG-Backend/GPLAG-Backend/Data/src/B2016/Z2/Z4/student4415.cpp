/*B 16/17, Zadaća 2, Zadatak 4

	NAPOMENA: i javni ATo-vi su dio postavke

	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include "TestCurenja.h"



int PotencijalniKrivci (char** &pok,std::vector<std::string> v1)
{
	char** imena(nullptr);
	try {
		imena = new char*[v1.size()];
	} catch (std::bad_alloc) {
		return 0;
	}

	for (int i = 0; i < v1.size(); i++) {
		imena[i] = nullptr;
	}

	try {
		for (int i = 0; i < v1.size(); i++) {
			imena[i] = new char[v1[i].size()+1];
		}
	} catch (std::bad_alloc) {
		for (int i = 0; i < v1.size(); i++) {
			delete[] imena[i];
		}
		delete[] imena;
		throw;
	}
	int i(0);
	int j(0);
	for (i = 0; i < v1.size(); i++) {
		for (j = 0; j < v1[i].size(); j++) {
			imena[i][j] = v1[i][j];
		}
		imena[i][j] = '\0';
	}
	
	pok = imena;
	return v1.size();
}

int OdbaciOptuzbu (char** &pok1,int vel,std::string s)
{
	bool nalazi_se(false);
	int pozicija(0);
	for (int i = 0; i < vel; i++) {
		if (std::string(pok1[i]) == s) {
			nalazi_se = true;
			pozicija = i;
			break;
		}
	}
	std::string izutezak("Osoba sa imenom ");
	izutezak +=s + " nije bila optuzena"; 
	if (nalazi_se == false) throw std::domain_error (izutezak);
	delete[] pok1[pozicija];
	pok1[pozicija] = nullptr;
	int brojac(0);
	for (int i = 0; i < vel; i++) {
		if(pok1[i] == nullptr) brojac++;
	}
	if (brojac > 10) {
		char** pok2(nullptr);
		try {
			pok2 = new char*[vel-brojac];
		} catch (std::bad_alloc) {
			throw;
		}
		for (int i = 0; i < vel-brojac; i++) {
			pok2[i] = nullptr;
		}
		int j(0);
		for (int i = 0; i < vel-brojac and j < vel;) {
			if(pok1[j] == nullptr) j++;
			else {
				pok2[i] = pok1[j];
				i++;
				j++;
			}
		}
		
		delete[] pok1;
		pok1 = pok2;
		return vel -brojac;
	}
	return vel;
	
}

int DodajOptuzbu (char** &pok1,int vel,std::string s)
{
	char* ime(nullptr);
	try {
		ime = new char[s.size()+1];
		int i(0);
		for (i = 0; i < s.size(); i++) {
			ime[i] = s[i];
		}
		ime[i] = '\0';
	} catch (std::bad_alloc) {
		throw;
	}
	for (int i = 0; i < vel; i++) {
		if(pok1[i] == nullptr) {
			pok1[i] = ime;
			return vel;
		}
	}
	
	char** pok2(nullptr);
	try {
		
		pok2 = new char*[vel+1];
		for (int i = 0; i < vel +1; i++) {
			pok2[i] = nullptr;
		}
		for (int i = 0; i < vel; i++) {
			pok2[i] = pok1[i];
		}
		pok2[vel] = ime;
		delete[] pok1; 		
		pok1 = pok2;		
		return vel+1;
		
	} catch (std::bad_alloc) {
		delete[] ime;
		throw;
	}
    return vel;
}

void IzlistajOptuzbu (char** const &pok,int vel)
{
	for (int i = 0; i < vel; i++) {
		if(pok[i] != nullptr) std::cout << pok[i] << std::endl;
	}
}


int main ()
{
	std::cout << "Koliko potencijalnih krivaca zelite unijeti? " << std::endl;
	int n;
	std::cin >> n;
	std::vector<std::string> imena(n);
	std::cout << "Unesite potencijalne krivce: "<<std::endl;
	for (auto &i : imena) {
		std::cin >> i;
	}
	char** p(nullptr);
	int opcija(0);
	int vel(PotencijalniKrivci(p,imena));
	std::string ime;
	do {
		std::cout << "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: " << std::endl;
		std::cin >> opcija;
		switch (opcija) {
			case 1 :  std::cout << "Unesite ime novog optuzenog: " << std::endl; std::cin >> ime; vel = DodajOptuzbu(p,vel,ime); break;
			case 2 :  std::cout << "Unesite ime koje zelite izbaciti: " << std::endl; std::cin >> ime; vel = OdbaciOptuzbu(p,vel,ime); break;
			case 3 :  IzlistajOptuzbu(p,vel); break;
			case 0 :  break;
			default : break;
		}
	}while(opcija != 0);
	for (int i = 0; i < vel; i++) {
	    delete[] p[i];
	}
	delete[] p;
	return 0;
}