/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

int PotencijalniKrivci(char **&znakovi, std::vector<std::string> imena){
	char **pok{nullptr};
	int brojac{0};
	try{
	    pok=new char*[imena.size()];
	    for(int i{0}; i<imena.size(); i++) pok[i] = nullptr;
	    try{
		    for(int i{0}; i<imena.size(); i++){ 
		    	pok[i]=new char[imena[i].size()+1];
		    	brojac++;
		    	for(int j{0}; j<imena[i].size()+1; j++){
		    		if(j==imena[i].size()) pok[i][j] = '\0';
		    		else
		    		pok[i][j] = imena.at(i).at(j);
		    	}
		    }
		}
		catch(...){
			for(int i{0}; i<imena.size(); i++) delete[] pok[i];
			throw;
		}
	}
	catch(...){ 
		delete[] pok;
		throw std::bad_alloc();
	}
	znakovi=pok;
	return brojac;
}

int OdbaciOptuzbu(char **&znakovi, int velicina, std::string nije){
	for(int i{0}; i<velicina; i++){
		int k{0};
		while(znakovi[i] != nullptr && znakovi[i][k] != '\0') k++;
		if(k == nije.size())
		for(int j{0}; j<k; j++){
			if(nije.at(j) != znakovi[i][j]) break;
			if(j == k-1){
				delete[] znakovi[i];
				znakovi[i]=nullptr;
				i=velicina;
				break;
			}
		}
	}
	int izbrisani{0};
	for(int i{0}; i<velicina; i++)
	    if(znakovi[i] == nullptr) izbrisani++;
	
	if(izbrisani==0) throw std::domain_error("Osoba sa imenom " + nije + " nije bila optuzena");
	if(izbrisani>10){
		char **novi{nullptr};
		try{
			novi = new char*[velicina-izbrisani];
			int j{0}, i{0};
			while(i<velicina && j<velicina-izbrisani){
				if(znakovi[i] != nullptr){
					novi[j]=znakovi[i];
					j++;
				}
				i++;
			}
			znakovi=novi;
			velicina=velicina-izbrisani;
		}
		catch(...){
			delete[] novi;
		}
	}
	return velicina;
}

int DodajOptuzbu(char **&znakovi, int velicina, std::string jeste){
	char *novi{nullptr};
	try{
		novi = new char[jeste.size()+1];
		for(int i{0}; i<jeste.size()+1; i++){
			if(i == jeste.size()) novi[i]='\0';
			else
			novi[i]=jeste.at(i);
		}
		int i{0}; 
		while(i<velicina){
			if(znakovi[i]==nullptr){
				znakovi[i]=novi;
				velicina++;
				break;
			}
			i++;
		}
		if(i==velicina){
			char **josnoviji{nullptr};
			try {
				josnoviji = new char*[velicina+1];
				for(int j{0}; j<velicina+1; j++){
					if(j<velicina) josnoviji[j]=znakovi[j];
					else josnoviji[j]=novi;
				}
				delete[] znakovi;
				znakovi=josnoviji;
				velicina++;
			}
			catch (...) {
				delete[] josnoviji;
				throw std::bad_alloc();
			}
			
		}
	}
	catch(...){
		delete[] novi;
		throw std::bad_alloc();
	}
	return velicina;
}

void IzlistajOptuzbu(char **znakovi, int velicina){
	for(int i{0}; i<velicina; i++){
		if(znakovi[i] != nullptr){
			int j{0};
			while(znakovi[i][j] != '\0'){ 
				std::cout << znakovi[i][j];
				j++;
			}
			std::cout << std::endl;
		}
	}
}

int main (){
	std::cout << "Koliko potencijalnih krivaca zelite unijeti? " << std::endl;
	int velicina;
	std::cin >> velicina;
	std::cin.ignore(10000,'\n');
	std::cout << "Unesite potencijalne krivce: " << std::endl;
	std::vector<std::string> spisak(velicina);
	for(int i{0}; i<velicina; i++) std::cin >> spisak[i];
	char **znak;
	try{
	   velicina = PotencijalniKrivci(znak,spisak);
	}
	catch(std::bad_alloc){
		std::cout << std::endl << "Izuzetak PotencijalniKrivci";
		return 0;
	}
	int oznaka;
	do{
	   std::cout << "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: " << std::endl;;
	   std::cin >> oznaka;
	   if(oznaka == 0){
	    	for(int i{0}; i<velicina; i++) delete[] znak[i];
	    	delete[] znak;
	    	return 0;
	   }
	   if(oznaka == 1){
	    	std::cout << "Unesite ime novog optuzenog: " << std::endl;
	    	std::string novi;
	    	std::cin >> novi;
	    	try{
	    	   velicina = DodajOptuzbu(znak,velicina,novi);
	    	}
	    	catch(std::bad_alloc){
	    		std::cout << std::endl << "Izuzetak DodajOptuzbu";
	    		return 0;
	    	}
	   }
	   if(oznaka == 2){
	   	 std::cout << "Unesite ime koje zelite izbaciti: " << std::endl;
	   	 std::string ime;
	   	 std::cin >> ime;
	   	 try{
	   	    velicina = OdbaciOptuzbu(znak,velicina,ime);
	   	 }
	   	 catch(std::domain_error izuzetak){
	   	 	std::cout << izuzetak.what() << std::endl;
	   	 }
	   }
	   if(oznaka==3){
	   	IzlistajOptuzbu(znak,velicina);
	   }
	}while(oznaka==1 || oznaka==2 || oznaka==3);
	
	for(int i{0}; i<velicina; i++) delete[] znak[i];
	delete[] znak;
	return 0;
}