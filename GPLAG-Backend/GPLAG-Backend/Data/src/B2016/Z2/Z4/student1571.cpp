#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <cstring>

int PotencijalniKrivci (char **&pok, std::vector<std::string> v) {
	char **niz = nullptr;
	int brojac (0);
	try {
		niz = new char *[v.size()];
		for (int i=0; i<v.size(); i++)
			niz[i] = nullptr;
		try {
			for (int j=0; j<v.size(); j++) {
				int duzina = v[j].size();
				niz[j] = new char [duzina+1];
				std::strcpy (niz[j], v[j].c_str());
				brojac++;
			}
		}
		catch(...) {
			for (int i=0; i<v.size(); i++) delete[] niz[i];
			delete[] niz;
			throw std::bad_alloc();
		}
	}
	catch (...) {
		delete[] niz;
		throw  std::bad_alloc();
	}
	pok = niz;
	return brojac;
}
int OdbaciOptuzbu (char **&pok, int n, std::string ime) {
	char **novi = nullptr;
	std::string izuzetak = "Osoba sa imenom " + ime + " nije bila optuzena";
	int br_nullptr (0);
	bool ne_postoji (true);
	for (int i=0; i<n; i++) {
		if (pok[i]!=nullptr && pok[i] == ime) {
			delete[] pok[i];
			pok[i] = nullptr;
			br_nullptr++;
			ne_postoji = false;
			break;
		}
	}
	if (ne_postoji) throw std::domain_error (izuzetak);
	if (br_nullptr <= 10) return n;
	else {
		 try {
		 	for (int i=0; i<n; i++) novi[i] = nullptr;
		 	try {
		 		for (int i=0; i<n; i++) {
		 			if (pok[i] != nullptr) {
		 				novi[i] = pok[i];
		 				delete[] pok[i];
		 				pok[i] = nullptr;
		 			}
		 			else continue;
		 		}
		 	}
		 	catch (...) {
		 		for (int i=0; i<n; i++) delete[] novi[i];
		 		delete[] novi;
		 	}
		 }
		 catch (...) {
		 	delete[] novi;
		 }
	}
	pok = novi;
	return n;
}
int DodajOptuzbu (char **&pok, int n, std::string s) {
	char *novi = nullptr;
	bool ima_nullptr = false;
	int indeks;
	try {
		int duzina = s.length();
		novi = new char [duzina+1];
		std::strcpy (novi, s.c_str());
		for (int i=0; i<n; i++) {
			if (pok[i] == nullptr) {
				ima_nullptr = true;
				indeks = i;
				break;
			}
		}
	}
	catch (...) {
		delete[] novi;
		throw std::bad_alloc ();
	}
	if (ima_nullptr) {
		pok[indeks] = novi;
	}
	else {
		char **pomocni = new char *[n+1];
		try {
			int i;
			for (i=0; i<n+1; i++) pomocni[i] = nullptr;
			try {
				for (i=0; i<n; i++)  pomocni[i] = pok[i]; 
				delete[] pok;
				pomocni[n] = novi;
				n++;
			}
			catch(...) {
				for (int i=0; i<n+1; i++) delete[] pomocni[i];
				delete[] pomocni;
				throw std::bad_alloc();
			}
		}
		catch(...) {
			delete[] pomocni;
			throw std::bad_alloc();
		}
		pok = pomocni;
	}
	return n;
}
void IzlistajOptuzbu (char **pok, int n) {
	for (int i=0; i<n; i++) {
		if (pok[i] == nullptr) continue;
		else std::cout << pok[i]<< std::endl;
	}
}
int main ()
{
	std::cout << "Koliko potencijalnih krivaca zelite unijeti? " << std::endl;
	int n;
	bool obrisano (false);
	char **pok = nullptr;
	std::cin >> n;
	std::cout << "Unesite potencijalne krivce: " << std::endl;
	std::vector<std::string> v;
	for (int i=0; i<n; i++) {
		std::cin >> std::ws;
		std::string ime;
		std::getline (std::cin, ime);
		v.push_back(ime);
	}
	try {
		n = PotencijalniKrivci(pok, v);
	}
	catch (std::bad_alloc) {
		std::cout << "Neuspjela alokacija";
		obrisano = true;
	}
	for (;;) {
		std::cout << "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: " << std::endl;
		int izbor;
		std::cin >> izbor;
		if (izbor == 0) break;
		if (izbor == 1) {
			std::cout << "Unesite ime novog optuzenog: " << std::endl;
			std::string ime;
			std::cin >> std::ws;
			std::getline (std::cin, ime);
			try {
				n = DodajOptuzbu(pok, n, ime);
			}
			catch (std::bad_alloc) {
				std::cout << "Neuspjela alokacija" << std::endl;
				obrisano = true;
			}
		}
		else if (izbor == 2) {
			std::cout << "Unesite ime koje zelite izbaciti: " << std::endl;
			std::string ime;
			std::cin >> std::ws;
			std::getline (std::cin, ime);
			try {
				n = OdbaciOptuzbu(pok, n, ime);
			}
			catch (std::domain_error poruka) {
				std::cout << poruka.what() << std::endl;
			}
		}
		else if (izbor == 3) {
			IzlistajOptuzbu(pok, n);
		}
	}
	for (int i=0; i<n; i++) delete[] pok[i];
	delete[] pok;
	
  	return 0;
}