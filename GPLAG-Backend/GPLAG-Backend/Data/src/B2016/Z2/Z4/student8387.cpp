#include <iostream>
#include <vector>
#include <string>
#include <new>
#include <cstring>
#include <stdexcept>
void Dealociraj(char **&mat, int n){
 for(int i = 0; i < n; i++) delete[] mat[i];
 delete[] mat;
}
int PotencijalniKrivci(char **&pok,std::vector<std::string> v){
	int brojac(0);
	pok=nullptr;
	try{
		pok=new char*[v.size()];
		for(int i=0;i<v.size();i++)pok[i]=nullptr;;
		try{
			for(int i=0;i<v.size();i++){
				pok[i]=new char[v[i].size()+1];
				brojac++;
			}
			for(int i=0;i<v.size();i++){
				for(int j=0;j<v[i].size();j++)
					pok[i][j]=v[i][j];
			}
			for(int i=0;i<v.size();i++)pok[i][v[i].size()]='\0';
			return brojac;
		}
		catch(...){
			Dealociraj(pok,brojac);
			throw std::bad_alloc();
		}
	}
	catch(std::bad_alloc()){
		throw std::bad_alloc();
	}
}
int OdbaciOptuzbu(char **&pok,int vel,std::string ime){
	bool ima=false;
	int pozicija;
	for(int i=0;i<vel;i++){
		if(ime==pok[i]){
			ima=true;
			pozicija=i;
			break;
		}
	}
	if(ima){
		delete[]pok[pozicija];
		pok[pozicija]=nullptr;
	}
	else if(!ima){
		std::string poruka=std::string("Osoba sa imenom ")+ime+std::string(" nije bila optuzena");
		throw std::domain_error(poruka);
	}
	int br0(0);
	int brojac(0);
	for(int i=0;i<vel;i++){
		if(pok[i]==nullptr)br0++;
		brojac++;
	}
	if(br0<10)return brojac;
	char**p=nullptr;
	int a=brojac-br0;
	try{
		p=new char*[a];
		for(int i=0;i<a;i++)p[i]=nullptr;
		int i(0),j(0);
		try{
			while(i<vel && j<a){
				if(pok[i]!=nullptr){
					p[j]=new char[std::strlen(pok[i])];
					std::strcpy(p[j],pok[i]);
					j++;
				}
				i++;
			}
			Dealociraj(pok,vel);
			pok=p;
			return a;
		}
		catch(std::bad_alloc()){
			Dealociraj(p,a);
			throw std::bad_alloc();
		}
	}
	catch(std::bad_alloc()){
		return brojac;
	}
}
int DodajOptuzbu(char **&pok,int vel,std::string ime){
	bool ima=false;
	int pozicija0(-1);
	for(int i=0;i<vel;i++){
		if(pok[i]==nullptr){
			ima=true;
			pozicija0=i;
			break;
		}
	}
	if(ima){
		char *s=new char [ime.size()+1];
		for(int i=0;i<ime.size();i++)s[i]=ime[i];
		s[ime.size()]='\0';
		std::strcpy(pok[pozicija0],s);
		delete[] s;
		return vel;
	}
	else {
		char**p=nullptr;
		try{
			p=new char*[vel+1];
			for(int i=0;i<=vel;i++)p[i]=nullptr;
			try{
				for(int i=0;i<vel;i++){
					p[i]=new char[std::strlen(pok[i])+1];
					p[i][std::strlen(pok[i])]='\0';
				}
				for(int i=0;i<vel;i++)std::strcpy(p[i],pok[i]);
				p[vel]=new char[ime.size()+1];
				for(int i=0;i<ime.size();i++)p[vel][i]=ime[i];
				p[vel][ime.size()]='\0';
				Dealociraj(pok,vel);
				pok=p;
				return vel+1;
			}
			catch(std::bad_alloc()){
				Dealociraj(p,vel+1);
				throw std::bad_alloc();
			}
		}
		catch(std::bad_alloc()){
				return vel;
			}
		}
}
void IzlistajOptuzbu(char **pok,int vel){
	for(int i=0;i<vel;i++){
		if(pok[i]!=nullptr)std::cout<<pok[i]<<std::endl;	
	}
}
int main (){
	int n;
	std::cout<<"Koliko potencijalnih krivaca zelite unijeti? "<<std::endl;
	std::cin>>n;
	std::vector<std::string> v(n+1);
	std::cout<<"Unesite potencijalne krivce: "<<std::endl;
	for(int i=0;i<v.size();i++){
		std::getline(std::cin,v[i]);
	}
	char **pok;
	int opcija(-1);
	try{
		int brojac=PotencijalniKrivci(pok,v);
		for(;;){
			std::cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: "<<std::endl;
			std::cin>>opcija;
			std::cin.ignore(1000,'\n');
			switch(opcija){
				case 1:{
						std::cout<<"Unesite ime novog optuzenog: "<<std::endl;
						std::string optuzeni;
						std::getline(std::cin,optuzeni);
						try{
							brojac=DodajOptuzbu(pok,brojac,optuzeni);
						}
						catch(...){
							std::cout<<"Memorija!";
						}
						break;
				}
				case 2:{
						std::cout<<"Unesite ime koje zelite izbaciti: "<<std::endl;
						std::string neki;
						std::getline(std::cin,neki);
						try{
							brojac=OdbaciOptuzbu(pok,brojac,neki);
						}
						catch(std::domain_error poruka){
							std::cout<<poruka.what();
						}
						catch(std::bad_alloc()){
							std::cout<<"Memorija!";
						}
						break;
				}
				case 3:{ IzlistajOptuzbu(pok,brojac);
						break;
				}
				
			}
			if(opcija==0)break;
		}
		Dealociraj(pok,brojac);
	}
	catch(...){std::cout<<"Memorija!";}
	return 0;
}