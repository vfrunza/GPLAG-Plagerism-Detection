#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

int PotencijalniKrivci(char **&p, std::vector<std::string> v)
{
	try
	{
		p = new char*[v.size()];
		for(int i(0); i < v.size(); i++)
			p[i] = nullptr;
		try
		{
			for(int i(0); i < v.size(); i++)
				p[i] = new char[v[i].size() + 1];
				
			for(int i(0); i < v.size(); i++)
			{
				int j = 0;
				for(; j < v[i].size(); j++)
					p[i][j] = v[i][j];
				p[i][j] = '\0';	
			}
			return v.size();
		}
		catch(std::bad_alloc)
		{
			for(int i(0); i < v.size(); i++)
				delete[] p[i];
			delete [] p;
			throw;
		}
	}
	catch(std::bad_alloc)
	{
		p = nullptr;
		throw;
	}
}
bool ProvjeriIsteRijeci(char *p, std::string ime)
{
	int brojac = 0;
	while(p[brojac] != '\0')
		brojac++;
	if(brojac != ime.size())
		return false;
	for(int i(0); i < brojac; i++)
	{
		if(p[i] == ime[i])
			continue;
		else
			return false;
	}
	return true;
}
int OdbaciOptuzbu(char **&p, int vel, std::string prodavaci)
{
	bool izmjena = false;
	for(int i(0); i < vel; i++)
	{
		if(prodavaci[0] == p[i][0])
		{
			izmjena = ProvjeriIsteRijeci(p[i], prodavaci);
			if(izmjena == true)
			{
				delete[] p[i];
				p[i] = nullptr;
				break;
			}
		}
		if(izmjena == true)
			break;
	}
	if(izmjena == false)
	{
		std::string s = "Osoba sa imenom " + prodavaci +" nije bila optuzena";
		throw std::domain_error(s);
	}
	int brojac = 0;
	for(int i(0); i < vel; i++)
		if(p[i] == nullptr)
			brojac++;
	if(brojac > 10)
	{
		std::vector<std::string> imena;
		for(int i(0); i < vel; i++)
		{
			if(p[i] != nullptr)
			{
				std::string temp;
				int slova = 0;
				while(p[i][slova] != '\0')
				{
					temp += p[i][slova];
					slova++;
				}
				imena.push_back(temp);
			}
		}
		try
		{
			char ** temp;
			int nova_vel = PotencijalniKrivci(temp, imena);
			for(int i(0); i < vel; i++)
				delete [] p[i];
			delete [] p;
			p = temp;
			return nova_vel;
		}
		catch(std::bad_alloc)
		{
			return vel;
		}
	}
	return vel;
}
int DodajOptuzbu(char **&p, int vel, std::string prodavaci)
{
	char *novi;
	try
	{
		novi = new char[prodavaci.size() + 1];
	}
	catch(std::bad_alloc)
	{
		throw;
	}
	int nul = 0;
	for( ; nul < prodavaci.size(); nul++)
		novi[nul] = prodavaci[nul];
	novi[nul] = '\0';
	
	for(int i(0); i < vel; i++)
		if(p[i] == nullptr)
		{
			p[i] = novi;
			return vel;
		}
	delete [] novi;
	std::vector<std::string> imena;
	for(int i(0); i < vel; i++)
	{
		std::string temp;
		int slova = 0;
		while(p[i][slova] != '\0')
		{
			temp += p[i][slova];
			slova++;
		}
		imena.push_back(temp);
	}
	imena.push_back(prodavaci);
	try
		{
			char ** temp;
			int nova_vel = PotencijalniKrivci(temp, imena);
			for(int i(0); i < vel; i++)
				delete[] p[i];
			delete [] p;
			p = temp;
			return nova_vel;
		}
		catch(std::bad_alloc)
		{
			throw;
		}
}
void IzlistajOptuzbu(char **p, int vel)
{
	for(int i(0); i < vel; i++)
	{
		if(p[i] == nullptr)
			continue;
		int broj = 0;
		while(p[i][broj] != '\0')
		{
			std::cout << p[i][broj];
			broj++;
		}
		std::cout << std::endl;
	}
}
int main ()
{
	try
	{
		std::cout << "Koliko potencijalnih krivaca zelite unijeti? \n";
		int br;
		std::cin >> br;
		std::cout << "Unesite potencijalne krivce: \n";
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::vector<std::string> krivci;
		for(int i(0); i < br; i++)
		{
			std::string s;
			std::getline(std::cin, s);
			krivci.push_back(s);
		}
		char **ListaOptuzenih = nullptr;
		int vel = PotencijalniKrivci(ListaOptuzenih, krivci);
		while(1)
		{
			std::cout << "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: \n";
			int n;
			std::cin >> n;
			if(n == 0)
				break;
			if(n == 1)
			{
				try
				{
					std::string temp;
					std::cout << "Unesite ime novog optuzenog: ";
					std::cin.clear();
					std::cin.ignore(10000, '\n');
					std::getline(std::cin, temp);
					vel = DodajOptuzbu(ListaOptuzenih, vel, temp);
				}
				catch(std::bad_alloc)
				{
					
				}
			}
			if(n == 2)
			{
				try
				{
					std::string temp2;
					std::cout << "Unesite ime koje zelite izbaciti: ";
					std::cin.clear();
					std::cin.ignore(10000, '\n');
					std::getline(std::cin, temp2);
					vel = OdbaciOptuzbu(ListaOptuzenih, vel, temp2);
				}
				catch(std::domain_error e)
				{
					std::cout << e.what();
				}
			}
			if(n == 3)
			{
				IzlistajOptuzbu(ListaOptuzenih, vel);
			}
		}
		if( ListaOptuzenih != nullptr)
		{
			for(int i = 0; i < vel; i++)
				delete [] ListaOptuzenih[i];
			delete [] ListaOptuzenih;
		}
			
		return 0;
	}
	catch(std::bad_alloc)
	{
		std::cout << "Nema dovoljno memorije!";
	}
}