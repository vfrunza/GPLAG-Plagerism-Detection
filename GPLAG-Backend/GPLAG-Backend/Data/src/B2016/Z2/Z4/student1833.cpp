/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

int PotencijalniKrivci(char**&p,std::vector<std::string> imena)
{
	int velicina1=imena.size();
	try
	{
		//ovdje treba bti niz pokazivača;
		p=new char*[imena.size()];
		int brojZnakova=0;
		for(int i=0;i<imena.size();i++)
		{
			brojZnakova=imena[i].length();
			std::string trenutni=imena[i];
			p[i]=new char[brojZnakova+1];
			for(int j=0;j<brojZnakova;j++) 
			{
				p[i][j]=trenutni[j];
				
			}
			p[i][brojZnakova]='\0';
		}
	}
	catch(...)
	{
		for(int i=0;i<velicina1;i++)
		delete p[i];
		delete p;
		throw std::bad_alloc();
	}
	return velicina1;
}
int OdbaciOptuzbu(char**&p,int velicina, std::string ime)
{
	bool postojiOsoba=false;
	for(int i=0;i<velicina;i++)
	{
		if(p[i]!=0)
		{
			bool rijeciPodudarne=true;
			for(int j=0;j<ime.length();j++)
			{
				if(p[i][j]!='\0')
				{
					if(j==(ime.length()-1))
					{
						if(p[i][j+1]!='\0') rijeciPodudarne=false;
					}
					if(p[i][j]!=ime[j]) rijeciPodudarne=false;
				}
				else 
				{
					if(j!=(ime.length()-1)) rijeciPodudarne=false;
				}
			}
			if(rijeciPodudarne)
			{
				postojiOsoba=true;
				delete [] p[i];
				p[i]=0;
			}
		}
	}
	if(!postojiOsoba)
	{
		std::string pom="Osoba sa imenom "+ime+" nije bila optuzena";
		throw std::domain_error(pom);
	}
	int brojNul=0;
	for(int i=0;i<velicina;i++)
	if(p[i]==0) brojNul++;
	if(brojNul>10)
	{
		char** p1;
		try
		{
			
			p1=new char*[brojNul];
			int brojac=0;
			for(int i=0;i<velicina;i++)
			{
				if(p[i]!=0)
				{
					p1[brojac]=p[i];
					brojac++;
				}
			}
			delete p;
			p=p1;
		}
		catch(...)
		{
			for(int i=0;i<brojNul;i++) delete p1[i];
			delete p1;
		}
		return brojNul;
	}
	else return velicina;
}
int DodajOptuzbu(char**&p,int velicina, std::string ime)
{
	
			bool podudaraSe=true;
	//prvo vidi je li ima na jednom mjestu
	for(int i=0;i<velicina;i++)
	{
		char*pomocna=p[i];
		if(pomocna!=0)
		{
			int j=0;
			while(pomocna[j]!='\0')
			{
				j++;
			}
			if(j==ime.length())
			{
				for(j=0;j<ime.length();j++)
				if(pomocna[j]!=ime[j]) podudaraSe=false;
			} else podudaraSe=false;
		}
	}
	if(!podudaraSe)
	{
	int vel=ime.length();
	char*p1=new char[vel+1];
	for(int i=0;i<vel;i++)
	p1[i]=ime[i];
	p1[vel]='\0';
	for(int i=0;i<velicina;i++)
	if(p[i]==0)
	{
		p[i]=p1; 
		return velicina;
	}
	char**pom;
	try
	{
	 pom=new char*[velicina+1];
	 for(int i=0;i<velicina;i++)
	 pom[i]=p[i];
	 pom[velicina]=p1;
	 delete[] p ;
	 p=pom;
	 velicina++;
	 return velicina;
	 
	}
	catch(...)
	{
		for(int i=0;i<velicina+1;i++) delete pom[i];
			delete pom;
			throw std::bad_alloc();
	}
	}
	else return velicina;
}
void IzlistajOptuzbu(char **&p,int velicina)
{
	
	for(int i=0;i<velicina;i++)
	{
		
		if(p[i]!=0)
		{
			char*pom=p[i];
			int j=0;
			while(pom[j]!='\0')
			{
			std::cout<<pom[j];
			j++;
			}
			if(i<(velicina-1))
			std::cout<<std::endl;
		}
	}
}

int main ()
{
	std::cout<<"Koliko potencijalnih krivaca zelite unijeti? ";
	int n;
	std::cin>>n;
	char**listaKrivaca;
	int velicina;
	std::vector<std::string> lista1;
	if(n>0)
	{
	std::cout<<std::endl<<"Unesite potencijalne krivce: ";
	while(n>0)
	{
		std::string krivac;
		std::cin>>krivac;
		lista1.push_back(krivac);
		n--;
	}
	velicina=PotencijalniKrivci(listaKrivaca, lista1);
	int k=1;
		while(k!=0)
		{
			std::cout<<std::endl<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: ";
			std::cin>>k;
			if(k==0 ) break;
			else if(k==1)
			{
				try
				{
				std::cout<<std::endl<<"Unesite ime novog optuzenog: ";
				std::string krivac;
				std::cin>>krivac;
				velicina=DodajOptuzbu(listaKrivaca,velicina,krivac);
				}
				catch(std::bad_alloc)
				{
					std::cout<<"Nema memorije!"<<std::endl;
				}
				
			}
			else if(k==2)
			{
			
			try
			{
				std::cout<<std::endl<<"Unesite ime koje zelite izbaciti: ";
				std::string nevin;
				std::cin>>nevin;
				velicina=OdbaciOptuzbu(listaKrivaca,velicina,nevin);
			}
			catch(std::domain_error e)
			{
				std::cout<<e.what()<<std::endl;
			}	
			}
			else if(k==3)
			{
				std::cout<<std::endl;
				IzlistajOptuzbu(listaKrivaca,velicina);
			}
		}
		for(int i=0;i<velicina;i++)
		delete [] listaKrivaca[i];
		delete [] listaKrivaca;
	}
	return 0;
}
