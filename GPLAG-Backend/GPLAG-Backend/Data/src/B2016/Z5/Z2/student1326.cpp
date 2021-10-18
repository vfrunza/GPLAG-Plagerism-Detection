/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <map>
#include <stdexcept>
#include <memory>

using namespace std;

struct Korisnik
{
    string ime,prezime,adresa,telefon;
    friend bool operator==(const Korisnik &K,const Korisnik &K1)
    {
        return K1.ime==K.ime && K1.prezime==K.prezime && K1.adresa==K.adresa && K1.telefon==K.telefon; 
    }
};


class Knjiga
{
  string Naslov,ImePisca,Zanr;
  int God;
  Korisnik *K;
  
  public:
  Knjiga(string Naslov,string ImePisca,string Zanr,int godina):Naslov(Naslov),ImePisca(ImePisca),Zanr(Zanr),God(godina),K(nullptr){}
  string DajNaslov()const{return Naslov;}
  string DajAutora()const{return ImePisca;}
  string DajZanr()const{return Zanr;}
  int DajGodinuIzdavanja()const{return God;}
  Korisnik DajKodKogaJe()const{return *K;}
  Korisnik *DajKodKogaJe(){return K;}
  void ZaduziKnjigu(Korisnik &K){Knjiga::K=&K;}
  void RazduziKnjigu(){Knjiga::K=nullptr;}
  bool DaLiJeZaduzena(){return K!=nullptr;}
};


class Biblioteka
{
    map<int,shared_ptr<Korisnik>>Korisnici;
    map<int,shared_ptr<Knjiga>>Knjige;
    
    public:
    Biblioteka(){};
    Biblioteka(Biblioteka &b);
    Biblioteka(Biblioteka &&b);
    Biblioteka &operator=(Biblioteka &b);
    Biblioteka &operator=(Biblioteka &&b);
    ~Biblioteka();
    void RegistrirajNovogKorisnika(int br,string ime,string prezime,string adresa,string telefon);
    void RegistrirajNovuKnjigu(int br,string ime,string autor,string zanr,int godina);
    Korisnik &NadjiKorisnika(int index);
    Knjiga &NadjiKnjigu(int index);
    void IzlistajKorisnike();
    void IzlistajKnjige();
    void ZaduziKnjigu(int index_knjige,int index_korisnika);
    void RazduziKnjigu(int index);
    void PrikaziZaduzenja(int index);
    
};

Biblioteka::Biblioteka(Biblioteka &b)
{
    for(auto i:b.Korisnici)
        Biblioteka::Korisnici.insert(make_pair(i.first,make_shared<Korisnik>(*i.second)));
    for(auto i:b.Knjige)
        Biblioteka::Knjige.insert(make_pair(i.first,make_shared<Knjiga>(*i.second)));
}

Biblioteka::Biblioteka(Biblioteka &&b)
{
    for(auto i:b.Korisnici)
        Biblioteka::Korisnici.insert(make_pair(i.first,i.second));
    for(auto i:b.Knjige)
        Biblioteka::Knjige.insert(make_pair(i.first,i.second));
}

 Biblioteka &Biblioteka::operator=(Biblioteka &b)
 {
     if(this!=&b) return *this;
     
     
        for(auto &i:Korisnici)
            i.second=nullptr;
        for(auto &i:Knjige)
            i.second=nullptr;
        
        for(auto i:b.Korisnici)
            Biblioteka::Korisnici.insert(make_pair(i.first,make_shared<Korisnik>(*i.second)));
        for(auto i:b.Knjige)
            Biblioteka::Knjige.insert(make_pair(i.first,make_shared<Knjiga>(*i.second)));
        
     return *this;
 }
 Biblioteka &Biblioteka::operator=(Biblioteka &&b)
 {
        if(this!=&b) return *this;
     
        for(auto &i:Korisnici)
            i.second=nullptr;
        for(auto &i:Knjige)
            i.second=nullptr;
     
        for(auto i:b.Korisnici)
            Biblioteka::Korisnici.insert(make_pair(i.first,i.second));
        for(auto i:b.Knjige)
            Biblioteka::Knjige.insert(make_pair(i.first,i.second));
        
        return *this;
 }
   

Biblioteka::~Biblioteka()
{
    for(auto &i:Korisnici)
        i.second=nullptr;
    for(auto &i:Knjige)
       i.second=nullptr;
}


void Biblioteka::RegistrirajNovogKorisnika(int index,string ime,string prezime,string adresa,string telefon)
{
    for(auto i:Korisnici) if(index==i.first) throw logic_error("Korisnik vec postoji");
    Korisnik K{ime,prezime,adresa,telefon};
    Korisnici.insert(make_pair(index,make_shared<Korisnik>(K)));
}
void Biblioteka::RegistrirajNovuKnjigu(int index,string ime,string autor,string zanr,int godina)
{   
    for(auto i:Knjige) if(index==i.first) throw logic_error("Knjiga vec postoji");
    Knjige.insert(make_pair(index,make_shared<Knjiga>(ime,autor,zanr,godina)));

}
Korisnik &Biblioteka::NadjiKorisnika(int index)
{
    return *Korisnici[index];
}
Knjiga &Biblioteka::NadjiKnjigu(int index)
{
    return *Knjige[index];
}
void Biblioteka::IzlistajKorisnike()
{
    for(auto i:Korisnici)
    {
        cout<<"Clanski broj: "<<i.first<<endl;
        cout<<"Ime i prezime: "<<i.second->ime<<" "<<i.second->prezime<<endl;
        cout<<"Adresa: "<<i.second->adresa<<endl;
        cout<<"Broj telefona: "<<i.second->telefon<<endl<<endl;
    }
}
void Biblioteka::IzlistajKnjige()
{
    for(auto i:Knjige)
    {
        cout<<"Evidencijski broj: "<<i.first<<endl;
        cout<<"Naslov: "<<i.second->DajNaslov()<<endl;
        cout<<"Pisac: "<<i.second->DajAutora()<<endl;
        cout<<"Zanr: "<<i.second->DajZanr()<<endl;
        cout<<"Godina izdavanja: "<<i.second->DajGodinuIzdavanja()<<endl;
        if(i.second->DajKodKogaJe()!=nullptr){
            cout<<"Zaduzena kod korisnika: "<<i.second->DajKodKogaJe()->ime;
            cout<<" "<<i.second->DajKodKogaJe()->prezime<<endl;
        }
        cout<<endl;
    }
}
void Biblioteka::ZaduziKnjigu(int index_knjige,int index_korisnika)
{
    Knjige[index_knjige]->ZaduziKnjigu(*Korisnici[index_korisnika]);
}
void Biblioteka::RazduziKnjigu(int index)
{
    Knjige[index]->RazduziKnjigu();
}
void Biblioteka::PrikaziZaduzenja(int index)
{
    for(auto i:Korisnici)
    {
        for(auto j:Knjige)
        {
            if(*i.second==*j.second->DajKodKogaJe())
            {
                cout<<"Evidencijski broj: "<<j.first<<endl;
                cout<<"Naslov: "<<j.second->DajNaslov()<<endl;
                cout<<"Pisac: "<<j.second->DajAutora()<<endl;
                cout<<"Zanr: "<<j.second->DajZanr()<<endl;
                cout<<"Godina izdavanja: "<<j.second->DajGodinuIzdavanja()<<endl<<endl;
                
            }
        }
    }
}

int main ()
{
	return 0;
}