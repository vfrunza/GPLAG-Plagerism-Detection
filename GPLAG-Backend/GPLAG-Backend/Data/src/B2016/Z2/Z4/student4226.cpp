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

void IzlistajOptuzbu(char** optuzeni, int n){
	for(int i(0); i<n; i++){
		if(optuzeni[i] == nullptr) continue;
		auto j(optuzeni[i]);
		int brslova(0);
		while(*j!='\0'){
			brslova++;
			j++;
		}
		for(int k(0); k<brslova; k++)
			std::cout << optuzeni[i][k];
		std::cout << std::endl;
	}
}

int PotencijalniKrivci(char** &optuzeni, std::vector<std::string> belajsuzi){
	//char** pokazivac;
	int brojac(0);
	try{
		optuzeni = nullptr;
		optuzeni = new char *[int(belajsuzi.size())];
		for(int i(0); i<belajsuzi.size(); i++) optuzeni[i] = nullptr;
		try{
			for(int i(0); i<belajsuzi.size(); i++)
				optuzeni[i] = new char [belajsuzi[i].size()+1];
			for(int i(0); i<belajsuzi.size(); i++){
				for(int j(0); j<=belajsuzi[i].size(); j++){
					if(j==belajsuzi[i].size()){
						optuzeni[i][j] = '\0';
						break;
					}
					optuzeni[i][j] = belajsuzi[i][j];
				}
				brojac++;
			}
		//optuzeni = pokazivac;
		}
		catch(...){
			for(int i(0); i<belajsuzi.size(); i++) delete[] optuzeni[i], optuzeni[i]=nullptr;
			delete[] optuzeni;
			optuzeni=nullptr;
			throw std::bad_alloc();
		}
	}
	catch(...){
		//for(int i(0); i<belajsuzi.size(); i++) delete[] optuzeni[i];
		delete[] optuzeni;
		optuzeni=nullptr;
		throw std::bad_alloc();
	}
	return brojac;
}

int OdbaciOptuzbu(char** &optuzeni, int n, std::string rijec){
	bool valja(true), ima_li(true);
	for(int i(0); i<n; i++){
		if(optuzeni[i] == nullptr) continue;
		if(optuzeni[i][0] == rijec[0]){
			for(int k(0); k<rijec.length(); k++){
				if(optuzeni[i][int(rijec.length())] != '\0') {valja=false; break;}
				if(optuzeni[i][k]!=rijec[k]){ valja=false; break;}
			}
			if(valja){
				delete[] optuzeni[i];
				optuzeni[i] = nullptr;
				ima_li=false;
				break;
			}
			valja = true;
		}
	}
	if(ima_li){
		std::string izuzetak = "Osoba sa imenom " + rijec + " nije bila optuzena";
		throw std::domain_error(izuzetak);
	}
	int brnull(0);
	for(int i(0); i<n; i++)
		if(optuzeni[i] == nullptr) brnull++;
	if(brnull>10){
		char** pomocni(nullptr);
		try{
			pomocni = new char*[n-brnull];
			for(int i(0); i<n-brnull; i++) pomocni[i]=nullptr;
			try{
				int brbr(0);
				for(int i(0); i<n; i++){
					if(optuzeni[i]==nullptr) continue;
					int brslova(0);
					auto k(optuzeni[i]);
					while (*k!='\0'){
						brslova++;
						k++;
					}
					pomocni[brbr]=new char[brslova+1];
					brbr++;
				}
			}
			catch(...){
				for(int i(0); i<n-brnull; i++) delete[] pomocni[i];
				delete[] pomocni;
				throw std::bad_alloc();
			}
		}
		catch(...){
			delete[] pomocni;
			throw std::bad_alloc();
		}
		int asdasd(0);
		for(int i(0); i<n; i++){
			if(optuzeni[i]==nullptr) continue;
			auto rec(optuzeni[i]);
			int brslova(0);
			while(*rec!='\0'){
				brslova++;
				rec++;
			}
			for(int j(0); j<brslova+1; j++){
				if(j==brslova){ pomocni[asdasd][j] = '\0'; break;}
				pomocni[asdasd][j] = optuzeni[i][j];
			}
			asdasd++;
		}
		for(int i(0); i<n; i++){ delete[] optuzeni[i]; optuzeni[i]=nullptr;}
		delete[] optuzeni;
		optuzeni = pomocni;
		return n-brnull;
	}
	return n;
}

int DodajOptuzbu(char** &optuzeni, int n, std::string rijec){
	char* pok = nullptr;
	bool valja(false);
	try{
		pok = new char[rijec.size()+1];
	}
	catch(...){
		delete[] pok;
		throw std::bad_alloc();
	}
	for(int i(0); i<int(rijec.size()+1); i++){
		if(i==int(rijec.size())){
			pok[i]='\0';
			break;
		}
		pok[i] = rijec[i];
	}
	for(int i(0); i<n; i++)
		if(optuzeni[i]==nullptr){
			optuzeni[i] = new char[rijec.size()+1];
			for(int j(0); j<int(rijec.size())+1; j++)
				//if(j==int(rijec.size())){ optuzeni[i][j] = '\0'; break;}
				optuzeni
				[i][j] = pok[j];
			valja=true;
			break;
		}
	if(!valja){
		char** pomocni(nullptr);
		pomocni = new char*[n+1];
		for(int i(0); i<n+1; i++) pomocni[i]=nullptr;
		try{
			for(int i(0); i<n+1; i++){
				if(i==n){
					pomocni[i] = new char [rijec.size()+1];
					break;
				}
				int brslova(0);
				auto j(optuzeni[i]);
				//if(j==nullptr){ pomocni[i] = new char [rijec.size()+1]; break;}
				while (*j!='\0'){
					brslova++;
					j++;
				}
				pomocni[i]=new char[brslova+1];
			}
		}
		catch(...){
			for(int i(0); i<n+1; i++) delete[] pomocni[i];
			delete[] pomocni;
			throw std::bad_alloc();
		}
		for(int i(0); i<n+1; i++){
			if(i==n){
				for(int j(0); j<int(rijec.size()+1); j++){
					if(j==int(rijec.size())) {pomocni[i][j] = '\0'; break;}
					pomocni[i][j] = pok[j];
				}
				break;
			}
			int brslova(0);
			auto k(optuzeni[i]);
			while(*k!='\0'){
				brslova++;
				k++;
			}
			for(int j(0); j<brslova+1; j++)
				pomocni[i][j] = optuzeni [i][j];
		}
		for(int i(0); i<n; i++) delete[] optuzeni[i];
		delete[] optuzeni;
		optuzeni = pomocni;
		n++;
	}
	delete[] pok;
	return n;
}


int main (){
	int n;
	std::cout << "Koliko potencijalnih krivaca zelite unijeti? " << std::endl;
	std::cin >> n;
	std::cin.ignore(10000, '\n');
	std::vector<std::string> krivci;
	std::cout << "Unesite potencijalne krivce: " << std::endl;
	for(int i(0); i<n; i++){
		std::string temp;
		std::getline(std::cin, temp);
		krivci.push_back(temp);
	}
	char** optuzeni;
	int broj_optuzenih(0);
	try{
		int broj = PotencijalniKrivci(optuzeni, krivci);
		for(;;){
			std::cout << "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: " << std::endl;
			int izbor;
			std::cin >> izbor;
			std::cin.ignore(10000, '\n');
			if(izbor == 0) break;
//			int broj = PotencijalniKrivci(optuzeni, krivci);
			//std::cout << broj;
			switch(izbor){
				case 1: try{
							std::cout << "Unesite ime novog optuzenog: " << std::endl;
							std::string temp;
							std::getline(std::cin, temp);
							broj = DodajOptuzbu(optuzeni, broj, temp);
							broj_optuzenih = broj;
						}
						catch(std::bad_alloc){
							std::cout << "Alokacija nije uspjela";
						}
						break;
				case 2: try{
							std::cout << "Unesite ime koje zelite izbaciti: " << std::endl;
							std::string temp;
							std::getline(std::cin, temp);
							broj = OdbaciOptuzbu(optuzeni, broj, temp);
							broj_optuzenih = broj;
						}
						catch(std::bad_alloc){
							std::cout << "Alokacija nije uspjela";
						}
						catch(std::domain_error e){
							std::cout << e.what() << std::endl;
						}
						break;
				case 3: try{
							broj_optuzenih = broj;
							IzlistajOptuzbu(optuzeni, broj);
						}
						catch(...){
							std::cout << "Alokacija nije uspjela";
						}
						break;
			}	
		}
		for(int i(0); i < broj_optuzenih; i++){ delete[] optuzeni[i]; optuzeni[i]=nullptr;}
		delete[] optuzeni;
		optuzeni = nullptr;
	}
	catch(std::bad_alloc()){
		for(int i(0); i< broj_optuzenih; i++){ delete[] optuzeni[i]; optuzeni[i]=nullptr;}
		delete[] optuzeni;
		std::cout << "Nedovoljno memorije";
	}
	
	return 0;
}