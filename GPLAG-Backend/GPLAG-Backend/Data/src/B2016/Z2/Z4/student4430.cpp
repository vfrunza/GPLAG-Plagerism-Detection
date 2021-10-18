/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include <vector>
#include <cstring>
#include <stdexcept>
#include <algorithm>
using namespace std; 
int PotencijalniKrivci(char **&znakovi, vector<string> krivci){
	char **niz=nullptr;
	int brojac=0; 
	try{
		niz=new char*[krivci.size()];
		try {
			for(int i=0; i<krivci.size(); i++){
			niz[i]=new char [krivci[i].size()+1]; 
			strcpy (niz[i],krivci[i].c_str()); 
			brojac++; 
			}
			znakovi=niz; 
		}
		catch(bad_alloc){
			for(int i=0; i<brojac; i++)
			delete [] niz[i]; 
			delete [] niz;  
			throw;  
		}
	}
	catch(bad_alloc){
		delete [] niz; 
		throw;  
	}
	return brojac; 
}
int OdbaciOptuzbu(char **&p, int velicina, string s){
	bool ima=false; 
	for(int i=0; i<velicina; i++){
		if(s==p[i]) ima=true; 
	}
	if(!ima){
		throw domain_error ("Osoba sa imenom "+s+" nije bila optuzena"); 
	}
	else{
		for(int i=0; i<velicina; i++){
			if(s==p[i]){
				delete [] p[i]; 
				p[i]=nullptr; 
			}
		}
	
	int brojac_null=0; 
	int brojac=0; 
	for(int i=0; i<velicina; i++){
		if(p[i]==nullptr) brojac_null++; 
		else brojac++; 
	}
	}
		return velicina; 
}
int DodajOptuzbu(char **&p, int velicina, string s){
	int brojac_null=0; 
	for(int i=0; i<velicina; i++)
		if(p[i]==nullptr) brojac_null++; 
	
	char *novi=nullptr; 
	try{
		novi=new char[s.size()+1]; 
		strcpy (novi,s.c_str());
		if(brojac_null>0){
			for(int i=0; i<velicina; i++){
				if(p[i]==nullptr){
					p[i]=novi;
					delete novi; 
					break; 
				}
			}
		}
	}
	catch(bad_alloc){
		throw; 
	}
	
	return velicina; 
}
void IzlistajOptuzbu(char **imena, int velicina){
	for(int i=0; i<velicina; i++){
		if(imena[i]!=nullptr){
				cout << imena[i] << endl;
		}
	}
}
int main ()
{
	cout << "Koliko potencijalnih krivaca zelite unijeti? " << endl; 
	int broj; 
	cin >> broj; 
	cin.clear(); 
	cin.ignore(10000, '\n'); 
	cout << "Unesite potencijalne krivce: "; 
	vector<string> krivci; 
	string s;
	for(int i=0; i<broj; i++){
		getline(cin, s); 
		krivci.push_back(s); 
	}
	char **pokazivac; 
	broj=PotencijalniKrivci(pokazivac, krivci); 
	
	int opcija=0; 
	do{
		cout <<endl<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: " << endl; 
		cin >> opcija; 
		cin.clear(); 
		cin.ignore(10000, '\n'); 
		
		if(opcija==1){
			cout << "Unesite ime novog optuzenog: "; 
			string novi;
			cin>> ws; 
			getline(cin, novi); 
			broj=DodajOptuzbu(pokazivac, broj, novi); 
			
		}
		else if(opcija==2){
			cout << "Unesite ime koje zelite izbaciti: "; 
			string izbaci; 
			cin>>ws; 
			getline(cin, izbaci); 
			broj=OdbaciOptuzbu(pokazivac, broj, izbaci); 
		}
		else if(opcija==3){
			 
			IzlistajOptuzbu(pokazivac, broj); 
			
		}
	}while(opcija!=0);
	for(int i=0; i<broj; i++){
		delete[] pokazivac[i]; 
	}
	delete[] pokazivac; 
	
	return 0;
}