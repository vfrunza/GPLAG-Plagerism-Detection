/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>
#include <cstring>

void Order66(char **mat, int n){
 for(int i = 0; i < n; i++) delete[] mat[i];
 delete[] mat;
}

int Duz(char *p)
{
	int n=0;
	while(*p!='\0') 
	{
		p++;
		n++;
	}
	return n+1;
}

int PotencijalniKrivci (char **&p, std::vector<std::string> krivci)
{
	int i;
	p=nullptr;
	try
	{
		p=new char*[krivci.size()];
		for(i=0;i<krivci.size();i++) p[i]=nullptr;
	}
	catch(std::bad_alloc x)
	{
		delete[] p;
		throw x;
	}
	try
	{
		for(i=0;i<krivci.size();i++)
		{
			p[i]=new char[krivci[i].size()+1];
			std::strcpy(p[i], krivci[i].c_str());
		}
	}
	catch(std::bad_alloc x)
	{
		for(i=0;i<krivci.size();i++) delete[] p[i];
		delete[] p;
		throw x;
	}
	return i;
}

int OdbaciOptuzbu(char **&p,int n,std::string nevin)
{
	bool izbacen=false;
	for(int i=0;i<n;i++)
	{
		if(p[i]==nullptr) continue;
		if(std::strcmp(p[i], nevin.c_str())==0)
		{
			delete[] p[i];
			p[i]=nullptr;
			izbacen=true;
		}
	}
	if(!izbacen) throw std::domain_error("Osoba sa imenom "+nevin+" nije bila optuzena");
	int broj=0;
	for(int i=0;i<n;i++)
	{
		if(p[i]==nullptr) broj++;
	}
	if(broj>10)
	{
		char **novi=nullptr;
		try
		{ 
			novi = new char*[n-broj];
		}
		catch(std::bad_alloc x)
		{
			delete[] novi;
		}
		try
		{
			for(int i=0;i<n-broj;i++) novi[i]=nullptr;
			int brojnovih=0;
			for(int i=0;i<n;i++)
			{
				if(p[i])
				{
					novi[brojnovih]=new char[Duz(p[i])+1];
					std::strcpy(novi[brojnovih],p[i]);
					brojnovih++;
				}
			}
			for(int i=0;i<n;i++) delete[] p[i];
			delete[] p;
			p=novi;
			n-=broj;
			return n;
		}
		catch(std::bad_alloc x)
		{
			for(int i=0;i<n-broj;i++) delete[] novi[i];
			delete[] novi;
		}
	}
	return n;
}
int DodajOptuzbu(char **&p,int n,std::string novi)
{	
	char* novic=nullptr;
	try
	{
		novic=new char[novi.size()+1];
		std::strcpy(novic,novi.c_str());
		for(int i=0;i<n;i++)
		{
			if(!p[i])
			{
				p[i]=novic;
				return n;
			}
		}
	}
	catch(std::bad_alloc x)
	{
		delete[] novic;
		throw x;
	}
	char **novin=nullptr;
	try
	{
		novin = new char*[n+1];
		for(int i=0;i<n+1;i++) novin[i]=nullptr;
		for(int i=0;i<n;i++)
		{
			novin[i]=new char[std::strlen(p[i])+1];
			std::strcpy(novin[i],p[i]);
		}
		novin[n]=novic;
		for(int i=0;i<n;i++) delete[] p[i];
		delete[] p;
		p=novin;
		n+=1;
		return n;
	}
	catch(std::bad_alloc x)
	{
		Order66(novin,n);
		throw x;
	}
}

void IzlistajOptuzbu (char **p,int n)
{
	for(int i=0;i<n;i++)
		if(p[i]) std::cout << p[i] << "\n";
}

int main ()
{
	try
	{
	int n;
	do{
	std::cout <<"Koliko potencijalnih krivaca zelite unijeti? \n";
	std::cin >> n;
	if(n<0) std::cout << "Broj ne može biti negativan!\n";
	}while(n<0);
	std::vector<std::string> imena(n);
	std::cout << "Unesite potencijalne krivce: \n";
	if(n!=0)std::cin >> std::ws;
	for(std::string &s:imena)
		std::getline(std::cin, s);
	char **nizPotencijalnih;
	n = PotencijalniKrivci(nizPotencijalnih, imena);
	int kom;
	while(std::cout << "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: \n",std::cin >> kom,kom!=0)
	{
		try{
		if(kom==1)
		{
			std::cout << "Unesite ime novog optuzenog: \n";
			std::string novi;
			std::cin >> std::ws;
			std::getline(std::cin, novi);
			n=DodajOptuzbu(nizPotencijalnih,n,novi);
			continue;
		}
		if(kom==2)
		{
			std::cout << "Unesite ime koje zelite izbaciti: \n";
			std::string novi;
			std::cin >> std::ws;
			std::getline(std::cin, novi);
			n=OdbaciOptuzbu(nizPotencijalnih,n,novi);
			continue;
		}
		if(kom==3) IzlistajOptuzbu(nizPotencijalnih,n);
		}catch(std::domain_error x)
		{
			std::cout << "IZUZETAK: "<< x.what() << "\n";
		}
		catch(std::bad_alloc x)
		{
			std::cout << "Greska u alokaciji";
		}
	}
	Order66(nizPotencijalnih, n);
	}
	catch(std::bad_alloc x)
	{
		std::cout << "Greska u alokaciji";
	}
	return 0;
}