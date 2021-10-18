//B 16/17, Zadaća 2, Zadatak 4
#include <stdexcept>
#include <iostream>
#include <vector>
#include <string>

int PotencijalniKrivci (char** &pok, std::vector<std::string> spisak_imena)
{
	try {
		int broj_alokacija(0);
		// Dinamicka inicijalizacija pok i postavljanje na nullptr ..
		pok = (new char*[spisak_imena.size()]);
		for (int i=0; i<spisak_imena.size(); ++i) pok[i] = nullptr;
		
		try {	// Kopiranje u ** & pok ..
			for (int i=0; i<spisak_imena.size(); ++i)
			{
				int znak(0);
				pok[i] = new char[spisak_imena[i].length() + 1];
				for (int z=0; z<spisak_imena[i].length(); ++z)
					pok[i][znak++] = spisak_imena[i][z];
					pok[i][znak] = '\0';	broj_alokacija++;
			}	return broj_alokacija;
		}	catch (...) {
			for (int i=0; i<broj_alokacija; ++i) delete[] pok[i];
			throw std::bad_alloc();
		}
	}	catch (...) {
		delete [] pok;
		throw std::bad_alloc();
	}
}

int DodajOptuzbu (char** &pok, int vel, std::string osoba)
{	
	char *niz_osoba(nullptr);
	try {
		niz_osoba = (new char[osoba.length()+1]);
		
		int index(0);
		for (int i=0; i<osoba.length(); ++i)
			niz_osoba[index++] = osoba[i];
			niz_osoba[index] = '\0';
		
		for (int i=0; i<vel; ++i)
			if (pok[i] == nullptr) {
				pok[i] = niz_osoba;
				niz_osoba = nullptr;
				return vel;
			}
	
		char **temp;
		try {
			temp = (new char*[vel+1]);
		
			index = 0; // Dodjela novom..
			for (int i=0; i<vel; ++i)
				temp[index++] = pok[i];
				temp[index] = niz_osoba;
				niz_osoba = nullptr;
		
			delete[] pok;	pok = temp;    
			temp = nullptr;	return vel+1;
	
		}	catch (...) {
			delete [] temp;
			temp = nullptr;
			throw std::bad_alloc();
		}
	}	catch (...) {
		delete [] niz_osoba;
		niz_osoba = nullptr;
		throw std::bad_alloc();
	}
}

bool Uporedi(const char* niz_charova, const std::string &string2) {
	if (niz_charova == nullptr)	return false;
	std::string string1 (niz_charova);
	if (string1 == string2)	return true;
	else	return false;
}

int OdbaciOptuzbu (char** &pok, int vel, std::string osoba)
{
	int broj_obrisanih(0);
	for (int i=0; i<vel; ++i) {
		if (Uporedi(pok[i], osoba)) {
			delete [] pok[i];
			pok[i] = nullptr;	
			broj_obrisanih++;
		}
	}
		
	if (broj_obrisanih == 0) {
		std::string output ("Osoba sa imenom " + osoba + " nije bila optuzena");
		throw std::domain_error (output);
	}	
	else if (broj_obrisanih > 10) 
	{
		try {
			int index(0);
			char** novi_pok (new char*[vel-broj_obrisanih]);
			for (int i=0; i<vel; ++i) {
				if (pok[i] == nullptr)  continue;
				else  novi_pok[index++] = pok[i];
			}	delete [] pok;
			pok = novi_pok;	return vel-broj_obrisanih;
		}	catch (...) {}
	}	return vel;
}

void IzlistajOptuzbu (char** output, int vel) {
	for (int i=0; i<vel; ++i) {
		if (output[i] == nullptr)	continue;
		// Ispis na ekran..
		int index(0);
		while (output[i][index] != '\0')
			std::cout << output[i][index++];
			std::cout << std::endl;
	}
}

int main ()
{
	int broj_krivaca(0);
	std::cout << "Koliko potencijalnih krivaca zelite unijeti? " << std::endl;
	std::cin >> broj_krivaca;
	std::cin.clear();	std::cin.ignore(10000 , '\n');
	
	std::vector<std::string> spisak_imena;
	std::cout << "Unesite potencijalne krivce: " << std::endl;
	for (int i=0; i<broj_krivaca; ++i) {
		std::string input;
		std::getline (std::cin, input);
		spisak_imena.push_back(input);
	}
	
	char **pok_spisak;
	int vel = PotencijalniKrivci(pok_spisak, spisak_imena);
	
	for (;;) {
		int opcija;
		std::cout << "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog";
		std::cout << " 3 za izlistavanje optuzenih, 0 za kraj: " << std::endl;
		std::cin >> opcija;
		std::cin.clear();	std::cin.ignore(10000, '\n');
		
		if (opcija == 0) break;
			else if (opcija == 1) {
				std::cout << "Unesite ime novog optuzenog: " << std::endl;
				std::string input; std::getline (std::cin, input);
				try {
					vel = DodajOptuzbu(pok_spisak, vel, input);
				}	catch (...) {}
		}	
		else if (opcija == 2) {
			// I input imena za izbaciti ..
			std::cout << "Unesite ime koje zelite izbaciti: " << std::endl;
			std::string input; std::getline (std::cin, input);
			try {	
				vel = OdbaciOptuzbu(pok_spisak, vel, input); 
			}	catch (std::domain_error text) {	
				std::cout << text.what() << std::endl;	
			}
		}	else if (opcija == 3) {
			IzlistajOptuzbu(pok_spisak, vel);
		}
	}
	
	for (int i=0; i<vel; ++i) {
		delete [] pok_spisak[i];
	}	delete [] pok_spisak;
	return 0;
}