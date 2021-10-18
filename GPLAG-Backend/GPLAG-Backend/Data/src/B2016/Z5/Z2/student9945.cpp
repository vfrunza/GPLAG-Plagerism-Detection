/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <stdexcept>
#include <utility>
#include <new>
#include <memory>
using namespace std;
struct Korisnik {
    string ime, prezime, adresa, telefon;
};

class Knjiga {
    string naslov_knjige, ime_pisca, zanr;
    int godina_izdavanja;
    Korisnik *pok=nullptr;
    public:
    Knjiga(string n_k, string i_p, string z, int g_i) : naslov_knjige(n_k), ime_pisca(i_p), zanr(z), godina_izdavanja(g_i), pok(nullptr) {};
    string DajNaslov() const { return naslov_knjige; }
    string DajAutora() const { return ime_pisca; }
    string DajZanr() const { return zanr; }
    int DajGodinuIzdavanja() const { return godina_izdavanja; }
    Korisnik *&DajKodKogaJe()  { return pok; }
    void ZaduziKnjigu( Korisnik &k);
    void RazduziKnjigu();
    bool DaLiJeZaduzena();
};

void Knjiga::ZaduziKnjigu( Korisnik &k) {
    pok=&k;
}
void Knjiga::RazduziKnjigu() {
    pok=nullptr;
}
bool Knjiga::DaLiJeZaduzena() {
    if(pok==nullptr) return false;
    else return true;
}

class Biblioteka {
   map<int, shared_ptr<Korisnik>> mkorisnici;
   map<int, shared_ptr<Knjiga>> mknjige;
   public:
   Biblioteka() {};
   Biblioteka(const Biblioteka &bb);
   Biblioteka(Biblioteka &&bb);
   Biblioteka &operator=(Biblioteka bb);
   Biblioteka &operator=(Biblioteka &&bb);
   void RegistrirajNovogKorisnika(int cl_br, string i, string p, string adr, string br_tl);
   void RegistrirajNovuKnjigu(int br_knj, string nas, string imep, string znr,int godiz);
   Korisnik &NadjiKorisnika(int cl_br);
   Knjiga &NadjiKnjigu(int br_knj);
   void IzlistajKorisnike() const;
   void IzlistajKnjige() const;
   void ZaduziKnjigu(int br_knj, int cl_br);
   void RazduziKnjigu(int br_knj);
   void PrikaziZaduzenja(int cl_br);
};

Biblioteka::Biblioteka(const Biblioteka &bb) {
    auto t=mkorisnici.begin();
    for(auto it=bb.mkorisnici.begin();it!=bb.mkorisnici.end();it++) {
        t->second=make_shared<Korisnik>(*(it->second)); 
        mkorisnici.insert(make_pair(it->first,t->second));
        t++;
    }
    auto j=mknjige.begin();
    for(auto i=bb.mknjige.begin();i!=bb.mknjige.end();i++) {
        j->second=make_shared<Knjiga>(*(i->second));
        mknjige.insert(make_pair(i->first,j->second));
        j++;
    }
}
Biblioteka::Biblioteka(Biblioteka &&bb) {
    for(auto it=bb.mkorisnici.begin();it!=bb.mkorisnici.end();it++) {
        mkorisnici.insert(make_pair(it->first,it->second));
        it->second=nullptr;
    }
    for(auto i=bb.mknjige.begin();i!=bb.mknjige.end();i++) {
        mknjige.insert(make_pair(i->first,i->second));
        i->second=nullptr;
    }
}
Biblioteka &Biblioteka::operator =(Biblioteka bb) {
    swap(mkorisnici,bb.mkorisnici); swap(mknjige,bb.mknjige);
    return *this;
}
Biblioteka &Biblioteka::operator =(Biblioteka &&bb) {
    swap(mkorisnici,bb.mkorisnici); swap(mknjige,bb.mknjige);
    return *this;
}

void Biblioteka::RegistrirajNovogKorisnika(int cl_br, string i, string p, string adr, string br_tl) {
    for(auto it=mkorisnici.begin();it!=mkorisnici.end();it++) {
        if(it->first==cl_br) throw logic_error ("Korisnik vec postoji");
    }
    Korisnik kor;
    kor.ime=i; kor.prezime=p; kor.adresa=adr; kor.telefon=br_tl;
    auto k(make_shared<Korisnik>(kor));
    mkorisnici.insert(make_pair(cl_br,k));
}
void Biblioteka::RegistrirajNovuKnjigu(int br_knj, string nas, string imep, string znr,int godiz) {
    for(auto it=mknjige.begin();it!=mknjige.end();it++) {
        if(it->first==br_knj) throw logic_error ("Knjiga vec postoji");
    }
    Knjiga knjig(nas,imep,znr,godiz);
    auto pk(make_shared<Knjiga>(knjig));
    mknjige.insert(make_pair(br_knj,pk));
}
Korisnik &Biblioteka::NadjiKorisnika(int cl_br) {
    for(auto it=mkorisnici.begin();it!=mkorisnici.end();it++) {
        if(it->first==cl_br) return *(it->second); 
    }
    throw logic_error("Korisnik nije nadjen");
}
Knjiga &Biblioteka::NadjiKnjigu(int br_knj) {
    for(auto it=mknjige.begin();it!=mknjige.end();it++) {
        if(it->first==br_knj) return *(it->second);
    }
    throw logic_error("Knjiga nije nadjena");
}
void Biblioteka::IzlistajKorisnike() const {
    for(auto it=mkorisnici.begin();it!=mkorisnici.end();it++) {
        cout<<"Clanski broj: "<<it->first<<endl;
        cout<<"Ime i prezime: "<<it->second->ime<<" "<<it->second->prezime<<endl;
        cout<<"Adresa: "<<it->second->adresa<<endl;
        cout<<"Broj telefona: "<<it->second->telefon<<endl;
        cout<<endl;
    }
}
void Biblioteka::IzlistajKnjige() const {
    for(auto it=mknjige.begin();it!=mknjige.end();it++) {
        cout<<"Evidencijski broj: "<<it->first<<endl;
        cout<<"Naslov: "<<it->second->DajNaslov()<<endl;
        cout<<"Pisac: "<<it->second->DajAutora()<<endl;
        cout<<"Zanr: "<<it->second->DajZanr()<<endl;
        cout<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<endl;
        if(it->second->DajKodKogaJe()!=nullptr) cout<<"Zaduzena kod korisnika: "<<it->second->DajKodKogaJe()->ime<<" "<<it->second->DajKodKogaJe()->prezime<<endl;
        cout<<endl;
    }
}
void Biblioteka::ZaduziKnjigu(int br_knj, int cl_br) {
    bool a=false;
    for(auto it=mknjige.begin();it!=mknjige.end();it++) {
        if(it->first==br_knj) a=true;
    }
    if(a==false) throw logic_error ("Knjiga nije nadjena");
    bool b=false;
    for(auto it=mkorisnici.begin();it!=mkorisnici.end();it++) {
        if(it->first==cl_br) b=true;
    }
    if(b==false) throw logic_error("Korisnik nije nadjen");
    for(auto it=mknjige.begin();it!=mknjige.end();it++) {
        if(it->second->DajKodKogaJe()!=nullptr) throw logic_error("Knjiga vec zaduzena");
    }
    for(auto it=mkorisnici.begin();it!=mkorisnici.end();it++) {
        if(it->first==cl_br) {
            for(auto iter=mknjige.begin();iter!=mknjige.end();iter++) {
            if(iter->first==br_knj)  iter->second->DajKodKogaJe()=it->second.get(); }
        }
    }
}
void Biblioteka::RazduziKnjigu(int br_knj) {
     bool a=false;
    for(auto it=mknjige.begin();it!=mknjige.end();it++) {
        if(it->first==br_knj) a=true;
    }
    if(a==false) throw logic_error ("Knjiga nije nadjena");
    for(auto it=mknjige.begin();it!=mknjige.end();it++) {
        if(it->second->DajKodKogaJe()==nullptr) throw logic_error("Knjiga nije zaduzena");
    }
    for(auto iter=mknjige.begin();iter!=mknjige.end();iter++) {
        if(iter->first==br_knj)  iter->second->DajKodKogaJe()=nullptr; }
}
void Biblioteka::PrikaziZaduzenja(int cl_br) {
    bool b=false;
    for(auto it=mkorisnici.begin();it!=mkorisnici.end();it++) {
        if(it->first==cl_br) b=true;
    }
    if(b==false) throw logic_error("Korisnik nije nadjen");
    
    for(auto it=mkorisnici.begin();it!=mkorisnici.end();it++) {
        if(it->first==cl_br) {
        cout<<"Clanski broj: "<<it->first<<endl;
        cout<<"Ime i prezime: "<<it->second->ime<<" "<<it->second->prezime<<endl;
        cout<<"Adresa: "<<it->second->adresa<<endl;
        cout<<"Broj telefona: "<<it->second->telefon<<endl; 
        bool ima=false;
        for(auto iter=mknjige.begin();iter!=mknjige.end();iter++) {
            if(it->second.get()==iter->second->DajKodKogaJe()) { ima=true;
                cout<<"Evidencijski broj: "<<iter->first<<endl;
                cout<<"Naslov: "<<iter->second->DajNaslov()<<endl;
                cout<<"Pisac: "<<iter->second->DajAutora()<<endl;
                cout<<"Zanr: "<<iter->second->DajZanr()<<endl;
                cout<<"Godina izdavanja: "<<iter->second->DajGodinuIzdavanja()<<endl; }
            }
            if(ima==false) cout<<"Nema zaduzenja za tog korisnika";
        } 
    }     
}
int main ()
{
	return 0;
}