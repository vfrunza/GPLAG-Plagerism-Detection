/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <vector>
#include <iostream>
#include <string>
#include <stdexcept>
#include <new>

using namespace std;

int PotencijalniKrivci(char **&pok, vector<string> spisak) {
	pok=nullptr;
	int brojac=0;
	try{
		pok=new char *[spisak.size()];
		for(int i(0);i<spisak.size();i++) pok[i]=nullptr;
		try{
			for(int i(0);i<spisak.size();i++) {
				pok[i]=new char [spisak[i].length()+1];
				brojac++;
			}
			for(int i(0);i<spisak.size();i++) {
				for(int j(0);j<spisak[i].length();j++) {
					pok[i][j]=spisak[i][j];
				}
				pok[i][spisak[i].length()]='\0';
			}
			return brojac;
		}
		catch(...){
			for(int i(0);i<spisak.size();i++) delete[] pok[i];
			delete[] pok;
			throw ;
		}
	}
	catch(...) {
		throw bad_alloc();
	}
}

int OdbaciOptuzbu(char **&matrica, int velicina, string ime) {
	char **pok=matrica;
	bool ima=false;
	int brojac=0;
	for(int i(0);i<velicina;i++) {
		if(pok[i] != nullptr && pok[i][0]==ime[0]){
			int j=0;
			while(j<ime.length() && pok[i][j]==ime[j]) j++;
			if(ime.length()==j && pok[i][j]=='\0') {
					ima=true;
					delete [] pok[i];
					pok[i]=nullptr;
				}
			}
			
		if(pok[i]==nullptr) brojac++;
	}
	if(!ima) throw domain_error ("Osoba sa imenom "+ime+" nije bila optuzena");
	if(brojac>9) {
		char **pok2=nullptr;
		int j=0;
		try {
			pok2=new char *[velicina-brojac];
			
			for(int i(0);i<(velicina-brojac);i++) pok2[i]=nullptr;
			for(int i(0);i<velicina;i++) {
				if(pok[i]!=nullptr) {
					pok2[j]=pok[i];
					j++;
					delete[] pok[i];
				}
			}
			velicina-=brojac;
			matrica=pok2;
			delete[] pok;
		}catch(...) {}
		
	}
	return velicina;
}

int DodajOptuzbu(char **&matrica, int velicina, string ime) {
	char *pom=nullptr;
	try{
		pom=new char[ime.length()+1];
		for(int i(0);i<ime.length();i++) pom[i]=ime[i];
		pom[ime.length()]='\0';
	}catch(...) { throw bad_alloc(); }
	
	bool ima=false;
	for(int i(0);i<velicina;i++) {
		if(matrica[i]==nullptr) {
			ima=true;
			matrica[i]=pom;
		}
		if(ima) break;
	}
	
	char **mat=nullptr;
	
	if(!ima) {
		try{
			mat=new char *[velicina+1];
			for(int j(0);j<velicina+1;j++) mat[j]=nullptr;
			for(int i(0);i<velicina;i++) {
				mat[i]=matrica[i];
			}
			mat[velicina]=pom;
			
			
			delete[] matrica;
			matrica=mat;
			mat=nullptr;
			velicina++;
			return velicina;
		}catch(...) {
			throw bad_alloc();
			delete[] mat;
			
		}
		
	}
	return velicina;
}

void IzlistajOptuzbu(char **matrica, int velicina) {
	for(int i(0);i<velicina;i++) {
		
		if(matrica[i]==nullptr) continue;
		
		else {
			cout<< endl << matrica[i];
		}
		
	}
}

int main ()
{
	cout << "Koliko potencijalnih krivaca zelite unijeti? ";
	int n; cin >> n;
	if(n>0) cout << "\nUnesite potencijalne krivce: ";
	vector<string> spisak;
	string ime;
	getline(cin,ime);
	int i=0;
	while(i<n) {
		getline(cin,ime);
		spisak.push_back(ime);
		i++;
	}
	char **mat;
	int BrOptuzenih;
	BrOptuzenih=PotencijalniKrivci(mat,spisak);
	int k=321; 
try{
	do{
		cout << "\nOdaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: ";
		cin >> k;
		
		if(k==1) {
			cout << "\nUnesite ime novog optuzenog: ";
			int c=0;
			try {
				string novi;
				getline(cin,novi);
				while(c<1) {
					getline(cin,novi);
					BrOptuzenih=DodajOptuzbu(mat,BrOptuzenih,novi);
					c++;
				}
			}catch(bad_alloc) { throw bad_alloc(); }
		}
		if(k==2) {
			string izbaci;
			try{
				cout << "\nUnesite ime koje zelite izbaciti: ";
				int c=0;
				getline(cin,izbaci);
				while(c<1) {
					getline(cin,izbaci);
					BrOptuzenih=OdbaciOptuzbu(mat,BrOptuzenih,izbaci);
					c++;
				}
			}catch(domain_error Izuzetak) { cout<< Izuzetak.what() << endl; };
		}
		if(k==3) IzlistajOptuzbu(mat,BrOptuzenih);
		
		if(k==0) {
			for(int i(0);i<BrOptuzenih;i++) delete[] mat[i];
			delete[] mat;
		}
		
	}while(k!=0);
}catch(bad_alloc) { };
	return 0;
}