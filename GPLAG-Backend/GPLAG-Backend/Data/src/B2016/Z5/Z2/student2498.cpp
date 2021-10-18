/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>

struct Korisnik {
    std::string ime, prezime, adresa, telefon;
};

class Knjiga {
    std::string naslov, ime_pisca, zanr;
    int godina_izdavanja;
    Korisnik *korisnik;
    
public:
    Knjiga(std::string naslov, std::string ime_pisca, std::string zanr, int godina_izdavanja, Korisnik *korisnik) : naslov(naslov), ime_pisca(ime_pisca), zanr(zanr), godina_izdavanja(godina_izdavanja), korisnik(new Korisnik){
        this->korisnik = korisnik;
    }
    std::string DajNaslov() {
        return naslov;
    }
    std::string DajAutora() {
        return ime_pisca;
    }
    std::string DajZanr() {
        return zanr;
    }
    int DajGodinuIzdavanja() {
        return godina_izdavanja;
    }
    Korisnik DajKodKogaJe() {
        return *korisnik;
    }
    void ZaduziKnjigu(Korisnik &k) {
        *korisnik = k;
    }
    void RazduziKnjigu() {
        korisnik = nullptr;
    }
    bool DaLiJeZaduzena() {
        if(korisnik==nullptr) return false;
        else return  true;
    }
};

int main ()
{
    Korisnik k{"Nejla", "Klisura", "Armija BiH 11", "062490682"}, m{"Sadbera", "Klisura", "Armija BiH 11", "062902663"};
    Knjiga knjiga{"Tvrdjava", "Mesa Selimovic", "Domace", 17101992, &k};
    std::cout << "Autor: " << knjiga.DajAutora() << " Naslov: " << knjiga.DajNaslov() << " Godina izdavanja: " << knjiga.DajGodinuIzdavanja() << " Zanr: " << knjiga.DajZanr() << std::endl;
    std::cout << "Knjigu zaduzio: " << (knjiga.DajKodKogaJe()).ime << std::endl;
    knjiga.ZaduziKnjigu(m);
    std::cout << "Knjigu zaduzio: " << (knjiga.DajKodKogaJe()).ime << std::endl;
    knjiga.RazduziKnjigu();
    std::cout << knjiga.DaLiJeZaduzena() << std::endl;
    std::cout << "Knjigu zaduzio: " << (knjiga.DajKodKogaJe()).ime << std::endl;
    return 0;
}