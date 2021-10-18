#include <iostream>
#include <map>
#include <string>
#include <stdexcept>
#include<utility>

struct Korisnik {
    std::string ime, prezime, adresa, telefon;
};

class Knjiga {
    std::string naslov, ime_pisca, zanr;
    int god__izdavanja;
    Korisnik *zaduzena;
    
    public:
    Knjiga (std::string naslov_knjige, std::string ime, std::string zanr_, int god);
    std::string DajNaslov () { return naslov;}
    std::string DajAutora () {return ime_pisca;}
    std::string DajZanr () {return zanr;}
    int DajGodinuIzdavanja () {return god__izdavanja;}
    Korisnik *DajKodKogaJe () { return zaduzena; }
    void ZaduziKnjigu (Korisnik &k) { zaduzena=&k;}
    void RazduziKnjigu () { zaduzena=nullptr;}
    bool DaLiJeZaduzena () {
        if(zaduzena==nullptr) return false;
        return true;
    }
};

Knjiga::Knjiga(std::string naslov_knjige, std::string ime, std::string zanr_, int god){
        naslov=naslov_knjige; ime_pisca=ime; zanr=zanr_, god__izdavanja=god; zaduzena=nullptr;
    }

class Biblioteka {
    std::map <int, Korisnik *> ko;
    std::map <int, Knjiga *> knj;
    
    public:
    Biblioteka () {};
    Biblioteka(const Biblioteka &b){
        for(auto it=(b.ko).begin(); it!=(b.ko).end(); it++){
            ko.insert(std::make_pair ( it->first, new Korisnik(*(it->second))));
        }
        
        for(auto it=(b.knj).begin(); it!=(b.knj).end(); it++){
           knj.insert(std::make_pair ( it->first, new Knjiga(*(it->second))));
        }
        
    }
    
    Biblioteka &operator = (const Biblioteka &b){
        if(this==&b) return *this;
        
        for(auto it=ko.begin();it!=ko.end();it++) delete it->second;
        for(auto it=knj.begin();it!=knj.end();it++) delete it->second;
        
        for(auto it=(b.ko).begin(); it!=(b.ko).end(); it++){
            ko.insert(std::make_pair ( it->first, new Korisnik(*(it->second))));
        }
        
        for(auto it=(b.knj).begin(); it!=(b.knj).end(); it++){
           knj.insert(std::make_pair ( it->first, new Knjiga(*(it->second))));
        }
    }
    
    void RegistrirajNovogKorisnika (int clanski_br, std::string ime, std::string prezime, std::string adresa, std::string br_telefona){
        Korisnik *pok;
            pok=new Korisnik;
        pok->ime=ime; pok->prezime=prezime; pok->adresa=adresa; pok->telefon=br_telefona;
        for(auto it=ko.begin(); it!=ko.end();it++)
            if(it->first==clanski_br) throw std::logic_error ("Korisnik vec postoji");

        ko.insert(std::make_pair(clanski_br,pok));
    }
    
    void RegistrirajNovuKnjigu (int evidencijski_broj, std::string naslov, std::string ime, std::string zanr, int godina){
        Knjiga *pok;
         try{
           pok=new Knjiga(naslov,ime,zanr,godina);
        }
        catch(...){
            delete pok;
        }
        //pok->DajNaslov()=naslov; pok->DajAutora()=ime; pok->DajZanr()=zanr; pok->DajGodinuIzdavanja()=godina;
        auto it (knj.find(evidencijski_broj));
        if(it==knj.end()) knj.insert (std::make_pair (evidencijski_broj,pok));
        else throw std::logic_error("Knjiga vec postoji");
       
    }
    
    Korisnik &NadjiKorisnika (int broj){
       auto it(ko.find(broj));
       if (it==ko.end()) throw  std::logic_error ("Korisnik nije nadjen");
       else return *ko [broj];
    }
    
    Knjiga &NadjiKnjigu (int broj){
       auto it(knj.find(broj));
       if (it==knj.end()) throw  std::logic_error ("Knjiga nije nadjena");
       else return  *knj [broj];
    }
    
    void IzlistajKorisnike () {
        for(auto i=ko.begin(); i!=ko.end(); i++){
            std::cout<<"Clanski broj: "<<i->first<<std::endl<<"Ime i prezime: "<<i->second->ime<<" "<<i->second->prezime<<std::endl<<"Adresa: "<<i->second->adresa<<std::endl<<"Broj telefona: "<<i->second->telefon;
            std::cout<<std::endl<<std::endl;
        }
    }
    
    void IzlistajKnjige () {
      for(auto i=knj.begin(); i!=knj.end(); i++){
          std::cout<<"Evidencijski broj: "<<i->first<<std::endl<<"Naslov: "<<i->second->DajNaslov()<<std::endl<<"Pisac: "<<i->second->DajAutora()<<std::endl<<"Zanr: "<<i->second->DajZanr()<<std::endl<<"Godina izdavanja: "<<i->second->DajGodinuIzdavanja()<<std::endl;
          if(i->second->DaLiJeZaduzena()) std::cout<<"Zaduzena kod korisnika: "<<i->second->DajKodKogaJe()->ime<<" "<<i->second->DajKodKogaJe()->prezime<<std::endl;
          std::cout<<std::endl;
      }  
    }
    
    void ZaduziKnjigu (int ev_broj, int cl_broj){
        Knjiga *pok1= &NadjiKnjigu(ev_broj);
        if(pok1->DaLiJeZaduzena()==true) throw std::logic_error ("Knjiga vec zaduzena");
        Korisnik *pok2=&NadjiKorisnika(cl_broj);
        pok1->Knjiga::ZaduziKnjigu(*pok2);
    }
    
    void RazduziKnjigu (int ev_broj){
        Knjiga *pok=&NadjiKnjigu(ev_broj);
        if(pok->DaLiJeZaduzena()==false) throw std::logic_error ("Knjiga nije zaduzena");
        pok->Knjiga::RazduziKnjigu();
    }
    
    ~Biblioteka (){
        for(auto it=ko.begin();it!=ko.end();it++) delete it->second;
        for(auto it=knj.begin();it!=knj.end();it++) delete it->second;
    }
   
   void PrikaziZaduzenja (int cl_broj){
       int br=0;
       Korisnik *pok=&NadjiKorisnika(cl_broj);
       for(auto it=knj.begin();it!=knj.end();it++){
           if((*it->second).DajKodKogaJe()==pok){
               br++;
               std::cout<<"Evidencijski broj: "<<it->first<<std::endl<<"Naslov: "<<it->second->DajNaslov()<<std::endl<<"Pisac: "<<it->second->DajAutora()<<std::endl<<"Zanr: "<<it->second->DajZanr()<<std::endl<<"Godina izdavanja: "<<it->second->DajGodinuIzdavanja()<<std::endl;
               std::cout<<std::endl;
           }
       }
       if(br==0) throw std::logic_error ("Nema zaduzenja za tog korisnika"); }
   
};
int main ()
{
    std::cout<<"Unesite tri korisnika biblioteke:\n";
    for(int i=0; i<3; i++){
        std::cout<<"Unesite clanski broj, ime i prezime, adresu, telefon "<<i+1<<". korisnika ";
        int cl_br;
        std::string im,p,a,t;
        std::cin>>cl_br;
        std::getline(std::cin,im); 
        std::getline(std::cin,p);
        std::getline(std::cin,a);
        std::getline(std::cin,t);
        RegistrirajNovogKorisnika (cl_br,im,p,a,t);
    }
	return 0;
}