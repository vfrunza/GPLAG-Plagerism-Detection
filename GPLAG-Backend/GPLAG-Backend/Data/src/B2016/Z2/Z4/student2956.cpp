/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/

#include <iostream>
#include <new>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

int PotencijalniKrivci(char** &p1,const vector<string>&s1)
{
	int broj=s1.size();  
	p1=nullptr;
	p1=new char*[broj]; 
	try{
		for(int i=0;i<broj;i++) p1[i]=nullptr;
		for(int i=0;i<broj;i++) p1[i]=new char[(int)s1[i].length()+1];
		for(int i=0;i<broj;i++){
		for(int j=0;j<s1[i].size();j++) {
		p1[i][j]=s1[i][j];
	}
	p1[i][s1[i].length()]='\0';
		}
	}

catch(bad_alloc){
	for(int i=0;i<broj;i++) delete [] p1[i];delete [] p1;
	throw;
}
return broj;
}

bool isti(char* s1,string s)
{
 if(s1==nullptr || s.length()==0 ) return false;
	int i(0);
	while(i<s.length() && *s1!='\0'){
		if(*s1!=s[i]) return false;
		s1++;
		i++;
	}
	if(*s1=='\0' && i==(int)s.length()) return true; else return false;
}

int PrebrojiNule(char**p,int velicina)
{
	int brojac(0);
	for(int i=0;i<velicina;i++){
		if(p[i]==nullptr) brojac++;
	}
	return brojac;
}

int SiZe(char*p){
	if(p==nullptr) return 0;
	int brojac(0);
	while(*p!='\0'){
		brojac++;
		p++;
	}
	return brojac+1;
}

int OdbaciOptuzbu(char** &p1,int velicina,string s)
{
	int broj=0;
	bool postoji=false;
	for(int i=0;i<velicina;i++){
		if(isti(p1[i],s)){
			postoji=true;
			delete [] p1[i];
			p1[i]=nullptr;
			broj=PrebrojiNule(p1,velicina);
			if(broj>10){
				try{
					char** novi=new char*[velicina-broj]; //velicina minus broj =potrebno po na niz znakova
					int br=0; // jer nece biti na istoj i-toj poziciji
					for(int k=0;k<(velicina-broj);k++) novi[k]=nullptr; //osiguranje
					for(int k(0);k<velicina;k++){
						int vel=SiZe(p1[k]);
						if(p1[k]!=nullptr){
							novi[br]=p1[k];
							br++;
						}
					}
					delete [] p1; // brisemo prostor koji smo imali za one pokazivace
					p1=novi;
					return velicina-broj;
				}
				catch(bad_alloc){
					
				}
				
			}
			break; // jer ne mogu biti dva ista imena
		}
	}
	try{
		if(!postoji) throw domain_error("");
	}
	catch(domain_error e){
		cout<<"Osoba sa imenom "<<s<<" nije bila optuzena";
		throw;
	}
	return velicina;
}

int DodajOptuzbu(char** &p1,int velicina,string s)
{
	char*novi=nullptr;
	int duzina=(int)s.length();
	novi=new char[duzina+1];
	for(int i=0;i<duzina;i++) novi[i]=s[i];
	novi[duzina]='\0';
	
	for(int j=0;j<velicina;j++){
		if(p1[j]==nullptr){
			p1[j]=novi; return velicina;
		}
	}
	// ako je dosao dovde definitivno nema slobodnih mjesta pa alociramo novu u try
	try{
		char**pok=new char*[velicina+1];
		for(int j=0;j<velicina;j++) pok[j]=p1[j];
		pok[velicina]=novi;
		delete[] p1;
		p1=pok;
		return velicina+1;
	}
	catch(bad_alloc){
		delete[] novi;
		throw;
	}
}

void Ispisi(char* ime)   // ispis za IzlistajOptuzbu
{
	while(*ime!='\0') cout<<*ime++;
}

void IzlistajOptuzbu(char**p1,int velicina) // ovo sa uradio 
{
	for(int i=0;i<velicina;i++){
		if(p1[i]!=nullptr){
		Ispisi(p1[i]);
		cout<<endl;
		}
	}
}

int main()
{
	cout<<"Koliko potencijalnih krivaca zelite unijeti? "<<endl;
	int n;
	cin>>n;
	try{
		vector<string>imena(n);
		cout<<"Unesite potencijalne krivce: "<<endl;
		cin.ignore(10000,'\n');
		for(int i=0;i<n;i++){
			getline(cin,imena[i]);
		}
		char**p=nullptr;
		auto VEL=PotencijalniKrivci(p,imena);
		int x=-1;
		while(x!=0){
			cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: "<<endl;
			cin>>x;
			if(x==1){
				cout<<"Unesite ime novog optuzenog: "<<endl;
				string s;
				cin.ignore(10000,'\n');
				getline(cin,s);
				VEL=DodajOptuzbu(p,VEL,s);
			}
			else if(x==2){
				cout<<"Unesite ime koje zelite izbaciti: "<<endl;
				string s;
				cin.ignore(10000,'\n');
				getline(cin,s);
				VEL=OdbaciOptuzbu(p,VEL,s);
			}
			else if(x==3){
				IzlistajOptuzbu(p,VEL);
			}
			
		}
		for(int i=0;i<VEL;i++) delete[] p[i];delete[]p;
	}
	catch(domain_error e){}
	catch(bad_alloc){}
	return 0;
}


