/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include <vector>
#include <algorithm>
struct Korisnik{
  
  std::string ime ;
  std::string prezime;
  std::string adresa;
  std::string telefon; 
  
};
class Knjiga{
  std::string naslov, ime_pisca, zanr;
   int godina_izdanja;
  Korisnik *kod_koga_je,*zaduzenje=nullptr;
  public:

  Knjiga(std::string naslov, std::string ime_pisca, std::string zanr, int godina_izdanja) : naslov(naslov), ime_pisca(ime_pisca), zanr(zanr), godina_izdanja(godina_izdanja),kod_koga_je(nullptr) {}
  std::string DajNaslov() const{return naslov;}
  std::string DajAutora() const{return ime_pisca;}
  std::string DajZanr() const {return zanr;}
  int DajGodinuIzdavanja() const {return godina_izdanja;}
 
  Korisnik* DajKodKogaJe()  {
    return zaduzenje;
    
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
typedef std::map<int, Korisnik*>mapa1;
typedef  std::pair<int, Korisnik*> par1;
typedef std::map<int, Knjiga*> mapa2;
typedef std::pair<int, Knjiga*> par2;
class Biblioteka{
 mapa1 mapa11;
 mapa2 mapa22;
 
Korisnik* korisnici;
Knjiga* knjige ;
  public:
  
~Biblioteka(){
  
  for(auto it=mapa11.begin(); it!=mapa11.end(); it++){
    delete(it->second);
  }
  
  for(auto it=mapa22.begin(); it!=mapa22.end(); it++){
    delete(it->second);
  }
};

  void RegistrirajNovogKorisnika(int clanski_broj, std::string ime, std::string prezime, std::string adresa, std::string telefon){
  for(auto it=mapa11.begin(); it!=mapa11.end(); it++){
    if(clanski_broj==it->first) throw std::logic_error("Korisnik vec postoji");
    
   
  }
  
       korisnici=new Korisnik{ime,prezime,adresa,telefon};
  mapa11.insert(par1(clanski_broj, korisnici)); 
    
  }
 
  void RegistrirajNovuKnjigu(int clanski_broj, std::string naslov, std::string ime_pisca, std::string zanr, int godina_izdanja){
  for(auto it=mapa22.begin(); it!=mapa22.end(); it++){
    if(clanski_broj==it->first) throw std::logic_error("Knjiga vec postoji");
  }
    
    knjige=new Knjiga( naslov, ime_pisca, zanr, godina_izdanja);
   
    mapa22.insert(par2(clanski_broj, knjige));
    
  
    
  }
  Korisnik NadjiKorisnika(int clanski_broj){
   
   for(auto it=mapa11.begin(); it!=mapa11.end(); it++) {
      if(it->first==clanski_broj ){
        return *(it->second);
      }
 }
  if(mapa11.find(clanski_broj)==mapa11.end()) throw std::logic_error("Korisnik nije nadjen");
  }
  
  Knjiga NadjiKnjigu(int evidencijski_broj){
    for(auto it=mapa22.begin(); it!=mapa22.end(); it++){
      if(it->first==evidencijski_broj ){
        return *(it->second);
      }
    }
    if(mapa22.find(evidencijski_broj)==mapa22.end()) throw std::logic_error("Knjiga nije nadjena");
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
  /*  int brojac = 0;
    for(auto it=mapa22.begin(); it!=mapa22.end(); it++){
      for(auto it1=mapa11.begin(); it1!=mapa11.end(); it1++){
        if(it->second->DaLiJeZaduzena()) brojac ++;
    }
    }
    int novi_brojac=0;*/
    for(auto it=mapa22.begin(); it!=mapa22.end(); it++){
      std::cout<<"Evidencijski broj: "<<it->first<<std::endl;
      std::cout<<"Naslov: "<<it->second->DajNaslov()<<std::endl;
      std::cout<<"Pisac: "<<it->second->DajAutora()<<std::endl;
      std::cout<<"Zanr: "<<it->second->DajZanr()<<std::endl;
      std::cout<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<std::endl;
   
    //if(it->second->DaLiJeZaduzena()) novi_brojac++;
      if (it->second->DaLiJeZaduzena() ){
        for(auto it1=mapa11.begin(); it1!=mapa11.end(); it1++){
        std::cout<<it1->second->ime;
        
          
        }
       }
      
       
       
    
  }
  }
  void ZaduziKnjigu(int evidencijski_broj, int clanski_broj){
    if(!(evidencijski_broj)) throw std::logic_error("Knjiga nije nadjena");
    if(!(clanski_broj)) throw std::logic_error("Korisnik nije nadjen");
    for(auto it=mapa22.begin(); it!=mapa22.end(); it++){
      if(it->second->DaLiJeZaduzena()) continue;
    
 else{
     NadjiKnjigu(evidencijski_broj);
     auto k=NadjiKorisnika(clanski_broj);
     for(auto it=mapa22.begin(); it!=mapa22.end(); it++){
       it->second->ZaduziKnjigu(k);
       
     }
  }
}
}
void RazduziKnjigu(int evidencijski_broj){
 if(!(evidencijski_broj)) throw std::logic_error("Knjiga nije nadjena");
  for(auto it=mapa22.begin(); it!=mapa22.end(); it++){
    if(!(it->second->DaLiJeZaduzena())) throw std::logic_error("Knjiga nije zaduzena");
    it->second->RazduziKnjigu();
  }
}
void PrikaziZaduzenja(int clanski_broj){
  //if(!(clanski_broj)) throw std::logic_error("Korisnik nije nadjen");
  for(auto it1=mapa11.begin(); it1!=mapa11.end(); it1++){
    if(it1->first==clanski_broj){
  for(auto it=mapa22.begin(); it!=mapa22.end(); it++){
  
      std::cout<<"Evidencijski broj: "<<it->first<<std::endl;
      std::cout<<"Naslov: "<<it->second->DajNaslov()<<std::endl;
      std::cout<<"Pisac: "<<it->second->DajAutora()<<std::endl;
      std::cout<<"Zanr: "<<it->second->DajZanr()<<std::endl;
      std::cout<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<std::endl;
      std::cout<<std::endl;
   
  }
  
}
}
}
};
int main(){
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
b.IzlistajKnjige();
}/*
int smain ()
{
  Biblioteka b;
int clanski_broj=0,n=0,evidencijski_broj=0,godina_izdanja=0;
std::string ime, prezime, adresa, telefon,naslov,ime_pisca,zanr;
for(;;){
  std::cout<<"Unesite: 1 za registrovanje korisnika, 2 za registorovanje knjige, 3 za pronalazenje korisnika, 4 za pronalazanje knjige, 5 za ispis svih registriranih korisnika, 6 za ispis svih registriranih knjiga, 7 za zaduzenje knjige, 8 za razduzenje knjige, 9 za prikaz zaduzenja, 0 za kraj";
  std::cin>>n;
  if(n==1){
    std::cout<<"Unesite clanski broj korisnika: ";
    std::cin>>clanski_broj;
    std::cout<<"Unesite ime korisnika: ";
    std::getline(std::cin, ime);
    std::cout<<"Unesite prezime korisnika: ";
    std::getline(std::cin, prezime);
    std::cout<<"Unesite adresu korisnika ";
    std::getline(std::cin, adresa);
    std::cout<<"Unesite telefon korisnika: ";
    std::getline(std::cin, telefon);
    b.RegistrirajNovogKorisnika(clanski_broj,ime,prezime,adresa,telefon);
  }
  if(n==2){
    std::cout<<"Unesite evidencijski broj knjige: ";
    std::cin>>evidencijski_broj;
    std::cout<<"Unesite naslov knjige: ";
    std::getline(std::cin, naslov);
    std::cout<<"Unesite ime pisca: ";
    std::getline(std::cin, ime_pisca);
    std::cout<<"Unesite zanr: ";
    std::getline(std::cin, zanr);
    std::cout<<"Unesite godina izdanja: ";
    std::cin>>godina_izdanja;
    b.RegistrirajNovuKnjigu(evidencijski_broj,naslov,ime_pisca,zanr,godina_izdanja);
  }
  if(n==3){
    std::cout<<"Unesite clanski broj korisnika kojeg zelite pronaci: ";
    std::cin>>clanski_broj;
    std::cout<<b.NadjiKorisnika(clanski_broj).ime;
  }
  if(n==4){
    std::cout<<"Unesite evidencijski broj knjige koju zelite pronaci: ";
    std::cin>>evidencijski_broj;
    std::cout<<b.NadjiKnjigu(evidencijski_broj).DajNaslov();
  }
  if(n==5){
    b.IzlistajKorisnike();
  }
  if(n==6){
    b.IzlistajKnjige();
  }
  if(n==7){
    std::cout<<"Unesite evidencijski broj knjige koju zelite zaduziti: ";
    std::cin>>evidencijski_broj;
    std::cout<<"Unesite clanski broj korisnika: ";
    std::cin>>clanski_broj;
    b.ZaduziKnjigu(evidencijski_broj,clanski_broj);
  }
  if(n==8){
    std::cout<<"Unesite evidencijski broj knjige koju zelite razduziti: ";
    std::cin>>evidencijski_broj;
    b.RazduziKnjigu(evidencijski_broj);
  }
  if(n==9){
    std::cout<<"Unesite clanski broj korisnika: ";
    std::cin>>clanski_broj;
    b.PrikaziZaduzenja(clanski_broj);
  }
  if(n==0){
    std::cout<<"Dovidjenja!";
    break;
  } 
}
	return 0;
}*/