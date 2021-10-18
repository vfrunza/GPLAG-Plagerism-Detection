/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include <vector>
#include <memory>

struct Korisnik{
    std::string ime, prezime, adresa, telefon; 
};

class Knjiga{
  std::string naslov, pisac, zanr;
  int god_izdavanja;
  Korisnik* pok=nullptr;
  public:
    explicit Knjiga(const std::string &naslov, const std::string &pisac, const std::string &zanr, const int &god_izdavanja){
    Knjiga::naslov=naslov; Knjiga::pisac=pisac; Knjiga::zanr=zanr; Knjiga::god_izdavanja=god_izdavanja;
  }
  std::string DajNaslov(){ return naslov;}
  std::string DajAutora(){ return pisac;}
  std::string DajZanr(){return zanr;}
  int DajGodinuIzdavanja() {return god_izdavanja;}
  Korisnik* DajKodKogaJe(){ if(pok!=nullptr) return pok;}
  
  void ZaduziKnjigu(Korisnik &korisnik){
      pok=&korisnik;
  }
  void RazduziKnjigu(){
      Knjiga::pok=nullptr;
  }
  bool DaLiJeZaduzena(){
      if(Knjiga::pok==nullptr) return false;
      return true;
  }
};

class Biblioteka{
    std::map<int,std::shared_ptr<Korisnik>> mapa_korisnika;
    std::map<int,std::shared_ptr<Knjiga>> mapa_knjiga;
    
    public:
    void RegistrirajNovogKorisnika(int evbroj, std::string ime, std::string prezime, std::string adresa, std::string telefon){
        if(mapa_korisnika.count(evbroj)==1) throw std::logic_error("Korisnik vec postoji");
        Korisnik kor;
        kor.ime=ime; kor.prezime=prezime; kor.adresa=adresa; kor.telefon=telefon;
        auto k=std::make_shared<Korisnik>(kor);
        mapa_korisnika.insert(std::make_pair(evbroj,k));
    }
    void RegistrirajNovuKnjigu(int evbroj, std::string naslov, std::string pisac, std::string zanr, int godina){
      if(mapa_knjiga.count(evbroj)==1) throw std::logic_error("Knjiga vec postoji");
    
        auto knjigica=std::make_shared<Knjiga>(naslov, pisac, zanr, godina);
        mapa_knjiga.insert(std::make_pair(evbroj,knjigica));
    } 
  
    Korisnik& NadjiKorisnika(int clbroj){
      std::map<int,std::shared_ptr<Korisnik>>::iterator i=mapa_korisnika.find(clbroj);
      if(i==mapa_korisnika.end()){
        throw std::logic_error("Korisnik nije nadjen");
      }
      else
        return *(i->second);
    }
   
    Knjiga& NadjiKnjigu(int broj){
      std::map<int, std::shared_ptr<Knjiga>>::iterator i=mapa_knjiga.find(broj);
      if(i==mapa_knjiga.end()){
        throw std::logic_error("Knjiga nije nadjena");
      }
      else {
        return *(i->second);
    }
    }
    
     void IzlistajKorisnike(){
       for(auto i=mapa_korisnika.begin();i!=mapa_korisnika.end();i++){
      std::cout<<"\nClanski broj: "<<i->first;
      std::cout<<"\nIme i prezime: "<<i->second->ime<<" "<<i->second->prezime;
      std::cout<<"\nAdresa: "<<i->second->adresa;
      std::cout<<"\nBroj telefona: "<<i->second->telefon;
      std::cout<<"\n";
       }
    }

     void IzlistajKnjige(){
       for(auto i=mapa_knjiga.begin();i!=mapa_knjiga.end();i++){
      std::cout<<"\nEvidencijski broj: "<<i->first;
      std::cout<<"\nNaslov: "<<i->second->DajNaslov();
      std::cout<<"\nPisac: "<<i->second->DajAutora();
      std::cout<<"\nZanr: "<<i->second->DajZanr();
      std::cout<<"\nGodina izdavanja: "<<i->second->DajGodinuIzdavanja();
      if(i->second->DaLiJeZaduzena()){
        std::cout<<"\nZaduzena kod korisnika: "<<i->second->DajKodKogaJe()->ime<<" "<<i->second->DajKodKogaJe()->prezime;
      }
      std::cout<<"\n";
    } 
  }
     void PrikaziZaduzenja(int clbroj){
       std::map<int,std::shared_ptr<Korisnik>>::iterator i=mapa_korisnika.find(clbroj);
       if(i==mapa_korisnika.end()) throw std::logic_error("Korisnik nije nadjen");
       bool ima=false;
       for(auto it=mapa_knjiga.begin();it!=mapa_knjiga.end();it++){
         if(mapa_korisnika[clbroj]==it->second->DajKodKogaJe()) ima=true;
       }
       if(!ima) throw std::logic_error("Nema zaduzenja za tog korisnika!");
       IzlistajKnjige();
     }
};

int main ()
{
  int opcija;
 Biblioteka bib;
 while(opcija!=6){
  std::cout<<"\nIzaberite: 1.Registriraj Novog Korisnika; 2.Registriraj Novu Knjigu; 3.Nadji Knjigu; 4.Izlistaj Korisnike; 5.Izlistaj Knjige; 6.Kraj\n";
  std::cin>>opcija;
  if(opcija==1){
    std::string ime, prezime, adresa, telefon;
    int evbroj;
    std::cout<<"Unesite clanski broj: ";
    std::cin>>evbroj;
    std::cout<<"\nUnesite ime: ";
    std::cin>>ime;
    std::cout<<"\nUnesite prezime: ";
    std::cin>>prezime;
    std::cout<<"\nUnesite adresu: ";
    std::cin>>adresa;
    std::cout<<"\nUnesite telefon: ";
    std::cin>>telefon;
try{
    bib.RegistrirajNovogKorisnika(evbroj,ime,prezime,adresa,telefon);
}catch(std::logic_error eror){ std::cout<<eror.what();}
  }
  else if(opcija==2){
    int evbroj, god_izdavanja;
    std::string naslov,pisac,zanr;
    std::cout<<"Unesite evidencijski broj: ";
    std::cin>>evbroj;
    std::cout<<"Unesite naslov knjige: ";
    std::cin>>naslov;
    std::cout<<"\nUnesite autora: ";
    std::cin>>pisac;
    std::cout<<"\nUnesite zanr: ";
    std::cin>>zanr;
    std::cout<<"\nUnesite godinu izdavanja: ";
    std::cin>>god_izdavanja;
 try{
    bib.RegistrirajNovuKnjigu(evbroj, naslov,pisac,zanr,god_izdavanja);
 }catch(std::logic_error eror){std::cout<<eror.what();}
  }
  else if(opcija==3){
    int evbroj;
    std::cout<<"Unesite evidencijski broj knjige: ";
    std::cin>>evbroj;
    try{
    auto knj=bib.NadjiKnjigu(evbroj);
    std::cout<<knj.DajNaslov();
    }catch(std::logic_error eror){std::cout<<eror.what();}
  }
  else if(opcija==4){
    bib.IzlistajKorisnike();
  }
  else if(opcija==5){
    bib.IzlistajKnjige();
  }
 }
	return 0;
}