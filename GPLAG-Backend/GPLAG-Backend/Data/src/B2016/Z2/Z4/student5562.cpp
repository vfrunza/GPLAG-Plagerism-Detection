/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <new>
#include <stdexcept>

int PotencijalniKrivci(char** &optuzeni, std::vector<std::string> primljena_imena)
{
	char **spisak_imena(nullptr); 
	try
	{
		int n(primljena_imena.size());
		spisak_imena = new char*[n];
		
		for (int i = 0; i < n; i++)
			spisak_imena[i] = nullptr;
		
		for (int i = 0; i < n; i++)
		{
			spisak_imena[i] = new char[primljena_imena[i].size() + 1];
			strcpy(spisak_imena[i], primljena_imena[i].c_str());
		}
		optuzeni = spisak_imena;
	}
	catch(std::bad_alloc)
	{
		if (spisak_imena)
			for (int i = 0; i < primljena_imena.size(); i++)
				delete[] spisak_imena[i];
		delete[] spisak_imena;
		throw;
	}
		
	return primljena_imena.size();
}

int OdbaciOptuzbu(char** &optuzeni, int vel, std::string nevin)
{
	for (int i = 0; i < vel; i++)
	{
		if (optuzeni[i] != nullptr && strcmp(optuzeni[i], nevin.c_str()) == 0)
		{
			delete[] optuzeni[i];
			optuzeni[i] = nullptr;
			break;
		}
		if (i == vel - 1)
			throw std::domain_error("Osoba sa imenom " + nevin + " nije bila optuzena");
	}
			
	int broj_praznih(0);
	for (int i = 0; i < vel; i++)
		if (optuzeni[i] == nullptr)
			broj_praznih++;
	
	char **nova_lista(nullptr);	
	if (broj_praznih > 10)
	{
		try
		{
			int br(0);
			nova_lista = new char*[vel - broj_praznih];
				
			for (int i = 0; i < vel; i++)
				if (optuzeni[i] != nullptr)
					nova_lista[br++] = optuzeni[i];
					
			delete[]optuzeni;
			optuzeni = nova_lista;
			vel -= broj_praznih;
		}
		catch(std::bad_alloc)
		{
			delete[] nova_lista;
		}
	}
	return vel;
}

int DodajOptuzbu(char** &optuzeni, int vel, std::string krivac)
{
	char*ime(nullptr);
	char** novi(nullptr);
	try 
	{
		ime = new char[krivac.size() + 1];
		strcpy(ime, krivac.c_str());
		
		for (int i = 0; i < vel; i++)
		{
			if (optuzeni[i] == nullptr)
			{
				optuzeni[i] = ime;
				break;
			}
			if (i == vel - 1)
			{
				novi = new char*[vel + 1];
					
				for (int j = 0; j < vel; j++)
				{
					novi[j] = optuzeni[j];
				}
				
				novi[vel] = ime;
				vel++;
				delete[] optuzeni;
				optuzeni = novi;
				break;
			}
		}
		
	}
	catch(std::bad_alloc)
	{
		delete[] ime;
		delete[] novi;
		throw;
	}
	
	return vel;
}

void IzlistajOptuzbu(char** optuzeni, int vel)
{
	for (int i = 0; i < vel; i++)
		if (optuzeni[i] != nullptr)
			std::cout << optuzeni[i] << "\n"; 
}

int main ()
{
	char **optuzeni(nullptr);
	int n;
	
	std::cout << "Koliko potencijalnih krivaca zelite unijeti? \n";
	std::cin >> n;
	try
	{
		std::cout << "Unesite potencijalne krivce: \n";
		std::vector<std::string> imena(n);
		for (int i = 0; i < n; i++)
		{
			std::cin >> imena[i];
		}

		n = PotencijalniKrivci(optuzeni, imena);
		
		int opcija;
		for (;;)
		{
			std::cout << "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: \n";
			std::cin >> opcija;
			
			std::string ime;
			if (opcija == 0) break;
			else if (opcija == 1)
			{
				std::cout << "Unesite ime novog optuzenog: \n";
				std::cin >> ime;
				n = DodajOptuzbu(optuzeni, n, ime);
			}
			else if (opcija == 2)
			{
				std::cout << "Unesite ime koje zelite izbaciti: \n";
				std::cin >> ime;
				n = OdbaciOptuzbu(optuzeni, n, ime);
			}
			else if (opcija == 3)
			{
				IzlistajOptuzbu(optuzeni, n);
			}
			
		}
	}
	catch (std::bad_alloc)
	{
		
	}
	catch (std::domain_error e)
	{
		std::cout << e.what(); 
	}
	
	if (optuzeni)
		for (int i = 0; i < n; i++)
			delete[] optuzeni[i];
	delete[] optuzeni;
	
	return 0;
}