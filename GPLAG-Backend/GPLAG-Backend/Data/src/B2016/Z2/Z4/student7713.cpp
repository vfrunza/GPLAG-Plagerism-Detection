/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include <vector>
#include <string>
#include <new>
#include <stdexcept>
int PotencijalniKrivci(char** &pok, std::vector<std::string> v) {
	pok=nullptr;
	try {
		pok=new char*[v.size()];
		for(int i(0); i<v.size(); i++) pok[i]=nullptr;
		try {
			for(int i(0); i<v.size(); i++) pok[i]=new char[v[i].length()+1];
		}
		catch(...) {
			for(int i(0); i<v.size(); i++) delete[] pok[i];
			delete[] pok;
			throw std::bad_alloc();
		}
	}
	catch(...) {
		delete[] pok;
		throw std::bad_alloc();
	}
	int brojac(0);
	for(int i(0); i<v.size(); i++) {
		for(int j(0); j<v[i].length()+1; j++) {
			if(j==v[i].length()) {
				pok[i][j]='\0';
				break;
			}
			pok[i][j]=v[i][j];
		}
		brojac++;	
	}
	return brojac;
}

int OdbaciOptuzbu(char** &pok, int n, std::string s) {
	bool naslo=false;
	for(int i(0); i<n; i++) {
		if(pok[i]==nullptr) continue;
			int j(0);
			if(pok[i][0]==s[0]) {
				while (pok[i][j]==s[j]) {
					j++;
					if(j==s.length()-1) break;
				}
			}
			if(j==s.length()-1) {
				naslo=true;
				delete[] pok[i];
				pok[i]=nullptr;
			}
	}
	if(naslo==false) throw std::domain_error("Osoba sa imenom "+s+" nije bila optuzena");
return n;
	
}

int DodajOptuzbu(char** &pok, int n, std::string s) {
	char * novi= nullptr;
	try{
		novi=new char[s.length()+1];
	}
	catch(...) {
		delete[] novi;
		throw std::bad_alloc();
	}
	for(int i(0); i<s.length()+1; i++) {
		if(i==s.length()) {
			novi[i]='\0';
			break;
		}
		novi[i]=s[i];
	}
	bool imaprazno=false;
	for(int i(0); i<n; i++) {
		if(pok[i]==nullptr) {
			try{
				pok[i]=new char[s.length()+1];
			}
			catch(...) {
				delete[] pok[i];
				throw std::bad_alloc();
			}
			imaprazno=true;
			for(int j(0); j<s.length()+1; j++) 	pok[i][j]=novi[j];
			break;
		}
	}
	if(imaprazno==false) {
	char**pok2=nullptr;
	try {
		pok2=new char*[n+1];
		for(int i(0); i<n+1; i++) pok2[i]=nullptr;
		try {
			for(int i(0); i<n+1; i++) {
				if(i==n) {
					pok2[i]=new char[s.length()+1];
					break;
				}
				int brsl(0);
				auto k=pok[i];
				while (*k!='\0') {
					k++;
					brsl++;
				}
				pok2[i]=new char[brsl+1];
			}
		}
		catch(...) {
			for(int i(0); i<n+1; i++) delete[] pok2[i];
			delete[] pok2;
			throw std::bad_alloc();
			}
		}
	catch(...) {
		delete[] pok2;
		throw std::bad_alloc();
		}
	
	for(int i(0); i<n+1; i++) {
		if(i==n) {
			for(int j(0); j<s.length()+1; j++)
			pok2[i][j]=novi[j];
			break;
		}
		int brsl(0);
		auto k=pok[i];
		while (*k!='\0') {
			k++;
			brsl++;
		}
		for(int j(0); j<brsl+1; j++) {
			if(j==brsl) {
				pok2[i][j]='\0';
				break;
			}
			pok2[i][j]=pok[i][j];
		}
	}
	
	for(int i(0); i<n; i++) delete[] pok[i];
	delete[] pok;
	pok=pok2;
	}
	delete[] novi;
	return n+1;
}

void IzlistajOptuzbu(char** pok, int n) {
	for(int i(0); i<n; i++) {
		if(pok[i]==nullptr) continue;
			int brsl(0);
			auto k=pok[i];
			while (*k!='\0') {
				k++;
				brsl++;
			}
			for(int j(0); j<brsl; j++) 
				std::cout<<pok[i][j];
		std::cout<<std::endl;
	}
}

int main ()
{
	std::cout<<"Koliko potencijalnih krivaca zelite unijeti? "<<std::endl;
	int broj;
	std::cin>>broj;
	std::cin.ignore(10000,'\n');
	std::cout<<"Unesite potencijalne krivce: "<<std::endl;
	std::vector<std::string> v;
	for(int i(0); i<broj; i++) {
		std::string pom;
		std::getline(std::cin, pom);
		v.push_back(pom);
	}
	char **pok;
	int broj2(0);
	try {
		broj2=PotencijalniKrivci(pok,v);
		while (1) {
			std::cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: "<<std::endl;
			int a;
			std::cin>>a;
			std::cin.ignore(10000,'\n');
			if(a==0) break;
			else if(a==3) {
				try {
				IzlistajOptuzbu(pok,broj2);
				}
				catch(std::bad_alloc) {
					std::cout<<"Alokacija nije uspjela";
				}
			}
			else if(a==1) {
				try {
				std::cout<<"Unesite ime novog optuzenog: "<<std::endl;
				std::string optuzeni;
				std::getline(std::cin,optuzeni);
				broj2=DodajOptuzbu(pok,broj2,optuzeni);
				}
				catch(std::bad_alloc) {
					std::cout<<"Alokacija nije uspjela";
				}
			}
			else if(a==2) {
				try {
				std::cout<<"Unesite ime koje zelite izbaciti: "<<std::endl;
				std::string optuzeni;
				std::getline(std::cin, optuzeni);
				broj2=OdbaciOptuzbu(pok,broj2,optuzeni);
				}
				catch(std::bad_alloc) {
					std::cout<<"Alokacija nije uspjela";
				}
				catch(std::domain_error izuzetak) {
					std::cout<<izuzetak.what()<<std::endl;
				}
			}
		}
		for(int i(0); i<broj2; i++) {
			delete[] pok[i];
			pok[i]=nullptr;
		}
		delete[] pok;
		pok=nullptr;
	}
	catch(std::bad_alloc) {
		for(int i(0); i<broj2; i++) {
			delete[] pok[i];
			pok[i]=nullptr;
		}
		delete[] pok;
		std::cout<<"Nedovoljno memorije";
	}
	return 0;
}