/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <algorithm>
#include <new>
#include <stdexcept>

struct Korisnik {
  std::string ime, prezime, adresa, telefon;  
};

class Knjiga {
    std::string naslov;
    std::string pisac;
    std::string zanr;
    int godina;
    Korisnik* korisnik{};
public:
    Knjiga(std::string n, std::string p, std::string z, int g) : korisnik(nullptr) {
        naslov = n;
        pisac = p;
        zanr = z;
        godina = g;
    }
    
    std::string DajNaslov() const { return naslov; }
    std::string DajAutora() const { return pisac; }
    std::string DajZanr() const { return zanr; }
    int DajGodinuIzdavanja() const { return godina; }
    Korisnik *DajKodKogaJe() const { return korisnik; } 
    void ZaduziKnjigu(Korisnik &k) { korisnik = &k; }
    void RazduziKnjigu() { korisnik = nullptr; }
    bool DaLiJeZaduzena() const { if(korisnik == nullptr) return false; return true; }
};

class Biblioteka {
    std::map<int, Korisnik*> korisnici;
    std::map<int, Knjiga*> knjige;
public:
    Biblioteka() { }
    Biblioteka(Biblioteka &b) {
        for(auto i = (b.korisnici).begin(); i != (b.korisnici).end(); i++) {
            korisnici.insert(std::make_pair(i->first, new Korisnik(*(i->second))));
        }
        
        for(auto i = (b.knjige).begin(); i != (b.knjige).end(); i++) {
            knjige.insert(std::make_pair(i->first, new Knjiga(*(i->second))));
        }
    }
    Biblioteka(Biblioteka &&b) {
        std::swap(korisnici, b.korisnici);
        std::swap(knjige, b.knjige);
    }
    Biblioteka &operator=(Biblioteka &b);
    Biblioteka &operator=(Biblioteka &&b);
    ~Biblioteka() {
        for(auto i = korisnici.begin(); i != korisnici.end(); i++) {
            delete i->second;
            i->second = nullptr;
        }
        for(auto i = knjige.begin(); i != knjige.end(); i++) {
            delete i->second;
            i->second = nullptr;
        }
    }
    void RegistrirajNovogKorisnika(int cl, std::string ime, std::string prezime, std::string adresa, std::string telefon);
    void RegistrirajNovuKnjigu(int cl, std::string naslov, std::string pisac, std::string zanr, int godina);
    Korisnik &NadjiKorisnika(int clanski);
    Knjiga &NadjiKnjigu(int clanski);
    void IzlistajKorisnike() const;
    void IzlistajKnjige() const;
    void ZaduziKnjigu(int br_knjige, int br_korisnika);
    void RazduziKnjigu(int clanski);
    void PrikaziZaduzenja(int clanski) const;
};

Biblioteka &Biblioteka::operator=(Biblioteka &b) {
    if(&b != this) {
        for(auto i = korisnici.begin(); i != korisnici.end(); i++) {
            delete (i -> second);
            i->second = nullptr;
        }
        korisnici = b.korisnici;
            
        for(auto i = knjige.begin(); i != knjige.end(); i++) {
            delete (i -> second);
            i->second = nullptr;
        }
        knjige = b.knjige;
    }
    return *this;
}
Biblioteka &Biblioteka::operator=(Biblioteka &&b) {
    std::swap(korisnici, b.korisnici);
    std::swap(knjige, b.knjige);
    return *this;
}
void Biblioteka::RegistrirajNovogKorisnika(int cl, std::string ime, std::string prezime, std::string adresa, std::string telefon) {
    auto it = korisnici.find(cl);
    if(it != korisnici.end()) throw std::logic_error("Korisnik vec postoji");
    Korisnik novi{ime, prezime, adresa, telefon};
    //korisnici.insert(std::make_pair(cl, new Korisnik(novi)));
    korisnici[cl] = new Korisnik(novi);
}
void Biblioteka::RegistrirajNovuKnjigu(int cl, std::string naslov, std::string pisac, std::string zanr, int godina) {
    auto it = knjige.find(cl);
    if(it != knjige.end()) throw std::logic_error("Knjiga vec postoji");
    Knjiga nova(naslov, pisac, zanr, godina);
    knjige[cl] = new Knjiga(nova);
}
Korisnik &Biblioteka::NadjiKorisnika(int clanski) {
    auto it = korisnici.find(clanski);
    if(it == korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
    return *korisnici[clanski];
}
Knjiga &Biblioteka::NadjiKnjigu(int clanski) {
    auto it = knjige.find(clanski);
    if(it == knjige.end()) throw std::logic_error("Knjiga nije nadjena");
    return *knjige[clanski];
}
void Biblioteka::IzlistajKorisnike() const {
    for(auto i = korisnici.begin(); i != korisnici.end(); i++) {
        std::cout << "Clanski broj: " << i -> first << std::endl;
        std::cout << "Ime i prezime: " << (i -> second) -> ime << " " << (i -> second) -> prezime << std::endl;
        std::cout << "Adresa: " << (i -> second) -> adresa << std::endl;
        std::cout << "Broj telefona: " << (i -> second ) -> telefon << std::endl;
        std::cout << std::endl;
    }
}
void Biblioteka::IzlistajKnjige() const {
    for(auto i = knjige.begin(); i != knjige.end(); i++) {
        std::cout << "Evidencijski broj: " << i->first << std::endl;
        std::cout << "Naslov: " << (*(i -> second)).DajNaslov() << std::endl;
        std::cout << "Pisac: " << (*(i -> second)).DajAutora() << std::endl;
        std::cout << "Zanr: " << (*(i -> second)).DajZanr() << std::endl;
        std::cout << "Godina izdavanja: " << (*(i -> second)).DajGodinuIzdavanja() << std::endl;
        if((*(i -> second)).DaLiJeZaduzena()) {
            Korisnik *trenutni = (*(i->second)).DajKodKogaJe();
            std::cout << "Zaduzena kod korisnika: " << trenutni -> ime << " " << trenutni -> prezime << std::endl;
        }
        std::cout << std::endl;
    }
}
void Biblioteka::ZaduziKnjigu(int br_knjige, int br_korisnika) {
    auto it1 = knjige.find(br_knjige);
    if(it1 == knjige.end()) throw std::logic_error("Knjiga nije nadjena");
    auto it2 = korisnici.find(br_korisnika);
    if(it2 == korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
    if((it1->second) -> DaLiJeZaduzena()) throw std::logic_error("Knjiga vec zaduzena");
    (it1->second) -> ZaduziKnjigu(*korisnici[br_korisnika]);
}
void Biblioteka::RazduziKnjigu(int clanski) {
    auto it = knjige.find(clanski);
    if(it == knjige.end()) throw std::logic_error("Knjiga nije nadjena");
    if(!(*(it->second)).DaLiJeZaduzena()) throw std::logic_error("Knjiga nije zaduzena");
    (*(it -> second)).RazduziKnjigu();
}
void Biblioteka::PrikaziZaduzenja(int clanski) const {
    auto it = korisnici.find(clanski);
    if(it == korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
    bool zaduzio = false;
    for(auto i = knjige.begin(); i != knjige.end(); i++) {
        if((*(i -> second)).DajKodKogaJe() == (it -> second)) {
            zaduzio = true;
            std::cout << "Evidencijski broj: " << i -> first << std::endl;
            std::cout << "Naslov: " << (*(i -> second)).DajNaslov() << std::endl;
            std::cout << "Pisac: " << (*(i -> second)).DajAutora() << std::endl;
            std::cout << "Zanr: " << (*(i -> second)).DajZanr() << std::endl;
            std::cout << "Godina izdavanja: " << (*(i -> second)).DajGodinuIzdavanja() << std::endl;
            std::cout << std::endl;
        }
    }
    if(!zaduzio) std::cout << "Nema zaduzenja za tog korisnika!";
}


int main ()
{
    int broj;
    //1 - registriraj novog korisnika
    //2 - registriraj novu knjigu
    //3 - nadji korisnika
    //4 - nadji knjigu
    //5 - izlistaj korisnike
    //6 - izlistaj knjige
    //7 - zaduzi knjigu
    //8 - razduzi knjigu
    //9 - prikazi zaduzenja
    Biblioteka b1;
    for(;;) {
        std::cout << "Unesite opciju: ";
        std::cin >> broj;
        switch(broj) {
            case 0: {
                std::cout << "Cao";
                return 0;
            }
            case 1: {
                int clanski;
                std::string ime, prezime, adresa, telefon;
                std::cout << "Unesi clanski broj, ime, prezime, adresu i telefon: ";
                std::cin >> clanski; std::cin >> std::ws;
                std::getline(std::cin, ime); std::cin >> std::ws;
                std::getline(std::cin, prezime); std::cin >> std::ws;
                std::getline(std::cin, adresa); std::cin >> std::ws;
                std::getline(std::cin, telefon); 
                b1.RegistrirajNovogKorisnika(clanski, ime, prezime, adresa, telefon);
                break;
            }
            case 2: {
                int clanski, godina;
                std::string naslov, pisac, zanr;
                std::cout << "Unesi evidencijski broj, naslov, pisca i godinu izdavanja knjige: ";
                std::cin >> clanski; std::cin >> std::ws;
                std::getline(std::cin, naslov); std::cin >> std::ws;
                std::getline(std::cin, pisac); std::cin >> std::ws;
                std::getline(std::cin, zanr); std::cin >> std::ws;
                std::cin >> godina; 
                b1.RegistrirajNovuKnjigu(clanski, naslov, pisac, zanr, godina);
                break;
            }
            case 3: {
                std::cout << "Unesite clanski broj korisnika: ";
                int clanski;
                std::cin >> clanski;
                Korisnik neki = b1.NadjiKorisnika(clanski);
                std::cout << "Podaci o korisniku: " << std::endl;
                std::cout << neki.ime << " " << neki.prezime << " " << neki.adresa << " " << neki.telefon;
                break;
            }
            case 4: {
                std::cout << "Unesi evidencijski broj knjige: ";
                int ev;
                std::cin >> ev;
                Knjiga neka = b1.NadjiKnjigu(ev);
                std::cout << "Podaci o knjizi: " << std::endl;
                std::cout << neka.DajNaslov() << " " << neka.DajAutora() << " " << neka.DajZanr() << " " << neka.DajGodinuIzdavanja();
                break;
            }
            case 5: {
                std::cout << "Korisnici: " << std::endl;
                b1.IzlistajKorisnike();
                break;
            }
            case 6: {
                std::cout << "Biblioteka: " << std::endl;
                b1.IzlistajKnjige();
                break;
            }
            case 7: {
                std::cout << "Unesi evidencijski broj knjige i clanski broj korisnika: ";
                int ev, br;
                std::cin >> ev >> br;
                b1.ZaduziKnjigu(ev,br);
                break;
            }
            case 8: {
                std::cout << "Unesi evidencijski broj knjige: ";
                int ev;
                std::cin >> ev;
                b1.RazduziKnjigu(ev);
                break;
            }
            case 9: {
                std::cout << "Unesi clanski broj korisnika: ";
                int clanski;
                std::cin >> clanski;
                b1.PrikaziZaduzenja(clanski);
                break;
            }
        }
    }
	return 0;
}