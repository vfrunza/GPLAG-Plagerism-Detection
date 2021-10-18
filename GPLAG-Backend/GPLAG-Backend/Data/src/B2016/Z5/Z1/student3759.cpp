/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <utility>
#include <map>
#include <stdexcept>
using std::cout;
using std::endl;
using std::string;
struct Korisnik{
    string ime, prezime, adresa, telefon;
};
class Knjiga{
    string naslov, ime_pisca, zanr;
    int godina_izdavanja;
    Korisnik *korisnik=nullptr;
    public:
    Knjiga (string nasloov, string imepisca, string zanrr, int godinaizdavanja): naslov(nasloov), ime_pisca(imepisca), zanr(zanrr), godina_izdavanja(godinaizdavanja){}
    string DajNaslov() const {return naslov;}
    string DajAutora() const {return ime_pisca;}
    string DajZanr() const {return zanr;}
    int DajGodinuIzdavanja() const {return godina_izdavanja;}
    Korisnik *DajKodKogaJe() const {return korisnik;}
    void ZaduziKnjigu(Korisnik &k){korisnik=&k;} // ili korisnik=&k, trebala bi oba biti dobra
    void RazduziKnjigu() {korisnik=nullptr;}
    bool DaLiJeZaduzena() const {if (korisnik==nullptr) return false; return true;}
};
class Biblioteka{
    std::map<int, Korisnik*> korisnici;
    std::map<int, Knjiga*> knjige;
    public:
    ~Biblioteka(){
        for (auto it=korisnici.begin(); it!=korisnici.end(); it++){
            delete it->second;
        }
        for (auto it2=knjige.begin();it2!=knjige.end(); it2++){
            delete it2->second;
        }
    }
    void RegistrirajNovogKorisnika(int clanski_broj, string ime, string prezime,  string adresa, string telefon){
        Korisnik *k=nullptr;
        try{
            k=new Korisnik{ime, prezime, adresa, telefon};
            if (korisnici.count(clanski_broj)>0) throw std::logic_error ("Korisnik vec postoji");
            else korisnici.insert(std::make_pair(clanski_broj, k));
        }
        catch(...){
            throw;
        }
    }
    void RegistrirajNovuKnjigu(int evid_broj_knjige, string naslov, string ime_pisca, string zanr, int godina_izdavanja){
        Knjiga *k=nullptr;
        try{
            k=new Knjiga{naslov, ime_pisca, zanr, godina_izdavanja};
            if (knjige.count(evid_broj_knjige)>0) throw std::logic_error ("Knjiga vec postoji");
            else knjige.insert(std::make_pair(evid_broj_knjige, k));
        }
        catch(...){
            
            throw;
        }
    }
    Korisnik &NadjiKorisnika(int cl_broj) const {
        auto it(korisnici.find(cl_broj));
        if (it==korisnici.end()) throw std::logic_error ("Korisnik nije nadjen");
       return *(it->second);
    }
    Knjiga &NadjiKnjigu(int broj) const {
        auto it(knjige.find(broj));
        if (it==knjige.end()) throw std::logic_error ("Korisnik nije nadjen");
        return *(it->second);
        
    }
    void IzlistajKorisnike() const{
        for (auto it=korisnici.begin(); it!=korisnici.end(); it++){
        cout<<"Clanski broj: "<<it->first<<endl<<"Ime i prezime: "<<it->second->ime<<" "<<it->second->prezime<<endl<<"Adresa: "<<it->second->adresa<<endl<<"Broj telefona: "<<it->second->telefon<<endl;
        cout<<endl;
        }
    }
    void IzlistajKnjige() const {
        for (auto it=knjige.begin(); it!=knjige.end(); it++){
            cout<<"Evidencijski broj: "<<it->first<<endl<<"Naslov: "<<it->second->DajNaslov()<<endl<<"Pisac: "<<it->second->DajAutora()<<endl<<"Zanr: "<<it->second->DajZanr()<<endl<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<endl;
            
            if (it->second->DaLiJeZaduzena()) cout<< "Zaduzena kod korisnika: "<<it->second->DajKodKogaJe()->ime<<" "<<it->second->DajKodKogaJe()->prezime<<endl;
            else cout<<endl;
        }
    }
    void ZaduziKnjigu(int evid_broj_knjige, int cl_broj) {
        auto it(knjige.find(evid_broj_knjige));
        if (it==knjige.end()) throw std::logic_error("Knjiga nije nadjena");
        auto it2(korisnici.find(cl_broj));
        if (it2==korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
        if (it->second->DaLiJeZaduzena()) throw std::logic_error("Knjiga vec zaduzena");
        it->second->ZaduziKnjigu(*(it2->second));
    }
    void RazduziKnjigu(int evid_broj_knjige){
        auto it(knjige.find(evid_broj_knjige));
        if (it==knjige.end()) throw std::logic_error("Knjiga nije nadjena");
        if (it->second->DaLiJeZaduzena()==false) throw std::logic_error("Knjiga nije zaduzena");
        it->second->RazduziKnjigu();
    }
    void PrikaziZaduzenja(int cl_broj) const{
        bool jel=false;
        auto it2(korisnici.find(cl_broj));
        if (it2==korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
        for (auto it=knjige.begin(); it!=knjige.end(); it++){
            if ((it->second->DajKodKogaJe()->ime)==(it2->second->ime) && (it->second->DajKodKogaJe()->prezime)==(it2->second->prezime) && (it->second->DajKodKogaJe()->adresa)==(it2->second->adresa) && (it->second->DajKodKogaJe()->telefon)==(it2->second->telefon) ) {
                cout<<"Naslov: "<<it->second->DajNaslov()<<endl<<"Pisac: "<<it->second->DajAutora()<<endl<<"Zanr: "<<it->second->DajZanr()<<endl<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<endl;
                cout<<endl; jel=true;
            }
        }
        if (jel==false) throw std::logic_error("Nema zaduzenja za tog korisnika!");
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