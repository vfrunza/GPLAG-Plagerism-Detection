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

int PotencijalniKrivci(char **&s, std::vector<std::string> spisak)
{
	int n = spisak.size();
	char **a = new char*[n];
	for(int i=0; i<n; i++)
	{
		int duzina = spisak.at(i).length();
		a[i] = new char[duzina+1];
		char pomocni[1000];
		int j;
		for(j=0; j<duzina; j++)
		{
			pomocni[j] = spisak.at(i).at(j);
		}
		pomocni[j] = '\0';
		std::strcpy(a[i], pomocni);
	}
	s = a;
	return n;
}

int OdbaciOptuzbu(char **&a, int n, std::string osobaa)
{
	int ima = 0;
	int brojosoba = n;
	char osoba[1000];
	char **b = nullptr;;
	int i;
	for(i=0; i<osobaa.length(); i++)
	{
		osoba[i] = osobaa.at(i);
	}
	osoba[i] = '\0';
	for(i=0; i<n; i++)
	{
		if(std::strcmp(a[i],osoba) == 0)
		{
			ima = 1;
			delete[] a[i];
			a[i] =  nullptr;
		}
	}
	int brima = 0;
	int brnull = 0;
	for(i=0; i<n; i++)
	{
		if(a[i] == nullptr)
		{
			brnull++;
		}
		else brima++;
	}
	if(brnull > 10)
	{
		b = new char*[brima];
		int j=0;
		for(i=0; i<n; i++)
		{
			if(a[i] == nullptr)
				continue;
			b[j] = a[i];
			j++;
		}
		delete[] a;
		a = b;
		brojosoba = brima;
	}
	if(ima == 0)
	{
		std::string sss;
		sss = "Osoba sa imenom " + osobaa + " nije bila optuzena";
		throw std::domain_error(sss);
	}
	return brojosoba;
}

int DodajOptuzbu(char **&a, int n, std::string osobaa)
{
	char osoba[1000];
	char **novi = nullptr;
	int i;
	int brosoba = n;
	for(i=0; i<osobaa.length(); i++)
	{
		osoba[i] = osobaa.at(i);
	}
	osoba[i] = '\0';
	int ima = 0;
	for(i=0; i<n; i++)
	{
		if(a[i] == nullptr)
		{
			ima = 1;
			a[i] = new char[osobaa.length()+1];
			a[i] = osoba;
			break;
		}
	}
	if(ima == 0)
	{
		novi = new char*[n+1];
		for(i=0; i<n; i++)
		{
			novi[i] = a[i];
		}
		novi[i] = osoba;
		brosoba++;
	}
	a = novi;
	return brosoba;
}

void IzlistajOptuzbu(char **a, int n)
{
	for(int i=0; i<n; i++)
	{
		std::cout << a[i] << std::endl;
	}
}

int main ()
{
	std::cout << "Koliko potencijalnih krivaca zelite unijeti? ";
	int n;
	std::cin >> n;
	std::vector<std::string> v(n);
	std::cout << "Unesite potencijalne krivce: ";
	std::cin.ignore();
	for(int i=0; i<n; i++)
	{
		std::getline(std::cin, v.at(i));
	}
	char **a = nullptr;
    n = PotencijalniKrivci(a,v);
	for(;;)
	{
		std::cout << "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: ";
		int opcija;
		std::cin >> opcija;
		std::cin.ignore();
		if(opcija == 0) break;
		if(opcija == 3) IzlistajOptuzbu(a,n);
		if(opcija == 1)
		{
			std::cout << "Unesite ime novog optuzenog: ";
			std::string unos;
			std::getline(std::cin, unos);
			n = DodajOptuzbu(a,n,unos);
		}
		if(opcija == 2)
		{
			std::cout << "Unesite ime koje zelite izbaciti: ";
			std::string unos;
			std::getline(std::cin, unos);
			n = OdbaciOptuzbu(a,n,unos);
		}
	}
	return 0;
}