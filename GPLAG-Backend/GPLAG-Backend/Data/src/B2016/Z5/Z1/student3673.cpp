/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <new>
#include <stdexcept>
#include <algorithm>

using namespace std;

struct Korisnik {
    string ime,prezime,adresa,telefon;
};

class Knjiga {
    string naslov,pisac,zanr;
    int godina_izdavanja;
    Korisnik *pok=nullptr;
    public:
    Knjiga(string n,string p,string z,int g){naslov=n;pisac=p;zanr=z;godina_izdavanja=g;};
    string DajNaslov() const {return naslov;}
    string DajAutora() const {return pisac;}
    string DajZanr() const {return zanr;}
    int DajGodinuIzdavanja() const {return godina_izdavanja;}
    Korisnik *DajKodKogaJe() const {return pok;}
    void ZaduziKnjigu(Korisnik &k){pok=&k;}
    void RazduziKnjigu(){pok=nullptr;}
    bool DaLiJeZaduzena(){if(pok!=nullptr)return true;return false;}
};
class Biblioteka {
    map<int,Korisnik *>korisnici;
    map<int,Knjiga *>knjige;
    public:
    Biblioteka(){};
    Biblioteka(const Biblioteka &b);
    Biblioteka(Biblioteka &&b);
    ~Biblioteka();
    Biblioteka &operator =(const Biblioteka &b);
    Biblioteka &operator = (Biblioteka &&b);
    void RegistrirajNovogKorisnika(int clanski_broj,string i,string pr,string adr,string tel);
    void RegistrirajNovuKnjigu(int evidencijski_broj,string nas,string pis,string zan,int god);
    Korisnik &NadjiKorisnika(int clanski_broj);
    Knjiga &NadjiKnjigu(int evidencijski_broj);
    void IzlistajKorisnike()const;
    void IzlistajKnjige()const;
    void ZaduziKnjigu(int evidencijski_broj,int clanski_broj);
    void RazduziKnjigu(int evidencijski_broj);
    void PrikaziZaduzenja(int clanski_broj);
};
Biblioteka::Biblioteka(const Biblioteka &b){
    try {
    for(auto j=b.korisnici.begin();j!=b.korisnici.end();j++){
        RegistrirajNovogKorisnika(j->first,j->second->ime,j->second->prezime,j->second->adresa,j->second->telefon);
    }
    for(auto j=b.knjige.begin();j!=b.knjige.end();j++){
        RegistrirajNovuKnjigu(j->first,j->second->DajNaslov(),j->second->DajAutora(),j->second->DajZanr(),j->second->DajGodinuIzdavanja());
    }
   }
   catch(...){
       throw;
   }
}
Biblioteka::Biblioteka(Biblioteka &&b):korisnici(b.korisnici),knjige(b.knjige){
   auto p(korisnici.begin());auto pomoc(b.korisnici.begin());
   while (pomoc!=b.korisnici.end() && p!=korisnici.end()){
       p->second=pomoc->second;
       pomoc->second=nullptr;
       p++;pomoc++;
   }
   auto p2(knjige.begin());auto pomoc2(b.knjige.begin());
   while(pomoc2!=b.knjige.end() && p2!=knjige.end()){
       p2->second=pomoc2->second;
       pomoc2->second=nullptr;
       p2++;pomoc2++;
   }
}
 Biblioteka & Biblioteka::operator =(const Biblioteka &b){
     if(&b!=this){
         try {
             for(auto i=korisnici.begin();i!=korisnici.end();i=korisnici.begin()){
                 delete i->second;korisnici.erase(i->first);
                 if(korisnici.size()==0)break;
             }
        for(auto j=b.korisnici.begin();j!=b.korisnici.end();j++){
                RegistrirajNovogKorisnika(j->first,j->second->ime,j->second->prezime,j->second->adresa,j->second->telefon);
        }
        for(auto i=knjige.begin();i!=knjige.end();i=knjige.begin()){
                 delete i->second;knjige.erase(i->first);
                 if(knjige.size()==0)break;
             }
        for(auto j=b.knjige.begin();j!=b.knjige.end();j++){
            RegistrirajNovuKnjigu(j->first,j->second->DajNaslov(),j->second->DajAutora(),j->second->DajZanr(),j->second->DajGodinuIzdavanja());
        }
    }
         catch(...){
             throw;
         }
     }
     return *this;
 }
 Biblioteka & Biblioteka::operator = (Biblioteka &&b){
     swap(korisnici,b.korisnici);
     swap(knjige,b.knjige);
     return *this;
 }
void Biblioteka::RegistrirajNovogKorisnika(int clanski_broj,string i,string pr,string adr,string tel){
    Korisnik *k=nullptr;
    try {
        k=new Korisnik;
        k->ime=i;k->prezime=pr;k->adresa=adr;k->telefon=tel;
        for(auto it=korisnici.begin();it!=korisnici.end();it++){
            if(it->first==clanski_broj)throw logic_error("Korisnik vec postoji");
        }
        korisnici.insert(make_pair(clanski_broj,k));
    }
    catch(logic_error l){
        cout<<l.what();delete k;
    }
}

void Biblioteka::RegistrirajNovuKnjigu(int evidencijski_broj,string nas,string pis,string zan,int god){
    Knjiga *k=nullptr;
    try {
        k=new Knjiga(nas,pis,zan,god);
       for(auto it=knjige.begin();it!=knjige.end();it++){
           if(it->first==evidencijski_broj)throw logic_error("Knjiga vec postoji");
       }
       knjige.insert(make_pair(evidencijski_broj,k));
    }
    catch(logic_error l){
        cout<<l.what();delete k;
    }
}

Korisnik& Biblioteka::NadjiKorisnika(int clanski_broj){
    for(auto it=korisnici.begin();it!=korisnici.end();it++){
        if(it->first==clanski_broj)return *(it->second);
    }
    throw logic_error("Korisnik nije nadjen");
}
Knjiga& Biblioteka::NadjiKnjigu(int evidencijski_broj){
    for(auto it=knjige.begin();it!=knjige.end();it++){
        if(it->first==evidencijski_broj)return *(it->second);
    }
    throw logic_error("Knjiga nije nadjena");
}
Biblioteka::~Biblioteka(){
    for(auto it=korisnici.begin();it!=korisnici.end();it++){
        delete it->second;it->second=nullptr;
    }
    for(auto it=knjige.begin();it!=knjige.end();it++){
        delete it->second;it->second=nullptr;
    }
}
void Biblioteka:: IzlistajKorisnike()const{
    for(auto it=korisnici.begin();it!=korisnici.end();it++){
        cout<<"Clanski broj: "<<it->first<<endl;
        cout<<"Ime i prezime: "<<it->second->ime<<" "<<it->second->prezime<<endl;
        cout<<"Adresa: "<<it->second->adresa<<endl;
        cout<<"Broj telefona: "<<it->second->telefon<<endl;
        cout<<endl;
    }
}
void Biblioteka::IzlistajKnjige()const{
    for(auto it=knjige.begin();it!=knjige.end();it++){
        cout<<"Evidencijski broj: "<<it->first<<endl;
        cout<<"Naslov: "<<it->second->DajNaslov()<<endl;
        cout<<"Pisac: "<<it->second->DajAutora()<<endl;
        cout<<"Zanr: "<<it->second->DajZanr()<<endl;
        cout<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<endl;
        if(it->second->DaLiJeZaduzena()){
            cout<<"Zaduzena kod korisnika: "<<it->second->DajKodKogaJe()->ime<<" "<<it->second->DajKodKogaJe()->prezime<<endl;
        }
        cout<<endl;
    }
}
void Biblioteka::ZaduziKnjigu(int evidencijski_broj,int clanski_broj){
   if(evidencijski_broj<=0)throw logic_error("Knjiga nije nadjena");
   if(clanski_broj<=0) throw logic_error("Korisnik nije nadjen");
    Knjiga *r =&NadjiKnjigu(evidencijski_broj);
    if(r->DaLiJeZaduzena())throw logic_error ("Knjiga vec zaduzena");
    r->ZaduziKnjigu(NadjiKorisnika(clanski_broj));
}
void Biblioteka::RazduziKnjigu(int evidencijski_broj){
    if(evidencijski_broj<=0)throw logic_error("Knjiga nije nadjena");
    Knjiga *r =&NadjiKnjigu(evidencijski_broj);
    if(!r->DaLiJeZaduzena())throw logic_error ("Knjiga nije zaduzena");
    r->RazduziKnjigu();
}
void Biblioteka::PrikaziZaduzenja(int clanski_broj){
    if(clanski_broj<=0)throw logic_error("Korisnik nije nadjen");
    bool a(false);
    for(auto it=knjige.begin();it!=knjige.end();it++){
        if(it->second->DajKodKogaJe()==&NadjiKorisnika(clanski_broj)){
        a=true;
        cout<<"Evidencijski broj: "<<it->first<<endl;
        cout<<"Naslov: "<<it->second->DajNaslov()<<endl;
        cout<<"Pisac: "<<it->second->DajAutora()<<endl;
        cout<<"Zanr: "<<it->second->DajZanr()<<endl;
        cout<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<endl;
        cout<<endl;
        }
    }
    if(a==false)cout<<"Nema zaduzenja za tog korisnika!"<<endl;
}
int main ()
{
	return 0;
}