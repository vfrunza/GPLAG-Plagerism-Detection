/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <stdexcept>

struct Korisnik {
    std::string ime, prezime, adresa, telefon;
};
class Knjiga {
   std::string naslov, ime_pisca, zanr;
   int god_izdavanja;
   Korisnik *pok;
public:
    Knjiga(std::string naslov_knjige, std::string pisac, std::string tip, int god) : naslov(naslov_knjige), 
    ime_pisca(pisac), zanr(tip), god_izdavanja(god), pok(nullptr) {}
    std::string DajNaslov() { return naslov; }
    std::string DajAutora() { return ime_pisca; }
    std::string DajZanr() { return zanr; }
    int DajGodinuIzdavanja() { return god_izdavanja; }
    Korisnik *DajKodKogaJe() { return pok; }
    void ZaduziKnjigu(Korisnik &osoba){  pok = &osoba;}
    void RazduziKnjigu() { pok = nullptr; }
    bool DaLiJeZaduzena() {
        if(pok == nullptr) return false;
        return true;
    }
};
class Biblioteka {
    std::map<int, Korisnik*> korisnici;
    std::map<int, Knjiga*> knjige;
public:
    Biblioteka(std::map<int,Korisnik*> members, std::map<int,Knjiga*> books) : korisnici(members), knjige(books) {}
    Biblioteka () {}
    ~Biblioteka();
    Biblioteka(const Biblioteka &bib);
    Biblioteka &operator=(const Biblioteka &bib);
    Biblioteka(Biblioteka &&bib);
    Biblioteka &operator=(Biblioteka &&bib);
    void RegistrirajNovogKorisnika(int clanski_broj, std::string name, std::string surname, std::string adress, std::string mob){
        auto it(korisnici.find(clanski_broj));
        if(it != korisnici.end()) throw std::logic_error("Korisnik vec postoji"); 
        Korisnik *novi_korisnik(new Korisnik);
        novi_korisnik->ime = name;
        novi_korisnik->prezime = surname;
        novi_korisnik->adresa = adress;
        novi_korisnik->telefon = mob;
        korisnici.insert(std::make_pair(clanski_broj,novi_korisnik));
        
    }
    void RegistrirajNovuKnjigu(int broj_knjige, std::string name, std::string autor, std::string type, int god){
        auto it(knjige.find(broj_knjige));
        if(it != knjige.end()) throw std::logic_error("Knjiga vec postoji");
        Knjiga *nova_knjiga(new Knjiga(name,autor,type,god));
        knjige.insert(std::make_pair(broj_knjige,nova_knjiga));
    }
    Korisnik &NadjiKorisnika(int clanski_broj){
        auto it(korisnici.find(clanski_broj));
        if(it == korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
        return *(it->second);
    }
    Knjiga &NadjiKnjigu(int broj){
        auto it(knjige.find(broj));
        if(it == knjige.end()) throw std::logic_error("Knjiga nije nadjena");
        return *(it->second);
    }
    void IzlistajKorisnike(){
        auto it(korisnici.begin());
        while(it!=korisnici.end()){
            std::cout<<"Clanski broj: "<<it->first<<std::endl;
            std::cout<<"Ime i prezime: "<<it->second->ime<<" "<<it->second->prezime<<std::endl;
            std::cout<<"Adresa: "<<it->second->adresa<<std::endl;
            std::cout<<"Broj telefona: "<<it->second->telefon<<std::endl;
            std::cout<<std::endl;
            it++;
        }
    }
    void IzlistajKnjige(){
        auto it(knjige.begin());
        while(it!=knjige.end()){
            std::cout<<"Evidencijski broj: "<<it->first<<std::endl;
            std::cout<<"Naslov: "<<it->second->DajNaslov()<<std::endl;
            std::cout<<"Pisac: "<<it->second->DajAutora()<<std::endl;
            std::cout<<"Zanr: "<<it->second->DajZanr()<<std::endl;
            std::cout<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<std::endl;
            if(it->second->DaLiJeZaduzena()) std::cout<<"Zaduzena kod korisnika: "
            <<it->second->DajKodKogaJe()->ime<<" "<<it->second->DajKodKogaJe()->prezime;
            std::cout<<std::endl;
            it++;
        }
    }
    void ZaduziKnjigu(int broj_knjige, int clanski_broj){
        auto itt(knjige.find(broj_knjige));
        if(itt->second->DaLiJeZaduzena()) throw std::logic_error("Knjiga je vec zaduzena");
        else if(itt == knjige.end()) throw std::logic_error("Knjiga nije nadjena");
        auto it(korisnici.find(clanski_broj));
        if(it == korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
        NadjiKnjigu(broj_knjige).Knjiga::ZaduziKnjigu(NadjiKorisnika(clanski_broj));
        
    }
    void RazduziKnjigu(int broj_knjige){
        auto it(knjige.find(broj_knjige));
        if(it == knjige.end()) throw std::logic_error("Knjiga nije nadjena");
        if(!(it->second->DaLiJeZaduzena())) throw std::logic_error("Knjiga nije zaduzena");
        NadjiKnjigu(broj_knjige).Knjiga::RazduziKnjigu();
    }
    void PrikaziZaduzenja(int clanski_broj){
        auto pom(korisnici.find(clanski_broj));
        if(pom == korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
        else{
        auto itt(korisnici.begin());
        while(itt!=korisnici.end()){
            if(itt->first == clanski_broj) break;
            itt++;
        }
        int br(0);
        auto it(knjige.begin());
        while(it!=knjige.end()){
            if(it->second->DaLiJeZaduzena()){
                if(it->second->DajKodKogaJe()==itt->second){
                    std::cout<<"Evidencijski broj: "<<it->first<<std::endl;
                    std::cout<<"Naslov: "<<it->second->DajNaslov()<<std::endl;
                    std::cout<<"Pisac: "<<it->second->DajAutora()<<std::endl;
                    std::cout<<"Zanr: "<<it->second->DajZanr()<<std::endl;
                    std::cout<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<std::endl;
                }
            }
                else br++;
            it++;
        }
            //if(br ==  std::cout<<"Nema zaduzenja za tog korisnika!";
    }
}
};
Biblioteka::~Biblioteka() {
    auto it(korisnici.begin());
        while(it!=korisnici.end()){
            delete it->second;
            it++;
        }
    auto it2(knjige.begin());
        while(it2!=knjige.end()){
            delete it2->second;
            it2++;
   }
}
Biblioteka::Biblioteka(const Biblioteka &bib){
    auto it(bib.korisnici.begin());
    auto it2(bib.knjige.begin());
    while(it!=bib.korisnici.end()){
        korisnici.insert(std::make_pair(it->first, new Korisnik(*(it->second))));
        it++;
    }
    while(it2!=knjige.end()){
        knjige.insert(std::make_pair(it2->first, new Knjiga(*(it2->second))));
        it2++;
    }
}
Biblioteka &Biblioteka::operator=(const Biblioteka &bib){
    if(this==&bib) return *this;
    auto it(korisnici.begin());
    auto it2(knjige.begin());
    while(it!=korisnici.end()){
        delete it->second;
        it++;
        
    }
    while(it2!=knjige.end()){
        delete it2->second;
        it2++;
    }
    auto novi(bib.korisnici.begin());
    auto novi2(bib.knjige.begin());
    while(novi!=bib.korisnici.end()){
        korisnici.insert(std::make_pair(novi->first, new Korisnik(*(novi->second))));
        novi++;
    }
    while(novi2!=knjige.end()){
        knjige.insert(std::make_pair(novi2->first, new Knjiga(*(novi2->second))));
        novi2++;
    }
        return *this;
}

Biblioteka::Biblioteka(Biblioteka &&bib){
    korisnici = bib.korisnici;
    knjige = bib.knjige;
    auto it (bib.korisnici.begin());
    while(it!=bib.korisnici.end()){
        it->second = nullptr;
        it++;
    }
    auto it2(bib.knjige.begin());
    while(it2!=bib.knjige.end()){
        it2->second = nullptr;
        it2++;
    }
}
    
Biblioteka &Biblioteka::operator=(Biblioteka &&bib){
    auto it(korisnici.begin());
        while(it!=korisnici.end()){
            delete it->second;
            it++;
        }
    auto it2(knjige.begin());
        while(it2!=knjige.end()){
            delete it2->second;
            it2++;
   }
    korisnici = bib.korisnici;
    knjige = bib.knjige;
    auto itt (bib.korisnici.begin());
    while(itt!=bib.korisnici.end()){
        itt->second = nullptr;
        itt++;
    }
    auto itt2(bib.knjige.begin());
    while(itt2!=bib.knjige.end()){
        itt2->second = nullptr;
        itt2++;
    }
        return *this;
}
 

int main ()
{
	return 0;
}