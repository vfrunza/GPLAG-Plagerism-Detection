/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>

struct Korisnik {
    std::string ime,prezime,adresa,telefon;  
};

class Knjiga {
        std::string naslov,ime_pisca,zanr;
        int godina_izdavanja;
        Korisnik *p;
    public:
        Knjiga(std::string naslov,std::string pisac,std::string zanr,int godina) : naslov(naslov),ime_pisca(pisac),zanr(zanr),godina_izdavanja(godina),p(nullptr) {};
        std::string DajNaslov() const { return naslov; }
        std::string DajAutora() const { return ime_pisca; }
        std::string DajZanr() const { return zanr; }
        int DajGodinuIzdavanja() const { return godina_izdavanja; }
        DajKodKogaJe() const {}                                                 //KOD KOGA JE??
        void ZaduziKnjigu(Korisnik &korisnik) { }                               //ZADUZI KNJIGU???
        void RazduziKnjigu() { p=nullptr; }
        bool DaLiJeZaduzena() const {
            if(p==nullptr) return false;
            else return true;
        }
};

class Biblioteka {
        std::map<int, > korisnici;
        std::map<int, > knjige;
    public:
        void RegistrirajNovogKorisnika(int clanski_br,std::string ime,std::string prezime,std::string adresa,std::string telefon) {
            Korisnik *pok(new Korisnik(ime,prezime,adresa,telefon));
        }
};
int main ()
{
	return 0;
}