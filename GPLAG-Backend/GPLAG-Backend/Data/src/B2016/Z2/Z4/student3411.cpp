/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <stdexcept>

int PotencijalniKrivci(char **& prvi_parametar, std::vector<std::string> matrica){
	int br(0);
	char **p;
	char **a(nullptr);
	//alociranje niza pokazivaca odgovarajuce velicine
	try {
		a=new char *[matrica.size()];
		p=a;
		try{
			while(br<matrica.size()) {
				a[br]=new char[matrica[br].length()+1];
				br++;
			}
		}
		catch(...){
			for(int i=0; i<br; i++) delete[] a[i];
			delete[] a;
			throw;
		}
		
	}
	catch (...) {
		throw;
	}
	//kopiranje matrice 
	for(int i=0; i<matrica.size(); i++){
		strcpy(a[i], matrica[i].c_str());
	}
	prvi_parametar=p;
	return br;
	
}
int OdbaciOptuzbu(char **& a, int vel, std::string s){
	bool nalazise(false);
	int poz;
	//provjera da li je osoba bila optuzena
	for(int i=0; i<vel; i++){
		if(a[i]!=nullptr && strcmp(a[i],s.c_str())==0){
			nalazise=true;
			poz=i;
			break;
		}
	}
	//bacanje izuzetka ako nije bila
	if(nalazise==false) {
		std::string izuzetak="Osoba sa imenom "+s+" nije bila optuzena";
		throw std::domain_error(izuzetak);
	}
	//brisanje niza znakova koji sadrzi podatke o datoj osobi i postavljanje odgovarajuceg pokazivaca na nul-pokazivac
	delete[] a[poz];
	a[poz]=nullptr;
	int br(0);
	//provjera koliko se nul-pokazivaca nalazi u nizu pokazivaca
	for(int i=0; i<vel; i++){
		if(a[i]==nullptr) br++;
	}
	//dodjela ukoliko nije vise od 10 izbrisanih osoba
	if(br<=10) return vel;
	char **p;
	char **b(nullptr);
	//usteda memorije alociranjem novog niza pokazivaca
	try {
		b=(new char *[vel-br]);
		p=b;
		int brojac(0),i(0);
	}
	catch(std::bad_alloc){
		return vel;
	}
	int br2(0);
	//kopiranje korisnog niza pokazivaca
	for(int i=0; i<vel; i++){
		if(a[i]!=nullptr){
			b[br2]=a[i];
			br2++;
		}
	}
	//uklanjanje starog niza pokazivaca
	for(int i=0; i<vel; i++) delete[] a[i];
	delete[] a;
	a=p;
	return vel-br;
}
int DodajOptuzbu(char **& a, int vel, std::string s){
	char *niz(nullptr);
	char **p;
	try {
		//alociranja novog niza znakova i kopiranje imena
		niz=new char[s.length()+1];
		strcpy(niz,s.c_str());
		bool nalazise(false);
		//ispitivanje da li se u nizu nalazi neki null-pokazivac i kopiranje adrese novog niza znakova ako postoji
		for(int i=0; i<vel; i++){
			if(a[i]==nullptr) {
				a[i]=niz;
				nalazise=true;
				break;
			}
		}
		if(nalazise==true) return vel;
		char **b(nullptr);
		//alociranje novog niza pokazivaca i obavljanje onog sto je zadatkom specificirano
		try{
			b=new char*[vel+1];
			for(int i=0; i<vel+1; i++) b[i]=nullptr;
			p=b;
			try{
				for(int i=0; i<vel; i++) b[i]=new char[strlen(a[i])+1];
				for(int i=0; i<vel; i++)
				strcpy(b[i],a[i]);
				b[vel]=niz;
			}
			catch(std::bad_alloc){
				for(int i=0; i<vel; i++) delete[] b[i];
				throw;
			}
		}
		catch(std::bad_alloc){
			delete[] b;
				throw;
		}
		
	}
	catch (std::bad_alloc) {
		throw;
	}
	for(int i=0; i<vel; i++)
		delete[] a[i];
	delete[] a;
	a=p;
	return vel+1;
}
void IzlistajOptuzbu(char **a, int vel){
	for(int i=0; i<vel; i++){
		if(a[i]!=nullptr){
			std::cout<<a[i]<<std::endl;
		}
	}
}
int main ()
{	int n;
	std::cout<<"Koliko potencijalnih krivaca zelite unijeti? "<<std::endl;
	std::cin>>n;
	std::cout<<"Unesite potencijalne krivce: "<<std::endl;
	std::cin.ignore(10000,'\n');
	try{
	std::vector<std::string> matrica(n);
	for(int i=0; i<n; i++)
		std::getline(std::cin, matrica[i]);
	int x;
	char **a;
	int vel(0);
	try{
		vel=PotencijalniKrivci(a,matrica);
	do{
		std::cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: "<<std::endl;
		std::cin>>x;
		if(x==0) break;
		if(x==1){
			std::string s;
			std::cout<<"Unesite ime novog optuzenog: "<<std::endl;
			std::cin.ignore(10000,'\n');
			std::getline(std::cin, s);
			try{
				vel=DodajOptuzbu(a,vel,s);	
			}
			catch(...){
				std::cout<<"Dodavanje nije uspjelo"<<std::endl;
			}
		}
		if(x==2){
			std::string s;
			std::cout<<"Unesite ime koje zelite izbaciti: "<<std::endl;
			std::cin.ignore(10000,'\n');
			std::getline(std::cin, s);
			try{
				vel=OdbaciOptuzbu(a,vel,s);	
			}
			catch(std::domain_error e){
				std::cout<<e.what()<<std::endl;
			}
		}
		if(x==3){
			IzlistajOptuzbu(a,vel);
		}
	}while(x!=0);
	for(int i=0; i<vel; i++) delete[] a[i];
	delete[] a;
	}
	catch(...){
		throw;
	}
	}
	catch(...){
		std::cout<<"Greska";
	}
	return 0;
}