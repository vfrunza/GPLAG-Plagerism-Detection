/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise

#include <iostream>
#include <string>
#include <stdexcept>
#include <map>
#include <memory>


struct Korisnik{
    std::string ime, prezime, adresa, telefon;
};

class Knjiga {
    std::string naslov, ime_pisca, zanr;
    int godina_izdavanja;
    Korisnik* korisnik;
    
public:

    Knjiga(std::string NASLOV, std::string IME, std::string ZANR, int GODINA) {
        Knjiga::naslov=NASLOV;
        Knjiga::ime_pisca=IME;
        Knjiga::zanr=ZANR;
        Knjiga::godina_izdavanja=GODINA;
    }
    
    
    std::string DajNaslov() const{ return naslov; }
    std::string DajAutora() const{ return ime_pisca; }
    std::string DajZanr() const{ return zanr; }
    int DajGodinuIzdavanja() const{ return godina_izdavanja; }
    Korisnik* DajKodKogaJe() const{ return korisnik; }
    
    void ZaduziKnjigu(Korisnik &referenca_na_korisnika){ korisnik=&referenca_na_korisnika; }
    void RazduziKnjigu(){ korisnik=nullptr; }
    
    bool DaLiJeZaduzena(){
        if(korisnik==nullptr) return false;
        return true;
    }
    friend class Biblioteka;
};

class Biblioteka{
    std::map<int, Korisnik*> mapa_korisnika;
    std::map<int, Knjiga*> mapa_knjiga;
public:
    void RegistrirajNovogKorisnika(int clanski_broj_korisnika, std::string ime_korisnika, std::string prezime_korisnika, std::string adresa_korisnika, std::string br_telefona){
        if(mapa_korisnika.count(clanski_broj_korisnika)) throw std::logic_error("Korisnik vec postoji");
        else{
            
                Korisnik pom;
                pom.ime=ime_korisnika;
                pom.prezime=prezime_korisnika;
                pom.telefon=br_telefona;
                pom.adresa=adresa_korisnika;
            
                auto *PomPok=new Korisnik(pom);
            try{
                mapa_korisnika.insert(std::make_pair(clanski_broj_korisnika, PomPok));
            }
            catch(...){
                delete PomPok;
                throw;
            }
        }
    }
    
    ~Biblioteka(){
        for(auto it=mapa_korisnika.begin(); it!=mapa_korisnika.end(); it++){
            delete it->second;
        }
        for(auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end(); it++){
            delete it->second;
        }       
    }
    
    
    void RegistrirajNovuKnjigu(int evidencijski_broj_knjige, std::string naslov_knjige, std::string ime_pisac_knjige, std::string zanr_knjige, int izdavanje){
        if(mapa_knjiga.count(evidencijski_broj_knjige)) throw std::logic_error("Knjiga vec postoji");
        else{
            auto *NewTempPtr=new Knjiga(naslov_knjige, ime_pisac_knjige, zanr_knjige, izdavanje);
            try{
                mapa_knjiga.insert(std::make_pair(evidencijski_broj_knjige, NewTempPtr));
            }
            catch(...){
                delete NewTempPtr;
                throw;
            }
        }
    }
    
   
    Korisnik &NadjiKorisnika(int clanski_broj_korisnika){
        if(!mapa_korisnika.count(clanski_broj_korisnika)) throw("Korisnik nije nadjen");
        else{
             return *(mapa_korisnika.find(clanski_broj_korisnika)->second);
        }
    }
    
    Knjiga &NadjiKnjigu(int evidencijski_br){
        if(!mapa_knjiga.count(evidencijski_br)) throw("Knjiga nije nadjen");
        else{
            return *(mapa_knjiga.find(evidencijski_br)->second);
        }       
    }
    
    void IzlistajKorisnike(){
        for(auto it=mapa_korisnika.begin(); it!=mapa_korisnika.end(); it++){
            std::cout<<"Clanski broj: "<<it->first<<std::endl;
            Korisnik* temp(it->second);
            std::cout<<"Ime i prezime: "<<temp->ime<<" "<<temp->prezime<<std::endl;
            std::cout<<"Adresa: "<<temp->adresa<<std::endl;
            std::cout<<"Broj telefona: "<<temp->telefon;
            std::cout<<std::endl;
        }
        std::cout<<std::endl;
    }
    
    void IzlistajKnjige(){
        for(auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end(); it++){
            std::cout<<"Evidencijski broj: "<<it->first<<std::endl;
            Knjiga* temp(it->second);
            std::cout<<"Naslov: "<<temp->naslov<<std::endl;
            std::cout<<"Pisac: "<<temp->ime_pisca<<std::endl;
            std::cout<<"Zanr: "<<temp->zanr<<std::endl;
            std::cout<<"Godina izdavanja: "<<temp->godina_izdavanja<<std::endl;
            if(temp->DaLiJeZaduzena()==true){
                auto varijabla(temp->korisnik);
                std::cout<<"Zaduzena kod korisnika: "<<varijabla->ime<<" "<<varijabla->prezime;
            }
        }
    }
    
    void ZaduziKnjigu(int evidencijski_broj_knjige, int clanski_broj_korisnika){
        if(!mapa_knjiga.count(evidencijski_broj_knjige)) throw("Knjiga nije nadjen");     
        if(!mapa_korisnika.count(clanski_broj_korisnika)) throw("Korisnik nije nadjen");
        auto PomPok(mapa_knjiga.find(evidencijski_broj_knjige)->second);
        if(PomPok->korisnik!=nullptr) std::logic_error("Knjiga vec zaduzena");
        else{
            auto knjiga(mapa_knjiga.find(evidencijski_broj_knjige)->second);
            auto Kor(mapa_korisnika.find(clanski_broj_korisnika)->second);
            knjiga->ZaduziKnjigu(*Kor);
        }
    }
    
    void RazduziKnjigu(int evidencijski_broj_knjige){
        if(!mapa_knjiga.count(evidencijski_broj_knjige)) throw std::logic_error("Knjiga nije nadjena");
        else{
            auto Pomocna(mapa_knjiga.find(evidencijski_broj_knjige)->second);
            if(Pomocna->korisnik==nullptr) throw std::logic_error("Knjiga nije zaduzena");
            else{
                Pomocna->korisnik=nullptr;
            }
        }
    }
    
    void PrikaziZaduzenja(int clanski_broj_korisnika){                                                     
        if(!mapa_korisnika.count(clanski_broj_korisnika)) throw("Korisnik nije nadjen");
        else{
             for(auto it=mapa_knjiga.begin(); it!=mapa_knjiga.end(); it++){
                if((it->second)->korisnik== mapa_korisnika[clanski_broj_korisnika]){
                    std::cout<<"Evidencijski broj: "<<it->first<<std::endl;
                    Knjiga* temp(it->second);
                    std::cout<<"Naslov: "<<temp->naslov<<std::endl;
                    std::cout<<"Pisac: "<<temp->ime_pisca<<std::endl;
                    std::cout<<"Zanr: "<<temp->zanr<<std::endl;
                    std::cout<<"Godina izdavanja: "<<temp->godina_izdavanja<<std::endl;
                    if(temp->DaLiJeZaduzena()==true){
                       auto varijabla(temp->korisnik);
                        std::cout<<"Zaduzena kod korisnika: "<<varijabla->ime<<" "<<varijabla->prezime;
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