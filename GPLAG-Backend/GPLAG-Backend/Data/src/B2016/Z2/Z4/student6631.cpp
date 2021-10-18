/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include <vector>
#include <new>
#include <string>
#include <cstring>
#include <stdexcept>

int PotencijalniKrivci(char **&a, std::vector<std::string> string){
	int vel(0);
	a=nullptr;
	try{
		a=new char* [string.size()];
		for(int i=0;i<string.size();i++){
			a[i]=new char[string[i].size()+1];
			vel++;
		}
		for(int i=0;i<string.size();i++){
			strcpy(a[i],string[i].c_str());
		}
	}
	catch(std::bad_alloc){
		for(int i = 0; i < string.size(); i++) delete[] a[i];
		delete[] a;
		throw;
	}
	return vel;
}

int OdbaciOptuzbu(char **&a, int vel, std::string string){
	bool nijenaspisku(true);
	for(int i=0;i<vel;i++){
		if(a[i]==nullptr)continue;
			if(!strcmp(string.c_str(),a[i])){
				nijenaspisku=false;
				delete[] a[i];
				a[i]=nullptr;
	}
	}
	if(nijenaspisku){
		throw std::domain_error("Osoba sa imenom "+string+" nije bila optuzena");
	}
	
	int brojac(0);
	for(int i=0;i<vel;i++){
		if(a[i]==nullptr) brojac++;
	}
	
	if(brojac>10){
		char** novi=nullptr;
		try{
			novi=new char* [vel-brojac];
			int red_br(0);
				
			for(int i=0;i<vel;i++){
				if(a[i]==nullptr) continue;
				novi[red_br]=a[i];
				red_br++;
		}	
		delete[] a;
			a=novi;
			}	
		catch(...){
			throw;
		}
	}
	
return vel;
}

int DodajOptuzbu(char **&a, int vel, std::string string){
	char* ime=nullptr;

	try{
	ime=new char[string.size()+1];
	strcpy(ime, string.c_str());
	
	bool imanull(false);
	for(int i=0;i<vel;i++){
		if(a[i]==nullptr) {
			a[i]=ime;
			imanull=1;
	}
	}
	
	if(!imanull){
		vel++;
		char** novi=new char*[vel];

		for(int i=0;i<vel-1;i++){
			novi[i]=a[i];
		}
		novi[vel-1]=ime;
		delete[] a;
		a=novi;
	
	}}
	catch(...){throw;}
	return vel;
}

void IzlistajOptuzbu(char **a, int vel){
	for(int i=0;i<vel;i++){
		if(a[i]==nullptr)continue;
		else std::cout<<a[i]<<std::endl;
	}
}


int main ()
{
	std::cout<<"Koliko potencijalnih krivaca zelite unijeti?"<<std::endl;
	int broj_krivaca;
	std::cin>>broj_krivaca;
	char** a=nullptr;
	std::vector<std::string> string;
	std::cout<<"Unesite potencijalne krivce: \n";
	std::string ime;
	std::cin.ignore(10000, '\n');
	for(int i=0;i<broj_krivaca;i++){
		std::getline(std::cin, ime);
		string.push_back(ime);
	}
	int velicina(PotencijalniKrivci(a,string));
	char** nova(a);
	int opcija;
	do{
	std::cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj:"<<std::endl;
	std::cin>>opcija;
	
	switch(opcija){
		case 0: break;
		case 1:{
			std::cout<<"Unesite ime novog optuzenog: "<<std::endl;
			std::string novi;
			std::cin.ignore(10000, '\n');
			std::getline(std::cin, novi);
			velicina=DodajOptuzbu(nova,velicina,novi);
			break;
		}
		case 2:{
			std::cout<<"Unesite ime koje zelite izbaciti: "<<std::endl;
			std::string novi2;
			std::cin.ignore(10000, '\n');
			std::getline(std::cin, novi2);
			try{
			velicina=OdbaciOptuzbu(nova,velicina,novi2);
			}
			catch(std::domain_error msg){
				std::cout<<msg.what()<<std::endl;
			}
			break;
		}
		case 3:{ 
			IzlistajOptuzbu(nova,velicina);
			break;
		}
	}}
	while(opcija!=0);
	
	for(int i=0;i<velicina;i++) delete[] nova[i];
	delete[] nova;
	
	return 0;
}