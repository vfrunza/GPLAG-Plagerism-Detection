/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <cstring>

int PotencijalniKrivci(char **&p, std::vector<std::string> v)
{
	int n=v.size();
	int m(0);
	for(int i(0); i<v.size(); i++)
	{
		m+=v[i].size()+1;
	}
	int br(0);
	char **a(nullptr);
	try
	{
	    a=new char*[n];
	    for(int i(0); i<v.size(); i++)
	    {
	    	a[i]=nullptr;
	    }
	    for(int i(0); i<v.size(); i++)
	    {
	    	a[i]=new char[v[i].size()+1];
	    	br++;
	    	std::strcpy(a[i],v[i].c_str());
	    }
	    p=a;
	}
	catch(...)
	{
		for(int i(0); i<n; i++) delete[] a[i];
		delete[] a;
		throw;
	}
	return br;
}

int OdbaciOptuzbu(char **&a, int vel, std::string s)
{
	bool pom(false);
	int brojac(0);
	for(int i(0); i<vel; i++)
	{
	    if(a[i]==s)
	    {
	    	pom=false;
	    	break;
	    }
	    else pom=true;
	}
	std::string poruka;
	poruka="Osoba sa imenom " + s + " nije bila optuzena";
	if(pom==true) throw std::domain_error(poruka);
	else
	{
		char **popis;
		popis=a;
		std::string pomocni;
		for(int i(0); i<vel; i++)
		{
			char *pomocni;
			std::strcpy(pomocni,s.c_str());
			if(popis[i]==pomocni)
			{
				delete[] popis[i];
				popis[i]=nullptr;
				brojac++;
			}
		}
	    if(brojac>10)
	    {
	    	char **novi(nullptr);
	    	novi=new char*[vel-brojac];
	    	for(int i(0); i<vel-brojac; i++)
	    	{
	    		novi[i]=nullptr;
	    	}
	    	/*for(int i(0); i<vel-brojac; i++)
	    	{
	    		novi[i]=new char[popis[i].size()+1];
	    	} */
	    	for(int i(0); i<vel-brojac; i++)
	    	{
	    		if(popis[i]!=nullptr)
	    		novi[i]=popis[i];
	    	}
	    	a=novi;
	    }
	}
	return vel-brojac;
}

int DodajOptuzbu(char **&a, int vel, std::string s)
{
	char **novi(nullptr);
	try
	{
		novi=new char*[vel];
		for(int i(0); i<vel; i++)
		{
			novi[i]=nullptr;
		}
		for(int i(0); i<vel; i++)
		{
			int duzina(0);
			for(int j(0); j!='\0'; j++)
			{
				duzina++;
			}
			novi[i]=new char[duzina];
		}
		for(int i(0); i<vel; i++)
		{
			novi[i]=a[i];
		}
		
	}
}


int main ()
{
	std::cout << "Koliko potencijalnih krivaca zelite unijeti?";
	int n;
	std::cin >> n;
	std::vector<std::string> v(n);
	std::cout << "Unesite potencijalne krivce: ";
	for(int i(0); i<n; i++)
	{
		std::getline(std::cin, v[i]);
	}
	char **a(nullptr);
	int br=PotencijalniKrivci(a,v);
	while(true)
	{
	    std::cout << "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: ";
	    int izbor;
	    std::cin >> izbor;
	    if(izbor==1)
	    {
		    std::cout << "Unesite ime novog optuzenog: ";
		    std::string s;
		    std::getline(std::cin,s);
		
	    }
	    else if (izbor==2)
	    {
	    	std::cout << "Unesite ime koje zelite izbaciti: ";
	    	std::string s;
	    	std::getline(std::cin,s);
	    }
	    else if(izbor==3)
	    {
	    	break;
	    }
	    else if(izbor==0) break;
	}
	return 0;
}