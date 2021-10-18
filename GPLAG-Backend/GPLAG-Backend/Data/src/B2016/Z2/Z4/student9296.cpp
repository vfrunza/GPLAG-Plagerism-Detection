/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include <vector>
#include <string>
#include <new>
#include <stdexcept>
#include <cstring>

int PotencijalniKrivci(char** &pok, std::vector<std::string> spisak){
	int brojac(0);
	try{
		pok=new char*[spisak.size()];
		try{
			for(int i=0; i<spisak.size(); i++) {
				pok[i]=new char[spisak[i].length()+1];
				brojac++;
			}
		}
		catch(std::bad_alloc){
			for(int i=0; i<brojac; i++) delete[] pok[i];
			delete[] pok;
			throw;
		}
	}
	catch(std::bad_alloc){
		throw;
	}
	int j;
	for(int i=0; i<spisak.size(); i++){
		for(j=0; j<spisak[i].length(); j++){
			pok[i][j]=spisak[i][j];
		}
		pok[i][j]='\0';
	}
	
	return brojac;
}
int OdbaciOptuzbu(char** &pok, int vel_niz_pok, std::string ime){
 	bool isti=true;
 	int br_nul_pok(0), nova_vel(-1), i;
 	for(i=0; i<vel_niz_pok; i++){
 		if(ime.length()==std::strlen(pok[i])){		//not sure da li se ovo treba deref mada msm da ipak treba UPDATE: ne treba, kompajler se buni lolz
	 		int j;
	 		for(j=0; j<ime.length(); j++){
	 			isti=true;
	 			if(pok[i][j]!=ime[j]){		//nije taj, trazi dalje
	 				isti=false;
	 				break;
	 				}
	 			}
	 		if(isti){
	 			int vel(ime.length());
	 			for(int k=0; k<vel-1; k++){
	 				pok[i][k]=pok[i][k+1];		//ja se nadam da ovo moze ovako
	 				vel--;
	 			}
	 			pok[i]=nullptr;
	 			br_nul_pok++;
	 			vel=vel_niz_pok;
	 			if(br_nul_pok>10){
	 				char**novi_pokazivaci;
		 			br_nul_pok=0;
		 			vel-=10;
		 			novi_pokazivaci=new char*[vel]; //alociramo novi niz pok, moze baciti
		 			int h(0);
					for(int k=0; k<vel; k++) if(pok[h]!=nullptr) novi_pokazivaci[k]=pok[h];
	 				for(int k=0; k<vel_niz_pok; k++) delete[] pok[k];
	 				delete[] pok;
	 				pok=novi_pokazivaci;		//ja se nadam da i ovo moze ovako
		 			nova_vel=vel;
	 			}
			}
		}
	}
 	if(!isti&&i==vel_niz_pok) throw std::domain_error ("Osoba sa imenom");	//fascinantno...ovo veze nemam kako da uradim kako treba al' hajd
 	if(nova_vel==-1) return vel_niz_pok;
 	return nova_vel;
 }

int DodajOptuzbu(char**&pok, int vel_niz_pok, std::string ime){
		char*novi=new char[ime.length()+1];
		for(int i=0; i<ime.length(); i++) novi[i]=ime[i];
		novi[ime.length()]='\0';
		int i;
		for(i=0; i<vel_niz_pok; i++){
			if(pok[i]==nullptr){
				pok[i]=novi;
				return vel_niz_pok;
			}
		}
		char**novi_novi=new char*[vel_niz_pok+1];
		for(i=0; i<vel_niz_pok; i++){
			novi[i]=*pok[i];
			delete[] pok[i];
		}
		novi_novi[vel_niz_pok]=novi;
		delete[] pok;
		pok=novi_novi;
		delete[] novi;
		for(i=0; i<vel_niz_pok+1; i++) delete[] novi_novi[i];
		delete[] novi_novi;
		
 	return vel_niz_pok+1;
 }
 
void IzlistajOptuzbu(char**pok, int vel){
	for(int i=0; i<vel; i++){
		if(pok[i]==nullptr) continue;
		std::cout<<pok[i]<<std::endl;
	}
}
int main ()
{
	try{
		std::cout<<"Koliko potencijalnih krivaca zeite unijeti?";
		int n;
		std::cin>>n;
		std::cin.ignore(100,'\n');
		std::cout<<std::endl<<"Unesite potencijalne krivce: "<<std::endl;
		char**pok;
		std::vector<std::string>spisak;
		for(int i=0; i<n; i++){
			std::string osoba;
			std::getline(std::cin, osoba);
			spisak.push_back(osoba);
		}
		int vel1, vel2;
		for(;;){
			std::cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: "<<std::endl;
			int opcija;
			std::cin>>opcija;
			std::cin.ignore(1000, '\n');
			int broj_alociranih(PotencijalniKrivci(pok, spisak));
			if(!std::cin){
				std::cin.clear();
				std::cin.ignore(1000, '\n');
			}
			else if(opcija==1){
				std::cout<<"Unesite ime novog optuzenog: "<<std::endl;
				std::string novi_optuzeni;
				std::getline(std::cin, novi_optuzeni);
				vel1=DodajOptuzbu(pok, spisak.size(), novi_optuzeni);
			}
			else if(opcija==2){
				std::cout<<"Unesite ime koje zelite izbaciti: ";
				std::string izbacen;
				std::getline(std::cin, izbacen);
				vel2=OdbaciOptuzbu(pok, spisak.size(), izbacen);
			}
			else if(opcija==0) break;
		}
	}
	catch(std::bad_alloc){}
	catch(std::domain_error){}
	return 0;
}