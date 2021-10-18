/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <stdexcept>

using namespace std;



int PotencijalniKrivci(char **&k,vector<string>s)
{
	char **pok;
	
	pok=new char *[s.size()];
	
	for(int i=0;i<s.size();i++)
		pok[i]=new char [s[i].size()+1];
		
	for(int i=0;i<s.size();i++)
	{
		for(int j=0;j<s[i].size();j++)
			{
				pok[i][j]=s[i][j];
			}
		pok[i][s[i].size()]='\0';
	}
	
		
	
	k=pok;
	return s.size();
}

int Alociraj(char **&k,int br,int count)
{
	char **pok=new char*[br-count];
		
		int cn=0;
		for(int i=0;i<br;i++)
		{
			if(k[i]!=nullptr){
				pok[cn]=k[i];
				cn++;
			}
		}
	delete []k;
	k=pok;
	return br-count;
	
}

bool ProvjeriString(char *p,string s)
{    
	char *pom;int i;
	for(i=0,pom=p;i<s.size() || *pom!='\0';i++,pom++)
	{
		if(s[i]!=*pom) return false;
	}
	return true;
}


int OdbaciOptuzbu(char **&k,int br,string s)
{	
 	bool ima=false;
 	
 	for(int i=0;i<br;i++)
 	{
 	 	if(ProvjeriString(k[i],s))
 			ima=true;
 	}
 	if(!ima) throw domain_error("Osoba sa imenom "+s+" nije bila optuzena");
 	
	for(int i=0;i<br;i++)
	{   
		int j=0;
		bool postoji=true;
		
		while(*k[i]!='\0')
		{	
			if(*k[i]!=s[j]) postoji=false;
			j++;
			k[i]++;
		}
		k[i]-=j;
		
		if(postoji==true)
		{   
			delete [] k[i];
			k[i]=nullptr;
			int count=0;
			for(int p=0;p<br;p++)
				if (k[p]==nullptr) count++;
			if(count>10)
				br=Alociraj(k,br,count);
			
			
		}
		
		
	}
	
	 
	
	
	return br;
}

void Dealociraj(char **&k,int br)
{
	if(k==nullptr) return;
	
	for(int i=0;i<br;i++)
	delete [] k[i];
	delete [] k;
	k=nullptr;
	
}
int Alociraj(char **&k,int br,char *pok)
{
	char **p=new char*[br+1];
    
    for(int i=0;i<br;i++)
    {
    	p[i]=k[i];
    }
    p[br]=pok;
    delete [] k;
    k=p;

    return br+1;
}



int DodajOptuzbu(char **&k,int br,string s)
{
	
	char *pok=new char [s.size()+1];
	for(int i=0;i<s.size();i++)
		pok[i]=s[i];
	pok[s.size()]='\0';
	
	for(int i=0;i<br;i++)
	{   
		if(k[i]==nullptr){
			k[i]=pok;
		return br;
		}
	}
	
	br=Alociraj(k,br,pok);

	return br;

}



void IzlistajOptuzbu(char **k,int br)
{   

	for(int i=0;i<br;i++)
	{	int count=0;
		if(k[i]==nullptr)continue;
		while(*k[i]!='\0')
		{
			cout<<*k[i];
			k[i]++;
			count++;
		}
		cout<<endl;
		k[i]-=count;
	}
}

int main ()
{  
	cout<<"Koliko potencijalnih krivaca zelite unijeti? "<<endl;
	int n;
	cin>>n;
	
	cout<<"Unesite potencijalne krivce: "<<endl;
	vector<string> s(n);
	for(int i=0;i<s.size();i++)
		cin>>s[i];
	
	char **k=nullptr;
	

	int br=PotencijalniKrivci(k,s);
	
	

		while(1)
		{
			cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: "<<endl;
			cin>>n;
			if(n==0) break;
			string s;
			switch(n){
				case 1:cout<<"Unesite ime novog optuzenog: "<<endl;cin>>s;br=DodajOptuzbu(k,br,s);break;		
			
				case 2:
					   cout<<"Unesite ime koje zelite izbaciti: "<<endl;
					   cin>>s;
				try
				{
					br=OdbaciOptuzbu(k,br,s);break;
					
				}
				catch(domain_error e) {cout<<e.what();}
			
				case 3:IzlistajOptuzbu(k,br);break;
			}
		}
		Dealociraj(k,br);

	
	return 0;
}