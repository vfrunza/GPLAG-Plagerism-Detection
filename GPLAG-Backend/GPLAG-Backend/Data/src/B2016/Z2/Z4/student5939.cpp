/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include <new>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <stdexcept>


int PotencijalniKrivci (char **& matrica, std::vector<std::string> imena) {
	try {
		matrica=nullptr;
		matrica=new char*[imena.size()];
	}
	catch (std::bad_alloc) {
		delete[] matrica;
		throw;
	}
	try {
		for(int i=0; i<imena.size(); i++) {
			matrica[i]=new char[imena[i].size()+1];
			std::strcpy(matrica[i],imena[i].c_str());
		}
		return imena.size();
}
	catch (std::bad_alloc) {
		for(int i=0; i<sizeof(matrica); i++) {
			delete[] matrica[i];
		}
		delete[] matrica;
		throw;
	}
}

int OdbaciOptuzbu (char **& matrica, int n, std::string ime) {
	int ima(0);
	for (int i=0; i<n; i++) {
		if(std::strcmp(matrica[i], ime.c_str())==0) {
			delete[] matrica[i];
			matrica[i]=nullptr;
			ima++;
		}
	}
	
	if(!ima) throw std::domain_error ("Osoba sa imenom "+ime+" nije bila optuzena");
	else if (ima>10) {
		char ** novamat(nullptr);
		int vel=n-ima;
		try{
			novamat=new char *[vel];
		}
		catch (std::bad_alloc) {
			delete[] novamat;
		}
		try {
			int j(0);
			for (int i=0; i<n; i++) {
				if (matrica[i] != nullptr) {
					novamat[j]= new char [sizeof(matrica[i]+1)];
					for (int k=0; k<=sizeof(matrica[i]); k++) {
						novamat[j][k]=matrica[i][k];
					}
					j++;
				}
			}
			for (int i=0; i<n; i++) {
				delete[] matrica[i];
			}
			delete[] matrica;
			matrica=novamat;
			return vel;
		}
		catch (std::bad_alloc) {
			for (int i=0; i<vel; i++) {
				delete[] novamat[i];
			}
			delete[] novamat;
		}
	}
	return n;
}

int DodajOptuzbu (char **&matrica, int n, std::string ime) {
	int ubaceno(0);
	char *ime_niz(nullptr);
	ime_niz=new char[ime.length()+1];
	std::strcpy (ime_niz, ime.c_str());
	for (int i=0; i<n; i++) {
		if (matrica[i] != nullptr) continue;
		else {
			matrica[i]=ime_niz;
			ubaceno++;
		}
		if (ubaceno) break;
	}
	if (!ubaceno) {
		int vel=n+1;
		char ** novamat(nullptr);
		try {
			novamat=new char*[vel];
		}
		catch (std::bad_alloc) {
			delete[] novamat;
			throw;
		}
		try {
			for (int i=0; i<vel; i++) {
				if (i==vel-1) {
					novamat[i]=ime_niz;
					break;
				}
				novamat[i]= new char [sizeof(matrica[i])+1];
				std::strcpy(novamat[i], matrica[i]);
			}
			for (int i=0; i<n; i++) {
				delete[] matrica[i];
			}
			delete[] matrica;
			matrica=novamat;
			return vel;
		}
		catch (std::bad_alloc) {
			for (int i=0; i<vel; i++) {
				delete[] novamat[i];
			}
			delete[] novamat;
			throw;
		}
	}
	return n;
}

void IzlistajOptuzbu (char **matrica, int n) {
	for (int i=0; i<n; i++) {
		std::cout << std::endl;
		if (matrica[i] != nullptr) {
			char *p=matrica[i];
			while (*p != '\0')
			std::cout << *p++;
		}
	}
}
int main ()
{
	int n;
	char **matrica;
	std::cout << "Koliko potencijalnih krivaca zelite unijeti?";
	std::cin >> n;
	std::vector <std::string> imena(n);
	std::cin.ignore(100000, '\n');
	std::cout << "\nUnesite potencijalne krivce: ";
	for (int i=0; i<n; i++) {
		std::cin >> imena[i];
	}
	try {
		int unos;
		std::string ime;
		n=PotencijalniKrivci(matrica, imena);
		while (1) {
			std::cout << "\nOdaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj:";
			std::cin >> unos;
			if (!unos) break;
			else if (unos==1) {
				std::cin.ignore (100000000, '\n');
				std::cout << "\nUnesite ime novog optuzenog: ";
				std::getline (std::cin, ime);
				n=DodajOptuzbu(matrica, n, ime);
			}
			else if (unos==2) {
				std::cin.ignore(10000000, '\n');
				std::cout << "\nUnesite ime koje zelite izbaciti: ";
				std::getline (std::cin, ime);
				n=OdbaciOptuzbu(matrica, n, ime);
			}
			else {
				IzlistajOptuzbu(matrica, n);
			}
		}
		for (int i=0; i<n; i++) {
			delete[] matrica[i];
		}
		delete[] matrica;
	}
	catch (std::bad_alloc) {
		for (int i=0; i<n; i++) {
			delete[] matrica[i];
		}
		delete[] matrica;
	}
	catch (std::domain_error izuzetak) {
		for (int i=0; i<n; i++) {
		delete[] matrica[i];
		}
	delete[] matrica;
	std::cout << izuzetak.what() << std::endl;
	}
	return 0;
}