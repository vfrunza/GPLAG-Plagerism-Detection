#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stdexcept>

using std::string;
using std::cout;
using std::cin;
using std::vector;


int PotencijalniKrivci(char **&pok,vector<string> v)
{
	char **p=new char*[v.size()];
	pok=p;
	int f=0;
	try
	{
		for(int i=0;i<v.size();i++)
		{
			f=i;
			p[i]=new char[v[i].size()+1];
			strcpy(p[i],v[i].c_str());
		}
	}
	catch(std::bad_alloc)
	{
		for(int i=0;i<f;i++)
			delete[] p[i];
		delete[] p;
		throw;
	}
	return f+1;
}
int OdbaciOptuzbu(char **&pok,int vel,string s)
{
	int brojac(0);
	for(int i=0;i<vel;i++)
	{
		if(pok[i]==nullptr)
		{
			brojac++;
			continue;
		}
		if(strcmp(pok[i],s.c_str())==0)
		{	
			delete[] pok[i];
			pok[i]=nullptr;
			brojac++;
			if(brojac<=10)
				return vel;
			try{
			char **p=new char*[vel-brojac];
			int k=0;
			for(int j=0;j<vel;j++)
			{
				if(pok[j]!=nullptr)
				{
					p[k]=pok[j];
					k++;
				}
			}
			delete[] pok;
			pok=p;
			vel=k;
			return vel;
			}
			catch(std::bad_alloc)
			{
				return vel;
			}
		}
	}
	throw std::domain_error("Osoba sa imenom "+s+" nije bila optuzena\n");
}
int DodajOptuzbu(char **&pok,int vel,string s)
{
	char *p=new char[s.length()+1];
	strcpy(p,s.c_str());
	for(int i=0;i<vel;i++)
	{
		if(pok[i]==nullptr)
		{
			pok[i]=p; 
			return vel;
		}
	}
	try
	{
		char **pok2=new char*[vel+1];
		for(int i=0;i<vel;i++)
			pok2[i]=pok[i];
		pok2[vel]=p;
		delete[] pok;
		pok=pok2;
		vel++;
		return vel;
	}
	catch(std::bad_alloc)
	{
		delete[] p;
		throw;
	}
}
void IzlistajOptuzbu(char **pok,int vel)
{
	for(int i=0;i<vel;i++)
		if(pok[i]!=nullptr)
			cout<<pok[i]<<"\n";
}
int main ()
{
	cout<<"Koliko potencijalnih krivaca zelite unijeti? \n";
	int vel;
	cin>>vel;
	cin.ignore(10000,'\n');
	cout<<"Unesite potencijalne krivce: \n";
	vector <string> v;
	for(int i=0;i<vel;i++)
	{
		string s;
		getline(cin,s);
		v.push_back(s);
	}
	int broj;
	char **p;
	try
	{
		try
		{
			vel=PotencijalniKrivci(p,v);
		}
		catch(std::bad_alloc)
		{
			return 0;
		}
		do{
		broj=0;
		cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: \n";
		cin>>broj;
		cin.ignore(10000,'\n');
		if(broj==1)
		{
			cout<<"Unesite ime novog optuzenog: \n";
			string s;
			getline(cin,s);
			vel=DodajOptuzbu(p,vel,s);
		}
		else if(broj==2)
		{
			cout<<"Unesite ime koje zelite izbaciti: \n";
			string s;
			getline(cin,s);
			try{
			vel=OdbaciOptuzbu(p,vel,s);
			}
			catch(std::domain_error e)
			{
				cout<<e.what();
			}
		}
		else if(broj==3)
			IzlistajOptuzbu(p,vel);
		}while(broj);
		for(int i=0;i<vel;i++)
			delete[] p[i];
		delete[] p;
	}
	
	catch(std::bad_alloc)
	{
		for(int i=0;i<vel;i++)
			delete[] p[i];
		delete[] p;
	}
	return 0;
}