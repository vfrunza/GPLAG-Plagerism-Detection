/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <stdexcept>
#include <iostream>
#include <string>
#include <map>

using namespace std;

struct Korisnik {
    string ime, prezime, adresa, telefon;
};

class Knjiga {
    string Naslov, ImePisca, Zanr;
    int GodinaIzdavanja;
    Korisnik *pok;
    public:
    Knjiga(string naslov_knjige, string ime_pisca, string zanr_knjige, int god_izdanja)
    {
        Naslov=naslov_knjige;
        ImePisca=ime_pisca;
        Zanr=zanr_knjige;
        GodinaIzdavanja=god_izdanja;
        pok=nullptr;
    };
    string DajNaslov() const { return Naslov; };
    string DajAutora() const { return ImePisca; };
    string DajZanr() const { return Zanr; };
    int DajGodinuIzdavanja() const { return GodinaIzdavanja; };
    Korisnik* DajKodKogaJe() const { return pok; };
    void ZaduziKnjigu(Korisnik &k) { pok=&k; };
    void RazduziKnjigu() { pok=nullptr; };
    bool DaLiJeZaduzena() { if(pok!=nullptr) return true; else return false; };
};

class Biblioteka {
      map< int, Korisnik* > korisnici;
      map< int, Knjiga*   > knjige;
      public:
      Biblioteka(){}
      Biblioteka( const Biblioteka &bib)
      {
      }
      Biblioteka( Biblioteka && bib);
      Biblioteka &operator =(const Biblioteka &bib);
      Biblioteka &operator =(Biblioteka &&bib);
      ~Biblioteka() { 
         
          for (auto it=korisnici.begin();it!=korisnici.end();it++)
              delete it->second;
               for (auto it=knjige.begin();it!=knjige.end();it++)
              delete it->second;
      }
      void RegistrirajNovogKorisnika( int clanski_broj, string ime, string prezime, string adresa, string br_telefona)
      {
          korisnici[clanski_broj]=new Korisnik;
          korisnici[clanski_broj]->ime=ime,
          korisnici[clanski_broj]->prezime=prezime;
          korisnici[clanski_broj]->adresa=adresa;
          korisnici[clanski_broj]->telefon=br_telefona;
      }
      void RegistrirajNovuKnjigu(int ev_broj, string naslov, string ime_pisca, string z, int god_izdanja)
      {
          knjige[ev_broj]=new Knjiga(naslov,ime_pisca,z,god_izdanja);
      }
      Korisnik& NadjiKorisnika(int clanski_broj) 
      {
          return *korisnici[clanski_broj];
      }
      Knjiga& NadjiKnjigu(int ev_broj) 
      {
          return *knjige[ev_broj];
      }
      
      void IzlistajKorisnike() const;
      void IzlistajKnjige() const;
      void ZaduziKnjigu(int ev_broj, int clanski_broj);
      void RazduziKnjigu(int ev_broj);
      void PrikaziZaduzenja(int clanski_broj);
};

int main()
{
    return 0;
}
