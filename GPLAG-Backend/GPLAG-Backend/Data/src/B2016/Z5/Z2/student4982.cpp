/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <new>
#include <stdexcept>
#include <algorithm>
#include <string>
#include <utility>
#include <map>

struct Korisnik
{
  std::string ime, prezime, adresa, telefon;  
};

class Knjiga
{
  std::string naslov,pisac,zanr;
  Korisnik *KodKogaJe;
  int god;
  public:
  Knjiga(std::string ime, std::string imePisca, std::string zanr, int godina) {naslov=ime; pisac=imePisca; Knjiga::zanr=zanr; god=godina; KodKogaJe=nullptr; }
  std::string DajNaslov() const { return naslov; }
  std::string DajAutora() const { return pisac; }
  std::string DajZanr() const { return zanr; }
  int DajGodinuIzdavanja() const { return god; }
  Korisnik *DajKodKogaJe() const { return KodKogaJe; }
  void ZaduziKnjigu(Korisnik &k) { KodKogaJe=&k; }
  void RazduziKnjigu() { KodKogaJe=nullptr; }
  bool DaLiJeZaduzena() { if(KodKogaJe==nullptr) return false; else return true; }
};

class Biblioteka
{
  std::map<int, Knjiga*> knjige;
  std::map<int, Korisnik*> korisnici;
  public:
  void RegistrirajNovogKorisnika(int br, std::string ime, std::string prez, std::string adresa, std::string br_tel);
  void RegistrirajNovuKnjigu(int br, std::string naslov, std::string ime_pisca, std::string zanr, int god);
  Korisnik &NadjiKorisnika(int br);
  Knjiga &NadjiKnjigu(int br);
  Biblioteka() {}
  Biblioteka(const Biblioteka &b)
     {
       auto it1(b.korisnici.begin()); auto it2(b.knjige.begin());
       while(it1!=b.korisnici.end())
       {
         auto temp=*(it1->second);
         korisnici.insert(std::make_pair(it1->first,new Korisnik(temp)));
         it1++;
       }
       while(it2!=b.knjige.end())
       {
         auto temp=*(it2->second);
         knjige.insert(std::make_pair(it2->first,new Knjiga(temp.DajNaslov(),temp.DajAutora(),temp.DajZanr(),temp.DajGodinuIzdavanja())));
         it2++;
       }
       it1=b.korisnici.begin(); it2=b.knjige.begin();
       while(it1!=b.korisnici.end())
       {
         it2=b.knjige.begin();
         while(it2!=b.knjige.end())
         {
           if(it2->second->DajKodKogaJe()==it1->second) ZaduziKnjigu(it2->first, it1->first);
           it2++;
         }
         it1++;
       }
     }
  Biblioteka(Biblioteka &&b)
  {
    auto it(b.korisnici.begin());
    while(it!=b.korisnici.end())
    {
      korisnici.insert(std::make_pair(it->first,it->second));
      it->second=nullptr;
      it++;
    }
    auto it2(b.knjige.begin());
    while(it2!=b.knjige.end())
    {
      knjige.insert(std::make_pair(it2->first,it2->second));
      it2->second=nullptr;
      it2++;
    }
  }
  Biblioteka &operator =(const Biblioteka &b)
  {
    if(&b!=this)
    {
      if(knjige.size()!=0)
      {
        auto it(knjige.begin());
        while(it!=knjige.end())
        {
          delete it->second;
          knjige.erase(it);
          it++;
        }
        auto it2(b.knjige.begin());
        while(it2!=b.knjige.end())
        {
          auto temp=*(it2->second);
          knjige.insert(std::make_pair(it2->first,new Knjiga(temp.DajNaslov(),temp.DajAutora(),temp.DajZanr(),temp.DajGodinuIzdavanja())));
          it2++;
        }
      }
      else
      {
        auto it(b.knjige.begin());
        while(it!=b.knjige.end())
        {
          auto temp=*(it->second);
          knjige.insert(std::make_pair(it->first,new Knjiga(temp.DajNaslov(),temp.DajAutora(),temp.DajZanr(),temp.DajGodinuIzdavanja())));
          it++;
        }
      }
      if(korisnici.size()!=0)
      {
        auto it(korisnici.begin());
        while(it!=korisnici.end())
        {
          delete it->second;
          korisnici.erase(it);
          it++;
        }
        auto it2(b.korisnici.begin());
        while(it2!=b.korisnici.end())
        {
          auto temp=*(it2->second);
          korisnici.insert(std::make_pair(it2->first,new Korisnik(temp)));
          it2++;
        }
      }
      else
      {
        auto it(b.korisnici.begin());
        while(it!=b.korisnici.end())
        {
          auto temp=*(it->second);
          korisnici.insert(std::make_pair(it->first,new Korisnik(temp)));
          it++;
        }
      }
      auto itt(b.korisnici.begin()); auto ittt(b.knjige.begin());
      {
        while(itt!=b.korisnici.end())
        {
          ittt=b.knjige.begin();
          while(ittt!=b.knjige.end())
          {
            if(ittt->second->DajKodKogaJe()==itt->second) ZaduziKnjigu(ittt->first,itt->first);
            ittt++;
          }
          itt++;
        }
        
      }
    }
    return *this;
  }
  void IzlistajKorisnike();
  void IzlistajKnjige();
  void ZaduziKnjigu(int br_knjige, int br_kor);
  void RazduziKnjigu(int br_knjige);
  void PrikaziZaduzenja(int br);
  ~Biblioteka() 
  { 
    auto it(korisnici.begin()); auto it2(knjige.begin());
    while(it2!=knjige.end())
    {
      it2->second->RazduziKnjigu();
      delete it2->second;
      it2++;
    }
    while(it!=korisnici.end())
    {
      delete it->second;
      it++;
    }
  }
};

void Biblioteka::RegistrirajNovogKorisnika(int br, std::string ime, std::string prez, std::string adresa, std::string br_tel)
{
  auto it(korisnici.find(br));
  if(it==korisnici.end()) korisnici.insert(std::make_pair(br,new Korisnik{ime,prez,adresa,br_tel}));
  else throw std::logic_error("Korisnik vec postoji");
}
void Biblioteka::RegistrirajNovuKnjigu(int br, std::string naslov, std::string ime_pisca, std::string zanr, int god)
{
  auto it(knjige.find(br));
  if(it==knjige.end()) knjige.insert(std::make_pair(br,new Knjiga(naslov,ime_pisca,zanr,god)));
  else throw std::logic_error("Knjiga vec postoji");
}
Knjiga& Biblioteka::NadjiKnjigu(int br)
{
  auto it(knjige.find(br));
  if(it==knjige.end()) throw std::logic_error("Knjiga nije nadjena");
  else return *(it->second);
}
Korisnik& Biblioteka::NadjiKorisnika(int br)
{
  auto it(korisnici.find(br));
  if(it==korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
  else return *(it->second);
}
void Biblioteka::IzlistajKorisnike()
{
  auto it(korisnici.begin());
  while(it!=korisnici.end())
  {
    std::cout<<"Clanski broj: "<<it->first<<std::endl;
    std::cout<<"Ime i prezime: "<<it->second->ime<<" "<<it->second->prezime<<std::endl;
    std::cout<<"Adresa: "<<it->second->adresa<<std::endl;
    std::cout<<"Broj telefona: "<<it->second->telefon<<std::endl;
    std::cout<<std::endl;
    it++;
  }
}
void Biblioteka::IzlistajKnjige()
{
  auto it(knjige.begin());
  while(it!=knjige.end())
  {
    std::cout<<"Evidencijski broj: "<<it->first<<std::endl;
    std::cout<<"Naslov: "<<it->second->DajNaslov()<<std::endl;
    std::cout<<"Pisac: "<<it->second->DajAutora()<<std::endl;
    std::cout<<"Zanr: "<<it->second->DajZanr()<<std::endl;
    std::cout<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<std::endl;
    if(it->second->DaLiJeZaduzena()) std::cout<<"Zaduzena kod korisnika: "<<it->second->DajKodKogaJe()->ime<<" "<<it->second->DajKodKogaJe()->prezime<<std::endl;
    std::cout<<std::endl;
    it++;
  }
}
void Biblioteka::ZaduziKnjigu(int br_knjige,int br_kor)
{
  auto it(knjige.find(br_knjige));
  auto it2(korisnici.find(br_kor));
  if(it==knjige.end()) throw std::logic_error("Knjiga nije nadjena");
  if(it2==korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
  if(it->second->DaLiJeZaduzena()==true) throw std::logic_error("Knjiga vec zaduzena");
  it->second->ZaduziKnjigu(*(it2->second));
}
void Biblioteka::RazduziKnjigu(int br_knjige)
{
  auto it(knjige.find(br_knjige));
  if(it==knjige.end()) throw std::logic_error("Knjiga nije nadjena");
  if(it->second->DaLiJeZaduzena()==false) throw std::logic_error("Knjiga nije zaduzena");
  it->second->RazduziKnjigu();
}
void Biblioteka::PrikaziZaduzenja(int br)
{
  auto it(korisnici.find(br));
  if(it==korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
  auto it2=knjige.begin();
  int broj=0;
  while(it2!=knjige.end())
  {
    if(it2->second->DajKodKogaJe()==it->second)
    {
      std::cout<<"Evidencijski broj: "<<it2->first<<std::endl;
      std::cout<<"Naslov: "<<it2->second->DajNaslov()<<std::endl;
      std::cout<<"Pisac: "<<it2->second->DajAutora()<<std::endl;
      std::cout<<"Zanr: "<<it2->second->DajZanr()<<std::endl;
      std::cout<<"Godina izdavanja: "<<it2->second->DajGodinuIzdavanja()<<std::endl<<std::endl;
      broj++;
    }
    it2++;
  }
  if(broj==0) std::cout<<"Nema zaduzenja za tog korisnika!"<<std::endl;
}
int main ()
{
  Biblioteka b;
  while(1) {
  std::cout<<"Odaberite opciju:"<<std::endl;
  std::cout<<"1 - Unos nove knjige"<<std::endl
  <<"2 - Unos novog korisnika"<<std::endl
  <<"3 - Zaduzenje knjige"<<std::endl
  <<"4 - Razduzenje knjige"<<std::endl
  <<"5 - Lista knjiga"<<std::endl
  <<"6 - Lista korisnika"<<std::endl
  <<"7 - Zaduzenja korisnika"<<std::endl
  <<"0 - Kraj"<<std::endl;
  int n;
  std::cin>>n;
  if(n==0) break;
  if(n==1)
  {
    std::string naziv, autor, zanr;
    int br_knj;
    std::cout<<"Unesite broj knjige: ";
    std::cin>>br_knj;
    std::cin.ignore(1000,'\n');
    std::cout<<"Unesite naziv knjige: ";
    int god;
    std::getline(std::cin, naziv);
    std::cout<<"Unesite ime autora: ";
    std::getline(std::cin, autor);
    std::cout<<"Unesite zanr knjige: ";
    std::getline(std::cin, zanr);
    std::cout<<"Unesite godinu izdavanja: ";
    std::cin>>god;
    std::cin.ignore(1000,'\n');
    try {
    b.RegistrirajNovuKnjigu(br_knj,naziv,autor,zanr,god);
    }
    catch (std::logic_error l)
    {
      std::cout<<l.what()<<std::endl;
    }
    catch (std::bad_alloc)
    {
      std::cout<<"Alokacija nije uspjela"<<std::endl;
    }
  }
  if(n==2)
  {
    std::string ime, prezime, adresa, tel;
    int br;
    std::cout<<"Unesite korisnicki broj: ";
    std::cin>>br;
    std::cin.ignore(1000,'\n');
    std::cout<<"Unesite ime korisnika: ";
    std::getline(std::cin,ime);
    std::cout<<"Unesite prezime korisnika: ";
    std::getline(std::cin,prezime);
    std::cout<<"Unesite adresu: ";
    std::getline(std::cin,adresa);
    std::cout<<"Unesite broj telefona: ";
    std::getline(std::cin,tel);
    try {
    b.RegistrirajNovogKorisnika(br,ime,prezime,adresa,tel);
    }
    catch(std::logic_error l)
    {
      std::cout<<l.what()<<std::endl;
    }
    catch(std::bad_alloc)
    {
      std::cout<<"Alokacija nije uspjela"<<std::endl;
    }
  }
  if(n==3)
  {
    int br_knj, br_kor;
    std::cout<<"Unesite broj knjige koju zelite zaduziti: ";
    std::cin>>br_knj;
    std::cin.ignore(1000,'\n');
    std::cout<<"Unesite broj korisnika koji zeli zaduziti knjigu: ";
    std::cin>>br_kor;
    std::cin.ignore(1000,'\n');
    try {
    b.ZaduziKnjigu(br_knj,br_kor);
    }
    catch (std::logic_error l)
    {
      std::cout<<l.what()<<std::endl;
    }
  }
  if(n==4)
  {
    int br_knj;
    std::cout<<"Unesite broj knjige koju zelite razduziti: ";
    std::cin>>br_knj;
    std::cin.ignore(1000,'\n');
    try {
    b.RazduziKnjigu(br_knj);
    }
    catch (std::logic_error l)
    {
      std::cout<<l.what()<<std::endl;
    }
  }
  if(n==5) b.IzlistajKnjige();
  if(n==6) b.IzlistajKorisnike();
  if(n==7)
  {
    std::cout<<"Unesite broj korisnika: ";
    int br;
    std::cin>>br;
    std::cin.ignore(1000,'\n');
    try {
    b.PrikaziZaduzenja(br);
    }
    catch(std::logic_error l)
    {
      std::cout<<l.what()<<std::endl;
    }
  }
  }
	return 0;
}