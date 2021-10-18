#include <iostream>
#include <string>
#include <map>
#include <memory>
#include <utility>
#include <iterator>
#include <algorithm>
#include <stdexcept>
struct Korisnik{
    std::string ime, prezime, adresa, telefon;    
};

class Knjiga{
    std::string naslov, ime_pisca, zanr;
    int godina;
    Korisnik* kod_koga_je;
    public:
    Knjiga(std::string naslov, std::string ime_pisca, std::string zanr, int godina):
    naslov(naslov), ime_pisca(ime_pisca), zanr(zanr), godina(godina)
    {
        kod_koga_je=nullptr;
    }
    std::string DajNaslov() const{return naslov;}
    std::string DajAutora() const{return ime_pisca;}
    std::string DajZanr() const{return zanr;}
    int DajGodinuIzdavanja() const{return godina;}
    Korisnik* DajKodKogaJe() const{return kod_koga_je;}
    void ZaduziKnjigu(Korisnik &zaduzena){
        kod_koga_je=&zaduzena;
    }
    void RazduziKnjigu(){
        kod_koga_je=nullptr;
    }
    bool DaLiJeZaduzena(){
        if(kod_koga_je!=nullptr) return true;
        else return false;
    }
};

class Biblioteka{
    std::map<int, std::shared_ptr<Korisnik>> m1;
    std::map<int, std::shared_ptr<Knjiga>> m2;
    public:
    Biblioteka(){}
    ~Biblioteka(){
        m1.clear(); m2.clear();
    }
    Biblioteka(const Biblioteka &b){
        auto it1=b.m1.begin();
        std::shared_ptr<Korisnik> pointer;
        try{
        for(auto it=b.m1.begin(); it!=b.m1.end(); it++){
            pointer=std::shared_ptr<Korisnik>(new Korisnik{it1->second->ime,it1->second->prezime,it1->second->adresa,it1->second->telefon});
            m1.insert(std::make_pair(it1->first,pointer));
        }
        }catch(std::bad_alloc){
            std::cout<<std::endl;
        }
        auto it2=b.m2.begin();
        std::shared_ptr<Knjiga> point;
        try{
        for(auto it=b.m2.begin(); it!=b.m2.end(); it++){
            point=std::make_shared<Knjiga>((*it2).second->DajNaslov(),(*it2).second->DajAutora(),(*it2).second->DajZanr(),(*it2).second->DajGodinuIzdavanja());
            m2.insert(std::make_pair((*it2).first,point));
        }
        }catch(std::bad_alloc){
            std::cout<<std::endl;
        }
    }
    Biblioteka(Biblioteka &&b){
        m1=b.m1;
        m2=b.m2;
    }
    Biblioteka &operator =(const Biblioteka &b){
        (*this).~Biblioteka();
        m1=b.m1;
        m2=b.m2;
        return *this;
        
    }  
    Biblioteka &operator =(Biblioteka &&b){
        (*this).~Biblioteka();
        m1=b.m1;
        m2=b.m2;
        return *this;
    }
    void RegistrirajNovogKorisnika(int broj, std::string ime, std::string prezime, std::string adresa, std::string telefon){
        try{
        if(m1.find(broj)!=m1.end()) throw std::logic_error("Korisnik vec postoji");
            std::shared_ptr<Korisnik> p(nullptr);
            p=std::shared_ptr<Korisnik> (new Korisnik{ime, prezime, adresa, telefon});
            m1.insert(std::make_pair(broj,p));
        }catch(std::bad_alloc){
            std::cout<<std::endl;
        }catch(std::logic_error l){
            std::cout<<l.what()<<std::endl;
        }
    }
    void RegistrirajNovuKnjigu(int broj, std::string naslov, std::string ime_pisca,  std::string zanr, int godina){
        try{
        if(m2.find(broj)!=m2.end()) throw std::logic_error("Knjiga vec postoji");
            std::shared_ptr<Knjiga>k(nullptr);
            k=std::make_shared<Knjiga>(naslov,ime_pisca,zanr, godina);
            m2.insert(std::make_pair(broj,k));
        }catch(std::bad_alloc){
            std::cout<<std::endl;
        }catch(std::logic_error l){
            std::cout<<l.what()<<std::endl;
        }
    } 
    Korisnik& NadjiKorisnika(int n){
        try{
            auto it(m1.find(n));
          if(it==m1.end()) throw std::logic_error("Korisnik nije nadjen");
        }catch(std::logic_error l){
            std::cout<<l.what()<<std::endl;
        } return (*(m1.find(n))->second);
    }
    Knjiga& NadjiKnjigu(int e){
       try{
           auto it(m2.find(e));
          if(it==m2.end()) throw std::logic_error("Knjiga nije nadjena");
        }catch(std::logic_error l){
            std::cout<<l.what()<<std::endl;
        } return (*(m2.find(e))->second);
    }
    void IzlistajKorisnike(){
        for(auto it=m1.begin(); it!=m1.end(); it++){
            std::cout<<"Clanski broj: "<<it->first<<std::endl;
            std::cout<<"Ime i prezime: "<<it->second->ime<<" "<<it->second->prezime<<std::endl;
            std::cout<<"Adresa: "<<it->second->adresa<<std::endl;
            std::cout<<"Broj telefona: "<<it->second->telefon<<std::endl;
            std::cout<<std::endl;
        }
    }
    void IzlistajKnjige(){
        for(auto it=m2.begin(); it!=m2.end(); it++){
            std::cout<<"Evidencijski broj: "<<it->first<<std::endl;
            std::cout<<"Naslov: "<<it->second->DajNaslov()<<std::endl;
            std::cout<<"Pisac: "<<it->second->DajAutora()<<std::endl;
            std::cout<<"Zanr: "<<it->second->DajZanr()<<std::endl;
            std::cout<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<std::endl;
            if(it->second->DaLiJeZaduzena()){
                std::cout<<"Zaduzena kod korisnika: "<<it->second->DajKodKogaJe()->ime<<" "<<it->second->DajKodKogaJe()->prezime;
            }
    }
    }
    void ZaduziKnjigu(int e, int n){
        try{
        auto it(m1.find(n));
        if(m2.find(e)==m2.end()) throw std::logic_error("Knjiga nije nadjena");
        if(it==m1.end()) throw std::logic_error("Korisnik nije nadjen");
        if(m2.find(e)->second->DaLiJeZaduzena()) throw std::logic_error("Knjiga vec zaduzena");
        NadjiKnjigu(e).Knjiga::ZaduziKnjigu(*(m1.find(n)->second));
    }catch(std::logic_error l){
        std::cout<<l.what();
    }
    }
    void RazduziKnjigu(int e){
        if(e<0 || m2.find(e)->second->DaLiJeZaduzena()==false) throw std::logic_error("Knjiga nije zaduzena");
        NadjiKnjigu(e).RazduziKnjigu();
    }
    void PrikaziZaduzenja(int n){
        try{
        if(n<1) throw std::domain_error("Korisnik nije nadjen");
        for(auto it=m2.begin(); it!=m2.end(); it++){
            if(it->second->DajKodKogaJe()==&NadjiKorisnika(n)){
            std::cout<<"Evidencijski broj: "<<it->first<<std::endl;
            std::cout<<"Naslov: "<<it->second->DajNaslov()<<std::endl;
            std::cout<<"Pisac: "<<it->second->DajAutora()<<std::endl;
            std::cout<<"Zanr: "<<it->second->DajZanr()<<std::endl;
            std::cout<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<std::endl;
            std::cout<<std::endl;
        }else{
            std::cout<<"Nema zaduzenja za tog korisnika"<<std::endl;
        }
    }}catch(std::domain_error e){
        std::cout<<e.what()<<std::endl;
    }
    }
};
int main ()
{   
    
	return 0;
}