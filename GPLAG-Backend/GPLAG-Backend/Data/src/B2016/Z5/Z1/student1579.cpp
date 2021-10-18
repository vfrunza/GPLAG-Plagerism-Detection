/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include<string>
#include<utility>
#include<map>
#include<stdexcept>
struct Korisnik {
    std::string ime,prezime,adresa,telefon;
};
class Knjiga
{
    std::string naslovknjige,imepisca,zanr;
    int godinaizdavanja;
    Korisnik *zaduzio=nullptr;
public:
    Knjiga (std::string naslov,std::string pisac,std::string zan,int godina):naslovknjige(naslov),imepisca(pisac),zanr(zan),godinaizdavanja(godina) {    }
    std::string DajNaslov() const{
        return naslovknjige;
    }
    std::string DajAutora() const {
        return imepisca;
    }
    std::string DajZanr() const{
        return zanr;
    }
    int DajGodinuIzdavanja()const {
        return godinaizdavanja;
    }
    Korisnik* DajKodKogaJe()const {
        return zaduzio;
    }
    void ZaduziKnjigu(Korisnik &zaduzuje) {
        zaduzio=&zaduzuje;
    }
    void RazduziKnjigu() {
        zaduzio=nullptr;
    }
    bool DaLiJeZaduzena()const {
        if(zaduzio==nullptr) return false;
        return true;
    }
};
class Biblioteka
{
    std::map<int,Korisnik*> mapakorisnika;
    std::map<int,Knjiga*> mapaknjiga;
public:
    ~Biblioteka() {
        for(auto it=mapakorisnika.begin(); it!=mapakorisnika.end(); it++) {
            delete it->second;
        }
        for(auto it=mapaknjiga.begin(); it!=mapaknjiga.end(); it++) {
            delete it->second;
        }
    }
    void RegistrirajNovogKorisnika(int x,std::string ime,std::string prezime,std::string adresa,std::string brtel) {
        Korisnik *pom=nullptr;
        try {
            pom=new Korisnik {ime,prezime,adresa,brtel};
        } catch(...) {
            throw;
        }
        if(!mapakorisnika.count(x)) mapakorisnika[x]=pom;
        else throw std::logic_error("Korisnik vec postoji");
    }
    void RegistrirajNovuKnjigu(int x,std::string naslov,std::string imep, std::string zanr,int godina) {
        Knjiga *pom=nullptr;
        try {
            pom=new Knjiga {naslov,imep,zanr,godina};
        } catch(...) {
            throw;
        }
        if(!mapaknjiga.count(x)) mapaknjiga[x]=pom;
        else throw std::logic_error("Knjiga vec postoji");
    }
    Korisnik &NadjiKorisnika(int x)const {
        auto it(mapakorisnika.find(x));
        if(it==mapakorisnika.end()) throw std::logic_error("Korisnik nije nadjen");
        else {
            return *(it->second);
        }
    }
    Knjiga &NadjiKnjigu(int x)const {
        auto it(mapaknjiga.find(x));
        if(it==mapaknjiga.end()) throw std::logic_error("Korisnik nije nadjen");
        else {
            return *(it->second);
        }
    }
    void IzlistajKorisnike() const{
        for(auto it=mapakorisnika.begin(); it!=mapakorisnika.end(); it++) {
            std::cout<<"Clanski broj: "<<it->first<<std::endl;
            std::cout<<"Ime i prezime: "<<(it->second)->ime<<" "<<(it->second)->prezime<<std::endl;
            std::cout<<"Adresa: "<<(it->second)->adresa<<std::endl;
            std::cout<<"Broj telefona: "<<(it->second)->telefon<<std::endl<<std::endl;
        }
    }
    void IzlistajKnjige()const {
        for(auto it=mapaknjiga.begin(); it!=mapaknjiga.end(); it++) {
            std::cout<<"Evidencijski broj: "<<it->first<<std::endl;
            std::cout<<"Naslov: "<<(it->second)->DajNaslov()<<std::endl;
            std::cout<<"Pisac: "<<(it->second)->DajAutora()<<std::endl;
            std::cout<<"Zanr: "<<(it->second)->DajZanr()<<std::endl;
            std::cout<<"Godina izdavanja: "<<(it->second)->DajGodinuIzdavanja()<<std::endl;
            if(!it->second->DaLiJeZaduzena()) std::cout<<std::endl;
            else
                std::cout<<"Zaduzena kod korisnika: "<<it->second->DajKodKogaJe()->ime<<" "<<it->second->DajKodKogaJe()->prezime<<std::endl<<std::endl;
        }
    }
    void ZaduziKnjigu(int x,int y) {
        auto it(mapaknjiga.find(x));
        if(it==mapaknjiga.end()) throw std::logic_error("Knjiga nije nadjena");
        auto it1(mapakorisnika.find(y));
        if(it1==mapakorisnika.end()) throw std::logic_error("Korisnik nije nadjen");
        if(!it->second->DaLiJeZaduzena())
            (it->second)->ZaduziKnjigu(*(it1->second));
        else {
            throw std::logic_error("Knjiga vec zaduzena");
        }
    }
    void RazduziKnjigu(int x) {
        auto it(mapaknjiga.find(x));
        if(it==mapaknjiga.end()) throw std::logic_error("Knjiga nije nadjena");
        if(!it->second->DaLiJeZaduzena()) throw std::logic_error("Knjiga nije zaduzena");
        it->second->RazduziKnjigu();
    }
    void PrikaziZaduzenja(int x) const{
        auto it1(mapakorisnika.find(x));
        bool ima=true;
        if(it1==mapakorisnika.end()) throw std::logic_error("Korisnik nije nadjen");
        for(auto it=mapaknjiga.begin(); it!=mapaknjiga.end(); it++) {
            if((it->second->DajKodKogaJe()->ime)==it1->second->ime && (it->second->DajKodKogaJe()->prezime)==it1->second->prezime && (it->second->DajKodKogaJe()->adresa)==it1->second->adresa && (it->second->DajKodKogaJe()->telefon)==it1->second->telefon) {
                ima=false;
                std::cout<<"Evidencijski broj: "<<it->first<<std::endl;
                std::cout<<"Naslov: "<<(it->second)->DajNaslov()<<std::endl;
                std::cout<<"Pisac: "<<(it->second)->DajAutora()<<std::endl;
                std::cout<<"Zanr: "<<(it->second)->DajZanr()<<std::endl;
                std::cout<<"Godina izdavanja: "<<(it->second)->DajGodinuIzdavanja()<<std::endl<<std::endl;
            }
        }
        if(ima){
            throw std::logic_error("Nema zaduzenja za tog korisnika!");
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