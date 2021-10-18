/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include <vector>

using namespace std;
struct Korisnik
{
	string ime, prezime, adresa, telefon;
	Korisnik (string i, string p, string a, string t)
	{
		ime=i;
		prezime=p;
		adresa=a;
		telefon=t;
	}
	friend bool operator!=(Korisnik k1, Korisnik k2)
	{
	    if(k1.ime==k2.ime && k1.prezime==k2.prezime && k1.adresa==k2.adresa && k1.telefon==k2.telefon) return true;
	    return false;
	}
};

class Knjiga 
{
	string naslov, ime_pisca, zanr;
	int god_izd;
	Korisnik *zaduzenje;
	public:
	Knjiga(string n, string ip, string z, int gi)
	{
		naslov=n;
		ime_pisca=ip;
		zanr=z;
		god_izd=gi;
		zaduzenje=nullptr;
		
	}
	string DajNaslov() const { return naslov; }
	string DajAutora() const { return ime_pisca; }
	string DajZanr() const { return zanr; }
	int DajGodinuIzdavanja() const { return god_izd; }
	Korisnik* DajKodKogaJe() const { return zaduzenje; }
	void ZaduziKnjigu(Korisnik &k) { zaduzenje=&k; }
	void RazduziKnjigu() { zaduzenje=nullptr; }
	bool DaLiJeZaduzena() { if(zaduzenje!=nullptr) return true; return false; }
};

class Biblioteka
{
    map<int, Korisnik*> m1;
    map<int, Knjiga*> m2;
    public:
    Biblioteka (){};
    ~Biblioteka()
    {
        for(auto i=m1.begin(); i!=m1.end(); i++) delete i->second;
        for(auto j=m2.begin(); j!=m2.end(); j++) delete j->second;
    }
    Biblioteka(Biblioteka &b)
    {
        for(auto i=b.m1.begin(); i!=b.m1.end(); i++)
            m1[i->first]=new Korisnik(*i->second);
        for(auto i=b.m2.begin(); i!=b.m2.end(); i++)
            m2[i->first]=new Knjiga(*i->second);
    }
    Biblioteka &operator=(Biblioteka &b)
    {
        if(this!=&b) {
        for(auto i=m1.begin(); i!=m1.end(); i++) delete i->second;
        for(auto j=m2.begin(); j!=m2.end(); j++) delete j->second;
        for(auto i=b.m1.begin();i!=b.m1.end(); i++)
            m1[i->first]=new Korisnik(*i->second);
        for(auto i:b.m2)
            m2[i.first]=new Knjiga(*i.second);
        }
        return *this;
    }
    Biblioteka(Biblioteka &&b)
    {
        for(auto i=b.m1.begin();i!=b.m1.end();i++)
            m1[i->first]=i->second;
        for(auto i=b.m2.begin(); i!=b.m2.end();i++)
            m2[i->first]=i->second;
    }
    Biblioteka &operator=(Biblioteka &&b)
    {
        if(this!=&b) {
        for(auto i=m1.begin(); i!=m1.end(); i++) delete i->second;
        for(auto j=m2.begin(); j!=m2.end(); j++) delete j->second;
        for(auto i=b.m1.begin();i!=b.m1.end();i++)
            m1[i->first]=i->second;
        for(auto i=b.m2.begin(); i!=b.m2.end();i++)
            m2[i->first]=i->second;
            }
        return *this;
    }
    void RegistrirajNovogKorisnika(int clanski, string i, string p, string a, string br_tel)
    {
        for(auto i=m1.begin(); i!=m1.end();i++)
            if(i->first==clanski) throw logic_error("Korisnik vec postoji");
        m1[clanski]=new Korisnik(i, p, a, br_tel);
    }
    void RegistrirajNovuKnjigu(int br_knj, string n, string ip, string z, int gi)
    {
        for(auto i=m2.begin(); i!=m2.end();i++)
            if(i->first==br_knj) throw logic_error("Knjiga vec postoji");
        m2[br_knj]=new Knjiga(n, ip, z, gi);
    }
    Korisnik &NadjiKorisnika(int cl_br)
    {
        for(auto i:m1)
            if(cl_br==i.first) return *i.second;
        throw logic_error("Korisnik nije nadjen");
    }
    Knjiga &NadjiKnjigu(int ev_br)
    {
        for(auto i:m2)
            if(ev_br==i.first) return *i.second;
        throw logic_error("Knjiga nije nadjena");
    }
    void IzlistajKorisnike()
    {
        for(auto x: m1)
        {
          cout<<"Clanski broj: "<<x.first<<endl;
          cout<<"Ime i prezime: "<<x.second->ime<<" "<<x.second->prezime<<endl;
          cout<<"Adresa: "<<x.second->adresa<<endl;
          cout<<"Broj telefona: "<<x.second->telefon;
          cout<<endl<<endl;
        }
    }
    void IzlistajKnjige()
    {
        for(auto x:m2)
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
    void PrikaziZaduzenja(int br)
    {
        bool cape=true;
        for(auto x: m1) if(x.first==br) cape=false;
        if(cape) throw logic_error("Korisnik nije nadjen");
        for(auto x: m2)
        {
            if(*m1[br]!=*x.second->DajKodKogaJe())
            {
              cout<<"Evidencijski broj: "<<x.first<<endl;
              cout<<"Naslov: "<<x.second->DajNaslov()<<endl;
              cout<<"Pisac: "<<x.second->DajAutora()<<endl;
              cout<<"Zanr: "<<x.second->DajZanr()<<endl;
              cout<<"Godina izdavanja: "<<x.second->DajGodinuIzdavanja()<<endl<<endl;
            }
        }
    }
    void ZaduziKnjigu(int ev_br, int clan_br)
    {
        bool cape=true;
        for(auto i:m2)
        {
            if(i.first==ev_br) cape=false;
            if(i.first==ev_br && i.second->DajKodKogaJe()!=nullptr) throw logic_error("Knjiga je vec zaduzena");
        }
        if(cape) throw logic_error("Knjiga nije nadjena");
        for(auto i:m1)
            if(i.first==clan_br) cape=true;
        if(!cape) throw logic_error("Korisnik nije nadjen");
        m2[ev_br]->ZaduziKnjigu(*m1[clan_br]);
    }
    void RazduziKnjigu(int x)
    {
        bool zile=true;
        for(auto i:m2)
        {
            if(i.first==x) zile=false;
            if(i.first==x && i.second->DajKodKogaJe()!=nullptr) throw logic_error("Knjiga je vec zaduzena");
        }
        if(zile) throw logic_error("Knjiga nije nadjena");
        m2[x]->RazduziKnjigu();
    }
};
int main ()
{
	return 0;
}