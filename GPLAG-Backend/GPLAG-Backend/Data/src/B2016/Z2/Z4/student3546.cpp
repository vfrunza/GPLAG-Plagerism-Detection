#include <iostream>
#include <new>
#include <string>
#include <vector>
#include <cstring>
#include <stdexcept>

using std::cin;
using std::cout;

int PotencijalniKrivci(char **&pok,std::vector<std::string> v){
	try{
		char **c(new char*[v.size()]);
		for(int i=0;i<v.size();i++) c[i]=nullptr;
		try{
			for(int i=0;i<v.size();i++) {
				c[i]=new char[v[i].length()+1];
				std::strcpy(c[i],v[i].c_str());
				}
			pok=c;
			return v.size();
		}
		catch(std::bad_alloc){
			for(int i=0;i<v.size();i++) delete[] c[i];
			delete c;
			throw;
		}
	}
	catch(std::bad_alloc){
		throw;
	}
}

int OdbaciOptuzbu(char **&pok,int vel,std::string s){
	int brojac(0);
	bool pronadjen(false);
	for (int i=0;i<vel;i++){
		if(std::strcmp(pok[i],s.c_str())==0){
			brojac++;
			delete[] pok[i];
			pok[i]=nullptr;
			pronadjen=true;
		}
		if(brojac>10){
			try{
				vel=vel-11;
				char** novi(new char *[vel]);
				for(int j=0;j<vel;j++){
					for(int k=0;k<vel+11;j++){
						if(pok[k]!=nullptr){
							novi[j]=pok[k];
							pok[k]=nullptr;
						}
					}
				}
				delete[] pok;
				pok=novi;
			}
			catch(...){
				vel=vel+11;
			}
		}
	}
	if(!pronadjen){
		throw std::domain_error("Osoba sa imenom "+s+" nije bila optuzena");
	}
	return vel;
}

int DodajOptuzbu(char **&pok,int vel, std::string s){
	try{
		char*p=new char[s.length()+1];
		std::strcpy(p,s.c_str());
		int i;
		for(i=0;i<vel;i++){
			if(!pok[i]) {
				pok[i]=p;
				break;
			}
		}
		if(i==vel){
			try{
				vel=vel+1;
				char **novi=new char*[vel];
				for(int j=0;j<vel;j++){
					if(j==vel-1)
					novi[j]=p;
					else
					novi[j]=pok[j];
				}
			delete[] pok;
			pok=novi;
			}
			catch(std::bad_alloc){
				vel=vel-1;
				delete[] p;
				throw;
			}
		}
		return vel;
	}
	catch(std::bad_alloc){
		throw;
	}
}

void IzlistajOptuzbu(char **pok,int vel){
	for(int i=0;i<vel;i++){
		if(pok[i]==nullptr) continue;
		else
		cout<<pok[i]<<std::endl;
	}
}

int main ()
{
	cout<<"Koliko potencijalnih krivaca zelite unijeti?"<<std::endl;
	int n;
	cin>>n;
	cin.ignore(1000,'\n');
	std::vector<std::string> v(3);
	cout<<"Unesite potencijalne krivce: "<<std::endl;
	for(int i=0;i<n;i++){
		std::getline(cin,v[i]);
	}
	char **pok;
	int vel=PotencijalniKrivci(pok,v);
	int opcija;
	int vel1(vel);
	int vel2(vel);
	int velkr(vel);
	do{
	cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: "<<std::endl;
	cin>>opcija;
	cin.ignore(1000,'\n');
	if(opcija!=0 && opcija!=1 && opcija!=2 && opcija!=3){
		cout<<"Nepostojeca opcija, ponovite unos: ";
	}
	else if(opcija==1){
		cout<<"Unesite ime novog optuzenog: "<<std::endl; 
		std::string s; 
		std::getline(cin,s); 
		vel1=DodajOptuzbu(pok,vel,s);
		velkr=vel1;
	}
	else if(opcija==2){
		cout<<"Unesite ime koje zelite izbaciti: "<<std::endl; 
		std::string s1; 
		std::getline(cin,s1); 
		vel2=OdbaciOptuzbu(pok,vel1,s1);
		velkr=vel2;
	}
	else if(opcija==3){
		IzlistajOptuzbu(pok,vel2);
	}
	}while(opcija!=0);
	for(int i=0;i<velkr;i++) delete[] pok[i];
	delete[] pok;
	return 0;
}