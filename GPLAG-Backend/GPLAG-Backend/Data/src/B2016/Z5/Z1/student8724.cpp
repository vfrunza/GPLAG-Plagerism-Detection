/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <stdexcept>

using std::cout;
using std::endl;
using std::string;
using std::map;
using std::make_pair;
using std::logic_error;

struct Korisnik{
    string ime, prezime, adresa, telefon;
};

class Knjiga{
    string naslov_knjige, ime_pisca, zanr;
    int godina_izdavanja;
    Korisnik *pok_zaduzenja=nullptr;
    public:
    Knjiga(string naslovknjige, string imepisca, string zanrr, int godinaizdavanja){naslov_knjige=naslovknjige; ime_pisca=imepisca; zanr=zanrr; godina_izdavanja=godinaizdavanja;}
    string DajNaslov() const{ return naslov_knjige; }
    string DajAutora() const{ return ime_pisca; }
    string DajZanr() const{ return zanr; }
    int DajGodinuIzdavanja() const{ return godina_izdavanja; }
    Korisnik* DajKodKogaJe() const{ return pok_zaduzenja; }
    void ZaduziKnjigu(Korisnik &a){ pok_zaduzenja=&a; }
    void RazduziKnjigu(){ pok_zaduzenja=nullptr; }
    bool DaLiJeZaduzena(){ if(pok_zaduzenja==nullptr) return false; return true; }
};

class Biblioteka{
    map<int, Korisnik*> korisnik;
    map<int, Knjiga*> knjiga;
    public:
    ~Biblioteka(){
        for(auto x : korisnik){
            delete x.second;
        }
        for(auto x : knjiga){
            delete x.second;
        }
    }
    void RegistrirajNovogKorisnika(int clanski_broj, string ime, string prezime, string adresa, string telefon){
        Korisnik* k=nullptr;
        try{
            k=new Korisnik{ime, prezime, adresa, telefon};
            if(korisnik.count(clanski_broj)>0) throw logic_error ("Korisnik vec postoji");
            else korisnik.insert(make_pair(clanski_broj, k));
        }
        catch(...){ throw; }
    }
    void RegistrirajNovuKnjigu(int evidencijski_broj_knjige, string naslov_knjige, string ime_pisca, string zanr, int godina_izdavanja){
        Knjiga* k=nullptr;
        try{
            k=new Knjiga{naslov_knjige, ime_pisca, zanr, godina_izdavanja};
            if(knjiga.count(evidencijski_broj_knjige)>0) throw logic_error ("Knjiga vec postoji");
            else knjiga.insert(make_pair(evidencijski_broj_knjige, k));
        }
        catch(...){ throw; }
    }

    Korisnik &NadjiKorisnika(int clanski_broj){
        auto it=korisnik.find(clanski_broj);
        bool nasao=true;
        if(it==korisnik.end()) nasao=false;
        if(nasao==0) throw logic_error("Korisnik nije nadjen");
        return *(it->second);
    }
    
    Knjiga &NadjiKnjigu(int evidencijski_broj_knjige){
        auto it=knjiga.find(evidencijski_broj_knjige);
        bool nasao=true;
        if(it==knjiga.end()) nasao=false;
        if(nasao==0) throw logic_error("Knjiga nije nadjena");
        return *(it->second);
    }
    
    void IzlistajKorisnike() const{
        for(auto it=korisnik.begin();it!=korisnik.end();it++){
        cout<<"Clanski broj: "<<it->first<<endl<<"Ime i prezime: "<<it->second->ime<<" "<<it->second->prezime<<endl<<"Adresa: "<<it->second->adresa<<endl<<"Broj telefona: "<<it->second->telefon<<endl;
        cout<<endl;
        }
    }
    void IzlistajKnjige() const{
        for(auto it=knjiga.begin();it!=knjiga.end();it++){
        cout<<"Evidencijski broj: "<<it->first<<endl<<"Naslov: "<<it->second->DajNaslov()<<endl<<"Pisac: "<<it->second->DajAutora()<<endl<<"Zanr: "<<it->second->DajZanr()<<endl<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<endl;
        if(it->second->DaLiJeZaduzena()) cout<<"Zaduzena kod korisnika: "<<it->second->DajKodKogaJe()->ime<<" "<<it->second->DajKodKogaJe()->prezime<<endl;
        else cout<<endl;
        }
    }
    
    void ZaduziKnjigu(int evidencijski_broj_knjige, int clanski_broj){
        auto it=knjiga.find(evidencijski_broj_knjige);
        bool nasao=true;
        if(it==knjiga.end()) nasao=false;
        if(nasao==0) throw logic_error("Knjiga nije nadjena");
        auto it1=korisnik.find(clanski_broj);
        bool nasao1=true;
        if(it1==korisnik.end()) nasao1=false;
        if(nasao1==0) throw logic_error("Korisnik nije nadjen");
        if(it->second->DaLiJeZaduzena()) throw logic_error ("Knjiga vec zaduzena");
        it->second->ZaduziKnjigu(*(it1->second));
        
    }
    
    void RazduziKnjigu(int evidencijski_broj_knjige){
        auto it=knjiga.find(evidencijski_broj_knjige);
        bool nasao=true;
        if(it==knjiga.end()) nasao=false;
        if(nasao==0) throw logic_error("Knjiga nije nadjena");
        if(!(it->second->DaLiJeZaduzena()) ) throw logic_error ("Knjiga nije zaduzena");
        it->second->RazduziKnjigu();
        
    }
    
   void PrikaziZaduzenja(int clanski_broj) const{
        bool nasao=false;
        auto it(korisnik.find(clanski_broj));
        if (it==korisnik.end()) throw logic_error("Korisnik nije nadjen");
        for (auto itx=knjiga.begin(); itx!=knjiga.end(); itx++){
            if ((itx->second->DajKodKogaJe()->ime)==(it->second->ime) && (itx->second->DajKodKogaJe()->prezime)==(it->second->prezime) && (itx->second->DajKodKogaJe()->adresa)==(it->second->adresa) && (itx->second->DajKodKogaJe()->telefon)==(it->second->telefon) ) {
                cout<<"Naslov: "<<itx->second->DajNaslov()<<endl<<"Pisac: "<<itx->second->DajAutora()<<endl<<"Zanr: "<<itx->second->DajZanr()<<endl<<"Godina izdavanja: "<<itx->second->DajGodinuIzdavanja()<<endl;
                cout<<endl; nasao=true;
            }
        }
        if (nasao==false) throw logic_error("Nema zaduzenja za tog korisnika!");
    }
};






int main (){
	return 0;
}