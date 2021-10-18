/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>
using namespace std;

int PotencijalniKrivci(char ** &sp, vector<string> lista)
{
	sp=nullptr;
	for(int i=0; i<lista.size(); i++) lista[i]+='\0';
	try
	{
		sp=new char*[lista.size()];
		for(int i=0; i<lista.size(); i++) sp[i]=nullptr;
		try
		{
			for(int i=0; i<lista.size(); i++) sp[i]=new char[lista[i].size()];
			for(int i=0; i<lista.size(); i++)
				for(int j=0; j<lista[i].size(); j++) sp[i][j]=lista[i][j];
			return lista.size();
		} catch(...) { for(int i=0; i<lista.size(); i++) delete [] sp[i]; throw;}
	}
	catch(...)
	{
		delete [] sp; throw;
	}
}

bool isti(char* niz, string s)
{
	for(int i=0; i<s.size(); i++)
		if(s[i]!=niz[i]) return false;
	return true;
}

int OdbaciOptuzbu(char ** &lista, int n, string rec)
{
	bool egzistira=false;
	for(int i=0; i<n; i++)
	{
		int br=0;
		char*z=&lista[i][0];
	while(*z!='\0') { br++; z++;}
		if(rec.size()==br)
		{
			if(isti(lista[i], rec))
			{
				egzistira=true;
				delete [] lista[i];
				lista[i]=nullptr;
			}
		}
	}
	if(!egzistira) throw domain_error("Osoba sa imenom "+rec+" nije bila optuzena");
	int broj=0;
	for(int i=0; i<n; i++) if(lista[i]==nullptr) broj++;
	if(broj>=10)
	{
		char **l1;
		l1=nullptr;
		try
		{
			l1=new char*[n-broj];
			for(int i=0; i<n-broj; i++) l1[i]=nullptr;
			try {
				int br=0;
			for(int i=0; i<n; i++)
				if(lista[i]!=nullptr)
				{
					int brr=0;
					char* z=&lista[i][0];
	                while(*z!='\0') { brr++; z++;}
					l1[br]=new char[brr+1];
					for(int j=0; j<brr; j++)l1[br][j]=lista[i][j];
					l1[br][brr]='\0';
					br++;
				}
			for(int i=0; i<n; i++) delete [] lista[i];
			delete [] lista;
			lista=l1;
			l1=nullptr;
			n-=broj;
			return n;
			}
			catch (...) {
				throw;
			}
		}
		catch(...) { throw; }
	} else return n;
}

int DodajOptuzbu(char ** &lista, int n, string rec)
{
	bool ima=false;
	rec+='\0';
	char *pok=nullptr;
	try
	{
		pok=new char[rec.size()];
		for(int i=0; i<rec.size(); i++) pok[i]=rec[i];
	}
	catch(...) {throw;}
	for(int i=0; i<n; i++)
	{
		if(lista[i]==nullptr)
		{
			ima=true;
			lista[i]=pok;
		}
	}
	if(ima) return n;
	else
	{
		char **li=nullptr;
		try
		{
			li=new char *[n+1];
			for(int i=0; i<n+1; i++) li[i]=nullptr;
			for(int i=0; i<n; i++){ 
				int brr=0;
				char* z=&lista[i][0];
	            while(*z!='\0') { brr++; z++;}
				li[i]=new char[brr+1];
				for(int j=0; j<brr; j++)
				li[i][j]=lista[i][j];
				li[i][brr]='\0';
			}
			li[n]=pok;
			for(int i=0; i<n; i++) delete [] lista[i];
			delete [] lista;
			lista=li;
			li=nullptr;
			n++;
			return n;
		} catch(...) {throw;}
	}
}

void IzlistajOptuzbu(char** lista, int n)
{
	for(int i=0; i<n; i++)
	{
		if(lista[i]==nullptr) continue;
		else cout<<lista[i]<<endl;
	}
}

void deal(char** &lista, int vel)
{
	for(int i=0; i<vel; i++) delete [] lista[i];
	delete [] lista;
}

int main ()
{
	int vel;
	cout<<"Koliko potencijalnih krivaca zelite unijeti? ";
	cin>>vel;
	cout<<endl;
	vector<string> s(vel);
	cout<<"Unesite potencijalne krivce: "<<endl;
	for(int i=0; i<s.size(); i++) cin>>s[i];
	char **lista=nullptr;
	try
	{
		vel=PotencijalniKrivci(lista,s);
		for(;;)
		{
			cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: "<<endl;
			int n; 
			cin>>n;
			if(n==0) break;
			if(n==1)
			{
				cout<<"Unesite ime novog optuzenog: "<<endl;
				string s1;
				cin>>s1;
				try
				{
					vel=DodajOptuzbu(lista,vel,s1);
				}
				catch(...) { cout<<"Nema dovoljno memorije";}
			}
			if(n==2)
			{
				string s1;
				cout<<"Unesite ime koje zelite izbaciti: "<<endl;
				cin>>s1;
				try
				{
					vel=OdbaciOptuzbu(lista,vel,s1);
				}
				catch(domain_error izuz) {cout<<izuz.what();}
			}
			if(n==3) IzlistajOptuzbu(lista,vel);
		}
		deal(lista,vel);
		return 0;
	} catch(...) { cout<<"Nema dovoljno memorije";}
}