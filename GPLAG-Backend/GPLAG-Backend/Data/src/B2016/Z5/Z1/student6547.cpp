/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include <iterator>

struct Korisnik {
    std::string ime, prezime, adresa, telefon;
};

class Knjiga {
    std::string naslov, ime_pisca, zanr;
    int godina_izdavanja;
    Korisnik *pok;
    
    public:
    Knjiga(std::string naslovknjige, std::string pisac, std::string vrsta, int godina) {
        naslov=naslovknjige;
        ime_pisca=pisac;
        zanr=vrsta;
        godina_izdavanja=godina;
        pok=nullptr;
    }
    std::string DajNaslov() const {
        return naslov;
    }
    std::string DajAutora() const {
        return ime_pisca;
    }
    std::string DajZanr() const {
        return zanr;
    }
    int DajGodinuIzdavanja() const {
        return godina_izdavanja;
    }
    Korisnik *DajKodKogaJe() const {
        return pok;
    }
    void ZaduziKnjigu(Korisnik &osoba) {
        pok=&osoba;
    }
    void RazduziKnjigu() {
        pok=nullptr;
    }
    bool DaLiJeZaduzena() {
        if(pok==nullptr) return false;
        else return true;
    }
};

class Biblioteka {
    std::map<int, Korisnik*> korisnici;
    std::map<int, Knjiga*> knjige;
    public:
    void RegistrirajNovogKorisnika(int clanski_broj, std::string ime, std::string prezime, std::string adresa, std::string br_telefona);
    void RegistrirajNovuKnjigu(int broj_knjige, std::string naslov, std::string ime_pisca, std::string zanr, int godina_izdavanja);
    Korisnik &NadjiKorisnika(int broj_korisnika);
    ~Biblioteka();
    Knjiga &NadjiKnjigu(int broj_knjige);
    void IzlistajKorisnike() const;
    void IzlistajKnjige() const;
    void ZaduziKnjigu(int ev_broj, int clanski_broj);
    void RazduziKnjigu(int ev_broj);
    void PrikaziZaduzenja ( int ev_broj);
};
   
    void Biblioteka::RegistrirajNovogKorisnika(int clanski_broj, std::string ime, std::string prezime, std::string adresa, std::string br_telefona) {
        auto it(korisnici.find(clanski_broj));
        if(it!=korisnici.end()) throw std::logic_error("Korisnik vec postoji");
        Korisnik *pok=nullptr;
        try{
            pok=new Korisnik{ime, prezime,adresa,br_telefona};
            korisnici.insert(std::make_pair(clanski_broj,pok));
        }
        catch(...) {
            std::cout<<"Nedovoljno memorije";
            throw;
        }
    }
    void Biblioteka::RegistrirajNovuKnjigu(int broj_knjige, std::string naslov, std::string ime_pisca, std::string zanr, int godina_izdavanja) {
        auto it(knjige.find(broj_knjige));
        if(it!=knjige.end()) throw std::logic_error("Knjiga vec postoji");
        try{
            Knjiga *pok=new Knjiga(naslov, ime_pisca, zanr, godina_izdavanja);
            knjige.insert(std::make_pair(broj_knjige, pok));
        }
        catch(...) {
            std::cout<<"Nedovoljno memorije";
        }
    }
    Korisnik &Biblioteka::NadjiKorisnika(int broj_korisnika) {
        auto it(korisnici.find(broj_korisnika));
        if(it==korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
        else {
            return *it->second;
        }
    }
    Knjiga &Biblioteka::NadjiKnjigu(int broj_knjige) {
        auto it(knjige.find(broj_knjige));
        if(it==knjige.end()) throw std::logic_error("Knjiga nije nadjena");
        else {
            return *it->second;
        }
    }
    void Biblioteka::IzlistajKorisnike() const {
        for(auto it=korisnici.begin(); it!=korisnici.end(); it++) {
            std::cout<<"Clanski broj: "<<it->first<<std::endl;
            std::cout<<"Ime i prezime: "<<it->second->ime<<" "<<it->second->prezime<<std::endl;
            std::cout<<"Adresa: "<<it->second->adresa<<std::endl;
            std::cout<<"Broj telefona: "<<it->second->telefon<<std::endl;
        }
    }
    void Biblioteka::IzlistajKnjige() const {
        for(auto it=knjige.begin(); it!=knjige.end(); it++) {
            std::cout<<std::endl<<"Evidencijski broj: "<<it->first<<std::endl;
            std::cout<<"Naslov: "<<it->second->DajNaslov()<<std::endl;
            std::cout<<"Pisac: "<<it->second->DajAutora()<<std::endl;
            std::cout<<"Zanr: "<<it->second->DajZanr()<<std::endl;
            std::cout<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<std::endl;
            if(it->second->DajKodKogaJe()!=nullptr) {
                std::cout<<"Zaduzena kod korisnika: "<<it->second->DajKodKogaJe()->ime<<" "<<it->second->DajKodKogaJe()->prezime;
            }
        }
    }
    void Biblioteka::ZaduziKnjigu(int ev_broj, int clanski_broj) {
        auto it(knjige.find(ev_broj));
        if(it==knjige.end()) throw std::logic_error("Knjiga nije nadjena");
        auto it1(korisnici.find(clanski_broj));
        if(it1==korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
        auto it2(knjige.find(ev_broj));
        if(it2->second->DaLiJeZaduzena()==true) throw std::logic_error("Knjiga vec zaduzena");
        it2->second->ZaduziKnjigu(*(it1->second));
    }
    void Biblioteka::RazduziKnjigu(int ev_broj) {
        auto it(knjige.find(ev_broj));
        if(it==knjige.end()) throw std::logic_error("Knjiga nije nadjena");
        auto it2(knjige.find(ev_broj));
        if(it2->second->DaLiJeZaduzena()==true) throw std::logic_error("Knjiga vec zaduzena");
        it2->second->RazduziKnjigu();
    }
    void Biblioteka::PrikaziZaduzenja(int ev_broj) {
        auto it1(korisnici.find(ev_broj));
        if(it1==korisnici.end()) { throw std::logic_error("Korisnik nije nadjen"); }
        for(auto it=knjige.begin(); it!=knjige.end(); it++) {
            if(it->second->DajKodKogaJe()==it1->second) {std::cout<<std::endl<<"Evidencijski broj: "<<it->first<<std::endl;
            std::cout<<"Naslov: "<<it->second->DajNaslov()<<std::endl;
            std::cout<<"Pisac: "<<it->second->DajAutora()<<std::endl;
            std::cout<<"Zanr: "<<it->second->DajZanr()<<std::endl;
            std::cout<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<std::endl;
           
        }
    }
    }
        Biblioteka::~Biblioteka() {
            for(auto it=korisnici.begin(); it!=korisnici.end(); it++) {
                delete it->second;
            }
            for(auto it=knjige.begin(); it!=knjige.end(); it++) {
                delete it->second;
            }
            
        }
    

int main () {
    Biblioteka nasa_biblioteka;
    int kraj=100;
    try {
    while(kraj!=0) {
        std::cout<<"Unesite: "<<std::endl;
        std::cout<<"1 za registraciju novog korisnika "<<std::endl;
        std::cout<<"2 za registraciju nove knjige "<<std::endl;
        std::cout<<"3 za izlistavanje korisnika "<<std::endl;
        std::cout<<"4 za izlistavanje knjiga "<<std::endl;
        std::cout<<"5 za pronalazak korisnika "<<std::endl;
        std::cout<<"6 za pronalazak knjige "<<std::endl;
        std::cout<<"7 za zaduzivanje knjige "<<std::endl;
        std::cout<<"8 za razduzivanje knjige "<<std::endl;
        std::cout<<"0 za kraj "<<std::endl;
        
        std::cin>>kraj;
        if(kraj==1) {
            int clanski_broj;
            std::cout<<"Unesite clanski_broj korisnika: ";
            std::string ime, prezime, adresa, telefon;
            std::cin>>clanski_broj;
            std::cin.ignore(1000, '\n');
            std::cout<<"Unesite ime korisnika: ";
            std::getline(std::cin, ime);
            std::cout<<"Unesite prezime korisnika: ";
            std:getline(std::cin, prezime);
            std::cout<<"Unesite adresu korisnika: ";
            std::getline(std::cin, adresa);
            std::cout<<"Unesite broj telefona korisnika: ";
            std::getline(std::cin, telefon);
            try{
                nasa_biblioteka.RegistrirajNovogKorisnika(clanski_broj,ime,prezime,adresa,telefon);
            }
            catch(std::logic_error izuzetak) {
                std::cout<<izuzetak.what()<<std::endl;
            }
        }
        
        if(kraj==2) {
            int broj_knjige;
            std::cout<<"Unesite evidencijski broj knjige: ";
            std::cin>>broj_knjige;
            std::cin.ignore(1000, '\n');
            std::string naslov, ime_pisca, zanr;
            int godina_izdavanja;
            std::cout<<"Unesite naslov knjige: ";
            std::getline(std::cin, naslov);
            std::cout<<"Unesite ime pisca: ";
            std::getline(std::cin, ime_pisca);
            std::cout<<"Unesite zanr: ";
            std::getline(std::cin, zanr);
            std::cout<<"Unesite godinu izdavanja knjige: ";
            std::cin>>godina_izdavanja;
            
            nasa_biblioteka.RegistrirajNovuKnjigu(broj_knjige,naslov,ime_pisca,zanr,godina_izdavanja);
        }
        if(kraj==3) {
            nasa_biblioteka.IzlistajKorisnike();
        }
        if(kraj==4) {
            nasa_biblioteka.IzlistajKnjige();
        }
        if(kraj==5) {
            int ev_broj, clanski_broj;
            std::cout<<"Unesite evidencijski broj knjige: ";
            std::cin>>ev_broj;
            std::cout<<"Unesite clanski broj korisnika: ";
            std::cin>>clanski_broj;
            nasa_biblioteka.ZaduziKnjigu(ev_broj,clanski_broj);
        }
        if(kraj==6) {
            std::cout<<"Unesite evidencijski broj knjige koju zelite razduziti: ";
            int ev_broj;
            std::cin>>ev_broj;
            nasa_biblioteka.RazduziKnjigu(ev_broj);
        }
        if(kraj==7) {
            std::cout<<"Unesite clanski broj korisnika za koji zelite vidjeti zaduzenja: ";
            int clanski_broj;
            std::cin>>clanski_broj;
            try {
                nasa_biblioteka.PrikaziZaduzenja(clanski_broj);
            }
            catch(std::logic_error izuzetak) {
                std::cout <<izuzetak.what() << std::endl;
            }
        }
        std::cout<<"Unesite opet zeljenu opciju: ";
        std::cin>>kraj;
    }
    }
    catch(std::logic_error greska) {
        std::cout<<greska.what()<<std::endl;
    }

	return 0;
}