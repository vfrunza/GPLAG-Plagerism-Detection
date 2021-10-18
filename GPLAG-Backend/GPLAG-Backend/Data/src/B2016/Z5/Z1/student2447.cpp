#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <map>
#include <utility>

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
  Korisnik *zaduzenje_knjige=nullptr;
  public:
  Knjiga(std::string naslov,std::string ime_pisca,std::string zanr,int godina_izdavanja) : naslov(naslov),ime_pisca(ime_pisca),zanr(zanr),godina_izdavanja(godina_izdavanja){};
  std::string DajNaslov() const {return naslov;}
  std::string DajAutora() const {return ime_pisca;}
  std::string DajZanr() const {return zanr;}
  int DajGodinuIzdavanja() const {return godina_izdavanja;}
  Korisnik *DajKodKogaJe() const {return zaduzenje_knjige;}
  
  void ZaduziKnjigu(Korisnik &k){zaduzenje_knjige=&k;}
  void RazduziKnjigu(){zaduzenje_knjige=nullptr;}
  bool DaLiJeZaduzena(){if(zaduzenje_knjige==nullptr) return false;return true;}
  
};

class Biblioteka {
  
  std::map<int,Korisnik*> m1;
  std::map<int,Knjiga*> m2;
  
  public:
  
  Biblioteka() {};
  Biblioteka(const Biblioteka &b){
    for(auto it=(b.m1).begin();it!=(b.m1).end();it++){
      m1.insert(std::make_pair(it->first,new Korisnik(*(it->second))));
    }
    for(auto it=(b.m2).begin();it!=(b.m2).end();it++){
      m2.insert(std::make_pair(it->first,new Knjiga(*(it->second))));
    }
    
  }
  
  Biblioteka(Biblioteka &&b){
    m1=b.m1;
    for(auto it=(b.m1).begin();it!=(b.m1).end();it++){
      it->second=nullptr;
    }
    m2=b.m2;
    for(auto it=(b.m2).begin();it!=(b.m2).end();it++){
      it->second=nullptr;
    }
  }
  
  Biblioteka &operator=(Biblioteka b){
    if(this!=&b){
    std::swap(m1, b.m1);
    std::swap(m2, b.m2);
    }
    return *this;
    
  }

  ~Biblioteka() {
    for(auto it=(m1).begin();it!=(m1).end();it++){
      delete it->second;
    }
    for(auto it=(m2).begin();it!=(m2).end();it++){
      delete it->second;
    }
  }
  
  void RegistrirajNovogKorisnika(int clanski_broj,std::string ime,std::string prezime,std::string adresa,std::string broj_telefona){
      
      auto it(m1.find(clanski_broj));
      if(it!=m1.end()) throw std::logic_error("Korisnik nije nadjen");
     
      else {
        
      Korisnik novi;
      novi.ime=ime;
      novi.prezime=prezime;
      novi.adresa=adresa;
      novi.telefon=broj_telefona;
      Korisnik *temp(new Korisnik(novi));
      m1.insert(std::make_pair(clanski_broj,temp));
      
      }
     
  }
  
  void RegistrirajNovuKnjigu(int evidencijski_broj_knjige,std::string naslov,std::string ime_pisca,std::string zanr,int godina_izdavanja){
    
    auto it(m2.find(evidencijski_broj_knjige));
    if(it!=m2.end()) throw std::logic_error("Knjiga vec postoji");
    else{
    Knjiga *temp(new Knjiga(naslov,ime_pisca,zanr,godina_izdavanja));
    m2.insert(std::make_pair(evidencijski_broj_knjige,temp));
    }
  }
 
  Korisnik &NadjiKorisnika(int clanski_broj){
    
    if(!m1.count(clanski_broj)) throw std::logic_error("Korisnik nije nadjen");
    else {
      auto it(m1.find(clanski_broj));
      return *(it->second);
    } 
    
  }
  Knjiga &NadjiKnjigu(int evidencijski_broj_knjige){
    
    if(!m2.count(evidencijski_broj_knjige)) throw std::logic_error("Knjiga nije nadjena");
    else {
      auto it(m2.find(evidencijski_broj_knjige));
      return *(it->second);
    }
    
  }
  
  void IzlistajKorisnike() const{
    for(auto it=m1.begin();it!=m1.end();it++){
    std::cout<<"Clanski broj: "<<(it->first)<<std::endl;
    std::cout<<"Ime i prezime: "<<(it->second->ime)<<" "<<(it->second->prezime)<<std::endl;
    std::cout<<"Adresa: "<<(it->second->adresa)<<std::endl;
    std::cout<<"Broj telefona: "<<(it->second->telefon)<<std::endl;
    std::cout<<std::endl;
  }
  }
  void IzlistajKnjige() const{
    
    for(auto it=m2.begin();it!=m2.end();it++){
    std::cout<<"Evidencijski broj: "<<(it->first)<<std::endl;
    std::cout<<"Naslov: "<<(it->second->DajNaslov())<<std::endl;
    std::cout<<"Pisac: "<<(it->second->DajAutora())<<std::endl;
    std::cout<<"Zanr: "<<(it->second->DajZanr())<<std::endl;
    std::cout<<"Godina izdavanja: "<<(it->second->DajGodinuIzdavanja())<<std::endl;
    if(it->second->DaLiJeZaduzena()) {
      std::cout<<"Zaduzena kod korisnika: "<<it->second->DajKodKogaJe()->ime<<" "<<it->second->DajKodKogaJe()->prezime;
      std::cout<<std::endl;
    }
    }
  }
  
  
  
  
  void ZaduziKnjigu(int evidencijski_broj_knjige,int clanski_broj){
    
    auto it1(m1.find(clanski_broj));
    auto it2(m2.find(evidencijski_broj_knjige));
    
    if(it2==m2.end()) throw std::logic_error("Knjiga nije nadjena");
    if(it1==m1.end()) throw std::logic_error("Korisnik nije nadjen");
    if(m2.find(evidencijski_broj_knjige)->second->DaLiJeZaduzena()) throw std::logic_error("Knjiga vec zaduzena");
    
   
   NadjiKnjigu(evidencijski_broj_knjige).ZaduziKnjigu(NadjiKorisnika(clanski_broj));
  
    
  }
  void RazduziKnjigu(int evidencijski_broj_knjige){
    
    auto it2(m2.find(evidencijski_broj_knjige));
    if(it2!=m2.end()) throw std::logic_error("Knjiga nije nadjena");
    if(!m2.find(evidencijski_broj_knjige)->second->DaLiJeZaduzena()) throw std::logic_error("Knjiga nije zaduzena");
    
    NadjiKnjigu(evidencijski_broj_knjige).RazduziKnjigu();
    
    
  }
  
  
  void PrikaziZaduzenja(const int &clanski_broj){
    int brojac(0);
    for(auto it=m2.begin();it!=m2.end();it++){
      
      if((m1[clanski_broj])==((*it).second->DajKodKogaJe()) && it->second->DaLiJeZaduzena()){
       
        std::cout<<"Evidencijski broj: "<<it->first<<std::endl;
        std::cout<<"Naslov: "<<it->second->DajNaslov()<<std::endl;
        std::cout<<"Pisac: "<<it->second->DajAutora()<<std::endl;
        std::cout<<"Zanr: "<<it->second->DajZanr()<<std::endl;
        std::cout<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<std::endl;
        std::cout<<std::endl;
        brojac++;
        
      }
    }
      if(brojac==0) {
        std::cout<<"Nema zaduzenja za tog korisnika!"<<std::endl;
      }
    
  
  }
  
};


int main ()
{
  Biblioteka b;
b.RegistrirajNovogKorisnika(1234, "Petar", "Petrovic",
"Zmaja od Bosne 30", "032/444-555");
b.RegistrirajNovogKorisnika(4312, "Hasan", "Hasanovic",
"Trg neznalica 111", "030/111-222");
b.RegistrirajNovogKorisnika(3124, "Mehmed", "Mehmedovic",
"Studenata etfovaca 3b", "037/654-321");
b.RegistrirajNovuKnjigu(231, "Prokleta avlija", "Ivo Andric", "Roman", 1955);
b.RegistrirajNovuKnjigu(555, "Grimove Bajke", "Braca Grim", "Bajke", 1927);
b.RegistrirajNovuKnjigu(136, "Kameni spavac", "Mak Dizdar", "Poezija", 1960);
b.ZaduziKnjigu(231, 1234);
b.ZaduziKnjigu(136, 1234);
b.PrikaziZaduzenja(1234);
	return 0;
}