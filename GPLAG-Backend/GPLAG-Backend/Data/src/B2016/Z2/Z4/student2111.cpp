/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>

typedef  char *pokazivac;
int PotencijalniKrivci(char  **&prvi,std::vector<std::string>spisak)
{
	char  **a=nullptr;
	a=new char*[spisak.size()];
	for(int i=0;i<spisak.size();i++)
	{
		a[i]=nullptr;
	}
	
	try{
	for(int i=0;i<spisak.size();i++)
	{
		a[i]=new char[spisak[i].size()+1];
	}
	
	for(int i=0;i<spisak.size();i++)
	{
		for(int j=0;j<spisak[i].size();j++)
		{
			a[i][j]=spisak[i][j];
		}
		
		a[i][spisak[i].size()]='\0';
	}
	
	prvi=a;
	return spisak.size();
	
	
	}
	catch(std::bad_alloc)
	{
			if(a!=nullptr)
			{
				for(int i=0;i<spisak.size();i++)
			  	delete[] a[i];
			delete [] a;
			}
			
		
		throw std::bad_alloc();
	}
	
	
}
void IzlistajOptuzbu(char **&prvi,int velicina)
{
	for(int i=0;i<velicina;i++)
	{
		int j=0;
		int prosao=0;
		while(prvi[i][j]!='\0')
		{
			prosao++;
			std::cout<<prvi[i][j];
			j++;
		}
		if(prosao!=0)
		std::cout<<"\n";
	}
	
	
}
int brojrijeci(char **&pokazivac,int i)
{
	int vrati=0;
	int j=0;
	while (pokazivac[i][j]!='\0') {
		vrati++;
		j++;
	}
	return vrati;
}
bool poredjenje_rijeci(char**&pokazivac,int i,std::string s,int velicina)
{
	
	std::string temp;
	int j=0;
	while (pokazivac[i][0]=='\0') {
		i++;
		if(i>=velicina)
		return false;
	}
	if(pokazivac[i][0]!='\0')
	{
		while (pokazivac[i][j]!='\0') 
		{
		temp.push_back(pokazivac[i][j]);
		j++;
		}
	}
	
	if(s==temp)
	return true;
	return false;
	
	
	
	
}
int OdbaciOptuzbu(char **&prvi,int velicina,std::string s)
{
	int broj_za_brisanje=0;
	bool postoji_u_spisku=true;
	bool izuzetak=true;
	std::string temp1="Osoba sa imenom ";
	std::string temp2=" nije bila optuzena";
	std::string izuzetak_ispis=temp1+s+temp2;

	for(int i=0;i<velicina;i++)
	{
		postoji_u_spisku=true;
		postoji_u_spisku=poredjenje_rijeci(prvi,i,s,velicina);
		if(postoji_u_spisku==true)
		{
			delete[] prvi[i];
			prvi[i]=new char[1];
			prvi[i][0]='\0';
			izuzetak=false;
		}
	}
	
	if(izuzetak==true)
	{
		throw std::domain_error(izuzetak_ispis);
	}
	
	for(int i=0;i<velicina;i++)
	   {
			if(prvi[i][0]=='\0')
			broj_za_brisanje++;
		}
		
	if(broj_za_brisanje>=10)
	{
		int pomocna=velicina;
		for(int i=0;i<pomocna;i++)
		{
			if(prvi[i][0]=='\0')
			{	
				prvi[i][0]='a';
				delete[] prvi[i];
			}
		
			
		}
			
		velicina=velicina-broj_za_brisanje;
	}
	if(velicina==0)
	delete[] prvi;
	return velicina;
}


int DodajOptuzbu(char **&prvi,int velicina,std::string s)
{
	bool prosao=false;
	int temp;
	char **vrati=nullptr;
	try{
		for(int i=0;i<velicina;i++)
		{
			if(prvi[i]==nullptr)
			{	prosao=true;
				temp=i;
				prvi[i]=new char[s.size()+1];
				for(int j=0;j<s.size();j++)
				prvi[i][j]=s[j];
				prvi[i][s.size()]='\0';
				i=velicina;
			}
			
		}
		if(prosao==true)
		{
			velicina++;
			return velicina;
		}
		int pomocna_velicina=0;
		vrati=new char*[velicina+1];
		std::string pomocni_string;
		for(int i=0;i<velicina;i++)
		{
			pomocni_string.resize(0);
			pomocna_velicina=0;
			while (prvi[i][pomocna_velicina]!='\0') {
			pomocni_string.push_back(prvi[i][pomocna_velicina]);
			pomocna_velicina++;
			}
			pomocni_string.push_back(prvi[i][pomocna_velicina]);
			
			vrati[i]=new char[pomocni_string.size()];
			for(int j=0;j<pomocni_string.size();j++)
			vrati[i][j]=pomocni_string[j];

		}
		
		vrati[velicina]=new char[s.size()+1];
		for(int i=0;i<s.size();i++)
		vrati[velicina][i]=s[i];
		vrati[velicina][s.size()]='\0';
		velicina++;
		for(int i=0;i<velicina-1;i++)
		delete[] prvi[i];
		delete[] prvi;
		prvi=vrati;
		return velicina;
	}
	catch(std::bad_alloc)
	{
		if(prosao==true)
		{
			delete prvi[temp];
			prvi[temp]=nullptr;
		}
		else{
			if(vrati!=nullptr)
			for(int i=0;i<velicina+1;i++)
			delete[] vrati[i];
			delete[] vrati;
		}
		
		throw std::bad_alloc();
		
	}
	
}
int main ()
{
	int pomocni_broj_krivaca=0;
	char **pointer;
	int broj_krivaca;
	int prolaz=0;
	try{
	int opcija;
	std::cout<<"Koliko potencijalnih krivaca zelite unijeti? \n";
	std::cin>>broj_krivaca;
	pomocni_broj_krivaca=broj_krivaca;
	std::cin.clear();
	std::cin.ignore(100,'\n');
	std::cout<<"Unesite potencijalne krivce: ";
	std::vector<std::string> spisak;
	for(int i=0;i<broj_krivaca;i++)
	{
		std::string s;
		std::getline(std::cin,s);
		spisak.push_back(s);
	}
	
	broj_krivaca=PotencijalniKrivci(pointer,spisak);
	prolaz++;
	std::cout<<"\nOdaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: ";
	do
	{
		
		std::cin>>opcija;
		std::cin.clear();
		std::cin.ignore(100,'\n');
		if(opcija==1)
			{
				std::cout<<"\nUnesite ime novog optuzenog: \n";
				std::string temp;
				std::getline(std::cin,temp);
				broj_krivaca=DodajOptuzbu(pointer,broj_krivaca,temp);
				pomocni_broj_krivaca=broj_krivaca;
				
			}
			
			
		if(opcija==2)
		{
			std::cout<<"\nUnesite ime koje zelite izbaciti: \n";
			std::string temp1;
			std::getline(std::cin,temp1);
			broj_krivaca=OdbaciOptuzbu(pointer,broj_krivaca,temp1);
			for(int i=0;i<spisak.size();i++)
			if(spisak[i]==temp1)
			spisak.erase(spisak.begin()+i);
			
		}
		if(opcija==3)
		{
			std::cout<<"\n";
			IzlistajOptuzbu(pointer,broj_krivaca);
		}
		if(opcija==0)
		{
			for(int i=0;i<pomocni_broj_krivaca;i++)
			delete[] pointer[i];
			delete[] pointer;
			return 0;
			
		}
			std::cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: ";

	}while (opcija!=0) ;
	}
	catch(std::domain_error izuzetak)
	{
		for(int i=0;i<pomocni_broj_krivaca;i++)
		delete[] pointer[i];
		delete[] pointer;
		std::cout<<izuzetak.what();
	}
	catch(std::bad_alloc)
	{
		std::cout<<"Nedovoljno memorije";
	}
	return 0;
}