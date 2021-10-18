#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <map>
#include <utility>
#include <memory>

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
  Korisnik* zaduzenje_knjige=nullptr;
  public:
  Knjiga(std::string naslov,std::string ime_pisca,std::string zanr,int godina_izdavanja) : naslov(naslov),ime_pisca(ime_pisca),zanr(zanr),godina_izdavanja(godina_izdavanja){};
  std::string DajNaslov() const {return naslov;}
  std::string DajAutora() const {return ime_pisca;}
  std::string DajZanr() const {return zanr;}
  int DajGodinuIzdavanja() const {return godina_izdavanja;}
  Korisnik* DajKodKogaJe() const {return zaduzenje_knjige;}
  
  void ZaduziKnjigu(Korisnik &k){zaduzenje_knjige=&k;}
  void RazduziKnjigu(){zaduzenje_knjige=nullptr;}
  bool DaLiJeZaduzena(){if(zaduzenje_knjige==nullptr) return false;return true;}
  
};

class Biblioteka {
  
  std::map<int,std::shared_ptr<Korisnik>> m1;
  std::map<int,std::shared_ptr<Knjiga>> m2;
  
  public:
  
  Biblioteka() {};
  Biblioteka(const Biblioteka &b){
    for(auto it=(b.m1).begin();it!=(b.m1).end();it++){
      m1.insert(std::make_pair(it->first,std::make_shared<Korisnik>(*(it->second))));
    }
    for(auto it=(b.m2).begin();it!=(b.m2).end();it++){
      m2.insert(std::make_pair(it->first,std::make_shared<Knjiga>(*(it->second))));
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
    std::swap(m1, b.m1);
    std::swap(m2, b.m2);
    return *this;
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
      
      std::shared_ptr<Korisnik> p(std::make_shared<Korisnik>(novi));
      m1.insert(std::make_pair(clanski_broj,p));
      
      }
     
  }
  
  void RegistrirajNovuKnjigu(int evidencijski_broj_knjige,std::string naslov,std::string ime_pisca,std::string zanr,int godina_izdavanja){
    
    auto it(m2.find(evidencijski_broj_knjige));
    if(it!=m2.end()) throw std::logic_error("Knjiga vec postoji");
    else{
    std::shared_ptr<Knjiga>temp(std::make_shared<Knjiga>(naslov,ime_pisca,zanr,godina_izdavanja));
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
    auto it=m1.begin();
    for(it;it!=m1.end();it++){
    std::cout<<"Clanski broj: "<<(it->first)<<std::endl;
    std::cout<<"Ime i prezime: "<<(it->second->ime)<<" "<<(it->second->prezime)<<std::endl;
    std::cout<<"Adresa: "<<(it->second->adresa)<<std::endl;
    std::cout<<"Broj telefona: "<<(it->second->telefon)<<std::endl;
    std::cout<<std::endl;
  }
  }
  void IzlistajKnjige() const{
    
    auto it=m2.begin();
    for(it;it!=m2.end();it++){
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
    
    if(it2==m2.end()) throw std::logic_error("Knjiga vec postoji");
    if(it1==m1.end()) throw std::logic_error("Korisnik vec postoji");
    
   
   NadjiKnjigu(evidencijski_broj_knjige).ZaduziKnjigu(NadjiKorisnika(clanski_broj));
  
    
  }
  void RazduziKnjigu(int evidencijski_broj_knjige){
    
    auto it2(m2.find(evidencijski_broj_knjige));
    if(it2!=m2.end()) throw std::logic_error("Knjiga nije nadjena");
    NadjiKnjigu(evidencijski_broj_knjige).RazduziKnjigu();
    
    
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