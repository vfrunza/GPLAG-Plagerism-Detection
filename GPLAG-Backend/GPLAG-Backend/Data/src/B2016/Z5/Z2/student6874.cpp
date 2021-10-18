/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <map>
#include <string>
#include <utility>
#include <memory>

struct Korisnik{
    std::string ime, prezime, adresa, telefon;
};

class Knjiga{
  std::string naslov, ime_pisca, zanr;
  int godina_izdavanja;
  Korisnik *zaduzioc;
  public:
    Knjiga(std::string naslov, std::string ime_pisca, std::string zanr, int godina_izdavanja) : naslov(naslov), ime_pisca(ime_pisca), zanr(zanr), godina_izdavanja(godina_izdavanja), zaduzioc(nullptr) {}
    std::string DajNaslov() const{return naslov;}
    std::string DajAutora() const {return ime_pisca;}
    std::string DajZanr() const {return zanr;}
    int DajGodinuIzdavanja() const {return godina_izdavanja;}
    Korisnik *DajKodKogaJe() const {return zaduzioc;}
    void ZaduziKnjigu (Korisnik &k) {zaduzioc = &k;}
    void RazduziKnjigu() {zaduzioc = nullptr;}
    bool DaLiJeZaduzena() const {return zaduzioc!=nullptr;}
};

class Biblioteka{
  std::map<int, std::shared_ptr<Korisnik>> mapa_korisnika;
  std::map<int, std::shared_ptr<Knjiga>> mapa_knjiga;
  public:
    Biblioteka() {}
    Biblioteka(const Biblioteka &b);
    Biblioteka(Biblioteka &&b);
    Biblioteka &operator= (const Biblioteka &b);
    Biblioteka &operator= (Biblioteka &&b);
    void RegistrirajNovogKorisnika(int clanski_broj, std::string ime, std::string prezime, std::string adresa, std::string broj_tel);
    void RegistrirajNovuKnjigu (int evidencijski_broj, std::string naslov, std::string ime_pisca, std::string zanr, int godina_izdavanja);
    Korisnik &NadjiKorisnika(int clanski_broj) ;
    Knjiga &NadjiKnjigu(int evidencijski_broj);
    void IzlistajKorisnike() const;
    void IzlistajKnjige() const;
    void ZaduziKnjigu(int evidencijski_broj, int clanski_broj);
    void RazduziKnjigu(int evidencijski_broj);
    void PrikaziZaduzenja(int clanski_broj) const;
};


Biblioteka::Biblioteka(const Biblioteka &b){
  try{
    for(auto x : b.mapa_korisnika){
      auto pok = std::make_shared<Korisnik>(*(x.second));
      mapa_korisnika.insert(std::make_pair(x.first, pok));
    }
    for(auto y : b.mapa_knjiga){
      auto pok = std::make_shared<Knjiga>(*(y.second));
      mapa_knjiga.insert(std::make_pair(y.first, pok));
    }
  }
    catch(...){
      for(auto x : mapa_korisnika)
        mapa_korisnika.erase(x.first);
      for(auto y : mapa_knjiga)
        mapa_knjiga.erase(y.first);
      throw;
    }
}

Biblioteka::Biblioteka(Biblioteka &&b){
  mapa_knjiga = b.mapa_knjiga;
  mapa_korisnika = b.mapa_korisnika;
  for(auto it=b.mapa_knjiga.begin(); it!=b.mapa_knjiga.end(); it++)
    b.mapa_knjiga.erase(it->first);
  for(auto it=b.mapa_korisnika.begin(); it!=b.mapa_korisnika.end(); it++)
    b.mapa_korisnika.erase(it->first);
}


Biblioteka &Biblioteka::operator= (const Biblioteka &b){
  if(this==&b)
    return *this;
  Biblioteka nova(*this);
  for(auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end(); it++)
    mapa_knjiga.erase(it->first);
  for(auto it=mapa_korisnika.begin(); it!=mapa_korisnika.end(); it++)
    mapa_korisnika.erase(it->first);
  try{
  for(auto it=b.mapa_korisnika.begin(); it!=b.mapa_korisnika.end(); it++){
    auto pok(std::make_shared<Korisnik>(*(it->second)));
    mapa_korisnika.insert(std::make_pair(it->first, pok));
  }
  for(auto it=b.mapa_knjiga.begin(); it!=b.mapa_knjiga.end(); it++){
    auto pok(std::make_shared<Knjiga>(*(it->second)));
    mapa_knjiga.insert(std::make_pair(it->first, pok));
  }
  }
  catch(...){
  for(auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end(); it++)
    mapa_knjiga.erase(it->first);
  for(auto it=mapa_korisnika.begin(); it!=mapa_korisnika.end(); it++)
    mapa_korisnika.erase(it->first);
  for(auto it=nova.mapa_knjiga.begin(); it!=nova.mapa_knjiga.end(); it++)
   mapa_knjiga.insert(std::make_pair(it->first, it->second));
  for(auto it=nova.mapa_korisnika.begin(); it!=nova.mapa_korisnika.end(); it++)
   mapa_korisnika.insert(std::make_pair(it->first, it->second));
   throw;
  }
  return *this;
}

Biblioteka &Biblioteka::operator= (Biblioteka &&b){
  mapa_knjiga = b.mapa_knjiga;
  mapa_korisnika = b.mapa_korisnika;
  for(auto it=b.mapa_knjiga.begin(); it!=b.mapa_knjiga.end(); it++)
    b.mapa_knjiga.erase(it->first);
  for(auto it=b.mapa_korisnika.begin(); it!=b.mapa_korisnika.end(); it++)
    b.mapa_korisnika.erase(it->first);
  return *this;
}

void Biblioteka::RegistrirajNovogKorisnika(int clanski_broj, std::string ime, std::string prezime, std::string adresa, std::string broj_tel){
  auto it(mapa_korisnika.find(clanski_broj));
  if(it!=mapa_korisnika.end())
    throw std::logic_error("Korisnik vec postoji");
  Korisnik k;
  k.ime = ime;
  k.prezime = prezime;
  k.adresa = adresa;
  k.telefon = broj_tel;
  auto pok(std::make_shared<Korisnik>(k));
  mapa_korisnika.insert(std::make_pair(clanski_broj, pok));
}

void Biblioteka::RegistrirajNovuKnjigu(int evidencijski_broj, std::string naslov, std::string ime_pisca, std::string zanr, int godina_izdavanja){
  auto it(mapa_knjiga.find(evidencijski_broj));
  if(it!=mapa_knjiga.end())
      throw std::logic_error("Knjiga vec postoji");
  Knjiga k(naslov, ime_pisca, zanr, godina_izdavanja);
  auto pok(std::make_shared<Knjiga>(k));
  mapa_knjiga.insert(std::make_pair(evidencijski_broj, pok));
}

Korisnik &Biblioteka::NadjiKorisnika(int clanski_broj){
  auto it(mapa_korisnika.find(clanski_broj));
  if(it==mapa_korisnika.end())
    throw std::logic_error("Korisnik nije nadjen");
  return *(it->second);
}

Knjiga &Biblioteka::NadjiKnjigu(int evidencijski_broj){
  auto it(mapa_knjiga.find(evidencijski_broj));
  if(it==mapa_knjiga.end())
    throw std::logic_error("Knjiga nije nadjena");
  return *(it->second);

}

void Biblioteka::IzlistajKorisnike() const{
  for(auto it=mapa_korisnika.begin(); it!=mapa_korisnika.end(); it++){
    std::cout<<"Clanski broj: "<<it->first<<std::endl;
    std::cout<<"Ime i prezime: "<<(*(it->second)).ime<<" "<<(*(it->second)).prezime<<std::endl;
    std::cout<<"Adresa: "<<(*(it->second)).adresa<<std::endl;
    std::cout<<"Broj telefona: "<<(*(it->second)).telefon<<std::endl;
    std::cout<<std::endl;
  }
}


void Biblioteka::IzlistajKnjige() const{
  for(auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end(); it++){
    std::cout<<"Evidencijski broj: "<<it->first<<std::endl;
    std::cout<<"Naslov: "<<(*it->second).DajNaslov()<<std::endl;
    std::cout<<"Pisac: "<<(*it->second).DajAutora()<<std::endl;
    std::cout<<"Zanr: "<<(*it->second).DajZanr()<<std::endl;
    std::cout<<"Godina izdavanja: "<<(*it->second).DajGodinuIzdavanja()<<std::endl;
    if((it->second)->DajKodKogaJe()){
       std::cout<<"Zaduzena kod korisnika: "<<(it->second)->DajKodKogaJe()->ime<<" "<<(it->second)->DajKodKogaJe()->prezime<<std::endl;
      
    }
    std::cout<<std::endl;
  }
}


void Biblioteka::ZaduziKnjigu(int evidencijski_broj, int clanski_broj){
    auto it1(mapa_knjiga.find(evidencijski_broj));
    if(it1==mapa_knjiga.end())
       throw std::logic_error("Knjiga nije nadjena");
    auto it2(mapa_korisnika.find(clanski_broj));
    if(it2==mapa_korisnika.end())
      throw std::logic_error("Korisnik nije nadjen");
    if(it1->second->DajKodKogaJe())
       throw std::logic_error("Knjiga vec zaduzena");
    
    it1->second->Knjiga::ZaduziKnjigu(*it2->second);

}

void Biblioteka::RazduziKnjigu(int evidencijski_broj){
    auto it(mapa_knjiga.find(evidencijski_broj));
    if(it==mapa_knjiga.end())
      throw std::logic_error("Knjiga nije nadjena");
    if(!(it->second->DajKodKogaJe()))
      throw std::logic_error("Knjiga nije zaduzena");
    it->second->Knjiga::RazduziKnjigu();
}

void Biblioteka::PrikaziZaduzenja(int clanski_broj) const{
  auto it(mapa_korisnika.find(clanski_broj));
  if(it==mapa_korisnika.end())
    throw std::logic_error("Korisnik nije nadjen");
  bool ima_knjiga(false);
  for(auto itk=mapa_knjiga.begin(); itk!=mapa_knjiga.end(); itk++){
    if((itk->second->DajKodKogaJe()->ime)==(it->second->ime) && (itk->second->DajKodKogaJe()->prezime==(it->second->prezime)) && itk->second->DajKodKogaJe()->adresa==it->second->adresa && itk->second->DajKodKogaJe()->telefon==it->second->telefon){
      ima_knjiga = true;
      std::cout<<"Evidencijski broj: "<<itk->first<<std::endl;
      std::cout<<"Naslov: "<<itk->second->DajNaslov()<<std::endl;
      std::cout<<"Pisac: "<<itk->second->DajAutora()<<std::endl;
      std::cout<<"Zanr: "<<itk->second->DajZanr()<<std::endl;
      std::cout<<"Godina izdavanja: "<<itk->second->DajGodinuIzdavanja()<<std::endl;
      std::cout<<std::endl;
    }
  }
  if(!ima_knjiga)
    std::cout<<"Nema zaduzenja za tog korisnika!";
}



int main ()
{
   Biblioteka b;
    int prva_opcija;
    std::cout<<"Dobrodosli!\n";
    do{
        std::cout<<"\nIzaberite opciju:\n 0 - kraj\n 1 - obrada korisnika\n 2 - obrada knjiga\n";
        std::cin>>prva_opcija;
        if(prva_opcija==0)
          break;
        if(prva_opcija==1){
            int druga_opcija;
            do{
                std::cout<<"\n\nIzaberite opciju:\n 0 - nazad\n 1 - dodavanje korisnika\n 2 - izlistavanje korisnika\n 3 - prikaz zaduzenja\n 4 - kraj\n";
                std::cin>>druga_opcija;
                if(druga_opcija==0){
                    break;
                }
                if(druga_opcija==4){
                    std::cout<<"Dovidjenja!";
                    return 0;
                }
                if(druga_opcija==1){
                    std::cout<<"Unesite clanski broj korisnika: ";
                    int cl_broj;
                    std::cin>>cl_broj;
                    std::string ime, prezime, adresa, broj_tel;
                    std::cout<<"Unesite ime korisnika: ";
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    std::getline(std::cin, ime);
                    std::cout<<"Unesite prezime korisnika: ";
                    std::getline(std::cin, prezime);
                    std::cout<<"Unesite adresu korisnika: ";
                    std::getline(std::cin, adresa);
                    std::cout<<"Unesite broj telefona korisnika: ";
                    std::getline(std::cin, broj_tel);
                    b.RegistrirajNovogKorisnika(cl_broj, ime, prezime, adresa, broj_tel);
                    std::cout<<"Korisnik uspjesno registrovan!";
                }
                if(druga_opcija==2){
                    b.IzlistajKorisnike();
                }
                
                if(druga_opcija==3){
                    std::cout<<"Unesite clanski broj korisnika: ";
                    int br;
                    std::cin>>br;
                    b.PrikaziZaduzenja(br);
                }
                
            }while(druga_opcija);
            
        }
            if(prva_opcija==2){
                int treca_opcija;
                do{
                    std::cout<<"\nIzaberite opciju:\n 0 - nazad\n 1 - dodavanje knjige\n 2 - ispis knjiga\n 3 - zaduzivanje knjige\n 4 - razduzivanje knjige\n 5 - kraj\n";
                    std::cin>>treca_opcija;
                    if(treca_opcija==0)
                      break;
                    if(treca_opcija==5){
                        std::cout<<"Dovidjenja!\n";
                        return 0;
                    }
                    
                    if(treca_opcija==1){
                        std::string naslov, ime_pisca, zanr;
                        int evidencijski_broj, godina_izdavanja;
                        std::cout<<"Unesite evidencijski broj knjige: ";
                        std::cin>>evidencijski_broj;
                        std::cin.clear();
                        std::cin.ignore(10000, '\n');
                        std::cout<<"Unesite naslov: ";
                        std::getline(std::cin, naslov);
                        std::cout<<"Unesite ime pisca: ";
                        std::getline(std::cin, ime_pisca);
                        std::cout<<"Unesite zanr: ";
                        std::getline(std::cin, zanr);
                        std::cout<<"Unesite godinu izdavanja: ";
                        std::cin>>godina_izdavanja;
                        b.RegistrirajNovuKnjigu(evidencijski_broj, naslov, ime_pisca, zanr, godina_izdavanja);
                        std::cout<<"Knjiga uspjesno evidentirana.\n";
                    }
                    
                    if(treca_opcija==2){
                        b.IzlistajKnjige();
                    }
                    if(treca_opcija==3){
                        int clanski_broj, evidencijski_broj;
                        std::cout<<"Unesite evidencijski broj knjige koju zelite zaduziti: ";
                        std::cin>>evidencijski_broj;
                        std::cout<<"Unesite clanski broj korisnika koji zaduzuje knjigu: ";
                        std::cin>>clanski_broj;
                        b.ZaduziKnjigu(evidencijski_broj, clanski_broj);
                        std::cout<<"Knjiga uspjesno zaduzena!\n";
                    }
                    
                    if(treca_opcija==4){
                        try{
                        int evidencijski_broj;
                        std::cout<<"Unesite evidencijski broj knjige koju zelite razduziti: ";
                        std::cin>>evidencijski_broj;
                        b.RazduziKnjigu(evidencijski_broj);
                        std::cout<<"Knjiga uspjesno razduzena!\n";
                        }
                        catch(std::logic_error e){
                            std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite ponovo.\n";
                        }
                    }
                }while(treca_opcija);
            }
        
    }while(prva_opcija);
	return 0;
}