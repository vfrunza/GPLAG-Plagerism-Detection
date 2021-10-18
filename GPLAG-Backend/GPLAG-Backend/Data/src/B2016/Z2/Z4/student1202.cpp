/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <cstring>
int PotencijalniKrivci(char **& ime, std::vector<std::string> imena){
	try{
	ime=new char*[imena.size()+1];
	}
	catch(std::bad_alloc e){
		delete[] ime;
		throw e;
	}
	for(int i=0;i<imena.size();i++){
		ime[i]=nullptr;
	}
	int brojac(0);
	for(int i=0;i<imena.size();i++){
		try{
			ime[i]=new char[imena[i].length()+1];
			brojac++;
		}
		catch(std::bad_alloc e){
			delete[] ime;
			throw e;
		}
	}
	for(int i=0;i<imena.size();i++){
		char radni_prostor[1000];
		for(int j=0;j<imena[i].length();j++){
			radni_prostor[j]=imena[i][j];
		}
		radni_prostor[imena[i].length()]='\0';
		std::strcpy(ime[i],radni_prostor);
	}
	return brojac;
}
int OdbaciOptuzbu(char **& ime, int n, std::string osoba){
	int br(0);
	char radni_prostor[1000];
	char**ime1=nullptr;
	for(int i=0;i<osoba.length();i++)radni_prostor[i]=osoba[i];
	radni_prostor[osoba.length()]='\0';
	bool nema_krivaca(true);
	int broj;
	for(int i=0;i<n;i++){
		if(std::strcmp(radni_prostor,ime[i])==0){nema_krivaca=false;broj=i;}
	}
	if(nema_krivaca==true)throw std::domain_error("Osoba sa imenom "+osoba+" nije bila optuzena");
	if(nema_krivaca==false){
		int brojac(0);
		for(int i=0;i<n;i++){
			if(std::strcmp(radni_prostor,ime[i])==0){
				delete[] ime[i];
				brojac++;
			}
		}
		if(brojac<10){
			for(int i=0;i<n;i++){
				if(ime[i][0]=='\0')ime[i]==nullptr;
			}
		}
		else if(brojac>10){
			try{
			ime1=new char*[n-brojac];
			}catch(std::bad_alloc e){
				delete[] ime1;
				throw e;
			}
			br=0;
			for(int i=0;i<n;i++){
				if(ime[i]!=nullptr){
				
					try{
						ime1[br++]=new char[strlen(ime[i])];
					}
					catch(std::bad_alloc e){
						throw e;
					}
				}
			}
			
		}
	}

	for(int i=0;i<n;i++){
		if(ime[i]!=nullptr){
		delete[] ime[i];
		ime[i]==nullptr;
		}
	}
	ime=ime1;
	
	return br;
}
int DodajOptuzbu(char **& ime,int n, std::string osoba){
	char*novi_niz=nullptr;
	try{
	novi_niz=new char[osoba.size()+1];
	}catch(std::bad_alloc e){
		delete[] novi_niz;
		throw e;
	}
	bool ima_prazan(true);
	for(int i=0;i<n;i++){
		if(ime[i]==nullptr){
			ima_prazan=false;
			ime[i]=novi_niz;
		}
	}
	char**ime_novi=nullptr;
	if(ima_prazan==true){
		try{
		ime_novi=new char*[n+1];
		}catch(std::bad_alloc e){
			delete[] ime_novi;
			throw e;
		}
		for(int i=0;i<n+1;i++)ime_novi[i]=nullptr;
		for(int i=0;i<n;i++){
			ime_novi[i]=ime[i];
		}
		ime_novi[n]=novi_niz;
		for(int i=0;i<n;i++)delete[] ime[i];
		ime=ime_novi;
	}
	if(ima_prazan==false)return n;
	else return n+1;
}
void IzlistajOptuzbu(char **imena, int n){
	for(int i=0;i<n;i++){
		if(imena[i]!=nullptr){
			for(int j=0;j<strlen(imena[i]);j++){
				std::cout<<imena[i][j];
			}
			std::cout<<std::endl;
		}
	}
}
int main ()
{
	std::cout<<"Koliko potencijalnih krivaca zelite unijeti? "<<std::endl;
	int q;
	std::cin>>q;
	std::cin.ignore(10000000,'\n');
	std::vector<std::string> imena;
	int &n(q);
	std::cout<<"Unesite potencijalne krivce: "<<std::endl;
	for(int i=0;i<n;i++){
		std::string neki;
		std::getline(std::cin,neki);
		imena.push_back(neki);
	}
	char ** nizPotencijalnih=nullptr;
	try{
	nizPotencijalnih=new char*[n];
	}catch(std::bad_alloc e){
		delete[] nizPotencijalnih;
		throw e;
	}
	for(int i=0;i<n;i++)nizPotencijalnih[i]=nullptr;
	n= PotencijalniKrivci( nizPotencijalnih, imena);
	int p;
	int opcija;
	std::cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: "<<std::endl;
	std::cin>>opcija;
	while(opcija!=0){
	if(opcija==1){
		std::cin.ignore(10000000,'\n');
		std::cout<<"Unesite ime novog optuzenog: \n";
		std::string nova;
		std::getline(std::cin,nova);
		imena.push_back(nova);
		try{
		n= PotencijalniKrivci( nizPotencijalnih, imena);
		}catch(std::bad_alloc e){
			for(int i=0;i<n;i++){
				delete[] nizPotencijalnih[i];
			}
			delete[] nizPotencijalnih;
		}
	}
	if(opcija==2){
		std::cin.ignore(10000000,'\n');
		std::cout<<"Unesite ime koje zelite izbaciti: \n";
		std::string novi;
		std::getline(std::cin,novi);
		try{
		n = OdbaciOptuzbu(nizPotencijalnih, n, novi);
		}catch(std::domain_error e){
			std::cout<<e.what();
			for(int i=0;i<n;i++){
				delete[] nizPotencijalnih[i];
			}
			delete[] nizPotencijalnih;
		}
	}
	if(opcija==0){
		return 0;
	}
	if(opcija==3){
		std::cin.ignore(10000000,'\n');
		IzlistajOptuzbu(nizPotencijalnih,n);
	}
	std::cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: "<<std::endl;
	std::cin>>opcija;
//std::cin.ignore(10000000,'\n');
	}
	for(int i=0;i<n;i++)delete[] nizPotencijalnih[i];
	delete[] nizPotencijalnih;
	return 0;
}