/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise

#include <iostream>
#include <string>
#include <stdexcept>
#include <map>
#include <iomanip>
#include <memory>

using namespace std;

struct Korisnik {
    string ime;
    string prezime;
    string adresa;
    string telefon;

    Korisnik(string ime,string prezime,string adresa,string telefon):
        ime(ime),prezime(prezime),adresa(adresa),telefon(telefon) {};
    friend bool operator ==(Korisnik a, Korisnik b) {
        return a.ime==b.ime && a.prezime==b.prezime && a.adresa==b.adresa && a.telefon==b.telefon;
    }
    void Ispisi() {
        cout<<"Ime i prezime: "<<ime<<" "<<prezime<<endl;
        cout<<"Adresa: "<<adresa<<endl;
        cout<<"Broj telefona: "<<telefon<<endl<<endl;
    }

};


class Knjiga
{
    string naslov;
    string imepisca;
    string zanr;
    int godinaizdavanja;
    Korisnik *kod_koga_je;

public:
    Knjiga(string naslov,string imepisca,string zanr,int godinaizdavanja):
        naslov(naslov),imepisca(imepisca),zanr(zanr),godinaizdavanja(godinaizdavanja),kod_koga_je(nullptr) {}
    string DajNaslov() const {
        return naslov;
    }
    string DajAutora() const {
        return imepisca;
    }
    string DajZanr() const {
        return zanr;
    }
    int DajGodinuIzdavanja() const {
        return godinaizdavanja;
    }
    Korisnik *DajKodKogaJe()const {
        return kod_koga_je;
    }
    void ZaduziKnjigu(Korisnik &k) {
        kod_koga_je=&k;
    }
    void RazduziKnjigu() {
        kod_koga_je=nullptr;
    }
    bool DaLiJeZaduzena() const {
        if(kod_koga_je==nullptr) return false;
        return true;
    }
    void Ispisi() const;
};

void Knjiga::Ispisi() const
{
    cout<<"Naslov: "<<DajNaslov()<<endl;
    cout<<"Pisac: "<<DajAutora()<<endl;
    cout<<"Zanr: "<<DajZanr()<<endl;
    cout<<"Godina izdavanja: "<<DajGodinuIzdavanja()<<endl;
    if(DajKodKogaJe()!=nullptr)
        cout<<"Zaduzena kod korisnika: "<<DajKodKogaJe()->ime<<" "<<DajKodKogaJe()->prezime<<endl;
    cout<<endl;
}


class Biblioteka
{

    map<int,shared_ptr<Korisnik>>m1;
    map<int,shared_ptr<Knjiga>>m2;


public:
    Biblioteka() {};
    Biblioteka(Biblioteka &b)=delete;
    Biblioteka &operator=(Biblioteka &b)=delete;
    ~Biblioteka() {
        for(auto i=m1.begin(); i!=m1.end(); i++)
            i->second=nullptr;

        for(auto i=m2.begin(); i!=m2.end(); i++)
            i->second=nullptr;
    }
    void RegistrirajNovogKorisnika(int clanski_broj,string ime,string prezime,string adresa,string telefon) {
        m1.insert(make_pair(clanski_broj,make_shared<Korisnik>(ime,prezime,adresa,telefon)));
    }
    void RegistrirajNovuKnjigu(int evidencijski_broj,string naslov,string imepisca,string zanr,int godinaizdavanja) {
        m2.insert(make_pair(evidencijski_broj,make_shared<Knjiga>(naslov,imepisca,zanr,godinaizdavanja)));
    }
    Korisnik &NadjiKorisnika(int clanski_broj) {
        return *m1[clanski_broj];
    }
    Knjiga &NadjiKnjigu(int evidencijski_broj) {
        return *m2[evidencijski_broj];
    }
    void IzlistajKorisnike() const {
        for(auto i:m1) {
            cout<<"Clanski broj: "<<i.first<<endl;
            i.second->Ispisi();
        }
    }
    void IzlistajKnjige() const {
        for(auto i:m2) {
            cout<<"Evidencijski broj: "<<i.first<<endl;
            i.second->Ispisi();
        }
    }
    void ZaduziKnjigu(int indexa,int indexb) {
        m2[indexa]->ZaduziKnjigu(*m1[indexb]);
    }
    void RazduziKnjigu(int index) {
        m2[index]->RazduziKnjigu();
    }
    void PrikaziZaduzenje(int index) {
        for(auto i:m2) {
            if(*m1[index]==*i.second->DajKodKogaJe()) {
                cout<<"Naslov: "<<i.second->DajNaslov()<<endl;
                cout<<"Pisac: "<<i.second->DajAutora()<<endl;
                cout<<"Zanr: "<<i.second->DajZanr()<<endl;
                cout<<"Godina izdavanja: "<<i.second->DajGodinuIzdavanja()<<endl;
                cout<<endl;
            }
        }
    }
};


int main ()
{


    return 0;
}