/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include <memory>
#include <new>

struct Korisnik{
    std::string ime;
    std::string prezime;
    std::string adresa;
    std::string telefon;
};

class Knjiga{
    std::string naslov;
    std::string ime_pisca;
    std::string zanr;
    int godina_izdavanja;
    std::shared_ptr<Korisnik> zaduzenje;
    
    public:
    Knjiga (std::string naslov, std::string ime_pisca, std::string zanr, int godina_izdavanja):naslov(naslov),ime_pisca(ime_pisca),zanr(zanr), godina_izdavanja(godina_izdavanja),zaduzenje(nullptr){}
    Knjiga ()= default;
    std::string DajNaslov() const{
        return naslov;
    }
    
    std::string DajAutora() const{
        return ime_pisca;
    }
    std::string DajZanr() const{
        return zanr;
    }
    int DajGodinuIzdavanja() const{
        return godina_izdavanja;
    }
    std::shared_ptr<Korisnik> DajKodKogaJe() const{
        return zaduzenje;
    }
    

    void ZaduziKnjigu(Korisnik &k){
        *zaduzenje=k;
    }
    
    void RazduziKnjigu(){
        zaduzenje=nullptr;
    }
    
    bool DaLiJeZaduzena(){
        if(zaduzenje==nullptr) return 0;
        else return 1;
    }
    
};

class Biblioteka{
    std::map<int, std::shared_ptr<Korisnik>> korisnici;
    std::map<int, std::shared_ptr<Knjiga>> knjige;
    
    
    public:
    Biblioteka(){}
    
    Biblioteka(const Biblioteka &b);
    Biblioteka(Biblioteka &&b);
    
    void RegistrirajNovogKorisnika(int clanski_broj_korisnika, std::string ime, std::string prezime, std::string adresa, std::string broj_telefona);
    void RegistrirajNovuKnjigu(int evidencijski_broj_knjige, std::string naslov, std::string ime_pisca, std::string zanr, int godina_izdavanja);
    Korisnik &NadjiKorisnika(int clanski_broj_korisnika) const;
    Knjiga &NadjiKnjigu (int evidencijski_broj_knjige) const;
    void IzlistajKorisnike() const;
    void IzlistajKnjige() const;
    void ZaduziKnjigu(int evidencijski_broj_knjige, int clanski_broj_korisnika);
    void RazduziKnjigu(int evidencijski_broj_knjige);
    void PrikaziZaduzenja(int clanski_broj_korisnika);
     
};


 Biblioteka::Biblioteka (const Biblioteka &b){
     for(auto it=b.korisnici.begin(); it!=b.korisnici.end(); it++){
         std::shared_ptr <Korisnik> pom=std::make_shared<Korisnik>();
         pom=it->second;
         Biblioteka::korisnici[it->first]=pom;
     }
     
     for(auto it=b.knjige.begin(); it!=b.knjige.end(); it++){
        
         std::shared_ptr<Knjiga> pom=std::make_shared <Knjiga>();
         pom=it->second;
         Biblioteka::knjige[it->first]=pom;
     }
     
 }
 
 Biblioteka::Biblioteka(Biblioteka &&b){
     Biblioteka::korisnici=b.korisnici;
     Biblioteka::knjige=b.knjige;
     for (auto it=b.korisnici.begin(); it!=b.korisnici.end(); it++){
         it->second=nullptr;
     }
     for (auto it=b.knjige.begin(); it!=b.knjige.end(); it++){
         it->second=nullptr;
     }
 }
 

 
 
 
 
 void Biblioteka::RegistrirajNovogKorisnika(int clanski_broj_korisnika, std::string ime, std::string prezime, std::string adresa, std::string broj_telefona){
     auto it(korisnici.find(clanski_broj_korisnika));
     if (it != korisnici.end()) throw std::logic_error ("Korisnik vec postoji");
   
     std::shared_ptr<Korisnik> pok=std::make_shared <Korisnik>();
     pok->ime=ime;
     pok->prezime=prezime;
     pok->adresa=adresa;
     pok->telefon=broj_telefona;
     
     korisnici[clanski_broj_korisnika]=pok;
     pok=nullptr;
 }
 
 void Biblioteka::RegistrirajNovuKnjigu(int evidencijski_broj_knjige, std::string naslov, std::string ime_pisca, std::string zanr, int godina_izdavanja){
     auto it(knjige.find(evidencijski_broj_knjige));
     if(it!=knjige.end()) throw std::logic_error ("Knjiga vec postoji");
     
    auto pok= std::make_shared <Knjiga> (naslov, ime_pisca, zanr,godina_izdavanja);
     
     
     knjige[evidencijski_broj_knjige]=pok;
     pok=nullptr;
     
     
 }
 
 Korisnik &Biblioteka::NadjiKorisnika(int clanski_broj_korisnika) const{
     auto it(korisnici.find(clanski_broj_korisnika));
     if (it == korisnici.end()) throw std::logic_error ("Korisnik nije nadjen");
     
     return *(it->second);
 }
 
 Knjiga &Biblioteka::NadjiKnjigu (int evidencijski_broj_knjige) const{
     auto it (knjige.find(evidencijski_broj_knjige));
     if(it==knjige.end()) throw std::logic_error ("Knjiga nije nadjena");
     
     return *(it->second);
 }
 
 void Biblioteka::IzlistajKorisnike() const{
     for(auto it=korisnici.begin(); it!=korisnici.end(); it++){
         std::cout<<"Clanski broj: "<<it->first;
         std::cout<<std::endl;
         std::cout<<"Ime i prezime: "<< it->second->ime <<" "<<it->second->prezime;
         std::cout<<std::endl;
         std::cout<<"Adresa: "<< it->second->adresa;
         std::cout<<std::endl;
         std::cout<<"Broj telefona: "<< it->second->telefon;
         std::cout<<std::endl;
         std::cout<<std::endl;
     }
 }
 
 void Biblioteka::IzlistajKnjige() const{
     for(auto it=knjige.begin(); it!=knjige.end(); it++){
         std::cout<<"Evidencijski broj: "<<it->first;
         std::cout<<std::endl;
         std::cout<<"Naslov: "<< it->second->DajNaslov();
         std::cout<<std::endl;
         std::cout<<"Pisac: "<< it->second->DajAutora();
         std::cout<<std::endl;
         std::cout<<"Zanr: "<< it->second->DajZanr();
         std::cout<<std::endl;
         std::cout<<"Godina izdavanja: " <<it->second->DajGodinuIzdavanja();
         std::cout<<std::endl;
         if(it->second->DaLiJeZaduzena()==1) {
             std::cout<<"Zaduzena kod korisnika: "<<it->second->DajKodKogaJe()->ime<<" "<<it->second->DajKodKogaJe()->prezime;
         }
         std::cout<<std::endl;
         std::cout<<std::endl;
     }
 }
 
 void Biblioteka::ZaduziKnjigu(int evidencijski_broj_knjige, int clanski_broj_korisnika){
     auto it1(knjige.find(evidencijski_broj_knjige));
     if (it1==knjige.end()) throw std::logic_error("Knjiga nije nadjena");
     auto it2(korisnici.find(clanski_broj_korisnika));
     if(it2==korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
     auto it3(knjige.find(evidencijski_broj_knjige));
     if(it3->second->DaLiJeZaduzena()==1) throw std::logic_error("Knjiga vec zaduzena");
     
     it1->second->ZaduziKnjigu(*(it2->second));
 }
 
 void Biblioteka::RazduziKnjigu(int evidencijski_broj_knjige){
     auto it(knjige.find(evidencijski_broj_knjige));
     if(it==knjige.end()) throw std::logic_error("Knjiga nije nadjena");
     if(it->second->DaLiJeZaduzena()==0)throw std::logic_error ("Knjiga nije zaduzena");
     
     it->second->RazduziKnjigu();
 }
 
 void Biblioteka::PrikaziZaduzenja(int clanski_broj_korisnika){
     auto it1(korisnici.find(clanski_broj_korisnika));
     if(it1==korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
     bool pronadjen (0);
     for (auto it=knjige.begin(); it!=knjige.end(); it++){
         if(it->second->DajKodKogaJe()==it1->second) {
            pronadjen=1;
         std::cout<<"Evidencijski broj: "<<it->first;
         std::cout<<std::endl;
         std::cout<<"Naslov: "<< it->second->DajNaslov();
         std::cout<<std::endl;
         std::cout<<"Pisac: "<< it->second->DajAutora();
         std::cout<<std::endl;
         std::cout<<"Zanr: "<< it->second->DajZanr();
         std::cout<<std::endl;
         std::cout<<"Godina izdavanja: "<< it->second->DajGodinuIzdavanja();
         std::cout<<std::endl;
         std::cout<<std::endl;
         }
         if(pronadjen==0) throw std::logic_error("Nema zaduzenja za tog korisnika");
     }
 }

int main ()
{
    
	return 0;
}