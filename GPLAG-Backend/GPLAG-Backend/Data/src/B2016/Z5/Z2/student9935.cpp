/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include<iostream>
#include<string>
#include<map>
#include<stdexcept>
#include<memory>

struct Korisnik{
  std::string ime, prezime, adresa, telefon;
};

class Knjiga{
  std::string naslov, pisac, zanr;
  int godina_izdavanja;
  Korisnik *pok;
  public:
  Knjiga(std::string naslov1, std::string pisac1, std::string zanr1, int godina_izdavanja1): naslov(naslov1), 
  pisac(pisac1), zanr(zanr1), godina_izdavanja(godina_izdavanja1), pok(nullptr){}
  std::string DajNaslov()const{ return naslov; }
  std::string DajAutora()const{ return pisac; }
  std::string DajZanr()const{ return zanr; }
  int DajGodinuIzdavanja()const{ return godina_izdavanja; }
  Korisnik *DajKodKogaJe()const{ return pok; }
  void ZaduziKnjigu(Korisnik &k){
      pok=&k;
  }
  void RazduziKnjigu(){ pok=nullptr; }
  bool DaLiJeZaduzena(){
      if(!pok) return false;
      return true;
  }
};

class Biblioteka{
  std::map<int, std::shared_ptr<Korisnik>> korisnici;
  std::map<int, std::shared_ptr<Knjiga>> knjige;  
  public:
  Biblioteka()=default;
  Biblioteka(const Biblioteka &b);
  Biblioteka(Biblioteka &&b){
    std::swap(korisnici,b.korisnici);
    std::swap(knjige,b.knjige);
  }
  Biblioteka &operator =(const Biblioteka &b)=delete;
  Biblioteka &operator =(Biblioteka &&b)=delete;
  void RegistrirajNovogKorisnika(int clanski_broj, std::string ime, std::string prezime, std::string adresa, std::string broj_telefona);
  void RegistrirajNovuKnjigu(int evidencijki_broj, std::string naslov, std::string ime, std::string zanr, int godina_izdavanja);
  Korisnik &NadjiKorisnika(int clanski_broj);
  Knjiga &NadjiKnjigu(int evidencijki_broj);
  void IzlistajKorisnike()const;
  void IzlistajKnjige()const;
  void ZaduziKnjigu(int evidencijki_broj, int clanski_broj);
  void RazduziKnjigu(int evidencijki_broj);
  void PrikaziZaduzenja(int clanski_broj)const;
};

  void Biblioteka::RegistrirajNovogKorisnika(int clanski_broj, std::string ime, std::string prezime, std::string adresa, std::string broj_telefona){
    if(!korisnici.count(clanski_broj)){
      korisnici[clanski_broj] = std::make_shared<Korisnik>();
      korisnici[clanski_broj]->ime=ime;
      korisnici[clanski_broj]->prezime=prezime;
      korisnici[clanski_broj]->adresa=adresa;
      korisnici[clanski_broj]->telefon=broj_telefona;
    }
    else
      throw std::logic_error("Korisnik vec postoji");
  }
  
  void Biblioteka::RegistrirajNovuKnjigu(int evidencijki_broj, std::string naslov, std::string ime, std::string zanr, int godina_izdavanja){
    if(!knjige.count(evidencijki_broj)){
      knjige[evidencijki_broj] = std::make_shared<Knjiga>(naslov, ime, zanr, godina_izdavanja);
    }
    else
      throw std::logic_error("Knjiga vec postoji");
  }
  
  Korisnik &Biblioteka::NadjiKorisnika(int clanski_broj){
    if(korisnici.count(clanski_broj))
      return *korisnici[clanski_broj];
    else
      throw std::logic_error("Korisnik nije nadjen");
  }
  
  Knjiga &Biblioteka::NadjiKnjigu(int evidencijki_broj){
    if(knjige.count(evidencijki_broj))
      return *knjige[evidencijki_broj];
    else
      throw std::logic_error("Knjiga nije nadjena");
  }
  
  void Biblioteka::IzlistajKorisnike()const{
    for(auto x: korisnici){
      std::cout<<"Clanski broj: "<<x.first<<std::endl;
      std::cout<<"Ime i prezime: "<<x.second->ime<<" "<<x.second->prezime<<std::endl;
      std::cout<<"Adresa: "<<x.second->adresa<<std::endl;
      std::cout<<"Broj telefona: "<<x.second->telefon<<std::endl<<std::endl;
    }
  }
  
  void Biblioteka::IzlistajKnjige()const{
    for(auto y: knjige){
      std::cout<<"Evidencijski broj: "<<y.first<<std::endl;
      std::cout<<"Naslov: "<<y.second->DajNaslov()<<std::endl;
      std::cout<<"Pisac: "<<y.second->DajAutora()<<std::endl;
      std::cout<<"Zanr: "<<y.second->DajZanr()<<std::endl;
      std::cout<<"Godina izdavanja: "<<y.second->DajGodinuIzdavanja()<<std::endl;
      if(y.second->DaLiJeZaduzena()){
        std::cout<<"Zaduzena kod korisnika: "<<y.second->DajKodKogaJe()->ime<<" "<<y.second->DajKodKogaJe()->prezime<<std::endl;
      }
    }
  }
  
  void Biblioteka::ZaduziKnjigu(int ev_broj, int cl_broj){
    auto it(knjige.find(ev_broj));
    if(it==knjige.end())
      throw std::logic_error("Knjiga nije nadjena");
    auto it1(korisnici.find(cl_broj));
    if(it1==korisnici.end())
      throw std::logic_error("Korisnik nije nadjen");
    bool pom(NadjiKnjigu(ev_broj).DaLiJeZaduzena());
    if(pom)
      throw std::logic_error("Knjiga vec zaduzena");
    NadjiKnjigu(ev_broj).ZaduziKnjigu(NadjiKorisnika(cl_broj));
  }
  
  Biblioteka::Biblioteka(const Biblioteka &b){
    for(auto it = korisnici.begin(); it != korisnici.end(); it++)
      korisnici[it->first] = std::make_shared<Korisnik>(*it->second);
    for(auto it = knjige.begin(); it != knjige.end(); it++)
      knjige[it->first] = std::make_shared<Knjiga>(*it->second);
  }

  
int main (){
    
	return 0;
}