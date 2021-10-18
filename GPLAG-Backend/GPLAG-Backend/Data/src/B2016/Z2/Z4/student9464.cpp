/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <new>
#include <stdexcept>

int nullbrojac(0);

int PotencijalniKrivci(char **&krivci, std::vector<std::string> spisak) {
	int brojac(0);
	krivci = nullptr;
	try{
		krivci = new char *[spisak.size()];
		for(int i=0; i<spisak.size(); i++) 
			krivci[i] = nullptr;
			for(int i=0; i<spisak.size(); i++) {
				krivci[i] = new char[spisak[i].length()+1];
				std::strcpy(krivci[i], spisak[i].c_str());
				if(*krivci)
					brojac++;
				}
		} catch(std::bad_alloc) {
			if(krivci)
				for(int i=0; i<spisak.size(); i++)
					delete[] krivci[i];
			delete[] krivci;
			throw;
		}
	return brojac;
}

int OdbaciOptuzbu (char **& krivci, int vel, std::string ime) {
	int nova_vel(vel);
	bool pronadjeno(false);
	for(int i=0; i<vel; i++) {
		if(krivci[i] && strcmp(krivci[i], ime.c_str()) == 0) {
			pronadjeno = true;
			nullbrojac++;
			delete[] krivci[i];
			krivci[i] = nullptr;
		}
	}
	if(nullbrojac >= 10) {
		char **novi_niz(nullptr);
		try{
			novi_niz = new char* [vel-nullbrojac];
			if(novi_niz) {
				int j(0);
				for(int i=0; i<vel; i++) {
					if(krivci[i]) {
						novi_niz[j] = krivci[i];
						krivci[i] = nullptr;
						j++;
					}
				}
				delete[] krivci;
				krivci = novi_niz;
				novi_niz = nullptr;
				nova_vel = j;
				nullbrojac = 0;
			}
		}catch(std::bad_alloc) {
			delete[] novi_niz;
			}
		}
	
	if(!pronadjeno) {
		std::string izuzetak("Osoba sa imenom ");
		izuzetak+=ime;
		izuzetak+=" nije bila optuzena";
		throw std::domain_error(izuzetak);
	}
	return nova_vel;;
}

int DodajOptuzbu (char **& krivci, int vel, std::string ime) {
	int nova_vel(vel);
	char *tmp(nullptr);
	char **novi_niz(nullptr);
	try{
		tmp = new char[ime.length()+1];
		std::strcpy(tmp, ime.c_str());
		for(int i=0; i<vel; i++) {
			if(!krivci[i]) {
				krivci[i] = tmp;
				tmp = nullptr;
			return vel;
			}
		}
		novi_niz = new char* [vel+1];
		if(novi_niz) {
			for(int i=0; i<vel; i++)  {
				novi_niz[i] = krivci[i];
				krivci[i] = nullptr;
			}
			novi_niz[vel] = tmp;
			tmp=nullptr;
			delete[] krivci;
			krivci = novi_niz;
			novi_niz=nullptr;
			nova_vel = vel+1;
			}
	}catch(std::bad_alloc) {
		delete[] tmp;
		delete[] novi_niz;
		throw;
	}
	return nova_vel;
	
}

void IzlistajOptuzbu (char **krivci, int vel) {
	for(int i=0; i<vel; i++) {
		if(krivci[i]){
			char *tmp(krivci[i]);
			while(*tmp != '\0') {
				std::cout<<*tmp;
				tmp++;
			}
			std::cout<<std::endl;
		}
	}
}

int main ()
{
	char **krivci(nullptr);
	std::cout<<"Koliko potencijalnih krivaca zelite unijeti? "<<std::endl;
	int n;
	std::cin>>n;
	int vel(n);
	std::cin.ignore();
 try{
 	std::vector<std::string> spisak(n);
 	std::cout<<"Unesite potencijalne krivce: "<<std::endl;
 	for(int i=0; i<n; i++)
 		std::getline(std::cin, spisak[i]);
 	vel =PotencijalniKrivci(krivci, spisak);
 	int opcija(0);
 	for(;;) {
 		std::cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: "<<std::endl;
 		std::cin>>opcija;
 		std::cin.ignore();
 		if(opcija == 0)
 				break;
 		if(opcija == 1) {
 				std::cout<<"Unesite ime novog optuzenog: "<<std::endl;
 				std::string ime1;
 				std::getline(std::cin, ime1);
 				vel=DodajOptuzbu(krivci, vel, ime1);
 		}
 		if(opcija == 2) {
 				std::cout<<"Unesite ime koje zelite izbaciti: "<<std::endl;
 				std::string ime2;
 				std::getline(std::cin, ime2);
 				vel=OdbaciOptuzbu(krivci, vel, ime2);
 		}
 		if(opcija == 3) 
 				IzlistajOptuzbu(krivci, vel);
 	}
 }
 catch(std::domain_error e) {
 	std::cout<<e.what();
 }
 catch(std::bad_alloc) {
 }
 if(krivci) 
 	for(int i=0; i<vel; i++)
 		delete[] krivci[i];
 delete[] krivci;
 
	return 0;
}