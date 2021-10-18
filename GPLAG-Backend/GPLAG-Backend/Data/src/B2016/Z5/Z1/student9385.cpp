/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <stdexcept>
#include <map>
using namespace std;

struct Korisnik {
  string ime, prezime, adresa, telefon;
  friend class Knjiga;
};

class Knjiga
{
  string naslov_knjige;
  string ime_pisca;
  string zanr;
  int godina_izdavanja;
  Korisnik *zaduzenje;
public:
  friend struct Korisnik;
  Knjiga(string naslov_knjige, string ime_pisca, string zanr, int godina_izdavanja) {
    Knjiga::naslov_knjige=naslov_knjige;
    Knjiga::ime_pisca=ime_pisca;
    Knjiga::zanr=zanr;
    Knjiga::godina_izdavanja=godina_izdavanja;
    zaduzenje=nullptr; //na pocetku nijedna knjiga nije zaduzena
  }

  //geteri
  string DajNaslov() const {
    return naslov_knjige;
  }
  string DajAutora() const {
    return ime_pisca;
  }
  string DajZanr() const {
    return zanr;
  }
  int DajGodinuIzdavanja() const {
    return godina_izdavanja;
  }
  Korisnik *DajKodKogaJe() const {
    return zaduzenje;
  }

  //seteri
  void ZaduziKnjigu (Korisnik &korisnik) {
    zaduzenje = &korisnik;
  }

  void RazduziKnjigu() {
    zaduzenje=nullptr;
  }

  bool DaLiJeZaduzena() const {
    if(zaduzenje!=nullptr) return true;
    return false;
  }

};

class Biblioteka
{
  map<int,Korisnik*> mapa_korisnika;
  map<int,Knjiga*> mapa_knjiga;
public:
  Biblioteka() {}
  ~Biblioteka() {
    for(auto it = mapa_korisnika.begin() ; it != mapa_korisnika.end(); it++)
      delete it->second;
    mapa_korisnika.clear();
    for(auto it = mapa_knjiga.begin() ; it != mapa_knjiga.end(); it++)
      delete it->second;
    mapa_knjiga.clear();
  }

  Biblioteka(const Biblioteka &b) {
    for(auto it = b.mapa_korisnika.begin(); it != b.mapa_korisnika.end(); it++)
      mapa_korisnika[it->first] = new Korisnik(*(it->second));
    for(auto it = b.mapa_knjiga.begin(); it != b.mapa_knjiga.end(); it++ )
      mapa_knjiga[it->first] = new Knjiga(*(it->second));
  }

  Biblioteka(Biblioteka &&b) {
    for(auto it = b.mapa_korisnika.begin(); it != b.mapa_korisnika.end(); it++) {
      mapa_korisnika[it->first] = it->second;
      it->second = nullptr;
    }
    for(auto it = b.mapa_knjiga.begin(); it != b.mapa_knjiga.end(); it++ ) {
      mapa_knjiga[it->first] = it->second;
      it->second = nullptr;
    }
  }

  Biblioteka & operator = (const Biblioteka &b) {
    if(&b!=this) {
      for(auto it=mapa_korisnika.begin(); it!=mapa_korisnika.end(); it++) delete it->second; //destruktor
      mapa_korisnika.clear();
      for(auto it = mapa_knjiga.begin() ; it != mapa_knjiga.end(); it++)  delete it->second; //destruktor
      mapa_knjiga.clear();
      for(auto it = b.mapa_korisnika.begin(); it != b.mapa_korisnika.end(); it++) //konstruktor kopije
        mapa_korisnika[it->first] = new Korisnik(*(it->second));
      for(auto it = b.mapa_knjiga.begin(); it != b.mapa_knjiga.end(); it++ ) //konstruktor kopije
        mapa_knjiga[it->first] = new Knjiga(*(it->second));
    }
    return *this;
  }

  Biblioteka & operator = (Biblioteka &&b) {
    if(&b!=this) {
      for(auto it=mapa_korisnika.begin(); it!=mapa_korisnika.end(); it++) delete it->second; //destruktor
      mapa_korisnika.clear();
      for(auto it = mapa_knjiga.begin() ; it != mapa_knjiga.end(); it++)  delete it->second; //destruktor
      mapa_knjiga.clear();
      for(auto it = b.mapa_korisnika.begin(); it != b.mapa_korisnika.end(); it++) {
        mapa_korisnika[it->first] = it->second;
        it->second = nullptr;
      }
      for(auto it = b.mapa_knjiga.begin(); it != b.mapa_knjiga.end(); it++ ) {
        mapa_knjiga[it->first] = it->second;
        it->second = nullptr;
      }
    }
    return *this;
  }

  void RegistrirajNovogKorisnika(int clanski_broj, string ime, string prezime, string adresa, string br_telefona) {
    if(mapa_korisnika.find(clanski_broj)!=mapa_korisnika.end()) throw std::logic_error("Korisnik vec postoji");
    auto x = new Korisnik();
    x->ime = ime;
    x->prezime = prezime;
    x->adresa = adresa;
    x->telefon = br_telefona;
    mapa_korisnika[clanski_broj]= x;
  }

  void RegistrirajNovuKnjigu(int broj_knjige, string naslov, string ime_pisca, string zanr, int godina_izdavanja) {
    if(mapa_knjiga.find(broj_knjige)!=mapa_knjiga.end()) throw std::logic_error("Knjiga vec postoji");
    mapa_knjiga[broj_knjige]=new Knjiga(naslov, ime_pisca, zanr, godina_izdavanja);
  }

  Korisnik  &NadjiKorisnika(int clanski_broj) {
    if(mapa_korisnika.find(clanski_broj)==mapa_korisnika.end()) throw std::logic_error("Korisnik nije nadjen");
    return *(mapa_korisnika[clanski_broj]);
  }

  Knjiga &NadjiKnjigu (int evidencijski_broj) {
    if(mapa_knjiga.find(evidencijski_broj)==mapa_knjiga.end()) throw std::logic_error("Knjiga nije nadjena");
    return *(mapa_knjiga[evidencijski_broj]);
  }

  void IzlistajKorisnike() const {
    for(auto it= mapa_korisnika.begin() ; it!=mapa_korisnika.end() ; it++) {
      cout<<"Clanski broj: "<<it->first<<endl;
      cout<<"Ime i prezime: "<<it->second->ime<<" "<<it->second->prezime<<endl;
      cout<<"Adresa: "<<it->second->adresa<<endl;
      cout<<"Broj telefona: "<<it->second->telefon<<endl;
    }
  }

  void IzlistajKnjige() const {
    for(auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end(); it++) {
      cout<<"Evidencijski broj: "<<it->first<<endl;
      cout<<"Naslov: "<<it->second->DajNaslov()<<endl;
      cout<<"Pisac: "<<it->second->DajAutora()<<endl;
      cout<<"Zanr: "<<it->second->DajZanr()<<endl;
      cout<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<endl;

      if(it->second->DaLiJeZaduzena()) cout<<"Zaduzena kod korisnika: "<<it->second->DajKodKogaJe()->ime<<" "<<it->second->DajKodKogaJe()->prezime<<endl;
      cout<<endl;
    }
  }

  void ZaduziKnjigu(int evidencijski_broj , int clanski_broj) {
    if(mapa_knjiga.find(evidencijski_broj)==mapa_knjiga.end()) throw std::logic_error("Knjiga nije nadjena");
    if(mapa_korisnika.find(clanski_broj)==mapa_korisnika.end()) throw std::logic_error("Korisnik nije nadjen");
    if(mapa_knjiga[evidencijski_broj]->DajKodKogaJe()!=nullptr) throw std::logic_error("Knjiga vec zaduzena");
    mapa_knjiga[evidencijski_broj]->ZaduziKnjigu(*mapa_korisnika[clanski_broj]);
  }

  void RazduziKnjigu(int evidencijski_broj) {
    if(mapa_knjiga.find(evidencijski_broj)==mapa_knjiga.end()) throw std::logic_error("Knjiga nije nadjena");
    if(mapa_knjiga[evidencijski_broj]->DajKodKogaJe()==nullptr) throw std::logic_error("Knjiga nije zaduzena");
    mapa_knjiga[evidencijski_broj]->RazduziKnjigu();
  }

  void PrikaziZaduzenja (int clanski_broj) {
    if(mapa_korisnika.find(clanski_broj)==mapa_korisnika.end()) throw std::logic_error("Korisnik nije nadjen");
    int br(0);
    for(auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end(); it++) {
      if(it->second->DaLiJeZaduzena() && it->second->DajKodKogaJe() == mapa_korisnika[clanski_broj]) {
        br++;
        cout<<"Evidencijski broj: "<<it->first<<endl;
        cout<<"Naslov: "<<it->second->DajNaslov()<<endl;
        cout<<"Pisac: "<<it->second->DajAutora()<<endl;
        cout<<"Zanr: "<<it->second->DajZanr()<<endl;
        cout<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<endl;
      }
    }
    if(br==0) cout<<"Nema zaduzenja za tog korisnika!";
  }

};

int main ()
{
  int n;
  Biblioteka prvi;
  Biblioteka drugi;
  do {
    cout<<"Dobrodosli! Izaberite opciju (1- korisnik , 2- knjiga , 0 kraj): "<<endl;
    cin>>n;
    if(n==1) {
      cout<<"Izaberite neku od sljedecih opcija ili 0 za kraj: "<<endl;
      cout<<"1- Registriraj novog korisnika"<<endl<<"2- nadji korisnika"<<endl<<"3-izlistaj korisnika"<<endl;
      int m;
      cout<<"Opcija: ";
      cin>>m;
      if(m==0) {
        cout<<"Hvala sto ste nas posjetili!";
        return 0;
      }
      if(m==1) {
        string ime,prezime,adresa,tel;
        int clanski_broj;
        cout<<"Unesite ime,prezime,adresu,telefon i clanski broj"<<endl;
        cin.ignore(1000, '\n');
        cout<<"Ime: ";
        getline(cin,ime);
        cout<<"Prezime: ";
        getline(cin,prezime);
        cout<<"Adresa: ";
        getline(cin,adresa);
        cout<<"Telefon: ";
        getline(cin,tel);
        cout<<"Clanski broj: ";
        cin>>clanski_broj;
        prvi.RegistrirajNovogKorisnika(clanski_broj,ime,prezime,adresa,tel);
      }
      if(m==2) {
        cout<<"Zelite da nadjete korisnika? Ukucajte clanski broj: ";
        int clanski_broj;
        cin>>clanski_broj;
        try {
          prvi.NadjiKorisnika(clanski_broj);
        } catch(logic_error e) {
          cout<<e.what()<<endl;
        }
      }
      if(m==3) {
        prvi.IzlistajKorisnike();
      }
    }

    if(n==2) {
      cout<<"Izaberite neku od sljedecih opcija ili 0 za kraj: "<<endl;
      cout<<"1- Registriraj novu knjigu"<<endl<<"2- nadji knjigu"<<endl<<"3-izlistaj knjige"<<endl;
      cout<<"4- zaduzi knjigu"<<endl<<"5- razduzi knjigu"<<endl<<"6- prikazi zaduzenja"<<endl;
      int m;
      cin>>m;
      if(m==1) {
        int broj_knjige;
        string naslov, ime_pisca, zanr;
        int godina_izdavanja;
        cout<<"Broj knjige:";
        cin>>broj_knjige;
        cin.ignore(1000,'\n');
        cout<<"Naslov: ";
        getline(cin,naslov);
        cout<<"Ime pisca: ";
        getline(cin,ime_pisca);
        cout<<"Zanr: ";
        getline(cin,zanr);
        cout<<"Godina izdavanja: ";
        cin>>godina_izdavanja;
        drugi.RegistrirajNovuKnjigu(broj_knjige, naslov, ime_pisca, zanr, godina_izdavanja);
      }

      if(m==2) {
        int evidencijski_broj;
        cout<<"Unesite evidencijski broj knjige koju zelite da nadjete: ";
        cin>>evidencijski_broj;
        try {
          drugi.NadjiKnjigu(evidencijski_broj);
        } catch(logic_error e) {
          cout<<e.what()<<endl;
        }
      }

      if(m==3) {
        drugi.IzlistajKnjige();
      }

      if(m==4) {
        int a,b;
        cout<<"Evidencijski broj: ";
        cin>>a;
        cout<<"Clanski broj: ";
        cin>>b;
        try {
        drugi.ZaduziKnjigu(a,b);
        }
        catch(logic_error e) {
          cout<<e.what()<<endl;
        }
      }

      if(m==5) {
        int a;
        cout<<"Evidencijski broj: ";
        cin>>a;
        try {
          drugi.RazduziKnjigu(a);
        } catch(logic_error e) {
          cout<<e.what()<<endl;
        }
      }

      if(m==6) {
        int clanski_broj;
        cout<<"Clanski broj: ";
        cin>>clanski_broj;
        try {
          drugi.PrikaziZaduzenja(clanski_broj);
        } catch(logic_error e) {
          cout<<e.what()<<endl;
        }
      }
    }

    if(n==0) {
      cout<<"Dovidjenja!";
    }

  } while (n!=0);

  return 0;
}