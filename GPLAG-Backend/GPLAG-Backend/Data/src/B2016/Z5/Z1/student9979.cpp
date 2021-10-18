/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: student9979@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise

#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include <type_traits>

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
  std::map<int, Korisnik*> korisnici;
  std::map<int, Knjiga*> knjige;
public:
  Biblioteka() = default;
  ~Biblioteka();
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

Biblioteka::~Biblioteka() {
  for(auto par : korisnici) delete par.second;
  for(auto par : knjige) delete par.second;
}

Biblioteka::Biblioteka(const Biblioteka &b) {
  try {
    for(auto par : b.korisnici) korisnici[par.first] = new Korisnik(*par.second);
    for(auto par : b.knjige) knjige[par.first] = new Knjiga(*par.second);
  }
  catch(...) {
    for(auto par : korisnici) delete par.second;
    for(auto par : knjige) delete par.second;
  }
}

Biblioteka &Biblioteka::operator =(Biblioteka b) {
  std::swap(korisnici, b.korisnici); std::swap(knjige, b.knjige);
  return *this;
}

void Biblioteka::RegistrirajNovogKorisnika(int clanski_broj, std::string ime,
  std::string prezime, std::string adresa, std::string telefon) {
    if(korisnici.count(clanski_broj) != 0)
      throw std::logic_error("Korisnik vec postoji");
    korisnici[clanski_broj] = new Korisnik{ime, prezime, adresa, telefon};
}

void Biblioteka::RegistrirajNovuKnjigu(int evidencijski_broj, std::string naslov,
  std::string pisac, std::string zanr, int godina) {
    if(knjige.count(evidencijski_broj) != 0)
      throw std::logic_error("Knjiga vec postoji");
    knjige[evidencijski_broj] = new Knjiga(naslov, pisac, zanr,godina);
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
    if(it2->second->DajKodKogaJe() == it1->second) {
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



int main ()
{
	return 0;
}