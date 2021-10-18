/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stdexcept>

int PotencijalniKrivci(char **&pok, std::vector<std::string> v){
	int n=v.size();
	try{
		pok=new char*[n];
	}
	catch(...){
		throw;
	}
	int koliko=0;
	try{
		for(int i=0;i<n;i++){
			pok[i]=new char [v[i].size()+1];
			for(int j=0;j<v[i].size();j++){
				pok[i][j]=v[i][j];
			}
			pok[i][v[i].size()]='\0';
			koliko++;
		}
		return koliko;
	}
	catch(...){
		for(int i=0;i<koliko;i++){
			delete[] pok[i];
		}
		delete[] pok;
		throw;
	}
}

int duzina(char *s){
	int t=0;
	while(*s){
		t++;
		s++;
	}
	return t;
}

bool poredi(char *s, std::string a){
	int n=duzina(s);
	if(n!=a.size())return false;
	for(int i=0;i<n;i++){
		if(s[i]!=a[i])return false;
	}
	return true;
}

int OdbaciOptuzbu(char **&pok, int n, std::string s){
	bool ima=false;
	int brojnull=0;
	for(int i=0;i<n;i++){
		if(pok[i]==nullptr)continue;
		if(poredi(pok[i], s)){
			ima=true;
			delete[] pok[i];
			pok[i]=nullptr;
			break;
		}
	}
	if(ima==false)throw std::domain_error("Osoba sa imenom "+s+" nije bila optuzena");
	for(int i=0;i<n;i++){
		if(pok[i]==nullptr)brojnull++;
	}
	if(brojnull<=10){
		return n;
	}
	try{
		char **temp=nullptr;
		temp=new char* [n-brojnull];
		int brojac=0;
		try{
			for(int i=0;i<n;i++){
				if(pok[i]!=nullptr){
					temp[brojac]=new char [duzina(pok[i])+1];
					std::strcpy(temp[brojac], pok[i]);
					brojac++;
				}
			}
			for(int i=0;i<n;i++){
				delete[] pok[i];
			}
			delete[] pok;
			pok=temp;
			return brojac;
		}
		catch(...){
			for(int i=0;i<brojac;i++){
				delete[] temp[i];
			}
			delete[] temp;
			return n;
		}
	}
	catch(...){
		return n;
	}
}

void IzlistajOptuzbu(char **pok, int n){
	for(int i=0;i<n;i++){
		if(pok[i]!=nullptr)std::cout<<pok[i]<<"\n";
	}
}

int DodajOptuzbu(char **&pok, int n, std::string s){
	try{
		char *a=new char[s.size()+1];
		std::strcpy(a, s.c_str());
		for(int i=0;i<n;i++){
			if(pok[i]==nullptr){
				pok[i]=a;
				return n;
			}
		}
		char **r;
		try{
			r=new char*[n+1];
		}
		catch(...){
			delete[] a;
			throw;
		}
		int brojac=0;
		try{
			for(int i=0;i<n;i++){
				r[i]=new char [duzina(pok[i])+1];
				std::strcpy(r[i], pok[i]);
				brojac++;
			}
			r[n]=a;
			for(int i=0;i<n;i++){
				delete[] pok[i];
			}
			delete[] pok;
			pok=r;
			return n+1;
		}
		catch(...){
			for(int i=0;i<brojac;i++){
				delete[] r[i];
			}
			delete[] r;
			delete[] a;
			throw;
		}
	}
	catch(...){
		throw;
	}
}

int main ()
{
	std::string s;
	char **pok=nullptr;
	int n=0;
	bool gg=true;
	std::cout<<"Koliko potencijalnih krivaca zelite unijeti?\n";
	std::cin>>n;
	std::cin.ignore(10000, '\n');
	try{
		pok=new char*[n];
	}
	catch(...){
		return 0;
	}
	for(int i=0;i<n;i++)pok[i]=nullptr;
	try{
		std::cout<<"Unesite potencijalne krivce: \n";
		for(int i=0;i<n;i++){
			std::getline(std::cin, s);
			pok[i]=new char[s.size()+1];
			std::strcpy(pok[i], s.c_str());
		}
	}
	catch(...){
		for(int i=0;i<n;i++){
			delete[] pok[i];
		}
		delete[] pok;
		return 0;
	}
	do{
		if(!gg)break;
		std::cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: \n";
		int a;
		std::cin>>a;
		std::cin.ignore(10000, '\n');
		if(a==0)break;
		if(a==1){
			std::cout<<"Unesite ime novog optuzenog: \n";
			std::getline(std::cin, s);
			bool gg=true;
			try{
				n=DodajOptuzbu(pok, n, s);
			}
			catch(...){
				gg=false;
			}
		}
		if(a==2){
			std::cout<<"Unesite ime koje zelite izbaciti: \n";
			std::getline(std::cin, s);
			try{
				n=OdbaciOptuzbu(pok, n, s);
			}
			catch(std::domain_error gg){
				std::cout<<gg.what();
			}
		}
		if(a==3){
			IzlistajOptuzbu(pok, n);
		}
	}while(true);
	for(int i=0;i<n;i++){
		delete[] pok[i];
	}
	delete[] pok;
	return 0;
}