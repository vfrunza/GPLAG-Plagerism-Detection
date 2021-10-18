/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <cmath>

int PotencijalniKrivci(char **&pocetak, std::vector<std::string> vs){
	int brojac(0);
	char **pok(nullptr);
	try{
		pok = new char* [vs.size()];
		for(int i=0; i<vs.size(); i++){
			pok[i] = nullptr;
		}
		
		for(int i=0; i<vs.size(); i++){
			pok[i] = new char[vs[i].length()+1];
			brojac++;
			
			for(int j=0; j<vs[i].length(); j++){
				pok[i][j] = vs[i][j];
			}
			pok[i][vs[i].length()] = '\0';
		}
		pocetak = pok;
	}catch(std::bad_alloc){
		for(int i=0; i<vs.size(); i++){
			delete[] pok[i];
		}
		delete[] pok;
		throw;
	}
	
	return brojac;
}

int OdbaciOptuzbu(char **&pocetak, int n , std::string ime){
	int i;
	int brojac(0);
	bool a(true);
	for(i=0; i<n ; i++){
		int j;
		if(pocetak[i] != nullptr){
			for(j=0; j<ime.length(); j++){
				if(ime[j] != pocetak[i][j]){
					break;
				}
			}
		
			if(j == ime.length()){
				delete[] pocetak[i];
				pocetak[i] = nullptr;
				a = false;
				brojac++;
			}
		}else{
			brojac++;
		}
	}
	
	if(a){
		std::string izuzetak("Osoba sa imenom " + ime + " nije bila optuzena");
		throw std::domain_error (izuzetak);
	}
	
	int k(0);
	if(brojac > 10){
		char **pok(nullptr);
		pok = new char *[n-brojac];
		for(int j=0; j< n-brojac; j++){
			pok[j] = nullptr;
		}
		for(i=0; i < n; i++){
			if(pocetak[i] != nullptr){
				int duzina(1);
				while(pocetak[i][duzina] != '\0'){
					duzina++;
				}
				pok[k] = new char[duzina + 1];
				
				for(int j=0; j<duzina; j++){
					pok[k][j] = pocetak[i][j];
				}
				pok[k][duzina] = '\0';
				k++;
			}
		}
		
		for(i=0; i<n; i++) delete[] pocetak[i];
		delete[] pocetak;
		pocetak = pok;
	}else{
		k = n;
	}
	
	return k;
}

int DodajOptuzbu(char **&pocetak, int n, std::string ime){
	char *pomocni(nullptr);
	try{
		pomocni = new char [ime.length()+1];
		for(int i=0; i<ime.length(); i++){
			pomocni[i] = ime[i];
		}
		pomocni[ime.length()] = '\0';
	
		int i(0);
		for(i=0; i<n; i++){
			if(pocetak[i] == nullptr){
				pocetak[i] = pomocni;
				break;
			}
		}
	
		if(i == n){
			char **pok(nullptr);
			pok = new char *[n+1];
			for(i=0; i<n; i++){
				pok[i] = pocetak[i]; 
			}
			pok[n] = pomocni;
		
			delete[] pocetak;
			n++;
		
			pocetak = pok;
		}
	}catch(std::bad_alloc){
		throw;
	}
	
	return n;
}

void IzlistajOptuzbu(char **pocetak, int n){
	for(int i=0; i<n; i++){
		if(pocetak[i] != nullptr){
			std::cout << pocetak[i] << std::endl;
		}
	}
}

int main ()
{
	std::cout << "Koliko potencijalnih krivaca zelite unijeti? " << std::endl;
	int n;
	std::cin >> n;
	std::cin.ignore (10000,'\n');
	std::vector<std::string> vs(n);
	std::cout << "Unesite potencijalne krivce: " << std::endl;
	std::string rijec;
	for(int i=0; i<n; i++){
		std::getline(std::cin, rijec);
		vs[i].resize(rijec.length());
		vs[i] = rijec;
	}
	char **pok;
	int br_alociranih( PotencijalniKrivci(pok, vs) );
	
	std::cout << "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: " << std::endl;
	int opcija;
	std::cin >> opcija;
	std::string ime;
	
	while(opcija != 0){
		
		if(opcija == 1){
			std::cout << "Unesite ime novog optuzenog: " << std::endl;
			try {
				std::cin.ignore(1000, '\n');
				std::getline(std::cin, ime);
				br_alociranih = DodajOptuzbu(pok, n, ime);
			}catch(std::bad_alloc){
				
			}
		}else if(opcija == 2){
			std::cout << "Unesite ime koje zelite izbaciti: " << std::endl;
			try{
				std::cin.ignore(1000, '\n');
				std::getline(std::cin, ime);
				br_alociranih = OdbaciOptuzbu(pok, br_alociranih, ime);
			}catch(std::domain_error izuzetak){
				std::cout << izuzetak.what() << std::endl;
			}
			
		}else if(opcija == 3){
			IzlistajOptuzbu(pok, br_alociranih);
			
		}
		
		std::cout << "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: " << std::endl;
		std::cin >> opcija;
	}
	
	for(int i=0; i<br_alociranih; i++) delete[] pok[i];
	delete[] pok;
	
	return 0;
}