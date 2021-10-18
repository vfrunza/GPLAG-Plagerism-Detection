/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <memory>
using namespace std;

struct Korisnik
{
    string ime,prezime,adresa,telefon;
    Korisnik(string ime,string prezime,string adresa,string telefon):ime(ime),prezime(prezime),adresa(adresa),telefon(telefon){};
    bool JesuIsti(const Korisnik k)const
    {
        return ime==k.ime && prezime==k.prezime && adresa==k.adresa && telefon==k.telefon;
    }
   
};

class Knjiga
{
    string Naziv,Pisac,Zanr;
    int Godina;
    Korisnik *k;
    
    public:
    Knjiga(string Naziv,string Pisac,string Zanr,int Godina):Naziv(Naziv),Pisac(Pisac),Zanr(Zanr),Godina(Godina),k(nullptr){};
    string DajNaslov()const{return Naziv;}
    string DajAutora()const{return Pisac;}
    string DajZanr()const{return Zanr;}
    int DajGodinuIzdavanja()const{return Godina;}
    Korisnik DajKodKogaJe()const{return *k;}
    Korisnik *DajKodKogaJe(){return k;}
    void ZaduziKnjigu(Korisnik &k1)
    {
        k=&k1;
       
    }
    void RazduziKnjigu()
    {
        k=nullptr;
   
    }
    bool DaLiJeZaduzena()
    {
        if(k==nullptr) return false;
        return true;
    }
};

class Biblioteka
{
    map<int,shared_ptr<Korisnik>> klijenti;
    map<int,shared_ptr<Knjiga>> knjige;
  
  public:
  Biblioteka(){};
  Biblioteka(Biblioteka &b)
  {
      for(auto i:b.klijenti)
      {
          klijenti[i.first]=make_shared<Korisnik>(*i.second);
      }
      for(auto i:b.knjige)
      {
          knjige[i.first]=make_shared<Knjiga>(*i.second);
      }
  }
  Biblioteka(Biblioteka &&b)
  {
      for(auto i:b.klijenti)
      {
          klijenti[i.first]=i.second;
      }
      
      for(auto i:b.knjige)
      {
          knjige[i.first]=i.second;
      }
  }
  Biblioteka &operator=(Biblioteka &b)
  {
      if(this!=&b)
      {
         for(auto &i:klijenti)
                i.second=nullptr;
        for(auto &i:knjige)
            i.second=nullptr;
            
         for(auto i:b.klijenti)
         {
             klijenti[i.first]=make_shared<Korisnik>(*i.second);
         }
        
      for(auto i:b.knjige)
      {
          knjige[i.first]=make_shared<Knjiga>(*i.second);
      }
      }
      return *this;
  }
  Biblioteka &operator=(Biblioteka &&b)
  {
       if(this!=&b)
      {
         for(auto &i:klijenti)
            i.second=nullptr;
        for(auto &i:knjige)
            i.second=nullptr;
            
         for(auto i:b.klijenti)
         {
             klijenti[i.first]=i.second;
         }
         
      for(auto i:b.knjige)
      {
          knjige[i.first]=i.second;
      }
        
      }
      return *this;
  }
  ~Biblioteka()
  {
      for(auto &i:klijenti)
            i.second=nullptr;
      for(auto &i:knjige)
            i.second=nullptr;
  }
  
  void RegistrirajNovogKorisnika(int br,string ime,string prezime,string adresa,string telefon)
  {
      for(auto i=klijenti.begin(); i!=klijenti.end();i++)
            if(i->first==br) throw logic_error("Korisnik vec postoji");
      klijenti[br]=make_shared<Korisnik>(ime,prezime,adresa,telefon);
  }
  void RegistrirajNovuKnjigu(int br,string ime,string pisac,string zanr,int godina)
  {
      for(auto i=knjige.begin(); i!=knjige.end();i++)
            if(i->first==br) throw logic_error("Knjiga vec postoji");
      knjige[br]=make_shared<Knjiga>(ime,pisac,zanr,godina);
  }
  Korisnik &NadjiKorisnika(int br)
  {
      bool a=true;
      for(auto i=klijenti.begin(); i!=klijenti.end(); i++) if(i->first==br) a=false;
      if(a)throw logic_error("Korisnik nije nadjen");
      return *klijenti[br];
  }
  Knjiga &NadjiKnjigu(int br)
  {
      bool a=true;
      for(auto i=knjige.begin(); i!=knjige.end(); i++) if(i->first==br) a=false;
      if(a)throw logic_error("Knjiga nije nadjena");
      return *knjige[br];
  }
  void IzlistajKorisnike()
  {
      for(auto i:klijenti)
      {
          cout<<"Clanski broj: "<<i.first<<endl;
          cout<<"Ime i prezime: "<<i.second->ime<<" "<<i.second->prezime<<endl;
          cout<<"Adresa: "<<i.second->adresa<<endl;
          cout<<"Broj telefona: "<<i.second->telefon<<endl;
          cout<<endl;
      }
  }
  void IzlistajKnjige()
  {
      for(auto i:knjige)
      {
          cout<<"Evidencijski broj: "<<i.first<<endl;
          cout<<"Naslov: "<<i.second->DajNaslov()<<endl;
          cout<<"Pisac: "<<i.second->DajAutora()<<endl;
          cout<<"Zanr: "<<i.second->DajZanr()<<endl;
          cout<<"Godina izdavanja: "<<i.second->DajGodinuIzdavanja()<<endl;
          if(i.second->DajKodKogaJe()!=nullptr)
            cout<<"Zaduzena kod korisnika: "<<i.second->DajKodKogaJe()->ime<<" "<<i.second->DajKodKogaJe()->prezime<<endl;
          cout<<endl;
      }
  }
  void ZaduziKnjigu(int brK,int brU)
  {
      knjige[brK]->ZaduziKnjigu(*klijenti[brU]);
  }
  void RazduziKnjigu(int br)
  {
      knjige[br]->RazduziKnjigu();
  }
  void PrikaziZaduzenja(int br)
  {
      bool a=true;
        for(auto x: klijenti) if(x.first==br) a=false;
        if(a) throw logic_error("Korisnik nije nadjen");
      for(auto i:knjige)
      {
          if(klijenti[br]->JesuIsti(*i.second->DajKodKogaJe()))
          {
              cout<<"Evidencijski broj: "<<i.first<<endl;
              cout<<"Naslov: "<<i.second->DajNaslov()<<endl;
              cout<<"Pisac: "<<i.second->DajAutora()<<endl;
              cout<<"Zanr: "<<i.second->DajZanr()<<endl;
              cout<<"Godina izdavanja: "<<i.second->DajGodinuIzdavanja()<<endl;
              cout<<endl;
         }
      }
  }
};


int main ()
{   
    Biblioteka b;
   // Korisnik k("Helo","world","cao","12345");
   // cout<<k.ime<<"->"<<k.telefon<<endl;
    
    b.RegistrirajNovogKorisnika(1,"Bravo","Ti","Zmaj Curenja 12","023456789");
    b.RegistrirajNovogKorisnika(2,"Hello","World","put ocaja 15","061234242");
    b.RegistrirajNovogKorisnika(3,"Cao","Zdravo","Gori zeljma 10","02313131");
    b.IzlistajKorisnike();
   
    b.RegistrirajNovuKnjigu(1,"Bajke neke","Neki tamo","Fantazija",1995);
    b.RegistrirajNovuKnjigu(2,"Stihovi Sabana","Tamo neki","Biografija",1990);
    b.RegistrirajNovuKnjigu(3,"Ko to tamo mapira","Ko ce Drugi","Strucna",2015);
    b.IzlistajKnjige();
   
    b.ZaduziKnjigu(1,1);
    b.ZaduziKnjigu(2,2);
    b.ZaduziKnjigu(3,1);
    b.PrikaziZaduzenja(1);
    b.PrikaziZaduzenja(2);

    cout<<endl<<"ok"<<endl<<endl;


    b.IzlistajKnjige();
    b.RazduziKnjigu(1);
    b.IzlistajKnjige();
    
    Biblioteka b1(b);
    cout<<"Odavdje->>>"<<endl;
    b1.IzlistajKnjige();
    cout<<"<<<-Dovdje"<<endl;
    
    
    Biblioteka b2=b1;
    cout<<"Odavdje 1->>>"<<endl;
    b2.IzlistajKnjige();
    cout<<"<<<-2 Dovdje"<<endl;
    
    
	return 0;
}