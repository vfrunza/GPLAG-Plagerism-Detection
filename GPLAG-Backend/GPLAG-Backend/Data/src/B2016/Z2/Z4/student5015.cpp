/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include <string>
#include <vector>
#include <new>
#include <cstring>
#include <stdexcept>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;

int PotencijalniKrivci(char **&pok, vector<string> imena)
{
	int brojac(0);
	try
	{
		pok=new char*[imena.size()];
		for (int i(0); i<imena.size(); i++)
			pok[i]=nullptr;
		for (int i(0); i<imena.size(); i++)
		{
			pok[i]=new char[imena[i].length()+1];
			std::strcpy(pok[i], imena[i].c_str());
			brojac++;
		}
		return brojac;
	}
	catch(std::bad_alloc)
	{
		for (int i(0); i<imena.size(); i++) 
			delete[] pok[i];
		delete[] pok;
		return brojac;
	}
}

int OdbaciOptuzbu(char **&pok, int vel, string nevin)
{
	bool isti=false;
	int brojac(0);
	for (int i(0); i<vel; i++)
	{
		if (pok[i]!=nullptr and std::strcmp(pok[i], nevin.c_str())==0) 
		{
			isti=true;
			delete[] pok[i];
			pok[i]=nullptr;
		}
	}
	if (!isti) throw std::domain_error("Osoba sa imenom " + nevin + " nije bila optuzena");
	for (int i(0); i<vel; i++)
		if (pok[i]==nullptr) brojac++;
	if (brojac>10)
	{
		vel-=brojac;
		char **novi=nullptr;
		try
		{
			novi=new char*[vel];
			for (int i=0; i<vel; i++)
				novi[i]=nullptr;
			for (int i=0; i<vel; i++)
			{
				if (pok[i]!=nullptr) 
				{
					char *p=pok[i];
					novi[i]=new char[strlen(p)+1];
					strcpy(novi[i], pok[i]);
				}
			}
			char **pomocni=pok;
			pok=novi;
			for (int i(0); i<vel+brojac; i++)
				delete[] pomocni[i];
			delete[] pomocni;
		}
		catch(std::bad_alloc)
		{
			for (int i=0; i<vel; i++)
				delete[] novi[i];
			delete[] novi;
			return vel+brojac;
		}
	} 
	return vel;
}

int DodajOptuzbu(char **&pok, int vel, string krivac)
{
	bool upisan(false);
	char **pomocni;
	char *niz=nullptr;
	char **novi=nullptr;
	try
	{
		niz=new char[krivac.length()+1];
		strcpy(niz, krivac.c_str());
		for (int i(0); i<vel; i++)
		{
			if (pok[i]==nullptr) 
			{
				pok[i]=niz;
				upisan=true;
				delete[] niz;
				break;
			}
		}
		if (!upisan) 
		{
			vel+=1;
			novi=new char*[vel];
			for (int i(0); i<vel; i++)
				novi[i]=nullptr;
			for (int i(0); i<vel-1; i++)
			{
				char *p=pok[i];
				novi[i]=new char[strlen(p)+1];
			}
			novi[vel-1]=new char[strlen(niz)+1];
			for (int i(0); i<vel-1; i++)
				strcpy(novi[i], pok[i]);
			strcpy(novi[vel-1], krivac.c_str());
			pomocni=pok;
			pok=novi;
			for (int i(0); i<vel-1; i++)
				delete[] pomocni[i];
			delete[] pomocni;
			delete[] niz;
		}
	}
	catch(std::bad_alloc)
	{
		delete[] novi;
		delete[] niz;
		throw;
	}
	return vel;
}

void IzlistajOptuzbu(char **pok, int vel)
{
	for (int i(0); i<vel; i++)
	{
		if (pok[i]!=nullptr) cout << pok[i] << endl;
	}
}

int main()
{
	int n;
	cout << "Koliko potencijalnih krivaca zelite unijeti? " << endl;
	cin >> n;
	cin.ignore(10000, '\n');
	vector<string> imena;
	string ime;
	char **pok=nullptr;
	cout << "Unesite potencijalne krivce: " << endl;
	while (imena.size()!=n)
	{
		std::getline(cin, ime);
		imena.push_back(ime);
	}
	int x;
	int vel=PotencijalniKrivci(pok, imena);
	do
	{
		cout << "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: " << endl;
		cin >> x;
		string s;
		switch(x)
		{
			case 0: for (int i=0; i<vel; i++)
						delete[] pok[i];
					delete[] pok;
					return 0;
			case 1: cin.ignore(10000, '\n');
					cout << "Unesite ime novog optuzenog: " << endl;
					std::getline(cin, s);
					vel=DodajOptuzbu(pok, vel, s);
					break;
			case 2: cin.ignore(10000, '\n');
					cout << "Unesite ime koje zelite izbaciti: " << endl;
					std::getline(cin, s);
					try
					{
						vel=OdbaciOptuzbu(pok, vel, s);
					}
					catch(std::domain_error izuzetak)
					{
						cout << izuzetak.what() << endl;
					}
					break;
			case 3: IzlistajOptuzbu(pok, vel);
					break;
		}
	} while(1);
}