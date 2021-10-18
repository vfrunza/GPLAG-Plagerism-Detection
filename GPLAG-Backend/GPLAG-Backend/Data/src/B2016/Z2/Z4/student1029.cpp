/*B 16/17, Zadaća 2, Zadatak 4

	NAPOMENA: i javni ATo-vi su dio postavke

	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include<vector>
#include <string>
#include <new>
#include <stdexcept>
using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

int PotencijalniKrivci(char **&pok_na_znakove , vector<string> v)
{
	int br=v.size();
	char **pok=nullptr;
	int j=0;
	try {
		pok=new char*[br];
		for(int i=0; i<br; i++) pok[i]=nullptr;
		try {
			for(int i=0; i<br; i++) {
				pok[i]=new char [v[i].size()+1];
			}

			for(int i=0; i<v.size(); i++) {
				for(j=0; j<v[i].size(); j++) {
					pok[i][j]=v[i][j];
				}
				pok[i][j]='\0';
			}
			pok=pok_na_znakove;
			int broj_uspjesnih=v.size();
			return broj_uspjesnih;
		} catch(...) {
			for(int i=0; i<v.size(); i++) {
				delete[] pok[i];
			}
			throw;
		}
	} catch(...) {
		delete[] pok;
		throw std::bad_alloc();
	}
}

int OdbaciOptuzbu(char **&pok , int velicina_niza_pok, string ime)
{
	bool ima_imena=false;

	for(int i=0; i<velicina_niza_pok; i++) {
		string novo_ime="";
		for(int j=0; j<ime.size(); j++) novo_ime+=pok[i][j];
		if(novo_ime==ime) {
			ima_imena=true;
			break;
		}
	}

	if(ima_imena==false) throw std::domain_error("Osoba sa imenom *ime* nije na spisku");

	for(int i=0; i<velicina_niza_pok; i++) {
		string novo_ime="";
		for(int j=0; j<ime.size(); j++) novo_ime+=pok[i][j];
		if(novo_ime==ime) {
			delete[] pok[i];
			pok[i]=nullptr;
		}
	}

	int br(0);
	for(int i=0; i<velicina_niza_pok; i++) {
		if(pok[i]==nullptr) br++;
	}

	if(br<10) return velicina_niza_pok;
	if(br>10) {
		int novi_br=velicina_niza_pok-br;
		char **novi_pok=nullptr;
		novi_pok=new char *[novi_br];
		for(int i=0; i<novi_br; i++) {
			novi_pok[i]=nullptr;

			for(int i=0; i<velicina_niza_pok; i++) {
				int m(0);
				if(pok[i]!=nullptr) {
					novi_pok[m]=pok[i];
					m++;
				}
			}

			delete[] pok;
			pok=novi_pok;
			return novi_br;
		}
	}
}

int DodajOptuzbu(char **&pok, int velicina_niza_pok, string ime)
{
	char *novi_pok=nullptr;
	char **novi_pok2=nullptr; 
	try {
		novi_pok=new char [ime.size()+1];
		for(int i=0; i<ime.size(); i++) {
			novi_pok[i]=ime[i];
		}
		novi_pok[ime.size()]='\0';


		int brojac_nullptra(0);
		for(int i=0; i<velicina_niza_pok; i++) {
			if(pok[i]==nullptr) brojac_nullptra++;
		}

		if(brojac_nullptra!=0) {
			for(int i=0; i<velicina_niza_pok; i++) {
				if(pok[i]==nullptr) {
					pok[i]=novi_pok;
					return velicina_niza_pok;
				}
			}
		}

		if(brojac_nullptra==0) {
			novi_pok2=new char *[velicina_niza_pok+1];
			for(int i=0; i<velicina_niza_pok+1; i++) novi_pok2[i]=nullptr;

			for(int i=0; i<velicina_niza_pok; i++) {
				novi_pok2[i]=pok[i];
			}
			novi_pok2[velicina_niza_pok]=novi_pok;
			delete[] pok;
			pok=novi_pok2;
			return velicina_niza_pok+1;
		}
	} catch(...) {
		delete[] novi_pok;
		delete[] novi_pok2;
		throw std::bad_alloc();
	}
}

void IzlistajOptuzbu(char **pok, int velicina_niza_pok) {
	for(int i=0;i<velicina_niza_pok;i++) {
		if(pok[i]!=nullptr) {
		cout<<pok[i]<<endl;
		}
	}
}


int main ()
{
	int n;
	cout<<"Koliko potencijalnih krivaca zelite unijeti?"<<endl;
	cin>>n;

	vector<string> s(n);
	
	char **pok;
	
	cout<<"Unesite potencijalne krivce: "<<endl;
	for(int i=0;i<n;i++) {
		cin>>s[i];
	}
	

	return 0;
}