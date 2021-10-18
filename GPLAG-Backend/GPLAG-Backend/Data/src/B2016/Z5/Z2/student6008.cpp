/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise

#include <iostream>
#include <map>
#include <memory>

struct Korisnik {
  std::string ime;
  std::string prezime;
  std::string adresa;
  std::string telefon;
};

class Knjiga {
  std::string naslov, ime_pisca, zanr;
  int godina_izdavanja;
  std::shared_ptr<Korisnik> zaduzenje = nullptr;
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
  bool DaLiJeZaduzena() const {
    if(zaduzenje == nullptr)
      return false;
    else return true;
  }
  void ZaduziKnjigu(Korisnik &k){
    zaduzenje = std::make_shared<Korisnik>(k);
  }
  void RazduziKnjigu(){
    zaduzenje = nullptr;
  }
  std::shared_ptr<Korisnik> DajKodKogaJe() const {
    return zaduzenje; 
  };
  
};
typedef std::map<int, std::shared_ptr<Knjiga>> MapaKnjiga;
typedef std::map<int, std::shared_ptr<Korisnik>> MapaKorisnika;
class Biblioteka {
    MapaKnjiga mapaKnjiga;
    MapaKorisnika mapaKorisnika;
    void IzlistajKnjigu (std::pair<int, std::shared_ptr<Knjiga>> i, bool kodKogaJe = true) const {
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
        mapaKorisnika[i.first] = std::make_shared<Korisnik>(*(i.second));
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
        mapaKorisnika.erase(i.first);
      }
      for (auto i : biblioteka.mapaKorisnika) {
        mapaKorisnika[i.first] = std::make_shared<Korisnik>(*i.second);
      }
      return *this;
    }
    Biblioteka &operator =(Biblioteka &&biblioteka) {
      mapaKnjiga = biblioteka.mapaKnjiga;
      mapaKorisnika = biblioteka.mapaKorisnika;
      return *this;
    }
    ~Biblioteka() { }
    void RegistrirajNovogKorisnika (int broj, std::string ime, std::string prezime, std::string adresa, std::string brojTel) {
      for (auto i : mapaKorisnika) {
        if (i.first == broj) {
          throw std::logic_error ("Korisnik vec postoji");
        }
      }
      mapaKorisnika[broj] = std::make_shared<Korisnik>(Korisnik{ime, prezime, adresa, brojTel});

    }
    void RegistrirajNovuKnjigu (int broj, std::string naslov, std::string pisac, std::string zanr, int godine) {
      for (auto i : mapaKnjiga) {
        if (i.first == broj) {
          throw std::logic_error ("Knjiga vec postoji");
        }
      }
      mapaKnjiga[broj] = std::make_shared<Knjiga>(naslov, pisac, zanr, godine);
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
    Biblioteka bib5;
    bib5.RegistrirajNovogKorisnika(1, "Niko", "Nikic", "Zmaja od Bosne bb", "123 456");
    bib5.RegistrirajNovuKnjigu(2, "Vlak u snijegu", "Mato Lovrak", "Roman", 1931);
    std::cout << bib5.NadjiKnjigu(2).DajNaslov();

    Biblioteka bib8;
    bib8.RegistrirajNovogKorisnika(1, "Niko", "Nikic", "Zmaja od Bosne bb", "123 456");
    bib8.RegistrirajNovuKnjigu(1, "Vlak u snijegu2", "Mato Lovrak2", "Roman2", 1941);
    bib8.RegistrirajNovuKnjigu(2, "Vlak u snijegu", "Mato Lovrak", "Roman", 1931);
    bib8.ZaduziKnjigu(2, 1);
    bib8.IzlistajKnjige();
  }
  catch (const char error[]) {
    std::cout << error << std::endl;
  }
  catch (std::logic_error error) {
    std::cout << error.what() << std::endl;
  }
	return 0;
}