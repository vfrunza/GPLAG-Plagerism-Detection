/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include <memory>

struct Korisnik {
    std::string ime, prezime, adresa, telefon;
};

class Knjiga {
    std::string naslov, ime_pisca, zanr;
    int godina_izdavanja;
    std::shared_ptr<Korisnik> zaduzena;
public:
    Knjiga(std::string ime_knjige, std::string pisac, std::string tip, int g) {
        naslov = ime_knjige; ime_pisca = pisac; zanr = tip; godina_izdavanja = g; zaduzena = nullptr;
    }
    std::string DajNaslov() const{ return naslov; }
    std::string DajAutora() const{ return ime_pisca; }
    std::string DajZanr() const{ return zanr; }
    int DajGodinuIzdavanja() const{ return godina_izdavanja; }
    std::shared_ptr<Korisnik> DajKodKogaJe() const{ return zaduzena; }
    
    void ZaduziKnjigu(Korisnik &k) {
        zaduzena = std::shared_ptr<Korisnik>(&k); 
    }
    void RazduziKnjigu() { zaduzena = nullptr; }
    bool DaLiJeZaduzena() const{ 
        if(zaduzena == nullptr) return false; 
        return true;
    }  
    friend class Biblioteka;
};

class Biblioteka {
    std::map<int, std::shared_ptr<Korisnik>> clanovi;
    std::map<int, std::shared_ptr<Knjiga>> knjige;
public:
    //kopirajuci konstruktor i operator dodjele
/*    ~Biblioteka() {
        for(auto it = clanovi.begin(); it != clanovi.end(); it++) delete it->second;
        for(auto it = knjige.begin(); it != knjige.end(); it++) delete it->second;
    }*/
    void RegistrirajNovogKorisnika(int clanski_br, std::string ime_korisnika, std::string prezime_korisnika, std::string adresa_korisnika, std::string br_tel) {
        if(clanovi.find(clanski_br) != clanovi.end()) throw std::logic_error("Korisnik vec postoji");
        Korisnik k;
        k.ime = ime_korisnika; k.prezime = prezime_korisnika; k.adresa = adresa_korisnika; k.telefon = br_tel;
        std::shared_ptr<Korisnik> p = std::make_shared<Korisnik>(k);
        clanovi[clanski_br] = p;
    }
    void RegistrirajNovuKnjigu(int evidenciski_br, std::string ime_knjige, std::string pisac, std::string tip, int g){
        if(knjige.find(evidenciski_br) != knjige.end()) throw std::logic_error("Knjiga vec postoji");
        Knjiga k(ime_knjige, pisac, tip, g);
        std::shared_ptr<Knjiga> p = std::make_shared<Knjiga>(k);
        knjige[evidenciski_br] = p;
    }
    Korisnik &NadjiKorisnika(int clanski_br) {
        auto it = clanovi.find(clanski_br);
        if(it != clanovi.end()) return *clanovi[clanski_br];
        else throw std::logic_error("Korisnik nije nadjen");
    }
    Knjiga &NadjiKnjigu(int evidenciski_br) {
        auto it = knjige.find(evidenciski_br);
        if(it != knjige.end()) return *knjige[evidenciski_br];
        else throw std::logic_error("Knjiga nije nadjena");
    }
    void IzlistajKorisnike() {
        auto it = clanovi.begin();
        while (it != clanovi.end()) {
            std::cout << "Clanski broj: " << it->first << std::endl;
            std::cout << "Ime i prezime: " << (it->second)->ime << " " << (it->second)->prezime << std::endl;
            std::cout << "Adresa: " << (it->second)->adresa << std::endl;
            std::cout << "Broj telefona: " << (it->second)->telefon << std::endl;
            std::cout << std::endl;
            it++;
        }
    }
    void IzlistajKnjige() {
        auto it = knjige.begin();
        while (it != knjige.end()) {
            std::cout << "Evidencijski broj: " << it->first << std::endl;
            std::cout << "Naslov: " << (it->second)->DajNaslov() << std::endl;
            std::cout << "Pisac: " << (it->second)->DajAutora() << std::endl;
            std::cout << "Zanr: " << (it->second)->DajZanr() << std::endl;
            std::cout << "Godina izdavanja: " << (it->second)->DajGodinuIzdavanja() << std::endl;
            
            if((it->second)->DaLiJeZaduzena()){
                std::cout << "Zaduzena kod korisnika: ";
                auto zaduzio((it->second)->zaduzena);
                std::cout << zaduzio->ime << " " << zaduzio->prezime;
            }
            std::cout << std::endl;
            it++;
        }
    }
    void ZaduziKnjigu(int evidenciski_br, int clanski_br) {
        if(knjige.find(evidenciski_br) == knjige.end()) throw std::logic_error("Knjiga nije nadjena");
        if(clanovi.find(clanski_br) == clanovi.end()) throw std::logic_error("Korisnik nije nadjen");
//        if(!(knjige[evidenciski_br]->zaduzena)) throw std::logic_error("Knjiga vec zaduzena");
        
        knjige[evidenciski_br]->zaduzena = clanovi[clanski_br];
    }
    void RazduziKnjigu(int evidenciski_br) {
        if(knjige.find(evidenciski_br) == knjige.end()) throw std::logic_error("Knjiga nije nadjena");
        if(knjige[evidenciski_br]->zaduzena) throw std::logic_error("Knjiga nije zaduzena");
       
        knjige[evidenciski_br]->zaduzena = nullptr;
    }
    void PikaziZaduzenja(int clanski_br) {
        for(auto it = knjige.begin(); it != knjige.end(); it++) {
            if((it->second)->DajKodKogaJe() == clanovi[clanski_br]) {
                std::cout << "Evidencijski broj: " << it->first << std::endl;
                std::cout << "Naslov: " << (it->second)->DajNaslov() << std::endl;
                std::cout << "Pisac: " << (it->second)->DajAutora() << std::endl;
                std::cout << "Zanr: " << (it->second)->DajZanr() << std::endl;
                std::cout << "Godina izdavanja: " << (it->second)->DajGodinuIzdavanja() << std::endl;
                std::cout << std::endl;
            }
        }
    }
    
};
int main ()
{
	return 0;
}