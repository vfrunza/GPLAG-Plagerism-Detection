/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <new>

int PotencijalniKrivci(char **&pok, std::vector<std::string> v){
	pok=nullptr;
	try{
		pok=new char *[v.size()];
		for(int i=0;i<v.size();i++) pok[i]=nullptr;
		try{
			for(int i=0;i<v.size();i++) pok[i]=new char[v[i].size()+1];
			for(int i=0;i<v.size();i++){
				for(int j=0;j<v[i].size();j++){
					pok[i][j]=v[i][j];
				}
				pok[i][v[i].size()]='\0';
			}
			return v.size();
		}
		catch(...){
			for(int i=0;i<v.size();i++) delete[] pok[i];
			throw;
		}
	}
	catch(...){
		delete[] pok;
		throw;
	}
}

int OdbaciOptuzbu (char **&pok, int vel_pok, std::string s){
		std::string izuzetak="Osoba sa imenom ";
		izuzetak+=s;
		izuzetak+=" nije bila optuzena";
		if(vel_pok==0) throw std::domain_error (izuzetak);
		bool JeLiBrisano=true;
		for(int i=0;i<vel_pok;i++){
			int j;
			for( j=0;j<s.size();j++){
				if(pok[i][j]!=s[j]) break;
			}
				if(pok[i][j]=='\0' && j==s.size()){
					delete[] pok[i];
					pok[i]=nullptr;
					JeLiBrisano=false;
				}
		}
		if(JeLiBrisano) {
			throw std::domain_error (izuzetak);
		}
		int brojac(0);
		for(int i=0;i<vel_pok;i++){
			if(pok[i]==nullptr) brojac++;
		}
		if(brojac>10){
			char **poki=nullptr;
			try{
			poki=new char* [vel_pok-brojac];
			int f=0;
			for(int i=0;i<vel_pok-brojac;i++){
				if(pok[i]!=nullptr){
					int j=0;
					while(pok[i][j]!='\0'){
						poki[f][j]=pok[i][j];
						j++;
					}
					poki[f][j]='\0';
					f++;
				}
			}
			for(int i=0;i<vel_pok;i++) delete[] pok[i];
			delete[] pok;
			pok=poki;
			return vel_pok-brojac;
			}catch(...){
				for(int i=0;i<vel_pok-brojac;i++) delete[] poki[i];
				delete [] poki;
			}
		}
		return vel_pok;
}

int DodajOptuzbu(char **&pok, int vel_pok, std::string s){
	char *p=nullptr;
	bool ImaLiMjesta=false;
	try{
		p=new char[s.size()+1];
		for(int i=0;i<s.size();i++){
			p[i]=s[i];
		}
		p[s.size()]='\0';
		for(int i=0;i<vel_pok;i++){
			if(pok[i]==nullptr){
				pok[i]=p;
				ImaLiMjesta =true;
				break;
			}
		}
		if(!ImaLiMjesta){
			char **poki=nullptr;
			vel_pok+=1;
			try{
				poki=new char*[vel_pok];
				for(int i=0;i<vel_pok-1;i++){
					poki[i]=pok[i];
				}
				poki[vel_pok-1]=p;
				for(int i=0;i<vel_pok-1;i++)  pok[i]=nullptr;
				delete[] pok;
				pok=poki;
			}
			catch(...){
				delete[] poki;
			}
		}
		
		return vel_pok; 
	}
	catch(...){
		delete [] p;
	}
}

void IzlistajOptuzbu (char **pok, int vel_pok){
	for(int i=0;i<vel_pok;i++){
		if(pok[i]!=nullptr) {
			std::cout << std::endl;
			int j=0;
			while(pok[i][j]!='\0') {
				std::cout << pok[i][j];
				j++;
			}
		}
	}
}

int main ()
{
	try{
		char **pok=nullptr;
		std::cout << "Koliko potencijalnih krivaca zelite unijeti? " ;
		int n;
		std::cin >> n;
		if(!std::cin){
			std::cin.clear();
			return 0;
		}
		std::cin.ignore(100000000,'\n');
		std::vector<std::string>v(n);
		if (n>0)
			std::cout << "\nUnesite potencijalne krivce: ";
		for(int i=0;i<n;i++){
			std::getline(std::cin, v[i]);
		}
		n=PotencijalniKrivci(pok,v);
		int broj;
		do{
			std::cout << "\nOdaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: ";
		std::cin >> broj;
		std::cin.ignore(10000000,'\n');
		if(!std::cin || (broj!=0 && broj!=1 && broj!=2 && broj!=3)){
			std::cin.clear();
			break;
		}
		else if(broj==0) break;
		else if(broj==1){
			std::cout << "\nUnesite ime novog optuzenog: ";
			std::string s;
			std::getline(std::cin, s);
			n=DodajOptuzbu(pok,n,s);
		}
		else if(broj==2){
			std::cout << "\nUnesite ime koje zelite izbaciti: ";
			std::string s;
			std::getline(std::cin, s);
			n=OdbaciOptuzbu(pok,n,s);
		}
		else if(broj==3){
			IzlistajOptuzbu(pok,n);
		}
		}while(broj!=0);
		for(int i=0;i<n;i++) delete [] pok[i];
		delete []pok;
		return 0;
	}catch(std::domain_error s){
		std::cout << s.what() <<std::endl;
	}
	catch(...){
		
	}
}