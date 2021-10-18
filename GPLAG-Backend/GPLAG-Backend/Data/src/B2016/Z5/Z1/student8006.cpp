/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>

struct Korisnik {
    std::string ime, prezime, adresa, telefon;
}

class Knjiga {
    std::string naslov, ime_pisca, zanr;
    int godina_izdavanja;
    Korisnik *izdata;
    public:
    Knjiga(std::string nas, std::string ip, std::string genre, int godina) {
        naslov = nas;
        ime_pisca = ip;
        zanr = genre;
        godina_izdavanja = godina;
        izdata = nullptr;
    }
    std::string DajNaslov() { return naslov; }
    std::string DajAutora() { return ime_pisca; }
    std::string DajZanr() { return zanr; }
    void ZaduziKnjigu(Korisnik &korisnik) { izdata = &korisnik; }
    void RazduziKnjigu() { izdata = nullptr; }
    bool DaLiJeZaduzena() { return (izdata != nullptr); }
}

class Biblioteka {
    std::map<int, Korisnik*> korisnici;
    std::map<int, Knjiga*> knjige;
    public:
    Biblioteka(Biblioteka &lib) {
        Biblioteka *biblioteka = nullptr;
        biblioteka = new Biblioteka;
        biblioteka = lib;
    }
}

int main ()
{
	return 0;
}