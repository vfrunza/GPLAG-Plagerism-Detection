#include <iostream>
#include <map>
#include <string>
#include <stdexcept>
#include <vector>
using namespace std;

struct Korisnik
{
    string ime, prezime, adresa, telefon;
    Korisnik(string i, string p, string a, string t)
    {
        ime=i; prezime=p; adresa=a; telefon=t;
    }
    friend int poredi(Korisnik k2, Korisnik k1)
    {
        if(k1.ime==k2.ime && k1.prezime==k2.prezime && k1.adresa==k2.adresa && k1.telefon==k2.telefon) return 1;
        else return 0;
    }
};

class Knjiga
{
    string naslov, autor, zanr;
    int god;
    Korisnik *pok;
public:
    Knjiga(string n, string a, string z, int g)
    {
        naslov=n;
        autor=a;
        zanr=z;
        god=g;
        pok=nullptr;
    }
    string DajNaslov() const
    {
        return naslov;
    }
    string DajAutora() const
    {
        return autor;
    }
    string DajZanr() const
    {
        return zanr;
    }
    int DajGodinuIzdavanja() const
    {
        return god;
    }
    void ZaduziKnjigu(Korisnik &k)
    {
        pok=&k;
    }
    void RazduziKnjigu()
    {
        pok=nullptr;
    }
    Korisnik *DajKodKogaJe()
    {
        return pok;
    }
    bool DaLiJeZaduzena()
    {
        if(pok==nullptr) return false;
        else return true;
    }
};

class Biblioteka
{
    map<int, Korisnik*> clanovi;
    map<int, Knjiga*> libris;
public:
    Biblioteka() {};
    Biblioteka(Biblioteka &z)
    {
        for(auto x: z.clanovi)
        {
            int a=x.first;
            Korisnik* p=new Korisnik(*x.second);
            pair<int, Korisnik*> pom;
            pom.first=a; pom.second=p;
            clanovi.insert(pom);
        }
        for(auto x: z.libris)
        {
            int a=x.first;
            Knjiga* p=new Knjiga(*x.second);
            pair<int, Knjiga*> pom;
            pom.first=a; pom.second=p;
            libris.insert(pom);
        }
    }
    Biblioteka(Biblioteka &&z)
    {
        for(auto x: z.clanovi)
        {
            int a=x.first;
            Korisnik* p=x.second;
            pair<int, Korisnik*> pom;
            pom.first=a; pom.second=p;
            clanovi.insert(pom);
        }
        for(auto x: z.libris)
        {
            int a=x.first;
            Knjiga* p=x.second;
            pair<int, Knjiga*> pom;
            pom.first=a; pom.second=p;
            libris.insert(pom);
        }
    }
    Biblioteka &operator =(Biblioteka &z)
    {
        if(&z!=this)
        {
            for(auto &x: libris) delete x.second;
            for(auto &x: clanovi) delete x.second;
            for(auto x: z.clanovi)
            {
                int a=x.first;
            Korisnik* p=new Korisnik(*x.second);
            pair<int, Korisnik*> pom;
            pom.first=a; pom.second=p;
            clanovi.insert(pom);
            }
            for(auto x: z.libris)
        {
            int a=x.first;
            Knjiga* p=new Knjiga(*x.second);
            pair<int, Knjiga*> pom;
            pom.first=a; pom.second=p;
            libris.insert(pom);
        }
        }
        return *this;
    }
        Biblioteka &operator = (Biblioteka &&z)
        {
            if(&z!=this)
        {
            for(auto &x: libris) delete x.second;
            for(auto &x: clanovi) delete x.second;
            for(auto x: z.clanovi)
        {
            int a=x.first;
            Korisnik* p=x.second;
            pair<int, Korisnik*> pom;
            pom.first=a; pom.second=p;
            clanovi.insert(pom);
        }
        for(auto x: z.libris)
        {
            int a=x.first;
            Knjiga* p=x.second;
            pair<int, Knjiga*> pom;
            pom.first=a; pom.second=p;
            libris.insert(pom);
        }
        }
        return *this;
    }
    void RegistrirajNovogKorisnika(int br, string im, string pr, string adr, string tel)
    {
        for(auto i: clanovi)
            if(br==i.first) throw logic_error("Korisnik vec postoji");
        pair<int, Korisnik*> par;
        par.first=br; par.second=new Korisnik(im,pr,adr,tel);
        clanovi.insert(par);
    }
    void RegistrirajNovuKnjigu(int br, string i, string au, string zan, int g)
    {
        for(auto i: libris)
            if(br==i.first) throw logic_error("Knjiga vec postoji");
        pair<int, Knjiga*> par;
        par.first=br; par.second=new Knjiga(i,au,zan,g);
        libris.insert(par);
    }
    void PrikaziZaduzenja(int br)
    {
        bool nj=true;
        for(auto x: clanovi) if(x.first==br) nj=false;
        if(nj) throw logic_error("Korisnik nije nadjen");
        for(auto x: libris)
        {
            if(poredi(*clanovi[br],*x.second->DajKodKogaJe())==1)
            {
              cout<<"Evidencijski broj: "<<x.first<<endl;
              cout<<"Naslov: "<<x.second->DajNaslov()<<endl;
              cout<<"Pisac: "<<x.second->DajAutora()<<endl;
              cout<<"Zanr: "<<x.second->DajZanr()<<endl;
              cout<<"Godina izdavanja: "<<x.second->DajGodinuIzdavanja()<<endl<<endl;
            }
        }
    }
    ~Biblioteka()
    {
        for(auto i: libris) delete i.second;
        for(auto i: clanovi) delete i.second;
    }
    Korisnik &NadjiKorisnika(int br)
    {
        for(auto i: clanovi) if(i.first==br) return *i.second;
        throw logic_error("Korisnik nije nadjen");
    }
    Knjiga &NadjiKnjigu(int br)
    {
        for(auto i: libris) if(i.first==br) return *i.second;
        throw logic_error("Knjiga nije nadjena");
    }
    void RazduziKnjigu(int a)
    {
        bool nj=true;
        for(auto i: libris)
        {
            if(i.first==a)
            {
                nj=false;
                if(i.second->DajKodKogaJe()!=nullptr) throw logic_error("Knjiga vec zaduzena");
            }
        }
        if(nj==true) throw logic_error("Knjiga nije nadjena");
        libris[a]->RazduziKnjigu();
    }
    void IzlistajKnjige()
    {
        for(auto x:libris)
        {
          cout<<"Evidencijski broj: "<<x.first<<endl;
          cout<<"Naslov: "<<x.second->DajNaslov()<<endl;
          cout<<"Pisac: "<<x.second->DajAutora()<<endl;
          cout<<"Zanr: "<<x.second->DajZanr()<<endl;
          cout<<"Godina izdavanja: "<<x.second->DajGodinuIzdavanja()<<endl;
          if(x.second->DajKodKogaJe()!=nullptr)
          cout<<"Zaduzena kod korisnika: "<<x.second->DajKodKogaJe()->ime<<" "<<x.second->DajKodKogaJe()->prezime<<endl<<endl;
        }
    }
    void ZaduziKnjigu(int a, int b)
    {
        bool nj=true;
        for(auto i: libris)
        {
            if(i.first==a)
            {
                nj=false;
                if(i.second->DajKodKogaJe()!=nullptr) throw logic_error("Knjiga vec zaduzena");
            }
        }
        if(nj==true) throw logic_error("Knjiga nije nadjena");
        nj=true;
        for(auto i: clanovi)
            if(i.first==b) nj=false;
        if(nj==true) throw logic_error("Korisnik nije nadjen");
        libris[a]->ZaduziKnjigu(*clanovi[b]);
    }
    void IzlistajKorisnike()
    {
        for(auto x: clanovi)
        {
          cout<<"Clanski broj: "<<x.first<<endl;
          cout<<"Ime i prezime: "<<x.second->ime<<" "<<x.second->prezime<<endl;
          cout<<"Adresa: "<<x.second->adresa<<endl;
          cout<<"Broj telefona: "<<x.second->telefon<<endl;
          cout<<endl;
        }
    }
    
};

int main ()
{
	return 0;
}