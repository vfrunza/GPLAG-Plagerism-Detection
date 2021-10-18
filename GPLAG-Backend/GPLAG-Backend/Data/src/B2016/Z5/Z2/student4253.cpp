/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <memory>
#include <string>
#include <map>

struct Korisnik{
    std::string ime, prezime, adresa, telefon;
};

class Knjiga{
    std::string naslov_knjige, ime_pisca, zanr;
    int godina_izdavanja;
    Korisnik *zaduzeno_kod;
    
    public:
    Knjiga(std::string naslov, std::string ime, std::string zanr, int godina): naslov_knjige(naslov), ime_pisca(ime), zanr(zanr), godina_izdavanja(godina), zaduzeno_kod(nullptr) {}
    std::string DajNaslov() const {return naslov_knjige;}
    std::string DajAutora() const {return ime_pisca;}
    std::string DajZanr() const {return zanr;}
    int DajGodinuIzdavanja() const {return godina_izdavanja;}
    Korisnik* DajKodKogaJe() const {return zaduzeno_kod;}
    void ZaduziKnjigu(Korisnik &korisnik) {zaduzeno_kod=&korisnik;}
    void RazduziKnjigu(){zaduzeno_kod=nullptr;}
    bool DaLiJeZaduzena() const {if(zaduzeno_kod==nullptr) return false; return true;}
};

class Biblioteka{
    std::map<int, std::shared_ptr<Korisnik>> korisnici;
    std::map<int, std::shared_ptr<Knjiga>> knjige;
    
    public:
    Biblioteka();
   
    Biblioteka(const Biblioteka &biblioteka);
    Biblioteka(Biblioteka &&biblioteka);
    Biblioteka &operator=(const Biblioteka &biblioteka);
    Biblioteka &operator=(Biblioteka &&biblioteka);
    void RegistrirajNovogKorisnika(int broj_korisnika, std::string ime, std::string prezime, std::string adresa, std::string broj_telefona);
    void RegistrirajNovuKnjigu(int broj_knjige, std::string naslov, std::string ime_pisca, std::string zanr, int godina_izdavanja);
    Korisnik &NadjiKorisnika(int broj_korisnika) const;
    Knjiga &NadjiKnjigu(int broj_knjige) const;
    void IzlistajKorisnike() const;
    void IzlistajKnjige()const;
    void ZaduziKnjigu(int broj_knjige, int broj_korisnika);
    void RazduziKnjigu(int broj_knjige);
    void PrikaziZaduzenja(int broj_korisnika) const;
};

Biblioteka::Biblioteka(){
    std::map<int, std::shared_ptr<Korisnik>> p1;
    std::map<int, std::shared_ptr<Knjiga>> p2;
    korisnici=p1; knjige=p2;
}

Biblioteka::Biblioteka(const Biblioteka &biblioteka){
    for(auto it=biblioteka.korisnici.begin(); it!=biblioteka.korisnici.end(); it++){
        korisnici.insert(std::make_pair(it->first, std::make_shared<Korisnik> (*(it->second))));
    }
    for(auto it=biblioteka.knjige.begin(); it!=biblioteka.knjige.end(); it++){
        knjige.insert(std::make_pair(it->first, std::make_shared<Knjiga>(*(it->second))));
    }
}

Biblioteka::Biblioteka(Biblioteka &&biblioteka){
    korisnici=biblioteka.korisnici;
    knjige=biblioteka.knjige;
    
    for(auto it=biblioteka.korisnici.begin(); it!=biblioteka.korisnici.end(); it++) it->second=nullptr;
    for(auto it=biblioteka.knjige.begin(); it!=biblioteka.knjige.end(); it++) it->second=nullptr;
}

Biblioteka &Biblioteka::operator=(const Biblioteka &biblioteka){
    for(auto it=korisnici.begin(); it!=korisnici.end(); it++) it->second=nullptr;
    for(auto it=knjige.begin(); it!=knjige.end(); it++) it->second=nullptr;
    
    for(auto it=korisnici.begin(); it!=korisnici.end(); it=korisnici.erase(it));
    for(auto it=knjige.begin(); it!=knjige.end(); it=knjige.erase(it));
    
    for(auto it=biblioteka.korisnici.begin(); it!=biblioteka.korisnici.end(); it++){
        korisnici.insert(std::make_pair(it->first, std::make_shared<Korisnik> (*(it->second))));
    }
    for(auto it=biblioteka.knjige.begin(); it!=biblioteka.knjige.end(); it++){
        knjige.insert(std::make_pair(it->first, std::make_shared<Knjiga>(*(it->second))));
    }
    return *this;
}

Biblioteka &Biblioteka::operator=(Biblioteka &&biblioteka){
    std::swap(korisnici,biblioteka.korisnici);
    std::swap(knjige,biblioteka.knjige);
    return *this;
}

void Biblioteka::RegistrirajNovogKorisnika(int broj_korisnika, std::string ime, std::string prezime, std::string adresa, std::string broj_telefona){
    auto it(korisnici.find(broj_korisnika));
    if(it!=korisnici.end()) throw std::logic_error("Korisnik vec postoji");
    
    std::shared_ptr<Korisnik> temp(new Korisnik);
    temp->ime=ime; temp->prezime=prezime; temp->adresa=adresa; temp->telefon=broj_telefona;
    
    korisnici.insert(std::make_pair(broj_korisnika, temp));
    
}

void Biblioteka::RegistrirajNovuKnjigu(int broj_knjige, std::string naslov, std::string ime_pisca, std::string zanr, int godina_izdavanja){
    auto it(knjige.find(broj_knjige));
    if(it!=knjige.end()) throw std::logic_error("Knjiga vec postoji");
    knjige.insert(std::make_pair(broj_knjige, std::make_shared<Knjiga>(naslov, ime_pisca, zanr, godina_izdavanja)));
}

Korisnik &Biblioteka::NadjiKorisnika(int broj_korisnika) const{
    auto it(korisnici.find(broj_korisnika));
    if(it==korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
    return *(it->second);
}

Knjiga &Biblioteka::NadjiKnjigu(int broj_knjige) const{
    auto it(knjige.find(broj_knjige));
    if(it==knjige.end()) throw std::logic_error("Knjiga nije nadjena");
    return *(it->second);
}

void Biblioteka::IzlistajKorisnike() const{
    for(auto it=korisnici.begin(); it!=korisnici.end(); it++){
        std::cout<<"Clanski broj: "<<it->first<<std::endl
                 <<"Ime i prezime: "<<(it->second)->ime<<" "<<(it->second)->prezime<<std::endl
                 <<"Adresa: "<<(it->second)->adresa<<std::endl
                 <<"Broj telefona: "<<(it->second)->telefon<<std::endl
                 <<std::endl;
    }
}

void Biblioteka::IzlistajKnjige() const{
    for(auto it=knjige.begin(); it!=knjige.end(); it++){
        std::cout<<"Evidencijski broj: "<<it->first<<std::endl
                 <<"Naslov: "<<(it->second)->DajNaslov()<<std::endl
                 <<"Pisac: "<<(it->second)->DajAutora()<<std::endl
                 <<"Zanr: "<<(it->second)->DajZanr()<<std::endl
                 <<"Godina izdavanja: "<<(it->second)->DajGodinuIzdavanja()<<std::endl;
        if( (it->second)->DaLiJeZaduzena() ) std::cout<<"Zaduzena kod korisnika: "<<(it->second)->DajKodKogaJe()->ime<<" "<<(it->second)->DajKodKogaJe()->prezime<<std::endl;
        std::cout<<std::endl;
    }
}

void Biblioteka::ZaduziKnjigu(int broj_knjige, int broj_korisnika){
    auto it_knjige(knjige.find(broj_knjige));
    if(it_knjige==knjige.end()) throw std::logic_error("Knjiga nije nadjena");
    auto it_korisnika(korisnici.find(broj_korisnika));
    if(it_korisnika==korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
    
    if((it_knjige->second)->DaLiJeZaduzena()) throw std::logic_error("Knjiga je vec zaduzena");
    (it_knjige->second)->ZaduziKnjigu(*(it_korisnika->second));
}

void Biblioteka::RazduziKnjigu(int broj_knjige){
    auto it_knjige(knjige.find(broj_knjige));
    if(it_knjige==knjige.end()) throw std::logic_error("Knjiga nije nadjena");
    if((it_knjige->second)->DaLiJeZaduzena()==false) throw std::logic_error("Knjiga nije zaduzena");
    (it_knjige->second)->RazduziKnjigu();
}

void Biblioteka::PrikaziZaduzenja(int broj_korisnika) const{
    auto it_k(korisnici.find(broj_korisnika));
    if(it_k==korisnici.end()) throw std::logic_error("Korisnik nije nadjen");
    
    Korisnik *p(it_k->second.get());
    
    bool nema(true);
    
    for(auto it=knjige.begin(); it!=knjige.end(); it++){
        if((it->second)->DajKodKogaJe()==p){
            nema=false;
            std::cout<<"Evidencijski broj: "<<it->first<<std::endl
                     <<"Naslov: "<<(it->second)->DajNaslov()<<std::endl
                     <<"Pisac: "<<(it->second)->DajAutora()<<std::endl
                     <<"Zanr: "<<(it->second)->DajZanr()<<std::endl
                     <<"Godina izdavanja: "<<(it->second)->DajGodinuIzdavanja()<<std::endl
                     <<std::endl;
        }
        if(nema) std::cout<<"Nema zaduzenja za tog korisnika!";
    }
}

int main ()
{
    Biblioteka biblioteka;
    for(;;){
        std::cout<<"Izaberite opciju: "<<std::endl
                 <<"0 - kraj"<<std::endl
                 <<"1 - dodavanje korisnika"<<std::endl
                 <<"2 - dodavanje knjige"<<std::endl
                 <<"3 - zaduzenje knjige"<<std::endl
                 <<"4 - razduzenje knjige"<<std::endl
                 <<"5 - izlistavanje knjiga"<<std::endl
                 <<"6 - izlistavanje korisnika"<<std::endl;
        int opcija;
        std::cin>>opcija;
        if(opcija==0) {std::cout<<"Kraj"; break;}
        if(opcija==1){
            std::cout<<"Unesi clanski broj";
            int broj;
            std::cin>>broj;
            std::cin.ignore(1000,'\n');
            std::cout<<"Unesi ime, prezime, adresu i telefon korisnika (svaki podatak u novom redu): ";
            std::string ime, prezime, adresa, telefon;
            std::getline(std::cin,ime); std::getline(std::cin,prezime); std::getline(std::cin,adresa); std::getline(std::cin,telefon);
            biblioteka.RegistrirajNovogKorisnika(broj,ime,prezime,adresa,telefon);
        }
        if(opcija==2){
            std::cout<<"Unesi evidencijski broj knjige: ";
            int broj;
            std::cin>>broj;
            std::cin.ignore(1000,'\n');
            std::cout<<"Unesi naslov, pisca, zanr i godinu izdavanja knjige (svaki podatak u novom redu): ";
            std::string naslov, pisac, zanr;
            int godina;
            std::getline(std::cin,naslov); std::getline(std::cin,pisac); std::getline(std::cin,zanr); std::cin>>godina;
            biblioteka.RegistrirajNovuKnjigu(broj,naslov,pisac,zanr,godina);
        }
        if(opcija==3){
            std::cout<<"Unesi evidencijski broj knjige: ";
            int knjiga;
            std::cin>>knjiga;
            std::cout<<"Unesi clanski broj korisnika: ";
            int korisnik;
            std::cin>>korisnik;
            try{
                biblioteka.ZaduziKnjigu(knjiga,korisnik);
            }
            catch(std::logic_error izuzetak){
                std::cout<<izuzetak.what();
            }
        }
        if(opcija==4){
            std::cout<<"Unesi evidencijski broj knjige: ";
            int knjiga;
            std::cin>>knjiga;
            try{
                biblioteka.RazduziKnjigu(knjiga);
            }
            catch(std::logic_error izuzetak){
                std::cout<<izuzetak.what();
            }
        }
        if(opcija==5){
            biblioteka.IzlistajKnjige();
        }
        if(opcija==6){
            biblioteka.IzlistajKorisnike();
        }
        
    }
	return 0;
}