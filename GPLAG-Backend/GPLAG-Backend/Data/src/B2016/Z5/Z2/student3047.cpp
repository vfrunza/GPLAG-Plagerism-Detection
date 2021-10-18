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
    std::string naslov, ime_pisca, zanr;  
    int gi;
    Korisnik* k = nullptr;
public:
    Knjiga(const std::string& n, const std::string& ip, const std::string& zanr, int gi)  
        : naslov(n), ime_pisca(ip), zanr(zanr), gi(gi){}
    
    std::string DajNaslov() const
    {
        return naslov;
    }
    
    std::string DajAutora() const
    {
        return ime_pisca;
    }
    
    std::string DajZanr() const
    {
        return zanr;
    }
    int DajGodinuIzdavanja()const
    {
        return gi;
    }
    
    Korisnik* DajKodKogaJe()const
    {
        return k;
    }
    
    void ZaduziKnjigu(Korisnik& ko)
    {
        k = &ko;
    }
    
    void RazduziKnjigu()
    {
        k = nullptr;
    }
    
    bool DaLiJeZaduzena() const
    {
        return k != nullptr;
    }
    
};


class Biblioteka
{
    std::map<int, std::shared_ptr<Korisnik>> korisnici;
    std::map<int, std::shared_ptr<Knjiga>> knjige;
    
public:
   
    Biblioteka() = default;
    Biblioteka(const Biblioteka& b);
    Biblioteka(Biblioteka&& b)
    {
        korisnici = std::move(b.korisnici);
        knjige = std::move(b.knjige);
        b.knjige.clear();
        b.korisnici.clear();
    }
    Biblioteka& operator=(Biblioteka&&);
    Biblioteka& operator=(const Biblioteka&);
    
    void RegistrirajNovogKorisnika(int cb, const std::string& i, const std::string& p, const std::string& a, const std::string bt);
    
    void RegistrirajNovuKnjigu(int eb, const std::string& n, const std::string& ip, const std::string& zanr, int gi);
    
    Korisnik& NadjiKorisnika(int eb) const;
    
    Knjiga& NadjiKnjigu(int eb) const;
    
    void IzlistajKnjige()const;
    
    void IzlistajKorisnike()const;
    
    void ZaduziKnjigu(int, int);
    
    void RazduziKnjigu(int);
    
    void PrikaziZaduzenja(int) const;
};


void Biblioteka::PrikaziZaduzenja(int ebko) const
{
    const auto& korisnik = NadjiKorisnika(ebko);
    bool zaduzen = false;    
    for(const auto& e : knjige)
    {
        if( (e.second)->DajKodKogaJe() == &korisnik )
        {
            zaduzen = true;
            const auto& k = *(e.second);
            std::cout << "Evidencijski broj: " << e.first;
            std::cout << "\nNaslov: " << k.DajNaslov();
            std::cout << "\nPisac: " << k.DajAutora();
            std::cout << "\nZanr: " << k.DajZanr();
            std::cout << "\nGodina izdavanja: " << k.DajGodinuIzdavanja() << "\n\n";    
        }
        
    }
    if(zaduzen == false)
        std::cout << "Nema zaduzenja za tog korisnika";
    
}

void Biblioteka::RazduziKnjigu(int ebk)
{
    auto& knjiga = NadjiKnjigu(ebk);
    if(!knjiga.DaLiJeZaduzena())
        throw std::logic_error("Knjiga nije zaduzena");
    knjiga.RazduziKnjigu();
}

void Biblioteka::ZaduziKnjigu(int ebk, int ebko)
{
    auto& knjiga = NadjiKnjigu(ebk);
    auto& korisnik = NadjiKorisnika(ebko);
    if(knjiga.DaLiJeZaduzena())
        throw std::logic_error("Knjiga vec zaduzena");
    knjiga.ZaduziKnjigu(korisnik);
}

void Biblioteka::IzlistajKorisnike()const
{
    for(const auto& e : korisnici)
    {
        const auto& k = *(e.second);
        std::cout << "Clanski broj: " << e.first;
        std::cout << "\nIme i prezime: " << k.ime << " " << k.prezime;
        std::cout << "\nAdresa: " << k.adresa;
        std::cout << "\nBroj telefona: " << k.telefon << "\n\n";
    }
}

void Biblioteka::IzlistajKnjige()const
{
    for(const auto& e : knjige)
    {
        const auto& k = *(e.second);
        std::cout << "Evidencijski broj: " << e.first;
        std::cout << "\nNaslov: " << k.DajNaslov();
        std::cout << "\nPisac: " << k.DajAutora();
        std::cout << "\nZanr: " << k.DajZanr();
        std::cout << "\nGodina izdavanja: " << k.DajGodinuIzdavanja() << "\n";
        if(k.DaLiJeZaduzena())
            std::cout << "Zaduzena kod korisnika: " << k.DajKodKogaJe()->ime << " " << k.DajKodKogaJe()->prezime << "\n";
        std::cout << "\n";
    }
}

Knjiga& Biblioteka::NadjiKnjigu(int eb) const
{
    auto it = knjige.find(eb);
    if(it == knjige.end())
        throw std::logic_error("Knjiga nije nadjen");
    return *(it->second);
}


Korisnik& Biblioteka::NadjiKorisnika(int eb) const
{
    auto it = korisnici.find(eb);
    if(it == korisnici.end())
        throw std::logic_error("Korisnik nije nadjen");
    return *(it->second);
}

void Biblioteka::RegistrirajNovuKnjigu(int eb, const std::string& n, const std::string& ip, const std::string& zanr, int gi)
{
    if(knjige.find(eb) != knjige.end())
        throw std::logic_error("Knjiga vec postoji");
    knjige[eb] = std::make_shared<Knjiga>( n, ip, zanr, gi );
}

void Biblioteka::RegistrirajNovogKorisnika(int cb, const std::string& i, const std::string& p, const std::string& a, const std::string bt)
{
    if(korisnici.find(cb) != korisnici.end())
        throw std::logic_error("Korisnik vec postoji");
    Korisnik k {i, p, a, bt};
    korisnici[cb] = std::make_shared<Korisnik>( k );
    
}

Biblioteka& Biblioteka::operator=(const Biblioteka& b)
{
    if(this == &b)
        return *this;

    for(auto it = b.korisnici.begin(); it != b.korisnici.end(); ++it)
        korisnici[it->first] = std::make_shared<Korisnik>(*(it->second));
        
    for(auto it = b.knjige.begin(); it != b.knjige.end(); ++it)
        knjige[it->first] = std::make_shared<Knjiga>(*(it->second));
        
    return *this;
}


Biblioteka& Biblioteka::operator=(Biblioteka&& b)
{
    if(this == &b)
        return *this;
    korisnici = std::move(b.korisnici);
    knjige = std::move(b.knjige);
    b.knjige.clear();
    b.korisnici.clear();
    
    return *this;
}

Biblioteka::Biblioteka(const Biblioteka& b) : Biblioteka()
{
    
    for(auto it = b.korisnici.begin(); it != b.korisnici.end(); ++it)
        korisnici[it->first] = std::make_shared<Korisnik>(*(it->second));
        
    for(auto it = b.knjige.begin(); it != b.knjige.end(); ++it)
        knjige[it->first] = std::make_shared<Knjiga>(*(it->second));
    
}


void IspisiKorisnika(const Korisnik& k)
{
    std::cout << "Ime i prezime: " << k.ime << " " << k.prezime;
    std::cout << "\nAdresa: " << k.adresa;
    std::cout << "\nBroj telefona: " << k.telefon << "\n\n";
}

void IspisiKnjigu(const Knjiga& k)
{
    std::cout << "Naslov: " << k.DajNaslov();
    std::cout << "\nPisac: " << k.DajAutora();
    std::cout << "\nZanr: " << k.DajZanr();
    std::cout << "\nGodina izdavanja: " << k.DajGodinuIzdavanja() << "\n\n";    
}

int main ()
{
Biblioteka libary;
	for (;;) {
		std::cout << "MENI:\n1. Registruj clana\n2. Registruj knjigu\n3. Nadjite clana\n4. Nadjite knjigu\n5. Prikazi sve clanove\n";
		std::cout << "6. Prikazi sve knjige\n7. Zaduzi knjigu\n8. Razduzi knjigu\n9. Prikazi zaduzenja\n10. Izlaz\nIzaberite: ";
		int izbor;
		std::cin >> izbor;
		std::cin.ignore (10000, '\n');
		if (izbor == 1) {
			int EBC;
			std::cout << "Unesite evidencijski broj clana: ";
			std::cin >> EBC;
			std::cin.ignore (10000, '\n');
			std::string ime, prezime, adresa, broj_telefona;
			std::cout << "Unesite ime: ";
			std::getline (std::cin, ime);
			std::cout << "Unesite prezime: ";
			std::getline (std::cin, prezime);
			std::cout << "Unesite adresu: ";
			std::getline (std::cin, adresa);
			std::cout << "Unesite broj teleofona: ";
			std::getline (std::cin, broj_telefona);
			try {
				libary.RegistrirajNovogKorisnika (EBC, ime, prezime, adresa, broj_telefona);
			} catch (std::domain_error e) {
				std::cout << e.what();
				continue;
			}
			std::cout << "Uspjesno ste unijeli clana!\n";
			continue;
		}
		if (izbor == 2) {
			int EBK, GI;
			std::cout << "Unesite evidencijski broj knjige: ";
			std::cin >> EBK;
			std::cout << "Unesite godinu izdavanja: ";
			std::cin >> GI;
			std::cin.ignore (10000, '\n');
			std::cout << "Unsite ime pisca: ";
			std::string ime_pisca, zanr, naslov;
			std::getline (std::cin, ime_pisca);
			std::cout << "Unsite ime zanr: ";
			std::getline (std::cin, zanr);
			std::cout << "Unsite ime naslov: ";
			std::getline (std::cin, naslov);
			try {
				libary.RegistrirajNovuKnjigu (EBK, naslov, ime_pisca, zanr, GI);
			} catch (std::domain_error e) {
				std::cout << e.what();
				continue;
			}
			std::cout << "Uspjesno ste dodali knjigu!\n";
			continue;
		}
		if (izbor == 3) {
			std::cout << "Unsite evidencijski broj clana kojeg zelite naci: ";
			int EBC;
			std::cin >> EBC;
			std::cout << "Informacije o clanu:\n";
			try {
				IspisiKorisnika(libary.NadjiKorisnika (EBC));
			} catch (std::domain_error r) {
				std::cout << r.what();
				continue;
			}
		}
		if (izbor == 4) {
			std::cout << "Unesite evidencijski broj knjige: ";
			int EBK;
			std::cin >> EBK;
			std::cout << "Informacije o knjizi:\n";
			try {
				IspisiKnjigu(libary.NadjiKnjigu (EBK));
			} catch (std::domain_error r) {
				std::cout << r.what();
				continue;
			}
			continue;
		}
		if (izbor == 5) {
			libary.IzlistajKorisnike();
			continue;
		}
		if (izbor == 6) {
			libary.IzlistajKnjige();
			continue;
		}
		if (izbor == 7) {
			std::cout << "Unesite evidencijski broj clana: ";
			int EBC;
			std::cin >> EBC;
			std::cout << "Unesite evidencijski broj knjige: ";
			int EBK;
			std::cin >> EBK;
			try {
				libary.ZaduziKnjigu (EBK, EBC);
			} catch (std::domain_error e) {
				std::cout << e.what();
				continue;
			}
			std::cout << "Zaduzili ste knjigu!\n";
			continue;
		}
		if (izbor == 8) {
			std::cout << "Unesite evidencijski broj knjige: ";
			int EBK;
			std::cin >> EBK;
			try {
				libary.RazduziKnjigu (EBK);
			} catch (std::domain_error e) {
				std::cout << e.what();
				continue;
			}
			std::cout << "Uspjesno ste razduzili knjigu!\n";
			continue;
		}
		if (izbor == 9) {
			std::cout << "Unesite evidencijski broj clana: ";
			int EBC;
			std::cin >> EBC;
			try {
				std::cout << "Zaduzenja clana su:\n";
				libary.PrikaziZaduzenja (EBC);
			} catch (std::domain_error e) {
				std::cout << e.what();
				continue;
			}
			continue;
		}
		if (izbor == 10)
			break;
	}
	return 0;
}