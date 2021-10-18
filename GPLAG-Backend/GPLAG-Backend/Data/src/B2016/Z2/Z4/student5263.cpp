/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::domain_error;
using std::getline;

int PotencijalniKrivci (char **& pok_na_znak, vector<string> v){
	char **pok(nullptr);
	pok=new char* [v.size()];
	for(int i=0;i<v.size();i++){
		pok[i]=nullptr;
	}
	try{
		for(int i=0;i<v.size();i++){
			pok[i]=new char[v[i].size()+1];
		}
		for(int i=0;i<v.size();i++){
			strcpy(pok[i],v[i].c_str());
		}
		pok_na_znak=pok;
		return v.size();
	}
	catch(...){
		for(int i=0;i<v.size();i++){
			delete [] pok[i];
		}
		delete [] pok;
		throw;
	}
}
int OdbaciOptuzbu (char **& pok_na_znak, int n, string s){
	bool ima(false);
	for(int i=0;i<n;i++){
		if(strcmp(pok_na_znak[i],s.c_str())==0){
			ima=true;
			delete [] pok_na_znak[i];
			pok_na_znak[i]=nullptr;
		}
	}
	if (!ima) {
		string s1;
		s1="Osoba sa imenom " +s+" nije bila optuzena";
		throw domain_error (s1);
		
	}
	int br(0);
	for(int i=0;i<n;i++){
		if(pok_na_znak[i]==nullptr) br++;
	}
	if(br>10){
		char **pok(nullptr);
		pok=(new char* [n-br]);
		for(int i=0;i<(n-br);i++){
			pok[i]=nullptr;
		}
		try{
		for(int i=0;i<n;i++){
			if(pok_na_znak[i]!=nullptr){
				pok[i]=new char [strlen(pok_na_znak[i])+1];
			}
		}
		for(int i=0;i<n;i++){
			if(pok_na_znak[i]!=nullptr){
				strcpy(pok[i],pok_na_znak[i]);
			}
		}
		for(int i=0;i<n;i++){
			delete [] pok_na_znak[i];
		}delete[] pok_na_znak;
		pok_na_znak=pok;
		return n-br;
	}
	catch(...){
		for(int i=0;i<(n-br);i++){
			delete [] pok[i];
		}
		delete [] pok;
		throw ;
	}
	}
	return n;
}
int DodajOptuzbu (char **& pok_na_znak, int n, string s){
	bool nemamjesta(true);
	char **pok(nullptr);
	char* novi (nullptr);
	novi= new char[s.size()+1];
	strcpy(novi,s.c_str());
	try{
	for(int i=0;i<n;i++){
		if(pok_na_znak[i]==nullptr){
			nemamjesta=false;
			pok_na_znak[i]=new char[s.size()+1];
			strcpy(pok_na_znak[i],novi);
			break;
		}
	}
	if(nemamjesta){
		pok=(new char* [n+1]);
		for(int i=0;i<n;i++){
		pok[i]=nullptr;
		}
		for(int i=0;i<n;i++){
			pok[i]=new char[strlen(pok_na_znak[i])+1];
		}
		for(int i=0;i<n;i++){
			strcpy(pok[i],pok_na_znak[i]);
		}
		pok[n]=novi;
		for(int i=0;i<n;i++){
			delete [] pok_na_znak[i];
		} delete[] pok_na_znak;
		pok_na_znak=pok;
		return n+1;
	}
	return n;
	}
	catch(...){
		for(int i=0;i<n;i++){
		delete [] pok[i];
		}
		delete[] pok;
		throw;
	}
}
void IzlistajOptuzbu (char ** pok_na_znak, int n){
	for(int i=0;i<n;i++){
		if(pok_na_znak[i]==nullptr) continue;
		else{
			char* q;
			q=pok_na_znak[i];
			while(*q!='\0'){
				cout<<*q;
				q++;
			}
			cout<<endl;
		}
	}
}
int main ()
{
	cout<<"Koliko potencijalnih krivaca zelite unijeti? "<<endl;
	int n;
	cin>>n;
	cin.ignore(1000, '\n');
	try{
		vector<string> Krivi (n);
		cout<<"Unesite potencijalne krivce: "<<endl;
		for(int i=0;i<n;i++){
			getline(cin, Krivi[i]);
		}
		char** Optuzeni;
		char**& NizOptuzenih(Optuzeni);
		try{
			n= PotencijalniKrivci(NizOptuzenih,Krivi);
			while(1){
				cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: "<<endl;
				int x;
				cin>>x;
				cin.ignore(10000,'\n');
				if (x==0) break;
				if(x==2){
					cout<<"Unesite ime koje zelite izbaciti: "<<endl;
					string s;
					getline(cin,s);
					try{
						n=OdbaciOptuzbu(NizOptuzenih,n,s);
					}
					catch(domain_error izuzetak){
						cout<<izuzetak.what();
					}
				}
				if (x==1){
					cout<<"Unesite ime novog optuzenog: "<<endl;
					string s1;
					getline(cin,s1);
					try{
						n=DodajOptuzbu(NizOptuzenih,n,s1);
					}
					catch(...){
						cout<<"Dodavanje nije uspjelo";
					}
				}
				if (x==3)
				IzlistajOptuzbu(NizOptuzenih,n);
			}
			for(int i=0;i<n;i++){
				delete [] Optuzeni[i];
			}
			delete[] Optuzeni;
		}
		catch(...){
		throw;
		}
	}
	catch(...){
		cout<<"Greska";
	}
	return 0;
}