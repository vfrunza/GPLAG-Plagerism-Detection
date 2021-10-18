/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include<map>
#include<string>
#include<algorithm>
#include<memory>
struct Korisnik {
  std::string ime,prezime,adresa,telefon;
};

class Knjiga
{
  std::string naslov_knjige,ime_pisca,zanr;
  int godina_izdavanja;
  Korisnik*zaduzenje;
public:

  Knjiga( std::string naslov_knjige,std::string ime_pisca, std::string zanr, int godina_izdavanja ): naslov_knjige(naslov_knjige),ime_pisca(ime_pisca),
    zanr(zanr),godina_izdavanja(godina_izdavanja),zaduzenje(nullptr) {
  }

  std::string DajNaslov()const {
    return naslov_knjige;
  }

  std::string DajAutora()const {
    return ime_pisca;
  }

  std::string DajZanr()const {
    return zanr;
  }

  int DajGodinuIzdavanja()const {
    return godina_izdavanja;
  }

  Korisnik* DajKodKogaJe()const {
    return zaduzenje;
  }

  void ZaduziKnjigu(Korisnik &k) {
    zaduzenje=&k;
  }

  void RazduziKnjigu() {
    zaduzenje=nullptr;
  }

  bool DaLiJeZaduzena()const {
    if(zaduzenje!=nullptr) {
      return true;
    }
    return false;
  }

};

class Biblioteka
{
  std::map<int, std::shared_ptr<Korisnik> > korisnici;
  std::map<int, std::shared_ptr<Knjiga> > knjige;

public:

  Biblioteka() {}

  Biblioteka(const Biblioteka &b) {

    for(auto &x : b.korisnici) {
      korisnici[x.first]=std::make_shared< Korisnik >(*(x.second)) ; //prepisujemo clanski broj i alociramo prostor novi za korisnika koji inicijaliziramo na odg vrijednosti;
    }
    for(auto &x : b.knjige) {
      knjige[x.first]=std::make_shared< Knjiga> (*(x.second) ); //prepisujemo evidencijski broj i alociramo prostor novi za knjgu koji inicijaliziramo na odg vrijednosti; sa tim da moramo pok na zaduzenje premjestiti !
      (*(knjige[x.first])).RazduziKnjigu(); // zaduzenje postavljamo na nullptr
    }
  }

  Biblioteka(Biblioteka &&b) {

    for(auto &x : b.korisnici) {
      korisnici[x.first]=x.second; //pokazivac preuzimamo od privremene
    }

    for(auto &x : b.knjige) {
      knjige[x.first]=x.second; //pokazivac preuzimamo od privremene
    }
  }

  Biblioteka &operator=(const Biblioteka &b) {
    if(this!=&b) {
      for(auto &x : b.korisnici) {
        korisnici[x.first]=std::make_shared<  Korisnik >(*(x.second) ); //prepisujemo clanski broj i alociramo prostor novi za korisnika koji inicijaliziramo na odg vrijednosti;
      }
      for(auto &x : b.knjige) {
        knjige[x.first]=std::make_shared< Knjiga >(*(x.second) ); //prepisujemo evidencijski broj i alociramo prostor novi za knjgu koji inicijaliziramo na odg vrijednosti; sa tim da moramo pok na zaduzenje premjestiti !
        (*(knjige[x.first])).RazduziKnjigu(); // zaduzenje postavljamo na nullptr
      }
    }
    return *this;
  }

  Biblioteka &operator=(Biblioteka &&b) {
    for(auto &x : b.korisnici) {
      korisnici[x.first]=x.second; //pokazivac preuzimamo od privremene
    }

    for(auto &x : b.knjige) {
      knjige[x.first]=x.second; //pokazivac preuzimamo od privremene
    }
    return *this;
  }



  void RegistrirajNovogKorisnika(int broj, std::string ime,std::string prezime,std::string adresa,std::string telefon) {

    if( korisnici.find(broj) != std::end(korisnici) ) {
      throw std::logic_error("Korisnik vec postoji");
    }
    korisnici[broj]=std::make_shared< Korisnik>();
    (*(korisnici[broj]))= {ime,prezime,adresa,telefon};
  }

  void RegistrirajNovuKnjigu(int broj, std::string naslov_knjige,std::string ime_pisca,std::string zanr,int godina_izdavanja) {

    if( knjige.find(broj) != std::end(knjige) ) {
      throw std::logic_error("Knjiga vec postoji");
    }
    knjige[broj]=std::make_shared< Knjiga> (naslov_knjige,ime_pisca,zanr,godina_izdavanja);

  }

  Korisnik &NadjiKorisnika(int broj)const {
    auto it(korisnici.find(broj));
    if( it == std::end(korisnici) ) {
      throw std::logic_error("Korisnik nije nadjen");
    }
    return *((*it).second);
  }

  Knjiga &NadjiKnjigu(int broj)const {
    auto it(knjige.find(broj));
    if( it == std::end(knjige) ) {
      throw std::logic_error("Knjiga nije nadjena");
    }
    return *((*it).second);
  }

  void IzlistajKorisnike()const {
    std::for_each(std::begin(korisnici),std::end(korisnici), [](std::pair< int, std::shared_ptr<Korisnik> >x) {
      std::cout <<"Clanski broj: "<<x.first << std::endl;
      std::cout << "Ime i prezime: " <<(*(x.second)).ime<<" "<<(*(x.second)).prezime<< std::endl;
      std::cout << "Adresa: " <<(*(x.second)).adresa<< std::endl;
      std::cout << "Broj telefona: " <<(*(x.second)).telefon<< std::endl;
      std::cout  << std::endl;
    });
  }

  void IzlistajKnjige()const {
    std::for_each(std::begin(knjige),std::end(knjige), [](std::pair<int, std::shared_ptr<Knjiga>>x) {
      std::cout <<"Evidencijski broj: "<<x.first << std::endl;
      std::cout << "Naslov: " <<(*(x.second)).DajNaslov()<< std::endl;
      std::cout << "Pisac: " <<(*(x.second)).DajAutora()<< std::endl;
      std::cout << "Zanr: " <<(*(x.second)).DajZanr()<< std::endl;
      std::cout << "Godina izdavanja: " <<(*(x.second)).DajGodinuIzdavanja()<< std::endl;
      if((*(x.second)).DaLiJeZaduzena()) {
        std::cout <<"Zaduzena kod korisnika: "<< (*(*(x.second)).DajKodKogaJe()).ime  <<" "<<(*(*(x.second)).DajKodKogaJe()).prezime << std::endl;
      }
      std::cout << std::endl;
    });
  }

  void ZaduziKnjigu(int evidencijski,int clanski) {
    if(NadjiKnjigu(evidencijski).DaLiJeZaduzena() ) {
      throw std::logic_error("Knjiga vec zaduzena");
    }
    NadjiKnjigu(evidencijski).ZaduziKnjigu(NadjiKorisnika(clanski));
  }

  void RazduziKnjigu(int evidencijski) {
    if(NadjiKnjigu(evidencijski).DaLiJeZaduzena() == false ) {
      throw std::logic_error("Knjiga nije zaduzena");
    }
    NadjiKnjigu(evidencijski).RazduziKnjigu();
  }


  void PrikaziZaduzenja (int clanski) {
    int brojac(0);
    for(auto x : knjige) {
      if( std::shared_ptr<Korisnik>( (*(x.second)).DajKodKogaJe() ) == std::shared_ptr<Korisnik>(&NadjiKorisnika(clanski) )) {
        std::cout <<"Evidencijski broj: "<<x.first << std::endl;
        std::cout << "Naslov: " <<(*(x.second)).DajNaslov()<< std::endl;
        std::cout << "Pisac: " <<(*(x.second)).DajAutora()<< std::endl;
        std::cout << "Zanr: " <<(*(x.second)).DajZanr()<< std::endl;
        std::cout << "Godina izdavanja: " <<(*(x.second)).DajGodinuIzdavanja()<< std::endl;
        std::cout << std::endl;
        brojac++;
      }
    }
    if(!brojac) {
      std::cout << "Nema zaduzenja za tog korisnika!" << std::endl;
    }
  }
};
int main ()
{

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
