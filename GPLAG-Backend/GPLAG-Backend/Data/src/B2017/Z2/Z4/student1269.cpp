/*B 2017/2018, Zadaća 2, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <new>
#include <vector>
#include <string>
#include <stdexcept>

using std:: cout;
using std:: vector;
using std:: cin;
using std:: endl;
using std:: string;


int PotencijalniKrivci(char **&znakovi, vector<string> imena)
{
	
	int br_imena=imena.size();
	char **pok;
	try 
	{
		pok=new char*[br_imena]{}; //svi su na nullptr
		for(int i=0; i<br_imena; i++)
		{
			pok[i]=new char[imena[i].size()+1];
			int j=0;
			for(j=0; j<imena[i].size(); j++)
			{
				pok[i][j]=imena[i][j];
			}
			pok[i][j]='\0';
		}
		znakovi=pok;
		return br_imena;
	}
	
	catch(...)
	{
		for(int i=0; i<br_imena; i++)
		{
			delete [] pok[i]; //delete ignorise nullptr
			
		}
		delete [] pok;
		throw std:: bad_alloc();
	}
}

int OdbaciOptuzbu (char **&znakovi, int br_imena, string ime)
{
	int brojac=0;
	for(int i=0; i<br_imena; i++)
	{
		if(znakovi[i]==nullptr) brojac++;
	}
	
	
	vector<string>svi_optuzeni;
	for(int i=0; i<br_imena; i++)
	{
		string neko="";
		for(int j=0; j<ime.size(); j++)
		{
			neko+=znakovi[i][j];
		}
		svi_optuzeni.push_back(neko);
	}
	int nijeistoime=0;
	for(int i=0; i<svi_optuzeni.size(); i++)
	{
		if(svi_optuzeni[i]!=ime) nijeistoime++;
	}
	if(nijeistoime==svi_optuzeni.size()) 
		{
			throw std:: domain_error("Osoba sa imenom "+ime+" nije bila optuzena");
		}
		
	for(int i=0; i<br_imena; i++)
	{
		string n = "";
		for(int j=0;j<ime.size();j++)
			n+= znakovi[i][j];
			
	
		if(n==ime) 
		{
			delete [] znakovi[i];
			znakovi[i]=nullptr;
			brojac++;
			if(brojac<10) return br_imena;
			else 
			{
				char **novi;
				novi = new char*[br_imena-brojac]{};
				int indeks=0;
				for(int j=0; j<br_imena ; j++)
				{
					if(znakovi[j]!=nullptr)
					{
						novi[indeks] = znakovi[j];
						indeks++;
					}
				}
				delete[] znakovi;
				znakovi = novi;
				return br_imena-brojac;
			}
		}
	}
		
	return br_imena;
}

int DodajOptuzbu(char **&znakovi, int br_imena, string ime)
{
	char* novi = nullptr;
	char** noviNiz = nullptr;
	try 
	{
		novi= new char[ime.length()+1];
		int i=0;
		for(i=0; i<ime.length(); i++)
		{
			novi[i]=ime[i];
		}
		novi[ime.length()]='\0';
	//	cout<<novi<<endl;
		for(i=0; i<br_imena; i++)
		{
			if(znakovi[i]==nullptr)
			{
				znakovi[i]=novi;
				return br_imena;
			}
		}
		noviNiz=new char* [br_imena+1]{};
		for(i=0; i<br_imena; i++)
		{
			noviNiz[i]=znakovi[i];
		}
		noviNiz[i]=novi;
		delete [] znakovi;
		znakovi=noviNiz;
		return br_imena+1;
	}
	catch(...)
	{
		delete[] novi;
		delete[] noviNiz;
		throw std::bad_alloc();
	}
}

void IzlistajOptuzbu(char **znakovi, int br_imena)
{
	for(int i=0; i<br_imena; i++)
	{
		if(znakovi[i]!=nullptr) cout<<znakovi[i]<<endl;
	}
}

int main ()
{
	cout<<"Koliko potencijalnih krivaca zelite unijeti?"<<endl;
	int br_krivaca;
	cin>>br_krivaca;
	vector<string> krivci;
	char** listakrivaca;
	string krivac;
	cout<<"Unesite potencijalne krivce: "<<endl;
	for(int i=0; i<br_krivaca; i++)
	{
		cin>>krivac; 
		krivci.push_back(krivac);
	}
	int vel = PotencijalniKrivci(listakrivaca, krivci);
	int opcija;
	while(1)
	{
		cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: "<<endl;
		cin>>opcija;
		if(opcija==0)
		{
			for(int i=0;i<vel;i++)
				delete[] listakrivaca[i];
			delete[] listakrivaca;
			return 0;
		}
		if(opcija==1) 
		{
			string ime1;
			cout<<"Unesite ime novog optuzenog: "<<endl;
			cin>>ime1;
			vel = DodajOptuzbu(listakrivaca, vel, ime1);
		}
		if(opcija==2) 
		{
			try 
			{
				string ime;
				cout<<"Unesite ime koje zelite izbaciti: "<<endl; 
				cin>>ime; 
				vel = OdbaciOptuzbu(listakrivaca, vel, ime);
			}
			catch(std:: domain_error izuzetak)
			{
				cout<<izuzetak.what()<<endl;
			}
			
		}
		if(opcija==3)
		{
			IzlistajOptuzbu(listakrivaca, vel);
		}
	}
	return 0;
}
