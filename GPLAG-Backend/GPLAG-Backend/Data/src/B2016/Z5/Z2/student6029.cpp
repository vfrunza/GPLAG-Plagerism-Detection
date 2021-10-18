#include <utility>
#include <stdexcept>
#include <map>
#include <iostream>
#include <string>
#include <memory>

struct Korisnik{
    std::string ime;
    std::string prezime;
    std::string adresa;
    std::string telefon;
    friend class Knjiga;
    friend class Biblioteka;
};

class Knjiga {
    std::string naslov;
    std::string pisac;
    int godina;
    std::string zanr;
    Korisnik* p;
    public:
    Knjiga (std::string n,std::string pi,std::string z,int g){
        naslov=n; pisac=pi; zanr=z; godina=g; p=nullptr;
    }
    std::string DajNaslov() const { return naslov; }
    std::string DajZanr () const { return zanr; }
    std::string DajAutora() const { return pisac; }
    int DajGodinuIzdavanja() const { return godina; }
    Korisnik* DajKodKogaJe() const { return p; }
    void ZaduziKnjigu(Korisnik &k){ this->p=&k; }
    void RazduziKnjigu(){ this->p=nullptr; }
    bool DaLiJeZaduzena() const {
        if(this->p==nullptr)
        return false;
        return true;
    }
    friend class Biblioteka;
};

class Biblioteka{
    std::map<int,std::shared_ptr<Korisnik>> Korisnici;
    std::map<int,std::shared_ptr<Knjiga>> Citabi;
    public:
    Biblioteka()=default;
   /* ~Biblioteka(){
        for(auto it=Korisnici.begin();it!=Korisnici.end();it++){
        auto p=it->second;
        delete p;
        }
        for(auto it=Citabi.begin();it!=Citabi.end();it++){
        auto p=it->second;
        delete p;
        }
    }*/
    Biblioteka(const Biblioteka &b){
        for(auto it=b.Citabi.begin();it!=b.Citabi.end();it++){
            auto p=it->second;
            auto id=it->first;
            std::shared_ptr<Knjiga> k=std::make_shared<Knjiga>(p->naslov,p->pisac,p->zanr,p->godina);
            Citabi.insert(std::make_pair(id,k));
        }
        
          for(auto it=b.Korisnici.begin();it!=b.Korisnici.end();it++){
            auto p=it->second;
            auto id=it->first;
            Korisnik a;
            a.ime=p->ime;
            a.prezime=p->prezime;
            a.adresa=p->adresa;
            a.telefon=p->telefon;
            std::shared_ptr<Korisnik>j=std::make_shared< Korisnik>(a);
            Korisnici.insert(std::make_pair(id,j));
        }
    }
    Biblioteka &operator=(Biblioteka b){
        std::swap(Korisnici, b.Korisnici);
        std::swap(Citabi, b.Citabi);
        return *this;
    }
    
    void RegistrirajNovogKorisnika(int broj,std::string im,std::string prez,std::string adr,std::string brtel){
        auto it=Korisnici.find(broj);
        if(it!=Korisnici.end()) throw std::logic_error("Korisnik vec postoji");
        auto k=std::make_shared <Korisnik>();
        k->ime=im;
        k->prezime=prez;
        k->adresa=adr;
        k->telefon=brtel;
        Korisnici.insert(std::make_pair(broj,k));
    }
    void RegistrirajNovuKnjigu(int broj,std::string nas,std::string pis,std::string zanr,int god){
        auto it=Citabi.find(broj);
        if(it!=Citabi.end()) throw std::logic_error("Knjiga vec postoji");
        auto c=std::make_shared< Knjiga>(nas,pis,zanr,god);
        Citabi.insert(std::make_pair(broj,c));
    }
  
    
    Korisnik &NadjiKorisnika(int broj) const{
        auto it=Korisnici.find(broj);
        if(it==Korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
        auto p=it->second;
        return *p;
    }
    Knjiga &NadjiKnjigu(int broj) const {
        auto it=Citabi.find(broj);
        if(it==Citabi.end()) throw std::logic_error("Knjiga nije nadjena");
        auto p=it->second;
        return *p;
    }
    void IzlistajKorisnike(){
        for(auto it=Korisnici.begin();it!=Korisnici.end();it++){
        auto p=it->second;
        std::cout << "Clanski broj: " << it->first<<std::endl;
        std::cout << "Ime i prezime: "<<p->ime<<" "<<p->prezime << std::endl;
            std::cout << "Adresa: "<<p->adresa << std::endl;
         std::cout << "Broj telefona: " << p->telefon<< std::endl;
         std::cout<<std::endl;
        }
    }
    
    void IzlistajKnjige(){
        for(auto it=Citabi.begin();it!=Citabi.end();it++){
            auto pok=it->second;
            std::cout << "Evidencijski broj: "<<it->first<< std::endl;
            std::cout << "Naslov: "<<pok->naslov << std::endl;
            std::cout << "Pisac: "<<pok->pisac << std::endl;
            std::cout << "Zanr: "<<pok->zanr << std::endl;
            std::cout << "Godina izdavanja: "<<pok->godina<<std::endl;
        if(pok->p!=nullptr)
            std::cout << "Zaduzena kod korisnika: "<<pok->p->ime<<" "<<pok->p->prezime<<std::endl;
            std::cout  << std::endl;
        }
    }
    
     void PrikaziZaduzenja(int broj){
         auto it1=Korisnici.find(broj);
         bool knj(false);
  for(auto it=Citabi.begin();it!=Citabi.end();it++){
      auto pok=it->second;
      auto k=(it1->second).get();
      if (k==pok->p) {
          knj=true;
           std::cout << "Evidencijski broj: "<<it->first<< std::endl;
            std::cout << "Naslov: "<<pok->naslov << std::endl;
            std::cout << "Pisac: "<<pok->pisac << std::endl;
            std::cout << "Zanr: "<<pok->zanr << std::endl;
            std::cout << "Godina izdavanja: "<<pok->godina<<std::endl;
      }
  }
       if(knj==false){
        std::cout << "Nema zaduzenja za tog korisnika!"<<std::endl;
        }
  }
    
    void ZaduziKnjigu(int knjiga,int citac){
        auto it1=Citabi.find(knjiga);
        if(it1==Citabi.end())
        throw std::logic_error("Knjiga nije nadjena");
        auto it2=Korisnici.find(citac);
        if(it2==Korisnici.end())
        throw std::logic_error("Korisnik nije nadjen");
        auto pok=it1->second;
        if(pok->p!=nullptr)
        throw std::logic_error("Knjiga je vec zaduzena");
        else{
        auto z((it2->second).get());
        pok->p=z;
        }
    }
    void RazduziKnjigu(int knjiga){
        auto it=Citabi.find (knjiga);
        if(it==Citabi.end())
        throw std::logic_error("Knjiga nije nadjena");
        auto pok=it->second;
        if(pok->p==nullptr)
        throw std::logic_error ("Knjiga nije zaduzena");
        else pok->p=nullptr;
    }
};
int main ()
{
    
    Biblioteka b;
    b.RegistrirajNovogKorisnika(1,"Harun","Dzihana","Hendek 8","061060559");
    b.RegistrirajNovuKnjigu(1,"Harry Potter","J.K.Rowling","sci-fi",1997);
    {
        Biblioteka c=b;
        c.IzlistajKnjige();
    } 
    b.IzlistajKnjige();
	return 0;
}