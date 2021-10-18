/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/

#include <iostream>
#include <string>
#include <vector>
#include <new>
#include <string.h>
#include <stdexcept>
int PotencijalniKrivci(char **&c, std::vector<std::string> S)
{
	int brojac (0);
	
	try{
		c = new char*[S.size()];
	} catch(std::bad_alloc e){
		throw e;
	}

	try
	{
		for(int i(0);i<S.size();i++) 
		{
			c[i]=new char[S[i].length()+1]; 
			brojac++;
			
		}	
	}
	catch(std::bad_alloc )
	{
		
		for(int i(0); i < brojac; i++) delete[] c[i];
		
		delete[] c;
		throw ;
	}
	
	for(int i(0); i < brojac; i++)
	{
		strcpy(c[i],S[i].c_str());
	}
	
	
	return brojac;
	
}

int OdbaciOptuzbu(char **& c, int velicina, std::string Ime)
{
	int brojac(0),triger(0), brojodbacenih(0);
	for(int i(0);i < velicina; i++)
	{
		if(c[i] == Ime) {
			delete[] c[i];
			c[i] = nullptr;
			brojodbacenih++;
			
		}
		brojac++;
	}
	
	if(brojodbacenih == 0) throw std::domain_error  (Ime);
	std::vector<int> v;
	for(int i(0); i < velicina;i++)
	{
		if(c[i] != nullptr)
		{
			triger++;
			v.push_back(i);
		}
			
	}
	
	if(velicina-v.size() <= 10 ) return velicina;
	else
	{
		char **a(new char*[v.size()]);
		for(int i(0);i< v.size(); i++)
		{
			
			a[i]= new char[strlen(c[v[i]]) + 1];
			strcpy(a[i], c[v[i]]);
			
		}
		for(int i=0; i < velicina; i++){
			delete[] c[i];
		}
		delete[] c;
		c=a;
		return v.size();
	}
	
}

int DodajOptuzbu(char **&c, int velicina, std::string Ime)
{
	char *Optuzeni(new char[Ime.length() + 1]);
	for(int i(0);i< Ime.length();i++)
	{
		Optuzeni[i]=Ime[i];
	}
	Optuzeni[Ime.length()] = '\0';
	
	if(velicina == 0) 
	{
		try
		{
		c = new char*[1];
		c[0] = Optuzeni;
		}
		catch(std::bad_alloc)
		{
			delete[] c[0];
			throw;
		}
		return velicina + 1;
	}
	
	int brojac (0),triger(0);
	for(int i(0); i < velicina ; i++)
	{
		if(c[i] == nullptr){
		 c[i] = Optuzeni;
		 return velicina;
		}
		brojac++;
	}
	if(brojac == velicina )
	{
		char **Novi_niz = nullptr;
		
		try 
		{
			Novi_niz = new char* [velicina+1];
			for(int i(0); i < velicina; i++)
				Novi_niz[i] = nullptr;
			for(int i(0); i < velicina; i++){
						
				Novi_niz[i] = new char[strlen(c[i]) + 1];
				triger++;
				strcpy(Novi_niz[i],c[i]);
			
			}
			Novi_niz[velicina] = Optuzeni;
			
			for(int i(0);i< velicina; i++)
				delete[] c[i];
			delete[] c;
			c = Novi_niz;
			//Novi_niz = nullptr;
			return (velicina+1);
		}
		catch(std::bad_alloc)
		{
			for(int i(0);i<velicina+1;i++)
				delete[] Novi_niz[i];
				delete[] Novi_niz;
			throw;
		}
		
	}
}

void IzlistajOptuzbu(char ** Lista, int n)
{
	for(int i(0);i<n;i++)
	{
		if(Lista[i] != nullptr) std::cout<<Lista[i]<<std::endl;
	}
	
	
}




int main ()
{
	char ** Optuzeni(nullptr);
	std::cout<<"Koliko potencijalnih krivaca zelite unijeti? \n";
	int n;
	std::cin>>n;
	std::cout<<"Unesite potencijalne krivce: \n";
	std::vector<std::string> Unos;
	for(int i(0);i<n;i++)
	{
		
		std::string Ime;
		std::cin.ignore(1000,'\n');
		std::cin>>Ime;
		Unos.push_back(Ime);
	}
	int velicina = PotencijalniKrivci(Optuzeni,Unos);
	
	
	try
	{
	while (true)
	{
		
		std::cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: \n";
		int a;
		std::cin>>a;
		if(a == 1)
		{
			std::cout<<"Unesite ime novog optuzenog: \n";
			std::string NovoIme;
			std::cin.ignore(1000,'\n');
			std::cin>>NovoIme;
			velicina=DodajOptuzbu(Optuzeni,velicina,NovoIme);
		}
		if(a == 2)
		{
			std::cout<<"Unesite ime koje zelite izbaciti: \n";
			std::string NoviOptuzeni;
			std::cin.ignore(1000,'\n');
			std::cin>>NoviOptuzeni;
			velicina=OdbaciOptuzbu(Optuzeni,velicina,NoviOptuzeni);
		}
		if(a == 3)
		{
			IzlistajOptuzbu(Optuzeni,velicina);
		}
		if(a == 0) return 0;
	}
	}
	catch(std::domain_error izuzetak)
	{
		std::cout<<"Osoba sa imenom "<<izuzetak.what()<<" nije bila optuzena"<<std::endl;
		
	}
	catch(std::bad_alloc)
	{
		for(int i(0);i<velicina;i++) delete[] Optuzeni[i];
		delete [] Optuzeni;
		std::cout<<"Nedovoljno memorije";
	}
	
	return 0;
}