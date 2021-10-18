/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <stdexcept>
#include <map>
#include <algorithm>
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
    std::map<int, Korisnik *> korisnik;
    std::map<int, Knjiga *> knjiga;
public:
    Biblioteka() {}
    Biblioteka(const Biblioteka &b)
    {
        for(auto i : b.korisnik)
        {
            Korisnik *novi = new Korisnik;
            novi->ime = i.second->ime;
            novi->prezime = i.second->prezime;
            novi->adresa = i.second->adresa;
            novi->telefon = i.second->telefon;
            korisnik.insert(std::make_pair(i.first, novi));
        }
        for(auto i : b.knjiga)
        {
            Knjiga *nova = new Knjiga(i.second->DajNaslov(), i.second->DajAutora(), i.second->DajZanr(), i.second->DajGodinuIzdavanja());
            knjiga.insert(std::make_pair(i.first, nova));
        }
    }
    ~Biblioteka() 
    {
        for(auto i : korisnik)
            delete i.second;
            
        for(auto i : knjiga)
            delete i.second;
    }
    Biblioteka &operator = (const Biblioteka &b)
    {
        if(this == &b)
            return *this;
            
        for(auto i : korisnik)
            delete i.second;
            
        for(auto i : knjiga)
            delete i.second;
        
        for(auto i : b.korisnik)
        {
            Korisnik *novi = new Korisnik;
            novi->ime = i.second->ime;
            novi->prezime = i.second->prezime;
            novi->adresa = i.second->adresa;
            novi->telefon = i.second->telefon;
            korisnik.insert(std::make_pair(i.first, novi));
        }
        for(auto i : b.knjiga)
        {
            Knjiga *nova = new Knjiga(i.second->DajNaslov(), i.second->DajAutora(), i.second->DajZanr(), i.second->DajGodinuIzdavanja());
            knjiga.insert(std::make_pair(i.first, nova));
        }
        return *this;
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
        
    Korisnik *k = nullptr;
    k = new Korisnik{ime, prezime, adresa, tel};
    korisnik[id] = k;
}
void Biblioteka::RegistrirajNovuKnjigu(int id, std::string naslov, std::string pisac, std::string zanr, int god)
{
    if(knjiga.count(id) != 0)
        throw std::logic_error("Knjiga vec postoji");
        
    Knjiga *k = nullptr;
    k = new Knjiga(naslov, pisac, zanr, god);
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
int main_at ()
{
    Korisnik kor{"Meho", "Mehic", "Dobojska 15", "033/123-456"};
    Knjiga knj("Tvrdjava", "Mesa Selimovic", "Roman", 1965);
    if(knj.DajKodKogaJe() == nullptr) std::cout << "Nije zaduzena\n";
    std::cout << knj.DaLiJeZaduzena() << std::endl;
    knj.ZaduziKnjigu(kor);
    std::cout << "Knjigu je zaduzio " << knj.DajKodKogaJe()->ime << std::endl;
    std::cout << knj.DaLiJeZaduzena() << std::endl;

	return 0;
}
int main_at2()
{
    Biblioteka bib5;
    bib5.RegistrirajNovogKorisnika(1, "Niko", "Nikic", "Zmaja od Bosne bb", "123 456");
    bib5.RegistrirajNovuKnjigu(2, "Vlak u snijegu", "Mato Lovrak", "Roman", 1931);
    std::cout << bib5.NadjiKnjigu(2).DajNaslov();
    return 0;
}

int main_at3()
{
    Biblioteka bib8;
    bib8.RegistrirajNovogKorisnika(1, "Niko", "Nikic", "Zmaja od Bosne bb", "123 456");
    bib8.RegistrirajNovuKnjigu(1, "Vlak u snijegu2", "Mato Lovrak2", "Roman2", 1941);
    bib8.RegistrirajNovuKnjigu(2, "Vlak u snijegu", "Mato Lovrak", "Roman", 1931);
    bib8.ZaduziKnjigu(2, 1);
    bib8.IzlistajKnjige();

}
int main_at4()
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
b.PrikaziZaduzenja(1234);
}

int main()
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
    b.ZaduziKnjigu(231, 1234);
    b.ZaduziKnjigu(136, 1234);
    b.PrikaziZaduzenja(1234);
}