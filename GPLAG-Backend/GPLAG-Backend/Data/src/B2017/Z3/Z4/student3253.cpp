/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <utility>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <string>
#include <exception>

enum class Boje { Pik, Tref, Herc, Karo };
const std::vector<Boje> sveBoje = { Boje::Pik, Boje::Tref, Boje::Herc, Boje::Karo };
const std::vector<std::string> naziviKarata = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };    

typedef std::list<std::pair<Boje, std::string>> Spil;

std::string dajStringBoje(Boje b) {
    switch (b) {
        case Boje::Pik: return "Pik";
        case Boje::Tref: return "Tref";
        case Boje::Herc: return "Herc";
        case Boje::Karo: return "Karo";
        default: return "Nepoznato";
    }
}

void ispisiSipl_Old(Spil &spil){
    for(auto karta : spil){
        std::cout<< dajStringBoje(karta.first) << " " << karta.second << std::endl;
    }
}

void ispisiSpil(Spil &spil){
    std::string boja = "NULL";
    std::cout << "U spilu trenutno ima " << spil.size() << " karata, i to:";
    for(auto karta : spil){
        if( dajStringBoje(karta.first) != boja){
            boja = dajStringBoje(karta.first);
            std::cout << std::endl;
            std::cout << boja << ":";
        }
        std::cout<< " " <<karta.second;
    }
    std::cout << std::endl;
}



void provjeriSpil(Spil &spil){
    auto itSpil = spil.begin();
    auto endSpil = spil.end();
    auto spilSize = spil.size();
    if(spilSize > 52){
        throw std::logic_error("Neispravna lista!");
    }
    
    for(Boje boja : sveBoje){
        for(std::string naziv : naziviKarata){
            if(itSpil == endSpil){
                return;
            }
            if(itSpil->first == boja && itSpil->second == naziv){
                ++itSpil;
            }
        }
    }
    if(itSpil != endSpil){
        throw std::logic_error("Neispravna lista!");
    }
}

Spil KreirajSpil() {
    Spil spil;

    for (Boje boja: sveBoje) {
        for (std::string naziv: naziviKarata) {
            spil.push_back(std::make_pair(boja, naziv));
        }
    }    
    
    return spil;
}

void IzbaciKarte(Spil &spil, std::multimap<Boje, std::string> &crnaLista) {
    std::pair <std::multimap<Boje, std::string>::iterator, std::multimap<Boje, std::string>::iterator> ret;
    auto itSpil = spil.begin();

    provjeriSpil(spil);
    
    while (itSpil != spil.end()) {
        
        bool izbaciKartu = false;
        ret = crnaLista.equal_range(itSpil->first);
        for(std::multimap<Boje, std::string>::iterator itCL=ret.first; itCL != ret.second; ++itCL){
            if(itCL->second == itSpil->second){
                std::cout<<"Brisem: " << dajStringBoje(itCL->first) << " " << itCL->second << std::endl;
                crnaLista.erase(itCL);
                izbaciKartu = true;
                break;
            }
        }
        if(izbaciKartu){
            itSpil = spil.erase(itSpil);
        } else {
            itSpil++;
        }
    }
}

std::queue<std::pair<std::string, std::string>> IzbaciKarteRazbrajanjem(Spil &spil, const short int &r, const int &b){
    std::queue<std::pair<std::string, std::string>> red;
    auto itSpil = spil.begin();
    int korak = 1;
    int izbaceno = 0;
    
    if (r < 1 || r > 52 || b < 1){
        throw std::logic_error("Neispravni elementi za izbacivanje!");
        // std::cout << "Izuzetak: Neispravni elementi za izbacivanje!" << std::endl;
    }
    provjeriSpil(spil);
    
    while(izbaceno < b) {
        if(spil.begin() == spil.end()){
            return red;
        }
        
        if(korak == r){
            izbaceno++;
            red.push(std::make_pair(dajStringBoje(itSpil->first), itSpil->second));
            // std::cout << "Brisem " << dajStringBoje(itSpil->first) << " " << itSpil->second << std::endl;
            itSpil = spil.erase(itSpil);
            korak = 1;
            
            if(itSpil == spil.end()) {
                itSpil = spil.begin();
            }
            
            continue;
        }
        
        if (itSpil != spil.end()) {
            ++itSpil; 
            ++korak;
        } else {
            itSpil = spil.begin();
        }
    }
    return red;
}

void provjeriValidnostReda(std::queue<std::pair<std::string, std::string>> red, int n){
    if(n<0){
        throw std::domain_error("Broj n je besmislen!");
    }
    if(n > red.size()){
        throw std::range_error("Nedovoljno karata u redu!");
    }
    while(!red.empty()){
        std::string boja = red.front().first;
        if(boja != "Pik" && boja !="Tref" && boja != "Herc" && boja!="Karo"){
            throw std::logic_error("Neispravne karte!");
        }
        if(std::find(naziviKarata.begin(), naziviKarata.end(), red.front().second) == naziviKarata.end()){
            throw std::logic_error("Neispravne karte!");
        }
        red.pop();
    }
}

void VratiPrvihNKarata(Spil &spil, std::queue<std::pair<std::string, std::string>> &red, int n){
    provjeriValidnostReda(red, n);
    
    while(n>0){
        auto trenutna = red.front();
        
        auto itSpil = spil.begin();
        for(Boje boja: sveBoje) {
            for(std::string naziv: naziviKarata){
                if(itSpil->first == boja && itSpil->second == naziv){
                    ++itSpil;
                } else if(trenutna.first == dajStringBoje(boja) && trenutna.second == naziv){
                    spil.insert(itSpil, std::make_pair(boja, naziv));
                }
            }
        }
        red.pop();
        n--;
    }
}

int main ()
{
    Spil nepotpunSpil = {
        { Boje::Pik , "2" },
        { Boje::Pik , "3" },
        { Boje::Pik , "4" },
        { Boje::Pik , "5" },
        { Boje::Pik , "6" },
        { Boje::Pik , "7" },
        { Boje::Pik , "8" },
        { Boje::Pik , "9" },
        { Boje::Pik , "10" },
        { Boje::Pik , "J" },
        { Boje::Pik , "Q" },
        { Boje::Pik , "K" },
        { Boje::Pik , "A" },
        
        { Boje::Tref , "2" },
        { Boje::Tref , "3" },
        { Boje::Tref , "4" },
        { Boje::Tref , "5" },
        { Boje::Tref , "6" },
        { Boje::Tref , "7" },
        { Boje::Tref , "8" },
        { Boje::Tref , "9" },
        { Boje::Tref , "10" },
        { Boje::Tref , "J" },
        { Boje::Tref , "Q" },
        { Boje::Tref , "K" },
        { Boje::Tref , "A" },
        
        { Boje::Herc , "2" },
        { Boje::Herc , "3" },
        { Boje::Herc , "4" },
        { Boje::Herc , "5" },
        { Boje::Herc , "6" },
        { Boje::Herc , "7" },
        { Boje::Herc , "8" },
        { Boje::Herc , "9" },
        { Boje::Herc , "10" },
        { Boje::Herc , "J" },
        { Boje::Herc , "Q" },
        { Boje::Herc , "K" },
        { Boje::Herc , "A" },
        
        { Boje::Karo , "2" },
        { Boje::Karo , "3" },
        { Boje::Karo , "4" },
        { Boje::Karo , "5" },
        { Boje::Karo , "6" },
        { Boje::Karo , "7" },
        { Boje::Karo , "8" },
        { Boje::Karo , "9" },
        { Boje::Karo , "10" },
        { Boje::Karo , "J" },
        { Boje::Karo , "Q" },
        { Boje::Karo , "K" },
        { Boje::Karo , "A" },
        
    };
    
    std::multimap<Boje, std::string> crnaLista = {
        { Boje::Herc , "A" },
        { Boje::Herc , "Q" },
        { Boje::Karo , "9" },
        { Boje::Pik , "9" },
    };

    /*    
    std::cout << std::endl << "Testiranje KreirajSpil" << std::endl;
    Spil spil = KreirajSpil();
    ispisiSpil(spil);
    
   Spil testSpil = nepotpunSpil;
   std::cout << std::endl << "Testiranje IzbaciKarte" << std::endl;
   ispisiSpil(testSpil);
   std::cout << "CRNA LISTA BEFORE" << std::endl;
   for(auto karta: crnaLista) {
       std::cout << dajStringBoje(karta.first) << " " << karta.second << std::endl;
   }
   IzbaciKarte(testSpil, crnaLista);
   ispisiSpil(testSpil);
   std::cout << "CRNA LISTA AFTER" << std::endl;
   for( auto karta : crnaLista) {
       std::cout << dajStringBoje(karta.first) << " " <<karta.second << std::endl;
   }
   */
   
   // std::cout << std::endl << "Testiranje IzbaciKarteRzbrajanjem i VratiPrvihKarata" << std::endl;
   int r, b, n;
   // while(true){
   try {
       std::cout << "Unesite korak razbrajanja: ";
       std::cin >> r;
       std::cout << "Unesite broj karata koje zelite izbaciti: ";
       std::cin >> b;
       std::queue<std::pair<std::string, std::string>> red = IzbaciKarteRazbrajanjem(nepotpunSpil, r, b);
       ispisiSpil(nepotpunSpil);
       std::cout<< "Unesite broj karata koje zelite vratiti u spil: ";
       std::cin >> n;
       VratiPrvihNKarata(nepotpunSpil, red, n);
       ispisiSpil(nepotpunSpil);
       // std::cout<<"--------------------------------------------------" << std::endl;
   } catch (std::exception &ex) {
       std::cout << "Izuzetak: " << ex.what() << std::endl;
   }
   // }
	return 0;
}
