/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <stdexcept>

struct Korisnik {
    std::string ime, prezime, adresa, telefon;
};
class Knjiga {
    std::string naslov_knjige, ime_pisca, zanr;
    int godina_izdavanja;
    Korisnik *zaduzenje;
    public:
    Knjiga (std::string naslov_knjige, std::string ime_pisca, std::string zanr, int godina_izdavanja) : 
    naslov_knjige(naslov_knjige), ime_pisca(ime_pisca), zanr(zanr), godina_izdavanja(godina_izdavanja), zaduzenje(nullptr) {}
    std::string DajNaslov() const { return naslov_knjige; }
    std::string DajAutora() const { return ime_pisca; }
    std::string DajZanr() const { return zanr; }
    int DajGodinuIzdavanja() const { return godina_izdavanja; }
    Korisnik *DajKodKogaJe() const { return zaduzenje; }
    void ZaduziKnjigu(Korisnik &korisnik) { zaduzenje = &korisnik; }
    void RazduziKnjigu() { zaduzenje = nullptr; }
    bool DaLiJeZaduzena() const { return zaduzenje != nullptr; }
};
class Biblioteka {
    std::map<int, Korisnik*> korisnici;
    std::map<int, Knjiga*> knjige;
    public:
    Biblioteka() = default;
    Biblioteka (const Biblioteka &b); // 
    Biblioteka (Biblioteka &&b);// 
    Biblioteka &operator =(const Biblioteka &b); // 
    Biblioteka &operator =(Biblioteka &&b); // ?
    void RegistrirajNovogKorisnika(int clanski_broj, std::string ime, std::string prezime, std::string adresa, std::string telefon);//
    void RegistrirajNovuKnjigu(int evidencijski_broj, std::string naslov_knjige, std::string ime_pisca, std::string zanr, int godina_izdavanja);//
    Korisnik &NadjiKorisnika(int clanski_broj) const;//
    Knjiga &NadjiKnjigu(int evidencijski_broj) const;//
    void IzlistajKorisnike() const;//
    void IzlistajKnjige() const;//
    void ZaduziKnjigu(int evidencijski_broj, int clanski_broj);
    void RazduziKnjigu(int evidencijski_broj);
    void PrikaziZaduzenja(int clanski_broj) const;
    ~Biblioteka();
};
Biblioteka::~Biblioteka() {
    for (auto it = korisnici.begin(); it != korisnici.end(); it++)
        delete it->second;
    for (auto it = knjige.begin(); it != knjige.end(); it++)
        delete it->second;
}
void Biblioteka::PrikaziZaduzenja(int clanski_broj) const {
    bool test_1(false);
    for (auto it = korisnici.begin(); it != korisnici.end(); it++)
        if (it->first == clanski_broj) { test_1 = true; break; }
    if (!test_1) throw std::logic_error ("Korisnik nije nadjen");
    bool test_2(false);
    for (auto it = knjige.begin(); it != knjige.end(); it++)
        if (it->second->DajKodKogaJe() == &NadjiKorisnika(clanski_broj)) {
            test_2 = true;
            std::cout << "Evidencijski broj: " << it->first << std::endl << "Naslov: " << it->second->DajNaslov() << std::endl << "Pisac: " << it->second->DajAutora() 
            << std::endl << "Zanr: " << it->second->DajZanr() << std::endl << "Godina izdavanja: " << it->second->DajGodinuIzdavanja() << std::endl << std::endl;
        }
    if (!test_2) std::cout << "Nema zaduzenja za tog korisnika!" << std::endl;
}
void Biblioteka::RazduziKnjigu(int evidencijski_broj) {
    bool test_broja(false), test_zaduzenja(true);
    for (auto it = knjige.begin(); it != knjige.end(); it++)
        if (it->first == evidencijski_broj) {
            if (it->second->DajKodKogaJe() == nullptr)  {
                test_zaduzenja = false;
                break;
            }
            test_broja = true;
            break;
        }
    if (!test_zaduzenja) throw std::logic_error ("Knjiga nije zaduzena");
    if (!test_broja) throw std::logic_error ("Knjiga nije nadjena");
    knjige[evidencijski_broj]->RazduziKnjigu(); 
} 
void Biblioteka::ZaduziKnjigu(int evidencijski_broj, int clanski_broj) {
    bool test(false);
    for (auto it = knjige.begin(); it != knjige.end(); it++)
        if (it->first == evidencijski_broj) { test = true; break; }
    if (!test) throw std::logic_error ("Knjiga nije nadjena");
    test = false;
    for (auto it = korisnici.begin(); it != korisnici.end(); it++)
        if (it->first == clanski_broj) { test = true; break; }
    if (!test) throw std::logic_error ("Korisnik nije nadjen");
    if (knjige[evidencijski_broj]->DajKodKogaJe()) throw std::logic_error ("Knjiga vec zaduzena");
    knjige[evidencijski_broj]->ZaduziKnjigu(*korisnici[clanski_broj]);
}

void Biblioteka::IzlistajKnjige() const {
    std::for_each(knjige.begin(), knjige.end(), [](std::pair<int, Knjiga*> k) {
        std::cout << "Evidencijski broj: " << k.first << std::endl << "Naslov: " << k.second->DajNaslov() << std::endl << "Pisac: " << k.second->DajAutora()
        << std::endl << "Zanr: " << k.second->DajZanr() << std::endl << "Godina izdavanja: " << k.second->DajGodinuIzdavanja() << std::endl;
        if (k.second->DajKodKogaJe()) std::cout << "Zaduzena kod korisnika: " << k.second->DajKodKogaJe()->ime << " " << k.second->DajKodKogaJe()->prezime << std::endl;
        std::cout << std::endl;
    });
}
void Biblioteka::IzlistajKorisnike() const {
    for (auto it = korisnici.begin(); it != korisnici.end(); it++)
        std::cout << "Clanski broj: " << it->first << std::endl << "Ime i prezime: " << it->second->ime << " " << it->second->prezime << std::endl
        << "Adresa: " << it->second->adresa << std::endl << "Broj telefona: " << it->second->telefon << std::endl << std::endl;
}
Biblioteka &Biblioteka::operator =(const Biblioteka &b) {
    if (this != &b) {
        auto pom = new Korisnik*[b.korisnici.size()];
        int i(0);
        for (auto it = b.korisnici.begin(); it != b.korisnici.end(); it++)
            pom[i++] = it->second;
        for (auto it = korisnici.begin(); it != korisnici.end(); it++) 
            delete it->second;
        korisnici.erase(korisnici.begin(), korisnici.end());
        auto it_pom = b.korisnici.begin();
        for (int i = 0; i < b.korisnici.size(); i++) {
            korisnici.insert(std::make_pair(it_pom->first, pom[i]));
            it_pom++;
        }
        auto pom2 = new Knjiga*[b.knjige.size()];
        int j(0);
        for (auto it = b.knjige.begin(); it != b.knjige.end(); it++)
            pom2[j++] = it->second;
        for (auto it = knjige.begin(); it != knjige.end(); it++)
            delete it->second;
        knjige.erase(knjige.begin(), knjige.end());
        auto it = b.knjige.begin();
        for (int i = 0; i < b.knjige.size(); i++) {
            knjige.insert(std::make_pair(it->first, pom2[i]));
            it++;
        }
        for (auto it = b.knjige.begin(); it != b.knjige.end(); it++) 
            if (it->second->DaLiJeZaduzena()) 
                for (auto pom = b.korisnici.begin(); pom != b.korisnici.end(); pom++) 
                    if (pom->second == it->second->DajKodKogaJe()) {
                        knjige[it->first]->ZaduziKnjigu(*korisnici[pom->first]);
                        break;
                    }
    }
    return *this;
}
Biblioteka::Biblioteka(Biblioteka &&b) {
    for (auto it = b.korisnici.begin(); it != b.korisnici.end(); it++) {
        korisnici.insert(std::make_pair(it->first, it->second));
        it->second = nullptr;
    }
    for (auto it = b.knjige.begin(); it != b.knjige.end(); it++) {
        knjige.insert(std::make_pair(it->first, it->second));
        it->second = nullptr;
    }
}
Biblioteka::Biblioteka(const Biblioteka &b) {
    try {
        for (auto it = b.korisnici.begin(); it != b.korisnici.end(); it++) {
            auto pom = new Korisnik;
            pom->ime = it->second->ime; pom->prezime = it->second->prezime; pom->adresa = it->second->adresa; pom->telefon = it->second->telefon;
            korisnici.emplace(std::make_pair(it->first, pom));
        }
        try {
            for (auto it = b.knjige.begin(); it != b.knjige.end(); it++) 
                knjige.emplace(std::make_pair(it->first, new Knjiga(it->second->DajNaslov(), it->second->DajAutora(), it->second->DajZanr(), it->second->DajGodinuIzdavanja())));
        }
        catch (...) {
            for (auto it = knjige.begin(); it != knjige.end(); it++) delete it->second;
            knjige.erase(knjige.begin(), knjige.end());
        }
        for (auto it = b.knjige.begin(); it != b.knjige.end(); it++) 
            if (it->second->DaLiJeZaduzena())
                for (auto pom = b.korisnici.begin(); pom != b.korisnici.end(); pom++)
                    if (pom->second == it->second->DajKodKogaJe()) {
                        knjige[it->first]->ZaduziKnjigu(*korisnici[pom->first]);
                        break;
                    }
        
    }
    catch (...) {
        for (auto it = korisnici.begin(); it != korisnici.end(); it++) delete it->second;
        korisnici.clear();
    }
}
Knjiga &Biblioteka::NadjiKnjigu(int evidencijski_broj) const {
    for (auto it = knjige.begin(); it != knjige.end(); it++)
        if (it->first == evidencijski_broj) return *it->second;
    throw std::logic_error ("Knjiga nije nadjena");
}
Korisnik &Biblioteka::NadjiKorisnika(int clanski_broj) const {
    for (auto it = korisnici.begin(); it != korisnici.end(); it++) 
        if (it->first == clanski_broj) return *it->second;
    throw std::logic_error ("Korisnik nije nadjen");
}
void Biblioteka::RegistrirajNovogKorisnika(int clanski_broj, std::string ime, std::string prezime, std::string adresa, std::string telefon) {
    auto pom(new Korisnik);
    pom->ime = ime; pom->prezime = prezime; pom->adresa = adresa; pom->telefon = telefon;
    auto velicina(korisnici.size());
    korisnici[clanski_broj] = pom;
    if (velicina == korisnici.size()) {
        delete pom;
        throw std::logic_error ("Korisnik vec postoji");
    }
}
void Biblioteka::RegistrirajNovuKnjigu(int evidencijski_broj, std::string naslov_knjige, std::string ime_pisca, std::string zanr, int godina_izdavanja) {
    auto pom(new Knjiga(naslov_knjige, ime_pisca, zanr, godina_izdavanja));
    auto velicina(knjige.size());
    knjige[evidencijski_broj] = pom;
    if (velicina == knjige.size()) {
        delete pom;
        throw std::logic_error ("Knjiga vec postoji");
    }
}


int main ()
{
	std::cout << "Dobrodosli!" << std::endl << std::endl;
	try {
	    Biblioteka b;
	    for(;;) { 
	        int n;
	        std::cout << "Odaberite opciju: " << std::endl;
	        std::cout << "  1 - Registrujte novog korisnika" << std::endl << "  2 - Registrujte novu knjigu" << std::endl << "  3 - Zaduzite knjigu"
	        << std::endl << "  4 - Razduzite knjigu" << std::endl << "  5 - Prikaz zaduzenja zeljenog korisnika" << std::endl << "  6 - Spisak korisnika"
	        << std::endl << "  7 - Spisak knjiga" << std::endl << "  0 - Kraj" << std::endl;
	        std::cin >> n;
	        if (n == 1) {
	            for (;;) {
	                try {
	                    int clanski_broj;
	                    std::string ime, prezime, telefon, adresa;
	                    std::cout << "Unesite trazene podatke:" << std::endl;
	                    std::cout << "Clanski broj: "; std::cin >> clanski_broj;
	                    if (!std::cin) throw std::logic_error ("Neispravan unos");
	                    std::cin.ignore(10000, '\n');
	                    std::cout << "Ime: "; std::getline(std::cin, ime);
	                    std::cout << "Prezime: "; std::getline(std::cin, prezime);
	                    std::cout << "Telefon: "; std::getline(std::cin, telefon);
	                    std::cout << "Adresa: "; std::getline(std::cin, adresa);
	                    b.RegistrirajNovogKorisnika(clanski_broj, ime, prezime, telefon, adresa);
	                    break;
	                }
	                catch(std::logic_error e) {
	                    std::cout << e.what() << ". Molimo, ponovite unos:" << std::endl;
	                    std::cin.clear();
	                    std::cin.ignore(10000, '\n');
	                }
	            }
	        }
	        else if (n == 2) {
	            for(;;) {             
	                try {             
	                    int evidencijski_broj, godina_izdavanja;
	                    std::string naslov_knjige, autor, zanr;
	                    std::cout << "Unesite trazene podatke:" << std::endl;
	                    std::cout << "Evidencijski broj: "; std::cin >> evidencijski_broj;
	                    if (!std::cin) throw std::logic_error ("Neispravan unos");
	                    std::cin.ignore(10000, '\n');
	                    std::cout << "Naslov knjige: "; std::getline(std::cin, naslov_knjige);
	                    std::cout << "Zanr: "; std::getline(std::cin, zanr);
	                    std::cout << "Autor: "; std::getline(std::cin, autor);
	                    std::cout << "Godina izdavanja: "; std::cin >> godina_izdavanja;
	                    b.RegistrirajNovuKnjigu(evidencijski_broj, naslov_knjige, autor, zanr, godina_izdavanja);
	                    break;
	                }
	                catch(std::logic_error e) {
	                    std::cout << e.what() << ". Molimo, ponovite unos:" << std::endl;
	                    std::cin.clear();
	                    std::cin.ignore(10000, '\n');
	                }
	            }
	        }
	        else if (n == 3) {
	            for(;;) {
	                try {
	                    int evidencijski_broj, clanski_broj;
	                    std::cout << "Unesite trazene podatke:" << std::endl;
	                    std::cout << "Unesite evidencijski broj knjige: "; std::cin >> evidencijski_broj;
	                    if (!std::cin) throw std::logic_error ("Neispravan unos");
	                    std::cout << "Unesite clanski broj: "; std::cin >> clanski_broj;
	                    if (!std::cin) throw std::logic_error ("Neispravan unos");
	                    b.ZaduziKnjigu(evidencijski_broj, clanski_broj);
	                    break;
	                }
	                catch (std::logic_error e) {
	                    std::cout << e.what() << ". Molimo, ponovite unos:" << std::endl;
	                    std::cin.clear();
	                    std::cin.ignore(10000, '\n');
	                }
	            }
	        }
	        else if (n == 4) {
	            for (;;) {
	                try {
	                  int evidencijski_broj;
	                  std::cout << "Unesite evidencijski broj knjige: "; std::cin >> evidencijski_broj;
	                  if (!std::cin) throw std::logic_error ("Neispravan unos");
	                  b.RazduziKnjigu(evidencijski_broj);
	                  break;
	                }
	                catch(std::logic_error e) {
	                    std::cout << e.what() <<". Molimo, ponovite unos:" << std::endl;
	                    std::cin.clear();
	                    std::cin.ignore(10000, '\n');
	                }
	            }
	        }
	        else if (n == 5) {
	            for (;;) {
	                try {
	                    int clanski_broj;
	                    std::cout << "Unesite clanski broj korisnika: "; std::cin >> clanski_broj;
	                    if (!std::cin) throw std::logic_error ("Neispravan unos");
	                    b.PrikaziZaduzenja(clanski_broj);
	                    break;
	                }
	                catch(std::logic_error e) {
	                    std::cout << e.what() << ". Molimo, ponovite unos:" << std::endl;
	                    std::cin.clear();
	                    std::cin.ignore(10000, '\n');
	                }
	            }
	        }
	        else if (n == 6) {
	            b.IzlistajKorisnike();
	        }
	        else if (n == 7) {
	            b.IzlistajKnjige();
	        }
	        else if (n == 0) break;
	        else {
	            std::cout << "Neispravan unos!" << std::endl;
	            std::cin.clear();
	            std::cin.ignore(10000, '\n');
	        }
	    }
	}
	catch(...) {
	    std::cout << "Nedovoljno memorije" << std::endl;
	}
	std::cout << "Dovidjenja!";
	return 0;
}