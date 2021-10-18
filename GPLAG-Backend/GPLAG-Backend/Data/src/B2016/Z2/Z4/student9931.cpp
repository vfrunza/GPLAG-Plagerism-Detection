/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <stdexcept>

int PotencijalniKrivci(char **&znakovi , std::vector<std::string> v){
	int brojac(0);
	try{
		znakovi=new char*[v.size()];
		for(int i=0;i<v.size();i++){ 
			znakovi[i]=new char[v[i].size()+1];
			brojac++;
		}
	//	for(int i=0;i<v.size();i++) znakovi[i]=nullptr;
		for(int i=0;i<v.size();i++){
			for(int j=0;j<v[i].size();j++){
				znakovi[i][j]=v[i][j];
				znakovi[i][j+1]='\0';
			}
		}
		
		return v.size();
	}
	catch(...){
		for(int i=0;i<brojac;i++) delete[] znakovi[i];
		delete [] znakovi;
		throw;
	}
}

int OdbaciOptuzbu(char **&imena, int vel, std::string s){
	
	int brojac(0);
	for(int i=0;i<vel;i++){
		if(imena[i]==nullptr) brojac++;
	}
	int k(0);
	if(brojac>=10){
		char **pok_new(new char*[vel-brojac]);
		for(int i=0;i<vel;i++){
			if(imena[i]!=nullptr){
				pok_new[k]=imena[i];
				k++;
			}
		}
		for(int i=0;i<vel;i++)delete [] imena[i];
		delete [] imena;
		return vel-brojac;
	}
	for(int i=0;i<vel;i++){
		if(imena[i]==s){
			delete [] imena[i];
			imena[i]=nullptr;
			return vel;
		}
	}
	throw std::domain_error(std::string("Osoba sa imenom ")+s+std::string(" nije bila optuzena"));
}

int DodajOptuzbu(char **&imena,int vel, std::string s){
	int z(0);
	char** pok_new;
	char* optuzeni;
	try{
		optuzeni=new char[s.size()+1];
		for(int i=0;i<s.size();i++) optuzeni[i]=s[i];
		optuzeni[s.size()]='\0';
		for(int i=0;i<vel;i++){
			if(imena[i]==nullptr){
				imena[i]=optuzeni;
				return vel;
		/*		delete [] imena[i];
				imena[i]=new char[s.size()+1];
				int j;
				for(j=0;j<s.size();j++) imena[i][j]=s[j];
				imena[i][j]='\0';  
				return;*/
			}
		}
		
	
		pok_new=new char *[vel+1];
		for(int i=0;i<vel;i++){
			if(imena[i]==nullptr) continue;
			int brojac(strlen(imena[i]));
			pok_new[z]=new char[brojac+1];
			z++;
		}
	//	pok_new[vel]=new char[s.size()+1];
		for(int i=0;i<vel;i++){
			int j;
			for(j=0;;j++){
				if(imena[i][j]=='\0') break;
				pok_new[i][j]=imena[i][j];
			}
			pok_new[i][j]='\0';
		}
		
	//	for(int i=0;i<s.size();i++) pok_new[vel][i]=s[i];
		pok_new[vel]=optuzeni;
	//	pok_new[vel][s.size()+1]='\0';
		char** p(imena);
		imena=pok_new;
		vel++;
		
		for(int i=0;i<vel-1;i++) delete[] p[i];
		delete [] p;
		return vel;
	}catch(...){
		for(int i=0;i<z;i++) delete[] pok_new[i];
		delete [] pok_new;
		throw ;
	}
	
	
}

void IzlistajOptuzbu(char **mat,int n){
	for(int i=0;i<n;i++){
		if(mat[i]==nullptr) continue;
		for(int j=0;j<strlen(mat[i]);j++){
			
			//if(mat[i][j]=='\0') break;
			std::cout << mat[i][j];
		}
		std::cout << std::endl;
	}
}

int main (){
	
	try{
		std::vector<std::string> v;
		int n;
		std::cout << "Koliko potencijalnih krivaca zelite unijeti?" << std::endl;
		std::cin >> n;
		v.resize(n);
		std::cin.ignore(10000,'\n');
		std::cout << "Unesite potencijalne krivce:" << std::endl;
		for(int i=0;i<n;i++){
			std::getline(std::cin,v[i]);
		}
		char**mat;
		n=PotencijalniKrivci(mat,v);
		int unos;
		do{
			std::cout << "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: " << std::endl;
			std::cin >> unos;
			if(unos==1){
				std::cin.ignore(10000, '\n');
				std::string s;
				std::cout << "Unesite ime novog optuzenog: " << std::endl;
				std::getline(std::cin,s);	//bez getline
				n=DodajOptuzbu(mat,n,s);
				
			}
			if(unos==2){
				std::cin.ignore(10000, '\n');
				std::string s;
				std::cout << "Unesite ime koje zelite izbaciti: " << std::endl;
				std::getline(std::cin,s);	//bez getline
				n=OdbaciOptuzbu(mat,n,s);
				
			}
			if(unos==3){
				IzlistajOptuzbu(mat,n);
			}
		}while(unos!=0);
		for(int i=0;i<n;i++) delete [] mat[i];
		delete [] mat;
	}
	catch(std::domain_error e){
		std::cout << e.what();
	}
	catch(...){
		std::cout << "Neuspjela alokacija" << std::endl;
	}
	
	
	return 0;
}