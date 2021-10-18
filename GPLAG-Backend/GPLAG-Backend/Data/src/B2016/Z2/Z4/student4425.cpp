#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//
void deallocate(char** niz, int vel) {
    for (int i = 0; i < vel; i++) delete[] niz[i];
    delete[] niz;
}

int PotencijalniKrivci(char**& niz, std::vector<std::string> imena) {
    char** novi_niz(nullptr);
    int i(0);
    try {
        novi_niz = new char*[imena.size()];
        try {
            for(i = 0; i < imena.size(); i++) novi_niz[i] = nullptr;
            for(i = 0; i < imena.size(); i++) {
                novi_niz[i] = new char[imena[i].size()+1]; //+1 za null graničnik
                std::copy(imena[i].begin(), imena[i].end(), novi_niz[i]);
                novi_niz[i][imena[i].size()] = '\0';
            }
            niz = novi_niz;
        } catch (...) {
            for (int j = i-1; j >= 0; j--) delete[] novi_niz[i];
            throw;
        }
    } catch (...) {
        delete[] novi_niz;
        throw;
    }
    
    return imena.size();
}

int OdbaciOptuzbu (char**& niz, int vel, std::string innocent) {
    
    int i(0);
    for (i = 0; i < vel; i++) {
        if (niz[i]!=nullptr) {
            std::string ime = std::string(niz[i]);
            if (ime == innocent) break;
        }
    }
    if (i==vel) {
        std::string err_msg = "Osoba sa imenom "; err_msg+=innocent; err_msg+=std::string(" nije bila optuzena");
        throw std::domain_error(err_msg);
    }
    
    static int nullpok_num(0);
    for (i = 0; i < vel; i++) {
        if (niz[i]!=nullptr) {
            std::string ime = std::string(niz[i]);
            if (ime == innocent) {
                delete[] niz[i];
                niz[i] = nullptr;
                nullpok_num++;
                break;
            }
        }
    }
    
    if (nullpok_num > 10) {
        
        int nova_vel(0);
        //prebroji stvarni broj osoba u spisku
        for (i = 0; i < vel; i++) {
            if (niz[i] != nullptr) nova_vel++;
        }
        
        char** novi_niz(nullptr);
        try {
            novi_niz = new char*[nova_vel];
            int tmp_index(0);
            for (i = 0; i < vel; i++) {
                if (niz[i]!=nullptr) {
                    novi_niz[tmp_index] = niz[i];
                    tmp_index++;
                }
            }
            delete[] niz;
            niz = novi_niz;
            nullpok_num = 0;
            return nova_vel;
        } catch(...) {
            delete[] novi_niz;
            goto no_alloc;
        }
        
    }
    
    no_alloc:
    return vel;
}

int DodajOptuzbu(char**& niz, int vel, std::string suspect) {
    
    char* osumnjiceni(nullptr);
    try {
        osumnjiceni = new char[suspect.length()+1];
        std::copy(suspect.begin(), suspect.end(), osumnjiceni);
        osumnjiceni[suspect.length()] = '\0';
    } catch (...) {
        delete[] osumnjiceni;
        throw;
    }
    
    for (int i = 0; i < vel; i++) {
        if (niz[i] == nullptr) {
            niz[i] = osumnjiceni;
            return vel;
        }
    }
    
    char** novi_niz(nullptr);
    try {
        novi_niz = new char*[vel+1];
        for (int i = 0; i < vel; i++) {
            novi_niz[i] = niz[i];
        }
        novi_niz[vel] = osumnjiceni;
        
        delete[] niz;
        niz = novi_niz;
        vel++;
        return vel;
        
    } catch (...) {
        delete[] novi_niz;
        throw;
    }
    
}

void IzlistajOptuzbu(char** niz, int vel) {
    for (int i = 0; i < vel; i++) {
        if (niz[i] == nullptr) continue;
        else std::cout << niz[i] << std::endl;
    }
}

int main () {

    std::cout << "Koliko potencijalnih krivaca zelite unijeti? " << std::endl;
    int n;
    std::cin >> n;
    std::cin.ignore(10000, '\n');
    
    std::cout << "Unesite potencijalne krivce: " << std::endl;
    std::vector<std::string> imena(n);
    for (int i = 0; i < n; i++) {
        std::string tmp;
        std::getline(std::cin, tmp);
        imena[i] = tmp;
    }
    
    char** niz(nullptr);
    int vel(0);
    try {
        vel = PotencijalniKrivci(niz, imena);
    } catch (...) {
        //deallocate(niz, vel);
        std::cout << "Nedovoljno memorije!";
        //return 0; - uključi ovo sutra u slučaju da ne prođe?
    }
    
    //std::vector<std::string> imena{"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15"};
    //vel = PotencijalniKrivci(niz, imena);
    while (1) {
        
        std::cout << "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: " << std::endl;
        int command;
        std::cin >> command;
        
        if (command == 0) {
            deallocate(niz, vel);
            break;
        }
        if (command==1) {
                std::cin.ignore(10000, '\n');
                std::cout << "Unesite ime novog optuzenog: " << std::endl;
                std::string tmp2;
                std::getline(std::cin, tmp2);
                try {
                    vel = DodajOptuzbu(niz, vel, tmp2);
                } catch (...) {
                    //uhvati bad_alloc al' nije rečeno šta uraditi s njim
                }
                continue;
        } else if (command==2) { 
                std::cin.ignore(10000, '\n');
                std::cout << "Unesite ime koje zelite izbaciti: " << std::endl;
                std::string tmp3;
                std::getline(std::cin, tmp3);
                try {
                    vel = OdbaciOptuzbu(niz, vel, tmp3);
                } catch (std::domain_error err) { 
                    std::cout << err.what() << std::endl;
                }
                continue;
        } else if (command==3) {
                IzlistajOptuzbu(niz, vel);
                continue;
        } else {
                std::cout << "YOU FORGOT STH!" << std::endl;
                break;
        }
    }
    
	return 0;
}