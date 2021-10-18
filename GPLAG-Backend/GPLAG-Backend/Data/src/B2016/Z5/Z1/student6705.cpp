/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <string>
#include <map>
#include <algorithm>
#include <functional>

struct Korisnik
{
    std::string ime;
    std::string prezime;
    std::string adresa;
    std::string telefon;
    void UnosKorisnika(std::string i,std::string p,std::string a,std::string t){
        ime = i; prezime = p; adresa = a; telefon = t;
    }
};

class Knjiga
{
    std::string naslov_knjige;
    std::string ime_pisca;  
    std::string zanr_knjige;
    int godina_izdavanja_knjige;
    Korisnik* zaduzenje = nullptr;
public:
    Knjiga(std::string naslov, std::string ime, std::string zanr, int godina): naslov_knjige(naslov),
        ime_pisca(ime), zanr_knjige(zanr), godina_izdavanja_knjige(godina){}
    std::string DajNaslov() const{ return naslov_knjige;}
    std::string DajAutora() const{ return ime_pisca;}
    std::string DajZanr() const{ return zanr_knjige;}
    int DajGodinuIzdavanja() const{ return godina_izdavanja_knjige;}
    Korisnik* DajKodKogaJe() const{ return zaduzenje;}
    void ZaduziKnjigu(Korisnik& korisnik){
        zaduzenje = &korisnik;
    }
    void RazduziKnjigu(){
        zaduzenje = nullptr;
    }
    bool DaLiJeZaduzena() const{
        return (zaduzenje != nullptr);
    }
};
class Biblioteka
{
    std::map<int, Korisnik*> korisnici;
    std::map<int, Knjiga*> knjige;
    void Dealociraj();
    public:
    Biblioteka() = default;
    ~Biblioteka(){
        Dealociraj();
    }
    Biblioteka(const Biblioteka &b);
    Biblioteka(Biblioteka &&b);
    Biblioteka &operator =(const Biblioteka &b);
    Biblioteka &operator =(Biblioteka &&b);
    void RegistrirajNovogKorisnika(int clanski, std::string ime, std::string prezime,
        std::string adresa, std::string telefon);
    void RegistrirajNovuKnjigu(int evidencijski, std::string naslov, std::string ime, 
        std::string zanr, int godina);
    void IzlistajKorisnike() const;
    void IzlistajKnjige() const;
    Korisnik& NadjiKorisnika(int clanski) const;
    Knjiga& NadjiKnjigu(int evidencijski) const;
    void ZaduziKnjigu(int evidencijski, int clanski);
    void RazduziKnjigu(int evidencijski);
    void PrikaziZaduzenja(int clanski) const;
};
void Biblioteka::Dealociraj()
{
    for(auto it = korisnici.begin(); it != korisnici.end(); it++)
        delete it->second;
    for(auto it = knjige.begin(); it != knjige.end(); it++)
        delete it->second;
    korisnici.clear();
    knjige.clear();
}
void Biblioteka::RegistrirajNovogKorisnika(int clanski, std::string ime, std::string prezime,
        std::string adresa, std::string telefon)
    {
        if(korisnici.count(clanski))
            throw std::logic_error("Korisnik vec postoji");
        Korisnik* novi = new Korisnik;
        novi->UnosKorisnika(ime, prezime, adresa, telefon);
        korisnici.insert(std::make_pair(clanski, novi));
    }
void Biblioteka::RegistrirajNovuKnjigu(int evidencijski, std::string naslov, std::string ime, 
        std::string zanr, int godina)
    {
        if(knjige.count(evidencijski))
            throw std::logic_error("Knjiga vec postoji");
        knjige[evidencijski] = new Knjiga(naslov, ime, zanr, godina);
    }
void Biblioteka::IzlistajKorisnike() const
{
    for(auto it = korisnici.begin(); it != korisnici.end(); it++)
    {
        std::cout << "Clanski broj: " << it->first << std::endl << "Ime i prezime: " << 
            it->second->ime << " " << it->second->prezime << std::endl << "Adresa: " << 
            it->second->adresa << std::endl << "Broj telefona: " << it->second->telefon
            << std::endl << std::endl;
    }
}
void Biblioteka::IzlistajKnjige() const
{
    for(auto it = knjige.begin(); it != knjige.end(); it++)
    {
        std::cout << "Evidencijski broj: " << it->first << std::endl << "Naslov: " << 
            it->second->DajNaslov() << std::endl << "Pisac: " << it->second->DajAutora()
            << std::endl << "Zanr: " << it->second->DajZanr() << std::endl <<
            "Godina izdavanja: " << it->second->DajGodinuIzdavanja() << std::endl;
        if(it->second->DaLiJeZaduzena())
            std::cout << "Zaduzena kod korisnika: " << it->second->DajKodKogaJe()->ime 
            << " " << it->second->DajKodKogaJe()->prezime << std::endl;
        std::cout << std::endl;
    }
}
Korisnik& Biblioteka::NadjiKorisnika(int clanski) const
{
    auto it = korisnici.begin();
    for(; it != korisnici.end(); it++)
        if(it->first == clanski)
            return *it->second;
    throw std::logic_error("Korisnik nije nadjen");
}
Knjiga& Biblioteka::NadjiKnjigu(int evidencijski) const
{
    auto it = knjige.begin();
    for(; it != knjige.end(); it++)
        if(it->first == evidencijski)
            return *it->second;
    throw std::logic_error("Knjiga nije nadjena");
}
void Biblioteka::ZaduziKnjigu(int evidencijski, int clanski)
{
    auto &k = NadjiKnjigu(evidencijski);
    auto &c = NadjiKorisnika(clanski);
    if(k.DaLiJeZaduzena())
        throw std::logic_error("Knjiga vec zaduzena");
    k.ZaduziKnjigu(c);
}
void Biblioteka::RazduziKnjigu(int evidencijski)
{
    auto &k = NadjiKnjigu(evidencijski);
    if(!k.DaLiJeZaduzena())
        throw std::logic_error("Knjiga nije zaduzena");
    k.RazduziKnjigu();
}
void Biblioteka::PrikaziZaduzenja(int clanski) const
{
    auto &k = NadjiKorisnika(clanski);
    int brojac = 0;
    for(auto it = knjige.begin(); it != knjige.end(); it++)
        if(it->second->DajKodKogaJe() == &k)
        {
            std::cout << "Evidencijski broj: " << it->first << std::endl << "Naslov: " << 
            it->second->DajNaslov() << std::endl << "Pisac: " << it->second->DajAutora()
            << std::endl << "Zanr: " << it->second->DajZanr() << std::endl <<
            "Godina izdavanja: " << it->second->DajGodinuIzdavanja() << std::endl << std::endl;
            brojac++;
        }
    if(brojac == 0)
        std::cout << "Nema zaduzenja za tog korisnika!" << std::endl;
}
Biblioteka::Biblioteka(const Biblioteka &b)
{
    try{
        for(auto it = b.korisnici.begin(); it != b.korisnici.end(); it++)
            korisnici[it->first] = new Korisnik(*it->second);
        for(auto it = b.knjige.begin(); it != b.knjige.end(); it++)
            knjige[it->first] = new Knjiga(*it->second);
    }
    catch(std::bad_alloc){
        Dealociraj();
        throw;
    }
}
Biblioteka::Biblioteka(Biblioteka &&b)
{
    korisnici = b.korisnici;
    knjige = b.knjige;
    b.korisnici.clear();
    b.knjige.clear();
}
Biblioteka &Biblioteka::operator =(const Biblioteka &b)
{
    if(&b == this) return *this;
    Dealociraj();
    try{
        for(auto it = b.korisnici.begin(); it != b.korisnici.end(); it++)
            korisnici[it->first] = new Korisnik(*it->second);
        for(auto it = b.knjige.begin(); it != b.knjige.end(); it++)
            knjige[it->first] = new Knjiga(*it->second);
    }
    catch(std::bad_alloc){
        Dealociraj();
        throw;
    }
    return *this;
}
Biblioteka &Biblioteka::operator =(Biblioteka &&b)
{
    if(&b == this) return *this;
    Dealociraj();
    korisnici = b.korisnici;
    knjige = b.knjige;
    b.korisnici.clear();
    b.knjige.clear();    
    return *this;
}
int Meni()
{
    int i(0);
    while (i < 1 || i > 8) {
        std::cout << "Meni: " << std::endl << "1. Dodaj novog korisnika!" << std::endl << 
            "2. Dodaj novu knjigu!" << std::endl << "3. Izlistaj korisnike!" << std::endl <<
            "4. Izlistaj knjige!" << std::endl << "5. Zaduzi knjigu!" << std::endl << 
            "6. Razduzi knjigu!" << std::endl << "7. Prikazi zaduzenje" << std::endl <<
            "8. Kraj Programa!" << std::endl;
            
        std::cin >> i;
    }
    return i;
}
int main(){
    try
    {
        Biblioteka b;
        int k(1);
        while (k != 8) {
            k = Meni();
            if(k == 1)
            {
                try
                {
                    int clanski;
                    std::cout << "Unesite clanski broj novog korisnika: ";
                    std::cin >> clanski;
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    std::string ime, prezime, adresa, broj;
                    std::cout << "Unesite ime pa prezime novog korisnika: ";
                    std::getline(std::cin, ime);
                    std::getline(std::cin, prezime);
                    std::cout << "Unesite adresu novog korisnika: ";
                    std::getline(std::cin, adresa);
                    std::cout << "Unesite broj telefona novog korisnika: ";
                    std::getline(std::cin, broj);
                    b.RegistrirajNovogKorisnika(clanski, ime, prezime, adresa, broj);
                }
                catch(std::logic_error e){
                    std::cout << e.what() << std::endl;
                }
            }
            else if(k == 2)
            {
                try
                {
                    int evidencijski;
                    std::cout << "Unesite evidencijski broj nove knjige: ";
                    std::cin >> evidencijski;
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    std::string naziv, pisac, zanr;
                    std::cout << "Unesite naziv nove knjige: ";
                    std::getline(std::cin, naziv);
                    std::cout << "Unesite naziv autora nove knjige: ";
                    std::getline(std::cin, pisac);
                    std::cout << "Unesite zanr nove knjige: ";
                    std::getline(std::cin, zanr);
                    int godina;
                    std::cout << "Unesite godinu izdavanja knjige: ";
                    std::cin >> godina;
                    b.RegistrirajNovuKnjigu(evidencijski, naziv, pisac, zanr, godina);
                }
                catch(std::logic_error e){
                    std::cout << e.what() << std::endl;
                }
            }
            else if(k == 3)
            {
                std::cout << "Korisnici: " << std::endl;
                b.IzlistajKorisnike();
                std::cout << std::endl;
            }
            else if(k == 4)
            {
                std::cout << "Knjige: " << std::endl;
                b.IzlistajKnjige();
                std::cout << std::endl;
            }
            else if(k == 5)
            {
                try
                {
                    int evidencijski, clanski;
                    std::cout << "Unesite clanski broj korisnika koji zaduzuje knjigu: ";
                    std::cin >> clanski;
                    std::cout << "Unesite evidencijski broj knjige koja se zaduzuje: ";
                    std::cin >> evidencijski;
                    b.ZaduziKnjigu(evidencijski, clanski);
                }
                catch(std::logic_error e)
                {
                    std::cout << e.what() << std::endl;
                }
            }
            else if(k == 6)
            {
                try
                {
                    int evidencijski;
                    std::cout << "Unesite evidencijski broj knjige koja se razduzuje: ";
                    std::cin >> evidencijski;
                    b.RazduziKnjigu(evidencijski);
                }
                catch(std::logic_error e)
                {
                    std::cout << e.what() << std::endl;
                }
            }
            else if(k == 7)
            {
                std::cout << "Unesite clanski broj korisnika za kojeg zelite prikazati zaduzenja: ";
                int clanski;
                std::cin >> clanski;
                std::cout << "Zaduzenja: " << std::endl;
                b.PrikaziZaduzenja(clanski);
                std::cout << std::endl;
            }
        }
    }
    catch(std::bad_alloc){
        std::cout << "Problemi sa memorijom!";
    }
    return 0;
}
