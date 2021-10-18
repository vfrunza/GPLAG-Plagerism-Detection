/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>

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
    map<int,Korisnik*> klijenti;
    map<int,Knjiga*> knjige;
  
  public:
  Biblioteka(){};
  Biblioteka(Biblioteka &b)
  {
      for(auto i:b.klijenti)
      {
          klijenti[i.first]=new Korisnik(*i.second);
      }
      for(auto i:b.knjige)
      {
          knjige[i.first]=new Knjiga(*i.second);
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
            delete i.second;
        for(auto &i:knjige)
            delete i.second;
            
         for(auto i:b.klijenti)
         {
             klijenti[i.first]=new Korisnik(*i.second);
         }
        
      for(auto i:b.knjige)
      {
          knjige[i.first]=new Knjiga(*i.second);
      }
      }
      return *this;
  }
  Biblioteka &operator=(Biblioteka &&b)
  {
       if(this!=&b)
      {
         for(auto &i:klijenti)
            delete i.second;
        for(auto &i:knjige)
            delete i.second;
            
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
            delete i.second;
      for(auto &i:knjige)
            delete i.second;
  }
  
  void RegistrirajNovogKorisnika(int br,string ime,string prezime,string adresa,string telefon)
  {
      for(auto i=klijenti.begin(); i!=klijenti.end();i++)
            if(i->first==br) throw logic_error("Korisnik vec postoji");
      klijenti[br]=new Korisnik(ime,prezime,adresa,telefon);
  }
  void RegistrirajNovuKnjigu(int br,string ime,string pisac,string zanr,int godina)
  {
      for(auto i=knjige.begin(); i!=knjige.end();i++)
            if(i->first==br) throw logic_error("Knjiga vec postoji");
      knjige[br]=new Knjiga(ime,pisac,zanr,godina);
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
      NadjiKnjigu(brK);NadjiKorisnika(brU);
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
  /*  Biblioteka b;
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
    
    */
    
    Biblioteka b;
b.RegistrirajNovogKorisnika(1234, "Petar", "Petrovic",
"Zmaja od Bosne 30", "032/444-555");
b.RegistrirajNovogKorisnika(4312, "Hasan", "Hasanovic",
"Trg neznalica 111", "030/111-222");
b.RegistrirajNovogKorisnika(3124, "Mehmed", "Mehmedovic",
"Studenata etfovaca 3b", "037/654-321");
b.RegistrirajNovuKnjigu(231, "Prokleta avlija", "Ivo Andric", "Roman", 1955);
b.RegistrirajNovuKnjigu(555, "Grimove Bajke", "Braca Grim", "Bajke", 1927);
b.RegistrirajNovuKnjigu(136, "Kameni spavac", "Mak Dizdar", "Poezija", 1960);
b.ZaduziKnjigu(231, 1234);
b.ZaduziKnjigu(136, 1234);
b.PrikaziZaduzenja(1234);
    
	return 0;
}