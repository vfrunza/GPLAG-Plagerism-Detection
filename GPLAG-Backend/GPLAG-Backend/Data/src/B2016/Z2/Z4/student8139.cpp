#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

/*
static size_t alocirano(0);
static int brojac_new(0);
static int brojac_deleteniz(0);
static size_t alokacije[20];
const size_t RAM = 300;

void *operator new[] (size_t vel)
{
    if (RAM < alocirano+vel) throw std::bad_alloc();
    alokacije[brojac_new]=vel;
    brojac_new++;
    alocirano+=vel;   
    return std::malloc (vel);
}

void operator delete [] ( void* ptr) {
  brojac_deleteniz++;
  free(ptr);
}

void dealociraj(char **mat, int n){
  for(int i = 0; i < n; i++) delete[] mat[i];
    delete[] mat;
}
*/


int PotencijalniKrivci(char** &mander, std::vector<std::string> spisak_imena){
    int vecvel(spisak_imena.size());
    mander=new char*[vecvel];
    for(int i=0; i<vecvel; i++) mander[i] = nullptr;
    try{
        for(int i=0; i<vecvel; i++){
            int svel(spisak_imena[i].length());
            mander[i]=new char[svel+1];
            for(int j=0; j<svel; j++) mander[i][j]=spisak_imena[i][j];
            mander[i][svel] = '\0';
        }
        return vecvel;
    }
    catch(...){
        for(int i=0; i<vecvel; i++) delete[] mander[i];
        delete[] mander;
        throw;
    }
    return 0;
}

int OdbaciOptuzbu(char** &mander, int brel, std::string s){
    bool pronadjen(false);
    for(int i=0; i<brel; i++){
        std::string pomocni;
        int j(0);
        while(mander[i][j] != '\0'){pomocni+=mander[i][j]; j++;}
        if(pomocni==s){ 
            pronadjen=true;
            delete[] mander[i];
            mander[i]=nullptr;
        }
    }
    if(!pronadjen){ 
        std::string greska{"Osoba sa imenom "};
        greska+=s;
        std::string nastavak_greske{" nije bila optuzena"};
        greska+=nastavak_greske;
        throw std::domain_error(greska);
    }
    int brojac(0);
    int brel2(0);
    for(int i=0; i<brel; i++){ if(mander[i]==nullptr) brojac++;}
    if(brojac>10){
        for(int i=0; i<brel; i++){ if(mander[i]!=nullptr) brel2++;}
        try{
            char** milion(new char*[brel2]);
            int j(0);
            for(int i=0; i<brel; i++){
                if(mander[i]==nullptr) continue;
                milion[j]=mander[i];
                j++;
            }
            delete[] mander;
            mander=milion;
            return brel2;
        }
        catch(...){}
    }
    return brel;
}

int DodajOptuzbu(char** &mander, int brel, std::string s){
    int brojac(brel);
    int mjesto;
    int svel(s.size());
    bool pronadjeno(false);
    for(int i=0; i<brel; i++){
        if(mander[i]==nullptr){
            mjesto=i;
            pronadjeno=true;
            break;
        }
    }
    if(pronadjeno){ 
        try{
            mander[mjesto]=new char[svel+1];
            for(int i=0; i<svel; i++) mander[mjesto][i]=s[i];
            mander[mjesto][svel]='\0';
            return brel;
        }
        catch(std::bad_alloc){
            mander[mjesto]=nullptr;
            throw;
        }
    }
    else{
        try{
            char** izard=new char*[brojac+1];
            for(int i=0; i<brojac; i++) izard[i]=mander[i];
            try{
                izard[brojac]=new char[svel+1];
                for(int i=0; i<svel; i++) izard[brojac][i]=s[i];
                izard[brojac][svel]='\0';
                delete[] mander;
                brojac++;
                mander=izard;
                return brojac;
            }
            catch(...){
                delete[] izard[brojac];
                delete[] izard;
                throw;
            }
        }
        catch(...){throw;}
    }
    return brojac;
}

void IzlistajOptuzbu(char** mander, int brel){
    for(int i=0; i<brel; i++){
        if(mander[i]==nullptr) continue;
        int j(0);
        while(mander[i][j] != '\0'){ std::cout << mander[i][j]; j++;}
        std::cout << std::endl;
    }
}

int main ()
{
	int broj_krivaca;
	std::cout << "Koliko potencijalnih krivaca zelite unijeti? " << std::endl;
	std::cin >> broj_krivaca;
	std::vector<std::string> spisak;
	std::string ime;
	std::cout << "Unesite potencijalne krivce: " << std::endl;
	std::cin >> std::ws;
	for(int i=0; i<broj_krivaca; i++) {
	    std::cin >> std::ws;
	    std::getline(std::cin, ime);
	    spisak.push_back(ime);
	}
	char** pocetak;
	int broj_elemenata(spisak.size());
	try{
	    broj_elemenata=PotencijalniKrivci(pocetak,spisak);
	}
	catch(...){
	    std::cout <<"Alokacija nije uspjela" << std::endl;
	    return 0;
	}
	for(;;){
	    int opcija;
    	std::cout << "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: " << std::endl;
	    std::cin >> opcija;
	    if(opcija==2){
	        std::string optuzeni;
	        std::cout << "Unesite ime koje zelite izbaciti: " << std::endl;
	        std::cin >> std::ws;
	        std::getline(std::cin, optuzeni);
	        try{
	            broj_elemenata=OdbaciOptuzbu(pocetak,broj_elemenata,optuzeni);}
	        catch(std::domain_error e){
	            //std::cout<< "Osoba sa imenom " << e.what() << " nije bila optuzena" << std::endl;
	            std::cout << e.what() << std::endl;
	        }
    	}
	    else if(opcija==1){
	        std::string novo_optuzeni;
	        std::cout << "Unesite ime novog optuzenog: " << std::endl;
	        std::cin >> std::ws;
	        std::getline(std::cin, novo_optuzeni);
	        try{
	            broj_elemenata=DodajOptuzbu(pocetak,broj_elemenata,novo_optuzeni);
	        }
	        catch(...){
	            std::cout <<"nesto ne valja!";
	        }
	    }
	    else if(opcija==3){ 
	        IzlistajOptuzbu(pocetak,broj_elemenata);
	    }
	    else if(opcija==0){ 
	        for(int i=0; i<broj_elemenata; i++) delete[] pocetak[i];
	        delete[] pocetak;
	        break;
	    }
	    else continue;
	}
	
/*char **nizPotencijalnih;
  int n;
    std::vector<std::string> imena = {"Fudo", "Pero", "Meho", "Fata", "Bajro", "Luca", "Jovo", "Amina", "Elma", "Selma", "Admira", "Zora", "Ivanka"};
    try{
      n = PotencijalniKrivci( nizPotencijalnih, imena);
      n = OdbaciOptuzbu(nizPotencijalnih, n, "Meho");
    }
    catch(std::bad_alloc){
      std::cout << "Neuspjela alokacija" << std::endl;
    }
    catch(...){
      std::cout << "Pogresan tip izuzetka" << std::endl;
    }
    std::cout << "New pozvan " << brojac_new << " puta,  delete [] pozvan " << brojac_deleteniz << " puta, a alocirano ukupno " << alocirano << " bajta i to redom: ";
    for (int i=0; i<brojac_new;i++) std::cout << alokacije[i] << " ";
    dealociraj(nizPotencijalnih, n);
	*/
	
	return 0;
}