#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <stdexcept>
std::string cstringtostring(char *st1){
	std::string st1a("");
	while(*st1!='\0' && st1!=nullptr){
		st1a.push_back(*st1);
		st1++;
	}
	return st1a;
}
int PotencijalniKrivci(char **&a,std::vector<std::string> spisak){
	char **nizpokaz(nullptr);
	int br(0);
	int brljudi(0);
	for(int i=0; i<spisak.size();i++)
		if(spisak[i].size()!=0)brljudi++;
	if(brljudi!=0)
		try{
			nizpokaz=new char*[brljudi];
			for(int i=0; i<brljudi;i++)
				nizpokaz[i]=nullptr;
		}catch(std::bad_alloc){
			delete[] nizpokaz;
			throw std::bad_alloc();
		}
	
	for(int i=0; i<spisak.size(); i++){
		if(spisak[i].size()!=0){
			try{
				nizpokaz[i]=new char[spisak[i].size()+1];
				for(int j=0; j<spisak[i].size();j++)
					nizpokaz[i][j]=spisak[i][j];
				nizpokaz[i][spisak[i].size()]='\0';
				br++;
			}catch(std::bad_alloc){
				for(int j=0; j<brljudi; j++)
					delete[] nizpokaz[j];
				delete[] nizpokaz;
				throw std::bad_alloc();
			}
		}
	}
	a=nizpokaz;
	return br;
}
int DodajOptuzbu(char **&a,int vel,std::string nekoime){
	bool ima(false);
	int novavel(vel);
	for(int i=0; i<vel; i++)
		if(a[i]!= nullptr && nekoime.size()!=0 && cstringtostring(a[i])==nekoime){ima=true; break;}
	if(!ima){
		for(int i=0; i<vel;i++){
			if(a[i]==nullptr){
			//	char *novi(nullptr);
				try{
					a[i]= new char[nekoime.size()+1];
					int k=0;
					while(k<nekoime.size()){
						a[i][k]=nekoime[k];
						k++;
					}
					a[i][k]='\0';
					return vel;
				}catch(std::bad_alloc){
					delete[] a[i];
					a[i]=nullptr;
					throw std::bad_alloc();
				}
			}
		}
		
		char **noviniz(nullptr);
		try{
			noviniz=new char*[vel+1];
			for(int j=0; j<vel+1;j++)
				noviniz[j]=nullptr;
			for(int j=0; j<vel;j++)
				noviniz[j]=a[j];
			try{
				noviniz[vel]= new char[nekoime.size()+1];
				int k=0;
				while(k<nekoime.size()){
					noviniz[vel][k]=nekoime[k];
					k++;
				}
				noviniz[vel][k]='\0';
				novavel=vel+1;
				delete[] a;
				a=noviniz;
			}catch(std::bad_alloc){
				delete[] noviniz[vel];
				//delete[] noviniz;
				throw std::bad_alloc();
			}
		}catch(std::bad_alloc){
			delete[] noviniz;
			throw std::bad_alloc();
		}
		
	}else novavel=vel;
	return novavel;
}
int OdbaciOptuzbu(char **&a,int vel,std::string nekoime){
	bool ima(false);
	int novavel(vel);
	for(int i=0; i<vel; i++){
		if(a[i]!=nullptr && cstringtostring(a[i])==nekoime){
			ima=true;
			delete[] a[i];
			a[i]=nullptr;
			int brnul(0);
			for(int j=0; j<vel;j++){
				if (a[j]==nullptr)brnul++;
			}
			if(brnul>10){
				char **noviniz(nullptr);
				try{
					noviniz=new char*[vel-brnul];
					int k(0);
					for(int j=0; j<vel;j++){
						if(a[j]!=nullptr){noviniz[k]=a[j]; k++;}
					}
					for(int j=0; j<vel;j++)
						if(a[j]==nullptr)delete[] a[j];
					delete[] a;
					a=noviniz;
					novavel=vel-brnul;
					
				}catch(std::bad_alloc){
					delete[] noviniz;
				}
				
			}else novavel=vel;
		}
	}
	if(!ima)throw std::domain_error("Osoba sa imenom "+nekoime+" nije bila optuzena");
	return novavel;
}
void IzlistajOptuzbu(char **&a,int vel){
	for(int i=0; i<vel;i++){
		if(a[i]!=nullptr)std::cout<<a[i]<<std::endl;
	}
}
int main (){
/*	char **mate(nullptr);
	
	auto tz(PotencijalniKrivci(mate,{""}));
	std::cout<<tz;
	return 0;*/
	std::cout<<"Koliko potencijalnih krivaca zelite unijeti? "<<std::endl;
	int brpot(0);
	char **mat(nullptr);
	std::cin>>brpot;
	std::cin.ignore(10000,'\n');
	std::cout<<"Unesite potencijalne krivce: "<<std::endl;
	std::vector<std::string> lista(brpot);
	for(int i=0; i<brpot; i++){
		std::string un;
		std::getline(std::cin,un);
		lista[i]=un;
	}
	try{
		brpot=PotencijalniKrivci(mat,lista);
	}catch(...){}
	while(true){
		std::cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: "<<std::endl;;
		int opcija(0);
		std::cin>>opcija;
		std::cin.ignore(10000,'\n');
		if(opcija==0)break;
		if(opcija==1){
			std::cout<<"Unesite ime novog optuzenog: "<<std::endl;
			std::string imeop;
			std::getline(std::cin,imeop);
			try{
				brpot=DodajOptuzbu(mat,brpot,imeop);
			}catch(...){
				
			}
		}else if(opcija==2){
			std::cout<<"Unesite ime koje zelite izbaciti: "<<std::endl;
			std::string izbacime;
			std::getline(std::cin,izbacime);
			try{
				brpot=OdbaciOptuzbu(mat,brpot,izbacime);
			}catch(std::domain_error a){
				std::cout<<a.what()<<std::endl;
			}
		}else if(opcija==3){
			IzlistajOptuzbu(mat,brpot);
		}
	}
	for(int i=0; i<brpot;i++)
		delete[] mat[i];
	delete[] mat;
	return 0;
}