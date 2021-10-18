#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<stdexcept>

int PotencijalniKrivci(char **& znak, std::vector<std::string>s){
	int br=0;
	try{
		znak=new char *[s.size()];
		while(br<s.size()){
			znak[br]=new char[s[br].size()+1];
			std::strcpy(znak[br],s[br].c_str());
			br++;
		}
		return br;
	}
	
	catch(...){
		for(int i=0;i<br;i++) delete [] znak[i];
		delete[] znak;
		throw ;
	}
}

int  OdbaciOptuzbu (char **&znak, int niz_pok, std::string s){
	int izbrisano=0;
	for(int i=0;i<niz_pok;i++){
		if(znak[i]!=nullptr && std::strcmp(znak[i],s.c_str())==0){
			delete[] znak[i];
			znak[i]=nullptr;
			izbrisano++;
		}
	}
	
	if(izbrisano==0) throw std::domain_error ("Osoba sa imenom "+s+" nije bila optuzena\n");
	if(izbrisano>10){
		char **ime;
		int br=0;
		try{
			ime=new char *[niz_pok-izbrisano];
			for(int i=0;i<niz_pok;i++){
				if(znak[i]!=nullptr){
				   ime[br]=new char[std::strlen(znak[i])+1];
				   std::strcpy(ime[br],znak[i]);
				   br++;
				}
			}
			
			for(int i=0;i<niz_pok;i++) delete[] znak[i];
			delete [] znak;
			znak=ime;
			return br;
		}
		catch(...){
			for(int i=0;i<br;i++) delete[] ime[i];
			delete [] ime;
		}
	}
 	return niz_pok;
}


int DodajOptuzbu(char **&znak, int vel,std::string s){
	char *pok=new char[s.size()+1];
	std::strcpy(pok,s.c_str());
	bool ima=false;
	for(int i=0;i<vel;i++){
		if(znak[i]==nullptr){
			znak[i]=pok;
			ima=true;
			break;
		}
	}
	
	if(!ima){
		char **novi;
		try{
			novi=new char *[vel+1];
			for(int i=0;i<vel;i++){
				novi[i]=new char[std::strlen(znak[i])+1];
				std::strcpy(novi[i],znak[i]);
			}
			novi[vel]=pok;
			
			for(int i=0;i<vel;i++) delete[]znak[i];
			delete [] znak;
			
			znak=novi;
			return vel+1;
		}
		catch(...){
			for(int i=0;i<vel+1;i++) delete[]novi[i];
			delete[]novi;
			throw;
		}
	}
	
	return vel;
}

void IzlistajOptuzbu(char **znak, int vel){
	for(int i=0;i<vel;i++){
		if(znak[i]!=nullptr) std::cout<<znak[i]<<std::endl;
	}
}

int main ()
{
	std::cout<<"Koliko potencijalnih krivaca zelite unijeti? ";
	int n;
	std::cin>>n;
	char **znak;
	std::cout<<"\nUnesite potencijalne krivce: ";
	std::vector<std::string>v;
	std::cin.ignore(1000,'\n');
	for(int i=0;i<n;i++){
		std::string s;
		std::getline(std::cin,s);
		v.push_back(s);
	}
	std::cout<<std::endl;
	int vel;
	try{
	vel=PotencijalniKrivci(znak,v);
	for(;;){
	std::cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj:\n";
		int a;
		std::cin>>a;
		std::cin.ignore(1000,'\n');
		if(a==1) {
			std::cout<<"Unesite ime novog optuzenog:\n";
			std::string s;
			std::getline(std::cin,s);
			try{
				vel=DodajOptuzbu(znak,vel,s);
			}
			
			catch(...){
				std::cout<<"Nema memorije!";
				throw;
			}
		}
		if(a==2){
			std::cout<<"Unesite ime koje zelite izbaciti:\n";
			std::string s;
			std::getline(std::cin,s);
			try{
			vel=OdbaciOptuzbu(znak,vel,s);
			}
			catch(std::domain_error e){
				std::cout<<e.what();
			}
		}
		if(a==3) {std::cout<<std::endl; IzlistajOptuzbu(znak,vel);}
		if(a==0) break;
	  }
	  
	  for(int i=0;i<vel;i++) delete [] znak[i];
	  delete [] znak;
	}
	
	catch(...){
		for(int i=0;i<vel;i++) delete[]znak[i];
		delete[]znak;
	}
	
	return 0;
}