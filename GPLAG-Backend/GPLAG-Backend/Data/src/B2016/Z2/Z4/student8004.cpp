/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/

#include<iostream>
#include<stdexcept>
#include<new>
#include<string>
#include<vector>

using namespace std;

int PotencijalniKrivci(char** &pok, vector<string> s)
{
	pok=nullptr;
	try
	{
		pok=new char*[s.size()];
		try
		{
			for(int i=0; i<s.size(); i++) pok[i]=nullptr;
			for(int i=0; i<s.size(); i++)
				pok[i]=new char[s[i].size()+1];
			for(int i=0; i<s.size(); i++)
				for(int j=0; j<s[i].size(); j++)
					pok[i][j]=s[i][j];
			for(int i=0; i<s.size(); i++) pok[i][s[i].size()]='\0';
			return s.size();
		}
		catch(...)
		{
			for(int i=0; i<s.size(); i++) delete [] pok[i];
			throw;
		}
	}
	catch(...)
	{
		delete [] pok;
		throw;
	}
}

int OdbaciOptuzbu(char** &pok, int n, string s)
{
	int ind=9999;
	for(int i=0; i<n; i++)
	{
		int br1=0;
		char *p=pok[i];
		while(*p!='\0') { br1++; p++;}
		if(br1==s.size())
		{
			p=pok[i];
			bool a=true;
			for(int i=0; i<s.size(); i++)
			{
				if(s[i]!=*p) a=false;
				p++;
			}
			if(a) ind=i;
		}
	}
	if(ind==9999)
	{
		string s1="Osoba sa imenom "+s+" nije bila optuzena";
		throw domain_error(s1);
	}
	delete [] pok[ind];
	pok[ind]=nullptr;
	int br=0;
	for(int i=0; i<n; i++)
		if(*pok==nullptr) br++;
	if(br>=10)
	{
		char **pok1=nullptr;
		try
		{
			pok1=new char*[n-br];
			for(int i=0; i<n-br; i++) pok1[i]=nullptr;
			try
			{
			    int br1=0, s=0;
			    for(int i=0; i<n; i++)
			    {
			    	if(pok[i]!=nullptr)
			    	{
			    		s=0;
			    		char* p= pok[i], *p1;
			    		while(*p!='\0') { s++; p++;}
			    		s++;
			    		pok1[br1]=new char[s];
			    		p=pok[i]; p1=pok1[br];
			    		while(s!=0)
			    		{
			    			*p1=*p;
			    			p1++;
			    			p++;
			    			s--;
			    		}
			    		br1++;
			    	}
			    }
			    char** pom=pok;
			    pok=pok1;
			    pok1=nullptr;
			    for(int i=0; i<n; i++) delete [] pom[i];
			    delete [] pom;
			    pom=nullptr;
			    return n-br;
			} catch(...) {throw;}
		} catch(...) { throw; }
	}
	else return n;
}

int DodajOptuzbu(char** &pok, int n, string s)
{
	for(int i=0; i<n; i++)
	{
		if(pok[i]==nullptr)
		{
			pok[i]=new char[s.size()+1];
			for(int j=0; j<s.size(); j++) pok[i][j]=s[j];
			pok[i][s.size()]='\0';
			return n;
		}
	}
	char **pok1=nullptr;
	try
	{
		pok1=new char * [n+1];
		for(int i=0; i<n+1; i++)  pok1[i]=nullptr;
		try
		{
			for(int i=0; i<n; i++)
			{
				int broj=0;
				char* p=&pok[i][0];
				while(*p!='\0') {p++; broj++;}
				pok1[i]=new char[broj+1];
				for(int j=0; j<broj+1; j++) pok1[i][j]=pok[i][j];
			}
			pok1[n]= new char [s.size()+1];
			for(int i=0; i<s.size(); i++) pok1[n][i]=s[i];
			pok1[n][s.size()]='\0';
			char ** pom=pok;
			pok=pok1;
			for(int i=0; i<n; i++) delete [] pom[i];
			delete [] pom;
			pok1=nullptr;
			pom=nullptr;
			return n+1;
		}
		catch(...)
		{
			for(int i=0; i<n+1; i++) delete [] pok1[i];
			throw;
		}
	}
	catch(...)
	{
		delete [] pok1;
		throw;
	}
	
}

void IzlistajOptuzbu(char ** pok, int n)
{
	for(int i=0; i<n; i++)
	{
		if(pok[i]!=nullptr)
		cout<<pok[i]<<endl;
	}
}


int main ()
{
	cout<<"Koliko potencijalnih krivaca zelite unijeti? ";
	int n;
	cin>>n;
	cout<<endl<<"Unesite potencijalne krivce: "<<endl;
	vector<string> v; v.resize(n);
	for(int i=0;i<v.size();i++) cin>>v[i];
	char ** pok=nullptr;
	try
	{
		n=PotencijalniKrivci(pok,v);
		while(1)
		{
			cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: "<<endl;
			int a;
			cin>>a;
			if(a==1)
			{
				string s;
				cout<<"Unesite ime novog optuzenog: "<<endl;
				cin>>s;
				try
				{
					n=DodajOptuzbu(pok,n,s);
				}
				catch(...) { cout<<"stas";}
			}
			else if(a==2)
			{
				cout<<"Unesite ime koje zelite izbaciti: "<<endl;
				string s; cin>>s;
				try
				{
					n=OdbaciOptuzbu(pok,n,s);
				}
				catch(domain_error m) {cout<<m.what();}
			}
			else if(a==3) IzlistajOptuzbu(pok,n);
			else if(a==0) break;
		}
		for(int i=0; i<n; i++) delete [] pok[i];
		delete [] pok;
		return 0;
	} 
	catch(...) {delete [] pok;} 
}