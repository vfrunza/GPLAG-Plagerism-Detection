/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>
#include <map>
#include <algorithm>
#include <memory>

struct Korisnik{
    std::string ime;
    std::string prezime;
    std::string adresa;
    std::string telefon;
};

class Knjiga{
    private:
        std::string naslov_knjige;
        std::string ime_pisca;
        std::string zanr;
        int godina_izdavanja;
        Korisnik* zaduzio_knjigu;
    public:
        Knjiga(std::string naslov, std::string pisac, std::string zanr, int godina);
        std::string DajNaslov() const {return naslov_knjige;}
        std::string DajAutora() const {return ime_pisca;}
        std::string DajZanr () const {return zanr;}
        int DajGodinuIzdavanja () const {return godina_izdavanja;}
        Korisnik* DajKodKogaJe() const {return zaduzio_knjigu;}
        void ZaduziKnjigu(Korisnik &korisnik);
        void RazduziKnjigu(){zaduzio_knjigu=nullptr;}
        bool DaLiJeZaduzena()const{return zaduzio_knjigu!=nullptr;}
};
void Knjiga::ZaduziKnjigu(Korisnik &korisnik){
    if(DaLiJeZaduzena()) throw std::domain_error("Knjiga vec zaduzena");
    zaduzio_knjigu=&korisnik;
}
Knjiga::Knjiga(std::string naslov, std::string pisac, std::string zanr, int godina){
    naslov_knjige=naslov; ime_pisca=pisac; Knjiga::zanr=zanr; godina_izdavanja=godina;
    zaduzio_knjigu=nullptr;
}

typedef std::shared_ptr<Knjiga> pok_na_knjigu;
typedef std::shared_ptr<Korisnik> pok_na_korisnika;

class Biblioteka{
    private:
        std::map<int,pok_na_knjigu> knjige;
        std::map<int,pok_na_korisnika> korisnici;
        friend void IspisiKnjigu(std::pair<int,pok_na_knjigu> p);
        friend bool Jednaki(Korisnik k1, Korisnik k2);
    public:
        Biblioteka(){}
        Biblioteka &operator=(const Biblioteka &b);
        Biblioteka &operator=(Biblioteka &&b);
        ~Biblioteka();
        void RegistrirajNovogKorisnika(int clanski_broj,const std::string &ime,const std::string &prezime, const std::string &adresa, const std::string &telefon);
        void RegistrirajNovuKnjigu(int e_broj, const std::string &naslov, const std::string &pisac, const std::string &zanr, int godina);
        Korisnik &NadjiKorisnika (int clanski_broj) const;
        Knjiga &NadjiKnjigu (int e_broj) const;
        void IzlistajKorisnike()const;
        void IzlistajKnjige() const;
        void ZaduziKnjigu(int e_broj, int clanski_broj);
        void RazduziKnjigu(int e_broj);
        void PrikaziZaduzenja (int clanski_broj)const;
};
        
Biblioteka& Biblioteka::operator=(const Biblioteka &b){
    
    auto it=knjige.begin();
    while(it!=knjige.end()) it->second=nullptr,it++; //brisanje u objektu kojem dodjeljujemo
    knjige.clear();
    auto it2=korisnici.begin();
    while(it2!=korisnici.end()) it2->second=nullptr,it2++;
    korisnici.clear();
    auto it3=b.knjige.begin();
    while(it3!=b.knjige.end()){
        knjige.insert({it3->first,std::make_shared<Knjiga>(*(it3->second))});
        it3++;
    }
    auto it4=b.korisnici.begin();
    while(it4!=b.korisnici.end()){
        korisnici.insert({it4->first,std::make_shared<Korisnik>(*(it4->second))});
        it4++;
    }
        
    return *this;
}
Biblioteka& Biblioteka::operator=(Biblioteka &&b){
    std::swap(korisnici,b.korisnici);
    std::swap(knjige,b.knjige);
    return *this;
}
Biblioteka::~Biblioteka(){
    auto it=knjige.begin();
    while(it!=knjige.end()){
        it->second=nullptr;
        it++;
    }
    
    auto it2=korisnici.begin();
    while(it2!=korisnici.end()){
        it2->second=nullptr;
        it2++;
    }
    korisnici.clear();
    knjige.clear();
}
void Biblioteka::ZaduziKnjigu(int e_broj, int clanski_broj){
    auto it1(knjige.find(e_broj));
    if(it1==knjige.end())
        throw std::logic_error("Knjiga nije nadjena");
    auto it2=korisnici.find(clanski_broj);
    if(it2==korisnici.end())
        throw std::logic_error("Korisnik nije nadjen");
    if((it1->second)->DaLiJeZaduzena()) throw std::logic_error("Knjiga vec zaduzena");
    (it1->second)->ZaduziKnjigu((*(it2->second)));
}
void Biblioteka::RazduziKnjigu(int e_broj){
    auto it(knjige.find(e_broj));
    if(it==knjige.end())
        throw std::logic_error("Knjiga nije nadjena");
    if(!((it->second)->DaLiJeZaduzena()))
        throw std::logic_error("Knjiga nije zaduzena");
    (it->second)->RazduziKnjigu();
}
void IspisiKnjigu(std::pair<int,pok_na_knjigu> p){
    std::cout<<"Evidencijski broj: "<<p.first<<std::endl;
    std::cout<<"Naslov: "<<(p.second)->DajNaslov()<<std::endl;
    std::cout<<"Pisac: "<<(p.second)->DajAutora()<<std::endl;
    std::cout<<"Zanr: "<<(p.second)->DajZanr()<<std::endl;
    std::cout<<"Godina izdavanja: "<<(p.second)->DajGodinuIzdavanja()<<std::endl;
}
void Biblioteka::RegistrirajNovogKorisnika(int clanski_broj, const std::string &ime, const std::string &prezime, const std::string &adresa, const std::string &telefon){
    if(korisnici.find(clanski_broj)!=korisnici.end()){
        throw std::logic_error("Korisnik vec postoji");
    }
    pok_na_korisnika pom(new Korisnik{ime,prezime,adresa,telefon});
    korisnici.insert({clanski_broj,pom});
}
void Biblioteka::RegistrirajNovuKnjigu(int e_broj, const std::string &naslov, const std::string &pisac, const std::string &zanr, int godina){
    if(knjige.find(e_broj)!=knjige.end()){
        throw std::logic_error("Knjiga vec postoji");
    }
    pok_na_knjigu pom(new Knjiga(naslov,pisac,zanr,godina));
    knjige.insert({e_broj,pom});
}
Korisnik &Biblioteka::NadjiKorisnika(int clanski_broj) const {
    auto it=korisnici.find(clanski_broj);
    if(it==korisnici.end())
        throw std::logic_error("Korisnik nije nadjen");
    return *(it->second);
}
Knjiga &Biblioteka::NadjiKnjigu(int e_broj) const {
    auto it=knjige.find(e_broj);
    if(it==knjige.end())
        throw std::logic_error("Knjiga nije nadjena");
    return *(it->second);
}
void Biblioteka::IzlistajKorisnike() const {
    std::for_each(korisnici.begin(),korisnici.end(),[](std::pair<int,pok_na_korisnika> p){
        std::cout<<"Clanski broj: "<<p.first<<std::endl;
        std::cout<<"Ime i prezime: "<<(p.second)->ime<<" "<<(p.second)->prezime<<std::endl;
        std::cout<<"Adresa: "<<(p.second)->adresa<<std::endl;
        std::cout<<"Broj telefona: "<<(p.second)->telefon<<std::endl;
        std::cout<<std::endl;
    });
}
void Biblioteka::IzlistajKnjige()const{
    std::for_each(knjige.begin(),knjige.end(),[](std::pair<int,pok_na_knjigu> p){
        IspisiKnjigu(p);
        if(p.second->DajKodKogaJe()!=nullptr)
        std::cout<<"Zaduzena kod korisnika: "<<(p.second)->DajKodKogaJe()->ime<<" "<<(p.second)->DajKodKogaJe()->prezime<<std::endl;
        std::cout<<std::endl;
    });
}
bool Jednaki(Korisnik k1, Korisnik k2){
    return k1.ime==k2.ime&&k1.prezime==k2.prezime&&k1.adresa==k2.adresa&&k1.telefon==k2.telefon;
}
void Biblioteka::PrikaziZaduzenja(int clanski_broj) const {
    auto it=std::find_if(korisnici.begin(),korisnici.end(),[clanski_broj](std::pair<int,pok_na_korisnika> p){
        return clanski_broj==p.first;
    });
    if(it==korisnici.end()) 
        throw std::logic_error("Korisnik nije nadjen");
    Korisnik pom=*(it->second);
    for(auto x : knjige){
        if(Jednaki(*(x.second->DajKodKogaJe()),pom))
            IspisiKnjigu(x);
    }
}

int main ()
{
    Biblioteka b;
    std::cout<<"Dobrodosli!"<<std::endl;
    for( ; ; ){
        int opcija;
        std::cout<<"Izaberite opciju: \n1 - dodavanje novog korisnika\n2 - dodavanje nove knjige\n3 - zaduzivanje knjige\n4 - razduzivanje knjige\n5 - ispis knjiga\n6 - ispis korisnika\n7 - kraj"<<std::endl;
        std::cin>>opcija;
        if(opcija==7) break;
        if(opcija==5) b.IzlistajKnjige();
        if(opcija==6) b.IzlistajKorisnike();
        if(opcija==3){
            std::cout<<"Unesite evidencijski broj knjige: ";
            int e;
            std::cin>>e;
            int k;
            std::cout<<"Unesite clanski broj korisnika: ";
            std::cin>>k;
            try{b.ZaduziKnjigu(e,k);}
            catch(std::logic_error h){
                std::cout<<"Izuzetak: "<<h.what()<<std::endl;
            }
        }
        if(opcija==4){
            std::cout<<"Unesite evidencijski broj knjige: ";
            int e;
            std::cin>>e;
            try{b.RazduziKnjigu(e);}
            catch(std::logic_error h){
                std::cout<<"Izuzetak: "<<h.what()<<std::endl;
            }
        }
        if(opcija==1){
            std::string ime,prezime,adresa,telefon;
            int clanski_broj;
            std::cout<<"Unesite ime: ";
            std::cin.ignore(1000,'\n');
            std::getline(std::cin,ime);
            std::cout<<"Unesite prezime: ";
            std::getline(std::cin,prezime);
            std::cout<<"Unesite adresu: ";
            std::getline(std::cin, adresa);
            std::cout<<"Unesite broj telefona: ";
            std::getline(std::cin, telefon);
            std::cout<<"Unesite clanski broj: ";
            std::cin>>clanski_broj;
            try{b.RegistrirajNovogKorisnika(clanski_broj,ime,prezime,adresa,telefon);
                std::cout<<"Korisnik uspjesno dodan."<<std::endl;
            }
            catch(std::logic_error h){
                std::cout<<"Izuzetak: "<<h.what()<<std::endl;
            }
        }
        if(opcija==2){
            int ebroj,godina;
            std::string naslov,pisac,zanr;
            std::cout<<"Unesite naslov knjige: ";
            std::cin.ignore(1000,'\n');
            std::getline(std::cin,naslov);
            std::cout<<"Unesite ime pisca: ";
            std::getline(std::cin,pisac);
            std::cout<<"Unesite zanr: ";
            std::getline(std::cin,zanr);
            std::cout<<"Unesite godinu izdavanja: ";
            std::cin>>godina;
            std::cout<<"Unesite evidencijski broj: ";
            std::cin>>ebroj;
            try{b.RegistrirajNovuKnjigu(ebroj,naslov,pisac,zanr,godina);
                std::cout<<"Knjiga uspjesno dodana"<<std::endl;
            }
            catch(std::logic_error h){
                std::cout<<"Izuzetak: "<<h.what()<<std::endl;
            }
        }
    }
    return 0;
}