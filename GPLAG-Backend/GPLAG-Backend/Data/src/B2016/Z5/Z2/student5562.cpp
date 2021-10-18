/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <new>
#include <string>
#include <map>
#include <utility>
#include <algorithm>
#include <stdexcept>
#include <memory>

struct Korisnik
{
    std::string ime, prezime, adresa, telefon;    
};


class Knjiga
{
    std::string naslov, ime_pisca, zanr;
    int godina_izdavanja;
    Korisnik* korisnik;
public:
    Knjiga(const std::string &naslov, const std::string &ime_pisca, const std::string &zanr, int godina_izdavanja): naslov(naslov), ime_pisca(ime_pisca), zanr(zanr), godina_izdavanja(godina_izdavanja), korisnik(nullptr){}
    std::string DajNaslov()const{ return naslov; }
    std::string DajAutora()const{ return ime_pisca; }
    std::string DajZanr()const{ return zanr; }
    int DajGodinuIzdavanja()const{ return godina_izdavanja; }
    Korisnik* DajKodKogaJe()const{ return korisnik;}
    void ZaduziKnjigu(Korisnik &korisnik){Knjiga::korisnik = &korisnik;}
    void RazduziKnjigu(){korisnik = nullptr;}
    bool DaLiJeZaduzena(){return korisnik;}
};


class Biblioteka
{
    std::map<int, std::shared_ptr<Korisnik>> korisnici;
    std::map<int, std::shared_ptr<Knjiga>> knjige;
    void IspisiKorisnika(const std::pair<int, std::shared_ptr<Korisnik>> &korisnik) const;
    void IspisiKnjigu(const std::pair<int, std::shared_ptr<Knjiga>> &knjiga)const;
    std::pair<int, std::shared_ptr<Korisnik>> KodKogaJe(const std::pair<int, std::shared_ptr<Knjiga>> &knjiga)const;
public:
    Biblioteka() = default;
    Biblioteka(const Biblioteka &b);
    Biblioteka(Biblioteka &&b) = default;
    //~Biblioteka();
    Biblioteka &operator=(const Biblioteka &b);
    Biblioteka &operator=(Biblioteka &&b) = default;
    void RegistrirajNovogKorisnika(int clanski_broj, const std::string &ime, const std::string &prezime, const std::string &adresa, const std::string &telefon);
    void RegistrirajNovuKnjigu(int evidencijski_broj, const std::string &naslov, const std::string &ime_pisca, const std::string &zanr, int godina_izdavanja);
    Korisnik &NadjiKorisnika(int clanski_broj);
    Knjiga &NadjiKnjigu(int evidencijski_broj);
    void IzlistajKorisnike() const;
    void IzlistajKnjige()const;
    void ZaduziKnjigu(int evidencijski_broj, int clanski_broj);
    void RazduziKnjigu(int evidencijski_broj);
    void PrikaziZaduzenja(int clanski_broj)const;
};

Biblioteka::Biblioteka(const Biblioteka &b)
{
    try
    {
        for (auto korisnik:b.korisnici)
            korisnici.insert(std::make_pair(korisnik.first, std::make_shared<Korisnik>(*korisnik.second)));
        for (auto knjiga:b.knjige)
        {
            //knjige.insert(std::make_pair(knjiga.first, std::make_shared<Knjiga>(*knjiga.second)));
            auto p(std::make_shared<Knjiga>(*knjiga.second));
            knjige.insert(std::make_pair(knjiga.first, p));
            int broj;
            for (auto korisnik:b.korisnici) if (korisnik.second.get() == knjiga.second->DajKodKogaJe()){ broj = korisnik.first;
            p->RazduziKnjigu(); ZaduziKnjigu(knjiga.first, broj);}
        }
    }
    catch (std::bad_alloc)
    {
        throw;
    }
}
/*Biblioteka::~Biblioteka()
{
    for (auto korisnik:korisnici) delete korisnik.second;
    for (auto knjiga:knjige) delete knjiga.second;
}*/
Biblioteka &Biblioteka::operator=(const Biblioteka &b)
{
    std::map<int, std::shared_ptr<Korisnik>> korisnici2;
    std::map<int, std::shared_ptr<Knjiga>> knjige2;
    try
    {
        for (auto korisnik:b.korisnici)
            korisnici2.insert(std::make_pair(korisnik.first, std::make_shared<Korisnik>(*korisnik.second)));
        for (auto knjiga:b.knjige)
            knjige2.insert(std::make_pair(knjiga.first, std::make_shared<Knjiga>(*knjiga.second)));
    }
    catch (std::bad_alloc)
    {
        throw;
    }
    korisnici = korisnici2;
    knjige = knjige2;
    for (auto knjiga:b.knjige)
    {
        int broj;
        for (auto korisnik:b.korisnici) if (korisnik.second.get() == knjiga.second->DajKodKogaJe()){ broj = korisnik.first;
        RazduziKnjigu(knjiga.first); ZaduziKnjigu(knjiga.first, broj);}
    }
    return *this;
}
void Biblioteka::RegistrirajNovogKorisnika(int clanski_broj, const std::string &ime, const std::string &prezime, const std::string &adresa, const std::string &telefon)
{
    if (korisnici.count(clanski_broj))
        throw std::logic_error("Korisnik vec postoji");
    korisnici.insert(std::make_pair(clanski_broj, std::make_shared<Korisnik>(Korisnik{ime, prezime, adresa, telefon})));
}
void Biblioteka::RegistrirajNovuKnjigu(int evidencijski_broj, const std::string &naslov, const std::string &ime_pisca, const std::string &zanr, int godina_izdavanja)
{
    if (knjige.count(evidencijski_broj))
        throw std::logic_error("Knjiga vec postoji");
    knjige.insert(std::make_pair(evidencijski_broj, std::make_shared<Knjiga>(naslov, ime_pisca, zanr, godina_izdavanja)));
}
Korisnik &Biblioteka::NadjiKorisnika(int clanski_broj)
{
    auto k(korisnici.find(clanski_broj));
    if (k == korisnici.end())
        throw std::logic_error("Korisnik nije nadjen");
    return *k->second;
}
Knjiga &Biblioteka::NadjiKnjigu(int evidencijski_broj)
{
    auto k(knjige.find(evidencijski_broj));
    if (k == knjige.end())
        throw std::logic_error("Knjiga nije nadjena");
    return *k->second;
}
void Biblioteka::IzlistajKorisnike()const
{
    for (auto korisnik:korisnici)
    {
        IspisiKorisnika(korisnik);
        std::cout << std::endl;
    }
}
void Biblioteka::IzlistajKnjige()const
{
    for (auto knjiga:knjige)
    {
        IspisiKnjigu(knjiga);
        if (knjiga.second->DaLiJeZaduzena())
            std::cout << "Zaduzena kod korisnika: " << knjiga.second->DajKodKogaJe()->ime << " " << knjiga.second->DajKodKogaJe()->prezime;
        std::cout << std::endl;
    }
}
void Biblioteka::ZaduziKnjigu(int evidencijski_broj, int clanski_broj)
{
    if (!knjige.count(evidencijski_broj))
        throw std::logic_error("Knjiga nije nadjena");
    if (knjige[evidencijski_broj]->DaLiJeZaduzena())
        throw std::logic_error("Knjiga vec zaduzena");
    if (!korisnici.count(clanski_broj))
        throw std::logic_error("Korisnik nije nadjen");
    knjige[evidencijski_broj]->ZaduziKnjigu(*korisnici[clanski_broj]);
}
void Biblioteka::RazduziKnjigu(int evidencijski_broj)
{
    if (!knjige.count(evidencijski_broj))
        throw std::logic_error("Knjiga nije nadjena");
    if (!knjige[evidencijski_broj]->DaLiJeZaduzena())
        throw std::logic_error("Knjiga nije zaduzena");
    knjige[evidencijski_broj]->RazduziKnjigu();
}
void Biblioteka::IspisiKorisnika(const std::pair<int, std::shared_ptr<Korisnik>> &korisnik)const
{
    std::cout << "Clanski broj: " << korisnik.first << std::endl;
    std::cout << "Ime i prezime: " << korisnik.second->ime << " " << korisnik.second->prezime << std::endl;
    std::cout << "Adresa: " << korisnik.second->adresa << std::endl;
    std::cout << "Broj telefona: " << korisnik.second->telefon << std::endl;
    std::cout << std::endl;
}
void Biblioteka::IspisiKnjigu(const std::pair<int, std::shared_ptr<Knjiga>> &knjiga)const
{
    std::cout << "Evidencijski broj: " << knjiga.first << std::endl;
    std::cout << "Naslov: " << knjiga.second->DajNaslov() << std::endl;
    std::cout << "Pisac: " << knjiga.second->DajAutora() << std::endl;
    std::cout << "Zanr: " << knjiga.second->DajZanr() << std::endl;
    std::cout << "Godina izdavanja: " << knjiga.second->DajGodinuIzdavanja() << std::endl;
        
}
void Biblioteka::PrikaziZaduzenja(int clanski_broj)const
{
    if (!korisnici.count(clanski_broj))
        throw std::domain_error("Korisnik nije nadjen");
    bool nadjena(false);
    for (auto knjiga:knjige)
        if (knjiga.second->DajKodKogaJe() == korisnici.find(clanski_broj)->second.get())
        {
            nadjena = true;
            IspisiKnjigu(knjiga);
            std::cout << std::endl;
        }
    if (!nadjena)
        std::cout << "Nema zaduzenja za tog korisnika!" << std::endl;
}

void Ignore()
{
    std::cin.ignore(1000, '\n');
}
int main ()
{
    Biblioteka biblioteka;
    for(;;)
    {
        int opcija1;
        std::cout << "\nIzaberite opciju:\n 0 - kraj\n 1 - uredjivanje korisnika\n 2 - uredjivanje knjiga\n";
        std::cin >> opcija1; Ignore();
        if (opcija1 == 0) break;
        else if (opcija1 == 1)
        {
            for (;;)
            {
                int opcija2;
                std::cout << "\nIzaberite opciju:\n 0 - nazad\n 1 - registriraj novog korisnika\n 2 - nadji korisnika\n 3 - izlistaj korisnike\n 4 - prikazi zaduzenja korisnika\n";
                std::cin >> opcija2; Ignore();
                if (opcija2 == 0) break;
                else if (opcija2 == 1)
                {
                    std::string ime, prezime, adresa, telefon;
                    int clanski_broj;
                    std::cout << "Unesite clanski broj korisnika: "; std::cin >> clanski_broj; Ignore();
                    std::cout << "Unesite ime korisnika: "; std::getline(std::cin, ime);
                    std::cout << "Unesite prezime korisnika: "; std::getline(std::cin, prezime);
                    std::cout << "unesite adresu korisnika: "; std::getline(std::cin, adresa);
                    std::cout << "Unesite broj telefona korisnika: "; std::getline(std::cin, telefon);
                    try
                    {
                        biblioteka.RegistrirajNovogKorisnika(clanski_broj, ime, prezime, adresa, telefon);
                        std::cout << "Korisnik uspjesno registriran!\n";
                    }
                    catch (std::logic_error e)
                    {
                        std::cout << e.what() << std::endl;
                    }
                }
                else if (opcija2 == 2)
                {
                    int clanski_broj;
                    std::cout << "Unesite clanski broj korisnika: ";
                    std::cin >> clanski_broj; Ignore();
                    try
                    {
                        Korisnik korisnik(biblioteka.NadjiKorisnika(clanski_broj));
                        std::cout << "Korisnik sa clanskim brojem " << clanski_broj << " je: " << korisnik.ime << " " << korisnik.prezime << ", zivi na adresi: " << korisnik.adresa << ", br. telefona: " << korisnik.telefon << "." << std::endl;
                    }
                    catch(std::logic_error e)
                    {
                        std::cout << e.what() << std::endl;
                    }
                }
                else if (opcija2 == 3)
                {
                    std::cout << "Registrirani korisnici u biblioteci su:\n";
                    biblioteka.IzlistajKorisnike();
                }
                else if (opcija2 == 4)
                {
                    int clanski_broj;
                    std::cout << "Unesite clanski broj korisnika: ";
                    std::cin >> clanski_broj; Ignore();
                    try
                    {
                        biblioteka.PrikaziZaduzenja(clanski_broj);
                    }
                    catch(std::domain_error e)
                    {
                        std::cout << e.what() << std::endl;
                    }
                }
            }
        }
        else if (opcija1 == 2)
        {
            for(;;)
            {
                int opcija2;
                std::cout << "\nIzaberite opciju:\n 0 - nazad\n 1 - registriraj novu knjigu\n 2 - nadji knjigu\n 3 - izlistaj knjige\n 4 - zaduzi knjigu\n 5 - razduzi knjigu\n";
                std::cin >> opcija2; Ignore();
                if (opcija2 == 0) break;
                else if (opcija2 == 1)
                {
                    int evidencijski_broj, godina_izdavanja;
                    std::string naslov, pisac, zanr;
                    std::cout << "Unesite evidencijski_broj: "; std::cin >> evidencijski_broj; Ignore();
                    std::cout << "Unesite naslov: "; std::getline(std::cin, naslov);
                    std::cout << "Unesite autora: "; std::getline(std::cin, pisac);
                    std::cout << "Unesite zanr: "; std::getline(std::cin, zanr);
                    std::cout << "Unesite godinu izdavanja: "; std::cin >> godina_izdavanja; Ignore();
                    try
                    {
                        biblioteka.RegistrirajNovuKnjigu(evidencijski_broj, naslov, pisac, zanr, godina_izdavanja);
                        std::cout << "Knjiga je uspjesno registrirana!\n";
                    }
                    catch (std::logic_error e)
                    {
                        std::cout << e.what() << std::endl;
                    }
                }
                else if (opcija2 == 2)
                {
                    int evidencijski_broj;
                    std::cout << "Unesite evidencijski broj knjige: "; std::cin >> evidencijski_broj; Ignore();
                    try
                    {
                        Knjiga knjiga(biblioteka.NadjiKnjigu(evidencijski_broj));
                        std::cout << "Knjiga s evidencijskim brojem " << evidencijski_broj << " je " << knjiga.DajNaslov() << ", autora " << knjiga.DajAutora() << ", zanr " << knjiga.DajZanr() << " izdata " << knjiga.DajGodinuIzdavanja() << ". godine" << std::endl;
                    }
                    catch (std::logic_error e)
                    {
                        std::cout << e.what() << std::endl;
                    }
                }
                else if (opcija2 == 3)
                {
                    std::cout << "Registrirane knjige u biblioteci su:\n";
                    biblioteka.IzlistajKnjige();
                }
                else if (opcija2 == 4)
                {
                    int clanski_broj, evidencijski_broj;
                    std::cout << "Unesite evidencijski_broj knjige: "; std::cin >> evidencijski_broj; Ignore();
                    std::cout << "Unesite clanski broj korisnika: "; std::cin >> clanski_broj; Ignore();
                    try
                    {
                        biblioteka.ZaduziKnjigu(evidencijski_broj, clanski_broj);
                        std::cout << "Knjiga uspjesno zaduzena!\n";
                    }
                    catch(std::logic_error e)
                    {
                        std::cout << e.what() << std::endl;
                    }
                }
                else if (opcija2 == 5)
                {
                    int evidencijski_broj;
                    std::cout << "Unesi evidencijski broj knjige: "; std::cin >> evidencijski_broj; Ignore();
                    try
                    {
                        biblioteka.RazduziKnjigu(evidencijski_broj);
                        std::cout << "Knjiga uspjesno razduzena!\n";
                    }
                    catch(std::logic_error e)
                    {
                        std::cout << e.what() << std::endl;
                    }
                }
            }
            
        }
    }
	return 0;
}