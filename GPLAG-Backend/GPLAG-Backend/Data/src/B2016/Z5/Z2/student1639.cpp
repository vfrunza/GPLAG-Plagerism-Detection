#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include <memory>

using namespace std;

struct Korisnik {
    string ime, prezime, adresa, telefon;
    Korisnik (string ime, string prezime, string adresa, string telefon) {
        Korisnik::ime=ime;
        Korisnik::prezime=prezime;
        Korisnik::adresa=adresa;
        Korisnik::telefon=telefon;
    }
};

class Knjiga {
    string naslov, ime_pisca, zanr;
    int godina_izdavanja;
    shared_ptr<Korisnik> kod_koga_je;
    public:
    Knjiga (string naslov, string ime_pisca, string zanr, int godina_izdavanja, shared_ptr<Korisnik> kod_koga_je=nullptr) {
        Knjiga::naslov=naslov;
        Knjiga::ime_pisca=ime_pisca;
        Knjiga::zanr=zanr;
        Knjiga::godina_izdavanja=godina_izdavanja;
        Knjiga::kod_koga_je=kod_koga_je;
    }
    string DajNaslov() const {return naslov;}
    string DajAutora() const {return ime_pisca;}
    string DajZanr() const {return zanr;}
    int DajGodinuIzdavanja() const {return godina_izdavanja;}
    shared_ptr<Korisnik> DajKodKogaJe() const {return kod_koga_je;}
    void ZaduziKnjigu(Korisnik& zaduzio) {
        kod_koga_je=&zaduzio;
    }
    void RazduziKnjigu() {
        kod_koga_je=nullptr;
    }
    bool DaLiJeZaduzena() const {
        if(kod_koga_je==nullptr) return false;
        return true;
    }
    
};

class Biblioteka {
    map<long int, shared_ptr<Korisnik>> korisnici;
    map<long int, shared_ptr<Knjiga>> knjige;
    public:
   
    void RegistrirajNovogKorisnika(long int clanski_broj, string ime, string prezime, string adresa, string telefon) {
        if(korisnici.size()!=0 and korisnici.find(clanski_broj)!=korisnici.end()) throw logic_error ("Korisnik vec postoji");
        korisnici.insert(make_pair(clanski_broj, new Korisnik(ime,prezime,adresa,telefon)));
 
    }
    void RegistrirajNovuKnjigu (long int evidencijski_broj, string naslov, string ime_pisca, string zanr, int godina_izdavanja) {
        
        if(knjige.size()!=0 and knjige.find(evidencijski_broj)!=knjige.end()) throw logic_error("Knjiga vec postoji");
        knjige.insert(make_pair(evidencijski_broj, new Knjiga(naslov,ime_pisca,zanr,godina_izdavanja)));
    }
    
    Korisnik& NadjiKorisnika (long int clanski_broj) const {
        if(korisnici.size()==0 or korisnici.find(clanski_broj)==korisnici.end()) throw logic_error("Korisnik nije nadjen");
        auto it (korisnici.find(clanski_broj));
        return *(it->second);
    }
    Knjiga& NadjiKnjigu (long int evidencijski_broj) const {
        if(knjige.size()==0 or knjige.find(evidencijski_broj)==knjige.end()) throw logic_error("Knjiga nije nadjena");
        auto it (knjige.find(evidencijski_broj));
        return *(it->second);
    }
    void IzlistajKorisnike () const {
        for(auto i=korisnici.begin(); i!=korisnici.end(); i++) {
            cout << "Clanski broj: " << i->first << endl << "Ime i prezime: " << i->second->ime << " " << i->second->prezime << endl
            << "Adresa: " << i->second->adresa << endl << "Broj telefona: " << i->second->telefon << endl << endl;
        } 
    }
    void IzlistajKnjige () const { 
        for(auto i=knjige.begin(); i!=knjige.end(); i++) {
            cout << "Evidencijski broj: " << i->first << endl << "Naslov: " << i->second->DajNaslov() << endl << "Pisac: " << i->second->DajAutora()
            << endl << "Zanr: " << i->second->DajZanr() << endl << "Godina izdavanja: " << i->second->DajGodinuIzdavanja() << endl;
            if(i->second->DajKodKogaJe()) cout << "Zaduzena kod korisnika: " << i->second->DajKodKogaJe()->ime << " " << i->second->DajKodKogaJe()->prezime << endl; 
            cout << endl;
        }
    }
    void ZaduziKnjigu(long int evidencijski_broj, long int clanski_broj) {
        if(knjige.size()!=0 and knjige.find(evidencijski_broj)==knjige.end()) throw logic_error("Knjiga nije nadjena");
        if(korisnici.size()!=0 and korisnici.find(clanski_broj)==korisnici.end()) throw logic_error("Korisnik nije nadjen");
        if(knjige.find(evidencijski_broj)->second->DajKodKogaJe()) throw logic_error("Knjiga vec zaduzena");
        
        Knjiga& knjiga(NadjiKnjigu(evidencijski_broj));
        Korisnik& korisnik(NadjiKorisnika(clanski_broj));
        knjiga.Knjiga::ZaduziKnjigu(korisnik);
    }
    void RazduziKnjigu(long int evidencijski_broj) {
        if(knjige.size()!=0 and knjige.find(evidencijski_broj)==knjige.end()) throw logic_error("Knjiga nije nadjena");
        Knjiga knjiga(NadjiKnjigu(evidencijski_broj));
        knjiga.Knjiga::RazduziKnjigu();
    }
    void PrikaziZaduzenja (long int clanski_broj) {
        int brojac(0);
        for(auto i=knjige.begin(); i!=knjige.end(); i++) {
            if(i->second->DajKodKogaJe()==korisnici.find(clanski_broj)->second) {
                 cout << "Evidencijski broj: " << i->first << endl << "Naslov: " << i->second->DajNaslov() << endl << "Pisac: " << i->second->DajAutora()
                    << endl << "Zanr: " << i->second->DajZanr() << endl << "Godina izdavanja: " << i->second->DajGodinuIzdavanja() << endl;
                    brojac++;
                }
                
            }
       if(brojac==0) cout << "Nema zaduzenja za ovog korisnika"; 
   
    }
    
};

int main ()
{
	return 0;
}