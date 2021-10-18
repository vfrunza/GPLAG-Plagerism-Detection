/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <map>

struct Korisnik {
  std::string ime;
  std::string prezime;
  std::string adresa;
  std::string telefon;
};

class Knjiga {
  std::string naslov, ime_pisca, zanr;
  int godina_izdavanja;
  Korisnik *zaduzenje = nullptr;
  public:
  Knjiga(std::string n, std::string ip, std::string z, int gi){
    naslov = n; ime_pisca = ip; zanr = z; godina_izdavanja = gi; 
  }
  std::string DajNaslov() const {
    return naslov;
  }
  std::string DajAutora() const {
    return ime_pisca;
  }
  std::string DajZanr() const {
    return zanr;
  }
  int DajGodinuIzdavanja() const {
    return godina_izdavanja;
  }
  bool DaLiJeZaduzena(){
    if(zaduzenje == nullptr)
      return false;
    else return true;
  }
  void ZaduziKnjigu(Korisnik &k){
    zaduzenje = &k;
  }
  void RazduziKnjigu(){
    zaduzenje = nullptr;
  }
  Korisnik *DajKodKogaJe() const {
    return zaduzenje; 
  };
  
};
typedef std::map<int, Knjiga*> MapaKnjiga;
typedef std::map<int, Korisnik*> MapaKorisnika;
class Biblioteka {
    MapaKnjiga mapaKnjiga;
    MapaKorisnika mapaKorisnika;
    void IzlistajKnjigu (std::pair<int, Knjiga*> i, bool kodKogaJe = true) const {
      std::cout << "Evidencijski broj: " << i.first << std::endl;
      std::cout << "Naslov: " << i.second->DajNaslov() << std::endl;
      std::cout << "Pisac: " << i.second->DajAutora() << std::endl;
      std::cout << "Zanr: " << i.second->DajZanr() << std::endl;
      std::cout << "Godina izdavanja: " << i.second->DajGodinuIzdavanja() << std::endl;
      if (kodKogaJe) {
        if (i.second->DaLiJeZaduzena()) {
          std::cout << "Zaduzena kod korisnika: " << i.second->DajKodKogaJe()->ime << " " << i.second->DajKodKogaJe()->prezime << std::endl;
        } else {
          std::cout << std::endl;
        }
      }
    }
    public:
    Biblioteka () {}
    Biblioteka(const Biblioteka &biblioteka) {
      for (auto i : biblioteka.mapaKorisnika) {
        mapaKorisnika[i.first] = new Korisnik(*(i.second));
      }
    }
    Biblioteka(Biblioteka &&biblioteka) {
      mapaKnjiga = biblioteka.mapaKnjiga;
      mapaKorisnika = biblioteka.mapaKorisnika;
    }
    Biblioteka &operator =(const Biblioteka &biblioteka) {
      if (this == &biblioteka) {
        return *this;
      }
      for (auto i : mapaKorisnika) {
        delete i.second;
        mapaKorisnika.erase(i.first);
      }
      for (auto i : biblioteka.mapaKorisnika) {
        mapaKorisnika[i.first] = new Korisnik(*i.second);
      }
      return *this;
    }
    Biblioteka &operator =(Biblioteka &&biblioteka) {
      mapaKnjiga = biblioteka.mapaKnjiga;
      mapaKorisnika = biblioteka.mapaKorisnika;
      return *this;
    }
    ~Biblioteka() {
      for (auto i : mapaKnjiga) {
        delete i.second;
      }
      for (auto i : mapaKorisnika) {
        delete i.second;
      }
    }
    void RegistrirajNovogKorisnika (int broj, std::string ime, std::string prezime, std::string adresa, std::string brojTel) {
      for (auto i : mapaKorisnika) {
        if (i.first == broj) {
          throw std::logic_error ("Korisnik vec postoji");
        }
      }
      mapaKorisnika[broj] = new Korisnik{ime, prezime, adresa, brojTel};

    }
    void RegistrirajNovuKnjigu (int broj, std::string naslov, std::string pisac, std::string zanr, int godine) {
      for (auto i : mapaKnjiga) {
        if (i.first == broj) {
          throw std::logic_error ("Knjiga vec postoji");
        }
      }
      mapaKnjiga[broj] = new Knjiga(naslov, pisac, zanr, godine);
    }
    Korisnik &NadjiKorisnika (int broj) const {
      for (auto i : mapaKorisnika) {
        if (i.first == broj) {
          return *i.second;
        }
      }
      throw std::logic_error ("Korisnik nije nadjen");
    }
    Knjiga &NadjiKnjigu (int broj) const {
      for (auto i : mapaKnjiga) {
        if (i.first == broj) {
          return *i.second;
        }
      }
      throw std::logic_error ("Knjiga nije nadjena");
    }
    void IzlistajKnjige () const {
      for (auto i : mapaKnjiga) {
        IzlistajKnjigu(i);
      }
    }
    void IzlistajKorisnike () const {
      for (auto i : mapaKorisnika) {
        std::cout << "Clanski broj: " << i.first << std::endl;
        std::cout << "Ime i prezime: " << i.second->ime << " " << i.second->prezime << std::endl;
        std::cout << "Adresa: " << i.second->adresa << std::endl;
        std::cout << "Broj telefona: " << i.second->telefon << std::endl << std::endl;
      }
    }
    void ZaduziKnjigu(int brojKnjige, int brojKorisnika) {
      auto knjiga = mapaKnjiga.find(brojKnjige);
      if (knjiga == mapaKnjiga.end()) {
        throw std::logic_error("Knjiga nije nadjena");
      }
      if (knjiga->second->DaLiJeZaduzena()) {
        throw std::logic_error("Knjiga vec zaduzena");
      }
      auto korisnik = mapaKorisnika.find(brojKorisnika);
      if (korisnik == mapaKorisnika.end()) {
        throw std::logic_error("Korisnik nije nadjen");
      }
      knjiga->second->ZaduziKnjigu(*(korisnik->second));
    }
    void RazduziKnjigu(int broj) {
      auto knjiga = mapaKnjiga.find(broj);
      if (knjiga == mapaKnjiga.end()) {
        throw std::logic_error("Knjiga nije nadjena");
      }
      if (!knjiga->second->DaLiJeZaduzena()) {
        throw std::logic_error("Knjiga nije zaduzena");
      }
      (*(knjiga->second)).RazduziKnjigu();
    }
    void PrikaziZaduzenja (int broj) const {
      auto korisnik = mapaKorisnika.find(broj);
      int n(0);
      if (korisnik == mapaKorisnika.end()) {
        throw std::logic_error("Korisnik nije nadjen");
      }
      for (auto i : mapaKnjiga) {
        if ((*(i.second)).DajKodKogaJe() == korisnik->second) {
          IzlistajKnjigu(i, false);
          std::cout << std::endl;
          n++;
        }
      }
      if (n == 0) {
        std::cout << "Nema zaduzenja za tog korisnika!";
      }
      
    }
};

int main ()
{
  try {
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
  }
  catch (const char error[]) {
    std::cout << error << std::endl;
  }
  catch (std::logic_error error) {
    std::cout << error.what() << std::endl;
  }
  
    
	return 0;
}