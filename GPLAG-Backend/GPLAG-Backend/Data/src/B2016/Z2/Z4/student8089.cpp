#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <stdexcept>

int PotencijalniKrivci (char **(&pok), std::vector<std::string> imenaKrivaca){
	int brojac(0);
	int brojKrivaca = imenaKrivaca.size();
	
	try{
		char **a(new char* [brojKrivaca]);
		
		for (int i = 0; i < brojKrivaca; i++) {
			int duzinaImena = imenaKrivaca[i].length();
			try{
			a[i] = new char [duzinaImena+1];
			int j;
			for (j = 0; j < duzinaImena; j++) {
				a[i][j] = imenaKrivaca[i][j];
			}
			a[i][j] = '\0';
			
			brojac++;
			}
			catch (std::bad_alloc e){
				throw;
			}
		}
		pok = a;
		
	}
	catch (std::bad_alloc e){
		
		std::cout << e.what() << std::endl;
	}


	return brojac;
} //Fja valjda radi

int OdbaciOptuzbu (char **(&pok), int n, std::string ime){
	char niz[100];
	int internibrojac(0);

	std::strcpy(niz, ime.c_str());

	
	bool uSistemu(false);
	for (int i = 0; i < n; i++) {
		if (pok[i] == nullptr) {
			continue;
		}
		
		if (std::strcmp(pok[i], niz)==0) {
			uSistemu=true;
			delete [] pok[i];
			pok[i]=nullptr;
			internibrojac++;
		}
	}
	if (!uSistemu) 	throw std::domain_error ("Osoba sa imenom " + ime + " nije bila optuzena");
	
	
	if (internibrojac > 10) {
		
		try{
			char **a(new char* [n-internibrojac]);
			
			int i;
			for (i = 0; i < n-internibrojac; i++) {
				if (a[i] != nullptr) {a[i] = pok[i];}
			}
			
			pok = a;
			return n-internibrojac;
		}
		
		catch (std::bad_alloc e){
			std::cout << e.what() << std::endl;
		}
	} //Ovo se ne testir
	

	return n;
}

int DodajOptuzbu (char **(&pok), int n, std::string ime){
	
	char* poky = new char[ime.length()+1];
	int i;
	for (i = 0; i < ime.length(); i++) {
		poky[i] = ime[i];
	}
	poky [i] = '\0';
	
	for (i = 0; i < n; i++) {
		if (pok[i] == nullptr) {
			
			pok[i] = poky;
	
		
			
			return n;
		}
	} //izgleda ok
	
	try{
		char **a(new char* [n+1]);
		
		int i;
		for (i = 0; i < n; i++) {
			a[i] = pok[i]; 
			pok[i] = nullptr;
			
		}
		
		
		a[i]=poky;
		
	
		
	
		pok = a;
	}
	catch (std::bad_alloc e){
		std::cout << e.what() << std::endl;
	}
	
	return n+1;
}

void IzlistajOptuzbu(char **(&pok), int n){
	for (int i = 0; i < n; i++) {
		if (pok[i] != nullptr) {
			std::cout << pok[i] << std::endl;
		}
	
	}
} 

int main (){
	
	int brPotKriv;
	std::cout << "Koliko potencijalnih krivaca zelite unijeti?" << std::endl;
	std::cin >> brPotKriv;
	
	std::vector<std::string> imenaKrivaca (brPotKriv);
	
	std::cout << "Unesite potencijalne krivce: " << std::endl;
	for (int i = 0; i < brPotKriv; i++) {
		std::cin >> imenaKrivaca[i];
	}
		
	char **pok=nullptr;
	int a;
	
	try{
	a = PotencijalniKrivci(pok, imenaKrivaca);
	
	for(;;) {
		std::cout << "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: "<< std::endl;
		std::cin >> brPotKriv;
		if (brPotKriv == 0) {
			break;
		}
		else if (brPotKriv == 1){
			std::cout << "Unesite ime novog optuzenog: "<< std::endl;
			std::string ime;
			std::cin.ignore(10000, '\n');
			std::cin >> ime;
			
			a= DodajOptuzbu(pok, a, ime);
		}
		else if (brPotKriv == 2){
			std::cout << "Unesite ime koje zelite izbaciti:  "<<std::endl;
			std::string ime;
			std::cin.ignore(10000, '\n');
			std::cin >> ime;
			
			
			a= OdbaciOptuzbu(pok, a, ime);
		}
		else if(brPotKriv == 3){
			IzlistajOptuzbu(pok, a);
		}
	}
	}
	catch(std::bad_alloc e){
		for (int i = 0; i < a; i++) {
			delete [] pok[i];
		}
		delete [] pok;
		std::cout << e.what() << std::endl;
	}
	catch(std::domain_error e){
		for (int i = 0; i < a; i++) {
			delete [] pok[i];
		}
		delete [] pok;
		std::cout << e.what() << std::endl;
	}


	for (int i = 0; i < a; i++) {
			delete [] pok[i];
			pok[i] = nullptr;
	}
	delete [] pok;
	pok = nullptr;
	

	
	
	return 0;
}