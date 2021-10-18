/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <string>
#include <cstring>
#include <vector>
#include <stdexcept>
#include <iostream>

int PotencijalniKrivci(char **&niz_imena, std::vector<std::string> vektor_imena);
int OdbaciOptuzbu(char **&niz_imena, int velicina, std::string za_odbaciti);
int DodajOptuzbu(char **&niz_imena, int velicina, std::string za_dodati);
void IzlistajOptuzbu(char **niz_imena, int velicina);

int main ()
{
	int broj_krivaca;
	std::vector<std::string> potencijalni_krivci;
	char **optuzeni;
	
	std::cout << "Koliko potencijalnih krivaca zelite unijeti? " << std::endl;
	std::cin >> broj_krivaca;
	std::cin.ignore(100, '\n');
	
	std::cout << "Unesite potencijalne krivce: " << std::endl;
	for (int i = 0; i < broj_krivaca; i++) {
		std::string trenutni;
		std::getline(std::cin, trenutni);
		potencijalni_krivci.push_back(trenutni);
	}
	
	broj_krivaca = PotencijalniKrivci(optuzeni, potencijalni_krivci);
	
	int izbor = -1;
	while(izbor != 0) {
		std::cout << "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: " << std::endl;
		std::cin >> izbor;
		std::cin.ignore(100, '\n');
		
		std::string ime;
		
		switch(izbor) {
			case 0:
				for (int i = 0; i < broj_krivaca; i++)
					delete[] optuzeni[i];
				delete[] optuzeni;
				break;
			case 1:
				std::cout << "Unesite ime novog optuzenog: " << std::endl;
				std::getline(std::cin, ime);
				broj_krivaca = DodajOptuzbu(optuzeni, broj_krivaca, ime);
				break;
			case 2:
				std::cout << "Unesite ime koje zelite izbaciti: " << std::endl;
				std::getline(std::cin, ime);
				broj_krivaca = OdbaciOptuzbu(optuzeni, broj_krivaca, ime);
				break;
			case 3:
				IzlistajOptuzbu(optuzeni, broj_krivaca);
				break;
			default:
				break;
		}
	}
	
	return 0;
}

int PotencijalniKrivci(char **&niz_imena, std::vector<std::string> vektor_imena) {
	try {
		niz_imena = new char*[vektor_imena.size()];
	} catch(std::bad_alloc izuzetak) {
		delete[] niz_imena;
		
		throw izuzetak;
	}
	
	for (int i = 0; i < vektor_imena.size(); i++) {
		try {
			// dodajemo +1 za '\0'
			niz_imena[i] = new char[vektor_imena[i].size() + 1];
			
			int j;
			for (j = 0; j < vektor_imena[i].size(); j++)
				niz_imena[i][j] = vektor_imena[i][j];
			
			niz_imena[i][j] = '\0';
		} catch(std::bad_alloc izuzetak) {
			for (int k = 0; k < i; k++)
				delete[] niz_imena[k];
				
			delete[] niz_imena;
			
			throw izuzetak;
		}
	}
		
	return vektor_imena.size();
}

int OdbaciOptuzbu(char **&niz_imena, int velicina, std::string za_odbaciti) {
	for (int i = 0; i < velicina; i++) {
		if (niz_imena[i] == za_odbaciti) {
			delete[] niz_imena[i];
			niz_imena[i] = nullptr;
			
			int broj_obrisanih = 0;
			for (int j = 0; j < velicina; j++) 
				if (niz_imena[i] == nullptr)
					broj_obrisanih += 1;
					
			if (broj_obrisanih > 10) {
				char **novi_niz;
				try {
					novi_niz = new char*[velicina - broj_obrisanih];
				} catch(std::bad_alloc izuzetak) {
					return velicina;
				}
				
				int trenutni_novi = 0;
				for (int j = 0; j < velicina; j++) {
					if (niz_imena[j] != nullptr) {
						try {
							novi_niz[trenutni_novi] = new char[std::strlen(niz_imena[j])];
						} catch(std::bad_alloc izuzetak) {
							for (int k = 0; k < trenutni_novi; k++)
								delete[] novi_niz[k];
							
							delete[] novi_niz;
							
							return velicina;
						}
						
						std::strcpy(novi_niz[trenutni_novi++], niz_imena[j]);
					}
				}
				
				for (int j = 0; j < velicina; j++)
					delete[] niz_imena[j];
					
				delete[] niz_imena;
				
				niz_imena = novi_niz;
				
				return velicina - broj_obrisanih;
			}
			
			return velicina;
		}
	}
	
	throw std::domain_error("Osoba sa imenom " + za_odbaciti + " nije bila optuzena");
	
	return velicina;
}

int DodajOptuzbu(char **&niz_imena, int velicina, std::string za_dodati) {
	char *novo_ime;
	try {
		novo_ime = new char[za_dodati.size() + 1];
	} catch(std::bad_alloc izuzetak) {
		throw izuzetak;
	}
	
	for (int i = 0; i < za_dodati.size(); i++)
		novo_ime[i] = za_dodati[i];
	novo_ime[za_dodati.size()] = '\0';
	
	for (int i = 0; i < velicina; i++) {
		if (niz_imena[i] == nullptr) {
			niz_imena[i] = novo_ime;
			return velicina;
		}
	}
	
	char **novi_niz;
	try {
		novi_niz = new char*[velicina + 1];
	} catch(std::bad_alloc izuzetak) {
		delete[] novo_ime;
		throw izuzetak;
	}
	
	for (int i = 0; i < velicina; i++)
		novi_niz[i] = niz_imena[i];
		
	novi_niz[velicina] = novo_ime;
	delete[] niz_imena;
	niz_imena = novi_niz;
	
	return velicina + 1;
}

void IzlistajOptuzbu(char **niz_imena, int velicina) {
	for (int i = 0; i < velicina; i++)
		if (niz_imena[i]) 
			std::cout << niz_imena[i] << std::endl;
}