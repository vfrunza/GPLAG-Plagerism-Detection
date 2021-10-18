/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <memory>
struct Korisnik{
  
  std::string ime ;
  std::string prezime;
  std::string adresa;
  std::string telefon; 
  
};
class Knjiga{
  std::string naslov, ime_pisca, zanr;
   int godina_izdanja;
   std::shared_ptr<Korisnik> kod_koga_je;Korisnik *zaduzenje;
  public:

  Knjiga(std::string naslov, std::string ime_pisca, std::string zanr, int godina_izdanja) : naslov(naslov), ime_pisca(ime_pisca), zanr(zanr), godina_izdanja(godina_izdanja),kod_koga_je(nullptr) {}
  std::string DajNaslov() const{return naslov;}
  std::string DajAutora() const{return ime_pisca;}
  std::string DajZanr() const {return zanr;}
  int DajGodinuIzdavanja() const {return godina_izdanja;}
 
  Korisnik* DajKodKogaJe()  {
    return  zaduzenje;
    
  }
  //int zaduzenje=0;
  void ZaduziKnjigu(Korisnik &kod_koga_je){
   zaduzenje=&kod_koga_je;
  }
  void RazduziKnjigu(){
    zaduzenje=nullptr;
  }
  bool DaLiJeZaduzena(){
    if(zaduzenje!=nullptr) return true;
    
     if(zaduzenje==nullptr){return false;}
  }
};
typedef std::map<int,Korisnik*>mapa1;
typedef  std::pair<int, Korisnik*> par1;
typedef std::map<int, std::shared_ptr<Knjiga>> mapa2;
typedef std::pair<int, std::shared_ptr<Knjiga>> par2;
class Biblioteka{
 mapa1 mapa11;
 mapa2 mapa22;
 Korisnik*korisnici;
//std::shared_ptr<Korisnik> korisnici;
//std::shared_ptr<Knjiga> knjige ;
  public:
  
~Biblioteka(){
  
  for(auto it=mapa11.begin(); it!=mapa11.end(); it++){
    delete(it->second);
  }
  
 
};

  void RegistrirajNovogKorisnika(int clanski_broj, std::string ime, std::string prezime, std::string adresa, std::string telefon){
  
   korisnici=new Korisnik{ime,prezime,adresa,telefon};
  mapa11.insert(par1(clanski_broj, korisnici)); 
   
  }
 
  void RegistrirajNovuKnjigu(int clanski_broj, std::string naslov, std::string ime_pisca, std::string zanr, int godina_izdanja){
 
    
    //std::shared_ptr<Knjiga>knjige=std::make_shared Knjiga{ naslov, ime_pisca, zanr, godina_izdanja};
  std::shared_ptr<Knjiga> knjige(std::make_shared<Knjiga>(naslov, ime_pisca, zanr, godina_izdanja));
    mapa22.insert(par2(clanski_broj, knjige));
    
  
    
  }
  Korisnik NadjiKorisnika(int clanski_broj){
   for(auto it=mapa11.begin(); it!=mapa11.end(); it++) {
      if(it->first==clanski_broj ){
        auto p=it->second;
      
        return *p;
        
      }
     
 
  }
  }
  
  Knjiga NadjiKnjigu(int clanski_broj){
    for(auto it=mapa22.begin(); it!=mapa22.end(); it++){
      if(it->first==clanski_broj ){
        auto p(it->second);
        p.get();
        return *p;
      }
    }
  }
  
  void IzlistajKorisnike(){
    for(auto it=mapa11.begin(); it!=mapa11.end(); it++){
      std::cout<<"Clanski broj: "<<it->first<<std::endl;
      std::cout<<"Ime i prezime: "<<it->second->ime<<" "<<it->second->prezime<<std::endl;
      std::cout<<"Adresa: "<<it->second->adresa<<std::endl;
      std::cout<<"Broj telefona: "<<it->second->telefon<<std::endl;
      std::cout<<std::endl;
      
    }
  }
  void IzlistajKnjige(){
    int brojac = 0;
    for(auto it=mapa22.begin(); it!=mapa22.end(); it++){
      for(auto it1=mapa11.begin(); it1!=mapa11.end(); it1++){
        if(it->second->DaLiJeZaduzena()) brojac ++;
    }
    }
    int novi_brojac=0;
    for(auto it=mapa22.begin(); it!=mapa22.end(); it++){
    for(auto it1=mapa11.begin(); it1!=mapa11.end(); it1++){
      std::cout<<"Evidencijski broj: "<<it->first<<std::endl;
      std::cout<<"Naslov: "<<it->second->DajNaslov()<<std::endl;
      std::cout<<"Pisac: "<<it->second->DajAutora()<<std::endl;
      std::cout<<"Zanr: "<<it->second->DajZanr()<<std::endl;
      std::cout<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<std::endl;
   
    if(it->second->DaLiJeZaduzena()) novi_brojac++;
      if (it->second->DaLiJeZaduzena() && novi_brojac==brojac){ std::cout<<"Zaduzena kod korisnika: "<<it1->second->ime<<" "<<it1->second->prezime<<std::endl;
     std::cout<<std::endl;}
      else  { 
        std::cout<<std::endl;
        break;
       }
       
       
    }
  }
  }/*
  void ZaduziKnjigu(int evidencijski_broj, int clanski_broj){
    for(auto it=mapa22.begin(); it!=mapa22.end(); it++){
      if(it->second->DaLiJeZaduzena()) continue;
    
 else{
     NadjiKnjigu(evidencijski_broj);
     auto k=NadjiKorisnika(clanski_broj);
     for(auto it=mapa22.begin(); it!=mapa22.end(); it++){
      auto a( it->second->ZaduziKnjigu(k));
      a.get();
     }
  }
}
}*/
};
int main ()
{

	return 0;
}