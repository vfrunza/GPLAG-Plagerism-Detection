#include <iostream>
#include <string>
#include <map>
#include <memory>

struct Korisnik {
    std::string ime, prezime, adresa, telefon;   
};
class Biblioteka;
class Knjiga {
    std::string naslov, ime_pisca, zanr;
    int god_izdavanja;
    Korisnik *pok;
    friend Biblioteka;
    public:
    Knjiga(std::string naslov, std::string ime_pisca, std::string zanr, int god_izdavanja) : naslov(naslov), ime_pisca(ime_pisca), zanr(zanr), god_izdavanja(god_izdavanja) {this->pok=nullptr;}
    std::string DajNaslov () const { return naslov; }
    std::string DajAutora () const { return ime_pisca; }
    std::string DajZanr () const { return zanr; }
    int DajGodinuIzdavanja  () const { return god_izdavanja; }
    Korisnik * DajKodKogaJe () const { return pok; }
    void ZaduziKnjigu (Korisnik & korisnik) { pok=&korisnik; }
    void RazduziKnjigu () { pok=nullptr; }
    bool DaLiJeZaduzena () const { return pok!=nullptr; }
};

class Biblioteka {
    std::map<int,std::shared_ptr<Korisnik>> mapa_korisnika;
    std::map<int,std::shared_ptr<Knjiga>> mapa_knjiga;
  
    public:
    Biblioteka(){}
    Biblioteka(Biblioteka &bib);
    Biblioteka(const Biblioteka &bib);
    void RegistrirajNovogKorisnika (int clanski_br, std::string ime, std::string prezima, std::string adresa, std::string telefon);
    void RegistrirajNovuKnjigu (int evid_br, std::string naslov, std::string ime_pisca, std::string zanr, int god_izdavanja);
    Korisnik & NadjiKorisnika (int clanski_br){   
        if(mapa_korisnika.find(clanski_br)==mapa_korisnika.end())
            throw std::logic_error ("Korisnik nije nadjen");
        else return *mapa_korisnika[clanski_br];
  }
    Knjiga & NadjiKnjigu (int evid_br){   
        if(mapa_knjiga.find(evid_br)==mapa_knjiga.end())
            throw std::logic_error ("Knjiga nije nadjena");
        else return *mapa_knjiga[evid_br];
  }
    void IzlistajKorisnike () const;
    void IzlistajKnjige () const;
    void ZaduziKnjigu(int evid_br, int clanski_br);
    void RazduziKnjigu(int evid_br);
    void PrikaziZaduzenja(int clanski_br) const;
};

Biblioteka::Biblioteka(const Biblioteka &bib){
    for(auto &korisnik: bib.mapa_korisnika)
        RegistrirajNovogKorisnika(korisnik.first, korisnik.second->ime, korisnik.second->prezime, korisnik.second->adresa, korisnik.second->telefon);
    for(auto &knjiga: bib.mapa_knjiga)
        RegistrirajNovuKnjigu(knjiga.first, knjiga.second->naslov, knjiga.second->ime_pisca, knjiga.second->zanr, knjiga.second->god_izdavanja);
        
    for(auto &korisnik: bib.mapa_korisnika)
        for(auto &knjiga: bib.mapa_knjiga)
            if(&*korisnik.second==knjiga.second->pok)
                mapa_knjiga.at(knjiga.first)->pok=&*mapa_korisnika.at(korisnik.first);
}

Biblioteka::Biblioteka(Biblioteka &bib){
    for(auto &korisnik: bib.mapa_korisnika)
        RegistrirajNovogKorisnika(korisnik.first, korisnik.second->ime, korisnik.second->prezime, korisnik.second->adresa, korisnik.second->telefon);
    for(auto &knjiga: bib.mapa_knjiga)
        RegistrirajNovuKnjigu(knjiga.first, knjiga.second->naslov, knjiga.second->ime_pisca, knjiga.second->zanr, knjiga.second->god_izdavanja);
        
    for(auto &korisnik: bib.mapa_korisnika)
        for(auto &knjiga: bib.mapa_knjiga)
            if(&*korisnik.second==knjiga.second->pok)
                mapa_knjiga.at(knjiga.first)->pok=&*mapa_korisnika.at(korisnik.first);
}

void Biblioteka::RegistrirajNovogKorisnika (int clanski_br, std::string ime, std::string prezime, std::string adresa, std::string telefon) {
    try{
        if(mapa_korisnika.find(clanski_br)!=mapa_korisnika.end())
            throw std::logic_error ("Korisnik vec postoji");
     
        mapa_korisnika[clanski_br]=std::shared_ptr<Korisnik> (new Korisnik{ime,prezime, adresa, telefon});
    }catch(std::logic_error izuzetak){
        std::cout<<izuzetak.what()<<std::endl;
    }
}

void Biblioteka::RegistrirajNovuKnjigu (int evid_br, std::string naslov, std::string ime_pisca, std::string zanr, int god_izdavanja){
    try{
        if(mapa_knjiga.find(evid_br)!=mapa_knjiga.end())
            throw std::logic_error ("Knjiga vec postoji");
     
        mapa_knjiga[evid_br]=std::shared_ptr<Knjiga>(new Knjiga{naslov, ime_pisca, zanr, god_izdavanja});
    }catch(std::logic_error izuzetak){
        std::cout<<izuzetak.what()<<std::endl;
    }
}

void Biblioteka::IzlistajKnjige () const {
    for(auto& knjiga : mapa_knjiga){
        std::cout<<"Evidencijski broj: "<< knjiga.first<<std::endl
        <<"Naslov: "<< knjiga.second->naslov<<std::endl
        <<"Pisac: "<<knjiga.second->ime_pisca<<std::endl
        <<"Zanr: "<<knjiga.second->zanr<<std::endl
        <<"Godina izdavanja: "<<knjiga.second->god_izdavanja<<std::endl;
        if(knjiga.second->pok!=nullptr)
            std::cout<<"Zaduzena kod korisnika: "<< knjiga.second->pok->ime<<" "<<knjiga.second->pok->prezime<<std::endl;
        std::cout<<std::endl;
    }
}

void Biblioteka::IzlistajKorisnike () const {
    for(auto& korisnik : mapa_korisnika){
        std::cout<<"Clanski broj: "<< korisnik.first<<std::endl
        <<"Ime i prezime: "<< korisnik.second->ime<<" "<<korisnik.second->prezime<<std::endl
        <<"Adresa: "<<korisnik.second->adresa<<std::endl
        <<"Broj telefona: "<<korisnik.second->telefon<<std::endl<<std::endl;
    }
}

void Biblioteka::ZaduziKnjigu(int evid_br, int clanski_br){
    if(mapa_knjiga.find(evid_br)==mapa_knjiga.end())
        throw std::logic_error("Knjiga nije nadjena");
    if(mapa_korisnika.find(clanski_br)==mapa_korisnika.end())
        throw std::logic_error("Korisnik nije nadjen");
    if(mapa_knjiga[evid_br]->pok!=nullptr)
        throw std::logic_error("Knjiga vec zaduzena");
    mapa_knjiga[evid_br]->pok=&*mapa_korisnika[clanski_br];
}

void Biblioteka::RazduziKnjigu(int evid_br){
    if(mapa_knjiga.find(evid_br)==mapa_knjiga.end())
        throw std::logic_error("Knjiga nije nadjena");
    if(mapa_knjiga[evid_br]->pok==nullptr)
        throw std::logic_error("Knjiga nije zaduzena");
    mapa_knjiga[evid_br]->pok=nullptr;
}

void Biblioteka::PrikaziZaduzenja( int clanski_br) const{
    if(mapa_korisnika.find(clanski_br)==mapa_korisnika.end())
        throw std::logic_error("Korisnik nije nadjen");
    bool zaduzenje(false);
    for(auto& knjiga : mapa_knjiga){
        if(&*mapa_korisnika.at(clanski_br)==knjiga.second->pok){
            zaduzenje=true;
            std::cout<<"Evidencijski broj: "<< knjiga.first<<std::endl
            <<"Naslov: "<< knjiga.second->naslov<<std::endl
            <<"Pisac: "<<knjiga.second->ime_pisca<<std::endl
            <<"Zanr: "<<knjiga.second->zanr<<std::endl
            <<"Godina izdavanja: "<<knjiga.second->god_izdavanja<<std::endl<<std::endl;
        }
    }
    if(!zaduzenje)
        std::cout<<"Nema zaduzenja za tog korisnika!";
}

int main ()
{
	return 0;
}