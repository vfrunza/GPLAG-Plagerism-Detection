/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
#include<new>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int PotencijalniKrivci(char **&ref, std::vector<std::string>v){
	char **niz(nullptr);
	
	try{
		
		niz=new char*[v.size()];
	}
	catch(std::bad_alloc){
		delete[] niz;
		throw;
	}
	try{
		for(int i=0; i<v.size(); i++)
			niz[i]=nullptr;
		for(int i=0; i<v.size(); i++)
			niz[i]=new char[v[i].size()+1];
		for(int i=0; i<v.size(); i++){
			for(int j=0; j<v[i].size(); j++){
				niz[i][j]=v[i][j];
				if(j==v[i].size()-1)
					niz[i][j+1]='\0';
			}
		}
		ref=niz;
		return v.size();
	}
	catch(std::bad_alloc){
		for(int i=0; i<v.size(); i++)
			delete[] niz[i];
		delete[] niz;
		throw;
	}
}
int OdbaciOptuzbu(char **&ref, int n, std::string s){
	int br=0;
	for(int i=0; i<n; i++){
		char *r=ref[i];
		int j=0;
		while(*r!='\0' && j<s.size()){
			if(*r==s[j]){
				j++;
				r++;
			}
			else break;
		}
		if(j==s.size() && *r=='\0'){
			delete[] ref[i];
			ref[i]=nullptr;
			br++;
		}
	}
	if(br==0) throw std::domain_error("Osoba sa imenom "+s+" nije bila optuzena");
	if(br>10){
		char**niz=nullptr;
	try{
		niz=new char*[n-br];
	}
	catch(std::bad_alloc){
		delete[] niz;
	}
	try{
		int j(0);
		for(int i=0; i<n-br; i++)
			niz[i]=nullptr;
		for(int i=0; i<n; i++){
			if(ref[i]!=nullptr){
				char *r=ref[i];
				char*e=ref[i];
				int b=0;
				while(*r!='\0'){ b++; r++;}
				niz[j]=new char[b+1];
				char *p=niz[j];
				while(*p++=*e++);
				j++;
		}
		}
		for(int i=0; i<n; i++)
		delete[] ref[i];
		ref=niz;
		return n-br;
	}
	catch(std::bad_alloc){
		for(int i=0; i<n-br; i++)
			delete[] niz[i];
		delete[] niz;
	}
	}
	return n;
}
int DodajOptuzbu(char **&ref, int n, std::string s){
	char *optuzeni=nullptr;
	try{
	optuzeni=new char[s.size()+1];
	for(int i=0; i<s.size(); i++){
		optuzeni[i]=s[i];
		if(i==s.size()-1) optuzeni[i+1]='\0';
	}
	}
	catch(std::bad_alloc){
		delete[] optuzeni;
		throw;
	}
	int br(0);
	for(int i=0; i<n; i++){
		if(ref[i]==nullptr){
			ref[i]=&optuzeni[0];
			br=1;
			break;
		}
	}
	if(br==0){
		char **niz=nullptr;
		try{
			niz=new char*[n+1];
		}
		catch(std::bad_alloc){
			delete[] niz;
			throw;
		}
		try{
			for(int i=0; i<n; i++)
				niz[i]=nullptr;
			for(int i=0; i<n; i++){
				char*r=ref[i];
				int b=0;
				while(*r!='\0'){ b++; r++;}
				niz[i]=new char[b+1];
				int j(0);
				for( ; ;){
					niz[i][j]=ref[i][j];
					if(ref[i][j]=='\0') break;
					j++;
				}
		
			}
		
				niz[n]=&optuzeni[0];
	
			for(int i=0; i<n; i++)
				delete[] ref[i];
			delete[] ref;
			ref=niz;

			return n+1;
		}
		catch(std::bad_alloc){
		for(int i=0; i<n+1; i++)
			delete[] niz[i];
		delete[] niz;
		throw;
		}
	}
	return n;
}
void IzlistajOptuzbu(char **ref, int n){
	cout<<endl;
	for(int i=0; i<n; i++){
		char *r=ref[i];
		if(ref[i]==nullptr) continue;
		while(*r!='\0'){
			cout<<*r;
			r++;
		}
		if(i!=n-1) cout<<endl;
	}
}
int main ()
{
	
	cout<<"Koliko potencijalnih krivaca zelite unijeti? ";
	int n;
	char **ref;
	cin>>n;
	cout<<endl<<"Unesite potencijalne krivce: ";
	std::cin.ignore(10000,'\n');
	try{
	std::vector<std::string>v(n);
	for(int i=0; i<n; i++)
		cin>>v[i];
	
	
	
	n=PotencijalniKrivci(ref, v);
	int x;
	std::string s;
	for( ; ; ){
		cout<<endl<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: ";
		cin>>x;
		if(x==0) break;
		if(x==1){
			cout<<endl<<"Unesite ime novog optuzenog: ";
			std::cin.ignore(10000,'\n');
			std::getline(cin, s);     
			n=DodajOptuzbu(ref, n, s);
			
		}
		if(x==2){
			cout<<endl<<"Unesite ime koje zelite izbaciti: ";
			std::cin.ignore(10000,'\n');
			std::getline(cin, s);
			n=OdbaciOptuzbu(ref, n, s);	
		}
		
		if(x==3) IzlistajOptuzbu(ref,n);
	}
		
	}
	catch(std:: domain_error izuzetak){
		cout<<izuzetak.what()<<endl;
		for(int i=0; i<n; i++)
			delete[] ref[i];
		delete[] ref;
		return 0;
	}
	catch(std::bad_alloc){
		for(int i=0; i<n; i++)
		delete[] ref[i];
		delete[] ref;
		return 0;
	}
	for(int i=0; i<n; i++)
	    delete[] ref[i];
	delete[] ref;
	return 0;
}
