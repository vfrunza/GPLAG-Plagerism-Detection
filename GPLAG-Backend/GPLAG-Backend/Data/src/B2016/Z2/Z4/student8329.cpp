/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::move;


// POTENCIJALNI KRIVCI

int PotencijalniKrivci (char** &pok, vector<string> v){
	int brojac=0;
	int broj_ljudi=v.size();
	try{
		char** pokazivac(new char* [broj_ljudi]);
		for(int i=0; i<broj_ljudi; i++){
			int duzina_imena;
			duzina_imena=v[i].length();
			pokazivac[i]=new char[duzina_imena+1];
			for(int j=0; j<v[i].length(); j++){
				pokazivac[i][j]=v[i][j];
			}
			
			brojac++;
		}
		pok=pokazivac;
	}
	catch(...){
		for(int i=0; i<brojac; i++){
			delete[] pok[i];
		}
		delete[]pok;
		throw;
	}
	return brojac;
}

// ODBACI OPTUZBU

int OdbaciOptuzbu(char ** &pok, int velicina, string ime){
	bool tacnost=0;
	int brojac=0;
	for(int i=0; i<velicina; i++){
		if(pok[i]==ime){
			delete[] pok[i];
			pok[i]==nullptr;
			tacnost=1;
		}
	}
	if(!tacnost){
		throw std::domain_error ("Osoba sa imenom " +ime+ " nije bila optuzena");
	}
	for(int i=0; i<velicina; i++){
		if(pok[i]==nullptr) brojac++;
	}
	if(brojac<=10){
		return velicina;
	}
	else{
		try{
			char** novi_pokazivac=new char*[velicina-brojac];
			int novi_brojac=0;
			for(int i=0; i<velicina;i++){
				if(pok[i]!=nullptr){
					novi_pokazivac[novi_brojac]=pok[i];
					novi_brojac++;
				
				}
				delete[] pok[i];
			}
			delete[] pok;
			auto pok=novi_pokazivac;
			return velicina-brojac;
			}
			catch(...){
				return velicina;
			}
		}
}

// DODAJ OPTUZBU

int DodajOptuzbu(char ** &pok, int velicina, string ime){
	int duzina_imena=ime.length();
	bool tacnost=1;
	for(int i=0; i<velicina; i++){
		if(pok[i]==nullptr){
			try{
				pok[i]=new char[duzina_imena+1];
				for(int j=0; j<duzina_imena; j++){
					pok[i][j]=ime[j];
				}
				tacnost=0;
				return velicina;
			}
			catch(...){
				return velicina;
			}
		}
	}
	if(tacnost){
		try{
			char** novi_pokazivac=new char*[velicina+1];
			for(int i=0; i<velicina; i++){
				novi_pokazivac[i]=pok[i];
			}
			for(int i=0; i<duzina_imena; i++){
				novi_pokazivac[velicina][i]=ime[i];
			}
			for(int i=0; i<velicina; i++){
				delete[]pok[i];
			}
			delete[]pok;
			auto pok=novi_pokazivac;
			
			return velicina+1;
		}
		catch(...){
			return velicina;
		}
	}
	return velicina;
}

void IzlistajOptuzbu(char ** pok, int velicina){
	for(int i=0; i<velicina; i++){
		if(pok[i]!=nullptr){
			cout<<pok[i];
			cout<<endl;
		}
	}
}

int main (){
	cout<<"Koliko potencijalnih krivaca zelite unijeti? "<<endl;
	int n;
	cin>>n;
	cout<<"Unesite potencijalne krivce: "<<endl;
	vector<string> imena;
	char** pok;
	cin.ignore(1000,'\n');
	for(int i=0; i<n; i++){
		string element;
		getline(cin,element);
		imena.push_back(element);
	}
	int broj;
	try{

		n=PotencijalniKrivci(pok,imena);
		do{
			cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj:";
			cin>>broj;
			cin.ignore(10000,'\n');
			if(broj==1){
				string ime;
				getline(cin,ime);
				n=DodajOptuzbu(pok,n,ime);
			}
			else if(broj==2){
				string ime;
				getline(cin,ime);
				n=OdbaciOptuzbu(pok,n,ime);
			}
			else if(broj==3){
				IzlistajOptuzbu(pok,n);
				
			}
		}
		while(broj!=0);
		for(int i=0; i<n; i++){
					delete[] pok[i];
				}
				delete[] pok;
	}
	catch(std::domain_error s){
		cout<<s.what();
	}
	return 0;
}