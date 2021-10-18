/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stdexcept>

typedef std::vector<std::string> VektorStringova;

int PotencijalniKrivci(char **&ref_na_pok, VektorStringova vs) {
	int brojac{};
	try {
		ref_na_pok=new char *[vs.size()];
		try {
			while(brojac<vs.size()) {
				ref_na_pok[brojac]=new char[vs[brojac].size()+1];
				std::strcpy(ref_na_pok[brojac], vs[brojac].c_str());
				brojac++;
			}
		}
		catch(std::bad_alloc) {
			for (int i=0; i<brojac; i++) delete[] ref_na_pok[i];
			delete[] ref_na_pok;
			throw;
		}
	}
	catch(std::bad_alloc) {
		throw;
	}
	return brojac;
}

int OdbaciOptuzbu(char **&ref_na_pok, int velicina, std::string ime_nevinog) {
	bool pronadjen=false;
	for (int i=0; i<velicina; i++) {
		std::string tmp=ime_nevinog;
		if (ref_na_pok[i]!=nullptr && !(std::strcmp(ref_na_pok[i], tmp.c_str()))) {
			pronadjen=true;
			delete[] ref_na_pok[i];
			ref_na_pok[i]=nullptr;
		}
	}
	if (!pronadjen)
		throw std::domain_error("Osoba sa imenom " + ime_nevinog + " nije bila optuzena");
	int brojac{};
	for (int i=0; i<velicina; i++)
		if (ref_na_pok[i]==nullptr) brojac++;
	if (brojac<=10) return velicina;
	char **pok=nullptr;
	int nova_velicina=velicina-brojac;
	int indeks{};
	try {
		pok=new char *[nova_velicina];
		for (int i=0; i<nova_velicina; i++) pok[i]=nullptr;
		try {	
			for (int i=0; i<velicina; i++) {
				if (ref_na_pok[i]!=nullptr) {
					int duzina=std::strlen(ref_na_pok[i])+1;
					pok[indeks]=new char[duzina+1];
					std::strcpy(pok[indeks], ref_na_pok[i]);
					indeks++;
				}
			}
		}
		catch(std::bad_alloc) {
			for (int i=0; i<nova_velicina; i++) delete[] pok[i];
			delete[] pok;
			return velicina;
		}
	}
	catch(std::bad_alloc) {
		return velicina;
	}
	for (int i=0; i<velicina; i++) delete[] ref_na_pok[i];
	delete[] ref_na_pok;
	ref_na_pok=pok;
	return nova_velicina;
}

int DodajOptuzbu(char **&ref_na_pok, int velicina, std::string ime_krivca) {
	char *pok1=nullptr;
	char **pok2=nullptr;
	try {
		pok1=new char[ime_krivca.size()+1];
		std::strcpy(pok1, ime_krivca.c_str());
		bool pronadjen=false;
		for (int i=0; i<velicina; i++) 
			if (ref_na_pok[i]==nullptr) {
				pronadjen=true;
				ref_na_pok[i]=pok1;
				delete[] pok1;
				return velicina;
			}
		if (!pronadjen) {
			try{
				int nova_velicina=velicina+1;
				pok2=new char *[nova_velicina];
				for (int i=0; i<nova_velicina; i++) pok2[i]=nullptr;
				for (int i=0; i<nova_velicina; i++) {
					if (i==nova_velicina-1) {
						try {
							pok2[i]=new char[ime_krivca.size()+1];
							std::strcpy(pok2[i], pok1);
							delete[] pok1;
						}
						catch(std::bad_alloc) {
							throw;
						}
					}
					else {
						int duzina=std::strlen(ref_na_pok[i])+1;
						pok2[i]=new char[duzina];
						std::strcpy(pok2[i], ref_na_pok[i]);
						delete[] ref_na_pok[i];
					}
				}
				delete[] ref_na_pok;
			}
			catch(std::bad_alloc) {
				delete[] pok1;
				throw;
			}
		}
	}
	catch(std::bad_alloc) {
		throw;
	}
	ref_na_pok=pok2;
	return velicina+1;
}

void IzlistajOptuzbu(char **pok, int velicina) {
	for (int i=0; i<velicina; i++)
		if (pok[i]!=nullptr) 
			std::cout << pok[i] << std::endl;
}

int main () {
	int broj_potencijalnih_krivaca{};
	std::cout << "Koliko potencijalnih krivaca zelite unijeti? " << std::endl;
	std::cin >> broj_potencijalnih_krivaca;
	std::cout << "Unesite potencijalne krivce: " << std::endl;
	VektorStringova potencijalni_krivci (broj_potencijalnih_krivaca);
	std::cin.ignore(10000, '\n');
	for (int i=0; i<broj_potencijalnih_krivaca; i++)
		std::getline(std::cin, potencijalni_krivci[i]);
	char **nizPotencijalnih;
	int velicina{};
	try {
		velicina=PotencijalniKrivci(nizPotencijalnih, potencijalni_krivci);
		int opcija{};
		do {
			std::cout << "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: " << std::endl;
			std::cin >> opcija;
			std::cin.ignore(10000,'\n');
			if (opcija==1) {
				std::cout << "Unesite ime novog optuzenog: " << std::endl;
				std::string novi_optuzeni;
				std::getline(std::cin, novi_optuzeni);
				velicina=DodajOptuzbu(nizPotencijalnih, velicina, novi_optuzeni);
			}
			else if (opcija==2) {
				std::cout << "Unesite ime koje zelite izbaciti: " << std::endl;
				std::string nevin_je;
				std::getline(std::cin, nevin_je);
				try {
					velicina=OdbaciOptuzbu(nizPotencijalnih, velicina, nevin_je);
				}
				catch(std::domain_error izuzetak) {
					for (int i=0; i<velicina; i++) delete[] nizPotencijalnih[i];
					delete[] nizPotencijalnih;
					std::cout << izuzetak.what() << std::endl;
				}
			}
			else if (opcija==3) {
				IzlistajOptuzbu(nizPotencijalnih, velicina);
			}
			else if (opcija==0) break;
		} while(opcija!=0);
	}
	catch(std::bad_alloc) {
		for (int i=0; i<velicina; i++) delete[] nizPotencijalnih[i];
		delete[] nizPotencijalnih;
	}
	for (int i=0; i<velicina; i++) delete[] nizPotencijalnih[i];
	delete[] nizPotencijalnih;
	return 0;
}