#include <string>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
#include "sake.h"

int PotencijalniKrivci(char**&p, std::vector<std::string> v){
	if(v.size()==0)
		return 0;
	p=nullptr;
	try {
		p=new char*[v.size()]{};
		try {
			for(int i=0; i<v.size(); i++){
					p[i]=new char[v[i].length()+1];
					int k;
					for(k=0; k<v[i].length(); k++){
						p[i][k]=v[i][k];
					}
					p[i][k]='\0';
			}
		}
        catch (std::bad_alloc) {
            for(unsigned int i=0; i<v.size(); i++)
                delete[] p[i]; 
            delete[] p;
            throw;
        }
    }
    catch (std::bad_alloc) {
        throw; 
    }
    return v.size();
}
std::string pretvori(char *p){
	std::string s="";
	while (*p!='\0') 
		s+=*p++;
	return s;	
}
int AlocirajPonovo(char**&p, int n, std::string novi){
	int br(0);
	for(int i=0; i<n; i++){
		if(p[i]!=nullptr)
			br++;
	}
	char **a=nullptr;
	try {
		if(n==br)
			a=new char*[br+1]{};
		else	
			a=new char*[br]{};
		try {
			int j=0;
			for(int i=0; i<n; i++){
				if(p[i]!=nullptr){
					std::string s=pretvori(p[i]);
					a[j]=new char[s.size()+1];
					int k;
					for(k=0; k<s.size(); k++){
						a[j][k]=p[i][k];
					}
					a[j][k]=0;
					j++;
				}
			}
			if(n==br){
				a[j]=new char[novi.size()+1];
				int k;
				for(k=0; k<novi.size(); k++){
					a[j][k]=novi[k];
				}
				a[j][k]=0;
				br++;
			}
		
		for(int i=0; i<n; i++)
			delete[] p[i];
		delete[] p;
		p=a;
		return br;
			
		}
		catch (std::bad_alloc) {
			for(int i=0; i<br; i++)
				delete[] a[i];
			delete[] a;
			if(n==br)
			throw;
			else
			return n;
		}
	}
	catch (std::bad_alloc) {
		if(n==br)
			throw;
		else
			return n;
	}
}
int OdbaciOptuzbu(char **&p, int n, std::string s){
	int br(0);
	for(int i=0; i<n; i++){
		std::string ime=pretvori(p[i]);
		if(ime==s){
			delete[] p[i];
			p[i]=nullptr;
			br++;
		}
	}
	int br2(0);
	for(int i=0; i<n; i++)
		if(p[i]==nullptr)
			br2++;
	if(br2>10)
	   n=AlocirajPonovo(p,n,s);
	if(br==0)
	   throw std::domain_error("Osoba sa imenom "+s+" nije bila optuzena");
	return n;   
}
char *AlocirajNIZ(std::string s){
	char *p=nullptr;
	try {
		p=new char[s.size()+1];
		int i;
		for(i=0; i<s.size(); i++)
			p[i]=s[i];
		p[i]=0;
		return p;
	}
	catch (std::bad_alloc) {
		throw;
	}
}
int DodajOptuzbu(char **&p, int n, std::string s){
	
	bool nije_nasao(true); 
	for(int i=0; i<n; i++){
		if(p[i]==nullptr){
			char* novi_clan=nullptr;
			try {
				novi_clan=AlocirajNIZ(s);
			}
			catch (...) {
				throw;
			}
			p[i]=novi_clan;
			delete[] novi_clan;
			nije_nasao=false;
			break;
		}
	}
	try {
		if(nije_nasao)
			n=AlocirajPonovo(p,n,s);
	}
	catch (std::bad_alloc) {
		throw;
	}
	return n;
}	
void IzlistajOptuzbu(char **p, int n){
	for(int i=0; i<n; i++){
		if(*p==nullptr){
			p++;
			continue;
		}	
		std::cout << *p++<<"\n";	
	}
}
int main (){
	std::cout << "Koliko potencijalnih krivaca zelite unijeti?\nUnesite potencijalne krivce: " << std::endl;
	int n;
	std::cin >> n;
	std::vector<std::string> v(n);
	std::string s;
	std::cin.ignore(10000, '\n');
	for(int i=0; i<n; i++){
   		 std::getline(std::cin, s);
   		 v[i]=s;
	}
	char**p=nullptr;
	try {
		n=PotencijalniKrivci(p,v);
		int br;
		do{
			std::cout << "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: " << std::endl;
			std::cin >> br;
			std::cin.ignore(10000, '\n');
			
			if(br==0)
				break;
			
			if(br==1){
				std::cout << "Unesite ime novog optuzenog: " << std::endl;
				std::getline(std::cin, s);
				try{n=DodajOptuzbu(p,n,s);}
				catch(...){
					throw;
					}
				}
			
			if(br==2){
				std::cout << "Unesite ime koje zelite izbaciti: " << std::endl;
				std::getline(std::cin, s);
				try{
					n=OdbaciOptuzbu(p,n,s);
				}	
				catch(std::domain_error error){
					std::cout << error.what() << std::endl;
				}
				catch(...){
					throw;
				}
			}
			
			if(br==3)
				IzlistajOptuzbu(p,n);
		}while(br!=0);
	}	
	catch(...){
		for(int i=0; i<n; i++)
			delete[] p[i];
		delete[] p;
		throw;
	}
	for(int i=0; i<n; i++)
		delete[] p[i];
	delete[] p;	
return 0;
}