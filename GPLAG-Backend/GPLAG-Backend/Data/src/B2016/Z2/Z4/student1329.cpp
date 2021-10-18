#include <iostream>
#include <vector>
#include <string>
#include <new>
#include <stdexcept>

int PotencijalniKrivci(char **(&pok), const std::vector<std::string> &potencijalni_krivci) {
	
	char **niz(nullptr);
	
	try {
		niz = new char*[potencijalni_krivci.size()];
		for(int i = 0; i < potencijalni_krivci.size(); i++) niz[i] = nullptr;
		try {
			for(int i = 0; i < potencijalni_krivci.size(); i++) niz[i] = new char[potencijalni_krivci[i].size() + 1];
			for(int i = 0; i < potencijalni_krivci.size(); i++) {
				int j(0);
				for(; j < potencijalni_krivci[i].size(); j++) 
					niz[i][j] = potencijalni_krivci[i][j];
				niz[i][j] = '\0';
			}
		}
		catch(...) {
			for(int i = 0; i < potencijalni_krivci.size(); i++) delete[] niz[i];
			delete[] niz;
			throw;
		}
	}
	catch(...) {
		throw std::bad_alloc();
	}
	
	pok = niz;
	return potencijalni_krivci.size();
}

int OdbaciOptuzbu(char **(&pok), int vel, std::string neduzan) {
	
	int broj_nullptr(0);
	bool obrisan(false);
	
	for(int i = 0; i < vel; i++) {
		if(pok[i] != nullptr) {
			if(neduzan == std::string(pok[i])) {
				delete[] pok[i];
				pok[i] = nullptr;
				broj_nullptr++;
				obrisan = true;
			}
		}
		else broj_nullptr++;
	}
	
	if(!obrisan) throw std::domain_error("Osoba sa imenom " + neduzan + " nije bila optuzena");
	if(broj_nullptr > 10) {
		char ** novi_pok(nullptr);
		try {
			novi_pok = new char*[vel - broj_nullptr];
			int j = 0;
			for(int i = 0; i < vel; i++) {
				if(pok[i] != nullptr) {
					novi_pok[j] = pok[i];
					j++;
				}
			}
			for(int i = 0; i < vel; i++) delete[] pok;
			pok = novi_pok;
			return vel - broj_nullptr;
		}
		catch(...) {
			return vel;
		}
	}
	
	return vel;
}

int DodajOptuzbu(char **(&pok), int vel, std::string krivac) {
	
	try {
		char *novi_krivac(nullptr);
		novi_krivac = new char[krivac.size() + 1];
		int h = 0;
		for(;h < krivac.size(); h++) novi_krivac[h] = krivac[h];
		novi_krivac[h] = '\0';
		
		bool upisan(false);
		
		for(int i = 0; i < vel; i++) {
			if(pok[i] == nullptr) {
				pok[i] = novi_krivac; upisan = true;
				break;
			}
		}
		
		if(!upisan) {
			try {
				char **novi_pok(nullptr);
				novi_pok = new char*[vel + 1];
				for(int i = 0; i < vel + 1; i++) {
					if(i != vel) novi_pok[i] = pok[i];
					else novi_pok[i] = novi_krivac;
				}
				delete[] pok;
				pok = novi_pok;
				return vel + 1;
			}
			catch(...) {
				delete[] novi_krivac;
				throw std::bad_alloc();
			}
		}
		else return vel;
	}
	catch(...) { throw std::bad_alloc(); }
	
	return vel;
}

void IzlistajOptuzbu(char **pok, int vel) {
	for(int i = 0; i < vel; i++) {
		if(pok[i] != nullptr) std::cout << pok[i] << std::endl;
	}
}

int main() {
	
	int n;
	char **niz(nullptr);
	
	try {
		std::cout << "Koliko potencijalnih krivaca zelite unijeti? " << std::endl;
		std::cin >> n;
		
		std::cin.ignore(10000, '\n');
		
		std::vector<std::string> v1(n);
		if(n != 0) {
			std::cout << "Unesite potencijalne krivce: " << std::endl;
			for(int i = 0; i < n; i++) std::getline(std::cin, v1[i]);
		}
			
		n = PotencijalniKrivci(niz, v1);
	
		std::cout << "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: " << std::endl;
		int opcija;
		std::cin >> opcija;
		while(opcija != 0) {
			std::cin.ignore(10000, '\n');
			if(opcija == 1) {
				std::cout << "Unesite ime novog optuzenog: " << std::endl;
				std::string krivac;
				std::getline(std::cin, krivac);
				n = DodajOptuzbu(niz, n, krivac);
			}
			else if(opcija == 2) {
				std::cout << "Unesite ime koje zelite izbaciti: " << std::endl;
				std::string neduzan;
				std::getline(std::cin, neduzan);
				n = OdbaciOptuzbu(niz, n, neduzan);
			}
			else if(opcija == 3) {
				IzlistajOptuzbu(niz, n);
			}
			std::cout << "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: " << std::endl;
			std::cin >> opcija;
		}
		
		for(int i = 0; i < n; i++) delete[] niz[i];
		delete[] niz;
	}
	catch(std::bad_alloc) { 
		std::cout << "Alokacija nije uspjela."; 
		for(int i = 0; i < n; i++) delete[] niz[i];
		delete[] niz;
	}
	catch(std::domain_error izuzetak) { 
		std::cout << izuzetak.what(); 
		for(int i = 0; i < n; i++) delete[] niz[i];
		delete[] niz;
	}
	
	return 0;
}