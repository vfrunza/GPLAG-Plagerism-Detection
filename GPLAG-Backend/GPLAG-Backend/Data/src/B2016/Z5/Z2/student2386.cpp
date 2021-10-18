#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include <memory>

struct Korisnik {
  std::string ime, prezime, adresa, telefon;
};

class Knjiga {
  std::string naslov, pisac, zanr;
  int godina;
  Korisnik *zaduzenje;
public:
  Knjiga(std::string naslov, std::string pisac, std::string zanr, int godina) :
    naslov(naslov), pisac(pisac), zanr(zanr), godina(godina), zaduzenje(nullptr) {}
  std::string DajNaslov() const { return naslov; }
  std::string DajAutora() const { return pisac; }
  std::string DajZanr() const { return zanr; }
  int DajGodinuIzdavanja() const { return godina; }
  Korisnik *DajKodKogaJe() const { return zaduzenje; }
  void ZaduziKnjigu(Korisnik &ko) { zaduzenje = &ko; }
  void RazduziKnjigu() { zaduzenje = nullptr; }
  bool DaLiJeZaduzena() const { return zaduzenje != nullptr; }
};

class Biblioteka {
  std::map<int, std::shared_ptr<Korisnik>> korisnici;
  std::map<int, std::shared_ptr<Knjiga>> knjige;
public:
  Biblioteka() = default;
  Biblioteka(const Biblioteka &b);
  Biblioteka(Biblioteka &&b) = default;
  Biblioteka &operator =(Biblioteka b);
  void RegistrirajNovogKorisnika(int clanski_broj, std::string ime,
    std::string prezime, std::string adresa, std::string telefon);
  void RegistrirajNovuKnjigu(int evidencijski_broj, std::string naslov,
    std::string pisac, std::string zanr, int godina);
  Korisnik &NadjiKorisnika(int clanski_broj);
  const Korisnik &NadjiKorisnika(int clanski_broj) const;
  Knjiga &NadjiKnjigu(int evidencijski_broj);
  const Knjiga &NadjiKnjigu(int evidencijski_broj) const;
  void IzlistajKorisnike() const;
  void IzlistajKnjige() const;
  void ZaduziKnjigu(int evidencijski_broj, int clanski_broj);
  void RazduziKnjigu(int evidencijski_broj);
  void PrikaziZaduzenja(int clanski_broj) const;
};

Biblioteka::Biblioteka(const Biblioteka &b) {
  for(auto par : b.korisnici) korisnici[par.first] = std::make_shared<Korisnik>(*par.second);
  for(auto par : b.knjige) knjige[par.first] = std::make_shared<Knjiga>(*par.second);
}

Biblioteka &Biblioteka::operator =(Biblioteka b) {
  std::swap(korisnici, b.korisnici); std::swap(knjige, b.knjige);
  return *this;
}

void Biblioteka::RegistrirajNovogKorisnika(int clanski_broj, std::string ime,
  std::string prezime, std::string adresa, std::string telefon) {
    if(korisnici.count(clanski_broj) != 0)
      throw std::logic_error("Korisnik vec postoji");
    Korisnik k{ime, prezime, adresa, telefon};
    korisnici[clanski_broj] = std::make_shared<Korisnik>(k);
}

void Biblioteka::RegistrirajNovuKnjigu(int evidencijski_broj, std::string naslov,
  std::string pisac, std::string zanr, int godina) {
    if(knjige.count(evidencijski_broj) != 0)
      throw std::logic_error("Knjiga vec postoji");
    knjige[evidencijski_broj] = std::make_shared<Knjiga>(naslov, pisac, zanr,godina);
  }

Korisnik &Biblioteka::NadjiKorisnika(int clanski_broj) {
  auto it(korisnici.find(clanski_broj));
  if(it == korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
  return *(it->second);
}

const Korisnik &Biblioteka::NadjiKorisnika(int clanski_broj) const {
  auto it(korisnici.find(clanski_broj));
  if(it == korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
  return *(it->second);
}

Knjiga &Biblioteka::NadjiKnjigu(int evidencijski_broj) {
  auto it(knjige.find(evidencijski_broj));
  if(it == knjige.end()) throw std::logic_error("Knjiga nije nadjena");
  return *(it->second);
}

const Knjiga &Biblioteka::NadjiKnjigu(int evidencijski_broj) const {
  auto it(knjige.find(evidencijski_broj));
  if(it == knjige.end()) throw std::logic_error("Knjiga nije nadjena");
  return *(it->second);
}

void Biblioteka::IzlistajKorisnike() const {
  auto it(korisnici.begin());
  while(it != korisnici.end()) {
    std::cout << "Clanski broj: " << it->first << std::endl
      << "Ime i prezime: " << it->second->ime << " " << it->second->prezime << std::endl
      << "Adresa: " << it->second->adresa << std::endl
      << "Broj telefona: " << it->second->telefon << std::endl;
    it++;
    if(it != korisnici.end()) std::cout << std::endl;
  }
}

void Biblioteka::IzlistajKnjige() const {
  auto it(knjige.begin());
  while(it != knjige.end()) {
    std::cout << "Evidencijski broj: " << it->first << std::endl
      << "Naslov: " << it->second->DajNaslov() << std::endl
      << "Pisac: " << it->second->DajAutora() << std::endl
      << "Zanr: " << it->second->DajZanr() << std::endl
      << "Godina izdavanja: " << it->second->DajGodinuIzdavanja() << std::endl;
    if(it->second->DajKodKogaJe())
      std::cout << "Zaduzena kod korisnika: " << it->second->DajKodKogaJe()->ime
        << " " << it->second->DajKodKogaJe()->prezime << std::endl;
    it++;
    if(it != knjige.end()) std::cout << std::endl;
  }
}

void Biblioteka::ZaduziKnjigu(int evidencijski_broj, int clanski_broj) {
  auto it_knjige(knjige.find(evidencijski_broj));
  if(it_knjige == knjige.end()) throw std::logic_error("Knjiga nije nadjena");
  auto it_korisnik(korisnici.find(clanski_broj));
  if(it_korisnik == korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
  if(it_knjige->second->DaLiJeZaduzena()) throw std::logic_error("Knjiga vec zaduzena");
  it_knjige->second->ZaduziKnjigu(*it_korisnik->second);
}

void Biblioteka::RazduziKnjigu(int evidencijski_broj) {
  auto it_knjige(knjige.find(evidencijski_broj));
  if(it_knjige == knjige.end()) throw std::logic_error("Knjiga nije nadjena");
  if(!it_knjige->second->DaLiJeZaduzena()) throw std::logic_error("Knjiga nije zaduzena");
  it_knjige->second->RazduziKnjigu();
}

void Biblioteka::PrikaziZaduzenja(int clanski_broj) const {
  auto it1(korisnici.find(clanski_broj));
  if(it1 == korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
  auto it2(knjige.begin());
  bool ima_zaduzenja(false);
  while(it2 != knjige.end()) {
    if(it2->second->DajKodKogaJe() == (it1->second).get()) {
      if(ima_zaduzenja) std::cout << std::endl;
      std::cout << "Evidencijski broj: " << it2->first << std::endl
        << "Naslov: " << it2->second->DajNaslov() << std::endl
        << "Pisac: " << it2->second->DajAutora() << std::endl
        << "Zanr: " << it2->second->DajZanr() << std::endl
        << "Godina izdavanja: " << it2->second->DajGodinuIzdavanja() << std::endl;
      ima_zaduzenja = true;
    }
    it2++;
  }
  if(!ima_zaduzenja) std::cout << "Nema zaduzenja za tog korisnika!" << std::endl;
}

// Makro za testiranje izuzetakta (vidi Zadatak 1, Tutorijal 10)
#define TestirajIzuzetak(izuzetak, tijelo) \
  try tijelo catch(izuzetak e) { std::cout << e.what() << std::endl; }

int main() {
  Korisnik kor{"Meho", "Mehic", "Dobojska 15", "033/123-456"};
  std::cout << kor.ime << " " << kor.prezime << " " << kor.adresa << " "
    << kor.telefon << std::endl;
  Knjiga knj("Tvrdjava", "Mesa Selimovic", "Roman", 1965);
  std::cout << knj.DajNaslov() << " " << knj.DajAutora() << " "
    << knj.DajZanr() << " " << knj.DajGodinuIzdavanja() << std::endl;
  if(knj.DajKodKogaJe() == nullptr) std::cout << "Nije zaduzena\n";
  std::cout << knj.DaLiJeZaduzena() << std::endl;
  knj.ZaduziKnjigu(kor);
  std::cout << "Knjigu je zaduzio " << knj.DajKodKogaJe()->ime << std::endl;
  std::cout << knj.DaLiJeZaduzena() << std::endl;
  const Knjiga knj2(knj);                                                       // Test inspektora...
  std::cout << knj2.DajNaslov() << " " << knj2.DajAutora() << " "
    << knj2.DajZanr() << " " << knj2.DajGodinuIzdavanja() << std::endl;
  std::cout << "Knjigu je zaduzio " << knj2.DajKodKogaJe()->ime << std::endl;
  std::cout << knj2.DaLiJeZaduzena() << std::endl;
  knj.RazduziKnjigu();
  if(knj.DajKodKogaJe() == nullptr) std::cout << "Nije zaduzena\n";
  std::cout << knj.DaLiJeZaduzena() << std::endl;
  Biblioteka b;
  b.RegistrirajNovogKorisnika(1234, "Petar", "Petrovic",
    "Zmaja od Bosne 30", "032/444-555");
  b.RegistrirajNovogKorisnika(4312, "Hasan", "Hasanovic",
    "Trg neznalica 111", "030/111-222");
  b.RegistrirajNovogKorisnika(3124, "Mehmed", "Mehmedovic",
    "Studenata ponovaca 3b", "037/654-321");
  b.RegistrirajNovuKnjigu(231, "Prokleta avlija", "Ivo Andric", "Roman", 1955);
  b.RegistrirajNovuKnjigu(555, "Grimove Bajke", "Braca Grim", "Bajke", 1927);
  b.RegistrirajNovuKnjigu(136, "Kameni spavac", "Mak Dizdar", "Poezija", 1960);
  b.IzlistajKorisnike();
  b.IzlistajKnjige();
  TestirajIzuzetak(std::logic_error, {
    b.RegistrirajNovogKorisnika(1234, "Neko", "Drugi", "Bilo gdje", "");
  });
  TestirajIzuzetak(std::logic_error, {
    b.RegistrirajNovuKnjigu(555, "Neka", "Druga", "Bilo sta", 0);
  });
  std::cout << b.NadjiKorisnika(4312).ime << std::endl;
  TestirajIzuzetak(std::logic_error, { b.NadjiKorisnika(1111).ime; })
  std::cout << b.NadjiKnjigu(231).DajNaslov() << std::endl;
  TestirajIzuzetak(std::logic_error, { b.NadjiKnjigu(999).DajNaslov(); })
  b.PrikaziZaduzenja(1234);
  TestirajIzuzetak(std::logic_error, { b.PrikaziZaduzenja(5555); })
  b.ZaduziKnjigu(231, 1234);
  TestirajIzuzetak(std::logic_error, { b.ZaduziKnjigu(777, 1234); })
  TestirajIzuzetak(std::logic_error, { b.ZaduziKnjigu(231, 7777); })
  TestirajIzuzetak(std::logic_error, { b.ZaduziKnjigu(231, 1234); })
  b.ZaduziKnjigu(136, 1234);
  b.IzlistajKnjige();
  b.PrikaziZaduzenja(1234);
  b.RazduziKnjigu(136);
  b.PrikaziZaduzenja(1234);
  TestirajIzuzetak(std::logic_error, { b.RazduziKnjigu(136); })
  TestirajIzuzetak(std::logic_error, { b.RazduziKnjigu(666); })
  const Biblioteka b2(b);                                           // Test inspektora...
  b2.IzlistajKorisnike();
  b2.IzlistajKnjige();
  b2.PrikaziZaduzenja(4312);
  std::cout << b2.NadjiKorisnika(4312).ime << std::endl;
  std::cout << b2.NadjiKnjigu(231).DajNaslov() << std::endl;
}