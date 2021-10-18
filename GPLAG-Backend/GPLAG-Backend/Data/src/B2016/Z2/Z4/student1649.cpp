/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	strcmp strcpy .c_str()
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stdexcept>
int PotencijalniKrivci(char** &Niz , std::vector<std::string> PotencijalniProdavaci ){
	int BrojNizova(PotencijalniProdavaci.size());
	Niz=new char* [BrojNizova];
	for(int i=0;i<BrojNizova;i++) Niz[i]=nullptr;
	try{
		for(int i=0;i<BrojNizova;i++) Niz[i]=new char[PotencijalniProdavaci.at(i).size()+1];
	}catch(...){
		for(int i=0;i<BrojNizova;i++) delete[] Niz[i];
		delete[] Niz;
		throw;
	}
	for(int i=0;i<BrojNizova;i++){
		for(int j=0;j<PotencijalniProdavaci.at(i).size();j++){
			Niz[i][j]=PotencijalniProdavaci.at(i).at(j);
		}
		Niz[i][PotencijalniProdavaci.at(i).size()]='\0'; //+1??
	}
	return BrojNizova;
}
int OdbaciOptuzbu(char** &Niz,int VelNiza,std::string Osoba){
	bool Postoji(false);
	for(int i=0;i<VelNiza;i++){
		if(Niz[i]!=nullptr){
			if(strcmp(Niz[i],Osoba.c_str())==0){
				Postoji=true;
				delete[] Niz[i];
				Niz[i]=nullptr;
				break;
			}
		}
	}
	if(!Postoji){
		std::string Poruka("Osoba sa imenom "+Osoba+" nije bila optuzena");
		throw std::domain_error(Poruka);
	}
	int NovaVelicina(0);
	for(int i=0;i<VelNiza; i++) if(Niz[i]!=nullptr) NovaVelicina++;
	if((VelNiza-NovaVelicina)<=10) return VelNiza;
	try{
		char** NoviNiz(new char* [NovaVelicina]);
		for(int i=0;i<NovaVelicina;i++) NoviNiz[i]=nullptr;
		try{
			int j(0);
			for(int i=0;i<VelNiza;i++){
				if(Niz[i]!=nullptr){
					NoviNiz[j]=(new char[strlen(Niz[i])+1]);
					strcpy(NoviNiz[j],Niz[i]);
					j++;
				}
			}
			for(int i=0;i<VelNiza;i++) delete[] Niz[i];
			delete[] Niz;
			Niz=NoviNiz;
			return NovaVelicina;
		}catch(...){
			for(int i=0;i<NovaVelicina;i++) delete[] NoviNiz[i];
			delete[] NoviNiz;
			return  VelNiza;
		}
	}catch(...){
		return VelNiza;
	}
}
int DodajOptuzbu(char** &Niz, int VelNiza,std::string Osoba){
	char* Pok(new char[Osoba.length()+1]);
	strcpy(Pok,Osoba.c_str());
	bool Ubacen(false);
	for(int i=0;i<VelNiza;i++){
		if(Niz[i]==nullptr){
			Niz[i]=Pok;
			Ubacen=true;
			break;
		}
	}
	if(!Ubacen){
		try{
			char** NoviNiz(new char* [VelNiza+1]);
			for(int i=0;i<VelNiza;i++) NoviNiz[i]=Niz[i];
			NoviNiz[VelNiza]=Pok;
			delete[] Niz;
			Niz=NoviNiz;
			VelNiza++;
		}catch(...){
			delete[] Pok;
			throw std::bad_alloc();
		}
	}
	return VelNiza;
}
void IzlistajOptuzbu(char** Niz,int VelNiza){
	for(int i=0;i<VelNiza;i++) if(Niz[i]!=nullptr) std::cout<<"\n"<<Niz[i];
}

int main()
{
	int Velicina;
	std::cout<<"Koliko potencijalnih krivaca zelite unijeti? ";
	std::cin>>Velicina;
	std::cin.ignore(100000,'\n');
	try{
		std::vector<std::string> Krivci(Velicina);
		std::cout<<"\nUnesite potencijalne krivce: ";
		for(auto &x:Krivci) std::getline(std::cin, x);
		try{
			char** Niz;
			Velicina=(PotencijalniKrivci(Niz,Krivci));
			while(1){
				std::cout<<"\nOdaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: ";
				int x;
				std::cin>>x;
				std::cin.ignore(100000,'\n');
				if(x==0) break;
				if(x==1){
					std::cout<<"\nUnesite ime novog optuzenog: ";
					std::string Ime;
					std::getline(std::cin,Ime);
					try{
						Velicina=DodajOptuzbu(Niz,Velicina,Ime);
					}catch(...){
						std::cout<<"Dodavanje nije uspjelo";
					}
				}
				if(x==2){
					std::cout<<"\nUnesite ime koje zelite izbaciti: ";
					std::string Ime;
					std::getline(std::cin,Ime);
					try{
						Velicina=OdbaciOptuzbu(Niz,Velicina,Ime);
					}catch(std::domain_error izuzetak){
						std::cout<<izuzetak.what();
					}
				}
				if(x==3) IzlistajOptuzbu(Niz,Velicina);
			}
			for(int i=0;i<Velicina;i++) delete[] Niz[i];
			delete[] Niz;
		}catch(...){
			throw;
		}
	}catch(...){
		std::cout<<"Greska";
	}
	return 0;
}