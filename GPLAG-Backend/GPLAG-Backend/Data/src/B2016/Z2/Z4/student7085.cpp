#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <new>
#include <string>


typedef std:: vector<std::string> vekstring;

void IzlistajOptuzbu(char ** mat, int &velicina){
	for(int i=0;i<velicina;i++){
		if(mat[i]==nullptr)continue;
		else{
			std::cout<<mat[i]<<std::endl;
		}
	}
}

int PotencijalniKrivci( char **&ime, vekstring krivci ){
	
	int brojac(0);
	ime=nullptr;
	try{
		ime=new char*[krivci.size()];
		   for (int i=0;i<krivci.size ();i++) 
		   ime [i]=nullptr;
		try{
			
		   for(int i=0;i<krivci.size();i++){
			  ime[i]=new char[krivci[i].size()+1];
			  brojac++;
		   }
		   for(int i=0;i<krivci.size();i++){
		   	for(int j=0;j<krivci[i].size();j++){
		   		ime[i][j]=krivci[i][j];
		   	}
		   	ime[i][krivci[i].size()]='\0';
		   }
		   return brojac;
		}        
		catch(std::bad_alloc){
			for(int i=0;i<brojac;i++) delete[]ime[i];
		    delete[]ime;
			throw;
		}
	}
	catch(std::bad_alloc){
		throw  ;
	}
}

int OdbaciOptuzbu( char **& ime, int &velicina, std::string potencijalni){
	int index=7877;
	bool postoji(true);
	bool ima=false;
	for(int i=0;i<velicina;i++){
		postoji=true;
		if(ime[i]!=nullptr)
		{
			int broj=0;
		char* p= ime[i];
		while(*p!='\0'){
			p++;
			broj++;
		}
		if(broj== potencijalni.size()){
		for(int j=0;j<potencijalni.size();j++)
		if(ime[i][j]!=potencijalni[j]) {  postoji=false; }
		if(postoji){
		index=i;
		ima=true;
		break;
		}
		}
		}
	}
	if(!ima)
	throw std::domain_error("Osoba sa imenom "+potencijalni+ " nije bila optuzena");
	else {
			delete[]ime[index];
			ime[index]=nullptr;
		int brojac(0);
		for(int i=0;i<velicina;i++){
			if(ime[i]==nullptr)brojac++;
		}
		if(brojac<=10)return velicina;
		else{
			
			char** pok=nullptr;
			try{
				pok=new char*[velicina - brojac];
				for(int i=0;i<velicina-brojac;i++)
				pok[i]=nullptr;
				
				int br(0);
				for(int i=0;i<velicina;i++){
					if(ime[i]!=nullptr){
						pok[i]=ime[i];
						br++;
					}
				}
				pok=ime;
				ime=nullptr;
				return br;
			}
			
			catch(...){
				return velicina;
			}
		}
	}
}

int DodajOptuzbu( char ** &mat, int &velicina, std::string s){
	char* pok=nullptr;
	try{
		pok=new char[s.size()+1];
		for(int i=0;i<s.size();i++){
			pok[i]=s[i];
		}
		pok[s.size()]='\0';
		for(int i=0;i<velicina;i++){
			if(mat[i]==nullptr){ 
				mat[i]=pok;
				return velicina;
			}
		}
			char** novi=nullptr;
			try{
				novi=new char*[velicina+1];
				for(int i=0;i<velicina+1;i++)
				novi[i]=nullptr;
				for(int i=0;i<velicina;i++){
					novi[i]=mat[i];
				}
				novi[velicina]=pok;
				mat = novi;
				novi = nullptr;
			
				return velicina+1;
				
			}
			catch(std::bad_alloc ){
				for(int i=0;i<velicina+1;i++){
					delete[]novi[i];
				}
				throw ;
			}
	}
	catch(std::bad_alloc ){
		throw ;
	}
}

int main ()
{
	int v,opcija;
	std::string s,s1,s2,s3;
	vekstring vs;
	char **mat ;
	std::cout<<"Koliko potencijalnih krivaca zelite unijeti? ";
	std::cin>> v;

	std::cout<<"\nUnesite potencijalne krivce: "<<std::endl;

	try{
	for(int i=0;i<=v;i++){
		std::getline(std::cin,s);
		vs.push_back(s);
	}

	 v= PotencijalniKrivci(mat,vs);
	
	while(1==1){
	std::cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: ";
	std::cin>> opcija;
//	std::cin.clear();
	if(opcija==3){
		IzlistajOptuzbu(mat,v);
	}
	if(opcija==2){
		std::cout<<"\nUnesite ime koje zelite izbaciti: "<<std::endl;
	//	std::cin.ignore(1000,'\n');
		std::cin>>s2;
	//	try{
		v=OdbaciOptuzbu(mat,v,s2);
//		}
	//	catch(std::domain_error e) {
	//	std::cout<<e.what()<<std::endl;
	//	for(int i=0;i<v;i++) delete[]mat[i];
	//	delete[] mat;
	//	return 0;
//		}
	}
	if(opcija==1){
		std::cout<<"\nUnesite ime novog optuzenog: "<<std::endl;
	//	std::cin.ignore(1000,'\n');
		std::cin>>s1;
//		try{
		v=DodajOptuzbu(mat,v,s1);
	//	}catch(std::bad_alloc){
		//	for(int i=0;i<v;i++)
		//	delete[]mat[i];
		//	delete[]mat;
		//	throw;
			
	//	}
	}
	
	if(opcija==0)break;
	}
	}
	catch(std::domain_error e){
		std::cout<<e.what()<<std::endl;
	//	for(int i=0;i<v;i++) delete[] mat[i];
	//	delete[]mat;
	//	return 0;
	}
	
	catch(std::bad_alloc){
	//	for(int i=0;i<v;i++) delete [] mat[i];
	//	delete[]mat;
		return 0;
	}
	
	for(int i=0;i<v;i++){
		delete[] mat[i];
	}
	delete[] mat;
	
     
	return 0;
}

