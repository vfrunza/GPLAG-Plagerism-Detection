/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include <algorithm>

struct Korisnik{
    std::string ime, prezime, adresa, telefon;
};

class Knjiga {
    std::string naslov_knjige, ime_pisca, zanr;
    int godina_izdanja;
    Korisnik *pok;
    public:
    Knjiga(std::string naslov_knjige, std::string ime_pisca, std::string zanr, int godina_izdanja) :
    naslov_knjige(naslov_knjige), ime_pisca(ime_pisca), zanr(zanr), godina_izdanja(godina_izdanja) {
        pok = nullptr;
    }
    std::string DajNaslov() const { return naslov_knjige;}
    std::string DajAutora() const {return ime_pisca;}
    std::string DajZanr() const {return zanr;}
    int DajGodinuIzdavanja() const {return godina_izdanja;}
    Korisnik *DajKodKogaJe() const{
        return pok;
    }
    void ZaduziKnjigu(Korisnik &k) {
        pok = &k;
    }
    void RazduziKnjigu() {
        pok = nullptr;
    }
    bool DaLiJeZaduzena() {
        if(pok == nullptr) return false;
        else {
            return true;
        }
    }
};

class Biblioteka {
    std::map<int , Korisnik *> mapa_korisnik;
    std::map<int , Knjiga *> mapa_knjiga;
    public:
    Biblioteka() {}
    ~Biblioteka() {
        for(auto i = mapa_korisnik.begin(); i != mapa_korisnik.end(); i++) {
            delete i->second;
            i->second = nullptr;
        }
        for(auto i = mapa_knjiga.begin(); i != mapa_knjiga.end(); i++) {
            delete i->second;
            i->second = nullptr;
        }
    }
    Biblioteka(const Biblioteka &b);
    Biblioteka(Biblioteka &&b);
    Biblioteka &operator =(const Biblioteka &b);
    Biblioteka &operator =(Biblioteka &&b);
    void RegistrirajNovogKorisnika(int clanski_broj, std::string ime, std::string prezime, std::string adresa, std::string broj_mobitela);
    void RegistrirajNovuKnjigu(int broj_knjige, std::string naslov, std::string ime_pisca, std::string zanr, int godina);
    Korisnik &NadjiKorisnika(int clanski_broj);
    Knjiga &NadjiKnjigu(int broj_knjige);
    void IzlistajKorisnike() const;
    void IzlistajKnjige() const;
    void ZaduziKnjigu(int broj_knjige, int clanski_broj);
    void RazduziKnjigu(int broj_knjige);
    void PrikaziZaduzenja(int clanski_broj);
};

Biblioteka::Biblioteka(const Biblioteka &b) {
    try{
        for(auto it = b.mapa_korisnik.begin(); it != b.mapa_korisnik.end(); it++) {
            mapa_korisnik.insert(std::make_pair(it->first, new Korisnik(*it->second)));
        }
        try{
            for(auto it = b.mapa_knjiga.begin(); it != b.mapa_knjiga.end(); it++) {
                mapa_knjiga.insert(std::make_pair(it->first, new Knjiga(*it->second)));
            }
        }
        catch(std::bad_alloc) {
            for(auto it = mapa_knjiga.begin(); it != mapa_knjiga.end(); it++) {
                delete it->second;
                it->second = nullptr;
            }
        }
    }
    catch(std::bad_alloc) {
        for(auto it = mapa_korisnik.begin(); it != mapa_korisnik.end(); it++) {
           delete it->second;
           it->second = nullptr;
        }
    }
}

Biblioteka::Biblioteka(Biblioteka &&b){
    mapa_knjiga = std::move(b.mapa_knjiga);
    mapa_korisnik = std::move(b.mapa_korisnik);
}

Biblioteka &Biblioteka::operator =(const Biblioteka &b){
    if(&b != this) {
        for(auto i = mapa_korisnik.begin(); i != mapa_korisnik.end(); i++) {
            delete i->second;
            i->second = nullptr;
        }
        for(auto i = mapa_knjiga.begin(); i != mapa_knjiga.end(); i++) {
            delete i->second;
            i->second = nullptr;
        }
        try{
        for(auto it = b.mapa_korisnik.begin(); it != b.mapa_korisnik.end(); it++) {
            mapa_korisnik.insert(std::make_pair(it->first, new Korisnik(*it->second)));
        }
        try{
            for(auto it = b.mapa_knjiga.begin(); it != b.mapa_knjiga.end(); it++) {
                mapa_knjiga.insert(std::make_pair(it->first, new Knjiga(*it->second)));
            }
        }
        catch(std::bad_alloc) {
            for(auto it = mapa_knjiga.begin(); it != mapa_knjiga.end(); it++) {
                delete it->second;
                it->second = nullptr;
            }
        }
    }
    catch(std::bad_alloc) {
        for(auto it = mapa_korisnik.begin(); it != mapa_korisnik.end(); it++) {
           delete it->second;
           it->second = nullptr;
        }
    }
    }
}

Biblioteka &Biblioteka::operator =(Biblioteka &&b) {
    if(&b != this) {
        for(auto i = mapa_korisnik.begin(); i != mapa_korisnik.end(); i++) {
            delete i->second;
            i->second = nullptr;
        }
        for(auto i = mapa_knjiga.begin(); i != mapa_knjiga.end(); i++) {
            delete i->second;
            i->second = nullptr;
        }
        mapa_knjiga = std::move(b.mapa_knjiga);
        mapa_korisnik = std::move(b.mapa_korisnik);
    }
    return *this;
}

void Biblioteka::RegistrirajNovogKorisnika(int clanski_broj, std::string ime, std::string prezime, std::string adresa, std::string broj_mobitela) {
    bool ok(false);
    for(auto it = mapa_korisnik.begin(); it != mapa_korisnik.end(); it++) {
        if(it->first == clanski_broj) {
            ok = true;
            break;
        }
    }
    if(ok == true) throw std::logic_error("Korisnik vec postoji");
   /* Korisnik k;
    k.ime = ime;
    k.prezime = prezime;
    k.adresa = adresa;
    k.telefon = broj_mobitela;*/
    mapa_korisnik.insert(std::make_pair(clanski_broj, new Korisnik{ime, prezime, adresa, broj_mobitela}));
}

void Biblioteka::RegistrirajNovuKnjigu(int broj_knjige, std::string naslov, std::string ime_pisca, std::string zanr, int godina){
    bool ok(false);
    for(auto it = mapa_knjiga.begin(); it != mapa_knjiga.end(); it++) {
        if(it->first == broj_knjige) {
            ok = true;
            break;
        }
    }
    if(ok == true) throw  std::logic_error("Knjiga vec postoji");
    //Knjiga k(naslov, ime_pisca, zanr, godina);
    mapa_knjiga.insert(std::make_pair(broj_knjige, new Knjiga(naslov, ime_pisca, zanr, godina)));
}

Korisnik &Biblioteka::NadjiKorisnika(int clanski_broj) {
    bool ok(false);
    for(auto it=mapa_korisnik.begin(); it != mapa_korisnik.end(); it++) {
        if(it-> first == clanski_broj) {
            ok = true;
            //std::cout << "aaa";
            return *(it->second);
        }
    }
    if(ok == false) throw std::logic_error("Korisnik nije nadjen");
}

Knjiga &Biblioteka::NadjiKnjigu(int broj_knjige){
    bool ok(false);
    for(auto it=mapa_knjiga.begin(); it != mapa_knjiga.end(); it++) {
        if(it-> first == broj_knjige) {
            ok = true;
            return *it->second;
        }
    }
    if(ok == false) throw std::logic_error("Knjiga nije nadjen");
}

void Biblioteka::IzlistajKorisnike() const {
    for(auto it = mapa_korisnik.begin(); it != mapa_korisnik.end(); it++) {
        std::cout << "Clanski broj: " << it->first << std::endl;
        std::cout << "Ime i prezime: " << it->second->ime << " " <<it->second->prezime << std::endl;
        std::cout << "Adresa: " << it->second->adresa << std::endl;
        std::cout << "Broj telefona: " << it->second->telefon << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
}

void Biblioteka::IzlistajKnjige() const{
    for(auto it = mapa_knjiga.begin(); it != mapa_knjiga.end(); it++) {
        std::cout << "Evidencijski broj: " << it->first << std::endl;
        std::cout << "Naslov: " << it->second->DajNaslov() << std::endl;
        std::cout << "Pisac: " << it->second->DajAutora() << std::endl;
        std::cout << "Zanr: " << it->second->DajZanr() << std::endl;
        std::cout << "Godina izdavanja: " << it->second->DajGodinuIzdavanja() << std::endl;
        if(it->second->DaLiJeZaduzena() == true || it->second->DaLiJeZaduzena() == 1) 
        std::cout << "Zaduzena kod korisnika: " << it->second->DajKodKogaJe()->ime << " " << it->second->DajKodKogaJe()->prezime << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
}

void Biblioteka::ZaduziKnjigu(int broj_knjige, int clanski_broj) {
    bool knjiga(false),clan(false),zaduzena(false);
    for(auto it=mapa_knjiga.begin(); it != mapa_knjiga.end(); it++) {
        if(it->first == broj_knjige) {
            knjiga = true;
        }
        /*if(it->second->DaLiJeZaduzena() == 1) {
            std::cout << "aaa" << std::endl;
            zaduzena = true;
        }*/
    }
    if(knjiga == false || broj_knjige < 0) throw std::logic_error("Knjiga nije nadjena");
    for(auto it=mapa_korisnik.begin(); it != mapa_korisnik.end(); it++) {
        if(it->first == clanski_broj) {
            clan = true;
            break;
        }
    }
    if(clan == false || clanski_broj < 0) throw std::logic_error("Korisnik nije nadjena");
    if(zaduzena == true) throw std::logic_error("knjiga vec zaduzena");
    mapa_knjiga[broj_knjige]->ZaduziKnjigu(NadjiKorisnika(clanski_broj));
}

void Biblioteka::RazduziKnjigu(int broj_knjige){
    try{
        NadjiKnjigu(broj_knjige);
    }
    catch(std::logic_error) {
        throw std::logic_error("Knjiga nije nadjena");
    }
    if(mapa_knjiga[broj_knjige] == nullptr) throw std::logic_error("Knjiga nije zaduzena");
    mapa_knjiga[broj_knjige] = nullptr;
}

void Biblioteka::PrikaziZaduzenja(int clanski_broj){
    try{
        NadjiKorisnika(clanski_broj);
    }
    catch (std::logic_error) {
        throw std::logic_error("Korisnik nije nadjen");
    }
    int br{};
    for(auto it=mapa_korisnik.begin(); it != mapa_korisnik.end(); it++) {
        if(it->first  == clanski_broj) {
            for(auto j=mapa_knjiga.begin(); j != mapa_knjiga.end(); j++) {
                if(it->second == j->second->DajKodKogaJe()) {
                    std::cout << "Evidencijski broj: " << j->first << std::endl;
                    std::cout << "Naslov: " << j->second->DajNaslov() << std::endl;
                    std::cout << "Pisac: " << j->second->DajAutora() << std::endl;
                    std::cout << "Zanr: " << j->second->DajZanr() << std::endl;
                    std::cout << "Godina izdavanja: " << j->second->DajGodinuIzdavanja() << std::endl;
                    std::cout << std::endl;
                    br++;
                }
            }
        }
    }
    if(br == 0)  std::cout << "Nema zaduzenja za tog korisnika!" << std::endl;
}

int main ()
{

	return 0;
}