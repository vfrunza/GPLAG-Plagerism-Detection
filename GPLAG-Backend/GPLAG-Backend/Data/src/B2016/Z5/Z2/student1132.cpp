/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <memory>

struct Korisnik
{
  std::string ime, prezime, adresa, telefon;  
};
bool operator==(Korisnik k1, Korisnik k2)
{
    return k1.ime == k2.ime && k1.prezime == k2.prezime && k1.adresa == k2.adresa && k1.telefon == k2.telefon;
}
class Knjiga
{
  private:
    std::string naslov, ime_pisca, zanr;
    int godina_izdavanja;
    Korisnik* kod_koga_je;
  public:
    ~Knjiga(){kod_koga_je = nullptr;}
    Knjiga(std::string naslov, std::string ime_pisca, std::string zanr, int godina_izdavanja);
    std::string DajNaslov() const;
    std::string DajAutora() const;
    std::string DajZanr() const;
    int DajGodinuIzdavanja() const;
    Korisnik* DajKodKogaJe() const;
    void ZaduziKnjigu(Korisnik& korisnik);
    void RazduziKnjigu();
    bool DaLiJeZaduzena()const;
};
Knjiga::Knjiga(std::string n, std::string i, std::string z, int g):naslov(n),ime_pisca(i),zanr(z),godina_izdavanja(g),kod_koga_je(nullptr){}
std::string Knjiga::DajNaslov()const { return naslov; }
std::string Knjiga::DajAutora()const { return ime_pisca; }
std::string Knjiga::DajZanr()const { return zanr; }
int Knjiga::DajGodinuIzdavanja()const { return godina_izdavanja; }
Korisnik* Knjiga::DajKodKogaJe()const { return kod_koga_je; }
void Knjiga::ZaduziKnjigu(Korisnik& korisnik){ kod_koga_je = (&korisnik); }
void Knjiga::RazduziKnjigu() { kod_koga_je = nullptr; }
bool Knjiga::DaLiJeZaduzena()const { return bool(kod_koga_je != nullptr); }

class Biblioteka
{
   private:
     std::map<int, std::shared_ptr<Korisnik> > korisnici;
     std::map<int, std::shared_ptr<Knjiga> > knjige;
   public:
     Biblioteka();
     Biblioteka(const Biblioteka& bibl);
     Biblioteka(Biblioteka&& bibl);
     Biblioteka& operator=(const Biblioteka& bibl);
     Biblioteka& operator=(Biblioteka&& bibl);
     void RegistrirajNovogKorisnika(int clanski_broj, std::string ime, std::string prezime, std::string adresa, std::string telefon);
     void RegistrirajNovuKnjigu(int evidencijski_broj, std::string naslov, std::string ime, std::string zanr, int godina_izdavanja);
     Korisnik& NadjiKorisnika(int clanski_broj);
     Knjiga& NadjiKnjigu(int evidencijski_broj);
     void IzlistajKorisnike()const;
     void IzlistajKnjige()const;
     void ZaduziKnjigu(int evidencijski_broj, int clanski_broj);
     void RazduziKnjigu(int evidencijski_broj);
     void PrikaziZaduzenja(int clanski_broj);
   private:
     void IspisiKnjigu(int evidencijski_broj, const Knjiga& knjiga,bool x = true)const;
     void IspisiKorisnika(int clanski_broj, const Korisnik& korisnik)const;
};

Biblioteka::Biblioteka(){}
Biblioteka::Biblioteka(const Biblioteka& bibl)
{
    try
    {
        for(auto e: bibl.korisnici)
        {
            auto empl = std::make_shared<Korisnik>(Korisnik(*e.second));
            korisnici.emplace(e.first, empl);
        }
        for(auto e: bibl.knjige)
        {
            auto empl = std::make_shared<Knjiga>(Knjiga(*e.second));
            knjige.emplace(e.first, empl);
        }
    }
    catch(...)
    {
        throw;
    }
}
Biblioteka::Biblioteka(Biblioteka&& bibl)
{
    std::swap(korisnici, bibl.korisnici);
    std::swap(knjige, bibl.knjige);
}
Biblioteka& Biblioteka::operator=(const Biblioteka& bibl)
{
    if(this == &bibl) return *this;
    korisnici.clear();
    knjige.clear();
    try
    {
        for(auto e: bibl.korisnici)
        {
            auto empl = std::make_shared<Korisnik>(Korisnik(*e.second));
            korisnici.emplace(e.first, empl);
        }
        for(auto e: bibl.knjige)
        {
            auto empl = std::make_shared<Knjiga>(Knjiga(*e.second));
            knjige.emplace(e.first, empl);
        }
    }
    catch(...)
    {}
    return *this;
}
Biblioteka& Biblioteka::operator=(Biblioteka&& bibl)
{
    std::swap(bibl.korisnici, korisnici);
    std::swap(bibl.knjige, knjige);
    return *this;
}
void Biblioteka::RegistrirajNovogKorisnika(int clanski_broj, std::string ime, std::string prezime, std::string adresa, std::string telefon)
{
    if(korisnici.count(clanski_broj) != 0) throw std::logic_error("Korisnik vec postoji");
    auto empl = std::make_shared<Korisnik>(Korisnik{ime,prezime,adresa,telefon});
    korisnici.emplace(clanski_broj, empl);
}
void Biblioteka::RegistrirajNovuKnjigu(int evidencijski_broj, std::string naslov, std::string ime, std::string zanr, int godina_izdavanja)
{
    if(knjige.count(evidencijski_broj) != 0) throw std::logic_error("Knjiga vec postoji");
    auto empl = std::make_shared<Knjiga>(Knjiga(naslov, ime, zanr, godina_izdavanja));
    knjige.emplace(evidencijski_broj, empl);
}
Korisnik& Biblioteka::NadjiKorisnika(int clanski_broj)
{
    auto it = korisnici.find(clanski_broj);
    if(it == korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
    return *it->second;
}
Knjiga& Biblioteka::NadjiKnjigu(int evidencijski_broj)
{
    auto it = knjige.find(evidencijski_broj);
    if(it == knjige.end()) throw std::logic_error("Knjiga nije nadjena");
    return *it->second;
}
void Biblioteka::IspisiKorisnika(int clanski_broj, const Korisnik& korisnik)const
{
    std::cout<<"Clanski broj: "<< clanski_broj<< "\n";
    std::cout<<"Ime i prezime: "<< korisnik.ime<<" "<<korisnik.prezime<<"\n";
    std::cout<<"Adresa: "<<korisnik.adresa<< "\n";
    std::cout<<"Broj telefona: "<<korisnik.telefon<<"\n";
}
void Biblioteka::IspisiKnjigu(int evidencijski_broj, const Knjiga& knjiga,bool x)const
{
    std::cout<<"Evidencijski broj: "<<evidencijski_broj<<"\n";
    std::cout<<"Naslov: "<<knjiga.DajNaslov()<<"\n";
    std::cout<<"Pisac: "<<knjiga.DajAutora()<<"\n";
    std::cout<<"Zanr: "<<knjiga.DajZanr()<<"\n";
    std::cout<<"Godina izdavanja: "<<knjiga.DajGodinuIzdavanja()<<"\n";
    if(x && knjiga.DaLiJeZaduzena())
    {
        std::cout<< "Zaduzena kod korisnika: "<< knjiga.DajKodKogaJe()->ime<<" "<< knjiga.DajKodKogaJe()->prezime;
    }
}
void Biblioteka::IzlistajKorisnike()const
{
    for(auto e: korisnici)
    {
        Biblioteka::IspisiKorisnika(e.first, *e.second);
        std::cout<<"\n";
    }
}
void Biblioteka::IzlistajKnjige()const
{
    for(auto e: knjige)
    {
        Biblioteka::IspisiKnjigu(e.first, *e.second);
        std::cout<<"\n";
    }
}
void Biblioteka::ZaduziKnjigu(int evidencijski_broj, int clanski_broj)
{
    Knjiga& knjiga = NadjiKnjigu(evidencijski_broj);
    Korisnik& korisnik = NadjiKorisnika(clanski_broj);
    if(knjiga.DaLiJeZaduzena()) throw std::logic_error("Knjiga vec zaduzena");
    knjiga.ZaduziKnjigu(korisnik);
}
void Biblioteka::RazduziKnjigu(int evidencijski_broj)
{
    Knjiga& knjiga = NadjiKnjigu(evidencijski_broj);
    if(!knjiga.DaLiJeZaduzena()) throw std::logic_error("Knjiga nije zaduzena");
    knjiga.RazduziKnjigu();
}
void Biblioteka::PrikaziZaduzenja(int clanski_broj)
{
    Korisnik& korisnik = NadjiKorisnika(clanski_broj);
    bool ima_ih = false;
    for(auto e: knjige)
    {
        if(korisnik == *(e.second)->DajKodKogaJe())
        {
            ima_ih = true;
            Biblioteka::IspisiKnjigu(e.first, *e.second,false);
            std::cout<<"\n";
        }
    }
    if(!ima_ih) std::cout<<"Nema zaduzenja za tog korisnika!\n";
}
int main ()
{
    Biblioteka bibl;
    Biblioteka b2(bibl);
    b2 = bibl;
    b2.RegistrirajNovogKorisnika(5,"AAAA","AAAA","012-345","Cekrcici Donji bb");
    b2.RegistrirajNovogKorisnika(43,"BBBB","BBBB","012-346","Cekrcici Donji 1");
    b2.RegistrirajNovuKnjigu(432,"UUUU","AAAA","BAJKA",1999);
    b2.RegistrirajNovuKnjigu(4321,"EEEE","BBBB","BAJKA",1999);
    b2.ZaduziKnjigu(432, 5);
    b2.PrikaziZaduzenja(5);
    bibl = Biblioteka();
    Biblioteka b(b2 = bibl);
    b.IzlistajKnjige();
	return 0;
	return 0;
}