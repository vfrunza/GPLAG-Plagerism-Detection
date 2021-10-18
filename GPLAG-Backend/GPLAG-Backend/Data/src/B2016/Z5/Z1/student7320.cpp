/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <map> 
#include <stdexcept> 

struct Korisnik {
  std::string ime, prezime, adresa, telefon;
};
class Knjiga {
  std::string naslov, pisac, zanr;
  int godina;
  Korisnik *zaduzenje = nullptr;
  
public:
  Knjiga(std::string _n, std::string _p, std::string _z, int _g) {
    naslov = _n; pisac = _p; zanr = _z; godina = _g;
    zaduzenje = nullptr;
  }
  std::string DajNaslov() { return naslov; }
  std::string DajAutora() { return pisac; }
  std::string DajZanr() { return zanr; }
  int DajGodinuIzdavanja() { return godina; }
  Korisnik *DajKodKogaJe() { return zaduzenje; }
  void ZaduziKnjigu(Korisnik &korisnik) {
    zaduzenje = &korisnik;
  }
  void RazduziKnjigu() { zaduzenje = nullptr; }
  bool DaLiJeZaduzena() { return (zaduzenje != nullptr); }
};
class Biblioteka {
  std::map<int, Korisnik*> korisnici;
  std::map<int, Knjiga*> knjige;
public:
  ~Biblioteka() {
    for (auto x = korisnici.begin(); x != korisnici.end(); x++)
      delete x->second;
    for (auto x = knjige.begin(); x != knjige.end(); x++)
      delete x->second;
  }
  void RegistrirajNovogKorisnika(int clbr, std::string ime_, std::string prezime_, std::string adresa_, std::string br_tel) {
    Korisnik *obj = new Korisnik();
    obj -> ime = ime_; obj -> prezime = prezime_;
    obj -> adresa = adresa_; obj -> telefon = br_tel;
    for (auto x = korisnici.begin(); x != korisnici.end(); x++)
      if (x -> first == clbr) throw std::logic_error("Korisnik vec postoji");
    korisnici.insert(std::make_pair(clbr, obj));
    //delete obj; obj = nullptr;
  }
  void RegistrirajNovuKnjigu(int evbr, std::string naslov_, std::string imep_, std::string zanr_, int god_) {
    Knjiga *obj = new Knjiga(naslov_, imep_, zanr_, god_);
    for (auto x = knjige.begin(); x != knjige.end(); x++)
      if (x -> first == evbr) throw std::logic_error("Knjiga vec postoji");
    knjige.insert(std::make_pair(evbr, obj));
    //knjige[evbr] = Knjiga(obj -> DajNaslov(), obj -> DajAutora(), obj -> DajZanr(), obj -> DajGodinuIzdavanja());
    //delete obj;
  }
  Korisnik &NadjiKorisnika(int clbr) {
    for (auto x = korisnici.begin(); x != korisnici.end(); x++)
      if (x -> first == clbr) return *(x->second);
    throw std::logic_error("Korisnik nije nadjen");
  }
  Knjiga &NadjiKnjigu(int evbr) {
    for (auto x = knjige.begin(); x != knjige.end(); x++)
      if (x -> first == evbr) return *(x->second);
    throw std::logic_error("Knjiga nije nadjena");
  }
  void IzlistajKorisnike() {
    for (auto x = korisnici.begin(); x != korisnici.end(); x++) {
      Korisnik kor = *(x -> second);
      std::cout << "Clanski broj: " << x->first << "\n";
      std::cout << "Ime i prezime: " << kor.ime << " " << kor.prezime << "\n";
      std::cout << "Adresa: " << kor.adresa << "\n";
      std::cout << "Broj telefona: " << kor.telefon << "\n";
      std::cout << "\n";
    }
  }
  void IzlistajKnjige() {
    for (auto x = knjige.begin(); x != knjige.end(); x++) {
      Knjiga knj = *(x -> second);
      std::cout << "Evidencijski broj: " << x->first << "\n";
      std::cout << "Naslov: " << knj.DajNaslov() << "\n";
      std::cout << "Pisac: " << knj.DajAutora() << "\n";
      std::cout << "Zanr: " << knj.DajZanr() << "\n";
      std::cout << "Godina izdavanja: " << knj.DajGodinuIzdavanja() << "\n";
      if (knj.DaLiJeZaduzena()) {
        Korisnik *zaduzenik = knj.DajKodKogaJe();
        std::cout << "Zaduzena kod korisnika: " << zaduzenik -> ime << " " << zaduzenik -> prezime << "\n"; 
      }
      std::cout << "\n";
    }
  }
  void ZaduziKnjigu (int evbr, int clbr) {
    bool postoji = 0;
    for (auto x = knjige.begin(); x != knjige.end(); x++)
      if (x -> first == evbr) postoji = 1;
    if (!postoji) throw std::logic_error("Knjiga nije nadjena");
    postoji = 0;
    for (auto x = korisnici.begin(); x != korisnici.end(); x++)
      if (x -> first == clbr) postoji = 1;
    if (!postoji) throw std::logic_error("Korisnik nije nadjen");
    if (knjige[evbr] -> DaLiJeZaduzena()) throw std::logic_error("Knjiga vec zaduzena");
    knjige[evbr] -> ZaduziKnjigu(*korisnici[clbr]);
  }
  void RazduziKnjigu(int evbr) {
    bool postoji = 0;
    for (auto x = knjige.begin(); x != knjige.end(); x++)
      if (x -> first == evbr) postoji = 1;
    if (!postoji) throw std::logic_error("Knjiga nije nadjena");
    if (knjige[evbr] -> DaLiJeZaduzena() == false) throw std::domain_error("Knjiga nije zaduzena");
    knjige[evbr] -> RazduziKnjigu();
  }
  void PrikaziZaduzenja(int clbr) {
    bool zaduzio = 0;
    bool postoji = 0;
    for (auto x = korisnici.begin(); x != korisnici.end(); x++)
      if (x -> first == clbr) postoji = 1;
    if (!postoji) throw std::logic_error("Korisnik nije nadjen");
    for(auto x = knjige.begin(); x != knjige.end(); x++) {
      if (x -> second -> DajKodKogaJe() == korisnici[clbr]) {
        zaduzio = 1;
        Knjiga knj = *(x -> second);
        std::cout << "Evidencijski broj: " << x->first << "\n";
        std::cout << "Naslov: " << knj.DajNaslov() << "\n";
        std::cout << "Pisac: " << knj.DajAutora() << "\n";
        std::cout << "Zanr: " << knj.DajZanr() << "\n";
        std::cout << "Godina izdavanja: " << knj.DajGodinuIzdavanja() << "\n\n";
      } 
    }
    if (!zaduzio) std::cout << "Nema zaduzenja za tog korisnika!\n";
  }
};


int main () {
Biblioteka bib5;
bib5.RegistrirajNovogKorisnika(1, "Niko", "Nikic", "Zmaja od Bosne bb", "123 456");
bib5.RegistrirajNovuKnjigu(2, "Vlak u snijegu", "Mato Lovrak", "Roman", 1931);
std::cout << bib5.NadjiKnjigu(2).DajNaslov();
	return 0;
}