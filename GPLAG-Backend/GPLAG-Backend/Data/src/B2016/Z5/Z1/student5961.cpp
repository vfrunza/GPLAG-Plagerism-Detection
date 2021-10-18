/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
using std::string;
struct Korisnik{
    string ime,prezime,adresa,telefon;
};
class Knjiga{
    string naslov_knjige,ime_pisca,zanr;
    int godina_izdavanja;
    Korisnik* zaduzenje=nullptr;
public:  
    Knjiga (string n, string i, string z, int g){
        naslov_knjige=n; ime_pisca=i; zanr=z; godina_izdavanja=g;
    }
    string DajNaslov() const{ return naslov_knjige; }
    string DajAutora() const { return ime_pisca; }
    string DajZanr() const { return zanr; }
    int DajGodinuIzdavanja() const{ return godina_izdavanja; }
    Korisnik* DajKodKogaJe() const { return zaduzenje; }
    void ZaduziKnjigu (Korisnik &a) { zaduzenje=&a; }
    void RazduziKnjigu () {zaduzenje=nullptr; }
    bool DaLiJeZaduzena() { return (!zaduzenje); }
};
class Biblioteka{
  std::map<int,Korisnik*> mapa_korisnika;
  std::map<int,Knjiga*> mapa_knjiga;
  public:
  void RegistrirajNovogKorisnika() {}
  void RegistrirajNovuKnjigu() {}
};
int main ()
{
	return 0;
}