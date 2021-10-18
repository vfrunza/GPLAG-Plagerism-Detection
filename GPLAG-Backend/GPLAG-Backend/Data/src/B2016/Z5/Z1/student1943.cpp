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
};

class Knjiga {
    std::string naslov;
    std::string ime_pisca;
    std::string zanr;
    int godina_izdavanja;
    Korisnik *kod_koga_je;
    public:
    Knjiga(std::string naslov,std::string ime_pisca,std::string zanr,int godina_izdavanja) :
    naslov(naslov),ime_pisca(ime_pisca),zanr(zanr),godina_izdavanja(godina_izdavanja) {
        kod_koga_je=nullptr;
    }
    std::string DajNaslov() const { return naslov; }
    std::string DajAutora() const { return ime_pisca; }
    std::string DajZanr() const { return zanr; }
    int DajGodinuIzdavanja() const { return godina_izdavanja; }
    Korisnik *DajKodKogaJe() const { return kod_koga_je; }
    void ZaduziKnjigu(Korisnik &k) { kod_koga_je=&k; }
    void RazduziKnjigu() { kod_koga_je=nullptr; }
    bool DaLiJeZaduzena () const {
        if(kod_koga_je!=nullptr) {
            return true;
        }
        return false;
    }
    
};

class Biblioteka {
  std::map<int,Korisnik*> mapa_korisnika;
  std::map<int,Knjiga*> mapa_knjiga;
  public:
  void RegistrirajNovogKorisnika(int broj_korisnika,std::string ime,std::string prezime,std::string adresa,std::string telefon);
  void RegistrirajNovuKnjigu(int broj_knjige,std::string naslov,std::string ime_pisca,std::string zanr,int godina_izdavanja);
  Korisnik &NadjiKorisnika(int broj_korisnika);
  Knjiga &NadjiKnjigu(int broj_knjige);
  void IzlistajKorisnike() const;
  void IzlistajKnjige() const;
  void ZaduziKnjigu(int evidencijski_broj_knjige, int clanski_broj_korisnika);
  void PrikaziZaduzenja(int clanski_broj_korisnika);
  void RazduziKnjigu(int evidencijski_broj_knjige);
  
  ~Biblioteka();
};
void Biblioteka::RegistrirajNovogKorisnika(int broj_korisnika,std::string ime,std::string prezime,std::string adresa,std::string telefon) {
    Korisnik *p(new Korisnik);
    (*p).ime=ime;
    (*p).prezime=prezime;
    (*p).adresa=adresa;
    (*p).telefon=telefon;
    for(auto it=mapa_korisnika.begin();it!=mapa_korisnika.end();it++) {
        if(it->first==broj_korisnika) {
            throw std::logic_error("Korisnik vec postoji");
        }
    }
    mapa_korisnika.insert(std::make_pair(broj_korisnika,p));
}
void Biblioteka::RegistrirajNovuKnjigu(int broj_knjige,std::string naslov,std::string ime_pisca,std::string zanr,int godina_izdavanja) {
    Knjiga *q(new Knjiga(naslov,ime_pisca,zanr,godina_izdavanja));
    for(auto it=mapa_knjiga.begin();it!=mapa_knjiga.end();it++) {
        if(it->first==broj_knjige) {
            throw std::logic_error("Knjiga vec postoji");
        }
    }
    mapa_knjiga.insert(std::make_pair(broj_knjige,q));
}
Korisnik &Biblioteka::NadjiKorisnika(int broj_korisnika) {
    for(auto it=mapa_korisnika.begin();it!=mapa_korisnika.end();it++) {
        if(it->first==broj_korisnika) {
            return *(it->second);
        }
    }
    throw std::logic_error("Korisnik nije nadjen");
}
Knjiga &Biblioteka::NadjiKnjigu(int broj_knjige) {
    for(auto it=mapa_knjiga.begin();it!=mapa_knjiga.end();it++) {
        if(it->first==broj_knjige) {
            return *(it->second);
        }
    }
    throw std::logic_error("Knjiga nije nadjena");
}
void Biblioteka::IzlistajKorisnike() const {
    for(auto it=mapa_korisnika.begin();it!=mapa_korisnika.end();it++) {
        std::cout<<"Clanski broj: "<<it->first<<std::endl;
        std::cout<<"Ime i prezime: "<<(*it->second).ime<<" "<<(*it->second).prezime<<std::endl;
        std::cout<<"Adresa: "<<(*it->second).adresa<<std::endl;
        std::cout<<"Broj telefona: "<<(*it->second).telefon<<std::endl;
        std::cout<<std::endl;
    }
}

void Biblioteka::IzlistajKnjige() const {
    for(auto it=mapa_knjiga.begin();it!=mapa_knjiga.end();it++) {
        std::cout<<"Evidencijski broj: "<<it->first<<std::endl;
        std::cout<<"Naslov: "<<(*it->second).DajNaslov()<<std::endl;
        std::cout<<"Pisac: "<<(*it->second).DajAutora()<<std::endl;
        std::cout<<"Zanr: "<<(*it->second).DajZanr()<<std::endl;
        std::cout<<"Godina izdavanja: "<<(*it->second).DajGodinuIzdavanja()<<std::endl;
        std::cout<<std::endl;
      if((*it->second).DaLiJeZaduzena()==true) {
          std::cout<<"Zaduzena kod korisnika: "<<(it->second->DajKodKogaJe())->ime<<" "<<it->second->DajKodKogaJe()->prezime;
      }
    }
    
}
Biblioteka::~Biblioteka() {
    for(auto it=mapa_korisnika.begin();it!=mapa_korisnika.end();it++) {
        delete it->second;
    }
    for(auto it=mapa_knjiga.begin();it!=mapa_knjiga.end();it++) {
        delete it->second;
    }
}

void Biblioteka::ZaduziKnjigu(int evidencijski_broj_knjige, int clanski_broj_korisnika) {
    bool rez=false;
    for(auto it=mapa_knjiga.begin();it!=mapa_knjiga.end();it++) {
        if((*it->second).DaLiJeZaduzena()==true) {
            throw std::logic_error("Knjiga vec zaduzena");
        }
        if((it->first)==evidencijski_broj_knjige) {
            rez=true;
        }
    }
    if(rez==false) {
        throw std::logic_error("Knjiga nije nadjena");
    }
    rez=false;
    for(auto it=mapa_korisnika.begin();it!=mapa_korisnika.end();it++) {
        if((it->first)==clanski_broj_korisnika) {
            rez=true;
        }
    }
    if(rez==false) {
        throw std::logic_error("Korisnik nije nadjen");
    }
    for(auto it1=mapa_korisnika.begin();it1!=mapa_korisnika.end();it1++) {
        for(auto it2=mapa_knjiga.begin();it2!=mapa_knjiga.end();it2++) {
            if((it1->first)==clanski_broj_korisnika && (it2->first)==evidencijski_broj_knjige) {
                (*it2->second).ZaduziKnjigu((*it1->second));
            }
        }
    }
    
    
    
}
void Biblioteka::RazduziKnjigu(int evidencijski_broj_knjige) {
      if(evidencijski_broj_knjige<0) {
          throw std::logic_error("Knjiga nije nadjena");
      }
      int broj_za_knjigu(-1);
      for(auto it=mapa_knjiga.begin();it!=mapa_knjiga.end();it++) {
          if(it->first==evidencijski_broj_knjige) {
              broj_za_knjigu=it->first;
          }
      }
      if(broj_za_knjigu==-1) {
          throw std::logic_error("Knjiga nije nadjena");
      }
      else {
          for(auto it=mapa_knjiga.begin();it!=mapa_knjiga.end();it++) {
              if(it->second->DaLiJeZaduzena()==true && it->first==evidencijski_broj_knjige ) {
                  it->second->RazduziKnjigu();
              }
              else {
                  throw std::logic_error("Knjiga nije zaduzena");
              }
          }
      }
      
  }
void Biblioteka::PrikaziZaduzenja(int clanski_broj_korisnika) {
    bool jeste(false);
    for(auto it=mapa_korisnika.begin();it!=mapa_korisnika.end();it++) {
        if(it->first==clanski_broj_korisnika) {
            jeste=true;
        }
}
if(jeste==false || clanski_broj_korisnika<0) {
    throw std::logic_error("Korisnik nije nadjen");
}
for(auto it=mapa_knjiga.begin();it!=mapa_knjiga.end();it++) {
    if(it->second->DaLiJeZaduzena()==false && it->first!=clanski_broj_korisnika) {
        throw std::logic_error("Nema zaduzenja za tog korisnika!");
    }
}
for(auto it=mapa_knjiga.begin();it!=mapa_knjiga.end();it++) {
        std::cout<<"Evidencijski broj: "<<it->first<<std::endl;
        std::cout<<"Naslov: "<<(*it->second).DajNaslov()<<std::endl;
        std::cout<<"Pisac: "<<(*it->second).DajAutora()<<std::endl;
        std::cout<<"Zanr: "<<(*it->second).DajZanr()<<std::endl;
        std::cout<<"Godina izdavanja: "<<(*it->second).DajGodinuIzdavanja()<<std::endl;
}
}















int main ()
{
Biblioteka b;
b.RegistrirajNovogKorisnika(1234, "Petar", "Petrovic",
"Zmaja od Bosne 30", "032/444-555");
b.RegistrirajNovogKorisnika(4312, "Hasan", "Hasanovic",
"Trg neznalica 111", "030/111-222");
b.RegistrirajNovogKorisnika(3124, "Mehmed", "Mehmedovic",
"Studenata 3b", "037/654-321");
b.RegistrirajNovuKnjigu(231, "Prokleta avlija", "Ivo Andric", "Roman", 1955);
b.RegistrirajNovuKnjigu(555, "Grimove Bajke", "Braca Grim", "Bajke", 1927);
b.RegistrirajNovuKnjigu(136, "Kameni spavac", "Mak Dizdar", "Poezija", 1960);
b.IzlistajKorisnike();
	return 0;
}