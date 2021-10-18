/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <memory>
#include <algorithm>
    struct Korisnik {
        std::string ime;
        std::string prezime;
        std::string adresa;
        std::string telefon;
        
    };
    
    class Knjiga {
       std::string naslov;
      std::string ime;
      std::string zanr;
      int godina;
      std::shared_ptr<Korisnik> korisnici;
        public:
        Knjiga(std::string naslov1,std::string ime1, std::string zanr1, int godina1) :naslov(naslov1), ime(ime1),zanr(zanr1),godina(godina1) { korisnici = nullptr;}
       std::string  DajNaslov() const { return naslov; }
       std::string  DajAutora() const { return ime; }
       std::string  DajZanr() const { return zanr; }
       int DajGodinuIzdavanja() const { return godina; }
       std::shared_ptr<Korisnik> DajKodKogaJe() const { return  korisnici; }
       bool DaLiJeZaduzena() const { if (korisnici == nullptr) return false; return true; }
      void ZaduziKnjigu(Korisnik &korisnik1) { korisnici =std::make_shared<Korisnik>korisnik1; }
      void RazduziKnjigu() { korisnici = nullptr; }
    };

    class Biblioteka {
      std::map<int,std::shared_ptr<Korisnik>> korisnici;
      std::map<int,std::shared_ptr<Knjiga>> knjige;
      public:
      Biblioteka() {   }
      Biblioteka(const Biblioteka &a) { 
      }
      
      ~Biblioteka() {      }
      void RegistrirajNovogKorisnika(int broj,std::string ime1,std::string prezime1,std::string adresa1, std::string telefon1 ) {
        if (!korisnici.count(broj)) {
          try {
          korisnici[broj] = std::make_shared<Korisnik>();
          auto it(korisnici.find(broj));
          it->second->ime = ime1;
          it->second->prezime = prezime1;
          it->second->adresa = adresa1;
          it->second->telefon = telefon1;
          }
           catch(...) {
           } 
          }
        
        else {
          throw std::logic_error("Korisnik vec postoji");
        }
      }
      
      void RegistrirajNovuKnjigu(int broj,std::string naslov1,std::string ime1,std::string zanr1, int godina1) {
        
        if (!knjige.count(broj)) {
         try {
          knjige[broj] = std::make_shared<Knjiga>(naslov1,ime1,zanr1,godina1);
         }
        catch(...) {
        }
        }
       
        else {
          throw std::logic_error("Knjiga vec postoji");
        }
      }
      Korisnik &NadjiKorisnika(int broj) const {
        auto it(korisnici.find(broj));
       if (!korisnici.count(broj)) throw std::logic_error("Korisnik nije nadjen");
          return *it->second;
      }
      Knjiga &NadjiKnjigu(int broj) const {
        auto it(knjige.find(broj));
       if (!knjige.count(broj)) throw std::logic_error("Knjiga nije nadjena");
          return *it->second;
      }
       
      void ZaduziKnjigu( int broj, int broj2 ) {
           if (!knjige.count(broj)) throw std::logic_error("Knjiga nije nadjena");
           if ( !korisnici.count(broj2)) throw std::logic_error("Korisnik nije nadjen");
           if (knjige[broj]->DaLiJeZaduzena()) throw std::logic_error("Knjiga vec zaduzena");
           knjige[broj]->ZaduziKnjigu(*korisnici[broj2]);
       }
       
       void RazduziKnjigu( int broj ) {
           if (!knjige.count(broj)) throw std::logic_error("Knjiga nije nadjena");
           if (!(knjige[broj]->DaLiJeZaduzena())) throw std::logic_error("Knjiga nije zaduzena");
               knjige[broj]->RazduziKnjigu();

         
       }
       void PrikaziZaduzenja (int broj ) {
         if ( !korisnici.count(broj)) throw std::logic_error("Korisnik nije nadjen");
                for ( auto it = knjige.begin(); it != knjige.end(); it++) {
                  if ( it->second->DajKodKogaJe() == korisnici[broj]) {
                     std::cout<<std::endl<<"Evidencijski broj: "<<it->first<<std::endl;
                     std::cout<<"Naslov: "<<it->second->DajNaslov()<<std::endl;
                     std::cout<<"Pisac: "<<it->second->DajAutora()<<std::endl;
                     std::cout<<"Zanr: "<<it->second->DajZanr()<<std::endl;
                     std::cout<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<std::endl;
                  }
                
                }
       }
      
      void IzlistajKorisnike() const {
        for ( auto it = korisnici.begin(); it != korisnici.end(); it++) {
          std::cout<<"Clanski broj: "<<it->first<<std::endl;
          std::cout<<"Ime i prezime: "<<it->second->ime<<" "<<it->second->prezime<<std::endl;
          std::cout<<"Adresa: "<<it->second->adresa<<std::endl;
          std::cout<<"Broj telefona: "<<it->second->telefon<<std::endl;
        }
      }
         void IzlistajKnjige() const {
        for ( auto it = knjige.begin(); it != knjige.end(); it++) {
          std::cout<<std::endl<<"Evidencijski broj: "<<it->first<<std::endl;
          std::cout<<"Naslov: "<<it->second->DajNaslov()<<std::endl;
          std::cout<<"Pisac: "<<it->second->DajAutora()<<std::endl;
          std::cout<<"Zanr: "<<it->second->DajZanr()<<std::endl;
          std::cout<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<std::endl;
          if (it->second->DaLiJeZaduzena()) {
            std::cout<<"Zaduzena kod korisnika: "<<it->second->DajKodKogaJe()->ime<<" "<<it->second->DajKodKogaJe()->prezime<<std::endl;
          }
        }
      }
      
    };

int main ()
{
  Biblioteka b;
  for (;;) {
    
    std::cout<<"Unesite 1 za RegistrirajNovogKorisnika, 2 za RegistrirajNovuKnjigu , 3 za NadjiKorisnika, 4 za NadjiKnjigu , 5 za ZaduziKnjigu"<<std::endl;
    std::cout<<" 6 za RazduziKnjigu, 7 za PrikaziZaduzenja, 8 za IzlistajKnjige, 9 za IzlistajKorisnike i 10 za kraj"<<std::endl;
    int a ;
    std::cin>>a;
    if ( a == 2 )   b.RegistrirajNovuKnjigu(10,"Lel","Ja","Riba",1900);
    else if ( a==1 ) b.RegistrirajNovogKorisnika(20,"Hasanaga","Pasic","bb","062 222 111"); 
    else if ( a==3)   std::cout<<b.NadjiKorisnika(20).ime<<std::endl;
    else if ( a== 4)    std::cout<<b.NadjiKnjigu(10).DajNaslov()<<std::endl;
    else if ( a == 5) b.ZaduziKnjigu(10,20);
    else if (a==6) b.RazduziKnjigu(10);
    else if ( a == 7) b.PrikaziZaduzenja(20);
    else if ( a==8) b.IzlistajKnjige();
    else if ( a == 9) b.IzlistajKorisnike();
    else if ( a== 10) break;
  }
	return 0;
}