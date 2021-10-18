/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <iostream>
#include <string>
#include <memory>
#include <stdexcept>
#include <vector>

using namespace std;

struct Korisnik {
    int korisnicki_broj;
    string ime, prezime, adresa, telefon;
public:
    Korisnik(string ime, string prezime, string adresa, string telefon){
        Korisnik::ime = ime; Korisnik::prezime = prezime; Korisnik::adresa = adresa; Korisnik::telefon = telefon;
    }
    Korisnik (int korisnicki_broj, string ime, string prezime, string adresa, string telefon) {
        Korisnik::korisnicki_broj = korisnicki_broj; Korisnik::ime = ime; Korisnik::prezime = prezime; Korisnik::adresa = adresa; Korisnik::telefon = telefon;
    }
    int DajEvidencijskiBroj() const { return korisnicki_broj; }
    string DajIme() const { return ime; }
    string DajPrezime() const { return prezime; }
    string DajAdresu() const { return adresa; }
    string DajTelefon() const { return telefon; }
    void Ispisi() const {
        cout << "Clanski broj: " << korisnicki_broj << endl;
        cout << "Ime i prezime: " << ime << " " << prezime << endl;
        cout << "Adresa: " << adresa << endl;
        cout << "Broj telefona: " << telefon <<"\n"<< endl;
    }
};
class Knjiga {
    string naslov, ime_pisca, zanr;
    int evidencijski_broj, godina_izdavanja;
    Korisnik* zaduzenje;
public:
    Knjiga(string naslov, string ime_pisca, string zanr, int godina_izdavanja){
        Knjiga::naslov = naslov; Knjiga::ime_pisca = ime_pisca; Knjiga::zanr = zanr;
    Knjiga::godina_izdavanja = godina_izdavanja;
    zaduzenje = nullptr;
    }
    Knjiga(int evidencijski_broj, string naslov, string ime_pisca, string zanr, int godina_izdavanja) {
    Knjiga::evidencijski_broj = evidencijski_broj; Knjiga::naslov = naslov; Knjiga::ime_pisca = ime_pisca; Knjiga::zanr = zanr;
    Knjiga::godina_izdavanja = godina_izdavanja;
    zaduzenje = nullptr;
    }
    int DajEvidencijskiBroj() const { return evidencijski_broj; }
    string DajNaslov() const { return naslov; }
    string DajAutora() const { return ime_pisca; }
    string DajZanr() const { return zanr; }
    int DajGodinuIzdavanja() const { return godina_izdavanja; }
    Korisnik* DajKodKogaJe() {
        return zaduzenje;
    }
    void ZaduziKnjigu(Korisnik &korisnik) {
        zaduzenje=&korisnik;
    }
    void RazduziKnjigu() {
        zaduzenje = nullptr;
    }
    bool DaLiJeZaduzena() { if(zaduzenje == nullptr) return false; return true;}
    void Ispisi() const {
        cout << "Evidencijski broj: " << evidencijski_broj << endl;
        cout << "Naslov: " << naslov << endl;
        cout << "Pisac: " << ime_pisca << endl;
        cout << "Zanr: " << zanr << endl;
        cout << "Godina izdavanja: " << godina_izdavanja << endl;
    }
};

class Biblioteka {
    vector<shared_ptr<Korisnik>> Korisnici;
    vector<shared_ptr<Knjiga>> Knjige;
public:
    Biblioteka() = default;
    Biblioteka(const Biblioteka &b) = delete;
    Biblioteka &operator = (const Biblioteka &b) = delete;
    void RegistrirajNovogKorisnika (int korisnicki_broj, string ime, string prezime, string adresa, string broj_telefona) {
        for(int i(0); i<int(Korisnici.size()); i++)
            if(Korisnici[i]->DajEvidencijskiBroj() == korisnicki_broj)
                throw domain_error ("Korisnik vec postoji\n");
        Korisnici.emplace_back(make_shared<Korisnik>(korisnicki_broj, ime, prezime, adresa, broj_telefona));
    }
    void RegistrirajNovuKnjigu (int evidencijski_broj, string naslov, string ime_pisca, string zanr, int godina_izdavanja) {
        for(int i(0); i<int(Knjige.size()); i++)
            if(Knjige[i]->DajEvidencijskiBroj() == evidencijski_broj)
                throw domain_error ("Knjiga vec postoji\n");
        Knjige.emplace_back(make_shared<Knjiga>(evidencijski_broj, naslov, ime_pisca, zanr, godina_izdavanja));
    }
    Korisnik& NadjiKorisnika(int evidencijski_broj) const;
    Knjiga& NadjiKnjigu(int evidencijski_broj) const;
    void IzlistajKorisnike() const;
    void IzlistajKnjige() const;
    void ZaduziKnjigu(int evidencijski_broj, int korisnicki_broj);
    void RazduziKnjigu(int evidencijski_broj);
    void PrikaziZaduzenja(int korisnicki_broj) const;
};
void IspisiMeni() {
    cout << "Unesite broj opcije koju zelite: \n";
    cout << "1)  Registracija novog korisnika" << endl;
    cout << "2)  Registracija nove knjige" << endl;
    cout << "3)  Pretraga korisnika na osnovu evidencijskog broja korisnika" << endl;
    cout << "4)  Pretraga knjige na osnovu evidencijskog broja knjige " << endl;
    cout << "5)  Izlistaj korisnike" << endl;
    cout << "6)  Izlistaj knjige" << endl;
    cout << "7)  Zaduzi knjigu " << endl;
    cout << "8)  Razduzi knjigu" << endl;
    cout << "9)  Prikazi zaduzenja korisnika" << endl;
    cout << "10) Kraj" << endl;
}
int main() {
    Biblioteka b;
    cout << "Izaberite neku od opcija biblioteke.\n" << endl;
    while(1) {
        IspisiMeni();
        int unos;
        cout << "Unesite zeljenu opciju: ";
        cin >> unos;
        if(unos == 1) {
            int korisnicki_broj;
            string ime, prezime, adresa, broj_telefona;
            cout << "Unesite korisnicki broj korisnika: ";
            cin >> korisnicki_broj;
            cout << "Unesite ime korisnika: ";
            cin.clear(); cin.ignore(10000, '\n');
            getline(cin, ime);
            cout << "Unesite prezime korisnika: ";
            getline(cin, prezime);
            cout << "Unesite adresu korisnika: ";
            getline(cin, adresa);
            cout << "Unesite broj telefona korisnika: ";
            getline(cin, broj_telefona);
            b.RegistrirajNovogKorisnika(korisnicki_broj, ime, prezime, adresa, broj_telefona);
        }
        else if(unos == 2) {
            int evidencijski_broj, godina_izdavanja;
            string naslov, ime_pisca, zanr;
            cout << "Unesite evidencijski broj knjige: ";
            cin >> evidencijski_broj;
            cout << "Unesite naslov knjige: ";
            cin.clear(); cin.ignore(10000, '\n');
            getline(cin, naslov);
            cout << "Unesite ime pisca: ";
            getline(cin, ime_pisca);
            cout << "Unesite zanr knjige: ";
            getline(cin, zanr);
            cout << "Unesite godinu izdavanja knjige: ";
            cin >> godina_izdavanja;
            b.RegistrirajNovuKnjigu(evidencijski_broj, naslov, ime_pisca, zanr, godina_izdavanja);
        }
        else if(unos == 3) {
            int evidencijski_broj;
            cout << "Unesite evidencijski broj clana: ";
            cin >> evidencijski_broj;
            try {
                Korisnik trazeni = b.NadjiKorisnika(evidencijski_broj);
                trazeni.Ispisi();
            }
            catch(domain_error nema_korisnika) { cout << nema_korisnika.what() << endl; }
        }
        else if(unos == 4) {
            int evidencijski_broj;
            cout << "Unesite evidencijski broj knjige: ";
            cin >> evidencijski_broj;
            try {
                Knjiga trazena = b.NadjiKnjigu(evidencijski_broj);
                trazena.Ispisi();
            }
            catch (domain_error nema_knjige) { cout << nema_knjige.what() << endl; }
        }
        else if(unos == 5) {
            b.IzlistajKorisnike();
        }
        else if(unos == 6) {
            b.IzlistajKnjige();
        }
        else if(unos == 7) {
            int evidencijski_broj, korisnicki_broj;
            cout << "Unesite evidencijski broj knjige koju zelite zaduziti: ";
            cin >> evidencijski_broj;
            cout << "Unesite evidencijski broj clana kojem zelite zaduziti knjigu: ";
            cin >> korisnicki_broj;
            try { b.ZaduziKnjigu(evidencijski_broj, korisnicki_broj); }
            catch (domain_error neki) { cout << neki.what() << endl; }
        }
        else if(unos == 8) {
            int evidencijski_broj;
            cout << "Unesite evidencijski broj knjige koju zelite razduziti: ";
            cin >> evidencijski_broj;
            try { b.RazduziKnjigu(evidencijski_broj); }
            catch (domain_error greska) { cout << greska.what() << endl; }
        }
        else if(unos == 9) {
            int evidencijski_broj;
            cout << "Unesite evidencijski broj korisnika cija zaduzenja zelite vidjeti: ";
            cin >> evidencijski_broj;
            try { b.PrikaziZaduzenja(evidencijski_broj); }
            catch (domain_error greska) { cout << greska.what() << endl; }
        }
        else if(unos == 10) {
            cout << "Dovidjenja";
            break;
        }
        else {
            cout << "Pogresan unos! \n";
        }


    }
}
void Biblioteka::PrikaziZaduzenja(int korisnicki_broj) const {
    bool korisnik_postoji = false;
    for(int i(0); i < int(Korisnici.size()); i++) {
        if(korisnicki_broj == int(Korisnici[i]->DajEvidencijskiBroj())) {
            korisnik_postoji = true;
            break;
        }
    }
    if(!korisnik_postoji) throw domain_error ("Korisnik nije nadjen");
    int brojac = 0;
    bool nemazaduzenja = true;
    for(int i(0); i < int(Knjige.size()); i++) {
        if(Knjige[i]->DaLiJeZaduzena() == false) continue;
        else
        if(korisnicki_broj == int(Knjige[i]->DajKodKogaJe()->DajEvidencijskiBroj())) {
            Knjige[i]->Ispisi();
            nemazaduzenja = false;
            if(brojac % 2 == 0) cout << endl;
            brojac++;
        }
    }
    if(nemazaduzenja) cout << "Nema zaduzenja za tog korisnika";
}
void Biblioteka::RazduziKnjigu(int evidencijski_broj){
    bool knjiga_nadjena = false;
    for(int i(0); i < int(Knjige.size()); i++){
        if(evidencijski_broj == int(Knjige[i]->DajEvidencijskiBroj())) {
            knjiga_nadjena = true;
            break;
        }
    }
    if(!knjiga_nadjena) throw domain_error ("Knjiga nije nadjena");
    for(int i(0); i < int(Knjige.size()); i++) {
        if(evidencijski_broj == int(Knjige[i]->DajEvidencijskiBroj())) {
            if(!(Knjige[i]->DaLiJeZaduzena())) { throw domain_error ("Knjiga nije zaduzena"); }
            else {
                NadjiKnjigu(evidencijski_broj).RazduziKnjigu();
            }
        }
    }
}
void Biblioteka::ZaduziKnjigu(int evidencijski_broj, int korisnicki_broj) {
    bool knjiga_nadjena = false;
    for(int i(0); i < int(Knjige.size()); i++){
        if(evidencijski_broj == int(Knjige[i]->DajEvidencijskiBroj())) {
            knjiga_nadjena = true;
            break;
        }
    }
    if(!knjiga_nadjena) throw domain_error ("Knjiga nije nadjena");
    bool korisnik_postoji = false;
    for(int i(0); i < int(Korisnici.size()); i++) {
        if(korisnicki_broj == int(Korisnici[i]->DajEvidencijskiBroj())) {
            korisnik_postoji = true;
            break;
        }
    }
    if(!korisnik_postoji) throw domain_error ("Korisnik nije nadjen");
    for(int i(0); i < int(Knjige.size()); i++) {
        if(evidencijski_broj == int(Knjige[i]->DajEvidencijskiBroj())){
            if(Knjige[i]->DaLiJeZaduzena()) { throw domain_error ("Knjiga vec zaduzena");}
            else {
                Knjige[i]->ZaduziKnjigu(NadjiKorisnika(korisnicki_broj));
            }
    }
    }
}
void Biblioteka::IzlistajKnjige() const {
    for(int i(0); i<int(Knjige.size()); i++) {
        Knjige[i]->Ispisi();
        if(Knjige[i]->DaLiJeZaduzena()) cout << "Zaduzena kod korisnika: " << Knjige[i]->DajKodKogaJe()->DajIme()<<" "<< Knjige[i]->DajKodKogaJe()->DajPrezime()<< endl;
        if((i+1) % 2 == 0) cout << endl;
    }
}
void Biblioteka::IzlistajKorisnike() const {
    for(int i(0); i<int(Korisnici.size()); i++) {
        Korisnici[i]->Ispisi();
        if((i+1) % 2 == 0) cout << endl;
    }
}
Korisnik& Biblioteka::NadjiKorisnika(int evidencijski_broj) const {
    for(int i(0); i < int(Korisnici.size()); i++)
        if(Korisnici[i]->DajEvidencijskiBroj() == evidencijski_broj)
           return *Korisnici[i];

    throw domain_error ("Korisnik nije nadjen");
}
Knjiga& Biblioteka::NadjiKnjigu(int evidencijski_broj) const {
    for(int i(0); i < int(Knjige.size()); i++)
        if(Knjige[i]->DajEvidencijskiBroj() == evidencijski_broj)
            return *Knjige[i];

    throw domain_error ("Knjiga nije nadjena");
}
