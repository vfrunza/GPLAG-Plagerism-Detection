/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <string>
#include <stdexcept>
#include <map>
#include <memory>

struct Korisnik{
    std::string ime, prezime, adresa, telefon;
};

class Knjiga{
    std::string naslov, autor, zanr;
    int godina;
    Korisnik *pok=nullptr;
    bool zaduzena=false;
public:
    Knjiga(std::string naslov, std::string autor, std::string zanr, int godina) : naslov(naslov), autor(autor), zanr(zanr), godina(godina) {}
    std::string DajNaslov() const { return naslov; }
    std::string DajAutora() const { return autor; }
    std::string DajZanr() const { return zanr; }
    int DajGodinuIzdavanja() const { return godina; }
    Korisnik* DajKodKogaJe() const { return pok;}
    void ZaduziKnjigu(Korisnik &k){ pok=&k; zaduzena=true; }
    void RazduziKnjigu() { pok=nullptr; zaduzena=false; }
    bool DaLiJeZaduzena() { return zaduzena; }
};

class Biblioteka{
    std::map< int, std::shared_ptr<Korisnik>> korisnici;
    std::map< int, std::shared_ptr<Knjiga>> knjige;
public:
    Biblioteka(){}
    ~Biblioteka();
    Biblioteka(const Biblioteka &b);
    Biblioteka &operator =(const Biblioteka &b);
    Biblioteka(Biblioteka &&b);
    Biblioteka &operator =(Biblioteka &&b);
    void RegistrirajNovogKorisnika(int clanski_broj, std::string ime, std::string prezime, std::string adresa, std::string telefon);
    void RegistrirajNovuKnjigu(int evidencijski_broj, std::string naslov, std::string autor, std::string zanr, int godina);
    Korisnik &NadjiKorisnika(int clanski_broj);
    Knjiga &NadjiKnjigu(int evidencijski_broj);
    void IzlistajKorisnike() const;
    void IzlistajKnjige() const;
    void ZaduziKnjigu(int evidencijski_broj, int clanski_broj);
    void RazduziKnjigu(int evidencijski_broj);
    void PrikaziZaduzenja(int clanski_broj) ;
};

void Biblioteka::RegistrirajNovogKorisnika(int clanski_broj, std::string ime, std::string prezime, std::string adresa, std::string telefon){
    for(auto it=korisnici.begin(); it!=korisnici.end(); it++){
        if(it->first == clanski_broj) throw std::logic_error("Korisnik vec postoji");
    }
    Korisnik p;
    auto pok(std::make_shared<Korisnik>(p));
    pok->ime=ime; pok->prezime=prezime; pok->adresa=adresa; pok->telefon=telefon;
    korisnici.insert(std::make_pair(clanski_broj,pok));
}

void Biblioteka::RegistrirajNovuKnjigu(int evidencijski_broj, std::string naslov, std::string autor, std::string zanr, int godina){
    for(auto it=knjige.begin(); it!=knjige.end(); it++){
        if(it->first == evidencijski_broj) throw std::logic_error("Knjiga vec postoji");
    }
    //Knjiga k(naslov,autor,zanr,godina);
    auto pok(std::make_shared<Knjiga>(naslov,autor,zanr,godina));
    knjige.insert(std::make_pair(evidencijski_broj,pok));
}

Biblioteka::Biblioteka(const Biblioteka &b){
    for(auto it=b.korisnici.begin(); it!=b.korisnici.end(); it++){
        Korisnik p;
        auto pok(std::make_shared<Korisnik>(p));
        pok->ime=it->second->ime; pok->prezime=it->second->prezime; pok->adresa=it->second->adresa; pok->telefon=it->second->telefon;
        korisnici.insert(std::make_pair(it->first,pok));
    }
    for(auto it=b.knjige.begin(); it!=b.knjige.end(); it++){
        auto pok(std::make_shared<Knjiga>(it->second->DajNaslov(),it->second->DajAutora(),it->second->DajZanr(),it->second->DajGodinuIzdavanja()));
        knjige.insert(std::make_pair(it->first,pok));
    }
}

Biblioteka &Biblioteka::operator =(const Biblioteka &b){
    if(this==&b) return *this;
    for(auto it=korisnici.begin(); it!=korisnici.end(); it++) it->second=nullptr;
    for(auto it=korisnici.begin(); it!=korisnici.end(); it++) korisnici.erase(it);
    for(auto it=knjige.begin(); it!=knjige.end(); it++) it->second=nullptr;
    for(auto it=knjige.begin(); it!=knjige.end(); it++) knjige.erase(it);
    for(auto it=b.korisnici.begin(); it!=b.korisnici.end(); it++){
        Korisnik p;
        auto pok(std::make_shared<Korisnik>(p));
        pok->ime=it->second->ime; pok->prezime=it->second->prezime; pok->adresa=it->second->adresa; pok->telefon=it->second->telefon;
        korisnici.insert(std::make_pair(it->first,pok));
    }
    for(auto it=b.knjige.begin(); it!=b.knjige.end(); it++){
        auto pok(std::make_shared<Knjiga>(it->second->DajNaslov(),it->second->DajAutora(),it->second->DajZanr(),it->second->DajGodinuIzdavanja()));
        knjige.insert(std::make_pair(it->first,pok));
    }
    return *this;
}

Biblioteka::Biblioteka(Biblioteka &&b){
    for(auto it=b.korisnici.begin(); it!=b.korisnici.end(); it++){
        korisnici.insert(std::make_pair(it->first,it->second));
        it->second = nullptr;
    }
    for(auto it=b.knjige.begin(); it!=b.knjige.end(); it++){
        knjige.insert(std::make_pair(it->first,it->second));
        it->second = nullptr;
    }
}

Biblioteka &Biblioteka::operator =(Biblioteka &&b){
    if(&b == this) return *this;
    if(this==&b) return *this;
    for(auto it=korisnici.begin(); it!=korisnici.end(); it++) it->second=nullptr;
    for(auto it=korisnici.begin(); it!=korisnici.end(); it++) korisnici.erase(it);
    for(auto it=knjige.begin(); it!=knjige.end(); it++) it->second=nullptr;
    for(auto it=knjige.begin(); it!=knjige.end(); it++) knjige.erase(it);
    for(auto it=b.korisnici.begin(); it!=b.korisnici.end(); it++){
        korisnici.insert(std::make_pair(it->first,it->second));
        it->second = nullptr;
    }
    for(auto it=b.knjige.begin(); it!=b.knjige.end(); it++){
        knjige.insert(std::make_pair(it->first,it->second));
        it->second = nullptr;
    }
    return *this;
}

Korisnik& Biblioteka::NadjiKorisnika(int clanski_broj){
    bool postoji(false);
    for(auto it=korisnici.begin(); it!=korisnici.end(); it++){
        if(it->first==clanski_broj){ postoji=true; break; }
    }
    if(!postoji) throw std::logic_error("Korisnik nije nadjen");
    return *korisnici[clanski_broj];
}

Knjiga& Biblioteka::NadjiKnjigu(int evidencijski_broj){
    bool postoji(false);
    for(auto it=knjige.begin(); it!=knjige.end(); it++){
        if(it->first==evidencijski_broj){ postoji=true; break; }
    }
    if(!postoji) throw std::logic_error("Knjiga nije nadjena");
    return *knjige[evidencijski_broj];
}

void Biblioteka::IzlistajKorisnike() const{
    for(auto it=korisnici.begin(); it!=korisnici.end(); it++){
        std::cout << "Clanski broj: " << it->first << std::endl;
        std::cout << "Ime i prezime: " << it->second->ime << " " << it->second->prezime << std::endl;
        std::cout << "Adresa: " << it->second->adresa << std::endl;
        std::cout << "Broj telefona: " << it->second->telefon << std::endl;
    }
}

void Biblioteka::IzlistajKnjige() const{
    for(auto it=knjige.begin(); it!=knjige.end(); it++){
        std::cout << "Evidencijski broj: " << it->first << std::endl;
        std::cout << "Naslov: " << it->second->DajNaslov() << std::endl;
        std::cout << "Pisac: " << it->second->DajAutora() << std::endl;
        std::cout << "Zanr: " << it->second->DajZanr() << std::endl;
        std::cout << "Godina izdavanja: " << it->second->DajGodinuIzdavanja() << std::endl;
        if(it->second->DaLiJeZaduzena()) 
        std::cout << "Zaduzena kod korisnika: " << it->second->DajKodKogaJe()->ime << " " << it->second->DajKodKogaJe()->prezime << std::endl;
    }
}

void Biblioteka::ZaduziKnjigu(int evidencijski_broj, int clanski_broj){
    bool postoji_korisnik(false), postoji_knjiga(false);
    for(auto it=korisnici.begin(); it!=korisnici.end(); it++){
        if(it->first == clanski_broj){ postoji_korisnik=true; break; }
    }
    for(auto it=knjige.begin(); it!=knjige.end(); it++){
        if(it->first == evidencijski_broj){ postoji_knjiga=true; break; }
    }
    if(!postoji_knjiga) throw std::logic_error("Knjiga nije nadjena");
    if(!postoji_korisnik) throw std::logic_error("Korisnik nije nadjen");
    if(knjige[evidencijski_broj]->DaLiJeZaduzena()) throw std::logic_error("Knjiga vec zaduzena");
    knjige[evidencijski_broj]->ZaduziKnjigu(*korisnici[clanski_broj]);
}

void Biblioteka::RazduziKnjigu(int evidencijski_broj){
    bool postoji(false);
    for(auto it=knjige.begin(); it!=knjige.end(); it++){
        if(it->first == evidencijski_broj){ postoji=true; break; }
    }
    if(!postoji) throw std::logic_error("Knjiga nije nadjena");
    if(!knjige[evidencijski_broj]->DaLiJeZaduzena()) throw std::logic_error("Knjiga nije zaduzena");
    knjige[evidencijski_broj]->RazduziKnjigu();
}

Biblioteka::~Biblioteka(){
    for(auto it=korisnici.begin(); it!=korisnici.end(); it++) it->second=nullptr;
    for(auto it=knjige.begin(); it!=knjige.end(); it++) it->second=nullptr;
}

void Biblioteka::PrikaziZaduzenja(int clanski_broj) {
    bool postoji(false);
    for(auto it=korisnici.begin(); it!=korisnici.end(); it++){
        if(it->first == clanski_broj){ postoji=true; break; }
    }
    
    bool postoji2=false;
    if(postoji){
        for(auto it=knjige.begin(); it!=knjige.end(); it++){
            if(!it->second->DaLiJeZaduzena()) continue;
            if(korisnici[clanski_broj]->ime == it->second->DajKodKogaJe()->ime && korisnici[clanski_broj]->prezime == it->second->DajKodKogaJe()->prezime &&
            korisnici[clanski_broj]->adresa == it->second->DajKodKogaJe()->adresa && korisnici[clanski_broj]->telefon == it->second->DajKodKogaJe()->telefon){ 
                postoji2=true;
                std::cout << "Evidencijski broj: " << it->first << std::endl;
                std::cout << "Naslov: " << it->second->DajNaslov() << std::endl;
                std::cout << "Pisac: " << it->second->DajAutora() << std::endl;
                std::cout << "Zanr: " << it->second->DajZanr() << std::endl;
                std::cout << "Godina izdavanja: " << it->second->DajGodinuIzdavanja() << std::endl;
            }
        }
        if(!postoji2) throw std::logic_error("Nema zaduzenja za tog korisnika!");
    }
    if(!postoji) throw std::logic_error("Korisnik nije nadjen");
}

int main ()
{
	Biblioteka bibli;
	for(;;){
	    int opcija(0);
        std::cout << "Izaberite opciju: " << std::endl;
        std::cout << "1-Registracija novog korisnika" << std::endl;
        std::cout << "2-registriraj novu knjigu" << std::endl;
        std::cout << "3-nadji korisnika" << std::endl;
        std::cout << "4-nadji knjigu" << std::endl;
        std::cout << "5-izlistaj korisnike" << std::endl;
        std::cout << "6-izlistaj knjige" << std::endl;
        std::cout << "7-zaduzi knjigu" << std::endl;
        std::cout << "8-razduzi knjigu" << std::endl;
        std::cout << "9-prikazi zaduzenje" << std::endl;
        std::cout << "0-prekid" << std::endl;
        std::cin >> opcija;
        if(opcija==0) break;
        else if(opcija==1){
            int clanski_broj;
            std::cout << "Unesite clanski broj novog korisnika:" << std::endl;
            std::cin >> clanski_broj;
            std::string ime, prezime, adresa, telefon;
            std::cout << "Unesite ime, prezime, adresu i telefon novog korisnika: " << std::endl;
            std::cin >> std::ws;
            std::getline(std::cin, ime);
            std::getline(std::cin, prezime);
            std::getline(std::cin, adresa);
            std::getline(std::cin, telefon);
            try{
                bibli.RegistrirajNovogKorisnika(clanski_broj,ime,prezime,adresa,telefon);
            }
            catch(std::logic_error e){
                std::cout << e.what() << std::endl;
            }
            catch(...){
                std::cout << "Problemi sa memorijom" << std::endl;
            }
        }
        else if(opcija==2){
            int evidencijski_broj;
            std::cout << "Unesite evidencijski broj nove knjige: " << std::endl;
            std::cin >> evidencijski_broj;
            std::string naslov, autor, zanr;
            int godina;
            std::cout << "Unesite naslov, autora, zanr i godinu izdavanja nove knjige" << std::endl;
            std::cin >> std::ws;
            std::getline(std::cin, naslov);
            std::getline(std::cin, autor);
            std::getline(std::cin, zanr);
            std::cin >> godina;
            try{
                bibli.RegistrirajNovuKnjigu(evidencijski_broj,naslov,autor,zanr,godina);
            }
            catch(std::logic_error e){
                std::cout << e.what() << std::endl;
            }
            catch(...){
                std::cout << "Problemi sa memorijom" << std::endl;
            }
        }
        else if(opcija==3){
            int clanski_broj;
            std::cout << "Unesite clanski broj trazenog korisnika: " << std::endl;
            std::cin >> clanski_broj;
            try{
                Korisnik novi(bibli.NadjiKorisnika(clanski_broj));
                std::cout << "Ime i prezime trazenog korisnika: " << novi.ime << " " << novi.prezime << std::endl;
                std::cout << "Adresa trazenog korisnika: " << novi.adresa << std::endl;
                std::cout << "Telefon trazenog korisnika: " << novi.telefon << std::endl;
            }
            catch(std::logic_error e){
                std::cout << e.what() << std::endl;
            }
        }
        else if(opcija==4){
            int evidencijski_broj;
            std::cout << "Unesite evidencijski broj trazene knjige: " << std::endl;
            std::cin >> evidencijski_broj;
            try{
                Knjiga trazena(bibli.NadjiKnjigu(evidencijski_broj));
                std::cout << "Naslov, autor, zanr i godina izdavanja trazene knjige su: " << trazena.DajNaslov() << " " << trazena.DajAutora() << " "
                << trazena.DajZanr() << " " << trazena.DajGodinuIzdavanja() << std::endl;
            }
            catch(std::logic_error e){
                std::cout << e.what() << std::endl;
            }
        }
        else if(opcija==5){
            bibli.IzlistajKorisnike();
        }
        else if(opcija==6){
            bibli.IzlistajKnjige();
        }
        else if(opcija==7){
            int evidencijski_broj, clanski_broj;
            std::cout << "Unesite evidencijski broj knjige i clanski broj korisnika koji zaduzuje: " << std::endl;
            std::cin >> evidencijski_broj >> clanski_broj;
            try{
                bibli.ZaduziKnjigu(evidencijski_broj,clanski_broj);
            }
            catch(std::logic_error e){
                std::cout << e.what() << std::endl;
            }
        }
        else if(opcija==8){
            int evidencijski_broj;
            std::cout << "Unesite evidencijski broj knjige koju razduzujete: " << std::endl;
            std::cin >> evidencijski_broj;
            try{
                bibli.RazduziKnjigu(evidencijski_broj);
            }
            catch(std::logic_error e){
                std::cout << e.what() << std::endl;
            }
        }
        else if(opcija==9){
            int clanski_broj;
            std::cout << "Unesite clanski broj korisnika cija zaduzenja zelite citati: " << std::endl;
            std::cin >> clanski_broj;
            try{
                bibli.PrikaziZaduzenja(clanski_broj);
            }
            catch(std::logic_error e){
                std::cout << e.what() << std::endl;
            }
        }
        else continue;
    }
    //std::cout << "I DALJE RADIIIII" ;
	return 0;
}