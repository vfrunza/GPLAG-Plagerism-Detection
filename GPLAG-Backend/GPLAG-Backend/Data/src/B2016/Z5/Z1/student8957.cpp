/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <stdexcept>
#include <map>

using namespace std;

struct Korisnik
{
    string ime;
    string prezime;
    string adresa;
    string telefon;
};

class Knjiga
{
    string naslov;
    string imePisca;
    string zanr;
    int godinaIzdavanja;
    Korisnik* zaduzena;
public:
    Knjiga(string naslov, string ime_pisca, string zanr, int godina_izdavanja) : naslov(naslov), imePisca(ime_pisca), zanr(zanr), godinaIzdavanja(godina_izdavanja), zaduzena(nullptr) {}
    string DajNaslov() const { return naslov; }
    string DajAutora() const { return imePisca; }
    string DajZanr() const { return zanr; }
    int DajGodinuIzdavanja() const { return godinaIzdavanja; }
    Korisnik* DajKodKogaJe() const { if(DaLiJeZaduzena()) return zaduzena; }
    void ZaduziKnjigu(Korisnik &korisnik) { zaduzena = &korisnik; }
    void RazduziKnjigu() { zaduzena = nullptr; }
    bool DaLiJeZaduzena() const { return (zaduzena != nullptr); }
};

class Biblioteka 
{
    map<int, Korisnik*> korisnici;
    map<int, Knjiga*> knjige;
public:
    Biblioteka() {}
    ~Biblioteka()
    {
        for(auto k: korisnici) delete k.second;
        for(auto k: knjige) delete k.second;
    }
    Biblioteka(const Biblioteka &b)
    {
        korisnici = b.korisnici;
        knjige = b.knjige;
        auto it1 = b.korisnici.begin();
        for(auto k: korisnici)
        {
            Korisnik *korisnik = new Korisnik;
            korisnik->ime = it1->second->ime;
            korisnik->prezime = it1->second->prezime;
            korisnik->adresa = it1->second->adresa;
            korisnik->telefon = it1->second->telefon;
            k.second = korisnik;
            it1++;
        }
        
        auto it2 = b.knjige.begin();
        for(auto k: knjige)
        {
            Knjiga *knjiga = new Knjiga(it2->second->DajNaslov(), it2->second->DajAutora(), it2->second->DajZanr(), it2->second->DajGodinuIzdavanja());
            k.second = knjiga;
            it2++;
        }
    }
    Biblioteka &operator=(const Biblioteka &b)
    {
        if(this == &b) return *this;
        
        for(auto k: korisnici) delete k.second;
        for(auto k: knjige) delete k.second;
        
        korisnici = b.korisnici;
        knjige = b.knjige;
        auto it1 = b.korisnici.begin();
        for(auto k: korisnici)
        {
            Korisnik *korisnik = new Korisnik;
            korisnik->ime = it1->second->ime;
            korisnik->prezime = it1->second->prezime;
            korisnik->adresa = it1->second->adresa;
            korisnik->telefon = it1->second->telefon;
            k.second = korisnik;
            it1++;
        }
        
        auto it2 = b.knjige.begin();
        for(auto k: knjige)
        {
            Knjiga *knjiga = new Knjiga(it2->second->DajNaslov(), it2->second->DajAutora(), it2->second->DajZanr(), it2->second->DajGodinuIzdavanja());
            k.second = knjiga;
            it2++;
        }
        
        return *this;
    }
    Biblioteka(const Biblioteka &&b)
    {
        korisnici = b.korisnici;
        knjige = b.knjige;
        
        for(auto k: b.korisnici) k.second = nullptr;
        for(auto k: b.knjige) k.second = nullptr;
    }
    Biblioteka &operator=(Biblioteka &&b)
    {
        if(this == &b) return *this;
        
        for(auto k: korisnici) delete k.second;
        for(auto k: knjige) delete k.second;
        
        korisnici = b.korisnici;
        knjige = b.knjige;
        for(auto k: b.korisnici) k.second = nullptr;
        for(auto k: b.knjige) k.second = nullptr;
        
        return *this;
    }
    void RegistrirajNovogKorisnika(int clanski_broj, string ime, string prezime, string adresa, string telefon);
    void RegistrirajNovuKnjigu(int evidencijski_broj, string naslov, string ime_pisca, string zanr, int godina_izdavanja);
    Korisnik &NadjiKorisnika(int clanski_broj);
    Knjiga &NadjiKnjigu(int evidencijski_broj);
    void IzlistajKorisnike() const;
    void IzlistajKnjige() const;
    void ZaduziKnjigu(int evidencijski_broj, int clanski_broj);
    void RazduziKnjigu(int evidencijski_broj);
    void PrikaziZaduzenja(int clanski_broj);
};

void Biblioteka::RegistrirajNovogKorisnika(int clanski_broj, string ime, string prezime, string adresa, string telefon)
{
    for(auto k: korisnici)
        if(k.first == clanski_broj) throw logic_error("Korisnik vec postoji");
    
    Korisnik *k = new Korisnik;
    k->ime = ime;
    k->prezime = prezime;
    k->adresa = adresa;
    k->telefon = telefon;
    korisnici.insert(make_pair(clanski_broj, k));
}

void Biblioteka::RegistrirajNovuKnjigu(int evidencijski_broj, string naslov, string ime_pisca, string zanr, int godina_izdavanja)
{
    for(auto k: knjige)
        if(k.first == evidencijski_broj) throw logic_error("Knjiga vec postoji");
    
    Knjiga *k = new Knjiga(naslov, ime_pisca, zanr, godina_izdavanja);
    knjige.insert(make_pair(evidencijski_broj, k));
}

Korisnik &Biblioteka::NadjiKorisnika(int clanski_broj)
{
    bool imaLiKorisnika = false;
    
    for(auto k: korisnici)
    {
        if(k.first == clanski_broj)
        {
            imaLiKorisnika = true;
            return *(k.second);
        }
    }
    
    if(!imaLiKorisnika) throw logic_error("Korisnik nije nadjen");
}

Knjiga &Biblioteka::NadjiKnjigu(int evidencijski_broj)
{
    bool imaLiKnjige = false;
    
    for(auto k: knjige)
    {
        if(k.first == evidencijski_broj)
        {
            imaLiKnjige = true;
            return *(k.second);
        }
    }
    
    if(!imaLiKnjige) throw logic_error("Knjiga nije nadjena");
}

void Biblioteka::IzlistajKorisnike() const
{
    for(auto k: korisnici)
    {
        cout << "Clanski broj: " << k.first << endl;
        cout << "Ime i prezime: " << k.second->ime << " " << k.second->prezime << endl;
        cout << "Adresa: " << k.second->adresa << endl;
        cout << "Broj telefona: " << k.second->telefon << endl;
    }
}

void Biblioteka::IzlistajKnjige() const
{
    for(auto k: knjige)
    {
        cout << "Evidencijski broj: " << k.first << endl;
        cout << "Naslov: " << k.second->DajNaslov() << endl;
        cout << "Pisac: " << k.second->DajAutora() << endl;
        cout << "Zanr: " << k.second->DajZanr() << endl;
        cout << "Godina izdavanja: " << k.second->DajGodinuIzdavanja() << endl;
        if(k.second->DaLiJeZaduzena())
            cout << "Zaduzena kod korisnika: " << k.second->DajKodKogaJe()->ime << " " << k.second->DajKodKogaJe()->prezime << endl; 
    }
}

void Biblioteka::ZaduziKnjigu(int evidencijski_broj, int clanski_broj)
{
    bool imaLiKnjige = false, imaLiKorisnika = false;
    
    for(auto k: korisnici)
    {
        if(k.first == clanski_broj)
        {
            imaLiKorisnika = true;
            break;
        }
    }
    
    for(auto k: knjige)
    {
        if(k.first == evidencijski_broj)
        {
            imaLiKnjige = true;
            if(k.second->DaLiJeZaduzena()) throw logic_error("Knjiga vec zaduzena");
            k.second->ZaduziKnjigu(NadjiKorisnika(clanski_broj));
            break;
        }
    }
    
    if(!imaLiKnjige) throw logic_error("Knjiga nije nadjena");
    if(!imaLiKorisnika) throw logic_error("Korisnik nije nadjen");
}

void Biblioteka::RazduziKnjigu(int evidencijski_broj) 
{
    bool imaLiKnjige = false;
    
    for(auto k: knjige)
    {
        if(k.first == evidencijski_broj)
        {
            imaLiKnjige = true;
            if(k.second->DaLiJeZaduzena())
            {
                k.second->RazduziKnjigu();
                break;
            }
            else
                throw logic_error("Knjiga nije zaduzena");
        }
    }
    
    if(!imaLiKnjige) throw logic_error("Knjiga nije nadjena");
}

void Biblioteka::PrikaziZaduzenja(int clanski_broj)
{
    bool imaLiKorisnika = false, imaLiZaduzenja = false;
    
    for(auto k: korisnici)
    {
        if(k.first == clanski_broj)
        {
            imaLiKorisnika = true;
            break;
        }
    }
    
    if(!imaLiKorisnika) throw logic_error("Korisnik nije nadjen");
    
    for(auto k: knjige)
    {
        if(k.second->DajKodKogaJe() == &NadjiKorisnika(clanski_broj))
        {
            imaLiZaduzenja = true;
            cout << "Evidencijski broj: " << k.first << endl;
            cout << "Naslov: " << k.second->DajNaslov() << endl;
            cout << "Pisac: " << k.second->DajAutora() << endl;
            cout << "Zanr: " << k.second->DajZanr() << endl;
            cout << "Godina izdavanja: " << k.second->DajGodinuIzdavanja() << endl;
        }
    }
    
    if(!imaLiZaduzenja) 
        cout << "Nema zaduzenja za tog korisnika!" << endl;
}

int main ()
{
    Biblioteka b;
    int izbor = 0;
    
    while(izbor != 10)
    {
        cout << "Meni: \n1. Registriraj novog korisnika\n2. Registriraj novu knjigu\n3. Nadji korisnika\n4. Nadji knjigu\n5. Izlistaj korisnike\n6. Izlistaj knjige\n7. Zaduzi knjigu\n8. Razduzi knjigu\n9. Prikazi zaduzeznja\n10. Izlaz\nUnesite vas izbor: ";
        cin >> izbor;
        
        switch(izbor)
        {
            case 1:
            {
                int clBr;
                string ime, prezime, adresa, telefon;
                cout << "Unesite clanski broj: ";
                cin >> clBr;
                cin.ignore(10000, '\n');
                cout << "Unesite ime: ";
                getline(cin, ime);
                cout << "Unesite prezime: ";
                getline(cin, prezime);
                cout << "Unesite adresu: ";
                getline(cin, adresa);
                cout << "Unesite broj telefona: ";
                getline(cin, telefon);
                try
                {
                    b.RegistrirajNovogKorisnika(clBr, ime, prezime, adresa, telefon);
                    break;
                }
                catch(logic_error e)
                {
                    cout << e.what() << endl;
                }
            }
            case 2:
            {
                int evBr, gIzdavanja;
                string naslov, autor, zanr;
                cout << "Unesite evidencijski broj: ";
                cin >> evBr;
                cin.ignore(10000, '\n');
                cout << "Unesite naslov: ";
                getline(cin, naslov);
                cout << "Unesite pisca: ";
                getline(cin, autor);
                cout << "Unesite zanr: ";
                getline(cin, zanr);
                cout << "Unesite godinu izdavanja: ";
                cin >> gIzdavanja;
                try
                {
                    b.RegistrirajNovuKnjigu(evBr, naslov, autor, zanr, gIzdavanja);
                    break;
                }
                catch(logic_error e)
                {
                    cout << e.what() << endl;
                }
            }
            case 3:
            {
                int clanski;
                cout << "Unesite clanski broj: ";
                cin >> clanski;
                try
                {
                    Korisnik korisnik = b.NadjiKorisnika(clanski);
                    cout << "Ime i prezime: " << korisnik.ime << " " << korisnik.prezime << endl;
                    cout << "Adresa: " << korisnik.adresa << endl;
                    cout << "Broj telefona: " << korisnik.telefon << endl;
                    break;
                }
                catch(logic_error e)
                {
                    cout << e.what() << endl;
                }
            }
            case 4:
            {
                int evidencijski;
                cout << "Unesite evidencijski broj: ";
                cin >> evidencijski;
                try
                {
                    Knjiga knjiga = b.NadjiKnjigu(evidencijski);
                    cout << "Naslov: " << knjiga.DajNaslov() << endl;
                    cout << "Pisac: " << knjiga.DajAutora() << endl;
                    cout << "Zanr: " << knjiga.DajZanr() << endl;
                    cout << "Godina izdavanja: " << knjiga.DajGodinuIzdavanja() << endl;
                    break;
                }
                catch(logic_error e)
                {
                    cout << e.what() << endl;
                }
            }
            case 5:
            {
                b.IzlistajKorisnike();
                break;
            }
            case 6:
            {
                b.IzlistajKnjige();
                break;
            }
            case 7:
            {
                int c, e;
                cout << "Unesite evidencijski broj: ";
                cin >> e;
                cout << "Unesite clanski broj: ";
                cin >> c;
                try
                {
                    b.ZaduziKnjigu(e, c);
                    break;
                }
                catch(logic_error e)
                {
                    cout << e.what() << endl;
                }
            }
            case 8:
            {
                int ev;
                cout << "Unesite evidencijski broj: ";
                cin >> ev;
                try
                {
                    b.RazduziKnjigu(ev);
                    break;
                }
                catch(logic_error e)
                {
                    cout << e.what() << endl;
                }
            }
            case 9:
            {
                int cl;
                cout << "Unesite clanski broj: ";
                cin >> cl;
                try
                {
                    b.PrikaziZaduzenja(cl);
                    break;
                }
                catch(logic_error e)
                {
                    cout << e.what() << endl;
                }
                
            }
            case 10:
                break;
        }   
    }
    
	return 0;
}