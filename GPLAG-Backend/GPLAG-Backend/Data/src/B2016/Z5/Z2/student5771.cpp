/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include<string>
#include<map>
#include<new>
#include<stdexcept>
#include<utility>
#include<memory>

struct Korisnik {
    std::string ime, prezime, adresa, telefon;
};

class Knjiga {
    std::string naslov, ime_pisca, zanr;
    int godina_izdavanja;
    Korisnik *zaduzenje;
public:
    Knjiga(std::string x, std::string y, std::string z, int g) : naslov(x), ime_pisca(y), zanr(z), godina_izdavanja(g), zaduzenje(nullptr) {};
    std::string DajNaslov() const { return naslov; }
    std::string DajAutora() const { return ime_pisca; }
    std::string DajZanr() const { return zanr; }
    int DajGodinuIzdavanja() const { return godina_izdavanja; }
    Korisnik* DajKodKogaJe() const { return zaduzenje; }
    void ZaduziKnjigu(Korisnik &x) { if(zaduzenje == nullptr) zaduzenje = &x; }
    void RazduziKnjigu() { zaduzenje = nullptr; }
    bool DaLiJeZaduzena() {
        if(zaduzenje == nullptr) return false;
        else return true;
    }
};

class Biblioteka {
    std::map<int, std::shared_ptr<Korisnik>> mapa_korisnika;
    std::map<int, std::shared_ptr<Knjiga>> mapa_knjiga;
public:
    Biblioteka() = default;

    
    Biblioteka(const Biblioteka &b); 
    
    Biblioteka &operator =(const Biblioteka &b);
    
    Biblioteka(Biblioteka &&pom);
    
    Biblioteka &operator =(Biblioteka &&pom);
    
    void RegistrirajNovogKorisnika(int clanski_broj_k, std::string ime_k, std::string prezime_k, std::string adresa_k, std::string telefon_k);
    
    void RegistrirajNovuKnjigu(int evidencijski_broj_k, std::string naslov_k, std::string ime_pisca_k, std::string zanr_k, int godina_izdavanja_k);
    
    Korisnik &NadjiKorisnika(int clanski_broj_k);
    
    Knjiga &NadjiKnjigu(int evidencijski_broj_k);
    
    void IzlistajKorisnike() const;
    
    void IzlistajKnjige() const;
    
    void ZaduziKnjigu(int evidencijski_broj_k, int clanski_broj_k);
    
    void RazduziKnjigu(int evidencijski_broj_k);
    
    void PrikaziZaduzenja(int clanski_broj_k);
    
    void IzlistajKnjige(int clanski_broj_k);
};



Biblioteka::Biblioteka(const Biblioteka &b) {
    for(auto x : b.mapa_korisnika)
        RegistrirajNovogKorisnika(x.first, x.second->ime, x.second->prezime, x.second->adresa, x.second->telefon);
    for(auto x : b.mapa_knjiga)
        RegistrirajNovuKnjigu(x.first, x.second->DajNaslov(), x.second->DajAutora(), x.second->DajZanr(), x.second->DajGodinuIzdavanja());
}

Biblioteka &Biblioteka::operator =(const Biblioteka &b) {
    if(this==&b) return *this;
    Biblioteka pom(b);
    for(auto x : pom.mapa_korisnika)
        mapa_korisnika.insert(std::pair<int,std::shared_ptr<Korisnik>>(x.first, x.second));
    for(auto x : pom.mapa_knjiga)
        mapa_knjiga.insert(std::pair<int,std::shared_ptr<Knjiga>>(x.first, x.second));
    for(auto x : pom.mapa_korisnika) x.second = nullptr;
    for(auto x : pom.mapa_knjiga) x.second = nullptr;
    return *this;
}

Biblioteka::Biblioteka(Biblioteka &&pom) {
    for(auto x : pom.mapa_korisnika)
        mapa_korisnika.insert(std::pair<int,std::shared_ptr<Korisnik>>(x.first, x.second));
    for(auto x : mapa_knjiga)
        mapa_knjiga.insert(std::pair<int,std::shared_ptr<Knjiga>>(x.first, x.second));
    for(auto x : pom.mapa_korisnika) x.second = nullptr;
    for(auto x : pom.mapa_knjiga) x.second = nullptr;
}

Biblioteka &Biblioteka::operator =(Biblioteka &&pom) {
    if(this==&pom) return *this;
    for(auto x : pom.mapa_korisnika)
        mapa_korisnika.insert(std::pair<int,std::shared_ptr<Korisnik>>(x.first, x.second));
    for(auto x : mapa_knjiga)
        mapa_knjiga.insert(std::pair<int,std::shared_ptr<Knjiga>>(x.first, x.second));
    for(auto x : pom.mapa_korisnika) x.second = nullptr;
    for(auto x : pom.mapa_knjiga) x.second = nullptr;
    return *this;
}

void Biblioteka::RegistrirajNovogKorisnika(int clanski_broj_k, std::string ime_k, std::string prezime_k, std::string adresa_k, std::string telefon_k) {
    auto it(mapa_korisnika.find(clanski_broj_k));
    if(it!=mapa_korisnika.end()) throw std::logic_error("Korisnik vec postoji");
    Korisnik pom = Korisnik{ime_k,prezime_k,adresa_k,telefon_k};
    auto p(std::make_shared<Korisnik>(pom));
    mapa_korisnika.insert(std::pair<int,std::shared_ptr<Korisnik>>(clanski_broj_k, p));
}

void Biblioteka::RegistrirajNovuKnjigu(int evidencijski_broj_k, std::string naslov_k, std::string ime_pisca_k, std::string zanr_k, int godina_izdavanja_k) {
    auto it(mapa_knjiga.find(evidencijski_broj_k));
    if(it!=mapa_knjiga.end()) throw std::logic_error("Knjiga vec postoji");
    auto pom = std::make_shared<Knjiga>(naslov_k, ime_pisca_k, zanr_k, godina_izdavanja_k);
    mapa_knjiga.insert(std::pair<int,std::shared_ptr<Knjiga>>(evidencijski_broj_k,pom));
}

Korisnik &Biblioteka::NadjiKorisnika(int clanski_broj_k) {
    auto it(mapa_korisnika.find(clanski_broj_k));
    if(it == mapa_korisnika.end()) throw std::logic_error("Korisnik nije nadjen");
    else return *(it->second);
}

Knjiga &Biblioteka::NadjiKnjigu(int evidencijski_broj_k) {
    auto it(mapa_knjiga.find(evidencijski_broj_k));
    if(it == mapa_knjiga.end()) throw std::logic_error("Knjiga nije nadjena");
    else return *(it->second);
}


void Biblioteka::IzlistajKorisnike() const {
    for(auto x : mapa_korisnika) {
        std::cout << "Clanski broj: " << x.first << std::endl;
        std::cout << "Ime i prezime: " << x.second->ime << " " << x.second->prezime << std::endl;
        std::cout << "Adresa: " << x.second->adresa << std::endl;
        std::cout << "Broj telefona: " << x.second->telefon << std::endl;
        std::cout << std::endl;
    }
}

void Biblioteka::IzlistajKnjige() const {
    for(auto x : mapa_knjiga) {
        std::cout << "Evidencijski broj: " << x.first << std::endl;
        std::cout << "Naslov: " << x.second->DajNaslov() << std::endl;
        std::cout << "Pisac: " << x.second->DajAutora() << std::endl;
        std::cout << "Zanr: " << x.second->DajZanr() << std::endl;
        std::cout << "Godina izdavanja: " << x.second->DajGodinuIzdavanja() << std::endl;
        if(x.second->DaLiJeZaduzena())
            std::cout << "Zaduzena kod korisnika: " << (x.second->DajKodKogaJe())->ime << " " << (x.second->DajKodKogaJe())->prezime << std::endl;
        std::cout << std::endl;
    }
}

void Biblioteka::ZaduziKnjigu(int evidencijski_broj_k, int clanski_broj_k) {
    try{
        auto x(NadjiKnjigu(evidencijski_broj_k));
        auto y(NadjiKorisnika(clanski_broj_k));
    } catch(std::logic_error) {
        throw;
    }
    if(NadjiKnjigu(evidencijski_broj_k).DaLiJeZaduzena()) throw std::logic_error("Knjiga vec zaduzena");
    NadjiKnjigu(evidencijski_broj_k).ZaduziKnjigu(NadjiKorisnika(clanski_broj_k));
}

void Biblioteka::RazduziKnjigu(int evidencijski_broj_k) {
    try{
        auto x(NadjiKnjigu(evidencijski_broj_k));
    } catch(std::logic_error) {
        throw;
    }
    if(!NadjiKnjigu(evidencijski_broj_k).DaLiJeZaduzena()) throw std::logic_error("Knjiga nije zaduzena");
    NadjiKnjigu(evidencijski_broj_k).RazduziKnjigu();
}

void Biblioteka::PrikaziZaduzenja(int clanski_broj_k) {
        auto it(mapa_korisnika.find(clanski_broj_k));
        if(it == mapa_korisnika.end()) throw std::logic_error("Korisnik nije nadjen");
       std::shared_ptr<Korisnik> m = mapa_korisnika[clanski_broj_k];
        int br_zaduzenih(0);
        for(auto x : mapa_knjiga) {
            if((m.get()) == (x.second->DajKodKogaJe())) {
                br_zaduzenih++;
            }
        }
        if(br_zaduzenih==0) std::cout << "Nema zaduzenja za tog korisnika!" << std::endl;
        for(auto x : mapa_knjiga) {
            if((m.get()) == (x.second->DajKodKogaJe())) {
                std::cout << "Korisnik " << m->ime << " " << m->prezime << " je zaduzio: " << x.second->DajNaslov() << std::endl;
            }
        }
    
}


void Biblioteka::IzlistajKnjige(int clanski_broj_k) {
        auto it(mapa_korisnika.find(clanski_broj_k));
        if(it == mapa_korisnika.end()) throw std::logic_error("Korisnik nije nadjen");
         std::shared_ptr<Korisnik> m = mapa_korisnika[clanski_broj_k];
        int br_zaduzenih(0);
        for(auto x : mapa_knjiga) {
            if((m.get()) == (x.second->DajKodKogaJe())) {
                br_zaduzenih++;
            }
        }
        if(br_zaduzenih==0) std::cout << "Nema zaduzenja za tog korisnika!" << std::endl;
        for(auto x : mapa_knjiga) {
            if((m.get()) == (x.second->DajKodKogaJe())) {
                std::cout << x.second->DajNaslov() << std::endl;
            }
        }
}

void IspisOpcija() {
    std::cout << "-----------------" << std::endl << "IZABERITE OPCIJU: " << std::endl << "-----------------" << std::endl;
    std::cout << "1: Registriraj novog korisnika" << std::endl;
    std::cout << "2: Registriraj novu knjigu" << std::endl;
    std::cout << "3: Izlistaj korisnike" << std::endl;
    std::cout << "4: Izlistaj knjige" << std::endl;
    std::cout << "5: Prikazi zaduzenja korisnika" << std::endl;
    std::cout << "6: Zaduzi knjigu" << std::endl;
    std::cout << "7: Razduzi knjigu" << std::endl;
    std::cout << "8: Kraj" << std::endl;
    std::cout << std::endl;
}


int main () {
    Biblioteka bib;
    for(;;) {
        IspisOpcija();
        int opcija;
        std::cout << "Unesite opciju: ";
        std::cin >> opcija;
        if(opcija == 8) break;
        if(!std::cin || (opcija!=1 && opcija!=2 && opcija!=3 && opcija!=4 && opcija!=5 && opcija!=6 && opcija!=7 && opcija!=8)) {
            std::cout << "Ne postoji takva opcija, ponovite unos!" << std::endl;
        }
        if(opcija == 1) {
            std::cout << "Unesite ime: ";
            std::string ime;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::getline(std::cin, ime);
            std::cout << "Unesite prezime: ";
            std::string prezime;
            std::getline(std::cin, prezime);
            std::cout << "Unesite adresu: ";
            std::string adresa;
            std::getline(std::cin, adresa);
            std::cout << "Unesite telefon: ";
            std::string telefon;
            std::getline(std::cin, telefon);
            std::cout << "Unesite clanski broj korisnika: ";
            int clanski_broj;
            std::cin >> clanski_broj;
            try{
                bib.RegistrirajNovogKorisnika(clanski_broj, ime, prezime, adresa, telefon);
            } catch(std::logic_error e) {
                std::cout << e.what();
            }
        }
        
        else if(opcija == 2) {
            std::cout << "Unesite naslov: ";
            std::string naslov;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::getline(std::cin, naslov);
            std::cout << "Unesite ime pisca: ";
            std::string ime_pisca;
            std::getline(std::cin, ime_pisca);
            std::cout << "Unesite zanr: ";
            std::string zanr;
            std::getline(std::cin, zanr);
            std::cout << "Unesite godinu izdavanja: ";
            int godina_izdavanja;
            std::cin >> godina_izdavanja;
            std::cout << "Unesite evidencijski broj knjige: ";
            int evidencijski_broj;
            std::cin >> evidencijski_broj;
            try{
                bib.RegistrirajNovuKnjigu(evidencijski_broj, naslov, ime_pisca, zanr, godina_izdavanja);
            } catch(std::logic_error e) {
                std::cout << e.what() << std::endl;
            }
        }
        
        else if(opcija == 3) {
            std::cout << "Trenutno registrovani korisnici u biblioteci: " << std::endl;
            bib.IzlistajKorisnike();
        }
        
        else if(opcija == 4) {
            std::cout << "Trenutno registrovane knjige u biblioteci: " << std::endl;
            bib.IzlistajKnjige();
        }
        
        else if(opcija == 5) {
            std::cout << "Unesite clanski broj korisnika: ";
            int clanski_broj;
            std::cin >> clanski_broj;
            try{
                bib.PrikaziZaduzenja(clanski_broj);
            } catch(std::logic_error e) {
                std::cout << e.what() << std::endl;
            }
        }
        
        else if(opcija == 6) {
            std::cout << "Unesite evidencijski broj knjige: ";
            int evidencijski_broj;
            std::cin >> evidencijski_broj;
            std::cout << "Unesite clanski broj korisnika: ";
            int clanski_broj;
            std::cin >> clanski_broj;
            try{
                bib.ZaduziKnjigu(evidencijski_broj,clanski_broj);
            } catch(std::logic_error e) {
                std::cout << e.what() << std::endl;
            }
        }
        
        else if(opcija == 7) {
            std::cout << "Unesite evidencijski broj knjige: ";
            int evidencijski_broj;
            std::cin >> evidencijski_broj;
            try{
                bib.RazduziKnjigu(evidencijski_broj);
            } catch(std::logic_error e) {
                std::cout << e.what() << std::endl;
            }
        }
    }
	return 0;
}