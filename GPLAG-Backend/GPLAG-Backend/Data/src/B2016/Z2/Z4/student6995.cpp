#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stdexcept>
int PotencijalniKrivci(char **&niz,std::vector<std::string> krivci){
	
	try{
		niz = new char*[krivci.size()];
		try{
			for(int i(0);i < krivci.size();i++) niz[i] = nullptr;
			for(int i(0);i < krivci.size();i++)niz[i] = new char[krivci[i].size()+1];
			for(int i(0);i < krivci.size();i++) strcpy(niz[i],krivci[i].c_str());
		}catch(std::bad_alloc){
			for(int i(0);i < krivci.size();i++) delete[] niz[i];
			delete[] niz;
			throw;
		}
	}catch(std::bad_alloc){
		throw;	
	}
	return krivci.size();
}
int OdbaciOptuzbu(char **&niz,int vel,std::string krivac){
bool greska(true);
for(int i(0);i < vel;i++){
	if(niz[i] && !strcmp(niz[i],krivac.c_str())){
		greska = false;
		*niz[i]=0;
		delete[] niz[i];
		niz[i]=nullptr;
		break;
	}
}
if(greska)throw std::domain_error("Osoba sa imenom "+krivac+" nije bila optuzena");
int brojac(0);
for(int i(0);i < vel;i++){
	if(!niz[i])brojac++;
}
if(brojac > 10){
	if(vel-brojac){
	try{
		char **tmp(niz);
		niz = new char*[vel-brojac];
			int j(0);
			for(int i(0);i < vel - brojac;i++){
				if(tmp[j]){
					niz[i]=tmp[i];
				}else i--;
				j++;
			}
			delete[] tmp;
			return vel-brojac;
	}catch(std::bad_alloc){
		return vel;
	}
}else{
	delete[] niz;
	niz = nullptr;
}
}
return vel;
}
int DodajOptuzbu(char **&niz,int vel,std::string krivac){
	char *rijec=nullptr;
	try{
		rijec = new char[krivac.size()+1];
		strcpy(rijec,krivac.c_str());
	}catch(std::bad_alloc){
		throw;		
	}
	
	for(int i(0);i < vel;i++){
		if(!niz[i]){
			niz[i]=rijec;
			return vel;
		}
	}
	
	try{
		char **tmp(niz);
		niz = new char*[vel+1];
	
			for(int i(0);i < vel;i++)niz[i]=tmp[i];
			
			niz[vel]=rijec;
			
			delete[] tmp;
			
			return vel+1;
	}catch(std::bad_alloc){
		delete[] rijec;
		throw;
	}
}
void IzlistajOptuzbu(char **niz,int vel){
	for(int i(0);i < vel;i++){
		if(niz[i]) std::cout << niz[i] << std::endl;
	}
}
int main ()
{
	int n;
	char ** niz(nullptr);
	std::vector<std::string> Krivci;
	std::string s;
	std::cout << "Koliko potencijalnih krivaca zelite unijeti?\n";
	std::cin >> n;
	std::cout << "Unesite potencijalne krivce: \n";
	for(int i(0);i < n;i++)
		std::cin >> s,Krivci.push_back(s);
		
	int vel(PotencijalniKrivci(niz,Krivci));
	try{	for(;;){
		std::cout << "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: ";
		std::cin >> n;
		if(n == 1){
			std::cout << "\nUnesite ime novog optuzenog: \n";
			std::cin >> s;
			vel = DodajOptuzbu(niz,vel,s);
		}else if(n == 2){
			std::cout << "\nUnesite ime koje zelite izbaciti: \n";
			std::cin >> s;
			vel = OdbaciOptuzbu(niz,vel,s);
		}else if(n == 3){
			std::cout << "\n";
			IzlistajOptuzbu(niz,vel);
		}else if(!n){
			for(int i(0);i < vel;i++)delete[] niz[i];
			delete[] niz;
			break;
		}
	}
	}catch(std::domain_error izuzetak){
		std::cout << "Izuzetak: " << izuzetak.what(); 
		for(int i(0);i < vel;i++)delete[] niz[i];
			delete[] niz;
	}catch(std::bad_alloc){
			std::cout << "Izuzetak: Neuspjela alokacija";
		for(int i(0);i < vel;i++)delete[] niz[i];
			delete[] niz;
	}
	return 0;
}