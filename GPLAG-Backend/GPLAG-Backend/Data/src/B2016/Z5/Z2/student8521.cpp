/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <memory>
#include <map>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <new>

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
    string DajNaslov()const{return naslov;}
    string DajAutora()const{return pisac;}
    string DajZanr()const{return zanr;}
    int DajGodinuIzdavanja() const {return godina_izdavanja;}
    Korisnik *DajKodKogaJe() const {return pok;}
    void ZaduziKnjigu(Korisnik &k){pok=&k;}
    void RazduziKnjigu(){pok=nullptr;}
    bool DaLiJeZaduzena(){if(pok!=nullptr)return true;return false;}
};

class Biblioteka {
     map<int,shared_ptr<Korisnik>>korisnici;
     map<int,shared_ptr<Knjiga>>knjige;
    public:
    Biblioteka(){};
    Biblioteka(const Biblioteka &b);
    Biblioteka(Biblioteka &&b);
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
    while(pomoc!=b.korisnici.end() && p!=korisnici.end()){
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
Biblioteka& Biblioteka::operator =(const Biblioteka &b){
    if(&b!=this){
        try {
            for(auto i=korisnici.begin();i!=korisnici.end();i=korisnici.begin()){
                i->second=nullptr;korisnici.erase(i->first);
                if(korisnici.size()==0)break;
            }
            for(auto j=b.korisnici.begin();j!=b.korisnici.end();j++){
                RegistrirajNovogKorisnika(j->first,j->second->ime,j->second->prezime,j->second->adresa,j->second->telefon);
            }
            for(auto i=knjige.begin();i!=knjige.end();i=knjige.begin()){
                i->second=nullptr;knjige.erase(i->first);
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
Biblioteka& Biblioteka::operator =(Biblioteka &&b){
    swap(korisnici,b.korisnici);
    swap(knjige,b.knjige);
    return *this;
}
void Biblioteka::RegistrirajNovogKorisnika(int clanski_broj,string i,string pr,string adr,string tel){
    try {
        for(auto it=korisnici.begin();it!=korisnici.end();it++){
            if(it->first==clanski_broj)throw logic_error("Korisnik vec postoji");
        }
        shared_ptr<Korisnik>k(new Korisnik);
        k->ime=i;k->prezime=pr;k->adresa=adr;k->telefon=tel;
        korisnici.insert(make_pair(clanski_broj,k));
    }
    catch(logic_error l){
        cout<<l.what();
    }
}
void Biblioteka::RegistrirajNovuKnjigu(int evidencijski_broj,string nas,string pis,string zan,int god){
    try {
       for(auto it=knjige.begin();it!=knjige.end();it++){
           if(it->first==evidencijski_broj)throw logic_error("Knjiga vec postoji");
       }
       shared_ptr<Knjiga> k(make_shared<Knjiga>(nas,pis,zan,god));
       knjige.insert(make_pair(evidencijski_broj,k));
    }
    catch(logic_error l) {
        cout<<l.what();
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
void Biblioteka::IzlistajKorisnike()const{
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
    if(clanski_broj<=0)throw logic_error("Korisnik nije nadjen");
     Knjiga *r =&NadjiKnjigu(evidencijski_broj);
    if(r->DaLiJeZaduzena())throw logic_error ("Knjiga vec zaduzena");
    r->ZaduziKnjigu(NadjiKorisnika(clanski_broj));
}

void Biblioteka::RazduziKnjigu(int evidencijski_broj){
    if(evidencijski_broj<=0)throw logic_error("Knjiga nije nadjena");
    Knjiga *r=&NadjiKnjigu(evidencijski_broj);
    if(!r->DaLiJeZaduzena())throw logic_error("Knjiga nije zaduzena");
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
/*Biblioteka b,b1;
b.RegistrirajNovogKorisnika(1234, "Petar", "Petrovic","Zmaja od Bosne 30", "032/444-555");
b1.RegistrirajNovogKorisnika(4312, "Hasan", "Hasanovic","Trg neznalica 111", "030/111-222");
b1.RegistrirajNovogKorisnika(3124, "Mehmed", "Mehmedovic","Studenata 3b", "037/654-321");
b.RegistrirajNovuKnjigu(231, "Prokleta avlija", "Ivo Andric", "Roman", 1955);
b1.RegistrirajNovuKnjigu(555, "Grimove Bajke", "Braca Grim", "Bajke", 1927);
b.RegistrirajNovuKnjigu(136, "Kameni spavac", "Mak Dizdar", "Poezija", 1960);
try{
//b.ZaduziKnjigu(231,1234);
//b.ZaduziKnjigu(555,1234);
//b.ZaduziKnjigu(136,1234);
//b.PrikaziZaduzenja(1234);
b.IzlistajKorisnike();
b=b1;
cout<<"Nakon dodjele"<<endl;
b.IzlistajKorisnike();
//b1.IzlistajKorisnike();
    
}
catch(logic_error l){
    cout<<l.what();
}*/
	return 0;
}