/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <cstring>
#include <new>

int PotencijalniKrivci(char**(&ref), std::vector<std::string> vektor){
	try{
		int brojac(0);
		char** a(new char* [vektor.size()]);
		for(int i=0; i<vektor.size(); i++) a[i]=nullptr;
		try{
			for(brojac=0; brojac<vektor.size(); brojac++) a[brojac]=new char[vektor[brojac].size()+1];
			for(int i=0; i<vektor.size(); i++) std::strcpy(a[i], vektor[i].c_str());
			ref=a;
			return brojac;
		}
		catch(std::bad_alloc){
			for(int i=0; i<vektor.size(); i++) delete[] a[i];
			delete[] a;
			throw;
		}
		return brojac;
	}
	catch(std::bad_alloc){
		throw;
	}
}

int OdbaciOptuzbu(char**(&niz), int vel, std::string s){
	int velicina(vel);
	bool istina(false);
	int broj(0);
	for(int i=0; i<vel; i++){
		if(std::strcmp(niz[i], s.c_str())==0){
			istina=true;
			delete[] niz[i];
			niz[i]=nullptr;
		}
	}
	for(int i=0; i<vel; i++){
		if(niz[i]==nullptr) broj++;
	}
	if(broj>10){
		 velicina=vel-broj;
		try{
			char** a(new char* [velicina]);
			for(int i=0; i<velicina; i++) a[i]=nullptr;
			try{
				int j(0);
				for(int i=0; i<vel; i++){
					if(niz[i]!=nullptr) std::strcpy(a[j++],niz[i]);
				}
				for(int i=0; i<vel; i++) delete[] niz[i];
				delete[] niz;
				niz=a;
				return velicina;
			}
			catch(std::bad_alloc){
				for(int i=0; i<velicina; i++) delete[] a[i];
				delete[] a;
				throw;
			}
			return velicina;
		}
		catch(std::bad_alloc){
			return velicina;
		}
	}
	if(!istina) throw std::domain_error ("Osoba sa imenom "+ s +" nije bila optuzena");
	return velicina;
}

int DodajOptuzbu(char**(&niz), int vel, std::string s){
	try{
		char* ime(new char[s.size()+1]);
		std::strcpy(ime,s.c_str());
		for(int i=0; i<vel; i++){
			if(niz[i]==nullptr) {
				niz[i]=ime;
				return vel;
			}
		}
		delete[] ime;
		try{
			char**a(new char*[vel+1]);
			for(int i=0; i<vel+1; i++) a[i]=nullptr;
			try{
				for(int i=0; i<vel+1; i++) {
					if(i==vel){ a[i]=new char[s.size()+1]; continue;}
					a[i]=new char[std::strlen(niz[i])+1];	
				}
				for(int i=0; i<vel+1; i++) {
					if(i==vel) { std::strcpy(a[i],s.c_str()); continue;}
					std::strcpy(a[i],niz[i]);
				}
				for(int i=0; i<vel; i++) delete[] niz[i];
				delete[] niz;
				niz=a;
				return vel+1;
			}
			catch(std::bad_alloc){
				for(int i=0; i<vel; i++) delete[] a[i];
				delete[] a;
				throw;
			}
		}
		catch(std::bad_alloc){
			throw;
		}
	}
	catch(std::bad_alloc){
		throw;
	}
	return vel;
}

void IzlistajOptuzbu(char** niz, int vel){
	for(int i=0; i<vel; i++){
		if(niz[i]==nullptr) continue;
		std::cout<<niz[i];
		std::cout<<std::endl;
	}
}
int main ()
{
	std::cout<<"Koliko potencijalnih krivaca zelite unijeti? "<<std::endl;
	int n;
	std::cin>>n;
	std::vector<std::string> lista(n);
	std::cout<<"Unesite potencijalne krivce: "<<std::endl;
	for(int i=0; i<n; i++) {
		std::cin>>std::ws;
		std::getline(std::cin,lista[i]);
	}
	char** niz;
	int velicina(PotencijalniKrivci(niz,lista));
	for(;;){
		std::cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: "<<std::endl;
		int x;
		std::cin>>x;
		std::cin.clear();
		std::cin.ignore(1000,'\n');
		if(x==0) break;
		if(x==1) {
			std::cout<<"Unesite ime novog optuzenog: "<<std::endl;
			std::string s;
			std::getline(std::cin, s);
			velicina=(DodajOptuzbu(niz,velicina,s));
			continue;
		}
		if(x==2) {
			try{
				std::cout<<"Unesite ime koje zelite izbaciti: "<<std::endl;
				std::string s;
				std::getline(std::cin, s);
				velicina=OdbaciOptuzbu(niz,velicina, s);
			}
			catch(std::domain_error izuzetak){
				std::cout<<izuzetak.what()<<std::endl;
			}
			continue;
		}
		if(x==3) {
			IzlistajOptuzbu(niz, velicina);
			continue;
		}
	}
	for(int i=0; i<velicina; i++) delete[] niz[i];
	delete[] niz;
	return 0;
	
}