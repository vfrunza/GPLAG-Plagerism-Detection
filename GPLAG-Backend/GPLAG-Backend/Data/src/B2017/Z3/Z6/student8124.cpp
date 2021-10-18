/B2017/2018: Zadaća 3, Zadatak 6

#include <iostream>
#include <list>
#include <utility>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>
#include <string>
#include <exception>
#include <memory>

enum class Boje { Pik, Tref, Herc, Karo };
const std::vector<Boje> sveBoje = { Boje::Pik, Boje::Tref, Boje::Herc, Boje::Karo };
const std::vector<std::string> naziviKarata = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };    

typedef std::list<std::pair<Boje, std::string>> Spil;

struct Karta {
    Boje boja;
    std::string vrijednost;
};

struct Cvor {
    Karta karta;
    std::shared_ptr<Cvor> sljedeci;
};

std::string dajStringBoje(Boje b) {
    switch (b) {
        case Boje::Pik: return "Pik";
        case Boje::Tref: return "Tref";
        case Boje::Herc: return "Herc";
        case Boje::Karo: return "Karo";
        default: return "Nepoznato";
    }
}

void ispisiSpil(std::shared_ptr<Cvor> spil){
    auto trenutniCvor = spil;
    auto spilSize = 0;
    while(true){
        spilSize++;
        if(trenutniCvor->sljedeci == spil) break;
        trenutniCvor = trenutniCvor->sljedeci;
    }
    trenutniCvor = spil;
    
    std::string boja = "NULL";
    std::cout << "U spilu trenutno ima " << spilSize << " karata, i to:";
    while(true){
        if( dajStringBoje(trenutniCvor->karta.boja) != boja){
            boja = dajStringBoje(trenutniCvor->karta.boja);
            std::cout << std::endl;
            std::cout << boja << ":";
        }
        std::cout<< " " <<trenutniCvor->karta.vrijednost;
        if(trenutniCvor->sljedeci == spil) break;
        trenutniCvor = trenutniCvor->sljedeci;
    }
    std::cout << std::endl;
}



void provjeriSpil(std::shared_ptr<Cvor> spil){
    auto trenutniCvor = spil;
    auto spilSize = 0;
    while (true){
        spilSize++;
        if (trenutniCvor->sljedeci == spil) break;
        
        if(spilSize > 52){
            throw std::logic_error("Neispravna lista!");
        }

        trenutniCvor = trenutniCvor->sljedeci;
    }
    trenutniCvor = spil;
    
    
    for(Boje boja : sveBoje){
        for(std::string naziv : naziviKarata){
            if(trenutniCvor->sljedeci == spil){
                return;
            }
            if(trenutniCvor->karta.boja == boja && trenutniCvor->karta.vrijednost == naziv){
                trenutniCvor = trenutniCvor -> sljedeci;
            }
        }
    }
    if(trenutniCvor->sljedeci != spil){
        throw std::logic_error("Neispravna lista!");
    }
}

std::shared_ptr<Cvor> KreirajSpil() {
    std::shared_ptr<Cvor> cvor;
    std::shared_ptr<Cvor> pocetak = nullptr;
    std::shared_ptr<Cvor> kraj = nullptr;

    for (Boje boja: sveBoje) {
        for (std::string naziv: naziviKarata) {
            // spil.push_back(std::make_pair(boja, naziv));
            cvor = std::make_shared<Cvor>();
            cvor->karta.boja = boja;
            cvor->karta.vrijednost = naziv;
            
            if (pocetak == nullptr) {
                pocetak = cvor;
                kraj = cvor;
                cvor->sljedeci = cvor;
            } else {
                kraj->sljedeci = cvor;
                cvor->sljedeci = pocetak;
                kraj = cvor;
            }
        }
    }    
    
    return pocetak;
}

void IzbaciKarte(std::shared_ptr<Cvor> &spil, std::multimap<Boje, std::string> &crnaLista) {
    std::pair <std::multimap<Boje, std::string>::iterator, std::multimap<Boje, std::string>::iterator> ret;
    auto trenutniCvor = spil;
    auto prethodniCvor = spil;

    provjeriSpil(spil);
    
    while (true) {
        
        bool izbaciKartu = false;
        ret = crnaLista.equal_range(trenutniCvor->karta.boja);
        for(std::multimap<Boje, std::string>::iterator itCL=ret.first; itCL != ret.second; ++itCL){
            if(itCL->second == trenutniCvor-> karta.vrijednost){
                std::cout<<"Brisem: " << dajStringBoje(itCL->first) << " " << itCL->second << std::endl;
                crnaLista.erase(itCL);
                izbaciKartu = true;
                break;
            }
        }
        
        if(izbaciKartu){
            if(trenutniCvor == trenutniCvor->sljedeci){
                trenutniCvor->sljedeci = nullptr;
                trenutniCvor = nullptr;
                spil = nullptr;
                return;
            } 
            
            if (trenutniCvor == spil) {
                spil = trenutniCvor->sljedeci;
            }
            
            trenutniCvor = trenutniCvor->sljedeci;
            prethodniCvor->sljedeci->sljedeci = nullptr;
            prethodniCvor->sljedeci = trenutniCvor;
        } else {
            prethodniCvor = trenutniCvor;
            trenutniCvor = trenutniCvor->sljedeci;
        }
        
        if(trenutniCvor->sljedeci == spil) {
            break;
        }
    }
}

std::stack<std::pair<std::string, std::string>> IzbaciKarteRazbrajanjem(std::shared_ptr<Cvor> spil, const short int &r, const int &b){
    std::stack<std::pair<std::string, std::string>> red;
    auto trenutniCvor = spil;
    auto prethodniCvor = spil;
    int korak = 1;
    int izbaceno = 0;
    
    if (r < 1 || r > 52 || b < 1){
        throw std::logic_error("Neispravni elementi za izbacivanje!");
        // std::cout << "Izuzetak: Neispravni elementi za izbacivanje!" << std::endl;
    }
    provjeriSpil(spil);
    
    while(izbaceno < b) {
        
        if(korak == r){
            izbaceno++;
            red.push(std::make_pair(dajStringBoje(trenutniCvor->karta.boja), trenutniCvor->karta.vrijednost));
            // std::cout << "Brisem " << dajStringBoje(itSpil->first) << " " << itSpil->second << std::endl;
            
            if(trenutniCvor == trenutniCvor->sljedeci) {
                trenutniCvor->sljedeci = nullptr;
                trenutniCvor = nullptr;
                spil = nullptr;
                return red;
            }
            if(trenutniCvor == spil){
                spil = trenutniCvor->sljedeci;
            }
            trenutniCvor = trenutniCvor->sljedeci;
            prethodniCvor->sljedeci->sljedeci = nullptr;
            prethodniCvor->sljedeci = trenutniCvor;
            
            korak = 1;
            continue;
        }
        
        prethodniCvor = trenutniCvor;
        trenutniCvor = trenutniCvor->sljedeci;
        ++korak;
    }
    return red;
}

void provjeriValidnostReda(std::stack<std::pair<std::string, std::string>> red, int n){
    if(n<0){
        throw std::domain_error("Broj n je besmislen!");
    }
    if(n > red.size()){
        throw std::range_error("Nedovoljno karata u redu!");
    }
    while(!red.empty()){
        std::string boja = red.top().first;
        if(boja != "Pik" && boja !="Tref" && boja != "Herc" && boja!="Karo"){
            throw std::logic_error("Neispravne karte!");
        }
        if(std::find(naziviKarata.begin(), naziviKarata.end(), red.top().second) == naziviKarata.end()){
            throw std::logic_error("Neispravne karte!");
        }
        red.pop();
    }
}

void VratiPosljednjihNKarata(std::shared_ptr<Cvor> spil, std::stack<std::pair<std::string, std::string>> &red, int n){
    provjeriValidnostReda(red, n);
    
    while(n>0){
        auto trenutna = red.top();
        auto trenutniCvor = spil;
        auto prethodniCvor = spil;
        
        for(Boje boja: sveBoje) {
            for(std::string naziv: naziviKarata){
                if(trenutniCvor->karta.boja == boja && trenutniCvor->karta.vrijednost == naziv){
                    prethodniCvor = trenutniCvor;
                    trenutniCvor = trenutniCvor->sljedeci;
                } else if(trenutna.first == dajStringBoje(boja) && trenutna.second == naziv){
                    auto cvor = std::make_shared<Cvor>();
                    cvor->karta.boja = boja;
                    cvor->karta.vrijednost = naziv;
                    prethodniCvor->sljedeci = cvor;
                    cvor->sljedeci = trenutniCvor;
                }
            }
        }
        red.pop();
        n--;
    }
}

int main ()
{
    
    std::shared_ptr<Cvor> nepotpunSpil = KreirajSpil();

    std::multimap<Boje, std::string> crnaLista = {

        { Boje::Herc , "A" },
        { Boje::Herc , "Q" },
        { Boje::Karo , "9" },
        { Boje::Pik , "9" },
    };
    
   int r, b, n;
   try {
       std::cout << "Unesite korak razbrajanja: ";
       std::cin >> r;
       std::cout << "Unesite broj karata koje zelite izbaciti: ";
       std::cin >> b;
       std::stack<std::pair<std::string, std::string>> red = IzbaciKarteRazbrajanjem(nepotpunSpil, r, b);
       ispisiSpil(nepotpunSpil);
       std::cout<< "Unesite broj karata koje zelite vratiti u spil: ";
       std::cin >> n;
       VratiPosljednjihNKarata(nepotpunSpil, red, n);
       ispisiSpil(nepotpunSpil);
       // std::cout<<"--------------------------------------------------" << std::endl;
   } catch (std::exception &ex) {
       std::cout << "Izuzetak: " << ex.what() << std::endl;
   }
   
   nepotpunSpil->sljedeci = nullptr;
   nepotpunSpil = nullptr;
   
	return 0;
}

