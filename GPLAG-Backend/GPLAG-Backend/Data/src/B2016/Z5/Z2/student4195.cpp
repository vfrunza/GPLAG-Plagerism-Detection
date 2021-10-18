#include <iostream>
#include <string>
#include <stdexcept>
#include <map>
#include <memory>

using std::shared_ptr;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::map;


struct Korisnik {
    string ime,prezime,adresa,telefon;
};

class Knjiga
{
    string naslov,ime_p,zanr;
    int godinaiz;
    Korisnik* zaduzenik=nullptr;
public:
    Knjiga(string naslov, string ime_p, string zanr, int godinaiz): naslov(naslov), ime_p(ime_p), zanr(zanr), godinaiz(godinaiz) {};
    string DajNaslov() const {
        return naslov;
    }
    string DajAutora() const {
        return ime_p;
    }
    string DajZanr() const {
        return zanr;
    }
    int DajGodinuIzdavanja() const {
        return godinaiz;
    }
    Korisnik* DajKodKogaJe() const {
        return zaduzenik;
    }
    void ZaduziKnjigu(Korisnik& korisnik) {
        zaduzenik=&korisnik;
    }
    void RazduziKnjigu() {
        zaduzenik=nullptr;
    }
    bool DaLiJeZaduzena() {
        if(!zaduzenik) return false;
        return true;
    }
};

class Biblioteka
{
    map<int,shared_ptr<Korisnik>> korisnici;
    map<int,shared_ptr<Knjiga>> knjige;
public:
    Biblioteka()=default;
    Biblioteka(const Biblioteka& bib);
    Biblioteka(Biblioteka&& bib);
    Biblioteka& operator = (const Biblioteka& bib);
    Biblioteka& operator =(Biblioteka&& bib);
    void RegistrirajNovogKorisnika(int,string,string,string,string);
    void RegistrirajNovuKnjigu(int ev_br, string naslov, string ime_p, string zanr, int godinaiz);
    Korisnik& NadjiKorisnika(int) const;
    Knjiga& NadjiKnjigu(int) const; 
    void IzlistajKorisnike() const;
    void IzlistajKnjige() const;
    void ZaduziKnjigu(int ev_br, int cb);
    void RazduziKnjigu(int);
    void PrikaziZaduzenja(int) const ;
};


void Biblioteka::ZaduziKnjigu(int ev_br, int cb)
{
    if(!knjige.count(ev_br)) throw std::logic_error("Knjiga nije nadjena");
    if(!korisnici.count(cb)) throw std::logic_error("Korisnik nije nadjen");
    if(knjige[ev_br]->DaLiJeZaduzena()) throw std::logic_error("Knjiga vec zaduzena");
    knjige[ev_br]->ZaduziKnjigu(*korisnici[cb]);
}

void Biblioteka::RazduziKnjigu(int ev_br)
{
    if(!knjige.count(ev_br)) throw std::logic_error("Knjiga nije nadjena");
    if(!knjige[ev_br]->DaLiJeZaduzena()) throw std::logic_error("Knjiga nije zaduzena");
    knjige[ev_br]->RazduziKnjigu();
}

void Biblioteka::PrikaziZaduzenja(int cb) const
{
    if(!korisnici.count(cb)) throw std::logic_error("Korisnik nije nadjen");
    bool ima(false);
    for(auto it=knjige.begin(); it!=knjige.end(); it++) {
        if(it->second->DajKodKogaJe()==korisnici.at(cb).get()) {
            ima=true;
            cout<<"Evidencijski broj: "<<it->first<<endl;
            cout<<"Pisac: "<<it->second->DajAutora()<<" "<<endl;
            cout<<"Zanr: "<<it->second->DajZanr()<<endl;
            cout<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<endl;
        }
    }
    if(!ima) cout<<"Nema zaduzenja kod korisnika"<<endl;
    cout<<endl;
}

void Biblioteka::IzlistajKorisnike() const
{
    for(auto it=korisnici.begin(); it!=korisnici.end(); it++) {
        cout<<"Clanski broj: "<<it->first<<endl;
        cout<<"Ime i prezime: "<<it->second->ime<<" "<<it->second->prezime<<endl;
        cout<<"Adresa: "<<it->second->adresa<<endl;
        cout<<"Broj telefona: "<<it->second->telefon<<endl;
        cout<<endl;
    }
}


void Biblioteka::IzlistajKnjige() const
{
    for(auto it=knjige.begin(); it!=knjige.end(); it++) {
        cout<<"Evidencijski broj: "<<it->first<<endl;
        cout<<"Naslov: "<<it->second->DajNaslov()<<endl;
        cout<<"Pisac: "<<it->second->DajAutora()<<" "<<endl;
        cout<<"Zanr: "<<it->second->DajZanr()<<endl;
        cout<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<endl;
        if(it->second->DaLiJeZaduzena()) {
            cout<<"Zaduzena kod korisnika: "<<it->second->DajKodKogaJe()->ime<<" "<<it->second->DajKodKogaJe()->prezime<<endl;
        }
        cout<<endl;
    }
}

Korisnik& Biblioteka::NadjiKorisnika(int cb) const
{
    if(!korisnici.count(cb)) throw std::logic_error("Korisnik nije nadjen");
    return *(*korisnici.find(cb)).second;
}

Knjiga& Biblioteka::NadjiKnjigu(int ev_br) const
{
    if(!knjige.count(ev_br)) throw std::logic_error("Knjiga nije nadjena");
    return *(*knjige.find(ev_br)).second;
}

void Biblioteka::RegistrirajNovogKorisnika(int cb,string ime, string prezime, string adresa, string telefon)
{
    if (korisnici.count(cb)) throw std::logic_error("Korisnik vec postoji");
    korisnici[cb]=std::make_shared<Korisnik>();
    *korisnici[cb]=std::move(Korisnik {ime,prezime,adresa,telefon});
}

void Biblioteka::RegistrirajNovuKnjigu(int ev_br, string naslov, string ime_p, string zanr, int godinaiz)
{
    if(knjige.count(ev_br)) throw std::logic_error("Knjiga vec postoji");
    knjige[ev_br] = std::make_shared<Knjiga>(naslov,ime_p,zanr,godinaiz);
}

Biblioteka::Biblioteka(const Biblioteka& bib)
{
    for(auto it = bib.korisnici.begin(); it!= bib.korisnici.end(); it++) {
        korisnici[it->first] = std::make_shared<Korisnik>();
        *korisnici[it->first] = *it->second;
    }
    for(auto it = bib.knjige.begin(); it!= bib.knjige.end(); it++) {
        knjige[it->first] = std::make_shared<Knjiga>(*it->second);
    }

}
Biblioteka::Biblioteka(Biblioteka&& bib)
{
    std::swap(korisnici,bib.korisnici);
    std::swap(knjige,bib.knjige);
}
Biblioteka& Biblioteka::operator = (const Biblioteka& bib)
{
    *this=Biblioteka(bib);
    return *this;
}
Biblioteka& Biblioteka::operator =(Biblioteka&& bib)
{
    *this=Biblioteka(std::move(bib));
    return *this;
}
#define TestirajIzuzetak(izuzetak, tijelo) \
  try tijelo catch(izuzetak e) { std::cout << e.what() << std::endl; }
int main ()
{
Biblioteka b;
b.RegistrirajNovogKorisnika(1234, "Petar", "Petrovic",
"Zmaja od Bosne 30", "032/444-555");
b.RegistrirajNovogKorisnika(4312, "Hasan", "Hasanovic",
"Trg neznalica 111", "030/111-222");
b.RegistrirajNovogKorisnika(3124, "Mehmed", "Mehmedovic",
"Studenata etfovaca 3b", "037/654-321");
b.RegistrirajNovuKnjigu(231, "Prokleta avlija", "Ivo Andric", "Roman", 1955);
b.RegistrirajNovuKnjigu(555, "Grimove Bajke", "Braca Grim", "Bajke", 1927);
b.RegistrirajNovuKnjigu(136, "Kameni spavac", "Mak Dizdar", "Poezija", 1960);
const Biblioteka b2(b);                                           
TestirajIzuzetak(std::logic_error, { std::cout << b2.NadjiKnjigu(1234).DajNaslov() << std::endl;
 })
    return 0;
}