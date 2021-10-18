#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>
#include <map>

struct Korisnik {
  std::string ime, prezime, adresa, telefon;
    
};

class Knjiga {
  std::string naslov, ime_pisca, zanr;
  int godina_izdavanja;
  Korisnik *pok = (nullptr);
  public:
  Knjiga(std::string naslov, std::string ime_pisca, std::string zanr, int godina_izdavanja): naslov(naslov), ime_pisca(ime_pisca),zanr(zanr),godina_izdavanja(godina_izdavanja) {}
    std::string DajNaslov() const { return naslov; };
    std::string DajAutora() const {return ime_pisca; };
    std::string DajZanr() const {return zanr;};
    int DajGodinuIzdavanja() const {return godina_izdavanja;};
    Korisnik *DajKodKogaJe() const {return pok;};
    void ZaduziKnjigu( Korisnik &k) { pok = &k; }
    void RazduziKnjigu() { pok = nullptr; }
    bool DaLiJeZaduzena() { if(pok != nullptr) return true; else return false; }
};

class Biblioteka {
    std::map<int, Korisnik*> korisnici;
    std::map<int, Knjiga*> knjige;
    public:
    void RegistrirajNovogKorisnika(int clanski_broj,std::string ime,std::string prezime,std::string adresa, std::string broj_telefona);
    void RegistrirajNovuKnjigu(int br_knjige,std::string naslov,std::string  ime,std::string zanr, int god_izdavanja);  
    Korisnik &NadjiKorisnika(int br_korisnika);
    Knjiga &NadjiKnjigu(int br_knjige);
    void IzlistajKorisnike() const;
    void IzlistajKnjige() const;
    void ZaduziKnjigu(int br_knjige, int br_korisnika);
    void RazduziKnjigu(int br_knjige);
    void PrikaziZaduzenja(int br_korisnika) const;
    
};

  void Biblioteka::RegistrirajNovogKorisnika(int clanski_broj,std::string ime,std::string prezime,std::string adresa, std::string broj_telefona) {
        if(korisnici.count(clanski_broj)) throw std::logic_error("Korisnik vec postoji");
        else {
          Korisnik p;
          p.ime = ime; p.prezime = prezime; p.adresa = adresa; p.telefon = broj_telefona;
          auto p1 = (new Korisnik(p));
          korisnici.insert(std::make_pair(clanski_broj, p1));
          //delete p1;
        }
    }
    
  void Biblioteka::RegistrirajNovuKnjigu(int br_knjige,std::string naslov,std::string ime_pisca, std::string zanr, int god_izdavanja) {
    if(knjige.count(br_knjige)) throw std::logic_error("Knjiga vec postoji");
    else {
         // auto p =  new Knjiga(naslov, ime_pisca, zanr, god_izdavanja);
      knjige.insert(std::make_pair(br_knjige, new Knjiga(naslov, ime_pisca, zanr, god_izdavanja)));
    //  delete p;
    }
  }    
  
  Korisnik &Biblioteka::NadjiKorisnika(int br_korisnika) {
    auto p = korisnici.find(br_korisnika);
//    std::cout <<"IME: "<< p->second->ime;
    if(korisnici.find(br_korisnika) == korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
    else {
       return *p->second;
    }
  }
  
  Knjiga &Biblioteka::NadjiKnjigu(int br_knjige) {
    auto p = (knjige.find(br_knjige));
    if(knjige.find(br_knjige) == knjige.end()) throw std::logic_error("Korisnik nije nadjen");
    else {
       return *p->second;
    }
  }
 
  void Biblioteka::IzlistajKorisnike() const {
    for(auto it = korisnici.begin(); it != korisnici.end(); it++) {
      std::cout << "Clanski broj: " << it->first << std::endl;
      std::cout <<"Ime i prezime: " << (it->second)->ime <<" "<< (it->second)->prezime <<std::endl;
      std::cout <<"Adresa: " << (it->second)->adresa <<std::endl;
      std::cout <<"Broj telefona: " << (it->second)->telefon <<std::endl;
      std::cout << std::endl;
    }
  }
  
  void Biblioteka::IzlistajKnjige() const {
    for(auto it = knjige.begin(); it != knjige.end(); it++) {
      std::cout << "Evidencijski broj: " << it->first << std::endl;
      std::cout <<"Naslov: " << (it->second)->DajNaslov() <<std::endl;
      std::cout <<"Pisac: " << (it->second)->DajAutora() <<std::endl;
      std::cout <<"Zanr: " << (it->second)->DajZanr() <<std::endl;
      std::cout <<"Godina izdavanja: " << (it->second)->DajGodinuIzdavanja() <<std::endl;
      if((it->second->DaLiJeZaduzena())) std::cout <<"Zaduzena kod korisnika: "<< ((it->second)->DajKodKogaJe())->ime<<" "<< it->second->DajKodKogaJe()->prezime;
      std::cout << std::endl;
    }
  }
  
  void Biblioteka::ZaduziKnjigu(int br_knjige, int br_korisnika) {
    if ((knjige.count(br_knjige))==0) throw std::logic_error("Knjiga nije nadjena");
    else
    if ((korisnici.count(br_korisnika))==0) throw std::logic_error("Korisnik nije nadjen");
    else
    if (((knjige.find(br_knjige))->second->DaLiJeZaduzena()) !=0) throw std::logic_error("Knjiga vec zaduzena");
    else
   (knjige.find(br_knjige))->second->ZaduziKnjigu( *(korisnici.find(br_korisnika))->second);
  }
  
  void Biblioteka::RazduziKnjigu(int br_knjige) {
    if (!(knjige.count(br_knjige))) throw std::logic_error("Knjiga nije nadjena");
    if (((knjige.find(br_knjige))->second->DaLiJeZaduzena())==0) throw std::logic_error("Knjiga nije zaduzena");
   (knjige.find(br_knjige))->second->RazduziKnjigu();
  }
  
  void Biblioteka::PrikaziZaduzenja(int br_korisnika) const {
    if ((korisnici.count(br_korisnika))==0) throw std::logic_error("Korisnik nije nadjen");
    int br(0);
    for(auto it = knjige.begin(); it != knjige.end(); it++) {
      if(it->second->DajKodKogaJe() == korisnici.find(br_korisnika)->second) {
        br++;
      std::cout <<"Evidencijski broj: " << it->first << std::endl;
      std::cout <<"Naslov: " << (it->second)->DajNaslov() <<std::endl;
      std::cout <<"Pisac: " << (it->second)->DajAutora() <<std::endl;
      std::cout <<"Zanr: " << (it->second)->DajZanr() <<std::endl;
      std::cout <<"Godina izdavanja: " << (it->second)->DajGodinuIzdavanja() <<std::endl;
      }
    }
    if(br == 0) std::cout <<"Nema zaduzenja za tog korisnika!";
  }
  
int main ()
{
//AT6 (c9): testira metodu NadjiKorisnika

Biblioteka bib6;
bib6.RegistrirajNovogKorisnika(1, "Niko", "Nikic", "Zmaja od Bosne bb", "123 456");
bib6.RegistrirajNovuKnjigu(2, "Vlak u snijegu", "Mato Lovrak", "Roman", 1931);
std::cout << bib6.NadjiKorisnika(1).ime;

	return 0;
}