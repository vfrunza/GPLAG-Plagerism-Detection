
/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <stdexcept>
#include <memory>

struct Korisnik {
    std::string ime;
    std::string prezime;
    std::string adresa;
    std::string telefon;
};

class Knjiga {
    std::string naslov;
    std::string ime_pisca;
    std::string zanr;
    int godina_izdavanja;
    std::shared_ptr<Korisnik> zaduzenje = nullptr;
    public:
    Knjiga(std::string naslo, std::string imep, std::string z, int god) {
        naslov = naslo;
        ime_pisca = imep;
        zanr=z;
        godina_izdavanja = god;
    }
    std::string DajNaslov() const { return naslov; }
    std::string DajAutora() const { return ime_pisca; }
    std::string DajZanr() const { return zanr; }
    int DajGodinuIzdavanja() const { return godina_izdavanja; }
    std::shared_ptr<Korisnik> DajKodKogaJe() const { return zaduzenje; }
    
    void ZaduziKnjigu(Korisnik &k) {
        zaduzenje = std::make_shared<Korisnik>(k);
    }
    void RazduziKnjigu() {
        zaduzenje = nullptr;
    }
    bool DaLiJeZaduzena() const {
        if(zaduzenje == nullptr) return false;
        return true;
    }
};

class Biblioteka {
    std::map<int, std::shared_ptr<Korisnik>> korisnici;
    std::map<int, std::shared_ptr<Knjiga>> knjige;
    public:
    void RegistrirajNovogKorisnika(int clanskibr, std::string imek, std::string prezimek, std::string adresak, std::string telefonk) {
            Korisnik novi{imek,prezimek,adresak,telefonk};
            std::shared_ptr<Korisnik> k(std::make_shared<Korisnik>(novi));
            if(!korisnici.count(clanskibr)) korisnici[clanskibr] = k;
            else throw std::logic_error("Korisnik vec postoji");
        
    }
    void RegistrirajNovuKnjigu(int brknjige, std::string naslovk, std::string ime_piscak, std::string zanrk, int godina_izdavanjak) {
        Knjiga nova{naslovk,ime_piscak,zanrk,godina_izdavanjak};
            std::shared_ptr<Knjiga> k(std::make_shared<Knjiga>(nova));
            if(!knjige.count(brknjige)) knjige[brknjige] = k;
            else throw std::logic_error("Knjiga vec postoji");
    }
    
    Korisnik &NadjiKorisnika(int clanskibr) const {
        auto it(korisnici.find(clanskibr));
        if(it== korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
        else return *(it->second);
    }
    
    Knjiga &NadjiKnjigu(int brknjige) const {
        auto it(knjige.find(brknjige));
        if(it== knjige.end()) throw std::logic_error("Knjiga nije nadjena");
        else return *(it->second);
    }
    
    void IzlistajKorisnike() const {
        for(auto it = korisnici.begin(); it!=korisnici.end(); it++) {
        std::cout << "Clanski broj: "<< it->first << std::endl;
        std::cout << "Ime i prezime: "<<it->second->ime << " "<<it->second->prezime<<std::endl;
        std::cout << "Adresa: "<<it->second->adresa << std::endl;
        std::cout << "Broj telefona: "<<it->second->telefon;
        std::cout << std::endl;
        std::cout << std::endl;
        }
    }
    void IzlistajKnjige() const {
        for(auto it = knjige.begin(); it!=knjige.end(); it++) {
        std::cout << "Evidencijski broj: "<< it->first << std::endl;
        std::cout << "Naslov: "<<it->second->DajNaslov() << std::endl;
        std::cout << "Pisac: "<<it->second->DajAutora() << std::endl;
        std::cout << "Zanr: "<<it->second->DajZanr() << std::endl;
        std::cout << "Godina izdavanja: "<<it->second->DajGodinuIzdavanja() << std::endl;
        if(it->second->DaLiJeZaduzena()) std::cout << "Zaduzena kod korisnika: "<<it->second->DajKodKogaJe()->ime << " " <<it->second->DajKodKogaJe()->prezime;
        std::cout << std::endl;
        std::cout << std::endl;
        }
    }
    
    void ZaduziKnjigu(int brknjige, int clanskibr) {
        auto it(knjige.find(brknjige));
        if(it== knjige.end()) throw std::logic_error("Knjiga nije nadjena");
        auto it1(korisnici.find(clanskibr));
        if(it1== korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
        if(it->second->DaLiJeZaduzena()) throw std::logic_error("Knjiga vec zaduzena");
        it->second->ZaduziKnjigu(*(it1->second));
    }
    
    void RazduziKnjigu(int brknjige) {
        auto it(knjige.find(brknjige));
        if(it == knjige.end()) throw std::logic_error("Knjiga nije nadjena");
        if(!(it->second->DaLiJeZaduzena())) throw std::logic_error("Knjiga nije zaduzena");
        it->second->RazduziKnjigu();
    }
    
    void PrikaziZaduzenja(int clanskibr) const {
        auto it1(korisnici.find(clanskibr));
        if(it1== korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
        bool zaduzeno=false;
        for(auto it = knjige.begin(); it!=knjige.end(); it++) {
            if((*(it->second->DajKodKogaJe())).ime == (*(it1->second)).ime && (*(it->second->DajKodKogaJe())).prezime == (*(it1->second)).prezime && (*(it->second->DajKodKogaJe())).adresa == (*(it1->second)).adresa && (*(it->second->DajKodKogaJe())).telefon == (*(it1->second)).telefon) {
                zaduzeno=true;
                std::cout << "Naslov: "<<it->second->DajNaslov() << std::endl;
                std::cout << "Pisac: "<<it->second->DajAutora() << std::endl;
                std::cout << "Zanr: "<<it->second->DajZanr() << std::endl;
                std::cout << "Godina izdavanja: "<<it->second->DajGodinuIzdavanja();
                std::cout << std::endl;
                std::cout << std::endl;
            }
        }
        if(zaduzeno == false) throw std::logic_error("Nema zaduzenja za tog korisnika!");
    }
    
};
int main() {
    
    return 0;
}