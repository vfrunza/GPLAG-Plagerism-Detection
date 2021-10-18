#include <iostream>
#include <memory>
#include <string>
#include <iterator>
#include <algorithm>
#include <map>
#include <stdexcept>

struct Korisnik {
    std::string ime, prezime, adresa, telefon;
};

class Knjiga
{  friend class Biblioteka; 
    std::string naslov, pisac,zanr;
    int g_izdavanja;
    std::shared_ptr<Korisnik>zaduzeni;

public:

    Knjiga(std::string n,std::string p,std::string z,int br):naslov(n),pisac(p),zanr(z),g_izdavanja(br),zaduzeni(nullptr) {}
    std::string DajNaslov() const{
        return naslov;
    }
    std::string DajAutora() const{
        return pisac;
    }
    std::string DajZanr() const{
        return zanr;
    }
    int  DajGodinuIzdavanja() const{
        return g_izdavanja;
    }
    
    std::shared_ptr<Korisnik>DajKodKogaJe() const{
        return zaduzeni;
    }
     void ZaduziKnjigu(Korisnik &zaduzuje) {
        zaduzeni=std::make_shared<Korisnik>(zaduzuje);
    }
    void RazduziKnjigu() {
        zaduzeni=nullptr;
    }
    bool DaLiJeZaduzena() const{
        bool x(false);
        if(zaduzeni!=nullptr) x=true;
        return x;
    }
};

class Biblioteka
{
    std::map<int,std::shared_ptr<Korisnik> > KORISNICI;
    std::map<int,std::shared_ptr<Knjiga> >KNJIGE;
public:

/*void RegistrirajNovogKorisnika(int clanski_br, std::string ime,std::string prezime, std::string adresa, std::string telefon);
void RegistrirajNovuKnjigu(int evidencijski,std::string naslov,std::string pisac,std::string zanr,int g_izdavanja);
    std::map<int,Korisnik *> &NadjiKorisnika(int clanski_br);
    std::map<int,Knjiga *> &NadjiKnjigu(int eviden_br);
    void IzlistajKorisnike();
    void IzlistajKnjige();
    void ZaduziKnjigu(int eviden_br,int clanski_br);
    void RazduziKnjigu(int eviden_br);
    void PrikaziZaduzenja(int clanski_br);
*/

Biblioteka &operator=(Biblioteka &k){
    if(this!=&k){
        for(auto it(KORISNICI.begin());it!=KORISNICI.end();it++){
           std::map<int,std::shared_ptr<Korisnik>>::iterator i;
        i=KORISNICI.find(it->first);
        KORISNICI.erase(i);
     }
     
     for(auto it(KNJIGE.begin());it!=KNJIGE.end();it++){
 std::map<int,std::shared_ptr<Knjiga>>::iterator i;
        i=KNJIGE.find(it->first);
        KNJIGE.erase(i);
    }
    
    std::shared_ptr<Korisnik>pok(nullptr);
     for(auto it(k.KORISNICI.begin());it!=k.KORISNICI.end();it++){
            pok=std::make_shared<Korisnik>();
            pok->ime=it->second->ime;   
            pok->prezime=it->second->prezime;
            pok->adresa=it->second->adresa;
            pok->telefon=it->second->telefon;
        }
        std::shared_ptr<Knjiga>p(nullptr);
        for(auto it(k.KNJIGE.begin());it!=k.KNJIGE.end();it++){
            p=std::make_shared<Knjiga>(it->second->naslov,it->second->pisac,it->second->zanr,it->second->g_izdavanja);
            p->naslov=it->second->naslov;
            p->pisac=it->second->pisac;
            p->zanr=it->second->zanr;
            p->g_izdavanja=it->second->g_izdavanja;
        }
        
}
    return *this;
}

Biblioteka(){}
    
void RegistrirajNovogKorisnika(int clanski_br, std::string ime,std::string prezime, std::string adresa, std::string telefon) {
        try {
            if(KORISNICI.count(clanski_br)!=0) throw std::logic_error("Korisnik vec postoji");
            std::shared_ptr<Korisnik>X(nullptr);
            X=std::make_shared<Korisnik>();
            X->ime=ime;
            X->prezime=prezime;
            X->adresa=adresa;
            X->telefon=telefon;
            
                KORISNICI.insert(std::make_pair(clanski_br,X));
} 
catch(std::logic_error &e) {
            throw;
        }
    }
    
void RegistrirajNovuKnjigu(int evidencijski,std::string naslov,std::string pisac,std::string zanr,int g_izdavanja) {
        try {
            if(KNJIGE.count(evidencijski)!=0) throw std::logic_error("Knjiga vec postoji");
            std::shared_ptr<Knjiga>X(nullptr);
            X=std::make_shared<Knjiga>(naslov,pisac,zanr,g_izdavanja);
            KNJIGE.insert(std::make_pair(evidencijski,X));
        } catch(std::logic_error &e) {
            throw;
        }
    }
    Korisnik &NadjiKorisnika(int clanski_br) {
        auto it(KORISNICI.begin());
           while(it!=KORISNICI.end()) {
               if(it->first==clanski_br)  return *(it->second);
               it++;
           }
           throw std::logic_error("Korisnik nije nadjen");
    }
    
    Knjiga &NadjiKnjigu(int eviden_br) {
        auto it(KNJIGE.begin());
           while(it!=KNJIGE.end()) {
               if(it->first==eviden_br) return *(it->second);
               it++;
           }
           throw std::logic_error("Knjiga nije nadjena");
    }
    
    void IzlistajKorisnike() {
        for(auto it(KORISNICI.begin()); it!=KORISNICI.end(); it++) {
            std::cout<<"Clanski broj: "<<it->first<<std::endl
            <<"Ime i prezime: "<<it->second->ime<<" "<<it->second->prezime<<std::endl
            <<"Adresa: "<<it->second->adresa<<std::endl<<"Broj telefona: "<<it->second->telefon<<std::endl;
            std::cout<<std::endl;
        }
    }
    void IzlistajKnjige() {
        for(auto it(KNJIGE.begin()); it!=KNJIGE.end(); it++){
std::cout<<"Evidencijski broj: "<<it->first<<std::endl
            <<"Naslov: "<<it->second->naslov<<std::endl
            <<"Pisac: "<<it->second->pisac<<std::endl<<"Zanr: "<<it->second->zanr<<std::endl
            <<"Godina izdavanja: "<<it->second->g_izdavanja<<std::endl;
         
            std::cout<<std::endl;
        }
        
    }
    
    void ZaduziKnjigu(int eviden_br,int clanski_br) {
        bool provjera(false);
     for(auto ti(KORISNICI.begin());ti!=KORISNICI.end();ti++){
        for(auto it(KNJIGE.begin()); it!=KNJIGE.end(); it++){
        if(it->first==eviden_br) it->second->zaduzeni=ti->second; break;
          if(ti->first==clanski_br) provjera=true;
         if(it==KNJIGE.end())throw std::logic_error("Knjiga nije nadjena.");
        if(it->second->DaLiJeZaduzena()) throw std::logic_error("Knjiga vec zaduzena");
             }
        }
    if(provjera) throw std::logic_error("Korisnik nije nadjen");
        
    }
    void RazduziKnjigu(int eviden_br) {
        for(auto it(KNJIGE.begin()); it!=KNJIGE.end(); it++){
            if(it->first==eviden_br) it->second->zaduzeni=nullptr; break; 
                 if(it==KNJIGE.end()) throw std::logic_error("Knjiga nije nadjena.");
             if(!(it->second->DaLiJeZaduzena())) throw std::logic_error("Knjiga nije zaduzena");
        }
    }
    
    void PrikaziZaduzenja(int clanski_br){
         bool provjera(false); int brojac(0);
    for(auto ti(KORISNICI.begin());ti!=KORISNICI.end();ti++){
        for(auto it(KNJIGE.begin()); it!=KNJIGE.end(); it++){
                     if(ti->first==clanski_br) provjera=true;
          if(it->second->zaduzeni==ti->second){
std::cout<<"Evidencijski broj: <"<<it->first<<">"<<std::endl
            <<"Naslov: <"<<it->second->naslov<<">"<<std::endl
            <<"Pisac: <"<<it->second->pisac<<">"<<std::endl<<"Zanr: <"<<it->second->zanr<<">"<<std::endl
            <<"Godina izdavanja: <"<<it->second->g_izdavanja<<">"<<std::endl;
            std::cout<<std::endl;
        }
    brojac++;
        if(brojac==0) throw std::logic_error("Nema zaduzenja za tog korisnika.");
        }
    }
    if(provjera) throw std::logic_error("Korisnik nije nadjen");
        
}
   /* ~Biblioteka(){
    for(auto it(KORISNICI.begin());it!=KORISNICI.end();it++){
         delete it->second;
     }
     for(auto it(KNJIGE.begin());it!=KNJIGE.end();it++){
     delete it->second;
        }
    }

void RegistrirajNovogKorisnika(int clanski_br, std::string ime,std::string prezime, std::string adresa, std::string telefon);
void RegistrirajNovuKnjigu(int evidencijski,std::string naslov,std::string pisac,std::string zanr,int g_izdavanja);
    std::map<int,Korisnik *> &NadjiKorisnika(int clanski_br);
    std::map<int,Knjiga *> &NadjiKnjigu(int eviden_br);
    void IzlistajKorisnike();
    void IzlistajKnjige();
    void ZaduziKnjigu(int eviden_br,int clanski_br);
    void RazduziKnjigu(int eviden_br);
    void PrikaziZaduzenja(int clanski_br);
*/

};

int main ()
{int x; bool y(true); Biblioteka B;
    std::cout<<"Unesite zeljeni broj od 0 do 7(0 znacava kraj usluge): ";
    std::cin>>x;
    try {
        while(x!=0){
        switch(x){
        case 0:     
            y=false; break;
        case 1:
        int clanski_br; std::string ime, prezime,adresa,telefon;
           std::cout<<"Unesi clanski broj korisnika biblioteke, qume: "; std::cin>>clanski_br;
           std::cout<<"Unesi ime korisnika biblioteke, qume: "; std::cin>>ime;
           std::cout<<"Unesi prezime korisnika biblioteke, qume: "; std::cin>>prezime;
           std::cout<<"Unesi adresu korisnika biblioteke, qume: "; std::cin>>adresa;
           std::cout<<"Unesi telefon korisnika biblioteke, qume: "; std::cin>>telefon;
           B.RegistrirajNovogKorisnika(clanski_br,ime,prezime,adresa,telefon);
            B.IzlistajKorisnike();
            B.IzlistajKnjige();
       std::cout<<"Unesite zeljeni broj od 0 do 7(0 znacava kraj usluge): ";
    std::cin>>x;
        }
            
        }
    } 
    catch(std::logic_error &e) {
        std::cout<<e.what();}

    return 0;
}