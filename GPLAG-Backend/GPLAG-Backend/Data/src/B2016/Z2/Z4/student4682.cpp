#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <new>
#include <stdexcept>
typedef std::vector<std::string> strvec;
unsigned int PotencijalniKrivci(char **&p, std::vector<std::string> imena);
unsigned int OdbaciOptuzbu(char **&p,unsigned int vel, std::string legalan);
unsigned int DodajOptuzbu(char **&p,unsigned int vel, std::string ilegalan);
void IzlistajOptuzbu(char **p,unsigned int vel);

int main ()
{
	std::cout<<"Koliko potencijalnih krivaca zelite unijeti? ";
	int n;
	std::cin >> n;
	std::cout << std::endl <<"Unesite potencijalne krivce: ";
	std::cin.ignore(10000,'\n');
	strvec imena;
	for(int i(0); i < n; i++) {
		std::string ime;
		std::getline(std::cin,ime);
		imena.push_back(ime);
	}
	char**pok;
	int m(PotencijalniKrivci(pok,imena));
	try {
		while(true) {
			std::cout << std::endl << "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: "<<std::endl;
			std::cin >> n;
			std::cin.ignore(10000,'\n'); //očisti ulazni tok
			
			try {
				switch(n) { //ako je ispravan unos radi šta treba da radiš u odnosu koliko je n
				case 0:
					for(int i(0); i < m; i++)
						delete[] pok[i];

					delete[] pok;
					return 0;
				case 1: {
					std::cout<<"Unesite ime novog optuzenog: ";
					std::string ime;
					std::getline(std::cin,ime);
					m = DodajOptuzbu(pok,m,ime);
					break;
				}
				case 2: {
					std::cout << "Unesite ime koje zelite izbaciti: ";
					std::string ime;
					std::getline(std::cin,ime);
					m = OdbaciOptuzbu(pok,m,ime);
					break;
				}
				case 3:
					IzlistajOptuzbu(pok,m);
					break;
				}
			} catch(std::domain_error error) { //uhvati i ispiši izuzetak
				std::cout << error.what() << std::endl; 
			} catch(std::bad_alloc) {
				std::cout<< "Neuspjela alokacija" << std::endl; //uhvati bad_alloc izuzetak
			}
		}

	} catch(std::bad_alloc) {
		std::cout<< "Neuspjela alokacija" << std::endl;
	}
	return 0;
}

unsigned int PotencijalniKrivci(char **&p, std::vector<std::string> imena)
{
	char **pok(nullptr); //inicijaliziraj pokazivač pmoćni na nul pokazivač
	try {
		int br_alociranih(0); //traži koliko je alociranih
		pok = new char*[imena.size()]; //niz pokazivača
		for(int i(0); i < imena.size(); i++)
			pok[i] = nullptr; //postavi sve na nul pokazivače

		try {
			for(int i(0); i < imena.size(); i++) {
				pok[i] = new char[imena[i].length()+1];  //alcoiraj nizove charova (+1 za NUL graničnik)
				char *q(&imena[i][0]);	//pokazivač na prvi elemenat imena koje treba alocirati
				std::strcpy(pok[i], q); //prebaci imenu u dinamički niz
				pok[i][imena[i].length()]= 0; //zadnji elemenat postavi na NUL graničnik
				br_alociranih++;
			}
		} catch(...) {
			for(int i(0); i < br_alociranih; i++)
				delete[] pok[i];		//briši nizove charova u slučaju izuzetka
			throw;
		}
	} catch(...) {
		delete[] pok;	//briši niz pokazivača
		throw;	//proslijedi bad_alloc izuzetak
	}

	p = pok;	//postavi ulazni pokazivač na niz pokazivača

	return imena.size();
}

unsigned int OdbaciOptuzbu(char **&p,unsigned int vel, std::string legalan)
{
	char *q(&legalan[0]);	//pokazivač na prvi elemenat stringa koji sadrđe ime za izbacit
	bool nijezbacen(true);	//pomocna u slučaju da navedeno ime ne postoji u nizovima charova

	for(int i(0); i < vel; i++)
		if(p[i] != nullptr && strcmp(p[i],q) == 0)	//ako nije nullptr (strcmp ima problema tad) i ako si našao ime 
			nijezbacen = false;						//postavi pomoćnu na false

	if(nijezbacen)	//izuzetak
		throw std::domain_error("Osoba sa imenom " +legalan+" nije bila optuzena");

	
	//Nađi koga treba izbaciti i izbaci ga, obriši niz charova i postavi pokazivač na nullptr
	for(int i(0); i < vel; i++)
		if(p[i] != nullptr && strcmp(p[i],q) == 0) {
			delete[] p[i];	
			p[i] = nullptr;
		}

	unsigned int vel2(0);	//nađi novu stvarnu veličinu niza pokazivača
	for(int i(0); i < vel; i++)
		if(p[i] != nullptr)
			vel2++;


	//ako ima >10 nullptr pravi novi niz
	if(vel - vel2 > 10) { 
	char **pom(nullptr);
		try {
			pom = new char*[vel2];
			try {
				for(int i(0), j(0); i < vel2; i++,j++) {
					if(p[j] != nullptr) {
						pom[i] = new char[sizeof p[j]];
						strcpy(pom[i],p[j]);
					} else i--;
				}

			} catch(...) {
				for(int i(0); i < vel2; i++)
					delete[] pom[i];
				throw;	//briši u slučaju izuzetka
			}
			
			//ako nije bilo problema briši stare nizove i postavi pokazivač na novi niz
			for(int i(0); i < vel; i++)
				delete[] p[i];
			delete[] p;
			p = pom; 
			return vel2;
		} catch(...) {
			delete pom;
		}
	}



	return vel;
}

unsigned int DodajOptuzbu(char **&p,unsigned int vel, std::string ilegalan)
{
	//standardno postavi pokazivač na nullptr da se kasniej može brisat kako treba (ako treba)
	char *novi(nullptr);
	char *q(&ilegalan[0]);
	try {
		novi = new char[ilegalan.length()+1]; //alociraj memorije za novo ime
	} catch(...) {
		delete[] novi;
		throw; //briši ako bude izuzetak
	}
	strcpy(novi,q);	//kopiraj sadržaj iz stringa u niz charova
	novi[ilegalan.length()] = 0; //zadnji element = NUL graničnik
	bool nijenasao(true);	//pomocna za pronalazak null pokazivača

	//traži prvi nul pokazivač ako ga nađeš postavi ga na novi niz charova
	for(int i(0); i < vel; i++)
		if(p[i] == nullptr) {
			p[i] = novi;
			nijenasao = false;
			break;
		}

	//ako nema nul pokazivača onda napravi novi niz pokazivača za 1 pokazivač veći i preusmjeri ne njeg
	if(nijenasao) {
		char **pom(nullptr);
		try {
			pom = new char*[++vel];
			for(int i(0); i < vel-1; i++)
				pom[i] = p[i];		//usmjeravanje pokazivača iz novog niza
			pom[vel-1] = novi;
			delete[] p;
			p = pom;
		} catch(...) {
			delete[] pom;
			throw;
		}

	}
	return vel;
}
void IzlistajOptuzbu(char **p,unsigned int vel)
{
	for(int i(0); i < vel; i++)
		if(p[i] != nullptr)	//ispisuj ako nije nullptr
			std::cout << p[i]<< std::endl;

}