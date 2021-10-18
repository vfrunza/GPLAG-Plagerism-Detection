/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <cstring>

int PotencijalniKrivci (char** &referenca, std::vector<std::string> imena) {
	int brojac(0);
	char **pokazivac(nullptr);
	try {
		pokazivac=new char*[imena.size()]{};
	}
	catch (...) {
		delete [] pokazivac;
		throw std::bad_alloc();
	}
	try {
		int j;
		for (int i=0; i<imena.size();i++) {
			pokazivac[i]=new char[imena[i].size()+1]{};
			brojac++;
				for (j=0; j<imena[i].size(); j++) {
					pokazivac[i][j]=imena[i][j];
				}
			pokazivac[i][j]=0;
		}
	}
	catch (...) {
		for (int i=0; i<brojac; i++) {
			delete [] pokazivac[i];
		}
		delete [] pokazivac;
	}
	referenca=pokazivac;
	return brojac;
}

int OdbaciOptuzbu (char** &referenca, int velicina, std::string neduzan) {
	int brojac(0), izbaceni(0);
	for (int i=0; i<velicina; i++) {
		int j(0);
		while (referenca[i][j]!=0 && j<neduzan.length()) {
			if (referenca[i][j]!=neduzan[j])
				break;
			j++;
			brojac++;
		}
		if (brojac==neduzan.length()) {
			izbaceni++;
			delete[] referenca[i];
			referenca[i]=nullptr;
		}
		brojac=0;
	}
	if (izbaceni==0) 
		throw std::domain_error ("Osoba sa imenom "+neduzan+" nije bila optuzena");
	if (izbaceni>10) {
		char**korisni;
		try {
			korisni=new char*[velicina-izbaceni]{};
		}
		catch (...) {
			delete [] korisni;
		}
		int k(0);
		for (int i=0; i<velicina; i++) {
			if(referenca[i]!=nullptr) {
				korisni[k]=referenca[i];
				k++;
			}
		}
		for (int i=0; i<velicina; i++) {
			delete [] referenca[i];
		}
		delete [] referenca;
		velicina=velicina-izbaceni;
	}
	return velicina;
}

int DodajOptuzbu (char ** &referenca, int velicina, std::string optuzeni){
	char*novi(nullptr);
	try {
		novi=new char[optuzeni.length()+1]{};
	}
	catch (...) {
		delete []novi;
		throw std::bad_alloc();
	}
	int brojac3(0);
	for (int i=0; i<optuzeni.length(); i++)
		novi[i]=optuzeni[i];
	for (int i=0; i<velicina; i++) {
		if (referenca[i]==nullptr) {
			for (int j=0; j<optuzeni.length(); j++) 
				referenca[i][j]=optuzeni[j];
			break;
		}
		brojac3++;
	}
	if (brojac3==velicina) {
		char **prosireni(nullptr);
		try {
			prosireni=new char*[velicina+1]{};
		}
		catch (...) {
			delete [] prosireni;
			throw std::bad_alloc();
		}
		int m(0);
		for (m=0; m<velicina; m++) {
			int brojac4(0);
			char *temp=referenca[m];
			while (*temp++!=0) 
				brojac4++;
			prosireni[m]=new char[brojac4 + 1]{};
			std::strcpy(prosireni[m], referenca[m]);
		}
		prosireni[m]=novi;
		for (int n=0; n<velicina; n++) 
			delete [] referenca[n];
			delete [] referenca;
			referenca=prosireni;
	velicina++;
	}
	return velicina;
}
void IzlistajOptuzbu (char **imena, int velicina) {
	for (int i=0; i<velicina; i++) {
		if (imena[i]!=nullptr) 
		std::cout<<imena[i]<<std::endl;
	}
}

int main ()
{
	std::cout<<"Koliko potencijalnih krivaca zelite unijeti? "<<std::endl;
	int n;
	std::cin>>n;
	std::vector<std::string>lista(n);
	std::cout<<"Unesite potencijalne krivce: \n";
	for (int i=0; i<n; i++) {
		std::cin>>lista[i];
	}
	char** pokazivac(nullptr);
	int broj(PotencijalniKrivci(pokazivac, lista));
	int opcija;
	do {
	std::cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: "<<std::endl;
	std::cin>>opcija;
	if (opcija==1) {
		std::cout<<"Unesite ime novog optuzenog: "<<std::endl;
		std::string optuzeni;
		std::cin>>optuzeni;
		broj=DodajOptuzbu(pokazivac, broj, optuzeni);
	}
	else if (opcija==2) {
		std::cout<<"Unesite ime koje zelite izbaciti: "<<std::endl;
		std::string izbaci;
		std::cin>>izbaci;
		broj=OdbaciOptuzbu(pokazivac, broj, izbaci);
	}
	else if (opcija==3)
		IzlistajOptuzbu(pokazivac, broj);
	} while (opcija!=0);
	for (int i=0; i<broj; i++)
		delete [] pokazivac[i];
		delete [] pokazivac;
	return 0;
}