/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <memory>
using std::map;
using std::string;

struct Korisnik {
    string ime, prezime, adresa, telefon;
};

class Knjiga {
    string naslov, ime_pisca, zanr;
    int godina_izdanja;
    Korisnik *kod_koga_je;
public:
    Knjiga (string naslov, string ime_pisca, string zanr, int godina_izdanja); 
    string DajNaslov () const { return naslov; }
    string DajAutora () const { return ime_pisca; }
    string DajZanr () const { return zanr; }
    int DajGodinuIzdavanja () const { return godina_izdanja; }
    Korisnik* DajKodKogaJe () const { return kod_koga_je; }
    void ZaduziKnjigu (Korisnik &korisnik);
    void RazduziKnjigu ();
    bool DaLiJeZaduzena () const;
};

class Biblioteka {
    map<int, std::shared_ptr<Korisnik>> korisnici;
    map<int, std::shared_ptr<Knjiga>> knjige;
public:
    Biblioteka () {};
    Biblioteka (const Biblioteka &b);
    Biblioteka (Biblioteka &&b);
    Biblioteka& operator= (const Biblioteka &b);
    void RegistrirajNovogKorisnika (int clanski_br_korisnika, string ime, string prezime, string adresa, string telefon);
    void RegistrirajNovuKnjigu (int evidencijski_br_knjige, string naslov, string ime_pisca, string zanr, int godina_izdanja);
    Korisnik &NadjiKorisnika (int clanski_br_korisnika) const;
    Knjiga &NadjiKnjigu (int evidencijski_br_knjige) const;
    void IzlistajKorisnike () const;
    void IzlistajKnjige() const;
    void ZaduziKnjigu (int evidencijski_br_knjige, int clanski_br_korisnika);
    void RazduziKnjigu (int evidencijski_br_knjige);
    void PrikaziZaduzenja (int clanski_br_korisnika) const;
};

Knjiga::Knjiga (string naslov, string ime_pisca, string zanr, int godina_izdanja) : naslov(naslov), ime_pisca(ime_pisca), zanr(zanr),
    godina_izdanja(godina_izdanja), kod_koga_je(nullptr) {}

void Knjiga::ZaduziKnjigu (Korisnik &korisnik) {
    kod_koga_je=&korisnik;
}

void Knjiga::RazduziKnjigu () {
    kod_koga_je=nullptr;
}

bool Knjiga::DaLiJeZaduzena () const {
    if (!kod_koga_je)
        return false;
    return true;
}

Biblioteka::Biblioteka (const Biblioteka &b) {
    for (auto it(b.korisnici.begin()); it!=b.korisnici.end(); it++) {
        std::shared_ptr<Korisnik> p(std::make_shared<Korisnik>());
        p->ime=it->second->ime;
        p->prezime=it->second->prezime;
        p->adresa=it->second->adresa;
        p->telefon=it->second->telefon;
        korisnici[it->first]=p;
    }
    for (auto it(b.knjige.begin()); it!=b.knjige.end(); it++) {
        std::shared_ptr<Knjiga> p(std::make_shared<Knjiga>(it->second->DajNaslov(), it->second->DajAutora(), it->second->DajZanr(), it->second->DajGodinuIzdavanja()));
        knjige[it->first]=p;
    }
}

Biblioteka::Biblioteka (Biblioteka &&b) {
    for (auto it(b.korisnici.begin()); it!=b.korisnici.end(); it++) {
        korisnici[it->first]=it->second;
        it->second=nullptr;
    }
    for (auto it(b.knjige.begin()); it!=b.knjige.end(); it++) {
        knjige[it->first]=it->second;
        it->second=nullptr;
    }
}

Biblioteka& Biblioteka::operator= (const Biblioteka &b) {
    if (&b!=this) {
        for (auto it(korisnici.begin()); it!=korisnici.end(); it++) {
            it->second=nullptr;
            korisnici.erase(it->first);
        }
        for (auto it(b.korisnici.begin()); it!=b.korisnici.end(); it++) {
            std::shared_ptr<Korisnik> p(std::make_shared<Korisnik>());
            p->ime=it->second->ime;
            p->prezime=it->second->prezime;
            p->adresa=it->second->adresa;
            p->telefon=it->second->telefon;
            korisnici[it->first]=p;
        }
        for (auto it(knjige.begin()); it!=knjige.end(); it++) {
            it->second=nullptr;
            knjige.erase(it->first);
        }
        for (auto it(b.knjige.begin()); it!=b.knjige.end(); it++) {
            std::shared_ptr<Knjiga> p(std::make_shared<Knjiga>(it->second->DajNaslov(), it->second->DajAutora(), it->second->DajZanr(), it->second->DajGodinuIzdavanja()));
            knjige[it->first]=p;
            knjige[it->first]->ZaduziKnjigu(*(it->second->DajKodKogaJe()));
        }
    }
    return *this;
}

void Biblioteka::RegistrirajNovogKorisnika (int clanski_br_korisnika, string ime, string prezime, string adresa, string telefon) {
    if (korisnici.count(clanski_br_korisnika)) throw std::logic_error("Korisnik vec postoji");
    std::shared_ptr<Korisnik> p(std::make_shared<Korisnik>());
    p->ime=ime;
    p->prezime=prezime;
    p->adresa=adresa;
    p->telefon=telefon;
    korisnici[clanski_br_korisnika]=p;
}

void Biblioteka::RegistrirajNovuKnjigu (int evidencijski_br_knjige, string naslov, string ime_pisca, string zanr, int godina_izdanja) {
    if (knjige.count(evidencijski_br_knjige)) throw std::logic_error("Knjiga vec postoji");
    std::shared_ptr<Knjiga> p(std::make_shared<Knjiga>(naslov, ime_pisca, zanr, godina_izdanja));
    knjige[evidencijski_br_knjige]=p;
}

Korisnik& Biblioteka::NadjiKorisnika (int clanski_br_korisnika) const {
    auto it(korisnici.find(clanski_br_korisnika));
    if (it==korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
    return *(it->second);
}

Knjiga& Biblioteka::NadjiKnjigu (int evidencijski_br_knjige) const {
    auto it(knjige.find(evidencijski_br_knjige));
    if (it==knjige.end()) throw std::logic_error("Knjiga nije nadjena");
    return *(it->second);
}

void Biblioteka::IzlistajKorisnike () const {
    for (auto it(korisnici.begin()); it!=korisnici.end(); it++) {
        std::cout << "Clanski broj: " << it->first << std::endl;
        std::cout << "Ime i prezime: " << it->second->ime << " " << it->second->prezime << std::endl;
        std::cout << "Adresa: " << it->second->adresa << std::endl;
        std::cout << "Broj telefona: " << it->second->telefon << std::endl << std::endl;
    }
}

void Biblioteka::IzlistajKnjige () const {
    for (auto it(knjige.begin()); it!=knjige.end(); it++) {
        std::cout << "Evidencijski broj: " << it->first << std::endl;
        std::cout << "Naslov: " << it->second->DajNaslov() << std::endl;
        std::cout << "Pisac: " << it->second->DajAutora() << std::endl;
        std::cout << "Zanr: " << it->second->DajZanr() << std::endl;
        std::cout << "Godina izdavanja: " << it->second->DajGodinuIzdavanja() << std::endl;
        if (it->second->DaLiJeZaduzena())
            std::cout << "Zaduzena kod korisnika: " << it->second->DajKodKogaJe()->ime << " " << it->second->DajKodKogaJe()->prezime << std::endl;
        std::cout << std::endl;
    }
}

void Biblioteka::ZaduziKnjigu (int evidencijski_br_knjige, int clanski_br_korisnika) {
    if (!knjige.count(evidencijski_br_knjige)) throw std::logic_error("Knjiga nije nadjena");
    if (!korisnici.count(clanski_br_korisnika)) throw std::logic_error("Korisnik nije nadjen");
    if (NadjiKnjigu(evidencijski_br_knjige).DaLiJeZaduzena()) throw std::logic_error("Knjiga vec zaduzena");
    NadjiKnjigu(evidencijski_br_knjige).ZaduziKnjigu(NadjiKorisnika(clanski_br_korisnika));
}

void Biblioteka::RazduziKnjigu (int evidencijski_br_knjige) {
    if (!knjige.count(evidencijski_br_knjige)) throw std::logic_error("Knjiga nije nadjena");
    if (!(NadjiKnjigu(evidencijski_br_knjige).DaLiJeZaduzena())) throw std::logic_error("Knjiga nije zaduzena");
    NadjiKnjigu(evidencijski_br_knjige).RazduziKnjigu();
}

void Biblioteka::PrikaziZaduzenja (int clanski_br_korisnika) const {
    if (!korisnici.count(clanski_br_korisnika)) throw std::logic_error("Korisnik nije nadjen");
    bool zaduzen(false);
    for (auto it(knjige.begin()); it!=knjige.end(); it++) {
        if (&(*(it->second->DajKodKogaJe()))==&NadjiKorisnika(clanski_br_korisnika)) {
            std::cout << "Evidencijski broj: " << it->first << std::endl;
            std::cout << "Naslov: " << it->second->DajNaslov() << std::endl;
            std::cout << "Pisac: " << it->second->DajAutora() << std::endl;
            std::cout << "Zanr: " << it->second->DajZanr() << std::endl;
            std::cout << "Godina izdavanja: " << it->second->DajGodinuIzdavanja() << std::endl << std::endl;
            zaduzen=true;
        }
    }
    if (!zaduzen)
        std::cout << "Nema zaduzenja za tog korisnika!";
}

int main ()
{
	return 0;
}