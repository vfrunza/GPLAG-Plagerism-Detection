/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <map>

struct Korisnik {
    std::string ime, prezime, adresa, telefon;
};

class Knjiga {
    std::string naslov, autor, zanr;
    int godina;
    Korisnik *zaduzena;
    public:
    Knjiga(std::string naslov_knjige, std::string ime_autora, std::string zanr_knjige, int godina_izdavanja);
    std::string DajNaslov() const { return naslov; }
    std::string DajAutora() const { return autor; }
    std::string DajZanr() const { return zanr; }
    int DajGodinuIzdavanja() const { return godina; }
    Korisnik *DajKodKogaJe() const { return zaduzena; }
    void ZaduziKnjigu(Korisnik &korisnik) { zaduzena = &korisnik; }
    void RazduziKnjigu() { zaduzena = nullptr; }
    bool DaLiJeZaduzena() const { return zaduzena != nullptr; }
};

class Biblioteka {
    std::map<int, Korisnik*> korisnici;
    std::map<int, Knjiga*> knjige;
    public:
    Biblioteka() {};
    ~Biblioteka();
    void RegistrirajNovogKorisnika(int clanski_broj, std::string ime, std::string prezime, std::string adresa, std::string telefon);
    void RegistrirajNovuKnjigu(int evidencijski_broj, std::string naslov, std::string autor, std::string zanr, int godina);
    Korisnik &NadjiKorisnika (int clanski_broj) const;
    Knjiga &NadjiKnjigu (int evidencijski_broj) const;
    void IzlistajKorisnike() const;
    void IzlistajKnjige() const;
    void ZaduziKnjigu(int evidencijski_broj, int clanski_broj);
    void RazduziKnjigu(int evidencijski_broj);
    void PrikaziZaduzenja(int clanski_broj);
    Biblioteka(const Biblioteka &b);
    Biblioteka(Biblioteka &&b);
    Biblioteka &operator =(const Biblioteka &b);
    Biblioteka &operator =(Biblioteka &&b);
};

Knjiga::Knjiga(std::string naslov_knjige, std::string ime_autora, std::string zanr_knjige, int godina_izdavanja) {
    naslov = naslov_knjige;
    autor = ime_autora;
    zanr = zanr_knjige;
    godina = godina_izdavanja;
    zaduzena = nullptr;
}

Biblioteka::~Biblioteka() {
    for(auto x : korisnici)
        delete x.second;
    for(auto x : knjige)
        delete x.second;
}

void Biblioteka::RegistrirajNovogKorisnika(int clanski_broj, std::string ime, std::string prezime, std::string adresa, std::string telefon) {
    if(korisnici.find(clanski_broj) == korisnici.end()) {
        Korisnik *p = new Korisnik;
        p->ime = ime;
        p->prezime = prezime;
        p->adresa = adresa;
        p->telefon = telefon;
        korisnici.insert(std::make_pair(clanski_broj, p));
    }
    else throw std::logic_error("Korisnik vec postoji");
}

void Biblioteka::RegistrirajNovuKnjigu(int evidencijski_broj, std::string naslov, std::string autor, std::string zanr, int godina) {
    if(knjige.find(evidencijski_broj) == knjige.end()) {
        Knjiga *p = new Knjiga(naslov, autor, zanr, godina);
        knjige.insert(std::make_pair(evidencijski_broj, p));
    }
    else throw std::logic_error("Knjiga vec postoji");
}

Korisnik &Biblioteka::NadjiKorisnika (int clanski_broj) const {
    auto it(korisnici.find(clanski_broj));
    if(it != korisnici.end()) return *(it->second);
    else throw std::logic_error("Korisnik nije nadjen");
}

Knjiga &Biblioteka::NadjiKnjigu (int evidencijski_broj) const {
    auto it(knjige.find(evidencijski_broj));
    if(it != knjige.end()) return *(it->second);
    else throw std::logic_error("Knjiga nije nadjena");
}

void Biblioteka::IzlistajKorisnike() const {
    for(auto x : korisnici) {
        std::cout << "Clanski broj: " << x.first << "\n";
        std::cout << "Ime i prezime: " << (x.second)->ime << " " << (x.second)->prezime << "\n";
        std::cout << "Adresa: " << (x.second)->adresa << "\n";
        std::cout << "Broj telefona: " << (x.second)->telefon << "" << std::endl << std::endl;
    }
}

void Biblioteka::IzlistajKnjige() const {
    for(auto x : knjige) {
        std::cout << "Evidencijski broj: " << x.first << "\n";
        std::cout << "Naslov: " << (x.second)->DajNaslov() << "\n";
        std::cout << "Pisac: " << (x.second)->DajAutora() << "\n";
        std::cout << "Zanr: " << (x.second)->DajZanr() << "\n";
        std::cout << "Godina izdavanja: " << (x.second)->DajGodinuIzdavanja() << "\n";
        if((x.second)->DaLiJeZaduzena()) {
            std::cout << "Zaduzena kod korisnika: " << ((x.second)->DajKodKogaJe())->ime << " " << ((x.second)->DajKodKogaJe())->prezime;
            std::cout << std::endl << std::endl;
        }
        else std::cout << std::endl;
    }
}

void Biblioteka::ZaduziKnjigu(int evidencijski_broj, int clanski_broj) {
    auto it1(knjige.find(evidencijski_broj));
    if(it1 == knjige.end()) throw std::logic_error("Knjiga nije nadjena");
    auto it2(korisnici.find(clanski_broj));
    if(it2 == korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
    
    if((it1->second)->DaLiJeZaduzena()) throw std::logic_error("Knjiga vec zaduzena");
    else (it1->second)->ZaduziKnjigu(*(it2->second));
}

void Biblioteka::RazduziKnjigu(int evidencijski_broj) {
    auto it(knjige.find(evidencijski_broj));
    if(it == knjige.end()) throw std::logic_error("Knjiga nije nadjena");
    if((it->second)->DaLiJeZaduzena()) (it->second)->RazduziKnjigu();
    else throw std::logic_error("Knjiga nije zaduzena");
}

void Biblioteka::PrikaziZaduzenja(int clanski_broj) {
    auto it(korisnici.find(clanski_broj));
    if(it == korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
    bool ima_zaduzenja(false);
    for(auto x : knjige) {
        if(((x.second)->DajKodKogaJe()) == (it->second)) {
            ima_zaduzenja = true;
            std::cout << "Evidencijski broj: " << x.first << "\n";
            std::cout << "Naslov: " << (x.second)->DajNaslov() << "\n";
            std::cout << "Pisac: " << (x.second)->DajAutora() << "\n";
            std::cout << "Zanr: " << (x.second)->DajZanr() << "\n";
            std::cout << "Godina izdavanja: " << (x.second)->DajGodinuIzdavanja() << "\n\n";
        }
    }
    if(!ima_zaduzenja) std::cout << "Nema zaduzenja za tog korisnika!";
}

Biblioteka::Biblioteka(const Biblioteka &b) : korisnici(b.korisnici), knjige(b.knjige) {
    auto it(b.korisnici.begin());
    for(auto x : korisnici) {
        x.second = new Korisnik;
        x.second->ime = it->second->ime;
        x.second->prezime = it->second->prezime;
        x.second->adresa = it->second->adresa;
        x.second->telefon = it->second->telefon;
        it++;
    }
    
    auto it2(b.knjige.begin());
    for(auto x : knjige) {
        x.second = new Knjiga(it2->second->DajNaslov(), it2->second->DajAutora(), it2->second->DajZanr(), it2->second->DajGodinuIzdavanja());
        it2++;
    }
}

Biblioteka::Biblioteka(Biblioteka &&b) : korisnici(b.korisnici), knjige(b.knjige) {
    for(auto x : b.korisnici) x.second = nullptr;
    for(auto x : b.knjige) x.second = nullptr;
}

Biblioteka &Biblioteka::operator =(const Biblioteka &b) {
    if(&b != this) {
        for(auto x : knjige) delete x.second;
        for(auto x : korisnici) delete x.second;
        knjige = b.knjige;
        korisnici = b.korisnici;
        
        auto it(b.korisnici.begin());
        for(auto x : korisnici) {
            x.second = new Korisnik;
            x.second->ime = it->second->ime;
            x.second->prezime = it->second->prezime;
            x.second->adresa = it->second->adresa;
            x.second->telefon = it->second->telefon;
            it++;
        }
    
        auto it2(b.knjige.begin());
        for(auto x : knjige) {
            x.second = new Knjiga(it2->second->DajNaslov(), it2->second->DajAutora(), it2->second->DajZanr(), it2->second->DajGodinuIzdavanja());
            it2++;
        }
    }
    return *this;
}

Biblioteka &Biblioteka::operator =(Biblioteka &&b) {
    if(&b != this) {
        for(auto x : knjige) delete x.second;
        for(auto x : korisnici) delete x.second;
        knjige = b.knjige;
        korisnici = b.korisnici;
        for(auto x : b.korisnici) x.second = nullptr;
        for(auto x : b.knjige) x.second = nullptr;
    }
    return *this;
}

int main ()
{
    Biblioteka gradska;
    for(;;) {
        std::cout << "Izaberite opciju:\n";
        std::cout << "1 - registriraj novog korisnika\n";
        std::cout << "2 - registriraj novu knjigu\n";
        std::cout << "3 - nadji korisnika\n";
        std::cout << "4 - nadji knjigu\n";
        std::cout << "5 - izlistaj korisnike\n";
        std::cout << "6 - izlistaj knjige\n";
        std::cout << "7 - zaduzi knjigu\n";
        std::cout << "8 - razduzi knjigu\n";
        std::cout << "9 - prikazi zaduzenja\n";
        std::cout << "0 - izlaz\n\n";
        std::cout << "Vas izbor je: ";
        int opcija;
        std::cin >> opcija;
        while(opcija < 0 || opcija > 9) {
            std::cout << "Pogresna opcija!\nVas izbor je: ";
            std::cin >> opcija;
        }
        if(opcija == 1) {
            std::string ime, prezime, adresa, telefon;
            int clanski_broj;
            std::cout << "\nUnesite clanski broj: ";
            std::cin >> clanski_broj;
            std::cin.get();
            std::cout << "Unesite ime: ";
            std::getline(std::cin, ime);
            std::cout << "Unesite prezime: ";
            std::getline(std::cin, prezime);
            std::cout << "Unesite adresu: ";
            std::getline(std::cin, adresa);
            std::cout << "Unesite telefon: ";
            std::getline(std::cin, telefon);
            try {
                gradska.RegistrirajNovogKorisnika(clanski_broj, ime, prezime, adresa, telefon);
                std::cout << "\nUnijeli ste novog korisnika sa podacima:\n";
                std::cout << "Clanski broj: " << clanski_broj << std::endl;
                std::cout << "Ime: " << ime << std::endl;
                std::cout << "Prezime: " << prezime << std::endl;
                std::cout << "Adresa: " << adresa << std::endl;
                std::cout << "Broj telefona: " << telefon << std::endl << std::endl;
            }
            catch(std::logic_error izuzetak) {
                std::cout << std::endl << izuzetak.what() << std::endl << std::endl;
            }
        }
        else if(opcija == 2) {
            std::string naslov, autor, zanr;
            int evidencijski_broj, godina;
            std::cout << "\nUnesite evidencijski broj: ";
            std::cin >> evidencijski_broj;
            std::cin.get();
            std::cout << "Unesite naslov: ";
            std::getline(std::cin, naslov);
            std::cout << "Unesite autora: ";
            std::getline(std::cin, autor);
            std::cout << "Unesite zanr: ";
            std::getline(std::cin, zanr);
            std::cout << "Unesite godinu izdavanja: ";
            std::cin >> godina;
            try {
                gradska.RegistrirajNovuKnjigu(evidencijski_broj, naslov, autor, zanr, godina);
                std::cout << "\nUnijeli ste novu knjigu sa podacima:\n";
                std::cout << "Evidencijski broj: " << evidencijski_broj << std::endl;
                std::cout << "Naslov: " << naslov << std::endl;
                std::cout << "Autor: " << autor << std::endl;
                std::cout << "Zanr: " << zanr << std::endl;
                std::cout << "Godina izdavanja: " << godina << std::endl << std::endl;
            }
            catch(std::logic_error izuzetak) {
                std::cout << std::endl << izuzetak.what() << std::endl << std::endl;
            }
        }
        else if(opcija == 3) {
            int clanski_broj;
            std::cout << "\nUnsite clanski broj korisnika kojeg zelite pronaci: ";
            std::cin >> clanski_broj;
            try {
                Korisnik p(gradska.NadjiKorisnika(clanski_broj));
                std::cout << "\nPronasli ste korisnika sa podacima:\n";
                std::cout << "Clanski broj: " << clanski_broj << std::endl;
                std::cout << "Ime: " << p.ime << std::endl;
                std::cout << "Prezime: " << p.prezime << std::endl;
                std::cout << "Adresa: " << p.adresa << std::endl;
                std::cout << "Broj telefona: " << p.telefon << std::endl << std::endl;
            }
            catch(std::logic_error izuzetak) {
                std::cout << std::endl << izuzetak.what() << std::endl << std::endl;
            }
        }
        else if(opcija == 4) {
            int evidencijski_broj;
            std::cout << "\nUnsite evidencijski broj knjige koju zelite pronaci: ";
            std::cin >> evidencijski_broj;
            try {
                Knjiga p(gradska.NadjiKnjigu(evidencijski_broj));
                std::cout << "\nPronasli ste knjigu sa podacima:\n";
                std::cout << "Evidencijski broj: " << evidencijski_broj << std::endl;
                std::cout << "Naslov: " << p.DajNaslov() << std::endl;
                std::cout << "Autor: " << p.DajAutora() << std::endl;
                std::cout << "Zanr: " << p.DajZanr() << std::endl;
                std::cout << "Godina izdavanja: " << p.DajGodinuIzdavanja() << std::endl << std::endl;
            }
            catch(std::logic_error izuzetak) {
                std::cout << std::endl << izuzetak.what() << std::endl << std::endl;
            }
        }
        else if(opcija == 5) {
            std::cout << "\nKorisnici biblioteke su: " << std::endl << std::endl;
            gradska.IzlistajKorisnike();
        }
        else if(opcija == 6) {
            std::cout << "\nKnjige koje se nalaze u biblioteci su: " << std::endl << std::endl;
            gradska.IzlistajKnjige();
        }
        else if(opcija == 7) {
            int evidencijski_broj, clanski_broj;
            std::cout << "\nUnesite evidencijski broj knjige koju zelite zaduziti: ";
            std::cin >> evidencijski_broj;
            std::cout << "Unesite clanski broj korisnika kojem zaduzujete knjigu: ";
            std::cin >> clanski_broj;
            try {
                gradska.ZaduziKnjigu(evidencijski_broj, clanski_broj);
                std::cout << "\nKnjigu sa evidencijskim brojem " << evidencijski_broj << " ste zaduzili korisniku sa clanskim brojem " <<
                clanski_broj << "." << std::endl << std::endl;
            }
            catch(std::logic_error izuzetak) {
                std::cout << std::endl << izuzetak.what() << std::endl << std::endl;
            }
        }
        else if(opcija == 8) {
            int evidencijski_broj;
            std::cout << "\nUnesite evidencijski broj knjige koju zelite razduziti: ";
            std::cin >> evidencijski_broj;
            try {
                gradska.RazduziKnjigu(evidencijski_broj);
                std::cout << "\nRazduzili ste knjigu sa evidencijskim brojem " << evidencijski_broj << "." << std::endl << std::endl;
            }
            catch(std::logic_error izuzetak) {
                std::cout << std::endl << izuzetak.what() << std::endl << std::endl;
            }
        }
        else if(opcija == 9) {
            int clanski_broj;
            std::cout << "\nUnesite clanski broj korisnika: ";
            std::cin >> clanski_broj;
            try {
                std::cout << "\nKorisnik sa clanskim brojem " << clanski_broj << " je zaduzio sljedece knjige: " << std::endl << std::endl;
                gradska.PrikaziZaduzenja(clanski_broj);
                std::cout << std::endl << std::endl;
            }
            catch(std::logic_error izuzetak) {
                std::cout << std::endl << izuzetak.what() << std::endl << std::endl;
            }
        }
        else break;
    }
	return 0;
}