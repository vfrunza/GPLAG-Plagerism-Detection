#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

void Brisi(char **mat, int broj) {
    for(int i=0; i<broj; i++) delete[] mat[i];
    delete[] mat;
}

int PotencijalniKrivci(char **&dabl_pok, std::vector<std::string> spisak) {
    
    int broj_alociranih(0);
    
    try {
        dabl_pok = new char *[spisak.size()];
        for(int i=0; i<spisak.size(); i++) dabl_pok[i]=nullptr;
        
        try {
            for(int i=0; i<spisak.size(); i++) {
                dabl_pok[i]=new char[spisak[i].size()+1];
                broj_alociranih++;
            }
            
            for(int i=0; i<broj_alociranih; i++) {
                for(int j=0; j<spisak[i].size(); j++) {
                    dabl_pok[i][j]=spisak[i][j];
                }
                dabl_pok[i][spisak[i].size()]='\0';
            }
        }
        catch(...) {
            Brisi(dabl_pok, spisak.size());
            throw;
        }
    }
    catch(...) { 
        delete[] dabl_pok; 
        throw; }
        
    
    return broj_alociranih;
}

int OdbaciOptuzbu(char **&dabl_pok, int vel, std::string ime) {
    int vel_niza(vel);
    
   bool ima_optuzenog(false);
   
   //spremanje u pomocni string imena da bi se poredilo
    for(int i=0; i<vel; i++) {
        std::string pomocni_string;
        
        for(int j=0; j<ime.length(); j++) {
            pomocni_string.push_back(dabl_pok[i][j]);
            if(dabl_pok[i][j]=='\0') {
                pomocni_string.resize(pomocni_string.length()-1); 
                break; 
            }
        }
        
        //poredjenje
            if(pomocni_string==ime) {
            
            delete[] dabl_pok[i];
            dabl_pok[i]=nullptr;
            
            ima_optuzenog=true;
            
            int broj_nule(0);
            
            for(int k=0; k<vel; k++) {
                if(dabl_pok[k]==nullptr) broj_nule++;
            }
            
            if(broj_nule>=10) {
                try{
                    char **novi = new char *[vel-broj_nule];
                
                    for(int i=0; i<vel-broj_nule; i++) novi[i]=nullptr;
                        int k(0);
                        for(int i=0; i<vel; i++) {
                            if(dabl_pok[i]!=nullptr) { novi[k]=dabl_pok[i]; k++; }
                        }
                        
                    delete[] dabl_pok;
                    
                    dabl_pok=novi; 
                        
                    novi=nullptr;
                    vel_niza=vel-broj_nule;
                } catch(...) {}        
            }
        }
    }
    
    if(ima_optuzenog==false) { std::string s="Osoba sa imenom " + ime + " nije bila optuzena"; throw std::domain_error(s); }
    
    return vel_niza;
}

int DodajOptuzbu(char **&dabl_pok, int vel, std::string ime) {
    
    char *niz = nullptr;
    char **novi = nullptr;
    try{
        niz = new char [ime.size()+1];
    } catch(...) { throw; }
    
        for(int i=0; i<ime.size(); i++) niz[i]=ime[i];
        niz[ime.size()]='\0';
        
        
        for(int i=0; i<vel; i++) {
            if(dabl_pok[i]==nullptr) {
                for(int j=0; j<ime.size()+1; j++) 
                dabl_pok[i]=niz;
                return vel;
            }
        }
        
        
            try{
                vel++;
                novi=new char *[vel];
                for(int i=0; i<vel; i++) novi[i]=nullptr;
                
                
                    for(int i=0; i<vel-1; i++) {
                        novi[i]=dabl_pok[i];
                        
                    }
                    
                    novi[vel-1]=niz;
                    
                    delete[] dabl_pok;
                    
                    dabl_pok=novi;
                    
            }
            catch(...) { delete[] niz; throw; }
        
    return vel;
}

void IzlistajOptuzbu(char **pok_na_pok, int vel) {
    
    for(int i=0; i<vel; i++) {
        if(pok_na_pok[i]!=nullptr) std::cout << pok_na_pok[i] << std::endl; 
    }
}

int main ()
{ 

    std::cout << "Koliko potencijalnih krivaca zelite unijeti? " << std::endl;
    int vel_niza;
    std::cin >> vel_niza;
    std::vector<std::string> spisak;
    int n(vel_niza);
    if(n>0) {
    std::cout << "Unesite potencijalne krivce: " << std::endl;
    
        std::cin.clear(); std::cin.ignore(1000000, '\n');
    
        while(n) {
            std::string unos;
            getline(std::cin, unos);
            spisak.push_back(unos);
            n--;
        }
    }
   
   try{
   char **niz;
   
    vel_niza = PotencijalniKrivci(niz, spisak);
    while(5) {
        std::cout << "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: " << std::endl;
        std::cin >> n;
    
        if(n==0) { 
            Brisi(niz, vel_niza);
            return 0; 
        }
        else if(n==1) {
            
            std::cout << "Unesite ime novog optuzenog: " << std::endl;
            std::string ime;
            std::cin.clear(); std::cin.ignore(100000, '\n');
            getline(std::cin, ime);
            try {
                vel_niza = DodajOptuzbu(niz, vel_niza, ime); 
            } catch(...) {}
        }
        else if(n==2) { 
            std::cout << "Unesite ime koje zelite izbaciti: " << std::endl;
            std::string ime;
            std::cin.clear(); std::cin.ignore(100000, '\n');
            getline(std::cin, ime);
           try {
            vel_niza = OdbaciOptuzbu(niz, vel_niza, ime);
           } catch(std::domain_error e) { std::cout << e.what(); }
        
        }
        else if(n==3) { 
               IzlistajOptuzbu(niz, vel_niza);
         }
    }
    } catch(...) { }
    
    
    //Brisi(niz, vel_niza+1);
	return 0;



}