/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stdexcept>

void IzlistajOptuzbu(char ** &pokazivac, int n){
	for(int i=0; i < n; i++){
		if(pokazivac[i] == nullptr) continue;
		std::cout << pokazivac[i];
		std::cout << std::endl;
	}
}

int PotencijalniKrivci(char ** &pokazivac, std::vector<std::string> &matrica){
	int brojac(0);
	pokazivac = nullptr;
	try{
		pokazivac = new char *[matrica.size()];
		for(int i=0; i < matrica.size(); i++) pokazivac[i] = nullptr;
		for(int i=0; i < matrica.size(); ++i){
			pokazivac[i] = new char[matrica[i].size()+1];
			const char *pok = matrica[i].c_str();
			for(int j=0; j < matrica[i].size(); j++){
				pokazivac[i][j] = pok[j];
			}
			pokazivac[i][matrica[i].size()] = '\0';
			brojac++;
		}
		
		
	}catch(...){
		for(int i=0; i < matrica.size(); i++) delete[] pokazivac[i];
		delete [] pokazivac;
		throw std::bad_alloc();
	}
	return brojac;
}

int OdbaciOptuzbu(char ** &pokazivac, int n, const std::string &string){
	
	const char *pok = string.c_str();
	
	bool ImalGlavonje=false;
	for(int i=0; i < n; i++){
		if(pokazivac[i] != nullptr && strcmp(pokazivac[i], pok) == 0){
			ImalGlavonje = true;
			delete[] pokazivac[i];
			pokazivac[i] = nullptr;
			break;
		}
	}

	if(!ImalGlavonje) throw std::domain_error("Osoba sa imenom " + string + " nije bila optuzena");
	int brojac(0);
	for(int i=0; i < n; i++) if(pokazivac[i] == nullptr) brojac++;
	
	int novi(n);
	if(brojac>10){
		for(int i=0; i < n; i++) if(pokazivac[i] != nullptr) novi--;
		
		char ** noviPokazivac = nullptr;
		try {
			int k=0;
			noviPokazivac = new char *[novi];
			for(int i=0; i < novi; i++) noviPokazivac[i] = nullptr;
			for(int i=0; i < n; i++){
				if(pokazivac[i] != nullptr){
					noviPokazivac[k] = pokazivac[i];
					k++;
					pokazivac[i] = nullptr;
				}
			}
			delete []pokazivac;
			pokazivac = nullptr;
			pokazivac = noviPokazivac;
			
		}catch(...){
			return n;
		}
	}
	return novi;
}

int DodajOptuzbu(char ** &pokazivac, int n, const std::string &string){
		
		char **noviPokazivacMoraSe = nullptr;
		char *pokazivacNovog = nullptr;
		
		try{
			pokazivacNovog = new char [string.size()+1];
			strcpy(pokazivacNovog, string.c_str());
		}catch(...){
			delete []pokazivacNovog;
			pokazivacNovog = nullptr;
			throw std::bad_alloc();
		}
		
		
		bool ImalGlavonjeZaNullptr = false;
		for(int i=0; i < n; i++){
			if(pokazivac[i] == nullptr){
				ImalGlavonjeZaNullptr = true;
				pokazivac[i] = pokazivacNovog;
				pokazivacNovog = nullptr;
				break;
			}
		}
		
		try {
		if(!ImalGlavonjeZaNullptr) {
			try{
			noviPokazivacMoraSe = new char *[n+1];
			for(int i=0; i < n+1; i++) noviPokazivacMoraSe[i] = nullptr;
			for(int i=0; i < n; i++) noviPokazivacMoraSe[i] = pokazivac[i];
			noviPokazivacMoraSe[n] = pokazivacNovog;
			
			for(int i=0; i < n; i++) pokazivac[i] = nullptr;
			delete []pokazivac;
			pokazivac = nullptr;
			pokazivac = noviPokazivacMoraSe;
			pokazivacNovog = nullptr;
			
			}catch(...){
				for(int i=0; i < n+1; i++) delete noviPokazivacMoraSe[i];
				for(int i=0; i < n+1; i++) noviPokazivacMoraSe[i] = nullptr;
				delete []noviPokazivacMoraSe;
				noviPokazivacMoraSe = nullptr;
				delete []pokazivacNovog; // dodano
				pokazivacNovog = nullptr; // dodano
				throw std::bad_alloc();
			}
		}
		
		pokazivacNovog = nullptr;
		
		}catch(...){
			delete []pokazivacNovog;
			pokazivacNovog = nullptr;
			throw std::bad_alloc();
		}
		if(!ImalGlavonjeZaNullptr) return n+1;
		else return n;
}

int main (){
	std::string string;
	int broj_pot_krivaca;
	std::cout << "Koliko potencijalnih krivaca zelite unijeti? " << std::endl;
	std::cin >> broj_pot_krivaca;
	std::vector<std::string> spisakGlavonja(broj_pot_krivaca);
	std::cin.ignore(10000, '\n');
	std::cout << "Unesite potencijalne krivce: " << std::endl;
	for(int i=0; i < broj_pot_krivaca; i++){
		std::getline(std::cin, spisakGlavonja[i]);
	}
	
	char **nizPotencijala;
	int duzina(0);
	try{
		duzina = PotencijalniKrivci(nizPotencijala, spisakGlavonja);
	}catch(...){
		std::cout << "Nema dovoljno memorije!" << std::endl;
		return 0;
	}
	int x;
	do{
		std::cout << "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: " << std::endl;
		std::cin >> x;
		if(x == 1){
			
			std::cout << "Unesite ime novog optuzenog: " << std::endl;
			std::cin.ignore(10000,'\n');
			std::getline(std::cin, string);
			try{
			duzina = DodajOptuzbu(nizPotencijala, duzina, string);
			}catch(...){
				std::cout << "Nema dovoljno memorije!" << std::endl;
				return 0;
			}
		}else if(x == 2){
			std::cout << "Unesite ime koje zelite izbaciti: " << std::endl;
			std::cin.ignore(10000,'\n');
			std::getline(std::cin, string);
			try{
			duzina = OdbaciOptuzbu(nizPotencijala, duzina, string);
			}catch(std::domain_error exec){
				std::cout << exec.what() << std::endl;
				// return 0;
			}
		}else if(x == 3){
			IzlistajOptuzbu(nizPotencijala, duzina);
		}
		
		
	}while(x!=0);
	
	for(int i=0; i < duzina; i++) delete[] nizPotencijala[i];
	delete [] nizPotencijala;
	
	return 0;
}