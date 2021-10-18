/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/

#include <iostream>
#include <cmath>
#include <new>
#include <stdexcept>
#include <string>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <type_traits>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;


int PotencijalniKrivci (char **&pok, vector<string> s) {
	int broj(0);
	
	pok=new char*[s.size()];
	for(int i=0; i<s.size(); i++) pok[i]=nullptr;
	try {
	for(int i=0; i<s.size(); i++) {
		pok[i]=new char[s[i].size()+1];
		broj++;
	}

	for(int i=0; i<s.size(); i++) {
		for(int j=0; j<s[i].size(); j++) {
			
			pok[i][j]=s[i][j]; 
			if(j==s[i].size()-1) pok[i][j+1]='\0';
			
		}
	}
	
	}
	catch (std::bad_alloc) {
		for(int i=0; i<s.size(); i++) delete[] pok[i];
		delete[]pok;
		throw;
	}
	return broj;
}

int OdbaciOptuzbu (char **&pok, int vel, string s) {
	
	int broj(0);
	for(int i=0; i<vel; i++) { 
		int j(0),br(0);
		char *p=pok[i];
		while(j<s.size()) { 
			if(*p==s[j] )br++;
			p++;
			j++;
		} 
	
	
		if(br==s.size() && isalpha(*(p))==false ) {
			delete[]pok[i];
			pok[i]=nullptr;
			broj++;
		}
	
	}
	
	if(broj==0) throw std::domain_error ("Osoba sa imenom "+s+" nije bila optuzena");
	if(broj>10) {
		
		char **novi=new char*[vel-broj];
		try{
		for(int i=0; i<vel; i++) {
			if(pok[i]!=nullptr)novi[i]=pok[i];
		}
		}
		catch(...) {
			for(int i=0; i<vel-broj; i++) delete[] novi[i];
			delete[]novi;
		}
		
	}
	
	
	

	return vel;
}

int DodajOptuzbu(char **&pok, int vel, string s){

	int br(0);
	
	char*novi=new char[s.size()+1];
	try {
	 for(int i=0; i<s.size()+1; i++) {
	 	novi[i]=s[i];
	 }
	
	for(int i=0; i<vel; i++) { 
		if(pok[i]==nullptr) { 
			pok[i]=novi;
			br++;
		}
	}
	if(br==0) {
		
		char **n=new char*[vel+1];
		for(int i=0; i<vel; i++) 
			n[i]=pok[i];
		n[vel]=novi;
		
		
		delete[] pok;
		pok=n;
		
	vel++;
	}
	}
	catch (...) {
		
		delete[]novi;
		throw;
	}

	return vel;

}


void IzlistajOptuzbu (char **pok, int vel ){

	for(int i=0; i<vel; i++) {
		if(pok[i] !=nullptr)cout<<pok[i];
		cout<<endl;
	}
}

int main ()
{
	
	cout<<"Koliko potencijalnih krivaca zelite unijeti? \n";
	int n;
	cin>>n;
	
	cout<<"Unesite potencijalne krivce: ";
	char **niz=nullptr;
	vector<string> imena;
	string s;
	cin.ignore(1000,'\n');
	do {
		getline(cin,s);
		imena.push_back(s);
		n--;
	} while(n!=0);
	int opcija;
	
		
	int velicina=PotencijalniKrivci(niz,imena);
	do {
	cout<<endl<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: \n";
	cin>>opcija;
	try {
	if(opcija==1) {
		string optuzeni;
		cout<<"Unesite ime novog optuzenog: ";
		cin.ignore(1000,'\n');
		getline(cin,optuzeni);
		velicina=DodajOptuzbu(niz,velicina,optuzeni);
	}
	if(opcija==2) {
		cout<<"Unesite ime koje zelite izbaciti: ";
		cin.ignore(1000,'\n');
		string izbaci;
		getline(cin,izbaci);
		velicina=OdbaciOptuzbu(niz,velicina,izbaci);
		
	}
	
	if(opcija==3) 	IzlistajOptuzbu(niz,velicina);
	
	
		}
	catch(std::bad_alloc) {
		for(int i=0; i<velicina; i++) delete[] niz[i];
		delete[]niz;
	}
	catch(std::domain_error i) {
	cout<<i.what()<<endl;
	}
	
	} while(opcija!=0);
	for(int i=0; i<velicina; i++) delete[] niz[i];
	delete[]niz;

	return 0;
}



