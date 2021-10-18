/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include <memory>
struct Korisnik{
    std::string ime,prezime,adresa,telefon;
    Korisnik(std::string i, std::string p, std::string a, std::string t) : ime(i), prezime(p), adresa(a), telefon(t) {}
    Korisnik(const Korisnik& k) {
        ime = k.ime; prezime = k.prezime; adresa = k.adresa; telefon = k.telefon;
    }
};
class Knjiga{ 
    std::string naslov,imepisca,zanr;
    int godina;
    Korisnik* zaduzena=nullptr;
    public:
    Knjiga (std::string n, std::string i,std::string z, int g): naslov(n),imepisca(i),zanr(z),godina(g),zaduzena(nullptr) {}
    Knjiga(const Knjiga& k) {
        naslov = k.naslov; imepisca = k.imepisca; zanr = k.zanr; godina = k.godina; zaduzena = k.zaduzena;
    }
    std::string DajNaslov()const{return naslov;}
    std::string DajAutora()const{return imepisca;}
    std::string DajZanr()const{return zanr;}
    int DajGodinuIzdavanja()const{return godina;}
    Korisnik* DajKodKogaJe()const{return zaduzena;}
    
    void RazduziKnjigu(){zaduzena=nullptr;}
    Korisnik* ZaduziKnjigu(Korisnik& zad){zaduzena = &zad; return zaduzena;}
    bool DaLiJeZaduzena(){if(zaduzena==nullptr)return false; return true;}
};
class Biblioteka{
    std::map<int, std::shared_ptr<Korisnik> > MapaKorisnika;
    std::map<int, std::shared_ptr<Knjiga> > MapaKnjiga;
    public:
    Biblioteka(){}
    Biblioteka &operator =(const Biblioteka &b){
        if(&b != this) {
        MapaKorisnika.clear();
        MapaKnjiga.clear();
        for(auto it(b.MapaKorisnika.begin()); it != b.MapaKorisnika.end(); it++) {
            MapaKorisnika.insert(std::make_pair(it -> first, std::make_shared< Korisnik>(*(it -> second))));
        }
        for(auto it(b.MapaKnjiga.begin()); it != b.MapaKnjiga.end(); it++) {
            MapaKnjiga.insert(std::make_pair(it -> first, std::make_shared<Knjiga>(*(it -> second))));
        }
    }
        return *this;
    }
    Biblioteka(const Biblioteka& b) {
        for(auto it(b.MapaKorisnika.begin()); it != b.MapaKorisnika.end(); it++) {
            MapaKorisnika.insert(std::make_pair(it -> first, std::make_shared<Korisnik>( Korisnik(*(it -> second)))));
        }
        for(auto it(b.MapaKnjiga.begin()); it != b.MapaKnjiga.end(); it++) {
            MapaKnjiga.insert(std::make_pair(it -> first,std::make_shared<Knjiga> ( Knjiga(*(it -> second)))));
        }
    }
    const Knjiga& NadjiKnjigu(int evi)const{
        for(auto it(MapaKnjiga.begin()); it != MapaKnjiga.end(); it++) {
            if(it->first==evi)return *(it->second);
        }
        throw std::logic_error("Knjiga nije nadjena");
    }
    const Korisnik& NadjiKorisnika(int clbr)const{
        for(auto it(MapaKorisnika.begin()); it != MapaKorisnika.end(); it++) {
            if(it -> first == clbr)return *(it->second);
        }
        throw std::logic_error("Korisnik nije nadjen");
    }
    void RegistrirajNovogKorisnika(int br, std::string ime, std::string prezime, std::string adresa, std::string telefon) {
        try{
           Korisnik a=NadjiKorisnika(br);
           throw std::logic_error("Korisnik vec postoji");
        }catch(std::logic_error){
        MapaKorisnika.insert(std::make_pair(br,std::make_shared<Korisnik>( Korisnik(ime, prezime, adresa, telefon))));
        }
    }
    void RegistrirajNovuKnjigu(int br, std::string naslov, std::string ime_pisca, std::string zanr, int godina) {
        try{
            Knjiga b=NadjiKnjigu(br);
        }catch(std::logic_error){
        MapaKnjiga.insert(std::make_pair(br, std::make_shared<Knjiga>( Knjiga(naslov, ime_pisca, zanr, godina))));
    }
    }
    void IzlistajKorisnike() {
        for(auto it(MapaKorisnika.begin()); it != MapaKorisnika.end(); it++) {
            std::cout << "Clanski broj: " << it -> first << "\n";
            std::cout << "Ime i prezime: " << it -> second -> ime << " " << it -> second -> prezime << "\n";
            std::cout << "Adresa: " << it -> second -> adresa << "\n";
            std::cout << "Broj telefona: " << it -> second -> telefon << "\n\n";
        }
    }
    void IzlistajKnjige() {
        for(auto it(MapaKnjiga.begin()); it != MapaKnjiga.end(); it++) {
            std::cout << "Evidencijski broj: " << it -> first << "\n";
            std::cout << "Naslov: " << it -> second -> DajNaslov() << "\n";
            std::cout << "Pisac: " << it -> second -> DajAutora() << "\n";
            std::cout << "Zanr: " << it -> second -> DajZanr() << "\n";
            std::cout << "Godina izdavanja: " << it -> second -> DajGodinuIzdavanja() << "\n";
            if(it->second->DajKodKogaJe()!=nullptr)std::cout<<"Zaduzena kod korisnika: "<<it->second->DajKodKogaJe()->ime<<" "<<it->second->DajKodKogaJe()->prezime<<"\n\n";
            else std::cout<<std::endl;
        }
    }
    void ZaduziKnjigu(int br_knjige, int br_kor) {
        try{
           Knjiga b=NadjiKnjigu(br_knjige);
        }catch(const std::exception& e){
            throw std::logic_error(e.what());
        }
        try{
           Korisnik g=NadjiKorisnika(br_kor);
        }catch(const std::exception& e){
            throw std::logic_error(e.what());
        }
        auto it = MapaKnjiga.find(br_knjige);
        bool zad=(*(it->second)).DaLiJeZaduzena();
        if(zad==true)throw std::logic_error("Knjiga vec zaduzena");
        auto it1 = MapaKorisnika.find(br_kor);
        it -> second -> ZaduziKnjigu(*(it1 -> second));
    }
    void RazduziKnjigu(int evbr) {
        auto it = MapaKnjiga.find(evbr);
        try{
            Knjiga b=NadjiKnjigu(evbr);
        }catch(const std::exception& e){
            throw std::logic_error(e.what());
        }
        if((*(it->second)).DaLiJeZaduzena()==false)throw std::logic_error("Knjiga nije zaduzena");
        if(it != MapaKnjiga.end())(*(it->second)).RazduziKnjigu();
    }
   void PrikaziZaduzenja(int br_kor) {
        try{
            Korisnik a=NadjiKorisnika(br_kor);
        }catch(const std::exception& e){
            throw std::logic_error(e.what());
        }
        auto it1(MapaKorisnika.find(br_kor));
        if(it1==MapaKorisnika.end())std::cout<<"Nema zaduzenja za tog korisnika!";
        bool uso=false;
        for(auto it(MapaKnjiga.begin()); it != MapaKnjiga.end(); it++) {
            if(it -> second -> DaLiJeZaduzena() && &(*(it1 -> second)) == it -> second -> DajKodKogaJe()) {
            uso=true;
            std::cout << "Evidencijski broj: " << it -> first << "\n";
            std::cout << "Naslov: " << it -> second -> DajNaslov() << "\n";
            std::cout << "Pisac: " << it -> second -> DajAutora() << "\n";
            std::cout << "Zanr: " << it -> second -> DajZanr() << "\n";
            std::cout << "Godina izdavanja: " << it -> second -> DajGodinuIzdavanja() << "\n\n";
            }
        }
        if(uso==false)std::cout<<"Nema zaduzenja za tog korisnika!";
    } 
};
int main ()
{
  return 0;
}