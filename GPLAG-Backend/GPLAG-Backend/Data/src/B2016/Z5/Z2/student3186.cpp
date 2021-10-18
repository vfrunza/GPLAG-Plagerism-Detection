/B16/17 (Zadaća 5, Zadatak 2)
#include <stdexcept>
#include <iostream>
#include <string>
#include <memory>
#include <new>
#include <map>

struct Korisnik {
    std::string ime, prezime, adresa, telefon;
};

class Knjiga {
    std::string naslov, ime_pisca, zanr; 
    int godina_izdanja; 
    struct Korisnik *zaduzeno = nullptr;
public:
    Knjiga (const std::string &naslov_, const std::string &ime_pisca_, const std::string &zanr_, int godina) {
        Knjiga::naslov = naslov_; Knjiga::ime_pisca = ime_pisca_; Knjiga::zanr = zanr_; Knjiga::godina_izdanja = godina;
    }
    
    std::string DajNaslov()  const { return naslov;        };
    std::string DajAutora()  const { return ime_pisca;     };
    std::string DajZanr()    const { return zanr;          };
    int DajGodinuIzdavanja() const { return godina_izdanja;};
    Korisnik *DajKodKogaJe() const { return zaduzeno;      };
    
    void ZaduziKnjigu (Korisnik &n) { zaduzeno = &n; };
    void RazduziKnjigu ()           { zaduzeno = nullptr; };
    bool DaLiJeZaduzena ()          { if (zaduzeno == nullptr) return false; else return true; };
};  

class Biblioteka {
    std::map <int, std::shared_ptr<Korisnik>> korisnici;
    std::map <int, std::shared_ptr<Knjiga>> knjige;
public:
    Biblioteka () {};                               // Default konstruktor ..
    Biblioteka (const Biblioteka &ZaKopirati) {     // Kopirajuci konstruktor duboke kopije ..
        for (auto it = ZaKopirati.korisnici.begin(); it != ZaKopirati.korisnici.end(); ++it)
            try {
                Biblioteka::korisnici.insert(std::make_pair(it->first,
                    std::make_shared<Korisnik> (Korisnik{it->second->ime, it->second->prezime, it->second->adresa, it->second->telefon}) ));
            }   catch (std::bad_alloc()) {
                for (auto it = Biblioteka::korisnici.begin(); it != Biblioteka::korisnici.end(); ++it)
                    it->second = nullptr;    Biblioteka::korisnici.clear(); throw std::bad_alloc();
            }
        
        for (auto it = ZaKopirati.knjige.begin(); it != ZaKopirati.knjige.end(); ++it)
            try {
                Biblioteka::knjige.insert(std::make_pair(it->first, 
                    std::make_shared<Knjiga> (Knjiga{it->second->DajNaslov(), it->second->DajAutora(), it->second->DajZanr(), it->second->DajGodinuIzdavanja()}) ));
            }   catch (std::bad_alloc()) {
                for (auto it = Biblioteka::korisnici.begin(); it != Biblioteka::korisnici.end(); ++it)
                    it->second = nullptr;    Biblioteka::korisnici.clear();
                for (auto it = Biblioteka::knjige.begin(); it != Biblioteka::knjige.end(); ++it)
                    it->second = nullptr;    Biblioteka::knjige.clear(); throw std::bad_alloc();
            }
    }
    Biblioteka (Biblioteka &&ZaPomjeriti) {         // Move konstruktor ..
        Biblioteka::korisnici = ZaPomjeriti.korisnici;  Biblioteka::knjige = ZaPomjeriti.knjige;
        ZaPomjeriti.korisnici.clear();                  ZaPomjeriti.knjige.clear();
    }

    Biblioteka &operator =(const Biblioteka &ZaKopirati) {  // preklapanje kopirajuceg operatora dodjele ..
        if (&ZaKopirati != this) {
            for (auto it = Biblioteka::knjige.begin(); it != Biblioteka::knjige.end(); ++it)
                it->second = nullptr;    Biblioteka::knjige.clear();
            for (auto it = Biblioteka::korisnici.begin(); it != Biblioteka::korisnici.end(); ++it)
                it->second = nullptr;    Biblioteka::korisnici.clear();
            
            for (auto it = ZaKopirati.knjige.begin(); it != ZaKopirati.knjige.end(); ++it)
                try {
                    Biblioteka::knjige.insert(std::make_pair(it->first,
                        std::make_shared<Knjiga> (Knjiga{it->second->DajNaslov(), it->second->DajAutora(), it->second->DajZanr(), it->second->DajGodinuIzdavanja()}) ));
                }   catch (std::bad_alloc()) {
                    for (auto it = Biblioteka::knjige.begin(); it != Biblioteka::knjige.end(); ++it)
                        it->second = nullptr;    Biblioteka::knjige.clear(); throw std::bad_alloc();
                }
            for (auto it = ZaKopirati.korisnici.begin(); it != ZaKopirati.korisnici.end(); ++it)
                try {
                    Biblioteka::korisnici.insert(std::make_pair(it->first,
                        std::make_shared<Korisnik> (Korisnik{it->second->ime, it->second->prezime, it->second->adresa, it->second->telefon}) ));
                }   catch (std::bad_alloc()) {
                    for (auto it = Biblioteka::knjige.begin(); it != Biblioteka::knjige.end(); ++it)
                        it->second = nullptr;    Biblioteka::knjige.clear();
                    for (auto it = Biblioteka::korisnici.begin(); it != Biblioteka::korisnici.end(); ++it)
                        it->second = nullptr;    Biblioteka::korisnici.clear(); throw std::bad_alloc();
                }
        }   return *this;
    }
    
    Biblioteka &operator =(Biblioteka &&ZaPomjeriti) {      // preklapanje pomjerajuceg opetarotra dodjele ..
        if (&ZaPomjeriti != this) {
            for (auto it = Biblioteka::knjige.begin(); it != Biblioteka::knjige.end(); ++it)
                it->second = nullptr;    knjige.clear();
            for (auto it = Biblioteka::korisnici.begin(); it != Biblioteka::korisnici.end(); ++it)
                it->second = nullptr;    korisnici.clear();
            Biblioteka::knjige = ZaPomjeriti.knjige;    Biblioteka::korisnici = ZaPomjeriti.korisnici;
            ZaPomjeriti.knjige.clear();                 ZaPomjeriti.korisnici.clear();
        }   return *this;
    }
    
    ~Biblioteka () {
        for (auto it = Biblioteka::knjige.begin(); it != Biblioteka::knjige.end(); ++it)        it->second = nullptr;
        for (auto it = Biblioteka::korisnici.begin(); it != Biblioteka::korisnici.end() ;++it)  it->second = nullptr;
    }
    
    void RegistrirajNovogKorisnika (int clanski_br, const std::string &im, const std::string &pr, const std::string &ad, const std::string br_tel) {
        for (auto it=korisnici.begin(); it != korisnici.end(); ++it) if (it->first == clanski_br) throw std::logic_error ("Korisnik vec postoji");
        try {
            Biblioteka::korisnici.insert(std::make_pair(clanski_br, std::make_shared<Korisnik> (Korisnik{im, pr, ad, br_tel})));
        }   catch (std::bad_alloc()) {
            for (auto it = Biblioteka::korisnici.begin(); it != Biblioteka::korisnici.end(); ++it)
                it->second = nullptr;    Biblioteka::korisnici.clear();  throw std::bad_alloc();
        }
    }
    
    void RegistrirajNovuKnjigu (int evidencijski_br, const std::string &naslov, const std::string &ime, const std::string &zanr, int godina) {
        for (auto it=knjige.begin(); it != knjige.end(); ++it) if (it->first == evidencijski_br) throw std::logic_error ("Knjiga vec postoji");
        try {
            Biblioteka::knjige.insert(std::make_pair(evidencijski_br, std::make_shared<Knjiga> (Knjiga{naslov, ime, zanr, godina}) ));
        }   catch (std::bad_alloc()) {
            for (auto it = Biblioteka::knjige.begin(); it != Biblioteka::knjige.end(); ++it)
                it->second = nullptr;    Biblioteka::knjige.clear();     throw std::bad_alloc();
        }
    }
    
    Korisnik &NadjiKorisnika (int clanski_broj) {
        for (auto it=Biblioteka::korisnici.begin(); it != Biblioteka::korisnici.end(); ++it)
            if (it->first == clanski_broj) return *it->second;   throw std::logic_error ("Korisnik nije nadjen");
    }
    
    Knjiga &NadjiKnjigu (int evidencijski_broj) {
        for (auto it = Biblioteka::knjige.begin(); it != Biblioteka::knjige.end(); ++it)
            if (it->first == evidencijski_broj) return *it->second; throw std::logic_error ("Knjiga nije nadjena");
    }
    
    void IzlistajKorisnike () {
        for (auto it = Biblioteka::korisnici.begin(); it != Biblioteka::korisnici.end(); ++it) {
            std::cout << "Clanski broj: " << it->first << std::endl << "Ime i prezime: " << it->second->ime << " " << it->second->prezime;
            std::cout << std::endl << "Adresa: " << it->second->adresa << std::endl << "Broj telefona: " << it->second->telefon << std::endl;
            std::cout << std::endl;
        }
    }
    
    void IzlistajKnjige () {
        for (auto it = Biblioteka::knjige.begin(); it != Biblioteka::knjige.end(); ++it) {
            std::cout << "Evidencijski broj: " << it->first << std::endl << "Naslov: " << it->second->DajNaslov() << std::endl;
            std::cout << "Pisac: " << it->second->DajAutora() << std::endl << "Zanr: " << it->second->DajZanr() << std::endl;
            std::cout << "Godina izdavanja: " << it->second->DajGodinuIzdavanja() << std::endl;
            if (it->second->DaLiJeZaduzena() == true)   {   std::cout << "Zaduzena kod korisnika: ";
            std::cout << it->second->DajKodKogaJe()->ime << " " << it->second->DajKodKogaJe()->prezime << std::endl; }
            std::cout << std::endl;
        }
    }
    
    void ZaduziKnjigu (int evidencijski_broj, int clanski_broj) {
        std::shared_ptr<Knjiga> pok_knjiga = nullptr;
        for (auto it = Biblioteka::knjige.begin(); it != Biblioteka::knjige.end(); ++it)
            if (it->first == evidencijski_broj) pok_knjiga = it->second;
        if (pok_knjiga == nullptr)  throw std::logic_error ("Knjiga nije nadjena");
        
        std::shared_ptr<Korisnik> pok_korisnik = nullptr;
        for (auto it = Biblioteka::korisnici.begin(); it != Biblioteka::korisnici.end(); ++it)
            if (it->first == clanski_broj) pok_korisnik = it->second;
        if (pok_korisnik == nullptr)  throw std::logic_error ("Korisnik nije nadjen");
        
        if (pok_knjiga->DaLiJeZaduzena()) throw std::logic_error ("Knjiga vec zaduzena");
        pok_knjiga->ZaduziKnjigu(*pok_korisnik.get()); // Zaduzenje ..
    }
    
    void RazduziKnjigu (int evidencijski_broj) {
        std::shared_ptr<Knjiga> pok_knjiga = nullptr;
        for (auto it = Biblioteka::knjige.begin(); it != Biblioteka::knjige.end(); ++it)
            if (it->first == evidencijski_broj) pok_knjiga = it->second;
        if (pok_knjiga == nullptr)             throw std::logic_error ("Knjiga nije nadjena");
        if (not(pok_knjiga->DaLiJeZaduzena())) throw std::logic_error ("Knjiga nije zaduzena");
        pok_knjiga->RazduziKnjigu(); // Razduzenje ..
    }
    
    void PrikaziZaduzenja (int clanski_broj) {
        std::shared_ptr<Korisnik> pok_korisnik = nullptr;
        for (auto it = Biblioteka::korisnici.begin(); it != Biblioteka::korisnici.end(); ++it)
            if (it->first == clanski_broj) pok_korisnik = it->second;
        if (pok_korisnik == nullptr)    throw std::logic_error ("Korisnik nije nadjen");
        bool DaLiSeNeNalazi(true);
        for (auto it = Biblioteka::knjige.begin(); it != Biblioteka::knjige.end(); ++it) {
            if (it->second->DajKodKogaJe() == pok_korisnik.get()) { DaLiSeNeNalazi = false;
                std::cout << "Evidencijski broj: " << it->first << std::endl << "Naslov: " << it->second->DajNaslov() << std::endl;
                std::cout << "Pisac: " << it->second->DajAutora() << std::endl << "Zanr: " << it->second->DajZanr() << std::endl;
                std::cout << "Godina izdavanja: " << it->second->DajGodinuIzdavanja() << std::endl << std::endl;
            }   if (DaLiSeNeNalazi) std::cout << "Nema zaduzenja za tog korisnika!";
        }
    }
};

int main ()
{
    int kontrolna{0};
    std::cout << "_..::BIBLIOTEKA::.._" << std::endl;
    std::cout << "Unesite 1 za pocetak" << std::endl;
    std::cin >> kontrolna; 
    
    if (kontrolna == 1) {
        Biblioteka moja_biblioteka;
        for (;;) {
            int opcija{0};
            std::cout << "Unesite opciju: (0 za kontrolnu tablu): ";
            std::cin >> opcija;
            
            if (opcija == 1) {
                std::cout << "Izabrali ste opciju 1. (Registraciju novog korisnika) " << std::endl;
                int clanski_broj; std::string ime, prezime, adresa, telefon;
                std::cout << "Molimo unesite clanski broj korisnika: ";
                std::cin >> clanski_broj;   std::cin.ignore(10000, '\n');
                std::cout << "Molimo unesite ime korisnika: ";
                std::getline (std::cin, ime);
                std::cout << "Molimo unesite prezime korisnika: ";
                std::getline (std::cin, prezime);
                std::cout << "Molimo unesite adresu korisnika: ";
                std::getline (std::cin, adresa);
                std::cout << "Molimo unesite telefon korisnika (format 06X/XXX-XXX): ";
                std::getline (std::cin, telefon);
                try {
                    moja_biblioteka.RegistrirajNovogKorisnika (clanski_broj, ime, prezime, adresa, telefon);
                }   catch (std::logic_error txt) {  std::cout << "Oops: " << txt.what() << std::endl; }
            }
            else if (opcija == 2) {
                std::cout << "Izabrali ste opciju 2. (Registraciju nove knjige) " << std::endl;
                int evidencijski_broj{0}, godina; std::string naslov, ime, zanr;
                std::cout << "Molimo unesite evidencijski broj knjige: ";
                std::cin >> evidencijski_broj;  std::cin.ignore(10000, '\n');
                std::cout << "Molimo unesite naslov knjige: ";
                std::getline (std::cin, naslov);
                std::cout << "Molimo unesite autora knjige: ";
                std::getline (std::cin, ime);
                std::cout << "Molimo unesite zanr knjige: ";
                std::getline (std::cin, zanr);
                std::cout << "Molimo unesite godinu izdavanja knjige: ";
                std::cin >> godina; std::cin.ignore (10000, '\n');
                try {
                    moja_biblioteka.RegistrirajNovuKnjigu(evidencijski_broj, naslov, ime, zanr, godina);
                }   catch (std::logic_error txt) {  std::cout << "Oops: " << txt.what() << std::endl; }
            }
            else if (opcija == 3) {
                std::cout << "Izabrali ste opciju 3. (Pretraga korisnika) " << std::endl;
                int clanski_broj;
                std::cout << "Molimo unesite clanski broj korisnika: ";
                std::cin >> clanski_broj;
                try {
                    Korisnik neki_korisnik = moja_biblioteka.NadjiKorisnika(clanski_broj);
                    std::cout << "Ime: " << neki_korisnik.ime << std::endl;
                    std::cout << "Prezime: " << neki_korisnik.prezime << std::endl;
                    std::cout << "Adresa: " << neki_korisnik.adresa << std::endl;
                    std::cout << "Telefon: " << neki_korisnik.telefon << std::endl;
                }   catch (std::logic_error txt) {  std::cout << "Oops: " << txt.what() << std::endl; }
            }
            else if (opcija == 4) {
                std::cout << "Izabrali ste opciju 4. (Pretraga knjige) " << std::endl;
                int evidencijski_broj;
                std::cout << "Molimo unesite evidencijski broj knjige: ";
                std::cin >> evidencijski_broj;
                try {
                    Knjiga neka_knjiga = moja_biblioteka.NadjiKnjigu(evidencijski_broj);
                    std::cout << "Naslov: " << neka_knjiga.DajNaslov() << std::endl;
                    std::cout << "Autor: "  << neka_knjiga.DajAutora() << std::endl;
                    std::cout << "Zanr: "   << neka_knjiga.DajZanr()   << std::endl;
                    std::cout << "Godina: " << neka_knjiga.DajGodinuIzdavanja() << std::endl;
                }   catch (std::logic_error txt) {  std::cout << "Oops: " << txt.what() << std::endl; }
            }
            else if (opcija == 5) {
                std::cout << "Izabrali ste opciju 5. (Lista korisnika) " << std::endl;
                std::cout << std::endl; moja_biblioteka.IzlistajKorisnike();
            }
            else if (opcija == 6) {
                std::cout << "Izabrali ste opciju 6. (Lista knjiga) " << std::endl;
                std::cout << std::endl; moja_biblioteka.IzlistajKnjige();
            }
            else if (opcija == 7) {
                std::cout << "Izabrali ste opciju 7. (Zaduzenje knjige) " << std::endl;
                int evidencijski_broj, clanski_broj;
                std::cout << "Unesite evidencijski broj: ";
                std::cin >> evidencijski_broj;
                std::cout << "Unesite clanski broj: ";
                std::cin >> clanski_broj;
                try {
                    moja_biblioteka.ZaduziKnjigu(evidencijski_broj, clanski_broj);
                }   catch (std::logic_error txt) {  std::cout << "Oops: " << txt.what() << std::endl; }
            }
            else if (opcija == 8) {
                std::cout << "Izabrali ste opciju 8. (Razduzenje knjige) " << std::endl;
                int evidencijski_broj;
                std::cout << "Unesite evidencijski broj: ";
                std::cin >> evidencijski_broj;
                try {  
                    moja_biblioteka.RazduziKnjigu(evidencijski_broj);
                }   catch (std::logic_error txt) {  std::cout << "Oops: " << txt.what() << std::endl; }
            }
            else if (opcija == 9) {
                std::cout << "Izabra ste opciju 9. (Lista zaduzenja) " << std::endl;
                int clanski_broj;
                std::cout << "Molimo unesite clanski broj: ";
                std::cin >> clanski_broj;
                try {
                    std::cout << std::endl;
                    moja_biblioteka.PrikaziZaduzenja(clanski_broj);
                }   catch (std::logic_error txt) {  std::cout << "Oops: " << txt.what() << std::endl; }
            }
            else if (opcija == 0) {
                std::cout << "||------------KONTORLNA-TABLA-------------||" << std::endl;
                std::cout << "|| 1.  za registraciju novog korisnika .. ||" << std::endl;
                std::cout << "|| 2.  za registraciju nove knjige ..     ||" << std::endl;
                std::cout << "|| 3.  za pretragu korisnika ..           ||" << std::endl;
                std::cout << "|| 4.  za pretragu knjige ..              ||" << std::endl;
                std::cout << "|| 5.  za izlistavanje svih korisnika ..  ||" << std::endl;
                std::cout << "|| 6.  za izlistavanje svih knjiga ..     ||" << std::endl;
                std::cout << "|| 7.  za zaduzenje knjige ..             ||" << std::endl;
                std::cout << "|| 8.  za razduzenje knjige ..            ||" << std::endl;
                std::cout << "|| 9. za prikaz zaduzenja knjiga ..       ||" << std::endl;
                std::cout << "||    _...::: // 10 za kraj // :::..._    ||" << std::endl;
                std::cout << "||----------------------------------------||" << std::endl;
            }   else break;
        }
    }   return 0;
}