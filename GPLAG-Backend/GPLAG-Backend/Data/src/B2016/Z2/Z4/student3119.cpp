/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stdexcept>

int PotencijalniKrivci (char **&a, std::vector<std::string> v){
	try{
		int br(0);
		a=new char*[v.size()];
		for(int i=0; i<v.size(); i++) a[i]=nullptr;
		try{
			for(int i=0; i<v.size(); i++){ 
				a[i]=new char[v[i].size()+1];
				br++;
				std::strcpy(a[i], v[i].c_str());
			}
		}
		catch(...){
			for(int i=0; i<v.size(); i++) delete[] a[i];
			delete[] a;
			throw;
		}
		
		return br;
	}
	catch(...){throw;}
}



int OdbaciOptuzbu( char **&a, int vel, std::string s){
	bool postoji(false);
	for(int i=0; i<vel; i++){
		int isti(0);
		isti=std::strcmp(a[i], s.c_str());
		if(isti==0) {
			delete [] a[i];
			a[i]=nullptr;
			postoji=true;
		}
	}
	if(postoji==false) throw std::domain_error ("Osoba sa imenom " + s +" nije bila optuzena"); /////////////
	
	//Provjera koliko ima nullptr pokazivaca
	int br(0);
	for(int i=0; i<vel; i++) if(a[i]==nullptr) br++;
	if(br>10){
		int broj_imena(0);
		for(int j=0; j<vel; j++) if(a[j]!=nullptr) broj_imena++;
		try{
			char **usteda(new char*[broj_imena]);
			for(int k=0; k<broj_imena; k++) usteda[k]=nullptr;
			try{
				int m(0);
				while(m<broj_imena){
					for(int z=0; z<vel; z++){
						if(a[z]!=nullptr){
							usteda[m]=new char[strlen(a[z])+1];
							std::strcpy(usteda[m], a[z]);
							m++;
						}
					}
				}
				
				//Ako je uspjelo kopiranje u novi dinamicki alocirani niz, brisemo stari
				for(int i=0; i<vel; i++) delete[] a[i];
				delete[] a;
				a=usteda;
				
				return broj_imena;
			}catch(...){
				//Ne treba da se baci izuzetak
				for(int l=0; l<broj_imena; l++) delete[] usteda[l];
				delete[] usteda;
			}
		}catch(...){ /*Ne treba da se baci izuzetak*/ }
	}
	
	return vel;
}




int DodajOptuzbu( char **&a, int vel, std::string s){
	try{
		char *pok(new char [s.size()+1]);
		std::strcpy(pok, s.c_str());
		bool postoji(false);
		for(int i=0; i<vel; i++){
			if(a[i]==nullptr){
				a[i]=pok;
				postoji=true;
				break;
			}
		}
		if(postoji==false){
			try{
				char** nova_alokacija(new char*[vel+1]);
				for(int i=0; i<vel+1; i++) nova_alokacija[i]=nullptr;
				try{
					for(int j=0; j<vel; j++){
						nova_alokacija[j]=new char[strlen(a[j])+1];
						std::strcpy(nova_alokacija[j], a[j]);
					}
					nova_alokacija[vel]=pok;
					//Brisanje starog niza pokazivaca
					for(int i=0; i<vel; i++) delete[] a[i];
					delete[] a;
					
					a=nova_alokacija;
					return vel+1;
				}catch(...){
					for(int i=0; i<vel+1; i++) delete[] nova_alokacija[i];
					delete[] nova_alokacija;
					throw;
				}
			}catch(...){ throw; }
		}
		
		return vel;
	}catch(...){ throw; }
	
}




void IzlistajOptuzbu(char** a, int vel){
	int i=0; 
	while(i<vel){
		if(a[i]==nullptr && i<vel-1) i++;
		else{
			if(i==vel-1) std::cout<<a[i];
			else std::cout<<a[i]<<std::endl;
			i++;
		}
	}
}




int main (){
	std::cout<<"Koliko potencijalnih krivaca zelite unijeti? ";
	int n;
	std::cin>>n;
	std::vector<std::string> v(n);
	std::cout<<std::endl<<"Unesite potencijalne krivce: ";
	std::cin.ignore(1000, '\n');
	for(int i=0; i<n; i++){
		std::string s;
		std::getline(std::cin, s);
		v[i]=s;
	}
	//for(int i=0; i<n; i++) std::cout<<v[i]<<" ";
	char** a;
	try{
		int vel_1 (PotencijalniKrivci(a, v));
		
		for(;;){
			std::cout<<std::endl<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: "<<std::endl;
			int broj;
			std::cin>>broj;
			if(broj==1){
				std::cout<<"Unesite ime novog optuzenog: ";
				std::string s;
				std::cin.ignore(1000, '\n');
				std::getline(std::cin, s);
				try{
					int vel_2(DodajOptuzbu(a, vel_1, s));
					vel_1=vel_2;
				}catch(...){ std::cout<<"Nedovoljno memorije"; }
			}
			else if(broj==2){
				std::cout<<"Unesite ime koje zelite izbaciti: ";
				std::cin.ignore(1000, '\n');
				std::string s;
				std::getline(std::cin, s);
				int vel_3 (OdbaciOptuzbu(a, vel_1, s));
				vel_1=vel_3;
			}
			else if(broj==3){
				IzlistajOptuzbu(a, vel_1);
			}
			else if(broj==0){ 
				for(int i=0; i<vel_1; i++) delete[] a[i];
				delete[] a;
				return 0;
			}
	}
	}
	catch(std::domain_error a){std::cout<<a.what();}
	catch(...){ std::cout<<"Nedovoljno memorije"; }
	
	
	
	return 0;
}