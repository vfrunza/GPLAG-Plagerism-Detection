/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <new>
#include <stdexcept>
#include <list>
#include <map>

struct Korisnik {
    std::string ime, prezime, adresa, telefon;
};

class Knjiga
{
    std::string naslovknjige, pisac, zanr;
    int godina;
    Korisnik *pok;
public:
    Knjiga(std::string naslov, std::string pisac, std::string zanr, int god, Korisnik *pokk=nullptr): naslovknjige(naslov), pisac(pisac), zanr(zanr), godina(god) {
        pok=pokk;
    }
    std::string DajNaslov() const {
        return naslovknjige;
    }
    std::string DajAutora() const {
        return pisac;
    }
    std::string DajZanr() const {
        return zanr;
    }
    int DajGodinuIzdavanja() const {
        return godina;
    }
    Korisnik DajKodKogaJe() const {
        return *pok;
    }
    void RazduziKnjigu()  {
        pok=nullptr;
    }
    void ZaduziKnjigu(Korisnik &korisnik) {
        pok=&korisnik;
    }
    bool DaLiJeZaduzena() const {
        if(pok==nullptr) return false;
        return true;
    }

};

class Biblioteka
{
    std::map<int, Korisnik*> mapakorisnika;
    std::map<int, Knjiga*> mapaknjiga;
public:
    // dodati: destruktor, kopirajuci + pomjerajuci konstruktor, razduzi i prikazizaduzenja
    void RegistrirajNovogKorisnika(int clbr, std::string ime, std::string prezime, std::string adr, std::string tel);
    void RegistrirajNovuKnjigu(int evbr, std::string naslov, std::string ime, std::string zanrr, int godina);
    Korisnik &NadjiKorisnika(int broj);
    Knjiga &NadjiKnjigu(int broj);
    void IzlistajKorisnike() const;
    void IzlistajKnjige() const;
    void ZaduziKnjigu(int evbr, int clbr);
    ~Biblioteka();
    void RazduziKnjigu(int evbr);
    void PrikaziZaduzenja(int clbr);
    // Biblioteka(cont Biblioteka &b);
};
/*
void Biblioteka::PrikaziZaduzenja(int clbr)
{
    bool ima=false;
for(auto it=mapakorisnika.begin(); it!=mapakorisnika.end(); it++) { if(it->first==clbr) { ima=true;
    for(auto it2=mapaknjiga.begin(); it2!=mapaknjiga.end(); it2++) {
        if(it2->second->DajKodKogaJe() == it) std::cout<<"E..."; //ispisi
    } }
    }  if(!ima) 
throw std::logic_error("Korisnik nije nadjen"); } */


void Biblioteka::RazduziKnjigu(int evbr)
{
    bool ima=false;
    for(auto it=mapaknjiga.begin(); it!=mapaknjiga.end(); it++) {
        if(it->first==evbr) { ima=true; break; } }
        if(!ima) throw std::logic_error("Knjiga nije nadjena");
    
    for(auto it=mapaknjiga.begin(); it!=mapaknjiga.end(); it++) if(it->first==evbr) {
            if(it->second->DaLiJeZaduzena()==false)
                throw std::logic_error("Knjiga nije zaduzena");
            if(it->second->DaLiJeZaduzena()) it->second->RazduziKnjigu();
        }
}


// Biblioteka::Biblioteka(const Biblioteka &b) {
//    for(int i=0; i<mapaknjiga)
//}

Biblioteka::~Biblioteka()
{
    for(auto it=mapaknjiga.begin(); it!=mapaknjiga.end(); it++) delete it->second;
    for(auto it=mapakorisnika.begin(); it!=mapakorisnika.end(); it++) delete it->second;
}

void Biblioteka::ZaduziKnjigu(int evbr, int clbr)
{
    if(mapaknjiga[evbr]->DaLiJeZaduzena()) throw std::logic_error("Knjiga vec zaduzena");
    for(auto it=mapaknjiga.begin(); it!=mapaknjiga.end(); it++) {
        if(it->first==evbr) break;
        if(it==mapaknjiga.end()) throw std::logic_error("Knjiga nije nadjena");
    }

    for(auto it=mapakorisnika.begin(); it!=mapakorisnika.end(); it++) {
        if(it->first==clbr) break;
        if(it==mapakorisnika.end()) throw std::logic_error("Korisnik nije nadjen");
    }

    mapaknjiga[evbr]->ZaduziKnjigu(*mapakorisnika[clbr]);

}

void Biblioteka::IzlistajKnjige() const
{
    for(auto it=mapaknjiga.begin(); it!=mapaknjiga.end(); it++)  {
        std::cout<<"Evidencijski broj: "<<it->first<<std::endl;
        std::cout<<"Naslov: "<<it->second->DajNaslov()<<std::endl;
        std::cout<<"Pisac: "<<it->second->DajAutora()<<std::endl;
        std::cout<<"Zanr: "<<it->second->DajZanr()<<std::endl;
        std::cout<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<std::endl;
        if(it->second->DaLiJeZaduzena()) std::cout<<"Zaduzena kod korisnika: "<<it->second->DajKodKogaJe().ime<<" "<<it->second->DajKodKogaJe().prezime<<std::endl;
        std::cout<<std::endl;
    }
}

void Biblioteka::IzlistajKorisnike() const
{
    for(auto it=mapakorisnika.begin(); it!=mapakorisnika.end(); it++) {
        std::cout<<"Clanski broj: "<<it->first<<std::endl;
        std::cout<<"Ime i prezime: "<<it->second->ime<<" "<<it->second->prezime<<std::endl;
        std::cout<<"Adresa: "<<it->second->adresa<<std::endl;
        std::cout<<"Broj telefona: "<<it->second->telefon<<std::endl;
        std::cout<<std::endl;
    }
}


void Biblioteka::RegistrirajNovogKorisnika(int clbr, std::string ime, std::string prezime, std::string adr, std::string tel)
{
    for(auto it=mapakorisnika.begin(); it!=mapakorisnika.end(); it++) if(it->first==clbr)
            throw std::logic_error("Korisnik vec postoji");
    mapakorisnika[clbr]=new Korisnik {ime, prezime, adr, tel};
}

void Biblioteka::RegistrirajNovuKnjigu(int evbr, std::string naslov, std::string ime, std::string zanrr, int godina)
{
    for(auto it=mapaknjiga.begin(); it!=mapaknjiga.end(); it++) if(it->first==evbr)
            throw std::logic_error("Knjiga vec postoji");
    mapaknjiga[evbr]=new Knjiga {naslov, ime, zanrr, godina};
}

Korisnik &Biblioteka::NadjiKorisnika(int broj)
{
    for(auto it=mapakorisnika.begin(); it!=mapakorisnika.end(); it++) if(it->first==broj) return *mapakorisnika[broj];
    throw std::logic_error("Korisnik nije nadjen");
}

Knjiga &Biblioteka::NadjiKnjigu(int broj)
{
    for(auto it=mapaknjiga.begin(); it!=mapaknjiga.end(); it++) if(it->first==broj) return *mapaknjiga[broj];
    throw std::logic_error("Knjiga nije nadjena");
}


int main ()
{
    Biblioteka bib;
    bib.RegistrirajNovogKorisnika(100, "Ajdin", "Zo", "Adresa", "061007");
    bib.RegistrirajNovogKorisnika(10500, "Miralem", "Pjanic", "Juve", "303030");
    bib.RegistrirajNovogKorisnika(101, "Abbb", "asnjas", "alja", "606060");
 //   bib.RegistrirajNovogKorisnika(100, "akask", "af", "akka", "2929");
    bib.IzlistajKorisnike();
    bib.RegistrirajNovuKnjigu(3, "Aa", "Bbb", "Aaaaa", 1999);
    bib.RegistrirajNovuKnjigu(2, "aaaa", "alkjfa", "jaf", 2020);
    bib.IzlistajKnjige();
    bib.ZaduziKnjigu(3, 100);
    bib.IzlistajKnjige();
    bib.RazduziKnjigu(35);
    bib.IzlistajKnjige();
    return 0;
}