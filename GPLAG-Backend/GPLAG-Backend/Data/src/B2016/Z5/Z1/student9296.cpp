/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <stdexcept>
struct Korisnik{
    std::string ime, prezime, adresa, telefon;
};
class Knjiga{
    std::string naslov, pisac, zanr;
    int gzad;
    Korisnik* zaduzen;
public:
    Knjiga(std::string naslov, std::string pisac, std::string zanr, int god):naslov(naslov),pisac(pisac),zanr(zanr),gzad(god),zaduzen(nullptr){}
    std::string DajNaslov()const{return naslov;}
    std::string DajAutora()const{return pisac;}
    std::string DajZanr()const{return zanr;}
    int DajGodinuIzdavanja()const{return gzad;}
    Korisnik* DajKodKogaJe()const{return zaduzen;}
    void ZaduziKnjigu(Korisnik &a){zaduzen=&a;}
    void RazduziKnjigu(){zaduzen=nullptr;}
    bool DaLiJeZaduzena()const{return zaduzen;}
};
class Biblioteka{
    std::map<int, Korisnik*> korisnici;
    std::map<int, Knjiga*> knjige;
public:
    Biblioteka()=default;
    Biblioteka(const Biblioteka &b);
    Biblioteka &operator =(const Biblioteka &b);
    Biblioteka &operator =(Biblioteka &&b);
    ~Biblioteka();
    void RegistrirajNovogKorisnika(int cl_broj, std::string ime, std::string prezime, std::string adresa, std::string tel);
    void RegistrirajNovuKnjigu(int ev, std::string naslov, std::string pisac, std::string zanr, int god);
    Korisnik &NadjiKorisnika(int clbr)const;
    Knjiga &NadjiKnjigu(int evbr)const;
    void IzlistajKorisnike()const;
    void IzlistajKnjige()const;
    void ZaduziKnjigu(int evbr, int clbr);
    void RazduziKnjigu(int evbr);
    void PrikaziZaduzenja(int clbr)const;
};

Biblioteka &Biblioteka::operator =(Biblioteka &&b){
    for(auto i=korisnici.begin(); i!=korisnici.end(); i++) delete i->second;
    for(auto i=knjige.begin(); i!=knjige.end(); i++) delete i->second;
    std::swap(korisnici, b.korisnici); std::swap(knjige, b.knjige);
    return *this;
}
Biblioteka::Biblioteka(const Biblioteka &b){
    for(auto i=b.korisnici.begin(); i!=b.korisnici.end(); i++) 
        korisnici.insert(std::make_pair(i->first, new Korisnik{i->second->ime, i->second->prezime,i->second->adresa,i->second->telefon}));
    for(auto i=b.knjige.begin(); i!=b.knjige.end(); i++)
        knjige.insert(std::make_pair(i->first, new Knjiga(i->second->DajNaslov(),i->second->DajAutora(),i->second->DajZanr(),i->second->DajGodinuIzdavanja())));
}
Biblioteka::~Biblioteka(){
    for(auto i=korisnici.begin(); i!=korisnici.end(); i++) delete i->second;
    for(auto i=knjige.begin(); i!=knjige.end(); i++) delete i->second;
}
void Biblioteka::RegistrirajNovogKorisnika(int cl_broj, std::string ime, std::string prezime, std::string adresa, std::string tel){
    if(korisnici.count(cl_broj)) throw std::logic_error("Korisnik vec postoji");
    korisnici[cl_broj]=new Korisnik{ime, prezime, adresa, tel};
}
void Biblioteka::RegistrirajNovuKnjigu(int ev, std::string naslov, std::string pisac, std::string zanr, int god){
    if(knjige.count(ev)) throw std::logic_error("Knjiga vec postoji");
    knjige[ev]=new Knjiga(naslov,pisac,zanr,god);
}
Korisnik& Biblioteka::NadjiKorisnika(int clbr)const{
    auto it(korisnici.find(clbr));
    if(it==korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
    return *(it->second);
}
Knjiga &Biblioteka::NadjiKnjigu(int evbr)const{
    auto it=knjige.find(evbr);
    if(it==knjige.end()) throw std::logic_error("Knjiga nije nadjena");
    return *(it->second);
}
void Biblioteka::IzlistajKorisnike()const{
    for(auto i=korisnici.begin(); i!=korisnici.end(); i++){
        std::cout<<"Clanski broj: "<<i->first<<std::endl;
        std::cout<<"Ime i prezime: "<<(i->second)->ime<<" "<<(i->second)->prezime<<std::endl;
        std::cout<<"Adresa: "<<(i->second)->adresa<<std::endl;
        std::cout<<"Broj telefona: "<<i->second->telefon<<std::endl<<std::endl;
    }
}
void Biblioteka::IzlistajKnjige()const{
    for(auto i=knjige.begin(); i!=knjige.end(); i++){
        std::cout<<"Evidencijski broj: "<<i->first<<std::endl;
        std::cout<<"Naslov: "<<i->second->DajNaslov()<<std::endl;
        std::cout<<"Pisac: "<<i->second->DajAutora()<<std::endl;
        std::cout<<"Zanr: "<<i->second->DajZanr()<<std::endl;
        std::cout<<"Godina izdavanja: "<<i->second->DajGodinuIzdavanja()<<std::endl;
        if(i->second->DaLiJeZaduzena()) 
            std::cout<<"Zaduzena kod korisnika: "<<i->second->DajKodKogaJe()->ime<<" "<<i->second->DajKodKogaJe()->prezime<<std::endl;
        std::cout<<std::endl;
    }
}
void Biblioteka::ZaduziKnjigu(int evbr, int clbr){
    NadjiKnjigu(evbr);
    NadjiKorisnika(clbr);
    if(knjige[evbr]->DaLiJeZaduzena()) throw std::logic_error("Knjiga vec zaduzena");
    knjige[evbr]->ZaduziKnjigu(*korisnici[clbr]);
}
void Biblioteka::RazduziKnjigu(int evbr){
    NadjiKnjigu(evbr);
    if(!(knjige[evbr]->DaLiJeZaduzena())) throw std::logic_error("Knjiga nije zaduzena");
    knjige[evbr]->RazduziKnjigu();
}
void Biblioteka::PrikaziZaduzenja(int clbr)const{
    Korisnik kor(NadjiKorisnika(clbr));
    auto i(knjige.begin());
    while(i!=knjige.end()){
        Korisnik *a(i->second->DajKodKogaJe());
        if(a->ime==kor.ime && a->prezime==kor.prezime && a->adresa == kor.adresa && a->telefon == kor.telefon){
            std::cout<<"Evidencijski broj: "<<i->first<<std::endl;
            std::cout<<"Naslov: "<<i->second->DajNaslov()<<std::endl;
            std::cout<<"Pisac: "<<i->second->DajAutora()<<std::endl;
            std::cout<<"Zanr: "<<i->second->DajZanr()<<std::endl;
            std::cout<<"Godina izdavanja: "<<i->second->DajGodinuIzdavanja()<<std::endl;
            std::cout<<std::endl;
        }
        i++;
    }
    if(i==knjige.end()) throw std::logic_error("Nema zaduzenja za tog korisnika!");
}
int main ()
{
	return 0;
}