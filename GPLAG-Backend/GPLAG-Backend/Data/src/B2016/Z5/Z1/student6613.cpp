/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include<string>
#include<map>
#include<stdexcept>
#include<new>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;
struct Korisnik {
    string ime, prezime, adresa, telefon;
};
class Knjiga
{
    string naslov, pisac, zanr;
    int god_izd;
    Korisnik *zaduzena;
public:
    Knjiga(string naziv, string autor, string zanrr, int izdanje):naslov(naziv), pisac(autor), zanr(zanrr), god_izd(izdanje), zaduzena(nullptr) {}

    string DajNaslov()const {
        return naslov;
    }
    string DajAutora()const {
        return pisac;
    }
    string DajZanr()const {
        return zanr;
    }
    int DajGodinuIzdanja()const {
        return god_izd;
    }
    Korisnik DajKodKogaJe()const {
        return *zaduzena;
    }
    void ZaduziKnjigu(const Korisnik &k) {
        zaduzena=&k;
    }
    void RazduziKnjigu() {
        zaduzena=nullptr;
    }
    bool DaLiJeZaduzena()const {
        return zaduzena;
    }
};
class Biblioteka
{
    map<int, *Korisnik> korisnici;
    map<int, *Knjiga> knjige;
public:
    Biblioteka() {}
    Biblioteka(const Biblioteka &b) {
        for(auto it=b.korisnici.begin(), it!=b.korisnici.end(); it++)
            this->korisnici.push_back(new Korisnik(*it));
        for(auto it=b.knjige.begin(), it!=b.knjige.end(); it++)
            this->knjige.push_back(new Knjiga(it->DajKopiju()));
    }
    ~Biblioteka() {
        for(auto it=korisnici.begin(), it!=korisnici.end(); it++) {
            delete it->second;
            it->second=nullptr;
        }
        for(auto it=b.knjige.begin(), it!=b.knjige.end(); it++) {
            delete it->second;
            it->second=nullptr;
        }
    }
    void RegistrirajNovogKorisnika(int br, string imee, string prezimee, string adresaa, string brtel) {
        for(auto it=korisnici.begin(); it!=korisnici.end(); it++)
            if(it->first==br) throw std::logic_error("Korisnik vec postoji");
        korisnici[br]=new Korisnik(imee, prezimee, adresaa, brtel);
    }
    void RegistrirajNovuKnjigu(int br, string naziv, string autor, string zanric, int izdanje) {
        for(auto it=knjige.begin(); it!=knjige.end(); it++)
            if(it->first==br) throw std::logic_error("Knjiga vec postoji");
        knjige[br]=new Knjiga(naziv, sutor, zanric, izdanje);
    }
    Korisnik &NadjiKorisnika(int br)const {
        for(auto it=korisnici.begin(); it!=korisnici.end(); it++)
            if(it->first==br) return *(it->second);
        throw std::logic_error("Korisnik nije nadjen");
    }
    Knjiga &NadjiKnjigu(int br)const {
        for(auto it=knjige.begin(); it!=knjige.end(); it++)
            if(it->first==br) return *(it->second);
        throw std::logic_error("Knjiga nije nadjena");
    }
    void IzlistajKorisnike()const {
        for(auto it1=korisnici.begin(); it1!=korisnici.end(); it1++)
            cout<<"Clanski broj: "<<it1->first<<endl<<"Ime i prezime: "<<it1->second.ime<<" "<<it1->prezime<<endl<<"Adresa: "<<it1->second.adresa<<endl<<"Broj telefona: "<<it1->second.telefon<<endl;
    }
    void IzlistajKnjige()const {
        for(auto it=knjige.begin(); it!=knjige.end(); it++) {
            cout<<"Evidencijski broj: "<<it->first<<endl<<"Naslov: "<<it->second.naslov<<endl<<"Pisac: "<<it->second->pisac<<endl<<"Zanr: "<<(it->second)->zanr<<endl<<"Godina izdavanja: "<<(it->second)->god_izd<<endl;
            if((it->second)->zauzeta) cout<<"Zaduzena kod korisnika: "<<((it->second)->zauzeta)->ime<<endl;
        }
    }
    void ZaduziKnjigu(int br_knj, int br_kor){
        for(auto it=knjige.begin(); it!=knjige.end(); it++)
            if(it->first==br_knj)
    }
};
int main ()
{
    return 0;
}