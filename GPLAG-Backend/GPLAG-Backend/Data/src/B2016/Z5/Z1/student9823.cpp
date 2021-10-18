/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
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
  void ZaduziKnjigu(Korisnik &novi) { pok = &novi;  }
  void RazduziKnjigu() { pok = nullptr; }
  bool DaLiJeZaduzena() const { if(pok != nullptr) return true; else return false; }
};

class Biblioteka {
    std::map<int, Korisnik*> Korisnici;
    std::map<int, Knjiga*> Knjige;
public:
    Biblioteka() { }
    Biblioteka(const Biblioteka &k){
        for(auto it = k.Korisnici.begin(); it != k.Korisnici.end(); it++){
            Korisnik *novi =  nullptr;
            novi = new Korisnik();
            novi->ime = (it->second)->ime; novi->prezime = (it->second)->prezime; novi->adresa = (it->second)->adresa; novi->telefon = (it->second)->telefon;
            Korisnici.insert(std::make_pair(it->first, novi));
        }
        for(auto it = k.Knjige.begin(); it != k.Knjige.end(); it++){
            Knjiga *novi = nullptr;
            novi = new Knjiga((it->second)->DajNaslov(), (it->second)->DajAutora(), (it->second)->DajZanr(), (it->second)->DajGodinuIzdavanja());
            Knjige.insert(std::make_pair(it->first, novi));
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
            delete it->second;
            it->second = nullptr;
        }
        for(auto it = Knjige.begin(); it != Knjige.end(); it++){
            delete it->second;
            it->second = nullptr;
        }
        
        std::swap(Korisnici, nova.Korisnici);
        std::swap(Knjige, nova.Knjige);
        return *this;
    }
    Biblioteka &operator =(Biblioteka &&k) {
        for(auto it = Korisnici.begin(); it != Korisnici.end(); it++){
            delete it->second;
            it->second = nullptr;
        }
        for(auto it = Knjige.begin(); it != Knjige.end(); it++){
            delete it->second;
            it->second = nullptr;
        }
        std::swap(Korisnici, k.Korisnici);
        std::swap(Knjige, k.Knjige);
        return *this;
    }
    
    ~Biblioteka() {
        for(auto it = Korisnici.begin(); it != Korisnici.end(); it++){
            delete it->second;
            it->second = nullptr;
        }
        for(auto it = Knjige.begin(); it != Knjige.end(); it++){
            delete it->second;
            it->second = nullptr;
        }
    }
    void RegistrirajNovogKorisnika(int clanskiBroj, std::string ime, std::string prezime, std::string adresa, std::string brTel){
        auto it(Korisnici.find(clanskiBroj));
        if(it != Korisnici.end()) throw std::logic_error("Korisnik vec postoji");
        Korisnik *novi =  nullptr;
        novi = new Korisnik();
        novi->ime = ime; novi->prezime = prezime; novi->adresa = adresa; novi->telefon = brTel;
        Korisnici.insert(std::make_pair(clanskiBroj, novi));
    }
    void RegistrirajNovuKnjigu(int evidencijskiBroj, std::string naslov, std::string imepsica, std::string zanr, int godinaIZD){
        auto it(Knjige.find(evidencijskiBroj));
        if(it != Knjige.end()) throw std::logic_error("Knjiga vec postoji");
        Knjiga *novi = nullptr;
        novi = new Knjiga(naslov, imepsica, zanr, godinaIZD);
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
            std::cout << "Zaduzena kod korisnika: " << it3->ime << " " << it3->prezime << std::endl;
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
    bool ima(false);
    
    for(auto it = Knjige.begin(); it != Knjige.end(); it++){
        if(it1->second == (it->second)->DajKodKogaJe()){
            ima = true;
        std::cout << "Evidencijski broj: " << it->first  << std::endl 
        << "Naslov: " << (it->second)->DajNaslov()  << std::endl 
        << "Pisac: " << (it->second)->DajAutora() << std::endl
        << "Zanr: " << (it->second)->DajZanr() << std::endl
        << "Godina izdavanja: " << (it->second)->DajGodinuIzdavanja() << std::endl;
        }
    }
    if(!ima) std::cout << "Nema zaduzenja za tog korisnika!";
}

int main ()
{
    Biblioteka b;
    b.RegistrirajNovogKorisnika(1234, "Petar", "Petrovic","Zmaja od Bosne 30", "032/444-555");
    b.RegistrirajNovogKorisnika(4312, "Hasan", "Hasanovic","Trg neznalica 111", "030/111-222");
    b.RegistrirajNovogKorisnika(3124, "Mehmed", "Mehmedovic","Studenata etfovaca 3b", "037/654-321");
    b.RegistrirajNovuKnjigu(231, "Prokleta avlija", "Ivo Andric", "Roman", 1955);
    b.RegistrirajNovuKnjigu(555, "Grimove Bajke", "Braca Grim", "Bajke", 1927);
    b.RegistrirajNovuKnjigu(136, "Kameni spavac", "Mak Dizdar", "Poezija", 1960);
    b.ZaduziKnjigu(231, 1234);
    b.ZaduziKnjigu(136, 1234);
    b.IzlistajKnjige();
	return 0;
}