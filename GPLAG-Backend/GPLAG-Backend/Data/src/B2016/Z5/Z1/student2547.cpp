#include <iostream>
#include <string>
#include <map>

using namespace std;


struct Korisnik {
    string ime;
    string prezime;
    string adresa;
    string telefon;
    Korisnik(string ime, string prezime, string adresa, string telefon){
        this->ime = ime;
        this->prezime = prezime;
        this->adresa = adresa;
        this->telefon = telefon;
    }

};


class Knjiga {

private:
    string naslov;
    string pisac;
    string zanr;
    string godina_izdavanja;
    Korisnik *zaduzio = nullptr;

public:
    Knjiga(string naslov, string pisac, string zanr, string godina_izdavanja, Korisnik *zaduzio);
    string DajNaslov();
    string DajAutora();
    string DajZanr();
    string DajGodinuIzdavanja();
    Korisnik& DajKodKogaJe();

    void ZaduziKnjigu(Korisnik& korisnik);
    void RazduziKnjigu();
    bool DaLiJeZaduzena();
};

Knjiga::Knjiga(string naslov, string pisac, string zanr, string godina_izdavanja, Korisnik *zaduzio) {

    this->naslov = naslov;
    this->pisac = pisac;
    this->godina_izdavanja = godina_izdavanja;
    this->zaduzio = zaduzio;
    this->zanr = zanr;
}

string Knjiga::DajNaslov() {
    return naslov;
}

string Knjiga::DajAutora() {
    return pisac;
}

string Knjiga::DajZanr() {
    return zanr;
}

string Knjiga::DajGodinuIzdavanja() {
    return godina_izdavanja;
}

Korisnik& Knjiga::DajKodKogaJe() {
    return *zaduzio;
}

void Knjiga::ZaduziKnjigu(Korisnik& korisnik) {
    if(zaduzio != nullptr)
        throw logic_error("Knjiga vec zaduzena");
    if(&korisnik == nullptr)
        throw logic_error("Korisnik nije nadjen");
    zaduzio = &korisnik;
}

void Knjiga::RazduziKnjigu() {
    if(zaduzio == nullptr) {
        throw logic_error("Knjiga nije zaduzena");
    }
    zaduzio = nullptr;
}

bool Knjiga::DaLiJeZaduzena() {
    return (zaduzio != nullptr);
}



class Biblioteka {

private:
    map<int, Korisnik*> korisnici;
    map<int, Knjiga*> knjige;

public:
    Biblioteka();
    Biblioteka(Biblioteka &b);
    map<int, Korisnik*> DajKorisnike();
    map<int, Knjiga*> DajKnjige();
    void RegistrirajNovogKorisnika(int clanski_broj, string ime, string prezime, string adresa, string telefon);
    void RegistrirajNovuKnjigu(int evidencijski_broj, string naslov, string pisac, string zanr, string godina_izdavanja);

    Korisnik& NadjiKorisnika(int clanski_broj);
    Knjiga& NadjiKnjigu(int evidencijski_broj);

    void IzlistajKorisnike();
    void IzlistajKnjige();

    void RazduziKnjigu(int evidencijski_broj);
    void ZaduziKnjigu(int evidencijski_broj, int clanski_broj);

    void PrikaziZaduzenja(int clanski_broj);

};

Biblioteka::Biblioteka() {
    //korisnici = new map<int, &Korisnik>();
    //knjige = new map<int, &Knjiga>();
}
Biblioteka::Biblioteka(Biblioteka &b) {
    this->korisnici = b.DajKorisnike();
    this->knjige = b.DajKnjige();
}

map<int, Korisnik*> Biblioteka::DajKorisnike() {
    return korisnici;
}

map<int, Knjiga*> Biblioteka::DajKnjige() {
    return knjige;
}

void Biblioteka::RegistrirajNovogKorisnika(int clanski_broj, string ime, string prezime, string adresa, string telefon) {
    if(korisnici.count(clanski_broj) > 0) {
        throw logic_error("Korisnik vec postoji");
    }
    Korisnik *k = new Korisnik(ime, prezime, adresa, telefon);
    korisnici.insert({ clanski_broj, k});

}

void Biblioteka::RegistrirajNovuKnjigu(int evidencijski_broj, string naslov, string pisac, string zanr, string godina_izdavanja) {
    if(knjige.count(evidencijski_broj) > 0) {
        throw logic_error("Knjiga vec postoji");
    }
    //Korisnik *k1 = nullptr;
    Knjiga *k = new Knjiga(naslov, pisac, zanr, godina_izdavanja, nullptr);
    knjige.insert({evidencijski_broj, k});
}

Korisnik& Biblioteka::NadjiKorisnika(int clanski_broj) {
    if(korisnici.count(clanski_broj) == 0) {
        throw logic_error("Korisnik nije nadjen");
    }
    return *korisnici[clanski_broj];
}

Knjiga& Biblioteka::NadjiKnjigu(int evidencijski_broj) {
    if(knjige.count(evidencijski_broj) == 0) {
        throw logic_error("Knjiga nije nadjena");
    }
    return *knjige[evidencijski_broj];
}

void Biblioteka::IzlistajKorisnike() {

    int i =0;
    for (const auto& k : korisnici) {
        cout << "Clanski broj: " << k.first << endl;
        cout << "Ime i prezime: " << k.second->ime << " " << k.second->prezime << endl;
        cout << "Adresa: " << k.second->adresa << endl;
        cout << "Broj telefona: " << k.second->telefon << endl;
        if( i != 0 && ((i%2) == 0)) {
            cout << endl;
        }
        i++;
    }
}


void Biblioteka::IzlistajKnjige() {

    int i =0;
    for (const auto& k : knjige) {
        cout << "Evidencijski broj: " << k.first << endl;
        cout << "Naslov: " << k.second->DajNaslov() << endl;
        cout << "Pisac: " << k.second->DajAutora() << endl;
        cout << "Zanr: " << k.second->DajZanr() << endl;
        cout << "Godina izdavanja: " << k.second->DajZanr() << endl;
        if(k.second->DaLiJeZaduzena())
            cout << "Zaduzena kod korisnika: " << k.second->DajKodKogaJe().ime << " " << k.second->DajKodKogaJe().prezime << endl;
        if( i != 0 && ((i%2) == 0)) {
            cout << endl;
        }
        i++;
    }
}

void Biblioteka::RazduziKnjigu(int evidencijski_broj) {
    if(knjige.count(evidencijski_broj) == 0)
        throw logic_error("Knjiga nije nadjena");

    if(!knjige[evidencijski_broj]->DaLiJeZaduzena())
        throw logic_error("Knjiga nije zaduzena");

    knjige[evidencijski_broj]->RazduziKnjigu();

}

void Biblioteka::ZaduziKnjigu(int evidencijski_broj, int clanski_broj) {
    if(knjige.count(evidencijski_broj) == 0)
        throw logic_error("Knjiga nije nadjena");


    if(korisnici.count(clanski_broj) == 0)
        throw logic_error("Korisnik nije nadjen");


    knjige[evidencijski_broj]->ZaduziKnjigu(*korisnici[clanski_broj]);
}

void Biblioteka::PrikaziZaduzenja(int clanski_broj) {
    if(korisnici.count(clanski_broj) == 0)
        throw logic_error("Korisnik nije nadjen");

    int i =0;
    for (const auto& k : knjige) {
        if(k.second->DaLiJeZaduzena() && (k.second->DajKodKogaJe().ime == korisnici[clanski_broj]->ime) && (k.second->DajKodKogaJe().prezime == korisnici[clanski_broj]->prezime)&& (k.second->DajKodKogaJe().telefon == korisnici[clanski_broj]->telefon)
           && (k.second->DajKodKogaJe().adresa == korisnici[clanski_broj]->adresa)) {
            cout << "Evidencijski broj: " << k.first << endl;
            cout << "Naslov: " << k.second->DajNaslov() << endl;
            cout << "Pisac: " << k.second->DajAutora() << endl;
            cout << "Zanr: " << k.second->DajZanr() << endl;
            cout << "Godina izdavanja: " << k.second->DajZanr() << endl;
            if( i != 0 && ((i%2) == 0)) {
                cout << endl;
            }
            i++;
        }
    }
    if(i == 0) {
        cout << "Nema zaduzenja za tog korisnika!\n";
    }
}

int main() {

    string ime, prezime, adresa, telefon;
    cout << "Unesite korisnika: " << endl;
    cout << "Ime : ";
    getline(cin, ime);
    cout << "Prezime: ";
    //cin.ignore(1000, '\n');
    getline(cin, prezime);
    cout << "Adresa: ";
    //cin.ignore(1000, '\n');
    getline(cin, adresa);
    cout << "Telefon: ";//cin.ignore(1000, '\n');
    getline(cin, telefon);
    //cin.ignore(1000, '\n');
    Biblioteka b;
    int clanski_broj;
    cout << "Registracija korisnika: ";
    cout << endl << "Clanski broj: ";
    cin >> clanski_broj;
    b.RegistrirajNovogKorisnika(clanski_broj, ime, prezime, adresa, telefon);
    cin.ignore(1000, '\n');
    cout << "Unesite knjigu: " << endl;
    string naslov, pisac, zanr, godina_izdavanja;
    cout << "Naslov: ";
    getline(cin, naslov);
    cout << "Pisac: ";//cin.ignore(1000, '\n');
    getline(cin, pisac);
    cout << "Zanr: ";//cin.ignore(1000, '\n');
    getline(cin, zanr);
    cout << "Godina izdavanja: ";//cin.ignore(1000, '\n');
    getline(cin, godina_izdavanja);
    int evidencijski_br;
    cout << "Evidencijski broj: " << endl;
    cin >> evidencijski_br;

    b.RegistrirajNovuKnjigu(evidencijski_br, naslov, pisac, zanr, godina_izdavanja);

    b.ZaduziKnjigu(evidencijski_br, clanski_broj);

    cout << "Pretraga korisnika(Clanski broj): " << endl;
    int pretraga;
    cin >> pretraga;
    Korisnik k = b.NadjiKorisnika(pretraga);
    if( &k == nullptr) {
        cout << "Korisnik nije pronadjen" << endl;
    }
    else cout << "Korisnik je pronadjen" << endl;


    cout << "Pretraga Knjige(Evidencijski broj): " << endl;
    cin >> pretraga;
    Knjiga kg = b.NadjiKnjigu(pretraga);
    if( &k == nullptr) {
        cout << "Knjiga nije pronadjena" << endl;
    }
    else cout << "Knjiga je pronadjena" << endl;

    b.IzlistajKnjige();
    b.IzlistajKorisnike();

    b.PrikaziZaduzenja(clanski_broj);

    b.RazduziKnjigu(evidencijski_br);

    b.PrikaziZaduzenja(clanski_broj);



    return 0;
}