/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <stdexcept>
#include <map>

struct Korisnik{
    std::string ime,prezime,adresa,telefon;
};

class Knjiga{
  std::string naziv_knjige, pisac, zanr;
  int godina_izdavanja; 
  Korisnik* zaduzio;
  public:
  Knjiga(std::string ime_knjige,std::string ime_pisca, std::string zanr_knjige, int godina){
    naziv_knjige=ime_knjige; pisac=ime_pisca; zanr=zanr_knjige; godina_izdavanja=godina; zaduzio=nullptr;
  }
  std::string DajNaslov() const {return naziv_knjige;}
  std::string DajAutora() const {return pisac;}
  std::string DajZanr() const {return zanr;}
  int DajGodinuIzdavanja() const { return godina_izdavanja;}
  Korisnik* DajKodKogaJe() const {return zaduzio;}
  void ZaduziKnjigu(Korisnik &k) { zaduzio=&k; }
  void RazduziKnjigu() { zaduzio=nullptr; }
  bool DaLiJeZaduzena() const { return zaduzio!=nullptr;}
};

class Biblioteka{
  std::map<int,Korisnik*> korisnici;
  std::map<int,Knjiga*> knjige;
  public:
  Biblioteka(){};
  Biblioteka(const Biblioteka &b);
  Biblioteka(Biblioteka &&b);
  ~Biblioteka();
  Biblioteka &operator =(const Biblioteka &b);
  Biblioteka &operator =(Biblioteka &&b);
  void RegistrirajNovogKorisnika(int clanski_broj, std::string ime_korisnika, std::string prezime_korisnika, std::string adresa_korisnika, std::string telefon_korisnika );
  void RegistrirajNovuKnjigu(int br_knjige, std::string naslov, std::string ime_pisca, std::string zanr_knjige, int godina);
  Korisnik &NadjiKorisnika(int clanski_broj) const;
  Knjiga &NadjiKnjigu(int br_knjige) const ;
  void IzlistajKorisnike() const;
  void IzlistajKnjige() const;
  void ZaduziKnjigu(int br_knjige, int clanski_broj);
  void RazduziKnjigu(int br_knjige);
  void PrikaziZaduzenja(int clanski_broj) const;
};

void Biblioteka::PrikaziZaduzenja(int clanski_broj) const{
  auto it1=korisnici.find(clanski_broj);
  if(it1==korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
  bool ImaLiBaremJednoZaduzenje=false;
  for(auto it=knjige.begin();it!=knjige.end();it++){
    if(it->second->DaLiJeZaduzena()){
      if(it->second->DajKodKogaJe()==it1->second){
        ImaLiBaremJednoZaduzenje=true;
        std::cout << "Evidencijski broj: " << it->first << std::endl;
        std::cout << "Naslov: " << (it->second)->DajNaslov() << std::endl;
        std::cout << "Pisac: " << (it->second)->DajAutora() << std::endl;
        std::cout << "Zanr: " << (it->second)->DajZanr() << std::endl;
        std::cout << "Godina izdavanja: " << (it->second)->DajGodinuIzdavanja()<< std::endl;
        std::cout << std::endl;
      }
    }
  }
  if(!ImaLiBaremJednoZaduzenje) std::cout << "Nema zaduzenja za tog korisnika!" << std::endl;
}

void Biblioteka::RazduziKnjigu(int br_knjige){
  auto it=knjige.find(br_knjige);
  if(it==knjige.end()) throw std::logic_error("Knjiga nije nadjena");
  else if(!(it->second->DaLiJeZaduzena())) throw std::logic_error("Knjiga nije zaduzena");
  else{
    it->second->RazduziKnjigu();
  }
}

void Biblioteka::ZaduziKnjigu(int br_knjige, int clanski_broj){
  auto it=knjige.find(br_knjige);
  auto it1=korisnici.find(clanski_broj);
  if(it==knjige.end()) throw std::logic_error("Knjiga nije nadjena");
  else if((it->second)->DaLiJeZaduzena()) throw std::logic_error("Knjiga vec zaduzena");
  else if(it1==korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
  else{
    it->second->ZaduziKnjigu(*(it1->second));
  }
}

void Biblioteka::IzlistajKnjige() const{
  for(auto it=knjige.begin();it!=knjige.end();it++){
    std::cout << "Evidencijski broj: " << it->first << std::endl;
    std::cout << "Naslov: " << (it->second)->DajNaslov() << std::endl;
    std::cout << "Pisac: " << (it->second)->DajAutora() << std::endl;
    std::cout << "Zanr: " << (it->second)->DajZanr() << std::endl;
    std::cout << "Godina izdavanja: " << (it->second)->DajGodinuIzdavanja()<< std::endl;
    if((it->second)->DaLiJeZaduzena()) std::cout << "Zaduzena kod korisnika: " << (it->second)->DajKodKogaJe()->ime << " " << (it->second)->DajKodKogaJe()->prezime << std::endl;
  }   
  std::cout << std::endl;
}

void Biblioteka::IzlistajKorisnike() const {
  for(auto it=korisnici.begin();it!=korisnici.end();it++){
    std::cout << "Clanski broj: " << it->first << std::endl;
    std::cout << "Ime i prezime: " << (it->second)->ime << " " << (it->second)->prezime << std::endl;
    std::cout << "Adresa: " << (it->second)->adresa << std::endl;
    std::cout << "Broj telefona: " << (it->second)->telefon << std::endl;
    std::cout << std::endl;
  }
}

void Biblioteka::RegistrirajNovogKorisnika(int clanski_broj, std::string ime_korisnika, std::string prezime_korisnika, std::string adresa_korisnika, std::string telefon_korisnika ){
  auto it=korisnici.find(clanski_broj);
  if(it!=korisnici.end()) throw std::logic_error("Korisnik vec postoji");
  Korisnik a; a.ime=ime_korisnika; a.prezime=prezime_korisnika;a.adresa=adresa_korisnika; a.telefon=telefon_korisnika;
  auto pok=new Korisnik(a);
  korisnici.insert(std::make_pair(clanski_broj,pok));
}

void Biblioteka::RegistrirajNovuKnjigu(int br_knjige, std::string naslov, std::string ime_pisca, std::string zanr_knjige, int godina){
  auto it=knjige.find(br_knjige);
  if(it!=knjige.end()) throw std::logic_error("Knjiga vec postoji");
  auto pok=new Knjiga(Knjiga(naslov,ime_pisca,zanr_knjige,godina));
  knjige.insert(std::make_pair(br_knjige,pok));
}

Korisnik &Biblioteka::NadjiKorisnika(int clanski_broj) const{
  auto it=korisnici.find(clanski_broj);
  if(it==korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
  return *(it->second);
}

Knjiga &Biblioteka::NadjiKnjigu(int br_knjige) const{
  auto it=knjige.find(br_knjige);
  if(it==knjige.end()) throw std::logic_error("Knjiga nije nadjena");
  return *(it->second);
}

Biblioteka &Biblioteka::operator =(Biblioteka &&b){
  if(&b!=this){
    for(auto it=korisnici.begin();it!=korisnici.end();it++){
      delete it->second;
    }
    for(auto it=knjige.begin();it!=knjige.end();it++){
      delete it->second;
    }
    korisnici.clear(); knjige.clear();
    for(auto it=(b.korisnici).begin();it!=(b.korisnici).end();it++){
      korisnici.insert(std::make_pair(it->first,it->second));
      it->second=nullptr;
    } b.korisnici.clear();
    for(auto it=(b.knjige).begin();it!=(b.knjige).end();it++){
      knjige.insert(std::make_pair(it->first,it->second));
      it->second=nullptr;
    }
    b.knjige.clear();
  }
  return *this;
}

Biblioteka &Biblioteka::operator =(const Biblioteka &b){
  if(&b!=this){
    for(auto it=korisnici.begin();it!=korisnici.end();it++){
      delete it->second;
    }
    for(auto it=knjige.begin();it!=knjige.end();it++){
      delete it->second;
    }
    korisnici.clear(); knjige.clear();
    for(auto it=(b.korisnici).begin();it!=(b.korisnici).end();it++){
      korisnici.insert(std::make_pair(it->first,new Korisnik(*(it->second))));
    }
    for(auto it=(b.knjige).begin();it!=(b.knjige).end();it++){
      knjige.insert(std::make_pair(it->first,new Knjiga(*(it->second))));
    }
  }
  return *this;
}

Biblioteka::~Biblioteka(){
  for(auto it=korisnici.begin();it!=korisnici.end();it++){
    delete it->second;
  }
  for(auto it=knjige.begin();it!=knjige.end();it++){
    delete it->second;
  }
}

Biblioteka::Biblioteka(Biblioteka &&b){
  for(auto it=(b.korisnici).begin();it!=(b.korisnici).end();it++){
    korisnici.insert(std::make_pair(it->first,it->second));
    it->second=nullptr;
  }
  b.korisnici.clear();
  for(auto it=(b.knjige).begin();it!=(b.knjige).end();it++){
    knjige.insert(std::make_pair(it->first,it->second));
    it->second=nullptr;
  }
  b.knjige.clear();
}

Biblioteka::Biblioteka(const Biblioteka &b){
  for(auto it=(b.korisnici).begin();it!=(b.korisnici).end();it++){
    korisnici.insert(std::make_pair(it->first,new Korisnik(*(it->second))));
  }
  for(auto it=(b.knjige).begin();it!=(b.knjige).end();it++){
    knjige.insert(std::make_pair(it->first,new Knjiga(*(it->second))));
  }
}

int main ()
{
 
	return 0;
}