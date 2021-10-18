/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <map>
#include <memory>

struct Korisnik
{
    std::string ime, prezime, adresa, telefon;
};

class Knjiga
{
    std::string naslov, autor, zanr;
    int godina_izdavanja;
    Korisnik *zaduzenje = nullptr;
public:
    Knjiga(std::string naslov, std::string ime_pisca, std::string zanr, int godina_izdavanja) 
          : naslov(naslov), autor(ime_pisca), zanr(zanr), godina_izdavanja(godina_izdavanja) {}
    
    std::string DajNaslov() const { return naslov; }
    std::string DajAutora() const { return autor; }
    std::string DajZanr() const { return zanr; }
    int DajGodinuIzdavanja() const { return godina_izdavanja; }
    Korisnik* DajKodKogaJe() const { return zaduzenje; }
    bool DaLiJeZaduzena() const { return zaduzenje != nullptr; }
    
    void ZaduziKnjigu(Korisnik &x) { zaduzenje = &x; }
    void RazduziKnjigu() { zaduzenje = nullptr; }
};



class Biblioteka
{
    std::map<int, std::shared_ptr<Korisnik>> korisnici;
    std::map<int, std::shared_ptr<Knjiga>> knjige;
public:
    void RegistrirajNovogKorisnika(int clanski_broj, const std::string &ime, const std::string &prezime, const std::string &adresa, const std::string &telefon);
    void RegistrirajNovuKnjigu(int br_knjige, std::string naslov, std::string autor, std::string zanr, int godina_izdavanja);
    
    Korisnik &NadjiKorisnika(int clanski_broj);
    Knjiga &NadjiKnjigu(int br_knjige);
    
    void IzlistajKorisnike() const;
    void IzlistajKnjige() const;
    
    void ZaduziKnjigu(int br_knjige, int clanski_broj);
    void RazduziKnjigu(int br_knjige);
};

void Biblioteka::RegistrirajNovogKorisnika(int clanski_broj, const std::string &ime, const std::string &prezime, const std::string &adresa, const std::string &telefon)
{
    if(korisnici.count(clanski_broj) != 0)
      throw std::logic_error("Korisnik vec postoji");
    
    std::shared_ptr<Korisnik> p(nullptr);
    try
    {
        p = std::make_shared<Korisnik>();
        p->ime = ime;
        p->prezime = prezime;
        p->adresa = adresa;
        p->telefon = telefon;
    }
    catch(...)
    {
        throw;
    }
    korisnici[clanski_broj] = p;
}

void Biblioteka::RegistrirajNovuKnjigu(int br_knjige, std::string naslov, std::string autor, std::string zanr, int godina_izdavanja)
{
    if(knjige.count(br_knjige) != 0)
      throw std::logic_error("Knjiga vec postoji");
    
    std::shared_ptr<Knjiga> p(nullptr);
    try
    {
        p = std::make_shared<Knjiga>(naslov, autor, zanr, godina_izdavanja);
    }
    catch(...)
    {
        throw;
    }
    knjige[br_knjige] = p;
}

Korisnik &Biblioteka::NadjiKorisnika(int clanski_broj)
{
    auto x(korisnici.find(clanski_broj));
    if(x == korisnici.end())
      throw std::logic_error("Korisnik nije nadjen");
    return *(x->second);
}

Knjiga &Biblioteka::NadjiKnjigu(int br_knjige)
{
    auto x(knjige.find(br_knjige));
    if(x == knjige.end())
      throw std::logic_error("Knjiga nije nadjena");
    return *(x->second);
}

void Biblioteka::IzlistajKorisnike() const
{
    for(auto i(korisnici.begin()); i != korisnici.end(); i++)
    {
        std::cout << "Clanski broj: " << i->first << std::endl;
        std::cout << "Ime i prezime: " << i->second->ime << " " << i->second->prezime << std::endl;
        std::cout << "Adresa: " << i->second->adresa << std::endl;
        std::cout << "Broj telefona: " << i->second->telefon << std::endl << std::endl;
    }
}

void Biblioteka::IzlistajKnjige() const
{
    for(auto i(knjige.begin()); i != knjige.end(); i++)
    {
        std::cout << "Evidencijski broj: " << i->first << std::endl;
        std::cout << "Naslov: " << i->second->DajNaslov() << std::endl;
        std::cout << "Pisac: " << i->second->DajAutora() << std::endl;
        std::cout << "Zanr: " << i->second->DajZanr() << std::endl;
        std::cout << "Godina izdavanja: " << i->second->DajGodinuIzdavanja() << std::endl;
        if(i->second->DaLiJeZaduzena())
        {
            std::cout << "Zaduzena kod korisnika: " << i->second->DajKodKogaJe()->ime << " " << i->second->DajKodKogaJe()->prezime;
        }
        std::cout << std::endl;
    }
}

void Biblioteka::ZaduziKnjigu(int br_knjige, int clanski_broj)
{
    auto x(knjige.find(br_knjige));
    if(x == knjige.end())
      throw std::logic_error("Knjiga nije nadjena");
    
    auto y(korisnici.find(clanski_broj));
    if(y == korisnici.end())
      throw std::logic_error("Korisnik nije nadjen");
    
    if(x->second->DaLiJeZaduzena() == true)
      throw std::logic_error("Knjiga vec zaduzena");
    
    x->second->ZaduziKnjigu(*(y->second));
}

void Biblioteka::RazduziKnjigu(int br_knjige)
{
    auto x(knjige.find(br_knjige));
    if(x == knjige.end())
      throw std::logic_error("Knjiga nije nadjena");
    else if(x->second->DaLiJeZaduzena() == false)
      throw std::logic_error("Knjiga nije zaduzena");
    
    x->second->RazduziKnjigu();
}

int main ()
{
	return 0;
}