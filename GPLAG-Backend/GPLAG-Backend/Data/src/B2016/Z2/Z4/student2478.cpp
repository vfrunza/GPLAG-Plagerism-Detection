#include <iostream>
#include <vector>
#include <new>
#include <stdexcept>

int PotencijalniKrivci(char **&aD , std::vector<std::string> Vstringova)
{

	try {
		int Duzina(0);
		aD = nullptr;
		aD = new char *[Vstringova.size()];

		try {
			for(int i(0); i< Vstringova.size(); i++) {
				aD[i] = nullptr;
				aD[i] = new char[Vstringova[i].length()+1];
				Duzina++;
			}
			for(int i(0); i < Vstringova.size(); i++) {
				int j;
				for(j = 0; j < Vstringova.at(i).length(); j++) {
					aD[i][j] = Vstringova[i][j];
				}
				aD[i][j] = '\0';
			}
			return Duzina;
		} catch(std::bad_alloc) {
			for(int i(0); i < Duzina; i++)
				delete [] aD[i];
			delete [] aD;
			throw;
		}
	} catch(std::bad_alloc) {
		delete [] aD;
		throw;
	}
}

int OdbaciOptuzbu(char **&aD, int n, std::string Pametan)
{
	bool Na_spisku(false);
	
	for(int i(0); i < n; i++)
	{
		if(aD[i] != nullptr && aD[i] == Pametan) {
			Na_spisku= true;
			delete []aD[i];
			aD[i] = nullptr;
		}
	}
	if(!Na_spisku)
	{
		std::string s = "Osoba sa imenom " + Pametan + " nije bila optuzena";
		throw std::domain_error(s);
	}
	int brojac(0);
	std::vector<std::string> Novi_s;
	for(int i(0); i < n; i++){
		if(aD[i] == nullptr)brojac++;
		else Novi_s.push_back(aD[i]);
	}
	if(brojac > 10)
	{
		char **Novi;
		int broj_novih(PotencijalniKrivci(Novi, Novi_s));
	
	for(int i(0); i < n; i++){
		delete []aD[i];
	}
	delete[]aD;
	aD = nullptr;
	for(int i(0); i < broj_novih; i++){
		aD[i] = Novi[i];
	}
	n = broj_novih;}
	return n;
}

int DodajOptuzbu(char **&aD, int n, std::string PotKrivac)
{

	try {
		char *niz=nullptr;
		niz= new char[PotKrivac.length()+1];

		for(int i(0); i < PotKrivac.length(); i++) {
			niz[i] = PotKrivac[i];
		}
		niz[PotKrivac.length()] = '\0';
		std::vector<std::string> Stringici;
		bool ima_null(false);
		for(int i(0); i < n; i++) {
			if(aD[i] == nullptr) {
				aD[i] = niz;
				delete [] niz;
				niz = nullptr;
				ima_null = true;
				break;
			}
			Stringici.push_back(aD[i]);
		}
		Stringici.push_back(PotKrivac);

		if(!ima_null) {
			char **Novi_s;
			int broj_novih(PotencijalniKrivci(Novi_s, Stringici));
			for(int i(0); i < n; i++) {
				delete [] aD[i];
			}
			delete [] aD;
			delete [] niz;
			niz=nullptr;
			aD = nullptr;

			aD = Novi_s;
			n = broj_novih;

			Novi_s = nullptr;

		}

	} catch(std::bad_alloc) {
		std::cout << "Neuspjela alokacija" << std::endl;
	}
	return n;
}

void IzlistajOptuzbu(char **Stringovi, int velicina)
{

	for(int i(0); i < velicina; i++) {
		if(Stringovi[i] != nullptr)
			std::cout << Stringovi[i] << std::endl;
	}

}


int main ()
{

	try {
		std::cout << "Koliko potencijalnih krivaca zelite unijeti? " << std::endl;
		int BrojPotKrivaca(0);
		std::cin >> BrojPotKrivaca;

		std::cout << "Unesite potencijalne krivce: " << std::endl;
		std::vector<std::string> PotKrivci;
		std::string Krivac;

		std::cin.ignore(1000, '\n');

		for(int i(0); i < BrojPotKrivaca; i++) {

			std::getline(std::cin, Krivac);
			PotKrivci.push_back(Krivac);
		}


		char** aD;
		int broj(PotencijalniKrivci(aD, PotKrivci));
		int &trenutni_broj = broj;
		int opcija;
		do {
			std::cout << "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: " << std::endl;
			std::cin >> opcija;

			if(opcija == 1) {
				std::cout << "Unesite ime novog optuzenog: " << std::endl;
				std::string ime;
				std::cin.ignore(1000, '\n');
				std::getline(std::cin, ime);
				trenutni_broj = DodajOptuzbu(aD, broj, ime);
			}

			else if(opcija == 2) {
				std::cout << "Unesite ime koje zelite izbaciti: " << std::endl;
				std::string ime;
				std::cin.ignore(1000, '\n');
				std::getline(std::cin, ime);
				trenutni_broj = OdbaciOptuzbu(aD, broj, ime);
			} else if(opcija == 3) IzlistajOptuzbu(aD, trenutni_broj);

		} while(opcija != 0);

		for(int i(0); i < broj; i++) {
			delete [] aD[i];
		}
		delete [] aD;
		return 0;
	} catch(std::domain_error izuzetak) {
		std::cout << izuzetak.what();
	}
	return 0;
}