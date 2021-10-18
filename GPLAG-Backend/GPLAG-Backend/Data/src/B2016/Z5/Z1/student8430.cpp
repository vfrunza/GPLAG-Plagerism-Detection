#include <iostream>

struct Korisnik {
    std::string ime, prezime, adresa, telefon;
    
}

class Knjiga {
    std::string naslov, ime_pisca, zanr;
    int godina_izdavanja;
    Korisnik *zaduzen=nullptr;
    Knjiga(std::string x, std::string y, std::string z, int k) : naslov(x), ime_pisca(y), zanr(z), godina_izdavanja(k) {}
    std::string DajNaslov() const { return naslov; }
    std::string DajAutora() const { return ime_pisca: }
    std::string DajZanr() const { return zanr; }
    int DajGodinuIzdavanja() const { return godina_izdavanja; }
    Korisnik *DajKodKogaJe() const { return zaduzen; }
    void ZaduziKnjigu(Korisnik &k) {
        zaduzen=&k;
    }
    void RazduziKnjigu() {
        zaduzen=nullptr;
    } 
    bool DaLiJeZaduzena() {
        if(zaduzena!=nullptr) return true;
        else return false;
    }
};

class Biblioteka {
    std::map<int,Korisnik*> korisnici;
    std::map<int,Knjiga*> knjige;
    public:
    ~Biblioteka() {
        for(auto it=korisnici.begin(); it!=korisnici.end(); it++) delete it->second;
        for(auto i=knjige.begin(); i!=knjige.end(); i++) delete i->second;
    }
    void RegistrirajNovogKorisnika(int clanski_broj, std::string ime, std::string prezime, std::string adresa, std::string tlf) {
        for(auto it=korisnici.begin(); it!=korisnici.end(); it++) {
            if(it->first==clanski_broj) throw std::logic_error("Korisnik vec postoji!");
        }
        auto pok(new Korisnik);
        pok->ime=ime;
        pok->prezime=prezime;
        pok->adresa=adresa;
        pok->telefon=tlf;
        korisnici.insert(std::make_pair(clanski_broj,pok));
    }
    void RegistrirajNovuKnjigu(int broj_knjige, std::string naslov, std::string ime_pisca, std::string zanr, int godina) {
        for(auto i=knjige.begin(); i!=knjige.end(); i++) {
            if(i->first==broj_knjige) throw std::logic_error("Knjiga vec postoji!");
        }
        auto p(new Knjiga);
        p->naslov=naslov;
        p->ime_pisca=ime_pisca;
        p->zanr=zanr;
        p->godina_izdavanja=godina;
        knjige.insert(std::make_pair(broj_knjige,p));
    }
    Korisnik &NadjiKorisnika(int broj) {
        int br(0);
        for(auto t=korisnici.begin(); t!=korisnici.end(); t++) {
            if(t->first==broj) {
                br++;
                return *(t->second);
            }
        }
        if(br==0) throw std::logic_error("Korisnik nije nadjen!");
    }
    Knjiga &NadjiKnjigu(int broj) {
        int br(0);
        for(auto it=knjige.begin(); it!=knjige.end(); it++) {
            if(it->first==broj) {
                br++;
                return *(it->second);
            }
        }
        if(br==0) throw std::logic_error("Knjiga nije nadjena!");
    }
    void IzlistajKorisnike() const {
        for(auto it=korisnici.begin(); it!=korisnici.end(); it++) {
            std::cout<<"Clanski broj: "it->first<<std::endl;
            std::cout<<"Ime i prezime: "it->second->ime<<" "<<it->second->prezime<<std::endl;
            std::cout<<"Adresa: "it->second->adresa<<std::endl;
            std::cout<<"Broj telefon: "<<it->second->telefon<<std::endl;
        }
    }
    void IzlistajKnjige() const {
        
    }
    Biblioteka (const Biblioteka &b) {
        for(auto it=b.korisnici.begin(); it!=b.korisnici.end(); it++) {
            auto pok(new Korisnik);
            pok->ime=it->second->ime;
            pok->prezime=it->second->prezime;
            pok->adresa=it->second->adresa;
            pok->telefon=it->second->telefon;
            korisnici.insert(std:.make_pair(it->first,pok));
        }
        for(auto i=b.knjige.begin(); i!=b.knjige.end(); i++) {
            knjige.insert(i->first, new Knjiga(i->second->DajNaslov(),i->second->DajAutora(),i->second->DajZanr(),i->second->DajGodinuIzdavanja()));
        }
    }
    Biblioteka &operator =(const Biblioteka &b) {
        for(auto it=b.korisnici.begin(); it!=b.korisnici.end(); it++) {
            auto pok(new Korisnik);
            pok->ime=it->second->ime;
            pok->prezime=it->second->prezime;
            pok->adresa=it->second->adresa;
            pok->telefon=it->second->telefon;
            korisnici.insert(std:.make_pair(it->first,pok));
        }
        for(auto i=b.knjige.begin(); i!=b.knjige.end(); i++) {
            knjige.insert(i->first, new Knjiga(i->second->DajNaslov(),i->second->DajAutora(),i->second->DajZanr(),i->second->DajGodinuIzdavanja()));
        }
        return *this;
    }
    
    
    
    
        
        
        
        
    }

    
    
    
    
    
}