/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <string>
#include <memory>
#include <map>
using namespace std;

struct Korisnik {
    string ime, prezime, adresa, telefon;
};

class Knjiga
{
    string naslov, ime_pisca, zanr;
    int godina_izdanja;
    shared_ptr<Korisnik> kod_koga_je;
public:
    Knjiga(string ime, string pisac, string zanr_knjige, int godina_izdavanja): naslov(ime), ime_pisca(pisac), zanr(zanr_knjige), godina_izdanja(godina_izdavanja), kod_koga_je(nullptr) {}
    string DajNaslov() const {
        return naslov;
    }
    string DajAutora() const {
        return ime_pisca;
    }
    string DajZanr() const {
        return zanr;
    }
    int DajGodinuIzdavanja() const {
        return godina_izdanja;
    }
    shared_ptr<Korisnik> DajKodKogaJe() const {
        return kod_koga_je;
    }
    void ZaduziKnjigu(Korisnik &osoba) {
        kod_koga_je = make_shared<Korisnik>(osoba);
    }
    void RazduziKnjigu() {
        kod_koga_je = nullptr;
    }
    bool DaLiJeZaduzena() const {
        if(kod_koga_je == nullptr) return false;
        return true;
    }
};

class Biblioteka
{
    map<int, shared_ptr<Korisnik>> mapa_korisnika;
    map<int, shared_ptr<Knjiga>> mapa_knjiga;
public:
    Biblioteka() = default;
    ~Biblioteka() = default;
    Biblioteka(const Biblioteka &original) {
        auto korisnici = original.mapa_korisnika;
        auto knjige = original.mapa_knjiga;
        for(auto it = korisnici.begin(); it != korisnici.end(); it++) {
            it->second = nullptr;
        }
        for(auto it = knjige.begin(); it != knjige.end(); it++) {
            it->second = nullptr;
        }
        auto it_originala = original.mapa_korisnika.begin();
        for(auto it_kopije = korisnici.begin(); it_kopije != korisnici.end(); it_kopije++) {
            it_kopije->second = make_shared<Korisnik>(*(it_originala->second));
            it_originala++;
        }
        auto it_original = original.mapa_knjiga.begin();
        for(auto it_kopije = knjige.begin(); it_kopije != knjige.end(); it_kopije++) {
            it_kopije->second = make_shared<Knjiga>(*(it_original->second));
            it_original++;
        }
        mapa_korisnika = korisnici;
        mapa_knjiga = knjige;
    }
    Biblioteka(Biblioteka &&original) {
        mapa_korisnika = original.mapa_korisnika;
        mapa_knjiga = original.mapa_knjiga;
        for(auto it = original.mapa_korisnika.begin(); it != original.mapa_korisnika.end(); it++) {
            it->second = nullptr;
        }
        for(auto it = original.mapa_knjiga.begin(); it != original.mapa_knjiga.end(); it++) {
            it->second = nullptr;
        }
    }
    Biblioteka &operator =(const Biblioteka &original) {
        auto korisnici = original.mapa_korisnika;
        auto knjige = original.mapa_knjiga;
        for(auto it = korisnici.begin(); it != korisnici.end(); it++) {
            it->second = nullptr;
        }
        for(auto it = knjige.begin(); it != knjige.end(); it++) {
            it->second = nullptr;
        }
        auto it_originala = original.mapa_korisnika.begin();
        for(auto it_kopije = korisnici.begin(); it_kopije != korisnici.end(); it_kopije++) {
            it_kopije->second = make_shared<Korisnik>(*(it_originala->second));
            it_originala++;
        }
        auto it_original = original.mapa_knjiga.begin();
        for(auto it_kopije = knjige.begin(); it_kopije != knjige.end(); it_kopije++) {
            it_kopije->second = make_shared<Knjiga>(*(it_original->second));
            it_original++;
        }
        mapa_korisnika = korisnici;
        mapa_knjiga = knjige;
        return *this;
    }
    Biblioteka &operator =(Biblioteka &&original) {
        mapa_korisnika = original.mapa_korisnika;
        mapa_knjiga = original.mapa_knjiga;
        
        for(auto it = original.mapa_korisnika.begin(); it != original.mapa_korisnika.end(); it++) {
            it->second = nullptr;
        }
        for(auto it = original.mapa_knjiga.begin(); it != original.mapa_knjiga.end(); it++) {
            it->second = nullptr;
        }
        return *this;
    }
    
    void RegistrirajNovogKorisnika(int clanski_broj, string ime, string prezime, string adresa, string telefon) {
        for(auto a: mapa_korisnika)
            if(a.first == clanski_broj) throw logic_error("Korisnik vec postoji");
        Korisnik neki_korisnik;
        neki_korisnik.ime = ime;
        neki_korisnik.prezime = prezime;
        neki_korisnik.adresa = adresa;
        neki_korisnik.telefon = telefon;
        shared_ptr<Korisnik> korisnik = make_shared<Korisnik>(neki_korisnik);
        mapa_korisnika.insert(make_pair(clanski_broj, make_shared<Korisnik>(neki_korisnik)));
    }

    void RegistrirajNovuKnjigu(int evidencijski_broj, string naslov, string pisac, string zanr, int godina_izdanja) {
        for(auto a: mapa_knjiga)
            if(a.first == evidencijski_broj) throw logic_error("Knjiga vec postoji");
        mapa_knjiga.insert(make_pair(evidencijski_broj, nullptr));
        mapa_knjiga[evidencijski_broj] = make_shared<Knjiga>(naslov, pisac, zanr, godina_izdanja);
    }

    Korisnik &NadjiKorisnika(int clanski_broj) const {
        for(auto &a: mapa_korisnika)
            if(a.first == clanski_broj) return *(a.second); //return mapa_korisnika[clanski_broj];
        throw logic_error("Korisnik nije nadjen");
    }
    Knjiga &NadjiKnjigu(int evidencijski_broj) {
        for(auto &a: mapa_knjiga)
            if(a.first == evidencijski_broj) return *(a.second); //return mapa_knjiga[evidencijski_broj];
        throw logic_error("Knjiga nije nadjena");
    }

    void IzlistajKorisnike() const {
        for(auto it = mapa_korisnika.begin(); it != mapa_korisnika.end(); it++) {
            cout << "Clanski broj: " << it -> first << endl;
            cout << "Ime i prezime: " << (it->second) -> ime  << " " << (it -> second) -> prezime << endl;
            cout << "Adresa: " << (it -> second) -> adresa << endl;
            cout << "Broj telefona: " << (it -> second) -> telefon << endl;
            cout << endl;
        }
    }

    void IzlistajKnjige() const {
        for(auto it = mapa_knjiga.begin(); it != mapa_knjiga.end(); it++) {
            cout << "Evidencijski broj: " << it -> first << endl;
            cout << "Naslov: " << (*(it->second)).DajNaslov() << endl;
            cout << "Pisac: " << (*(it -> second)).DajAutora() << endl;
            cout << "Zanr: " << (*(it -> second)).DajZanr() << endl;
            cout << "Godina izdavanja: " << (*(it -> second)).DajGodinuIzdavanja() << endl;
            if((*(it -> second)).DaLiJeZaduzena() == true) {
                shared_ptr<Korisnik> kod_koga_je_trenutno = (*(it -> second)).DajKodKogaJe();
                cout << "Zaduzena kod korisnika: " << kod_koga_je_trenutno -> ime << " " << kod_koga_je_trenutno -> prezime << endl;
            }
            cout << endl;
        }
    }

    void ZaduziKnjigu(int evidencijski_broj, int clanski_broj) {
        Knjiga &knjiga = NadjiKnjigu(evidencijski_broj);
        Korisnik &korisnik = NadjiKorisnika(clanski_broj);
        if(knjiga.DaLiJeZaduzena())
            throw logic_error("Knjiga vec zaduzena");
        knjiga.ZaduziKnjigu(korisnik);
    }

    void RazduziKnjigu(int evidencijski_broj) {
        Knjiga &knjiga = NadjiKnjigu(evidencijski_broj);
        if(knjiga.DaLiJeZaduzena() == false)
            throw logic_error("Knjiga nije zaduzena");
        knjiga.RazduziKnjigu();
    }
    
    void PrikaziZaduzenja(int clanski_broj) const {
        auto korisnik = mapa_korisnika.find(clanski_broj);
        if(korisnik == mapa_korisnika.end())
            throw logic_error("Korisnik nije nadjen");
        bool nema_zaduzenja = true;
        for(auto a = mapa_knjiga.begin(); a != mapa_knjiga.end(); a++) {
            if((*(a->second)).DajKodKogaJe() == (korisnik -> second)) {
                nema_zaduzenja = false;
                cout << "Evidencijski broj: " << a -> first << endl << "Naslov: " << (*(a -> second)).DajNaslov() << endl << "Pisac: " << (*(a -> second)).DajAutora() << endl << "Zanr: " << (*(a -> second)).DajZanr() << endl 
                << "Godina izdavanja: " << (*(a->second)).DajGodinuIzdavanja() << endl;
                cout << endl;
            }
        }
        if(nema_zaduzenja) cout << "Nema zaduzenja za tog korisnika!" << endl;
    }

};
int main ()
{
    return 0;
}