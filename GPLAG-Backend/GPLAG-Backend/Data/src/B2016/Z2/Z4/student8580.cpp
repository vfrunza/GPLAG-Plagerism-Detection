#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
void IzlistajOptuzbu(char **, int);
//POMOCNE FUNKCIJE
int DuzinaStringa(std::string s) {
    int duzina = s.length();
    return duzina + 1;
}

int DuzinaNizaCharova(char *niz) {
    int duzina = 0;
    while(*niz != '\0') {
        niz++;
        duzina++;
    }
    return duzina;
}

bool PostojiUNizu(char **niz, int velicina, std::string ime, int &index) {
    for(int i = 0; i < velicina; i++) {
        if(niz[i] == nullptr) continue;
        int j = 0;
        int brojac = 0;
        char *pomocni = nullptr;
        pomocni = niz[i];
        while(*(niz[i]) != '\0' && j < ime.length()){
            if(*(niz[i]) == ime[j]) brojac++;
            niz[i]++;
            j++;
        }
        niz[i] = pomocni;
        if(brojac == ime.length() && brojac == DuzinaNizaCharova(niz[i])) {
            index = i;
            return true; 
        }
    }
    return false;
}

//FUNKCIJE IZ POSTAVKE
int PotencijalniKrivci(char **&prodavaci, std::vector<std::string> imena) {
    int velicina = imena.size();
    int broj = 0;
    
    try {
        prodavaci = new char * [velicina];
        for(int i = 0; i < velicina; i++)
            prodavaci[i] = nullptr;
       
        for(int i = 0; i < velicina; i++) {
                prodavaci[i] = new char[DuzinaStringa(imena[i])];
                broj++;
        }
        
    }
    catch(std::bad_alloc) {
        if(prodavaci != nullptr)
        for(int i = 0; i < broj; i++) {
            delete[] prodavaci[i];
        }
        delete[] prodavaci;
    }
    
    for(int i = 0; i < velicina; i++) {
        int j = 0;
        while(j < imena[i].length()) {
            prodavaci[i][j] = imena[i][j];
            j++;
        }
        prodavaci[i][j] = '\0';
    }
    
    return broj;
}

int OdbaciOptuzbu(char **&prodavaci, int velicina, std::string ime) {
    int index;
    if(PostojiUNizu(prodavaci, velicina, ime, index)) {
        delete[] prodavaci[index];
        prodavaci[index] = nullptr;
    }
    else {
        throw std::domain_error(ime);
    }
    int broj_null = 0;
    for(int i = 0; i < velicina; i++) {
        if(prodavaci[i] == nullptr) broj_null++;
    }
    
    int nova_velicina;
    if(broj_null >= 10) {
        char **novi;
        nova_velicina = 0;
        novi = nullptr;
        for(int i = 0; i < velicina; i++) {
            if(prodavaci[i] == nullptr) continue;
            novi = new char *[nova_velicina];
            novi[nova_velicina] = new char [DuzinaNizaCharova(prodavaci[i])];
            char *pomocni = prodavaci[i];
            while(*(prodavaci[i]) != '\0') {
                *(novi[nova_velicina]) = *(prodavaci[i]);
                prodavaci[i]++;
                novi[nova_velicina]++;
            }
            prodavaci[i] = pomocni;
            nova_velicina++;
        }
        
        for(int i = 0; i < velicina; i++) 
            delete[] prodavaci[i];
            
        delete[] prodavaci;
        
        prodavaci = novi;
        for(int i = 0; i < nova_velicina; i++) {
            delete[] novi[i];
        }
        delete[] novi;
    }
    else nova_velicina = velicina;
    
    return nova_velicina;
}

int DodajOptuzbu(char **&prodavaci, int velicina, std::string ime) {
    char *novo_ime;
    try{
        novo_ime = new char[DuzinaStringa(ime)];
    }
    catch(std::bad_alloc) {
        delete[] novo_ime;
        return velicina;
    }
    int k = 0;
    char *pomocni = nullptr;
    pomocni = novo_ime;
    while(k < ime.length()) {
        *novo_ime = ime[k];
        novo_ime++;
        k++;
    }
    *novo_ime = '\0';
    novo_ime = pomocni;
    
    for(int i = 0; i < velicina; i++) {
        if(prodavaci[i] != nullptr) continue;
        prodavaci[i] = novo_ime;
        return velicina;
    }
    
    int nova_velicina = velicina+1;
    char **novi = nullptr;
    
    try {
        novi = new char *[nova_velicina];
    }
    catch(std::bad_alloc) {
        delete[] novi;
        delete[] novo_ime;
        return velicina;
    }

    for(int i = 0; i < velicina; i++) 
        novi[i] = prodavaci[i];

    novi[velicina] = novo_ime;
    delete[] prodavaci;
    prodavaci = novi;
        
    return nova_velicina;
}

void IzlistajOptuzbu(char **prodavaci, int velicina) {
    std::cout << std::endl;
    for(int i = 0; i < velicina; i++) {
        if(prodavaci[i] == nullptr) continue;
        while(*(prodavaci[i]) != '\0') {
            std::cout << *(prodavaci[i]);
            prodavaci[i] ++;
        }
        std::cout << std::endl;
    }
}

void UnosProdavaca(int &broj, std::vector<std::string> &baza){
    std::cout << "Koliko potencijalnih krivaca zelite unijeti? ";
    std::cin >> broj;
    std::cout << std::endl << "Unesite potencijalne krivce: " << std::endl;
    std::cin.clear();
    std::cin.ignore(1000,'\n');
    for(int i = 0; i < broj; i++) {
        std::string pomocni;
        std::getline(std::cin,pomocni);
        baza.push_back(pomocni);
    }
}

void UnosNovog(std::string &s) {
    std::cout << std::endl << "Unesite ime novog optuzenog: " << std::endl;
    std::cin.clear();
    std::cin.ignore(1000,'\n');
    std::getline(std::cin, s);
}

void IzbaciIme(std::string &s) {
    std::cout << std::endl << "Unesite ime koje zelite izbaciti: " << std::endl;
    std::cin.clear();
    std::cin.ignore(1000,'\n');
    std::getline(std::cin, s);
}

int main ()
{
	char **pok;
	pok = nullptr;
	
	int broj_prodavaca;
	std::vector<std::string> baza;
	UnosProdavaca(broj_prodavaca, baza);
	
	int alocirani = 0;
	std::string ime;
	int novaV = alocirani;
	
	try {
	    alocirani = PotencijalniKrivci(pok, baza);
	    int komanda = -1;
	    while(komanda != 0) {
	        std::cout << "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: ";
	        std::cin >> komanda;
	        if(komanda == 1) {
	            UnosNovog(ime);
	            novaV = DodajOptuzbu(pok,alocirani,ime);
	        }
	        else if(komanda == 2) {
	            IzbaciIme(ime);
	            novaV = OdbaciOptuzbu(pok,alocirani,ime);
	        }
	        else if(komanda == 3) IzlistajOptuzbu(pok, alocirani);
	        if(alocirani != novaV) alocirani = novaV;
	    }
	    
	}
	catch(std::bad_alloc()) {
	    std::cout << "Doslo je do greske pri alokaciji.";
	    if(pok != nullptr)
	      for(int i = 0; i < alocirani; i++)
	        delete[] pok[i];
	    delete[] pok;
	}
	catch(std::domain_error izuzetak) {
	    if(pok != nullptr)
	        for(int i = 0; i < alocirani; i++) delete[] pok[i];
	        delete[] pok;
	    std::cout << "Osoba sa imenom " << izuzetak.what() << " nije bila optuzena";
	}
	
	
	for(int i = 0; i < alocirani; i++) 
	    delete[] pok[i];
    
    delete[] pok;
    pok = nullptr;

	return 0;
}