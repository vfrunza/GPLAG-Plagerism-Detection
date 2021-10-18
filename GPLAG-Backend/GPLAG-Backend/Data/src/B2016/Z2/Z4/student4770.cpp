/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/

#include <iostream>
#include <stdexcept>
#include <vector>
#include <cstring>
#include <string>

typedef std::vector<std::string> vektorstringova;
void kopiraj(std::string p, char* q)
{
	for(int i = 0; i < p.length(); i++)
		*q++ = p[i];

	*q = '\0';
	
}
void KopirajUString (std::string &c, char* q)
{
	if(!q) return;
	int n = std::strlen(q), br(0);
	c.resize(n);
	while(*q != '\0')
		c[br++] = *q++;
}

int PotencijalniKrivci(char** &a, vektorstringova s)
{
	int brojac(0);
	char** pomocni = nullptr;
	try {
		pomocni = new char *[s.size()];
		for(int i = 0; i < s.size(); i++)
			pomocni[i] = nullptr;
		for(int i = 0; i < s.size(); i++)
		{
			pomocni[i] = new char [s[i].size() + 1];
			brojac++;
			kopiraj(s[i], pomocni[i]);
		}
		
	}
	catch(...) {
		for(int i = 0; i < s.size(); i++)
			delete [] pomocni[i];
		delete [] pomocni;
		throw std::bad_alloc();
	}
	a = pomocni;
	return brojac;
}
int ima(char** a, int vel, std::string s)
{
	std::string tmp;
	for(int i = 0; i < vel; i++)
	{
		KopirajUString(tmp, a[i]);
		if(tmp == s) return i+1;
	} return 0;
}
int PrebrojNulPokazivace(char** a, int vel)
{
	int suma(0);
	for(int i = 0; i < vel; i++)
		if(!a[i]) suma++;
	return suma;
}
int DodajOptuzbu(char** &a, int vel, std::string s)
{
	bool DesiloSe(false);
	char *niz = nullptr;
	try {
		niz = new char[s.size()+1];
		for(int i = 0; i < s.size(); i++)
			niz[i] = s[i];
		niz[s.size()] = '\0'; 
		for(int i = 0; i < vel; i++)
		{
			if(!a[i])
			{
				DesiloSe = true;
				a[i] = niz;
				break;
			}
		}
	} catch(...)
	{
		delete [] niz;
		throw std::bad_alloc();
	}
	try {
		if(!DesiloSe) 
		{
			char **novi = nullptr;
			novi = new char*[vel+1];
			for(int i = 0; i < vel; i++)
				novi[i] = a[i];
			novi[vel] = niz;
			delete [] a;
			a = novi;
			return vel + 1;
		}
	} catch(...)
	{
		delete [] niz;
		throw std::bad_alloc();
	} return vel;
}
int OdbaciOptuzbu (char** &a, int vel, std::string s)
{
	int x(ima(a, vel, s)), j(0);
	if(!x) throw std::domain_error("Osoba sa imenom "+ s +" nije bila optuzena");
	delete[] a[x-1];
	a[x-1] = nullptr;
	int n = PrebrojNulPokazivace(a, vel);
	if(n > 10)
	{
		try {
			char** drugi = new char*[vel - n];
			for(int i = 0; i < vel; i++)
				if(a[i]) drugi[j++] = a[i];
			delete [] a;
			a = drugi;
			return vel - n;
		}	catch(...) {
			;
		}
	} return vel;
}
void IzlistajOptuzbu (char** p, int vel)
{
	for(int i = 0; i < vel; i++)
		if(p[i]) std::cout<<p[i]<<std::endl;
}

int main ()
{
	std::cout<<"Koliko potencijalnih krivaca zelite unijeti? \n";
	int n;
	std::cin>>n;
	std::cin.ignore(10000, '\n');
	std::cout<<"Unesite potencijalne krivce: \n";
	vektorstringova v(n);
	char** anela;
	for(int i = 0; i < n; i++)
		std::getline(std::cin, v[i]);
	n = PotencijalniKrivci(anela, v);
	for(;;)
	{
		std::cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: \n";
		int opcija;
		std::cin>>opcija;
		std::cin.ignore(100000, '\n');
		if(!opcija) break;
		else if(opcija == 1) {
			std::cout<<"Unesite ime novog optuzenog: \n";
			std::string nekinovi;
			std::getline(std::cin, nekinovi);
			n = DodajOptuzbu(anela, n, nekinovi);
		}
		else if(opcija == 2) {
			std::cout<<"Unesite ime koje zelite izbaciti: \n";
			std::string nekinovi;
			std::getline(std::cin, nekinovi);
			try {
			n = OdbaciOptuzbu(anela, n, nekinovi); }
			catch(std::domain_error err) {
				std::cout<<err.what();
			}
		}
		else if(opcija == 3)
			IzlistajOptuzbu(anela, n);
	}
	for(int i = 0; i < n; i++)
		delete [] anela[i];
	delete [] anela;
	return 0;
}
