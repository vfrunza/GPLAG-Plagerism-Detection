/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <string>
#include <map>
#include <memory>

struct Korisnik{
    std::string ime, prezime, adresa, telefon;
    
};
class Knjiga{
    std::string naslovknjige, pisac, zanr;
    int god_izdavanja;
    std::shared_ptr<Korisnik> poknakor;
    public:
    Knjiga (std::string naslov, std::string imepisca, std::string zanrzanr, int godina): naslovknjige(naslov), pisac(imepisca),zanr(zanrzanr),  god_izdavanja(godina),poknakor(nullptr) {}
    std::string DajNaslov() const { return naslovknjige; }
    std::string DajAutora() const {return pisac; }
    std::string DajZanr() const {return zanr; }
    int DajGodinuIzdavanja() const {return god_izdavanja; }
   std::shared_ptr<Korisnik> DajKodKogaJe() const {return poknakor;}
    void ZaduziKnjigu ( Korisnik &korisnik) { poknakor=std::make_shared<Korisnik>(korisnik); }
    void RazduziKnjigu() { poknakor=nullptr; }
    bool DaLiJeZaduzena () {
        if(poknakor == nullptr) return false;
        return true;
    }
};
class Biblioteka{
    std::map<int, std::shared_ptr<Korisnik>> korisnici;
    std::map<int, std::shared_ptr<Knjiga>> knjige;
    public:
    void RegistrirajNovogKorisnika(int indeks, std::string ime1,std::string prezime1, std::string adresa1, std::string telefon1 );
    void RegistrirajNovuKnjigu(int broj, std::string naslov, std::string imepisca, std::string zanrzanr, int godina);
    Korisnik &NadjiKorisnika(int clanskibroj);
    Knjiga &NadjiKnjigu(int broj);
    void IzlistajKorisnike() const;
    void IzlistajKnjige() const;
    void ZaduziKnjigu(int evibroj, int clbroj);
    void RazduziKnjigu(int evibroj);
    void PrikaziZaduzenja ( int clbroj);
  //  Biblioteka &operator =(const Biblioteka &v);
  //    Biblioteka &operator =(Biblioteka &&v);
//    Biblioteka(const Biblioteka &v);
  //  Biblioteka(Biblioteka &&v);
};

 void Biblioteka::RegistrirajNovogKorisnika(int indeks, std::string ime1,std::string prezime1, std::string adresa1, std::string telefon1 ){
        auto it(korisnici.find(indeks));
        if(it!=korisnici.end()) throw std::logic_error("Korisnik vec postoji");
        try{
        std::shared_ptr<Korisnik> korisnik(new Korisnik{ime1, prezime1, adresa1,telefon1});
        korisnici[indeks]=korisnik;
        }
        catch(...)
        {
            std::cout<<"Problemi sa memorijom";
        }
    }
    
 void Biblioteka::RegistrirajNovuKnjigu(int broj, std::string naslov, std::string imepisca, std::string zanrzanr, int godina){
     
     auto it(knjige.find(broj));
     if(it!=knjige.end()) throw std::logic_error("Knjiga vec postoji");
     try{
          std::shared_ptr<Knjiga> knjiga(new Knjiga(naslov, imepisca, zanrzanr,godina));
         knjige[broj]=knjiga;
     }
     catch(...)
     {
         std::cout<<"Problemi sa memorijom";
        
     }
 }    
 Korisnik &Biblioteka::NadjiKorisnika(int clanskibroj){
  auto it(korisnici.find(clanskibroj));
    if(it==korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
    return *(it->second); 
 }
 
 Knjiga &Biblioteka::NadjiKnjigu(int broj){
     auto it(knjige.find(broj));
     if(it==knjige.end()) throw std::logic_error("Knjiga nije nadjena");
     return  *(it->second);
 }

    void Biblioteka::IzlistajKorisnike() const{
        for(auto it = korisnici.begin(); it != korisnici.end(); it++)
        {
            std::cout<<"Clanski broj: "<< it->first<<std::endl;
            std::cout<<"Ime i prezime: "<< it->second->ime<<" "<<it->second->prezime<<std::endl;
            std::cout<<"Adresa: "<<it->second->adresa<<std::endl;
            std::cout<<"Broj telefona: "<<it->second->telefon<<std::endl;
            std::cout<<std::endl;
        }
    }
    
    void Biblioteka::IzlistajKnjige() const{
         for(auto it = knjige.begin(); it != knjige.end(); it++)
        {
            std::cout<<"Evidencijski broj: "<< it->first<<std::endl;
            std::cout<<"Naslov: "<< it->second->DajNaslov()<<std::endl;
            std::cout<<"Pisac: "<<it->second->DajAutora()<<std::endl;
            std::cout<<"Zanr: "<<it->second->DajZanr()<<std::endl;
            std::cout<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<std::endl;
             if(it->second->DajKodKogaJe()!=nullptr){
                std::cout<<"Zaduzena kod korisnika: "<<it->second->DajKodKogaJe()->ime<<" "<<it->second->DajKodKogaJe()->prezime;
            }
            std::cout<<std::endl;
            
        }
    }
   
    void Biblioteka::ZaduziKnjigu(int evibroj, int clbroj){
        auto it(knjige.find(evibroj));
     if(it==knjige.end()) throw std::logic_error("Knjiga nije nadjena");
        auto it1(korisnici.find(clbroj));
     if(it1==korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
        auto it2(knjige.find(evibroj));
    // if(it2->second != nullptr) throw std::logic_error("Knjiga vec zaduzena");
     
     (*(it2->second)).Knjiga::ZaduziKnjigu(*(it1->second));   
    }
    
    void Biblioteka::RazduziKnjigu(int evibroj){
    
    auto it(knjige.find(evibroj));
    if(it==knjige.end()) throw std::logic_error("Knjiga nije nadjena");
    if(it->second->DaLiJeZaduzena() ==false) throw std::logic_error("Knjiga nije zaduzena");
    
     (*(it->second)).Knjiga::RazduziKnjigu();
        }

    void Biblioteka::PrikaziZaduzenja ( int clbroj){
        auto it1(korisnici.find(clbroj));
     if(it1==korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
        
        for(auto it = knjige.begin(); it != knjige.end(); it++)
        {
            if(it->second->DajKodKogaJe()==it1->second){
                 std::cout<<"Evidencijski broj: "<< it->first<<std::endl;
            std::cout<<"Naslov: "<< it->second->DajNaslov()<<std::endl;
            std::cout<<"Pisac: "<<it->second->DajAutora()<<std::endl;
            std::cout<<"Zanr: "<<it->second->DajZanr()<<std::endl;
            std::cout<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<std::endl;
            std::cout<<std::endl;
            }
        }
        
    }

int main ()
{
    Biblioteka biblioteka;
    
    int n;
     std::cout<<"Izaberite jednu od mogucih opcija: "<<std::endl;
     std::cout<<"1 - Registriraj novog korisnika"<<std::endl;
     std::cout<<"2 - Registriraj novu knjigu"<<std::endl;
	std::cout<<"3 - Izlistaj korisnike"<<std::endl;
	std::cout<<"4 - Izlistaj knjige"<<std::endl;
	std::cout<<"5 - Zaduzi knjigu"<<std::endl;
	std::cout<<"6 - Razduzi knjigu"<<std::endl;
	std::cout<<"7 - Prikazi zaduzenja"<<std::endl;
	std::cout<<"0 - Kraj programa"<<std::endl;
	std::cin>>n;
	if(n==0) return 0;
	try{
	while(n!=0)
	{
	    if(n==1){
	        int clbroj;
	        std::string ime, prezime, adresa, telefon;
	        std::cout<<"Unesite clanski broj korisnika: ";
	        std::cin>> clbroj;
	        std::cout<<"Unesite ime korisnika: ";
	        std::cin>>ime;
	        std::cout<<"Unesite prezime korisnika: ";
	        std::cin>>prezime;
	        std::cout<<"Unesite adresu korisnika: ";
	        std::cin>>adresa;
	        std::cout<<"Unesite broj telefona korisnika: ";
	        std::cin>>telefon;
	        biblioteka.RegistrirajNovogKorisnika(clbroj,ime,prezime,adresa,telefon);
	    }
	    else if(n==3){
	        biblioteka.IzlistajKorisnike();
	    }
	    else if(n==2){
	        int broj,godina;
	        std::string naslov, pisac, zanr;
	        std::cout<<"Unesite evidencijski broj knjige: ";
	        std::cin>> broj;
	        std::cout<<"Unesite naslov knjige: ";
	        std::cin>>naslov;
	        std::cout<<"Unesite ime pisca: ";
	        std::cin>>pisac;
	        std::cout<<"Unesite zanr knjige: ";
	        std::cin>>zanr;
	        std::cout<<"Unesite godinu izdavanja: ";
	        std::cin>>godina;
	        biblioteka.RegistrirajNovuKnjigu(broj,naslov,pisac,zanr,godina);
	    }
	    else if(n==4){
	        biblioteka.IzlistajKnjige();
	    }
	    else if(n==5){
	        int evbroj, clbroj;
	        std::cout<<"Unesite evidencijski broj knjige: ";
	        std::cin>>evbroj;
	        std::cout<<"Unesite clanski broj korisnika: ";
	        std::cin>>clbroj;
	        biblioteka.ZaduziKnjigu(evbroj, clbroj);
	    }
	    else if(n==7)
	    {
	        std::cout<<"Unesite clanski broj korisnika za koji zelite vidjeti zaduzenja: ";
	        int clbroj;
	        std::cin>>clbroj;
	        biblioteka.PrikaziZaduzenja(clbroj);
	    }
	    else if(n==6)
	    {
	        std::cout<<"Unesite evidencijski broj knjige koju zelite razduziti: ";
	        int evibroj;
	        std::cin>>evibroj;
	        biblioteka.RazduziKnjigu(evibroj);
	    }
	    std::cout<<"Unesite opet zeljenu opciju: ";
	    std::cin>>n;
	    
	}
	}
	catch(std::logic_error s)
	{
	    std::cout<<s.what()<<std::endl;
	}
	return 0;
}