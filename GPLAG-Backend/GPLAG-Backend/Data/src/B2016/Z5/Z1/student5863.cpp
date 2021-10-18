/B16/17 (Zadaća 5, Zadatak 1)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <map>
#include <stdexcept>


struct Korisnik { 
    std::string ime,prezime,adresa,telefon;
};

class Knjiga {
    std::string naslov,ime_pisca,zanr;
    int godina_izdavanja;
    Korisnik *zaduzen = nullptr;
    public:
    Knjiga(std::string naslov, std::string ime_pisca, std::string zanr, int godina) : naslov(naslov), ime_pisca(ime_pisca), zanr(zanr), godina_izdavanja(godina), zaduzen(nullptr) {}
    std::string DajNaslov() const { return naslov; }
    std::string DajAutora() const { return ime_pisca; }
    std::string DajZanr() const { return zanr; }
    int DajGodinuIzdavanja() const { return godina_izdavanja; }
    Korisnik *DajKodKogaJe() const { return zaduzen; }  // msm da je to to
    void ZaduziKnjigu(Korisnik &k) {
       
        zaduzen = &k;
    }
    void RazduziKnjigu() {
        zaduzen = nullptr;
    }
    bool DaLiJeZaduzena() {
        if( zaduzen == nullptr) return false;
        return true;
    }
    
};


class Biblioteka {
    std::map<int,Korisnik*> korisnici;
    std::map<int,Knjiga*> knjige;
    
    static void IspisKnjige(const Knjiga *k) {
           std::cout<<"Naslov: "<<k->DajNaslov()<<std::endl;
           std::cout<<"Pisac: "<<k->DajAutora()<<std::endl;
           std::cout<<"Zanr: "<<k->DajZanr()<<std::endl;
           std::cout<<"Godina izdavanja: "<<k->DajGodinuIzdavanja()<<std::endl;
    }
    
    public:
 
    
    Biblioteka() {}
    Biblioteka(const Biblioteka &b);
    Biblioteka &operator =(const Biblioteka &b);
    ~Biblioteka() {
        for(auto it = korisnici.begin(); it != korisnici.end(); it++)
         delete it->second;
        for(auto i = knjige.begin(); i != knjige.end(); i++)
         delete i->second;
    }
    
    void RegistrirajNovogKorisnika(int clanski_br, std::string ime, std::string prezime, std::string adresa, std::string tel) {
     
        for(auto it = korisnici.begin(); it != korisnici.end(); it++)
        if( clanski_br == it->first) throw std::logic_error("Korisnik vec postoji");
        auto pok(new Korisnik);
        pok->ime = ime;
        pok->prezime = prezime;
        pok->adresa = adresa;
        pok->telefon = tel;
        
        korisnici.insert(std::make_pair(clanski_br, pok));
    }
    void RegistrirajNovuKnjigu(int br_knjige, std::string naslov, std::string autor, std::string zanr, int godina) {
        for(auto it = knjige.begin(); it != knjige.end(); it++)
        if(br_knjige == it->first) throw std::logic_error("Knjiga vec postoji");
        
        knjige.insert(std::make_pair(br_knjige, new Knjiga(naslov,autor,zanr,godina)));
    }
    
    Korisnik &NadjiKorisnika(int clanski_br) const {
        for(auto it = korisnici.begin(); it != korisnici.end(); it++ )
           if(clanski_br == it->first) return *(it->second);
           
           throw std::logic_error("Korisnik nije nadjen");
    }
    
    Knjiga &NadjiKnjigu( int br_knjige) const {
        for(auto it = knjige.begin(); it != knjige.end(); it++)
        if( it->first == br_knjige) return *(it->second); // ili nesto kao daj kopiju
        
        throw std::logic_error("Knjiga nije nadjena");
        
    }
    
    void IzlistajKorisnike() const {
       for(auto it = korisnici.begin(); it != korisnici.end(); it++) {
           std::cout<<"Clanski broj: "<<it->first<<std::endl;
           std::cout<<"Ime i prezime: "<<it->second->ime<<" "<<it->second->prezime<<std::endl;
           std::cout<<"Adresa: "<<it->second->adresa<<std::endl;
           std::cout<<"Broj telefona: "<<it->second->telefon<<std::endl<<std::endl;
       }
    }

   void IzlistajKnjige() const {
       for(auto it = knjige.begin(); it != knjige.end(); it++) {
           std::cout<<"Evidencijski broj: "<<it->first<<std::endl;
           IspisKnjige(it->second);
           if( it->second->DajKodKogaJe() != nullptr)  std::cout<<"Zaduzena kod korisnika: "<< it->second->DajKodKogaJe()->ime<< " " << it->second->DajKodKogaJe()->prezime<<std::endl;
         
               std::cout<<std::endl;
          
       }
   } 
   
   void ZaduziKnjigu(int ev_br_knjige, int clanski_br) const {
      if(NadjiKnjigu(ev_br_knjige).DaLiJeZaduzena()) throw std::logic_error("Knjiga vec zaduzena");
       knjige.find(ev_br_knjige)->second->ZaduziKnjigu(*(korisnici.find(clanski_br)->second));
     
     
   }
   
   void RazduziKnjigu(int ev_br_knjige) const {
       if(!NadjiKnjigu(ev_br_knjige).DaLiJeZaduzena()) throw std::logic_error("Knjiga nije zaduzena");
       knjige.find(ev_br_knjige)->second->RazduziKnjigu();
   }
   
   void PrikaziZaduzenja(int clanski_br) const { 
       auto k = NadjiKorisnika(clanski_br) ;
       bool jel = true;
       for(auto it = knjige.begin(); it != knjige.end(); it++) 
       if( it->second->DajKodKogaJe() != nullptr) {
               if(k.ime == it->second->DajKodKogaJe()->ime && k.prezime == it->second->DajKodKogaJe()->prezime && k.adresa == it->second->DajKodKogaJe()->adresa && k.telefon == it->second->DajKodKogaJe()->telefon) 
                {
                     std::cout<<"Evidencijski broj: "<<it->first<<std::endl;
                     IspisKnjige(it->second);
                     jel = false;
                     std::cout<<std::endl;
                }
       }
      if(jel) std::cout<<"Nema zaduzenja za tog korisnika!";
      
   }
   
   
};



Biblioteka::Biblioteka(const Biblioteka &b) {
    for( auto it = b.korisnici.begin(); it != b.korisnici.end(); it++ ) {
        auto pok(new Korisnik);
        pok->ime = it->second->ime;
        pok->prezime = it->second->prezime;
        pok->adresa = it->second->adresa;
        pok->telefon = it->second->telefon;
    
    korisnici.insert(std::make_pair(it->first, pok));
    }
    for(auto i = b.knjige.begin(); i != b.knjige.end(); i++)
    knjige.insert(std::make_pair(i->first, new Knjiga(i->second->DajNaslov(), i->second->DajAutora(), i->second->DajZanr(), i->second->DajGodinuIzdavanja())));
}

Biblioteka &Biblioteka::operator =(const Biblioteka &b) {
    for( auto it = b.korisnici.begin(); it != b.korisnici.end(); it++ ) {
        auto pok(new Korisnik);
        pok->ime = it->second->ime;
        pok->prezime = it->second->prezime;
        pok->adresa = it->second->adresa;
        pok->telefon = it->second->telefon;
     
    korisnici.insert(std::make_pair(it->first, pok));
    }
    for(auto i = b.knjige.begin(); i != b.knjige.end(); i++)
    knjige.insert(std::make_pair(i->first, new Knjiga(i->second->DajNaslov(), i->second->DajAutora(), i->second->DajZanr(), i->second->DajGodinuIzdavanja())));
    
    return *this;
}

    


int main ()
{
    try{
       Biblioteka b;
       while(true) {
       std::cout<<" 0 - kraj\n 1 - registruj novog korisnika\n 2 - registruj novu knjigu\n 3 - nadji korisnikan 4 - nadji knjigu\n 5 - izlistaj korisnike\n 6 - izlistaj knjige\n 7 - zaduzi knjigu\n 8 - razduzi knjigu\n 9 - prikazi zaduzenja\n";
       int opcija = 0;
       std::cin>> opcija;
       if(opcija == 0) break;
       else if(opcija == 1) {
           //ime,prezime,adresa,br tel
            std::cout<<"Unesite clanski broj: ";
           int br;
           std::cin>>br;
           std::cout<<"Unesite ime korisnika: ";
           std::string ime;
           std::cin.ignore(1000,'\n');
           std::getline(std::cin,ime);
           std::cout<<"Unesite prezime korisnika: ";
           std::string prezime;
           std::getline(std::cin, prezime);
           std::cout<<"Unesite adresu korisnika: ";
           std::string adresa;
           std::getline(std::cin, adresa);
           std::cout<<"Unesite broj telefona korisnika: ";
           std::string fon;
           std::getline(std::cin,fon);
           b.RegistrirajNovogKorisnika(br,ime,prezime,adresa,fon);
       }
       else if(opcija == 2) {
           //naslov ime pisca zanr i godina izdavanja
           std::cout<<"Unesite evidencijski broj: ";
           int br;
           std::cin>>br;
           std::cout<<"Unesite naslov: ";
           std::string naslov;
           std::cin.ignore(1000,'\n');
           std::getline(std::cin,naslov);
           std::cout<<"Unesite ime pisca: ";
           std::string ime;
           std::getline(std::cin, ime);
           std::cout<<"Unesite zanr: ";
           std::string zanr;
           std::getline(std::cin, zanr);
           std::cout<<"Unesite godinu izdavanja: ";
           int god;
           std::cin>>god;
           b.RegistrirajNovuKnjigu(br,naslov,ime,zanr,god);
           
       }
       else if( opcija == 3) {
           //clanski broj
           std::cout<<"Unesite clanski broj: ";
           int br;
           std::cin>>br;
          auto kor = b.NadjiKorisnika(br);
          std::cout<<kor.ime<<"  "<<kor.prezime<<std::endl;
       }
       else if( opcija == 4) {
           //evidencijski broj
           std::cout<<"Unesite evidencijski broj: ";
           int br;
           std::cin>>br;
           auto knj = b.NadjiKnjigu(br);
           std::cout<<knj.DajNaslov()<<" "<<knj.DajAutora()<<std::endl;
       }
       else if( opcija == 5) {
           b.IzlistajKorisnike();
           
       }
       else if(opcija == 6) {
           b.IzlistajKnjige();
           
       }
       else if(opcija == 7) {
           //ev br knjige i clnaski korisnika
            std::cout<<"Unesite clanski broj: ";
           int br;
           std::cin>>br;
           std::cout<<"Unesite evidencijski broj: ";
           int ev;
           std::cin>>ev;
           b.ZaduziKnjigu(ev,br);
       }
       else if( opcija == 8) {
           //ev br knjige
           std::cout<<"Unesite evidencijski broj: ";
           int ev;
           std::cin>>ev;
           b.RazduziKnjigu(ev);
       }
       else if( opcija == 9) {
           //clanski br korisnika
             std::cout<<"Unesite clanski broj: ";
           int br;
           std::cin>>br;
           b.PrikaziZaduzenja(br);
       }
       
       }

    
    }catch(std::logic_error l) {
        std::cout << l.what() << std::endl;
    }
	return 0;
}