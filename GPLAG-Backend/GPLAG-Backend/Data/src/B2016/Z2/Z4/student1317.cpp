/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>
#include<algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::getline;

// Funkcija PotencijalniKrivci dinamicki alocira niz pokazivaca na dinamicki
// alocirane nizove znakova u koje ce se smjestiti imena proslijedjenja funkciji
int PotencijalniKrivci(char **&pok, vector<string> ime)
{
	try
	{
		char **p(new char*[ime.size()]);
		for(int i=0; i<ime.size(); i++)
			p[i]=nullptr;
		try
		{
			for(int i=0; i<ime.size(); i++)
				p[i]=new char[ime[i].length()+1];
			
			for(int i=0; i<ime.size(); i++)
			{
				char *pom_pok(std::copy(ime[i].begin(), ime[i].end(), p[i]));
				*pom_pok='\0';
			}
				
			pok=p;
		}	
		catch(...)
		{
			for(int i=0; i<ime.size(); i++)
				delete[] p[i];
			delete[] p;
			throw;
		}
	}
	catch(...)
	{
		throw;
	}
	
	return ime.size();	
}

// Funkcija OdbaciOptuzbu oslobadja osobu optuzbe tj.
// brise osobu iz spiska potencijalnih krivaca
int OdbaciOptuzbu(char **&pok, int vel, string ime)
{
	bool optuzen(false);
	for(int i=0; i<vel; i++)
	{
		if(std::equal(ime.begin(), ime.end(), pok[i])) 
		{
			delete[] pok[i];
			pok[i]=nullptr;
			optuzen=true;
		}
	}
	if(!optuzen)
	{
		string s;
		s="Osoba sa imenom " + ime + " nije bila optuzena";
		throw std::domain_error(s);
	}
	
	int brojac(0);
	for(int i=0; i<vel; i++)
		if(pok[i]==nullptr) brojac++;
		
	if(brojac<=10) return vel;
	
	try
	{
		char **p(new char*[vel-brojac]);
		
		int pom_brojac(0);
		for(int i=0; i<vel; i++)
		{
			if(pok[i]==nullptr) continue;
			else 
			{
				p[pom_brojac]=pok[i];
				pom_brojac++;
			}
		}
		
		pok=p;
	}
	catch(...)
	{
		return vel;
	}
	
	return vel-brojac;
}

// Funkcija DodajOptuzbu vrsi dodavanje novog imena
// u niz potencijalnih krivaca
int DodajOptuzbu(char **&pok, int vel, string ime)
{
	try
	{
		char *p(new char[ime.length()+1]);
		char *pom_pok(std::copy(ime.begin(), ime.end(), p));
		*pom_pok='\0';
		bool prazan(false);
		for(int i=0; i<vel; i++)
		{
			if(pok[i]==nullptr) 
			{
				pok[i]=p;
				prazan=true;
			}
		}
		if(!prazan)
		{
			try
			{
				char **q(new char*[vel+1]);
					
				for(int i=0; i<vel; i++)
					q[i]=pok[i];
					
				q[vel]=p;
			
				delete[] pok;
				
				vel++;
				pok=q;
			}
			catch(...)
			{
				throw;
			}
		}
	}
	catch(...)
	{
		throw;
	}
	return vel;
}

// Funkcija IzlistajOptuzbu vrsi ispis svih registriranih imena
void IzlistajOptuzbu(char **pok, int vel)
{
	for(int i=0; i<vel; i++)
	{
		if(pok[i]==nullptr) continue;
		cout << pok[i] << endl;
	}
	return;
}

int main ()
{
	vector<string> krivci;
	char** pok(nullptr);
	int vel;
	cout << "Koliko potencijalnih krivaca zelite unijeti? " << endl;
	cin >> vel;
	cin.clear();
	cin.ignore(1000, '\n');
	cout << "Unesite potencijalne krivce: " << endl;
	for(int i=0; i<vel; i++)
	{
		string s;
		getline(cin, s);
		krivci.push_back(s);
	}
	vel=PotencijalniKrivci(pok, krivci);
	
	int opcija;
	do
	{
		cout << "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: " << endl;
		cin >> opcija;
		cin.clear();
		cin.ignore(1000, '\n');
		switch(opcija)
		{
			case 1: 
			{
				string ime;
				cout << "Unesite ime novog optuzenog: " << endl;
				getline(cin, ime);
				vel=DodajOptuzbu(pok, vel, ime);
				break;
			}
			case 2: 
			{
				string ime;
				cout << "Unesite ime koje zelite izbaciti: " << endl;
				getline(cin, ime);
				vel=OdbaciOptuzbu(pok, vel, ime);
				break;
			}
			case 3: 
			{
				IzlistajOptuzbu(pok, vel); 
				break;
			}
			case 0: 
			{
				for(int i=0; i<vel; i++) delete[] pok[i];
				delete[] pok;
				break;
			}
		}
	}while(opcija!=0);
	
	return 0;
}
