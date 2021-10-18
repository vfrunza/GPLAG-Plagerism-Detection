/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <map>

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
    std::map<int, Korisnik*> korisnici;
    std::map<int, Knjiga*> knjige;
public:
    void RegistrirajNovogKorisnika(int clanski_broj, const std::string &ime, const std::string &prezime, const std::string &adresa, const std::string &telefon);
    void RegistrirajNovuKnjigu(int br_knjige, std::string naslov, std::string autor, std::string zanr, int godina_izdavanja);
    ~Biblioteka();
    
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
    
    Korisnik* p(nullptr);
    try
    {
        p = new Korisnik{ime, prezime, adresa, telefon};
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
    
    Knjiga* p(nullptr);
    try
    {
        p = new Knjiga(naslov, autor, zanr, godina_izdavanja);
    }
    catch(...)
    {
        throw;
    }
    knjige[br_knjige] = p;
}

Biblioteka::~Biblioteka()
{
    for(auto i(korisnici.begin()); i != korisnici.end(); i++)
    {
        delete i->second;
    }
    
    for(auto i(knjige.begin()); i != knjige.end(); i++)
    {
        delete i->second;
    }
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
    /*Korisnik x{"Ivan", "Grozni", "Bosanska 13", "061092400"};
    KnjigaB"C++", "Zeljko Juric", "Strucna literatura", 2017);
    
    std::cout <<BDaLiJeZaduzena() << std::endl;
   BZaduziKnjigu(x);
    std::cout <<BDaLiJeZaduzena() << std::endl;
   BRazduziKnjigu();
    std::cout <<BDaLiJeZaduzena() << std::endl;*/
    try
    {
        Biblioteka bib8;
        bib8.RegistrirajNovogKorisnika(1, "Niko", "Nikic", "Zmaja od Bosne bb", "123 456");
        bib8.RegistrirajNovuKnjigu(1, "Vlak u snijegu2", "Mato Lovrak2", "Roman2", 1941);
        bib8.RegistrirajNovuKnjigu(2, "Vlak u snijegu", "Mato Lovrak", "Roman", 1931);
        bib8.ZaduziKnjigu(2, 1);
        bib8.IzlistajKnjige();
    }
    catch(const std::exception &e)
    {
        std::cout << e.what();
    }
	return 0;
}