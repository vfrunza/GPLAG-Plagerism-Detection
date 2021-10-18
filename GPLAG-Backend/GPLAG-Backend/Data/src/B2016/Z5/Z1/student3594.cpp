/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <map>
#include <string>
#include <stdexcept>
#include <vector>

struct Korisnik{
    std::string ime;
    std::string prezime;
    std::string adresa;
    std::string telefon;
};

class Knjiga{
  std::string naslov;
  std::string ime_pisca;
  std::string zanr;
  int godina_izdavanja;
  Korisnik *pok; 
  public:  
  Knjiga(std::string nas, std::string pisac, std::string zan, int god);
  std::string DajNaslov() const { return naslov; }
  std::string DajAutora() const { return ime_pisca; }
  std::string DajZanr() const   { return zanr; }
  int DajGodinuIzdavanja() const{ return godina_izdavanja; }
  Korisnik* DajKodKogaJe() const{ return pok; }
  void ZaduziKnjigu(Korisnik &k);
  void RazduziKnjigu();
  bool DaLiJeZaduzena();
};

class Biblioteka{
  std::map<int, Korisnik*> mapa_korisnika;
  std::map<int, Knjiga*> mapa_knjiga;
  
  public:
  ~Biblioteka();
  
  //Biblioteka(const Biblioteka &b);
  //Biblioteka(Biblioteka &&b);
  //Biblioteka &operator =(const Biblioteka &b);
  //Biblioteka &operator =(Biblioteka &&b)
  void RegistrirajNovogKorisnika(int clanski_broj, std::string ime, std::string prezime, std::string adresa, std::string broj_telefona);
  void RegistrirajNovuKnjigu(int broj_knjige, std::string naslov, std::string autor, std::string zanr, int godina_izdavanja);
  Korisnik NadjiKorisnika(int clanski_broj);
  Knjiga NadjiKnjigu(int broj_knjige) const;
  void IzlistajKorisnike();
  void IzlistajKnjige();
  void ZaduziKnjigu(int broj_knjige, int clanski_broj);
  void RazduziKnjigu(int broj_knjige);
  void PrikaziZaduzenja(int clanski_broj);
  
};


Biblioteka::~Biblioteka(){
  for(auto it = mapa_korisnika.begin(); it != mapa_korisnika.end(); it++){
    delete it -> second;
  }
  for(auto it = mapa_knjiga.begin(); it != mapa_knjiga.end(); it++){
    delete it -> second;
  }
}

Knjiga::Knjiga(std::string nas, std::string pisac, std::string zan, int god){
  Knjiga::naslov = nas;
  Knjiga::ime_pisca = pisac;
  Knjiga::zanr = zan;
  Knjiga::godina_izdavanja = god;
  Knjiga::pok = nullptr;
}

void Knjiga::ZaduziKnjigu(Korisnik &k){
  Knjiga::pok = &k;
}

void Knjiga::RazduziKnjigu(){
  this -> pok = nullptr;
}
bool Knjiga::DaLiJeZaduzena(){
  if(pok == nullptr) return false;
  return true;
}

void Biblioteka::RegistrirajNovogKorisnika(int clanski_broj, std::string ime, std::string prezime, std::string adresa, std::string broj_telefona){
  Korisnik* pok = new Korisnik;
  pok -> ime = ime;
  pok -> prezime = prezime;
  pok -> adresa = adresa;
  pok -> telefon = broj_telefona;
  mapa_korisnika.insert(std::make_pair(clanski_broj, pok));
}

void Biblioteka::RegistrirajNovuKnjigu(int broj_knjige, std::string naslov, std::string autor, std::string zanr, int godina_izdavanja){
  Knjiga* pok = new Knjiga(naslov, autor, zanr, godina_izdavanja);
  mapa_knjiga.insert(std::make_pair(broj_knjige, pok));
}

Korisnik Biblioteka::NadjiKorisnika(int clanski_broj){
  
  auto it(mapa_korisnika.find(clanski_broj));
  if(it == mapa_korisnika.end()) throw std::logic_error("Korisnik nije nadjen");
  else{
    
    Korisnik k;
    k.ime = it -> second -> ime;
    k.prezime = it -> second -> prezime;
    k.adresa = it -> second -> adresa;
    k.telefon = it -> second -> telefon;
    return k;
    
  }
  
}

Knjiga Biblioteka::NadjiKnjigu(int broj_knjige) const{
  
  auto it(mapa_knjiga.find(broj_knjige));
  if(it == mapa_knjiga.end()) throw std::logic_error("Knjiga nije nadjena");
  
    auto k = Knjiga(it -> second -> DajNaslov(), it -> second -> DajAutora(), it -> second -> DajZanr(), it -> second -> DajGodinuIzdavanja());
  
  return k;
}

void Biblioteka::IzlistajKorisnike(){
  for(auto it = mapa_korisnika.begin(); it != mapa_korisnika.end(); it++){
      std::cout << "Clanski broj: " << it -> first << std::endl << "Ime i prezime: " << it -> second -> ime << " " << it -> second -> prezime << std::endl
      << "Adresa: " << it -> second -> adresa << std::endl << "Broj telefona: " << it -> second -> telefon << std::endl << std::endl;
  }
}

void Biblioteka::IzlistajKnjige(){
  for(auto it = mapa_knjiga.begin(); it != mapa_knjiga.end(); it++){
    
    if(it -> second -> DaLiJeZaduzena() == false){
    std::cout << "Evidencijski broj: " << it -> first << std::endl << "Naslov: " << it -> second -> DajNaslov() << std::endl << "Pisac: " << it -> second -> DajAutora() << 
    std::endl << "Zanr: " << it -> second -> DajZanr() << std::endl << "Godina izdavanja: " << it -> second -> DajGodinuIzdavanja() << std::endl;
    }
    
    else if(it -> second -> DaLiJeZaduzena() == true){
    std::cout << "Evidencijski broj: " << it -> first << std::endl << "Naslov: " << it -> second -> DajNaslov() << std::endl << "Pisac: " << it -> second -> DajAutora() << 
    std::endl << "Zanr: " << it -> second -> DajZanr() << std::endl << "Godina izdavanja: " << it -> second -> DajGodinuIzdavanja() << std::endl << "Zaduzena kod korisnika: "
     << it -> second -> DajKodKogaJe() -> ime << " " << it -> second -> DajKodKogaJe() -> prezime << std::endl;
    }
  }
}


void Biblioteka::ZaduziKnjigu(int broj_knjige, int clanski_broj){
  auto it1(mapa_knjiga.find(broj_knjige));
  if(it1 == mapa_knjiga.end()) throw std::logic_error("Knjiga nije nadjena");
  
  auto it2(mapa_korisnika.find(clanski_broj));
  if(it2 == mapa_korisnika.end()) throw std::logic_error("Korisnik nije nadjen");
  
  if(it1 -> second -> DaLiJeZaduzena() == true) throw std::logic_error("Knjiga vec zaduzena");
  else{
         it1 -> second -> ZaduziKnjigu((*(it2 -> second)));
      }
}
  
void Biblioteka::RazduziKnjigu(int broj_knjige){
  auto it1(mapa_knjiga.find(broj_knjige));
  if(it1 == mapa_knjiga.end()) throw std::logic_error("Knjiga nije nadjena");
  else{
    if(it1 -> second -> DaLiJeZaduzena() == false) throw std::logic_error("Knjiga nije zaduzena");
    it1 -> second -> RazduziKnjigu();
  }
}

void Biblioteka::PrikaziZaduzenja(int clanski_broj){
  auto it2(mapa_korisnika.find(clanski_broj));
    if(it2 == mapa_korisnika.end()) throw std::logic_error("Korisnik nije nadjen");
    
    Korisnik k = *(it2 -> second);
    bool pomocna(false);
    
for(auto it = mapa_knjiga.begin(); it != mapa_knjiga.end(); it++){
  if(it->second->DaLiJeZaduzena() == true){
    pomocna = true;
    if( it -> second -> DajKodKogaJe() -> ime == k.ime &&  it -> second -> DajKodKogaJe() -> prezime == k.prezime &&  it -> second -> DajKodKogaJe() -> adresa == k.adresa &&  it -> second -> DajKodKogaJe() -> telefon == k.telefon){
       std::cout << "Evidencijski broj: " << it -> first << std::endl << "Naslov: " << it -> second -> DajNaslov() << std::endl << "Pisac: " << it -> second -> DajAutora() << 
    std::endl << "Zanr: " << it -> second -> DajZanr() << std::endl << "Godina izdavanja: " << it -> second -> DajGodinuIzdavanja() << std::endl << std::endl;
    }
  }
}
  if(!pomocna) std::cout << "Nema zaduzenja za tog korisnika!";

}


int main (){

	return 0;
}