#include <iostream>
#include <new>
#include <cmath>
#include <stdexcept>
#include <vector>
#include <string>
#include <cstring>
#include <limits>

int uporedi(char* s1, char* s2) {
while (*s1 != '\0' && *s2 != '\0') {
if (*s1 < *s2) return -1;
if (*s1 > *s2) return 1;
s1++;
s2++;
}
if (*s1 != '\0') return 1;
if (*s2 != '\0') return -1;
return 0;
}


int PotencijalniKrivci(char **&n, std::vector<std::string> v ) {

char **p;
try {
	p = (new char*[v.size()]);
	for(int i = 0; i < v.size(); i++) p[i] = nullptr;
		n = p;
try 
{
	for(int i=0; i<v.size(); i++) 
		p[i] = new char [v[i].size() +1];
	
		
		for(int i=0; i<v.size(); i++) {
		strcpy(p[i], v[i].c_str());
	}
		
} catch(std::bad_alloc) {
	for(int i=0; i<v.size(); i++) delete p[i];
	delete [] p;
	throw;
} 
}
	catch(...) {
		delete [] p;
	
	}

	return v.size();
}


// ODBACI OPTUŽBU 

int OdbaciOptuzbu (char **&p, int vel, std::string s) {
	bool ima = false;
	int br(0);
try {	
	for(int i=0; i<vel; i++) {
		int b = uporedi(p[i], s.c_str());
		if(b == 0) {
			ima = true;
			delete [] p[i];
			p[i] = nullptr;
		}
		
		for(int i=0; i<vel; i++) if (p[i] == nullptr) br++;
	}
	
	if (!(ima)) throw std::domain_error("Osoba sa imenom " + s + " nije bila optuzena");
	
		if(br<=10) return vel;
		
		else if(br > 10) {
			char **novi;
			try {
				int j=0;
				novi = (new char*[vel-br]);
				
				for(int i=0; i<vel; i++) {
					if(p[i] != nullptr) {
						novi[j] = p[i];
						j++;
					}
				}
			} catch(std::bad_alloc) {
				for(int i=0; i<vel-br; i++) delete novi[i];
				delete [] novi;
			}
			
			
			return vel-br ;
		}
	
} 
catch (...) {
throw;
	
}
}
// DODAJ OPTUŽBU

int DodajOptuzbu (char **&p, int vel, std::string s) { 
	bool ima = false;
	char *novi;
	try {
		novi = (new char [s.size()+1]);
		for(int i=0; i<vel; i++) {
			if(p[i]==nullptr) {
				ima = true;
				p[i] = novi;
			
				break;
			}
		}
		
			if(!ima) {
				char **n;
	try {
			n = (new char*[vel+1]);
			for(int i=0; i<vel+1; i++) n[i] = nullptr;
			for(int i=0; i<vel; i++) n[i] = p[i];
			n[vel] = novi;
	
	return vel;
	
		
	} catch (std::bad_alloc) {
		int i;
		for( i=0; i<vel; i++) delete [] n[i];
		delete [] n[i+1];
		delete [] n;
	}
}
}catch (std::bad_alloc) {
	
		delete [] novi;
	} 
}
void IzlistajOptuzbu(char **optuzeni, int vel) {

	for(int i=0; i<vel; i++) {
		if(optuzeni[i] != nullptr)
		std::cout << optuzeni[i] << std::endl;
	}
}

int main ()
{
	try {
	int vel, opcija;
	std::vector<std::string> v;
	std::string ime, s;
	char **nizPotencijalnih;
	
	int prvi (PotencijalniKrivci(nizPotencijalnih, v));
	
	std::cout <<"Koliko potencijalnih krivaca zelite unijeti? \n";
	std::cin >> vel;
	
	std::cin.ignore(1000, '\n');
	
	std::cout <<"Unesite potencijalne krivce: \n";
	for(int i=0; i<vel; i++) {
		std::getline(std::cin, ime);
		v.push_back(ime);
	}

	
	while (1) {
	std::cout <<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: \n";
	std::cin >> opcija;
	
	if(opcija == 1) {
		
		std::cout << "Unesite ime novog optuzenog: \n";
		std::cin.ignore(50, '\n');
		std::getline(std::cin, s);
		 prvi = DodajOptuzbu(nizPotencijalnih, prvi, s);
	}
	
	else if(opcija == 2) {
		std::cout << "Unesite ime koje zelite izbaciti: \n";
		std::cin.ignore(50, '\n');
		std::getline(std::cin, s);
		prvi = OdbaciOptuzbu(nizPotencijalnih, prvi, s);
	}
	
	else if(opcija == 3) {
	  IzlistajOptuzbu(nizPotencijalnih, prvi);
	  break;
	  
} 
		
	}
	
	delete [] nizPotencijalnih;
	} catch (std::domain_error izuzetak) {
	std::cout <<izuzetak.what();
	
}
	
	return 0;
}


