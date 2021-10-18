/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <stdexcept>
#include <map>
#include <new>



struct Korisnik
{
    std::string ime;
    std::string prezime;
    std::string adresa;
    std::string telefon;
};

class Knjiga
{
    private:
    std::string naslov;
    std::string pisac;
    std::string zanr;
    int godina_izdavanja;
    Korisnik *zaduzenje;
    public:
    Knjiga(std::string naslov, std::string pisac, std::string zanr, int godina_izdavanja) : naslov(naslov),
    pisac(pisac), zanr(zanr), godina_izdavanja(godina_izdavanja), zaduzenje(nullptr) {}
    
    std::string DajNaslov() const
    {
        return naslov;
    }
    std::string DajAutora() const
    {
        return pisac;
    }
    std::string DajZanr() const
    {
        return zanr;
    }
    int DajGodinuIzdavanja() const
    {
        return godina_izdavanja;
    }
    Korisnik *DajKodKogaJe() const 
    {
        return zaduzenje;
    }
    void ZaduziKnjigu(Korisnik &onaj_koji_je_zaduzio)
    {
        zaduzenje = &onaj_koji_je_zaduzio;
    }
    void RazduziKnjigu()
    {
        zaduzenje = nullptr;
    }
    bool DaLiJeZaduzena() const
    {
        if(zaduzenje)
            return true;
        return false;
    }
};

class Biblioteka
{
    private:
    std::map<int, Korisnik*> korisnik;
    std::map<int, Knjiga*> knjiga;
    public:
    Biblioteka() {}
    Biblioteka(const Biblioteka &b);
    Biblioteka &operator=(const Biblioteka &b);
    ~Biblioteka() 
    {
        for(auto it = korisnik.begin(); it != korisnik.end(); it++)
                delete it->second;
        for(auto it = knjiga.begin(); it != knjiga.end(); it++)
                delete it->second;
    }
    
    void RegistrirajNovogKorisnika(int cl_broj, std::string ime, std::string prezime, std::string adresa, std::string br_telefona)
    {
        for(auto it = korisnik.begin(); it != korisnik.end(); it++)
        {
            if(it->first == cl_broj)
                throw std::logic_error("Korisnik vec postoji");
        }
        Korisnik *novikorisnik = new Korisnik{ime, prezime, adresa, br_telefona};
        korisnik.insert(std::make_pair(cl_broj, novikorisnik));
    }
    
    void RegistrirajNovuKnjigu(int br_knjige, std::string naslov, std::string pisac, std::string zanr, int godina_izdavanja)
    {
        for(auto it = korisnik.begin(); it != korisnik.end(); it++)
        {
            if(it->first == br_knjige)
                throw std::logic_error("Knjiga vec postoji");
        }
        Knjiga *novaknjiga = new Knjiga(naslov, pisac, zanr, godina_izdavanja);
        knjiga.insert(std::make_pair(br_knjige, novaknjiga));
    }
    
    Korisnik &NadjiKorisnika(int cl_broj)
    {
        for(auto it = korisnik.begin(); it != korisnik.end(); it++)
        {
            if(it->first == cl_broj) 
                return *(it->second);
        }
        throw std::logic_error("Korisnik nije nadjen");
    }
    
    Knjiga &NadjiKnjigu(int br_knjige)
    {
        for(auto it = knjiga.begin(); it != knjiga.end(); it++)
        {
            if(it->first == br_knjige) 
                return *(it->second);
        }
            throw std::logic_error("Knjiga nije nadjena");
    }
    
    void IzlistajKorisnike()
    {
        for(auto it = korisnik.begin(); it != korisnik.end(); it++)
        {
            std::cout << "Clanski broj: " << it->first << std::endl;
            std::cout << "Ime i prezime: " << it->second->ime << " " << it->second->prezime << std::endl;
            std::cout << "Adresa: " << it->second->adresa << std::endl;
            std::cout << "Broj telefona: " << it->second->telefon << std::endl;
        }
    }
    
    void IzlistajKnjige()
    {
        for(auto it = knjiga.begin(); it != knjiga.end(); it++)
        {
            std::cout << "Evidencijski broj: " << it->first << std::endl;
            std::cout << "Naslov: " << it->second->DajNaslov()<< std::endl;
            std::cout << "Pisac: " << it->second->DajAutora() << std::endl;
            std::cout << "Zanr: " << it->second->DajZanr() << std::endl;
            std::cout << "Godina izdavanja: " << it->second->DajGodinuIzdavanja() << std::endl;
            if(it->second->DaLiJeZaduzena())
            {
                std::cout << "Zaduzena kod korisnika: ";
                auto kod_koga = it->second->DajKodKogaJe();
                std::cout << kod_koga->ime << " " << kod_koga->prezime;
            }
        }
    }
    
    void ZaduziKnjigu(int br_knjige, int cl_broj)
    {
        Korisnik* k = nullptr;
        for(auto it = korisnik.begin(); it != korisnik.end(); it++)
        if(it->first == cl_broj)
            k = it->second;
        
        if(k != nullptr)
        {
            for(auto it = knjiga.begin(); it != knjiga.end(); it++)
            if(it->first == br_knjige)
            {
                if(it->second->DaLiJeZaduzena())
                    throw std::logic_error("Knjiga vec zaduzena");
                it->second->ZaduziKnjigu(*k);
                return;
            }
            throw std::logic_error("Knjiga nije nadjena");
        }
        else
        {
            throw std::logic_error("Korisnik nije nadjen");
        }
        
    }
    
    void RazduziKnjigu(int br_knjige)
    {
        //Knjiga *k = nullptr;
        for(auto it = knjiga.begin(); it != knjiga.end(); it++)
        if(it->first == br_knjige)
        {
            if(!(it->second->DaLiJeZaduzena()))
                throw std::logic_error("Knjiga nije zaduzena");
            it->second->RazduziKnjigu();
            return;
        }
        throw std::logic_error("Knjiga nije nadjena");
    }
    
    void PrikaziZaduzenja(int cl_broj)
    {
        for(auto it = korisnik.begin(); it != korisnik.end(); it++)
        {
            if(it->first == cl_broj)
            {
                bool jel_zaduzena (false);
                for(auto it1 = knjiga.begin(); it1 != knjiga.end(); it1++)
                {
                    if(it1->second->DaLiJeZaduzena())
                    {
                        jel_zaduzena = true;
                        auto u_koga = it1->second->DajKodKogaJe();
                        if(it->first == cl_broj)
                        {
                            std::cout << u_koga->ime << " " << u_koga->prezime;
                        }
                    }
                    std::cout << std::endl;
                }
                if(!jel_zaduzena)
                    std::cout << "Nema zaduzenja za tog korisnika";
            }
        }
    }
    
};

int main()
{
    Biblioteka skolska_biblioteka;
    while(1)
    {
        std::cout << "Izaberite opciju: " << std::endl << std::endl;
        std::cout << "1. Dodaj novog korisnika" << std::endl;
        std::cout << "2. Dodaj novu knjigu" << std::endl;
        std::cout << "3. Nadji korisnika" << std::endl;
        std::cout << "4. Nadji knjigu" << std::endl;
        std::cout << "5. Izlistaj korisnike" << std::endl;
        std::cout << "6. Izlistaj knjige" << std::endl;
        std::cout << "7. Zaduzi knjigu" << std::endl;
        std::cout << "8. RazduziKnjigu" << std::endl;
        std::cout << "9. Prikazi zaduzenja" << std::endl;
        std::cout << "10. PREKINI" << std::endl << std::endl;
        std::cout << "Vasa opcija je: ";
        int n;
        std::cin >> n;
        if(n == 1)
        {
            std::string ime, prezime, adresa, telefon;
            std::cout << "Unesite podatke za novog korisnika: ";
            std::getline(std::cin, ime);
            std::getline(std::cin, prezime);
            std::getline(std::cin, adresa);
            std::getline(std::cin, telefon);
            int clanski_broj;
            std::cout << "Unesite clanski broj novog korisnika: ";
            std::cin >> clanski_broj;
            try
            {
                skolska_biblioteka.RegistrirajNovogKorisnika(clanski_broj, ime, prezime, adresa, telefon);
            }
            catch(std::logic_error IZUZETAK)
            {
                std::cout << IZUZETAK.what() << std::endl;
            }
        }
        else if(n == 2)
        {
            std::string naslov, pisac, zanr;
            int clanski_broj, godina_izdavanja;
            std::cout << "Unesite podatke za novu knjigu: ";
            std::getline(std::cin, naslov);
            std::getline(std::cin, pisac);
            std::getline(std::cin, zanr);
            std::cin >> godina_izdavanja;
            std::cin >> clanski_broj;
            try
            {
                skolska_biblioteka.RegistrirajNovuKnjigu(clanski_broj, naslov, pisac, zanr, godina_izdavanja);
            }
            catch(std::logic_error IZUZETAK)
            {
                std::cout << IZUZETAK.what() << std::endl;
            }
        }
        else if(n == 3)
        {
            int clanski_broj;
            std::cout << "Unesite clanski broj: ";
            std::cin >> clanski_broj;
            try
            {
                Korisnik korisnik = skolska_biblioteka.NadjiKorisnika(clanski_broj);
                std::cout << "Korisnik sa brojem " << clanski_broj << " je " << korisnik.ime << " " << korisnik.prezime;
            }
            catch(std::logic_error IZUZETAK)
            {
                std::cout << IZUZETAK.what() << std::endl;
            }
        }
        else if(n == 4)
        {
            int br_knjige;
            std::cout << "Unesite broj knjige: ";
            std::cin >> br_knjige;
            try
            {
                Knjiga knjiga = skolska_biblioteka.NadjiKnjigu(br_knjige);
                std::cout << "Knjiga sa brojem: " << br_knjige << "je: ";
                std::cout << "Naslov: " << knjiga.DajNaslov()<< std::endl;
                std::cout << "Pisac: " << knjiga.DajAutora() << std::endl;
                std::cout << "Zanr: " << knjiga.DajZanr() << std::endl;
                std::cout << "Godina izdavanja: " << knjiga.DajGodinuIzdavanja() << std::endl;
            }
            catch(std::logic_error IZUZETAK)
            {
                std::cout << IZUZETAK.what() << std::endl;
            }
        }
        else if(n == 5)
        {
            skolska_biblioteka.IzlistajKorisnike();
        }
        else if(n == 6)
        {
            skolska_biblioteka.IzlistajKnjige();
        }
        else if(n == 7)
        {
            int br_knjige;
            std::cout << "Unesite broj knjige koja se zaduzuje: ";
            std::cin >> br_knjige;
            int clanski_broj;
            std::cout << "Unesite clanski broj korisnika koji zaduzuje: ";
            std::cin >> clanski_broj;
            try
            {
                skolska_biblioteka.ZaduziKnjigu(br_knjige, clanski_broj);
            }
            catch(std::logic_error IZUZETAK)
            {
                std::cout << IZUZETAK.what() << std::endl;
            }
        }
        else if(n == 8)
        {
            int br_knjige;
            std::cout << "Unesite broj knjige koja se razduzuje: ";
            std::cin >> br_knjige;
            try
            {
                skolska_biblioteka.RazduziKnjigu(br_knjige);
            }
            catch(std::logic_error IZUZETAK)
            {
                std::cout << IZUZETAK.what() << std::endl;
            }
        }
        else if(n == 9)
        {
            int clanski_broj;
            std::cout << "Unesite broj korisnika kod kojeg provjeravate zaduzenje: ";
            std::cin >> clanski_broj;
            try
            {
                skolska_biblioteka.PrikaziZaduzenja(clanski_broj);
            }
            catch(std::logic_error IZUZETAK)
            {
                std::cout << IZUZETAK.what() << std::endl;
            }
        }
        else if(n == 10)
            break;
    }
    return 0;
}