/B16/17 (Zadaća 5, Zadatak 1)
#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include <algorithm>
struct Korisnik{
  std::string ime,prezime,adresa,telefon;
};
class Knjiga{
  std::string naslov,ime_pisca,zanr;
  int godina_izdavanja;
  Korisnik * kod_koga_je;
  public:
  Knjiga(std::string naslov,std::string ime_pisca,std::string zanr,int godina_izdavanja):kod_koga_je(nullptr){
         Knjiga::naslov=naslov,Knjiga::ime_pisca=ime_pisca;Knjiga::zanr=zanr; Knjiga::godina_izdavanja=godina_izdavanja;
  }
Knjiga(const Knjiga &k):naslov(k.naslov),ime_pisca(k.ime_pisca),zanr(k.zanr),godina_izdavanja(k.godina_izdavanja),kod_koga_je(k.kod_koga_je){}
 
  std::string DajNaslov() const{return naslov;}
  std::string DajAutora() const{return ime_pisca;}
  std::string DajZanr() const {return zanr;}
  int DajGodinuIzdavanja() const{return godina_izdavanja;}
  Korisnik *DajKodKogaJe() const{return kod_koga_je;}
  void ZaduziKnjigu(Korisnik &k ){kod_koga_je= &k;}
  void RazduziKnjigu(){kod_koga_je=nullptr;}
  bool DaLiJeZaduzena(){return kod_koga_je!=nullptr;}
  
};

class Biblioteka{
  std::map<int,Korisnik*>korisnik;
  std::map<int,Knjiga*> knjiga;
  public:
  Biblioteka(){}
  Biblioteka(const Biblioteka & b);
  Biblioteka(Biblioteka && b);
  Biblioteka &operator=(const Biblioteka &b);
  Biblioteka &operator=(Biblioteka &&b);
  ~Biblioteka();
  void RegistrirajNovogKorisnika(int clanskibr,std::string ime,std::string prezime,std::string adresa,std::string telefon);
  void  RegistrirajNovuKnjigu(int br_knjige,std::string naslov,std::string ime,std::string zanr,int godina);
  Korisnik &NadjiKorisnika(int clanskibr)const;
  Knjiga &NadjiKnjigu(int brojknjige)const;
  void IzlistajKorisnike()const;
  void IzlistajKnjige()const;
  void ZaduziKnjigu(int evidencijski_br,int clanski_br);
  void RazduziKnjigu(int evidencijski_br);
  void PrikaziZaduzenja(int clanski_br)const;
};
void Biblioteka::RegistrirajNovogKorisnika(int clanskibr,std::string ime,std::string prezime,std::string adresa,std::string telefon){
    auto it (korisnik.find(clanskibr));
    if(it!=korisnik.end()) throw std::logic_error("Korisnik vec postoji");
       Korisnik *k(new Korisnik);
        k->ime=ime;k->prezime=prezime;k->adresa=adresa;k->telefon=telefon;
        korisnik.insert(std::make_pair(clanskibr,k));
  }
Biblioteka::~Biblioteka(){
  for(auto it=korisnik.begin();it!=korisnik.end();it++) delete it->second;
  for(auto i=knjiga.begin();i!=knjiga.end();i++) delete i->second;
  
}
Biblioteka::Biblioteka(const Biblioteka &b){
  for(auto it(b.knjiga.begin());it!=b.knjiga.end();it++){
     Knjiga k(*(it->second));
     Knjiga * pok(new Knjiga(k));
     knjiga.insert(std::make_pair(it->first,pok));
  }   
  for(auto it(b.korisnik.begin()); it!=b.korisnik.end(); it++){
    Korisnik k(*(it->second));
    Korisnik *p(new Korisnik(k));
    korisnik.insert(std::make_pair(it->first,p));
  }   
}
Biblioteka::Biblioteka(Biblioteka && b){
  knjiga=b.knjiga;
  for(auto it(b.knjiga.begin());it!=b.knjiga.end();it++) it->second=nullptr;
  korisnik=b.korisnik;
  for(auto it(b.korisnik.begin());it!=b.korisnik.end();it++) it->second=nullptr;
}

Biblioteka &Biblioteka::operator=(const Biblioteka &b){
  if(&b!=this){
    for(auto it(korisnik.begin());it!=korisnik.end();it++){delete it->second; korisnik.erase(it->first);}
    for(auto it(knjiga.begin());it!=knjiga.end();it++){ delete it->second; knjiga.erase(it->first);}
    for(auto it(b.knjiga.begin());it!=b.knjiga.end();it++){
        Knjiga k(*(it->second));
        Knjiga *p(new Knjiga(k));
        knjiga.insert(std::make_pair(it->first,p));
    }
    for(auto it(b.korisnik.begin());it!=b.korisnik.end();it++){
        Korisnik k(*(it->second));
        Korisnik *p(new Korisnik(k));
        korisnik.insert(std::make_pair(it->first,p));
    }
  }
  return *this;
}
Biblioteka & Biblioteka::operator =(Biblioteka &&b){
  if(&b!=this){
    for (auto it(korisnik.begin());it!=korisnik.end();it++){delete it->second;korisnik.erase(it->first);}
    for (auto it(knjiga.begin());it!=knjiga.end();it++){delete it->second;knjiga.erase(it->first);}
    knjiga=b.knjiga;
    for(auto it(b.knjiga.begin());it!=b.knjiga.end();it++) it->second=nullptr;
    korisnik=b.korisnik;
    for(auto it(b.korisnik.begin());it!=b.korisnik.end();it++) it->second=nullptr;
  }
  return *this;
}

void Biblioteka::RegistrirajNovuKnjigu(int br_knjige,std::string naslov,std::string ime,std::string zanr,int godina){
   auto it(knjiga.find(br_knjige));
  if(it!=knjiga.end()) throw std::logic_error ("Knjiga vec postoji");
   knjiga.insert(std::make_pair(br_knjige,new Knjiga(naslov,ime,zanr,godina)));
   
}
Korisnik& Biblioteka::NadjiKorisnika(int clanskibr)const{
   auto it(korisnik.find(clanskibr));
   if(it==korisnik.end()) throw std::logic_error("Korisnik nije nadjen");
   else return *(it->second);
}
Knjiga & Biblioteka::NadjiKnjigu(int brojknjige)const{
  auto it(knjiga.find(brojknjige));
  if(it==knjiga.end()) throw std::logic_error("Knjiga nije nadjena");
  else return *(it->second); 
}
void Biblioteka::IzlistajKorisnike()const{
  for(auto it=korisnik.begin();it!=korisnik.end();it++){
  std::cout<<"Clanski broj: "<<it->first<<std::endl
  <<"Ime i prezime: "<<(it->second)->ime<<" "<<(it->second)->prezime<<std::endl
  <<"Adresa: "<<(it->second)->adresa<<std::endl
  <<"Broj telefona: "<<(it->second)->telefon<<std::endl;
  std::cout<<std::endl;
    }
 
}

void Biblioteka::IzlistajKnjige()const{
  for(auto it=knjiga.begin();it!=knjiga.end();it++){
    std::cout<<"Evidencijski broj: "<<it->first<<std::endl
    <<"Naslov: "<<(it->second)->DajNaslov()<<std::endl
    <<"Pisac: "<<(it->second)->DajAutora()<<std::endl
    <<"Zanr: "<<(it->second)->DajZanr()<<std::endl
    <<"Godina izdavanja: "<<(it->second)->DajGodinuIzdavanja()<<std::endl;
    if((it->second)->DaLiJeZaduzena())
    std::cout<<"Zaduzena kod korisnika: "<<(it->second)->DajKodKogaJe()->ime
    <<" "<<(it->second)->DajKodKogaJe()->prezime<<std::endl;
    std::cout<<std::endl;
  }
}

void Biblioteka::ZaduziKnjigu(int evidencijski_br,int clanski_br){
    NadjiKnjigu(evidencijski_br);
    NadjiKorisnika(clanski_br);
    auto i(knjiga.find(evidencijski_br)); if(i->second->DaLiJeZaduzena()) throw std::logic_error("Knjiga vec zaduzena");
    for(auto it(korisnik.begin());it!=korisnik.end();it++){
          if(it->first ==clanski_br){
            for(auto j(knjiga.begin());j!=knjiga.end();j++)
              if(j->first==evidencijski_br) (j->second)->ZaduziKnjigu(*(it->second)) ;
          }
      }
}
void Biblioteka::RazduziKnjigu(int evidencijski_br){
    NadjiKnjigu(evidencijski_br);
    auto it(knjiga.find(evidencijski_br));
       if(!((it->second)->DaLiJeZaduzena())) throw std::logic_error("Knjiga nije zaduzena");
       (it->second)->RazduziKnjigu();
    
}

void Biblioteka::PrikaziZaduzenja(int clanski_br)const{
  NadjiKorisnika(clanski_br);
  auto j (korisnik.find(clanski_br));
  int br(0);
  for(auto it(knjiga.begin());it!=knjiga.end();it++){
      if(((it->second)->DajKodKogaJe())==(j->second)){
          std::cout<<"Evidencijski broj: "<<it->first<<std::endl
          <<"Naslov: "<<it->second->DajNaslov()<<std::endl
          <<"Pisac: "<<it->second->DajAutora()<<std::endl
           <<"Zanr: "<<it->second->DajZanr()<<std::endl
          <<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<std::endl;
          br++;
     }
     std::cout<<std::endl;
  }
  if(br==0) std::cout<<"Nema zaduzenja za tog korisnika!"<<std::endl;
  
}


int main (){
  try{
    
  Biblioteka b1;
  int clanski_br,evidencijski_br,godina_izdavanja,opcija;
  std::string ime,prezime,adresa,telefon,naslov,ime_pisca,zanr;
   std::cout<<"OPCIJE : "<<std::endl;
    std::cout<<"IZLAZ -----> 0"<<std::endl;
    std::cout<<"REGISTRACIJA CLANA   ---> 1 "<<std::endl;
    std::cout<<"REGISTRACIJA KNJIGE  ---> 2 "<<std::endl;
    std::cout<<"ZADUZIVANJE KNJIGE   ---> 3 "<<std::endl;
    std::cout<<"RAZDUZIVANJE KNJIGE  ---> 4 "<<std::endl;
    std::cout<<"IZLISTAJ ZADUZENJA   ---> 5 "<<std::endl;
    std::cout<<"IZLISTAJ SVE CLANOVE ---> 6 "<<std::endl;
    std::cout<<"IZLISTAJ SVE KNJIGE  ---> 7 "<<std::endl<<std::endl;

    while(1){
      std::cout<<"Odaberite opciju: "<<std::endl;
    std::cin>>opcija;
    std::cin.clear();
    std::cin.ignore(1000000,'\n');
    
    switch(opcija){
      
      case(0):
      std::cout<<"Dovidjenja  "<<std::endl<<std::endl;
      return 0;
      
      case 1:
            std::cout<<"Unesite ime korisnika: ";
            std::getline(std::cin,ime);
            std::cout<<"Unesite prezime korisnika: ";
            std::getline(std::cin,prezime);
            std::cout<<"Unesite adresu: ";
            std::getline(std::cin,adresa);
            std::cout<<"Unesite broj telefona: ";
            std::getline(std::cin,telefon);
            std::cout<<"Unesite clanski broj: ";
            std::cin>>clanski_br;
            std::cin.clear();
            std::cin.ignore(1000000,'\n');
            try{
            b1.RegistrirajNovogKorisnika(clanski_br,ime,prezime,adresa,telefon);
            std::cout<<"Uspjesno ste registrirali korisnika "<<std::endl;
            }
            catch(std::logic_error e){
              std::cout<<e.what()<<std::endl;
            }
            break;
            
      case 2:
             std::cout<<"Unesite naslov knjige: ";
             std::getline(std::cin,naslov);
             std::cout<<"Unesite pisca: ";
             std::getline(std::cin,ime_pisca);
             std::cout<<"Unesite zanr: ";
             std::getline(std::cin,zanr);
             std::cout<<"Unesite godinu izdavanja: ";
             std::cin>>godina_izdavanja;
             std::cout<<"Unesite evidencijski broj: ";
             std::cin>>evidencijski_br;
             std::cin.clear();
             std::cin.ignore(100000,'\n');
             try{
             b1.RegistrirajNovuKnjigu(evidencijski_br,naslov,ime_pisca,zanr,godina_izdavanja);
             std::cout<<"Uspjesno ste registrirali knjigu "<<std::endl;
             }
             catch(std::logic_error e){
               std::cout<<e.what()<<std::endl;
             }
             break;
      case 3:
             std::cout<<"Unesite clanski broj korisnika : ";
             std::cin>>clanski_br;
             std::cout<<"Unesite evidencijski broj knjige : ";
             std::cin>>evidencijski_br;
             std::cin.clear();
             std::cin.ignore(100000,'\n');
             try{
             b1.ZaduziKnjigu(evidencijski_br,clanski_br);
             }
             catch(std::logic_error e){
               std::cout<<e.what()<<std::endl;
             }
             break;
      case 4:
            std::cout<<"Unesite evidencijski broj: ";
            std::cin>>evidencijski_br;
            std::cin.clear();
            std::cin.ignore(100000,'\n');
            try{
            b1.RazduziKnjigu(evidencijski_br);
            }
            catch(std::logic_error e){
              std::cout<<e.what()<<std::endl;
              
            }
            break;
            
      case 5:
            std::cout<<"Unesite clanski broj: ";
            std::cin>>clanski_br;
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            try{
            b1.PrikaziZaduzenja(clanski_br);
            }
            catch(std::logic_error e){
              std::cout<<e.what()<<std::endl;
            }
            break;
            
      case 6:
            b1.IzlistajKorisnike();
            break;
            
      case 7:
            b1.IzlistajKnjige();
            break;
    }
 
  }
 
}
  catch(std::logic_error e){
    std::cout<<e.what();
  }
  
	return 0;
}