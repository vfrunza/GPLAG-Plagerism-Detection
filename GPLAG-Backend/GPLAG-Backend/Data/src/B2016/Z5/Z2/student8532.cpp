/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include <algorithm>
#include <memory>

using namespace std;

struct Korisnik {
    string ime, prezime, adresa, telefon;
};

class Knjiga {
    string naslov, pisac, zanr;
    int godinaIzdavanja;
    Korisnik* korisnik;
public:
    Knjiga(string naslov, string pisac, string zanr, int godinaIzdavanja) :
        naslov(naslov), pisac(pisac), zanr(zanr), godinaIzdavanja(godinaIzdavanja), korisnik(nullptr) { }
    string DajNaslov() const { return naslov; }
    string DajAutora() const { return pisac; }
    string DajZanr() const { return zanr; }
    int DajGodinuIzdavanja() const { return godinaIzdavanja; }
    Korisnik * DajKodKogaJe() const { return korisnik; }
    void ZaduziKnjigu(Korisnik& k) { /*provjera ? */ korisnik = &k; }
    void RazduziKnjigu() { korisnik = nullptr; }
    bool DaLiJeZaduzena() const { return korisnik ? true : false; }
};

class Biblioteka {
    map<int, shared_ptr<Korisnik>> korisnici;
    map<int, shared_ptr<Knjiga>> knjige;
    void Dealociraj();
public:
    explicit Biblioteka() : korisnici(), knjige() { }
    Biblioteka(const Biblioteka&);
    Biblioteka(Biblioteka&&);
    Biblioteka& operator=(const Biblioteka&);
    Biblioteka& operator=(Biblioteka&&);
    ~Biblioteka() { Dealociraj(); }
    void RegistrirajNovogKorisnika(int, string, string, string, string);
    void RegistrirajNovuKnjigu(int, string, string, string, int);
    Korisnik& NadjiKorisnika(int) const;
    Knjiga& NadjiKnjigu(int) const;
    void IzlistajKorisnike() const;
    void IzlistajKnjige() const;
    void ZaduziKnjigu(int, int);
    void RazduziKnjigu(int);
    void PrikaziZaduzenja(int) const;
};

void Biblioteka::Dealociraj() {
    korisnici.clear();
    knjige.clear();
}

Biblioteka::Biblioteka(const Biblioteka& b){
    Dealociraj();
    for(auto korisnik : b.korisnici)
        korisnici[korisnik.first] = make_shared<Korisnik>(*(korisnik.second));
    for(auto knjiga : b.knjige)
        knjige[knjiga.first] = make_shared<Knjiga>(*(knjiga.second));
}

Biblioteka& Biblioteka::operator=(const Biblioteka& b){
    if(this != &b){
        Dealociraj();
        for(auto korisnik : b.korisnici)
            korisnici[korisnik.first] = make_shared<Korisnik>(*(korisnik.second));
        for(auto knjiga : b.knjige)
            knjige[knjiga.first] = make_shared<Knjiga>(*(knjiga.second));
    }
    return *this;
}

Biblioteka::Biblioteka(Biblioteka&& b){
    Dealociraj();
    for(auto korisnik : b.korisnici)
        korisnici[korisnik.first] = korisnik.second, korisnik.second = nullptr;
    for(auto knjiga : b.knjige)
        knjige[knjiga.first] = knjiga.second, knjiga.second = nullptr;
}

Biblioteka& Biblioteka::operator=(Biblioteka&& b){
    if(this != &b){
        Dealociraj();
        for(auto korisnik : b.korisnici)
            korisnici[korisnik.first] = korisnik.second, korisnik.second = nullptr;
        for(auto knjiga : b.knjige)
            knjige[knjiga.first] = knjiga.second, knjiga.second = nullptr;
    }
    return *this;
}

void Biblioteka::RegistrirajNovogKorisnika(int id, string ime, string prezime, string adresa, string telefon){
    auto it = find_if(korisnici.begin(), korisnici.end(), [id](pair<int, shared_ptr<Korisnik>> k) {
        return k.first == id;
    });
    if(it != korisnici.end())
        throw logic_error("Korisnik vec postoji");
    Korisnik k;
    k.ime = ime;
    k.prezime = prezime;
    k.adresa = adresa;
    k.telefon = telefon;
    korisnici[id] = make_shared<Korisnik>(k);
}

void Biblioteka::RegistrirajNovuKnjigu(int id, string naslov, string autor, string zanr, int godinaIzdavanja){
    auto it = find_if(knjige.begin(), knjige.end(), [id](pair<int, shared_ptr<Knjiga>> k) {
        return k.first == id;
    });
    if(it != knjige.end())
        throw logic_error("Knjiga vec postoji");
    knjige[id] = make_shared<Knjiga>(naslov, autor, zanr, godinaIzdavanja);
}

Korisnik& Biblioteka::NadjiKorisnika(int id) const {
    auto it = korisnici.find(id);
    if(it == korisnici.end()) 
        throw logic_error("Korisnik nije nadjen");
    return *(it->second.get());
}

Knjiga& Biblioteka::NadjiKnjigu(int id) const {
    auto it = knjige.find(id);
    if(it == knjige.end())
        throw logic_error("Knjiga nije nadjena");
    return *(it->second.get());
}

void Biblioteka::IzlistajKorisnike() const {
    for(auto k : korisnici){
        cout << "Clanski broj: " << k.first << endl;
        cout << "Ime i prezime: " << k.second->ime << " " << k.second->prezime << endl;
        cout << "Adresa: " << k.second->adresa << endl;
        cout << "Broj telefona: " << k.second->telefon << endl << endl;
    }
} 

void Biblioteka::IzlistajKnjige() const {
    for(auto k : knjige){
        cout << "Evidencijski broj: " << k.first << endl;
        cout << "Naslov: " << k.second->DajNaslov() << endl;
        cout << "Pisac: " << k.second->DajAutora() << endl;
        cout << "Zanr: " << k.second->DajZanr() << endl;
        cout << "Godina izdavanja: " << k.second->DajGodinuIzdavanja() << endl;
        if(k.second->DaLiJeZaduzena())
            cout << "Zaduzena kod korisnika: " << k.second->DajKodKogaJe()->ime << " " << k.second->DajKodKogaJe()->prezime << endl;
        cout << endl;
    }
}

void Biblioteka::ZaduziKnjigu(int idKnjige, int idKorisnika){
    Knjiga &knjiga = NadjiKnjigu(idKnjige);
    Korisnik &korisnik = NadjiKorisnika(idKorisnika);
    if(knjiga.DaLiJeZaduzena()) 
        throw logic_error("Knjiga vec zaduzena");
    knjiga.ZaduziKnjigu(korisnik);
}

void Biblioteka::RazduziKnjigu(int id) {
    Knjiga &knjiga = NadjiKnjigu(id);
    if(!knjiga.DaLiJeZaduzena()) 
        throw logic_error("Knjiga nije zaduzena");
    knjiga.RazduziKnjigu();
}

void Biblioteka::PrikaziZaduzenja(int id) const {
    Korisnik &k = NadjiKorisnika(id);
    bool imaZaduzenja(false);
    for(auto knjiga : knjige){
        if(knjiga.second->DajKodKogaJe() == &k){
            cout << "Evidencijski broj: " << knjiga.first << endl;
            cout << "Naslov: " << knjiga.second->DajNaslov() << endl;
            cout << "Pisac: " << knjiga.second->DajAutora() << endl;
            cout << "Zanr: " << knjiga.second->DajZanr() << endl;
            cout << "Godina izdavanja: " << knjiga.second->DajGodinuIzdavanja() << endl << endl;
            imaZaduzenja = true;
        }
    }
    if(!imaZaduzenja)
        cout << "Nema zaduzenja za tog korisnika!" << endl;
}

int main ()
{
    try{
    Biblioteka b;
    b.RegistrirajNovogKorisnika(0, "Seno", "Sejdic", "neka adresa", "broj telefona");
    b.RegistrirajNovogKorisnika(5, "Neko", "Nekic", "nekina adresa", "neki broj");
    b.RegistrirajNovuKnjigu(0, "neka knjiga", "neki autor", "neki zanr", 1859);
    b.ZaduziKnjigu(0, 5);
    b.ZaduziKnjigu(0, 0);
    b.IzlistajKnjige();
    b.IzlistajKorisnike();
    cout << "-------------------" << endl;
    b.PrikaziZaduzenja(0);
    
    Biblioteka b2(b);
    cout << "-------------------------------------------------------------------" << endl;
    b2.RazduziKnjigu(0);
    b2.IzlistajKnjige();
    b2.IzlistajKorisnike();
    b2.PrikaziZaduzenja(0);
    }catch(exception &e){
        cout << e.what() << endl;
    }
	return 0;
}