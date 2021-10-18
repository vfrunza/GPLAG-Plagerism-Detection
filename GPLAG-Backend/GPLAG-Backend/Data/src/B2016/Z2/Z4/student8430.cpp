/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/

#include <vector>
#include <iostream>
#include <stdexcept>
using namespace std;


void IzlistajOptuzbu(char **a , int n){
	
	for(int i = 0 ; i < n ; i++){
		
		char *pok = a[i];
		if(pok == nullptr){
			continue;
		}
		while(*pok != '\0'){
			cout << *pok;
			pok++;
		}
		cout << endl;
	}
	
}

int PotencijalniKrivci(char **& a , vector<string> v){
	
	char **pom;
	int broj = 0;
	
	try{

		char **pok(new char*[v.size()]);
		pom = pok;
		
		for(int i = 0 ; i < v.size() ; i++){
			pok[i] = new char[v[i].size() + 1];
		}
		
		for(int i = 0 ; i < v.size() ; i++){
			char *p = pok[i];
			for(int j = 0 ; j < v[i].size() ; j++){
				*p = v[i][j];
				p++;
			}
			*p = '\0';
			broj++;
		}
		
		a = pok;
		
	}
	catch(exception e){
		
		for(int i = 0 ; i < v.size() ; i++){
			delete[] pom[i];
		}
		delete[] pom;
		
		throw bad_alloc();
	}
	
	return broj;
	
}

bool provjeraImena(char *pok , string ime){
	
	bool provjera = true;
	for(int i = 0 ; i < ime.length() ; i++){
		
		if(*pok != ime[i] || *pok == '\0'){
			provjera = false;
			break;
		}
		pok++;
	}
	
	return provjera;
}

int OdbaciOptuzbu(char **& a , int n , string ime){
	
	bool ima = false;
	
	for(int i = 0 ; i < n ; i++){
		
		if(*a == nullptr){
			continue;
		}
			
		if(provjeraImena(a[i] , ime)){
			delete[] a[i];
			a[i] = nullptr;
			ima = true;
			return n;
		}
		
	}
	
	if(!ima){
		throw domain_error("Osoba sa imenom " + ime + " nije bila optuzena");
	}
	
	int brojNull = 0;
	for(int i = 0 ; i < n ; i++){
		if(a[i] == nullptr){
			brojNull++;
		}
	}
	
	if(brojNull > 10){
		
		char **pom(new char*[n - 11]);
		int brojDodjeljenih = 0;
		for(int i = 0 ; i < n ; i++){
			if(a[i] != nullptr){
				pom[brojDodjeljenih] = a[i];
				brojDodjeljenih++;
			}
		}
		
		delete[] a;
		a = pom;
	}
	return n - 11;	
}

int DodajOptuzbu(char **& a , int n , string ime){
	
	try{
		
		char *p = new char[ime.length() + 1];
		char *p_pom = p;
		for(int i = 0 ; i < ime.length() ; i++){
			*p_pom = ime[i];
			p_pom++;
		}
		*p_pom = '\0';
		
		for(int i = 0 ; i < n ; i++){
			if(a[i] == nullptr){
				a[i] = p;
				return n;
			}
		}

	
		char **pok = a;
		a = new char*[n + 1];
		for(int i = 0 ; i < n ; i++){
			a[i] = pok[i];
		}
		a[n] = p;
		delete[] pok;
	}
	catch(exception e){
		throw bad_alloc();
	}
	
	return n + 1;	
}

int main ()
{
	
	
	int x , n;
	vector<string> v;
	char **pok;
	
	cout << "Koliko potencijalnih krivaca zelite unijeti?" << endl;
	cin >> x;
	
	cout << "Unesite potencijalne krivce: " << endl;
	for(int i = 0 ; i < x ; i++){
		string s;
		cin >> s;
		v.push_back(s);
	}
	
	n = PotencijalniKrivci(pok , v);
	
	int broj = 1;
	while(broj != 0){
		
		cout << "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: " << endl;
		cin >> broj;
		if(broj == 1){
			cout << "Unesite ime novog optuzenog: " << endl;
			string ime;
			cin >> ime;
			n = DodajOptuzbu(pok , n , ime);	
		}
		else if(broj == 2){
			cout << "Unesite ime koje zelite izbaciti: " << endl;
			string ime;
			cin >> ime;
			n = OdbaciOptuzbu(pok,n,ime);
		}
		else if(broj == 3){
			IzlistajOptuzbu(pok , n);
		}
	}
	
	for(int i = 0 ; i < n ; i++){
		delete[] pok[i];
	}
	delete[] pok;


	return 0;
}