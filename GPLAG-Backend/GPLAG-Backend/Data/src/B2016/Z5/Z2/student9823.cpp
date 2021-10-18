/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <memory>
#include <stdexcept>

struct Korisnik {
  std::string ime, prezime;
  std::string adresa, telefon;
};

class Knjiga {
  std::string naslov, imePisca, zanr;
  int godinaIzdavanja;
  Korisnik *pok;
public:
  Knjiga(std::string naslov, std::string imePisca, std::string zanr, int godinaIzdavanja) : naslov(naslov), imePisca(imePisca), zanr(zanr), godinaIzdavanja(godinaIzdavanja) {
     pok = nullptr; 
  }
  std::string DajNaslov() const { return naslov; }
  std::string DajAutora() const { return imePisca; }
  std::string DajZanr() const { return zanr; }
  int DajGodinuIzdavanja() const { return godinaIzdavanja; }
  
  Korisnik* DajKodKogaJe() const { return pok; } 
  void ZaduziKnjigu(Korisnik &novi) { pok = &novi; }
  void RazduziKnjigu() { pok = nullptr; }
  bool DaLiJeZaduzena() const { if(pok != nullptr) return true; else return false; }
};

class Biblioteka {
    std::map<int, std::shared_ptr<Korisnik>> Korisnici;
    std::map<int, std::shared_ptr<Knjiga>> Knjige;
public:
    // dodati dodijelivanje / kopiranje međusobno
    Biblioteka() { }
    Biblioteka(const Biblioteka &k){
        for(auto it = k.Korisnici.begin(); it != k.Korisnici.end(); it++){
            std::shared_ptr<Korisnik> novi =  nullptr;
            novi = std::make_shared<Korisnik>();
            novi->ime = (it->second)->ime; novi->prezime = (it->second)->prezime; novi->adresa = (it->second)->adresa; novi->telefon = (it->second)->telefon;
            Korisnici.insert(std::make_pair(it->first, novi));
            novi = nullptr;
        }
        for(auto it = k.Knjige.begin(); it != k.Knjige.end(); it++){
            std::shared_ptr<Knjiga> novi = nullptr;
            novi = std::make_shared<Knjiga> (Knjiga((it->second)->DajNaslov(), (it->second)->DajAutora(), (it->second)->DajZanr(), (it->second)->DajGodinuIzdavanja()));
            Knjige.insert(std::make_pair(it->first, novi));
            novi = nullptr;
        }
    }
    Biblioteka(Biblioteka &&k){
         std::swap(Korisnici, k.Korisnici);
         std::swap(Knjige, k.Knjige);
    }
    Biblioteka &operator = (const Biblioteka &k) {
        Biblioteka nova(k);
        // kreirali novu brišemo sad
        for(auto it = Korisnici.begin(); it != Korisnici.end(); it++){
            it->second = nullptr;
        }
        for(auto it = Knjige.begin(); it != Knjige.end(); it++){
            it->second = nullptr;
        }
        
        std::swap(Korisnici, nova.Korisnici);
        std::swap(Knjige, nova.Knjige);
        return *this;
    }
    Biblioteka &operator =(Biblioteka &&k) {
        for(auto it = Korisnici.begin(); it != Korisnici.end(); it++){
            it->second = nullptr;
        }
        for(auto it = Knjige.begin(); it != Knjige.end(); it++){
            it->second = nullptr;
        }
        std::swap(Korisnici, k.Korisnici);
        std::swap(Knjige, k.Knjige);
        return *this;
    }
    
    void RegistrirajNovogKorisnika(int clanskiBroj, std::string ime, std::string prezime, std::string adresa, std::string brTel){
        auto it(Korisnici.find(clanskiBroj));
        if(it != Korisnici.end()) throw std::logic_error("Korisnik vec postoji");
        std::shared_ptr<Korisnik> novi =  nullptr;
        novi = std::make_shared<Korisnik>();
        novi->ime = ime; novi->prezime = prezime; novi->adresa = adresa; novi->telefon = brTel;
        Korisnici.insert(std::make_pair(clanskiBroj, novi));
    }
    void RegistrirajNovuKnjigu(int evidencijskiBroj, std::string naslov, std::string imepsica, std::string zanr, int godinaIZD){
        auto it(Knjige.find(evidencijskiBroj));
        if(it != Knjige.end()) throw std::logic_error("Knjiga vec postoji");
        std::shared_ptr<Knjiga> novi = nullptr;
        novi = std::make_shared<Knjiga> (Knjiga(naslov, imepsica, zanr, godinaIZD));
        Knjige.insert(std::make_pair(evidencijskiBroj, novi));
    }
    Korisnik &NadjiKorisnika(int clBroj){
        auto it(Korisnici.find(clBroj));
        if(it == Korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
        else return *(it->second);
    }
    Knjiga &NadjiKnjigu(int clBroj) const {
        auto it(Knjige.find(clBroj));
        if(it == Knjige.end()) throw std::logic_error("Knjiga nije nadjena");
        else return *(it->second);
    }
    void IzlistajKorisnike() const {
        for(auto it = Korisnici.begin(); it != Korisnici.end(); it++){
        std::cout << "Clanski broj: " << it->first  << std::endl 
        << "Ime i prezime: " << (it->second)->ime  << " " << (it->second)->prezime << std::endl 
        << "Adresa: " << (it->second)->adresa << std::endl
        << "Broj telefona: " << (it->second)->telefon << std::endl;
        }
    }
    void IzlistajKnjige() const {
        for(auto it = Knjige.begin(); it != Knjige.end(); it++){
        std::cout << "Evidencijski broj: " << it->first  << std::endl 
        << "Naslov: " << (it->second)->DajNaslov()  << std::endl 
        << "Pisac: " << (it->second)->DajAutora() << std::endl
        << "Zanr: " << (it->second)->DajZanr() << std::endl
        << "Godina izdavanja: " << (it->second)->DajGodinuIzdavanja() << std::endl;
        if((it->second)->DaLiJeZaduzena()){
            auto it3 = (it->second)->DajKodKogaJe();
            std::cout << "Zaduzena kod korisnika: " << it3->ime << " " << it3->prezime;
        }
      }
    }
    void ZaduziKnjigu(int evBroj, int clBroj) {
        try {
            NadjiKnjigu(evBroj);
        } catch (...){
            throw std::logic_error("Knjiga nije nadjena");
        }
        auto it(Knjige.find(evBroj));
        if((it->second)->DaLiJeZaduzena()) throw std::logic_error("Knjiga vec zaduzena");
        
        try {
            NadjiKorisnika(clBroj);
        } catch (...){
            throw std::logic_error("Korisnik nije nadjen");
        }
        (it->second)->ZaduziKnjigu(NadjiKorisnika(clBroj));
    }
    void RazduziKnjigu(int evBroj) {
         try {
            NadjiKnjigu(evBroj);
        } catch (...){
            throw std::logic_error("Knjiga nije nadjena");
        }
        auto it(Knjige.find(evBroj));
        if(!(it->second)->DaLiJeZaduzena()) throw std::logic_error("Knjiga nije zaduzena");
        (it->second)->RazduziKnjigu();
    }
    void PrikaziZaduzenja(int clBroj);
};

void Biblioteka::PrikaziZaduzenja(int clBroj) {
    auto it1(Korisnici.find(clBroj));
    if(it1 == Korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
    for(auto it = Knjige.begin(); it != Knjige.end(); it++){
        std::shared_ptr<Korisnik> a((it->second)->DajKodKogaJe());
        if(it1->second == a){
        std::cout << "Evidencijski broj: " << it->first  << std::endl 
        << "Naslov: " << (it->second)->DajNaslov()  << std::endl 
        << "Pisac: " << (it->second)->DajAutora() << std::endl
        << "Zanr: " << (it->second)->DajZanr() << std::endl
        << "Godina izdavanja: " << (it->second)->DajGodinuIzdavanja() << std::endl;
        }
    }
}

int main ()
{
    try {
        Biblioteka bib8;
        bib8.RegistrirajNovogKorisnika(1, "Niko", "Nikic", "Zmaja od Bosne bb", "123 456");
        bib8.RegistrirajNovuKnjigu(1, "Vlak u snijegu2", "Mato Lovrak2", "Roman2", 1941);
        bib8.RegistrirajNovuKnjigu(2, "Vlak u snijegu", "Mato Lovrak", "Roman", 1931);
        bib8.ZaduziKnjigu(2, 1);
        bib8.IzlistajKnjige();
    } catch(std::logic_error exec){
        std::cout << exec.what() << std::endl;
    }
	return 0;
}