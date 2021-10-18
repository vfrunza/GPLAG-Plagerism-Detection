/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise

#include <iostream>
#include <string>
#include <map>

using std::string;
using std::map;
using std::bad_alloc;
using std::swap;
using std::logic_error;
using std::cout;
using std::cin;
using std::endl;

struct Korisnik {
    string ime, prezime, adresa, telefon;
};

class Knjiga {
    string naslov, pisac, zanr;
    int godina_izdavanja;
    Korisnik *zaduzili;
    
    public :
        // treba li umjesto string const char ili nesto?
        Knjiga(string naslov, string pisac, string zanr, int godina) : naslov(naslov),
            pisac(pisac), zanr(zanr), godina_izdavanja(godina), zaduzili(nullptr) {};
        
        string DajNaslov() const { return naslov; }
        string DajAutora() const { return pisac; }
        string DajZanr() const { return zanr; }
        int DajGodinuIzdavanja() const { return godina_izdavanja; }
        Korisnik *DajKodKogaJe() const { return zaduzili; }
        
        void ZaduziKnjigu(Korisnik &korisnik) { zaduzili = &korisnik; }
        void RazduziKnjigu() { zaduzili = nullptr; }
        bool DaLiJeZaduzena() const { return zaduzili; }

};

class Biblioteka {
    map<int, Knjiga*> knjige;
    map<int, Korisnik*> korisnici;
    
    public:
        Biblioteka() {};
        Biblioteka(const Biblioteka &b);
        Biblioteka(Biblioteka &&b);
        ~Biblioteka();
        
        Biblioteka &operator=(const Biblioteka &b);
        Biblioteka &operator=(Biblioteka &&b);
        
        void RegistrirajNovogKorisnika(int clanski_broj, string ime, string prezime,
            string adresa, string telefon);
        void RegistrirajNovuKnjigu(int evidencijski_broj, string naslov, string pisac,
            string zanr, int godina);
        
        Korisnik &NadjiKorisnika(int clanski_broj);
        Knjiga &NadjiKnjigu(int evidencijski_broj);
        void IzlistajKorisnike() const;
        void IzlistajKnjige() const;
        void ZaduziKnjigu(int evidencijski_broj, int clanski_broj);
        void RazduziKnjigu(int evidencijski_broj);
        void PrikaziZaduzenja(int clanski_broj) const;
};

Biblioteka::Biblioteka(const Biblioteka &b)
{
    // Pravimo duboku kopiju knjiga
    for(auto it = b.knjige.begin(); it != b.knjige.end(); it++) {
        try {
            auto pok = new Knjiga(*it->second);
            knjige[it->first] = pok;
        } catch (bad_alloc &e) {
            // Brisemo alocirane objekte
            for (auto it2 = b.knjige.begin(); it2 != it; it++) {
                delete knjige[it->first];
            }
            knjige = map<int, Knjiga*>();
            throw;
        }
    }
    // Pravimo duboku kopiju korisnika
    for(auto it = b.korisnici.begin(); it != b.korisnici.end(); it++) {
        try {
            auto pok = new Korisnik(*it->second);
            korisnici[it->first] = pok;
            // kao kod knjiga
        } catch (bad_alloc &e) {
            // Brisemo alocirane objekte
            for(auto it1 = b.knjige.begin(); it1 != b.knjige.end(); it1++) {
                delete knjige[it->first];
            }
            knjige = map<int, Knjiga*>();
            for (auto it2 = b.korisnici.begin(); it2 != it; it++) {
                delete korisnici[it->first];
            }
            korisnici = map<int, Korisnik*>();
            throw;
        }
    }
}

Biblioteka::Biblioteka(Biblioteka &&b)
{
    if(&b != this) {
        knjige = b.knjige;
        b.knjige = map<int, Knjiga*>(); // Ili b.knjige.clear() ?, treba li nam ista uopce?
        korisnici = b.korisnici;
        b.korisnici = map<int, Korisnik*>();
    }
}

Biblioteka::~Biblioteka()
{
    for(auto it = knjige.begin(); it != knjige.end(); it++)
        delete it->second;
    for(auto it = korisnici.begin(); it != korisnici.end(); it++)
        delete it->second;
}

Biblioteka &Biblioteka::operator=(const Biblioteka &b)
{
    // Provjera, da izbjegnemo mnogo nepotrebnih radnji
    if (this == &b)
        return *this;
    // Pokusavamo alokaciju novih knjiga, duboka kopija
    map<int, Knjiga*> temp1;
    for(auto it = b.knjige.begin(); it != b.knjige.end(); it++) {
        try {
            temp1[it->first] = new Knjiga(*it->second);
        } catch (bad_alloc &e) {
            for (auto it2 = b.knjige.begin(); it2 != it; it++) {
                delete temp1[it->first];
            }
            throw;
        }
    }
    // Ako je uspjela, vrsimo dealokaciju prethodnih knjiga i dodjelu novih
    for(auto it = knjige.begin(); it != knjige.end(); it++)
        delete it->second;
    knjige = temp1; // Ispitati da li ovo unistava stare indekse kojih nema u b.knjige
    
    // Pokusavamo alokaciju novih korisnika, duboka kopija
    map<int, Korisnik*> temp2;
    for(auto it = b.korisnici.begin(); it != b.korisnici.end(); it++) {
        try {
            temp2[it->first] = new Korisnik(*it->second);
        } catch (bad_alloc &e) {
            for (auto it2 = b.korisnici.begin(); it2 != it; it++) {
                delete temp2[it->first];
            }
            throw;
        }
    }
    // Ako je uspjela, vrsimo dealokaciju prethodnih korisnika i dodjelu novih
    for(auto it = korisnici.begin(); it != korisnici.end(); it++)
        delete it->second;
    korisnici= temp2;
    
    return *this;
}

Biblioteka &Biblioteka::operator=(Biblioteka &&b)
{
    // Da izbjegnemo destruktivnu samododjelu
    if (this == &b)
        return *this;
    // Vrsimo dealokaciju prethodnih knjiga i korisnika
    for(auto it = knjige.begin(); it != knjige.end(); it++)
        delete it->second;
    for(auto it = korisnici.begin(); it != korisnici.end(); it++)
        delete it->second;
    
    // Preuzimamo
    knjige = b.knjige;
    korisnici = b.korisnici;
    
    return *this;
}

void Biblioteka::RegistrirajNovogKorisnika(int clanski_broj, string ime, string prezime,
        string adresa, string telefon)
{
    if(korisnici.count(clanski_broj))
        throw logic_error("Korisnik vec postoji");
    
    Korisnik *pok;
    try {
        pok = new Korisnik{ime, prezime, adresa, telefon}; // Kako ovo radi? (Da li radi ono sto hocemo)
        korisnici[clanski_broj] = pok;
    } catch(bad_alloc &e) {
        throw;
    }
}

void Biblioteka::RegistrirajNovuKnjigu(int evidencijski_broj, string naslov, string pisac,
            string zanr, int godina)
{
    if(knjige.count(evidencijski_broj))
        throw logic_error("Knjiga vec postoji");
    
    Knjiga *pok;
    try {
        pok = new Knjiga{naslov, pisac, zanr, godina}; // Kao i gore
        knjige[evidencijski_broj] = pok;
    } catch(bad_alloc &e) {
        throw;
    }
}

Korisnik &Biblioteka::NadjiKorisnika(int clanski_broj)
{
    if(korisnici.count(clanski_broj))
        return *korisnici[clanski_broj];
    else
        throw logic_error("Korisnik nije nadjen");
}

Knjiga &Biblioteka::NadjiKnjigu(int evidencijski_broj)
{
    if(knjige.count(evidencijski_broj))
        return *knjige[evidencijski_broj];
    else
        throw logic_error("Knjiga nije nadjena");
}

void Biblioteka::IzlistajKorisnike() const
{
    Korisnik *pok;
    for(auto it = korisnici.begin(); it != korisnici.end(); it++) {
        pok = it->second;
        cout << "Clanski broj: " << it->first << endl <<
            "Ime i prezime: " << pok->ime << " " << pok->prezime << endl <<
            "Adresa: " << pok->adresa << endl <<
            "Broj telefona: " << pok->telefon << endl << endl; //endl tek ako ima jos jedan?
    }
}

void Ispisi(string naslov, string pisac, string zanr, int godina)
{
    cout << "Naslov: " << naslov << endl << "Pisac: " << pisac << endl << "Zanr: "
        << zanr << endl << "Godina izdavanja: " << godina << endl;
}

void Biblioteka::IzlistajKnjige() const
{
    Knjiga *pok;
    for(auto it = knjige.begin(); it != knjige.end(); it++) {
        pok = it->second;
        cout << "Evidencijski broj: " << it->first << endl;
        Ispisi(pok->DajNaslov(), pok-> DajAutora(), pok->DajZanr(), pok->DajGodinuIzdavanja());
        if (pok->DaLiJeZaduzena())
            cout << "Zaduzena kod korisnika: " << pok->DajKodKogaJe()->ime <<
                " " << pok->DajKodKogaJe()->prezime;
        cout << endl;
    }
}

void Biblioteka::PrikaziZaduzenja(int clanski_broj) const
{
    if(!korisnici.count(clanski_broj))
        throw logic_error("Korisnik nije nadjen");
    Korisnik *pok_korisnik(korisnici.find(clanski_broj)->second);
    
    Knjiga *pok_knjiga;
    for(auto it = knjige.begin(); it != knjige.end(); it++) {
        pok_knjiga = it->second;
        if (pok_knjiga->DajKodKogaJe() == pok_korisnik) { // Korisnik posudio knjigu
            Ispisi(pok_knjiga->DajNaslov(), pok_knjiga-> DajAutora(), pok_knjiga->DajZanr(),
                pok_knjiga->DajGodinuIzdavanja());
            cout << endl;
        }
    }
}

void Biblioteka::ZaduziKnjigu(int evidencijski_broj, int clanski_broj)
{
    if(!knjige.count(evidencijski_broj))
        throw logic_error("Knjiga nije nadjena");
    else if(knjige[evidencijski_broj]->DaLiJeZaduzena())
        throw logic_error("Knjiga vec zaduzena");
    else if(!korisnici.count(clanski_broj)) // Da li ovi redosljedom?
        throw logic_error("Korisnik nije nadjen");
    else
        knjige[evidencijski_broj]->ZaduziKnjigu(*korisnici[clanski_broj]);
}

void Biblioteka::RazduziKnjigu(int evidencijski_broj)
{
    if(!knjige.count(evidencijski_broj))
        throw logic_error("Knjiga nije nadjena");
    else if(!knjige[evidencijski_broj]->DaLiJeZaduzena())
        throw logic_error("Knjiga nije zaduzena");
    else {
        knjige[evidencijski_broj]->RazduziKnjigu();
    }
}


int main ()
{
    string meni = "Izaberite opciju: Uclanite se(1), Registrirajte knjigu(2), "
        "Pronadjite korisnika(3), Pronadjite knjigu(4), Izlistavanje korisnika(5)\n"
        "Izlistavanje knjiga(6), Zaduzite knjigu(7), Razduzite knjigu(8), "
        "Prikaz zaduzenja(9), Izlaz(0). ";
    
    Biblioteka bib;
    int opcija(0), zadnji_evidencijski_broj(0);
    do {
        cout << meni;
        cin >> opcija;
        cin.ignore(10000, '\n');
        if (opcija == 1) {
            string ime, prezime, adresa, telefon;
            cout << "Unesite ime, prezime, adresu i telefon (svako polje u jednom redu): ";
            getline(cin, ime); getline(cin, prezime); getline(cin, adresa); getline(cin, telefon);
            try {
                bib.RegistrirajNovogKorisnika(1, ime, prezime, adresa, telefon);
                cout << "\nUspjesno ste se uclanili";
            } catch(logic_error &e) {
                cout << e.what();
            }
        } else if (opcija == 2) {
            string naslov, pisac, zanr;
            int godina;
            cout << "Unesite naslov, ime autora, zanr i godinu (svako polje ujednom redu): ";
            getline(cin, naslov); getline(cin, pisac); getline(cin, zanr);
            cin >> godina;
            cin.ignore(10000, '\n');
            try {
                bib.RegistrirajNovuKnjigu(zadnji_evidencijski_broj + 1, naslov, pisac, zanr, godina);
                cout << "\nUspjesna registracija knjige";
                zadnji_evidencijski_broj++;
            } catch(logic_error &e) {
                cout << e.what();
            }
        } else if (opcija == 3) {
            int clanski_broj;
            cout << "Unesite clanski broj korisnika: ";
            cin >> clanski_broj;
            cin.ignore(10000, '\n');
            try {
                Korisnik kor(bib.NadjiKorisnika(clanski_broj));
                cout << "\nIme i prezime: " << kor.ime << " " << kor.prezime;
                cout << " Adresa: " << kor.adresa << " Telefon: " << kor.telefon;
            } catch(logic_error &e) {
                cout << e.what();
            }
        } else if (opcija == 4) {
            int evidencijski_broj;
            cout << "Unesite evidencijski broj knjiga: ";
            cin >> evidencijski_broj;
            cin.ignore(10000, '\n');
            try {
                Knjiga knj(bib.NadjiKnjigu(evidencijski_broj));
                cout << "\nNaslov: " << knj.DajNaslov() << " Autor: " << knj.DajAutora();
                cout << " Zanr: " << knj.DajZanr() << " Godina izdavanja: " << knj.DajGodinuIzdavanja();
            } catch(logic_error &e) {
                cout << e.what();
            }
        } else if (opcija == 5) {
            bib.IzlistajKorisnike();
        } else if (opcija == 6) {
            bib.IzlistajKnjige();
        } else if (opcija == 7) {
            int evidencijski_broj;
            cout << "Unesite evidencijski broj: ";
            cin >> evidencijski_broj;
            cin.ignore(10000, '\n');
            try {
                bib.ZaduziKnjigu(evidencijski_broj, 1);
                cout << "\nUspjesno ste zaduzili knjigu";
            } catch(logic_error &e) {
                cout << e.what();
            }
        } else if (opcija == 8) {
            int evidencijski_broj;
            cout << "Unesite evidencijski broj";
            cin >> evidencijski_broj;
            cin.ignore(10000, '\n');
            try {
                bib.RazduziKnjigu(evidencijski_broj);
                cout << "Knjiga razduzena";
            } catch(logic_error &e) {
                cout << e.what();
            }
        } else if (opcija == 9) {
            bib.PrikaziZaduzenja(1);
        } else if (opcija == 0) {
            cout << "Dovidjenja!";
        } else {
            cout << "Nepravilan unos!";
        }
        cout << "\n";
    } while (opcija);
	return 0;
}