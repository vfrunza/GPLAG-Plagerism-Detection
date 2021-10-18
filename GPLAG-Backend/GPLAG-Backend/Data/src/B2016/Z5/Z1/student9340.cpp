#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <stdexcept>
#include <new>
#include <map>
#include <functional>

struct Korisnik {
    std::string ime,prezime,adresa,telefon;
    };
    class Knjiga {
        std::string naslov,ime_pisca,zanr;
        int godina_izdanja;
        Korisnik* zaduzena;
        public:
Knjiga(std::string naslov,std::string ime_pisca,std::string zanr,int godina_izdanja) :naslov(naslov),ime_pisca(ime_pisca),zanr(zanr),godina_izdanja(godina_izdanja) {
            zaduzena=nullptr;
        }
        std::string DajNaslov() {
            return naslov;
        }
        std::string DajAutora() {
            return ime_pisca;
        }
        std::string DajZanr() {
            return zanr;
        }
        int DajGodinuIzdavanja() {
            return godina_izdanja;
        }
        Korisnik* &DajKodKogaJe() {
            return zaduzena;
        }
        void ZaduziKnjigu(Korisnik &zaduzio) {
           Knjiga::zaduzena=&zaduzio;
        }
        void RazduziKnjigu() {
            Knjiga::zaduzena=nullptr;
        }
        bool DaLiJeZaduzena() {
            return zaduzena!=nullptr;
        }
    };
    
    class Biblioteka {
        std::map<int,Korisnik*> korisnici;
        std::map<int,Knjiga*> knjige;
        public:
        Biblioteka() {}
        ~Biblioteka() {
            if(korisnici.size()!=0 &&  knjige.size()!=0) {
                auto it(korisnici.begin());
         for(it=korisnici.begin();it!=korisnici.end();it++) {
            delete (*it).second;
            it->second=nullptr;
         }  
         auto  it2(knjige.begin());
         for(int j=0;j<knjige.size();j++) {
           delete (*it2).second;
           it2->second=nullptr;
           it2++;
         }
        }
        }
        Biblioteka(const Biblioteka &biblioteka);
            
        void RegistrirajNovogKorisnika(int clanski_broj,std::string ime,std::string prezime,std::string adresa,std::string broj_telefona);
        Biblioteka operator =(const Biblioteka &biblioteka);
        Biblioteka (Biblioteka &&biblioteka);
        Biblioteka operator =(Biblioteka &&biblioteka);
        void RegistrirajNovuKnjigu(int evidencijski_broj,std::string naslov,std::string ime_pisca,std::string zanr,int godina_izdanja);
        Korisnik &NadjiKorisnika(int clanski_broj);
        Knjiga &NadjiKnjigu(int evidencijski_broj);
        void IzlistajKorisnike() const;
        void IzlistajKnjige() const;
        void PrikaziZaduzenja(int clanski_broj) const;
        void ZaduziKnjigu(int evidencijski_broj,int clanski_broj);
        void RazduziKnjigu(int evidencijski_broj);
        };
Biblioteka::Biblioteka(const Biblioteka &biblioteka) {
        try {
            auto it2(biblioteka.korisnici.begin());
            for(int i=0;i<biblioteka.korisnici.size();i++) {
                Korisnik*pok(nullptr);
                pok=new Korisnik{(*it2).second->ime,(*it2).second->prezime,(*it2).second->adresa,(*it2).second->telefon};
               korisnici.insert(std::make_pair((*it2).first,pok));
               it2++;
            }
            }
            catch(std::bad_alloc) {
            }
        try {
            auto it(biblioteka.knjige.begin());
            for(int j=0;j<biblioteka.knjige.size();j++) {
                Knjiga*pok(nullptr);
               
                pok=new Knjiga((*it).second->DajNaslov(),(*it).second->DajAutora(),(*it).second->DajZanr(),(*it).second->DajGodinuIzdavanja());                              
            knjige.insert(std::make_pair((*it).first,pok));
            it++;
                }
        }
        catch(std::bad_alloc) {
        }
}
Biblioteka::Biblioteka(Biblioteka &&biblioteka) {
  korisnici=biblioteka.korisnici;
  knjige=biblioteka.knjige;
   } 
 Biblioteka  Biblioteka::operator =(const Biblioteka &biblioteka) {
     korisnici=biblioteka.korisnici;
     knjige=biblioteka.knjige;
     return *this;
 }
 Biblioteka Biblioteka::operator =(Biblioteka &&biblioteka) {
     
     korisnici=biblioteka.korisnici;
     knjige=biblioteka.knjige;
     return *this;
 }
void Biblioteka::RegistrirajNovogKorisnika(int clanski_broj,std::string ime,std::string prezime,std::string adresa,std::string broj_telefona) {
    try {
        auto it(korisnici.find(clanski_broj));
        if(it!=korisnici.end()) {
            throw std::logic_error ("Korisnik vec postoji");
        }
    Korisnik* pok(nullptr);
    pok=new Korisnik;
    (*pok).ime=ime;
    (*pok).prezime=prezime;
    (*pok).adresa=adresa;
    (*pok).telefon=broj_telefona;
    korisnici.insert(std::make_pair(clanski_broj,pok));
}
catch(std::bad_alloc) {
}
catch(std::logic_error e) {
    std::cout<<e.what()<<std::endl;
}
}
void Biblioteka::RegistrirajNovuKnjigu(int evidencijski_broj,std::string naslov,std::string ime_pisca,std::string zanr,int godina_izdanja) {
try {
    auto it(knjige.find(evidencijski_broj));
    if(it!=knjige.end()) {
        throw std::logic_error("Knjiga vec postoji");
    }
    Knjiga* pok(nullptr);
    pok=new Knjiga(naslov,ime_pisca,zanr,godina_izdanja);
    knjige.insert(std::make_pair(evidencijski_broj,pok));
}
catch(std::bad_alloc) {
}
catch(std::logic_error e) {
    std::cout<<e.what()<<std::endl;
}
}
Korisnik &Biblioteka::NadjiKorisnika(int clanski_broj) {
    
    auto it(korisnici.find(clanski_broj));
    try {
    if(it==korisnici.end()) 
    throw std::logic_error("Korisnik nije nadjen");
    return *(it->second);
}
catch(std::logic_error e) {
    std::cout<<e.what()<<std::endl;
}
return *(it->second);
}
Knjiga& Biblioteka::NadjiKnjigu(int evidencijski_broj) {
    auto it(knjige.find(evidencijski_broj));
    try {
    if(it==knjige.end()) 
    throw std::logic_error("Knjiga nije nadjena");
    return *(it->second);
}
catch(std::logic_error e) {
    std::cout<<e.what()<<std::endl;
}
return *(it->second);
}
void Biblioteka::IzlistajKorisnike() const {
    std::for_each(korisnici.begin(),korisnici.end(),[](const std::pair<int,Korisnik*> &par) {
        std::cout<<"Clanski broj: "<<par.first<<std::endl<<"Ime i prezime: "<<par.second->ime<<" "<<par.second->prezime<<std::endl<<"Adresa: "<<par.second->adresa<<std::endl;
        std::cout<<"Broj telefona: "<<par.second->telefon<<std::endl<<std::endl;
    });
}
void Biblioteka::IzlistajKnjige() const {
    std::for_each(knjige.begin(),knjige.end(),[](const std::pair<int,Knjiga*> &par) {
        std::cout<<"Evidencijski broj: "<<par.first<<std::endl<<"Naslov: "<<par.second->DajNaslov()<<std::endl<<"Pisac: "<<par.second->DajAutora()<<std::endl<<"Zanr: "<<par.second->DajZanr()<<std::endl;
              std::cout<<"Godina izdavanja: "<<par.second->DajGodinuIzdavanja()<<std::endl;    
              if(par.second->DaLiJeZaduzena()) {
                  std::cout<<"Zaduzena kod korisnika: "<<par.second->DajKodKogaJe()->ime<<" "<<par.second->DajKodKogaJe()->prezime<<std::endl;
                  }
              std::cout<<std::endl;
        });
}
void Biblioteka::ZaduziKnjigu(int evidencijski_broj,int clanski_broj) {
    if(knjige.find(evidencijski_broj)==knjige.end())
    throw std::logic_error("Knjiga nije nadjena");
    if(korisnici.find(clanski_broj)==korisnici.end()) 
        throw std::logic_error("Korisnik nije nadjen");
        if((knjige.find(evidencijski_broj)->second->DaLiJeZaduzena()))
        throw std::logic_error("Knjiga vec zaduzena");
        auto it(korisnici.find(clanski_broj));
        Korisnik* kor(it->second);
        auto it2(knjige.find(evidencijski_broj));
        Knjiga* &knj(it2->second);
        knj->DajKodKogaJe()=kor;
}
void Biblioteka::RazduziKnjigu(int evidencijski_broj) {
    try {
    if(knjige.find(evidencijski_broj)==knjige.end()) throw std::logic_error("Knjiga nije nadjena");
    if(!(knjige.find(evidencijski_broj)->second->DaLiJeZaduzena())) throw std::logic_error("Knjiga nije zaduzena");
    auto it(knjige.find(evidencijski_broj));
    (it->second)->RazduziKnjigu();
}
catch(std::logic_error e){
    std::cout<<e.what()<<std::endl;
}
}

void Biblioteka::PrikaziZaduzenja(int clanski_broj) const {
    int broj(0);
    std::vector<Knjiga> v;
    std::vector<int> v1;
    try {
    if(korisnici.find(clanski_broj)==korisnici.end())
    throw std::logic_error("Korisnik nije nadjen");
    Biblioteka tek(*this);
    for_each(knjige.begin(),knjige.end(),[clanski_broj, &broj, &v, &v1,&tek](std::pair<int,Knjiga*> par) {
        if(par.second->DajKodKogaJe()->ime==tek.NadjiKorisnika(clanski_broj).ime && par.second->DajKodKogaJe()->prezime==tek.NadjiKorisnika(clanski_broj).prezime && par.second->DajKodKogaJe()->adresa==tek.NadjiKorisnika(clanski_broj).adresa && par.second->DajKodKogaJe()->telefon==tek.NadjiKorisnika(clanski_broj).telefon) {
        broj++;
        v1.push_back(par.first);
        v.push_back(*(par.second));
    }
    });
    if(broj==0)
        std::cout<<"Nema zaduzenja za tog korisnika"<<std::endl;
    else {
        int i(0);
        for_each(v.begin(),v.end(),[v1,&i](Knjiga k) {
             std::cout<<"Evidencijski broj: "<<v1[i++]<<std::endl<<"Naslov: "<<k.DajNaslov()<<std::endl<<"Pisac: "<<k.DajAutora()<<std::endl<<"Zanr: "<<k.DajZanr()<<std::endl;
              std::cout<<"Godina izdavanja: "<<k.DajGodinuIzdavanja()<<std::endl;  
        });
    }
}
catch(std::logic_error e) {
    std::cout<<e.what()<<std::endl;
}
}
int main ()
{
    std::cout<<"Unesite nesto";
	return 0;
}