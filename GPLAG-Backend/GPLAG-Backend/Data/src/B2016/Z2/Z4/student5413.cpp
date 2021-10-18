/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include <cstring>
#include <vector>
#include <stdexcept>
#include <new>

int PotencijalniKrivci(char** &p, std::vector<std::string> imena)
{
	p = nullptr;
	try
	{
		p = new char*[imena.size()];
		for(int i(0); i < imena.size(); i++) p[i] = nullptr;
		try
		{
			for(int i(0); i < imena.size(); i++)
			{
				p[i] = new char[imena[i].length() + 1];
				strcpy(p[i], imena[i].c_str());
			}
			return imena.size();
		}
		catch(...)
		{
			delete[] p;
			throw;
		}
	}
	catch(...)
	{
		throw std::bad_alloc();
	}
}

int OdbaciOptuzbu(char** &p, int vel, std::string ime)
{
	int x(0), nul(0), vr(0);
	bool nadjen(false);
	for(int i(0); i < vel; i++)
	{
		int Isti;
		if(p[i] != nullptr)
		{
			Isti = strcmp(p[i], ime.c_str());
			vr++;
			x++;
		}
		else 
		{
			Isti = 2;
			nul++;
			x++;
		}
		if(Isti == 0)
		{
			delete[] p[i];
			p[i] = nullptr;
			vr--;
			nul++;
			nadjen = true;
		}
	}
	if(x == vel && nadjen == false) throw std::domain_error("Osoba sa imenom " + ime + " nije bila optuzena");
	if(nul >= 10)
	{
		char **q = new char*[vr];
		int j(0);
		for(int i(0); i < vel; i++)
		{
			if(p[i] != nullptr)
			{
				q[i] = p[j];
				j++;
			}
			delete[] p[i];
		}
		p = q;
		return vr;
	}
	return vel;
}

int DodajOptuzbu(char** &p, int vel, std::string ime)
{
	for(int i(0); i < vel; i++)
	{
		if(p[i] == nullptr)
		{
			try
			{
				p[i] = new char[ime.length() + 1];	
				strcpy(p[i], ime.c_str());
				return vel;
			}
			catch(...)
			{
				throw std::domain_error("");
			}
		}
	}
	
	char** x(nullptr);
	try
	{
		x = new char*[vel + 1];
		for(int i(0); i < vel; i++) x[i] = p[i];
		try
		{
			x[vel] = new char[ime.length() + 1];	
			strcpy(x[vel], ime.c_str());
			
			for(int i(0); i < vel; i++) p[i] = nullptr;
			p = x;
			return vel + 1;
		}
		catch(std::bad_alloc)
		{
			delete[] x;
			throw;
		}
	}
	catch(std::bad_alloc)
	{
		throw std::bad_alloc();
	}
}

void IzlistajOptuzbu(char **p, int vel)
{
	for(int i(0); i < vel; i++)
	{
		if(p[i] != nullptr)
		  std::cout << p[i] << std::endl;
	}
}

int main ()
{
	int n;
	std::cout << "Koliko potencijalnih krivaca zelite unijeti?" << std::endl;
	std::cin >> n;
	
	std::vector<std::string> imena(n);
	std::cout << "Unesite potencijalne krivce: ";
	for(auto &ime : imena) std::cin >> ime;
	std::cout << std::endl;
	
	char **nizp(nullptr);
	int vel;
	try
	{
		vel = PotencijalniKrivci(nizp, imena);
	}
	catch(...)
	{
		return 0;
	}
	
	while(n != 0)
	{
		std::cout << "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: ";
		std::cin >> n;
		std::cin.ignore(10000, '\n');
		if(n == 1)
		{
			std::string ime;
			std::cout << std::endl << "Unesite ime novog optuzenog: ";
			std::getline(std::cin, ime);
			try
			{
				vel = DodajOptuzbu(nizp, vel, ime);
			}
			catch(...)
			{
				
			}
			std::cout << std::endl;
		}
		else if(n == 2)
		{
			std::string ime;
			std::cout << std::endl << "Unesite ime koje zelite izbaciti: ";
			std::getline(std::cin, ime);
			try
			{
				vel = OdbaciOptuzbu(nizp, vel, ime);
			}
			catch(std::domain_error e)
			{
				std::cout << e.what() << std::endl;
			}
			
		}
		else if(n == 3)
		{
			IzlistajOptuzbu(nizp, vel);
		}
	}
	for(int i(0); i < vel; i++) delete[] nizp[i];
	delete[] nizp;
	return 0;
}