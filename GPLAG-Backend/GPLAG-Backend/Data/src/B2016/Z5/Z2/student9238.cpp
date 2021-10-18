#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include <algorithm>
#include <memory>

struct Korisnik {
    std::string ime, prezime, adresa, telefon;
};

class Knjiga {
    std::string naslov_knjige, ime_pisca, zanr;
    int godina_izdavanja;
    Korisnik* kod_koga_je;
public:
    Knjiga(std::string naslov_knjige, std::string ime_pisca, std::string zanr, int godina_izdavanja);
    std::string DajNaslov() const { return naslov_knjige; }
    std::string DajAutora() const { return ime_pisca; }
    std::string DajZanr() const { return zanr; }
    int DajGodinuIzdavanja() const { return godina_izdavanja; }
    Korisnik* DajKodKogaJe() const { return kod_koga_je; }
    void ZaduziKnjigu(Korisnik &k) { kod_koga_je = &k; }
    void RazduziKnjigu() { kod_koga_je = nullptr; }
    bool DaLiJeZaduzena();
};

inline Knjiga::Knjiga(std::string naslov_knjige, std::string ime_pisca, std::string zanr, int godina_izdavanja) : naslov_knjige(naslov_knjige), ime_pisca(ime_pisca), zanr(zanr), godina_izdavanja(godina_izdavanja), kod_koga_je(nullptr) {}

inline bool Knjiga::DaLiJeZaduzena() {
    if(kod_koga_je == nullptr) return false;
    return true;
}

class Biblioteka {
    std::map<int, std::shared_ptr<Korisnik>> mapa_korisnika;
    std::map<int, std::shared_ptr<Knjiga>> mapa_knjiga;
    void PostojiSaClanskim(int clanski_broj) {
        for(auto it = mapa_korisnika.begin(); it != mapa_korisnika.end(); it++) {
            if(it->first == clanski_broj) throw std::logic_error("Izuzetak");
        }
    }
    void PostojiSaEvid(int evidencijski_broj) {
        for(auto it = mapa_knjiga.begin(); it != mapa_knjiga.end(); it++) {
            if(it->first == evidencijski_broj) throw std::logic_error("Izuzetak");
        }
    }
public:
    Biblioteka() = default;
    Biblioteka(const Biblioteka &b);
    Biblioteka(Biblioteka &&b);
    Biblioteka &operator = (const Biblioteka &b);
    Biblioteka &operator = (Biblioteka &&b);
    void RegistrirajNovogKorisnika(int clanski_broj, std::string ime, std::string prezime, std::string adresa, std::string telefon);
    void RegistrirajNovuKnjigu(int evidencijski_broj, std::string naslov, std::string ime_pisca, std::string zanr, int godina_izdavanja);
    Korisnik &NadjiKorisnika(int clanski_broj);
    Knjiga &NadjiKnjigu(int evidencijski_broj);
    void IzlistajKorisnike() const;
    void IzlistajKnjige() const;
    void ZaduziKnjigu(int evidencijski_broj, int clanski_broj);
    void RazduziKnjigu(int evidencijski_broj);
    void PrikaziZaduzenja(int clanski_broj) const;
};

Biblioteka::Biblioteka(const Biblioteka &b) : mapa_korisnika(b.mapa_korisnika), mapa_knjiga(b.mapa_knjiga) {
    for(auto it = mapa_korisnika.begin(); it != mapa_korisnika.end(); it++) {
        std::shared_ptr<Korisnik> novi(std::make_shared<Korisnik>());
        *novi = *(it->second);
        it->second = novi;
    }
    for(auto it = mapa_knjiga.begin(); it != mapa_knjiga.end(); it++) {
        it->second = std::make_shared<Knjiga>(*(it->second));
    }
}

Biblioteka::Biblioteka(Biblioteka &&b) : mapa_korisnika(std::move(b.mapa_korisnika)), mapa_knjiga(std::move(b.mapa_knjiga)) {}

Biblioteka &Biblioteka::operator = (const Biblioteka &b) {
    mapa_korisnika = b.mapa_korisnika; mapa_knjiga = b.mapa_knjiga;
    
    for(auto it = mapa_korisnika.begin(); it != mapa_korisnika.end(); it++) {
        std::shared_ptr<Korisnik> novi(std::make_shared<Korisnik>());
        *novi = *(it->second);
        it->second = novi;
    }
    for(auto it = mapa_knjiga.begin(); it != mapa_knjiga.end(); it++) {
        it->second = std::make_shared<Knjiga>(*(it->second));
    }
    return *this;
} 

Biblioteka &Biblioteka::operator = (Biblioteka &&b) {
    mapa_korisnika = std::move(b.mapa_korisnika);
    mapa_knjiga = std::move(b.mapa_knjiga);
    return *this;
}

void Biblioteka::RegistrirajNovogKorisnika(int clanski_broj, std::string ime, std::string prezime, std::string adresa, std::string telefon) {
    std::shared_ptr<Korisnik> pok(std::make_shared<Korisnik>());
    Korisnik k1{ime, prezime, adresa, telefon};
    *pok = k1;
    try {
        PostojiSaClanskim(clanski_broj);
        mapa_korisnika[clanski_broj] = pok;
    }
    catch(...) { throw std::logic_error("Korisnik vec postoji"); }
}

void Biblioteka::RegistrirajNovuKnjigu(int evidencijski_broj, std::string naslov, std::string ime_pisca, std::string zanr, int godina_izdavanja) {
    std::shared_ptr<Knjiga> pok(std::make_shared<Knjiga>(naslov, ime_pisca, zanr, godina_izdavanja));
    try {
        PostojiSaEvid(evidencijski_broj);
        mapa_knjiga[evidencijski_broj] = pok;
    }
    catch(...) { throw std::logic_error("Knjiga vec postoji"); }
}

Korisnik &Biblioteka::NadjiKorisnika(int clanski_broj) {
    for(auto it = mapa_korisnika.begin(); it != mapa_korisnika.end(); it++)
        if(it->first == clanski_broj) return *(it->second);
    throw std::logic_error("Korisnik nije nadjen");
}

Knjiga &Biblioteka::NadjiKnjigu(int evidencijski_broj) {
    for(auto it = mapa_knjiga.begin(); it != mapa_knjiga.end(); it++) {
        if(it->first == evidencijski_broj) return *(it->second);
    }
    throw std::logic_error("Knjiga nije nadjena");
}

void Biblioteka::IzlistajKorisnike() const {
    for(auto it = mapa_korisnika.begin(); it != mapa_korisnika.end(); it++) {
        std::cout << "Clanski broj: " << it->first << std::endl;
        std::cout << "Ime i prezime: " << it->second->ime << " " << it->second->prezime << std::endl;
        std::cout << "Adresa: " << it->second->adresa << std::endl;
        std::cout << "Broj telefona: " << it->second->telefon << std::endl;
        std::cout << std::endl;
    }
}

void Biblioteka::IzlistajKnjige() const {
    for(auto it = mapa_knjiga.begin(); it != mapa_knjiga.end(); it++) {
        std::cout << "Evidencijski broj: " << it->first << std::endl;
        std::cout << "Naslov: " << it->second->DajNaslov() << std::endl;
        std::cout << "Pisac: " << it->second->DajAutora() << std::endl;
        std::cout << "Zanr: " << it->second->DajZanr() << std::endl;
        std::cout << "Godina izdavanja: " << it->second->DajGodinuIzdavanja() << std::endl;
        if(it->second->DaLiJeZaduzena()) std::cout << "Zaduzena kod korisnika: " << it->second->DajKodKogaJe()->ime << " " << it->second->DajKodKogaJe()->prezime << std::endl;
        std::cout << std::endl;
    }
}

void Biblioteka::ZaduziKnjigu(int evidencijski_broj, int clanski_broj) {
    auto it_knjiga(mapa_knjiga.find(evidencijski_broj));
    if(it_knjiga == mapa_knjiga.end()) throw std::logic_error("Knjiga nije nadjena");
    auto it_korisnik(mapa_korisnika.find(clanski_broj));
    if(it_korisnik == mapa_korisnika.end()) throw std::logic_error("Korisnik nije nadjen");
    if(it_knjiga->second->DaLiJeZaduzena()) throw std::logic_error("Knjiga vec zaduzena");
    it_knjiga->second->ZaduziKnjigu(*(it_korisnik->second));
}

void Biblioteka::RazduziKnjigu(int evidencijski_broj) {
    auto it_knjiga(mapa_knjiga.find(evidencijski_broj));
    if(it_knjiga == mapa_knjiga.end()) throw std::logic_error("Knjiga nije nadjena");
    if(!it_knjiga->second->DaLiJeZaduzena()) throw std::logic_error("Knjiga nije zaduzena");
    it_knjiga->second->RazduziKnjigu();
}

void Biblioteka::PrikaziZaduzenja(int clanski_broj) const {
    auto it_korisnik(mapa_korisnika.find(clanski_broj));
    if(it_korisnik == mapa_korisnika.end()) throw std::logic_error("Korisnik nije nadjen");
    bool ima_zaduzenja(false);
    for(auto it = mapa_knjiga.begin(); it != mapa_knjiga.end(); it++) {
        if(it->second->DajKodKogaJe() == it_korisnik->second.get()) {
            std::cout << "Evidencijski broj: " << it->first << std::endl;
            std::cout << "Naslov: " << it->second->DajNaslov() << std::endl;
            std::cout << "Pisac: " << it->second->DajAutora() << std::endl;
            std::cout << "Zanr: " << it->second->DajZanr() << std::endl;
            std::cout << "Godina izdavanja: " << it->second->DajGodinuIzdavanja() << std::endl;
            std::cout << std::endl;
            ima_zaduzenja = true;
        }
    }
    if(!ima_zaduzenja) std::cout << "Nema zaduzenja za tog korisnika!" << std::endl;
}

int main() {
    
    
    
    return 0;
}
