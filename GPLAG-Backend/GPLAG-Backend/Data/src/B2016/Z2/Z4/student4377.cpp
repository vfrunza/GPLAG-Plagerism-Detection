#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <stdexcept>

int PotencijalniKrivci(char **&a, std::vector<std::string> string)
{
	int brojac(0);
	try
	{
		a = new char* [string.size()];
		for(int i=0; i<string.size(); i++)
		{
			a[i] = new char[string[i].size()+1];
			brojac++;
		}
		for(int i=0; i<string.size(); i++) strcpy(a[i], string[i].c_str());
	}
	catch(...)
	{
		for(int i=0; i<string.size(); i++) delete [] a[i];
		delete [] a;
		
	
		throw;
	}
	
	return brojac;
}

int OdbaciOptuzbu(char **&a, int vel, std::string nevin)
{
	bool logika (true);
	for(int i=0; i<vel; i++)
	{
		if(a[i] == nullptr) continue;
		if(!strcmp(nevin.c_str(), a[i]))
		{
			logika = false;
			delete [] a[i];
			a[i] = nullptr;
		}
	}
	if(logika) throw std::domain_error("Osoba sa imenom " + nevin + " nije bila optuzena");
	
	int brojac(0);
	for(int i=0; i<vel; i++)
	{	
		if(a[i] == nullptr) brojac++;
	}
	
	if(brojac > 10)
	{
		char **a2 = nullptr;
		try
		{
			a2 = new char* [vel-brojac];
			int index(0);
			for(int i=0; i<vel; i++)
			{	
				if(a[i] == nullptr) continue;
				a2[index] = a[i];
				index++;
			}
			delete []a;
			a = a2;
		}
		catch(...){	}
	}
	return vel;
}


int DodajOptuzbu(char **&a, int vel, std::string kriv)
{
	char *ime = nullptr;
	try
	{
		ime = new char[kriv.size()+1];
		strcpy(ime, kriv.c_str());
		
		bool stao(false);
		for(int i=0; i<vel; i++)
		{
			if(a[i] == nullptr)
			{
				a[i] = ime;
				stao = true;
			}
		}
		if(!stao)
		{
			vel++;
			char **a2 = new char*[vel];
			for(int i=0; i<vel-1; i++)
			{
				a2[i] = a[i];
			}
			a2[vel-1] = ime;
			delete [] a;
			a = a2;
		}
	}
	catch(...)
	{
		
		throw;
	}
	return vel;
}

void IzlistajOptuzbu(char **a, int vel)
{
	for(int i=0; i<vel; i++) 
 	{
 		if(a[i] == nullptr) continue;
 		std::cout << a[i];
 		std::cout << std::endl;
 	}
}


int  main()
{
	std::cout << "Koliko potencijalnih krivaca zelite unijeti? ";
	int n;
	std::cin >> n;
	std::cin.ignore(10000, '\n');
	std::vector<std::string> imena(n);
	
	std::cout << "\nUnesite potencijalne krivce: ";
	for(int i=0; i<n; i++)
	{
		std::getline(std::cin, imena[i]);
	}
	
	//char **a (nullptr);
	char **b (nullptr);
	
	int vel(0);
	vel = PotencijalniKrivci(b, imena);
	
	char **a (b);
		
	for(;;)
	{
		std::cout << "\nOdaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: ";
		int n;
		std::cin >> n;
		std::cin.ignore(10000, '\n');
		
		if(n==0)
		{
			break;
		}
		else if(n==1)	
		{
			std::cout << "\nUnesite ime novog optuzenog: ";
			std::string ime;
			std::getline(std::cin, ime);
			vel = DodajOptuzbu(a, vel, ime);
		}	
		else if(n==2) 
		{
			std::cout << "\nUnesite ime koje zelite izbaciti: ";
			std::string ime;
			std::getline(std::cin, ime);
			vel = OdbaciOptuzbu(a, vel, ime);
		}	
		else if(n==3)
		{
			std::cout << std::endl;
			IzlistajOptuzbu(a, vel);
		}
	}
	
	for(int i=0; i < vel; i++) delete [] a[i];
	delete [] a;
	
	return 0;
}


int main2 ()
{
	std::vector<std::string> st = {"benjo", "tarzan", "betmen", "supermen", "spajdermen", "benjo", "ranko"};
	char **a =nullptr;
	int vel = PotencijalniKrivci(a, st);
	
	
	std::cout << std::endl;
	
 	
 	std::string nevin = {"spajdermen"};
 	vel = OdbaciOptuzbu(a, vel, nevin);
 	
 	std::string kriv = {"hulk"};
 	vel = DodajOptuzbu(a, vel, kriv);
 	
 	kriv = {"nidal"};
 	vel = DodajOptuzbu(a, vel, kriv);
 	
	IzlistajOptuzbu(a, vel);
 	
	return 0;
}