/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include <memory>

struct Korisnik{
    std::string ime,prezime,adresa,telefon;
};

class Knjiga{
  std::string ime_pisca,zanr,naslov;
  int godina_izdavanja;
  std::shared_ptr<Korisnik> zaduzeni_korisnik;
  public:
  Knjiga(std::string naslov_knjige,std::string imepisca, std::string zanr_knjige, int godina){
      naslov=naslov_knjige;
      ime_pisca=imepisca;
      zanr=zanr_knjige;
      godina_izdavanja=godina;
  }
  std::string DajNaslov() const{return naslov;}
  std::string DajAutora() const{return ime_pisca;}
  std::string DajZanr() const{return zanr;}
  int DajGodinuIzdavanja() const{return godina_izdavanja;}
  std::shared_ptr<Korisnik> DajKodKogaJe() const{return zaduzeni_korisnik;}
  void ZaduziKnjigu(Korisnik &korisnik){
      zaduzeni_korisnik=std::make_shared<Korisnik>(korisnik);
  }
  void RazduziKnjigu(){
      zaduzeni_korisnik=nullptr;
  }
  bool DaLiJeZaduzena(){
      if(zaduzeni_korisnik!=nullptr)return true;
      else return false;
  }
};
class Biblioteka{
  std::map<int,std::shared_ptr<Korisnik>> korisnici;
  std::map<int,std::shared_ptr<Knjiga>> knjige;
  public:
  Biblioteka(){}
  void RegistrirajNovogKorisnika(int clanski_br_korisnika, std::string imekorisnika,std::string prezimekor, std::string adresakor,std::string broj_tel){
      Korisnik pom{imekorisnika, prezimekor,adresakor,broj_tel};
      std::shared_ptr<Korisnik> korisnik(std::make_shared<Korisnik>(pom));
      auto it(korisnici.find(clanski_br_korisnika));
      if(it==korisnici.end())korisnici.insert(std::make_pair(clanski_br_korisnika,korisnik));
      else throw std::logic_error("Korisnik vec postoji");
  }
  void RegistrirajNovuKnjigu(int evidencijski_br_knj,std::string naslov_knjige,std::string imepisca,std::string zanr,int godina_izdavanja){
      std::shared_ptr<Knjiga> nova_knjiga(std::make_shared<Knjiga> (naslov_knjige,imepisca,zanr,godina_izdavanja));
      auto it(knjige.find(evidencijski_br_knj));
      if(it==knjige.end())knjige.insert(std::make_pair(evidencijski_br_knj,nova_knjiga));
      else throw std::logic_error("Knjiga vec postoji");
  }
  Korisnik &NadjiKorisnika(int clanski_broj_korisnika){
      auto it(korisnici.find(clanski_broj_korisnika));
      if(it==korisnici.end())throw std::logic_error("Korisnik nije nadjen");
      else return *it->second;
  }
  Knjiga &NadjiKnjigu(int evidencijski_br_knjige){
      auto it(knjige.find(evidencijski_br_knjige));
      if(it==knjige.end())throw std::logic_error("Knjiga nije nadjena");
      else return *it->second;
  }
  void IzlistajKorisnike() const{
      for(auto it=korisnici.begin();it!=korisnici.end();it++)
      std::cout << "Clanski broj: "<< it->first <<std::endl<<"Ime i prezime: "<< it->second->ime<<" "<<it->second->prezime<< std::endl<<"Adresa: "<< it->second->adresa <<std::endl<<"Broj telefona: "<<it->second->telefon<<std::endl<<std::endl;
      }
  void IzlistajKnjige() const{
      for(auto it=knjige.begin();it!=knjige.end();it++){
      std::cout << "Evidencijski broj: "<< it->first <<std::endl<<"Naslov: "<< it->second->DajNaslov()<< std::endl<<"Pisac: "<< it->second->DajAutora() <<std::endl<<"Zanr: "<<it->second->DajZanr()<<std::endl<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<std::endl<<std::endl;
      if(it->second->DaLiJeZaduzena()==true)std::cout << "Zaduzena kod korisnika: "<<it->second->DajKodKogaJe()->ime <<" "<<it->second->DajKodKogaJe()->prezime<< std::endl;
      }
  }
  void ZaduziKnjigu(int evidencijski_br_knjige,int clanski_broj_korisnika){
      auto it1(korisnici.find(clanski_broj_korisnika));
      auto it2(knjige.find(evidencijski_br_knjige));
      if(it2==knjige.end())throw std::logic_error("Knjiga nije nadjena");
      if(it1==korisnici.end())throw std::logic_error("Korisnik nije nadjen");
      if(it2!=knjige.end() && it2->second->DaLiJeZaduzena()==true)throw std::logic_error("Knjiga vec zaduzena");
      else it2->second->Knjiga::ZaduziKnjigu(*it1->second);
  }
  void RazduziKnjigu(int evidencijski_br_knjige){
      auto it(knjige.find(evidencijski_br_knjige));
      if(it==knjige.end())throw std::logic_error("Knjiga nije nadjena");
      if(it!=knjige.end() && it->second->DaLiJeZaduzena()==false)throw std::logic_error("Knjiga nije zaduzena");
      else it->second->Knjiga::RazduziKnjigu();
  }
  void PrikaziZaduzenja(int clanski_broj_korisnika){
    auto it2(korisnici.find(clanski_broj_korisnika));
    if(it2==korisnici.end())throw std::logic_error("Korisnik nije nadjen");
    int a(0);
    for(auto it=knjige.begin();it!=knjige.end();it++){
      if(it2->second->ime==it->second->DajKodKogaJe()->ime){a=1;
      std::cout << "Evidencijski broj: "<< it->first <<std::endl<<"Naslov: "<< it->second->DajNaslov()<< std::endl<<"Pisac: "<< it->second->DajAutora() <<std::endl<<"Zanr: "<<it->second->DajZanr()<<std::endl<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<std::endl<<std::endl;
     }
    }
    if(a==0)throw std::logic_error("Nema zaduzenja za tog korisnika");
  }
  
};

int main ()
{
    Biblioteka bib8;
bib8.RegistrirajNovogKorisnika(1, "Niko", "Nikic", "Zmaja od Bosne bb", "123 456");
bib8.RegistrirajNovuKnjigu(1, "Vlak u snijegu2", "Mato Lovrak2", "Roman2", 1941);
bib8.RegistrirajNovuKnjigu(2, "Vlak u snijegu", "Mato Lovrak", "Roman", 1931);
bib8.ZaduziKnjigu(2, 1);
bib8.IzlistajKnjige();
	return 0;
}