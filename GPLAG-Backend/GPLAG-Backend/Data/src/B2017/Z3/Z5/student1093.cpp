/B2017/2018: Zadaća 3, Zadatak 5
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stdexcept>
#include <algorithm>
#include <stack>
#include <utility>
#include <new>

enum class Boje
{
    Pik, Tref, Herc, Karo
};

std::vector<std::string> NazivKarata {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};

struct Karta {
    Boje boja;
    std::string vrijednost;
};

struct Cvor {
    Karta karta;
    Cvor* sljedeci;
};

Cvor* KreirajSpil()
{
    Cvor *pocetak (nullptr), *pomocni;
    for (int i = 0; i < NazivKarata.size(); i++) {
        Cvor* temp = new Cvor;
        temp->karta.boja = Boje::Pik;
        temp->karta.vrijednost = NazivKarata.at(i);
        temp->sljedeci = nullptr;
        if(pocetak == nullptr) pocetak = temp;
        else pomocni->sljedeci = temp;
        pomocni = temp;
    }
    for (int i = 0; i < NazivKarata.size(); i++) {
        Cvor *temp = new Cvor;
        temp->karta.boja = Boje::Tref;
        temp->karta.vrijednost = NazivKarata.at(i);
        temp->sljedeci = nullptr;
        pomocni->sljedeci = temp;
        pomocni = temp;
    }
    for (int i = 0; i < NazivKarata.size(); i++) {
        Cvor *temp = new Cvor;
        temp->karta.boja = Boje::Herc;
        temp->karta.vrijednost = NazivKarata.at(i);
        temp->sljedeci = nullptr;
        pomocni->sljedeci = temp;
        pomocni = temp;
    }
    for (int i = 0; i < NazivKarata.size(); i++) {
        Cvor *temp = new Cvor;
        temp->karta.boja = Boje::Karo;
        temp->karta.vrijednost = NazivKarata.at(i);
        if(i == NazivKarata.size() - 1) temp->sljedeci = pocetak;
        else temp->sljedeci = nullptr;
        pomocni->sljedeci = temp;
        pomocni = temp;
    }
    return pocetak;
}

void Izuzeci(Cvor *pocetakspila)
{
    int brojac = 0;
    for(auto kretanje = pocetakspila; kretanje->sljedeci != pocetakspila; kretanje = kretanje->sljedeci) {
        brojac++;
        bool smislen = false;
        for(int i = 0; i < NazivKarata.size(); i++) {
            if(kretanje->karta.vrijednost == NazivKarata.at(i)) smislen = true;
        }
        if(smislen == false) throw std::logic_error("Neispravna lista!");

        if(brojac > 52) throw std::logic_error("Neispravna lista!");
        Boje boja;
        for(auto kretanje = pocetakspila; kretanje->sljedeci != pocetakspila; kretanje = kretanje->sljedeci) {
            boja = kretanje->karta.boja;
            while(kretanje->karta.boja == boja && kretanje->sljedeci != pocetakspila) {
                auto pomocnakarta = kretanje;
                kretanje = kretanje->sljedeci;
                if(kretanje->karta.boja != boja) break;
                auto nazivpomocna = std::find(NazivKarata.begin(), NazivKarata.end(), pomocnakarta->karta.vrijednost);
                auto nazivkretanje = std::find(NazivKarata.begin(), NazivKarata.end(), kretanje->karta.vrijednost);
                if(nazivpomocna >= nazivkretanje) throw std::logic_error("Neispravna lista!");
            }
            if(boja == Boje::Karo && kretanje->sljedeci != pocetakspila) throw std::logic_error("Neispravna lista!");
            for(auto kretanje2 = kretanje; kretanje2 != pocetakspila; kretanje2 = kretanje2->sljedeci) {
                if(boja == Boje::Pik) {
                    if(kretanje2->karta.boja == Boje::Pik) throw std::logic_error("Neispravna lista!");
                } else if(boja == Boje::Tref) {
                    if(kretanje2->karta.boja == Boje::Tref || kretanje2->karta.boja == Boje::Pik) throw std::logic_error("Neispravna lista!");
                } else if(boja == Boje::Herc) {
                    if(kretanje2->karta.boja == Boje::Pik || kretanje2->karta.boja == Boje::Tref || kretanje2->karta.boja == Boje::Herc) throw std::logic_error("Neispravna lista!");
                }
            }
            if(kretanje->sljedeci == pocetakspila) break;
        }
    }
}

void IzbaciKarte(Cvor *&pocetakspila, std::multimap<Boje, std::string> &m)
{
    Izuzeci(pocetakspila);
    auto novi = pocetakspila;
    auto kraj = pocetakspila;
    while(kraj->sljedeci != pocetakspila) kraj = kraj -> sljedeci;

    for(auto it = m.begin(); it != m.end();) { // pomjera se ručno ako se karta ne obriše ili pomoću erase ako se obriše
        bool obrisana(false);
        if((*it).first == novi->karta.boja && (*it).second == novi->karta.vrijednost) {
            obrisana = true;
            pocetakspila = pocetakspila->sljedeci;
            kraj->sljedeci = pocetakspila;
            if(pocetakspila == pocetakspila->sljedeci) pocetakspila = nullptr;
            delete novi;
            it = m.erase(it); // pomjera it za jedno mjesto
            novi = pocetakspila; 
        }
        if(obrisana == false) {
            for(auto kretanje = pocetakspila->sljedeci; kretanje != pocetakspila; kretanje = kretanje->sljedeci) {
                if((*it).first == kretanje->karta.boja && (*it).second == kretanje->karta.vrijednost) {
                    obrisana = true;
                    auto prethodnik = pocetakspila;
                    while(prethodnik->sljedeci != kretanje) prethodnik = prethodnik->sljedeci;
                    prethodnik->sljedeci = kretanje->sljedeci;
                    delete kretanje;
                    it = m.erase(it); // pomjera it za jedno mjesto
                    break;
                }
            }
        }
        if(obrisana == false) it++; // ako it nije pomjeren tj ako se nijedna karta nije obrisala, pomjeri
    }
}


std::stack<std::pair<std::string, std::string>>IzbaciKarteRazbrajanjem(Cvor* &pocetakspila, const short int &r, const int &b)
{
    if (r < 1 || r > 52 || b < 1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    Izuzeci(pocetakspila);
    auto kraj = pocetakspila;
    auto novi = pocetakspila;
    auto kretanje = pocetakspila;
    while(kraj->sljedeci != pocetakspila) kraj = kraj->sljedeci;
    std::stack<std::pair<std::string, std::string>> stek;
    int broj_izbacenih = 0;
    while(broj_izbacenih != b && pocetakspila != nullptr) {
        int korak(0);
        while(korak < r - 1) {
            kretanje = kretanje->sljedeci;
            korak++;
        }
        std::pair<std::string, std::string>element_steka;
        if(kretanje->karta.boja == Boje::Pik) element_steka.first = "Pik";
        else if(kretanje->karta.boja == Boje::Tref) element_steka.first = "Tref";
        else if(kretanje->karta.boja == Boje::Herc) element_steka.first = "Herc";
        else element_steka.first = "Karo";
        element_steka.second = kretanje->karta.vrijednost;
        stek.push(element_steka);
        if (kretanje == pocetakspila ) {
            if(pocetakspila == pocetakspila->sljedeci) {
                delete pocetakspila;
                pocetakspila = nullptr;
            }
            else {
                pocetakspila = pocetakspila->sljedeci;
                kraj->sljedeci = pocetakspila;
                delete novi;
                novi = pocetakspila;
                kretanje = pocetakspila;
                broj_izbacenih++;
            }
        }
        else {
            auto prethodnik = pocetakspila;
            while (prethodnik->sljedeci != kretanje) prethodnik = prethodnik->sljedeci;
            if(kretanje->sljedeci == pocetakspila) kraj = prethodnik;
            prethodnik->sljedeci = kretanje->sljedeci;
            kretanje->sljedeci = nullptr;
            delete kretanje;
            broj_izbacenih++;
            kretanje = prethodnik->sljedeci;                
        }
    }
    return stek;
}


void NeispravneKarte(const std::stack<std::pair<std::string, std::string>> &stek)
{
    auto pomocni = stek;
    while( !pomocni.empty()) {
        std::pair<std::string, std::string> p = pomocni.top();
        if (p.first != "Pik" && p.first != "Tref" && p.first != "Herc" && p.first != "Karo") throw std::logic_error("Neispravne karte!");
        bool smislen = false;
        for( int i = 0; i < NazivKarata.size(); i++) {
            if( NazivKarata.at(i) == p.second) smislen = true;
        }
        if ( smislen == false) throw std::logic_error("Neispravne karte!");
        pomocni.pop();
    }
}

std::string IspisiBoju(Boje b) {
    if(b == Boje::Pik) return "Pik ";
    else if(b == Boje::Tref) return "Tref ";
    else if(b == Boje::Herc) return "Herc ";
    else return "Karo ";
}

void VratiPosljednjihNKarata(Cvor* &pocetakspila, std::stack<std::pair<std::string, std::string>> &stek, int n)
{
    if (n  < 0) throw std::domain_error("Broj n je besmislen!");
    if (n > stek.size()) throw std::range_error("Nedovoljno karata u steku!");
    NeispravneKarte(stek);
    std::pair<std::string, std::string> p;
    for( int i = 0; i < n; i++) {
        p = stek.top();
        stek.pop();
        std::pair<Boje, std::string> pomocni;
        try {
            Cvor* novakarta = new Cvor;
            if(p.first == "Pik")  novakarta->karta.boja = Boje::Pik;
            else if(p.first == "Tref")  novakarta->karta.boja = Boje::Tref;
            else if(p.first == "Karo") novakarta->karta.boja = Boje::Karo;
            else novakarta->karta.boja = Boje::Herc;
            for( int j = 0; j < NazivKarata.size(); j++) {
                if ( p.second == NazivKarata.at(j)) novakarta->karta.vrijednost = NazivKarata.at(j);
            }
            //ako se u spilu vec nalazi karta novakarta, ignorisati je, ne ubacivati nazad;
            bool ubacena(false);
            if(pocetakspila != nullptr) {
                auto kraj = pocetakspila;
                while(kraj->sljedeci != pocetakspila) kraj = kraj->sljedeci;
                if(kraj->karta.boja == novakarta->karta.boja && kraj->karta.vrijednost == novakarta->karta.vrijednost){
                    delete novakarta;
                    continue;
                } 
                for(auto kretanje = pocetakspila; kretanje->sljedeci != pocetakspila; kretanje = kretanje->sljedeci) {
                    if (kretanje->karta.boja ==  novakarta->karta.boja && kretanje->karta.vrijednost == novakarta->karta.vrijednost){
                        delete novakarta;
                        continue;
                    }
                }
                //posto petlja ispod nece ici do kraja spila potrebno je posebno provjeriti zadnju kartu
                for(auto kretanje = pocetakspila;  kretanje->sljedeci != pocetakspila; kretanje = kretanje->sljedeci) {
                    ubacena = false;
                    if( novakarta->karta.boja > kretanje->karta.boja) continue;
                    else if(kretanje->sljedeci != pocetakspila && novakarta->karta.boja == kretanje->karta.boja) {
                        auto novakartait = std::find(NazivKarata.begin(), NazivKarata.end(), novakarta->karta.vrijednost);
                        //ubacena = false;
                        auto kretanjekrozboje(kretanje);
                        int kruzenje(0);
                        for(kretanjekrozboje = kretanje; kretanjekrozboje->karta.boja == kretanje->karta.boja; kretanjekrozboje = kretanjekrozboje->sljedeci) { // ova petlja će biti beskonačna ako se u špilu nalaze karte samo jedne boje pa se trebamo zaštiti od toga
                            if(kretanjekrozboje == kretanje) kruzenje++;
                            if(kruzenje > 1) break; // ako je kruzenje naislo na pocetnu kartu vise od jednom, petlja se izvrsila vec jednom citava i ne treba ponovo
                            auto kretanjekrozbojeit = std::find(NazivKarata.begin(), NazivKarata.end(), kretanjekrozboje->karta.vrijednost);
                            if ( novakartait > kretanjekrozbojeit ) continue;
                            // kada dođemo ispod ovog ifa kretanje kroz boje pokazuje na kartu koja treba biti nakon one što se ubacuje, pa trebamo naći prethodnika radi uvezivanja
                            auto prethodnik(pocetakspila);
                            while(prethodnik->sljedeci != kretanjekrozboje) prethodnik = prethodnik->sljedeci;
                            //ubacivanje karte
                            if(prethodnik->karta.boja > novakarta->karta.boja) pocetakspila = novakarta; // ako je boja karte koja dolazi prije karte koja se ubacuje veca od nje same, znaci da se karta ubacuje na pocetak
                            novakarta->sljedeci = kretanjekrozboje;
                            prethodnik->sljedeci = novakarta;
                            ubacena = true;
                            break;
                        }
                        if(ubacena == false) {
                            //ubacvanje karte
                            // ponovo tražimo prethodnu kartu
                            auto prethodnik(pocetakspila);
                            while(prethodnik->sljedeci != kretanjekrozboje) prethodnik = prethodnik->sljedeci;
                            if(prethodnik->karta.boja > novakarta->karta.boja) pocetakspila = novakarta;
                            novakarta->sljedeci = kretanjekrozboje;
                            prethodnik->sljedeci = novakarta;
                            ubacena = true;
                            break;
                        }
                    } 
                    if(ubacena) break;
                    else if(kretanje->sljedeci == pocetakspila || novakarta->karta.boja < kretanje->karta.boja) {
                        //ubaci
                        // ponovo tražimo prethodnu kartu
                        auto prethodnik(pocetakspila);
                        while(prethodnik->sljedeci != kretanje) prethodnik = prethodnik->sljedeci; 
                        if(prethodnik->karta.boja > novakarta->karta.boja) pocetakspila = novakarta;
                        novakarta->sljedeci = kretanje;
                        prethodnik->sljedeci = novakarta;
                        ubacena = true;
                        break;
                    }
                }
            }
            if(ubacena == false) {
                if(pocetakspila == nullptr) { // ako u spilu nije bila nijedna karta nasa karta je pocetak 
                    pocetakspila = novakarta;
                    pocetakspila->sljedeci = pocetakspila;
                }
                else if(pocetakspila == pocetakspila->sljedeci) { // ako je u spilu bila samo jedna karta petlja se nikad nije pokrenula i trebamo vidjeti gdje tu kartu ubacujemo
                    pocetakspila->sljedeci = novakarta;
                    novakarta->sljedeci = pocetakspila;
                    // dvije karte koje ce biti u spilu svakako ce biti medjusobno povezane, samo jos treba provjeriti gdje treba da bude pocetak
                    if(novakarta->karta.boja < pocetakspila->karta.boja) pocetakspila = novakarta; // ako se ubacuje npr pik a u spilu smo imali samo karo, pik treba postati pocetak spila
                    else if(novakarta->karta.boja == pocetakspila->karta.boja) { // ako su karte iste boje porede im se pozicije
                        auto novakartait = std::find(NazivKarata.begin(), NazivKarata.end(), novakarta->karta.vrijednost);
                        auto prisutnakartait = std::find(NazivKarata.begin(), NazivKarata.end(), pocetakspila->karta.vrijednost);
                        if(novakartait < prisutnakartait) pocetakspila = novakarta;
                        // iteratori ne mogu biti jednaki a ako je nova veca onda pocetak treba ostati gdje je bio
                    }
                    // na kraju, ako je boja nove karte veca od boje karte koja je vec bila tu pocetak treba ostati gdje je bio (na onoj koja je vec bila tu)
                }
            }
        }
        catch(...) {
            throw;
        }
    }
}
int BrojKarataUSpilu(Cvor* pocetak){
    int broj(1);
    if(pocetak == nullptr) return 0;
    else if(pocetak->sljedeci == pocetak) return 1;
    for( auto kretanje = pocetak; kretanje->sljedeci != pocetak; kretanje = kretanje->sljedeci){
        broj++;
    }
    return broj;
   
}

void UnistiSpil(Cvor* pocetakspila)
{
    if (pocetakspila == nullptr) return;
    auto pomocni = pocetakspila;
    while(pocetakspila->sljedeci != pomocni) {
        while ( pomocni->sljedeci != pocetakspila) {
            pomocni = pomocni -> sljedeci;
        }
        pomocni->sljedeci = pocetakspila->sljedeci;
        pocetakspila->sljedeci = nullptr;
        delete pocetakspila;
        pocetakspila = pomocni -> sljedeci;
    }
    pocetakspila->sljedeci = nullptr;
    pomocni->sljedeci = nullptr;
    if(pocetakspila == pomocni) {
        delete pocetakspila;
        pocetakspila = nullptr;
        pomocni = nullptr;
    }
    delete pocetakspila;
    delete pomocni;
}

int main ()
{
    Cvor *pocetak = nullptr;
    try {
        pocetak = KreirajSpil();
        auto pok = pocetak;
        short int r;
        std::cout<<"Unesite korak razbrajanja: ";
        std::cin>>r;
        int b;
        std::cout<<"Unesite broj karata koje zelite izbaciti: ";
        std::cin>>b;
        std::stack<std::pair<std::string, std::string>>stek;
        stek = IzbaciKarteRazbrajanjem(pocetak,r,b);
        std::cout<<"U spilu trenutno ima "<<BrojKarataUSpilu(pocetak)<<" karata, i to:"<<std::endl;
        std::cout << "Pik: ";
        for(pok = pocetak; pok != nullptr && pok->sljedeci != pocetak; pok = pok->sljedeci) {
            if(pok->karta.boja == Boje::Pik) std::cout << pok->karta.vrijednost << " ";
        }
        if(pok != nullptr && pok->karta.boja == Boje::Pik) std::cout << pok->karta.vrijednost;
        std::cout << std::endl << "Tref: ";
        for(pok = pocetak; pok != nullptr && pok->sljedeci != pocetak; pok = pok->sljedeci) {
            if(pok->karta.boja == Boje::Tref) std::cout << pok->karta.vrijednost << " ";
        }
        if(pok != nullptr && pok->karta.boja == Boje::Tref) std::cout << pok->karta.vrijednost;
        std::cout << std::endl << "Herc: ";
        for(pok = pocetak; pok != nullptr && pok->sljedeci != pocetak; pok = pok->sljedeci) {
            if(pok->karta.boja == Boje::Herc) std::cout << pok->karta.vrijednost << " ";
        }
        if(pok != nullptr && pok->karta.boja == Boje::Herc) std::cout << pok->karta.vrijednost;
        std::cout << std::endl << "Karo: ";
        for(pok = pocetak; pok != nullptr && pok->sljedeci != pocetak; pok = pok->sljedeci) {
            if(pok->karta.boja == Boje::Karo) std::cout << pok->karta.vrijednost << " ";
        }
        if(pok != nullptr && pok->karta.boja == Boje::Karo) std::cout << pok->karta.vrijednost;
        
        int n;
        std::cout<<std::endl;
        std::cout<<"Unesite broj karata koje zelite vratiti u spil: ";
        std::cin>>n;
        VratiPosljednjihNKarata(pocetak,stek,n);
        std::cout<<"U spilu trenutno ima "<<BrojKarataUSpilu(pocetak)<<" karata, i to:"<<std::endl;
        pok = pocetak;
        
        std::cout<<"Pik: ";
        for(pok = pocetak; pok!= nullptr && pok->sljedeci != pocetak; pok = pok->sljedeci){
            if(pok->karta.boja == Boje::Pik) std::cout<< pok->karta.vrijednost<<" ";
        }
        if(pok != nullptr && pok->karta.boja == Boje::Pik) std::cout<< pok->karta.vrijednost<<" ";
        std::cout<<std::endl<<"Tref: ";
        for(pok = pocetak; pok != nullptr && pok->sljedeci != pocetak; pok = pok->sljedeci){
            if(pok->karta.boja == Boje::Tref) std::cout<<pok->karta.vrijednost<<" ";
        }
        if(pok != nullptr && pok->karta.boja == Boje::Tref) std::cout<<pok->karta.vrijednost<<" ";
        std::cout<<std::endl<<"Herc: ";
        for(pok = pocetak; pok != nullptr && pok->sljedeci != pocetak; pok = pok->sljedeci){
            if(pok->karta.boja == Boje::Herc) std::cout<<pok->karta.vrijednost<<" ";
        }
        if(pok != nullptr && pok->karta.boja == Boje::Herc) std::cout<<pok->karta.vrijednost<<" ";
        std::cout<<std::endl<<"Karo: ";
        for(pok = pocetak; pok != nullptr && pok->sljedeci != pocetak; pok = pok->sljedeci){
            if(pok->karta.boja == Boje::Karo) std::cout<<pok->karta.vrijednost<<" ";
        }
        if(pok != nullptr && pok->karta.boja == Boje::Karo) std::cout<<pok->karta.vrijednost<<" ";
        
    }catch(std::domain_error e){
        std::cout<<"Izuzetak: "<<e.what();
    }
    catch(std::range_error e){
        std::cout<<"Izuzetak: "<<e.what();
    }
    catch(std::logic_error e) {
        std::cout <<"Izuzetak: "<<e.what();
    }
    
    UnistiSpil(pocetak);
    
    return 0;
}
