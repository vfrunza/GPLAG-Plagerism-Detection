#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
#include <string>

typedef std::vector<std::string> VekString;

void OslobodiMemoriju(char **pok, int vel = 0) {
	if(pok == nullptr) return;
	for(int i=0; i<vel; i++)
		delete[] pok[i];
	delete[] pok;
	pok = nullptr;
}

int PotencijalniKrivci(char **&ref, VekString mat) {
	char **pok(nullptr);
	try {
		pok = new char *[mat.size()];
		for(int i=0; i<mat.size(); i++) 
			pok[i] = nullptr;
		for(int i=0; i<mat.size(); i++) {
			pok[i] = new char[mat[i].size()+1];
			for(int j=0; j<mat[i].size(); j++)
				pok[i][j] = mat[i][j];
			pok[i][mat[i].size()] = '\0';
			ref = pok;
		}
	}
	catch(...) {
		OslobodiMemoriju(pok, mat.size());
		throw;
	}
	return mat.size();
}

int OdbaciOptuzbu(char **&ref, int &vel, std::string s) {
	char **pok(ref), **spasko(nullptr);
	bool a(true);
	int indeks(0);
	for(int i=0; i<vel; i++) {
		if(s == std::string(pok[i])) {
			a = false; 
			indeks = i;
			break;
		}
	}
	if(a) throw std::domain_error("Osoba sa imenom " + s + " nije bila optuzena");
	delete[] pok[indeks];
	pok[indeks] = nullptr;
	int br(0);
	for(int i=0; i<vel; i++)
		if(pok[i] == nullptr) br++;
	if(br > 10) {
		spasko = new char*[vel-br];
		for(int i=0; i<vel-br; i++)
			spasko[i] = nullptr;
		try {
			int k(0);
			for(int i=0; i<vel; i++) 
				if(pok[i] != nullptr) {
					spasko[k] = pok[i];
					k++;
				}
			ref = spasko;
			for(int i=0; i<vel; i++)
				pok[i] = nullptr;
			OslobodiMemoriju(pok, vel);	
			vel -= br;
		}
		catch(...) {
			for(int i=0; i<vel; i++)
				spasko[i] = nullptr;
			delete[] spasko;
		}
	}
	return vel;
}

int DodajOptuzbu(char **&ref, int &vel, std::string s) {
	char **pok(ref), **spasko(nullptr);
	if(s.size() == 0) return vel;
	char *novi(nullptr);
	bool a(true);
	try {
		novi = new char[s.size()+1];
		for(int i=0; i<s.size(); i++) 
			novi[i] = s[i];
		novi[s.size()] = '\0';
		for(int i=0; i<vel; i++) 
			if(pok[i] == nullptr) {
				pok[i] = novi;
				a = false;
				break;
			}
		if(a) {
			spasko = new char*[vel+1];
			for(int i=0; i<vel+1; i++)
				spasko[i] = nullptr;
			try {
				for(int i=0; i<vel; i++) 
					spasko[i] = pok[i];
				spasko[vel] = novi;
				novi = nullptr;
				ref = spasko;
				for(int i=0; i<vel; i++)
					pok[i] = nullptr;
				OslobodiMemoriju(pok, vel);
				vel++;
			}
			catch(...) {
				for(int i=0; i<vel; i++)
					spasko[i] = nullptr;
				delete[] spasko;
				throw;
			}
		}
	}
	catch(...) {
		delete[] novi;
		throw;
	}
	return vel;
}

void IzlistajOptuzbu(char **pok, int vel) {
	for(int i=0; i<vel; i++) 
		if(pok[i] != nullptr) {
			std::cout << pok[i];
			std::cout << std::endl;
		}
}

int main () {
	int vel;
	char **pok(nullptr);
	std::cout << "Koliko potencijalnih krivaca zelite unijeti? " << std::endl;
	std::cin >> vel;
	VekString popis;
	std::cin.ignore(1000, '\n');
	std::cout << "Unesite potencijalne krivce: " << std::endl;
	for(int i=0; i<vel; i++) {
		std::string temp;
		std::getline(std::cin, temp);
		popis.push_back(temp);
	}
	try {
		vel = PotencijalniKrivci(pok, popis);
		for(;;) {
			int komanda;
			std::cout << "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog " << "3 za izlistavanje optuzenih, 0 za kraj: " << std::endl;
			std::cin >> komanda;
			std::cin.ignore(1000, '\n');
			if(komanda == 0) break;
			else if(komanda == 1)  {
				std::cout << "Unesite ime novog optuzenog: " << std::endl;
				std::string ime;
				std::getline(std::cin, ime);
				try {
					vel = DodajOptuzbu(pok, vel, ime);
				}
				catch(...) {
					throw;
				}
			}
			else if(komanda == 2) {
				std::cout << "Unesite ime koje zelite izbaciti: " << std::endl;
				std::string ime;
				std::getline(std::cin, ime);
				try {
					vel = OdbaciOptuzbu(pok, vel, ime);
				}
				catch(std::domain_error e) {
					std::cout << e.what() << std::endl;	
					throw;
				}
			}
			else if(komanda == 3) IzlistajOptuzbu(pok, vel);
		}
		OslobodiMemoriju(pok, vel);
	}
	catch(...) {
		OslobodiMemoriju(pok, vel);
	}
	return 0;
}