#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <algorithm>

struct Korisnik {
    std::string ime, prezime, adresa, telefon;
};
class Knjiga {
    std::string naslov, ime_pisca, zanr;
    int god_izdavanja;
    Korisnik *p;
public:
    Knjiga(std::string naslov, std::string ime_pisca, std::string zanr, int god_izdavanja, Korisnik *p = nullptr) : naslov(naslov), 
    ime_pisca(ime_pisca), zanr(zanr), god_izdavanja(god_izdavanja), p(p) {}
    std::string DajNaslov() const { return naslov; }
    std::string DajAutora() const { return ime_pisca; }
    std::string DajZanr() const { return zanr; }
    int DajGodinuIzdavanja() const { return god_izdavanja; }
    Korisnik *DajKodKogaJe() { return p; }
    void ZaduziKnjigu(Korisnik &k) { p = &k; }
    void RazduziKnjigu() { p = nullptr; }
    bool DaLiJeZaduzena() const { return p != nullptr; }
};
class Biblioteka {
    std::map<int, Korisnik*> korisnici;
    std::map<int, Knjiga*> knjige;
public:
    Biblioteka() {}
    ~Biblioteka();
    Biblioteka(const Biblioteka &a);
    Biblioteka(Biblioteka &&a);
    Biblioteka &operator =(Biblioteka a);
    void RegistrirajNovogKorisnika(int clanski_broj, std::string ime, std::string prezime, std::string adresa, std::string telefon);
    void RegistrirajNovuKnjigu(int ev_broj, std::string naslov, std::string ime_pisca, std::string zanr, int god_izdavanja);
    Korisnik &NadjiKorisnika(int clanski_broj);
    Knjiga &NadjiKnjigu(int ev_broj);
    Knjiga NadjiKnjigu(int ev_broj) const;
    Korisnik NadjiKorisnika(int clanski_broj) const;
    void IzlistajKorisnike() const;
    void IzlistajKnjige() const;
    void ZaduziKnjigu(int ev_broj, int clanski_broj);
    void RazduziKnjigu(int ev_broj);
    void PrikaziZaduzenja(int clanski_broj) ;
};
Biblioteka::~Biblioteka() {
    for(auto it=knjige.begin(); it!=knjige.end(); it++)
        delete it->second;
    for(auto it=korisnici.begin(); it!=korisnici.end(); it++)
        delete it->second;
}
Biblioteka::Biblioteka(const Biblioteka &a) {
    //for(auto it=a.korisnici.begin(); it != a.korisnici.end(); it++)
    //    korisnici[it->first] = new Korisnik(*it->second);
    for(auto x : a.korisnici) korisnici[x.first] = new Korisnik(*x.second);
    for(auto it=a.knjige.begin(); it!=a.knjige.end(); it++)
        knjige[it->first] = new Knjiga(*it->second);
}
Biblioteka::Biblioteka(Biblioteka &&a) {
    //std::swap(korisnici, a.korisnici); std::swap(knjige, a.knjige);
    korisnici = a.korisnici; knjige = a.knjige;
    a.korisnici.clear(); a.knjige.clear();
}
Biblioteka &Biblioteka::operator =(Biblioteka a) {
    std::swap(knjige, a.knjige); std::swap(korisnici, a.korisnici); 
    return *this;
}
void Biblioteka::RegistrirajNovogKorisnika(int clanski_broj, std::string ime, std::string prezime, std::string adresa, std::string telefon) {
    auto it(korisnici.find(clanski_broj));
    if(it != korisnici.end()) throw std::logic_error("Korisnik vec postoji");
    korisnici[clanski_broj] = new Korisnik;
    korisnici[clanski_broj]->ime = ime; 
    korisnici[clanski_broj]->prezime = prezime;
    korisnici[clanski_broj]->adresa = adresa;
    korisnici[clanski_broj]->telefon = telefon;
}
void Biblioteka::RegistrirajNovuKnjigu(int ev_broj, std::string naslov, std::string ime_pisca, std::string zanr, int god_izdavanja) {
    auto it(knjige.find(ev_broj));
    if(it != knjige.end()) throw std::logic_error("Knjiga vec postoji");
    knjige[ev_broj] = new Knjiga{naslov, ime_pisca, zanr, god_izdavanja};
}
Korisnik &Biblioteka::NadjiKorisnika(int clanski_broj) {
    if(korisnici.find(clanski_broj) == korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
    return *korisnici[clanski_broj];
}
Korisnik Biblioteka::NadjiKorisnika(int clanski_broj) const {
    if(korisnici.find(clanski_broj) == korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
    return *korisnici.find(clanski_broj)->second;
}
Knjiga &Biblioteka::NadjiKnjigu(int ev_broj)  {
    if(knjige.find(ev_broj) == knjige.end()) throw std::logic_error("Knjiga nije nadjena");
    return *knjige[ev_broj];
}
Knjiga Biblioteka::NadjiKnjigu(int ev_broj) const {
    if(knjige.find(ev_broj) == knjige.end()) throw std::logic_error("Knjiga nije nadjena");
    return *knjige.find(ev_broj)->second;
}
void Biblioteka::IzlistajKorisnike() const {
    for(auto it=korisnici.begin(); it!=korisnici.end(); it++) {
        std::cout << "Clanski broj: " << it->first << std::endl <<
        "Ime i prezime: " << it->second->ime << " " << it->second->prezime << std::endl <<
        "Adresa: " << it->second->adresa << std::endl <<
        "Broj telefona: " << it->second->telefon << std::endl;
        std::cout << std::endl;
    }
}
void Biblioteka::IzlistajKnjige() const {
    for(auto it=knjige.begin(); it!=knjige.end(); it++) {
        std::cout << "Evidencijski broj: " << it->first << std::endl <<
        "Naslov: " << it->second->DajNaslov() << std::endl << "Pisac: " << it->second->DajAutora() << std::endl <<
        "Zanr: " << it->second->DajZanr() << std::endl << "Godina izdavanja: " << it->second->DajGodinuIzdavanja() << std::endl;
        if(it->second->DaLiJeZaduzena())
            std::cout << "Zaduzena kod korisnika: " << it->second->DajKodKogaJe()->ime <<
            " " << it->second->DajKodKogaJe()->prezime << std::endl;
        std::cout << std::endl;
    }
}
void Biblioteka::ZaduziKnjigu(int ev_broj, int clanski_broj) {
    if(NadjiKnjigu(ev_broj).DaLiJeZaduzena()) throw std::logic_error("Knjiga vec zaduzena");
    knjige[ev_broj]->ZaduziKnjigu(*korisnici[clanski_broj]);
}
void Biblioteka::RazduziKnjigu(int ev_broj) {
    auto ref(NadjiKnjigu(ev_broj));
    if(!ref.DaLiJeZaduzena()) throw std::logic_error("Knjiga nije zaduzena");
    NadjiKnjigu(ev_broj).RazduziKnjigu();
}
void Biblioteka::PrikaziZaduzenja(int clanski_broj) {
    Korisnik *pom(&NadjiKorisnika(clanski_broj));
    bool nije(true);
    for(auto it=knjige.begin(); it!=knjige.end(); it++)
        if(it->second->DajKodKogaJe() == pom) {
            std::cout << "Evidencijski broj: " << it->first << std::endl <<
            "Naslov: " << it->second->DajNaslov() << std::endl << "Pisac: " << it->second->DajAutora() << std::endl <<
            "Zanr: " << it->second->DajZanr() << std::endl << "Godina izdavanja: " << it->second->DajGodinuIzdavanja() << std::endl
            << std::endl;
            nije = false;
        } 
    if(nije) std::cout << "Nema zaduzenja za tog korisnika!";
}
int main () {
    Biblioteka b;
    for(;;) {
    try {
    int opcija;
    std::cout << "Unesite opciju: 1 - Registriraj novog korisnika" << std::endl << "2 - RegistrirajNovuKnjigu" << std::endl <<
    "3 - Nadji korisnika" << std::endl << "4 - Nadji knjigu" << std::endl << "5 - Izlistaj Korisnike"
    << std::endl << "6 - Izlistaj knjige" << "7 - Zaduzi knjigu" << std::endl << "8 - Razduzi knjigu" 
    << std::endl << "9 - Prikazi zaduzenja" << std::endl << "10 - Kraj" << std::endl;
    std::cin >> opcija;
    if(opcija == 1) {
        std::cout << "Unesite clanski broj, ime, prezime, adresu i telefon novog korisnika: " << std::endl;
        std::string ime, prezime, adresa, tel;
        int clanski; 
        std::cin >> clanski; std::cin.ignore(1000, '\n');
        std::getline(std::cin, ime); std::getline(std::cin, prezime); std::getline(std::cin, adresa);
        std::getline(std::cin, tel);
        b.RegistrirajNovogKorisnika(clanski, ime, prezime, adresa, tel);
    }
    if(opcija == 2) {
        std::cout << "Unesite evidencijski broj, godinu izdavanja, naslov, ime pisca i zanr: " << std::endl;
        int evidencijski, god;
        std::string naslov, ime, zanr;
        std::cin >> evidencijski >> god; std::cin.ignore(1000, '\n');
        std::getline(std::cin, naslov); std::getline(std::cin, ime); std::getline(std::cin, zanr);
        b.RegistrirajNovuKnjigu(evidencijski, naslov, ime, zanr, god);
    }
    if(opcija == 3) {
        std::cout << "Unesite clanski broj korisnika: " << std::endl;
        int clanski;
        std::cin >> clanski; std::cin.ignore(1000, '\n');
        Korisnik k(b.NadjiKorisnika(clanski));
        std::cout << "Unesite opciju: 1 - Zaduzi knjigu" << std::endl << "2 - Razduzi knjigu" << std::endl << "3 - Prikazi zaduzenja" << std::endl;
        int o; std::cin >> o;
        if(o == 1) {
            std::cout << "Unesite evidencijski broj knjige: " << std::endl;
            int evidencijski; std::cin >> evidencijski;
            b.ZaduziKnjigu(clanski, evidencijski);
        }
        if(o == 2) {
            std::cout << "Unesite evidencijski broj knjige: " << std::endl;
            int evidencijski; std::cin >> evidencijski;
            b.RazduziKnjigu(evidencijski);
        }
        if(o == 3) b.PrikaziZaduzenja(clanski);
    }
    if(opcija == 4) {
        std::cout << "Unesite evidencijski broj knjige: " << std::endl;
        int evidencijski; std::cin >> evidencijski; std::cin.ignore(1000, '\n');
        Knjiga k(b.NadjiKnjigu(evidencijski));
        std::cout << "Unesite opciju: 1 - Naslov, 2 - Ime pisca, 3 - Zanr, 4 - Godina izdavanja" << std::endl;
        int o; std::cin >> o; std::cin.ignore(1000, '\n');
        if(o == 1) std::cout << k.DajNaslov() << std::endl;
        if(o == 2) std::cout << k.DajAutora() << std::endl;
        if(o == 3) std::cout << k.DajZanr() << std::endl;
        if(o == 4)std::cout << k.DajGodinuIzdavanja() << std::endl;
    }
    if(opcija == 5) b.IzlistajKorisnike();
    if(opcija == 6) b.IzlistajKnjige();
    if(opcija == 7) {
        std::cout << "Unesite clanski i evidencijski: "<< std::endl;
        int c, e; std::cin >> c >> e; std::cin.ignore(1000,'\n');
        b.ZaduziKnjigu(e,c);
    }
    if(opcija == 8) {
        std::cout << "Unesite evidencijski: " << std::endl;
        int e; std::cin >> e; std::cin.ignore(1000, '\n');
        b.RazduziKnjigu(e);
    }
    if(opcija == 9) {
        std::cout << "Unesite clanski: " << std::endl;
        int c;
        std::cin >> c; std::cin.ignore(1000, '\n');
        b.PrikaziZaduzenja(c);
    }
    if(opcija == 10) break;
    }
    catch(std::logic_error e) {
        std::cout << e.what() << std::endl;
    }
    catch(...) {
        std::cout << "Alokacija" << std::endl;
    }
    }
	return 0;
}