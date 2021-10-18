/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>


struct Korisnik{
    std::string ime, prezime, adresa, telefon;
};

class Knjiga{
    std::string naslov, ime_pisca, zanr;
    int godina_izdavanja;
    Korisnik *zaduzio;
    
    public:
    Knjiga(std::string naslov, std::string ime_pisca, std::string zanr, int godina_izdavanja) : naslov(naslov), ime_pisca(ime_pisca), zanr(zanr), godina_izdavanja(godina_izdavanja) { zaduzio=nullptr; }
    std::string DajNaslov() const { return naslov; }
    std::string DajAutora() const { return ime_pisca; }
    std::string DajZanr() const { return zanr; }
    int DajGodinuIzdavanja() const { return godina_izdavanja; }
    Korisnik *DajKodKogaJe() const { return zaduzio; }
    void ZaduziKnjigu(Korisnik &zaduzuje) { zaduzio=&zaduzuje; }
    void RazduziKnjigu() { zaduzio=nullptr; }
    bool DaLiJeZaduzena() const { if(zaduzio==nullptr) return false; return true; }
    //~Knjiga() { delete zaduzio; }
};

class Biblioteka {
    std::map<int, Korisnik*> korisnici;
    std::map<int, Knjiga*> knjige;
    
    public:
    Biblioteka() {};
    Biblioteka(const Biblioteka &biblio);
    Biblioteka &operator =(const Biblioteka &biblio);
    void RegistrirajNovogKorisnika(int clanski_br, std::string ime, std::string prezime, std::string adresa, std::string br_tel);
    void RegistrirajNovuKnjigu(int evidencijski_br, std::string naslov, std::string pisac, std::string zanr, int godina_izdavanja);
    Korisnik &NadjiKorisnika(int clanski_br);
    Knjiga &NadjiKnjigu(int evidencijski_br);
    void IzlistajKorisnike();
    void IzlistajKnjige();
    void ZaduziKnjigu(int evidencijski_br, int clanski_br);
    void RazduziKnjigu(int evidencijski_br);
    void PrikaziZaduzenja(int clanski_br);
    ~Biblioteka() {
        for(auto it=korisnici.begin(); it!=korisnici.end(); it++) delete it->second;
        for(auto it=knjige.begin(); it!=knjige.end(); it++) delete it->second; 
    }
};

Biblioteka::Biblioteka(const Biblioteka &biblio) {
    for(auto it=biblio.korisnici.begin(); it!=biblio.korisnici.end(); it++) korisnici.insert(std::make_pair(it->first, it->second));
    for(auto it=biblio.knjige.begin(); it!=biblio.knjige.end(); it++) knjige.insert(std::make_pair(it->first, it->second));
}
Biblioteka &Biblioteka::operator =(const Biblioteka &biblio) {
    if(this== &biblio) return *this;
    for(auto it=korisnici.begin(); it!=korisnici.end(); it++) delete it->second;
    for(auto it=knjige.begin(); it!=knjige.end(); it++) delete it->second;
    for(auto it=biblio.korisnici.begin(); it!=biblio.korisnici.end(); it++) korisnici.insert(std::make_pair(it->first, it->second));
    for(auto it=biblio.knjige.begin(); it!=biblio.knjige.end(); it++) knjige.insert(std::make_pair(it->first, it->second));
    return *this;
}
void Biblioteka::ZaduziKnjigu(int evidencijski_br, int clanski_br) {
    bool yes=false;
    for(auto it=knjige.begin(); it!=knjige.end(); it++) {
        if(evidencijski_br==it->first) {
            yes=true;
            if(!(it->second->DaLiJeZaduzena())) {
                bool nema=false;
                for(auto it2=korisnici.begin(); it2!=korisnici.end(); it2++) {
                    if(it2->first==clanski_br)  { it->second->ZaduziKnjigu(*(it2->second)); nema=true; }
                }
                if(nema==false) throw std::logic_error("Korisnik nije nadjen");
                break;
            }
        }
    }
    
    if(yes==false) throw std::logic_error("Knjiga nije nadjena");

}
void Biblioteka::RazduziKnjigu(int evidencijski_br) {
    for(auto it=knjige.begin(); it!=knjige.end(); it++) {
        if(evidencijski_br==it->first) {
            if(it->second->DaLiJeZaduzena()) { it->second->RazduziKnjigu();  }
            else throw std::logic_error("Knjiga nije zaduzena");
            break;
        }
    }
    throw std::logic_error("Knjiga nije nadjena");
}

void Biblioteka::RegistrirajNovogKorisnika(int clanski_br, std::string ime, std::string prezime, std::string adresa, std::string br_tel) {
    for(auto it=korisnici.begin(); it!=korisnici.end(); it++)   if(it->first==clanski_br) throw std::logic_error("Korisnik vec postoji");
    Korisnik novi;
    novi.ime=ime; novi.prezime=prezime; novi.adresa=adresa; novi.telefon=br_tel;
    korisnici.insert(std::make_pair(clanski_br, new Korisnik(novi)));
}
void Biblioteka::RegistrirajNovuKnjigu(int evidencijski_br, std::string naslov, std::string pisac, std::string zanr, int godina_izdavanja) {
    for(auto it=knjige.begin(); it!=knjige.end(); it++) if(it->first==evidencijski_br) throw std::logic_error("Knjiga vec postoji");
    Knjiga nova(naslov, pisac, zanr, godina_izdavanja);
    knjige.insert(std::make_pair(evidencijski_br, new Knjiga(nova)));
}

void Biblioteka::IzlistajKorisnike() {
    for(auto it=korisnici.begin(); it!=korisnici.end(); it++) {
        std::cout << "Clanski broj: " << it->first << std::endl;
        std::cout << "Ime i prezime: " << (it->second)->ime << " " << it->second->prezime << std::endl;
        std::cout << "Adresa: " << it->second->adresa << std::endl;
        std::cout << "Broj telefona: " << it->second->telefon << std::endl;
        std::cout << std::endl;
    }
}
void Biblioteka::IzlistajKnjige() {
    for(auto it=knjige.begin(); it!=knjige.end(); it++) {
    std::cout << "Evidencijski broj: " << it->first << std::endl;
    std::cout << "Naslov: " << (it->second)->DajNaslov() << std::endl;
    std::cout << "Pisac: " << (*it).second->DajAutora() << std::endl;
    std::cout << "Zanr: " << (*it).second->DajZanr() << std::endl;
    std::cout << "Godina izdavanja: " << (*it).second->DajGodinuIzdavanja() << std::endl;
    if(it->second->Knjiga::DaLiJeZaduzena()) { std::cout << "Zaduzena kod korisnika: " << (it->second)->DajKodKogaJe()->ime << " " << (*it).second->DajKodKogaJe()->prezime << std::endl; }
    std::cout << std::endl; 
    }
}

Korisnik& Biblioteka::NadjiKorisnika(int clanski_br) {
    for(auto it=korisnici.begin(); it!=korisnici.end(); it++) {
        if(clanski_br==it->first) {
               return *(it->second);
        }
    }
    throw std::logic_error("Korisnik nije nadjen");

    return *(korisnici.begin()->second);
}
Knjiga& Biblioteka::NadjiKnjigu(int evidencijski_br) {
    //auto k = *(knjige.begin()->second);
    for(auto it=knjige.begin(); it!=knjige.end(); it++) {
        if(evidencijski_br==(*it).first) {
            return *(it->second);
        }
    }
    throw std::logic_error("Knjiga nije nadjena");
    return *(knjige.begin()->second);
}

void Biblioteka::PrikaziZaduzenja(int clanski_br) {
    for(auto i=korisnici.begin(); i!=korisnici.end(); i++) {
        bool nula=false;
        if(i->first==clanski_br) {
            for(auto it=knjige.begin(); it!=knjige.end(); it++) {
                if(i->second==it->second->DajKodKogaJe()) {
                std::cout << "Evidencijski broj: " << it->first << std::endl;
                std::cout << "Naslov: " << (it->second)->DajNaslov() << std::endl;
                std::cout << "Pisac: " << (*it).second->DajAutora() << std::endl;
                std::cout << "Zanr: " << (*it).second->DajZanr() << std::endl;
                std::cout << "Godina izdavanja: " << (*it).second->DajGodinuIzdavanja() << std::endl;
                std::cout << std::endl;
                nula=true; 
                }
            }
            if(nula==false) std::cout << "Nema zaduzenja za tog korisnika!";
        }
    }
}

int main ()
{
 Biblioteka b;
b.RegistrirajNovogKorisnika(1234, "Petar", "Petrovic",
"Zmaja od Bosne 30", "032/444-555");
b.RegistrirajNovogKorisnika(4312, "Hasan", "Hasanovic",
"Trg neznalica 111", "030/111-222");
b.RegistrirajNovogKorisnika(3124, "Mehmed", "Mehmedovic",
"Studenata etfovaca 3b", "037/654-321");
b.RegistrirajNovuKnjigu(231, "Prokleta avlija", "Ivo Andric", "Roman", 1955);
b.RegistrirajNovuKnjigu(555, "Grimove Bajke", "Braca Grim", "Bajke", 1927);
b.RegistrirajNovuKnjigu(136, "Kameni spavac", "Mak Dizdar", "Poezija", 1960);
const Biblioteka b2(b);                                           
std::cout << b2.NadjiKorisnika(4312).ime << std::endl;
  	return 0;
}