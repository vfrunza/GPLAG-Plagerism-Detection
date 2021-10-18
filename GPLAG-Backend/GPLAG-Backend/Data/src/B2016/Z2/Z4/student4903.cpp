/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<new>
#include<stdexcept>

int PotencijalniKrivci(char**&c,std::vector<std::string> v)
{
	c=nullptr;
	int brojac(0);
	try
	{
		c=new char*[v.size()];
		
		for(int i(0);i<v.size();i++)
		{
			c[i]=new char[v[i].length()+1];
			std::strcpy(c[i],&v[i][0]);
			brojac++;
		}
	}
	catch(std::bad_alloc izuzekak)
	{
		for(int i(0);i<v[i].size();i++)
		{
			delete[] c[i];
		}
		delete [] c;
		throw std::bad_alloc();
	}
	return brojac;
}

int OdbaciOptuzbu(char**&c,int vel,std::string s)
{
	bool isti(false);
	for(int i(0);i<vel;i++)
	{
		if(std::strcmp(c[i],&s[0])==0)
		{
			isti=true;
			delete [] c[i];
			c[i]=nullptr;
		}
	}
	if(isti==false)
		throw std::domain_error("Osoba sa imenom "+s+" nije bila optuzena");
	int brojac(0);
	for(int i(0);i<vel;i++)
	{
		if(c[i]==nullptr)
			brojac++;
	}
	char**h=nullptr;
	try
	{
		if(brojac>10)
		{
			int nvel=vel-brojac;
			h=new char*[nvel];
			int j(0);
			for(int i(0);i<vel;i++)
			{
				if(c[i]!=nullptr)
				{
					h[j]=new char[std::strlen(c[i])+1]; //+1 zbog nul-terminatora
					std::strcpy(h[j],c[i]);
					j++;
				}
			}
			for(int i(0);i<vel;i++) delete [] c[i];
			delete [] c;
			vel=nvel;
			c=h;
		}
	}
	catch(std::bad_alloc izuzekak)
	{
		if(!h) delete [] h;
		else
		{
		for(int i(0);i<vel;i++)
			{
				delete [] h[i];
			}
			delete [] h;
		}
	}
	return vel;
}

int DodajOptuzbu(char**&c,int vel,std::string s)
{
	char *pok=nullptr;
	char**h=nullptr;
	try
	{
		pok=new char[s.length()+1];
		std::strcpy(pok,&s[0]);
		bool imaprazno(false);
		for(int i(0);i<vel;i++)
		{
			if(c[i]==nullptr)
			{
				c[i]=pok;
				imaprazno=true;
				break;
			}
		}
		if(imaprazno==false)
		{
			h=new char*[vel+1];
			for(int i(0);i<vel;i++)
			{
				h[i]=new char[std::strlen(c[i])+1];
				std::strcpy(h[i],c[i]);
			}
			h[vel]=pok;
			for(int i(0);i<vel;i++)
			{
				delete [] c[i];
			}
			delete [] c;
			c=h;
			vel++;
		}
	}
	catch(std::bad_alloc izuzetak)
	{
		delete [] pok;
		if(!h) delete [] h; 
		else
		{
		for(int i(0);i<vel;i++)
			{
				delete [] h[i];
			}
			delete [] h;
		}
	}
	return vel;
}

void IzlistajOptuzbu(char**c,int vel)
{
	for(int i(0);i<vel;i++)
	{
		if(c[i]!=nullptr)
		{
			std::cout<<c[i]<<std::endl;
		}
	}
}

int main ()
{
try
{
	std::cout<<"Koliko potencijalnih krivaca zelite unijeti? "<<std::endl;
	int vel;
	std::cin>>vel;
	std::vector<std::string> v(vel);
	std::cin.ignore(1000,'\n');
	std::cout<<"Unesite potencijalne krivce: "<<std::endl;
	for(int i(0);i<vel;i++)
	{
		std::getline(std::cin,v[i]);
	}
	char**c;
	vel=PotencijalniKrivci(c,v);
	int choice(-1);
	for(;;)
	{
		std::cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: "<<std::endl;
		std::cin>>choice;
		std::cin.ignore(1000,'\n');
	
		if(choice==0)
			break;
		else if(choice==1)
		{
			std::cout<<"Unesite ime novog optuzenog: "<<std::endl;
			std::string s;
			std::getline(std::cin,s);
			vel=DodajOptuzbu(c,vel,s);
		}
		else if(choice==2)
		{
		try
		{
			std::cout<<"Unesite ime koje zelite izbaciti: "<<std::endl;
			std::string s2;
			std::getline(std::cin,s2);
			vel=OdbaciOptuzbu(c,vel,s2);
		}
		catch(std::domain_error izuzetak)
		{
			std::cout<<izuzetak.what()<<std::endl;
		}
		}
		else if(choice==3)
			IzlistajOptuzbu(c,vel);
	}
	for(int i(0);i<vel;i++)
	{
		delete [] c[i];
	}
	delete [] c;
	return 0;
}
	catch(std::bad_alloc)
	{
	}
	
}