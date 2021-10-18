/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <stdexcept>

struct Korisnik {
    std::string ime, prezime, adresa, telefon;
};
class Knjiga {
    std::string naslovKnjige, imePisca, zanr;
    int godinaIzdavanja;
    Korisnik *dugovaoc;
public:
    Knjiga(std::string naslov, std::string pisac, std::string genre, int godina) : dugovaoc {nullptr} {
        naslovKnjige = naslov;
        imePisca = pisac;
        zanr = genre;
        godinaIzdavanja = godina;
    }
    std::string DajNaslov () const {
        return naslovKnjige;
    }
    std::string DajAutora () const {
        return imePisca;
    }
    std::string DajZanr () const {
        return zanr;
    }
    int DajGodinuIzdavanja () const {
        return godinaIzdavanja;
    }
    Korisnik * DajKodKogaJe () const {
        return dugovaoc;
    }
    void ZaduziKnjigu (Korisnik & zaduzitelj) {
        dugovaoc = & zaduzitelj;
    }
    void RazduziKnjigu () {
        dugovaoc = nullptr;
    }
    bool DaLiJeZaduzena () {
        return dugovaoc != nullptr;
        //true  !nullptr, zaduzena je
        //false nullptr, nije zaduzena
    }
};

class Biblioteka {
    //U petljama koje trebaju da urade nesto sa svakim clanom koristim "x" kao ime posebnog korisnika
    // kao korisnik X ili knjiga X. Veoma mastovito ime
    std::map<int, Korisnik*> korisnici;
    std::map<int, Knjiga*> knjige;

    static void ispisiKorisnika(int evBroj, Korisnik k);
    static void ispisiKnjigu(int evBroj, Knjiga k, bool blaa);
public:
    Biblioteka() : korisnici(), knjige() {}
    Biblioteka(const Biblioteka & bib);
    /*
    //kopiranje, dodjeljivanje vec postojecih biblioteka novim sa dubokim kopiranjem
    //sve knjige se kopiraju a korisnici registriraju u novu biblioteku
    //veliki dogadjaj u gradu u kojem se otvara nova biblioteka
    //do sada su bili mali gradic sa samo jednom bibliotekom ali sada se otvorila nova
    //istina je da ima iste knjige kao i stara, ali svima je obecano da ce u buducnosti izbor postati veci
    //I sada svi hrle u novu bibliotekuu, ostavljajuci staru praznom
    //i tako se stara biblioteka zatvori, uniste se sve knjige u njoj i ovaj mali gradic ponovo ima samo jednu biblioteku
    //*/
    void RegistrirajNovogKorisnika (int clanskiBroj, std::string ime, std::string prezime, std::string adresa, std::string telefon);

    void RegistrirajNovuKnjigu (int evidencijskiBroj, std::string naslov, std::string pisac, std::string zanr, int godinaIzdavanja);
    ~Biblioteka();
    Korisnik & NadjiKorisnika (int clanskiBroj) const {
        if(korisnici.find(clanskiBroj) == korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
        return *korisnici.at(clanskiBroj);
    }
    Knjiga & NadjiKnjigu (int evidencijskiBroj) const {
        if(knjige.find(evidencijskiBroj) == knjige.end()) throw std::logic_error("Knjiga nije nadjena");
        return *knjige.at(evidencijskiBroj);
    }
    void IzlistajKorisnike () const;
    void IzlistajKnjige () const;
    void ZaduziKnjigu (int evBroj, int clBroj) {
        if(knjige.find(evBroj) == knjige.end()) throw std::logic_error("Knjiga nije nadjena");
        if(korisnici.find(clBroj) == korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
        if(knjige.at(evBroj) -> DaLiJeZaduzena()) throw std::logic_error("Knjiga vec zaduzena");
        knjige.at(evBroj) -> ZaduziKnjigu(*korisnici.at(clBroj));
    }
    void RazduziKnjigu (int evBroj) {
        if(knjige.find(evBroj) == knjige.end()) throw std::logic_error("Knjiga nije nadjena");
        if(!knjige.at(evBroj) -> DaLiJeZaduzena()) throw std::logic_error("Knjiga nije zaduzena");
        knjige.at(evBroj) -> RazduziKnjigu();
    }
    void PrikaziZaduzenja (int clBroj) const {
        if(korisnici.find(clBroj) == korisnici.end()) throw std::logic_error("Korisnik nije nadjen");

    }
};

void Biblioteka::RegistrirajNovogKorisnika (int clanskiBroj, std::string ime, std::string prezime, std::string adresa, std::string telefon) {
    //provjeriti da li ima vec korisnik sa istim clanskim brojem
    if(korisnici.find(clanskiBroj) != korisnici.end()) throw std::logic_error("Korisnik vec postoji");

    //postavljanje vrijednosti korisnika (knjigocitalaca)
    Korisnik * ptPomKorisnik(nullptr);
    ptPomKorisnik = new Korisnik;
    ptPomKorisnik->ime = ime;
    ptPomKorisnik->prezime = prezime;
    ptPomKorisnik->adresa = adresa;
    ptPomKorisnik->telefon = telefon;
    korisnici.insert(std::make_pair(clanskiBroj, ptPomKorisnik));
}
void Biblioteka::RegistrirajNovuKnjigu (int evidencijskiBroj, std::string naslov, std::string pisac, std::string zanr, int godinaIzdavanja) {
    if(knjige.find(evidencijskiBroj) != knjige.end()) throw std::logic_error("Knjiga vec postoji");

    Knjiga * ptPomKnjiga(nullptr);
    ptPomKnjiga = new Knjiga(naslov, pisac, zanr, godinaIzdavanja);
    knjige.insert(std::make_pair(evidencijskiBroj, ptPomKnjiga));
}
Biblioteka::~Biblioteka() {
    for(auto & x : korisnici) {
        delete x.second;
    }
    for(auto & x : knjige) {
        delete x.second;
    }
}
Biblioteka::Biblioteka(const Biblioteka & bib) : korisnici(), knjige() {
    for(auto x : bib.korisnici) {
        Korisnik * ptPomKorisnik = new Korisnik(*x.second);
        korisnici.insert(std::make_pair(x.first, ptPomKorisnik));
    }
    for(auto x : bib.knjige) {
        Knjiga * ptPomKnjiga = new Knjiga(*x.second);
        knjige.insert(std::make_pair(x.first, ptPomKnjiga));
    }
}

void Biblioteka::ispisiKorisnika(int evBroj, Korisnik k) {
    std::cout << "Clanski broj: " << evBroj << "\n";
    std::cout << "Ime i prezime: " << k.ime << " " << k.prezime << "\n";
    std::cout << "Adresa: " << k.adresa << "\n";
    std::cout << "Broj telefona: " << k.telefon << "\n";
}
void Biblioteka::IzlistajKorisnike () const {
    for(auto x : korisnici) {
        ispisiKorisnika(x.first, *x.second);
        std::cout << std::endl;
    }
}

void Biblioteka::ispisiKnjigu(int evBroj, Knjiga k, bool blaa) {
    std::cout << "Evidencijski broj: " << evBroj << "\n";
    std::cout << "Naslov: " << k.DajNaslov() << "\n";
    std::cout << "Pisac: " << k.DajAutora() << "\n";
    std::cout << "Zanr: " << k.DajZanr() << "\n";
    std::cout << "Godina izdavanja: " << k.DajGodinuIzdavanja() << "\n";
    if(blaa && k.DaLiJeZaduzena()) {
        std::cout << "Zaduzena kod korisnika: " << k.DajKodKogaJe()->ime << " " << k.DajKodKogaJe()->prezime << "\n";
    }
}
void Biblioteka::IzlistajKnjige () const {
    for(auto x : knjige) {
        ispisiKnjigu(x.first, *x.second, true);
        std::cout << std::endl;
    }
}

int main () {
    Biblioteka test();
    for(;;) {
        std::cout << "Odaberite opciju: \n";
        std::cout << "1. Registriraj Novog Korisnika\n";
        std::cout << "2. Registriraj Novu Knjigu\n";
        std::cout << "3. Nadji Korisnika\n";
        std::cout << "4. Nadji Knjigu\n";
        std::cout << "5. Izlistaj Korisnike\n";
        std::cout << "6. Izlistaj Knjige\n";
        std::cout << "7. Zaduzi Knjigu\n";
        std::cout << "8. Razduzi Knjigu\n";
        std::cout << "9. Prikazi Zaduzenja\n";
        std::cout << "0. Kraj\n";
        int broj;
        std::cin >> broj;
        if(broj == 0) break;
    }
    return 0;
}