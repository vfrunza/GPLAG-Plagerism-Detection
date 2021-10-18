/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <cstring>
using std::cout;
using std::cin;
using std::vector;
using std::string;
int PotencijalniKrivci(char **&ref,vector<string> vek)
{
int brojac(0);
//ref=nullptr;
	try
	{
		char **studenti(new char*[vek.size()]);
		ref=studenti;
		for(int i=0;i<vek.size();i++)
		{
		studenti[i]=nullptr;
		}
		try
		{
			for(int i=0;i<vek.size();i++)
			{
			studenti[i]=new char[vek[i].size()+1];
			brojac++;
			std::strcpy(studenti[i],vek[i].c_str());
			}
		}
		catch(std::bad_alloc)
		{
			for(int i=0;i<vek.size();i++)
			{
				delete[] studenti[i];
			}
			delete[] studenti;
			return brojac;
		}
	ref=studenti;
	return brojac;
	}
	catch(std::bad_alloc)
	{
		return brojac;
	}

return brojac;
}
int OdbaciOptuzbu(char **&ref,int vel,string ime)
{
	int broj(vel);
	bool da_ne(false);
	for(int i=0;i<vel;i++)
	{
	if(ref[i]==ime)
	{
		delete[] ref[i];
		ref[i]=nullptr;
		da_ne=true;
	}
	}
	if(!da_ne)
	{
	string rec1{"Osoba sa imenom "};
	string rec2{" nije bila optuzena"};
	rec1+=ime;
	rec1+=rec2;
	throw std::domain_error(rec1);
	}
	int brojacnull(0);
	for(int i=0;i<vel;i++)
	{
		if(ref[i]==nullptr)
		brojacnull++;
	}
	if(brojacnull<=10)
	return broj;
	if(brojacnull>10)
	{
		char **stud;
		try
		{
			stud=new char*[broj-brojacnull];
			for(int i=0;i<broj-brojacnull;i++)
			stud[i]=nullptr;
			try
			{
				int brojac(0);
				for(int i=0;i<broj;i++)
				{
					string koristan;
					if(ref[i]!=nullptr)
					{
					koristan=ref[i];
					stud[i-brojac]=new char[koristan.size()+1];
					stud[i-brojac]=ref[i];
					}
					else
					brojac++;
				}
			}
			catch(std::bad_alloc)
			{
				for(int i=0;i<broj-brojacnull;i++)
				delete[] stud[i];
				delete[] stud;
			}
		}
		catch(std::bad_alloc)
		{
			return broj;
		}
		for(int i=0;i<broj;i++)
		delete[] ref[i];
		delete[] ref;
		ref=stud;
	}
	return (broj-brojacnull);
}
int DodajOptuzbu(char **&ref,int vel,string ime)
{
	char *pok;
	try
	{
		pok=new char[ime.size()+1];
		std::strcpy(pok,ime.c_str());
	}
	catch(...)
	{
		throw std::bad_alloc();
	}
	for(int i=0;i<vel;i++)
	{
		if(ref[i]==nullptr)
		{
		std::strcpy(ref[i],pok);
		return vel;
		}
	}
	try
{
	char **studenti=new char*[vel+1];
	for(int i=0;i<vel+1;i++)
	studenti[i]=nullptr;
	vector<string> svi;
	for(int i=0;i<vel;i++)
	{
		svi.push_back(ref[i]);
	}
	try
	{
		for(int i=0;i<vel+1;i++)
		{
			if(i==vel)
			{
			studenti[i]=new char[ime.size()+1];
			std::strcpy(studenti[i],ime.c_str());
			}
			else
			{
			studenti[i]=new char[svi[i].size()+1];
			std::strcpy(studenti[i],svi[i].c_str());
			}
		}
	for(int i=0;i<vel;i++)
	delete[] ref[i];
	delete[] ref;
	ref=studenti;
	}
	catch(std::bad_alloc)
	{
		delete[] pok;
			for(int i=0;i<(vel+1);i++)
			{
				delete[] studenti[i];
			}
			delete[] studenti;
			throw std::bad_alloc();
	}
}
	catch(std::bad_alloc)
	{
		delete[] pok;
		throw std::bad_alloc();
	}
vel+=1;
delete[] pok;
return vel;
}
void IzlistajOptuzbu(char **ref,int vel)
{
	for(int i=0;i<vel;i++)
	{
		if(ref[i]!=nullptr)
		{
			cout<<ref[i]<<std::endl;
		}
	}
}
int main ()
{
int vel;
cout<<"Koliko potencijalnih krivaca zelite unijeti? "<<std::endl;
cin>>vel;
cout<<"Unesite potencijalne krivce: "<<std::endl;
vector<string> imena;
cin.ignore(1000,'\n');
for(int i=0;i<vel;i++)
{
	string ime;
	std::getline(cin,ime);
	imena.push_back(ime);
}
char **ref;
vel=PotencijalniKrivci(ref,imena);
int nvel=vel;
while(true)
{
	int opcija;
	cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: "<<std::endl;
	cin>>opcija;
	cin.ignore(10000,'\n');
	if(opcija==0)
	{
	for(int i=0;i<nvel;i++)	
	delete[] ref[i];
	delete[] ref;
	break;
	}
	if(opcija==1)
	{
		string novi;
		cout<<"Unesite ime novog optuzenog: "<<std::endl;
		std::getline(cin,novi);
		nvel=DodajOptuzbu(ref,nvel,novi);
	}
	if(opcija==2)
	{
		string brisi;
		cout<<"Unesite ime koje zelite izbaciti: "<<std::endl;
		std::getline(cin,brisi);
		nvel=OdbaciOptuzbu(ref,nvel,brisi);
	}
	if(opcija==3)
	{
	    IzlistajOptuzbu(ref,nvel);
	}
}
	return 0;
}