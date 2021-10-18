/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <memory>
#include <cstring>
#include <string>
#include <map>
#include <new>

struct Korisnik {
    std::string ime, prezime, adresa, telefon;
};
class Knjiga {
    std::string naslov, pisac, zanr;
    int god;
    Korisnik* kod_koga_je=nullptr; 
    public:
    Knjiga (std::string Naslov, std::string Pisac, std::string Zanr, int God) { 
        naslov=Naslov;
        pisac=Pisac;
        zanr=Zanr;
        god=God;
    }
    std::string DajNaslov () const { return naslov;}
    std::string DajAutora () const {return pisac;}
    std::string DajZanr () const {return zanr;}
    int DajGodinuIzdavanja () const { return god;}
    Korisnik* DajKogKogaJe () const { return kod_koga_je;}
    void ZaduziKnjigu (Korisnik &k) {
        kod_koga_je=&k; 
    }
    void RazduziKnjigu () {
        kod_koga_je=nullptr;
    }
    bool DaLiJeZaduzena () {
        if (!kod_koga_je) return false;
        return true;
    }
}; 
class Biblioteka {
    std::map<int,Korisnik*> mapa_korisnika;
    std::map<int,Knjiga*> mapa_knjiga;
    public:
    Biblioteka() {}
    Biblioteka (const Biblioteka &b) {
        for (auto it=b.mapa_korisnika.begin(); it!=b.mapa_korisnika.end(); it++) {
            mapa_korisnika.insert(std::make_pair(b.mapa_korisnika.first,b.mapa_korisnika.second));
        }
        for (auto it=b.mapa_knjiga.begin(); it!=b.mapa_knjiga.end(); it++) {
            mapa_knjiga.insert(std::make_pair(b.fist, b.second));
        }
    }
    &Biblioteka::operator =(const Biblioteka &b) {
        for (auto it=b.mapa_korisnika.begin();it!=b.mapa_korisnika.end();it++) {
            mapa_korisnika.insert(std::make_pair(b.first,b.second));
        }
        for (auto it=b.mapa_knjiga.begin(); it!=b.mapa_knjiga.end(); it++) {
            mapa_knjiga.insert(std::make_pair(b.first,b.second));
        }
        return *this;
    }
    Biblioteka (Biblioteka &&b): mapa_korisnika(std::move(b.mapa_korisnika)), mapa_knjiga(std::move(b.mapa_knjiga)) {}
     &Biblioteka operator =(Biblioteka &&b) {
        mapa_knjiga=std::move(b.mapa_knjiga);
        mapa_korisnika=std::move(b.mapa_korisnika);
        return *this;
    }
    Biblioteka RegistrirajNovogKorisnika (int id, std::string ime, std::string prezime, std::string adresa, std::string telefon) {
        auto it(mapa_korisnika.find(id));
        if(it!=mapa_korisnika.end())  throw std::logic_error("Korisnik vec postoji");
        Korisnik *pok(new Korisnik(ime,prezime,adresa,telefon));
        mapa_korisnika[id]=pok;
        return *this;
    }
    Biblioteka RegistrirajNovuKnjigu (int ev,std::string naslov,std::string autor,std::string zanr,int god) {
        auto it(mapa_knjiga.find(ev));
        if(it!=mapa_knjiga.end()) throw std::logic_error("Knjiga vec postoji");
        Knjiga *pok=(new Knjiga(naslov,autor,zanr,god));
        mapa_knjiga[ev]=pok;
        return *this;
    }
    &Korisnik NadjiKorisnika (int id) {
        auto it(mapa_korisnika.find(id));
        if(it=mapa_korisnika.end()) throw std::logic_error("Korisnik nije nadjen");
        return it->second;
    }
    &Knjiga NadjiKnjigu (int ev) {
        auto it(mapa_knjiga.find(ev));
        if(it=mapa_knjiga.end()) throw std::logic_error("Knjiga nije nadjena");
        return it->second;
    }
    void IzlistajKorisnike () const {
        std::cout<<"Clanski broj: "<<id<<std::endl<<"Ime i prezime: "<<ime<<" "<<prezime<<std::endl<<"Broj telefona: "<<telefon<<std::endl;
        std::cout<<std::endl;
    }
    void IzlistajKnjige () const {
        std::cout<<"Evidencijski broj: "<<ev<<std::endl<<"Naslov :"<<pisac<<std::endl<<"Zanr: "<<zanr<<std::endl<<"Godina izdavanja: "<<god;
        if(DaLiJeZaduzena()==true)
            std::cout<<"Zaduzena kod korisnika: "<<*kod_koga_je<<std::endl;
        std::cout<<std::endl;
    }
    void ZaduziKnjigu(int ev, int id) {
        auto it(mapa_knjiga.find(ev));
        auto it1(mapa_korisnika.find(id));
        if (ev<=0 || it=mapa_knjiga.end()) throw std::logic_error ("Knjiga nije nadjena");
        if (id<=0 || it=mapa_korisnika.end()) throw std::logic_error ("Korisnik nije nadjen");
        if (mapa_knjiga[ev].DaLiJeZaduzena()==true) throw std::logic_error ("Knjiga vec zaduzena");
                kod_koga_je=mapa_korisnika[id];
    }
    void RazduziKnjigu(int ev) {
        auto it(mapa_knjiga.find(ev));
        if(it=mapa_knjiga.end()) throw std::logic_error ("Knjiga nije nadjena");
        if(mapa_knjiga[ev].DaLiJeZaduzena()==false) throw std::logic_error ("Knjiga nije zaduzena");
            mapa_knjiga[ev].kod_koga_je=nullptr;
    }
    void PrikaziZaduzenja (int id) {
        auto it(mapa_korisnika.find(id));
        if (it=mapa_korisnika.end()) throw std::logic_error ("Korisnik nije nadjen");
        bool ima(false);
        for (auto it1=mapa_knjiga.begin(); it1!=mapa_knjiga.end();it1++) {
            if (it1.kod_koga_je==mapa_korisnika[id]) ima=true;
        }
        if(ima==false) throw std::logic_error ("Nema zaduzenja za tog korisnika!");
        for (auto it1=mapa_knjiga.begin();it1!=mapa_knjiga.end();it1++) {
            if (it1.kod_koga_je==mapa_korisnika[id]) {
                std::cout<<"Evidencijski broj: "<<ev<<std::endl<<"Naslov :"<<pisac<<std::endl<<"Zanr: "<<zanr<<std::endl<<"Godina izdavanja: "<<god<<std::endl;
            }
        }
    }
};



int main ()
{
	return 0;
}