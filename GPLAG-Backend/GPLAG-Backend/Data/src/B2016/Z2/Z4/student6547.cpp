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

int PotencijalniKrivci(char **&p, std::vector<std::string> imena) {
	char **matrica(new char*[imena.size()]);
	p=nullptr;
	for(int i=0; i<imena.size(); i++) matrica[i]=nullptr;
	try{
		for(int i=0; i<imena.size(); i++) matrica[i]=new char[imena[i].size()+1];
	}
	catch(...) {
		if(!matrica) return 0;
		for(int i=0; i<imena.size();i++) delete [] matrica[i];
		delete [] matrica;
		throw;
	}
	try {
	p=matrica;
	for(int i=0; i<imena.size(); i++) {
		for(int j=0; j<=imena[i].size(); j++) {
			if(j==imena[i].size()) p[i][j]='\0';
			else p[i][j]=imena[i][j];
		}
	}
	}
	catch(std::bad_alloc) {
		std::cout<<"Neuspjela alokacija"<<std::endl;
	}
	
	return imena.size();
}

int OdbaciOptuzbu(char **&p, int vel, std::string s) {
	int brojac(0);
	int brojac2(vel);
	int provjer(0);
	for(int i=0; i<vel;i++) {
		if(p[i]==s) provjer=1;
	}
	if(provjer==0) throw std::domain_error ("Osoba sa imenom " + s + " nije bila optuzena");
	for(int i=0; i<vel; i++) {
		if(p[i]==s) {
			delete [] p[i];
			p[i]=nullptr;
			brojac++;
		}
	}
	if(brojac>10) {
		char**novamat(new char*[vel-brojac]);
		for(int i=0; i<(vel-brojac); i++) novamat[i]=nullptr;
	try{
		
		int k(0);
		for(int i=0; i<(vel-brojac); i++) {
			if(p[i]!=nullptr) {
				novamat[k]=p[i];
				k++;
		}
	}
	
	return vel-brojac;
	}
	
	catch(...) {
		if(!novamat) return 0;
		for(int i=0; i<(vel-brojac);i++) delete [] novamat[i];
		delete [] novamat;
		throw;
	}
	
	
	}
	return brojac2;
}

int DodajOptuzbu(char **&p, int vel, std::string s) {
	char *niz(new char[s.length()+1]);
	for(int i=0; i<s.length();i++) niz[i]=s[i];
	niz[s.length()]='\0';
	int brojac(0);
	for(int i=0; i<vel; i++) {
		if(p[i]==nullptr) {
		p[i]=niz;
		brojac++;}
	}
	if(brojac==0) {
		try{
		
		char**matrica(new char*[vel+1]);
		for(int i=0; i<=vel; i++) matrica[i]=nullptr;
		
		try{
		
		for(int i=0; i<vel; i++) matrica[i]=p[i];
		matrica[vel]=niz;
		delete[] p;
		p=matrica;
		
	    return vel+1;
	}
	catch(...) {
		if(!matrica) return 0;
		for(int i=0; i<=vel; i++) delete [] matrica[i];
		delete [] matrica;
		throw;
	}
	
	}
	catch(...) {
		std::cout<<"Nedovoljno memorije.";
	}
	}
	return vel;
}

void IzlistajOptuzbu(char **p, int vel) {
	for(int i=0; i<vel; i++) {
		if(p[i]!=nullptr) std::cout<<p[i]<<std::endl;
}
}


int main ()
{
	try{
	char**p;
	int n;
	std::string s;
	std::vector<std::string> imena;
	std::cout<<"Koliko potencijalnih krivaca zelite unijeti? "<<std::endl;
	std::cin>>n;
	std::cin.clear();
	std::cin.ignore(10000, '\n');
	std::cout<<"Unesite potencijalne krivce: " << std::endl;
	for(int i=0; i<n; i++) {
		std::getline(std::cin, s);
		imena.push_back(s);
	}
	int vel=PotencijalniKrivci(p,imena);
	for(;;) {
	int n1;
	int odbacen(0);
	std::cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: "<<std::endl;
	std::cin>>n1;
	std::cin.clear();
	std::cin.ignore(10000, '\n');
	if(n1==0) break;
	else if(n1==1) {
		std::cout<<"Unesite ime novog optuzenog: " << std::endl;
		std::string s1;
		std::getline(std::cin, s1);
		vel=DodajOptuzbu(p,vel,s1);
	}
	
	else if(n1==2) {
		std::cout<<"Unesite ime koje zelite izbaciti: " << std::endl;
		std::string s2;
		std::getline(std::cin, s2);
		vel=OdbaciOptuzbu(p,vel,s2);
		odbacen++;
			
	}
	
	else if(n1==3) {
	 if(odbacen==0)IzlistajOptuzbu(p,vel);
	 else IzlistajOptuzbu(p,vel+1);
	}
	}
	for(int i=0; i<vel; i++) {
		delete[] p[i];
	}
	delete[] p;
	}
	catch(std::domain_error f) {
		std::cout<<f.what();
	}

	return 0;
}