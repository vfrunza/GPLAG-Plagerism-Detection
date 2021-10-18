/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <stdexcept>
#include <memory>
#include <map>
struct Korisnik{
    std::string ime,prezime,adresa,telefon;
};

class Knjiga{
    std::string naslov,ime_pisca,zanr;
    int godina_izdavanja;
    Korisnik *kod_koga_je;
    
    public:
    Knjiga(std::string s1,std::string s2,std::string s3,int godina){
        naslov=s1;
        ime_pisca=s2;
        zanr=s3;
        godina_izdavanja=godina;
        kod_koga_je=nullptr;
    }
    
    std::string DajNaslov() const { return naslov; }
    std::string DajAutora() const { return ime_pisca; }
    std::string DajZanr() const { return zanr; }
    int DajGodinuIzdavanja() const { return godina_izdavanja; }
    Korisnik *DajKodKogaJe() const {return kod_koga_je; }
    void ZaduziKnjigu(Korisnik &korisnik){
        kod_koga_je=&korisnik;
    }
    
    void RazduziKnjigu() {
        kod_koga_je=nullptr;
    }
    
    bool DaLiJeZaduzena(){
        if(kod_koga_je==nullptr) return false;
        else return true;
    }
    
};

class Biblioteka {
    std::map<int,std::shared_ptr<Korisnik>> korisnicka_mapa;
    std::map<int,std::shared_ptr<Knjiga>> mapa_knjiga;
    
    public:
    void RegistrirajNovogKorisnika(int n,std::string s1,std::string s2,std::string s3,std::string s4){
        if(!korisnicka_mapa.count(n)){
            std::shared_ptr<Korisnik> pok;
            pok=std::make_shared<Korisnik> ();
            pok->ime=s1;
            pok->prezime=s2;
            pok->adresa=s3;
            pok->telefon=s4;
            korisnicka_mapa.insert(std::make_pair(n,pok));
        }
        else {
            throw std::logic_error("Korisnik vec postoji");
        }
    }
    
    void RegistrirajNovuKnjigu(int n,std::string s1,std::string s2,std::string s3,int god){
        if(!mapa_knjiga.count(n)) {
            std::shared_ptr<Knjiga> pok1;
            pok1=std::make_shared<Knjiga> (s1,s2,s3,god);
            mapa_knjiga.insert(std::make_pair(n,pok1));
        }
        else {
            throw std::logic_error("Knjiga vec postoji");
        }
    }
    
    Korisnik NadjiKorisnika(int n){
        int a(0);
        for(auto it=korisnicka_mapa.begin();it!=korisnicka_mapa.end();it++){
            if(korisnicka_mapa.count(n))
             {
                 Korisnik korisnik=*((it->second).get());
                 return korisnik;
             }
            else a=1;
        }
        if(a==1) throw std::logic_error("Korisnik nije nadjen");
        
    }
    
    Knjiga NadjiKnjigu(int n){
        int a(0);
        for (auto it=mapa_knjiga.begin();it!=mapa_knjiga.end();it++){
            if(mapa_knjiga.count(n)){
                Knjiga knjige(" "," "," ",0);
                knjige= *((it->second).get());
                return knjige;
            }
            else a=1;
        }
        if(a==1) throw std::logic_error("Knjiga nije nadjena");
    }
    
    void IzlistajKorisnike() const {
        for(auto it=korisnicka_mapa.begin();it!=korisnicka_mapa.end();it++){
            std::cout<<"Clanski broj: "<<it->first;
            std::cout<<"\nIme i prezime: "<<it->second->ime<<" "<<it->second->prezime;
            std::cout<<"\nAdresa: "<<it->second->adresa;
            std::cout<<"\nBroj telefona: "<<it->second->telefon;
            std::cout<<"\n\n";
        }
    }
    
    void IzlistajKnjige() const {
       std::string s1,s2;
       int a=0;
        for(auto it=mapa_knjiga.begin();it!=mapa_knjiga.end();it++){
            std::cout<<"Evidencijski broj: "<<it->first;
            std::cout<<"\nNaslov: "<<it->second->DajNaslov();
            std::cout<<"\nPisac: "<<it->second->DajAutora();
            std::cout<<"\nZanr: "<<it->second->DajZanr();
            std::cout<<"\nGodina izdavanja: "<<it->second->DajGodinuIzdavanja();
            if(it->second->DaLiJeZaduzena()==true ){
                s1=it->second->DajKodKogaJe()->ime;
                s2=it->second->DajKodKogaJe()->prezime;
                a=1;
            }
           
            std::cout<<"\n\n";
        }
            if(a==1)
            std::cout<<"\nZaduzena kod korisnika: "<<s1<<" "<<s2;
            
        
    }
    
    void ZaduziKnjigu(int broj1,int broj2){
        for(auto it=mapa_knjiga.begin();it!=mapa_knjiga.end();it++){
            if(mapa_knjiga.count(broj1)){
                if(it->second->DaLiJeZaduzena()==true)
                throw std::logic_error("Knjiga je vec zaduzena");
                for(auto it1=korisnicka_mapa.begin();it1!=korisnicka_mapa.end();it1++){
                    if(korisnicka_mapa.count(broj2))
                   { it->second->ZaduziKnjigu(*(it1->second));
                       break;
                   }
                   else throw std::logic_error("Korisnik nije nadjen");
                }
            }
            
            else throw std::logic_error("Knjiga nije nadjena");
        }
        
    }
    
    void RazduziKnjigu(int broj){
        for(auto it=mapa_knjiga.begin();it!=mapa_knjiga.end();it++){
            if(mapa_knjiga.count(broj))
            {
                if(it->second->DaLiJeZaduzena()==false) 
                throw std::logic_error("Knjiga nije zaduzena");
                else
                it->second->RazduziKnjigu();
            }
            else throw std::logic_error("Knjiga nije nadjena");
            
        }
    }
};
int main ()
{
	return 0;
}