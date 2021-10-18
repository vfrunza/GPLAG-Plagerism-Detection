#include <utility>
#include <stdexcept>
#include <map>
#include <iostream>
#include <string>

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
    std::map<int,Korisnik*> Korisnici;
    std::map<int, Knjiga*> Citabi;
    public:
    Biblioteka()=default;
    ~Biblioteka(){
        for(auto it=Korisnici.begin();it!=Korisnici.end();it++){
        auto p=it->second;
        delete p;
        }
        for(auto it=Citabi.begin();it!=Citabi.end();it++){
        auto p=it->second;
        delete p;
        }
    }
    Biblioteka(const Biblioteka &b){
        for(auto it=b.Citabi.begin();it!=b.Citabi.end();it++){
            auto p=it->second;
            auto id=it->first;
            Knjiga* k=new Knjiga (p->naslov,p->pisac,p->zanr,p->godina);
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
            Korisnik*j=new Korisnik(a);
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
        auto k=new Korisnik;
        k->ime=im;
        k->prezime=prez;
        k->adresa=adr;
        k->telefon=brtel;
        Korisnici.insert(std::make_pair(broj,k));
    }
    void RegistrirajNovuKnjigu(int broj,std::string nas,std::string pis,std::string zanr,int god){
        auto it=Citabi.find(broj);
        if(it!=Citabi.end()) throw std::logic_error("Knjiga vec postoji");
        auto c=new Knjiga(nas,pis,zanr,god);
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
    
     void PrikaziZaduzenja(int broj){
         auto it1=Korisnici.find(broj);
         bool knj(false);
  for(auto it=Citabi.begin();it!=Citabi.end();it++){
      auto pok=it->second;
      if (it1->second==pok->p) {
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
  
    void IzlistajKnjige(){
        for(auto it=Citabi.begin();it!=Citabi.end();it++){
            auto pok=it->second;
            std::cout << "Evidencijski broj: "<<it->first<< std::endl;
            std::cout << "Naslov: "<<pok->naslov << std::endl;
            std::cout << "Pisac: "<<pok->pisac << std::endl;
            std::cout << "Zanr: "<<pok->zanr << std::endl;
            std::cout << "Godina izdavanja: "<<pok->godina<<std::endl;
        if(pok->p!=nullptr){
        std::cout << "Zaduzena kod korisnika: "<<pok->p->ime<<" "<<pok->p->prezime<<std::endl;
        }
        std::cout  << std::endl;
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
        else pok->p=it2->second;
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
    b.RegistrirajNovogKorisnika(2,"Adela","Burkic","Ulica Slobode","062345943");
    b.RegistrirajNovogKorisnika(3,"Ajla","Loncar","Donjici bb","062267472");
    b.RegistrirajNovogKorisnika(4,"Edah","Karalic","Bosanska bb","061876098");
    b.RegistrirajNovogKorisnika(5,"Hadzera","Dzihana","Hendek 8","062938088");
    b.RegistrirajNovogKorisnika(6,"Ema","Karajlic","Branilaca Sarajeva","070221870");
    b.RegistrirajNovuKnjigu(1,"Harry Potter","J.K.Rowling","sci-fi",1997);
    b.RegistrirajNovuKnjigu(2,"Igre Gladi","Suzanne Collins","sci-fi",2012);
    b.RegistrirajNovuKnjigu(3,"Romeo i Julija","William Shakespear","drama",1462);
    b.RegistrirajNovuKnjigu(4,"Matematicka analiza","Svetozar Kurepa","sci-fi",1989);
     int br;
     int brj,god;
     std::string naslov, pisac, zanr;
    int bro;
    std::string im,pr,ad,brt;
    for(;;){
    std::cout<<"Odaberite opciju:"<<std::endl<<"1 - ispisivanje svih knjiga"<<std::endl<<"2 - ispisivanje svih korisnika"<<std::endl<<"3 - dodavanje nove knjige"<<std::endl<<"4 - dodavanje novog korisnika"<<std::endl<<"0 - kraj"<<std::endl;
    std::cin>>br;
  if(br==1)
  b.IzlistajKnjige();
  if(br==2)
  b.IzlistajKorisnike();
  if(br==3){
      std::cout<<"Unesite podatke(evidencijski broj, naslov, pisac, zanr, godina izdavanja): ";
      std::cin>>brj;
      std::cin.clear();
      std::cin.ignore(10000,'\n');
      std::getline(std::cin,naslov);
      std::getline(std::cin,pisac);
      std::getline(std::cin,zanr);
      std::cin>>god;
      try{
      b.RegistrirajNovuKnjigu(brj,naslov,pisac,zanr,god);
      } catch(std::logic_error e){
          std::cout<<e.what()<<std::endl;
      }
      }
 
  if(br==4){
      std::cout<<"Unesite podatke(clanski broj ,ime i prezime, adresa, broj telefona): ";
      std::cin>>bro;
      std::cin.clear();
      std::cin.ignore(10000,'\n');
      std::getline(std::cin,im);
      std::getline(std::cin,pr);
      std::getline(std::cin,ad);
      std::getline(std::cin,brt);
      try{
      b.RegistrirajNovogKorisnika(bro,im,pr,ad,brt);
      } 
      catch(std::logic_error e){
          std::cout<<e.what()<<std::endl;
      }
  }
  if(br==0){
      return 0;
  }
    }
	return 0;
}