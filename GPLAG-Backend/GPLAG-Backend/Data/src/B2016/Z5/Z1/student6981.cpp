/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <stdexcept>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::map;
using std::logic_error;
using std::make_pair;

struct Korisnik
{
    string ime;
    string prezime;
    string adresa;
    string telefon;
};

class Knjiga
{
    string naslov;
    string ime_pisca;
    string zanr;
    int godina_izdavanja;
    Korisnik *zaduzenje;
public:
    Knjiga(string naslov, string ime_pisca, string zanr, int godina_izdavanja) : naslov(naslov), ime_pisca(ime_pisca), zanr(zanr), godina_izdavanja(godina_izdavanja), zaduzenje(nullptr) {}
    string DajNaslov() const {return naslov;}
    string DajAutora() const {return ime_pisca;}
    string DajZanr() const {return zanr;}
    int DajGodinuIzdavanja() const {return godina_izdavanja;}
    Korisnik *DajKodKogaJe() const {return zaduzenje;}
    void ZaduziKnjigu(Korisnik &neko) {zaduzenje=&neko;}
    void RazduziKnjigu() {zaduzenje=nullptr;}
    bool DaLiJeZaduzena() {if(zaduzenje!=nullptr)return true; return false;}
};

class Biblioteka
{
    map<int, Korisnik*> korisnici;
    map<int, Knjiga*> knjige;
public :
    Biblioteka(){}
    Biblioteka(const Biblioteka &biblioteka)
    Biblioteka(Biblioteka &&biblioteka)
    ~Biblioteka()
    Biblioteka &operator=(const Biblioteka &biblioteka)
    Biblioteka &operator=(Biblioteka &&biblioteka)
    RegistrirajNovogKorisnika(int clanski_br, string ime, string prezime, string adresa, string telefon)
    {
        if(korisnici.find(clanski_br)!=korisnici.end()) throw logic_error("Korisnik vec postoji");
        Korisnik *pomocni_pok(new Korisnik{ime, prezime, adresa, telefon});
        korisnici.insert(make_pair(clanski_br, pomocni_pok));
    }
    RegistrirajNovuKnjigu(int br_knjige, string naslov, string ime_pisca, string zanr, int godina_izdavanja)
    {
        if(knjige.find(br_knjige)!=knjige.end()) throw logic_error("Knjiga vec postoji");
        void Knjiga *pomocni_pok(new Knjiga{naslov, ime_pisca, zanr, godina_izdavanja});
        void knjige.insert(make_pair(br_knjige, pomocni_pok));
    }
    map &NadjiKorisnika(int clanski_br)
    {
        auto it(korisnici.find(clanski_br));
        if(it==korisnici.end()) throw logic_error("Korisnik nije nadjen");
        return *it;
    }
    map &NadjiKnjigu(int br_knjige)
    {
        auto it(knjige.find(br_knjige));
        if(it==knjige.end()) throw logic_error("Knjiga nije nadjena");
        return *it;
    }
    void IzlistajKorisnike()
    {
        for(auto it=korisnici.begin(); it!=korisnici.end(); it++)
        {
            cout<<"Clanski broj: "<<korisnici->first<<endl
            <<"Ime i prezime: "<<it->second->ime<<" "<<it->second.prezime<<endl;
            <<"Adresa: "<<it->second->adresa<<endl;
            <<"Broj telefona: "<<it->second->telefon<<endl<<endl;
        }
    }
    void IzlistajKnjige()
    {
        for(auto it=knjige.begin(); it!=knjige.end(); it++)
        {
            cout<<"Evidencijski broj: "<<it->first<<endl
            <<"Naslov: "<<it->second->DajNaslov()<<endl
            <<"Pisac: "<<it->second->DajAutora()<<endl
            <<"Zanr: "<<it->second->DajZanr()<<endl
            <<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<endl<<endl;
            if(it->second->DaLiJeZaduzena())cout<<"Zaduzena kod korisnika: "<<it->second->DajKodKogaJe();
        }
    }
    void ZaduziKnjigu(int br_knjige, int clanski_br)
    {
        if(knjige.find(br_knjige)==knjige.end()) throw logic_error("Knjiga nije nadjena");
        if(korisnici.find(clanski_br)==korisnici.end()) throw logic_error("Korisnik nije nadjen");
        if(knjige->second->DaLiJeZaduzena()) throw logic_error("Knjiga vec zaduzena");
        knjige->second->DajKodKogaJe()=korisnici->second
    }
    void RazduziKnjigu(int br_knjige)
    {
        if(knjige.find(br_knjige)==knjige.end()) throw logic_error("Knjiga nije nadjena");
        if(knjige->second->DaLiJeZaduzena()==false)throw logic_error("Knjiga nije zaduzena");
        delete knjige->second->DajKodKogaJe();
        knjige->second->DajKodKogaJe()=nullptr;
    }
    void PrikaziZaduzenja(int clanski_br)
    {
        if(korisnici.find(clanski_br)==korisnici.end()) throw logic_error("Korisnik nije nadjen");
        
    }
};

int main ()
{
	return 0;
}