/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise

#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include <memory>

typedef std::string string;

struct Korisnik{
    string ime, prezime, adresa, telefon;
};

class Knjiga{
  private:
  string naslov,ime_pisca,zanr;
  int god_izdavanja;
  Korisnik *zaduzena=nullptr;
  public:
  explicit Knjiga(string n,string i_p,string z,int g): naslov(n), ime_pisca(i_p), zanr(z), god_izdavanja(g) {}
  string DajNaslov() const {return naslov;}
  string DajAutora() const {return ime_pisca;}
  string DajZanr() const {return zanr;}
  int DajGodinuIzdavanja() const {return god_izdavanja;}
  Korisnik *DajKodKogaJe() const {return zaduzena;}
  void ZaduziKnjigu(Korisnik &osoba){zaduzena=&osoba;};
  void RazduziKnjigu(){zaduzena=nullptr;}
  bool DaLiJeZaduzena(){if (zaduzena==nullptr) return false; return true;}
  
};

class Biblioteka{
  private:
  std::map<int,std::shared_ptr<Korisnik>> korisnik;
  std::map<int, std::shared_ptr<Knjiga>> knjiga;
  public:
  Biblioteka(){};
  Biblioteka(Biblioteka &b){for(auto it=korisnik.begin();it!=korisnik.end();it++){this->korisnik[it->first]=std::make_shared<Korisnik>(*it->second);} for(auto it=knjiga.begin();it!=knjiga.end();it++){this->knjiga[it->first]=std::make_shared<Knjiga>(*it->second); } }
  Biblioteka operator=(const Biblioteka &b){
    if(this==&b) return *this;
    /*for(auto it=korisnik.begin(); it!=korisnik.end();it++){
      delete it->second;
    }
    for(auto it=knjiga.begin();it!=knjiga.end();it++){
      delete it->second;
    }*/
    for(auto it=b.korisnik.begin();it!=b.korisnik.end();it++){
      this->korisnik[it->first]=std::make_shared<Korisnik> (*it->second);
    }
    for(auto it=b.knjiga.begin();it!=b.knjiga.end();it++){
      this->knjiga[it->first]=std::make_shared<Knjiga> (*it->second);
    }
    return *this;
  }
  //~Biblioteka(){ for(auto it=korisnik.begin();it!=korisnik.end();it++){ delete it->second;  } for(auto it=knjiga.begin();it!=knjiga.end();it++) {delete it->second;} }
  void RegistrirajNovogKorisnika(int cl_broj, string ime, string prezime, string adresa, string br_tel);
  void IzlistajKorisnike() const {
    for(auto it=korisnik.begin();it!=korisnik.end();it++){
      std::cout<<"Clanski broj: "<<it->first<<std::endl;
      std::cout<<"Ime i prezime: "<<it->second->ime<<" "<<it->second->prezime<<std::endl;
      std::cout<<"Adresa: "<<it->second->adresa<<std::endl;
      std::cout<<"Broj telefona: "<<it->second->telefon<<std::endl;
      std::cout<<std::endl;
    }
  }
  void RegistrirajNovuKnjigu(int ev_broj, string naslov, string ime_pisca, string zanr,int god_izdavanja);
  void IzlistajKnjige() const {
    for(auto it=knjiga.begin();it!=knjiga.end();it++){
      std::cout<<"Evidencijski broj: "<<it->first<<std::endl;
      std::cout<<"Naslov: "<<it->second->DajNaslov()<<std::endl;
      std::cout<<"Pisac: "<<it->second->DajAutora()<<std::endl;
      std::cout<<"Zanr: "<<it->second->DajZanr()<<std::endl;
      std::cout<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<std::endl;
      if(it->second->DaLiJeZaduzena()) std::cout<<"Zaduzena kod korisnika: "<<it->second->DajKodKogaJe()->ime<<" "<<it->second->DajKodKogaJe()->prezime<<std::endl;
      std::cout<<std::endl;
    }
  }
  void ZaduziKnjigu(int ev_broj, int cl_broj);
  void RazduziKnjigu(int ev_broj);
  void PrikaziZaduzenja(int cl_broj);
  
  Korisnik &NadjiKorisnika(int cl_broj);
  Knjiga &NadjiKnjigu(int ev_broj);
};

void Biblioteka::RegistrirajNovogKorisnika(int cl_broj, string ime, string prezime, string adresa, string br_tel){
  for(auto it=korisnik.begin();it!=korisnik.end();it++){
    if(it->first==cl_broj) throw std::logic_error("Korisnik vec postoji");
  }
  Korisnik k;
  k.ime=ime; k.prezime=prezime; k.adresa=adresa; k.telefon=br_tel;
  korisnik[cl_broj]=std::make_shared<Korisnik>(k);
}

void Biblioteka::RegistrirajNovuKnjigu(int ev_broj, string naslov, string ime_pisca, string zanr,int god_izdavanja){
  for(auto it=knjiga.begin();it!=knjiga.end();it++){
    if(it->first==ev_broj) throw std::logic_error("Knjiga vec postoji");
  }
  Knjiga k(naslov,ime_pisca,zanr,god_izdavanja);
  knjiga[ev_broj]=std::make_shared<Knjiga>(k);
}

Korisnik &Biblioteka::NadjiKorisnika(int cl_broj){
  if(korisnik.find(cl_broj)==korisnik.end()) throw std::logic_error("Korisnik nije nadjen");
  auto it(korisnik.find(cl_broj));
  return *(it->second);
}

Knjiga &Biblioteka::NadjiKnjigu(int ev_broj){
  if(knjiga.find(ev_broj)==knjiga.end()) throw std::logic_error("Knjiga nije nadjena");
  auto it(knjiga.find(ev_broj));
  return *(it->second);
}

void Biblioteka::ZaduziKnjigu(int ev_broj,int cl_broj){
  if(knjiga.find(ev_broj)==knjiga.end()) throw std::logic_error("Knjiga nije nadjena");
  if(korisnik.find(cl_broj)==korisnik.end()) throw std::logic_error("Korisnik nije nadjen");
  auto knj(knjiga.find(ev_broj));
  if(knj->second->DaLiJeZaduzena()) throw std::logic_error("Knjiga je vec zaduzena");
  auto kor(korisnik.find(cl_broj));
  knj->second->ZaduziKnjigu(*(kor->second));
}

void Biblioteka::RazduziKnjigu(int ev_broj){
  if(knjiga.find(ev_broj)==knjiga.end()) throw std::logic_error("Knjiga nije nadjena");
  auto knj(knjiga.find(ev_broj));
  if(!(knj->second->DaLiJeZaduzena())) throw std::logic_error("Knjiga nije zaduzena");
  knj->second->RazduziKnjigu();
}

void Biblioteka::PrikaziZaduzenja(int cl_broj){
    bool ima(false);
    if(korisnik.find(cl_broj)==korisnik.end()) throw std::logic_error("Korisnik nije nadjen");
    for(auto it=knjiga.begin();it!=knjiga.end();it++){
    if(it->second->DajKodKogaJe()!=korisnik[cl_broj].get()) ima=true;
  }
  if(ima==false) throw std::logic_error("Nema zaduzenja za tog korisnika!");
 IzlistajKnjige(); 
}

int main (){
  try{
    int n;
    Biblioteka b;
    do{
    std::cout<<"Odaberite opciju: "<<std::endl;
    std::cout<<"1: REGISTRACIJA NOVOG KORISNIKA"<<std::endl;
    std::cout<<"2: REGISTRACIJA NOVE KNJIGE"<<std::endl;
    std::cout<<"3: PRONALAZAK ZELJENOG KORISNIKA"<<std::endl;
    std::cout<<"4: PRONALAZAK ZELJENE KNJIGE"<<std::endl;
    std::cout<<"5: ZADUZIVANJE KNJIGE"<<std::endl;
    std::cout<<"6: RAZDUZIVANJE KNJIGE"<<std::endl;
    std::cout<<"7: PRIKAZ ZADUZENJA"<<std::endl;
    std::cout<<"8: ISPIS KORISNIKA"<<std::endl;
    std::cout<<"9: ISPIS KNJIGA"<<std::endl;
    std::cout<<"0: IZLAZAK IZ PROGRAMA"<<std::endl;
    std::cin>>n;
    if(n==1){
      int cl_br;
      string ime, prezime,adresa,tel;
      std::cout<<"REGISTRACIJA NOVOG KORISNIKA"<<std::endl;
      std::cout<<"Clanski broj: "<<std::endl; std::cin>>cl_br;
      std::cout<<"Ime: "<<std::endl;
      std::cin>>ime;
      std::cout<<"Prezime: "<<std::endl;
      std::cin>>prezime;
      std::cout<<"Adresa stanovanja: "<<std::endl;
      std::cin>>adresa;
      std::cout<<"Kontakt telefon: "<<std::endl;
      std::cin>>tel;
      b.RegistrirajNovogKorisnika(cl_br,ime,prezime,adresa,tel);
      std::cout<<"Korisnik registriran!"<<std::endl;
    }
    else if(n==2){
      int ev_br,god;
      string naslov, pisac,zanr;
      std::cout<<"REGISTRACIJA NOVE KNJIGE"<<std::endl;
      std::cout<<"Evidencijski broj: "<<std::endl; std::cin>>ev_br;
      std::cout<<"Naslov: "<<std::endl; 
      std::cin>>naslov;
      std::cout<<"Autor: "<<std::endl; 
      std::cin>>pisac;
      std::cout<<"Zanr: "<<std::endl; 
      std::cin>>zanr;
      std::cout<<"Godina izdavanja: "<<std::endl;
      std::cin>>god;
      b.RegistrirajNovuKnjigu(ev_br,naslov,pisac,zanr,god);
      std::cout<<"Knjiga registrirana!"<<std::endl;
    }
    else if(n==3){
      int cl_br;
      std::cout<<"PRONALAZAK ZELJENOG KORISNIKA"<<std::endl;
      std::cout<<"Unesite clanski broj korisnika kojeg trazite: "<<std::endl;
      std::cin>>cl_br;
      b.NadjiKorisnika(cl_br);
    }
    else if(n==4){
      int ev_br;
      std::cout<<"PRONALAZAK ZELJENE KNJIGE"<<std::endl;
      std::cout<<"Unesite evidencijski broj knjige koju trazite: "<<std::endl;
      std::cin>>ev_br;
      b.NadjiKnjigu(ev_br);
    }
    else if(n==5){
      int ev_br,cl_br;
      std::cout<<"ZADUZIVANJE KNJIGE"<<std::endl;
      std::cout<<"Unesite evidencijski broj knjige i clanski broj korisnika koji je zaduzuje: "<<std::endl;
      std::cin>>ev_br; std::cin>>cl_br;
      b.ZaduziKnjigu(ev_br,cl_br);
      std::cout<<"Knjiga zaduzena!"<<std::endl;
    }
    else if(n==6){
      int ev_br;
      std::cout<<"RAZDUZIVANJE KNJIGE"<<std::endl;
      std::cout<<"Unesite evidencijski broj knjige koju treba razduziti: "<<std::endl;
      std::cin>>ev_br;
      b.RazduziKnjigu(ev_br);
      std::cout<<"Knjiga razduzena!"<<std::endl;
    }
    else if(n==7){
      int cl_br;
      std::cout<<"PRIKAZ ZADUZENJA"<<std::endl;
      std::cout<<"Unesite clanski broj korisnika cija zaduzenja trazite: "<<std::endl;
      std::cin>>cl_br;
      b.PrikaziZaduzenja(cl_br);
    }
    else if(n==8){
      b.IzlistajKorisnike();
    }
    else if(n==9){
      b.IzlistajKnjige();
    }
    else{
 
      std::cout<<"Pogresan unos! Pokusajte ponovo."<<std::endl;
    }
    std::cout<<std::endl;
    } while(n!=0);
  }
  catch(std::logic_error izuzetak){
    std::cout<<izuzetak.what();
  }
  return 0;
}