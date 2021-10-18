/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include <memory>

struct Korisnik
{
    std::string ime, prezime, adresa, telefon;
};
class Knjiga
{
    Korisnik* Zaduzenje = nullptr;
    std::string Naslov;
    std::string ImePisca;
    std::string Zanr;
    int GodinaIzdavanja;
public:
    Knjiga(std::string naslov, std::string imepisca, std::string zanr, int godinaizdavanja): Naslov(naslov), 
        ImePisca(imepisca), Zanr(zanr), GodinaIzdavanja(godinaizdavanja){}
    std::string DajNaslov() const {return Naslov;}
    std::string DajAutora() const {return ImePisca;}
    std::string DajZanr() const {return Zanr;}
    int DajGodinuIzdavanja() const {return GodinaIzdavanja;}
    Korisnik* DajKodKogaJe() const {return Zaduzenje;}
    void ZaduziKnjigu(Korisnik& korisnik) {Zaduzenje = &korisnik;}
    void RazduziKnjigu() {Zaduzenje = nullptr;}
    bool DaLiJeZaduzena() const
    {
        if(Zaduzenje == nullptr)
            return false;
        return true;
    }
};

class Biblioteka
{
    std::map<int, std::shared_ptr<Korisnik>> Korisnici;
    std::map<int, std::shared_ptr<Knjiga>> Knjige;
    public:
    Biblioteka(){}
    void RegistrirajNovogKorisnika(int clanski, std::string ime, std::string prezime, std::string adresa, std::string broj);
    void RegistrirajNovuKnjigu(int brojknjige, std::string naslov, std::string ime, std::string zanr, int godina);
    Korisnik& NadjiKorisnika(int clanski) const;
    Knjiga& NadjiKnjigu(int brojknjige) const;
    void IzlistajKorisnike() const;
    void IzlistajKnjige() const;
    void ZaduziKnjigu(int brojknjige, int clanski);
    void RazduziKnjigu(int brojknjige);
    void PrikaziZaduzenja(int clanski) const;
};
void Biblioteka::RegistrirajNovogKorisnika(int clanski, std::string ime, std::string prezime, std::string adresa, std::string broj)
{
        auto it(Korisnici.find(clanski));
        if(it == Korisnici.end());
        else
            throw std::logic_error("Korisnik vec postoji");
        std::shared_ptr<Korisnik> temp = std::make_shared<Korisnik>();
        temp->ime = ime;
        temp->prezime = prezime;
        temp->adresa = adresa;
        temp->telefon = broj;
        Korisnici.insert(std::make_pair(clanski, temp));
    
}
void Biblioteka::RegistrirajNovuKnjigu(int brojknjige, std::string naslov, std::string ime, std::string zanr, int godina)
{
    
        auto it(Knjige.find(brojknjige));
        if(it == Knjige.end());
        else
            throw std::logic_error("Knjiga vec postoji");
        auto temp = std::make_shared<Knjiga>(naslov, ime, zanr, godina);
        Knjige.insert(std::make_pair(brojknjige, temp));
}
Korisnik& Biblioteka::NadjiKorisnika(int clanski) const
{
    auto it(Korisnici.find(clanski));
    if(it == Korisnici.end())
        throw std::logic_error("Korisnik nije nadjen");
    else
        return *it->second;
}
Knjiga& Biblioteka::NadjiKnjigu(int brojknjige) const
{
    auto it(Knjige.find(brojknjige));
    if(it == Knjige.end())
        throw std::logic_error("Knjiga nije nadjena");
    else
        return *it->second;
}
void Biblioteka::IzlistajKorisnike() const
{
    for(auto it = Korisnici.begin(); it != Korisnici.end(); it++)
    {
        std::cout << "Clanski broj: " << it->first << std::endl;
        std::cout << "Ime i prezime: " << it->second->ime << " " << it->second->prezime << std::endl;
        std::cout << "Adresa: " << it->second->adresa << std::endl;
        std::cout << "Broj telefona: " << it->second->telefon << std::endl << std::endl;
    }
}
void Biblioteka::IzlistajKnjige() const
{
    for(auto it = Knjige.begin(); it != Knjige.end(); it++)
    {
        std::cout << "Evidencijski broj: " << it->first << std::endl;
        std::cout << "Naslov: " << it->second->DajNaslov() << std::endl;
        std::cout << "Pisac: " << it->second->DajAutora() << std::endl;
        std::cout << "Zanr: " << it->second->DajZanr() << std::endl;
        std::cout << "Godina izdavanja: " << it->second->DajGodinuIzdavanja() << std::endl;
        if(it->second->DaLiJeZaduzena() == true)
            std::cout << "Zaduzena kod korisnika: " << it->second->DajKodKogaJe()->ime << " " 
                << it->second->DajKodKogaJe()->prezime << std::endl;
        
        std::cout << std::endl;
    }
}
void Biblioteka::ZaduziKnjigu(int brojknjige, int clanski)
{
    auto &knjiga = NadjiKnjigu(brojknjige);
    auto &korisnik = NadjiKorisnika(clanski);
    if(knjiga.DaLiJeZaduzena() == true)
        throw std::logic_error("Knjiga vec zaduzena");
    knjiga.ZaduziKnjigu(korisnik);
}
void Biblioteka::RazduziKnjigu(int brojknjige)
{
    auto &knjiga = NadjiKnjigu(brojknjige);
    if(knjiga.DaLiJeZaduzena() != true)
        throw std::logic_error("Knjiga nije zaduzena");
    knjiga.RazduziKnjigu();
}
void Biblioteka::PrikaziZaduzenja(int clanski) const
{
    auto &korisnik = NadjiKorisnika(clanski);
    int temp = 0;
    for(auto it = Knjige.begin(); it != Knjige.end(); it++)
    {
        if(it->second->DajKodKogaJe() == &korisnik)
        {
            std::cout << "Evidencijski broj: " << it->first << std::endl;
            std::cout << "Naslov: " << it->second->DajNaslov() << std::endl;
            std::cout << "Pisac: " << it->second->DajAutora() << std::endl;
            std::cout << "Zanr: " << it->second->DajZanr() << std::endl;
            std::cout << "Godina izdavanja: " << it->second->DajGodinuIzdavanja() << std::endl << std::endl;
            temp++;
        }
    } 
    if(temp == 0)
        std::cout << "Nema zaduzenja za tog korisnika!" << std::endl;
}
int main ()
{
    Biblioteka niz;
    int n = 1;
    while (n != 0) {
        std::cout << "0: Kraj\n1: Dodaj novog korisnika\n2: Dodaj novu knjigu\n3: Zaduzi knjigu\n4: Razduzi knjigu\n";
        std::cout << "5: Prikazi zaduzenja\n6: Ispisi korisnike\n7: Ispisi knjige:\n\n";
        std::cin >> n;
        if(n == 1)
        {
            int clanski;
            std::cout << "Unesite clanski: ";
            std::cin >> clanski;
            std::cin.ignore(1000, '\n');
            std::string ime, prezime, adresa, telefon;
            std::cout << "Unesite redom ime, prezime, adresu i broj telefona: ";
            std::getline(std::cin, ime);
            std::getline(std::cin, prezime);
            std::getline(std::cin, adresa);
            std::getline(std::cin, telefon);
            try
            {
                niz.RegistrirajNovogKorisnika(clanski, ime, prezime, adresa, telefon);
            }
            catch(const std::exception &t)
            {
                std::cout << t.what() << std::endl;
            }
        }
        else if(n == 2)
        {
            int clanski;
            std::cout << "Unesite broj knjige: ";
            std::cin >> clanski;
            std::cin.ignore(1000, '\n');
            std::string naslov, ime, zanr;
            std::cout << "Unesite redom naslov knjige, ime pisca, zanr knjige te godinu izdavanja";
            std::getline(std::cin, naslov);
            std::getline(std::cin, ime);
            std::getline(std::cin, zanr);
            int godina;
            std::cin >> godina;
            try
            {
                niz.RegistrirajNovuKnjigu(clanski, naslov, ime, zanr, godina);
            }
            catch(const std::exception &t)
            {
                std::cout << t.what() << std::endl;
            }
        }
        else if(n == 3)
        {
            try
            {
                int broj, clanski;
                std::cout << "Unesite broj knjige te clanski broj korisnika koji zaduzuje knjigu: ";
                std::cin >> broj;
                std::cin >> clanski;
                niz.ZaduziKnjigu(broj, clanski);
            }
            catch(const std::exception &t)
            {
                std::cout << t.what() << std::endl;
            }
        }
        else if(n == 4)
        {
             try
            {
                int broj;
                std::cout << "Unesite broj knjige koju zelite razduziti: ";
                std::cin >> broj;
                niz.RazduziKnjigu(broj);
            }
            catch(const std::exception &t)
            {
                std::cout << t.what() << std::endl;
            }
        }
        else if(n == 5)
        {
            std::cout << "Unesite clanski broj za koga zelite vidjeti zaduzenja: ";
            int clanski;
            std::cin >> clanski;
            niz.PrikaziZaduzenja(clanski);
        }
        else if(n == 6)
        {
            std::cout << "Korisnici: " << std::endl;
            niz.IzlistajKorisnike();
        }
        else if(n == 7)
        {
            std::cout << "Knjige: " << std::endl;
            niz.IzlistajKnjige();
        }
        else if(n == 0)
            std::cout << "Dovidjenja!";
        else
            std::cout << "Pogresan unos, unesite ponovo!\n";
    }
	return 0;
}