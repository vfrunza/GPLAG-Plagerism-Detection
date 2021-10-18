/*B 16/17, Zadaća 2, Zadatak 4 */
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <new>
#include <stdexcept>

typedef std::vector<std::string> VektorStringova;

int PotencijalniKrivci (char** &pok, VektorStringova v){

	int n(v.size());
	
	try{
		pok=nullptr;
		pok=new char* [n]; 
		for(int i=0; i<n; i++) pok[i]=nullptr;
		
		for(int i=0; i<n; i++) {
			pok[i]=new char[v[i].length()+1];
			std::strcpy(pok[i], v[i].c_str());
		}
	}

	catch(...){
		for(int i=0; i<n; i++) {
			delete[] pok[i];
			pok[i]=nullptr;
		}
		delete[] pok;
		pok=nullptr;
		throw std::bad_alloc();
	}
	return n;
}

int DodajOptuzbu (char** &pok, int n, std::string s){
	
	char *novi(nullptr);
	bool ubacio(false);
	
	try{
		novi=new char [s.length()+1];
		strcpy(novi, s.c_str());
		bool null(false);
		
		for(int i=0; i<n; i++) {
			if(pok[i]==nullptr && !null){
				pok[i]=novi;
				null=true;
				ubacio=true;
				novi=nullptr;
			}
		}
		
		if(!ubacio){
			char **p(nullptr);
			
			try{
				p=new char* [n+1];
				for(int i=0; i<n+1; i++) p[i]=nullptr;
				
				for(int i=0; i<n; i++) p[i] = new char[std::strlen(pok[i])+1];
				p[n] = new char [std::strlen(novi)+1];
				
				for(int i=0; i<n; i++) strcpy(p[i], pok[i]);
				strcpy(p[n], novi);
				delete[] novi;
				novi=nullptr;
				
				for(int i=0; i<n; i++) {
					delete[] pok[i];
					pok[i]=nullptr;
				}
				
				delete[] pok;
				pok=p;
				p=nullptr;
			}
			catch(...){	
				for(int i=0; i<n; i++) delete[] p[i];
				delete[] p;
				throw std::bad_alloc();
			}
		}
	}
	
	catch(...){
		delete[] novi;
		throw std::bad_alloc();
	}

	if(!ubacio) return n+1;
	return n;
}

int OdbaciOptuzbu (char** &pok, int n, std::string s){
	
	bool nasao(false);

	for(int i=0; i<n; i++){
			if(pok[i]!=nullptr && !strcmp(pok[i], s.c_str())){
				delete[] pok[i];
				pok[i]=nullptr;
				nasao=true;
			}
	}

	int obrisani(0);
	for(int i=0; i<n; i++) if(pok[i]==nullptr) obrisani++;
	
	if(obrisani>10){
		char** p(nullptr);
		int novi(0);
		for(int i=0; i<n; i++) if(pok[i]!=nullptr) novi++;

		try{
			p=new char *[novi];
			for(int i=0; i<novi; i++) p[i]=nullptr;
			
			int brojac(0);
			for(int i=0; i<n; i++){
				if(pok[i]!=nullptr) p[brojac++] = new char [std::strlen(pok[i])+1];
			}
			
			brojac=0;
			for(int i=0; i<n; i++){
				if(pok[i]!=nullptr) strcpy (p[brojac++], pok[i]);
			}
			
			for(int i=0; i<n; i++) {
				delete[] pok[i];
				pok[i]=nullptr;
			}	
			pok=p;
			p=nullptr;
			return novi;
		}
		catch(...){
			for(int i=0; i<novi; i++) delete[] p[i];
			delete[] p;
			p=nullptr;
			return n;
		}
	}
	
	if(!nasao) throw std::domain_error ("Osoba sa imenom "+s+" nije bila optuzena");
	return n;
}

void IzlistajOptuzbu (char **pok, int n){
	for(int i=0; i<n; i++){
		if(pok[i]==nullptr) continue;
		std::cout << pok[i] << std::endl;
	}
}

int main ()
{
	char **pok(nullptr);
	VektorStringova lista; 
	int n;
	
	std::cout << "Koliko potencijalnih krivaca zelite unijeti? \n";
	std::cin >> n; lista.resize(n);
	std::cin.ignore(10000, '\n');
	std::cout << "Unesite potencijalne krivce: \n";
	for(int i=0; i<n; i++) std::getline(std::cin, lista[i]);
	
	try{
		n=PotencijalniKrivci(pok, lista);
		int opcija(38);
		
		while(opcija!=0){
			std::cout << "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: \n";
			std::cin >> opcija;
			
			if(opcija==1){
					std::cin.ignore(10000, '\n');
					std::string ime;
					std::cout << "Unesite ime novog optuzenog: \n";
					std::getline(std::cin, ime);
					n=DodajOptuzbu(pok, n, ime);
			}
			
			if(opcija==2){
				std::cin.ignore(10000, '\n');
				std::string ime;
				std::cout << "Unesite ime koje zelite izbaciti: \n";
				std::getline(std::cin, ime);
				try{
					n=OdbaciOptuzbu(pok, n, ime);
				}
				catch(std::domain_error izuzetak){
					std::cout << izuzetak.what() << std::endl;
				}
				catch(...){
					std::cout << "Pogresan tip izuzetka." << std::endl;
				}
			}
			if(opcija==3) IzlistajOptuzbu(pok, n);
		}
		for(int i=0; i<n; i++) {
			delete[] pok[i];
			pok[i]=nullptr;
		}
		delete[] pok;
		pok=nullptr;
	}
	catch(std::bad_alloc()){
		
	}
	return 0;
}

