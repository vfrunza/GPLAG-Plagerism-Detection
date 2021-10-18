#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include <new>


struct Korisnik{
    std::string ime,prezime,adresa,telefon;
};
class Knjiga{
    std::string naslov,ime_pisca,zanr;
    int godina_izdavanja;
    Korisnik *koga=nullptr;
    public:
        Knjiga(std::string n,std::string i,std::string z,int g):naslov(n),ime_pisca(i),zanr(z),godina_izdavanja(g),koga(nullptr){}
        std::string DajNaslov() const{return naslov;}
        std::string DajAutora() const{return ime_pisca;}
        std::string DajZanr() const{return zanr;}
        int DajGodinuIzdavanja() const{return godina_izdavanja;}
        Korisnik DajKodKogaJe () const{return *koga;}
        void ZaduziKnjigu(Korisnik &korisnik){koga=&korisnik;}
        void RazduziKnjigu(){koga=nullptr;}
        bool DaLiJeZaduzena(){return koga!=nullptr;}
};
class Biblioteka{
    std::map<int,Korisnik*> korisnici;
    std::map<int,Knjiga*> knjige;
    public:
        Biblioteka()=default;
        ~Biblioteka();
        Biblioteka(Biblioteka &b);
        Biblioteka(Biblioteka &&b);
        Biblioteka &operator=(Biblioteka &b);
        Biblioteka &operator=(Biblioteka &&b);
        void RegistrirajNovogKorisnika(int clbr,std::string ime,std::string prezime,std::string adresa,std::string broj);
        void RegistrirajNovuKnjigu(int clbr,std::string naslov,std::string ime,std::string zanr,int godina);
        Korisnik &NadjiKorisnika(int n);
        Knjiga &NadjiKnjigu(int n);
        void IzlistajKorisnike()const;
        void IzlistajKnjige()const;
        void ZaduziKnjigu(int evbr,int clbr);
        void RazduziKnjigu(int evbr);
        void PrikaziZaduzenja(int clbr);
        
};
bool operator ==(const Korisnik &k1,const Korisnik &k2){
    return (k1.ime==k2.ime && k1.prezime==k2.prezime && k1.adresa==k2.adresa && k1.telefon==k2.telefon);
}
Biblioteka::~Biblioteka(){
    for(auto i=korisnici.begin();i!=korisnici.end();i++)delete i->second;
    for(auto i=knjige.begin();i!=knjige.end();i++)delete i->second;
}
Biblioteka::Biblioteka(Biblioteka &b){
    try{
        for(auto i=b.korisnici.begin();i!=b.korisnici.end();i++){
               korisnici[i->first]=new Korisnik(*(i->second)); 
        }
        for(auto i=b.knjige.begin();i!=b.knjige.end();i++){
            knjige[i->first]=new Knjiga(*(i->second));
        }
    }
    catch(...){
        throw std::bad_alloc();
    }
}
Biblioteka::Biblioteka(Biblioteka &&b){
    try{
        for(auto i=b.korisnici.begin();i!=b.korisnici.end();i++){
               korisnici[i->first]=new Korisnik(*(i->second)); 
        }
        for(auto i=b.knjige.begin();i!=b.knjige.end();i++){
            knjige[i->first]=new Knjiga(*(i->second));
        }
    }
    catch(...){
        throw std::bad_alloc();
    }
}
Biblioteka &Biblioteka::operator=(Biblioteka &b){
    if(this!=&b){
        for(auto i=korisnici.begin();i!=korisnici.end();i++)delete i->second;
        for(auto i=knjige.begin();i!=knjige.end();i++)delete i->second;
        
        for(auto i=b.korisnici.begin();i!=b.korisnici.end();i++){
           korisnici[i->first]=new Korisnik(*(i->second)); 
        }
        for(auto i=b.knjige.begin();i!=b.knjige.end();i++){
            knjige[i->first]=new Knjiga(*(i->second));
        }
    }
    return *this;
}
Biblioteka &Biblioteka::operator=(Biblioteka &&b){
    if(this!=&b){
        for(auto i=korisnici.begin();i!=korisnici.end();i++)delete i->second;
        for(auto i=knjige.begin();i!=knjige.end();i++)delete i->second;
        for(auto i=b.korisnici.begin();i!=b.korisnici.end();i++){
           korisnici[i->first]=new Korisnik(*(i->second)); 
        }
        for(auto i=b.knjige.begin();i!=b.knjige.end();i++){
            knjige[i->first]=new Knjiga(*(i->second));
        }
    }
    return *this;
}
void Biblioteka::RegistrirajNovogKorisnika(int clbr,std::string ime,std::string prezime,std::string adresa,std::string broj){
    if(korisnici.count(clbr))throw std::logic_error("Korisnik vec postoji");
    korisnici[clbr]=new Korisnik{ime,prezime,adresa,broj};
}
void Biblioteka::RegistrirajNovuKnjigu(int clbr,std::string naslov,std::string ime,std::string zanr,int godina){
    if(knjige.count(clbr))throw std::logic_error("Korisnik vec postoji");
    knjige[clbr]=new Knjiga(naslov,ime,zanr,godina);
}
Korisnik &Biblioteka::NadjiKorisnika(int n){
    if(!korisnici.count(n))throw std::logic_error("Korisnik nije nadjen");
    return(*korisnici[n]);
}
Knjiga &Biblioteka::NadjiKnjigu(int n){
    if(!knjige.count(n))throw std::logic_error("Knjiga nije nadjena");
    return(*knjige[n]);
}
void Biblioteka::IzlistajKorisnike()const{
    for(auto i=korisnici.begin();i!=korisnici.end();i++){
        std::cout<<"Clanski broj: "<<i->first<<std::endl;
        std::cout<<"Ime i prezime: "<<i->second->ime<<" "<<i->second->prezime<<std::endl;
        std::cout<<"Adresa: "<<i->second->adresa<<std::endl;
        std::cout<<"Broj telefona: "<<i->second->telefon<<std::endl<<std::endl;
    }
}
void Biblioteka::IzlistajKnjige()const{
    for(auto i=knjige.begin();i!=knjige.end();i++){
        std::cout<<"Evidencijski broj: "<<i->first<<std::endl;
        std::cout<<"Naslov: "<<i->second->DajNaslov()<<std::endl;
        std::cout<<"Pisac: "<<i->second->DajAutora()<<std::endl;
        std::cout<<"Zanr: "<<i->second->DajZanr()<<std::endl;
        std::cout<<"Godina izdavanja: "<<i->second->DajGodinuIzdavanja()<<std::endl;
        if(i->second->DaLiJeZaduzena())std::cout<<"Zaduzena kod korisnika: "<<i->second->DajKodKogaJe().ime<<" "<<i->second->DajKodKogaJe().prezime<<std::endl;
        std::cout<<std::endl;
    }
}
void Biblioteka::ZaduziKnjigu(int evbr,int clbr){
    if(!knjige.count(evbr))throw std::logic_error("Knjiga nije nadjena");
    if(!korisnici.count(clbr))throw std::logic_error("Korisnik nije nadjen");
    if(knjige[evbr]->DaLiJeZaduzena())throw std::logic_error("Knjiga vec zaduzena");
    knjige[evbr]->ZaduziKnjigu(*korisnici[clbr]);
}
void Biblioteka::RazduziKnjigu(int evbr){
    if(!knjige.count(evbr))throw std::logic_error("Knjiga nije nadjena");
    if(!(knjige[evbr]->DaLiJeZaduzena()))throw std::logic_error("Knjiga nije zaduzena");
    knjige[evbr]->RazduziKnjigu();
}
void Biblioteka::PrikaziZaduzenja(int clbr){
    if(!korisnici.count(clbr))throw std::domain_error("Korisnik nije nadjen");
    int br(0);
    for(auto i=knjige.begin();i!=knjige.end();i++){
        if((i->second->DaLiJeZaduzena()==false))continue;
        if(i->second->DajKodKogaJe()==(*korisnici[clbr])){
            std::cout<<"Evidencijski broj: "<<i->first<<std::endl;
            std::cout<<"Naslov: "<<i->second->DajNaslov()<<std::endl;
            std::cout<<"Pisac: "<<i->second->DajAutora()<<std::endl;
            std::cout<<"Zanr: "<<i->second->DajZanr()<<std::endl;
            std::cout<<"Godina izdavanja: "<<i->second->DajGodinuIzdavanja()<<std::endl;
            std::cout<<std::endl;
            br++;
        }
    }
    if(br==0)std::cout<<"Nema zaduzenja za tog korisnika!";
}
int main ()
{
    
	return 0;
}