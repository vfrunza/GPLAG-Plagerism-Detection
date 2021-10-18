/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>

using std::cout; using std::cin; //using std::endl;

struct Korisnik{
  std::string ime, prezime, adresa, telefon;  
};
class Knjiga{
  std::string naslov, ime_pisca, zanr;
  int godina;
  Korisnik *pok;
  public:
  Knjiga (std::string n, std::string i_p, std::string z, int g):pok(nullptr){
      naslov = n; ime_pisca = i_p; zanr = z; godina = g;
  };
  //~Knjiga() {if(pok != nullptr) delete pok;};
  std::string DajNaslov() const {return naslov;};
  std::string DajAutora() const {return ime_pisca;};
  std::string DajZanr() const {return zanr;};
  int DajGodinuIzdavanja() const {return godina;};
  Korisnik *DajKodKogaJe() const {return pok;};
  void ZaduziKnjigu(Korisnik &k){
    //  pok = new Korisnik;
      pok = &k;
  };
  void RazduziKnjigu() {pok = nullptr;};
  bool DaLiJeZaduzena() {
    if(pok == nullptr) return false;
    return true;
  };
};
class Biblioteka{
    std::map<int,Korisnik*> Korisnici;
    std::map<int,Knjiga*> Knjige;
    void Unisti(){
        for(auto it=Korisnici.begin(); it!=Korisnici.end(); it++){
            delete (*it).second;
        }
        for(auto it=Knjige.begin(); it!=Knjige.end(); it++)
            delete (*it).second;
    };
    public:
    Biblioteka() {};
    Biblioteka(const Biblioteka &b){
        for(auto it=b.Korisnici.begin(); it!=b.Korisnici.end(); it++){
            Korisnici[(*it).first] = new Korisnik;
            Korisnici[(*it).first] = (*it).second;
        }
        for(auto it=b.Knjige.begin(); it!=b.Knjige.end(); it++){
            Knjige[(*it).first] = new Knjiga((*it).second->DajNaslov(), (*it).second->DajAutora(), (*it).second->DajZanr(), (*it).second->DajGodinuIzdavanja());
         //   Korisnici[(*it).first] = (*it).second;
        }
    }; 
    ~Biblioteka(){
        Unisti();
    };
    Biblioteka &operator = (const Biblioteka &b){
    Unisti();
    for(auto it=b.Korisnici.begin(); it!=b.Korisnici.end(); it++){
            Korisnici[(*it).first] = new Korisnik;
            Korisnici[(*it).first] = (*it).second;
    }
    for(auto it=b.Knjige.begin(); it!=b.Knjige.end(); it++){
            Knjige[(*it).first] = new Knjiga((*it).second->DajNaslov(), (*it).second->DajAutora(), (*it).second->DajZanr(), (*it).second->DajGodinuIzdavanja());
         //   Korisnici[(*it).first] = (*it).second;
    }
        return *this;
    };
    Biblioteka &operator = (Biblioteka &&b){
        *this = b;
        b.Unisti();
        return *this;
    };
    void RegistrirajNovogKorisnika(int cl_br, std::string ime, std::string prezime, std::string adresa, std::string br_tel){
        if(Korisnici.count(cl_br) > 0) throw std::logic_error("Korisnik vec postoji");
        Korisnik k; k.ime = ime; k.prezime = prezime; k.adresa = adresa; k.telefon = br_tel;
        Korisnici[cl_br] = new Korisnik; *Korisnici[cl_br] = k;
    };
    void RegistrirajNovuKnjigu(int ev_br, std::string naslov, std::string ime_pisca, std::string zanr, int god){
        if(Knjige.count(ev_br) > 0) throw std::logic_error("Knjiga vec postoji");
    //    Knjiga k; k.naslov = naslov; k.ime_pisca = ime_pisca; k.zanr = zanr; k.godina = god;
        Knjige[ev_br] = new Knjiga(naslov, ime_pisca, zanr, god);
    };
    Korisnik &NadjiKorisnika(int cl_br){
        if(Korisnici.count(cl_br) <= 0) throw std::logic_error("Korisnik nije nadjena");
        return *Korisnici[cl_br];
    };
    Knjiga &NadjiKnjigu(int ev_br){
        if(Knjige.count(ev_br) <= 0) throw std::logic_error("Knjiga nije nadjena");
        return *Knjige[ev_br];
    };
    void IzlistajKorisnike(){
        for(auto it=Korisnici.begin(); it!=Korisnici.end(); it++){
            cout << "Clanski broj: " << it->first << std::endl;
            cout << "Ime i prezime: " << it->second->ime << " " << it->second->prezime << std::endl;
            cout << "Adresa: " << it->second->adresa << std::endl;
            cout << "Broj telefona: " << it->second->telefon << std::endl << std::endl;
        }
    };
    void IzlistajKnjige(){
        for(auto it=Knjige.begin(); it!=Knjige.end(); it++){
            cout << "Evidencijski broj: " << it->first << std::endl;
            cout << "Naslov: " << it->second->DajNaslov() << std::endl;
            cout << "Pisac: " << it->second->DajAutora() << std::endl;
            cout << "Zanr: " << it->second->DajZanr() << std::endl;
            cout << "Godina izdavanja: " << it->second->DajGodinuIzdavanja() << std::endl;
            if(it->second->DaLiJeZaduzena())
            cout << "Zaduzena kod korisnika: " << it->second->DajKodKogaJe()->ime << " " << it->second->DajKodKogaJe()->prezime << std::endl;
            cout << std::endl;
        }
    };
    void ZaduziKnjigu(int ev_br, int cl_br){
        if(Knjige.count(ev_br) <= 0) throw std::logic_error("Knjiga nije nadjena");
        if(Korisnici.count(cl_br) <= 0) throw std::logic_error("Korisnik nije nadjen");
        if(Knjige[ev_br]->DaLiJeZaduzena()) throw std::logic_error("Knjiga vec zaduzena");
        Knjige[ev_br]->ZaduziKnjigu(*Korisnici[cl_br]);
    };
    void RazduziKnjigu(int ev_br){
        if(Knjige.count(ev_br) <= 0) throw std::logic_error("Knjiga nije nadjena");
        if(!Knjige[ev_br]->DaLiJeZaduzena()) throw std::logic_error("Knjiga nije zaduzena");
        Knjige[ev_br]->RazduziKnjigu();
    };
};


int main ()
{
    Biblioteka bib8;
bib8.RegistrirajNovogKorisnika(1, "Niko", "Nikic", "Zmaja od Bosne bb", "123 456");
bib8.RegistrirajNovuKnjigu(1, "Vlak u snijegu2", "Mato Lovrak2", "Roman2", 1941);
bib8.RegistrirajNovuKnjigu(2, "Vlak u snijegu", "Mato Lovrak", "Roman", 1931);
bib8.ZaduziKnjigu(2, 1);
bib8.IzlistajKnjige();
	return 0;
}