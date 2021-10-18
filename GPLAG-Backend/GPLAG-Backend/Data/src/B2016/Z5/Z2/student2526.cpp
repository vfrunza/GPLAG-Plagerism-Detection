/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <map>
#include <new>
#include <string>
#include <memory>
#include <utility>
#include <stdexcept>
struct Korisnik{
    std::string ime,prezime,adresa,telefon;
};
class Knjiga{
    std::string naslov,ime_pisca,zanr;
    int godina;
    Korisnik *zaduzio;
    public:
    Knjiga(std::string naslov1,std::string ime_pisca1,std::string zanr1,
    int godina1):naslov(naslov1),ime_pisca(ime_pisca1),zanr(zanr1),godina(godina1),zaduzio(nullptr){};
    std::string  DajNaslov() const { return naslov;}
    std::string  DajAutora() const { return ime_pisca;}
    std::string  DajZanr() const {return zanr;}
    Korisnik* DajKodKogaJe() const {return zaduzio;}
    int DajGodinuIzdavanja() const {return godina;}
    void ZaduziKnjigu(Korisnik &papak){ zaduzio=&papak;}
    void RazduziKnjigu(){ zaduzio=nullptr;}
    bool DaLiJeZaduzena(){ return !(zaduzio==nullptr);}
};
class Biblioteka{
    std::map<int,std::shared_ptr<Korisnik>> korisnici;
    std::map<int,std::shared_ptr<Knjiga>> knjige;
    public:
    Biblioteka(){};
    void RegistrirajNovogKorisnika(int clanskibr,std::string ime,std::string prezime,std::string adresa,std::string telefon);
    void RegistrirajNovuKnjigu( int br,std::string naslov, std::string ime_pisca, std::string zanr, int godina_izdavanja);
    Korisnik &NadjiKorisnika(int br);
    Knjiga &NadjiKnjigu(int br);
    void IzlistajKorisnike () const;
    void IzlistajKnjige() const;
    void ZaduziKnjigu(int evbr,int clbr);
    void RazduziKnjigu(int evbr);
     void PrikaziZaduzenja(int clbr) const;
     ~Biblioteka()=default;
    Biblioteka(const Biblioteka &bibl);
    Biblioteka(Biblioteka &&bibl);
    Biblioteka &operator =(const Biblioteka &bibl);
    Biblioteka &operator =(Biblioteka &&bibl);
};
Biblioteka:: Biblioteka(const Biblioteka &bibl){
    try{
        auto it=bibl.korisnici.begin();
        while(it!=bibl.korisnici.end()){
            korisnici.insert(std::make_pair((*it).first,std::make_shared<Korisnik>(*((*it).second))));
            it++;
        }
        auto it2=bibl.knjige.begin();
        while(it2!=bibl.knjige.end()){
            knjige.insert(std::make_pair((*it2).first, std::make_shared<Knjiga>(*((*it2).second))));
            if (it2->second->DaLiJeZaduzena()){
                RazduziKnjigu(it2->first);
                int clanskibr;
                auto it3(korisnici.begin());
                auto tmp(it2->second->DajKodKogaJe());
                while(it3!=korisnici.end()){
                    if(it3->second->ime==tmp->ime&&it3->second->prezime==tmp->prezime&&it3->second->adresa==tmp->adresa&&it3->second->telefon==tmp->telefon){
                    ZaduziKnjigu(it2->first,it3->first); break;}
                    it3++;
                }
            }
            it2++;
        }
    }
    catch(...){
        throw ;
    }
}
Biblioteka& Biblioteka:: operator =(const Biblioteka &bibl){
    try{
        auto it=bibl.korisnici.begin();
        while(it++!=bibl.korisnici.end()){
            korisnici.insert(std::make_pair((*it).first,std::make_shared<Korisnik>(*((*it).second))));
        }
        auto it2=bibl.knjige.begin();
        while(it2++!=bibl.knjige.end()){
            knjige.insert(std::make_pair((*it2).first, std::make_shared<Knjiga>(*((*it2).second))));
                        if (it2->second->DaLiJeZaduzena()){
                RazduziKnjigu(it2->first);
                auto it3(korisnici.begin());
                auto tmp(it2->second->DajKodKogaJe());
                while(it3!=korisnici.end()){
                    if(it3->second->ime==tmp->ime&&it3->second->prezime==tmp->prezime&&it3->second->adresa==tmp->adresa&&it3->second->telefon==tmp->telefon){
                    ZaduziKnjigu(it2->first,it3->first); break;}
                    it3++;
                }
            }
        }
    }
    catch(...){
        throw ;
    }
    return *this;
}
Biblioteka& Biblioteka::operator =(Biblioteka &&bibl){
    if(this!=&bibl){
        korisnici=bibl.korisnici;
        knjige=bibl.knjige;
        auto it=bibl.knjige.begin();
        while(it!=bibl.knjige.end()){ (*it).second=nullptr; it++;}
        auto it2=bibl.korisnici.begin();
        while(it2!=bibl.korisnici.end()){(*it2).second=nullptr; it2++;}
    }
    return *this;
}
Biblioteka:: Biblioteka(Biblioteka &&bibl){
     if(this!=&bibl){
        korisnici=bibl.korisnici;
        knjige=bibl.knjige;
        auto it=bibl.knjige.begin();
        while(it!=bibl.knjige.end()) {(*it).second=nullptr; it++;}
        auto it2=bibl.korisnici.begin();
        while(it2!=bibl.korisnici.end()){ (*it2).second=nullptr; it2++;}
    }
}
void Biblioteka::RegistrirajNovogKorisnika(int clanskibr,std::string ime,std::string prezime,std::string adresa,std::string telefon){
    auto it(korisnici.find(clanskibr));
    if(it!=korisnici.end()) throw std::logic_error("Korisnik vec postoji");
    try{
    
    korisnici.insert(std::make_pair(clanskibr,std::make_shared<Korisnik>(Korisnik{ime,prezime,adresa,telefon})));
    }
    catch(...){
        
        throw;
    }
}
 void Biblioteka::RegistrirajNovuKnjigu( int br,std::string naslov, std::string ime_pisca, std::string zanr, int godina_izdavanja){
     auto it(knjige.find(br));
     if(it!=knjige.end()) throw std::logic_error("Knjiga vec postoji");
     try{
     knjige.insert(std::make_pair(br,std::make_shared<Knjiga>(naslov,ime_pisca,zanr,godina_izdavanja)));
     } catch(...){
         throw;
     }
 }
 Korisnik& Biblioteka:: NadjiKorisnika(int br){
     auto it(korisnici.find(br));
     if(it==korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
     return *((*it).second);
 }
 Knjiga & Biblioteka::NadjiKnjigu(int br){
     auto it(knjige.find(br));
     if(it==knjige.end()) throw std::logic_error("Knjiga nije nadjena");
     return *((*it).second);
 }
 void Biblioteka::IzlistajKorisnike() const{
     auto it=korisnici.begin();
     while(it!=korisnici.end()){
         std::cout<<"Clanski broj: "<<(*it).first<<std::endl;
         std::cout<<"Ime i prezime: "<<(*it).second->ime<<" "<<(*it).second->prezime<<std::endl;
         std::cout<<"Adresa: "<<(*it).second->adresa<<std::endl;
         std::cout<<"Broj telefona: "<<(*it).second->telefon<<std::endl<<std::endl;
         it++;
     }
 }
 void Biblioteka::IzlistajKnjige() const{
     auto it=knjige.begin();
     while(it!=knjige.end()){
         std::cout<<"Evidencijski broj: "<<(*it).first<<std::endl;
         std::cout<<"Naslov: "<<(*it).second->DajNaslov()<<std::endl;
         std::cout<<"Pisac: "<<(*it).second->DajAutora()<<std::endl;
         std::cout<<"Zanr: "<<(*it).second->DajZanr()<<std::endl;
         std::cout<<"Godina izdavanja: "<<(*it).second->DajGodinuIzdavanja()<<std::endl;
         if((*it).second->DaLiJeZaduzena()){
             auto kor=*((*it).second->DajKodKogaJe());
             std::cout<<"Zaduzena kod korisnika: "<<kor.ime<<" "<<kor.prezime<<std::endl;
         }
         std::cout<<std::endl;
         it++;
     }
 }
 void Biblioteka::ZaduziKnjigu(int evbr,int clbr){
     auto it(knjige.find(evbr)); auto it2(korisnici.find(clbr));
     if(it==knjige.end()) throw std::logic_error("Knjiga nije nadjena");
     if(it2==korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
     if((*it).second->DaLiJeZaduzena()) throw std::logic_error("Knjiga vec zaduzena");
     (*it).second->ZaduziKnjigu(*((*it2).second));
 }
 void Biblioteka::RazduziKnjigu(int evbr){
     auto it(knjige.find(evbr));
     if(it==knjige.end()) throw std::logic_error("Knjiga nije nadjena");
     if((*it).second->DaLiJeZaduzena()) (*it).second->RazduziKnjigu();
     else throw std::logic_error("Knjiga nije zaduzena");
 }
  void Biblioteka::PrikaziZaduzenja(int clbr) const{
      auto it(korisnici.find(clbr));
      if(it==korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
      auto it2=knjige.begin();
      bool ima=false;
      while(it2!=knjige.end()){
          if((*it2).second->DaLiJeZaduzena()){
              auto kor=*((*it2).second->DajKodKogaJe());
              if(kor.ime==(*it).second->ime&&kor.prezime==(*it).second->prezime&&kor.adresa==(*it).second->adresa&&kor.telefon==(*it).second->telefon){
                  ima=true;
                  std::cout<<"Evidencijski broj: "<<(*it2).first<<std::endl;
                  std::cout<<"Naslov: "<<(*it2).second->DajNaslov()<<std::endl;
                  std::cout<<"Pisac: "<<(*it2).second->DajAutora()<<std::endl;
                  std::cout<<"Zanr: "<<(*it2).second->DajZanr();
                  std::cout<<"Godina izdavanja: "<<(*it2).second->DajGodinuIzdavanja()<<std::endl<<std::endl;
              }
          }
          it2++;
      }
      if(!ima) std::cout<<"Nema zaduzenja za tog korisnika!"<<std::endl;
  }
 

int main ()
{
    Biblioteka bib5;
bib5.RegistrirajNovogKorisnika(1, "Niko", "Nikic", "Zmaja od Bosne bb", "123 456");
bib5.RegistrirajNovuKnjigu(2, "Vlak u snijegu", "Mato Lovrak", "Roman", 1931);
std::cout << bib5.NadjiKnjigu(2).DajNaslov();
	return 0;
}