#include <iostream>
#include <string>
#include <vector>
#include <new>
#include <cstring>
#include <stdexcept>

int PotencijalniKrivci(char **&pok1, std::vector<std::string> vektor) {
	
	int brojalociranih=0;
	char **pok=nullptr;
	
	try {
	pok=new char*[vektor.size()];
	
	for(int i=0; i<vektor.size(); i++) {
		pok[i]=nullptr;
	}
	
	try {
	for(int i=0; i<vektor.size(); i++) {
		pok[i]=new char[vektor[i].length()+1];
		brojalociranih++;
	}
	int j;
	for(int i=0; i<vektor.size(); i++) {
		for(j=0; j<vektor[i].size(); j++) {
			pok[i][j]=vektor[i][j];
		}
		pok[i][j]='\0';
	}
	
	
	pok1=pok;
	
	
	return brojalociranih;
	}
	catch(std::bad_alloc) {
		for(int i=0; i<vektor.size(); i++) {
			delete[] pok[i];
		}
		delete[] pok;
		throw;
		
	}
	}
	catch(std::bad_alloc) {
		throw "Neuspjela alokacija";
	}
	
}

int OdbaciOptuzbu(char **&pok,  int velicina, std::string nije_prodao) {
	
	char nizime[20];
	int i;
	for(i=0; i<nije_prodao.length(); i++) {
		nizime[i]=nije_prodao[i];
	}
	nizime[i]='\0';
	bool imauspisku=0;
	for(int i=0; i<velicina; i++) {
		
		if(strcmp(pok[i], nizime)==0) { imauspisku=1; break; }

	}
	
	if(imauspisku==0) {
		throw std::domain_error("Osoba sa imenom " + nije_prodao + " nije bila optuzena");
	}
	
	for(int i=0; i<velicina; i++) {
		
		if(strcmp(pok[i], nizime)==0) { delete[] pok[i]; pok[i]=nullptr;  }
	
	}
	int brojac=0;
	for(int i=0; i<velicina; i++) {
		if(pok[i]==nullptr) brojac++;
	}
	
	if(brojac<=10) return velicina;
	
	int novibrojredova=velicina-brojac;
	try {
	
	if(brojac>10) {
		
		char **novipok;
		
		novipok=new char*[novibrojredova];
		
		int k=0;
		for(int i=0; i<velicina; i++) {
			if(pok[i]!=nullptr) {
				novipok[k]=pok[i];
				k++;
			}
		}
		
		pok=novipok;
		
		return novibrojredova;
		}
	}
	catch(std::bad_alloc) {
		for(int i=0; i<velicina; i++) delete[] pok[i]; delete[] pok;
		throw ("Neuspjela alokacija");
	}
	return 0;
}

int DodajOptuzbu(char **&pok,  int velicina, std::string novo_ime) {
	
	char *poknaniz;
	poknaniz=new char[novo_ime.length()+1];
	int i;
	for(i=0; i<novo_ime.length(); i++) {
		poknaniz[i]=novo_ime[i];
	}
	poknaniz[i]='\0';
	
	for(int i=0; i<velicina; i++) {
		if(pok[i]==nullptr) { pok[i]=poknaniz; return velicina; }
	}
	
	char **novipok;
	novipok=new char*[velicina+1];
	
	for(int i=0; i<velicina; i++) {
		novipok[i]=pok[i];
	}
	
	novipok[velicina]=poknaniz;
	
	delete[] pok;
	
	pok=novipok;
	
	return velicina+1;
}

void IzlistajOptuzbu( char **pok, int velicina) {
	
	for(int i=0; i<velicina; i++) {
	    if(pok[i]!=nullptr) { std::cout << pok[i];
		std::cout << std::endl;
	    }
	}
	
	
}

int main ()
{
	try {
	char **a;
	int brojalociranih;
	std::cout << "Koliko potencijalnih krivaca zelite unijeti? " << std::endl;
	int n;
	std::cin >> n;
	std::string krivac;
	std::vector<std::string> krivci;
	std::cin.ignore(1000,'\n');
	std::cout << "Unesite potencijalne krivce: " << std::endl;
	
	for(int i=0; i<n; i++) {
		std::getline(std::cin, krivac);
		
		krivci.push_back(krivac);
		
	}
	
	brojalociranih=PotencijalniKrivci(a, krivci);
	
	std::string ime;
	int broj=5;
	
	while(broj!=0) {
	std::cout << "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: " << std::endl;
	
	
	std::cin >> broj;
	std::cin.ignore(1000, '\n');
	
	if(broj==1) {
		std::cout << "Unesite ime novog optuzenog: " <<std::endl;
		std::getline(std::cin, ime);
		krivci.push_back(ime);
		brojalociranih=DodajOptuzbu(a, brojalociranih, ime);
		
	}
	
	if(broj==2) {
		std::cout << "Unesite ime koje zelite izbaciti: " << std::endl;
		std::getline(std::cin, ime);
		try {
		brojalociranih=OdbaciOptuzbu(a, brojalociranih, ime);
		}
		catch(std::domain_error izuzetak) {
			std::cout <<  izuzetak.what();
			for(int i=0; i<brojalociranih; i++) delete[] a[i]; delete[] a;
			return 0;
		}
	}
	
	if(broj==3) {
		IzlistajOptuzbu(a, brojalociranih);
	}
	
	}
	
	for(int i=0; i<brojalociranih; i++) {
		delete[] a[i];
	}
	delete[] a;
	}
	catch(std::bad_alloc) {
		std::cout <<"Neuspjela alokacija";
	}
	
	
	return 0;
}