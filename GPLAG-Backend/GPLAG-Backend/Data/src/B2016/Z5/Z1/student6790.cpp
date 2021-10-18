
#include <iostream>
#include <string>
#include <map>
#include <stdexcept>

struct Korisnik {
    std::string ime;
    std::string prezime;
    std::string adresa;
    std::string telefon;
};

class Knjiga {
    std::string naslov;
    std::string ime_pisca;
    std::string zanr;
    int godina_izdavanja;
    Korisnik *zaduzio;
    public:
    Knjiga(const Knjiga &k) {*this=k;}
    Knjiga(std::string nas, std::string ime, std::string z, int god): naslov(nas), 
    ime_pisca(ime), zanr(z), godina_izdavanja(god), zaduzio(nullptr) {}
    std::string DajNaslov() {return naslov;}
    std::string DajAutora() {return ime_pisca;}
    std::string DajZanr() {return zanr;}
    int DajGodinuIzdavanja() {return godina_izdavanja;}
    Korisnik *DajKodKogaJe() {return zaduzio;}
    void ZaduziKnjigu (Korisnik &kor) {zaduzio=&kor;}
    void RazduziKnjigu() {zaduzio=nullptr;}
    bool DaLiJeZaduzena() {if(zaduzio==nullptr) return false; else return true;}
};

class Biblioteka {
    private:
    std::map<int, Korisnik*> korisnici;
    std::map<int, Knjiga*> knjige;
    public:
    Biblioteka() {}
    Biblioteka(const Biblioteka &b){
        *this=b;
    for(auto i=b.korisnici.begin(); i!=b.korisnici.end(); i++) {
        auto kor=korisnici.begin();
        kor->second=new Korisnik;
        kor->second=i->second;
        kor++;
    }
    for(auto i=b.knjige.begin(); i!=b.knjige.end(); i++) {
        auto kor=knjige.begin();
        kor->second=new Knjiga(*i->second);
        kor++;
    }
    }
    ~Biblioteka() {
        for(auto i=knjige.begin(); i!=knjige.end(); i++) {
        delete i->second; i->second=nullptr; 
        }
        for(auto i=korisnici.begin(); i!=korisnici.end(); i++) {
        delete i->second; i->second=nullptr; 
        }
    }
    void RegistrirajNovogKorisnika(int cl_br, std::string ime, std::string prez, std::string adresa, std::string br_tel) {
        Korisnik kor;
        kor.ime=ime;  kor.prezime=prez; kor.adresa=adresa; kor.telefon=br_tel;
        Korisnik *pok=new Korisnik(kor);
        for(auto i=korisnici.begin(); i!=korisnici.end(); i++) {
            if(cl_br==i->first) {throw std::logic_error("Korisnik vec postoji");}
        }
        korisnici.insert(std::pair<int, Korisnik*>(cl_br, pok)) ;
    }
    void RegistrirajNovuKnjigu(int ev_br, std::string naslov, std::string ime_pisca, std::string zanr, int godina) {
        Knjiga *pok=new Knjiga(naslov, ime_pisca, zanr, godina);
        for(auto i=knjige.begin(); i!=knjige.end(); i++) {
            if(ev_br==i->first) {throw std::logic_error("Knjiga vec postoji");}
        }
        knjige.insert(std::pair<int, Knjiga*>(ev_br, pok)) ;
    }
    Korisnik &NadjiKorisnika (int cl_br) const {
         for(auto i=korisnici.begin(); i!=korisnici.end(); i++) {
            if(cl_br==i->first) { return *i->second;}
        }
        throw std::logic_error("Korisnik nije nadjen");
    }
    Knjiga &NadjiKnjigu  (int ev_br) const {
         for(auto i=knjige.begin(); i!=knjige.end(); i++) {
            if(ev_br==i->first) { return *i->second;}
        }
        throw std::logic_error("Knjiga nije nadjena");
    }
    void IzlistajKorisnike() const {
        for(auto i=korisnici.begin(); i!=korisnici.end(); i++) {
        std::cout<<"Clanski broj: "<<i->first<<std::endl<<"Ime i prezime: "<<i->second->ime<<" "<<i->second->prezime
        <<std::endl<<"Adresa: "<<i->second->adresa<<std::endl<<"Broj telefona: "<<i->second->telefon<<std::endl<<std::endl;
        }
    }
    void IzlistajKnjige() const {
        for(auto i=knjige.begin(); i!=knjige.end(); i++) {
        std::cout<<"Evidencijski broj: "<<i->first<<std::endl<<"Naslov: "<<i->second->DajNaslov()<<std::endl
        <<"Pisac: "<<i->second->DajAutora()<<std::endl<<"Zanr: "<<i->second->DajZanr()<<std::endl
        <<"Godina izdavanja: "<<i->second->DajGodinuIzdavanja()<<std::endl;
        if(i->second->DajKodKogaJe()!=nullptr) std::cout<<"Zaduzena kod korisnika: "<<i->second->DajKodKogaJe()->ime<<" "<<i->second->DajKodKogaJe()->prezime
        <<std::endl; std::cout<<std::endl;
        }
    }
    void ZaduziKnjigu(int ev_br, int cl_br) {
        bool da=false; 
        auto pok_na_knjigu=knjige.begin();
        for(auto i=knjige.begin(); i!=knjige.end(); i++) {
            if(ev_br==i->first) {da=true; pok_na_knjigu=i;}
        }
        if(da==false) throw std::logic_error("Knjiga nije nadjena");
        da=false; auto pok_na_korisnika=korisnici.begin();
        for(auto i=korisnici.begin(); i!=korisnici.end(); i++) {
            if(cl_br==i->first) { da=true; pok_na_korisnika=i;}
        }
        if(da==false) throw std::logic_error("Korisnik nije nadjen");
        pok_na_knjigu->second->ZaduziKnjigu(*pok_na_korisnika->second);
        
    }
};
int main ()
{
    std::cout<<"Unesite "
    

	return 0;
}