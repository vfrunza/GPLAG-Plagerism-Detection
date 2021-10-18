/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include <memory>

struct Korisnik {
    std::string ime, prezime, adresa, telefon;
};
class Knjiga
{
    std::string naslov, ime_pisca, zanr;
    int god;
    Korisnik*pok {nullptr};
public:
    Knjiga(std::string naslov, std::string ime_pisca, std::string zanr, int god) {
        Knjiga::naslov=naslov;
        Knjiga::ime_pisca=ime_pisca;
        Knjiga::zanr=zanr;
        Knjiga::god=god;
    }
    std::string DajNaslov()const {
        return naslov;
    }
    std::string DajAutora() const {
        return ime_pisca;
    }
    std::string DajZanr()const {
        return zanr;
    }
    int DajGodinuIzdavanja() const {
        return god;
    }
    Korisnik *DajKodKogaJe() const {
        return pok;
    }
    void ZaduziKnjigu(Korisnik &k) {
        pok=&k;
    }
    void RazduziKnjigu() {
        pok=nullptr;
    }
    bool DaLiJeZaduzena()const {
        if(pok==nullptr) return 0;
        return 1;
    }
    friend class Biblioteka;

};
class Biblioteka
{
    std::map<int, std::shared_ptr<Korisnik>>m;
    std::map<int, std::shared_ptr<Knjiga>>m2;
public:
    Biblioteka() =default;
    Biblioteka(const Biblioteka &b) {
        for(auto it=b.m.begin(); it!=b.m.end(); it++) {
            Korisnik *pomocna;
            try {
                pomocna =new Korisnik;
                pomocna->ime=it->second->ime;
                pomocna->prezime=it->second->prezime;
                pomocna->adresa=it->second->adresa;
                pomocna->telefon=it->second->telefon;
                m.insert(std::make_pair(it->first, std::shared_ptr<Korisnik>(pomocna)));
            } catch(...) {
                delete pomocna;
            }

        }
        for(auto it2=b.m2.begin(); it2!=b.m2.end(); it2++) {
            Knjiga *pomocna2;
            try {
                pomocna2 =new Knjiga(it2->second->naslov,it2->second->ime_pisca,it2->second->zanr,it2->second->god);

                m2.insert(std::make_pair(it2->first, std::shared_ptr<Knjiga>(pomocna2)));
            } catch(...) {
                delete pomocna2;
            }

        }
    }
    Biblioteka(Biblioteka &&b):m(b.m), m2(b.m2) {
        for(auto it=b.m.begin(); it!=b.m.end(); it++) it->second=nullptr;
        for(auto it=b.m2.begin(); it!=b.m2.end(); it++) it->second=nullptr;
    }
    Biblioteka &operator=(const Biblioteka &b) {
        if(&b!=this){
        for(auto it=b.m.begin(); it!=b.m.end(); it++) {
            Korisnik *pomocna;
            try {
                pomocna =new Korisnik;
                pomocna->ime=it->second->ime;
                pomocna->prezime=it->second->prezime;
                pomocna->adresa=it->second->adresa;
                pomocna->telefon=it->second->telefon;
                m.insert(std::make_pair(it->first,std::shared_ptr<Korisnik>(pomocna)));
            } catch(...) {
                delete pomocna;
            }

        }
        for(auto it2=b.m2.begin(); it2!=b.m2.end(); it2++) {
            Knjiga *pomocna2;
            try {
                pomocna2 =new Knjiga(it2->second->naslov,it2->second->ime_pisca,it2->second->zanr,it2->second->god);

                m2.insert(std::make_pair(it2->first, std::shared_ptr<Knjiga>(pomocna2)));
            } catch(...) {
                delete pomocna2;
            }

        }
        }
        return *this;
    }
    Biblioteka &operator=(Biblioteka &&b) {
        m=std::move(b.m);
        for(auto it=b.m.begin(); it!=b.m.end(); it++) it->second=nullptr;
        for(auto it=b.m2.begin(); it!=b.m2.end(); it++) it->second=nullptr;
        return *this;
    }
    void RegistrirajNovogKorisnika(int clanski_broj, std::string ime, std::string prezime, std::string adresa, std::string telefon) {
        int ima(0);
        for(auto it=m.begin(); it!=m.end(); it++) {
            if(it->first==clanski_broj) {
                ima=1;
                break;
            }
        }
        if(ima) throw std::logic_error("Korisnik vec postoji");
        Korisnik* p= new Korisnik;
        p->ime=ime;
        p->prezime=prezime;
        p->adresa=adresa;
        p->telefon=telefon;
        m.insert(std::make_pair(clanski_broj, std::shared_ptr<Korisnik>(p)));

    }
    void RegistrirajNovuKnjigu(int evid_broj, std::string naslov, std::string ime_pisca, std::string zanr, int god) {
        int ima(0);
        for(auto it=m2.begin(); it!=m2.end(); it++) {
            if(it->first==evid_broj) {
                ima=1;
                break;
            }
        }
        if(ima) throw std::logic_error("Knjiga vec postoji");
        std::shared_ptr<Knjiga> k(std::make_shared<Knjiga>(naslov, ime_pisca, zanr, god));
        m2.insert(std::make_pair(evid_broj, k));
    }
    Korisnik& NadjiKorisnika (int clanski_broj) {
        int ima(0);
        for(auto it=m.begin(); it!=m.end(); it++) {
            if(it->first!=clanski_broj) ima=0;
            else {
                ima=1;
                break;
            }
        }
        if(ima==0) throw std::logic_error("Korisnik nije nadjen");
        for(auto it=m.begin(); it!=m.end(); it++) {
            if(it->first==clanski_broj) return *(it->second);
        }
    }
    Knjiga& NadjiKnjigu(int evid_broj) {
        int ima(0);
        for(auto it=m2.begin(); it!=m2.end(); it++) {
            if(it->first!=evid_broj) ima=0;
            else {
                ima=1;
                break;
            }
        }
        if(ima==0) throw std::logic_error("Knjiga nije nadjena");
        for(auto it=m2.begin(); it!=m2.end(); it++) {
            if(it->first==evid_broj) return (*(it->second));
        }
    }
    void IzlistajKnjige()const {
        for(auto it=m2.begin(); it!=m2.end(); it++) {
            std::cout<<"Evidencijski broj: "<<it->first<<std::endl;
            std::cout<<"Naslov: "<<(*(it->second)).naslov<<std::endl;
            std::cout<<"Pisac: "<<(*(it->second)).ime_pisca<<std::endl;
            std::cout<<"Zanr: "<<(*(it->second)).zanr<<std::endl;
            std::cout<<"Godina izdavanja: "<<(*(it->second)).god<<std::endl;
            if(it->second->DaLiJeZaduzena()) {
                std::cout<<"Zaduzena kod korisnika: "<<it->second->pok->ime<<" "<<it->second->pok->prezime<<std::endl;
            }
            std::cout<<std::endl;
        }
    }
    void IzlistajKorisnike()const {
        for(auto it=m.begin(); it!=m.end(); it++) {
            std::cout<<"Clanski broj: "<<it->first<<std::endl;
            std::cout<<"Ime i prezime: "<<(*(it->second)).ime<<" "<<(*(it->second)).prezime<<std::endl;
            std::cout<<"Adresa: "<<(*(it->second)).adresa<<std::endl;
            std::cout<<"Broj telefona: "<<(*(it->second)).telefon<<std::endl<<std::endl;
        }
    }
    void ZaduziKnjigu(int evid_broj, int clanski_broj) {
        int ima(0), ima2(0);
        for(auto it=m2.begin(); it!=m2.end(); it++) {
            if(it->first!=evid_broj) ima=0;
            else {
                ima=1;
                break;
            }
        }
        if(ima==0) throw std::logic_error("Knjiga nije nadjena");
        for(auto it=m.begin(); it!=m.end(); it++) {
            if(it->first!=clanski_broj) ima2=0;
            else {
                ima2=1;
                break;
            }
        }
        if(ima2==0) throw std::logic_error("Korisnik nije nadjen");
        for(auto it=m2.begin(); it!=m2.end(); it++) {
            if(it->first==evid_broj && (it->second)->DaLiJeZaduzena()==1) throw std::logic_error("Knjiga vec zaduzena");
            else if(it->first==evid_broj && (it->second)->DaLiJeZaduzena()==0) {
                std::shared_ptr<Korisnik>pok2=nullptr;
                for(auto it2=m.begin(); it2!=m.end(); it2++) {
                    if(it2->first==clanski_broj) {
                        pok2=it2->second;
                        break;
                    }
                }
                (it->second)->pok=pok2.get();

            }
        }

    }
    void RazduziKnjigu(int evid_broj) {
        int ima(0);
        for(auto it=m2.begin(); it!=m2.end(); it++) {
            if(it->first!=evid_broj) ima=0;
            else {
                ima=1;
                break;
            }
        }
        if(ima==0) throw std::logic_error("Knjiga nije nadjena");
        for(auto it=m2.begin(); it!=m2.end(); it++) {
            if(it->first==evid_broj) {
                if((it->second)->DaLiJeZaduzena() && it->second->pok==nullptr) throw std::logic_error("Knjiga nije zaduzena");
                if((it->second)->DaLiJeZaduzena())(it->second)->pok=nullptr;
            }
        }
    }
    void PrikaziZaduzenja(int clanski_broj) {
        int ima(0);
        for(auto it=m.begin(); it!=m.end(); it++) {
            if(it->first!=clanski_broj) ima=0;
            else {
                ima=1;
                break;
            }
        }
        if(ima==0) throw std::logic_error("Korisnik nije nadjen");
        int ima2(0);
        for(auto it=m.begin(); it!=m.end(); it++) {
            if(it->first==clanski_broj) {
                for(auto it2=m2.begin(); it2!=m2.end(); it2++) {
                    if(it2->second->pok!=it->second.get()) ima2=0;
                    else ima2=1; break;}}}
                    if(ima2==0)throw std::logic_error("Nema zaduzenja za tog korisnika!");
        for(auto it=m.begin(); it!=m.end(); it++) {
            if(it->first==clanski_broj) {
                for(auto it2=m2.begin(); it2!=m2.end(); it2++) {
                    if(it2->second->pok==it->second.get()) {
                        std::cout<<"Evidencijski broj: "<<it2->first<<std::endl;
                        std::cout<<"Naslov: "<<it2->second->naslov<<std::endl;
                        std::cout<<"Pisac: "<<it2->second->ime_pisca<<std::endl;
                        std::cout<<"Zanr: "<<it2->second->zanr<<std::endl;
                        std::cout<<"Godina izdavanja: "<<it2->second->god<<std::endl;
                        std::cout<<std::endl;

                    }
                }
            }
        }
    }
};
int main ()
{
    return 0;
}