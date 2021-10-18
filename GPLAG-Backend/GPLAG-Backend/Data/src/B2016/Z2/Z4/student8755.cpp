/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <cstring>
#include <new>

int PotencijalniKrivci(char **&niz, std::vector<std::string> imena)
{
	int n(imena.size());	//broj potencijalnih prodavaca
	try
	{
		niz=new char*[n];
		for(int i=0; i<n; i++)	niz[i]=nullptr;
		try
		{
			for(int i=0; i<n; i++)
			{
				int l(int(imena[i].length()));	//duzina imena potencijalnog prodavaca + '\0' ~ posljednji znak
				niz[i]=new char[l+1];
				strcpy(niz[i],imena[i].c_str());
			}
			return n;
		}
		catch(std::bad_alloc)
		{
			for(int i=0; i<imena.size(); i++)	delete[] niz[i];
			delete[] niz;
			throw;
		}
	}
	catch(std::bad_alloc)
	{
		throw;
	}
}
int OdbaciOptuzbu(char **&niz, int n, std::string nije_kriv)
{
	int duz(n), br(0);
	bool NemaImena(true);
		for(int i=0; i<n; i++)
		{
			if(strcmp(niz[i], nije_kriv.c_str())==0)
			{
				NemaImena=false;
				delete[] niz[i];
				niz[i]=nullptr;
			}
		}
		if(NemaImena)	throw std::domain_error("Osoba sa imenom "+nije_kriv+" nije bila optuzena");
		
		for(int i=0; i<n; i++)	if(niz[i]==nullptr)	br++;
	char **novi_niz;
	try
	{
		if(br>=10)
		{
			duz=n-br;
			novi_niz=new char*[duz];
			
			for(int i=0; i<duz; i++)	novi_niz[i]=nullptr;
			
			for(int i=0, k=0; i<n; i++)
				if(niz[i]!=nullptr)	novi_niz[k++]=niz[i];
			delete[] niz;
				
			niz=novi_niz;
			return duz;
		}
		
		return n;
	}
	catch(std::bad_alloc)
	{
		delete[] novi_niz;
		return n;
	}
}
int DodajOptuzbu(char **&niz, int n, std::string ime)
{
		int duz=n+1;
		for(int i=0; i<n; i++)
		{
			if(niz[i]==nullptr)	
			{
				try
				{
					niz[i]=new char[int(ime.length())+1];
					strcpy(niz[i], ime.c_str());
					return n;
				}
				catch(std::bad_alloc)
				{
					delete[] niz[i];
					throw;
				}
			}
		}
	try
	{
		char **final(new char*[duz]);
		for(int i=0; i<duz; i++)	final[i]=nullptr;
		for(int i=0; i<n; i++)		final[i]=niz[i];
		try
		{
			final[n]=new char[int(ime.length())+1];
			strcpy(final[n], ime.c_str());
		}
		catch(std::bad_alloc)
		{
			delete[] final[n];
			delete[] final;
			throw;
		}
		delete[] niz;
		niz=final;
		return duz;
	}
	catch(std::bad_alloc)
	{
		throw;
	}
}
void IzlistajOptuzbu(char **niz, int n)
{
	for(int i=0; i<n; i++)
	{
		if(niz[i]!=nullptr)
		{
			std::cout<<niz[i];
			std::cout<<std::endl;
		}
	}
}
int main()
{
	char **niz;
	int n;
	std::cout<<"Koliko potencijalnih krivaca zelite unijeti?"<<std::endl;
	std::cin>>n;
	std::cin.ignore(10000,'\n');
	std::cin.clear();
	std::vector<std::string> imena;
	std::cout<<"Unesite potencijalne krivce: "<<std::endl;
	for(int i=0; i<n; i++)
	{
		std::string s;
		std::getline(std::cin,s);
		imena.push_back(s);
	}
	n=PotencijalniKrivci(niz,imena);
	for(;;)
	{
		int broj;
		std::cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: "<<std::endl;
		std::cin>>broj;
		std::cin.ignore(10000,'\n');
		std::cin.clear();
		if(broj==1)
		{
			std::string s;
			std::cout<<"Unesite ime novog optuzenog: "<<std::endl;
			std::getline(std::cin,s);
			n=DodajOptuzbu(niz, n, s);
		}
		else if(broj==2)
		{
			std::string s;
			std::cout<<"Unesite ime koje zelite izbaciti: "<<std::endl;
			std::cin>>s;
			try
			{
				n=OdbaciOptuzbu(niz, n, s);
			}
			catch(std::domain_error izuzetak)
			{
				izuzetak.what();
			}
		}
		else if(broj==3)	IzlistajOptuzbu(niz, n);
		else if(broj==0)	break;
	}
	for(int i=0; i<n; i++)
		delete[] niz[i];
	delete[] niz;
}