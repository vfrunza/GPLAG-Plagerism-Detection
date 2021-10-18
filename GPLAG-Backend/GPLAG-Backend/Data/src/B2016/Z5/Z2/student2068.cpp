#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <utility>
#include <stdexcept>
#include <memory>

struct Korisnik {
  std::string ime, prezime, adresa, telefon;  
};

std::shared_ptr<Korisnik> StvoriKorisnika(const std::string &ime, const std::string &prezime, const std::string &adresa, const std::string &telefon) {
  std::shared_ptr<Korisnik> p=std::make_shared<Korisnik>();
  p->ime=ime; p->prezime=prezime; p->adresa=adresa; p->telefon=telefon;
  return p;
}

class Knjiga {
  std::string naslov, ime_pisca, zanr;
  int godina_izdavanja;
  std::shared_ptr<Korisnik> zaduzio;
public:
  Knjiga (std::string naslov, std::string ime_pisca, std::string zanr, int godina_izdavanja) : naslov(naslov), ime_pisca(ime_pisca), zanr(zanr), godina_izdavanja(godina_izdavanja), zaduzio(nullptr) {}
  std::string DajNaslov() const { return naslov; }
  std::string DajAutora() const { return ime_pisca; }
  std::string DajZanr() const { return zanr; }
  int DajGodinuIzdavanja() const { return godina_izdavanja; }
  std::shared_ptr<Korisnik> DajKodKogaJe() const { return zaduzio; }
  void ZaduziKnjigu(Korisnik& k) { zaduzio=std::make_shared<Korisnik>(k); }
  void RazduziKnjigu() { zaduzio=nullptr; }
  bool DaLiJeZaduzena() const { return (bool)zaduzio; }
};

class Biblioteka {
  std::map<int, std::shared_ptr<Knjiga>>Knjige;
  std::map<int, std::shared_ptr<Korisnik>>Korisnici;
public:
  Biblioteka() {}
  Biblioteka(const Biblioteka& druga);
  Biblioteka(Biblioteka &&druga);
  Biblioteka& operator =(const Biblioteka &druga);
  Biblioteka operator =(Biblioteka &&druga);
  
  void RegistrirajNovogKorisnika(int clanski_broj, const std::string &ime, const std::string &prezime, const std::string &adresa, const std::string &telefon);
  void RegistrirajNovuKnjigu(int broj, const std::string &naslov, const std::string ime_pisca, const std::string &zanr, int godina_izdavanja);

  Korisnik &NadjiKorisnika(int clanski_broj);
  Knjiga &NadjiKnjigu(int broj);
  
  void IzlistajKorisnike() const;
  void IzlistajKnjige() const;
  
  void ZaduziKnjigu(int broj, int clanski_broj);
  void RazduziKnjigu(int broj);
  
  void PrikaziZaduzenja(int clanski_broj);
};

Biblioteka::Biblioteka(const Biblioteka& druga) {
  for(auto x : druga.Knjige) {
    Knjige.insert({x.first, std::make_shared<Knjiga>(*x.second)});
  }
  for(auto x : druga.Korisnici) {
    Korisnici.insert({x.first, std::make_shared<Korisnik>(*x.second)});
  }
}
Biblioteka::Biblioteka(Biblioteka &&druga) {
  std::swap(Knjige, druga.Knjige);
  std::swap(Korisnici, druga.Korisnici);
}
Biblioteka& Biblioteka::operator =(const Biblioteka &druga) {
    Knjige.clear(); Korisnici.clear();
    for(auto x : druga.Knjige) {
        Knjige.insert({x.first, std::make_shared<Knjiga>(*x.second)});
    }
    for(auto x : druga.Korisnici) {
        Korisnici.insert({x.first, std::make_shared<Korisnik>(*x.second)});
    }
    return *this;
}
Biblioteka Biblioteka::operator =(Biblioteka &&druga) {
  std::swap(Knjige, druga.Knjige);
  std::swap(Korisnici, druga.Korisnici);
  return *this;
}

void Biblioteka::RegistrirajNovogKorisnika(int clanski_broj, const std::string &ime, const std::string &prezime, const std::string &adresa, const std::string &telefon) {
  if(Korisnici.find(clanski_broj)!=Korisnici.end()) throw std::logic_error("Korisnik vec postoji");
  Korisnici.insert({clanski_broj, StvoriKorisnika(ime, prezime, adresa, telefon)});
}
void Biblioteka::RegistrirajNovuKnjigu(int broj, const std::string &naslov, const std::string ime_pisca, const std::string &zanr, int godina_izdavanja) {
  if(Knjige.find(broj)!=Knjige.end()) throw std::logic_error("Knjiga vec postoji");
  Knjige.insert({broj, std::make_shared<Knjiga>(naslov, ime_pisca, zanr, godina_izdavanja)});
}

Korisnik& Biblioteka::NadjiKorisnika(int clanski_broj) {
  auto i=Korisnici.find(clanski_broj); if(i!=Korisnici.end()) return *i->second;
  throw std::logic_error("Korisnik nije nadjen");
}
Knjiga& Biblioteka::NadjiKnjigu(int broj) {
  auto i=Knjige.find(broj); if(i!=Knjige.end()) return *i->second;
  throw std::logic_error("Knjiga nije nadjena");
}

void Biblioteka::IzlistajKorisnike() const {
  for(auto x : Korisnici) {
    std::cout << "Clanski broj: " << x.first << "\n";
    std::cout << "Ime i prezime: " << x.second->ime << " " << x.second->prezime << "\n";
    std::cout << "Adresa: " << x.second->adresa << "\n";
    std::cout << "Broj telefona: " << x.second->telefon << "\n\n";
  }
}
void Biblioteka::IzlistajKnjige() const {
  for(auto x : Knjige) {
    std::cout << "Evidencijski broj: " << x.first << "\n";
    std::cout << "Naslov: " << x.second->DajNaslov() << "\n";
    std::cout << "Pisac: " << x.second->DajAutora() << "\n";
    std::cout << "Zanr: " << x.second->DajZanr() << "\n";
    std::cout << "Godina izdavanja: " << x.second->DajGodinuIzdavanja() << "\n";
    if(x.second->DaLiJeZaduzena()) std::cout << "Zaduzena kod korisnika: " << x.second->DajKodKogaJe()->ime << " " << x.second->DajKodKogaJe()->prezime << "\n\n";
  }
}

void Biblioteka::ZaduziKnjigu(int broj, int clanski_broj) {
  for(auto x : Knjige) {
    if(x.first==broj) {
      if(x.second->DaLiJeZaduzena()) throw std::logic_error("Knjiga vec zaduzena");
      for(auto y : Korisnici) {
        if(y.first==clanski_broj) {
          x.second->ZaduziKnjigu(*y.second);
          return;
        }
      }
      throw std::logic_error("Korisnik nije nadjen");
    }
  }
  throw std::logic_error("Knjiga nije nadjena");
}
void Biblioteka::RazduziKnjigu(int broj) {
  for(auto x : Knjige) {
    if(x.first==broj) {
      if(x.second->DaLiJeZaduzena()) {
        x.second->RazduziKnjigu();
        return;
      }
      throw std::logic_error("Knjiga nije zaduzena");
    }
  }
  throw std::logic_error("Knjiga nije nadjena");
}

void Biblioteka::PrikaziZaduzenja(int clanski_broj) {
  auto K=NadjiKorisnika(clanski_broj);
  bool bar_jedan=false;
  for(auto x : Knjige) {
    auto p=x.second->DajKodKogaJe(); Korisnik novi;
    if(p) novi=*p;
    if(p && (novi.ime==K.ime && novi.prezime==K.prezime && novi.adresa==K.adresa && novi.telefon==K.telefon)) {
      bar_jedan=true;
      std::cout << "Evidencijski broj: " << x.first << "\n";
      std::cout << "Naslov: " << x.second->DajNaslov() << "\n";
      std::cout << "Pisac: " << x.second->DajAutora() << "\n";
      std::cout << "Zanr: " << x.second->DajZanr() << "\n";
      std::cout << "Godina izdavanja: " << x.second->DajGodinuIzdavanja() << "\n\n";
    }
  }
  if(!bar_jedan) std::cout << "Nema zaduzenja za tog korisnika!\n";
}

int main () {
	
}