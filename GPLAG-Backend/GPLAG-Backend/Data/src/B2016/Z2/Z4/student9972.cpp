#include <iostream>
#include <vector>
#include <string>
#include <new>
#include <stdexcept>
#include <cstring>
using namespace std;
void dealociraj1(char **mat, int n){
 for(int i = 0; i < n; i++) delete[] mat[i];
 delete[] mat;
}
void RazmijeniPokazivace(char **&pok, char **&p) {
 char **pomocna=nullptr;
 pomocna=pok;
 pok=p;
 p=pomocna;
}
void RazmjeniVrijednosti(char *&pok, char *&p)
{
	char *pomocna(pok);
	pok=p;
	p=pomocna;
}
bool Jeliisti(char *p, string s)
{
    for(int i=0;p[i]!='\0' || s[i]!='\0';i++)
    {
        if(p[i]!=s[i])return false;
    }
    return true;
}

int broji(char *p )
{
	int br=0;
	while(*p!='\0'){
	br++;
	p++;
	}
	return br;
}

int PotencijalniKrivci(char **&p, vector<string>v)
{ int br=0;
	
	try
	{	p=nullptr;
		p=new char*[v.size()];
		for(int i = 0; i < v.size(); i++) p[i] = nullptr;
			try
			{
			for(int i=0;i<v.size();i++){  
			p[i]=new char[v[i].size()+1];
			br++;
				}
				for(int i=0;i<v.size();i++)
					for(int j=0;j<v[i].size();j++)
						p[i][j]=v[i][j];
						
				for(int i=0;i<v.size();i++)
				p[i][v[i].size()]='\0';
				return br;
			}
			catch(bad_alloc)
			{
				for(int i=0;i<v.size();i++)
				delete[] p[i];
				delete[] p;
				throw;
			}
			
	}
	catch(...)
	{
		throw;
	}
	return br;
}

int OdbaciOptuzbu(char **& pok, int vel, string s)
{
	string novi;
	int br=0;
	bool ima=false;
	for(int i=0;i<vel;i++){
		if(pok[i]==nullptr)continue;
   		if(Jeliisti(pok[i],s))
   		{ 
   			ima=true;
   			delete[] pok[i];
			pok[i]=nullptr;
		}
	}
   		if(!ima) throw domain_error ("Osoba sa imenom " + s + " nije bila optuzena");

		for(int i=0;i<vel;i++)
		if(pok[i]==nullptr){br++;}
		if(br>10)
		{ 
		int izb=0;
		try
		{
		char **p=nullptr;
		p=new char*[vel-br];
		for(int i = 0; i<vel-br; i++) p[i]=nullptr;
			for(int i=0;i<vel;i++){ 
				if(pok[i]==nullptr) {izb++;continue;}
				 char *pomocna=p[i-izb];
					p[i-izb]=pok[i];
					pok[i]=pomocna;

				}
				RazmijeniPokazivace(pok,p);
				for(int i=0;i<vel;i++)
				delete[] p[i];
				delete[] p;
		}
		catch(...)
		{ return vel;}
		
		return vel-br;	
		}	
				
return vel;
}
int DodajOptuzbu(char **&p, int vel, string s)
{

	try
	{ 
		char *novi=new char[s.length()+1];
		for(int i=0;i<s.length();i++){
		novi[i]=s[i];
		}
		novi[s.length()]='\0';
		bool ima_mjesta=false;
		for(int i=0;i<vel;i++)
		{
			if(p[i]==nullptr){ima_mjesta=true;p[i]=novi;}
		}
		if(!ima_mjesta)
		{
			char **pok=nullptr;
		try
		{
			pok=new char*[vel+1];
			for(int i = 0; i < vel+1; i++) pok[i] = nullptr;
				
				for(int i=0;i<vel;i++){
					char *pomocna=pok [i];
					pok[i]=p[i];
					p[i]=pomocna;
					delete[] p[i];
				}
				delete[] p;
					RazmjeniVrijednosti(pok[vel],novi);
				
		
					RazmijeniPokazivace(pok,p);
					
					delete [] novi;
					vel+=1;
				}
				catch(bad_alloc)
				{
					throw;
				}
				
			}
		}
		catch(bad_alloc)
		{
			throw;
		}
	return vel;
}

void IzlistajOptuzbu(char **pok, int vel)
{
	for(int i=0;i<vel;i++){
		if(pok[i]==nullptr){continue;}
			for(int j=0;pok[i][j]!='\0';j++)
			cout<<pok[i][j];
			cout<<endl;
	}
}
int main ()
{
	int m,n;
	string s,a;
	char **p;
	vector<string> v;
	cout<<"Koliko potencijalnih krivaca zelite unijeti? "<<endl;
	cin>>n;
	if(n>0)
	{
	cout<<"Unesite potencijalne krivce: "<<endl;
	for(int i=0;i<n;i++){
	cin>>a;
	v.push_back(a);
	}
	}
	if(n>=0)
	{
	try
	{
		n=PotencijalniKrivci(p,v);	
	
	
	do
	{
		cout<<"Odaberite opciju: "<<1<<" za unos novog optuzenog, "<<2<<" za brisanje nekog optuzenog "<<3<<" za izlistavanje optuzenih, "<<0<<" za kraj: "<<endl; 
		cin>>m;
		if(m==0){ dealociraj1(p,n);break;}
		if(m==1)
		{
			try 
			{

				cout<<"Unesite ime novog optuzenog: "<<endl;
				cin.ignore(10000,'\n');
				getline(cin,s);
				n=DodajOptuzbu(p,n,s);
				}
				
			catch(bad_alloc)
			{
				cout<<"Problemi sa memorijom!\n";
			}

		}
		else if(m==2)
		{
			try
			{
				cout<<"Unesite ime koje zelite izbaciti: "<<endl;
				cin.ignore(10000,'\n');
				getline(cin,s);
				n=OdbaciOptuzbu(p,n,s);
			}
			catch(domain_error e)
			{
				cout<<"Izuzetak: "<<e.what()<<endl;
			}
		}
		else if(m==3){IzlistajOptuzbu(p,n);}
	}
	while(m!=0);
	}
	catch(bad_alloc)
	{
		cout<<"Problemi sa memorijom!\n";	
	}
}
	return 0;
}