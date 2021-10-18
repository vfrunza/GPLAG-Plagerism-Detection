#include<iostream>
#include<string>
#include<vector>
#include<new>
#include<stdexcept>
#include<cstring>
#include<algorithm>
int PotencijalniKrivci(char**& a,std::vector<std::string> v)
{
	int N = v.size();
	try
	{
		a = new char*[N];
		for(int i=0;i<N;i++) a[i] = nullptr;
	}
	catch(std::bad_alloc)
	{
		throw std::bad_alloc();
	}
	
	for(int i=0;i<N;i++)
	{
		try
		{
			a[i] = new char[v[i].size()+1];
		}
		catch(std::bad_alloc)
		{
			for(int j=0;j<N;j++) delete[] a[j];
			delete[] a;
			throw std::bad_alloc();
		}
		strcpy(a[i],v[i].c_str());
	}
	return N;
}

int OdbaciOptuzbu(char**& a,int N,std::string s)
{
	bool ima = false;
	for(int i=0;i<N;i++)
	{
		if(a[i]==nullptr) continue;
		if(s == std::string(a[i]))
		{
			ima = true;
			break;
		}
	}
	if(!ima) 
	{
		throw std::domain_error("Osoba sa imenom "+s+" nije bila optuzena");
	}
	for(int i=0;i<N;i++)
	{
		if(a[i]==nullptr) continue;
		if(s == std::string(a[i]))
		{
			delete[] a[i];
			a[i] = nullptr;
		}
	}
	int cnt = std::count(a,a+N,nullptr);
	if(cnt>10)
	{
		char** b;
		try 
		{
			b = new char*[N-cnt];	
		}
		catch (std::bad_alloc) 
		{
			return N;
		}
		int k = 0;
		for(int i=0;i<N;i++)
		{
			if(a[i]!=nullptr)
			{
				b[k] = a[i];
				k++;
			}
		}
		delete[] a;
		a = b;
		return N-cnt;
	}
	return N;
}
int DodajOptuzbu(char**& a,int N,std::string s)
{
	char* pok = new char[s.size()+1];//
	strcpy(pok,s.c_str());
	
	if(std::count(a,a+N,nullptr) == 0)
	{
		char** b;
		try
		{
			b = new char*[N+1];
		}
		catch(...)
		{
			return N;
		}
		for(int i=0;i<N;i++)
		{
		  b[i] = a[i];
		}
		delete[] a;
		b[N] = pok;
		a = b;
		return N+1;
	}
	else
	{
		for(int i=0;i<N;i++)
		{
			if(a[i]==nullptr)
			{
				a[i] = pok;
				break;
			}
		}
		return N;
	}
}

void IzlistajOptuzbu(char** a,int N)
{
	for(int i=0;i<N;i++)
	{
		if(a[i]!=nullptr)
		{
			std::cout<<a[i]<<"\n";
		}
	}
}

int main ()
{
	
	std::cout<<"Koliko potencijalnih krivaca zelite unijeti? \n";
	int N, opt;
	std::cin>> N;
	std::vector<std::string> v(N);
	std::cout<<"Unesite potencijalne krivce: \n";
	std::cin.ignore(1000,'\n');
	for(auto& e:v) std::getline(std::cin, e);
	char** a;
	try
	{
	PotencijalniKrivci(a,v);
	}
	catch(...)
	{
		std::cout<<"Izuzetak";
		return 0;
	}
	while(true)
	{
	std::cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: \n";
	std::cin>> opt;
	if(opt == 0) break;
	else if(opt == 1)
	{
		std::cout<<"Unesite ime novog optuzenog: \n";
		std::string s;
		std::cin.ignore(10000,'\n');
		std::getline(std::cin, s);
		try
		{
			N =	DodajOptuzbu(a, N, s);
		}
		catch(...)
		{
			std::cout<<"Izuzetak";
			break;
		}
	}
	else if(opt == 2)
	{
		std::cout<<"Unesite ime koje zelite izbaciti: \n";
		std::string s;
		std::cin.ignore(10000,'\n');
		std::getline(std::cin, s);
		try
		{
			N =	OdbaciOptuzbu(a, N, s);
		}
		catch(std::domain_error e)
		{
			std::cout<<e.what()<<"\n";
			break;
		}
	}
	else if(opt == 3) IzlistajOptuzbu(a, N);
	}
	for(int i=0;i<N;i++) delete[] a[i];
	delete[] a;
	return 0;
}