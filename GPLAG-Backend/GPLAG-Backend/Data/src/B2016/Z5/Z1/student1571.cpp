/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include <algorithm>

struct Korisnik {
    std::string ime, prezime, adresa, telefon;
};
class Knjiga {
    std::string naslov, ime_pisca, zanr;
    int godina_izdavanja;
    Korisnik *zaduzenje;
    void Ispisi() const;
    public:
    Knjiga (std::string naslov, std::string ime_pisca, std::string zanr, int godina_izdavanja): naslov(naslov), ime_pisca(ime_pisca),zanr(zanr),godina_izdavanja(godina_izdavanja) { zaduzenje = nullptr; }
    std::string DajNaslov() const { return naslov; }
    std::string DajAutora() const { return ime_pisca; }
    std::string DajZanr() const { return zanr; }
    int DajGodinuIzdavanja() const { return godina_izdavanja; }
    Korisnik *DajKodKogaJe() const { return zaduzenje; }
    void ZaduziKnjigu (Korisnik &zaduzenje) { Knjiga::zaduzenje = &zaduzenje; }
    void RazduziKnjigu() { zaduzenje = nullptr; }
    bool DaLiJeZaduzena() const { return zaduzenje!=nullptr; }
};
class Biblioteka {
    std::map<int, Korisnik*> korisnici;
    std::map<int, Knjiga*>  knjige;
    void IspisiKorisnike() const;
    public:
    void RegistrirajNovogKorisnika (int clanski_broj, std::string ime, std::string prezime, std::string adresa, std::string broj_telefona);//
    void RegistrirajNovuKnjigu (int evi_broj, std::string naslov, std::string pisac, std::string zanr, int god_izdavanja);//
    Korisnik &NadjiKorisnika (int cl_broj) const; //
    Knjiga &NadjiKnjigu (int ev_broj); //
    Biblioteka (const Biblioteka &kop); // kasnije imple.
    Biblioteka &operator= (const Biblioteka &nema); // kasnije
    Biblioteka() {};
    void IzlistajKorisnike() { this->IspisiKorisnike(); }//
    void IzlistajKnjige() const; //
    void ZaduziKnjigu (int ev_broj, int clanski_broj); //
    void RazduziKnjigu(int ev_broj); //
    void PrikaziZaduzenja (int clanski_broj) const;//
    ~Biblioteka();//
};
void Biblioteka::IspisiKorisnike() const {
    for (auto it=korisnici.begin(); it!= korisnici.end(); it++) {
        std::cout << "Clanski broj: " << it->first; 
        std::cout << std::endl << "Ime i prezime: " << it->second->ime << " " << it->second->prezime << std::endl;
        std::cout << "Adresa: " << it->second->adresa << std::endl;
        std::cout << "Broj telefona: " << it->second->telefon;
        std::cout << std::endl;
    }
}
void Knjiga::Ispisi() const {
    std::cout << "Naslov: " << DajNaslov() << std::endl;
    std::cout << "Pisac: " << DajAutora() << std::endl;
    std::cout << "Zanr: " << DajZanr() << std::endl;
    std::cout << "Godina izdavanja: " << DajGodinuIzdavanja();
    std::cout << std::endl;
}
void Biblioteka::RegistrirajNovogKorisnika (int clanski_broj, std::string ime, std::string prezime, std::string adresa, std::string broj_telefona) {
    auto it = korisnici.find (clanski_broj);
    if (it != korisnici.end()) throw std::logic_error ("Korisnik vec postoji");
    Korisnik *pok = new Korisnik;
    (*pok).ime = ime;
    (*pok).prezime = prezime;
    (*pok).adresa = adresa;
    (*pok).telefon = broj_telefona;
    korisnici[clanski_broj] = pok;
}
void Biblioteka::RegistrirajNovuKnjigu (int evi_broj, std::string naslov, std::string pisac, std::string zanr, int god_izdavanja) {
    auto it = knjige.find (evi_broj);
    if (it != knjige.end()) throw std::logic_error ("Knjiga vec postoji");
    Knjiga *pok = new Knjiga (naslov, pisac, zanr, god_izdavanja);
    knjige[evi_broj] = pok;
}
Korisnik &Biblioteka::NadjiKorisnika (int cl_broj) const {
    Korisnik *pomocni;
    auto it = korisnici.find (cl_broj);
    if (it == korisnici.end()) throw std::logic_error ("Korisnik nije nadjen");
    if (it != korisnici.end()) {
        pomocni = it->second;
        return *pomocni;
    }
}
Knjiga &Biblioteka::NadjiKnjigu (int ev_broj) {
    Knjiga *pomocni;
    auto it = knjige.find (ev_broj);
    if (it != knjige.end()) {
        pomocni = it->second;
        return *pomocni;
    }
    throw std::logic_error ("Knjiga nije nadjena");
}
void Biblioteka::IzlistajKnjige() const {
    for (auto it=knjige.begin(); it!=knjige.end(); it++) {
      
        std::cout << "Evidencijski broj: " << it->first << std::endl;
        std::cout << "Naslov: " << it->second->DajNaslov() << std::endl;
        std::cout << "Pisac: " << it->second->DajAutora() << std::endl;
        std::cout << "Zanr: " << it->second->DajZanr() << std::endl;
        std::cout << "Godina izdavanja: " << it->second->DajGodinuIzdavanja() << std::endl;
        if (it->second->DaLiJeZaduzena()) {
            std::cout << "Zaduzena kod korisnika: ";
            std::cout << it->second->DajKodKogaJe()->ime << " " << it->second->DajKodKogaJe()->prezime;
            std::cout << std::endl << std::endl;
        }
    }
}
void Biblioteka::ZaduziKnjigu(int ev_broj, int clanski_broj) {
    auto it = knjige.find(ev_broj);
    if (it == knjige.end()) throw std::logic_error ("Knjiga nije nadjena");
    auto proba = knjige.find(ev_broj);
    if (proba->second->DaLiJeZaduzena()) throw std::logic_error ("Knjiga vec zaduzena");
    auto it2 = korisnici.find (clanski_broj);
    if (it2 == korisnici.end()) throw std::logic_error ("Korisnik nije nadjen");
    
    for (auto it1=korisnici.begin(); it1!=korisnici.end(); it1++) {
        if (it1->first == clanski_broj ) {
            for (auto it3=knjige.begin(); it3!=knjige.end(); it3++) {
                if (it3->first == ev_broj) {
                    it3->second->ZaduziKnjigu(*(it1)->second);
                    break;
                }
            }
        }
    }
}
void Biblioteka::RazduziKnjigu(int ev_broj) {
    auto it = knjige.find (ev_broj);
    if (it == knjige.end()) throw std::logic_error ("Knjiga nije nadjena");
    if (it != knjige.end()) it->second->RazduziKnjigu();
}
void Biblioteka::PrikaziZaduzenja(int clanski_broj) const {
    bool ima(false);
    auto it = korisnici.find (clanski_broj);
    if (it == korisnici.end()) throw std::logic_error ("Korisnik nije nadjen");
    for (auto it1=knjige.begin(); it1!=knjige.end(); it1++) {
        if (it1->second->DaLiJeZaduzena() && it->second->ime == it1->second->DajKodKogaJe()->ime && it->second->prezime == it1->second->DajKodKogaJe()->prezime && it->second->adresa == it1->second->DajKodKogaJe()->adresa && it->second->telefon == it1->second->DajKodKogaJe()->telefon) {
            ima = true;
            std::cout << "Evidencijski broj: " << it1->first << std::endl;
            std::cout << "Naslov: " << it1->second->DajNaslov() << std::endl;
            std::cout << "Pisac: " << (it1->second)->DajAutora() << std::endl; 
            std::cout << "Zanr: " << (it1->second)->DajZanr() << std::endl;
            std::cout << "Godina izdavanja: " << (it1->second)->DajGodinuIzdavanja() ;
            std::cout << std::endl << std::endl;
        }
    }
    if (!ima) throw std::logic_error ("Nema zaduzenja za tog korisnika");
}
Biblioteka::~Biblioteka() {
    for (auto it=knjige.begin(); it!=knjige.end(); it++) {
        if (it->second != nullptr)
            delete it->second;
    }
    for (auto it=korisnici.begin(); it!=korisnici.end(); it++) {
        if (it->second != nullptr)
            delete it->second;
    }
}
Biblioteka::Biblioteka (const Biblioteka &kop) {
    for (auto it=kop.korisnici.begin(); it!=kop.korisnici.end(); it++) {
        Korisnik *pomocni = new Korisnik;
        (*pomocni).ime = it->second->ime;
        (*pomocni).prezime = it->second->prezime;
        (*pomocni).adresa = it->second->adresa;
        (*pomocni).telefon = it->second->telefon;
        korisnici.insert (std::make_pair(it->first, pomocni));
    }
    for (auto it=kop.knjige.begin(); it!=kop.knjige.end(); it++) {
        Knjiga *pomocni = new Knjiga (it->second->DajNaslov(), it->second->DajAutora(), it->second->DajZanr(), it->second->DajGodinuIzdavanja());
        knjige.insert (std::make_pair(it->first, pomocni));
    }
}
Biblioteka &Biblioteka::operator= (const Biblioteka &nema) {
     if (this != &nema) {
        korisnici.erase (korisnici.begin(), korisnici.end());
        knjige.erase (knjige.begin(), knjige.end());
        for (auto it=nema.korisnici.begin(); it!=nema.korisnici.end(); it++) {
            korisnici[it->first] = it->second;
        }
        for (auto it=nema.knjige.begin(); it!=nema.knjige.end(); it++)
            knjige.insert (std::make_pair (it->first, new Knjiga (it->second->DajNaslov(), it->second->DajAutora(), it->second->DajZanr(), it->second->DajGodinuIzdavanja())));
    }
    return *this;
}

int main ()
{
    Biblioteka bib;
    std::string ime, prezime, adresa, telefon, naziv_knjige, zanr, autor;
    int evidencijski_broj, clanski_broj, godina_izdavanja, izbor;
    for(;;) {
        std::cout << "Izaberite neku od opcija:\n";
        std::cout << "0 - Kraj\n";
        std::cout << "1 - Registriraj novog korisnika\n";
        std::cout << "2 - Registriraj novu knjigu\n";
        std::cout << "3 - Izlistaj korisnike\n";
        std::cout << "4 - Izlistaj knjige\n";
        std::cout << "5 - Zaduzi knjigu\n";
        std::cout << "6 - Razduzi knjigu\n";
        std::cout << "7 - Prikazi zaduzenja\n\n";
        std::cout << "Vas izbor:\n";
        std::cin >> izbor;
        std::cin.clear();
        std::cin.ignore (10000,'\n');
        try {
            switch(izbor) {
                case (0): {
                    std::cout <<  "Dovidjenja!" << std::endl;
                    return 0;
                }
                case (1): {
                    std::cout << "Unesite ime korisnika: ";
                    std::getline (std::cin, ime);
                    std::cout << "Unesite prezime korisnika: ";
                    std::getline (std::cin, prezime);
                    std::cout << "Unesite adresu: ";
                    std::getline (std::cin, adresa);
                    std::cout << "Unesite broj telefona: ";
                    std::getline (std::cin, telefon);
                    std::cout << "Unesite clanski broj: ";
                    std::cin >> clanski_broj;
                    std::cin.clear();
                    std::cin.ignore (10000,'\n');
                    bib.RegistrirajNovogKorisnika (clanski_broj, ime, prezime, adresa, telefon);
                    std::cout << "Korisnik uspjesno dodan!\n\n" ;
                    break;
                }
                case(2): {
                    std::cout << "Unesite naziv knjige: ";
                    std::getline (std::cin, naziv_knjige);
                    std::cout << "Unesite zanr knjige: ";
                    std::getline (std::cin, zanr);
                    std::cout << "Unesite ime autora knjige: ";
                    std::getline (std::cin, autor);
                    std::cout << "Unesite godinu izdavanja knjige: ";
                    std::cin >> godina_izdavanja;
                    std::cout << "Unesite evidencijski broj knjige: ";
                    std::cin >> evidencijski_broj;
                    std::cin.clear();
                    std::cin.ignore (10000,'\n');
                    bib.RegistrirajNovuKnjigu (evidencijski_broj, naziv_knjige, zanr, autor, godina_izdavanja);
                    std::cout << "Knjiga uspjesno dodana!\n\n";
                    break;
                }
                case(3): {
                    bib.IzlistajKorisnike();
                    std::cout << std::endl;
                    break;
                }
                case(4): {
                    bib.IzlistajKnjige();
                    std::cout << std::endl;
                    break;
                }
                case(5): {
                    std::cout << "Unesite clanski broj: ";
                    std::cin >> clanski_broj;
                    std::cout << "Unesite evidencijski broj: ";
                    std::cin >> evidencijski_broj;
                    std::cin.clear();
                    std::cin.ignore(10000,'\n');
                    bib.ZaduziKnjigu(evidencijski_broj, clanski_broj);
                    std::cout << "Knjiga je uspjesno zaduzena!\n\n";
                    break;
                }
                case(6): {
                    std::cout << "Unesite evidencijski broj: ";
                    std::cin >> evidencijski_broj;
                    std::cin.clear();
                    std::cin.ignore(10000,'\n');
                    bib.RazduziKnjigu(evidencijski_broj);
                    std::cout << "Knjiga je uspjesno razduzena!\n\n";
                    break;
                }
                case(7): {
                    std::cout << "Unesite clanski broj: ";
                    std::cin >> clanski_broj;
                    std::cin.clear();
                    std::cin.ignore(10000,'\n');
                    bib.PrikaziZaduzenja(clanski_broj);
                    break;
                }
            }
        }
        catch (std::logic_error por) {
            std::cout << por.what() << std::endl << std::endl;
        }
    }
	return 0;
}