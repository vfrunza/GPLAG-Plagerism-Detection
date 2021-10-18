/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <stdexcept>
#include <map>
#include <algorithm>
#include <memory>
struct Korisnik
{
    std::string ime, prezime, adresa, telefon;  
};

class Knjiga
{
    std::string naslov, pisac, zanr;
    int god;
    Korisnik *zad = nullptr;
public:
    Knjiga(std::string naslov, std::string pisac, std::string zanr, int god) : naslov(naslov), pisac(pisac), zanr(zanr), god(god) {}
    std::string DajNaslov() const { return naslov; }
    std::string DajAutora() const { return pisac; }
    std::string DajZanr() const { return zanr; }
    int DajGodinuIzdavanja() const { return god; }
    Korisnik *DajKodKogaJe() const { return zad; }
    void ZaduziKnjigu (Korisnik &k) { zad = &k; }
    void RazduziKnjigu() { zad = nullptr; }
    bool DaLiJeZaduzena() const
    { 
        if(zad == nullptr) 
            return false; 
            
        return true; 
    }
};

class Biblioteka
{
    std::map<int, std::shared_ptr<Korisnik>> korisnik;
    std::map<int, std::shared_ptr<Knjiga>> knjiga;
public:
    Biblioteka() {}
    Biblioteka(const Biblioteka &b)
    {
        for(auto i : b.korisnik)
        {
            std::shared_ptr<Korisnik> novi(new Korisnik{});
            novi->ime = i.second->ime;
            novi->prezime = i.second->prezime;
            novi->adresa = i.second->adresa;
            novi->telefon = i.second->telefon;
            korisnik.insert(std::make_pair(i.first, novi));
        }
        for(auto i : b.knjiga)
        {
            std::shared_ptr<Knjiga> nova(new Knjiga(i.second->DajNaslov(), i.second->DajAutora(), i.second->DajZanr(), i.second->DajGodinuIzdavanja()));
            knjiga.insert(std::make_pair(i.first, nova));
        }
    }
    Biblioteka &operator = (const Biblioteka &b)
    {
        if(this == &b)
            return *this;
            
        for(auto i : b.korisnik)
        {
            std::shared_ptr<Korisnik> novi = std::make_shared<Korisnik>();
            novi->ime = i.second->ime;
            novi->prezime = i.second->prezime;
            novi->adresa = i.second->adresa;
            novi->telefon = i.second->telefon;
            korisnik.insert(std::make_pair(i.first, novi));
        }
        for(auto i : b.knjiga)
        {
            std::shared_ptr<Knjiga> nova (new Knjiga(i.second->DajNaslov(), i.second->DajAutora(), i.second->DajZanr(), i.second->DajGodinuIzdavanja()));
            knjiga.insert(std::make_pair(i.first, nova));
        }
    }
    void RegistrirajNovogKorisnika(int id, std::string ime, std::string prezime, std::string adresa, std::string tel);
    void RegistrirajNovuKnjigu(int id, std::string naslov, std::string pisac, std::string zanr, int god);
    Korisnik &NadjiKorisnika(int id)
    {
        auto i = korisnik.find(id);
        if(i == korisnik.end())
            throw std::logic_error("Korisnik nije nadjen");
        return *i->second;
    }
    Knjiga NadjiKnjigu(int id)
    {
        auto i = knjiga.find(id);
        if(i == knjiga.end())
            throw std::logic_error("Knjiga nije nadjena");
            
        return *i->second;
    }
    void IzlistajKorisnike() const;
    void IzlistajKnjige() const;
    void ZaduziKnjigu(int id1, int id2);
    void RazduziKnjigu(int id);
    void PrikaziZaduzenja(int id) const;
};
void Biblioteka::RegistrirajNovogKorisnika(int id, std::string ime, std::string prezime, std::string adresa, std::string tel)
{
    if(korisnik.count(id) != 0)
        throw std::logic_error("Korisnik vec postoji");
        
    std::shared_ptr<Korisnik> k(std::make_shared<Korisnik>());
    k->ime = ime;
    k->prezime = prezime;
    k->adresa = adresa;
    k->telefon = tel;
    korisnik[id] = k;
}
void Biblioteka::RegistrirajNovuKnjigu(int id, std::string naslov, std::string pisac, std::string zanr, int god)
{
    if(knjiga.count(id) != 0)
        throw std::logic_error("Knjiga vec postoji");
        
    std::shared_ptr<Knjiga> k(std::make_shared<Knjiga>(naslov, pisac, zanr, god));
    knjiga[id] = k;
}
void Biblioteka::IzlistajKorisnike() const
{
    for(auto i : korisnik)
    {
        std::cout << "Clanski broj: " << i.first << std::endl;
        std::cout << "Ime i prezime: " << i.second->ime << " " << i.second->prezime << std::endl;
        std::cout << "Adresa: " << i.second->adresa << std::endl;
        std::cout << "Broj telefona: " << i.second->telefon << std::endl;
        std::cout << std::endl;
    }
}
void Biblioteka::IzlistajKnjige() const
{
    for(auto i : knjiga)
    {
        std::cout << "Evidencijski broj: " << i.first << std::endl;
        std::cout << "Naslov: " << i.second->DajNaslov() << std::endl;
        std::cout << "Pisac: " << i.second->DajAutora() << std::endl;
        std::cout << "Zanr: " << i.second->DajZanr() << std::endl;
        std::cout << "Godina izdavanja: " << i.second->DajGodinuIzdavanja() << std::endl;
        
        if(i.second->DaLiJeZaduzena())
            std::cout << "Zaduzena kod korisnika: " << i.second->DajKodKogaJe()->ime << " " << i.second->DajKodKogaJe()->prezime << std::endl;
            
        std::cout << std::endl;
    }
}

void Biblioteka::ZaduziKnjigu(int id1, int id2)
{
    auto i = knjiga.find(id1);
    if(i == knjiga.end())
        throw std::logic_error("Knjiga nije nadjena");
        
    if((*i).second->DaLiJeZaduzena())
        throw std::logic_error("Knjiga vec zaduzena");
        
    auto j = korisnik.find(id2);
    if(j == korisnik.end())
        throw std::logic_error("Korisnik nije nadjen");
    
    i->second->ZaduziKnjigu(*j->second);
}
void Biblioteka::RazduziKnjigu(int id)
{
    auto i = knjiga.find(id);
    if(i == knjiga.end())
        throw std::logic_error("Knjiga nije nadjena");
    
    if(!(*i).second->DaLiJeZaduzena())
        throw std::logic_error("Knjiga nije zaduzena");
        
    (*i).second->RazduziKnjigu();
}
void Biblioteka::PrikaziZaduzenja(int id) const
{
    auto i = korisnik.find(id);
    if(i == korisnik.end())
        throw std::domain_error("Korisnik nije nadjen");
    
    bool ima = false;
    for(auto j : knjiga)
    {
        if(j.second->DajKodKogaJe() != nullptr && i->second->ime == j.second->DajKodKogaJe()->ime && i->second->prezime == j.second->DajKodKogaJe()->prezime
            && i->second->adresa == j.second->DajKodKogaJe()->adresa && i->second->telefon == j.second->DajKodKogaJe()->telefon)
        {
            ima = true;
            std::cout << "Evidencijski broj: " << j.first << std::endl;
            std::cout << "Naslov: " << j.second->DajNaslov() << std::endl;
            std::cout << "Pisac: " << j.second->DajAutora() << std::endl;
            std::cout << "Zanr: " << j.second->DajZanr() << std::endl;
            std::cout << "Godina izdavanja: " << j.second->DajGodinuIzdavanja() << std::endl << std::endl;
        }
    }
    if(ima == false)
        std::cout << "Nema zaduzenja za tog korisnika!";
}
int main ()
{
    Biblioteka bib6;
bib6.RegistrirajNovogKorisnika(1, "Niko", "Nikic", "Zmaja od Bosne bb", "123 456");
bib6.RegistrirajNovuKnjigu(2, "Vlak u snijegu", "Mato Lovrak", "Roman", 1931);
std::cout << bib6.NadjiKorisnika(1).ime;

	return 0;
}