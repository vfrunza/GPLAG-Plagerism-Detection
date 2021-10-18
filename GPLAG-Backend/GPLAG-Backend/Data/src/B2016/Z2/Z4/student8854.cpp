/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include <new>
#include <stdexcept>
#include <vector>
#include <string>


int PotencijalniKrivci(char** &pok,std::vector<std::string> ulaz)
{
	
	char** p=nullptr;
	try
	{
		p=new char*[ulaz.size()];
	}
	catch(std::bad_alloc)
	{
		delete[] p;
		throw;
	}
	{
	int i;
	for(i=0;i<ulaz.size();i++)
	{
		p[i]=nullptr;
		try
		{
		p[i]=new char[ulaz[i].size()+1];
		}
		catch(std::bad_alloc)
		{
			for(int j=0;j<=i;j++)
			delete[] p[j];
			delete[] p;
			throw;
		}
		
	}
	} 
	
	int suma=0;
	for(int i=0;i<ulaz.size();i++)
	{
		for(int j=0;j<ulaz[i].size();j++)
		p[i][j]=ulaz[i][j];
		p[i][ulaz[i].size()]='\0';
		suma=suma+ulaz[i].size()+1;
	}
	pok=p;
	
	
	return ulaz.size();
/*	return suma;*/
}

int OdbaciOptuzbu(char** &pok,int vel,std::string ime)
{
	
	for(int i=0;i<vel;i++)
	{
		bool imalga=false;
		for(int j=0;j<ime.size();j++)
		{
			if(pok[i][j]==ime[j])
			{imalga=true;}
			else
			{imalga=false;break;}
		}
		if(imalga && pok[i][ime.size()]=='\0')
		{
			delete[] pok[i];
			pok[i]=nullptr;
			int brojac=0;
			for(int j=0;j<vel;j++)
			{
				if(pok[j]==nullptr)
				brojac++;
			}
			if(brojac>10)
			{
				char** novipok=nullptr;
				try
				{
					novipok=new char*[vel-brojac];
				}
				catch(std::bad_alloc)
				{
					delete[] novipok;
					return vel;
				}
				int broj=0;;
				for(int j=0;j<vel;j++)
				{
					if(pok[j]!=nullptr)
					novipok[broj++]=pok[j];
				}
				for(int i=0;i<vel;i++)
				delete[] pok[i];
				
				delete[] pok;
				pok=novipok;
				vel=vel-brojac;
				
				
			}
			
			
			return vel;
		}
	}
		
		{
			std::string trenutni="Osoba sa imenom "+ime+" nije bila optuzena";
			throw std::domain_error(trenutni);
		}
		
		
	
	
	return vel;
}

int DodajOptuzbu(char** &pok,int vel,std::string ime)
{
	char* p=nullptr;
	try
	{
		p=new char[ime.size()+1];
	}
	catch(std::bad_alloc)
	{
		delete[] p;
		throw;
	}
	
	for(int i=0;i<ime.size();i++)
	p[i]=ime[i];
	p[ime.size()]='\0';
	
	for(int i=0;i<vel;i++)
	{
		if(pok[i]==nullptr)
		{
			pok[i]=p;
			return vel;
		}
	}
	
	char** novipok=nullptr;
	try
	{
		novipok=new char*[vel+1];
	}
	catch(std::bad_alloc)
	{
		delete[] novipok;
		delete[] p;
		throw;
	}
	for(int i=0;i<vel;i++)
	novipok[i]=pok[i];
	delete[] pok;
	novipok[vel]=p;
	pok=novipok;
	
	return vel+1;
}

void IzlistajOptuzbu(char** pok,int vel)
{
	for(int i=0;i<vel;i++)
	{
		if(pok[i]!=nullptr)
		{
			int j=0;
			while(pok[i][j]!='\0')
			{
				std::cout<<pok[i][j];
				j++;
			}
			
			std::cout<<std::endl;
			
			
		}
	}
	
	
	
}





int main ()
{
	std::cout<<"Koliko potencijalnih krivaca zelite unijeti? "<<std::endl;
	int n;
	std::cin>>n;
	std::cin.ignore(10000,'\n');
	std::vector<std::string>ulaz;
	std::string trenutni;
	
	std::cout<<"Unesite potencijalne krivce: "<<std::endl;
	for(int i=0;i<n;i++)
	{
		std::getline(std::cin,trenutni);
		ulaz.push_back(trenutni);
		
		
	}
	char** pok;
	int vel;
	try
	{
	    vel=PotencijalniKrivci(pok,ulaz);
	}
	catch(std::bad_alloc)
	{
		return 0;
	}
	for(;;)
	{
		std::cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: "<<std::endl; 
		int a;
		/*std::cin.ignore(10000,'\n');*/
		std::cin>>a;
		std::cin.ignore(10000,'\n');
		if(a==0)
		{
			break;
		}
		if(a==1)
		{
			std::cout<<"Unesite ime novog optuzenog: "<<std::endl;
			std::string trenutni;
			std::getline(std::cin,trenutni);
			try
			{
			    vel=DodajOptuzbu(pok,vel,trenutni);
			}
			catch(std::bad_alloc)
			{
				break;
			}
			
			
			
			continue;
		}
		if(a==2)
		{
			std::cout<<"Unesite ime koje zelite izbaciti: "<<std::endl;
			std::string trenutni;
			std::getline(std::cin,trenutni);
			try
			{
			    vel=OdbaciOptuzbu(pok,vel,trenutni);
			}
			catch(std::bad_alloc)
			{
				break;
			}
			catch(std::domain_error e)
			{
			
			}
			
			continue;
		}
		if(a==3)
		{
			IzlistajOptuzbu(pok,vel);
			continue;
		}
		
		
	}
	
	for(int i=0;i<vel;i++)
	delete[] pok[i];
	delete[] pok;
	return 0;
}

