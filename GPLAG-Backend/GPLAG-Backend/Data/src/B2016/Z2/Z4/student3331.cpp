/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include <new>
#include <cstring>
#include <stdexcept>
#include <vector>
#include <string>
#include <new>


int PotencijalniKrivci(char **&znakovi, std::vector<std::string> imena) {
	int brojAlociranih=0; 
	
	try{
		
		znakovi = new char *[int(imena.size())];
	}catch(...) {
		delete[] znakovi;
		throw std::bad_alloc();
	}
	
		for(int i=0; i<imena.size(); i++)
			znakovi[i] = nullptr;
			
			try {
		    for(int i=0; i<imena.size(); i++) {
			znakovi[i] = new char[imena[i].length()+1];
				std::strcpy(znakovi[i], imena[i].c_str());
			brojAlociranih++;
		}
		    }catch(...) {
		    	for(int i=0; i<imena.size(); i++)
		           delete[] znakovi[i];
		           delete[] znakovi;
		           throw std::bad_alloc();
		    }
	
	return brojAlociranih;
}


int OdbaciOptuzbu(char **&znakovi, int velicinaNizaPok, std::string finaOsoba) {
	int k=0,brojac=0,velN=0,brojacNULL=0;
	char *pok = nullptr,*p=nullptr;
	char **gdje = nullptr;
	gdje = znakovi;
	bool jelObrisan = false;

	//provjera osobe
	for(int i=0; i<velicinaNizaPok; i++) {
		brojac=0;
		k=0;
		if(znakovi[i] == nullptr) brojacNULL++;
		else{
			p= znakovi[i];
		while (*p != '\0' && k < finaOsoba.length()) {
			if(*p == finaOsoba[k]) brojac++;
			k++;
			p++;
		}
		}
		if(brojac != finaOsoba.length()) velN++;
	}
	if(velN == velicinaNizaPok) throw std::domain_error("Osoba sa imenom " + finaOsoba + " nije bila optuzena");
	znakovi = gdje;
	velN=0;
	for(int i=0; i<velicinaNizaPok; i++) {
		brojac=0;
		k=0;
		pok = znakovi[i];
		velN++;
		
		if(*pok == finaOsoba[0] && !jelObrisan) {
		while (*pok != '\0' && k < finaOsoba.length()) {
			if(*pok == finaOsoba[k]) brojac++;
			pok++;
			k++;
		}
		if(brojac == finaOsoba.length()) {
			delete[] znakovi[i]; 
			znakovi[i] = nullptr;
			brojacNULL++;
			jelObrisan = true;
	
		
			}
		
		}
	}
		k=0;
		if(brojacNULL >= 10) { //ovo
			velN=0;
			char **pokazivaci= nullptr,**poc=nullptr;
			try{
			pokazivaci = new char*[velicinaNizaPok-brojacNULL];
		
			poc= pokazivaci;
			for(int i=0; i<velicinaNizaPok-brojacNULL; i++)
			pokazivaci[i] = nullptr;
			for(int i=0; i<velicinaNizaPok; i++) {
				if(znakovi[i] != nullptr){ pokazivaci[k] = znakovi[i]; k++; velN++;}
			}
			
			}catch(... ) {
				delete[] pokazivaci;
			}
			
			delete[] znakovi;
			znakovi = poc;
		}
	
	return velN; 
}


int DodajOptuzbu(char **&znakovi, int velicinaNizaPok, std::string prepisivac) {
	bool jest = false;
	char **pok = nullptr;
	char *p = nullptr,*k=nullptr;
	

	try{
	p = new char[prepisivac.length()+1];
	k=p;
	}catch(...) {
		delete[] p;
		throw std::bad_alloc();
	}
		std::strcpy(p,prepisivac.c_str());
		
	for(int i=0; i< velicinaNizaPok; i++)
	  if(znakovi[i] == nullptr){ znakovi[i] = p;  jest = true; break;}
	  
	if(!jest) {
		
		try {
		pok = new char *[velicinaNizaPok+1];
		}catch(...) {
			delete[] pok;
			throw std::bad_alloc();
		}
	
	try{
		for(int i=0; i< velicinaNizaPok; i++)
		pok[i] = znakovi[i];
		pok[velicinaNizaPok] = k;
	}catch(...){
		delete[] pok;
		throw std::bad_alloc();
	}
		velicinaNizaPok+=1;
		delete[] znakovi;
		znakovi = pok;
	}
	
	
	return velicinaNizaPok;
}


void IzlistajOptuzbu(char **znakovi, int vel) {
	char *p = nullptr;
	
		for(int i=0; i<vel; i++) {
  		p = znakovi[i];
  		if(p != nullptr) {
			while(*p != '\0') {
				std::cout<<*p;
				p++;
			}
			std::cout<<std::endl;
		
				
  		}
		}
}



int main ()
{
	std::cout<<"Koliko potencijalnih krivaca zelite unijeti? "<<std::endl;
	int brEl,unos;
	std::cin>>brEl;
	std::cout<<"Unesite potencijalne krivce: "<<std::endl;
	std::vector<std::string> imena;
	std::string ime,drugo;
	std::cin.ignore(10000,'\n');
	while (brEl) {
		std::getline(std::cin,ime);
		imena.push_back(ime);
		brEl--;
	}
	char **znakovi= nullptr;
	int vel=0;
    try{
	vel =PotencijalniKrivci(znakovi,imena);
	
	do{
	std::cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: "<<std::endl;
	std::cin>>unos;
	if(unos == 0)break;
	switch(unos){
		case 1: 
			std::cout<<"Unesite ime novog optuzenog: "<<std::endl;
			std::cin>>drugo;
		vel= DodajOptuzbu(znakovi,vel,drugo);
		break;
	
		
		case 2:
	
		std::cout << "Unesite ime koje zelite izbaciti: "<< std::endl;
		std::cin>>drugo;
		vel = OdbaciOptuzbu(znakovi,vel,drugo);
		break;
		
		case 3: IzlistajOptuzbu(znakovi,vel); break;
	}
	}while(unos != 0);
	
	for(int i=0; i< vel; i++)
		 delete[] znakovi[i];
		delete[] znakovi;
	

}
catch(std::bad_alloc b) {
	std::cout<< b.what() <<std::endl;
}catch(std::domain_error e) {
	std::cout << e.what() << std::endl;
}
	return 0;
}