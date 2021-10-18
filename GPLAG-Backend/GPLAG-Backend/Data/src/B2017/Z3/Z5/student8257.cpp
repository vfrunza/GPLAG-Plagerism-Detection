/B2017/2018: Zadaća 3, Zadatak 5
#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <stdexcept>
#include <stack>
#include <iterator>

using std::pair;
using std::vector;
using std::string;
using std::multimap;
using std::stack;

enum class Boje {Pik, Tref , Herc , Karo};

vector<string> nazivi {"Pik","Tref","Herc","Karo"};
vector<string> v {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};

struct Karta {
  Boje boja;
  string vrijednost;
};

struct Cvor {
  Karta karta;
  Cvor* sljedeci;
};

void IspisiKarte(Cvor *prviCvor);

void IspisiStek(stack<pair<string,string>> stek) {
    while(!stek.empty()) {
        auto karta = stek.top();
        std::cout<<karta.first<<"-"<<karta.second<<" ";
        stek.pop();
    }
}

int brojKarata(Cvor *prviCvor) {
    if(prviCvor==nullptr) return 0;
    int broj=1;
    auto p = prviCvor;
    while(true) {
        p=p->sljedeci;
        if(p==prviCvor) break;
        broj++;
    }
    return broj;
}

bool postojiUSpilu(Cvor *prviCvor , pair<Boje,string> karta) {
    auto p = prviCvor;
    for(int i=0;i<brojKarata(prviCvor);i++) {
        if((p->karta).boja == karta.first && (p->karta).vrijednost == karta.second) 
            return true;
        p=p->sljedeci;
    }
    return false;
}


Cvor *KreirajSpil() {
    Cvor *pocetak = nullptr , *prethodni;
        for(int i=0;i<nazivi.size();i++) {
            for(int j=0;j<v.size();j++) {
                Cvor* novi = new Cvor{Karta{Boje(i),v.at(j)},nullptr};
                if(pocetak==nullptr) pocetak = novi;      // Samo za pocetni cvor
                else prethodni->sljedeci = novi;        // veza izmedju dva cvora
                prethodni = novi;
            }
        }
        prethodni->sljedeci = pocetak;       // Zadnji element pokazuje na pocetak (kruzna lista)
        return pocetak;
}

void IspravnostSpila(Cvor *prviCvor) {
    if(prviCvor == nullptr) return;
    int brKarata = 0;
    auto prethodna = prviCvor;
    auto p = prviCvor;
    for(int i=0;i<brojKarata(prviCvor);i++) {
        p=p->sljedeci;
        brKarata++;
        // Ako su podaci liste besmisleni (Program ce dozvoliti samo da vrijednost karte bude besmislena)
        if(std::count(v.begin(),v.end(),(p->karta).vrijednost)==0)
            throw std::logic_error("Neispravna lista!");
        if(brKarata>52) throw std::logic_error("Neispravna lista!"); 
        if(int((prethodna->karta).boja) > int((p->karta).boja) || 
            ((std::find(v.begin(),v.end(),(prethodna->karta).vrijednost)) > std::find(v.begin(),v.end(),(p->karta).vrijednost) && int((prethodna->karta).boja)==int((p->karta).boja))) 
            throw std::logic_error("Neispravna list3!");
    }
        
}

void IzbaciKarte(Cvor *&prviCvor, multimap<Boje,string> &m) {
    IspravnostSpila(prviCvor);
    auto prethodna = prviCvor;
    auto p = prviCvor;              // Pokazivac sa kojim cemo se kretati kroz listu
    while(true) {
        p = p->sljedeci;
        bool postoji = false;
        auto it = m.begin();     // Za svaku kartu u listi, pretrazujem mapu
        while(it!=m.end()) {
            if(it->first == (p->karta).boja && it->second == (p->karta).vrijednost){                // Ako postoji karta iz liste u mapi , izbrisi je u mapi
                it = m.erase(it);
                postoji = true;
            }
            else it++;
        }
        if(postoji) {   // Ako karta postoji u multimapi, treba je izbaciti iz liste
            if(p == p->sljedeci) {                   // Ako brisem zadnju preostalu kartu iz liste 
                delete p;
                prviCvor = nullptr;
                break;                              // izadji iz petlje kad se isprazni lista
            }
            else {                              
                prethodna->sljedeci = p->sljedeci;      // preusmjeri prethodnu kartu na sljedecu poslije trenutne
                delete p;                               // izbrisi trenutnu kartu
                if(p==prviCvor)
                    prviCvor = prethodna->sljedeci;    // Ako smo izbrisali prvu kartu u listi , iduca karta u listi postaje druga
                p = prethodna->sljedeci;            // prebaci pokazivac sa izbrisane karte na sljedecu u listi
            }
        }
        else {              // Ako ne treba brisati kartu
            if(p==p->sljedeci) // Ako zadnju preostalu kartu ne treba brisati , izadji iz petlje
                break;
            prethodna = p;    // Azuriraj prethodnu kartu da pokazuje na trenutnu
        }
    }
}

stack<pair<string,string>> IzbaciKarteRazbrajanjem(Cvor *&prviCvor, const short &r , const int &b) {
    if(r<1 || r>52 || b<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    //if(prviCvor==nullptr) return;
    IspravnostSpila(prviCvor);
    stack<pair<string,string>> stek;
    // KRUZNO IZBACIVANJE KARATA 
    auto p = prviCvor , prethodna = prviCvor;
    int brojac=0;
    while(brojac<b) {
        int korak=0;
        if(p == p->sljedeci ) { // Ako se isprazni spil
            stek.push({ nazivi.at(int((p->karta).boja)) , (p->karta).vrijednost});
            delete p;
            prviCvor = nullptr;
            break; 
        }
        while(korak<r-1) {           // r-1 zbog brisanja
            prethodna = p;
            p=p->sljedeci;
            korak++;
        }
        stek.push({ nazivi.at(int((p->karta).boja)) , (p->karta).vrijednost});
        if(p!=prviCvor) {                                   // Ako ne brisem prvi cvor
            prethodna->sljedeci = p->sljedeci;
            delete p;
            p = prethodna->sljedeci;
        }
        else if(p==prviCvor) {                              // Ako brisem prvi cvor
            auto zadnja = prviCvor;
            for(int i=0;i<brojKarata(prviCvor)-1;i++) zadnja = zadnja->sljedeci;
            prviCvor = p->sljedeci;
            delete p;
            p = prviCvor;
            zadnja->sljedeci = p;
            IspravnostSpila(prviCvor);
        }
        brojac++;
    }
    return stek;
}

void VratiPosljednjihNKarata(Cvor *&prviCvor, stack<pair<string,string>> &stek, int n) {
    //Provjera ispravnosti spila i reda
    
    if(n<0) throw std::domain_error("Broj n je besmislen!");
    if(n>stek.size()) throw std::range_error("Nedovoljno karata u steku!");
    if(prviCvor==nullptr) return;
    IspravnostSpila(prviCvor);

    // VRACANJE "n" KARATA IZ steka u spil
    int brojac=0;
    int duzinaSteka = stek.size();
    for(int i=0;i<duzinaSteka;i++) {
        pair<string,string> par = stek.top();
        if(std::count(nazivi.begin(),nazivi.end(),par.first)==0 || std::count(v.begin(),v.end(),par.second)==0)
            throw std::logic_error("Neispravne karte!");
        
        int indeks = std::find(nazivi.begin(),nazivi.end(),par.first)-nazivi.begin();  // indeks naziva trenutne karte
        
        pair<Boje,string> karta = {Boje(indeks),par.second};                             //TRENUTNA KARTA KOJU ISPITUJEM
        if(!postojiUSpilu(prviCvor,karta) && brojac<n) {             // Ako karta iz steka ne postoji u spilu , vrati je u spil.
            auto p = prviCvor;
            auto prethodni = prviCvor;
            int j=0;
            // TRAZENJE PRAVOG MJESTA ZA UMETANJE KARTE
            while(j<brojKarata(prviCvor) && int((p->karta).boja) < indeks) {
                prethodni = p;
                p=p->sljedeci;
                j++;
            }
            while(j<brojKarata(prviCvor) && (std::find(v.begin(),v.end(),par.second) > std::find(v.begin(),v.end(),(p->karta).vrijednost) && int((p->karta).boja)==indeks)) {
                prethodni = p;
                p=p->sljedeci;
                j++;
            }
            if(p!=prviCvor) {
                Cvor* novi = new Cvor{{karta.first,karta.second},nullptr};      // Kreiraj novi cvor i uvezi ga u listu
                prethodni->sljedeci = novi;
                novi->sljedeci = p;
            }
            else if(p==prviCvor) {
                auto zadnja = prviCvor; for(int i=0;i<brojKarata(prviCvor)-1;i++) zadnja = zadnja->sljedeci;  // Ako moram da ubacim na mjesto prvog cvora,moram zadnji cvor povezati sa novim prvim
                Cvor* novi = new Cvor{{karta.first,karta.second},nullptr};
                if(int(karta.first) <= int((p->karta).boja))            // Ovo rjesava slucaj kad se ubacuje karta izmedju zadnje i prve, a pri tom ta karta je veca od prve
                    prviCvor = novi;
                if(zadnja!=nullptr)                 // Ako postoji makar jedna karta (tj. ako spil nije prazan)
                    zadnja->sljedeci = novi;
                novi->sljedeci = p;
            }
            brojac++;
        }
        stek.pop();
    }
} 

void UnistiSpil(Cvor *prviCvor) {
    if(prviCvor == nullptr) return;
    int duzinaListe = brojKarata(prviCvor);
    auto iduci = prviCvor, p = prviCvor;
    for(int i=0;i<duzinaListe;i++) {
        iduci = p->sljedeci;
        delete p;
        p=iduci;
    }
    prviCvor = nullptr;
}

void IspisiKarte(Cvor *prviCvor) {
    auto it = prviCvor;
    int indeksNaziva = 0;
    int brojac=0;
    auto duzinaListe = brojKarata(prviCvor);
    while(indeksNaziva<4) {
        std::cout<<nazivi.at(indeksNaziva)<<": ";
        while(brojac<duzinaListe && nazivi.at(int((it->karta).boja)) == nazivi.at(indeksNaziva)) {
            std::cout<<(it->karta).vrijednost<<" ";
            it = it->sljedeci;
            brojac++;
        }
        indeksNaziva++;
        std::cout<<std::endl;
    }
}

int main ()
{
    try {
        auto spil = KreirajSpil();
        //IspisiKarte(spil);
        std::cout<<"Unesite korak razbrajanja: ";
        short int r;
        std::cin>>r;
        std::cout<<"Unesite broj karata koje zelite izbaciti: ";
        int b;
        std::cin>>b;
        try {
            auto izbaceneKarte = IzbaciKarteRazbrajanjem(spil,r,b);
            std::cout<<"U spilu trenutno ima "<<brojKarata(spil)<<" karata, i to:\n";
            IspisiKarte(spil);
            std::cout<<"Unesite broj karata koje zelite vratiti u spil: ";
            int n;
            std::cin>>n;
            VratiPosljednjihNKarata(spil,izbaceneKarte,n);
            std::cout<<"U spilu trenutno ima "<<brojKarata(spil)<<" karata, i to:\n";
            IspisiKarte(spil);
        }
        catch(...) {
            UnistiSpil(spil);
            throw;
        }
        UnistiSpil(spil);
        return 0;
    }
    catch(std::logic_error e1) {
        std::cout<<"Izuzetak: "<<e1.what();
    }
    catch(std::range_error e2) {
        std::cout<<"Izuzetak: "<<e2.what();
    }
}
