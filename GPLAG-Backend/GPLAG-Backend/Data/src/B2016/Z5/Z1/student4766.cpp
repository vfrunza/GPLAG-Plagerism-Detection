#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include <memory>

struct Korisnik{
  std::string ime,prezime,adresa,telefon;
};
class Knjiga{
  std::string naslov,imePisca,zanr;
  int god;
  Korisnik *k = nullptr;
  public:
    Knjiga(std::string naslov,std::string imePisca,std::string zanr, int god):
    naslov(naslov),imePisca(imePisca),zanr(zanr),god(god){ }
    std::string DajNaslov()const{ return naslov; }
    std::string DajAutora()const{ return imePisca; }
    std::string DajZanr()const{ return zanr; }
    int DajGodinuIzdavanja()const{ return god; }
    Korisnik *DajKodKogaJe()const{return k; }
    void ZaduziKnjigu( Korisnik &x){ k = &x; }
    void RazduziKnjigu(){ k = nullptr; }
    bool DaLiJeZaduzena(){ return k; }
};
class Biblioteka{
    std::map<int,Korisnik*> clanovi;
    std::map<int,Knjiga*> knjige;
    public:
        Biblioteka(){ }
        void RegistrirajNovogKorisnika(int br,std::string ime,std::string prezime,
            std::string adresa,std::string telefon);
        void RegistrirajNovuKnjigu(int br, std::string naslov, std::string imeP,
            std::string zanr, int god);
        ~Biblioteka(){
            for(auto &p:clanovi) delete p.second;
            for(auto &p:knjige) delete p.second;
        }
        Biblioteka &operator=(const Biblioteka &b);
        Biblioteka &operator=(Biblioteka &&b);
        Biblioteka (const Biblioteka &b){ *this = b; }
        Biblioteka(Biblioteka &&b) {*this = b; }
        Korisnik &NadjiKorisnika(int br)const;
        Knjiga &NadjiKnjigu(int br)const;
        void IzlistajKorisnike()const;
        void IzlistajKnjige()const;
        void ZaduziKnjigu(int evNum, int clNum);
        void RazduziKnjigu(int evNum);
        void PrikaziZaduzenja(int clNum)const;
};
Biblioteka &Biblioteka::operator=(Biblioteka &&b){
    for(auto &p:knjige) delete p.second; 
    for(auto &p:clanovi) delete p.second;
    knjige = std::move(b.knjige);
    clanovi = std::move(b.clanovi);
    return *this;
}
Biblioteka &Biblioteka::operator=(const Biblioteka &b){
    
    std::map<int,Knjiga*> knjigee;
    std::map<int,Korisnik*> clanovii;
    try{
        for(auto &p:b.knjige)
            knjigee[p.first] = new Knjiga(p.second->DajNaslov(),p.second->DajAutora(),
            p.second->DajZanr(),p.second->DajGodinuIzdavanja());
        for(auto &p:b.clanovi){
            clanovii[p.first] = new Korisnik;
            clanovii[p.first] ->ime = p.second->ime;
            clanovii[p.first]-> prezime = p.second->prezime;
            clanovii[p.first]->adresa = p.second->adresa;
            clanovii[p.first]->telefon = p.second->telefon;
        }
        for(auto &p:clanovi) delete p.second;
        for(auto &p:knjige) delete p.second;
        knjige = std::move(knjigee);
        clanovi = std::move(clanovii);
    }catch(...){
        for(auto &p:clanovii) delete p.second;
        for(auto &p:knjigee) delete p.second;
        throw;
    }
    return *this;
}
void Biblioteka::PrikaziZaduzenja(int clNum)const{
    try{
        Korisnik &k(NadjiKorisnika(clNum)); int num(0);
        for(auto &p:knjige){
            if(p.second->DajKodKogaJe() == &k){
                std::cout << "\nEvidencijksi broj: " << p.first << std::endl <<
                "Naslov: " << p.second->DajNaslov() << "\nPisac: " << p.second->DajAutora()
                << "\nZanr: " << p.second->DajZanr() << "\nGodina izdavanja: " <<
                p.second->DajGodinuIzdavanja() << std::endl;
                num++;
            }
        }
        if(!num) std::cout << "Nema zaduzenja za tog korisnika!" << std::endl; 
    }catch(std::logic_error err){
        std::cout << err.what() << std::endl;
    }
}
void Biblioteka::ZaduziKnjigu(int evNum, int clNum){
    try{
        auto &book(NadjiKnjigu(evNum)); auto &k(NadjiKorisnika(clNum));
        if(book.DaLiJeZaduzena()) throw std::logic_error("Knjiga vec zaduzena");
        book.ZaduziKnjigu(k);
    }catch(std::logic_error err){
        std::cout << err.what()<<std::endl;
    }
}
void Biblioteka::RazduziKnjigu(int evNum){
    try{
        auto book(NadjiKnjigu(evNum));
        if(!book.DaLiJeZaduzena()) throw std::logic_error("Knjiga nije zaduzena");
        book.RazduziKnjigu();
    }catch(std::logic_error err){
        std::cout << err.what() << std::endl;
    }
}
void Biblioteka::IzlistajKorisnike()const{
    for(auto &p:clanovi){
        std::cout << "Clanski broj: " << p.first << "\nIme i prezime: " <<
        p.second->ime << " " << p.second->prezime << "\nAdresa: " << p.second->adresa
        << "\nBroj telefona: " << p.second->telefon << std::endl;
    }
}
void Biblioteka::IzlistajKnjige()const{
    for(auto &p:knjige){
        std::cout << "\nEvidencijski broj: " << p.first << "\nNaslov: " <<
        p.second->DajNaslov() << "\nPisac: " << p.second->DajAutora() << 
        "\nZanr: " << p.second->DajZanr() << "\nGodina izdavanja: " <<
        p.second->DajGodinuIzdavanja() << std::endl;
        if(p.second->DaLiJeZaduzena())
            std::cout << "Zaduzena kod korisnika: " <<
            p.second->DajKodKogaJe()->ime<<" "<<p.second->DajKodKogaJe()->prezime<<"\n";
    }
}
Korisnik &Biblioteka::NadjiKorisnika(int br)const{
    if(clanovi.find(br) == clanovi.end()) throw std::logic_error("Korisnik nije nadjen");
    return *(clanovi.find(br)->second);
}
Knjiga &Biblioteka::NadjiKnjigu(int br)const{
    auto p(knjige.find(br));
    if(p == knjige.end()) throw std::logic_error("Knjiga nije nadjena");
    return *(p->second);
}
void Biblioteka::RegistrirajNovuKnjigu(int br, std::string naslov, std::string imeP,
    std::string zanr, int god){
    if(knjige.find(br) != knjige.end()) throw std::logic_error("Knjiga vec postoji");
    knjige[br] = new Knjiga(naslov,imeP,zanr,god);
}
void Biblioteka::RegistrirajNovogKorisnika(int br,std::string ime,std::string prezime,
    std::string adresa,std::string telefon){
    if(clanovi.find(br)!= clanovi.end()) throw std::logic_error("Korisnik vec postoji");
    clanovi[br] = new Korisnik;
    clanovi[br]->ime = ime; clanovi[br]->prezime = prezime;
    clanovi[br]->adresa = adresa; clanovi[br]->telefon = telefon;
}
Biblioteka vrati(){
    Biblioteka z;
    return z;
}
int main () {
    Korisnik k;
    k.ime = "a"; k.prezime = "b"; k.adresa = "c"; k.telefon = "nemam";
    
    Knjiga b("a","b","c",10);
    std::cout << b.DajAutora() << b.DajNaslov() << b.DajZanr() <<
    b.DajGodinuIzdavanja() << b.DajKodKogaJe();
    b.ZaduziKnjigu(k);
    b.RazduziKnjigu();
    if(b.DaLiJeZaduzena()) std::cout <<std::endl << "jest";
    
    Biblioteka l;
    l.RegistrirajNovogKorisnika(1,"ime","prezime","adrsa","tel");
    l.RegistrirajNovuKnjigu(2,"naslo","imeP","zanr", 100);
    auto x = l;
    l = x;
    x = vrati();
    Biblioteka zzz(vrati());
    Biblioteka kkkkk(x);
    auto korisnik = l.NadjiKorisnika(1);
    auto knjizurina = l.NadjiKnjigu(2);
    l.IzlistajKorisnike();
    l.IzlistajKnjige();
    l.ZaduziKnjigu(2,1);
    l.RazduziKnjigu(2);
    l.PrikaziZaduzenja(1);
	return 0;
}