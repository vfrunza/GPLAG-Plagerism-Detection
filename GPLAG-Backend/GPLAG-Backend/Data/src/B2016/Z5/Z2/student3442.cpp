#include <iostream>
#include <string>
#include <stdexcept>
#include <map>
#include <memory>

struct Korisnik {
    std::string ime, prezime, adresa, telefon;  
};

bool operator == (const Korisnik &k1, const Korisnik &k2) {
    return k1.ime == k2.ime && k1.prezime == k2.prezime && k1.adresa == k2.adresa && k1.telefon == k2.telefon;
}

class Knjiga {
    std::string naslov_knige, ime_pisca, zanr;
    int godina_izdavanja;
    Korisnik* zaduzenik = nullptr;
public: 
    Knjiga(std::string naslov_knige, std::string ime_pisca, std::string zanr, int godina_izdavanja) 
    : naslov_knige(naslov_knige), ime_pisca(ime_pisca), zanr(zanr), godina_izdavanja(godina_izdavanja) {}
    
    std::string DajNaslov() const {
        return naslov_knige;
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
    Korisnik* DajKodKogaJe() const {
        return zaduzenik;
    }
    void ZaduziKnjigu(Korisnik &korisnik) {
        zaduzenik = &korisnik;
    }
    void RazduziKnjigu() {
        zaduzenik = nullptr;
    }
    bool DaLiJeZaduzena() {
        if(zaduzenik == nullptr) return false;
        return true;
    }
};

class Biblioteka {
    std::map<int, std::shared_ptr<Korisnik>> mapa_korisnika;
    std::map<int, std::shared_ptr<Knjiga>> mapa_knjiga;
public: 
    void RegistrirajNovogKorisnika(int clanski_broj_korisnika, std::string ime, std::string prezime, std::string adresa, std::string telefon);
    void RegistrirajNovuKnjigu(int evidencijski_broj_knige, std::string naslov, std::string ime_pisca, std::string zanr, int godina_izdavanja);
    ~Biblioteka() { Dealociraj(); }
    Korisnik& NadjiKorisnika(int clanski_broj_korisnika);
    Knjiga& NadjiKnjigu(int evidencijski_broj_knige);
    void IzlistajKorisnike() const;
    void IzlistajKnjige() const;
    void ZaduziKnjigu(int evidencijski_broj_knjige, int clanski_broj_korisnika);
    void RazduziKnjigu(int evidencijski_broj_knjige);
    void PrikaziZaduzenja(int clanski_broj_korisnika);

    Biblioteka& operator = (const Biblioteka &b2);
    Biblioteka(const Biblioteka &b);
    Biblioteka& operator = (Biblioteka &&b2) = default;
    Biblioteka(Biblioteka &&b) = default;
    Biblioteka() = default;

    void Dealociraj();
};

void Biblioteka::RegistrirajNovogKorisnika(int clanski_broj_korisnika, std::string ime, std::string prezime, std::string adresa, std::string telefon) {
    for(auto iter = mapa_korisnika.begin(); iter != mapa_korisnika.end(); iter++) 
        if(iter->first == clanski_broj_korisnika) 
            throw std::logic_error("Korisnik vec postoji");
    auto novi_korisnik = std::make_shared<Korisnik>();
    novi_korisnik->ime = ime;
    novi_korisnik->prezime = prezime;
    novi_korisnik->adresa = adresa;
    novi_korisnik->telefon = telefon;
    mapa_korisnika.insert(std::make_pair(clanski_broj_korisnika, novi_korisnik));
}
void Biblioteka::RegistrirajNovuKnjigu(int evidencijski_broj_knjige, std::string naslov, std::string ime_pisca, std::string zanr, int godina_izdavanja) {
    for(auto iter = mapa_knjiga.begin(); iter != mapa_knjiga.end(); iter++) 
        if(iter->first == evidencijski_broj_knjige) 
            throw std::logic_error("Knjiga vec postoji");    
    auto nova_knjiga = std::make_shared<Knjiga>(naslov, ime_pisca, zanr, godina_izdavanja);
    mapa_knjiga.insert(std::make_pair(evidencijski_broj_knjige, nova_knjiga));
}
Korisnik& Biblioteka::NadjiKorisnika(int clanski_broj_korisnika) {
    for(auto iter = mapa_korisnika.begin(); iter != mapa_korisnika.end(); iter++) {
        if(iter->first == clanski_broj_korisnika)
            return *(iter->second);
    }
    throw std::logic_error("Korisnik nije nadjen");
}
Knjiga& Biblioteka::NadjiKnjigu(int evidencijski_broj_knjige) {
    for(auto iter = mapa_knjiga.begin(); iter != mapa_knjiga.end(); iter++) {
        if(iter->first == evidencijski_broj_knjige)
            return *(iter->second);
    }
    throw std::logic_error("Knjiga nije nadjena");    
}
void Biblioteka::IzlistajKorisnike() const {
    for(auto iter = mapa_korisnika.begin(); iter != mapa_korisnika.end(); iter++) {
        std::cout << "Clanski broj: " << iter->first << std::endl;
        std::cout << "Ime i prezime: " << iter->second->ime << " " << iter->second->prezime << std::endl;
        std::cout << "Adresa: " << iter->second->adresa << std::endl;
        std::cout << "Broj telefona: " << iter->second->telefon << std::endl << std::endl;
    }
}
void Biblioteka::IzlistajKnjige() const {
    for(auto iter = mapa_knjiga.begin(); iter != mapa_knjiga.end(); iter++) {
        std::cout << "Evidencijski broj: " << iter->first << std::endl;
        std::cout << "Naslov: " << iter->second->DajNaslov() << std::endl;
        std::cout << "Pisac: " << iter->second->DajAutora() << std::endl;
        std::cout << "Zanr: " << iter->second->DajZanr() << std::endl;
        std::cout << "Godina izdavanja: " << iter->second->DajGodinuIzdavanja() << std::endl;
        
        if(iter->second->DaLiJeZaduzena()) {
            std::cout << "Zaduzena kod korisnika: ";
            std::cout << iter->second->DajKodKogaJe()->ime << " " << iter->second->DajKodKogaJe()->prezime << std::endl;
        }
        std::cout << std::endl;
    }
}
void Biblioteka::ZaduziKnjigu(int evidencijski_broj_knjige, int clanski_broj_korisnika) {
    if(NadjiKnjigu(evidencijski_broj_knjige).DaLiJeZaduzena())
        throw std::logic_error("Knjiga vec zaduzena");
    NadjiKnjigu(evidencijski_broj_knjige).ZaduziKnjigu(NadjiKorisnika(clanski_broj_korisnika));
}
void Biblioteka::RazduziKnjigu(int evidencijski_broj_knjige) {
    if(!NadjiKnjigu(evidencijski_broj_knjige).DaLiJeZaduzena())
        throw std::logic_error("Knjiga nije zaduzena");
    NadjiKnjigu(evidencijski_broj_knjige).RazduziKnjigu();
}
void Biblioteka::PrikaziZaduzenja(int clanski_broj_korisnika) {
    auto korisnik = NadjiKorisnika(clanski_broj_korisnika);
    bool zaduzen = false;
    for(auto iter = mapa_knjiga.begin(); iter != mapa_knjiga.end(); iter++) {
        if(iter->second->DaLiJeZaduzena()) {
            if(*(iter->second->DajKodKogaJe()) == korisnik) {
                zaduzen = true;
                std::cout << "Evidencijski broj: " << iter->first << std::endl;
                std::cout << "Naslov: " << iter->second->DajNaslov() << std::endl;
                std::cout << "Pisac: " << iter->second->DajAutora() << std::endl;
                std::cout << "Zanr: " << iter->second->DajZanr() << std::endl;
                std::cout << "Godina izdavanja: " << iter->second->DajGodinuIzdavanja() << std::endl << std::endl;
            }
        }
    }
    if(!zaduzen) std::cout << "Nema zaduzenja za tog korisnika!";
}

Biblioteka& Biblioteka::operator = (const Biblioteka &b2) {
    Dealociraj();

    std::map<int, std::shared_ptr<Korisnik>> m_korisnika;
    std::map<int, std::shared_ptr<Knjiga>> m_knjiga;

    for(auto x = b2.mapa_korisnika.begin(); x != b2.mapa_korisnika.end(); x++) {
        auto novi_korisnik = std::make_shared<Korisnik>();
        novi_korisnik->ime = x->second->ime;
        novi_korisnik->prezime = x->second->prezime;
        novi_korisnik->adresa = x->second->adresa;
        novi_korisnik->telefon = x->second->telefon;        
        m_korisnika.insert(std::make_pair(x->first, novi_korisnik));
    }
    mapa_korisnika = m_korisnika;
    
    for(auto x = b2.mapa_knjiga.begin(); x != b2.mapa_knjiga.end(); x++) {
        auto nova_knjiga = std::make_shared<Knjiga>(x->second->DajNaslov(), x->second->DajAutora(), x->second->DajZanr(), x->second->DajGodinuIzdavanja());
        m_knjiga.insert(std::make_pair(x->first, nova_knjiga));
    }
    mapa_knjiga = m_knjiga;

    return *this;
}
Biblioteka::Biblioteka(const Biblioteka &b2) {
    std::map<int, std::shared_ptr<Korisnik>> m_korisnika;
    std::map<int, std::shared_ptr<Knjiga>> m_knjiga;

    for(auto x = b2.mapa_korisnika.begin(); x != b2.mapa_korisnika.end(); x++) {
        auto novi_korisnik = std::make_shared<Korisnik>();
        novi_korisnik->ime = x->second->ime;
        novi_korisnik->prezime = x->second->prezime;
        novi_korisnik->adresa = x->second->adresa;
        novi_korisnik->telefon = x->second->telefon;        
        m_korisnika.insert(std::make_pair(x->first, novi_korisnik));
    }
    mapa_korisnika = m_korisnika;
    
    for(auto x = b2.mapa_knjiga.begin(); x != b2.mapa_knjiga.end(); x++) {
        auto nova_knjiga = std::make_shared<Knjiga>(x->second->DajNaslov(), x->second->DajAutora(), x->second->DajZanr(), x->second->DajGodinuIzdavanja());
        m_knjiga.insert(std::make_pair(x->first, nova_knjiga));
    }
    mapa_knjiga = m_knjiga;
}

void Biblioteka::Dealociraj() {
    for(auto x : mapa_korisnika) 
        x.second = nullptr;
    for(auto x : mapa_knjiga)
        x.second = nullptr;
}
void OcistiTok() {
    std::cin.ignore(1000, '\n');
    std::cin.clear();
}

int main() {
    Biblioteka bi;
    while(true) {
        std::cout << "Odaberite opciju: " << std::endl;
        std::cout << "1 - Registracija novog korisnika " << std::endl;
        std::cout << "2 - Registracija nove knjige" << std::endl;
        std::cout << "3 - Lista registriranih korisnika" << std::endl;
        std::cout << "4 - Lista registriranih knjiga" << std::endl;
        std::cout << "5 - Zaduzivanje knjige" << std::endl;
        std::cout << "6 - Razduzivanje knjige" << std::endl;
        std::cout << "7 - Lista zaduzenih korisnika" << std::endl;
        std::cout << "8 - Izlaz" << std::endl;
        std::cout << "Opcija: "; int opcija; std::cin >> opcija;
        try {
            std::cout << std::endl; OcistiTok();
            if(opcija == 1) {
                std::cout << "Clanski broj: "; int clanski_broj_korisnika; std::cin >> clanski_broj_korisnika;
                OcistiTok();
                std::cout << "Ime: "; std::string ime; std::getline(std::cin, ime);
                std::cout << "Prezime: "; std::string prezime; std::getline(std::cin, prezime);
                std::cout << "Adresa: "; std::string adresa; std::getline(std::cin, adresa);
                std::cout << "Telefon: "; std::string telefon; std::getline(std::cin, telefon);
                bi.RegistrirajNovogKorisnika(clanski_broj_korisnika, ime, prezime, adresa, telefon);
            }
            else if(opcija == 2) {
                std::cout << "Evidencijski broj: "; int evidencijski_broj_knjige; std::cin >> evidencijski_broj_knjige;
                OcistiTok();
                std::cout << "Naslov: "; std::string naslov; std::getline(std::cin, naslov);
                std::cout << "Ime autora: "; std::string autor; std::getline(std::cin, autor);
                std::cout << "Zanr: "; std::string zanr; std::getline(std::cin, zanr);
                std::cout << "Godina izdavanja: "; int godina_izdavanja; std::cin >> godina_izdavanja;
                bi.RegistrirajNovuKnjigu(evidencijski_broj_knjige, naslov, autor, zanr, godina_izdavanja);
            }
            else if(opcija == 3) {
                bi.IzlistajKorisnike();
            }
            else if(opcija == 4) {
                bi.IzlistajKnjige();
            }
            else if(opcija == 5) {
                std::cout << "Evidencijski broj knjige: "; int evidencijski_broj_knjige; std::cin >> evidencijski_broj_knjige;
                std::cout << "Clanski broj korisnika: "; int clanski_broj_korisnika; std::cin >> clanski_broj_korisnika;
                bi.ZaduziKnjigu(evidencijski_broj_knjige, clanski_broj_korisnika);
            }
            else if(opcija == 6) {
                std::cout << "Clanski broj korisnika: "; int clanski_broj_korisnika; std::cin >> clanski_broj_korisnika;
                bi.RazduziKnjigu(clanski_broj_korisnika);
            }
            else if(opcija == 7) {
                std::cout << "Clanski broj korisnika: "; int clanski_broj_korisnika; std::cin >> clanski_broj_korisnika;
                bi.PrikaziZaduzenja(clanski_broj_korisnika);
            }
            else if(opcija == 8) {
                return 0;
            }
            else throw std::runtime_error("Nekoretan unos");
        }
        catch(std::domain_error e) {
            std::cout << e.what() << std::endl;
        }
        catch(std::logic_error e) {
            std::cout << e.what() << std::endl;
        }
        catch(std::bad_alloc) {
            std::cout << "Nedovoljno memorije" << std::endl;
        }
        catch(std::runtime_error e) {
            std::cout << e.what();
        }
        catch(...) {
            std::cout << "Nepoznata greska..." << std::endl;
        }
    }
	return 0;
}