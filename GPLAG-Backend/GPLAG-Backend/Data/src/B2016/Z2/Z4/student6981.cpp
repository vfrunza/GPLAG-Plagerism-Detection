/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include <vector>
#include <string>
#include <new>
#include <cstring>
#include <stdexcept>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;


int PotencijalniKrivci(char ** &a, vector<string> potencijalni_prodavaci)
{
	char ** b(new char * [potencijalni_prodavaci.size()]);
	int brojac(0);
	for(int i=0; i<potencijalni_prodavaci.size(); i++)
		b[i]=nullptr;
	try
	{
		for(int i=0; i<potencijalni_prodavaci.size(); i++)
		{
			b[i]=new char [potencijalni_prodavaci[i].size()+1];
			brojac++;
		}
	}
	catch(std::bad_alloc)
	{
		for(int i=0; i<potencijalni_prodavaci.size(); i++)
			delete [] b[i];
		delete [] b;
		throw;
	}
	for(int i=0; i<potencijalni_prodavaci.size(); i++)
		for(int j=0; j<potencijalni_prodavaci[i].size(); j++)
			strcpy(b[i], potencijalni_prodavaci[i].c_str());
			
	a=b;
	
	return brojac;
}

int OdbaciOptuzbu(char ** &optuzeni, int broj_optuzenih, string ime)
{
	bool postoji(false);
	for(int i=0; i<broj_optuzenih; i++)
	{
		if(strcmp(optuzeni[i], ime.c_str())==0)
		{
			delete [] optuzeni[i];
			optuzeni[i]=nullptr;
			postoji=true;
		}
	}
	if(!postoji)throw std::domain_error("Osoba sa imenom "+ime+" nije bila optuzena");
	
	int br_nul_pok(0);
	for(int i=0; i<broj_optuzenih; i++)
		if(optuzeni[i]==nullptr)br_nul_pok++;
		
	if(br_nul_pok>10)
	{
		try
		{
			char **privremeni(new char *[broj_optuzenih-br_nul_pok]);
			int j=0;
			for(int i=0; i<broj_optuzenih; i++)
				if(optuzeni[i]!=nullptr)
				{
					privremeni[j]=optuzeni[i];
					j++;
				}
			for(int i=0; i<broj_optuzenih; i++)
				delete [] optuzeni[i];
			delete [] optuzeni;
			optuzeni=privremeni;
			broj_optuzenih-=br_nul_pok;
		}
		catch(...){}
	}
	
	return broj_optuzenih;
}

int DodajOptuzbu(char ** &optuzeni, int broj_optuzenih, string ime)
{
	char *pomocni(new char [ime.size()+1]);
	strcpy(pomocni, ime.c_str());
	bool ima_nul_pok(false);
	for(int i=0; i<broj_optuzenih; i++)
		if(optuzeni[i]==nullptr)
		{
			optuzeni[i]=pomocni;
			ima_nul_pok=true;
			break;
		}
		
	if(!ima_nul_pok)
	{
		char **privremeni(new char *[broj_optuzenih+1]);
		for(int i=0; i<broj_optuzenih; i++)
			privremeni[i]=optuzeni[i];
		privremeni[broj_optuzenih]=pomocni;
		for(int i=0; i<broj_optuzenih; i++)
			delete [] optuzeni[i];
		delete [] optuzeni;
		optuzeni=privremeni;
		broj_optuzenih-=1;
	}
	return broj_optuzenih;
}

void IzlistajOptuzbu(char **optuzeni, int broj_optuzenih)
{
	for(int i=0; i<broj_optuzenih; i++)
		if(optuzeni[i]!=nullptr)
			cout<<optuzeni[i]<<endl;
}

int main ()
{
	int broj_optuzenih;
	cout<<"Koliko potencijalnih krivaca zelite unijeti? ";
	cin>>broj_optuzenih;
	vector<string> imena(broj_optuzenih);
	cout<<"Unesite potencijalne krivce: ";
	cin.ignore(10000, '\n');
	for(int i=0; i<imena.size(); i++)
	{
		std::getline(cin, imena[i]);
		cin.ignore(10000, '\n');
	}
	char ** optuzeni;
	PotencijalniKrivci(optuzeni, imena);
	int n;
	for(;;)
	{
		cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog, 3 za izlistavanje optuzenih, 0 za kraj: ";
		cin>>n;
		cin.ignore(10000, '\n');
		if(n==0)break;
		else if(n==1)
		{
			string ime;
			cout<<"Unesite ime novog optuzenog";
			std::getline(cin, ime);
			DodajOptuzbu(optuzeni, broj_optuzenih, ime);
			broj_optuzenih++;
		}
		else if(n==2)
		{
			string ime;
			cout<<"Unesite ime koje zelite izbaciti: ";
			std::getline(cin, ime);
			OdbaciOptuzbu(optuzeni, broj_optuzenih, ime);
			broj_optuzenih--;
		}
		else if(n==3)
		{
			IzlistajOptuzbu(optuzeni, broj_optuzenih);
		}
	}
	return 0;
}