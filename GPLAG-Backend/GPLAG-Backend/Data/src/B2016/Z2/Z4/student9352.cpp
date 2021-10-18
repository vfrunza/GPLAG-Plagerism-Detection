/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/

#include <iostream>
#include <vector>
#include <stdexcept>
#include <cstring>
#include <new>

using namespace std;

//Vrati broj alociranih nizova znakova
int PotencijalniKrivci(char** &alocirano, vector<string> spisakImena)
{
	int brojPrepisivaca{int(spisakImena.size())};
	if(brojPrepisivaca==0)
	{
		alocirano = nullptr;
		return 0;
	}
	try {
		alocirano = new char*[brojPrepisivaca];
		for(int i=0;i<brojPrepisivaca;i++)
		{
			alocirano[i] = nullptr;
			alocirano[i] = new char[spisakImena[i].size()+1];
			strcpy( alocirano[i] , spisakImena[i].c_str() );
		}
	}
	catch(bad_alloc)
	{
		for(int i=0; i<brojPrepisivaca;i++)  delete[] alocirano[i];
		delete[] alocirano;
		throw;
	}
	
	return brojPrepisivaca;
}


//Vrati novu velicinu niza pokazivaca, koja moze biti jednaka staroj
int OdbaciOptuzbu(char** &alocirano, int vel, string posteni)
{
	int novaVelicina{vel};
	int brojIzbrisanih{0};
	
	for(int i=0; i<vel;i++)
	{
		if(alocirano[i]==nullptr)
		{
			brojIzbrisanih++;
		}
	}
	for(int i=0;i<vel;i++)
	{
		if(alocirano[i] && alocirano[i]==posteni)
		{
			delete[] alocirano[i];
			alocirano[i] = nullptr;
			brojIzbrisanih++;
			novaVelicina=vel;
			break;
		}
	}
	
	if(brojIzbrisanih>10)
	{
		try {
			char **noviNizPokazivaca = new char*[vel - brojIzbrisanih];
			for(int i=0;i<vel-brojIzbrisanih;)
			{
				for(int j=0;j<vel;j++)
				{
					if(alocirano[j] != nullptr){
						noviNizPokazivaca[i] = alocirano[i];
						i++;
						alocirano[j]=nullptr;
					}
				}
			}
			delete[] alocirano;
			alocirano = noviNizPokazivaca;
			novaVelicina = vel - brojIzbrisanih;
		}
		catch(bad_alloc) {}
	}
	
	return novaVelicina;
}

//Vrati novu velicinu niza pokazivaca, koja moze biti jednaka staroj
int DodajOptuzbu(char** &alocirano, int vel, string krivac)
{
	int novaVel{vel};
	char* noviZnakovi = new char[krivac.size()+1] ;
	strcpy(noviZnakovi,krivac.c_str());
	
	bool nadjenNulPokazivac{false};
	
	for(int i=0;i<vel;i++)
	{
		if(alocirano[i]==nullptr)
		{
			alocirano[i] = noviZnakovi;
			nadjenNulPokazivac = true;
			break;
		}
	}
	
	//ako je bio nadjen nul-pokazivac nismo mijenjali velicinu
	if(nadjenNulPokazivac)  return vel;
	
	//u suprotnom alociramo novi niz pokazivaca i tu smjestimo stare i novog krivca
	try
	{
		char** noviNizPokazivaca{ new char*[vel+1] };
		int i{0};
		for(;i<vel;i++)
		{
			noviNizPokazivaca[i] = nullptr;
			noviNizPokazivaca[i] = new char[strlen(alocirano[i])+1];
			strcpy(noviNizPokazivaca[i] , alocirano[i]);
		}
		noviNizPokazivaca[i] = noviZnakovi;
		//delete[] alocirano;
		for(int r=0;r<vel;r++)
		{
			delete[] alocirano[r];
		}
		alocirano = noviNizPokazivaca;
		/*for(int r=0;r<vel+1;r++)
		{
			alocirano[r]=nullptr;
			alocirano[r] = new char[strlen(noviNizPokazivaca[r])+1];
			strcpy(alocirano[r],noviNizPokazivaca[r]);
		}*/
		for(int f=0;f<vel+1;f++)
		{
			delete[] noviNizPokazivaca[f];
		}
		delete[] noviNizPokazivaca;
		novaVel = vel+1;
	}
	catch(bad_alloc) {}
	
	return novaVel;
}

void IzlistajOptuzbu(char** alocirano, int vel)
{
	for(int i=0;i<vel;i++)
	{
		if(alocirano[i])  cout<< alocirano[i] << endl;
	}
}



int main ()
{
	char **pok{nullptr};
	int broj;
	
	cout<<"Koliko potencijalnih krivaca zelite unijeti?"<<endl;
	cin>>broj;
	
	pok = new char*[broj];
	
	vector<string> krivci;
	krivci.resize(broj);
	
	cout<<"Unesite potencijalne krivce: "<<endl;
	for(int i=0;i<broj;i++)
	{
		cin>>krivci[i];
	}
	
	try {
	
	PotencijalniKrivci(pok,krivci);
	
	int opcija{0};
	do{
		
		cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog "
			<<"3 za izlistavanje optuzenih, 0 za kraj:"<<endl;
		cin>>opcija;
		cin.clear();
		cin.ignore(10000,'\n');
		string noviOptuzeni, odjednomPosten;
		if(opcija==1)
		{
			cout<<"Unesite ime novog optuzenog:"<<endl;
			cin>>noviOptuzeni;
			cin.clear();
			cin.ignore(10000,'\n');
			broj = DodajOptuzbu(pok, broj, noviOptuzeni);
			IzlistajOptuzbu(pok,broj);
		}
		else if(opcija==2)
		{
			cout<<"Unesite ime koje zelite izbaciti:"<<endl;
			cin>>odjednomPosten;
			cin.clear();
			cin.ignore(10000,'\n');
			broj = OdbaciOptuzbu(pok, broj, odjednomPosten);
			IzlistajOptuzbu(pok,broj);
		}
		else if(opcija==3)
		{
			IzlistajOptuzbu(pok,broj);
		}
	}while(opcija!=0);
	
	//for(int i=0;i<broj;i++)   delete[] pok[i];
	//delete[] pok;
	
	}
	catch(bad_alloc e)
	{
		cout<<e.what()<<endl;
	}
	
	return 0;
}