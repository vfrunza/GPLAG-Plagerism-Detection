/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <utility>

struct Korisnik{
      std::string ime, prezime, adresa, telefon;
};

class Knjiga{
    std::string naslov, pisac, zanr;
    int godina;
    Korisnik *zaduzio;
public:
    Knjiga(std::string n, std::string p, std::string z, int g) : zaduzio(nullptr)
    {
        naslov = n; p = pisac; z = zanr; godina = g;
    }
    std::string DajNaslov() const {return naslov;}
    std::string DajAutora() const {return pisac;}
    std::string DajZanr() const {return zanr;}
    int DajGodinuIzdavanja() const {return godina;}
    Korisnik* DajKodKogaJe() const {return zaduzio;}
    void ZaduziKnjigu(Korisnik &korisnik) {*zaduzio = korisnik;}
    void RazduziKnjigu() {*zaduzio = nullptr;}
    bool DaLiJeZaduzena() const {if(*zaduzio != nullprt) return true; else return false;} 
};

class Biblioteka{
    std::map<int, Korisnik*> korisnici;
    std::map<int, Knjiga*> knjige;
public:
    Biblioteka() {}
    Biblioteka(const Biblioteka &biblioteka) 
    {
        korisnici = biblioteka.korisnici; 
        knjige = biblioteka.knjige;
    }
    void RegistrirajNovogKorisnika(int br, std::string i, std::string p, std::string adr, std::string brt)
    {
        
    }
};

int main ()
{
	return 0;
}