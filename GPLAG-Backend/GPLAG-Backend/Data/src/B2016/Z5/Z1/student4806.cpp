/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <stdexcept>

struct Korisnik {
    std::string ime;
    std::string prezime;
    std::string adresa;
    std::string telefon;
    //Korisnik()=default;
};

class Knjiga
{
    std::string naslov,ime_pisca,zanr;
    int godina_izdavanja;
    Korisnik *zaduzeno=nullptr;
public:
    Knjiga(std::string naslov,std::string ime_pisca,std::string zanr,int godina_izdavanja):naslov(naslov),ime_pisca(ime_pisca),zanr(zanr),godina_izdavanja(godina_izdavanja){}
    std::string DajNaslov() const {
        return naslov;
    }
    std::string DajAutora() const {
        return ime_pisca;
    }
    std::string DajZanr() const {
        return zanr;
    }
    int DajGodinuIzdavanja() const {
        return godina_izdavanja;
    }
    Korisnik *DajKodKogaJe()const {
        return zaduzeno;
    }
    void ZaduziKnjigu(Korisnik &korisnik) {
        //zaduzeno=new Korisnik(korisnik);
        zaduzeno=&korisnik;
    }
    void RazduziKnjigu() {
       // delete zaduzeno;
        zaduzeno=nullptr;
    }
    bool DaLiJeZaduzena() {
        if(zaduzeno==nullptr) return false;
        return true;
    }
};
class Biblioteka
{
    std::map<int,Korisnik*> korisnici;
    std::map<int,Knjiga*> knjige;
    public:
    Biblioteka()=default;
    Biblioteka(const Biblioteka &b);
    Biblioteka(Biblioteka &&b);
    ~Biblioteka(){
          for(auto it=korisnici.begin(); it!=korisnici.end(); it++) {
              delete it->second;
          }
          for(auto it=knjige.begin(); it!=knjige.end(); it++) {
              delete it->second;
          }
    }
    void RegistrirajNovogKorisnika(int clanski_broj,std::string ime,std::string prezime,std::string adresa,std::string broj_telefona);
    void RegistrirajNovuKnjigu(int evidecijski_broj,std::string ime_pisca,std::string naslov,std::string zanr,int godina_izdavanja);
    Korisnik &NadjiKorisnika(int clanski_broj);
    Knjiga &NadjiKnjigu(int evidecijski_broj);
    void IzlistajKorisnike() const;
    void IzlistajKnjige() const;
    void ZaduziKnjigu(int evidecijski_broj,int clanski_broj);
    void RazduziKnjigu(int evidecijski_broj);
    void PrikaziZaduzenja(int clanski_broj);
};

Biblioteka::Biblioteka(const Biblioteka &b)
{
    for(auto it=b.korisnici.begin(); it!=b.korisnici.end(); it++) {
        Korisnik k;
        k=*(it->second);
        Korisnik *pok(new Korisnik(k));
        korisnici.insert(std::make_pair(it->first,pok));
    }
    for(auto it=b.knjige.begin(); it!=b.knjige.end(); it++) {
        Knjiga k(*(it->second));
        Knjiga *pok(new Knjiga(k));
        knjige.insert(std::make_pair(it->first,pok));
    }
}

void Biblioteka::RegistrirajNovogKorisnika(int clanski_broj,std::string ime,std::string prezime,std::string adresa,std::string broj_telefona)
{
    auto it(korisnici.find(clanski_broj));
    if(it == korisnici.end()) {
        Korisnik *pok;
        Korisnik k;
        k.ime=ime;
        k.prezime=prezime;
        k.adresa=adresa;
        k.telefon=broj_telefona;
        pok=new Korisnik(k);
        korisnici.insert(std::make_pair(clanski_broj,pok));
    } else {
        throw std::logic_error("Korisnik vec postoji");
    }
}

void Biblioteka::RegistrirajNovuKnjigu(int evidencijski_broj,std::string ime_pisca,std::string naslov,std::string zanr,int godina_izdavanja)
{
    auto it(knjige.find(evidencijski_broj));
    if(it == knjige.end()) {
        Knjiga *pok;
        pok=new Knjiga(ime_pisca,naslov,zanr,godina_izdavanja);
        knjige.insert(std::make_pair(evidencijski_broj,pok));
    } else {
        throw std::logic_error("Knjiga vec postoji");
    }
}

Korisnik &Biblioteka::NadjiKorisnika(int clanski_broj)
{
    auto it(korisnici.find(clanski_broj));
    if(it == korisnici.end()) {
        throw std::logic_error("Korisnik nije nadjen");
    } else {
        Korisnik &poki(*(it->second));
        return poki;
    }
}

Knjiga &Biblioteka::NadjiKnjigu(int evidencijski_broj)
{
    auto it(knjige.find(evidencijski_broj));
    if(it == knjige.end()) {
        throw std::logic_error("Knjiga nije nadjena");
    } else {
        Knjiga &poki(*(it->second));
        return poki;
    }
}

void Biblioteka::ZaduziKnjigu(int evidencijski_broj,int clanski_broj)
{
    auto it(knjige.find(evidencijski_broj));
    auto it1(korisnici.find(clanski_broj));
    if(it == knjige.end()) {
        throw std::logic_error("Knjiga nije nadjena");
    } else if(it1==korisnici.end()) {
        throw std::logic_error("Korisnik nije nadjen");
    } else {
        if(it->second->Knjiga::DaLiJeZaduzena()) throw std::logic_error("Knjiga vec zaduzena");
    }
    Korisnik &poki(*(it1->second));
    it->second->Knjiga::ZaduziKnjigu(poki);
}


void Biblioteka::RazduziKnjigu(int evidencijski_broj)
{
     auto it(knjige.find(evidencijski_broj));
      if(it == knjige.end()) {
        throw std::logic_error("Knjiga nije nadjena");
    }else if(it->second->Knjiga::DaLiJeZaduzena()==false)
    {
        throw std::logic_error("Knjiga nije zaduzena");
    }else
    {
     it->second->Knjiga::RazduziKnjigu();   
    }
}

 void Biblioteka::IzlistajKorisnike() const{
     for(auto it = korisnici.begin(); it != korisnici.end(); it++){
      std::cout << "Clanski broj: " << it->first <<std::endl;
      std::cout<<"Ime i prezime: "<< it->second->Korisnik::ime<<" "<<it->second->Korisnik::prezime<<std::endl;
      std::cout<<"Adresa: "<<it->second->Korisnik::adresa<<std::endl;
      std::cout<<"Broj telefona: "<<it->second->Korisnik::telefon<<std::endl;
        std::cout<<std::endl;
     }
 }
 
 void Biblioteka::IzlistajKnjige() const{
     for(auto it = knjige.begin(); it != knjige.end(); it++){
      std::cout << "Evidencijski broj: " << it->first <<std::endl;
      std::cout<<"Naslov: "<< it->second->Knjiga::DajNaslov()<<std::endl;
      std::cout<<"Pisac: "<<it->second->Knjiga::DajAutora()<<std::endl;
      std::cout<<"Zanr: "<<it->second->Knjiga::DajZanr()<<std::endl;
        std::cout<<"Godina izdavanja: "<<it->second->Knjiga::DajGodinuIzdavanja()<<std::endl;
        if(it->second->Knjiga::DaLiJeZaduzena()==true){
            std::cout<<"Zaduzena kod korisnika: "<<it->second->Knjiga::DajKodKogaJe()->ime<<" "<<it->second->Knjiga::DajKodKogaJe()->prezime;
        }
        std::cout<<std::endl;
     }
     
     
 }
 
 void Biblioteka::PrikaziZaduzenja(int clanski_broj){
      for(auto it = korisnici.begin(); it != korisnici.end(); it++){
          if(it->first==clanski_broj){
           for(auto it1 = knjige.begin(); it1 != knjige.end(); it1++){
               Korisnik * poki((it1->second->Knjiga::DajKodKogaJe()));
               if(poki==it->second){
      std::cout << "Evidencijski broj: " << it1->first <<std::endl;
      std::cout<<"Naslov: "<< it1->second->Knjiga::DajNaslov()<<std::endl;
      std::cout<<"Pisac: "<<it1->second->Knjiga::DajAutora()<<std::endl;
      std::cout<<"Zanr: "<<it1->second->Knjiga::DajZanr()<<std::endl;
        std::cout<<"Godina izdavanja: "<<it1->second->Knjiga::DajGodinuIzdavanja()<<std::endl;
          }
      }      
          }
      }
 }
 
 int main(){
     Biblioteka bib8;
bib8.RegistrirajNovogKorisnika(1, "Niko", "Nikic", "Zmaja od Bosne bb", "123 456");
bib8.RegistrirajNovuKnjigu(1, "Vlak u snijegu2", "Mato Lovrak2", "Roman2", 1941);
bib8.RegistrirajNovuKnjigu(2, "Vlak u snijegu", "Mato Lovrak", "Roman", 1931);
bib8.ZaduziKnjigu(2, 1);
bib8.IzlistajKnjige();
     return 0;
 }