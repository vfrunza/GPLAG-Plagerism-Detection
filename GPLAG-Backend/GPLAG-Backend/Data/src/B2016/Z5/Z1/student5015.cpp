/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>

struct Korisnik
{
    std::string ime, prezime, adresa, telefon;
};

class Knjiga
{
    std::string naslov, ime_pisca, zanr;
    int godina;
    Korisnik *zaduzenje;
public:
    Knjiga(std::string n, std::string ime, std::string z, int god) : naslov(n), ime_pisca(ime), zanr(z), godina(god), zaduzenje(nullptr) {} 
    std::string DajNaslov() const { return naslov; }
    std::string DajZanr() const { return zanr; }
    std::string DajAutora() const { return ime_pisca; }
    int GodinuIzdavanja() const { return godina; }
    Korisnik DajKodKogaJe() const { return *zaduzenje; }
    void ZaduziKnjigu(Korisnik &k) { zaduzenje=&k; }
    void RazduziKnjigu() { zaduzenje=nullptr; }
    bool DaLiJeZaduzena() const { if (zaduzenje!=nullptr) return true; return false; }
};

class Biblioteka
{
    std::map<int, Korisnik*> mapa_korisnika;
    std::map<int, Knjiga*> mapa_knjiga;
public:
    Biblioteka() = default;
    Biblioteka(const Biblioteka &b)
    {
        std::map<int, Korisnik*> pomocna1;
        std::map<int, Knjiga*> pomocna2;
        Korisnik *pok1{};
        Knjiga *pok2{};
        try
        {
            for (auto it=b.mapa_korisnika.begin(); it!=b.mapa_korisnika.end(); it++)
            {
                pok1=new Korisnik(*(it->second));
                pomocna1.insert(std::make_pair(it->first, pok1));
            }
        }
        catch(...)
        {
            delete pok1;
            throw;
        }
        try
        {
            for (auto it=b.mapa_knjiga.begin(); it!=b.mapa_knjiga.end(); it++)
            {
                pok2=new Knjiga(*(it->second));
                pomocna2.insert(std::make_pair(it->first, pok2));
            }
        }
        catch(...)
        {
            delete pok2;
            throw;
        }
        mapa_korisnika=pomocna1;
        mapa_knjiga=pomocna2;
    }
    Biblioteka(Biblioteka &&b)
    {
        b.mapa_korisnika=mapa_korisnika;
        b.mapa_knjiga=mapa_knjiga;
        for (auto it=mapa_korisnika.begin(); it!=mapa_korisnika.end(); it++) it->second=nullptr;
        for (auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end(); it++) it->second=nullptr;
    }
    Biblioteka &operator =(const Biblioteka &b)
    {
        std::map<int, Korisnik*> pomocna1;
        std::map<int, Knjiga*> pomocna2;
        Korisnik *pok1{};
        Knjiga *pok2{};
        try
        {
            for (auto it=b.mapa_korisnika.begin(); it!=b.mapa_korisnika.end(); it++)
            {
                pok1=new Korisnik(*(it->second));
                pomocna1.insert(std::make_pair(it->first, pok1));
            }
        }
        catch(...)
        {
            delete pok1;
            throw;
        }
        try
        {
            for (auto it=b.mapa_knjiga.begin(); it!=b.mapa_knjiga.end(); it++)
            {
                pok2=new Knjiga(*(it->second));
                pomocna2.insert(std::make_pair(it->first, pok2));
            }
        }
        catch(...)
        {
            delete pok2;
            throw;
        }
        for (auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end(); it++) delete it->second, it->second=nullptr;
        for (auto it=mapa_korisnika.begin(); it!=mapa_korisnika.end(); it++) delete it->second, it->second=nullptr;
        mapa_korisnika=pomocna1;
        mapa_knjiga=pomocna2;
        return *this;
    }
    Biblioteka &operator =(Biblioteka &&b)
    {
        std::swap(mapa_korisnika, b.mapa_korisnika); std::swap(mapa_knjiga, b.mapa_knjiga);
        return *this;
    }
    void RegistrirajNovogKorisnika(int cl_br, std::string ime, std::string pr, std::string ad, std::string br_tel)
    {
        Korisnik k;
        k.ime=ime; k.prezime=pr; k.adresa=ad; k.telefon=br_tel;
        for (auto it=mapa_korisnika.begin(); it!=mapa_korisnika.end(); it++) 
            if (it->first==cl_br) throw std::logic_error("Korisnik vec postoji");
        mapa_korisnika[cl_br]=new Korisnik(k);
    }
    void RegistrirajNovuKnjigu(int ev_br, std::string nasl, std::string ime, std::string z, int god)
    {
        Knjiga *novi=new Knjiga(nasl, ime, z, god);
        for (auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end(); it++) 
            if (it->first==ev_br) throw std::logic_error("Knjiga vec postoji");
        mapa_knjiga[ev_br]=novi;
    }
    Korisnik &NadjiKorisnika(int br)
    { 
        if (!mapa_korisnika.count(br)) throw std::logic_error("Korisnik nije nadjen");
        return *mapa_korisnika[br];
    }
    Korisnik &NadjiKnjigu(int br) 
    { 
        if (!mapa_knjiga.count(br)) throw std::logic_error("Knjiga nije nadjena");
        return *mapa_knjiga[br];
    }
    void IzlistajKorisnike() const 
    {
        for (auto it=mapa_korisnika.begin(); it!=mapa_korisnika.end(); it++)
        {
            std::cout << "Clanski broj: " << it->first << std::endl;
            std::cout << "Ime i prezime: " << it->second->ime << " " << it->second->prezime << std::endl;
            std::cout << "Adresa: " << it->second->adresa << std::endl;
            std::cout << "Broj telefona " << it->second->telefon << std::endl;
         //   if (zaduzenje!=nullptr) std::cout << "Zaduzena kod korisnika: " << zaduzenje->ime << " " << zaduzenje->prezime << std::endl;
            std::cout << std::endl;
        }
    }
    
};


int main ()
{
	return 0;
}