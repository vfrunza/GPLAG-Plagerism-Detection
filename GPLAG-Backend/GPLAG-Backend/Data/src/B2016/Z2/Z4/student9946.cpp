/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <stdexcept>

using namespace std;

int PotencijalniKrivci(char** &p, vector<string> imena)
{
	try
	{
		p = new char *[imena.size()];
		try{
		for(int i = 0; i < imena.size(); i++)
		{
			p[i] = new char[imena[i].length() + 1];
		}
		
		for(int i = 0; i < imena.size(); i++)
		{
			strcpy(p[i], imena[i].c_str());
		}
		}catch(...){
				for(int i = 0; i < imena.size(); i++)
					delete[] p[i];
		
				delete[] p;
				throw bad_alloc();
		}
	}
	catch(bad_alloc())
	{
		abort();
	}
	
	return imena.size();
}

int OdbaciOptuzbu(char** &p, int velicina, string ime)
{
	try
	{
			int pozicija = -1;
			for(int i = 0 ; i < velicina; i++)
			{
				if(p[i]==nullptr)continue;
				if(strcmp(p[i], ime.c_str()) == 0) 
				{
					pozicija = i;
					delete[] p[pozicija];
					p[pozicija] = nullptr;
				}	
			}
			
					int brojac = 0;
					for(int i = 0; i < velicina; i++)
					{
						if(p[i] == nullptr) brojac++;
					}
					
					
					if(brojac > 10)
					{
						try {
						int brojac_novi = 0;
						char **novi = new char*[velicina-brojac];
						for(int i = 0; i < velicina; i++)
						{
							if(p[i] != nullptr)
							{
								novi[brojac_novi] = p[i];
								brojac_novi++;
							}
						}
						delete[] p;
						p = novi;
						velicina -= brojac;
						}catch(...){}
					}
	
			if(pozicija == -1)
				throw domain_error("");
		
	}
	catch (...)
	{
		cout << "Osoba sa imenom " + ime + " nije bila optuzena" << endl;
	}
	
	return velicina;
}

int DodajOptuzbu(char** &p, int velicina, string ime)
{
	try
	{
		int pozicija = -1;
		char *pointer = new char[ime.length()+1];
		strcpy(pointer, ime.c_str());
		for(int i = velicina-1; i > 0; i--)
		{
			if(p[i] == nullptr) 
			{
				pozicija = i ;
			}
		}
		if(pozicija != -1)
		{
			p[pozicija] = new char[ime.length()-1];
			strcpy(p[pozicija], ime.c_str());
			velicina++;
		}
		else 
		{
			char **novi=new char*[velicina+1];
			int i=0;
			for( i=0;i<velicina;i++){
				novi[i]=p[i];
			}
			novi[i]=pointer;
			velicina++;
			delete[] p;
			p=novi;
		}
	}
	catch(...)
	{
		abort();
	}
	return velicina;
}

void IzlistajOptuzbu(char** &p, int velicina)
{
	for(int i = 0; i < velicina; i++)
	{
		int j = 0;
		while( p[i] != nullptr  && p[i][j] != '\0')
		{
			cout << p[i][j];
			j++;
		
		}
		if(p[i] != nullptr) cout << endl;
	}
}

int main ()
{
	char **p;
	vector<string> skup_imena;
	int broj_krivaca;
	cout << "Koliko potencijalnih krivaca zelite unijeti? " << endl;
	cin >> broj_krivaca;
	
	cout << "Unesite potencijalne krivce: " << endl;
	for(int i = 0; i < broj_krivaca; i++)
	{
		string ime; 
		cin >> ime;
		skup_imena.push_back(ime);
	}
	
	broj_krivaca = PotencijalniKrivci(p, skup_imena);
	
	int komanda;
	
	do
	{
		cout << "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: " << endl;
		cin >> komanda;
		switch(komanda)
		{
			case 1:
				{
				cout << "Unesite ime novog optuzenog: " << endl;
				string novo_ime;
				cin >> novo_ime;
				
				broj_krivaca = DodajOptuzbu(p, broj_krivaca, novo_ime);
				}
				break;
			
			case 2:
				{
				cout << "Unesite ime koje zelite izbaciti: " << endl;
				string nov_ime;
				cin >> nov_ime;
				
				broj_krivaca = OdbaciOptuzbu(p, broj_krivaca, nov_ime);
				}
				break;
				
			case 3:
				{
				IzlistajOptuzbu(p, broj_krivaca);
				}
				break;
		}
	}while(komanda > 0 && komanda < 4);
	
	for(int i = 0; i < broj_krivaca; i++)
		delete[] p[i];
		
	delete[] p;
	
	return 0;
}