#include <iostream>
#include <vector>
#include <cstring>
#include <stdexcept>


using namespace std;
/* kontinualnom alokacijom
int PotencijalniKrivci(char **& krivciKopija, std::vector<string> krivciOrginal)
{
	try {
		krivciKopija = new char*[krivciOrginal.size()];
		
		brojZnakova=0;
		
		for (int i = 0; i < krivciOrginal.size(); i++) {
			brojZnakova+=krivciOrginal[i].size()+1;
		}
		
		try {
			krivciKopija[0] = new char[brojZnakova];
			
			for (int i = 1; i < krivciKopija.size(); i++) {
				krivciKopija[i] = krivciKopija[i-1]+krivciOrginal[i-1].size()+1;
			}
			
			
			for (int i = 0; i < krivciOrginal.size(); i++) {
				for (int j = 0; j < krivciOrginal[i].size(); j++) {
					krivciKopija[i][j]=krivciOrginal[i][j];
				}
				krivciKopija[i][j]='\0';
			}
			
			return 
			
		}
		catch (bad_alloc) {
			delete[] krivciKopija;
		}
		
	
	}
	catch (bad_alloc) {
		throw;
	}
	
	
}

*/


/* fragmentirana alokacija */

int PotencijalniKrivci(char **& krivciKopija, std::vector<string> krivciOrginal){
	
	try {
		krivciKopija = new char*[krivciOrginal.size()];
		
		for (int i = 0; i < krivciOrginal.size(); i++) {
			krivciKopija[i]=nullptr;
		}
		
		try {
			
			for (int i = 0; i < krivciOrginal.size(); i++) {
				krivciKopija[i] = new char[krivciOrginal[i].size()+1];
			}
			
			for (int i = 0; i < krivciOrginal.size(); i++) {
				int j;
				for ( j = 0; j < krivciOrginal[i].size(); j++) {
					
					krivciKopija[i][j] = krivciOrginal[i][j];
				}
				krivciKopija[i][j]='\0';
			}
			
		}
		catch (bad_alloc) {
			for (int i = 0; i < krivciOrginal.size(); i++) {
				delete [] krivciKopija[i];
			}
			delete [] krivciKopija;
		}
	}
	catch (bad_alloc) {
		throw;
	}
	
	
	return krivciOrginal.size();
}


int OdbaciOptuzbu(char**&potencijalniKrivci, int velicina, string nijeKriv){
	
	
	bool postoji=false;
	int brojNullPtr=0;
	for (int i = 0; i < velicina; i++) {
		
		if(potencijalniKrivci[i]!=nullptr){
			if(strcmp(potencijalniKrivci[i],nijeKriv.c_str())==0){
				delete[]potencijalniKrivci[i];
				potencijalniKrivci[i]=nullptr;
				
				postoji=true;
				brojNullPtr++;
			}
		}
		else{
			brojNullPtr++;
		}
	}
	
	if(!postoji){
		throw domain_error("Osoba sa imenom "+nijeKriv+" nije bila optuzena");
	}
	
	if(brojNullPtr>10){
		
		int brojKorisnihPokazivaca = velicina - brojNullPtr;
		char**pomocni;
		try{
			pomocni= new char*[brojKorisnihPokazivaca];
			int j=0;
			for (int i = 0; i < velicina; i++) {
				if(potencijalniKrivci[i]!=nullptr){
					pomocni[j] = potencijalniKrivci[i];
					j++;
				}
			}
		}
		catch(bad_alloc){
			return velicina;
		}
		
		delete[] potencijalniKrivci;
		potencijalniKrivci = pomocni;
		velicina-=brojNullPtr;	
	}
	

	return velicina;
}





int DodajOptuzbu(char**&potencijalniKrivci, int velicina, string krivac){
	char* pomocniKrivac = new char[krivac.size()+1];
	
	strcpy(pomocniKrivac,krivac.c_str());
	
	bool postojiSlobodnoMjesto=false;
	for (int i = 0; i < velicina; i++) {
		if(potencijalniKrivci[i]==nullptr){
			potencijalniKrivci[i]=pomocniKrivac;
			postojiSlobodnoMjesto=true;
			break;
		}
	}
	
	
	if(!postojiSlobodnoMjesto){
		char**pomocni ;
		
		try {
			pomocni = new char*[velicina+1];
			
			for (int i = 0; i < velicina; i++) {
				pomocni[i]=potencijalniKrivci[i];
			}
			
			pomocni[velicina]=pomocniKrivac;
			
			delete[]potencijalniKrivci;
			potencijalniKrivci = pomocni;
			
			velicina++;
		}
		catch (bad_alloc) {
			return velicina;
		}
		
	}
	return velicina;
}
	


void IzlistajOptuzbu(char** potencijalniKrivci,int velicina){
	for (int i = 0; i < velicina; i++) {
		if(potencijalniKrivci[i]!=nullptr){
			cout<<potencijalniKrivci[i]<<endl;
		}
	}
}

int main ()
{
	char**pKrivci=nullptr;
	cout<<"Koliko potencijalnih krivaca zelite unijeti? "<<endl;
	int brojKrivaca;
	cin>>brojKrivaca;
	
	cout<<"Unesite potencijalne krivce: "<<endl;
	
	std::vector<string>imenaKrivaca(brojKrivaca);
	cin.ignore();
	for (int i = 0; i < brojKrivaca; i++) {
		getline(cin,imenaKrivaca[i]);
	}
	
	try {
		PotencijalniKrivci(pKrivci,imenaKrivaca);
		int izbor;
		do{
			
			cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: "<<endl;
			cin>>izbor;
			cin.ignore();
			if(izbor==1){
				string noviKrivac;
				cout<<"Unesite ime novog optuzenog: "<<endl;
				getline(cin,noviKrivac);
				brojKrivaca = DodajOptuzbu(pKrivci,brojKrivaca,noviKrivac);
			}
			else if(izbor==2){
				cout<<"Unesite ime koje zelite izbaciti: "<<endl;
				string noviOslobodjeni;
				getline(cin,noviOslobodjeni);
				brojKrivaca = OdbaciOptuzbu(pKrivci,brojKrivaca,noviOslobodjeni);
			}
			else if(izbor==3){
				IzlistajOptuzbu(pKrivci,brojKrivaca);
			}
			
			
			
		}while(izbor!=0);
		
		for (int i = 0; i < brojKrivaca; i++) {
			delete[] pKrivci[i];
		}
		delete[] pKrivci;
	}
	catch (bad_alloc) {
		std::cout << "Nema memorije"<< std::endl;
	}
	

	
	
	return 0;
}