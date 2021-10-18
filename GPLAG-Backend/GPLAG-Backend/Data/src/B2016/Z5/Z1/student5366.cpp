/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise


#include <iostream>
#include <string>
#include <map>
#include <stdexcept>

using namespace std;

struct Korisnik {
  std::string ime, prezime, adresa, telefon;
};

class Knjiga
{
  std::string naslov, pisac, zanr;
  int godina;
  Korisnik *korisnik = nullptr;

public:
  Knjiga(std::string naslov, std::string autor, std::string zanr, int g): naslov(naslov), pisac(autor), zanr(zanr), godina(g), korisnik(nullptr) {}
  std::string DajNaslov()const {
    return naslov;
  }
  std::string DajAutora()const {
    return pisac;
  }
  std::string DajZanr()const {
    return zanr;
  }
  int DajGodinuIzdavanja()const {
    return godina;
  }
  Korisnik* DajKodKogaJe()const {
    return korisnik;
  }
  void ZaduziKnjigu(Korisnik &k) {
    korisnik=&k;
  }
  void RazduziKnjigu() {
    korisnik=nullptr;
  }
  bool DaLiJeZaduzena() const {
    if(korisnik==nullptr)return false;
    return true;
  }
};
class Biblioteka
{
  map<int,Korisnik*> korisnici;
  map<int,Knjiga*> knjige;

public:

  Biblioteka() {}

  ~Biblioteka() {
    for(auto it=korisnici.begin(); it!=korisnici.end(); it++) {
      delete it->second;
    }
    korisnici.clear();

    for(auto it=knjige.begin(); it!=knjige.end(); it++) {
      delete it->second;
    }
    knjige.clear();
  }

  Biblioteka(const Biblioteka&b) {

    for(auto it=b.korisnici.begin(); it!=b.korisnici.end(); it++) {
      korisnici[it->first] = new Korisnik(*it->second);
    }
    for(auto it=b.knjige.begin(); it!=b.knjige.end(); it++) {
      knjige[it->first] = new Knjiga(*it->second);
    }
  }

  Biblioteka( Biblioteka&&b) {
    korisnici=b.korisnici;
    knjige=b.knjige;
    b.korisnici.clear();
    b.knjige.clear();
  }

  Biblioteka& operator=(const Biblioteka&b) {
    if(this!=&b) {
      for(auto it=korisnici.begin(); it!=korisnici.end(); it++) {
        delete it->second;
      }
      korisnici.clear();

      for(auto it=knjige.begin(); it!=knjige.end(); it++) {
        delete it->second;
      }
      knjige.clear();
      
      for(auto it=b.korisnici.begin(); it!=b.korisnici.end(); it++) {
        korisnici[it->first] = new Korisnik(*it->second);
      }
      for(auto it=b.knjige.begin(); it!=b.knjige.end(); it++) {
        knjige[it->first] = new Knjiga(*it->second);
      }
    }

    return *this;

  }
  
  
  Biblioteka& operator=(Biblioteka &&b){
      if(this!=&b) {
        for(auto it=korisnici.begin(); it!=korisnici.end(); it++) {
          delete it->second;
        }
        korisnici.clear();
  
        for(auto it=knjige.begin(); it!=knjige.end(); it++) {
          delete it->second;
        }
        knjige.clear();
        
        korisnici=b.korisnici;
        knjige=b.knjige;
        b.korisnici.clear();
        b.knjige.clear();
        
      }
      
      return *this;
  
  }
  
  void RegistrirajNovogKorisnika(int clanskiBroj, string ime, string prezime, string adresa, string telefon){
    if(korisnici.find(clanskiBroj)!=korisnici.end()) throw logic_error("Korisnik vec postoji");
    
    korisnici[clanskiBroj] = new Korisnik{ime,prezime,adresa,telefon};
  }

  void RegistrirajNovuKnjigu(int evidencijskiBroj, string naslov, string imePisca, string zanr, int godina){
    if(knjige.find(evidencijskiBroj)!=knjige.end()) throw logic_error("Knjiga vec postoji");
    
    knjige[evidencijskiBroj] = new Knjiga{naslov,imePisca,zanr,godina};
  }


  Korisnik& NadjiKorisnika(int clanskiBroj){
    if(korisnici.find(clanskiBroj)==korisnici.end()) throw logic_error("Korisnik nije nadjen");
    
    return *korisnici[clanskiBroj];
  }
   
  Knjiga& NadjiKnjigu(int evidencijskiBroj){
     if(knjige.find(evidencijskiBroj)==knjige.end()) throw logic_error("Knjiga ne postoji");
    
    return *knjige[evidencijskiBroj];
  }
  
  
  void IzlistajKorisnike()const{
    for(auto it=korisnici.begin();it!=korisnici.end();it++){
      cout<<"Clanski broj: "<<it->first<<endl;
      cout<<"Ime i prezime: "<<it->second->ime<<" "<<it->second->prezime<<endl;
      cout<<"Adresa: "<<it->second->adresa<<endl;
      cout<<"Broj telefona: "<<it->second->telefon<<endl<<endl;
    }
  }

  void IzlistajKnjige()const{
      for(auto it=knjige.begin();it!=knjige.end();it++){
      cout<<"Evidencijski broj: "<<it->first<<endl;
      cout<<"Naslov: "<<it->second->DajNaslov()<<endl;
      cout<<"Pisac: "<<it->second->DajAutora()<<endl;
      cout<<"Zanr: "<<it->second->DajZanr()<<endl;
      cout<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<endl;
      
      if(it->second->DaLiJeZaduzena()){
        Korisnik* k = it->second->DajKodKogaJe();
        cout<<"Zaduzena kod korisnika: "<<k->ime<<" "<<k->prezime<<endl;
      }
      
      cout<<endl;
    }
  }
  
  
  void ZaduziKnjigu(int evidencijskiBroj, int clanskiBroj){
    if(korisnici.find(clanskiBroj)==korisnici.end()) throw logic_error("Korisnik nije nadjen");
    if(knjige.find(evidencijskiBroj)==knjige.end()) throw logic_error("Knjiga nije nadjena");
    if(knjige[evidencijskiBroj]->DaLiJeZaduzena()) throw logic_error("Knjiga vec zaduzena");
    
    knjige[evidencijskiBroj]->ZaduziKnjigu(*korisnici[clanskiBroj]);
  }
  
  void RazduziKnjigu(int evidencijskiBroj){
    if(knjige.find(evidencijskiBroj)==knjige.end()) throw logic_error("Knjiga nije nadjena");
    
    if(!knjige[evidencijskiBroj]->DaLiJeZaduzena()) throw logic_error("Knjiga nije zaduzena");
    
    knjige[evidencijskiBroj]->RazduziKnjigu();
  }
  
  void PrikaziZaduzenja(int clanskiBroj){
        if(korisnici.find(clanskiBroj)==korisnici.end()) throw logic_error("Korisnik nije nadjen");
        bool zaduzio=false;
        
        Korisnik* k = korisnici[clanskiBroj];
        for(auto it=knjige.begin();it!=knjige.end();it++){
          if(it->second->DajKodKogaJe()==k){
            zaduzio = true;
            cout<<"Evidencijski broj: "<<it->first<<endl;
            cout<<"Naslov: "<<it->second->DajNaslov()<<endl;
            cout<<"Pisac: "<<it->second->DajAutora()<<endl;
            cout<<"Zanr: "<<it->second->DajZanr()<<endl;
            cout<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<endl;
          }
        }
        if(zaduzio==false) cout<<"Nema zaduzenja za tog korisnika!";
  }
  
};




int main ()
{
  return 0;
}