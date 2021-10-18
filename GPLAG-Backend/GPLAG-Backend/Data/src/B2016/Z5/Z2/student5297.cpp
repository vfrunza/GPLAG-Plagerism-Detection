/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <map>
#include <string>
#include <memory>
#include <stdexcept>

struct Korisnik {   
    std::string ime, prezime, adresa, telefon;    
};

class Knjiga {
    std::string naslov, ime_pisca, zanr;
    int godina_izdavanja;
    std::shared_ptr<Korisnik> pok;
public:
    Knjiga (std::string n, std::string i_p, std::string z, int g_i) : naslov(n), ime_pisca(i_p), zanr(z), godina_izdavanja(g_i), pok(nullptr) {}
    std::string DajNaslov() const { return naslov; }
    std::string DajAutora() const { return ime_pisca; }
    std::string DajZanr() const { return zanr; }
    int DajGodinuIzdavanja() const { return godina_izdavanja; }
    std::shared_ptr<Korisnik> DajKodKogaJe() const { return pok; }
    void ZaduziKnjigu(Korisnik &korisnik) { pok=std::make_shared<Korisnik>(korisnik); }
    void RazduziKnjigu() { pok=nullptr; }
    bool DaLiJeZaduzena() const { if(pok==nullptr) return false; return true; }
};

class Biblioteka {
    std::map<int, std::shared_ptr<Korisnik>> korisnici;
    std::map<int, std::shared_ptr<Knjiga>> knjige;
public:
    Biblioteka() {}
    ~Biblioteka()=default;
    Biblioteka(Biblioteka &biblioteka);
    Biblioteka operator=(Biblioteka &biblioteka);
    Biblioteka(Biblioteka &&biblioteka);
    Biblioteka operator=(Biblioteka &&biblioteka);
    void RegistrirajNovogKorisnika(int clanski_broj, std::string i, std::string p, std::string a, std::string br_t);
    void RegistrirajNovuKnjigu(int broj_knjige, std::string n, std::string i_p, std::string z, int g_i);
    Korisnik &NadjiKorisnika(int clanski_broj) const;
    Knjiga &NadjiKnjigu(int broj_knjige) const;
    void IzlistajKorisnike() const;
    void IzlistajKnjige() const;
    void ZaduziKnjigu(int broj_knjige, int clanski_broj);
    void RazduziKnjigu(int broj_knjige);
    void PrikaziZaduzenja(int clanski_broj) const;
};
/*
Biblioteka::~Biblioteka() {
    for(auto x: korisnici) {
        delete x.second;
    }
    for(auto x: knjige) {
        delete x.second;
    }
}*/

Biblioteka::Biblioteka(Biblioteka &biblioteka) {
    for(auto x: biblioteka.korisnici) {  
        korisnici.insert(std::make_pair(x.first, std::make_shared<Korisnik>(*(x.second))));
    }
    for(auto x: biblioteka.knjige) {
        knjige.insert(std::make_pair(x.first, std::make_shared<Knjiga>(*(x.second))));
    }
}

Biblioteka Biblioteka::operator=(Biblioteka &biblioteka) {
    for(auto x: biblioteka.korisnici) {
        korisnici.insert(std::make_pair(x.first, std::make_shared<Korisnik>(*(x.second))));
        biblioteka.korisnici.erase(x.first);
    }
    for(auto x: biblioteka.knjige) {
        knjige.insert(std::make_pair(x.first, std::make_shared<Knjiga>(*(x.second))));
        biblioteka.knjige.erase(x.first);
    }
    return *this;
}

Biblioteka::Biblioteka(Biblioteka &&biblioteka) {
    swap(korisnici, biblioteka.korisnici);
    swap(knjige, biblioteka.knjige);
}

Biblioteka Biblioteka::operator=(Biblioteka &&biblioteka) {
    swap(korisnici, biblioteka.korisnici);
    swap(knjige, biblioteka.knjige);
    return *this;
}

void Biblioteka::RegistrirajNovogKorisnika(int clanski_broj, std::string i, std::string p, std::string a, std::string br_t) {
    auto it(korisnici.find(clanski_broj));
    if(it!=korisnici.end()) {
        throw std::logic_error("Korisnik vec postoji");
    }
    Korisnik k;
    k.ime=i; k.prezime=p; k.adresa=a; k.telefon=br_t;
    std::shared_ptr<Korisnik> pk=std::make_shared<Korisnik>(k);
    korisnici.insert(std::make_pair(clanski_broj, std::make_shared<Korisnik>(*(pk))));
}

void Biblioteka::RegistrirajNovuKnjigu(int broj_knjige, std::string n, std::string i_p, std::string z, int g_i) {
    auto it(knjige.find(broj_knjige));
    if(it!=knjige.end()) {
        throw std::logic_error("Knjiga vec postoji");
    }
    Knjiga k(n, i_p, z, g_i);
    std::shared_ptr<Knjiga> pk=std::make_shared<Knjiga>(k);
    knjige.insert(std::make_pair(broj_knjige, std::make_shared<Knjiga>(*(pk))));
}

Korisnik &Biblioteka::NadjiKorisnika(int clanski_broj) const {
    auto it(korisnici.find(clanski_broj));
    if(it==korisnici.end()) {
        throw std::logic_error("Korisnik nije nadjen");
    }
    return *it->second;
}

Knjiga &Biblioteka::NadjiKnjigu(int broj_knjige) const {
    auto it(knjige.find(broj_knjige));
    if(it==knjige.end()) {
        throw std::logic_error("Knjiga nije nadjena");
    }
    return *it->second;
}

void Biblioteka::IzlistajKorisnike() const {
    for (auto x: korisnici) {
        std::cout << "Clanski broj: " << x.first << std::endl;
        std::cout << "Ime i prezime: " << x.second->ime << " " << x.second->prezime << std::endl;
        std::cout << "Adresa: " << x.second->adresa << std::endl;
        std::cout << "Broj telefona: " << x.second->telefon << std::endl;
        std::cout << std::endl;
    }
}

void Biblioteka::IzlistajKnjige() const {
    for(auto x: knjige) {
        std::cout << "Evidencijski broj: " << x.first << std::endl;
        std::cout << "Naslov: " << x.second->DajNaslov() << std::endl;
        std::cout << "Pisac: " << x.second->DajAutora() << std::endl;
        std::cout << "Zanr: " << x.second->DajZanr() << std::endl;
        std::cout << "Godina izdavanja: " << x.second->DajGodinuIzdavanja() << std::endl;
        auto pok=x.second->DajKodKogaJe();
        if(pok!=nullptr) {
            std::cout << "Zaduzena kod korisnika: " << pok->ime << " " << pok->prezime << std::endl;
        }
        std::cout << std::endl;
    }
}

void Biblioteka::ZaduziKnjigu(int broj_knjige, int clanski_broj) {
    auto it1(knjige.find(broj_knjige));
    if(it1==knjige.end()) throw std::logic_error("Knjiga nije nadjena");
    auto it2(korisnici.find(clanski_broj));
    if(it2==korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
    if((it1->second)->DaLiJeZaduzena()) throw std::logic_error("Knjiga vec zaduzena");
    else (it1->second)->ZaduziKnjigu(*korisnici[clanski_broj]);
}

void Biblioteka::RazduziKnjigu(int broj_knjige) {
    auto it1(knjige.find(broj_knjige));
    if(it1==knjige.end()) throw std::logic_error("Knjiga nije nadjena");
    if((it1->second)->DaLiJeZaduzena()==false) throw std::logic_error("Knjiga nije zaduzena");
    (it1->second)->RazduziKnjigu();
}

void Biblioteka::PrikaziZaduzenja(int clanski_broj) const {
    auto it(korisnici.find(clanski_broj));
    if(it==korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
    bool zaduzen(false);
    for(auto x: knjige) {
        if(x.second->DajKodKogaJe()==it->second) {
            std::cout << "Evidencijski broj: " << x.first << std::endl;
            std::cout << "Naslov: " << x.second->DajNaslov() << std::endl;
            std::cout << "Pisac: " << x.second->DajAutora() << std::endl;
            std::cout << "Zanr: " << x.second->DajZanr() << std::endl;
            std::cout << "Godina izdavanja: " << x.second->DajGodinuIzdavanja() << std::endl;
            std::cout << std::endl;
            zaduzen=true;
        }
    }
    if(zaduzen==false) std::cout << "Nema zaduzenja za tog korisnika" << std::endl;
}

int main () {
    Biblioteka b;
    while(1) {
        std::cout << "Izaberite opciju(1-unesi novog korisnika, 2-unesi novu knjigu, 3- nadji korisnika, 4-nadji knjigu, 5-zaduzi knjigu, 6-razduzi knjigu, 7-kraj): ";
        int broj;
        std::cin >> broj;
        if(broj==1) {
            int clanski_broj;
            std::string ime, prezime, adresa, telefon;
            std::cout << "Unesite clanski broj: "; std::cin >> clanski_broj;
            std::cout << "Unesite ime: "; std::cin >> ime;
            std::cout << "Unesite prezime: "; std::cin >> prezime >> std::ws;
            std::cout << "Unesite adresu: "; std::getline(std::cin, adresa);
            std::cout << "Unesite telefon: "; std::cin >> telefon;
            b.RegistrirajNovogKorisnika(clanski_broj, ime, prezime, adresa, telefon);
        }
        else if(broj==2) {
            int broj_knjige, godina_izdavanja;
            std::string naslov, ime_pisca, zanr;
            std::cout << "Unesite broj: "; std::cin >> broj_knjige;
            std::cout << "Unesite naslov: "; std::cin >> std::ws; std::getline(std::cin, naslov);
            std::cout << "Unesite ime pisca: "; std::cin >> std::ws; std::getline(std::cin, ime_pisca);
            std::cout << "Unesite zanr: "; std::cin >> zanr;
            std::cout << "Unesite godinu izdavanja: "; std::cin >> godina_izdavanja;
            b.RegistrirajNovuKnjigu(broj_knjige, naslov, ime_pisca, zanr, godina_izdavanja);
        }
        else if(broj==3) {
            int clanski_broj;
            std::cout << "Unesite clanski broj korisnika kojeg zelite naci: "; std::cin >> clanski_broj;
            b.NadjiKorisnika(clanski_broj);
            b.PrikaziZaduzenja(clanski_broj);
        }
        else if(broj==4) {
            int broj_knjige;
            std::cout << "Unesite broj knjige koju zelite naci: "; std::cin >> broj_knjige;
            b.NadjiKnjigu(broj_knjige);
        }
        else if(broj==5) {
            int broj_knjige, clanski_broj;
            std::cout << "Unesite broj knjige koju zelite zaduziti: "; std::cin >> broj_knjige;
            std::cout << "Unesite clanski broj korisnika koji zaduzuje knjigu: "; std::cin >> clanski_broj;
            b.ZaduziKnjigu(broj_knjige, clanski_broj);
        }
        else if(broj==6) {
            int broj_knjige;
            std::cout << "Unesite broj knjige koju zelite razduziti: "; std::cin >> broj_knjige;
            b.RazduziKnjigu(broj_knjige);
        }
        else if(broj==7) {
            std::cout << "Knjige: " << std::endl;
            b.IzlistajKnjige();
            std::cout << "Korisnici: " << std::endl;
            b.IzlistajKorisnike();
            break;
        }
        else {
            std::cout << "Pogresan broj" << std::endl;
            continue;
        }
    }
    Biblioteka k=b;
    k.IzlistajKorisnike();
	return 0;
}