#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <cstring>

using std::cin;
using std::cout;

int PotencijalniKrivci(char **&refKrivci, std::vector<std::string> optuzeni){
    
    char ** krivci(nullptr);
    try{
        krivci = new char*[optuzeni.size()];
    }
    catch(...){
        delete[] krivci;
        throw std::bad_alloc();
    }
    try{
        for(int i = 0; i < optuzeni.size(); i++)
            krivci[i] = nullptr;
        for(int i = 0; i < optuzeni.size(); i++){
            krivci[i] = new char[optuzeni[i].length() + 1];
            for(int j = 0; j < optuzeni[i].length(); j++){
                krivci[i][j] = optuzeni[i][j];
            }
            krivci[i][optuzeni[i].length()] = '\0';
        }
    }
    catch(...){
        for(int i = 0; i < optuzeni.size(); i++)
            delete[] krivci[i];
        delete[] krivci;
        throw std::bad_alloc();
    }
    refKrivci = krivci;
    return optuzeni.size();
}

int OdbaciOptuzbu(char **&refKrivci, int velicina, std::string nevini){
    bool isti;
    for(int i = 0; i < velicina; i++){
        isti = false;
//        cout << i << "--" << sizeof(refKrivci[i]) << "--" << nevini.length() << std::endl;
        if(strlen(refKrivci[i]) != nevini.length()) continue;
        for(int j = 0; j < nevini.length(); j++){
            if(refKrivci[i][j] != nevini[j]){
                 isti = false;
                 break;
            }
            else isti = true;
        }
        if(isti == true){
             refKrivci[i] = nullptr;
             break;
        }
    }
    if(!isti){
        std::string ispis("Osoba sa imenom  nije bila optuzena");
        throw std::domain_error(ispis.substr(0, 16) + nevini + ispis.substr(16, 19));
    }
    
    int brojNull(0);
    for(int i = 0; i < velicina; i++)
        if(refKrivci[i] == nullptr)
            brojNull++;
    if(brojNull <= 10) return velicina;
    else{
        char ** noviKrivci = nullptr;
        try{
            noviKrivci = new char*[velicina - brojNull];
        }
        catch(...){
            delete[] noviKrivci;
            throw std::bad_alloc();
        }
        int br(0);
        for(int i = 0; i < velicina - brojNull; i++){
            while (refKrivci[br] == nullptr) br++;
            noviKrivci[i] = refKrivci[br];
            br++;
        }
        delete[] refKrivci;
        refKrivci = noviKrivci;
    }
    return velicina - brojNull;
}

int DodajOptuzbu(char **&refKrivci, int velicina, std::string krivac){
    
    char *noviKrivac(nullptr);
    try{
        noviKrivac = new char [krivac.length() + 1];
    }
    catch(...){
        delete[] noviKrivac;
        for(int i = 0; i < velicina; i++)
            delete[] refKrivci[i];
        delete[] refKrivci;
        throw std::bad_alloc();
    }
    int i;
    for(i = 0; i < krivac.length(); i++)
        noviKrivac[i] = krivac[i];
    noviKrivac[i] = '\0';
    bool ima_nullptr;
    for(int i = 0; i < velicina; i++){
        if(i == velicina - 1 && refKrivci[i] != nullptr)
            ima_nullptr = false;
        if(refKrivci[i] == nullptr){
            refKrivci[i] = noviKrivac;
            ima_nullptr = true;
            break;
        }
    }
    if(ima_nullptr) return velicina;
    
    char **konacniKrivci(nullptr);
    try{
        konacniKrivci = new char*[++velicina];
    }
    catch(...){
        delete[] konacniKrivci;
        throw std::bad_alloc();
    }
    try{
        for(int i = 0; i < velicina; i++){
            if(i == velicina - 1){
                konacniKrivci[i] = new char [krivac.length() + 1];
                break;
            }
            try{
                konacniKrivci[i] = new char [strlen(refKrivci[i]) + 1];
                for(int j = 0; j < strlen(refKrivci[i]) + 1; j++){
                    konacniKrivci[i][j] = refKrivci[i][j];
                }
            }
            catch(...){
                delete[] konacniKrivci[i];
                konacniKrivci[i] = nullptr;
                throw std::bad_alloc();
            }
        }
        for(int i = 0; i < krivac.length() + 1; i++){
            konacniKrivci[velicina - 1][i] = noviKrivac[i];
        }
    }
    catch(...){
        for(int i = 0; i < velicina; i++)
            delete[] konacniKrivci[i];
        delete[] konacniKrivci;    
        throw std::bad_alloc();
    }
    for(int i = 0; i < velicina - 1; i++)
        delete[] refKrivci[i];
    delete[] refKrivci;
    refKrivci = konacniKrivci;
    
    return velicina;
}

void IzlistajOptuzbu(char **Krivci, int velicina){
    for(int i = 0; i < velicina; i++){
        if(Krivci[i] != nullptr){
            for(int j = 0; j < strlen(Krivci[i]); j++)
                cout << Krivci[i][j];
            cout << std::endl;
        }
    }
}

int main ()
{
    int velicina;
    char **pokKrivci;
    cout << "Koliko potencijalnih krivaca zelite unijeti? " << std::endl;
    cin >> velicina;
    try{    
        std::vector<std::string> krivci(velicina);
        cin.ignore(10000, '\n');
        cout << "Unesite potencijalne krivce: " << std::endl;
        for(std::string &x : krivci){
            std::getline(cin, x);
        }
        velicina = PotencijalniKrivci(pokKrivci, krivci);
        int opcija(1);
        while(opcija != 0){
            cout << "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: " << std::endl;
            cin >> opcija;
            std::string novi;
            switch(opcija){
                case 1 :
                    try{
                        cout << "Unesite ime novog optuzenog: " << std::endl;
                        cin.ignore(10000, '\n');
                        std::getline(cin, novi);
                        velicina = DodajOptuzbu(pokKrivci, velicina, novi);
                        break;
                    }
                    catch(...){
                        cout << "Memorijska greska";
                        return 0;
                    }
                case 2 :
                    try{
                        cout << "Unesite ime koje zelite izbaciti: " << std::endl;
                        cin.ignore(10000, '\n');
                        std::getline(cin, novi);
                        velicina = OdbaciOptuzbu(pokKrivci, velicina, novi);
                        break;
                    }
                    catch(std::domain_error x){
                        cout << x.what();
                        for(int i = 0; i < velicina; i++)
                            delete[] pokKrivci[i];
                        delete[] pokKrivci;
                        return 0;
                    }
                    catch(...){
                        cout << "Memorijska greska";
                        return 0;
                    }
                case 3 :
                    IzlistajOptuzbu(pokKrivci, velicina);
                    break;
            }
        }
    }
    catch(...){
        cout << "Memorijska greska";
    }
    for(int i = 0; i < velicina; i++)
        delete[] pokKrivci[i];
    delete[] pokKrivci;
	return 0;
}