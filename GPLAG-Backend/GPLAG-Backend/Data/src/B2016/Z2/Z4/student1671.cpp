/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <cstring>

int PotencijalniKrivci(char **&ref_na_pok, std::vector<std::string> v) {
	char **pok;
	try {
		pok = new char*[v.size()];
	}
	catch (...) {
		throw;
	}
	try {
		for (int i = 0; i < v.size(); i++) pok[i] = new char[v[i].size()+1];
	}
	catch (...) {
		delete[] pok;
		throw;
	}
	for (int i = 0; i < v.size(); i++) {
		auto pocetak(v[i].begin());
		for (int j = 0; j < v[i].size(); j++) pok[i][j] = *pocetak++;
		pok[i][v[i].size()] = '\0';
	}
	ref_na_pok = pok;
	return v.size();
}

int OdbaciOptuzbu(char **&ref_na_pok, int velicina_niza, std::string s) {
	bool test(false);
	int nevin_i;
	for (int i = 0; i < velicina_niza; i++) {
		std::string pom(ref_na_pok[i]);
		if (ref_na_pok[i] != nullptr && pom == s) {
			test = true;
			nevin_i = i;
			break;
		}
		/*char *pocetak(ref_na_pok[i]);
		int j(0);
		while (pocetak != nullptr && *pocetak != '\0' && j < s.size() && *pocetak == s[j]) {
			pocetak++;
			j++;
		}
		if (*pocetak == '\0' && j == s.size()) {
			test = true;
			nevin_i = i;
			break;
		}*/
	}
	if (!test) throw std::domain_error ("Osoba sa imenom " + s + " nije bila optuzena");
	if (test) {
		delete[] ref_na_pok[nevin_i];
		ref_na_pok[nevin_i] = nullptr;
	}
	int brojac(0);
	for (int i = 0; i < velicina_niza; i++) {
		if (ref_na_pok[i] == nullptr) brojac++;
	}
	if (brojac <= 10) return velicina_niza;
	char **pok(nullptr);
	try {
		pok = new char*[velicina_niza-brojac];
		try {
			for (int i = 0; i < velicina_niza; i++) 
				if (ref_na_pok[i] != nullptr) pok[i] = ref_na_pok[i];
			delete[] ref_na_pok;
			ref_na_pok = pok;
		}
		catch (...) {
			delete[] pok;	
		}
	}
	catch(...) {
		return velicina_niza;
	}
	return velicina_niza-brojac;
}
int DodajOptuzbu(char **&ref_na_pok, int velicina_niza, std::string s) {
	char *pok;
	try {
		pok = new char[s.size()+1];
	}
	catch (...) {
		throw;
	}
	std::strcpy(pok, s.c_str());
	for (int i = 0; i < velicina_niza; i++) {
		if (ref_na_pok[i] == nullptr) {
			ref_na_pok[i] = pok;
			pok = nullptr;
			return velicina_niza;
		}
	}
	char **pom;
	try {
		pom = new char*[velicina_niza+1];
	}
	catch (...) {
		throw;
	}
	for (int i = 0; i < velicina_niza; i++) 
		pom[i] = ref_na_pok[i];
	delete[] ref_na_pok;
	pom[velicina_niza] = pok;
	ref_na_pok = pom;
	pom = nullptr;
	return velicina_niza+1;
}
void IzlistajOptuzbu(char **pok, int velicina_niza) {
	for (int i = 0; i < velicina_niza; i++)
		if (pok[i] != nullptr) std::cout << pok[i] << std::endl;
}

int main ()
{
	try {
		int n;
		std::cout << "Koliko potencijalnih krivaca zelite unijeti? " << std::endl;
		std::cin >> n;
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::vector<std::string> v(n);
		std::cout << "Unesite potencijalne krivce: " << std::endl;
		for (int i = 0; i < n; i++) {
			std::string s;
			std::getline(std::cin, s);
			v[i] = s;
		}
		char **pok;
		auto velicina1(PotencijalniKrivci(pok, v));
		char opcija;
		do {
			int &velicina(velicina1);
			std::cout << "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: " << std::endl;
			std::cin >> opcija;
			switch (opcija) {
				case '1': {
					std::cout << "Unesite ime novog optuzenog: " << std::endl;
					std::cin.clear();
					std::cin.ignore(10000, '\n');
					std::string s;
					std::getline(std::cin, s);
					velicina = DodajOptuzbu(pok, velicina, s);
				} break;
				case '2': {
					std::cout << "Unesite ime koje zelite izbaciti: " << std::endl;
					std::cin.clear();
					std::cin.ignore(10000, '\n');
					std::string s;
					std::getline(std::cin, s);
					velicina = OdbaciOptuzbu(pok, velicina, s);
				} break;
				case '3': {
					IzlistajOptuzbu(pok, velicina);
				} break;
			}
		} while (opcija != '0');
		for (int i = 0; i < velicina1; i++) delete[] pok[i];
		delete[] pok;
	}
	catch(std::domain_error tekst) {
		std::cout << tekst.what();
	}
	catch(...) {
		
	}
	return 0;
}