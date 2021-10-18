/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include<string>
#include<new>
#include<algorithm>
#include<cstring>
#include<map>
#include<stdexcept>
#include<iomanip>
#include<memory>
using namespace std;
struct Korisnik
{
    string ime, prezime, adresa, telefon;
};
class Knjiga
{
  string naslov, ime_pisca, zanr;
  int godina_izdavanja;
  Korisnik *zaduzenje;
  public:
  Knjiga(string naslov, string ime_pisca, string zanr, int godina_izdavanja):naslov(naslov), ime_pisca(ime_pisca), zanr(zanr), godina_izdavanja(godina_izdavanja)
  {
      zaduzenje=nullptr;
  }
  string DajNaslov() const { return naslov;}
  string DajZanr() const { return zanr;}
  string DajAutora() const { return ime_pisca;} 
    int DajGodinuIzdavanja() const { return godina_izdavanja;}
Korisnik *DajKodKogaJe() const { return zaduzenje;}
void ZaduziKnjigu(Korisnik &k) { zaduzenje=&k;}
void RazduziKnjigu() { zaduzenje=nullptr;}
bool DaLiJeZaduzena()
{if(!zaduzenje) return false;
return true; }

};

class Biblioteka
{
    map<int, shared_ptr<Korisnik>> korisnici;
    map<int, shared_ptr<Knjiga>> knjige;
    public:
    Biblioteka() {}
    Biblioteka(const Biblioteka &b)=delete;
    void RegistrirajNovogKorisnika(int clanski_broj, string ime_korisnika, string prezime_korisnika, string adresa, string br_tel);
    void RegistrirajNovuKnjigu(int evid_broj, string naslov, string ime_pisca, string zanr, int godina_izdavanja);
    Korisnik &NadjiKorisnika(int broj);
    Knjiga &NadjiKnjigu(int evid_broj);
    void IzlistajKorisnike() const;
    void IzlistajKnjige() const;
    void ZaduziKnjigu(int broj_knjige, int broj_korisnika);
    void RazduziKnjigu(int broj_knjige);
    void PrikaziZaduzenja(int id_korisnika);

/*~Biblioteka()
{
    for(auto it=korisnici.begin();it!=korisnici.end();it++)
    delete (*it).second;
    for(auto it=knjige.begin();it!=knjige.end();it++)
    delete (*it).second;
} */
};
void Biblioteka::RegistrirajNovogKorisnika(int clanski_broj, string ime_korisnika, string prezime_korisnika, string adresa_korisnika, string br_tel)
{
    for(auto it(korisnici.begin()); it!=korisnici.end();it++)
    if(it->first==clanski_broj) throw logic_error("Korisnik vec postoji");
    try
    {
        
       Korisnik pok;
        pok.ime=ime_korisnika;
        pok.prezime=prezime_korisnika;
        pok.adresa=adresa_korisnika;
        pok.telefon=br_tel; 
        korisnici.insert(make_pair(clanski_broj, make_shared<Korisnik>(pok)));
    }
    catch(bad_alloc)
    {throw; }
}
void Biblioteka::RegistrirajNovuKnjigu(int evid_broj, string Naslov, string ime_pisca, string zanr_knjige, int god)
{
    for(auto it(knjige.begin());it!=knjige.end();it++)
    if(it->first==evid_broj) throw logic_error("Knjiga vec postoji");
    try
    {
        
       Knjiga k(Naslov, ime_pisca, zanr_knjige, god);
        knjige.insert(make_pair(evid_broj, make_shared<Knjiga>(k)));
    }
    catch(bad_alloc)
    {
        throw;
    }
}
Korisnik &Biblioteka::NadjiKorisnika(int broj_korisnika)
{
    auto it(korisnici.find(broj_korisnika));
    if(it==korisnici.end()) throw logic_error("Korisnik nije nadjen");
    else return *it->second;
}
Knjiga &Biblioteka::NadjiKnjigu(int broj_knjige)
{
    auto it(knjige.find(broj_knjige));
    if(it==knjige.end()) throw logic_error("Knjiga nije nadjena");
    else return *it->second;
}
void Biblioteka::IzlistajKorisnike() const
{
    for(auto it(korisnici.begin()); it!=korisnici.end();it++)
    {
        cout<<"Clanski broj: "<<it->first<<endl;
        cout<<"Ime i prezime: "<<it->second->ime<<" "<<it->second->prezime<<endl;
        cout<<"Adresa: "<<it->second->adresa<<endl;
        cout<<"Broj telefona: "<<it->second->telefon<<endl;
        cout<<endl;
    }
}
void Biblioteka::IzlistajKnjige() const

{
    for(auto it(knjige.begin());it!=knjige.end();it++)
    {
        cout<<"Evidencijski broj: "<<it->first<<endl;
        cout<<"Naslov: "<<it->second->DajNaslov()<<endl;
        cout<<"Pisac: "<<it->second->DajAutora()<<endl;
        cout<<"Zanr: "<<it->second->DajZanr()<<endl;
        cout<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<endl;
        if(it->second->DaLiJeZaduzena()) cout<<"Zaduzena kod korisnika: "<<it->second->DajKodKogaJe()->ime<<" "<<it->second->DajKodKogaJe()->prezime<<endl;
        cout<<endl;
    }
}
void Biblioteka::ZaduziKnjigu(int broj_knjige, int broj_korisnika)
{
    auto it1(korisnici.find(broj_korisnika));
    auto it2(knjige.find(broj_knjige));
    if((it1==korisnici.end() && it2==knjige.end()) || it2==knjige.end()) throw logic_error("Knjiga nije nadjena");
    if(it1==korisnici.end()) throw logic_error("Korisnik nije nadjen");
    if(it2->second->DaLiJeZaduzena()) throw logic_error("Knjiga vec zaduzena");
    it2->second->ZaduziKnjigu(*it1->second);
}

void Biblioteka::RazduziKnjigu(int broj)
{
    auto it(knjige.find(broj));
    if(it==knjige.end()) throw logic_error("Knjiga nije nadjena");
    else
    {
        if(it->second->DaLiJeZaduzena())
        it->second->RazduziKnjigu();
        else throw logic_error("Knjiga nije zaduzena");
    }
}

int main()
{
    Korisnik k{"Ja", "Jahic", "Sigismundska 15", "035/156-652"};
    Knjiga nova("Moja knjiga, nisam joj još dao ime", "Ja Jahic", "Roman", 2017);
    if(nova.DajKodKogaJe()==nullptr) cout<<"Moja knjiga nije zaduzena, ne dam je";
    cout<<endl;
    cout<<nova.DaLiJeZaduzena()<<endl;
    nova.ZaduziKnjigu(k);
    cout<<"Knjigu je zaduzio "<<nova.DajKodKogaJe()->ime<<endl;
    cout<<nova.DaLiJeZaduzena()<<endl;
    return 0;
}