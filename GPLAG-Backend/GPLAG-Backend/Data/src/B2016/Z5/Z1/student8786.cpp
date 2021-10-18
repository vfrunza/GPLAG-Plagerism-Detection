/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct Korisnik
{
    string ime, prezime, adresa, telefon;
    Korisnik(string ime,string prezime,string adresa,string telefon):ime(ime),prezime(prezime),adresa(adresa),telefon(telefon){};
    friend bool operator == (Korisnik k1, Korisnik k2)
    {
        return k1.ime==k2.ime && k1.prezime==k2.prezime && k1.adresa==k2.adresa && k1.telefon==k2.telefon;
    }
};

class Knjiga
{
    string naslov,pisac,zanr;
    int godina;
    Korisnik *z;
public:
    Knjiga (string naslov, string pisac, string zanr, int godina): naslov(naslov),pisac(pisac),zanr(zanr),godina(godina),z(nullptr) {};
    string DajNaslov () const {return naslov;}
    string DajAutora () const {return pisac;}
    string DajZanr () const {return zanr;}
    int DajGodinuIzdavanja () const {return godina;}
    Korisnik* DajKodKogaJe () const {return z;}
    bool DaLiJeZaduzena () { return z!=nullptr;}
    void ZaduziKnjigu (Korisnik &k) {z=&k;}
    void RazduziKnjigu () { z=nullptr;}
};

class Biblioteka
{
    map<int,Korisnik*> k;
    map<int,Knjiga*> l;
public:
    Biblioteka(){};
    Biblioteka (Biblioteka &b)
    {
        for(auto x: b.k)
        {
            k.insert(make_pair(x.first, new Korisnik(*x.second)));
        }
        for(auto x: b.l)
        {
            l.insert(make_pair(x.first, new Knjiga(*x.second)));
        }
    }
    Biblioteka(Biblioteka&&b)
    {
        for(auto x: b.l)
        {
            l.insert(make_pair(x.first, x.second));
        }
        for(auto x: b.k)
        {
            k.insert(make_pair(x.first, x.second));
        }
    }
    Biblioteka &operator =(Biblioteka &b)
    {
        if(&b!=this)
        {
            for(auto &x: l) delete x.second;
            for(auto &x: k) delete x.second;
            for(auto x: b.k) k.insert(make_pair(x.first, new Korisnik(*x.second)));
            for(auto x: b.l) l.insert(make_pair(x.first, new Knjiga(*x.second)));
        }
        return *this;
    }
    Biblioteka &operator =(Biblioteka &&b)
    {
        if(&b!=this)
        {
            for(auto &x: l) delete x.second;
            for(auto &x: k) delete x.second;
            for(auto x: b.k) k.insert(make_pair(x.first, x.second));
            for(auto x: b.l) l.insert(make_pair(x.first, x.second));
        }
        return *this;
    }
    ~Biblioteka()
    {
        for(auto &x: l) delete x.second;
        for(auto &x: k) delete x.second;
    }
    void RegistrirajNovogKorisnika(int br, string i, string p, string a, string t)
    {
        bool ima=false;
        for(auto x:k) if(x.first==br) ima=true;
        if(ima) throw logic_error("Korisnik vec postoji");
        k.insert(make_pair(br, new Korisnik(i,p,a,t)));
    }
    void RegistrirajNovuKnjigu(int br,string ime,string pisac,string zanr,int godina)
    {
        bool ima=false;
        for(auto x:l) if(x.first==br) ima=true;
        if(ima) throw logic_error("Knjiga vec postoji");
        l.insert(make_pair(br, new Knjiga(ime,pisac,zanr,godina)));
    }
    Korisnik &NadjiKorisnika (int br)
    {
        for(auto x:k) if(x.first==br) return *x.second;
        throw logic_error("Korisnik nije nadjen");
    }
    Knjiga &NadjiKnjigu (int br)
    {
        for(auto x:l) if(x.first==br) return *x.second;
        throw logic_error("Knjiga nije nadjena");
    }
    void ZaduziKnjigu(int knj, int kor)
    {
        bool ima=false;
        for(auto x: l) if(x.first==knj) { ima=true; if(x.second->DajKodKogaJe()!=nullptr) throw logic_error("Knjiga vec zaduzena"); }
        if(!ima) throw logic_error("Knjiga nije nadjena");
        ima=false;
        for(auto x: k) if(x.first==kor) ima=true;
        if(!ima) throw logic_error("Korisnik nije nadjen");
        l[knj]->ZaduziKnjigu(*k[kor]);
    }
    void RazduziKnjigu(int br)
    {
        bool ima=false;
        for(auto x: l) if(x.first==br) { ima=true; if(x.second->DajKodKogaJe()==nullptr) throw logic_error("Knjiga nije zaduzena"); }
        if(!ima) throw logic_error("Knjiga nije nadjena");
        l[br]->RazduziKnjigu();
    }
    void IzlistajKorisnike()
    {
        for(auto x: k)
        {
          cout<<"Clanski broj: "<<x.first<<endl;
          cout<<"Ime i prezime: "<<x.second->ime<<" "<<x.second->prezime<<endl;
          cout<<"Adresa: "<<x.second->adresa<<endl;
          cout<<"Broj telefona: "<<x.second->telefon<<endl;
          cout<<endl;
        }
    }
    void IzlistajKnjige()
    {
        for(auto x:l)
        {
          cout<<"Evidencijski broj: "<<x.first<<endl;
          cout<<"Naslov: "<<x.second->DajNaslov()<<endl;
          cout<<"Pisac: "<<x.second->DajAutora()<<endl;
          cout<<"Zanr: "<<x.second->DajZanr()<<endl;
          cout<<"Godina izdavanja: "<<x.second->DajGodinuIzdavanja()<<endl;
          if(x.second->DajKodKogaJe()!=nullptr)
          cout<<"Zaduzena kod korisnika: "<<x.second->DajKodKogaJe()->ime<<" "<<x.second->DajKodKogaJe()->prezime<<endl;
          cout<<endl;
        }
    }
    void PrikaziZaduzenja(int br)
    {
        bool ima=false;
        for(auto x: k) if(x.first==br) ima=true;
        if(!ima) throw logic_error("Korisnik nije nadjen");
        for(auto x: l)
        {
            if(*k[br]==*x.second->DajKodKogaJe())
            {
              cout<<"Evidencijski broj: "<<x.first<<endl;
              cout<<"Naslov: "<<x.second->DajNaslov()<<endl;
              cout<<"Pisac: "<<x.second->DajAutora()<<endl;
              cout<<"Zanr: "<<x.second->DajZanr()<<endl;
              cout<<"Godina izdavanja: "<<x.second->DajGodinuIzdavanja()<<endl;
              cout<<endl;
            }
        }
    }
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