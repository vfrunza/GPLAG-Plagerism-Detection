/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

int PotencijalniKrivci(char **&alociraniSpisakKrivaca, std::vector<std::string> spisakKrivaca) {
	//char **alociraniSpisak(new char*[spisakKrivaca.size()]{nullptr});
	alociraniSpisakKrivaca = new char*[spisakKrivaca.size()]{nullptr};
	int brojAlociranih(0);
	try {
		for (int i = 0; i < spisakKrivaca.size(); i++) {
			alociraniSpisakKrivaca[i] = new char[spisakKrivaca[i].size() + 1];
			brojAlociranih++;
			for (int j = 0; j < spisakKrivaca[i].size(); j++)
				alociraniSpisakKrivaca[i][j] = spisakKrivaca[i][j];
			alociraniSpisakKrivaca[i][spisakKrivaca[i].size()] = '\0';
		}
	//	alociraniSpisakKrivaca = alociraniSpisak;
		return brojAlociranih;
	}
	catch(...) {
		for (int i = 0; i < brojAlociranih; i++)
			delete[] alociraniSpisakKrivaca[i];
		delete[] alociraniSpisakKrivaca;
		throw;
	}
	return -1;
}

int OdbaciOptuzbu(char **&spisakKrivaca, int n, std::string imeOptuzenog) {
	bool jednaki(true);
	for (int i = 0; i < n; i++) {
		jednaki = true;
		if (spisakKrivaca[i] == nullptr) continue;
		for (int j = 0; spisakKrivaca[i][j] != '\0'; j++) {
			if (spisakKrivaca[i][j] != imeOptuzenog[j]) {
				jednaki = false;
				break;
			}
		}
		if (jednaki) {
			delete [] spisakKrivaca[i];
			spisakKrivaca[i] = nullptr;
			break;
		}
	}
	if (!jednaki) {
		throw std::domain_error("Osoba sa imenom " + imeOptuzenog + " nije bila optuzena\n");
	}
	int broj(0);
	for (int i = 0; i < n; i++)
		if (spisakKrivaca[i] == nullptr) broj++;
	if (broj > 10) {
		try {
			char **noviSpisak(new char* [n - broj]{nullptr});
			int tmp(0);
			for (int i = 0; i < n; i++) 	
				if (spisakKrivaca[i] != nullptr) noviSpisak[tmp++] = spisakKrivaca[i];
				else delete[] spisakKrivaca[i];
			delete [] spisakKrivaca;
			spisakKrivaca = noviSpisak;
		}
		catch(...){}
		return n - broj;
	}
	return n;
}

int DodajOptuzbu(char **&spisakKrivaca, int n, std::string imeOptuzenog) {
	try {
		char *alociranoIme(new char[imeOptuzenog.size() + 1]);
		for (int i = 0; i < imeOptuzenog.size(); i++) 
			alociranoIme[i] = imeOptuzenog[i];
		alociranoIme[imeOptuzenog.size()] = '\0';
		for (int i = 0; i < n; i++) 
			if (spisakKrivaca[i] == nullptr) {
				spisakKrivaca[i] = alociranoIme;
				return n;
			}
		try {
				
			char **noviSpisak(new char* [n + 1] {nullptr});
			for (int i = 0; i < n; i++) 
				noviSpisak[i] = spisakKrivaca[i];
			noviSpisak[n] = alociranoIme;
			delete [] spisakKrivaca;
			spisakKrivaca = noviSpisak;
			return n + 1;
		}
		catch (...) {
			delete alociranoIme;
			throw;
		}
	}
	catch (...) {
		throw;
	}
}

void IzlistajOptuzbu(char **spisakKrivaca, int n) {
	for (int i = 0; i < n; i++) {
		if (spisakKrivaca[i] != nullptr) 
			for (int j = 0; spisakKrivaca[i][j] != '\0'; j++) 
				std::cout << spisakKrivaca[i][j];
		else continue;
		if (i != n - 1)
			std::cout << "\n";
	}
}

int main () {
	std::cout << "Koliko potencijalnih krivaca zelite unijeti? ";
	int n;
	std::cin >> n;
	std::cin.ignore(10000, '\n');
	std::vector<std::string> krivciKont;
	std::cout << "\nUnesite potencijalne krivce: ";
	for (int i = 0; i < n; i++) {
		std::string tmp;
		std::getline(std::cin, tmp);
		krivciKont.push_back(tmp);
	}
	char **krivci(nullptr);
	try {
		n = PotencijalniKrivci(krivci, krivciKont);
	}
	catch (std::bad_alloc e) {
		std::cout << e.what();
	}
	int unos;
	do {
		std::cout << "\nOdaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: \n";
		std::cin >> unos;
		std::cin.ignore(10000, '\n');
		std::string tmp;
		switch (unos) {
			case 1:
				std::cout << "Unesite ime novog optuzenog: ";
				std::getline(std::cin, tmp);
				try {
					n = DodajOptuzbu(krivci, n, tmp);
				}
				catch (...) {
					continue;
				}
				break;
			case 2:
				std::cout << "Unesite ime koje zelite izbaciti: ";
				std::getline(std::cin, tmp);
				try {
					n = OdbaciOptuzbu(krivci, n, tmp);
				}
				catch (std::domain_error e) {
					std::cout << e.what();
				}
				break;
			case 3:
				IzlistajOptuzbu(krivci, n);
				break;
			case 0:
				break;
			default:
				break;
		}
	} while (unos != 0);
	for (int i = 0; i < n; i++)
		delete[] krivci[i];
	delete[] krivci;
	return 0;
}