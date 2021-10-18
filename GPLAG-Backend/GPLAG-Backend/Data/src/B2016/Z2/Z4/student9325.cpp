#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stdexcept>
#include <new>

int PotencijalniKrivci(char** &c, std::vector<std::string> vs) {
    try {
        c = new char* [vs.size()];
        for(int i = 0; i < vs.size(); i++) 
            c[i] = nullptr;
        try {
            for(int i = 0; i < vs.size(); i++) {
                c[i] = new char[vs[i].length()+1];
                strcpy(c[i], vs[i].c_str());
            }
        } 
        catch(...) {
            for(int i = 0; i < vs.size(); i++) 
                delete c[i];
            delete[] c;
            throw;
        }
    }
    catch(...) {
        throw std::bad_alloc();
    }
    return vs.size();
}

int OdbaciOptuzbu(char** &c, int vel, std::string s) {
    bool DaLiJeNaSpisku = false;
    for(int i = 0; i < vel; i++) {
        if(c[i] == nullptr) continue;
        if(strcmp(c[i], s.c_str()) == 0) {
            delete[] c[i];
            c[i] = nullptr;
            DaLiJeNaSpisku = true;
            
        }
    }
    if(DaLiJeNaSpisku == false) {
        std::string izuzetak = "Osoba sa imenom " + s + " nije bila optuzena";
        throw std::domain_error(izuzetak);
    }
        
    int brojSlobodnihMjesta = 0;
    int brojOptuzenih = 0;
    for(int i = 0; i < vel; i++) {
        if(c[i] == nullptr) {
            brojSlobodnihMjesta++;
        } else brojOptuzenih++;
    }
    
    if(brojSlobodnihMjesta > 10) {
        char** novi_c;
        try {
            novi_c = new char* [brojOptuzenih];
            for(int i = 0; i < brojOptuzenih; i++)
                novi_c[i] = nullptr;
                
            try {
                int brojac = 0;
                for(int i = 0; i < vel; i++) {
                    if(c[i] == nullptr) continue;
                    novi_c[brojac++] = c[i];
                }
                for(int i = 0; i < vel; i++) 
                    delete[] c[i];
                delete[] c;
                
                c = novi_c;
                return brojOptuzenih;
            }
            catch(...) {
                 for(int i = 0; i < brojOptuzenih; i++) 
                    delete[] novi_c[i];
                 delete[] novi_c;    
                 throw;
            }
        }
        catch(...) {
            throw std::bad_alloc();
        }
    }
    return vel;
}

int DodajOptuzbu(char** &c, int vel, std::string s) {
    char* krivac = nullptr;
    try {
        krivac = new char [s.size()+1]; 
    }
    catch(...) {
        delete krivac;
        throw std::bad_alloc();
    }
    
    strcpy(krivac, s.c_str());
    
    bool ImaLiSlobodnoMjesto = true;
    for(int i = 0; i < vel; i++) {
        if(c[i] == nullptr) {
            c[i] = krivac;
            ImaLiSlobodnoMjesto = false;
            break;
        }
    }
    
    if(ImaLiSlobodnoMjesto) {
        char** novi_c;
        try {
            novi_c = new char* [vel+1];
            for(int i = 0; i < vel + 1; i++)
                novi_c[i] = nullptr;
                
            try {
                for(int i = 0; i < vel; i++) {
                    novi_c[i] = new char [strlen(c[i])+1];
                    strcpy(novi_c[i], c[i]);
                }
                novi_c[vel] = krivac;
                
                for(int i = 0; i < vel; i++) 
                    delete[] c[i];
                delete[] c;
                
                c = novi_c;
                vel += 1;
            }
            catch(...) {
                for(int i = 0; i < vel; i++) 
                    delete[] novi_c[i];
                delete[] novi_c; 
                
                throw;
            }
        }
        catch(...) {
            throw std::bad_alloc();
        }
    }
    return vel;
}

void IzlistajOptuzbu(char** c, int vel) {
    for(int i = 0; i < vel; i++) {
        if(c[i] == nullptr) continue;
        std::cout << std::endl << c[i];
    }
}


int main() {
    std::cout << "Koliko potencijalnih krivaca zelite unijeti? ";
    int brojPotencijalnih; 
    std::cin >> brojPotencijalnih;
    std::cin.clear();
    std::cin.ignore(1000,'\n');
    std::vector<std::string> spisak(brojPotencijalnih);
    std::cout << "\nUnesite potencijalne krivce: ";
    for(int i = 0; i < spisak.size(); i++) {
        std::getline(std::cin, spisak[i]);
    }
    
    char** c;
    int vel = PotencijalniKrivci(c, spisak);
    int opcija;
    
    try {
        while(true) {
            std::cout << "\nOdaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: ";
            std::cin >> opcija;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            if(opcija == 1) {
                std::cout << "\nUnesite ime novog optuzenog: ";
                std::string optuzeni;
                std::getline(std::cin, optuzeni);
                vel = DodajOptuzbu(c, vel, optuzeni);
            }
            if(opcija == 2) {
                std::cout << "\nUnesite ime koje zelite izbaciti: ";
                std::string osoba;
                std::getline(std::cin, osoba);
                vel = OdbaciOptuzbu(c, vel, osoba);
            }
            if(opcija == 3) {
                IzlistajOptuzbu(c, vel);
            }
            if(opcija == 0) {
                for(int i = 0; i < vel; i++) 
                    delete[] c[i];
                delete[] c;
                
                return 0;
            }
        }
    }
    catch(std::domain_error izuzetak) {
        std::cout << izuzetak.what();
    }
    catch(std::bad_alloc) {
        std::cout << "Nedovoljno memorije";
    } 
    return 0;
}