#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <deque>
#include <algorithm>
#include <cstring>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::deque;
int PotencijalniKrivci(char **&p, vector<string> V)
{
	p=nullptr;
	if(V.size()==0)	return 0;
	p=new char *[V.size()];
	try {
		
		for(int i=0; i<V.size(); i++) {
			p[i]=nullptr;
		}
		for(int i=0; i<V.size(); i++) {
			p[i]=new char [V[i].size()+1];
		}
	} catch(std::bad_alloc) {
		for(int i=0; i<V.size(); i++) delete[] p[i];
		delete[] p;
		throw;
	}
	for(int i=0; i<V.size(); i++) {
		for(int j=0; j<V[i].size(); j++) {
			p[i][j]=V[i][j];
		}
		p[i][V[i].size()]='\0';
	}

	return V.size();
}
bool Provjera(char *c, string s)
{
	bool isti=true;
	int i;
	for( i=0; i<s.size(); i++) {
		if(c[i]=='\0') {
			isti=false;
			break;
		}
		if(c[i]!=s[i])
			isti=false;
	}
	if(c[i]!='\0')
		isti=false;
	return isti;
}
int Velicina(char *c)
{
	int vel {1};
	while(*c++!='\0')
		vel++;
	return vel;
}
int OdbaciOptuzbu(char **&c, int vel, string s)
{
	bool provjera=false;

	for(int i=0; i<vel; i++) {
		if(c[i]!=nullptr && (strcmp(s.c_str(),c[i]))==0) {
			delete[] c[i];
			c[i]=nullptr;
			provjera=true;
		}
	}
	if(!provjera) {
		string izuzetak{"Osoba sa imenom  nije bila optuzena"};
		izuzetak.insert(16,s);
		throw std::domain_error (izuzetak);
	}
	
	int br_nul {};
	for(int i=0; i<vel; i++) {
		if(c[i]==nullptr)
			br_nul++;
	}
	if(br_nul>10) {
		char **n=nullptr;
		try {
			int NovaVel {vel-br_nul};

			int j {};
			n=new char *[NovaVel];
			for(int i=0; i<NovaVel; i++) n[i]=nullptr;
			for(int i=0; i<vel; i++) {
				if(c[i]!=nullptr) {

					n[j]=c[i];
					j++;
				} else delete[] c[i];
			}
			delete[] c;
			c=n;
			return NovaVel;

		} catch(...) {
			delete [] n;
		}
	}
	return vel;
}
int DodajOptuzbu(char **&c, int vel, string s)
{
	char *p=nullptr;
	char **f=nullptr;
	f=c;
	p=new char [s.size()+1];
	for(int i=0; i<s.size(); i++) {
		p[i]=s[i];
	}
	p[s.size()]='\0';
	bool pronasao=false;
	for(int i=0; i<vel; i++) {
		if(f[i]==nullptr) {
			f[i]=p;
			pronasao=true;
			break;
		}
	}
	if(!pronasao) {
		char **n=nullptr;
		try {
			n=new char *[vel+1];
			for(int i=0; i<vel; i++) n[i]=f[i];
			n[vel]=p;
			delete[] c;
			c=n;
			vel++;
		} catch(std::bad_alloc) {
			delete []p;
			delete[] n;
			throw;
		}
	}
	return vel;
}
void IzlistajOptuzbu(char **c, int vel)
{
	for(int i=0; i<vel; i++) {
		if(c[i]==nullptr)
			continue;
		else if(i!=vel-1)cout<<c[i]<<endl;
		else cout<<c[i];
	}
}
int main ()
{
	try {
		vector<string>V ;
		char **p=nullptr;
		int br;
		int n;
		int opcija;
		cout<<"Koliko potencijalnih krivaca zelite unijeti? ";
		cin>>n;
		V.resize(n);
		std::cin.ignore(10000, '\n');
		if(n>0) std::cout<<endl<<"Unesite potencijalne krivce: ";
		for(int i=0; i<n; i++) {
			std::getline(std::cin, V[i]);

		}
		br=PotencijalniKrivci(p,V);
		string s;
		do {
			cout<<endl<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: "<<endl;
			cin>>opcija;
			if(opcija==1) {
				std::cin.clear();
				try {
					cout<<"Unesite ime novog optuzenog: ";
									std::cin.ignore(10000, '\n');

									std::getline(std::cin, s);

					br=DodajOptuzbu(p, br,s);
				} catch(std::bad_alloc) {
					cout<<"Nedovoljno memorije!";
				}
				
			}
			if(opcija==2) {
				cout<<"Unesite ime koje zelite izbaciti: ";
													std::cin.ignore(10000, '\n');

				std::getline(std::cin, s);
				try{
					br=OdbaciOptuzbu(p,br,s);
				}
				catch(std::domain_error e){
					cout<<e.what();
				}
			}
			if(opcija==3)
				IzlistajOptuzbu(p,br);
		} while(opcija!=0);
		for(int i=0; i<br; i++) delete[] p[i];
		delete[] p;
	} catch(std::bad_alloc) {
		cout<<"Nedovoljno memorije!";
	}
	return 0;
}