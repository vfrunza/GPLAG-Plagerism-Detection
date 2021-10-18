/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <stdexcept>

struct Korisnik
{
    std::string ime, prezime, adresa, telefon;
};

class Knjiga
{
    std::string naslov, ime_pisca, zanr;
    int god_izdavanja;
    Korisnik *zaduzenje;
    public:
    Knjiga (std::string naslov, std::string ime_pisca, std::string zanr, int god_izdavanja) : naslov(naslov), ime_pisca(ime_pisca), zanr(zanr), god_izdavanja(god_izdavanja) {zaduzenje=nullptr;}
    std::string DajNaslov() {return naslov;}
    std::string DajAutora() {return ime_pisca;}
    std::string DajZanr() {return zanr;}
    int DajGodinuIzdavanja() {return god_izdavanja;}
    Korisnik DajKodKogaJe() {return zaduzenje;}
    Korisnik *ZaduziKnjigu(&Korisnik.ime) {return *zaduzenje;}
    Korisnik *RazduziKnjigu() {return *zaduzenje(nullptr);}
    bool DaLiJeZaduzena() 
    {
        if (zaduzenje == nullptr) return false;
        else return true;
    }
};

class Biblioteka
{
    std::map<Korisnik, int> korisnik;
    std::map<Knjiga, int> knjiga;
    void RegistrirajNovogKorisnika (int clanski_br, std::string ime, std::string prezime, std::string adresa, std::string telefon)
    {
        auto it = korisnik.begin();
        if (clanski_br == it->second) throw std::logic_error("Korisnik vec postoji");
        std::cin >> clanski_br;
        std::strcpy(Korisnik.ime, ime);
        std::strcpy(Korisnik.prezime, prezime);
        std::strcpy(Korisnik.adresa, adresa);
        std::strcpy(Korisnik.telefon,telefon);
    }
    void RegistrirajNovuKnjigu (int br_knjige, std::string naslov, std::string ime_pisca, std::string zanr, int god_izdavanja)
    {
        auto it = knjiga.begin();
        if(br_knjige == it->second) throw std::logic_error ("Knjiga vec postoji");
        std::cin >> br_knjige;
        std::strcpy (Knjga::naslov, naslov);
        std::strcpy (Knjiga::ime_pisca, ime_pisca);
        std::strcpy (Knjiga::zanr, zanr);
        std::cin >> god_izdavanja;
    }
    Korisnik &NadjiKorisnika (int clanski_br)
    {
        auto it (korisnik.find(clanski_br));
        if (it == korisnik.end()) throw std::logic_error("Korisnik nije nadjen");
        else return it->first;
    }
    Knjiga &NadjiKnjigu (int br_knjige)
    {
        auto it (knjiga.find(br_knjige));
        if (it == knjiga.end()) throw std::logic_error("Knjiga nije nadjena");
        else return it->first;
    }
};

int main ()
{
	return 0;
}