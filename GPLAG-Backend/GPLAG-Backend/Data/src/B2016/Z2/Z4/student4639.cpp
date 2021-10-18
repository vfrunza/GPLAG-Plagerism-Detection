/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>
#include <string.h>

int PotencijalniKrivci(char **&a,std::vector<std::string>v){
	
		
	try{
		
		a = new char *[v.size()];
		for(int i (0); i < v.size();i++){
			a[i] = nullptr;
		}
		
		
		try{
			
			//a = new char *[v.size()];
			
			for(size_t i = 0; i < v.size();i++){
					a[i] = new char [v.size() + 1];
					strcpy(a[i],v[i].c_str());
			}
			
			
			}catch(std::bad_alloc){
				
				for(int i (0); i < v[i].size();i++)
					delete[] a[i];
					
					delete [] a;
			}
			
			
		}catch(...){
			std::cout<<"Nedovoljno memorije!\n";
			throw;
		}
		
		//...VRATI VELICINU NIZA
		return v.size();
	
}

int OdbaciOptuzbu(char **&a,int vel,std::string s){
		//.....NE RADI dobro!
	int brojobr(0);
	
	//...UPOREDI
	int j = 0;
	for(int i (0); i < vel; i++){
		if(strcmp (a[i],s.c_str()) == 0){
			
			brojobr++;
			j = i;
			
			while(j + 1 < vel){
						a[j] = *&a[j + 1];
						
						if(j == vel - brojobr - 1){
							delete[] a[j];
						}
						
						j++;
			}
				
		}
			
	}	

	
	//....USTEDA
	
	if(brojobr > 10){
		
		char **novi = nullptr;
		
		try{
			novi = new char *[vel - brojobr];
			/*
			//...PREKOPIRA SE STARI NIZ POKAZIVACA U NOVI
			novi = a;
			//...UKLONI SE STARI NIZ POKAZIVACA
			a = nullptr;
			//...POSALJE SE NOVI POKAZIVAC
			a = novi;
			*/
			
			for(int i(0); i < vel - brojobr;i++){
				if(a[i] != nullptr){
					novi[i] = *&a[i];
				}
				delete[] a;
				
				a = novi;
			}
		}catch(std::bad_alloc){
			
			std::cout<<"Novi niz pokazivaca u OdbaciOptuzbu nije alociran!\n";
			for(int i (0); i < vel - brojobr;i++)
				delete [] novi[i];
			delete [] novi;
			throw;
			
		}catch(...){
			std::cout<<"Nedovoljno memorije!\n";
		}
	}
	return vel - brojobr;
}


int DodajOptuzbu(char **&a,int vel,std::string s){
	int brojdodan (0);
	
	char * niz = nullptr;
	
	try{
		//...DINAMICKI ALOCIRA NIZ
		niz = new char [s.size() + 1];
		//...PREPISI IZ STRINGA U NIZ
		strcpy(niz,s.c_str());
		
		brojdodan++;
	}catch(std::bad_alloc){
		std::cout<<"Niz DodajOptuzbu neuspijesno alociran!\n";
		delete[] niz;
		throw;
	}catch(...){
		std::cout<<"Nedovoljno memorije!\n";
	}	
		//... UKOLIKO JE NEKI NULLPTR NA NJEGA ZAKACI NOVI NIZ
		
		char ** novi = nullptr;
		
		try{
			novi = new char * [vel + brojdodan];
			for(int i (0); i < brojdodan + vel;i++ ){
				if (i < vel){
					if(a[i] != nullptr){
						novi[i] = *&a[i];
					}
				}else{
					novi[i] = niz;
				}
			}
			delete[] a;
			a = novi;
		}catch(std::bad_alloc){
			std::cout<<"Alokacija novog u DodajOptuzbu nije uspjela!\n";
			for(int i(0); i < vel + brojdodan;i++) delete [] novi[i];
			delete[] novi;
			throw;
		}
		return vel + brojdodan;
	
}

void IzlistajOptuzbu(char **a,int vel){
	char **pok = a;
	
	for(int i (0); i < vel ; i++){
		if(pok[i] == nullptr) continue;
		std::cout<<pok[i]<<std::endl;
	}
	
}

int main (){
	std::cout<<"Koliko potencijalnih krivaca zelite unijeti?\n";
	int n;
	std::cin >> n;
	std::cin.ignore(10000,'\n');
	
	std::cout<<"Unesite potencijalne krivce:\n";
	std::vector<std::string>k;
	std::string s;
	
	for(int i (0); i < n; i++){
		std::getline(std::cin,s);
		k.push_back(s);
	}
	
	char **pk = nullptr;
	try{
		int vel = PotencijalniKrivci(pk,k);
		try{ 
		int opcija = -1;
		
		while(opcija != 0){
			std::cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj:\n";
			std::cin >> opcija;
			
			if(opcija == 1){
			
				std::cout<<"Unesite ime novog optuzenog:\n";
				std::string c;
				std::cin.ignore(10000,'\n');
				std::getline(std::cin,c);
				
				try{
					vel = DodajOptuzbu(pk,vel,c);
				}catch(std::bad_alloc izuzetak){
					std::cout<<izuzetak.what()<<std::endl;
				}
				
				opcija = -1;
			}
			
			if(opcija == 2){
				
				std::cout<<"Unesite ime koje zelite izbaciti:\n";
				std::string p;
				std::cin.ignore(10000,'\n');
				std::getline(std::cin,p);
					
					try{
						vel = OdbaciOptuzbu(pk,vel,p);
					}catch(std::bad_alloc izuzetak){
						std::cout<<izuzetak.what()<<std::endl;
					}
					opcija = -1;
			}
			
			if(opcija  == 3){
				IzlistajOptuzbu(pk,vel);
				opcija = -1;
			}
			
			if(opcija == 0){
				
				break;
			}
		}
		
		
	}catch(std::bad_alloc izuzetak){
		std::cout<<izuzetak.what()<<std::endl;
	}
	
	}catch(std::bad_alloc izuzetak){
		std::cout<<izuzetak.what()<<std::endl;
	}
	return 0;
}
