/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/

#include <iostream>
#include <cstring>
#include <string>
#include <stdexcept>
#include <new>
#include <vector>

int PotencijalniKrivci (char**& lista, std::vector<std::string> imena) {
	
	try{lista=new char* [imena.size()];}
	catch(std::bad_alloc){
		throw;
	}
	int brojac(0);
	
	for(int i=0;i<imena.size();i++){
		lista[i]=nullptr;
	}
	
	try{
		for(int i=0;i<imena.size();i++){
			lista[i]=new char [imena[i].size()+1];
			std::strcpy(lista[i], imena[i].c_str());
			brojac++;
		}
	}
	catch(std::bad_alloc){
		for(int i=0;i<imena.size();i++){
			delete[] lista[i];
		}
		delete[] lista;
		throw;
	}
	
	return brojac;
} //f

void IzlistajOptuzbu(char** lista, int velicina){
	
	for(int i=0;i<velicina;i++){
		if(lista[i]!=nullptr){
			std::cout<<lista[i]<<std::endl;
		}
	}
}

int OdbaciOptuzbu (char**& lista, int velicina, std::string osoba) {
	
	bool ima(0);
	int broj_null(0);
	
	for(int i=0;i<velicina;i++){
		
		if(lista[i]==nullptr){
			broj_null++;
			continue;
		}
		
		if(strcmp(lista[i],osoba.c_str())==0){
			ima=1;
			delete[] lista[i];
			lista[i]=nullptr;
			broj_null++;
		}
	} //izbacivanje i brojanje nullpointera
	
	if(ima==0){
		std::string izuzetak="Osoba sa imenom "+osoba+" nije bila optuzena";
		throw std::domain_error(izuzetak);
	}
	
	if(broj_null>10){
		char** nova_lista=nullptr;
		int nova_velicina=velicina-broj_null;
		
		try{
			nova_lista=new char* [nova_velicina];
		}
		catch(std::bad_alloc izuzetak){
			return velicina;
		}
		
		for(int i=0;i<nova_velicina;i++) nova_lista[i]=nullptr;
		
		int indeks(0);
		
		try{
		for(int i=0;i<velicina;i++){
			if(lista[i]!=nullptr){
				nova_lista[indeks]=new char[std::strlen(lista[i])+1];
				std::strcpy(nova_lista[indeks],lista[i]);
				indeks++;
			}	
		}
		

		for(int i=0;i<velicina;i++) 
			delete[] lista[i];
		delete[] lista;
		
		lista=nova_lista;
		
		return nova_velicina;
	}
		catch(std::bad_alloc){
			for(int i=0;i<nova_velicina;i++) delete[] nova_lista[i];
			delete[] nova_lista;
			
			return velicina;
		}
		
	}
	
	return velicina;
}

int DodajOptuzbu (char**& lista, int velicina, std::string osoba) {
	
	char* NoviKrivac=nullptr;
	
	try{
		NoviKrivac = new char [osoba.size()+1];
	}
	catch(...){throw;}
	
	std::strcpy(NoviKrivac,osoba.c_str());
	
	for(int i=0;i<velicina;i++){
		if(lista[i]==nullptr){
			lista[i]=NoviKrivac;
			return velicina;
		}
	}
	
	char **nova_lista=nullptr;
	
	try{
		nova_lista=new char* [velicina+1];
	}
	catch(std::bad_alloc izuzetak){
		throw;
	}
		
		for(int i=0;i<velicina+1;i++) nova_lista[i]=nullptr;
		
		try{
		
		for(int i=0;i<velicina;i++){
			
			nova_lista[i]=new char[std::strlen(lista[i])+1];
			std::strcpy(nova_lista[i],lista[i]);
		}
		
		nova_lista[velicina]=NoviKrivac;
		
		for(int i=0;i<velicina;i++){
			delete[] lista[i];
		}
		delete[] lista;
		lista=nova_lista;
		return velicina+1;
	}
	catch(std::bad_alloc){
		for(int i=0;i<velicina+1;i++) delete[] nova_lista[i];
		delete[] nova_lista;
		delete[] NoviKrivac;
		
		throw;
	}
	
}



int main ()
{
	int n,velicina;
	std::vector<std::string> krivci;
	std::string osoba;
	
	std::cout<<"Koliko potencijalnih krivaca zelite unijeti? "<<std::endl;
	std::cin>>n;
	
	std::cin.ignore(10000,'\n');
	std::cout<<"Unesite potencijalne krivce: "<<std::endl;

	for(int i=0;i<n;i++){
		std::getline(std::cin, osoba);
		krivci.push_back(osoba);
	}
	
	char** lista=nullptr;
	
	try{
	
	velicina = PotencijalniKrivci(lista, krivci);
	
	int opcija;
	
	for( ; ; ){
		
		std::cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: "<<std::endl;
		std::cin>>opcija;
		
		std::cin.ignore(10000, '\n');
		if(opcija==0) {
			for(int i=0;i<velicina;i++)
				delete[] lista[i];
			delete[] lista;
			break;
		}
		
		if(opcija==1){
			std::cout<<"Unesite ime novog optuzenog: "<<std::endl;
			std::getline(std::cin,osoba);
			
				try {velicina = DodajOptuzbu(lista,velicina,osoba);}
				catch(std::bad_alloc izuzetak){
					std::cout<<"Nedovoljno memorije"<<std::endl;
				}

		}
		else if(opcija==2){
			std::cout<<"Unesite ime koje zelite izbaciti: "<<std::endl;
			std::getline(std::cin,osoba);
			try {velicina=OdbaciOptuzbu(lista, velicina, osoba);}
			catch(std::domain_error izuzetak){
				std::cout<<izuzetak.what()<<std::endl;
			}
			catch(std::bad_alloc izuzetak){
				std::cout<<"Neodovljno memorije";
			}

		}
		else if(opcija==3){
			IzlistajOptuzbu(lista, velicina);
		}
		
		
	}
	
	}
	
	catch(std::bad_alloc){
		std::cout<<"Nedovoljno memorije";
	}

	
	return 0;
}