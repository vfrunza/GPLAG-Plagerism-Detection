/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
struct Korisnik{
    std::string ime,prezime,adresa,telefon;
    friend class Biblioteka;
};
class Knjiga{
    std::string naslov,pisac,zanr;
    int godina;
    Korisnik*zaduzenje;
  public:
    Knjiga(std::string n,std::string i,std::string z,int g);
    std::string DajNaslov()const{return naslov;}
    std::string DajAutora()const{return pisac;}
    std::string DajZanr()const{return zanr;}
    int DajGodinuIzdavanja()const{return godina;}
    Korisnik* DajKodKogaJe()const{return zaduzenje;}
    void ZaduziKnjigu(Korisnik&k){zaduzenje=&k;}
    void RazduziKnjigu(){zaduzenje=nullptr;}
    bool DaLiJeZaduzena(){if(zaduzenje)return true; return false;}
};
Knjiga::Knjiga(std::string n,std::string i,std::string z,int g){
    zaduzenje=nullptr;
    naslov=n; pisac=i; zanr=z; godina=g;
}

class Biblioteka{
    std::map<int,Korisnik*> korisnici;
    std::map<int,Knjiga*> knjige;
  public:
    Biblioteka(){}
    ~Biblioteka();
    Biblioteka(const Biblioteka&b);
    //Biblioteka(const Biblioteka&&b){std::swap(korisnici,b.korisnici);std::swap(knjige,b.knjige);}
    void RegistrirajNovogKorisnika(int clanski,std::string i,std::string p,std::string a,std::string brt);
    void RegistrirajNovuKnjigu(int evid,std::string n,std::string i,std::string z,int g);
    Korisnik& NadjiKorisnika(int clanski)const;
    Knjiga& NadjiKnjigu(int evid)const;
    void IzlistajKorisnike();
    void IzlistajKnjige();
    void ZaduziKnjigu(int evid,int clanski);
    void RazduziKnjigu(int evid);
    void PrikaziZaduzenja(int clanski);
};
Biblioteka::~Biblioteka(){
    auto pok1(korisnici.begin());
    while(pok1!=korisnici.end()){delete(pok1->second);pok1++;}
    auto pok2(knjige.begin());
    while(pok2!=knjige.end()){delete (pok2->second);pok2++;}
}
Biblioteka::Biblioteka(const Biblioteka&b){
    auto pok1=b.korisnici.begin();
    while(pok1!=b.korisnici.end()){
        korisnici.insert(std::make_pair(pok1->first,new Korisnik(*(pok1->second))));
        pok1++;
    }
    auto pok2=b.knjige.begin();
    while(pok2!=b.knjige.end()){
        knjige.insert(std::make_pair(pok2->first,new Knjiga(*(pok2->second))));
        pok2++;
    }
}
void Biblioteka::RegistrirajNovogKorisnika(int clanski,std::string i,std::string p,std::string a,std::string brt){
    if(korisnici.find(clanski)!=korisnici.end())throw std::logic_error("Korisnik vec postoji");
    Korisnik*pok=new Korisnik;
    pok->ime=i; pok->prezime=p; pok->adresa=a; pok->telefon=brt;
    korisnici.insert(std::make_pair(clanski,pok));
}
void Biblioteka::RegistrirajNovuKnjigu(int evid,std::string n,std::string i,std::string z,int g){
    if(knjige.find(evid)!=knjige.end())throw std::logic_error("Korisnik vec postoji");
    Knjiga*pok=new Knjiga(n,i,z,g);
    knjige.insert(std::make_pair(evid,pok));
}
Korisnik& Biblioteka::NadjiKorisnika(int clanski)const{
    auto pok=korisnici.find(clanski);
    if(pok==korisnici.end())throw std::logic_error("Korisnik nije nadjen");
    return *(pok->second);
}
Knjiga& Biblioteka::NadjiKnjigu(int evid)const{
    auto pok=knjige.find(evid);
    if(pok==knjige.end()) throw std::logic_error("Knjiga nije nadjena");
    return *(pok->second);
}
void Biblioteka::IzlistajKorisnike(){
    auto pok(korisnici.begin());
    while(pok!=korisnici.end()){
        std::cout<<"Clanski broj: "<<pok->first<<std::endl;
        std::cout<<"Ime i prezime: "<<(pok->second)->ime<<" "<<(pok->second)->prezime<<std::endl;
        std::cout<<"Adresa: "<<(pok->second)->adresa<<std::endl;
        std::cout<<"Broj telefona: "<<(pok->second)->telefon<<std::endl;
        pok++;
    }
}
void Biblioteka::IzlistajKnjige(){
    auto pok(knjige.begin());
    while(pok!=knjige.end()){
        std::cout<<"Evidencijski broj: "<<pok->first<<std::endl;
        std::cout<<"Naslov: "<<(pok->second)->DajNaslov()<<std::endl;
        std::cout<<"Pisac: "<<(pok->second)->DajAutora()<<std::endl;
        std::cout<<"Zanr: "<<(pok->second)->DajZanr()<<std::endl;
        std::cout<<"Godina izdavanja: "<<(pok->second)->DajGodinuIzdavanja()<<std::endl;
        if((pok->second)->DaLiJeZaduzena()){
            std::cout<<"Zaduzena kod korisnika: "<<(pok->second)->DajKodKogaJe()->ime<<" "<<(pok->second)->DajKodKogaJe()->prezime<<std::endl;
        }
        pok++;
    }
}
void Biblioteka::ZaduziKnjigu(int evid,int clanski){
    auto pok1(korisnici.find(clanski));
    auto pok2(knjige.find(evid));
    if(pok2==knjige.end())throw std::logic_error("Knjiga nije nadjena");
    if(pok1==korisnici.end())throw std::logic_error("Korisnik nije nadjen");
    if((pok2->second)->DaLiJeZaduzena())throw std::logic_error("Knjiga vec zaduzena");
    (pok2->second)->ZaduziKnjigu(*(pok1->second));
}
void Biblioteka::RazduziKnjigu(int evid){
    auto pok(knjige.find(evid));
    if(pok==knjige.end())throw std::logic_error("Knjiga nije nadjena");
    if((pok->second)->DaLiJeZaduzena()==0)throw std::logic_error("Knjiga nije zaduzena");
    (pok->second)->RazduziKnjigu();
}
void Biblioteka::PrikaziZaduzenja(int clanski){
    auto pok(korisnici.find(clanski));
    if(pok==korisnici.end())throw std::logic_error("Korisnik nije nadjen");
    auto p(knjige.begin());
    bool zaduzio(true);
    while(p!=knjige.end()){
        if((p->second)->DajKodKogaJe()==pok->second){
            zaduzio=false;
            std::cout<<"Evidencijski broj: "<<p->first<<std::endl;
            std::cout<<"Naslov: "<<(p->second)->DajNaslov()<<std::endl;
            std::cout<<"Pisac: "<<(p->second)->DajAutora()<<std::endl;
            std::cout<<"Zanr: "<<(p->second)->DajZanr()<<std::endl;
            std::cout<<"Godina izdavanja: "<<(p->second)->DajGodinuIzdavanja()<<std::endl;
        }
        p++;
    }
    if(zaduzio)std::cout<<"Nema zaduzenja za tog korisnika!";
}

int main (){
    Biblioteka b;
    b.RegistrirajNovogKorisnika(1234, "Petar", "Petrovic","Zmaja od Bosne 30", "032/444-555");
    b.RegistrirajNovuKnjigu(231, "Prokleta avlija", "Ivo Andric", "Roman", 1967);
    b.RegistrirajNovuKnjigu(222,"Knjiga","Pisac","Roman",1998);
    b.ZaduziKnjigu(231,1234);
    b.ZaduziKnjigu(222,1234);
    Biblioteka a(b);
    //Biblioteka c(std::move(a));
    //b.PrikaziZaduzenja(1234);
    //b.IzlistajKorisnike();
    a.IzlistajKnjige();
	return 0;
}