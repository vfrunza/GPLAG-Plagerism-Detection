#include<iostream>
#include<stdexcept>
#include<vector>
#include<string>
#include<cstring>
using namespace std;
int PotencijalniKrivci(char **&niz,vector<string> imena){
	//char** pomocniNiz;
	try{
		niz=new char*[imena.size()];
		try{
		for(int i(0);i<imena.size();i++){
			niz[i]=nullptr;
		}
		for(int i(0);i<imena.size();i++){
			niz[i]=new char [imena[i].size()+1];
		for(int j(0);j<imena[i].size();j++){
		   niz[i][j]=imena[i][j];
		}
		niz[i][imena[i].size()]='\0';
		}
		return imena.size();
	}
	catch(...){
		for(int i(0);i<imena.size();i++){
		delete[] niz[i];
	}
	delete[] niz;
		throw bad_alloc();
	}
	}
	catch(...){
		delete[] niz;
		throw bad_alloc();
}
}
int OdbaciOptuzbu( char **& niz,int vel, string nevin){
	bool pronadjen =false;
	for(int i(0);i<vel;i++){
		string pomocniString="";
		char *tmp=niz[i];
		while(*tmp!='\0'){
			pomocniString+=*tmp;
			tmp++;
		}
		int br(0);
		if(pomocniString==nevin){
			pronadjen=true;
			delete[] niz[i];
			niz[i]=nullptr;
			for(int j(0);j<vel;j++)
				if(!niz[j]) br++;
				if(br>10){
					int Novavelicina=vel - br;
					char **pomocniNiz=new char*[Novavelicina];
					int k=0;
					for(int j(0);j<vel;j++){
						if(niz[j]!=nullptr){
							pomocniNiz[k]=niz[j];
							k++;
						}
					}
					delete [] niz;
					niz=pomocniNiz;
					return Novavelicina;
				}
				return vel;
			
			
		}
		
	}
	if(!pronadjen)
		throw domain_error("Osoba sa imenom"+ nevin +"nije bila optuzena");
}
int DodajOptuzbu( char **& niz,int vel, string optuzen){
	bool pronadjen=false;
	char*nizznakova;
	try{
	nizznakova=new char[optuzen.size()+1];
	for(int i(0);i<optuzen.size();i++){
		nizznakova[i]=optuzen[i];
	}
	nizznakova[optuzen.size()]='\0';
	for(int i(0);i<vel;i++){
		if(niz[i]==nullptr){
			pronadjen=true;
		niz[i]=nizznakova;
		break;
	}
	}
	if(pronadjen==false){
		char**novi;
		novi=new char*[vel+1];
		for(int i(0);i<vel;i++){
			novi[i]=niz[i];
		}
		novi[vel]=nizznakova;
		//for(int i(0);i<vel;i++)
		delete[] niz;
		niz=novi;
	}
}
catch(...){
	delete[] nizznakova;
	throw bad_alloc();
}
return vel+1;
}
void IzlistajOptuzbu( char **pok,int vel){
	for(int i(0);i<vel;i++){
		if(pok[i]!=nullptr)
		cout<<pok[i]<<endl;
	}
}
int main ()
{
	int n=3,m=5;
	int vel;
	char **pok;
	
	vector<string> imena;
	string rijec;
	try{
		cout<<"Koliko potencijalnih krivaca zelite unijeti?"<<endl;
		cin>>n;
		cout<<"Unesite potencijalne krivce: "<<endl;
		for(int i(0);i<n;i++){
			cin>>rijec;
			imena.push_back(rijec);
		}
		vel=PotencijalniKrivci(pok,imena);
		do{
		cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: "<<endl;
		cin>>m;
		if(m==1){
			cout<<"Unesite ime novog optuzenog: "<<endl;
				cin>>rijec;
		vel=DodajOptuzbu(pok,vel,rijec);
		}
		if(m==2){
			cout<<"Unesite ime koje zelite izbaciti: "<<endl;
		cin>>rijec;
		vel=OdbaciOptuzbu(pok,vel,rijec);
		}
		if(m==3){
			IzlistajOptuzbu(pok,vel);
		}
		
		if(m==0)
		break;
		}while(m!=0);
	
	for(int i(0);i<vel;i++){
	delete[] pok[i];
	}
	delete[] pok;
	}
	catch(...){
		delete[] pok;
		cout<<"Nedovoljno memorije"<<endl;
	}
	return 0;
}